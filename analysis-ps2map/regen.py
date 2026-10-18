# regen.py Game/X.c... : regenerate already-ported files from their last
# placeholder version in git, applying new names/folds, and carry over each
# function's "Read against the x86" note.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, os, re, subprocess
OG = _OG; SP = OG + "/analysis-ps2map"
def notes_of(t):
    hdr = t.split(" */", 1)[0]
    flat = re.sub(r"\n \* ", " ", hdr)
    out = {}
    for m in re.finditer(r"(\w+) 0x[0-9A-F]+ size 0x[0-9A-F]+\. Read against the x86: (.*?)(?= \w+ 0x[0-9A-F]+ size| \w+ is folded| Not located| Data:| Globals:| Unnamed data| TARGET_PS2|$)", flat):
        out[m[1]] = m[2].strip()
    return out
for rel in sys.argv[1:]:
    path = f"{OG}/src/sf33rd/Source/{rel}"; gp = f"src/sf33rd/Source/{rel}"
    old = open(path).read(); notes = notes_of(old)
    revs = subprocess.run(["git", "log", "--format=%h", "--", gp], cwd=OG, capture_output=True, text=True).stdout.split()
    ph = None
    for r in revs:
        s = subprocess.run(["git", "show", f"{r}:{gp}"], cwd=OG, capture_output=True, text=True).stdout
        if "PlayStation 2 C, not hand-adjusted" in s[:3000]: ph = s; break
    if ph is None: print(rel, "no placeholder in history"); continue
    open(path, "w").write(ph)
    subprocess.run(["python3", SP + "/headers.py"], capture_output=True)
    if os.path.exists(SP + "/portgen_new.json"): os.remove(SP + "/portgen_new.json")
    subprocess.run(["python3", SP + "/portgen.py", rel], capture_output=True)
    if os.path.exists(SP + "/portgen_new.json"):
        print(rel, subprocess.run(["python3", SP + "/applynew.py"], capture_output=True, text=True).stdout.strip().replace("\n", "; "))
        subprocess.run(["python3", SP + "/headers.py"], capture_output=True)
    r = subprocess.run(["python3", SP + "/portgen.py", rel, "--write"], capture_output=True, text=True)
    if "NOT WRITTEN" in r.stderr or "Traceback" in r.stderr:
        open(path, "w").write(old); print(rel, "NOT WRITTEN, kept old\n", r.stderr[-800:]); continue
    if os.path.exists(SP + "/portgen_new.json"): os.remove(SP + "/portgen_new.json")
    new = open(path).read()
    keep = [f"{rel}|{n}|{txt}" for n, txt in notes.items() if re.search(rf"^ \* {re.escape(n)} 0x[0-9A-F]+ size 0x[0-9A-F]+\.", new, re.M)]
    if keep:
        open(SP + "/regen_ann.txt", "w").write("\n".join(keep) + "\n")
        subprocess.run(["python3", SP + "/annotate.py", SP + "/regen_ann.txt"], capture_output=True)
    print(rel, "regenerated;", len(keep), "notes carried over")
