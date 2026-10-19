#!/bin/bash
# Prepares a Claude Code cloud session to build and match: retail inputs and
# compilers come from the private nkhoit/fzgx-build repository, exactly as CI
# does (see docs/github_actions.md). Without access to it the session still
# starts; only building and checking are unavailable.
set -euo pipefail

if [ "${CLAUDE_CODE_REMOTE:-}" != "true" ]; then
    exit 0
fi

cd "$CLAUDE_PROJECT_DIR"
VERSION=GFZE01
INPUTS="$(dirname "$CLAUDE_PROJECT_DIR")/fzgx-build"

if [ ! -d "$INPUTS/.git" ]; then
    if ! git clone --depth 1 https://github.com/nkhoit/fzgx-build "$INPUTS" >/dev/null 2>&1; then
        echo "fzgx-build is not available to this session; skipping build setup." >&2
        exit 0
    fi
fi

(cd "$INPUTS/$VERSION" && sha1sum -c ../SHA1SUMS --quiet)
mkdir -p orig
if [ ! -d "orig/$VERSION/sys" ]; then
    cp -a "$INPUTS/$VERSION" orig/
fi

command -v ninja >/dev/null || pip install -q ninja
uv sync -q

python3 configure.py --version "$VERSION" --compilers "$INPUTS/compilers" >/dev/null
# tools/fzgx.py compiles single units against build/compilers directly
ln -sfn "$INPUTS/compilers" build/compilers
ninja >/dev/null
