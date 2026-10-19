#!/usr/bin/env python3
"""Write the tables the C uses but does not define, from the XBE, as C.

The tree's C declares some initialized tables without defining them: the
character tables the PS2 build also takes from the game binary, a few
Xbox-only tables, and the XDK's data. They are not in the tree. A port
can take them from its own XBE with this script: it lists every global
the compiled objects (build/obj) reference and no object defines, keeps
those data.txt (or a D_ADDR name) places in initialized data, and writes
each to build/xbe_tables.c.

Each table's size is its data.txt size, else the PS2 map's size for the
same name, else the distance to the next address the tree knows (a
data.txt or D_ADDR name, a function, or another table this script
writes), at most 0x4000 bytes. A table that is 4-byte aligned is written
as words. A word that holds an address in the image is written as that
address's symbol plus an offset: a function, a global the C defines, or
another table this script writes. A pointer into initialized data that no
name covers gets a table of its own (D_ADDR), which is written the same
way, so pointer tables keep working where the image is not mapped at its
own addresses. An address is told from a number only by its value, so the
file's header lists every word read as a pointer for review, and the
words that look like addresses but could not be resolved. Zero-
initialized globals get storage only, sized the same way but without the
0x4000 limit.

    python3 tools/xbe_tables.py [-o build/xbe_tables.c]
"""

from __future__ import annotations

import argparse
import bisect
import json
import os
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
MAXSIZE = 0x4000


def read_syms(f: str) -> dict[str, tuple[int, str]]:
    out: dict[str, tuple[int, str]] = {}
    p = SYM / f
    for line in p.read_text(errors="replace").splitlines():
        m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);(.*)", line)
        if m:
            out.setdefault(m[1], (int(m[2], 16), m[3]))
    return out


def ps2_sizes() -> dict[str, int]:
    root = os.environ.get("PS2_ROOT")
    if not root and (ROOT / "ps2.path").is_file():
        root = (ROOT / "ps2.path").read_text().strip().rstrip("/")
        if os.path.basename(root) == "src":
            root = os.path.dirname(root)
    p = Path(root or "/nonexistent") / "config" / "anniversary" / "symbols" / "syms_sfiii.txt"
    out: dict[str, int] = {}
    if p.is_file():
        for line in p.read_text(errors="replace").splitlines():
            m = re.match(r"(\S+) = 0x[0-9A-Fa-f]+;.*size:0x([0-9A-Fa-f]+)", line)
            if m:
                out[m[1]] = int(m[2], 16)
    return out


