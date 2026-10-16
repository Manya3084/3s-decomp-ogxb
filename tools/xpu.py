#!/usr/bin/env python3
"""List .xpu combiner programs, or disassemble the files named on the command line."""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.paths import find_shaders
from ogxb.xpu import format_program, list_xpu, parse_xpu


def disassemble(paths: list[str]) -> int:
    status = 0
    for arg in paths:
        path = Path(arg)
        blob = path.read_bytes()
        shader = parse_xpu(blob)
        if shader is None:
            print(f"bad {path.name}", file=sys.stderr)
            status = 1
            continue
        print(f"{path.name}  {len(blob)}")
        print(format_program(shader))
    return status


def summarize() -> int:
    directory = find_shaders()
    if directory is None or not directory.is_dir():
        print("shader directory not found. Set SF33RD_SHADERS.", file=sys.stderr)
        return 1
    found, bad = list_xpu(directory)
    print(f"xpu   {len(found)}")
    for path, shader in found:
        print(f"  {path.name}  stages {shader.stages}")
    for path in bad:
        print(f"  bad {path.name}")
    return 1 if bad else 0


def main() -> int:
    if len(sys.argv) > 1:
        return disassemble(sys.argv[1:])
    return summarize()


if __name__ == "__main__":
    raise SystemExit(main())
