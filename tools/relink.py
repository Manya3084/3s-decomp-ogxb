#!/usr/bin/env python3
"""Build build/sf33rd.xbe from the compiled objects and the retail image.

The retail XBE supplies everything that has no C yet. Each compiled function
chosen below is written into its retail slot with its relocations applied:
named targets get their retail addresses, and local data (string literals,
float constants, static tables) is pointed at the copy objdiff.py found in
the retail image. Section digests are recomputed for every section that
changed.

By default only functions that objdiff.py calls "match" are written, so the
output must be byte-identical to retail: that checks the whole path from C
to image. --nonmatching also writes each other function that fits its slot
and whose relocations all resolve. That build runs this tree's C in place of
Capcom's code, and it is not identical to retail.

Run tools/build_c.py and tools/objdiff.py first.

    python3 tools/relink.py [--nonmatching] [-o build/sf33rd.xbe]
"""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from objdiff import OBJ, OUT as REPORT, Checker, function_ranges, symbol_maps
from ogxb import coff
from ogxb.paths import ROOT, find_xbe
from ogxb.xbe import load

RANK = {"match": 0, "reloc": 1, "diff": 2}


def resolve(obj: coff.Coff, ck: Checker, locals_: dict, tsym: coff.Symbol) -> int | None:
    section_symbol = (tsym.storage == 3 and tsym.defined and tsym.value == 0
                      and tsym.name == obj.section(tsym.section).name)
    if not section_symbol and tsym.storage == 3 and tsym.defined and not obj.section(tsym.section).code:
        # a static placed by its uses (objdiff.py does that when data.txt's
        # entry of that name is another file's); .bss has no bytes to check
        loc = locals_.get(str(tsym.section))
        if loc is not None and (loc.get("status") == "match"
                                or loc.get("status") == "unmapped" and obj.section(tsym.section).name == ".bss"):
            return loc["va"] + tsym.value
    if not section_symbol:
        va = ck.lookup(tsym.name)
        if va is not None:
            return va
    if not tsym.defined:
        return None
    sec = obj.section(tsym.section)
    if sec.code:
        fn = next((s for s in obj.symbols.values() if s.section == tsym.section and s.function), None)
        fva = ck.lookup(fn.name) if fn is not None else None
        return None if fva is None else fva - fn.value + tsym.value
    loc = locals_.get(str(tsym.section))
    if loc is None or loc.get("status") != "match":
        return None
    return loc["va"] + tsym.value


def build_body(obj: coff.Coff, sec: coff.CoffSection, start: int, end: int, va: int,
               ck: Checker, locals_: dict) -> bytes | None:
    body = bytearray(sec.data[start:end])
    for r in sec.relocs:
        if not start <= r.offset < end:
            continue
        o = r.offset - start
        target = resolve(obj, ck, locals_, obj.symbols[r.symbol])
        if target is None:
            return None
        addend = struct.unpack_from("<I", body, o)[0]
        if r.type == coff.REL_DIR32:
            value = (target + addend) & 0xFFFFFFFF
        elif r.type == coff.REL_REL32:
            value = (target + addend - (va + o + 4)) & 0xFFFFFFFF
        else:
            return None
        struct.pack_into("<I", body, o, value)
    return bytes(body)


def fix_digests(data: bytearray, changed: set[int]) -> None:
    base = struct.unpack_from("<I", data, 0x104)[0]
    count = struct.unpack_from("<I", data, 0x11C)[0]
    headers = struct.unpack_from("<I", data, 0x120)[0] - base
    for i in range(count):
        off = headers + i * 0x38
        raw, size = struct.unpack_from("<2I", data, off + 0x0C)
        if any(raw <= c < raw + size for c in changed):
            data[off + 0x24:off + 0x38] = hashlib.sha1(struct.pack("<I", size) + data[raw:raw + size]).digest()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--nonmatching", action="store_true")
    ap.add_argument("-o", type=Path, default=ROOT / "build" / "sf33rd.xbe")
    a = ap.parse_args()
    xbe = find_xbe()
    if xbe is None or not REPORT.is_file():
        print("needs the retail XBE (SF33RD_XBE or xbe.path) and build/objdiff.json", file=sys.stderr)
        return 2
    img = load(xbe)
    retail = xbe.read_bytes()
    out = bytearray(retail)
    addr, size = symbol_maps()
    ck = Checker(img, addr, size)
    report = json.loads(REPORT.read_text())

    # one compiled body per retail address, the best-matching one
    chosen: dict[int, tuple] = {}
    for rel, entry in report.items():
        for f in entry["functions"]:
            if "va" not in f:
                continue
            ok = f["status"] == "match" or (a.nonmatching and f["size"] <= f["slot"])
            if not ok:
                continue
            cur = chosen.get(f["va"])
            if cur is None or RANK[f["status"]] < RANK[cur[1]["status"]]:
                chosen[f["va"]] = (rel, f)

    objs: dict[str, coff.Coff] = {}
    written = {"match": 0, "reloc": 0, "diff": 0}
    skipped = 0
    changed: set[int] = set()
    for va, (rel, f) in sorted(chosen.items()):
        obj = objs.setdefault(rel, coff.read((OBJ / rel).read_bytes()))
        hit = None
        for sec in obj.sections:
            if not sec.code:
                continue
            for sym, start, end in function_ranges(sec, obj):
                if coff.undecorate(sym.name) == f["name"]:
                    hit = (sec, start, end)
        if hit is None:
            skipped += 1
            continue
        body = build_body(obj, *hit, va, ck, report[rel]["locals"])
        if body is None:
            skipped += 1
            continue
        off = img.va_offset(va)
        slot = f["slot"]
        if off is None or img.va_offset(va + slot - 1) != off + slot - 1:
            print(f"  not in the file image: {f['name']} {va:#x}")
            skipped += 1
            continue
        new = body + b"\xCC" * (slot - len(body)) if f["status"] != "match" else body
        if out[off:off + len(new)] != new:
            changed.add(off)
        out[off:off + len(new)] = new
        written[f["status"]] += 1
    fix_digests(out, changed)
    a.o.parent.mkdir(parents=True, exist_ok=True)
    a.o.write_bytes(out)
    same = bytes(out) == retail
    print("written: " + ", ".join(f"{k} {v}" for k, v in written.items()) + f"; skipped {skipped} (unresolved targets)")
    print(f"{a.o}: sha256 {hashlib.sha256(out).hexdigest()}")
    if same:
        print("identical to retail")
    elif not a.nonmatching:
        diffs = [i for i in range(len(out)) if out[i] != retail[i]]
        print(f"DIFFERS from retail at {len(diffs)} bytes, first at file offset {diffs[0]:#x}")
        return 1
    else:
        print(f"differs from retail in {len(changed)} functions (expected with --nonmatching)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
