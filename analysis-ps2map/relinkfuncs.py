# relinkfuncs.py [--apply] : locate functions from the relink check.
#
# relinkdata.json holds each name the matching C uses that has no address,
# with the address the retail code uses there. A name at a code address is a
# function: alone at an unnamed address it is a new location (named with
# addat.py); sharing an address with other names, or with a funcs.txt name,
# it is an MSVC fold of identical PS2 twins (recorded in folded.json, and the
# funcs.txt name there is removed, as for every fold). Without --apply this
# only prints the plan. Run regen_new.py afterwards.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG
import json, os, re, sys, subprocess, collections
SP = _OG + "/analysis-ps2map"
RL = json.load(open(SP + "/relinkdata.json"))
RL.pop("rebase", None)
FO = json.load(open(SP + "/folded.json"))
F = {}
for l in open(_OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+) = 0x([0-9A-F]+);", l)
    if m: F[m[1]] = int(m[2], 16)
byaddr = {v: n for n, v in F.items()}
folded = {n for v in FO.values() for n in v}
groups = collections.defaultdict(list)
for n, a in RL.items():
    a = int(a, 16)
    if a < 0x218DC0 and n not in F and n not in folded:
        groups[a].append(n)
new, folds, unname = [], {}, []
for a, names in sorted(groups.items()):
    key = f"0x{a:x}"
    if len(names) == 1 and a not in byaddr and key not in FO:
        new.append(f"{names[0]}={a:X}")
        continue
    folds[key] = sorted(set(FO.get(key, [])) | set(names) | ({byaddr[a]} if a in byaddr else set()))
    if a in byaddr: unname.append(byaddr[a])
print("new locations", len(new), new)
print("folds", len(folds), folds)
print("unname", unname)
if "--apply" in sys.argv:
    if new:
        print(subprocess.run(["python3", SP + "/addat.py"] + new, capture_output=True, text=True).stdout.splitlines()[-1])
    if unname:
        open(SP + "/relinkfuncs_unname.txt", "w").write("\n".join(unname) + "\n")
        print(subprocess.run(["python3", SP + "/fixnames.py", SP + "/relinkfuncs_unname.txt"], capture_output=True, text=True).stdout.strip())
        os.remove(SP + "/relinkfuncs_unname.txt")
    FO.update(folds)
    json.dump(FO, open(SP + "/folded.json", "w"), indent=0)
