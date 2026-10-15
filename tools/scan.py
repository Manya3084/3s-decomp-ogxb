#!/usr/bin/env python3
"""Write function starts, kernel imports, strings, and xrefs under build/sf33rd/."""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.cap import Disassembler
from ogxb.funcs import containing, function_sizes, function_starts
from ogxb.krnl import load_ordinals
from ogxb.paths import BUILD, find_xbe
from ogxb.strings import c_strings, imm_sites
from ogxb.xbe import load


def main() -> int:
    path = find_xbe()
    if path is None or not path.is_file():
        print("sf33rd.xbe not found. Set SF33RD_XBE or write xbe.path.", file=sys.stderr)
        return 1
    image = load(path)
    text, blob = image.text
    with Disassembler() as dis:
        starts = function_starts(blob, text.va, image.entry, dis)
    sized = function_sizes(starts, text.va, text.raw_size)
    names = load_ordinals()
    sites = imm_sites(blob, text.va)
    strings = []
    for section in image.sections:
        if section.name not in (".rdata", ".data", ".text"):
            continue
        raw = image.data[section.raw : section.raw + section.raw_size]
        strings.extend(c_strings(raw, section.va))

    BUILD.mkdir(parents=True, exist_ok=True)
    func_lines = [
        f"# {len(sized)} starts in {text.name} {text.va:#x} size {text.raw_size:#x}",
        "# size is the distance to the next start and can include a jump table",
    ]
    for va, size in sized:
        func_lines.append(f"{va:#010x} size:{size:#x}")
    (BUILD / "functions.txt").write_text("\n".join(func_lines) + "\n")

    import_lines = [f"# {len(image.imports)} kernel imports at {image.thunk_va:#x}"]
    for item in image.imports:
        name, argbytes, convention = names.get(item.ordinal, ("?", 0, "?"))
        import_lines.append(f"{item.va:#010x} {item.ordinal:3d} {name} {convention} {argbytes}")
    (BUILD / "imports.txt").write_text("\n".join(import_lines) + "\n")

    string_lines = []
    xref_lines = ["# va kind function string"]
    referenced = 0
    for va, text_s in strings:
        hits = sites.get(va, [])
        string_lines.append(f"{va:#010x} {len(hits):3d} {text_s}")
        if not hits:
            continue
        referenced += 1
        for site, kind in hits:
            owner = containing(starts, site)
            owner_s = f"{owner:#010x}" if owner is not None else "-"
            xref_lines.append(f"{site:#010x} {kind:4} {owner_s} {text_s}")
    (BUILD / "strings.txt").write_text("\n".join(string_lines) + "\n")
    (BUILD / "xrefs.txt").write_text("\n".join(xref_lines) + "\n")
    print(f"starts {len(sized)}")
    print(f"strings {len(strings)} referenced {referenced}")
    print(f"wrote {BUILD}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
