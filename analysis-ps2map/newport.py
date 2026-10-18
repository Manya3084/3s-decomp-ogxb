# newport.py Game/X.c... : make a placeholder for a PS2 file that has no
# port yet, from its PS2 C and the funcs.txt names it defines, so that
# regen.py can port it like the others. gen.py makes placeholders for files
# whose functions still need names; this is for files whose functions were
# named another way (call alignment, the relink check) after the PS2-copy
# files were ported.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, PS as _PS
import os, re, sys, json

OG = _OG
MARK = " * PlayStation 2 C, not hand-adjusted for Xbox."
funcs = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*0x([0-9A-Fa-f]+);.*size:0x([0-9A-Fa-f]+)", l)
    if m: funcs[m[1]] = (int(m[2], 16), int(m[3], 16))
folded = {n: k for k, v in json.load(open(OG + "/analysis-ps2map/folded.json")).items() for n in v}
DEF = re.compile(r"^(?:static\s+)?[A-Za-z_][\w \*]*?\b(\w+)\s*\([^;{}]*\)\s*\{", re.M)
for rel in sys.argv[1:]:
    src = f"{_PS}/src/anniversary/sf33rd/Source/{rel}"
    dst = f"{OG}/src/sf33rd/Source/{rel}"
    if os.path.exists(dst):
        print(rel, "already exists"); continue
    text = open(src, errors="replace").read()
    names = [m[1] for m in DEF.finditer(text) if m[1] not in ("if", "while", "for", "switch")]
    located = sorted((funcs[n][0], n) for n in names if n in funcs)
    if not located:
        print(rel, "defines no located function"); continue
    hdr = [f"/* {os.path.basename(rel)}, retail sf33rd.xbe.",
           MARK + " Each named body was located",
           " * from the PS2 retail map, call alignment, or the relink check. See",
           " * docs/decompiling.md.",
           " * The #include lines name headers in the PS2 tree (ps2.path)."]
    hdr += [f" * {n} 0x{a:X} size 0x{funcs[n][1]:X}." for a, n in located]
    if len(located) < len(set(names)):
        hdr.append(" * The other functions in this file are not located in sf33rd.xbe yet.")
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    open(dst, "w").write("\n".join(hdr) + "\n */\n\n" + text)
    print(rel, "placeholder with", len(located), "located of", len(set(names)))
