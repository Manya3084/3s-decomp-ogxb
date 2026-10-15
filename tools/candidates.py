#!/usr/bin/env python3
"""Suggest names. Writes build/sf33rd/candidates.txt and does not touch funcs.txt.

A suggestion is recorded when one function references the string. A path is a
file anchor. Text in parentheses is a possible function name. When the PS2
sources are available, a string owned by one PS2 function is labeled with that
name. None of these lines is a confirmed Xbox name.
"""

from __future__ import annotations

import os
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.cap import Disassembler
from ogxb.funcs import containing, function_starts
from ogxb.paths import BUILD, ROOT, find_xbe
from ogxb.strings import c_strings, imm_sites
from ogxb.xbe import load

PAREN = re.compile(r"\(([A-Za-z_][A-Za-z0-9_]{2,})\)")
FUNC_DEF = re.compile(
    r"^(?:static\s+)?(?:inline\s+)?[\w*][\w\s*]+\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*\)\s*\{?\s*$"
)
LITERAL = re.compile(r'"((?:\\.|[^"\\])*)"')


def ps2_root() -> Path | None:
    env = os.environ.get("PS2_SRC")
    if env:
        path = Path(env)
        return path if path.is_dir() else None
    pointer = ROOT / "ps2.path"
    if pointer.is_file():
        line = pointer.read_text().strip()
        if line:
            path = Path(line)
            return path if path.is_dir() else None
    return None


def ps2_owners(root: Path) -> dict[str, set[str]]:
    owners: dict[str, set[str]] = {}
    for path in root.rglob("*.c"):
        current = None
        for line in path.read_text(errors="replace").splitlines():
            defined = FUNC_DEF.match(line)
            if defined and "(" in line and not line.strip().endswith(";"):
                current = defined.group(1)
            if current is None:
                continue
            for raw in LITERAL.findall(line):
                try:
                    value = bytes(raw, "utf-8").decode("unicode_escape")
                except UnicodeDecodeError:
                    value = raw
                value = value.split("\x00", 1)[0]
                if len(value) < 6 or not value.isascii():
                    continue
                owners.setdefault(value, set()).add(current)
    return owners


def main() -> int:
    path = find_xbe()
    if path is None or not path.is_file():
        print("sf33rd.xbe not found. Set SF33RD_XBE or write xbe.path.", file=sys.stderr)
        return 1
    image = load(path)
    text, blob = image.text
    with Disassembler() as dis:
        starts = function_starts(blob, text.va, image.entry, dis)
    sites = imm_sites(blob, text.va)
    owners_by_string: dict[str, set[int]] = {}
    literals: dict[str, int] = {}
    for section in image.sections:
        if section.name not in (".rdata", ".data"):
            continue
        raw = image.data[section.raw : section.raw + section.raw_size]
        for va, literal in c_strings(raw, section.va):
            funcs = {owner for site, _kind in sites.get(va, []) if (owner := containing(starts, site))}
            if not funcs:
                continue
            owners_by_string.setdefault(literal, set()).update(funcs)
            literals.setdefault(literal, va)

    ps2 = ps2_root()
    ps2_map = ps2_owners(ps2) if ps2 is not None else {}
    lines = [
        "# suggestions only. do not copy these into config/sf33rd/symbols/funcs.txt",
        "# until the body matches. one reference, and a PS2 name when the string has one owner there.",
    ]
    if ps2 is not None:
        lines.append(f"# ps2 sources {ps2}")
    kept = 0
    for literal, funcs in sorted(owners_by_string.items(), key=lambda item: min(item[1])):
        if len(funcs) != 1:
            continue
        owner = next(iter(funcs))
        kind = "string"
        detail = ""
        if ".c" in literal or ".cpp" in literal or ".h" in literal:
            kind = "file"
            detail = Path(literal.replace("\\", "/")).name
        names = PAREN.findall(literal)
        if names:
            kind = "paren"
            detail = ",".join(names)
        ps2_name = ""
        owners = ps2_map.get(literal, set())
        if len(owners) == 1:
            ps2_name = next(iter(owners))
        if kind == "string" and not ps2_name:
            continue
        shown = literal if len(literal) <= 120 else literal[:117] + "..."
        lines.append(f"{owner:#010x}\t{kind}\t{ps2_name or '-'}\t{detail or '-'}\t{shown}")
        kept += 1
    BUILD.mkdir(parents=True, exist_ok=True)
    (BUILD / "candidates.txt").write_text("\n".join(lines) + "\n")
    print(f"candidates {kept}")
    print(f"wrote {BUILD / 'candidates.txt'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
