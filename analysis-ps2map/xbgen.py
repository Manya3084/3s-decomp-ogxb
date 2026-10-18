# xbgen.py [--apply] : C for the smallest Xbox-only functions.
#
# Capcom's Xbox-only code has no PS2 C. Its smallest functions follow a few
# shapes: a C++ accessor (`mov eax, [ecx + 0x50]; ret`), the address of a
# member, a constant, a global read, a member store, and a jump to another
# function. This reads each named function that has no C yet, matches its
# instructions against those shapes, and writes the C for the ones it
# recognises. A C++ method receives `this` in ecx and pops its stack
# arguments, which is what __fastcall does with the first parameter, so a
# method is written __fastcall, with an unused second (edx) parameter in
# front of any stack arguments.
#
# The candidates go into src/sf33rd/Source/XBOX/xb_gen_check.c, the tree is
# built and checked, and only the functions that match retail are kept.
# With --apply they are written into files named after the run of no-C
# functions they sit in (src/sf33rd/Source/XBOX/xb_XXXXXX.c, by the run's
# first address), each with a header saying so.
import sys as _sys
_here = _sys.path.pop(0)  # analysis-ps2map/queue.py would shadow the standard queue
from concurrent.futures import ThreadPoolExecutor  # noqa: F401
_sys.path.insert(0, _here)
import os as _os
_sys.path.insert(0, _os.path.join(_here, "..", "tools"))
from ps2paths import OG
import json, os, re, struct, subprocess, sys
from pathlib import Path

ROOT = Path(OG)
sys.path.insert(0, str(ROOT / "tools"))
import asmdiff
from ogxb.xbe import load
from ogxb.paths import find_xbe
from ogxb.cap import Disassembler

XB = ROOT / "src" / "sf33rd" / "Source" / "XBOX"
CHECK = XB / "xb_gen_check.c"
CRI_START = 0x165000  # CRI's libraries start here; their statics go in src/cri

R = json.load(open(ROOT / "build" / "objdiff.json"))
have = {f["name"] for r in R.values() for f in r["functions"]}
# run boundaries come from the ported code only, so a file's name does not
# change as Xbox-only C is added
ported = {f["name"] for o, r in R.items() if not o.startswith("sf33rd/Source/XBOX/") for f in r["functions"]}
funcs = []
for l in open(ROOT / "config" / "sf33rd" / "symbols" / "funcs.txt"):
    m = re.match(r"(\S+) = 0x([0-9A-F]+);.*size:0x([0-9A-F]+)", l)
    if m:
        funcs.append((int(m[2], 16), int(m[3], 16), m[1]))
funcs.sort()
data = {}
for l in open(ROOT / "config" / "sf33rd" / "symbols" / "data.txt"):
    m = re.match(r"(\S+) = 0x([0-9A-F]+);.*size:0x([0-9A-F]+)", l)
    if m:
        data[int(m[2], 16)] = (m[1], int(m[3], 16))
names = asmdiff.names_by_addr()
xdk = {}
for l in open(ROOT / "config" / "sf33rd" / "symbols" / "xdk.txt"):
    m = re.match(r"(\S+) = 0x([0-9A-F]+);.*conv:(\w+)", l)
    if m:
        xdk[int(m[2], 16)] = (m[1], m[3])
img = load(find_xbe())

# runs of consecutive no-C functions, for the file names
run_of, cur = {}, None
for a, s, n in funcs:
    if n in ported:
        cur = None
    else:
        cur = cur if cur is not None else a
        run_of[n] = cur

# Capcom's source paths: the _assert strings name each file, and the code
# that pushes a path places that file
def modules():
    import bisect, collections
    starts = [a for a, _, _ in funcs]

    def func_at(a):
        i = bisect.bisect_right(starts, a) - 1
        return funcs[i][0] if i >= 0 and funcs[i][0] <= a < funcs[i][0] + funcs[i][1] else None
    sec = {s.name: s for s in img.sections}
    strs = {}
    for nm in (".rdata", ".data"):
        s = sec[nm]
        b = img.bytes_at(s.va, min(s.raw_size, s.virtual_size))
        for m in re.finditer(rb"[A-Za-z0-9_:\\. \-]{3,240}\.(?:cpp|c)\x00", b):
            path = m.group(0)[:-1].decode()
            if "sf33rd" in path:
                strs[s.va + m.start()] = path[path.find("sf33rd"):].replace("\\", "/")
    s = sec[".text"]
    b = img.bytes_at(s.va, min(s.raw_size, s.virtual_size))
    refs = collections.defaultdict(list)
    for i in range(len(b) - 4):
        v = struct.unpack_from("<I", b, i)[0]
        if v in strs:
            f = func_at(s.va + i)
            if f is not None:
                refs[strs[v]].append(f)
    return {k: (min(v), max(v)) for k, v in refs.items()}


