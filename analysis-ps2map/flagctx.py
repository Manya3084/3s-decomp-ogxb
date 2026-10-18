# flagctx.py Game/X.c... : for each FLAG in the header, print the x86 lines
# with the flagged value (2 lines of context) and the C lines that mention it.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re
sys.path.insert(0, _SP)
import portcheck as pc
from feat import _dis, text, TVA
OG = _OG
for rel in sys.argv[1:]:
    t = open(f"{OG}/src/sf33rd/Source/{rel}").read()
    hdr, body = t.split(" */", 1)
    flat = re.sub(r"\n \* ", " ", hdr)
    for n, fl in re.findall(r"(\w+) 0x[0-9A-F]+ size 0x[0-9A-F]+\. FLAG: (.*?\.)(?= \w+ (?:0x|is )| Data:| Globals:| Not located| Read|$)", flat):
        print(f"##### {rel} {n}: {fl}")
        va, sz = pc.xf[n]
        ins = list(_dis.disasm(text[va - TVA: va - TVA + sz], va))
        vals = []
        for part in fl.rstrip(".").split("; "):
            kind, _, rest = part.rpartition(" ")
            for v in rest.split(","):
                try: vals.append((kind, int(v, 0)))
                except ValueError: vals.append((kind, v))
        want = set()
        for kind, v in vals:
            if isinstance(v, str): continue
            pats = {hex(v), hex(v & 0xFFFFFFFF), f"- {hex(-v)}" if v < 0 else f"+ {hex(v)}", (f"- {-v}]" if v < 0 else f"+ {v}]") if abs(v) < 10 else hex(v)}
            for k, i in enumerate(ins):
                s = i.op_str
                if any(re.search(re.escape(p) + r"\b", s) for p in pats): want |= set(range(max(0, k - 2), min(len(ins), k + 3)))
        for k in sorted(want):
            i = ins[k]; o = i.op_str
            for h in re.findall(r"0x[0-9a-f]+", o):
                x = int(h, 16)
                if x in pc.xa: o = o.replace(h, f"{h}<{pc.xa[x]}>")
                elif x >= 0x218DC0 and pc.xsym(x): o = o.replace(h, f"{h}<{pc.xsym(x)}>")
            print(f"   {i.address:x} {i.mnemonic} {o}")
        m = re.search(r"^[A-Za-z_][\w \*]*\b" + re.escape(n) + r"\s*\([^;{]*\)\s*\{", body, re.M)
        if m:
            i0 = m.start(); d = 0
            for j in range(m.end() - 1, len(body)):
                if body[j] == "{": d += 1
                elif body[j] == "}":
                    d -= 1
                    if d == 0: break
            fb = body[i0:j + 1].split("\n")
            nums = {str(abs(v)) for _, v in vals if not isinstance(v, str)} | {hex(abs(v)).upper().replace("0X", "0x") for _, v in vals if not isinstance(v, str)}
            hit = [l for l in fb if any(re.search(r"\b" + re.escape(x) + r"\b", l, re.I) for x in nums)]
            for l in hit[:8]: print("   C:", l.strip())
