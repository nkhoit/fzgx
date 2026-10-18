# GitHub Actions

CI builds every push and checks that all 16 output files are byte-identical to
retail (`ninja` fails on any SHA-1 mismatch), then uploads `report.json`.

## Build inputs

The game files are not in this repository. CI fetches the extracted
`orig/GFZE01` files and the Metrowerks compilers from the private repository
`nkhoit/fzgx-build` using a read-only deploy key stored as the Actions secret
`FZGX_BUILD_DEPLOY_KEY`. Only the extracted files the build needs are stored
there, never a disc image. The compilers are mirrored because their usual
download host, decomp.dev, is being shut down.

## Progress badges

On every push to `main`, the `badges` job turns the build's `report.json` into
shields.io endpoint files (`code.json`, `dol.json`, `rels.json`, `data.json`)
and force-pushes them, with the report, to the `badges` branch. The README
badges read those files, so they only render while the repository is public.

Pull requests from forks do not receive secrets, so their CI run stops with a
notice and a maintainer builds the change locally or on a branch in this
repository.

## Rotating the key

1. `ssh-keygen -t ed25519 -N "" -f fzgx-ci-key`
2. Add `fzgx-ci-key.pub` as a read-only deploy key on `nkhoit/fzgx-build` and
   remove the old one.
3. `gh secret set FZGX_BUILD_DEPLOY_KEY -R nkhoit/fzgx < fzgx-ci-key`
4. Delete both local key files.
