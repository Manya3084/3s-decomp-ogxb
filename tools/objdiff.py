#!/usr/bin/env python3
"""Compare the compiled objects in build/obj with retail sf33rd.xbe.

Every function in an object that has a name in funcs.txt is compared with the
retail body at that address. Bytes that a relocation patches are masked, and
each relocation is checked on its own:

  - a target with a name (funcs.txt, xdk.txt, data.txt, or sub_/D_/dat_ADDR)
    must be the address the retail code uses there;
  - a target local to the object (a string literal, a float constant, a
    static table) has no name, so its address is read off the retail code. All
    uses of one local section must agree on where it sits, and its bytes are
    then compared with the retail bytes there.

A function is "match" when its bytes and every relocation agree and the rest
of the retail slot is padding. build/objdiff.json has the per-function result
that tools/relink.py uses.

    python3 tools/objdiff.py [-v] [OBJ ...]
"""

from __future__ import annotations

import argparse
import json
import re
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb import coff
from ogxb.paths import ROOT, find_xbe
from ogxb.xbe import load

SYMS = ROOT / "config" / "sf33rd" / "symbols"
OBJ = ROOT / "build" / "obj"
OUT = ROOT / "build" / "objdiff.json"
ROW = re.compile(r"^([A-Za-z_.$][\w.$]*)\s*=\s*0x([0-9A-Fa-f]+)\s*;(.*)$")
PLACEHOLDER = re.compile(r"^(?:sub|D|dat)_([0-9A-Fa-f]{5,8})$")
PADDING = (0xCC, 0x90, 0x00)


def symbol_maps() -> tuple[dict[str, int], dict[str, int]]:
    """Name -> address for everything, and function name -> retail size."""
    addr: dict[str, int] = {}
    size: dict[str, int] = {}
    for f in ("funcs.txt", "xdk.txt", "data.txt"):
        for line in (SYMS / f).read_text().splitlines():
            m = ROW.match(line.strip())
            if not m or "kind:offset" in m.group(3):
                continue
            addr.setdefault(m.group(1), int(m.group(2), 16))
            s = re.search(r"\bsize:0x([0-9A-Fa-f]+)", m.group(3))
            if f == "funcs.txt" and "type:func" in m.group(3) and s:
                size[m.group(1)] = int(s.group(1), 16)
    return addr, size


def fold_map() -> dict[str, int]:
    """Names whose body MSVC merged into another (analysis-ps2map/folded.json)."""
    p = ROOT / "analysis-ps2map" / "folded.json"
    if not p.is_file():
        return {}
    return {n: int(a, 16) for a, names in json.loads(p.read_text()).items() for n in names}


class Checker:
    def __init__(self, img, addr: dict[str, int], size: dict[str, int]):
        self.img = img
        self.addr = addr
        self.size = size
        self.fold = fold_map()

    def lookup(self, raw: str) -> int | None:
        name = coff.undecorate(raw)
        if name in self.addr:
            return self.addr[name]
        m = PLACEHOLDER.match(name)
        return int(m.group(1), 16) if m else None

    def u32(self, va: int) -> int | None:
        try:
            return struct.unpack("<I", self.img.bytes_at(va, 4))[0]
        except Exception:
            return None


def function_ranges(sec: coff.CoffSection, obj: coff.Coff) -> list[tuple[coff.Symbol, int, int]]:
    funcs = sorted((s for s in obj.symbols.values()
                    if s.section == sec.index and s.function and s.storage in (2, 3)), key=lambda s: s.value)
    out = []
    for i, s in enumerate(funcs):
        end = funcs[i + 1].value if i + 1 < len(funcs) else sec.size
        out.append((s, s.value, end))
    return out


