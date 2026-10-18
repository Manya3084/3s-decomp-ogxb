# Link-order check for callalign proposals: the PS2 address of the proposed
# name should lie between the PS2 addresses of the nearest named XBE
# neighbours (named in funcs.txt or by other proposals).
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import json, re, bisect, sys
OG = _OG; PS = _PS
pa = {}
for l in open(PS + "/config/retail/symbols/funcs.txt"):
    m = re.match(r"(\S+) = (0x[0-9A-Fa-f]+);", l)
    if m: pa[m[1]] = int(m[2], 16)
xn = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);", l)
    if m: xn[int(m[2], 16)] = m[1]
prop = {int(k, 16): v for k, v in json.load(open(OG + "/analysis-ps2map/callalign.json")).items()}
allx = dict(xn); allx.update({a: v[0] for a, v in prop.items()})
keys = sorted(a for a, n in allx.items() if n in pa)
out = {}
for a, v in sorted(prop.items()):
    n = v[0]; i = keys.index(a)
    lo = next((keys[j] for j in range(i - 1, -1, -1)), None)
    hi = next((keys[j] for j in range(i + 1, len(keys))), None)
    pl, ph, pc = pa.get(allx.get(lo)), pa.get(allx.get(hi)), pa[n]
    ok_lo = pl is not None and pl < pc and pc - pl < 0x8000
    ok_hi = ph is not None and pc < ph and ph - pc < 0x8000
    out[hex(a)] = "both" if ok_lo and ok_hi else ("one" if ok_lo or ok_hi else "none")
json.dump(out, open(OG + "/analysis-ps2map/ordercheck.json", "w"), indent=0)
import collections
print(collections.Counter(out.values()))
