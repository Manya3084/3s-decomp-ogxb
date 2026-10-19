# xbgen.py [--apply] [--from FILE] : C for the smallest Xbox-only functions.
#
# --from FILE takes hand-written definitions instead (with the declarations
# they need), checks them the same way, and files the ones that match.
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
R.pop("sf33rd/Source/XBOX/xb_gen_check.obj", None)  # a check build left by --keep
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
# a run between two functions of one ported object is that object's code:
# its functions go into the object's own source (the override of a
# generated port), not a file of their own. So does xb_X_draw just before
# X_move (the Xbox effect draw functions, called through the table at
# 0x25B2C0 by xb_draw_effect_work).
objof = {f["name"]: o for o, r in R.items() if not o.startswith("sf33rd/Source/XBOX/") for f in r["functions"]}
host_of = {}
_prev = None
_pending = []
for a, s, n in funcs:
    if n in ported:
        o = objof.get(n)
        for m in _pending:
            if _prev is not None and o == _prev:
                host_of[m] = o
            elif re.fullmatch(r"xb_(\w+)_draw", m) and n == re.fullmatch(r"xb_(\w+)_draw", m)[1] + "_move":
                # an effect's Xbox draw function comes just before its move
                # function, in the move's object
                host_of[m] = o
        _pending, _prev = [], o
    else:
        _pending.append(n)

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
                name = path[path.find("sf33rd"):].replace("\\", "/")
                # a path can follow other text with no break between them:
                # the pushed address is where the path itself starts
                for k, ch in enumerate(path):
                    if ch == "\\" and k < path.find("sf33rd"):
                        strs[s.va + m.start() + k] = name
                strs[s.va + m.start()] = name
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


def decl_name(d):
    fp = re.search(r"\(\s*(?:XB_STDCALL\s+|XB_FASTCALL\s+|__stdcall\s+|__fastcall\s+)?\*\s*(\w+)\s*\)\s*\(", d)
    if fp:
        return fp.group(1)  # a function pointer: extern void (*name)(void);
    if d.startswith("typedef"):
        m = re.search(r"(\w+)\s*;\s*$", d)
        return m.group(1) if m else None
    m = re.search(r"\b(\w+)\s*\(", d) or re.search(r"\b(\w+)\s*(?:\[[^\]]*\]\s*)*;", d)
    return m.group(1) if m else None


def typedefs_of(text):
    """top-level typedefs, braces and all"""
    out = []
    for m in re.finditer(r"^typedef\b", text, re.M):
        j, d = m.start(), 0
        while j < len(text):
            if text[j] == "{":
                d += 1
            elif text[j] == "}":
                d -= 1
            elif text[j] == ";" and d == 0:
                break
            j += 1
        out.append(text[m.start():j + 1])
    return out


def ds_of(text):
    live = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    tds = typedefs_of(live)
    for td in tds:
        live = live.replace(td, "")
    # every brace level, however deep the bodies nest
    while True:
        stripped = re.sub(r"\{[^{}]*\}", "", live)
        if stripped == live:
            break
        live = stripped
    return tds + [l.strip() for l in live.splitlines() if l.strip().endswith(";") and not l.strip().startswith("return")]


def from_file(path):
    """hand-written candidates: the declarations and definitions in a file"""
    return from_file_text(open(path).read())


def from_file_text(text, keep_all=False):
    out, decls, i = [], [], 0
    addr = {n: a for a, _, n in funcs}
    for m in re.finditer(r"^([A-Za-z_][^;{}()\n]*?\b(\w+)\s*\([^;{}]*\))\s*\{", text, re.M):
        if m.start() < i:
            continue
        d, j = 0, m.end() - 1
        while j < len(text):
            if text[j] == "{":
                d += 1
            elif text[j] == "}":
                d -= 1
                if d == 0:
                    break
            j += 1
        n = m.group(2)
        # the comment right above a definition goes with it
        c0 = m.start()
        before = text[:c0].rstrip()
        if before.endswith("*/"):
            k = before.rfind("/*")
            if k >= 0 and k >= i:
                c0 = k
        if n in addr and (keep_all or n not in have):
            out.append((addr[n], n, ([], text[c0:j + 1].strip())))
        i = j + 1
    live = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    body_free = re.sub(r"\{[^{}]*\}", "", re.sub(r"\{[^{}]*\}", "", re.sub(r"\{[^{}]*\}", "", live)))
    decls = ds_of(text)

    ident = decl_name

    def named(s):
        # a D_ placeholder for an address data.txt names takes that name
        return re.sub(r"\bD_([0-9A-F]{8})\b", lambda m: data[int(m.group(1), 16)][0] if int(m.group(1), 16) in data else m.group(0), s)
    res = []
    for a, n, (_, c) in out:
        used = set(re.findall(r"\b\w+\b", c))
        keep_d = [d for d in decls if ident(d) in used and ident(d) != n and not d.startswith("typedef")]
        # a typedef the body or a kept declaration uses
        used |= set(re.findall(r"\b\w+\b", " ".join(keep_d)))
        tds = []
        while True:
            more = [d for d in decls if d.startswith("typedef") and ident(d) in used and d not in tds]
            if not more:
                break
            tds += more
            used |= set(re.findall(r"\b\w+\b", " ".join(more)))
        # in declaration order, so a typedef comes after the ones it uses
        tds = [d for d in decls if d in tds]
        res.append((a, n, ([named(d) for d in tds + keep_d], named(c))))
    return res


