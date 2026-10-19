# portdata.py PS2FILE... [--write]: port a PS2 data file and check it.
#
# PS2FILE is a path under the PS2 tree's src/anniversary (for example
# sf33rd/Source/Game/Com_Data.c). The file's text is taken with its
# includes replaced by the Xbox tree's ("structs.h"), built with gcc -m32,
# and every table it defines is compared with the retail XBE at the
# address data.txt gives that name. Plain bytes must be equal. A pointer
# must point where its target is: a named target at its retail address
# (funcs.txt, data.txt, xdk.txt), a string literal or other local object
# at retail bytes equal to its own. Each table is reported as "match",
# "differs" (with the first offsets), or "no address".
#
# With --write the file is written to src/ under its PS2 path, with a
# header that records the result. Nothing is written without --write.
# A path under src/ checks that file of this tree as it is (after an Xbox
# change to a table, for instance).
import os, re, subprocess, sys, tempfile, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ps2paths import OG, PS
sys.path.insert(0, OG + "/tools")
from ogxb.paths import find_xbe
from ogxb.xbe import load

img = load(find_xbe())
RAW = open(img.path, "rb").read()


def rd(va, n):
    for s in img.sections:
        if s.va <= va < s.va + s.virtual_size:
            o = va - s.va
            b = RAW[s.raw + o:s.raw + min(o + n, s.raw_size)] if o < s.raw_size else b""
            return b + b"\0" * (n - len(b))
    return None


ADDR = {}
# a folded name is at the address of the body it was merged into
import json
for a_, ns_ in json.load(open(OG + "/analysis-ps2map/folded.json")).items():
    for n_ in ns_:
        ADDR.setdefault(n_, int(a_, 16))
for f in ("funcs.txt", "data.txt", "xdk.txt"):
    for l in open(OG + "/config/sf33rd/symbols/" + f, errors="replace"):
        m = re.match(r"(\S+)\s*=\s*0x([0-9A-Fa-f]+);", l)
        if m:
            ADDR.setdefault(m[1], int(m[2], 16))


def header_types(hpath):
    """the typedefs and #defines of a PS2 header (no prototypes or externs)"""
    if not os.path.isfile(hpath):
        return ""
    h = open(hpath, errors="replace").read()
    h = re.sub(r"/\*.*?\*/|//[^\n]*", "", h, flags=re.S)
    out = []
    for m in re.finditer(r"^#define\s+(\w+)(?!\()\s+[^\n]*$", h, re.M):
        if not m[1].endswith("_H"):
            out.append(m[0])
    for m in re.finditer(r"^typedef\b[^;{]*(?:\{.*?\}[^;]*)?;", h, re.M | re.S):
        out.append(m[0])
    for m in re.finditer(r"^(?:struct|union|enum)\s+\w+\s*\{.*?\}\s*;", h, re.M | re.S):
        out.append(m[0])
    # extern data (another file's tables this one points at) and the
    # prototypes of functions a table points at
    for m in re.finditer(r"^extern\s+[^;()]*;", h, re.M):
        out.append(m[0])
    for m in re.finditer(r"^(?!typedef|extern|#)[A-Za-z_][\w \*]*\b\w+\s*\([^;{]*\)\s*;", h, re.M):
        out.append(m[0])
    return "\n".join(out)


def prepare(text):
    extra = []
    for m in re.finditer(r'^#include\s+"(sf33rd/[^"]+\.h)"', text, re.M):
        t = header_types(os.path.join(PS, "include", m[1]))
        if t:
            extra.append(f"/* from {m[1]} */\n" + t)
    text = re.sub(r'^#include\s+[<"][^>"]*[>"]\s*\n', "", text, flags=re.M)
    # the PS2 bin2obj files place their tables with DATA_SECTION
    pre = "#ifndef DATA_SECTION\n#define DATA_SECTION\n#endif\n\n" if "DATA_SECTION" in text else ""
    return '#include "structs.h"\n#include <stddef.h>\n\n' + pre + ("\n\n".join(extra) + "\n\n" if extra else "") + text.lstrip("\n")


def elf(obj):
    secs = {}
    for l in subprocess.run(["readelf", "-SW", obj], capture_output=True, text=True).stdout.splitlines():
        m = re.match(r"\s*\[\s*(\d+)\]\s+(\S+)", l)
        if m:
            secs[int(m[1])] = m[2]
    syms = {}
    for l in subprocess.run(["readelf", "-sW", obj], capture_output=True, text=True).stdout.splitlines():
        p = l.split()
        if len(p) >= 8 and p[0].rstrip(":").isdigit() and p[6].isdigit():
            syms.setdefault(p[7], (secs.get(int(p[6])), int(p[1], 16), int(p[2]), p[3], p[4]))
    rel = {}
    cur = None
    for l in subprocess.run(["readelf", "-rW", obj], capture_output=True, text=True).stdout.splitlines():
        m = re.match(r"Relocation section '\.rel(\S+)'", l)
        if m:
            cur = m[1]; rel.setdefault(cur, {}); continue
        m = re.match(r"([0-9a-f]{8})\s+\S+\s+\S+\s+[0-9a-f]+\s+(\S+)", l)
        if m and cur:
            rel[cur][int(m[1], 16)] = m[2]
    return secs, syms, rel


def secbytes(obj, sec, td):
    dst = os.path.join(td, "s.bin")
    subprocess.run(["objcopy", "-O", "binary", "--only-section=" + sec, obj, dst], check=True)
    return open(dst, "rb").read()


