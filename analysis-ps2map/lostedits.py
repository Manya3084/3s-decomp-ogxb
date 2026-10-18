# lostedits.py Game/X.c... : after a regen, list what the HEAD version of
# each file had that the regenerated one does not: function bodies and data
# definitions that differ (beyond sub_ADDR renames and fold names), and
# header lines whose text is gone. Run it before committing a mass regen.
import sys, re, subprocess, json
sys.path.insert(0, __import__("os").path.dirname(__import__("os").path.abspath(__file__)))
from ps2paths import OG, SP
src = open(SP + "/portgen.py").read()
s = src.index("def items_of"); e = src.index("\n", src.index("    return out", s))
g = {"re": re}; exec(src[s:e], g)
xa = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*0x([0-9A-Fa-f]+);", l)
    if m: xa["sub_%08X" % int(m[2], 16)] = m[1]
FO = json.load(open(SP + "/folded.json"))
fold = {n: "sub_%08X" % int(a, 16) for a, ns in FO.items() for n in ns}
def norm(t):
    t = re.sub(r"/\*.*?\*/|//[^\n]*", "", t, flags=re.S)
    t = re.sub(r"#if defined\(TARGET_PS2\)\n.*?#endif\n?", "", t, flags=re.S)
    t = re.sub(r"\bsub_[0-9A-F]{8}\b", lambda m: xa.get(m[0], m[0]), t)
    t = re.sub(r"\b\w+\b", lambda m: xa.get(fold.get(m[0], ""), fold.get(m[0], m[0])) if m[0] in fold else m[0], t)
    return re.sub(r"\s+", " ", t).strip()
def key(k, t):
    if k == "func":
        m = re.search(r"\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*\{", re.sub(r"/\*.*?\*/|//[^\n]*", "", t, flags=re.S), re.S)
        return ("func", m[1]) if m else None
    if "=" in t:
        m = re.search(r"\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*=", t)
        return ("data", m[1]) if m else None
    return None
def items(body):
    out = {}
    for k, t in g["items_of"](body):
        kk = key(k, t)
        if kk: out.setdefault(kk, norm(t))
    return out
def hdrlines(h):
    flat = re.sub(r"\n \* ", " ", h)
    return [x.strip() for x in re.split(r"(?<=\.) (?=[A-Z_a-z][\w ]* (?:is|stays|has|0x)|Data:|Globals:|Unnamed|[A-Z])", flat) if x.strip()]
for rel in sys.argv[1:]:
    p = f"src/sf33rd/Source/{rel}"
    old = subprocess.run(["git", "-C", OG, "show", "HEAD:" + p], capture_output=True, text=True).stdout
    new = open(f"{OG}/{p}").read()
    oh, ob = old.split(" */", 1); nh, nb = new.split(" */", 1)
    io, inew = items(ob.split("\n#if 0\n/* PS2 C for functions not located")[0]), items(nb.split("\n#if 0\n/* PS2 C for functions not located")[0])
    for kk, t in io.items():
        if kk not in inew: print(rel, "GONE", *kk)
        elif inew[kk] != t: print(rel, "CHANGED", *kk)
    nflat = re.sub(r"\s+", " ", re.sub(r"\n \* ", " ", nh))
    for x in hdrlines(oh):
        xx = re.sub(r"\s+", " ", x)
        if re.match(r"^(Unnamed data used|Globals:|Data: .* bytes compared|Not located|\w+ (stays|has no|is folded))", xx): continue
        if xx not in nflat: print(rel, "HEADER", xx[:150])
