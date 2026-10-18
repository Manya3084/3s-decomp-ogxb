# annotate.py LISTFILE : each line "Game/X.c|FUNC|text". Replaces the FLAG on
# FUNC's header line with "Read against the x86: text", rewrapping the header.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, textwrap
OG = _OG
by = {}
for l in open(sys.argv[1]):
    l = l.rstrip("\n")
    if not l.strip(): continue
    f, n, txt = l.split("|", 2); by.setdefault(f, []).append((n, txt))
for f, L in by.items():
    p = f"{OG}/src/sf33rd/Source/{f}"; t = open(p).read()
    hdr, body = t.split(" */", 1)
    # unwrap header into logical lines: a logical line starts with " * " + Capital/identifier
    lines = hdr.split("\n"); first = lines[0]; logical = []
    for l in lines[1:]:
        s = l[3:] if l.startswith(" * ") else l.lstrip(" *")
        if logical and (s.startswith(" ") or not re.match(r"^(\w+ 0x[0-9A-F]+ size|\w+ is folded|Not located|Data:|Globals:|Ported|x86 by|and globals|\w+ (stays|is folded|has no)|[A-Z])", s)):
            logical[-1] += " " + s.strip()
        else: logical.append(s)
    for n, txt in L:
        hit = False
        for i, s in enumerate(logical):
            if re.match(rf"^{re.escape(n)} 0x[0-9A-F]+ size 0x[0-9A-F]+\.", s):
                logical[i] = re.sub(r" (?:FLAG|Read against the x86): .*$", "", s) + " Read against the x86: " + txt; hit = True
        assert hit, (f, n)
    out = [first]
    for s in logical:
        w = textwrap.wrap(s, 76, break_on_hyphens=False) or [""]
        out += [" * " + x for x in w]
    open(p, "w").write("\n".join(out) + "\n */" + body)
print("annotated", sum(len(v) for v in by.values()))
