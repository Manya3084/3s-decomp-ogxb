# batch.py N [--skip a,b] : port the next N placeholder files (smallest located
# size first) with portgen, then print each flagged function's flag, C, and x86.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, subprocess, re, os
OG = _OG; SP = OG + "/analysis-ps2map"
N = int(sys.argv[1]); skip = set(sys.argv[sys.argv.index("--skip") + 1].split(",")) if "--skip" in sys.argv else set()
q = subprocess.run(["python3", SP + "/queue.py"], capture_output=True, text=True).stdout.splitlines()[:-1]
rows = [l.split() for l in q]
rows.sort(key=lambda r: int(r[4]))
todo = [r[0] for r in rows if os.path.basename(r[0])[:-2] not in skip and not r[0].startswith("Compress/zlib")][:N]
def guard():
    n = sum(1 for _ in open(OG + "/config/sf33rd/symbols/funcs.txt"))
    r = subprocess.run(["python3", "-m", "unittest", "discover", "-s", OG + "/tests"], capture_output=True, text=True, cwd=OG)
    assert n > 5000 and "OK" in r.stderr.splitlines()[-1], ("GUARD", n, r.stderr[-500:])
for f in todo:
    if os.path.exists(SP + "/portgen_new.json"): os.remove(SP + "/portgen_new.json")
    subprocess.run(["python3", SP + "/portgen.py", f], capture_output=True, text=True)
    if os.path.exists(SP + "/portgen_new.json"):
        print(f"## {f} new:", subprocess.run(["python3", SP + "/applynew.py"], capture_output=True, text=True).stdout.strip().replace("\n", "; "))
        subprocess.run(["python3", SP + "/headers.py"], capture_output=True, text=True)
        guard()
    r = subprocess.run(["python3", SP + "/portgen.py", f, "--write"], capture_output=True, text=True)
    if os.path.exists(SP + "/portgen_new.json"): os.remove(SP + "/portgen_new.json")
    err = r.stderr.strip()
    if "NOT WRITTEN" in err or "Traceback" in err:
        print(f"### {f} NOT WRITTEN\n{err[-1500:]}\n"); continue
    hdr = open(f"{OG}/src/sf33rd/Source/{f}").read().split(" */", 1)[0]
    flat = re.sub(r"\n \* ", " ", hdr)
    flags = re.findall(r"(\w+) 0x[0-9A-F]+ size 0x[0-9A-F]+\. FLAG: (.*?\.)(?= \w+ (?:0x|is )| Data:| Globals:| Not located|$)", flat)
    data = re.findall(r"Data: ([^.]*(?:DIFFER|not located|not compared)[^.]*)\.", flat)
    print(f"### {f}: {len(flags)} flagged" + (f"; data: {data}" if data else ""))
    for n, fl in flags: print(f"  {n}: {fl}")
