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
    # a hand port is edited directly; regenerating it would replace it with the PS2 port
    if "Ported from the PS2 C" not in old[:2000]:
        print(rel, "is a hand port, not regenerated"); continue
    revs = subprocess.run(["git", "log", "--format=%h", "--", gp], cwd=OG, capture_output=True, text=True).stdout.split()
    ph = None
    for r in revs:
        s = subprocess.run(["git", "show", f"{r}:{gp}"], cwd=OG, capture_output=True, text=True).stdout
        if "PlayStation 2 C, not hand-adjusted" in s[:3000]: ph = s; break
    if ph is None:
        # a file ported after the PS2-copy ports (newport.py) has no
        # placeholder in git; make it again from the PS2 C
        import newport
        ph = newport.placeholder(rel)
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
    # portgen writes some lines itself (the portcheck "PS2-only callees ..."
    # line, callee lists); a carried note drops any sentence the new header
    # already has, so it is not written twice
    flat_new = re.sub(r"\s+", " ", re.sub(r"\n \* ", " ", new.split(" */", 1)[0]))
    def fresh(txt):
        # also drop a sentence that repeats one kept earlier in the same note
        # (earlier regens multiplied some)
        kept = []
        for s in re.split(r"(?<=\.) (?=[A-Z(])", txt):
            n = re.sub(r"\s+", " ", s).strip()
            if n and n not in flat_new and not any(n in k for k in kept):
                kept.append(n)
        return " ".join(kept)
    notes = {n: fresh(txt) for n, txt in notes.items()}
    keep = [f"{rel}|{n}|{txt}" for n, txt in notes.items() if txt and re.search(rf"^ \* {re.escape(n)} 0x[0-9A-F]+ size 0x[0-9A-F]+\.", new, re.M)]
    if keep:
        open(SP + "/regen_ann.txt", "w").write("\n".join(keep) + "\n")
        subprocess.run(["python3", SP + "/annotate.py", SP + "/regen_ann.txt"], capture_output=True)
    print(rel, "regenerated;", len(keep), "notes carried over")
