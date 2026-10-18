# freeze.py Game/X.c NAME... : copy functions or data definitions NAME from
# the HEAD version of a ported file into overrides/X.c, with HEAD's
# declarations of the sub_/D_ symbols they use, so that a regen keeps them.
import sys, re, os, subprocess
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ps2paths import OG, SP
rel, wanted = sys.argv[1], sys.argv[2:]
old = subprocess.run(["git", "-C", OG, "show", "HEAD:src/sf33rd/Source/" + rel], capture_output=True, text=True).stdout
body = old.split(" */", 1)[1].split("\n#if 0\n/* PS2 C for functions not located")[0]
src = open(SP + "/portgen.py").read()
s = src.index("def items_of"); e = src.index("\n", src.index("    return out", s))
g = {"re": re}; exec(src[s:e], g)
items = g["items_of"](body)
op = f"{SP}/overrides/{os.path.basename(rel)}"
have = open(op).read() if os.path.exists(op) else ""
out = []
for w in wanted:
    hit = None
    for k, t in items:
        c = re.sub(r"/\*.*?\*/|//[^\n]*", "", t, flags=re.S)
        if k == "func" and re.search(r"\b" + re.escape(w) + r"\s*\([^;{]*\)\s*\{", c): hit = t; break
        if k != "func" and "=" in c and re.search(r"\b" + re.escape(w) + r"\s*(?:\[[^\]]*\]\s*)*=", c): hit = t; break
    assert hit, (rel, w)
    out.append(hit.strip("\n"))
text = "\n\n".join(out)
syms = sorted(set(re.findall(r"\b(?:sub|D)_[0-9A-F]{8}\b", text)))
decls = []
for sy in syms:
    if re.search(r"\b" + sy + r"\b[^;{]*;", have): continue
    m = re.search(r"^[^\n#]*\b" + sy + r"\b[^\n{]*;$", body, re.M)
    if m and not m[0].lstrip().startswith(("return", "if", "}")) and "=" not in m[0].split(sy)[0][-3:]:
        decls.append(m[0].strip())
block = ("\n".join(decls) + "\n\n" if decls else "") + text
open(op, "a").write(("\n" if have else "") + block + "\n")
print(rel, "froze", ", ".join(wanted), "| decls:", len(decls))
