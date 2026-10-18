#!/bin/bash
set -e
cd "$(dirname "$0")/.."
S="$PWD/analysis-ps2map"
python3 $S/tables.py
python3 $S/tables2.py
python3 $S/localtabs.py
python3 $S/xprop2.py $S/xprop2.json | tail -1
python3 $S/unfold.py
out=$(python3 $S/gen.py '.')
echo "$out"
[ "$out" = "nothing" ] && exit 3
python3 -m unittest discover -s tests 2>&1 | tail -1 | grep -q OK
python3 - <<'PY'
import sys,re,json,subprocess
import os; sys.path.insert(0, os.getcwd() + "/analysis-ps2map")
from feat import *
S = os.getcwd() + "/analysis-ps2map/"
T={int(k,16) for k in json.load(open(S+"tables.json"))}|{int(k,16) for k in json.load(open(S+"tables2.json"))}|{int(k,16) for k in json.load(open(S+"localtabs.json"))}
head=subprocess.run(["git","show","HEAD:config/sf33rd/symbols/funcs.txt"],capture_output=True,text=True).stdout
old={l.split(" = ")[0] for l in head.splitlines() if " = " in l}
cur={}; sz={}
for l in open("config/sf33rd/symbols/funcs.txt"):
    m=re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)",l)
    if m: cur[int(m[2],16)]=m[1]; sz[int(m[2],16)]=int(m[3],16)
nt=[(va,n) for va,n in cur.items() if n not in old and va not in T and n in pinfo]
fl=[(hex(va),n) for va,n in nt if pushed_const_veto(n,va,sz[va],cur) or (lambda r:(not r[0] and r[1]>0))(accept(n,va,sz[va]))]
print("new non-table",len(nt),"flagged",fl)
sys.exit(4 if fl else 0)
PY
python3 $S/foldnotes.py >/dev/null
python3 $S/readme.py >/dev/null
tot=$(grep -oE '^[0-9]+ functions are named' README.md | cut -d' ' -f1)
why=$(python3 -c "import json;d=json.load(open('$S/genlast.json'));print(', '.join(f'{k} {v}' for k,v in d['why'].items()))")
n=$(python3 -c "import json;print(json.load(open('$S/genlast.json'))['count'])")
git add -A README.md config tests src
git commit -q -F - <<MSG
Locate $n more functions from the PS2 map.

Another pass of the table, call-graph, source-order, signature, and
fingerprint rules over the new anchors. Placed by: $why. Every non-table name
passed the constant, field offset, callee, call-site count, size, and
argument checks in docs/decompiling.md. $tot functions are named.

Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>
MSG
git push -q origin HEAD
git log origin/main --oneline -1
