# handconv.py Game/X.c... : turn a hand port into a generated port.
#
# A hand port holds only the functions someone wrote out, and the rest of
# its PS2 file stays without C. Here the hand port's function bodies and its
# header notes become overrides/X.c, the PS2 file is made a placeholder
# (newport.py) and ported (batch.py), and the tree is rebuilt. The
# conversion is kept only when every function that matched still matches;
# otherwise the hand port and the old override come back.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG
import os, re, sys, json, shutil, subprocess

OG = _OG
SP = OG + "/analysis-ps2map"


def bodies(text):
    out = []
    body = text.split("*/", 1)[1] if text.lstrip().startswith("/*") else text
    for m in re.finditer(r"^[A-Za-z_][^;\n]*\)\s*\{", body, re.M):
        i, d = m.end() - 1, 0
        while True:
            if body[i] == "{": d += 1
            elif body[i] == "}":
                d -= 1
                if d == 0: break
            i += 1
        out.append(body[m.start():i + 1])
    return out


def statuses():
    R = json.load(open(OG + "/build/objdiff.json"))
    return {f"{o}|{f['name']}": f["status"] for o, r in R.items() for f in r["functions"] if "va" in f}


def run(*cmd):
    return subprocess.run(list(cmd), cwd=OG, capture_output=True, text=True)


for rel in sys.argv[1:]:
    path = f"{OG}/src/sf33rd/Source/{rel}"
    ovp = f"{SP}/overrides/{os.path.basename(rel)}"
    hand = open(path).read()
    if "Ported from the PS2" in hand[:4000]:
        print(rel, "is already generated"); continue
    old_ov = open(ovp).read() if os.path.exists(ovp) else None
    before = statuses()
    head = hand.split("*/", 1)[0] + "*/\n" if hand.lstrip().startswith("/*") else ""
    note = "/* Notes from the hand port this file replaced:\n" + head.split("\n", 1)[1] if head else ""
    fs = bodies(hand)
    open(ovp, "w").write(note + "\n" + "\n\n".join(fs) + "\n")
    os.remove(path)
    r = run("python3", SP + "/newport.py", rel)
    ok = "placeholder" in r.stdout
    if ok:
        r = run("python3", SP + "/batch.py", "1")
        ok = os.path.exists(path) and "Ported from the PS2" in open(path).read()[:4000] and "NOT WRITTEN" not in r.stdout
    if ok:
        run("python3", OG + "/tools/build_c.py", "-j", "24")
        run("python3", OG + "/tools/objdiff.py")
        after = statuses()
        lost = [k for k, s in before.items() if s == "match" and after.get(k) != "match"]
        gained = [k for k, s in after.items() if s == "match" and before.get(k) != "match"]
        ok = not lost
    if not ok:
        open(path, "w").write(hand)
        if old_ov is None:
            os.remove(ovp)
        else:
            open(ovp, "w").write(old_ov)
        run("python3", OG + "/tools/build_c.py", "-j", "24")
        run("python3", OG + "/tools/objdiff.py")
        print(rel, "reverted:", "lost " + ", ".join(lost[:8]) if "lost" in dir() and lost else (r.stdout[-400:] + r.stderr[-400:]))
        continue
    print(rel, f"converted: {len(fs)} hand bodies kept as overrides, +{len(gained)} matches")
