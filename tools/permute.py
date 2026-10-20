#!/usr/bin/env python3
"""decomp-permuter for MWCC: set up and run a permuter directory for one function.

    python3 tools/permute.py setup fn_1_D2404 --body path/to/body.c
    python3 tools/permute.py run fn_1_D2404 -j4 --best-only --stop-on-zero

`setup` writes build/permuter/<symbol>/ with:
  base.c      the body, preprocessed (gcc -E -P) so pycparser can read it
  target.o    the retail split object dtk wrote for the function
  compile.sh  wibo + mwcceppc with the function's module flags and unit overrides
  settings.toml

`run` fetches decomp-permuter (pinned) into build/tools/, finds a PowerPC objdump
and starts permuter.py on the directory; extra arguments go to permuter.py.
Candidates that score better land in build/permuter/<symbol>/output-<score>-<n>/.

Scores are permuter scores, not objdiff percentages: 0 is a match, and a register
swap costs 5 per instruction. Literal-pool relocations are not rewritten by
poolfix here, so a function that loads float constants keeps a constant penalty
from the `@N` vs `lbl_*` names; it does not change which candidate is better.
"""

import argparse
import os
import shlex
import shutil
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from fzgx import oracle  # noqa: E402
from fzgx.project import Project, ROOT  # noqa: E402

PERMUTER_URL = "https://github.com/simonlindholm/decomp-permuter"
PERMUTER_REV = "8556c81d80d1c1af98a858c8f4dc951357f29139"
PERMUTER_DIR = ROOT / "build" / "tools" / "decomp-permuter"
OBJDUMPS = ["powerpc-eabi-objdump", "powerpc-linux-gnu-objdump"]
OBJDUMP_APT = "binutils-powerpc-linux-gnu"


def perm_dir(symbol: str) -> Path:
    return ROOT / "build" / "permuter" / symbol


def find_objdump() -> str:
    for name in OBJDUMPS:
        local = ROOT / "build" / "binutils" / name
        if local.exists():
            return str(local)
        hit = shutil.which(name)
        if hit:
            return hit
    if os.geteuid() == 0 and shutil.which("apt-get"):
        print(f"installing {OBJDUMP_APT} for a PowerPC objdump", file=sys.stderr)
        if subprocess.run(["apt-get", "install", "-y", "-q", OBJDUMP_APT],
                          stdout=subprocess.DEVNULL).returncode != 0:
            subprocess.run(["apt-get", "update", "-q"], stdout=subprocess.DEVNULL)
            subprocess.run(["apt-get", "install", "-y", "-q", OBJDUMP_APT], stdout=subprocess.DEVNULL)
        hit = shutil.which("powerpc-linux-gnu-objdump")
        if hit:
            return hit
    sys.exit(f"no PowerPC objdump found; install {OBJDUMP_APT} (or powerpc-eabi binutils)")


def ensure_permuter() -> Path:
    if not (PERMUTER_DIR / "permuter.py").exists():
        PERMUTER_DIR.parent.mkdir(parents=True, exist_ok=True)
        subprocess.run(["git", "clone", "-q", PERMUTER_URL, str(PERMUTER_DIR)], check=True)
    head = subprocess.run(["git", "-C", str(PERMUTER_DIR), "rev-parse", "HEAD"],
                          capture_output=True, text=True).stdout.strip()
    if head != PERMUTER_REV:
        subprocess.run(["git", "-C", str(PERMUTER_DIR), "fetch", "-q", "origin", PERMUTER_REV], check=False)
        subprocess.run(["git", "-C", str(PERMUTER_DIR), "checkout", "-q", PERMUTER_REV], check=True)
    return PERMUTER_DIR


def compile_script(project: Project, sym):
    mw, extra = oracle.version_for(project, sym)
    cmd = [a for a in oracle.compile_command(project, sym.module, mw, extra) if a != "-nofail"]
    defines = [a for a in cmd if a.startswith("-D")]
    return ("#!/bin/bash\n"
            "# decomp-permuter compile script: $1 = input .c, $3 = output .o\n"
            'in=$(realpath "$1"); out=$(realpath -m "$3")\n'
            f"cd {shlex.quote(str(ROOT))} || exit 1\n"
            f"exec {shlex.join(cmd)} \"$in\" -o \"$out\"\n"), defines


def cmd_setup(args) -> int:
    project = Project()
    sym = project.find_symbol(args.symbol)
    if not sym:
        sys.exit(f"unknown symbol {args.symbol}")
    target = project.target_object_for(sym)
    if not target or not target.exists():
        sys.exit(f"no retail object for {args.symbol}; run ninja first")
    body = Path(args.body) if args.body else None
    if body is None:
        unit = project.unit_of(sym)
        if not unit:
            sys.exit(f"{args.symbol} has no carved unit; pass --body")
        body = oracle.unit_source_path(project, unit)
    d = Path(args.dir) if args.dir else perm_dir(args.symbol)
    if d.exists() and any(d.iterdir()) and not args.force:
        sys.exit(f"{d} already exists; pass --force to overwrite")
    d.mkdir(parents=True, exist_ok=True)

    script, defines = compile_script(project, sym)
    pre = subprocess.run(["gcc", "-E", "-P", "-nostdinc", "-I", str(ROOT / "include"),
                          "-I", str(project.build_dir / "include"), *defines, str(body.resolve())],
                         capture_output=True, text=True)
    if pre.returncode != 0:
        sys.exit(f"preprocessing {body} failed:\n{pre.stderr}")
    (d / "base.c").write_text(pre.stdout)
    shutil.copyfile(body, d / "orig.c")
    shutil.copyfile(target, d / "target.o")
    (d / "compile.sh").write_text(script)
    (d / "compile.sh").chmod(0o755)
    (d / "settings.toml").write_text(
        f'func_name = "{sym.name}"\n'
        'compiler_type = "mwcc"\n'
        f'objdump_command = "{find_objdump()} -dr -EB -mpowerpc -M broadway"\n')

    probe = subprocess.run([str(d / "compile.sh"), str(d / "base.c"), "-o", str(d / "base.o")],
                           capture_output=True, text=True)
    if probe.returncode != 0 or not (d / "base.o").exists():
        sys.exit(f"base.c does not compile:\n{probe.stdout}{probe.stderr}")
    print(d)
    return 0


def cmd_run(args, extra) -> int:
    d = Path(args.target)
    if not d.is_dir():
        d = perm_dir(args.target)
    if not (d / "base.c").exists():
        sys.exit(f"{d} is not set up; run `permute.py setup {args.target}` first")
    find_objdump()
    root = ensure_permuter()
    return subprocess.run([sys.executable, str(root / "permuter.py"), str(d), *extra]).returncode


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("setup", help="write build/permuter/<symbol>/ for one function")
    s.add_argument("symbol")
    s.add_argument("--body", help="C file holding the function (default: its carved unit)")
    s.add_argument("--dir", help="permuter directory (default: build/permuter/<symbol>)")
    s.add_argument("--force", action="store_true", help="overwrite an existing directory")
    s = sub.add_parser("run", help="run decomp-permuter; extra arguments go to permuter.py")
    s.add_argument("target", help="symbol or permuter directory")
    args, extra = ap.parse_known_args()
    if args.cmd == "setup":
        if extra:
            ap.error(f"unrecognized arguments: {' '.join(extra)}")
        return cmd_setup(args)
    return cmd_run(args, extra)


if __name__ == "__main__":
    sys.exit(main())
