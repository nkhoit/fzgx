F-Zero GX
[![Build Status]][actions] [![Code Progress]][actions] [![DOL Progress]][actions] [![RELs Progress]][actions] [![Data Progress]][actions] [![Discord Badge]][discord]
=========

[Build Status]: https://github.com/nkhoit/fzgx/actions/workflows/build.yml/badge.svg
[actions]: https://github.com/nkhoit/fzgx/actions/workflows/build.yml
[Code Progress]: https://img.shields.io/endpoint?url=https%3A%2F%2Fraw.githubusercontent.com%2Fnkhoit%2Ffzgx%2Fbadges%2Fcode.json
[DOL Progress]: https://img.shields.io/endpoint?url=https%3A%2F%2Fraw.githubusercontent.com%2Fnkhoit%2Ffzgx%2Fbadges%2Fdol.json
[RELs Progress]: https://img.shields.io/endpoint?url=https%3A%2F%2Fraw.githubusercontent.com%2Fnkhoit%2Ffzgx%2Fbadges%2Frels.json
[Data Progress]: https://img.shields.io/endpoint?url=https%3A%2F%2Fraw.githubusercontent.com%2Fnkhoit%2Ffzgx%2Fbadges%2Fdata.json
[Discord Badge]: https://img.shields.io/discord/727908905392275526?color=%237289DA&logo=discord&logoColor=%23FFFFFF
[discord]: https://discord.gg/hKx3FJJgrV

A work-in-progress matching decompilation of F-Zero GX for the Nintendo GameCube.

This repository does **not** contain any game assets, assembly or binaries. An existing copy of the game is required; functions that are not decompiled yet are linked from your own copy at build time.

Supported versions:

- `GFZE01`: Rev 0 (USA) — primary
- `GFZP01`: Rev 0 (PAL) — configuration scaffold only
- `GFZJ01`: Rev 0 (JPN) — configuration scaffold only

What is being matched
=====================

The disc ships sixteen executables and this project rebuilds every one of them byte for byte:

| Target | Role |
|---|---|
| `sys/main.dol` | Loader and engine core: Dolphin SDK, MSL, MetroTRK, CRI ADX, AX |
| `main.rel` | Almost half of all code: physics, racing, machines, AI, in-race logic. Not on the disc as a file: it is the encrypted, LZ-compressed archive `files/enemy_line/line__.bin`, which `tools/prepare_orig.py` decrypts and decompresses |
| `files/fze.*.rel` (14) | Title, selection, customise, story, ranking, replay, memory card, movie and other screens |
| `files/fze.sample.rel` | The stub that locates, decrypts and links `main.rel` |

`ninja` ends with `16 files OK` when every target hashes identically to the retail files.

Source is organised by recovered translation unit. main.rel embeds its original file names (`camera.c`, `coli.c`, `car.c`, `driver.c`, `enemy_ctrl.c`, ...), and the order of those strings in `.data` matches the order of the code that references them, so each function is placed under `src/rel/main_rel/<file>/`. Struct layouts for the most-referenced globals are recovered from every access in the disassembly and generated into `include/rel/main_rel/globals.h`, with every field offset proven under the original compiler.

Status
======

Current progress is shown by the badges above. Roughly 30% of the code is matched; the rest is
linked from your own copy of the game at build time.

What remains is mostly mid-sized and large game logic in `main.rel` (machines, collision,
effects, course and menu code). Most small functions are already done. Two problems account for
most of the functions that are close but not finished:

- **Register allocation.** Many near-misses (95–99.9%) differ only in which registers MWCC picks
  or in the order of a few independent instructions. These usually need a different but
  equivalent way of writing the same C (declaration order, temporaries, types).
