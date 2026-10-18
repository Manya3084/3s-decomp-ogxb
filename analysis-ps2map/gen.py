# Write src files, funcs.txt rows, and matched_bytes entries for proposals in
# the PS2 Game files the Xbox tree lacks. Usage: gen.py PATTERN (regex on file name)
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import sys, re, json, os, pathlib, collections
OG = _OG; PS = _PS
S = (_SP + "/")
sys.path.insert(0, OG + "/tools")
from ogxb.xbe import load
from ogxb.cap import Disassembler
img = load(pathlib.Path(open(OG + "/xbe.path").read().strip()))
pat = re.compile(sys.argv[1])
J = json.load(open(S + "xprop2.json")); P = J["prop"]; pf = J["pfile"]
xbfiles = {os.path.relpath(os.path.join(r_, f_), OG + "/src").lower() for r_, _, fs_ in os.walk(OG + "/src") for f_ in fs_}

funcs_p = OG + "/config/sf33rd/symbols/funcs.txt"
rows = open(funcs_p).read().splitlines()
taken = []
for l in rows:
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: taken.append((int(m[2], 16), int(m[2], 16) + int(m[3], 16), m[1]))
names_taken = {n for _, _, n in taken}

MARK = " * PlayStation 2 C, not hand-adjusted for Xbox."
def ours(b):
    p_ = f"{OG}/src/{b}"
    return os.path.exists(p_) and MARK in open(p_).read(2000)
_src = {}
def stub(b, n):
    """True when the PS2 C for n is only an INCLUDE_ASM / not_implemented stub."""
    if b not in _src: _src[b] = open(f"{PS}/src/anniversary/{b}", errors="replace").read()
    t = _src[b]
    if not re.search(r"INCLUDE_ASM\([^)]*,\s*" + re.escape(n) + r"\s*\)", t): return False
    m = re.search(r"^[A-Za-z_][\w\s\*]*\b" + re.escape(n) + r"\s*\([^;{]*\)\s*\{", t, re.M)
    if not m: return True
    depth = 0; i = m.end() - 1
    for j in range(i, len(t)):
        if t[j] == "{": depth += 1
        elif t[j] == "}":
            depth -= 1
            if depth == 0: return "not_implemented" in t[i:j]
    return True
FOLDED = {int(k, 16) for k in json.load(open(S + "folded.json"))} if os.path.exists(S + "folded.json") else set()
DENY = {(int(a, 16), n) for a, n in json.load(open(S + "deny.json"))} if os.path.exists(S + "deny.json") else set()
byfile = collections.defaultdict(list)
for k, (n, why, sz) in P.items():
    b = pf.get(n, "")
    if not b: continue
    # PS2 platform layers: the XBE has its own implementations with other C
    if re.search(r"(^|/)ps2_[^/]*\.c$|AcrSDK/ps2/|AcrSDK/MiddleWare/PS2|Source/PS2/", b): continue
    if stub(b, n): continue
    if b.lower() in xbfiles and not ours(b): continue
    if not pat.search(b) or n in names_taken: continue
    va = int(k, 16)
    if va in FOLDED or (va, n) in DENY: continue
    if any(a < va + sz and va < e for a, e, _ in taken): continue
    byfile[b].append((va, sz, n, why))

dis = Disassembler()
def imms(va, size):
    out = []; blob = img.bytes_at(va, size)
    for ins in dis.disasm(blob, va):
        if ins.mnemonic == "call" or ins.mnemonic.startswith("j"): continue
        for h in re.findall(r"0x[0-9a-f]+", ins.op_str):
            v = int(h, 16)
            if 0x11000 <= v < 0xD20000 and v.to_bytes(4, "little") in blob and v not in out: out.append(v)
    return tuple(out)

new_rows = []; new_matched = []; written = []
for b in sorted(byfile):
    items = sorted(byfile[b])
    dst = f"{OG}/src/{b}"
    if ours(b):
        t = open(dst).read()
        anchor = " * The other functions in this file are not located in sf33rd.xbe yet.\n"
        assert anchor in t
        hl, rest = t.split(anchor, 1)
        lines = hl.split("\n")
        ent = [l for l in lines if re.match(r" \* \w+ 0x[0-9A-F]+ size 0x[0-9A-F]+\.$", l)]
        head = [l for l in lines if l not in ent and l != ""]
        for va, sz, n, why in items: ent.append(f" * {n} 0x{va:X} size 0x{sz:X}.")
        ent = list(dict.fromkeys(ent))
        ent.sort(key=lambda l: int(re.search(r"0x([0-9A-F]+) size", l)[1], 16))
        open(dst, "w").write("\n".join(head + ent) + "\n" + anchor + rest)
        written.append(b)
        for va, sz, n, why in items:
            new_rows.append(f"{n} = 0x{va:08X}; // type:func size:0x{sz:X}")
            new_matched.append(f'    ("{n}", 0x{va:08X}, 0x{sz:X}, ({"".join(f"0x{x:X}," for x in imms(va, sz))}),\n     "{img.bytes_at(va, sz).hex()}"),')
        continue
    src = open(f"{PS}/src/anniversary/{b}", errors="replace").read()
    hdr = [f"/* {os.path.basename(b)}, retail sf33rd.xbe.",
           " * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located",
           " * from the PS2 retail map: call graph, source order, and agreement of",
           " * constants, field offsets, callees, and size. See docs/decompiling.md.",
           " * The #include lines name headers in the PS2 tree (ps2.path)."]
    for va, sz, n, why in items:
        hdr.append(f" * {n} 0x{va:X} size 0x{sz:X}.")
    hdr.append(" * The other functions in this file are not located in sf33rd.xbe yet.")
    hdr.append(" */")
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    open(dst, "w").write("\n".join(hdr) + "\n\n" + src)
    written.append(b)
    for va, sz, n, why in items:
        new_rows.append(f"{n} = 0x{va:08X}; // type:func size:0x{sz:X}")
        blob = img.bytes_at(va, sz).hex()
        im = imms(va, sz)
        new_matched.append(f'    ("{n}", 0x{va:08X}, 0x{sz:X}, ({"".join(f"0x{x:X}," for x in im)}),\n     "{blob}"),')
if not new_rows: print("nothing"); sys.exit()
open(funcs_p, "w").write("\n".join(rows + new_rows) + "\n")
mb = OG + "/tests/matched_bytes.py"; t = open(mb).read().rstrip()
assert t.endswith(")")
t = t[:-1].rstrip() + "\n" + "\n".join(new_matched) + "\n)\n"
open(mb, "w").write(t)
print(len(new_rows), "names in", len(written), "files")
json.dump({"files": written, "count": len(new_rows),
           "why": collections.Counter(w for v in byfile.values() for *_, w in v)}, open(S + "genlast.json", "w"))
