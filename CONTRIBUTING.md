# Contributing

Everything in this repository goes through the same oracle: a unit is accepted when
every function in it assembles to the retail bytes, the data sections are equal, lint
passes, and the full link of all sixteen targets still hashes identical. That is true
for every contribution, however it was produced.

## The loop

```sh
uv run tools/fzgx.py sync                              # once: load the function inventory
uv run tools/fzgx.py inventory --module main_rel --status unmatched --max-size 128
uv run tools/fzgx.py claim fn_1_XXXX --name <you>     # carves src/rel/main_rel/<tu>/fn_1_XXXX.c, prints the context bundle
# edit the unit (or: uv run tools/fzgx.py write-unit fn_1_XXXX --name <you> --file body.c, which also checks)
uv run tools/fzgx.py check fn_1_XXXX                   # compiles the unit, diffs it against retail
uv run tools/fzgx.py submit fn_1_XXXX --name <you> --message "what it does"
uv run tools/fzgx.py verify                            # relinks once, verifies every hash, commits pending units
```

`check` shows a `target | ours` instruction diff. `check --versions all` compiles under
every CodeWarrior version we ship, which is how per-unit compiler versions are recorded
(`--mw-version` on submit). If you give up, `release --reason "..."` keeps your best body
for the next attempt.

`quick fn_1_XXXX scratch.c` is the scratch loop: it compiles any C file with the module's
flags (wibo + mwcceppc, no ninja) and prints the same diff, without a claim, ledger entry
or build lock. `verify --trailer "Co-Authored-By: ..."` (or `FZGX_COMMIT_TRAILERS`, one
trailer per line, which `tu-finish` and `trivial` also use) adds trailers to the auto-commit.

For a body that is down to register or scheduling differences, run decomp-permuter on it:

```sh
python3 tools/permute.py setup fn_1_XXXX --body body.c   # writes build/permuter/fn_1_XXXX/
python3 tools/permute.py run fn_1_XXXX -j4 --best-only --stop-on-zero
```

`run` fetches the permuter into `build/tools/` and installs a PowerPC objdump if none is
found. Better candidates land in `build/permuter/fn_1_XXXX/output-<score>-<n>/source.c`;
a score of 0 is a match, then `check` it as usual.

## Rules (enforced by `fzgx lint` and `submit`)

- No integer literal in `0x80000000..0x817FFFFF`, `0xC0000000..0xC17FFFFF` or
  `0xCC000000..0xCC00FFFF` outside `include/dolphin/hw_regs.h`. Every cross-reference is
  a symbol; the tree must stay shiftable.
- No inline assembly, no `.s` files for code. Unmatched code stays in decomp-toolkit's
  split objects.
- `goto`, `volatile` and codegen-only `union` need a one-line justification comment.
- Use the shared types: `#include "rel/<module>/globals.h"` and its recovered struct
  fields (`unk_XX` names are offsets, and the offsets are verified) instead of casts and
  pointer arithmetic on globals.
- Keep names as they are in a matching change. Renames go through `fzgx rename` or a
  naming proposal, which apply everywhere and relink-verify.
- Reference code adapted from Dolphin SDK decompilations is welcome; credit the source
  in `docs/RESOURCES.md`. Do not copy from projects without a licence.

Full rules: `docs/CODING_RULES.md`. Compiler idioms that unblocked functions before:
`docs/MWCC_IDIOMS.md`.

## Structure

- `src/dol/` — main.dol units; `src/rel/<module>/<tu>/` — REL units grouped by recovered
  translation unit (`config/GFZE01/main_rel/tus.json`).
- `include/rel/<module>/globals.h` — generated (`fzgx headers`), never hand-edited: regenerate.
- `config/GFZE01/` — decomp-toolkit configuration; `units.json` lists every C unit and is
  maintained by the tools.
