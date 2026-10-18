# Apply portgen_new.json: name table entries portgen pinned, and add fold
# notes for entries that share a body. Names need a sane size ratio and no
# pushed-constant veto; the rest are reported and skipped.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, json, re, bisect, os, subprocess
sys.path.insert(0, _SP)
from feat import cfg_extent, padded_end, pinfo, pushed_const_veto, TEND
OG = _OG; SP = OG + "/analysis-ps2map"
J = json.load(open(SP + "/portgen_new.json"))
xf = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: xf[int(m[2], 16)] = m[1]
names_used = set(xf.values())
FO = json.load(open(SP + "/folded.json"))
stops = sorted(set(xf) | {int(k, 16) for k in FO} | {v for _, v in J["names"]} | {v for _, v in J["folds"]})
add = []
for w, v in J["names"]:
    if w in names_used or v in xf: continue
    i = bisect.bisect_right(stops, v); nx = stops[i] if i < len(stops) else TEND
    sz = padded_end(cfg_extent(v, stops), nx) - v
    ok = True; why = ""
    if w in pinfo:
        r = sz / pinfo[w][1]
        if not (0.15 <= r <= 3): ok = False; why = f"size x{sz:#x}/p{pinfo[w][1]:#x}"
        elif pushed_const_veto(w, v, sz, xf): ok = False; why = "pushed constant"
    if ok: add.append(f"{w} {v:X} {sz:X}\n")
    else: print("SKIP", w, hex(v), why)
if add:
    open(SP + "/applynew.txt", "w").write("".join(add))
    print(subprocess.run(["python3", SP + "/addnames.py", SP + "/applynew.txt"], capture_output=True, text=True).stdout.strip())
if J["folds"]:
    p = f"{OG}/src/sf33rd/Source/{J['file']}"; t = open(p).read(); hdr, body = t.split(" */", 1)
    lines = hdr.split("\n")
    for w, v in J["folds"]:
        FO.setdefault(hex(v), [])
        if w not in FO[hex(v)]: FO[hex(v)].append(w)
    for w, v in J["folds"]:
        others = len(FO[hex(v)]) - 1
        ln = f" * {w} is folded into 0x{v:X} with {others} other bodies. Unnamed."
        if not any(l.startswith(f" * {w} is folded") for l in lines):
            j = next((i for i, l in enumerate(lines) if l.startswith(" * The other functions")), len(lines))
            lines.insert(j, ln)
    open(p, "w").write("\n".join(lines) + " */" + body)
    json.dump(FO, open(SP + "/folded.json", "w"), indent=0)
    print("folds", len(J["folds"]))
# a named body that is really a fold of byte-identical twins: unname it
def file_of(n):
    for r_, _, fs_ in os.walk(OG + "/src"):
        for f_ in fs_:
            q = os.path.join(r_, f_); s = open(q, errors="replace").read()
            if re.search(r"^[A-Za-z_][\w \*]*\b" + re.escape(n) + r"\s*\([^;]*\)\s*\{", s, re.M): return q
    return None
for x, w, v in J.get("refold", []):
    fp = OG + "/config/sf33rd/symbols/funcs.txt"
    rows = [l for l in open(fp) if not l.startswith(f"{x} = ")]
    if len(rows) != sum(1 for _ in open(fp)):
        open(fp, "w").write("".join(rows))
        mp = OG + "/tests/matched_bytes.py"; mt = open(mp).read()
        mt = re.sub(r'    \("' + re.escape(x) + r'", 0x[0-9A-F]+, .*?"\),\n', "", mt, flags=re.S)
        open(mp, "w").write(mt)
    FO.setdefault(hex(v), [])
    for n in (x, w):
        if n not in FO[hex(v)]: FO[hex(v)].append(n)
    for n in (x, w):
        q = file_of(n)
        if not q: continue
        t = open(q).read(); hdr, body = t.split(" */", 1)
        hdr = re.sub(r"\n \* " + re.escape(n) + r" (?:is )?0x[0-9A-F]+ size 0x[0-9A-F]+\.[^\n]*(?:\n \*  [^\n]*)*", "", hdr)
        if f" * {n} is folded" not in hdr:
            hdr += f"\n * {n} is folded into 0x{v:X} with {len(FO[hex(v)]) - 1} other bodies. Unnamed."
        open(q, "w").write(hdr + " */" + body)
    print("refold", x, w, hex(v))
json.dump(FO, open(SP + "/folded.json", "w"), indent=0)
os.remove(SP + "/portgen_new.json")
