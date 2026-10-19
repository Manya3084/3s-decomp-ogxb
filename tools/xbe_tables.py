#!/usr/bin/env python3
"""Write the tables the C uses but does not define, from the XBE, as C.

The tree's C declares some initialized tables without defining them: the
character tables the PS2 build also takes from the game binary, the staff
roll, a few Xbox-only tables, the Live strings, and the XDK's data. They
are not in the tree. A port that does not map sf33rd.xbe's data at its own
addresses can take them from its own XBE with this script: it lists every
global the compiled objects (build/obj) reference and no object defines,
keeps those data.txt (or a D_ADDR name) places in initialized data, and
writes each as a byte array to build/xbe_tables.c.

The bytes are the XBE's. A word that holds an address inside the image may
be a pointer, which is only right where the image is mapped at its own
addresses; each table whose words look like that is listed in the file's
header for review. Zero-initialized globals are left out (they need only
storage).

    python3 tools/xbe_tables.py [-o build/xbe_tables.c]
"""

from __future__ import annotations

import argparse
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from objdiff import OBJ
from ogxb import coff
from ogxb.paths import find_xbe
from ogxb.xbe import load

ROOT = Path(__file__).resolve().parent.parent
SYM = ROOT / "config" / "sf33rd" / "symbols"


def names_and_sizes() -> tuple[set[str], dict[str, tuple[int, int]]]:
    funcs: set[str] = set()
    for f in ("funcs.txt", "xdk.txt"):
        for line in (SYM / f).read_text(errors="replace").splitlines():
            m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);(.*)", line)
            if m and (f == "funcs.txt" or "func" in m[3]):
                funcs.add(m[1])
    data: dict[str, tuple[int, int]] = {}
    for line in (SYM / "data.txt").read_text().splitlines():
        m = re.match(r"(\S+) = 0x([0-9A-F]+); // type:data(?: size:0x([0-9A-F]+))?", line)
        if m:
            data[m[1]] = (int(m[2], 16), int(m[3], 16) if m[3] else 4)
    return funcs, data


def undefined_data(funcs: set[str]) -> set[str]:
    defined: set[str] = set()
    undef: set[str] = set()
    for p in Path(OBJ).rglob("*.obj"):
        obj = coff.read(p.read_bytes())
        for s in obj.symbols.values():
            n = coff.undecorate(s.name)
            if s.section > 0:
                defined.add(n)
            elif s.section == 0 and s.storage == 2 and not s.function:
                undef.add(n)
    return {n for n in undef - defined if n not in funcs and not n.startswith(("sub_", "__", "?", "$"))}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", default=str(ROOT / "build" / "xbe_tables.c"))
    a = ap.parse_args()
    img = load(find_xbe())
    raw = Path(img.path).read_bytes()
    lo = min(s.va for s in img.sections)
    hi = max(s.va + s.virtual_size for s in img.sections)
    funcs, data = names_and_sizes()

    def initialized(va: int, n: int) -> bytes | None:
        for s in img.sections:
            if s.va <= va < s.va + s.virtual_size:
                o = va - s.va
                if o + n > s.raw_size:
                    return None
                return raw[s.raw + o:s.raw + o + n]
        return None

    rows = []
    for n in sorted(undefined_data(funcs)):
        m = re.fullmatch(r"D_([0-9A-F]{8})", n)
        if m:
            va, size = int(m[1], 16), data.get(n, (0, 4))[1]
        elif n in data:
            va, size = data[n]
        else:
            continue
        b = initialized(va, size)
        if b is None or not any(b):
            continue
        ptrs = sum(1 for i in range(0, size - 3, 4) if lo <= struct.unpack_from("<I", b, i)[0] < hi)
        rows.append((n, va, b, ptrs))

    out = ["/* xbe_tables.c: written by tools/xbe_tables.py from sf33rd.xbe. Do not commit.",
           " * Tables whose words include image addresses (possible pointers):"]
    out += [f" *   {n} 0x{va:X}: {p} of {len(b) // 4} words" for n, va, b, p in rows if p]
    out += [" */", "", "#include \"types.h\"", ""]
    for n, va, b, p in rows:
        out.append(f"/* 0x{va:X}, 0x{len(b):X} bytes */")
        out.append(f"XB_ALIGN16 u8 {n}[0x{len(b):X}] = {{")
        for i in range(0, len(b), 16):
            out.append("    " + ", ".join(f"0x{x:02X}" for x in b[i:i + 16]) + ",")
        out.append("};")
        out.append("")
    Path(a.o).parent.mkdir(parents=True, exist_ok=True)
    Path(a.o).write_text("\n".join(out))
    print(f"{len(rows)} tables, 0x{sum(len(b) for _, _, b, _ in rows):X} bytes, {sum(1 for r in rows if r[3])} with image addresses -> {a.o}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