def objects() -> tuple[set[str], set[str], set[str]]:
    """names defined, names referenced and not defined, and the defined
    functions"""
    defined: set[str] = set()
    funcs: set[str] = set()
    undef: set[str] = set()
    for p in Path(OBJ).rglob("*.obj"):
        for s in coff.read(p.read_bytes()).symbols.values():
            if s.storage != 2:
                continue
            n = coff.undecorate(s.name)
            if s.section > 0:
                defined.add(n)
                if s.function:
                    funcs.add(n)
            elif s.section == 0 and not s.function:
                undef.add(n)
    return defined, undef - defined, funcs


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", default=str(ROOT / "build" / "xbe_tables.c"))
    a = ap.parse_args()
    img = load(find_xbe())
    raw = Path(img.path).read_bytes()
    funcs_txt = read_syms("funcs.txt")
    xdk = read_syms("xdk.txt")
    data = {n: (v, int(m[1], 16) if (m := re.search(r"size:0x([0-9A-Fa-f]+)", c)) else None)
            for n, (v, c) in read_syms("data.txt").items()}
    psize = ps2_sizes()
    defined, undef, cfuncs = objects()
    folded = json.loads((ROOT / "analysis-ps2map" / "folded.json").read_text())

    # every name the tree knows at each address, for pointer targets
    func_at: dict[int, str] = {}
    for n, (v, c) in funcs_txt.items():
        if n in cfuncs:
            func_at.setdefault(v, n)
    for ad, ns in folded.items():
        for n in ns:
            if n in cfuncs:
                func_at.setdefault(int(ad, 16), n)
    for n, (v, c) in xdk.items():
        func_at.setdefault(v, n)
    data_at: dict[int, tuple[str, int | None]] = {}
    for n, (v, size) in data.items():
        if n in defined:
            data_at.setdefault(v, (n, size))
    srcnames = set()
    ptrdecl: set[str] = set()
    declsize: dict[str, tuple[str, str, str]] = {}
    for p in (ROOT / "src").rglob("*.c"):
        t = p.read_text(errors="replace")
        srcnames.update(re.findall(r"\bD_([0-9A-F]{8})\b", t))
        for m in re.finditer(r"^extern\s+(?:const\s+)?(\w+)\s*(\*?)\s*(?:const\s+)?(\w+)\s*((?:\[[^\]]*\]\s*)*);", t, re.M):
            declsize.setdefault(m[3], (m[1], m[2], m[4]))
        # declared with a pointer element type: char* X[2], u32* X[], s32 (*X)(...)
        for m in re.finditer(r"^extern\s[^;=]*?(?:\*\s*(?:const\s+)?(\w+)\s*[\[;]|\(\s*\*\s*(\w+)\s*(?:\[[^\]]*\]\s*)*\))", t, re.M):
            ptrdecl.add(m[1] or m[2])
    for h in srcnames:
        n = "D_" + h
        if n in defined:
            data_at.setdefault(int(h, 16), (n, data.get(n, (0, None))[1]))

    def section(va: int):
        for s in img.sections:
            if s.va <= va < s.va + s.virtual_size:
                return s
        return None

    def initialized(va: int, n: int) -> bytes | None:
        s = section(va)
        if s is None:
            return None
        o = va - s.va
        if o + n > s.raw_size:
            return None
        return raw[s.raw + o:s.raw + o + n]

    def init_end(va: int) -> int:
        s = section(va)
        return s.va + min(s.raw_size, s.virtual_size)

    # the kernel import table runs from thunk_va to its zero word
    thunk_end = img.thunk_va
    while (initialized(thunk_end, 4) or b"\0\0\0\0") != b"\0\0\0\0":
        thunk_end += 4

    BASE = {"s8": 1, "u8": 1, "char": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "f32": 4,
            "int": 4, "f64": 8, "s64": 8, "u64": 8}

    def c_size(n: str, va: int) -> int | None:
        """the size the C declaration gives: a scalar, an array with all its
        dimensions, or a char array up to its terminator"""
        if n not in declsize:
            return None
        base, star, dims = declsize[n]
        el = 4 if star else BASE.get(base)
        if el is None:
            return None
        ds = re.findall(r"\[([^\]]*)\]", dims)
        if not ds:
            return el
        if all(re.fullmatch(r"\s*(0x[0-9A-Fa-f]+|\d+)\s*", d) for d in ds):
            k = el
            for d in ds:
                k *= int(d, 0)
            return k
        if base == "char" and not star and len(ds) == 1:
            b = initialized(va, min(MAXSIZE, init_end(va) - va)) or b""
            e = b.find(b"\0")
            return e + 1 if e >= 0 else None
        return None

    # the tables to write: (name, va, size or None)
    want: dict[str, list] = {}
    storage: dict[str, list] = {}  # zero-initialized: [va, size]
    for n in sorted(undef):
        if n.startswith(("sub_", "__", "?", "$")) or n in funcs_txt or n in xdk:
            continue
        m = re.fullmatch(r"D_([0-9A-F]{8})", n)
        if m:
            va = int(m[1], 16)
        elif n in data:
            va = data[n][0]
        else:
            continue
        size = data.get(n, (0, None))[1] or psize.get(n) or c_size(n, va)
        s = section(va)
        if s is None:
            continue
        if va >= s.va + min(s.raw_size, s.virtual_size):
            storage[n] = [va, size]
            continue
        if img.thunk_va <= va < thunk_end:
            continue  # a kernel import slot: the port supplies the import
        want[n] = [va, size, "ptr" if n in ptrdecl else "any"]

    lo = min(s.va for s in img.sections)
    hi = max(s.va + s.virtual_size for s in img.sections)
    pointers: list[str] = []
    unresolved: list[str] = []
    done: dict[str, tuple[int, bytes]] = {}

    def bounds() -> list[int]:
        b = set(data_at) | set(func_at) | {w[0] for w in want.values()}
        b |= {int(h, 16) for h in srcnames}
        b |= {v for n, (v, _) in data.items()}
        return sorted(b)

    def owner(t: int) -> tuple[str, int] | None:
        """the name a pointer to t is written with"""
        if t in func_at:
            return func_at[t], 0
        for n, (va, size, _) in list(want.items()):
            if va <= t < va + (size or 1) or (size is None and va == t):
                return n, t - va
        for n, (va, b) in done.items():
            if va <= t < va + len(b):
                return n, t - va
        i = bisect.bisect_right(dkeys, t) - 1
        if i >= 0:
            va = dkeys[i]
            n, size = data_at[va]
            if t == va or (size and t < va + size):
                return n, t - va
        return None

    dkeys = sorted(data_at)
    # addresses a word of a table not declared as pointers must equal to
    # be read as one: a function, or the start of a named table
    exact = set(func_at) | set(data_at) | {w[0] for w in want.values()}
    out_rows = []
    while want:
        b = bounds()
        # size every pending table first, so pointers can land inside them
        for n, w in want.items():
            if w[1] is None and w[2] == "raw":
                # a string a pointer reaches: up to its terminator
                b_ = initialized(w[0], min(0x400, init_end(w[0]) - w[0])) or b""
                e = b_.find(b"\0")
                if e > 0 and all(c >= 0x20 or c in (9, 10, 13) for c in b_[:e]):
                    w[1] = e + 1
            if w[1] is None:
                i = bisect.bisect_right(b, w[0])
                nxt = b[i] if i < len(b) else w[0] + 4
                w[1] = max(4, min(nxt - w[0], MAXSIZE, init_end(w[0]) - w[0]))
        n = min(want, key=lambda k: want[k][0])
        va, size, kind = want.pop(n)
        by = initialized(va, size)
        if by is None:
            by = initialized(va, max(0, init_end(va) - va)) or b""
        done[n] = (va, by)
        words = None
        if kind != "raw" and va % 4 == 0 and len(by) % 4 == 0 and len(by):
            words = []
            for i in range(0, len(by), 4):
                v = struct.unpack_from("<I", by, i)[0]
                if not (lo <= v < hi) or (kind != "ptr" and v not in exact):
                    words.append(f"0x{v:08X}")
                    continue
                o = owner(v)
                if o is None and kind == "ptr":
                    s = section(v)
                    if s is not None and s.name in (".rdata", ".data") and v < init_end(v):
                        tn = f"D_{v:08X}"
                        if tn not in done:
                            want[tn] = [v, None, "raw"]
                        o = (tn, 0)
                if o is None:
                    unresolved.append(f"{n}+0x{i:X}: 0x{v:X}")
                    words.append(f"0x{v:08X}")
                    continue
                t, off = o
                pointers.append(f"{n}+0x{i:X} -> {t}" + (f"+0x{off:X}" if off else ""))
                words.append(f"(u32){'' if t in func_at.values() else '&'}{t}" + (f" + 0x{off:X}" if off else ""))
        out_rows.append((n, va, by, words))

    # zero-initialized globals: storage, up to the next known address
    b = bounds()
    for n, w in storage.items():
        if w[1] is None:
            i = bisect.bisect_right(b, w[0])
            s_ = section(w[0])
            end = s_.va + s_.virtual_size
            w[1] = max(4, min(b[i] if i < len(b) else end, end) - w[0])

    emitted = {n for n, *_ in out_rows}
    ext_f = sorted({t for p in pointers for t in [p.split(" -> ")[1].split("+")[0]] if t in func_at.values()})
    ext_d = sorted({t for p in pointers for t in [p.split(" -> ")[1].split("+")[0]]
                    if t not in func_at.values() and t not in emitted})
    out = ["/* xbe_tables.c: written by tools/xbe_tables.py from sf33rd.xbe. Do not commit.",
           f" * {len(out_rows)} tables. Words read as pointers ({len(pointers)}):"]
    out += [f" *   {p}" for p in pointers]
    out += [f" * Words that look like image addresses but have no symbol ({len(unresolved)}):"]
    out += [f" *   {u}" for u in unresolved]
    out += [" */", "", "#include \"types.h\"", ""]
    out += [f"extern void {f}(void);" for f in ext_f]
    out += [f"extern u8 {d}[];" for d in ext_d]
    out += [f"extern {'u32' if w is not None else 'u8'} {n}[];" for n, va, b, w in out_rows]
    out.append("")
    for n, va, b, w in out_rows:
        out.append(f"/* 0x{va:X}, 0x{len(b):X} bytes */")
        if w is not None:
            out.append(f"XB_ALIGN16 u32 {n}[0x{len(w):X}] = {{")
            for i in range(0, len(w), 4):
                out.append("    " + ", ".join(w[i:i + 4]) + ",")
        else:
            out.append(f"XB_ALIGN16 u8 {n}[0x{max(len(b), 1):X}] = {{")
            for i in range(0, len(b), 16):
                out.append("    " + ", ".join(f"0x{x:02X}" for x in b[i:i + 16]) + ",")
        out.append("};")
        out.append("")
    out.append(f"/* Zero-initialized globals ({len(storage)}): storage only. */")
    for n, (va, size) in sorted(storage.items(), key=lambda x: x[1][0]):
        out.append(f"XB_ALIGN16 u8 {n}[0x{size:X}]; /* 0x{va:X} */")
    out.append("")
    Path(a.o).parent.mkdir(parents=True, exist_ok=True)
    Path(a.o).write_text("\n".join(out))
    print(f"{len(out_rows)} tables, 0x{sum(len(b) for _, _, b, _ in out_rows):X} bytes, "
          f"{len(pointers)} pointer words, {len(unresolved)} unresolved, "
          f"{len(storage)} zero-initialized (0x{sum(w[1] for w in storage.values()):X} bytes) -> {a.o}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
