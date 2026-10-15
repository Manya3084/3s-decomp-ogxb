#!/usr/bin/env python3
"""List .xvu vertex programs and reject files whose size does not match the header."""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.paths import find_shaders
from ogxb.xvs import list_shaders


def main() -> int:
    directory = find_shaders()
    if directory is None or not directory.is_dir():
        print("shader directory not found. Set SF33RD_SHADERS.", file=sys.stderr)
        return 1
    programs, other = list_shaders(directory)
    counts = [item.count for item in programs]
    print(f"dir   {directory}")
    print(f"xvu   {len(programs)}  instructions {min(counts)}..{max(counts)}")
    print(f"other {len(other)}")
    for path in other:
        if path.suffix.lower() == ".xvu":
            print(f"  bad {path.name}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