def check_object(path: Path, ck: Checker, verbose: bool) -> dict:
    obj = coff.read(path.read_bytes())
    # (section index) -> {retail base: count}: where each local section sits
    placed: dict[int, Counter] = defaultdict(Counter)
    funcs = []
    for sec in obj.sections:
        if not sec.code or sec.flags & coff.DISCARDABLE:
            continue
        for sym, start, end in function_ranges(sec, obj):
            name = coff.undecorate(sym.name)
            body = sec.data[start:end]
            res = {"name": name, "size": len(body)}
            funcs.append(res)
            va = ck.addr.get(name)
            slot = ck.size.get(name)
            if (va is None or slot is None) and name in ck.fold:
                # a folded name has no slot of its own: compare with the body
                # it was merged into, without a padding check
                va, slot = ck.fold[name], len(body)
                res["fold"] = True
            if va is None or slot is None:
                res["status"] = "unplaced"
                continue
            res["va"] = va
            res["slot"] = slot
            try:
                retail = ck.img.bytes_at(va, max(slot, len(body)))
            except Exception:
                res["status"] = "unplaced"
                continue
            mask = bytearray(len(body))
            relocs = []
            bad = []
            for r in sec.relocs:
                if not start <= r.offset < end:
                    continue
                o = r.offset - start
                for k in range(4):
                    if o + k < len(mask):
                        mask[o + k] = 1
                tsym = obj.symbols[r.symbol]
                addend = struct.unpack_from("<I", body, o)[0]
                if r.type == coff.REL_REL32:
                    have = (va + o + 4 + struct.unpack("<i", retail[o:o + 4])[0]) & 0xFFFFFFFF
                    have = (have - addend) & 0xFFFFFFFF
                elif r.type == coff.REL_DIR32:
                    have = (struct.unpack("<I", retail[o:o + 4])[0] - addend) & 0xFFFFFFFF
                else:
                    bad.append(f"+{o:#x} reloc type {r.type:#x}")
                    continue
                want = ck.lookup(tsym.name) if not (tsym.storage == 3 and tsym.defined and tsym.value == 0
                                                     and tsym.name == obj.section(tsym.section).name) else None
                if want is None and tsym.defined:
                    target_sec = obj.section(tsym.section)
                    fn = next((s for s in obj.symbols.values() if s.section == tsym.section and s.function), None)
                    fva = ck.lookup(fn.name) if target_sec.code and fn is not None else None
                    if fva is not None:
                        want = fva - fn.value + tsym.value
                    else:
                        placed[tsym.section][(have - tsym.value) & 0xFFFFFFFF] += 1
                        relocs.append((o, "local", tsym.section))
                        continue
                if want is None:
                    bad.append(f"+{o:#x} unresolved {coff.undecorate(tsym.name)} (retail {have:#x})")
                    relocs.append((o, "unresolved", coff.undecorate(tsym.name)))
                    continue
                if want != have:
                    bad.append(f"+{o:#x} {coff.undecorate(tsym.name)} is {want:#x}, retail uses {have:#x}")
                relocs.append((o, "named", coff.undecorate(tsym.name)))
            diff = [i for i in range(len(body)) if not mask[i] and body[i] != retail[i]]
            tail_ok = len(body) <= slot and all(b in PADDING for b in retail[len(body):slot])
            same = sum(1 for i in range(len(body)) if not mask[i] and body[i] == retail[i])
            res["same"] = same
            if not diff and not bad and tail_ok:
                res["status"] = "match"
            elif not diff and tail_ok:
                res["status"] = "reloc"
                res["notes"] = bad[:6]
            else:
                res["status"] = "diff"
                res["first_diff"] = diff[0] if diff else None
                if len(body) > slot:
                    res["notes"] = [f"compiled {len(body):#x} bytes, retail slot {slot:#x}"]
            res["unresolved"] = sum(1 for _, k, _ in relocs if k == "unresolved")
    # a local section is placed only when every use agrees
    locals_ = {}
    for idx, bases in placed.items():
        sec = obj.section(idx)
        base, n = bases.most_common(1)[0]
        entry = {"section": sec.name, "size": sec.size, "uses": sum(bases.values())}
        if len(bases) > 1:
            entry["status"] = "conflict"
        else:
            entry["va"] = base
            try:
                retail = ck.img.bytes_at(base, sec.size)
                mask = bytearray(sec.size)
                for r in sec.relocs:
                    for k in range(4):
                        if r.offset + k < sec.size:
                            mask[r.offset + k] = 1
                same = all(mask[i] or sec.data[i] == retail[i] for i in range(sec.size)) if not sec.flags & coff.BSS else True
                entry["status"] = "match" if same else "diff"
            except Exception:
                entry["status"] = "unmapped"
        locals_[str(idx)] = entry
    return {"functions": funcs, "locals": locals_}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("-v", action="store_true")
    ap.add_argument("objs", nargs="*")
    a = ap.parse_args()
    xbe = find_xbe()
    if xbe is None:
        print("retail sf33rd.xbe not found: set SF33RD_XBE or xbe.path", file=sys.stderr)
        return 2
    addr, size = symbol_maps()
    ck = Checker(load(xbe), addr, size)
    objs = [Path(p) for p in a.objs] if a.objs else sorted(OBJ.rglob("*.obj"))
    report = {}
    for p in objs:
        report[str(p.relative_to(OBJ))] = check_object(p, ck, a.v)
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps(report, indent=1))
    st = Counter(f["status"] for r in report.values() for f in r["functions"])
    placed = [f for r in report.values() for f in r["functions"] if f["status"] != "unplaced"]
    mbytes = sum(f["size"] for f in placed if f["status"] == "match")
    tbytes = sum(f["size"] for f in placed)
    lc = Counter(l["status"] for r in report.values() for l in r["locals"].values())
    print(f"objects {len(report)}, functions {sum(st.values())}: " + ", ".join(f"{k} {v}" for k, v in st.most_common()))
    print(f"placed functions matching: {st['match']} of {len(placed)} ({mbytes:#x} of {tbytes:#x} bytes)")
    print("local data sections: " + ", ".join(f"{k} {v}" for k, v in lc.most_common()))
    return 0


if __name__ == "__main__":
    sys.exit(main())
