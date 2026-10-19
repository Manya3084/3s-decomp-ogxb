#!/usr/bin/env python3
"""List the linker aliases a port needs for calls to folded bodies.

Retail's linker folded identical functions into one body (see
analysis-ps2map/folded.json). Where the tree keeps a call by the body's
address (sub_ADDR) because several names share it, the C defines the
body under one of those names only, and sub_ADDR is left undefined. This
script finds every such name the compiled objects (build/obj) reference
and no object defines, and names the defined function at the same
address that it stands for. The relink places sub_ADDR itself; a port's
linker needs the alias:

    python3 tools/fold_aliases.py [--format ld|msvc|list]

ld prints --defsym options for GNU ld (-Wl,--defsym=...), msvc prints
/ALTERNATENAME options (with the cdecl leading underscore). A name no
defined function stands for is listed as a warning.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from objdiff import OBJ
from ogxb import coff

ROOT = Path(__file__).resolve().parent.parent
SYM = ROOT / "config" / "sf33rd" / "symbols"


def names_at() -> dict[int, list[str]]:
    at: dict[int, list[str]] = {}
    for line in (SYM / "funcs.txt").read_text(errors="replace").splitlines():
        m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);", line)
        if m:
            at.setdefault(int(m[2], 16), []).append(m[1])
    for a, ns in json.loads((ROOT / "analysis-ps2map" / "folded.json").read_text()).items():
        at.setdefault(int(a, 16), []).extend(ns)
    return at


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--format", choices=("ld", "msvc", "list"), default="list")
    a = ap.parse_args()
    defined: set[str] = set()
    undef: set[str] = set()
    for p in Path(OBJ).rglob("*.obj"):
        for s in coff.read(p.read_bytes()).symbols.values():
            n = coff.undecorate(s.name)
            if s.section > 0 and s.storage == 2:
                defined.add(n)
            elif s.section == 0 and s.storage == 2:
                undef.add(n)
    at = names_at()
    bad = 0
    for n in sorted(undef - defined):
        m = re.fullmatch(r"sub_([0-9A-F]{8})", n)
        if not m:
            continue
        to = [t for t in at.get(int(m[1], 16), []) if t in defined]
        if not to:
            print(f"warning: {n}: no defined function at 0x{int(m[1], 16):X}", file=sys.stderr)
            bad += 1
            continue
        if a.format == "ld":
            print(f"--defsym={n}={to[0]}")
        elif a.format == "msvc":
            print(f"/ALTERNATENAME:_{n}=_{to[0]}")
        else:
            print(f"{n} {to[0]}")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
