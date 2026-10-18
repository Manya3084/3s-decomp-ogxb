# List PS2-copy placeholder files: named, folded, C defs, total located size.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import os, re
D = (_OG + "/src/sf33rd/Source")
rows = []
for r, _, fs in os.walk(D):
    for f in fs:
        p = os.path.join(r, f); t = open(p, errors="replace").read()
        if "PlayStation 2 C, not hand-adjusted" not in t[:3000]: continue
        hdr = t.split(" */", 1)[0]
        named = re.findall(r"^ \* (\w+) 0x([0-9A-F]+) size 0x([0-9A-F]+)\.$", hdr, re.M)
        fold = len(re.findall(r" is folded into 0x", hdr))
        body = t.split(" */", 1)[1]
        defs = len(re.findall(r"^[A-Za-z_][\w \*]*\b\w+\s*\([^;]*\)\s*\{", body, re.M))
        sz = sum(int(s, 16) for _, _, s in named)
        rows.append((os.path.relpath(p, D), len(named), fold, defs, sz, len(t)))
import sys
key = sys.argv[1] if len(sys.argv) > 1 else "size"
rows.sort(key=lambda x: (x[3] - x[1] - x[2] > 0, x[4]))
for r in rows: print(*r)
print(len(rows), "files; fully located", sum(1 for r in rows if r[1] + r[2] >= r[3]), "total located bytes", hex(sum(r[4] for r in rows)))