- **Shared literal pools.** About 840 unmatched functions read float constants from a pool that
  is shared by the whole original source file. Compiled on their own they get a private pool
  and every constant offset differs. `tools/fzgx.py fixup` can generate a *pool primer* that
  reproduces the original layout (see [docs/MWCC_IDIOMS.md](docs/MWCC_IDIOMS.md), "Literal pool
  base"); once a whole source file is matched it can be compiled as one unit and the primers go
  away.

Good places to start are source files that already have many matched functions, such as
`car.c`, `effect.c` and the selection screens: their structs and helper functions are already
recovered, so the next function in the same file is usually much easier.

Dependencies
============

Windows
--------

On Windows, it's **highly recommended** to use native tooling. WSL or msys2 are **not** required.  
When running under WSL, [objdiff](#diffing) is unable to get filesystem notifications for automatic rebuilds.

- Install [Python](https://www.python.org/downloads/) and add it to `%PATH%`.
  - Also available from the [Windows Store](https://apps.microsoft.com/store/detail/python-311/9NRWMJP3717K).
- Download [ninja](https://github.com/ninja-build/ninja/releases) and add it to `%PATH%`.
  - Quick install via pip: `pip install ninja`

macOS
------

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages):

  ```sh
  brew install ninja
  ```

[wibo](https://github.com/decompals/wibo), a minimal 32-bit Windows binary wrapper, will be automatically downloaded and used (under Rosetta 2 on Apple Silicon).

Linux
------

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages).

[wibo](https://github.com/decompals/wibo), a minimal 32-bit Windows binary wrapper, will be automatically downloaded and used.

All platforms
-------------

- Install [uv](https://docs.astral.sh/uv/) for the project tooling (`tools/`).

Building
========

- Clone the repository:

  ```sh
  git clone https://github.com/nkhoit/fzgx.git
  ```

- Copy your game's disc image to `orig/` (not `orig/GFZE01/`).
  - Supported formats: ISO (GCM), RVZ, WIA, WBFS, CISO, NFS, GCZ, TGC
  - `dtk disc verify` should report a Redump match.

- Extract the targets and derive `main.rel`:

  ```sh
  uv run tools/prepare_orig.py --version GFZE01
  ```

  This pulls the sixteen targets out of the image into `orig/GFZE01/`, decrypts and decompresses `line__.bin`, and prints the SHA-1 of each target. The disc image can be deleted afterwards.

- Configure:

  ```sh
  python configure.py
  ```

  The compilers are downloaded from `files.decomp.dev` by default. If that
  download is unavailable, pass a local copy of the GameCube Metrowerks
  compilers with `--compilers <dir>` (the directory containing `GC/`).

  To use a version other than `GFZE01` (USA), specify it with `--version`.

- Build:

  ```sh
  ninja
  ```

Diffing
=======

Once the initial build succeeds, an `objdiff.json` should exist in the project root.

Download the latest release from [encounter/objdiff](https://github.com/encounter/objdiff). Under project settings, set `Project directory`. The configuration should be loaded automatically.

Select an object from the left sidebar to begin diffing. Changes to the project will rebuild automatically: changes to source files, headers, `configure.py`, `splits.txt` or `symbols.txt`.

Contributing
============

See [CONTRIBUTING.md](CONTRIBUTING.md). In short: one function per change, matched and link-verified through `tools/fzgx.py`, no hardcoded addresses, no inline assembly, readable C. Questions and discussion: the [GC/Wii Decompilation Discord][discord], `#dtk`.

Credits
=======

This project builds on [rayanht/fzgx](https://github.com/rayanht/fzgx), whose CC0-licensed source, recovered types, build configuration, tooling and matched code form the foundation of this repository. It was imported as a new repository at commit `3a0542c` rather than forked. It also incorporates matching work from an earlier private F-Zero GX decompilation effort.

See [docs/RESOURCES.md](docs/RESOURCES.md). This project stands on [decomp-toolkit](https://github.com/encounter/decomp-toolkit), [objdiff](https://github.com/encounter/objdiff), [wibo](https://github.com/decompals/wibo) and [dtk-template](https://github.com/encounter/dtk-template) by encounter and the decompals community, on CosmoCortney's [Line__Crypt](https://github.com/CosmoCortney/Line__Crypt) and bobjrsenior's [SMB_LZ_Tool](https://github.com/bobjrsenior/SMB_LZ_Tool) for the `line__.bin` format, and on a decade of format work by the F-Zero GX modding community.

License
=======

The source code and tooling in this repository are released under [CC0 1.0](LICENSE). F-Zero GX is © Nintendo / Sega / Amusement Vision; no game data is distributed here.
