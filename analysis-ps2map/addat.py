# addat.py NAME=VA ... : add names at known addresses (from call order or a
# table), sizing each body as applynew.py does, via addnames.py.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, bisect, json, subprocess
sys.path.insert(0, _SP)
from feat import cfg_extent, padded_end, pinfo, TEND
OG = _OG; SP = OG + "/analysis-ps2map"
xf = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);", l)
    if m: xf[int(m[2], 16)] = m[1]
FO = json.load(open(SP + "/folded.json"))
DRY = "--dry" in sys.argv
new = {a.split("=")[0]: int(a.split("=")[1], 16) for a in sys.argv[1:] if a != "--dry"}
for n, v in new.items():
    assert v not in xf, (n, hex(v), xf.get(v)); assert n not in xf.values(), n
    assert hex(v) not in FO, (n, hex(v), "folded")
stops = sorted(set(xf) | {int(k, 16) for k in FO} | set(new.values()))
out = []
for n, v in new.items():
    i = bisect.bisect_right(stops, v); nx = stops[i] if i < len(stops) else TEND
    sz = padded_end(cfg_extent(v, stops), nx) - v
    r = sz / pinfo[n][1] if n in pinfo else 1
    print(n, hex(v), hex(sz), "ps2", hex(pinfo[n][1]) if n in pinfo else "?", "" if 0.15 <= r <= 3 else "SIZE?")
    out.append(f"{n} {v:X} {sz:X}\n")
if DRY: sys.exit()
open(SP + "/applynew.txt", "w").write("".join(out))
print(subprocess.run(["python3", SP + "/addnames.py", SP + "/applynew.txt"], capture_output=True, text=True).stdout.strip())