def check(path):
    # a+b+c checks several files as one unit (tables that point across files)
    parts = path.split("+")
    if parts[0].startswith("src/"):
        # a file already in this tree: checked as it is
        text = "\n".join(open(os.path.join(OG, p), errors="replace").read() for p in parts)
    else:
        text = prepare("\n".join(open(os.path.join(PS, "src/anniversary", p), errors="replace").read() for p in parts))
    out = []
    with tempfile.TemporaryDirectory() as td:
        src = os.path.join(td, os.path.basename(path.split("+")[0]))
        open(src, "w").write(text)
        obj = os.path.join(td, "f.o")
        r = subprocess.run(["gcc", "-m32", "-std=gnu17", "-O0", "-fno-pic", "-fno-common", "-fno-merge-constants", "-w", "-Wno-incompatible-pointer-types", "-Wno-int-conversion",
                            "-I" + OG + "/include", "-c", src, "-o", obj], capture_output=True, text=True)
        if r.returncode:
            return text, None, r.stderr[-1500:]
        secs, syms, rel = elf(obj)
        cache = {}
        def sb(sec):
            if sec not in cache:
                cache[sec] = secbytes(obj, sec, td)
            return cache[sec]
        objs = {n: v for n, v in syms.items() if v[3] == "OBJECT" and v[0] is not None}
        def mine_of(n):
            sec, off, size = objs[n][:3]
            return sb(sec)[off:off + size] if sec != ".bss" else b"\0" * size
        bysec = {}
        for n_, v_ in objs.items():
            bysec.setdefault(v_[0], []).append((v_[1], v_[2], n_))
        def resolve(t, add):
            """a section-relative pointer to an object in that section, as
            (object, offset in it)"""
            if t.startswith(".") and not t.startswith(".rodata.str"):
                for o_, sz_, n_ in bysec.get(t, []):
                    if o_ <= add < o_ + max(sz_, 1):
                        return n_, add - o_
            return t, add
        def ptrs_of(n):
            sec, off, size = objs[n][:3]
            return {o - off: t for o, t in rel.get(sec, {}).items() if off <= o < off + size}
        # an object the file does not name in data.txt gets the address a
        # pointer to it holds in retail
        addr = {n: ADDR[n] for n in objs if n in ADDR}
        # a D_ADDR name of this tree is at its address (a PS2 file's D_ names
        # are PS2 addresses)
        if parts[0].startswith("src/"):
            addr.update({n: int(n[2:], 16) for n in objs if re.fullmatch(r"D_[0-9A-F]{8}", n)})
        via = {}
        work = list(addr)
        while work:
            n = work.pop()
            ret = rd(addr[n], objs[n][2])
            if ret is None:
                continue
            mine = mine_of(n)
            for o, t in ptrs_of(n).items():
                t, add = resolve(t, struct.unpack_from("<i", mine, o)[0])
                if t in objs and t not in addr and t not in ADDR:
                    addr[t] = struct.unpack_from("<I", ret, o)[0] - add
                    via[t] = n
                    work.append(t)
        for name in sorted(objs):
            sec, off, size, typ, bind = objs[name]
            if name not in addr:
                if bind == "GLOBAL":
                    out.append((name, None, size, "no address", []))
                continue
            a = addr[name]
            mine = mine_of(name)
            ret = rd(a, size)
            if ret is None:
                out.append((name, a, size, "address outside the image", []))
                continue
            bad = []
            skip = set()
            for o, t in ptrs_of(name).items():
                skip.update(range(o, o + 4))
                t, add = resolve(t, struct.unpack_from("<i", mine, o)[0])
                rv = struct.unpack_from("<I", ret, o)[0]
                if t in addr or t in ADDR:
                    if addr.get(t, ADDR.get(t)) + add != rv:
                        bad.append(o)
                elif t.startswith("."):
                    # a section symbol (string literals): the bytes it points at
                    lb = sb(t)
                    e = lb.find(b"\0", add)
                    s_ = lb[add:e + 1] if e >= 0 else lb[add:add + 4]
                    if rd(rv, len(s_)) != s_:
                        bad.append(o)
                else:
                    bad.append(o)
            for i in range(size):
                if i not in skip and mine[i] != ret[i]:
                    bad.append(i)
            bad = sorted(set(bad))
            st = "match" if not bad else "differs"
            if name in via:
                st += " (placed by " + via[name] + ")"
            out.append((name, a, size, st, bad))
    return text, out, None


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    write = "--write" in sys.argv
    for path in args:
        text, res, err = check(path)
        if res is None:
            print(f"{path}: gcc failed\n{err}")
            continue
        for name, a, size, st, bad in res:
            more = (" at " + ", ".join(hex(b) for b in bad[:6]) + (" ..." if len(bad) > 6 else "")) if bad else ""
            print(f"{path}: {name} {hex(a) if a else ''} size {hex(size)}: {st}{more}")
        if write:
            for part in path.split("+"):
                ptext = open(os.path.join(PS, "src/anniversary", part), errors="replace").read()
                mine_ = [(n, a, s_, st) for n, a, s_, st, _ in res
                         if re.search(r"\b" + re.escape(n) + r"\s*(?:\[[^\]]*\]\s*)*=", ptext)]
                lines = [f" * {n} {hex(a) if a else ''} size {hex(s_)}: {st}." for n, a, s_, st in mine_]
                dst = os.path.join(OG, "src", part)
                os.makedirs(os.path.dirname(dst), exist_ok=True)
                head = (f"/* {os.path.basename(part)}, retail sf33rd.xbe.\n"
                        " * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py\n"
                        " * against the XBE: each table at its data.txt address, or at the\n"
                        " * address a checked table's pointer to it holds (\"placed by\").\n"
                        + "\n".join(lines) + "\n */\n\n")
                open(dst, "w").write(head + prepare(ptext))

if __name__ == "__main__":
    main()
