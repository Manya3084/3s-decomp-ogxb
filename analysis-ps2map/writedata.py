# Write config/sf33rd/symbols/data.txt from hand notes and datamap.json.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG as _OG, SP as _SP, PS as _PS
import json, re, os, sys, pathlib, collections
OG = _OG
sys.path.insert(0, OG + "/tools")
from ogxb.xbe import load
from ogxb.cap import Disassembler
sys.path.insert(0, OG + "/analysis-ps2map")
import notefix
img = load(pathlib.Path(open(OG + "/xbe.path").read().strip()))
M = {k: (int(v[0], 16), v[1]) for k, v in json.load(open(OG + "/analysis-ps2map/datamap.json")).items()}
funcs = {}
for l in open(OG + "/config/sf33rd/symbols/funcs.txt"):
    m = re.match(r"(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: funcs[m[1]] = (int(m[2], 16), int(m[3], 16))
PSDATA = set()
for l in open((_PS + "/config/anniversary/symbols/syms_sfiii.txt")):
    m_ = re.match(r"(\S+) = (0x[0-9A-Fa-f]+);\s*//(.*)", l)
    if m_ and "type:func" not in m_[3]: PSDATA.add(m_[1])
# names the C declares extern (a table only this tree knows by that name)
CDECL = set()
for r_, _, fs_ in os.walk(OG + "/src"):
    for f_ in fs_:
        if f_.endswith(".c"):
            for m_ in re.finditer(r"^extern\s[^;()]*?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*;", open(os.path.join(r_, f_), errors="replace").read(), re.M):
                CDECL.add(m_[1])
# but not a name the relink already places from its uses (a static of the
# same name elsewhere, like staff.c's name_ptr, keeps its own notes)
if os.path.exists(OG + "/analysis-ps2map/relinkdata.json"):
    CDECL -= set(json.load(open(OG + "/analysis-ps2map/relinkdata.json")))
notes = {}
NOTE = re.compile(r"(?<![\w.\]>])([A-Za-z_]\w*) is (?:the (?:word|dword|byte|float|table) at )?(0x[0-9A-F]{5,})\b")
# notes in src/ and in the overrides (a hand port turned into a generated
# one keeps its notes there, analysis-ps2map/handconv.py)
for r, _, fs in list(os.walk(OG + "/src")) + [(OG + "/analysis-ps2map/overrides", None, os.listdir(OG + "/analysis-ps2map/overrides"))]:
    for f in sorted(fs):
        s = notefix.fix(open(os.path.join(r, f), errors="replace").read(30000))
        if "not hand-adjusted" in s[:3000]: continue
        for m in NOTE.finditer(s):
            a = int(m[2], 16)
            if a >= 0x218DC0 and a < 0xD20000 and m[1] not in funcs and (m[1] in PSDATA or m[1] in M or m[1] in CDECL): notes.setdefault(m[1], a)
dsize = {}
for l in open((_PS + "/config/anniversary/symbols/syms_sfiii.txt")):
    m = re.match(r"(\S+) = (0x[0-9A-Fa-f]+);\s*//.*size:(0x[0-9A-Fa-f]+)", l)
    if m: dsize[m[1]] = int(m[3], 16)
# references of each address in named bodies: indexed or plain
refkind = collections.defaultdict(set)
with Disassembler() as dis:
    for n, (va, sz) in funcs.items():
        for i in dis.disasm(img.bytes_at(va, sz), va):
            for m in re.finditer(r"\[([^\]]*)\]", i.op_str):
                inner = m[1]
                for h in re.findall(r"0x[0-9a-f]{5,}", inner):
                    v = int(h, 16)
                    refkind[v].add("idx" if re.search(r"e\w\w", inner) else "abs")
            for h in re.findall(r"(?<![\[+ ])0x[0-9a-f]{5,}", i.op_str):
                refkind[int(h, 16)].add("imm")
structs = [(a, dsize.get(n, 0)) for n, a in notes.items() if dsize.get(n, 0) >= 0x40]
structs += [(a, sz) for n, (a, sz) in M.items() if sz >= 0x40]
def below_struct(a):
    return any(b - 0x400 <= a < b for b, sz in structs)
handaddr = set(notes.values())
rows = [(a, n, dsize.get(n), "hand") for n, a in notes.items()]
drop = collections.Counter()
DENYD = set(open(OG + "/analysis-ps2map/denydata.txt").read().split()) if os.path.exists(OG + "/analysis-ps2map/denydata.txt") else set()
for n, (a, sz) in M.items():
    if n in notes or n in DENYD: continue
    if a in handaddr: drop["hand-address"] += 1; continue
    if re.match(r"^(literal_|D_|jtbl_)", n) or re.search(r"_[0-9A-Fa-f]{6,8}$", n): drop["placeholder"] += 1; continue
    if sz >= 2 and a % 2: drop["misaligned"] += 1; continue
    pass
    rows.append((a, n, sz, "map"))
# "relink" rows: bases read off the retail code by tools/objdiff.py for
# globals the matching C uses (analysis-ps2map/relinkdata.py)
RL = OG + "/analysis-ps2map/relinkdata.json"
named = {n for _, n, _, _ in rows}
taken = {a: n for a, n, _, _ in rows}
RLJ = json.load(open(RL)) if os.path.exists(RL) else {}
REBASE = {n: int(a, 16) for n, a in RLJ.pop("rebase", {}).items()}
for n, a in RLJ.items():
    a = int(a, 16)
    if n in named or n in funcs: continue
    if not 0x218DC0 <= a < 0xD20000: drop["relink-code-address"] += 1; continue  # a function: a fold candidate
    if a in taken: drop["relink-address-taken"] += 1; print("relink: address", hex(a), "is", taken[a], "not", n); continue
    rows.append((a, n, dsize.get(n), "relink")); taken[a] = n
# rebases: rows whose address byte-matching code contradicts (relinkdata.py)
for i, (a, n, sz, src) in enumerate(rows):
    if n in REBASE and REBASE[n] != a:
        rows[i] = (REBASE[n], n, sz, src + " relink-rebase")
rows.sort()
hdr = open(OG + "/config/sf33rd/symbols/data.txt").read().split("\n\n")[0] if os.path.exists(OG + "/config/sf33rd/symbols/data.txt") else ""
hdr = "\n".join(l for l in open(OG + "/config/sf33rd/symbols/data.txt").read().splitlines() if l.startswith("//"))
with open(OG + "/config/sf33rd/symbols/data.txt", "w") as f:
    f.write(hdr + "\n")
    for a, n, sz, src in rows:
        f.write(f"{n} = 0x{a:08X}; // type:data" + (f" size:0x{sz:X}" if sz else "") + f" {src}\n")
print("rows", len(rows), "hand", len(notes), "map", sum(1 for r in rows if r[3] == "map"), "relink", sum(1 for r in rows if r[3] == "relink"), dict(drop))
