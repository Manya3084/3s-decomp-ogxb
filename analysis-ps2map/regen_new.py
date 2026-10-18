# regen_new.py : regenerate every ported file that mentions a name added to
# funcs.txt since HEAD (as a call, definition, or sub_ADDR), then report
# function bodies that changed beyond renames (bodydiff.py).
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import re, os, subprocess, sys
OG = _OG; SP = OG + "/analysis-ps2map"
diff = subprocess.run(["git", "-C", OG, "diff", "-U0", "HEAD", "--", "config/sf33rd/symbols/funcs.txt"], capture_output=True, text=True).stdout
new = {m[1]: int(m[2], 16) for m in re.finditer(r"^\+(\w+) = 0x([0-9A-Fa-f]+);", diff, re.M)}
pat = re.compile(r"\b(" + "|".join(map(re.escape, list(new) + ["sub_%08X" % v for v in new.values()])) + r")\b")
files = []
for r, _, fs in os.walk(OG + "/src/sf33rd/Source"):
    for f in fs:
        p = os.path.join(r, f); s = open(p, errors="replace").read()
        if "Ported from the PS2" in s[:4000] and pat.search(s): files.append(os.path.relpath(p, OG + "/src/sf33rd/Source"))
files += [a for a in sys.argv[1:] if a not in files]
print(len(new), "new names;", len(files), "files")
out = subprocess.run(["python3", SP + "/regen.py"] + files, capture_output=True, text=True)
print("\n".join(l for l in (out.stdout + out.stderr).splitlines() if "regenerated" not in l))
print(subprocess.run(["python3", SP + "/bodydiff.py"] + files, capture_output=True, text=True).stdout)
for f in files:
    e = subprocess.run(["gcc", "-m32", "-std=gnu17", "-Wno-incompatible-pointer-types", "-fsyntax-only", "-I" + OG + "/include", f"{OG}/src/sf33rd/Source/{f}"], capture_output=True, text=True).stderr
    if "error" in e: print("COMPILE", f)
