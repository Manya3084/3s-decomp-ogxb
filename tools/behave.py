#!/usr/bin/env python3
"""behave.py FUNC... [-n TRIALS] [--seed S] [-v]: run a function's C against its retail code.

A function whose C does not build to retail's bytes can still behave the
same. This checks that by running both. The retail image is mapped at its
own addresses in a 32-bit host process (it fits below the host program),
so retail code runs with its real callees and globals. The function's
source file is compiled with gcc -m32, and every other symbol in it that
has a retail address (funcs.txt, data.txt, xdk.txt, and the D_/sub_
placeholders) is pointed at that address, so the C version also calls
retail callees and reads and writes retail globals. Only FUNC itself is
the C.

Each trial forks twice from the same state: one child calls the retail
body, the other the C body, with the same arguments. A pointer argument
points at a scratch buffer of random bytes; other arguments are random
small values. Afterwards each child hashes every page of the image and the
scratch buffers and reports them with the return value. Equal hashes and
return values pass. A trial where both crash is counted but proves
nothing; one crashing alone is a mismatch.

Needs gcc with -m32 support and the retail XBE (xbe.path). Nothing is
written to the tree; the build goes to a temporary directory.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
def register_statics(src: Path) -> set[str]:
    """the functions config/sf33rd/static.txt lists for this source file"""
    rel = str(Path(src).resolve().relative_to(ROOT))
    out: set[str] = set()
    for line in (ROOT / "config" / "sf33rd" / "static.txt").read_text().splitlines():
        p = line.split()
        if p and not p[0].startswith("#") and p[0] == rel:
            out.update(p[1:])
    return out


HOST_LIBC = {"__divdi3", "__udivdi3", "__moddi3", "__umoddi3", "free", "malloc", "calloc", "realloc", "fopen", "fclose", "fgets", "fputs", "fread", "fwrite",
             "fseek", "ftell", "fflush", "printf", "fprintf", "puts", "atol", "atoi", "strtol", "strtoul",
             "qsort", "rand", "srand", "time", "exit", "abort", "lrintf", "lrint", "lroundf", "lround"}
sys.path.insert(0, str(Path(__file__).resolve().parent))

from ogxb.paths import find_xbe  # noqa: E402
from ogxb.xbe import load  # noqa: E402

SYMDIR = ROOT / "config" / "sf33rd" / "symbols"


def retail_addresses() -> dict[str, int]:
    out: dict[str, int] = {}
    # a folded name runs the body it was merged into
    for k, names in json.loads((ROOT / "analysis-ps2map" / "folded.json").read_text()).items():
        if int(k, 16) >= 0x11000:
            for n in names:
                out.setdefault(n, int(k, 16))
    for f in sorted(SYMDIR.glob("*.txt")):
        for line in f.read_text(errors="replace").splitlines():
            m = re.match(r"(\S+)\s*=\s*0x([0-9A-Fa-f]+);", line)
            if m:
                out.setdefault(m[1], int(m[2], 16))
    return out


def placeholder_address(name: str) -> int | None:
    m = re.fullmatch(r"(?:D|sub|dat)_([0-9A-Fa-f]{8})", name)
    return int(m[1], 16) if m else None


def source_of(func: str) -> Path:
    data = json.loads((ROOT / "build" / "objdiff.json").read_text())
    for obj, rec in data.items():
        if any(f["name"] == func for f in rec["functions"]):
            return ROOT / "src" / (obj[: -len(".obj")] + ".c")
    raise SystemExit(f"{func}: not in build/objdiff.json (no C, or run make objdiff)")


def prototype(src: str, func: str) -> tuple[str, str, list[str]]:
    """return type, convention (cdecl/stdcall/fastcall), parameter types"""
    m = re.search(r"^([A-Za-z_][\w \*]*?)\b" + re.escape(func) + r"\s*\(([^)]*)\)\s*\{", src, re.M)
    if not m:
        raise SystemExit(f"{func}: definition not found")
    head, params = m[1], m[2]
    conv = "fastcall" if "XB_FASTCALL" in head or "__fastcall" in head else \
        "stdcall" if "XB_STDCALL" in head or "__stdcall" in head else "cdecl"
    ret = re.sub(r"\b(static|XB_FASTCALL|XB_STDCALL|__fastcall|__stdcall|inline)\b", "", head).strip()
    ps = [p.strip() for p in params.split(",") if p.strip() and p.strip() != "void"]
    return ret, conv, ps


def gcc_flags(path: Path) -> list[str]:
    # Capcom's files use /arch:SSE (float math in SSE); CRI's do not (x87)
    fpm = ["-mfpmath=387"] if "/cri/" in str(path) else ["-msse2", "-mfpmath=sse"]
    fl = ["-m32", "-std=gnu17", "-O1", "-fno-pic", "-fno-pie", "-fno-stack-protector", "-fcf-protection=none",
          "-fno-strict-aliasing", "-fwrapv", *fpm, "-w", f"-I{ROOT / 'include'}"]
    if "/Source/Game/" in str(path):
        fl.append("-Wno-incompatible-pointer-types")
    return fl


RUNNER = r"""
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define IMG_LO 0x10000u
#define IMG_HI @IMG_HI@u
#define SCR 0x0E000000u
#define SCRSZ 0x4000u
#define NSCR 16
extern void @FUNC@(void);
uint32_t g_args[16], g_ret[2], g_saved_esp, g_fn;
int g_nargs, g_conv, g_fret;
uint32_t g_rmask[2];
static void call_it(void) {
    /* push the arguments, call, and restore esp whatever the callee popped */
    __asm__ volatile(
        "pushal\n\t"
        "movl %%esp, g_saved_esp\n\t"
        "movl g_nargs, %%ecx\n\t"
        "movl g_conv, %%eax\n\t"
        "cmpl $2, %%eax\n\t"
        "jne 1f\n\t"
        "subl $2, %%ecx\n\t"
        "jle 3f\n\t"
        "1:\n\t"
        "testl %%ecx, %%ecx\n\t"
        "jle 3f\n\t"
        "2:\n\t"
        "movl g_conv, %%eax\n\t"
        "cmpl $2, %%eax\n\t"
        "jne 4f\n\t"
        "pushl g_args+4(,%%ecx,4)\n\t"
        "jmp 5f\n\t"
        "4:\n\t"
        "pushl g_args-4(,%%ecx,4)\n\t"
        "5:\n\t"
        "decl %%ecx\n\t"
        "jnz 2b\n\t"
        "3:\n\t"
        "movl g_args, %%ecx\n\t"
        "movl g_args+4, %%edx\n\t"
        "call *g_fn\n\t"
        "movl %%eax, g_ret\n\t"
        "movl %%edx, g_ret+4\n\t"
        "movl g_fret, %%ecx\n\t"
        "testl %%ecx, %%ecx\n\t"
        "jz 6f\n\t"
        "fstps g_ret\n\t"
        "6:\n\t"
        "movl g_saved_esp, %%esp\n\t"
        "popal\n\t"
        ::: "memory");
}
static uint32_t crc(const uint8_t *p, size_t n) {
    const uint32_t *w = (const uint32_t *)p;
    uint32_t h = 2166136261u;
    for (size_t i = 0; i < n / 4; i++) h = (h ^ w[i]) * 16777619u;
    return h;
}
static void report(int fd) {
    uint32_t n = 0;
    for (uint32_t a = IMG_LO; a < IMG_HI; a += 0x1000) { uint32_t h = crc((uint8_t *)a, 0x1000); write(fd, &h, 4); n++; }
    for (uint32_t a = SCR; a < SCR + NSCR * SCRSZ; a += 0x1000) { uint32_t h = crc((uint8_t *)a, 0x1000); write(fd, &h, 4); }
    g_ret[0] &= g_rmask[0]; g_ret[1] &= g_rmask[1];
    write(fd, g_ret, 8);
}
static int dump_page(uint32_t fn, uint32_t page, uint8_t *buf) {
    int p[2]; pipe(p);
    pid_t pid = fork();
    if (pid == 0) {
        close(p[0]); alarm(2);
        { unsigned short cw = 0x027F; __asm__ volatile("fldcw %0" :: "m"(cw)); }
        g_fn = fn; call_it(); write(p[1], (void *)page, 0x1000); _exit(0);
    }
    close(p[1]);
    size_t got = 0; ssize_t r;
    while (got < 0x1000 && (r = read(p[0], buf + got, 0x1000 - got)) > 0) got += r;
    close(p[0]); int st; waitpid(pid, &st, 0);
    return got == 0x1000;
}
static int run(uint32_t fn, uint32_t *hashes, uint32_t npg) {
    int p[2]; pipe(p);
    pid_t pid = fork();
    if (pid == 0) {
        close(p[0]); alarm(2);
        { unsigned short cw = 0x027F; __asm__ volatile("fldcw %0" :: "m"(cw)); } /* the Xbox runs x87 at 53 bits */
        g_fn = fn; call_it(); report(p[1]); _exit(0);
    }
    close(p[1]);
    size_t want = (npg + 2) * 4, got = 0; uint8_t *b = (uint8_t *)hashes;
    ssize_t r;
    while (got < want && (r = read(p[0], b + got, want - got)) > 0) got += r;
    close(p[0]);
    int st; waitpid(pid, &st, 0);
    if (got != want) return WIFSIGNALED(st) ? WTERMSIG(st) : 99;
    return 0;
}
int main(int argc, char **argv) {
    int trials = atoi(argv[2]); unsigned seed = (unsigned)atoi(argv[3]); int verbose = atoi(argv[4]);
    void *m = mmap((void *)IMG_LO, IMG_HI - IMG_LO, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    if (m == MAP_FAILED) { perror("mmap image"); return 2; }
    FILE *f = fopen(argv[1], "rb"); if (!f) { perror("xbe"); return 2; }
@SECTIONS@
    fclose(f);
    if (mmap((void *)SCR, NSCR * SCRSZ, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0) == MAP_FAILED) { perror("mmap scratch"); return 2; }
    uint32_t npg = (IMG_HI - IMG_LO) / 0x1000 + NSCR * SCRSZ / 0x1000;
    uint32_t *ha = malloc((npg + 2) * 4), *hb = malloc((npg + 2) * 4);
    int pass = 0, both = 0, bad = 0;
    g_nargs = @NARGS@; g_conv = @CONV@; g_fret = @FRET@; g_rmask[0] = @RMASK0@u; g_rmask[1] = @RMASK1@u;
    srand(seed);
    for (int t = 0; t < trials; t++) {
        for (uint32_t i = 0; i < NSCR * SCRSZ; i++) ((uint8_t *)SCR)[i] = rand();
        if (t % 4 == 0) memset((void *)SCR, 0, NSCR * SCRSZ);
@ARGS@
@POKES@
        int sa = run(@RETAIL@u, ha, npg), sb = run((uint32_t)(uintptr_t)@FUNC@, hb, npg);
        if (sa && sb) { both++; if (verbose) printf("trial %d: both stop (%d, %d)\n", t, sa, sb); continue; }
        if (sa || sb) { bad++; printf("trial %d: retail %s, C %s\n", t, sa ? "crashed" : "ran", sb ? "crashed" : "ran"); continue; }
        if (memcmp(ha, hb, (npg + 2) * 4) == 0) { pass++; continue; }
        bad++;
        if (bad <= 3) {
            printf("trial %d: args", t); for (int i = 0; i < g_nargs; i++) printf(" %#x", g_args[i]); printf("\n");
            if (ha[npg] != hb[npg] || ha[npg + 1] != hb[npg + 1]) printf("  return retail %#x:%#x C %#x:%#x\n", ha[npg + 1], ha[npg], hb[npg + 1], hb[npg]);
            int shown = 0;
            for (uint32_t i = 0; i < npg && shown < 6; i++)
                if (ha[i] != hb[i]) {
                    uint32_t a = i < (IMG_HI - IMG_LO) / 0x1000 ? IMG_LO + i * 0x1000 : SCR + (i - (IMG_HI - IMG_LO) / 0x1000) * 0x1000;
                    printf("  page %#x differs:", a); shown++;
                    static uint8_t pa[0x1000], pb[0x1000];
                    if (dump_page(@RETAIL@u, a, pa) && dump_page((uint32_t)(uintptr_t)@FUNC@, a, pb)) {
                        int k = 0;
                        for (int o = 0; o < 0x1000 && k < 6; o++)
                            if (pa[o] != pb[o]) { printf(" %#x:%02x/%02x", a + o, pa[o], pb[o]); k++; }
                    }
                    printf("\n");
                }
        }
    }
    printf("%d pass, %d both stop, %d mismatch, of %d\n", pass, both, bad, trials);
    return bad ? 1 : 0;
}
"""


def is_wide(p: str) -> bool:
    """a parameter passed in two stack slots (f64, s64, u64)"""
    return "*" not in p and "[" not in p and bool(re.search(r"\b(f64|double|s64|u64|long long)\b", p))


def nslots(params: list[str]) -> int:
    return sum(2 if is_wide(p) else 1 for p in params)


def arg_code(params: list[str], fixed: list[str] | None = None) -> str:
    lines = []
    i = 0
    for p in params:
        if i >= 16:
            break
        if is_wide(p):
            # fixed arguments name stack slots, so a wide one takes two
            if fixed and i + 1 < len(fixed) and fixed[i] not in ("", "p", "?"):
                lines.append(f"        g_args[{i}] = (uint32_t)({fixed[i]}); g_args[{i + 1}] = (uint32_t)({fixed[i + 1]});")
            elif re.search(r"\b(f64|double)\b", p):
                lines.append(f"        {{ double v = (double)(rand() % 2001 - 1000) / 7.0; memcpy(&g_args[{i}], &v, 8); }}")
            else:
                lines.append(f"        g_args[{i}] = (uint32_t)rand(); g_args[{i + 1}] = (uint32_t)(rand() & 0xFF);")
            i += 2
            continue
        lines.extend(_one_arg(i, p, fixed))
        i += 1
    return "\n".join(lines)


def _one_arg(i: int, p: str, fixed: list[str] | None) -> list[str]:
    lines = []
    if True:
        if fixed and i < len(fixed) and fixed[i] not in ("", "p", "?"):
            m = re.fullmatch(r"scr(\d+)", fixed[i])
            v = f"SCR + {int(m[1])} * SCRSZ" if m else fixed[i]
            lines.append(f"        g_args[{i}] = (uint32_t)({v});")
            return lines
        if "*" in p or "[" in p:
            lines.append(f"        g_args[{i}] = SCR + {i} * SCRSZ + (t % 2) * 0x100;")
        elif re.search(r"\b(f32|float)\b", p):
            lines.append(f"        {{ float v = (float)(rand() % 2001 - 1000) / 7.0f; memcpy(&g_args[{i}], &v, 4); }}")
        else:
            lines.append(f"        {{ static const int small[] = {{0, 1, 2, 3, 4, -1, 5, 8}}; int r = rand() % 4;"
                         f" g_args[{i}] = r == 0 ? (uint32_t)rand() : r == 1 ? (uint32_t)(rand() & 0xFF) : (uint32_t)small[rand() % 8]; }}")
    return lines


def poke_code(pokes: list[str]) -> str:
    out = []
    for p in pokes:
        k, v = p.split("=", 1)

        def place(x: str) -> str:
            # scrN or scrN+OFF is scratch buffer N (plus OFF); anything else is an address or value
            m = re.fullmatch(r"scr(\d+)(?:\+(0x[0-9A-Fa-f]+|\d+))?", x)
            if m:
                return f"(SCR + {int(m[1])} * SCRSZ + {int(m[2], 0) if m[2] else 0})"
            return f"({x}u)"

        out.append(f"        *(uint32_t *)({place(k)}) = (uint32_t)({place(v)});")
    return "\n".join(out)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("funcs", nargs="+")
    ap.add_argument("-n", type=int, default=200)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("-v", action="store_true")
    ap.add_argument("--args", help="comma-separated fixed arguments (p or ? keeps the random one)")
    ap.add_argument("--poke", action="append", default=[],
                    help="ADDR=VALUE: a dword written before each trial (VALUE may be scrN, scratch buffer N)")
    ap.add_argument("--keep", help="build in this directory and keep it (for a debugger)")
    ap.add_argument("--fill-null", action="store_true",
                    help="point each global dword the function's C uses and the image holds as 0 at scratch "
                         "(buffers 8 to 15), so code that reads through the game's work pointers runs")
    a = ap.parse_args()
    addr = retail_addresses()
    xbe = find_xbe()
    img = load(xbe)
    hi = max(s.va + s.virtual_size for s in img.sections)
    hi = (hi + 0xFFF) & ~0xFFF
    secs = "\n".join(
        f"    fseek(f, {s.raw:#x}, SEEK_SET); fread((void *){s.va:#x}u, 1, {min(s.raw_size, s.virtual_size):#x}, f);"
        for s in img.sections)
    # a static listed in static.txt takes its arguments in registers, which a cdecl call cannot give it
    regargs = set()
    for line in (ROOT / "config" / "sf33rd" / "static.txt").read_text().splitlines():
        if line.strip() and not line.startswith("#"):
            regargs.update(line.split()[1:])
    worst = 0
    for func in a.funcs:
        if func in regargs:
            print(f"{func}: register arguments (static.txt), not run"); continue
        if func not in addr:
            print(f"{func}: no retail address"); worst = 2; continue
        src_path = source_of(func)
        src_text = src_path.read_text(errors="replace")
        if re.search(r"^static\b[^;{]*\b" + re.escape(func) + r"\s*\(", src_text, re.M):
            print(f"{func}: static, may take register arguments, not run"); continue
        ret, conv, params = prototype(src_text, func)
        with tempfile.TemporaryDirectory() as td:
            td = Path(a.keep) if a.keep else Path(td)
            td.mkdir(parents=True, exist_ok=True)
            obj = td / "f.o"
            r = subprocess.run(["gcc", *gcc_flags(src_path), "-c", str(src_path), "-o", str(obj)], capture_output=True, text=True)
            if r.returncode:
                print(f"{func}: gcc failed\n{r.stderr[-2000:]}"); worst = 2; continue
            nm = subprocess.run(["nm", str(obj)], capture_output=True, text=True).stdout
            weaken, defs, used = [], [], []
            regstatic = register_statics(src_path)
            for line in nm.splitlines():
                parts = line.split()
                if len(parts) == 3 and parts[1] in "TDBRCV" and parts[2] != func:
                    n = parts[2]
                    # retail's copy of a register-argument static reads its argument where
                    # the C call does not put it, so the C keeps calling its own copy
                    if n in regstatic:
                        continue
                    v = addr.get(n, placeholder_address(n))
                    if v is not None:
                        weaken.append(n); defs.append((n, v))
                elif len(parts) == 2 and parts[0] == "U":
                    n = parts[1]
                    # the host C library calls these itself, so pointing them at retail's
                    # copies would break the harness; the C side uses the host's
                    if n in HOST_LIBC:
                        continue
                    v = addr.get(n, placeholder_address(n))
                    # a C library call goes to retail's copy when it has one, so both sides run the same code
                    if v is None and n in ("memset", "memcpy", "memmove", "memcmp", "strlen", "strcmp", "strcpy",
                                            "strncpy", "strcat", "sprintf", "vsprintf", "abs",
                                            "sinf", "cosf", "sqrtf", "tanf", "atan2f", "atanf", "fabsf", "powf",
                                            "sin", "cos", "sqrt", "tan", "atan2", "atan", "fabs", "pow", "floor", "ceil"):
                        continue
                    defs.append((n, v if v is not None else 0xDEAD0000))
                    if a.fill_null and v is not None:
                        used.append((n, v))
            # a name with no retail address gets zeroed host storage (data the PS2 port keeps,
            # or a global another file defines); the retail side uses its own copy, so a
            # mismatch through it may only mean the data was never located
            missing = [n for n, v in defs if v == 0xDEAD0000]
            defs = [(n, v) for n, v in defs if v != 0xDEAD0000]
            if weaken:
                subprocess.run(["objcopy", *sum((["-W", n] for n in weaken), []), str(obj)], check=True)
            pokes = list(a.poke)
            if a.fill_null:
                # a null pointer in the unstarted image: give both sides the same scratch target
                k = 0
                raw = xbe.read_bytes() if hasattr(xbe, "read_bytes") else Path(xbe).read_bytes()
                for n, v in sorted(used, key=lambda x: x[1]):
                    sec = next((x for x in img.sections if x.va <= v < x.va + x.virtual_size), None)
                    if sec is None or sec.name != ".data" or v % 4:
                        continue
                    o = v - sec.va
                    word = raw[sec.raw + o:sec.raw + o + 4] if o + 4 <= sec.raw_size else b"\0\0\0\0"
                    if word == b"\0\0\0\0":
                        pokes.append(f"{v:#x}=scr{8 + k % 8}+{(k // 8) * 0x400:#x}")
                        k += 1
            fret = 1 if re.fullmatch(r"(f32|float|f64|double)", ret) else 0
            rmask = (0, 0) if ret == "void" else (0xFF, 0) if re.fullmatch(r"(s8|u8|char|signed char|unsigned char|bool)", ret) \
                else (0xFFFF, 0) if re.fullmatch(r"(s16|u16|short|unsigned short)", ret) \
                else (0xFFFFFFFF, 0xFFFFFFFF) if re.fullmatch(r"(s64|u64)", ret) else (0xFFFFFFFF, 0)
            runner = (RUNNER.replace("@FUNC@", func).replace("@IMG_HI@", hex(hi)).replace("@SECTIONS@", secs)
                      .replace("@NARGS@", str(nslots(params))).replace("@CONV@", {"cdecl": "0", "stdcall": "1", "fastcall": "2"}[conv])
                      .replace("@FRET@", str(fret)).replace("@RMASK0@", hex(rmask[0])).replace("@RMASK1@", hex(rmask[1])).replace("@ARGS@", arg_code(params, a.args.split(",") if a.args else None))
                      .replace("@POKES@", poke_code(pokes)).replace("@RETAIL@", hex(addr[func])))
            runner = "".join(f"unsigned char {n}[0x10000] __attribute__((aligned(16)));\n" for n in missing) + runner
            (td / "run.c").write_text(runner)
            exe = td / "run"
            link = ["gcc", "-m32", "-O1", "-fno-pie", "-no-pie", "-w", "-Wl,-Ttext-segment=0x10000000",
                    str(td / "run.c"), str(obj), "-lm", "-o", str(exe), *[f"-Wl,--defsym,{n}={v:#x}" for n, v in defs]]
            r = subprocess.run(link, capture_output=True, text=True)
            if r.returncode:
                print(f"{func}: link failed\n{r.stderr[-2000:]}"); worst = 2; continue
            r = subprocess.run([str(exe), str(xbe), str(a.n), str(a.seed), "1" if a.v else "0"], capture_output=True, text=True)
            out = (r.stdout + r.stderr).strip()
            print(f"{func} ({src_path.relative_to(ROOT)}): {out.splitlines()[-1] if out else 'no output'}"
                  + (f"  [no retail address: {', '.join(missing)}]" if missing else ""))
            if a.v or r.returncode:
                for l in out.splitlines()[:-1][:20]:
                    print("   ", l)
            worst = max(worst, r.returncode)
    return worst


if __name__ == "__main__":
    raise SystemExit(main())
