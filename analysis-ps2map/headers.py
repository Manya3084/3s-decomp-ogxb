# Bring PS2-copy placeholder headers up to date with funcs.txt: add each
# function the file defines that is now named, in address order, and drop
# the "not located yet" line when every definition is located or folded.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import os, re, json, collections
OG = _OG; PS = _PS
MARK = " * PlayStation 2 C, not hand-adjusted for Xbox."
ANCH = " * The other functions in this file are not located in sf33rd.xbe yet."
fn = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: fn[m[1]] = (int(m[2], 16), int(m[3], 16))
# a fold line is stale once folded.json drops the name or funcs.txt places it
FOLD_NOW = {n for v in json.load(open(OG + "/analysis-ps2map/folded.json")).values() for n in v}
FOLDLINE = re.compile(r"^ \* (\w+) is folded into 0x[0-9A-F]+.*$")
DEF = re.compile(r"^(?:static\s+)?[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*\{", re.M)
changed = 0; owned = set()
for r, _, fs in os.walk(OG + "/src"):
    for f in fs:
        p = os.path.join(r, f); t = open(p, errors="replace").read()
        if MARK not in t[:3000]: continue
        hdr, body = t.split(" */", 1)
        hdr = "\n".join(l for l in hdr.split("\n")
                        if not (FOLDLINE.match(l) and (FOLDLINE.match(l)[1] not in FOLD_NOW or FOLDLINE.match(l)[1] in fn)))
        defs = [m[1] for m in DEF.finditer(body) if m[1] not in ("if", "while", "for", "switch")]
        lines = hdr.split("\n")
        listed = set(re.findall(r"^ \* (\w+) 0x[0-9A-F]+ size", hdr, re.M)) | set(re.findall(r"^ \* (\w+) is folded into", hdr, re.M))
        owned |= set(defs)
        new = [n for n in defs if n in fn and n not in listed]
        if not new: 
            pass
        ent = []
        for l in lines:
            m = re.match(r"^ \* (\w+) 0x([0-9A-F]+) size 0x[0-9A-F]+\.$", l)
            if not m: continue
            if m[1] in fn: ent.append((fn[m[1]][0], f" * {m[1]} 0x{fn[m[1]][0]:X} size 0x{fn[m[1]][1]:X}."))
            # a name no longer in funcs.txt drops out
        ent += [(fn[n][0], f" * {n} 0x{fn[n][0]:X} size 0x{fn[n][1]:X}.") for n in new]
        ent.sort()
        rest = [l for l in lines if not re.match(r"^ \* (\w+) 0x([0-9A-F]+) size 0x[0-9A-F]+\.$", l)]
        # entries go where the first one was (after the #include note line)
        k = next(i for i, l in enumerate(rest) if l.startswith(" * The #include lines"))
        out = rest[:k + 1] + [l for _, l in ent] + rest[k + 1:]
        missing = [n for n in defs if n not in fn and n not in listed]
        if not missing and ANCH in out: out.remove(ANCH)
        if missing and ANCH not in out: out.append(ANCH)
        nh = "\n".join(out)
        if nh != hdr:
            open(p, "w").write(nh + " */" + body); changed += 1
print("headers changed", changed)
