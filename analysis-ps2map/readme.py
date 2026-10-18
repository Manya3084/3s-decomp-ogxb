import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import re, subprocess
OG = _OG
out = subprocess.run(["python3", "tools/progress.py"], cwd=OG, capture_output=True, text=True).stdout
named = int(re.search(r"named (\d+)", out)[1]); inside = int(re.search(r"inside a scanned span (\d+)", out)[1])
p = OG + "/README.md"; s = open(p).read()
s = re.sub(r"^\d+ functions are named in `config/sf33rd/symbols/funcs.txt`\. The matching C is under `src/`\. A name is added when the retail body matches C from the PlayStation 2 decompilation\.( Bodies located from the PS2 map carry the PS2 C unchanged; see \[decompiling\.md\]\(docs/decompiling\.md#bodies-located-from-the-ps2-map\)\.)?",
           f"{named} functions are named in `config/sf33rd/symbols/funcs.txt`. The matching C is under `src/`. A name is added when the retail body matches C from the PlayStation 2 decompilation. Bodies located from the PS2 map carry the PS2 C unchanged; see [decompiling.md](docs/decompiling.md#bodies-located-from-the-ps2-map).", s, count=1, flags=re.M)
def words(n):
    return str(n)
s = re.sub(r"(`make progress` counts those names\. )[^.]*? of them sit inside a scanned span", lambda m: m[1] + f"{inside} of them sit inside a scanned span", s, count=1)
open(p, "w").write(s)
print(named, inside)
