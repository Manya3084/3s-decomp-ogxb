#!/usr/bin/env python3
"""Print the identity of sf33rd.xbe."""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.krnl import load_ordinals
from ogxb.paths import find_xbe
from ogxb.xbe import load


def main() -> int:
    path = find_xbe()
    if path is None or not path.is_file():
        print("sf33rd.xbe not found. Set SF33RD_XBE or write xbe.path.", file=sys.stderr)
        return 1
    image = load(path)
    text, _ = image.text
    print(f"file     {image.path}")
    print(f"size     {len(image.data)}")
    print(f"title    {image.title_id:#010x} {image.title}")
    print(f"keys     {image.key_kind}")
    print(f"built    {image.built:%Y-%m-%d %H:%M:%S} UTC")
    print(f"xdk      {image.xdk_build}")
    print(f"entry    {image.entry:#010x}")
    print(f"text     {text.va:#010x} size {text.raw_size:#x}")
    print(f"thunk    {image.thunk_va:#010x} imports {len(image.imports)}")
    print(f"debug    {image.debug_path}")
    print(f"pdb      age {image.rsds_age} {image.rsds_path}")
    names = load_ordinals()
    missing = [item.ordinal for item in image.imports if item.ordinal not in names]
    print(f"ordinals {len(image.imports) - len(missing)} named, {len(missing)} unnamed")
    print("sections")
    for item in image.sections:
        print(f"  {item.name:16} {item.va:#010x} {item.raw_size:#08x}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
