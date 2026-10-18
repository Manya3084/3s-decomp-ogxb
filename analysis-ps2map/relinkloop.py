# relinkloop.py [--rounds N] : name functions from the relink check until
# no new name turns up.
#
# Each round runs relinkdata.py, writedata.py (data names into data.txt) and
# relinkfuncs.py --apply, regenerates the
# generated ports that define a newly located name or call it by its
# sub_XXXXXXXX placeholder, and rebuilds (build_c.py, objdiff.py), so the
# callers that now match name the functions they call in turn.
import os as _os, sys as _sys
_sys.path.insert(0, _os.path.dirname(_os.path.abspath(__file__)))
from ps2paths import OG
import glob, os, re, subprocess, sys

SP = OG + "/analysis-ps2map"
rounds = int(sys.argv[sys.argv.index("--rounds") + 1]) if "--rounds" in sys.argv else 10


def run(*cmd):
    r = subprocess.run(list(cmd), cwd=OG, capture_output=True, text=True)
    if r.returncode:
        sys.exit(f"{' '.join(cmd)} failed:\n{r.stdout[-2000:]}{r.stderr[-2000:]}")
    return r.stdout


def generated():
    for p in glob.glob(OG + "/src/sf33rd/Source/**/*.c", recursive=True):
        t = open(p, errors="replace").read()
        if "Ported from the PS2" in t[:4000]:
            yield p, t


for rnd in range(rounds):
    run("python3", SP + "/relinkdata.py")
    run("python3", SP + "/writedata.py")
    out = run("python3", SP + "/relinkfuncs.py", "--apply")
    m = re.search(r"new locations \d+ (\[.*\])", out)
    new = [x.split("=") for x in eval(m[1])] if m else []
    f = re.search(r"folds \d+ (\{.*\})", out)
    folds = eval(f[1]) if f else {}
    if not new and not folds:
        print(f"round {rnd + 1}: nothing new")
        break
    names = {n for n, _ in new} | {n for v in folds.values() for n in v}
    subs = {f"sub_{int(a, 16):08X}" for _, a in new} | {f"sub_{int(k, 16):08X}" for k in folds}
    word = re.compile(r"\b(" + "|".join(map(re.escape, sorted(names | subs))) + r")\b")
    files = sorted(os.path.relpath(p, OG + "/src/sf33rd/Source") for p, t in generated() if word.search(t))
    print(f"round {rnd + 1}: {len(new)} new, {len(folds)} folds; regenerating {len(files)} files", flush=True)
    if files:
        run("python3", SP + "/regen.py", *files)
    run("python3", OG + "/tools/build_c.py", "-j", "24")
    print("  " + run("python3", OG + "/tools/objdiff.py").strip().splitlines()[-2], flush=True)