def refile():
    """Move each Xbox-only function into the file its address belongs to
    (a module an _assert path names, or its run), as module_of and the
    runs now say, then build and check."""
    addr = {n: a for a, _, n in funcs}
    files = sorted(p for p in XB.rglob("*.c") if p.name not in ("main.c", "xb_gen_check.c"))
    items = []
    for p in files:
        text = p.read_text()
        body = re.sub(r"^#include <[^>]+>\n", "", text.split("#include \"types.h\"\n", 1)[1], flags=re.M)
        ds = ds_of(body)
        for a, n, (_, c) in from_file_text(body, keep_all=True):
            used = set(re.findall(r"\b\w+\b", c))
            mine = [d for d in ds if decl_name(d) in used and decl_name(d) != n and not d.startswith("typedef")]
            used |= set(re.findall(r"\b\w+\b", " ".join(mine)))
            tds = []
            while True:
                more = [d for d in ds if d.startswith("typedef") and decl_name(d) in used and d not in tds]
                if not more:
                    break
                tds += more
                used |= set(re.findall(r"\b\w+\b", " ".join(more)))
            items.append((a, n, ([d for d in ds if d in tds] + mine, c)))
    for p in files:
        p.unlink()
    return items


STRUCT_TYPES = None


def needs_structs(text):
    """whether text uses a type that include/structs.h defines"""
    global STRUCT_TYPES
    if STRUCT_TYPES is None:
        h = (ROOT / "include" / "structs.h").read_text(errors="replace")
        STRUCT_TYPES = set(re.findall(r"^\}\s*(\w+)\s*;", h, re.M)) | set(re.findall(r"^typedef\b[^;{]*?\b(\w+)\s*;", h, re.M)) \
            | set(re.findall(r"^struct\s+(\w+)\s*\{", h, re.M))
    return any(w in STRUCT_TYPES for w in re.findall(r"\b[A-Za-z_]\w*\b", text))


def main():
    cands = []
    if "--refile" in sys.argv:
        items = refile()
        sys.argv.append("--apply")
        return finish(items)
    if "--from" in sys.argv:
        cands = from_file(sys.argv[sys.argv.index("--from") + 1])
        return finish(cands)
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
    return finish(cands)


