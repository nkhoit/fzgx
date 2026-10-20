"""Cross-check a module's tus.json against the retail relocations, and repair it.

tus.json comes from tools/seeds/debug_strings.py, which starts each TU at its first
__FILE__ reference and ends it at the next TU's. A TU usually starts a few functions
before that reference, so ranges run long; the generator's data vote then moved single
functions into other TUs' lists without moving any range, and units followed the lists.
Every later step (carving, collapsing, objdiff naming) trusts these, so a wrong bound
costs a detour each time.

CodeWarrior links every TU's sections in one order, and a TU's statics, string literals
and float pool sit in its own block of .rodata/.data/.bss, in TU order. So the data a
function references orders it among the TUs. Neighbours do share globals and even pooled
float constants, so sharing alone proves little; order does. `check()` reports:

  structure   ranges overlap, leave a gap, or don't start/end at a function
  membership  "functions" disagrees with the text range, or a unit's TU file with both
  anchor      a __FILE__ reference lies outside its TU's range
  string      a function uses a string literal outside its TU's .data neighbourhood
              (between the previous and next TU's __FILE__ strings)
  cut         2+ symbols referenced from one side of a boundary only are out of data order
  data        a .data boundary sits above data only the next TU references
  hint / pool one out-of-order symbol, or a .rodata constant used on both sides of a
              boundary: worth a look with `explain()`, not flagged

Where a boundary goes is decided by reading `explain()` (which side each function's data
is shared with), so `repair()` takes reviewed cuts rather than deriving them. It then makes
every function list exactly its range, fixes the .data boundaries, and moves matched blocks
to their TU files, keeping each unit's object byte-identical.
"""

from __future__ import annotations

import bisect
import json
import re
import struct
from collections import defaultdict
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple

from .project import ROOT, Project

DATA_SECTIONS = (".rodata", ".data", ".bss")
CUT_FLAG = 2  # out-of-order symbols at a boundary that flag it; one is often a neighbour's global
POOL_FLAG = 2  # users on each side of a boundary that make a shared .rodata constant suspicious
CLUSTER_GAP = 0x1000  # bytes between referenced symbols that split a section into separate runs


@dataclass
class Evidence:
    funcs: list  # function Symbols in address order
    refs: Dict[int, Set[Tuple[str, int]]]  # function index -> {(section, symbol addr)}
    users: Dict[Tuple[str, int], Set[int]]  # (section, symbol addr) -> function indices
    size: Dict[Tuple[str, int], int] = field(default_factory=dict)  # (section, symbol addr) -> size
    data_section: Dict[int, str] = field(default_factory=dict)  # REL section index -> name


def _rel_bytes(p: Project, module: str) -> bytes:
    cfg = (p.config_dir / "config.yml").read_text().splitlines()
    for i, line in enumerate(cfg):
        if line.strip() == f"name: {module}":
            obj = next(l.split(":", 1)[1].strip() for l in reversed(cfg[:i]) if l.startswith("- object:"))
            return (ROOT / "orig" / p.version / obj).read_bytes()
    raise ValueError(f"module {module} not in config.yml")


def _section_names(p: Project, module: str) -> List[str]:
    """Section names from the Sections header of splits.txt (dtk lists the non-empty REL
    sections in index order)."""
    names = []
    for ln in (p.module_config_dir(module) / "splits.txt").read_text().splitlines():
        if ln.startswith("Sections:"):
            continue
        m = re.match(r"^\t(\.\w+)\s+type:", ln)
        if m:
            names.append(m.group(1))
        elif names and ln.strip():
            break
    return names


