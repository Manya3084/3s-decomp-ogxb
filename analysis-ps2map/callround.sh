#!/bin/bash
# One callalign naming round: propose, check order and features, select.
set -e
cd "$(dirname "$0")/.."
S=${1:-/tmp}
python3 analysis-ps2map/callalign.py > $S/ca.txt 2>$S/ca.err
python3 analysis-ps2map/ordercheck.py
DIAG=analysis-ps2map/callalign.json python3 analysis-ps2map/xprop2.py /dev/null > $S/diag.txt
python3 - "$S" <<'PY'
import json, re, sys
S = sys.argv[1]
oc = json.load(open("analysis-ps2map/ordercheck.json"))
d = {}
for l in open(f"{S}/diag.txt"):
    p = l.split(); d[p[0]] = " ".join(p[2:])
f = []
for l in open("config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: f.append((int(m[2], 16), int(m[3], 16), m[1]))
acc = []; hold = 0
for l in open(f"{S}/ca.txt"):
    r = l.split(); n, a, s = r[0], int(r[1], 16), int(r[2], 16); h = int(r[12]); o = oc[hex(a)]
    if any(x[0] < a < x[0] + x[1] for x in f): hold += 1; continue
    feat = "accept-fail" not in d.get(n, "accept-fail")
    ok = (not (o == "none" and h <= 3)) if h >= 2 else (o == "both" or (o == "one" and feat))
    if ok: acc.append(f"{n} {a:X} {s:X}\n")
    else: hold += 1
open(f"{S}/accept.txt", "w").write("".join(acc))
print(len(acc), "accept", hold, "hold")
PY