MODULES = modules()
# copies of XDK sample code: not written out here (see docs/decompiling.md)
SAMPLE = ("_xbOnlineTask", "_xbsocket", "_xbutil", "_xbSockAddr", "XHVVoiceManager")


def module_of(a):
    best = None
    for path, (lo, hi) in MODULES.items():
        if lo <= a <= hi and (best is None or hi - lo < best[1] - best[0]):
            best = (lo, hi, path)
    return best[2] if best else None


INT = {"byte": ("u8", "s8"), "word": ("u16", "s16"), "dword": ("s32", "s32")}


PROTOS = {}
for _p in (ROOT / "src").rglob("*.c"):
    if _p.name == "xb_gen_check.c":
        continue
    _t = re.sub(r"^#if 0\b.*?^#endif\b", "", _p.read_text(errors="replace"), flags=re.M | re.S)
    for _m in re.finditer(r"^((?:static\s+)?[A-Za-z_][\w \*]*?)\b(\w+)\s*\(([^;{}()]*)\)\s*\{", _t, re.M):
        PROTOS.setdefault(_m.group(2), (_m.group(1).strip(), _m.group(3).strip()))


def gname(v):
    """a data name for address v, and its offset"""
    if v in data:
        return data[v][0], 0
    for a in range(v - 1, v - 0x40, -1):
        if a in data and a + data[a][1] > v:
            return data[a][0], v - a
    return f"D_{v:08X}", 0


def fname(v):
    return names.get(v) or f"sub_{v:08X}"


def ret_count(va):
    """bytes a function pops on return (ret N), from its first ret"""
    try:
        code = img.bytes_at(va, 0x400)
    except Exception:
        return None
    with Disassembler() as d:
        for ins in d.disasm(code, va):
            if ins.mnemonic == "ret":
                return int(ins.op_str, 16) if ins.op_str else 0
            if ins.mnemonic in ("jmp",) and ins.op_str.startswith("0x"):
                return None
    return None