def finish(cands):
    # a thunk whose target is written here too would declare it twice
    made = {n for _, n, _ in cands}
    cands = [(a, n, g[:2]) for a, n, g in cands if len(g) < 3 or g[2] not in made]
    if not cands:
        print("no candidates")
        return
    print(f"{len(cands)} candidates", flush=True)
    if "--refile" in sys.argv:
        # the bodies already match where they are: no check build, the
        # files are written and checked below
        keep = cands
    else:
        decls = list(dict.fromkeys(x for _, _, (ds, _) in cands for x in ds))
        decls = [d for d in decls if d.startswith("typedef")] + [d for d in decls if not d.startswith("typedef")]
        CHECK.write_text("/* xbgen.py check build; not committed. */\n\n#include \"types.h\"\n#include \"structs.h\"\n#include <string.h>\n#include <stdarg.h>\n\n" + "\n".join(decls) + "\n\n" +
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
        if "--keep" in sys.argv:
            # leave the check build for tools/asmdiff.py; build_c.py drops it later
            print("kept the check build (src/sf33rd/Source/XBOX/xb_gen_check.c); delete it when done")
            return
        CHECK.unlink()
        (ROOT / "build" / "obj" / "sf33rd" / "Source" / "XBOX" / "xb_gen_check.obj").unlink(missing_ok=True)
        subprocess.run(["python3", str(ROOT / "tools" / "build_c.py"), "-j", "24"], cwd=ROOT, capture_output=True)
        subprocess.run(["python3", str(ROOT / "tools" / "objdiff.py")], cwd=ROOT, capture_output=True)
    if "--apply" in sys.argv and keep:
        addr = {n: a for a, _, n in funcs}
        by = {}
        hosted = {}
        for a, n, g in keep:
            if n in host_of:
                src = ROOT / "src" / (host_of[n][:-4] + ".c")
                hosted.setdefault(src, []).append((a, n, g))
                continue
            mod = module_of(a)
            key = (ROOT / "src" / mod).with_suffix(".c") if mod and "/XBOX/" in mod else XB / f"xb_{run_of[n]:06X}.c"
            by.setdefault(key, []).append((a, n, g))
        for p, items in sorted(by.items()):
            p.parent.mkdir(parents=True, exist_ok=True)
            defs, decls = {}, []
            if p.is_file():
                # what the file has: its definitions (with their comments) and declarations
                old = p.read_text()
                body = re.sub(r"^#include <[^>]+>\n", "", old.split("#include \"types.h\"\n", 1)[1], flags=re.M)
                for a, n, (ds, c) in from_file_text(body, keep_all=True):
                    defs[n] = c
                for d in ds_of(body):
                    if d not in decls:
                        decls.append(d)
            for a, n, (ds, c) in items:
                defs[n] = c
                for d in ds:
                    # a name the file declares already keeps that declaration
                    if d not in decls and decl_name(d) not in {decl_name(x) for x in decls}:
                        decls.append(d)
            orig = next((m for m in MODULES if (ROOT / "src" / m).with_suffix(".c") == p), None)
            if orig:
                what = (f"Capcom's {orig.split('/')[-1]}. Its _assert path names it, and the\n"
                        f" * code that pushes the path places it at 0x{MODULES[orig][0]:X} to 0x{MODULES[orig][1]:X}")
            else:
                what = (f"the run of Xbox-only functions at 0x{int(p.stem[3:], 16):X}, which no\n"
                        " * PS2 file covers")
            head = (f"/* {p.name}: Xbox-only code from {what}.\n"
                    " * Capcom's source is lost. Its C++ methods are written as C,\n"
                    " * XB_FASTCALL (__fastcall) with this first. Each body was checked\n"
                    " * against retail by analysis-ps2map/xbgen.py. The xb_ names are\n"
                    " * made up. */\n\n#include \"types.h\"\n\n")
            order = sorted(defs, key=lambda n: addr.get(n, 0))
            used = "\n\n".join(defs[n] for n in order)
            ds = [d for d in decls if not d.startswith("typedef") and re.search(r"\b" + re.escape(decl_name(d) or "") + r"\b", used) and decl_name(d) not in defs]
            # typedefs the bodies or the kept declarations use
            refs = used + "\n".join(ds)
            tds = []
            while True:
                more = [d for d in decls if d.startswith("typedef") and d not in tds and re.search(r"\b" + re.escape(decl_name(d) or "") + r"\b", refs)]
                if not more:
                    break
                tds += more
                refs += "\n".join(more)
            ds = [d for d in decls if d in tds] + ds
            # a prototype for each function defined here, from its own
            # definition, so a caller above it sees the right type
            own = []
            for n in order:
                m = re.search(r"^([A-Za-z_][^;{}()\n]*?\b" + re.escape(n) + r"\s*\([^;{}]*\))\s*\{", defs[n], re.M)
                if m and re.search(r"\b" + re.escape(n) + r"\s*\(", used[:used.find(m.group(0))]):
                    own.append(re.sub(r"\s+", " ", m.group(1)) + ";")
            inc = "#include <string.h>\n" if re.search(r"\b(memset|memcpy|memcmp|strlen|strcpy)\s*\(", used) else ""
            if re.search(r"\bva_(list|start)\b", used + "\n".join(decls)):
                inc += "#include <stdarg.h>\n"
            if needs_structs(used + "\n".join(decls)) and "structs.h" not in head:
                inc = "#include \"structs.h\"\n" + inc
            head = head.replace("#include \"types.h\"\n", "#include \"types.h\"\n" + inc, 1)
            # a function defined in another file that a body here calls
            have_d = {decl_name(d) for d in ds} | set(defs)
            for fn in dict.fromkeys(re.findall(r"\b(\w+)\s*\(", used)):
                if fn not in have_d and fn in PROTOS:
                    rt, params = PROTOS[fn]
                    ds.append(f"{re.sub(r'^static\s+', '', rt)} {fn}({params or 'void'});")
                    have_d.add(fn)
            ds = [d for d in ds if d.startswith("typedef")] + [d for d in ds if not d.startswith("typedef")] + own
            p.write_text(head + "\n".join(ds) + ("\n\n" if ds else "") + used + "\n")
        regen = []
        for src, items in sorted(hosted.items()):
            # into the game file: the override of a generated port, or the
            # hand port itself
            gen = "Ported from the PS2" in src.read_text(errors="replace")[:4000]
            dst = ROOT / "analysis-ps2map" / "overrides" / src.name if gen else src
            text = dst.read_text() if dst.is_file() else ""
            ds = [d for d in dict.fromkeys(x for _, _, (dd, _) in items for x in dd) if (decl_name(d) or "") not in text]
            add = ("/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */\n"
                   + "\n".join(ds) + ("\n\n" if ds else "") + "\n\n".join(c for _, _, (_, c) in sorted(items)) + "\n")
            dst.write_text((text.rstrip("\n") + "\n\n" if text else "") + add)
            if gen:
                regen.append(src.relative_to(ROOT / "src" / "sf33rd" / "Source").as_posix())
            by.setdefault(src, [])
        if regen:
            subprocess.run(["python3", str(ROOT / "analysis-ps2map" / "regen.py"), *regen], cwd=ROOT)
        print("written", len(by), "files")
        # the files as written must build and keep every body matching; a
        # body that does not (one that matched alone but not beside its
        # file's other functions) is taken back out
        sys.path.insert(0, str(ROOT / "tools"))
        import permute
        tried_alone = set()
        for attempt in range(5):
            r = subprocess.run(["python3", str(ROOT / "tools" / "build_c.py"), "-j", "24"], cwd=ROOT, capture_output=True, text=True)
            fails = [l for l in r.stdout.splitlines() if l.startswith("FAIL")]
            for q in sorted(by):
                # game files are checked as in the commit checklist: their PS2 C
                # passes array members where pointers are declared
                extra = ["-Wno-incompatible-pointer-types"] if "/Game/" in str(q) else []
                g = subprocess.run(["gcc", "-m32", "-std=gnu17", "-fsyntax-only", *extra, "-I" + str(ROOT / "include"), str(q)], capture_output=True, text=True)
                fails += [f"gcc: {l}" for l in g.stderr.splitlines() if "error" in l]
            if fails:
                print("VERIFY FAILED (fix by hand):", *fails, sep="\n  ")
                sys.exit(1)
            subprocess.run(["python3", str(ROOT / "tools" / "objdiff.py")], cwd=ROOT, capture_output=True)
            st = {f["name"]: f["status"] for o, rr in json.load(open(ROOT / "build" / "objdiff.json")).items() for f in rr["functions"]}
            bad = [n for _, n, _ in keep if st.get(n) != "match"]
            if not bad:
                break
            print("taken back out (no match in its file):", ", ".join(f"{n} {st.get(n)}" for n in bad))
            # a body that matched alone but not beside the others shows a
            # file boundary: it starts a file of its own, tried once
            moved = [(a, n, g) for a, n, g in keep if n in bad and n not in tried_alone]
            regen2 = []
            for q in sorted(by):
                if "Ported from the PS2" in q.read_text(errors="replace")[:4000]:
                    # a generated port changes through its override
                    regen2.append(q.relative_to(ROOT / "src" / "sf33rd" / "Source").as_posix())
                    q = ROOT / "analysis-ps2map" / "overrides" / q.name
                txt = q.read_text()
                for n in bad:
                    s = permute.find_definition(txt, n)
                    if s:
                        a0 = s[0]
                        before = txt[:a0].rstrip()
                        if before.endswith("*/"):
                            a0 = before.rfind("/*")
                        txt = txt[:a0].rstrip("\n") + "\n\n" + txt[s[1]:].lstrip("\n")
                        txt = re.sub(r"^[^\n;{}]*\b" + re.escape(n) + r"\s*\([^;{}]*\);\n", "", txt, flags=re.M)
                q.write_text(txt)
            if regen2:
                subprocess.run(["python3", str(ROOT / "analysis-ps2map" / "regen.py"), *regen2], cwd=ROOT, capture_output=True)
            for a, n, (ds, c) in moved:
                if n in host_of:
                    continue
                q = XB / f"xb_{a:06X}.c"
                tried_alone.add(n)
                q.write_text(f"/* {q.name}: Xbox-only code from 0x{a:X}. {n} matches only apart from\n"
                             " * the functions around it, so a file of Capcom's starts here.\n"
                             " * Capcom's source is lost. Its C++ methods are written as C,\n"
                             " * XB_FASTCALL (__fastcall) with this first. Each body was checked\n"
                             " * against retail by analysis-ps2map/xbgen.py. The xb_ names are\n"
                             " * made up. */\n\n#include \"types.h\"\n"
                             + ("#include \"structs.h\"\n" if needs_structs(c) else "")
                             + ("#include <string.h>\n" if re.search(r"\bmem(set|cpy)\b|\bstr(len|cpy)\b", c) else "")
                             + "\n" + "\n".join(ds) + ("\n\n" if ds else "") + c + "\n")
                by.setdefault(q, [])
            keep = [k for k in keep if k[1] not in bad or k[1] in tried_alone and k in moved]
        print("verified: the written files build and all", len(keep), "match")


main()
