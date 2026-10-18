# xblocks.py FILE TABLE ADDR NBLOCKS [--write FLAGVAR]
# Compare a string-pointer table's C initializer with NBLOCKS consecutive XBE
# copies at ADDR; print each difference. With --write, rewrite the C table
# as [NBLOCKS][...] from the XBE strings (the C initializer is the template)
# and index it with FLAGVAR.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, struct, pathlib
OG = _OG
sys.path.insert(0, OG + "/tools")
from ogxb.xbe import load
img = load(pathlib.Path(open(OG + "/xbe.path").read().strip()))
f, tab, addr, nb = sys.argv[1], sys.argv[2], int(sys.argv[3], 16), int(sys.argv[4])
p = f"{OG}/src/sf33rd/Source/{f}"; t = open(p).read()
m0 = re.search(r"((?:const )?s8\s*\*\s*(?:const\s+)?" + re.escape(tab) + r")((?:\[\d+\])+)\s*=\s*\{", t)
i = m0.end() - 1; d = 0; j = i
while j < len(t):
    c = t[j]
    if c == '"':
        j += 1
        while t[j] != '"': j += 2 if t[j] == "\\" else 1
    elif c == "{": d += 1
    elif c == "}":
        d -= 1
        if d == 0: break
    j += 1
k = t.index(";", j) + 1
class _M:
    def __init__(s, g): s.g = g
    def __getitem__(s, n): return s.g[n]
m = _M({0: t[m0.start():k] + ("\n" if t[k:k+1] == "\n" else ""), 1: m0[1], 2: m0[2], 3: t[i:j + 1]})
dims = [int(x) for x in re.findall(r"\[(\d+)\]", m[2])]
n = 1
for d in dims: n *= d
# flatten the C initializer in order, padding short rows with NULL
def flatten(s, dims):
    if len(dims) == 1:
        L = re.findall(r'"((?:[^"\\]|\\.)*)"|\b(NULL|0)\b', s)
        L = [bytes(a, "latin1").decode("unicode_escape") if a or not b else None for a, b in L]
        return L + [None] * (dims[0] - len(L))
    parts = []; depth = 0; start = None; instr = False; esc = False
    for i, c in enumerate(s):
        if instr:
            if esc: esc = False
            elif c == "\\": esc = True
            elif c == '"': instr = False
            continue
        if c == '"': instr = True; continue
        if c == "{":
            depth += 1
            if depth == 1: start = i
        elif c == "}":
            if depth == 1: parts.append(s[start:i + 1])
            depth -= 1
    out = []
    for q in parts: out += flatten(q[1:-1], dims[1:])
    sub = 1
    for d in dims[1:]: sub *= d
    return out + [None] * (dims[0] * sub - len(out))
C = flatten(m[3].strip()[1:-1], dims)
def xs(v):
    if v == 0: return None
    return img.bytes_at(v, 80).split(b"\0")[0].decode("latin1")
blocks = []
for b in range(nb):
    X = [xs(struct.unpack("<I", img.bytes_at(addr + 4 * (b * n + k), 4))[0]) for k in range(n)]
    blocks.append(X)
    d = [(k, C[k], X[k]) for k in range(n) if C[k] != X[k]]
    print(f"block {b}: {len(d)} differ", *[f"\n  {k}: {c!r} -> {x!r}" for k, c, x in d[:20]])
if "--write" in sys.argv:
    flag = sys.argv[sys.argv.index("--write") + 1]
    def emit(X, dims, ind):
        if len(dims) == 1:
            items = ["NULL" if x is None else '"' + x.replace("\\", "\\\\").replace('"', '\\"') + '"' for x in X]
            while items and items[-1] == "NULL": items.pop()
            return "{ " + ", ".join(items) + " }"
        sub = len(X) // dims[0]
        return "{\n" + ",\n".join(ind + "    " + emit(X[i * sub:(i + 1) * sub], dims[1:], ind + "    ") for i in range(dims[0])) + "\n" + ind + "}"
    allx = [x for B in blocks for x in B]
    body = emit(allx, [nb] + dims, "")
    new = f"{m[1]}[{nb}]{m[2]} = {body};\n"
    t = t.replace(m[0], new)
    t = re.sub(r"\b" + re.escape(tab) + r"\[", f"{tab}[{flag}][", t.split(new, 1)[1] and t, count=0)
    # undo the replacement inside the definition itself
    t = t.replace(f"{m[1]}[{nb}]{m[2]}".replace(tab + "[", f"{tab}[{flag}]["), f"{m[1]}[{nb}]{m[2]}")
    open(p, "w").write(t)
    print("written")
