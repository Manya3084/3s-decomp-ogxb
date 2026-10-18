# relinkdata.py : collect data addresses that the relink check reads off the
# retail code, into analysis-ps2map/relinkdata.json for writedata.py.
#
# tools/objdiff.py reports a global the C uses but data.txt does not name as
# "unresolved NAME (retail ADDR)". Only functions whose bytes already match
# retail are used (status "reloc"), so the C's field offset is the retail one
# and ADDR is the symbol's base. A name is kept when every use agrees.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG
import json, os, re, collections
R = json.load(open(_OG + "/build/objdiff.json"))
seen = collections.defaultdict(collections.Counter)
for obj, r in R.items():
    for f in r["functions"]:
        if f["status"] != "reloc":
            continue
        for n in f.get("notes", []):
            m = re.search(r"unresolved (\S+) \(retail (0x[0-9a-f]+)\)", n)
            if m:
                seen[m[1]][int(m[2], 16)] += 1
# rounds accumulate: a name found once stays, since once named it is no
# longer reported as unresolved
P = _OG + "/analysis-ps2map/relinkdata.json"
keep = json.load(open(P)) if os.path.exists(P) else {}
bad = {n: sorted(hex(a) for a in c) for n, c in seen.items() if len(c) > 1}
added = 0
for n, c in seen.items():
    if len(c) != 1: continue
    a = f"0x{next(iter(c)):X}"
    if n in keep and keep[n] != a: bad[n] = [keep[n], a]; continue
    added += n not in keep
    keep[n] = a
json.dump(dict(sorted(keep.items())), open(P, "w"), indent=0)
print("added", added, "total", len(keep), "conflicting", len(bad), bad)