def gen(name, lines):
    """(decls, C) for a body, or None"""
    L = [re.sub(r"\s+", " ", l.strip()) for l in lines]
    while L and L[-1] in ("int3", "nop"):
        L.pop()
    if not L:
        return None
    retn = 0
    m = re.match(r"ret(?: (0x[0-9a-f]+|\d+))?$", L[-1])
    if m:
        retn = int(m.group(1), 0) if m.group(1) else 0
    stack = [f"s32 a{i}" for i in range(retn // 4)]
    meth = lambda self_t: f"XB_FASTCALL {name}({self_t} self" + (", s32 edx, " + ", ".join(stack) if stack else "") + ")"
    unused = "".join(f"    (void){p.split()[1]};\n" for p in (["s32 edx"] + stack if stack else []))
    body = L[:-1] if m else L
    # constants
    if body == ["xor al, al"]:
        return [], f"u8 {name}(void) {{\n    return 0;\n}}" if not stack else None
    if body == ["xor eax, eax"] and not stack:
        return [], f"s32 {name}(void) {{\n    return 0;\n}}"
    if body == ["xor eax, eax"]:
        return [], f"s32 {meth('void*')} {{\n    (void)self;\n{unused}    return 0;\n}}"
    mm = re.match(r"^(?:mov eax, (0x[0-9a-f]+|\d+)|push (-?0x[0-9a-f]+|-?\d+))$", body[0]) if len(body) in (1, 2) else None
    if mm and (len(body) == 1 and mm.group(1) or len(body) == 2 and mm.group(2) and body[1] == "pop eax") and not stack:
        v = int(mm.group(1) or mm.group(2), 0)
        if 0x218000 <= v < 0xE00000 and mm.group(1):
            g, off = gname(v)
            decl = f"extern u8 {g}[];"
            return [decl], f"void* {name}(void) {{\n    return {g}" + (f" + 0x{off:X}" if off else "") + ";\n}"
        return [], f"s32 {name}(void) {{\n    return 0x{v:X};\n}}"
    if not body:
        if stack:
            return [], f"void {meth('void*')} {{\n    (void)self;\n{unused}}}"
        return [], f"void {name}(void) {{\n}}"
    if len(body) == 1:
        b = body[0]
        if b == "mov eax, ecx":
            return [], f"void* {meth('void*')} {{\n{unused}    return self;\n}}"
        mm = re.match(r"^(mov|movzx|movsx) (eax|al|ax), (byte|word|dword) ptr \[ecx(?: \+ (0x[0-9a-f]+|\d+))?\]$", b)
        if mm:
            op, reg, w = mm.group(1), mm.group(2), mm.group(3)
            off = int(mm.group(4), 0) if mm.group(4) else 0
            t = INT[w][1 if op == "movsx" else 0] if w != "dword" else "s32"
            if (reg, w) not in (("al", "byte"), ("ax", "word"), ("eax", "dword"), ("eax", "byte"), ("eax", "word")):
                return None
            rt = t if op != "mov" or w == "dword" else t
            return [], f"{rt} {meth('u8*')} {{\n{unused}    return *({t}*)(self + 0x{off:X});\n}}"
        mm = re.match(r"^lea eax, \[ecx \+ (0x[0-9a-f]+|\d+)\]$", b)
        if mm:
            return [], f"u8* {meth('u8*')} {{\n{unused}    return self + 0x{int(mm.group(1), 0):X};\n}}"
        mm = re.match(r"^(mov|movzx|movsx) (eax|al|ax), (byte|word|dword) ptr \[(0x[0-9a-f]+)\]$", b)
        if mm and not stack:
            op, reg, w, v = mm.group(1), mm.group(2), mm.group(3), int(mm.group(4), 16)
            t = INT[w][1 if op == "movsx" else 0] if w != "dword" else "s32"
            g, off = gname(v)
            if off:
                return None
            return [f"extern {t} {g};"], f"{'s32' if op != 'mov' else t} {name}(void) {{\n    return {g};\n}}"
        mm = re.match(r"^mov (byte|word|dword) ptr \[ecx(?: \+ (0x[0-9a-f]+|\d+))?\], (0x[0-9a-f]+|\d+)$", b)
        if mm:
            t = INT[mm.group(1)][0]
            off = int(mm.group(2), 0) if mm.group(2) else 0
            return [], f"void {meth('u8*')} {{\n{unused}    *({t}*)(self + 0x{off:X}) = 0x{int(mm.group(3), 0):X};\n}}"
    # a jump to another function
    if len(L) == 1:
        mm = re.match(r"^jmp (0x[0-9a-f]+|\w+)$", L[0])
        if mm:
            tgt = int(mm.group(1), 16) if mm.group(1).startswith("0x") else next((a for a, n in names.items() if n == mm.group(1)), None)
            if tgt is None:
                return None
            tn = fname(tgt)
            if tn in PROTOS:
                # forward to a function that has C, with its own prototype
                rt, params = PROTOS[tn]
                rt = re.sub(r"^static\s+", "", rt)
                ps = [] if params in ("", "void") else [x.strip() for x in params.split(",")]
                pn = [re.search(r"(\w+)\s*$", x).group(1) for x in ps]
                conv = "XB_FASTCALL " if re.search(r"__fastcall|XB_FASTCALL", rt) else "XB_STDCALL " if re.search(r"__stdcall|XB_STDCALL", rt) else ""
                base = re.sub(r"\b(__fastcall|__stdcall|XB_STDCALL|XB_FASTCALL)\b\s*", "", rt).strip()
                sig = ", ".join(ps) or "void"
                ret = "" if base == "void" else "return "
                return ([f"{base} {conv}{tn}({sig});"],
                        f"{base} {conv}{name}({sig}) {{\n    {ret}{tn}({', '.join(pn)});\n}}", tn)
            n_ = ret_count(tgt)
            if n_ is None:
                return None
            args = [f"s32 a{i}" for i in range(n_ // 4)]
            conv = xdk.get(tgt, (None, "cdecl"))[1]
            if n_ and conv != "stdcall":
                conv = "stdcall"
            cc = "XB_STDCALL " if n_ else ""
            sig = ", ".join(args) or "void"
            call = ", ".join(a.split()[1] for a in args)
            # the result, if any, stays in eax: the thunk is void
            return ([f"void {cc}{tn}({sig});"],
                    f"void {cc}{name}({sig}) {{\n    {tn}({call});\n}}", tn)
    return None


def main():
    cands = []
    with Disassembler() as d:
        for a, s, n in funcs:
            if n in have or a >= CRI_START or s > 0x20 or n.startswith(("CXB", "CXHV")):
                continue
            mod = module_of(a)
            if mod and any(x in mod for x in SAMPLE):
                continue
            try:
                lines = asmdiff.lines_for(d, img.bytes_at(a, s), a, {}, {})
            except Exception:
                continue
            g = gen(n, lines)
            if g:
                cands.append((a, n, g))
    # a thunk whose target is written here too would declare it twice
    made = {n for _, n, _ in cands}
    cands = [(a, n, g[:2]) for a, n, g in cands if len(g) < 3 or g[2] not in made]
    print(f"{len(cands)} candidates", flush=True)
    decls = sorted({x for _, _, (ds, _) in cands for x in ds})
    CHECK.write_text("/* xbgen.py check build; not committed. */\n\n#include \"types.h\"\n\n" + "\n".join(decls) + "\n\n" +
                     "\n\n".join(c for _, _, (_, c) in cands) + "\n")
    r = subprocess.run(["python3", str(ROOT / "tools" / "build_c.py"), "-j", "24", str(CHECK)], cwd=ROOT, capture_output=True, text=True)
    print("\n".join(l for l in r.stdout.strip().splitlines() if l.startswith(("FAIL", "compiled"))) or r.stderr[-2000:])
    subprocess.run(["python3", str(ROOT / "tools" / "objdiff.py")], cwd=ROOT, capture_output=True)
    res = json.load(open(ROOT / "build" / "objdiff.json")).get("sf33rd/Source/XBOX/xb_gen_check.obj", {})
    st = {f["name"]: f["status"] for f in res.get("functions", [])}
    keep = [(a, n, g) for a, n, g in cands if st.get(n) == "match"]
    print(f"{len(keep)} match, {sum(1 for v in st.values() if v == 'reloc')} reloc, {sum(1 for v in st.values() if v == 'diff')} diff")
    for a, n, g in cands:
        if st.get(n) != "match":
            print("  not kept:", n, st.get(n))
    CHECK.unlink()
    (ROOT / "build" / "obj" / "sf33rd" / "Source" / "XBOX" / "xb_gen_check.obj").unlink(missing_ok=True)
    subprocess.run(["python3", str(ROOT / "tools" / "build_c.py"), "-j", "24"], cwd=ROOT, capture_output=True)
    subprocess.run(["python3", str(ROOT / "tools" / "objdiff.py")], cwd=ROOT, capture_output=True)
    if "--apply" in sys.argv and keep:
        by = {}
        for a, n, g in keep:
            mod = module_of(a)
            key = (ROOT / "src" / mod).with_suffix(".c") if mod and "/XBOX/" in mod else XB / f"xb_{run_of[n]:06X}.c"
            by.setdefault(key, []).append((a, n, g))
        for p, items in sorted(by.items()):
            start = items[0][0]
            p.parent.mkdir(parents=True, exist_ok=True)
            old = p.read_text() if p.is_file() else None
            ds = sorted({x for _, _, (dd, _) in items for x in dd})
            bodies = [c for _, _, (_, c) in sorted(items)]
            if old is None:
                orig = next((m for m in MODULES if (ROOT / "src" / m).with_suffix(".c") == p), None)
                what = (f"Capcom's {orig.split('/')[-1]} (its _assert path names it and places\n"
                        f" * it at 0x{MODULES[orig][0]:X} to 0x{MODULES[orig][1]:X})") if orig else \
                       f"the run of Xbox-only functions at 0x{start:X}, which no PS2 file covers"
                head = (f"/* {p.name}: Xbox-only code from {what}.\n"
                        " * Capcom's source is lost. The C++ methods are written as C,\n"
                        " * XB_FASTCALL (__fastcall) with this first (analysis-ps2map/xbgen.py wrote\n"
                        " * these from their shapes). The names are made up (xb_). */\n\n"
                        "#include \"types.h\"\n\n")
                p.write_text(head + "\n".join(ds) + ("\n\n" if ds else "") + "\n\n".join(bodies) + "\n")
            else:
                add_d = [x for x in ds if x not in old]
                add_b = [b for b in bodies if b.split("(")[0] not in old]
                text = old
                if add_d:
                    text = text.replace("#include \"types.h\"\n\n", "#include \"types.h\"\n\n" + "\n".join(add_d) + "\n", 1)
                p.write_text(text.rstrip("\n") + "\n\n" + "\n\n".join(add_b) + "\n")
        print("written", len(by), "files")


main()
