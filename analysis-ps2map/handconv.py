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
from ps2paths import OG as _OG, PS as _PS
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


KEEP = "--keep" in sys.argv  # leave a conversion that lost matches, to fix it
for rel in [a for a in sys.argv[1:] if not a.startswith("--")]:
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
    # the hand port's prototypes and extern data declarations come along:
    # its bodies were written against them (a helper returning a pointer, a
    # caller's own parameter types). Its local struct types do not, since
    # the generated port has structs.h's.
    live = re.sub(r"^#if 0\b.*?^#endif\b", "", hand, flags=re.M | re.S)
    ps2 = open(f"{_PS}/src/anniversary/sf33rd/Source/{rel}", errors="replace").read()
    hand_names = {re.search(r"\b(\w+)\s*\(", f).group(1) for f in fs}
    # the PS2 text outside the functions the hand port wrote: a name used or
    # defined there gets the PS2 header's declaration, not the hand port's
    rest = ps2
    for n in hand_names:
        m = re.search(r"^[A-Za-z_][^;\n]*?\b" + re.escape(n) + r"\s*\([^;{}]*\)\s*\{", rest, re.M)
        if m:
            i, d = m.end() - 1, 0
            while i < len(rest):
                if rest[i] == "{": d += 1
                elif rest[i] == "}":
                    d -= 1
                    if d == 0: break
                i += 1
            rest = rest[:m.start()] + rest[i + 1:]
    used_in_bodies = set(re.findall(r"\b[A-Za-z_]\w*\b", "\n".join(fs)))
    decls = []
    for m in re.finditer(r"^(?:extern\s+[^;{}=]+;|(?:static\s+)?[A-Za-z_][\w \*]*\b\w+\s*\([^;{}()]*\)\s*;)", live, re.M):
        d = m.group(0)
        if d.startswith(("typedef", "return")):
            continue
        fn = re.search(r"\b(\w+)\s*\(", d) or re.search(r"\b(\w+)\s*(?:\[[^\]]*\]\s*)*;", d)
        name = fn.group(1) if fn else None
        # a struct member of the same name (sys_w.bgm_type) is another thing
        if not name or name not in used_in_bodies or re.search(r"(?<![.>\w])" + re.escape(name) + r"\b", rest):
            continue
        decls.append(d)
    open(ovp, "w").write(note + "\n" + "\n".join(decls) + "\n\n" + "\n\n".join(fs) + "\n")
    os.remove(path)
    r = run("python3", SP + "/newport.py", rel)
    ok = "placeholder" in r.stdout
    if ok:
        for attempt in range(4):
            r = run("python3", SP + "/batch.py", "1")
            ok = os.path.exists(path) and "Ported from the PS2" in open(path).read()[:4000] and "NOT WRITTEN" not in r.stdout
            if ok:
                break
            # a call the declaration index lacks: take its prototype from the
            # PS2 headers and retry
            missing = set(re.findall(r"implicit declaration of function [‘']([A-Za-z_]\w*)[’']", r.stdout + r.stderr))
            found = []
            for fn in missing:
                for hr, _, hfs in os.walk(f"{_PS}/include"):
                    for hf in hfs:
                        if not hf.endswith(".h"):
                            continue
                        m = re.search(r"^[A-Za-z_][^;\n{}]*\b" + re.escape(fn) + r"\s*\([^;{}]*\)\s*;", open(os.path.join(hr, hf), errors="replace").read(), re.M)
                        if m:
                            found.append(m.group(0)); break
                    else:
                        continue
                    break
            if not found:
                break
            ov = open(ovp).read()
            open(ovp, "w").write(ov.replace("\n\n", "\n" + "\n".join(found) + "\n\n", 1))
            if not os.path.exists(path):
                run("python3", SP + "/newport.py", rel)
    if ok:
        run("python3", OG + "/tools/build_c.py", "-j", "24")
        run("python3", OG + "/tools/objdiff.py")
        after = statuses()
        lost = [k for k, s in before.items() if s == "match" and after.get(k) != "match"]
        gained = [k for k, s in after.items() if s == "match" and before.get(k) != "match"]
        # nothing lost and something gained: a conversion that adds no match
        # only churns a working hand port
        ok = (not lost and bool(gained)) or KEEP
        if lost and KEEP:
            print(rel, "kept for fixing; lost " + ", ".join(lost))
    if not ok:
        open(path, "w").write(hand)
        if old_ov is None:
            os.remove(ovp)
        else:
            open(ovp, "w").write(old_ov)
        run("python3", OG + "/tools/build_c.py", "-j", "24")
        run("python3", OG + "/tools/objdiff.py")
        print(rel, "reverted:", "lost " + ", ".join(lost[:8]) if "lost" in dir() and lost else (r.stdout[-1500:] + r.stderr[-1500:]))
        continue
    print(rel, f"converted: {len(fs)} hand bodies kept as overrides, +{len(gained)} matches")
