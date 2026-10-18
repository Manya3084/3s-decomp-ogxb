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


def relocated_ranges(obj: Path) -> dict[str, dict[int, str]]:
    """section -> {offset a relocation patches: target symbol}"""
    out: dict[str, dict[int, str]] = {}
    cur = None
    for line in subprocess.run(["readelf", "-rW", str(obj)], capture_output=True, text=True).stdout.splitlines():
        m = re.match(r"Relocation section '\.rel(\S+)'", line)
        if m:
            cur = m[1]; out.setdefault(cur, {}); continue
        m = re.match(r"([0-9a-f]{8})\s+\S+\s+\S+\s+[0-9a-f]+\s+(\S+)", line)
        if m and cur:
            out[cur][int(m[1], 16)] = m[2]
    return out


def retail_addresses() -> dict[str, int]:
    import json
    out: dict[str, int] = {}
    for k, names in json.loads((ROOT / "analysis-ps2map" / "folded.json").read_text()).items():
        if int(k, 16) >= 0x11000:
            for n in names:
                out.setdefault(n, int(k, 16))
    for f in sorted((ROOT / "config" / "sf33rd" / "symbols").glob("*.txt")):
        for line in f.read_text(errors="replace").splitlines():
            m = re.match(r"(\S+)\s*=\s*0x([0-9A-Fa-f]+);", line)
            if m:
                out[m[1]] = int(m[2], 16)
    return out


def masked_find(hay: bytes, pat: bytes, mask: bytes) -> list[int]:
    """offsets where hay agrees with pat on every byte mask is 0xFF"""
    # anchor on the longest run of known bytes
    best, run, start = (0, 0), 0, 0
    for i, mb in enumerate(mask):
        if mb:
            if run == 0:
                start = i
            run += 1
            if run > best[1]:
                best = (start, run)
        else:
            run = 0
    a, n = best
    if n < 4:
        return []
    anchor = pat[a:a + n]
    out = []
    i = hay.find(anchor)
    while i >= 0:
        base = i - a
        if base >= 0 and base + len(pat) <= len(hay) and all(
                not mask[k] or hay[base + k] == pat[k] for k in range(len(pat))):
            out.append(base)
        i = hay.find(anchor, i + 1)
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
    addr = retail_addresses()
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
                if sec not in cache:
                    cache[sec] = section_bytes(obj, sec, td)
                blob = bytearray(cache[sec][off:off + size])
                mask = bytearray(b"\xff" * size)
                ptrs = {o - off: t for o, t in rel.get(sec, {}).items() if off <= o < off + size}
                known = 0
                for o, t in ptrs.items():
                    # a pointer to a symbol with a retail address is that address (plus its addend)
                    if t in addr and t != n:
                        v = addr[t] + int.from_bytes(blob[o:o + 4], "little")
                        blob[o:o + 4] = (v & 0xFFFFFFFF).to_bytes(4, "little"); known += 1
                    else:
                        mask[o:o + 4] = b"\0\0\0\0"
                if ptrs and known * 2 < len(ptrs):
                    print(f"{f.name}: {n}: pointers mostly unknown ({known}/{len(ptrs)}), skipped"); continue
                if not ptrs and not bytes(blob).strip(b"\0"):
                    print(f"{f.name}: {n}: all zero"); continue
                hits = []
                for va, b in hay:
                    for i in masked_find(b, bytes(blob), bytes(mask)):
                        if (va + i) % 2 == 0:
                            hits.append(va + i)
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