def evidence(p: Project, module: str) -> Evidence:
    data = _rel_bytes(p, module)
    v = struct.unpack(">16I", data[:0x40])
    self_id, numsec, secoff, impoff, impsize = v[0], v[3], v[4], v[10], v[11]
    sizes = [struct.unpack(">II", data[secoff + 8 * i: secoff + 8 * i + 8])[1] for i in range(numsec)]
    present = [i for i in range(numsec) if sizes[i]]
    names = dict(zip(present, _section_names(p, module)))
    text_i = next(i for i, n in names.items() if n == ".text")
    funcs = p.functions(module)
    starts = [f.addr for f in funcs]
    objs: Dict[str, Tuple[List[int], List[int]]] = {}
    for s in p.symbols(module).values():
        if s.kind == "object" and s.section in DATA_SECTIONS:
            objs.setdefault(s.section, ([], []))
    for sec in objs:
        rows = sorted((s.addr, s.end) for s in p.symbols(module).values() if s.kind == "object" and s.section == sec)
        objs[sec] = ([a for a, _ in rows], [e for _, e in rows])

    def owner_sym(sec: str, off: int) -> int:
        a, e = objs.get(sec, ([], []))
        i = bisect.bisect_right(a, off) - 1
        return a[i] if i >= 0 and off < max(e[i], a[i] + 1) else off

    refs: Dict[int, Set[Tuple[str, int]]] = defaultdict(set)
    users: Dict[Tuple[str, int], Set[int]] = defaultdict(set)
    for k in range(impsize // 8):
        mod, ro = struct.unpack(">II", data[impoff + 8 * k: impoff + 8 * k + 8])
        if mod != self_id:
            continue
        pos, cur = 0, None
        while True:
            off, typ, sec, add = struct.unpack(">HBBI", data[ro: ro + 8])
            ro += 8
            if typ == 203:
                break
            if typ == 202:
                cur, pos = sec, 0
                continue
            pos += off
            to = names.get(sec)
            if cur != text_i or to not in DATA_SECTIONS:
                continue
            fi = bisect.bisect_right(starts, pos) - 1
            if fi < 0 or pos >= funcs[fi].end:
                continue
            key = (to, owner_sym(to, add))
            refs[fi].add(key)
            users[key].add(fi)
    size = {}
    for sec, (a, e) in objs.items():
        size.update(((sec, x), y - x) for x, y in zip(a, e))
    return Evidence(funcs, refs, users, size=size, data_section=names)


def _load(p: Project, module: str) -> dict:
    return json.loads((p.module_config_dir(module) / "tus.json").read_text())


def _cut_cost(ev: Evidence, lo: int, hi: int, b: int) -> int:
    """Data-order violations of cutting functions [lo, hi) at index b.

    A symbol votes when every function referencing it lies in [lo, hi) (a global used
    further away says nothing about this boundary) and all of them lie on one side of
    the cut: then it is that side's own data. Symbols referenced from both sides are
    ordinary cross-TU references (neighbours share globals and even pooled floats) and
    do not vote. Per section the cost is the fewest left symbols at or after, plus right
    symbols before, the best data cut: zero when every one-sided symbol is in order."""
    total = 0
    for sec in DATA_SECTIONS:
        left, right = [], []
        for key, us in ev.users.items():
            if key[0] != sec or not us or min(us) < lo or max(us) >= hi:
                continue
            if max(us) < b:
                left.append(key[1])
            elif min(us) >= b:
                right.append(key[1])
        left, right = _main_cluster(ev, sec, left, right)
        if not left or not right:
            continue
        left.sort()
        right.sort()
        best = min((len(left) - bisect.bisect_left(left, c)) + bisect.bisect_left(right, c)
                   for c in sorted(set(left + right)) + [max(left[-1], right[-1]) + 1])
        total += best
    return total


def _main_cluster(ev: Evidence, sec: str, left: List[int], right: List[int]) -> Tuple[List[int], List[int]]:
    """Keep the symbols of the densest run of the section. The window's own data is one
    contiguous stretch; a symbol far from it (another TU's global that only these
    functions happen to use) would read as a misordering."""
    addrs = sorted(left + right)
    runs, cur = [], [addrs[0]] if addrs else []
    for a in addrs[1:]:
        if a - (cur[-1] + ev.size.get((sec, cur[-1]), 4)) > CLUSTER_GAP:
            runs.append(cur)
            cur = []
        cur.append(a)
    runs.append(cur)
    keep = set(max(runs, key=len))
    return [a for a in left if a in keep], [a for a in right if a in keep]


def _index_of(ev: Evidence, addr: int) -> int:
    starts = [f.addr for f in ev.funcs]
    i = bisect.bisect_left(starts, addr)
    return i if i < len(starts) and starts[i] == addr else -1


def _is_string(raw: bytes, addr: int) -> bool:
    end = raw.find(b"\0", addr, addr + 256)
    chunk = raw[addr:end]
    return end > addr + 1 and all(32 <= c < 127 or c in (9, 10) for c in chunk)


def _file_strings(ev: Evidence, tus: List[dict], raw: bytes) -> List[Optional[int]]:
    """.data address of each TU's __FILE__ string: the string its anchor functions reference
    that names the file."""
    out: List[Optional[int]] = []
    starts = [f.addr for f in ev.funcs]
    for t in tus:
        hit = None
        for a in t.get("anchor_refs", []):
            i = bisect.bisect_left(starts, a)
            for sec, d in ev.refs.get(i, ()):
                if sec != ".data":
                    continue
                end = raw.find(b"\0", d, d + 128)
                name = raw[d:end].decode("latin-1").replace("\\", "/")
                if name.rsplit("/", 1)[-1] == t["file"]:
                    hit = d if hit is None else min(hit, d)
        out.append(hit)
    return out


def _data_cuts(ev: Evidence, tus: List[dict], cuts: List[int], fstr: List[Optional[int]]) -> Dict[int, Tuple[int, int]]:
    """Per boundary k | k+1 with both __FILE__ strings known: the span (lo, hi] the .data
    boundary must fall in. It lies between the two strings, above every symbol only TU k's
    functions reference there and at or below every one only TU k+1's do."""
    tu_of = {i: k for k in range(len(tus)) for i in range(cuts[k], cuts[k + 1])}
    own: Dict[int, List[int]] = defaultdict(list)
    for (sec, addr), us in ev.users.items():
        ks = {tu_of.get(i) for i in us}
        if sec == ".data" and len(ks) == 1 and None not in ks:
            own[ks.pop()].append(addr)
    out = {}
    for k in range(len(tus) - 1):
        a, b = fstr[k], fstr[k + 1]
        if a is None or b is None or not a < b or ev.data_section.get(tus[k]["data_sec"]) != ".data":
            continue
        lo = max([a] + [x for x in own.get(k, []) if a < x < b])
        hi = min([b] + [x for x in own.get(k + 1, []) if a < x < b])
        if lo < hi:
            out[k] = (lo, hi)
    return out


def _runs(cands: List[int], ok) -> List[Tuple[int, int]]:
    runs: List[Tuple[int, int]] = []
    for c in cands:
        if ok(c):
            if runs and runs[-1][1] == c - 1:
                runs[-1] = (runs[-1][0], c)
            else:
                runs.append((c, c))
    return runs


def analyse(p: Project, module: str, ev: Optional[Evidence] = None) -> Dict[str, object]:
    ev = ev or evidence(p, module)
    tus = _load(p, module)["tus"]
    funcs = ev.funcs
    name_idx = {f.name: i for i, f in enumerate(funcs)}
    starts = [f.addr for f in funcs]
    findings: List[dict] = []

    def note(tu: str, kind: str, detail: str, **extra):
        findings.append({"tu": tu, "kind": kind, "detail": detail, **extra})

    # cuts[k] = index of TU k's first function; cuts[n] = one past the last TU's last
    cuts: List[int] = []
    for k, t in enumerate(tus):
        lo, hi = t["text"]
        i = _index_of(ev, lo)
        if i < 0:
            note(t["file"], "structure", f"text start {lo:#x} is not a function start")
            i = bisect.bisect_left(starts, lo)
        cuts.append(i)
        if hi != funcs[-1].end and _index_of(ev, hi) < 0:
            note(t["file"], "structure", f"text end {hi:#x} is not a function start")
        if k + 1 < len(tus) and hi != tus[k + 1]["text"][0]:
            gap = "overlaps" if hi > tus[k + 1]["text"][0] else "leaves a gap before"
            note(t["file"], "structure", f"text end {hi:#x} {gap} {tus[k + 1]['file']} ({tus[k + 1]['text'][0]:#x})")
    cuts.append(bisect.bisect_left(starts, tus[-1]["text"][1]) if tus else 0)
    name = lambda i: funcs[i].name if i < len(funcs) else "end"

    for k, t in enumerate(tus):
        listed, want = set(t["functions"]), {funcs[i].name for i in range(cuts[k], cuts[k + 1])}
        if listed - want:
            note(t["file"], "membership", "listed outside the text range: " + ", ".join(sorted(listed - want, key=name_idx.get)))
        if want - listed:
            note(t["file"], "membership", "in the text range, not listed: " + ", ".join(sorted(want - listed, key=name_idx.get)))
        stray = [a for a in t.get("anchor_refs", []) if not (t["text"][0] <= a < t["text"][1])]
        if stray:
            note(t["file"], "anchor", "__FILE__ references outside the range: " + ", ".join(f"{a:#x}" for a in stray))

    # string literals are private to their TU, and TU k's .data block lies strictly between
    # the __FILE__ strings of TUs k-1 and k+1
    raw = p._raw_section(module, ".data") or b""
    fstr = _file_strings(ev, tus, raw)
    for k, t in enumerate(tus):
        below = next((fstr[j] for j in range(k - 1, -1, -1) if fstr[j] is not None), None)
        above = next((fstr[j] for j in range(k + 1, len(tus)) if fstr[j] is not None), None)
        bad = []
        for i in range(cuts[k], cuts[k + 1]):
            for sec, d in sorted(ev.refs.get(i, ())):
                if sec == ".data" and _is_string(raw, d) and d not in fstr and (
                        (below is not None and d <= below) or (above is not None and d >= above)):
                    bad.append(f"{funcs[i].name}->{d:#x}")
        if bad:
            note(t["file"], "string", "references string literals outside the TU's .data neighbourhood: " + ", ".join(bad[:8]))

    for k, (lo, hi) in _data_cuts(ev, tus, cuts, fstr).items():
        cur = tus[k + 1]["data"][0]
        if not lo < cur <= hi:
            note(tus[k]["file"], "data", f".data boundary with {tus[k + 1]['file']} at {cur:#x}: data only "
                 f"{tus[k]['file']} references runs to {lo:#x}, data only {tus[k + 1]['file']} references starts at {hi:#x}")

    # boundary k | k+1: the cut lies after TU k's last __FILE__ reference and at or before
    # TU k+1's first one; score every position by data order
    boundaries: Dict[int, dict] = {}
    for k in range(len(tus) - 1):
        a, b = tus[k], tus[k + 1]
        pa = [x for x in (_index_of(ev, y) for y in a.get("anchor_refs", [])) if x >= 0]
        pb = [x for x in (_index_of(ev, y) for y in b.get("anchor_refs", [])) if x >= 0]
        pin_lo, pin_hi = max(pa, default=cuts[k]), min(pb, default=cuts[k + 2] - 1)
        cur = cuts[k + 1]
        if not (pin_lo < cur <= pin_hi):
            note(a["file"], "anchor", f"boundary with {b['file']} at {name(cur)} is outside "
                 f"{name(pin_lo + 1)}..{name(pin_hi)}, the span the __FILE__ references allow")
        lo, hi = min(cuts[k], pin_lo), max(cuts[k + 2], pin_hi + 1)
        cands = list(range(pin_lo + 1, pin_hi + 1))
        if not cands:
            continue
        costs = {c: _cut_cost(ev, lo, hi, c) for c in cands}
        cur_cost = costs.get(cur, _cut_cost(ev, lo, hi, cur))
        best = min(costs.values())
        zero = _runs(cands, lambda c: costs[c] == best)
        span = ", ".join(f"{name(x)}..{name(y)}" if x != y else name(x) for x, y in zero[-3:])
        boundaries[k] = {"cut": cur, "cost": cur_cost, "best": best, "runs": zero, "pins": (pin_lo, pin_hi)}
        shared = []
        for key, us in ev.users.items():
            if key[0] == ".rodata" and min(us) >= lo and max(us) < hi:
                l, r = sum(1 for i in us if i < cur), sum(1 for i in us if i >= cur)
                if min(l, r) >= POOL_FLAG:
                    shared.append(f"{key[1]:#x} ({l}|{r})")
        if shared:
            note(a["file"], "pool", f"boundary with {b['file']} at {name(cur)} splits the users of .rodata "
                 + ", ".join(shared[:6]))
        if cur_cost - best >= CUT_FLAG:
            note(a["file"], "cut", f"boundary with {b['file']} at {name(cur)}: {cur_cost} symbols out of data "
                 f"order; {best} with the cut in {span}")
        elif cur_cost > best:
            note(a["file"], "hint", f"boundary with {b['file']} at {name(cur)}: {cur_cost} symbol out of data "
                 f"order; {best} with the cut in {span}")
    return {"module": module, "findings": findings, "cuts": cuts, "boundaries": boundaries}


def explain(p: Project, module: str, tu_file: str, limit: int = 60) -> List[str]:
    """Per function between the boundary's pins (nearest the current cut first): every data
    symbol it references, as section+address with the users before the window / inside it /
    from the next TU's first pin on. A function whose symbols are shared mostly with one side
    belongs to it."""
    ev = evidence(p, module)
    r = analyse(p, module, ev)
    tus = _load(p, module)["tus"]
    k = next(j for j, t in enumerate(tus) if t["file"] == tu_file)
    bd = r["boundaries"].get(k)
    if bd is None:
        return [f"{tu_file}: no free span between its pins and the next TU's"]
    pin_lo, pin_hi = bd["pins"]
    first = max(pin_lo + 1, bd["cut"] - limit // 2)
    rows = [f"{tu_file} | {tus[k + 1]['file']}: cut at {ev.funcs[bd['cut']].name}, "
            f"free span {ev.funcs[pin_lo + 1].name}..{ev.funcs[pin_hi].name}; counts are users "
            f"before {ev.funcs[first].name} / from there to {ev.funcs[pin_hi].name} / after"]
    for i in range(first, min(pin_hi + 1, first + limit)):
        cells = []
        for sec, addr in sorted(ev.refs.get(i, ())):
            us = ev.users[(sec, addr)]
            cells.append(f"{sec}:{addr:x} {sum(j < first for j in us)}/{sum(first <= j <= pin_hi for j in us)}"
                         f"/{sum(j > pin_hi for j in us)}")
        mark = ">" if i == bd["cut"] else " "
        rows.append(f"{mark} {ev.funcs[i].name:14s} {'  '.join(cells)}")
    return rows


def unit_mismatches(p: Project, module: str, tus: List[dict]) -> List[Tuple[dict, str, str]]:
    """(unit, its tu, the tu its function's address belongs to) for every block unit whose
    TU file disagrees with tus.json text ranges."""
    syms = p.symbols(module)
    prefix = p.module_src_prefix(module)
    out = []
    for u in p.load_units():
        if u["module"] != module or not u.get("tu") or u.get("collapsed"):
            continue
        s = syms.get(u["symbols"][0])
        if s is None:
            continue
        t = next((t for t in tus if t["text"][0] <= s.addr < t["text"][1]), None)
        want = f"{prefix}/{t['file']}" if t else None
        if want and want != u["tu"]:
            out.append((u, u["tu"], want))
    return out


def check(p: Project, module: str = "main_rel") -> Dict[str, object]:
    r = analyse(p, module)
    tus = _load(p, module)["tus"]
    for u, have, want in unit_mismatches(p, module, tus):
        r["findings"].append({"tu": Path(have).name, "kind": "membership",
                              "detail": f"unit {u['symbols'][0]} lives in {have} but its address is in {Path(want).name}"})
    del r["cuts"], r["boundaries"]
    r["flagged"] = sorted({f["tu"] for f in r["findings"] if f["kind"] not in ("hint", "pool")})
    return r


def _decl_chunks(text: str) -> List[str]:
    """Top-level declarations of a prologue, each with its own text: preprocessor lines one
    by one, everything else up to the `;` that closes it at brace depth zero."""
    chunks: List[str] = []
    cur: List[str] = []
    depth = 0
    for ln in text.splitlines():
        if not cur and (not ln.strip() or ln.lstrip().startswith("#")):
            if ln.strip():
                chunks.append(ln)
            continue
        cur.append(ln)
        code = re.sub(r"/\*.*?\*/|//.*$", "", ln)
        depth += code.count("{") - code.count("}")
        if depth == 0 and code.rstrip().endswith((";", "}")) and not code.rstrip().endswith("{"):
            if code.rstrip().endswith("}") and re.match(r"\s*(typedef|struct|union|enum)\b", cur[0]):
                continue  # `typedef struct {...} Name;` closes on a later line
            chunks.append("\n".join(cur))
            cur = []
    if cur:
        chunks.append("\n".join(cur))
    return chunks


C_TYPES = {"void", "int", "char", "float", "double", "long", "short", "unsigned", "signed", "const", "volatile"}


def _declared(chunk: str) -> Set[str]:
    if chunk.lstrip().startswith("#"):
        m = re.match(r"\s*#\s*define\s+(\w+)", chunk)
        return {m.group(1)} if m else set()
    code = re.sub(r"/\*.*?\*/|//[^\n]*", "", chunk, flags=re.S)
    names = set(re.findall(r"\b(?:struct|union|enum)\s+(\w+)\s*\{", code))
    flat = re.sub(r"\{[^{}]*\}", "{}", code)
    while re.search(r"\{[^{}]*\{", flat):
        flat = re.sub(r"\{[^{}]*\}", "{}", flat)
    m = re.search(r"(\w+)\s*\(", flat)  # a function: the name before the first `(`
    if m and m.group(1) in C_TYPES:  # `void (*name)(...)`: a function pointer
        m = re.search(r"\(\s*\*\s*(\w+)\s*\)", flat)
    if m and not flat.lstrip().startswith("typedef struct"):
        names.add(m.group(1))
    m = re.search(r"(\w+)\s*(?:\[[^\]]*\]\s*)*(?:=[^;]*)?;\s*$", flat)
    if m:
        names.add(m.group(1))
    return names - C_TYPES


def _needed_decls(chunks: List[str], body: str) -> List[str]:
    """The prologue declarations a block uses, directly or through other kept declarations;
    preprocessor lines are always kept."""
    words = lambda t: set(re.findall(r"\b\w+\b", t))
    names = [_declared(c) for c in chunks]
    keep = {i for i, c in enumerate(chunks) if c.lstrip().startswith("#")}
    seen = words(body)
    changed = True
    while changed:
        changed = False
        for i, n in enumerate(names):
            if i not in keep and n & seen:
                keep.add(i)
                seen |= words(chunks[i])
                changed = True
    return [c for i, c in enumerate(chunks) if i in keep]


def _header_chunks(include: str) -> Optional[List[str]]:
    """Declarations of a TU header (`#include "rel/<module>/<tu>.h"`), without its guard
    and includes; None for any other include."""
    m = re.match(r'\s*#\s*include\s+"(rel/[^/"]+/[^/"]+\.h)"', include)
    path = ROOT / "include" / m.group(1) if m else None
    if path is None or not path.exists() or path.name == "globals.h":
        return None
    body = [ln for ln in path.read_text().splitlines()
            if not re.match(r"\s*#\s*(ifndef|define\s+\w+_H\w*\s*$|endif|include)", ln)]
    return _decl_chunks("\n".join(body))


def _same_object(p: Project, unit: dict, before: str, after: str) -> bool:
    """Both texts compile, under the unit's flags, to byte-identical objects."""
    from . import oracle
    scratch = p.build_dir / "gen" / "tubounds"
    scratch.mkdir(parents=True, exist_ok=True)
    src, objs = scratch / Path(unit["source"]).name, []
    flags = " ".join(unit.get("extra_cflags") or []) or None
    for k, text in enumerate((before, after)):
        src.write_text(text)
        obj = scratch / f"{src.stem}.{k}.o"
        cp = oracle.compile_source(p, unit["module"], src, obj, unit.get("mw_version"), flags)
        if cp.returncode != 0 or not obj.exists():
            return False
        objs.append(obj.read_bytes())
    return objs[0] == objs[1]


def _moved_block(p: Project, unit: dict, old, dst) -> "tufile.Block":
    """The block to put in the destination TU file: the old body under the destination's
    prologue plus whichever of the old prologue's includes and declarations it uses, if that
    compiles to the same object; else the old generated text verbatim, flagged noprologue."""
    from . import tufile
    name = unit["symbols"][0]
    blk = old.get(name)
    before = tufile.gen_text(old, name)
    if "noprologue" in blk.flags:
        return blk
    includes, _ = tufile.split_includes(old.prologue)
    every = _decl_chunks(tufile.prologue_decls(old))

    def text(inc: List[str], decls: List[str]) -> str:
        parts = (["\n".join(inc)] if inc else []) + (["\n".join(decls)] if decls else [])
        return "\n\n".join(parts + [blk.body.strip("\n")]) + "\n"

    # under the destination's prologue, adding only what it lacks
    inc = [ln for ln in includes if ln.strip() not in {x.strip() for x in dst.prologue.splitlines()}]
    chunks = [c for c in every if c.strip() not in dst.prologue]
    needed = _needed_decls(chunks, blk.body)
    # the old TU's own header, opened up: its declarations would clash with the new TU's
    own = [_header_chunks(ln) for ln in inc]
    own_needed = _needed_decls(chunks + [c for h in own if h for c in h], blk.body)
    other = [ln for ln, h in zip(inc, own) if h is None]
    for extra, decls in (([], needed), (other, own_needed), (inc, needed), (inc, chunks)):
        body = text(extra, decls)
        if _same_object(p, unit, before, dst.prologue + "\n" + body):
            return tufile.Block(name, body, blk.flags)
    # self-contained, when the two prologues' declarations clash
    body = text(includes, _needed_decls(every, blk.body))
    if _same_object(p, unit, before, body):
        return tufile.Block(name, body, blk.flags + ["noprologue"])
    return tufile.Block(name, before, blk.flags + ["noprologue"])


def move_unit(p: Project, unit: dict, new_tu: str) -> str:
    """Move a matched block to another TU file and rename its unit, keeping the compiled
    object byte-identical (checked by compiling both). Returns how the block moved."""
    from . import tufile, tu as tu_mod
    old_tu, name = unit["tu"], unit["symbols"][0]
    old, dst = tufile.load(p, old_tu), tufile.load(p, new_tu)
    if old.get(name) is None:
        raise ValueError(f"{name}: no block in {old_tu}")
    if not (dst.prologue.strip() or dst.blocks):
        dst.prologue = old.prologue
    moved = _moved_block(p, unit, old, dst)
    how = "as is" if moved is old.get(name) else "noprologue" if "noprologue" in moved.flags else "merged"
    old.blocks = [b for b in old.blocks if b.name != name]
    tufile._write_atomic(tufile.tu_path(p, old_tu), old.render())
    dst.blocks = [b for b in dst.blocks if b.name != name] + [moved]
    dst.blocks.sort(key=lambda b: tufile._addr_of(p, unit["module"], b.name))
    tufile._write_atomic(tufile.tu_path(p, new_tu), dst.render())
    tufile.gen_path(p, unit["source"]).unlink(missing_ok=True)
    new_source = f"{Path(new_tu).with_suffix('')}/{Path(unit['source']).name}"
    tu_mod._move_unit(p, unit["module"], unit["source"], new_source)
    units = p.load_units()
    rec = next(u for u in units if u["source"] == new_source)
    rec["tu"] = new_tu
    p.save_units(units)
    tufile.write_gen(p, rec, dst)
    return how


def repair(p: Project, module: str = "main_rel", cuts: Optional[Dict[str, str]] = None,
           move_units: bool = True) -> Dict[str, object]:
    """Rewrite tus.json from its text ranges, with `cuts` ({tu file: first function of the
    next TU}) moving boundaries first: every TU's function list becomes exactly the functions
    in its range, and matched blocks whose TU changes move to the right TU file. The data
    order cannot always tell where a boundary goes, so cuts are reviewed input, not derived
    here. The caller relinks to verify."""
    ev = evidence(p, module)
    r = analyse(p, module, ev)
    d = _load(p, module)
    tus, funcs = d["tus"], ev.funcs
    bounds = list(r["cuts"])
    by_file = {t["file"]: k for k, t in enumerate(tus)}
    for tu_file, first in (cuts or {}).items():
        k, i = by_file[tu_file], next(j for j, f in enumerate(funcs) if f.name == first)
        if k + 1 >= len(tus) or not bounds[k] < i < bounds[k + 2]:
            raise ValueError(f"{tu_file}: {first} is not between its start and the next TU's end")
        bounds[k + 1] = i
    for k, t in enumerate(tus):
        t["text"] = [funcs[bounds[k]].addr, funcs[bounds[k + 1]].addr if bounds[k + 1] < len(funcs) else funcs[-1].end]
        names = [funcs[i].name for i in range(bounds[k], bounds[k + 1])]
        if names != t["functions"]:
            t.pop("confidence", None)  # debug_strings.py's vote counts no longer describe the list
        t["functions"] = names
    fstr = _file_strings(ev, tus, p._raw_section(module, ".data") or b"")
    for k, (lo, hi) in _data_cuts(ev, tus, bounds, fstr).items():
        if not lo < tus[k + 1]["data"][0] <= hi:
            tus[k]["data"][1] = tus[k + 1]["data"][0] = hi
    (p.module_config_dir(module) / "tus.json").write_text(json.dumps(d, indent=1) + "\n")
    if hasattr(p, "_tu_maps"):
        p._tu_maps.pop(module, None)
    moved = []
    if move_units:
        for u, have, want in unit_mismatches(p, module, tus):
            moved.append((u["symbols"][0], have, want, move_unit(p, u, want)))
    return {"moved": moved}
