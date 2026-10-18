# relinkdata.py : collect what the relink check reads off the retail code,
# into analysis-ps2map/relinkdata.json for writedata.py and relinkfuncs.py.
#
# Names: tools/objdiff.py reports a global the C uses but data.txt does not
# name as "unresolved NAME (retail ADDR)". Only functions whose bytes already
# match retail are used (status "reloc"), so the C's field offset is the
# retail one and ADDR is the symbol's base. A name is kept when every use
# agrees. Rounds accumulate: once named, a name is no longer reported.
#
# Rebases ("rebase" in the json): a named global whose data.txt address is
# wrong. Every absolute use of it in byte-matching code is compared with the
# address the retail code uses there. When the "reloc" uses all differ by one
# constant shift and no fully matching function uses it at its current
# address, the base moves by that shift. A global that matching functions do
# use where data.txt puts it keeps its address: there the C is wrong.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG
import json, os, re, sys, struct, collections
sys.path.insert(0, _OG + "/tools")
from objdiff import OBJ, function_ranges, symbol_maps
from ogxb import coff
from ogxb.paths import find_xbe
from ogxb.xbe import load

R = json.load(open(_OG + "/build/objdiff.json"))
P = _OG + "/analysis-ps2map/relinkdata.json"
store = json.load(open(P)) if os.path.exists(P) else {}
rebase = store.pop("rebase", {})
keep = store

seen = collections.defaultdict(collections.Counter)
for obj, r in R.items():
    for f in r["functions"]:
        if f["status"] != "reloc":
            continue
        for n in f.get("notes", []):
            m = re.search(r"unresolved (\S+) \(retail (0x[0-9a-f]+)\)", n)
            if m:
                seen[m[1]][int(m[2], 16)] += 1
bad = {n: sorted(hex(a) for a in c) for n, c in seen.items() if len(c) > 1}
added = 0
for n, c in seen.items():
    if len(c) != 1:
        continue
    a = f"0x{next(iter(c)):X}"
    if n in keep and keep[n] != a:
        bad[n] = [keep[n], a]
        continue
    added += n not in keep
    keep[n] = a

img = load(find_xbe())
addr, _ = symbol_maps()
shifts = collections.defaultdict(lambda: {"reloc": collections.Counter(), "match": collections.Counter()})
for rel, r in R.items():
    status = {f["name"]: f for f in r["functions"] if f["status"] in ("reloc", "match") and "va" in f}
    if not status:
        continue
    o = coff.read((OBJ / rel).read_bytes())
    for sec in o.sections:
        if not sec.code:
            continue
        for sym, s, e in function_ranges(sec, o):
            f = status.get(coff.undecorate(sym.name))
            if f is None:
                continue
            for rl in sec.relocs:
                tn = coff.undecorate(o.symbols[rl.symbol].name)
                if not s <= rl.offset < e or rl.type != coff.REL_DIR32 or addr.get(tn, 0) < 0x218DC0:
                    continue
                add = struct.unpack_from("<I", sec.data, rl.offset)[0]
                have = struct.unpack("<I", img.bytes_at(f["va"] + rl.offset - s, 4))[0]
                shifts[tn][f["status"]][(have - add - addr[tn]) & 0xFFFFFFFF] += 1
for n, sh in shifts.items():
    moved = {d for d in sh["reloc"] if d}
    if len(sh["reloc"]) == 1 and moved and not sh["match"]:
        d = next(iter(moved))
        d = d - (1 << 32) if d >= 1 << 31 else d
        rebase[n] = f"0x{addr[n] + d:X}"
keep["rebase"] = dict(sorted(rebase.items()))
json.dump(dict(sorted(keep.items())), open(P, "w"), indent=0)
print("added", added, "total", len(keep) - 1, "conflicting", len(bad), bad)
print("rebase", keep["rebase"])
