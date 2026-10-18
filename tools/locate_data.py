#!/usr/bin/env python3
"""locate_data.py [FILE.c...]: find data the port could not place by its bytes.

A generated Game file notes each PS2 table it could not find in the XBE
("Data: NAME: not located in the XBE, PS2 initializer kept"). This builds
the file with gcc -m32, reads each such table's bytes from the object, and
searches the XBE's .rdata and .data for them. A table with a relocation
inside it (a pointer table) is skipped, as is one whose bytes are all
zero. A table found at exactly one aligned place is reported as
"NAME is 0xADDR" (the note form writedata.py reads); one found nowhere
or in several places is listed as such. Nothing in the tree is changed.
"""

from __future__ import annotations

import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.paths import find_xbe  # noqa: E402
from ogxb.xbe import load  # noqa: E402

NOTE = re.compile(r"Data: (\w+): not located in the XBE")


def elf_symbols(obj: Path) -> dict[str, tuple[str, int, int]]:
    """name -> (section, offset, size) for defined data symbols"""
    out = {}
    secs = {}
    for line in subprocess.run(["readelf", "-SW", str(obj)], capture_output=True, text=True).stdout.splitlines():
        m = re.match(r"\s*\[\s*(\d+)\]\s+(\S+)", line)
        if m:
            secs[m[1]] = m[2]
    for line in subprocess.run(["readelf", "-sW", str(obj)], capture_output=True, text=True).stdout.splitlines():
        p = line.split()
        if len(p) >= 8 and p[3] == "OBJECT" and p[6].isdigit():
            out[p[7]] = (secs.get(p[6], "?"), int(p[1], 16), int(p[2]))
    return out


def relocated_ranges(obj: Path) -> dict[str, list[int]]:
    """section -> offsets that a relocation patches"""
    out: dict[str, list[int]] = {}
    cur = None
    for line in subprocess.run(["readelf", "-rW", str(obj)], capture_output=True, text=True).stdout.splitlines():
        m = re.match(r"Relocation section '\.rel(\S+)'", line)
        if m:
            cur = m[1]; out.setdefault(cur, []); continue
        m = re.match(r"([0-9a-f]{8})\s", line)
        if m and cur:
            out[cur].append(int(m[1], 16))
    return out


def section_bytes(obj: Path, sec: str, td: Path) -> bytes:
    dst = td / "sec.bin"
    subprocess.run(["objcopy", "-O", "binary", f"--only-section={sec}", str(obj), str(dst)], check=True)
    return dst.read_bytes()


def main() -> int:
    files = [Path(a) for a in sys.argv[1:]] or sorted((ROOT / "src/sf33rd/Source/Game").glob("*.c"))
    img = load(find_xbe())
    raw = Path(img.path).read_bytes()
    hay = []
    for s in img.sections:
        if s.name in (".rdata", ".data"):
            hay.append((s.va, raw[s.raw:s.raw + min(s.raw_size, s.virtual_size)]))
    total = found = 0
    for f in files:
        f = f if f.is_absolute() else (ROOT / f)
        text = f.read_text(errors="replace")
        names = NOTE.findall(text[:60000])
        if not names:
            continue
        with tempfile.TemporaryDirectory() as td:
            td = Path(td)
            obj = td / "f.o"
            fl = ["-m32", "-std=gnu17", "-O0", "-fno-pic", "-fno-common", "-w", f"-I{ROOT / 'include'}"]
            r = subprocess.run(["gcc", *fl, "-c", str(f), "-o", str(obj)], capture_output=True, text=True)
            if r.returncode:
                print(f"{f.name}: gcc failed"); continue
            syms = elf_symbols(obj)
            rel = relocated_ranges(obj)
            cache: dict[str, bytes] = {}
            for n in names:
                total += 1
                if n not in syms:
                    print(f"{f.name}: {n}: not in the object"); continue
                sec, off, size = syms[n]
                if size < 4:
                    print(f"{f.name}: {n}: too small ({size})"); continue
                if any(off <= o < off + size for o in rel.get(sec, [])):
                    print(f"{f.name}: {n}: has pointers, skipped"); continue
                if sec not in cache:
                    cache[sec] = section_bytes(obj, sec, td)
                blob = cache[sec][off:off + size]
                if not blob.strip(b"\0"):
                    print(f"{f.name}: {n}: all zero"); continue
                hits = []
                for va, b in hay:
                    i = b.find(blob)
                    while i >= 0:
                        if (va + i) % 2 == 0:
                            hits.append(va + i)
                        i = b.find(blob, i + 1)
                if len(hits) == 1:
                    found += 1
                    print(f"{f.name}: {n} is 0x{hits[0]:X}")
                elif hits:
                    print(f"{f.name}: {n}: {len(hits)} places ({', '.join(hex(h) for h in hits[:4])})")
                else:
                    print(f"{f.name}: {n}: not found ({size} bytes)")
    print(f"{found} of {total} located")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
