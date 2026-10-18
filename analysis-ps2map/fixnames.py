# fixnames.py FILE : lines "NAME" (remove) or "NAME VAHEX SIZEHEX" (move/resize).
# Removes funcs.txt rows and matched_bytes entries, then re-adds moved ones.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, subprocess
OG = _OG; SP = OG + "/analysis-ps2map"
L = [l.split() for l in open(sys.argv[1]) if l.strip()]
names = {x[0] for x in L}
fp = OG + "/config/sf33rd/symbols/funcs.txt"; rows = open(fp).readlines()
open(fp, "w").write("".join(r for r in rows if r.split(" = ")[0] not in names))
mp = OG + "/tests/matched_bytes.py"; mt = open(mp).read()
for n in names: mt = re.sub(r'    \("' + re.escape(n) + r'", 0x[0-9A-F]+, .*?"\),\n', "", mt, flags=re.S)
open(mp, "w").write(mt)
add = [" ".join(x) + "\n" for x in L if len(x) == 3]
if add:
    open(SP + "/fixnames.txt", "w").write("".join(add))
    print(subprocess.run(["python3", SP + "/addnames.py", SP + "/fixnames.txt"], capture_output=True, text=True).stdout.strip())
print("removed", len(names) - len(add), "moved", len(add))
