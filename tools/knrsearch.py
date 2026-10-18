#!/usr/bin/env python3
"""Search for definitions that were old-style (K&R) in Capcom's source.

An old-style definition gives the callers in its file no prototype, so they
sign- or zero-extend each narrow argument to int; a prototyped s16 or u8
parameter lets them pass only the low bits. For every definition in src/
with an 8- or 16-bit integer parameter, this builds its file with that
definition old-style (build_c.old_style, as config/sf33rd/knr.txt does) and
compares the file's functions with the current build/objdiff.json. A
definition is kept when the file then matches more functions and loses
none; the kept ones of a file are then tried together.

    python3 tools/knrsearch.py [--apply] [-j N]

--apply adds the kept definitions to config/sf33rd/knr.txt. Run
tools/build_c.py and tools/objdiff.py first.
"""

from __future__ import annotations

import argparse
import itertools
import json
import re
import shutil
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import build_c
from fieldsign import Tree
from objdiff import OUT, check_object
from ogxb.paths import ROOT

WORK = ROOT / "build" / "knrsearch"
NARROW = re.compile(r"^(?:const\s+)?(?:s8|u8|s16|u16|char|short|unsigned char|unsigned short|Sint8|Uint8|Sint16|Uint16)\s+\w+$")
SIMPLE = re.compile(r"^(?:const\s+)?[A-Za-z_][\w ]*?\**\s*\w+$")


def candidates(text: str, have: set[str]) -> list[str]:
    out = []
    live = re.sub(r"^#if 0\b.*?^#endif\b", "", text, flags=re.M | re.S)
    for m in build_c.DEFINITION.finditer(live):
        name = re.search(r"(\w+)\s*$", m.group(1)).group(1)
        if name in ("if", "while", "for", "switch") or name in have:
            continue
        params = [re.sub(r"/\*.*?\*/", "", p).strip() for p in m.group(2).split(",")]
        if not params[0] or params == ["void"] or build_c.FLOATISH.search(m.group(2)):
            continue
        if not all(SIMPLE.match(p) for p in params) or not any(NARROW.match(p) for p in params):
            continue
        # only a definition its own file calls can change anything
        if len(re.findall(r"\b" + re.escape(name) + r"\s*\(", live)) < 2:
            continue
        out.append(name)
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("-j", type=int, default=24)
    a = ap.parse_args()
    report = json.loads(OUT.read_text())
    base = {f"{o}|{f['name']}": f["status"] for o, r in report.items() for f in r["functions"] if "va" in f}
    tree = Tree(a.j)
    have = build_c.knr_map()
    trials = []
    for src in tree.files:
        rel = src.relative_to(ROOT).as_posix()
        rel_o = src.relative_to(build_c.SRC).with_suffix(".obj").as_posix()
        if not any(k.startswith(rel_o + "|") and s != "match" for k, s in base.items()):
            continue
        for name in candidates(src.read_text(errors="replace"), have.get(rel, set())):
            trials.append((src, [name]))
    print(f"{len(trials)} candidates", flush=True)
    counter = itertools.count()

    def build(src: Path, names: list[str]) -> tuple[list[str], list[str]]:
        d = WORK / f"t{next(counter)}"
        rel = src.relative_to(ROOT).as_posix()
        rel_o = src.relative_to(build_c.SRC).with_suffix(".obj").as_posix()
        prepared, _ = build_c.prepare_text(src.read_text(errors="replace"), rel)
        prepared = build_c.old_style(prepared, set(names), [0])
        c = d / src.name
        c.parent.mkdir(parents=True, exist_ok=True)
        c.write_text(f'#line 1 "{src}"\n' + prepared)
        o = d / src.with_suffix(".obj").name
        subprocess.run(["wine", str(tree.cl), *build_c.COMMON, *build_c.flags_for(src),
                        "/Fo" + build_c.wine_path(o), build_c.wine_path(c)], env=tree.env, capture_output=True)
        if not o.is_file():
            shutil.rmtree(d, ignore_errors=True)
            return [], ["(no object)"]
        res = {f"{rel_o}|{f['name']}": f["status"] for f in check_object(o, tree.ck, False)["functions"] if "va" in f}
        shutil.rmtree(d, ignore_errors=True)
        scope = {k: s for k, s in base.items() if k.startswith(rel_o + "|")}
        gained = [k for k, s in res.items() if s == "match" and scope.get(k) != "match"]
        lost = [k for k, s in scope.items() if s == "match" and res.get(k) != "match"]
        return gained, lost

    kept: dict[Path, list[str]] = {}
    with ThreadPoolExecutor(a.j) as pool:
        for (src, names), (gained, lost) in zip(trials, pool.map(lambda t: build(*t), trials)):
            if gained and not lost:
                kept.setdefault(src, []).extend(names)
                print(f"{src.relative_to(ROOT)} {names[0]}: +{len(gained)}", flush=True)
    final: dict[Path, tuple[list[str], int]] = {}
    for src, names in kept.items():
        gained, lost = build(src, names)
        while lost and len(names) > 1:
            # together they lose a match: keep the best one alone
            best = max(names, key=lambda n: len(build(src, [n])[0]))
            names = [best]
            gained, lost = build(src, names)
        if gained and not lost:
            final[src] = (names, len(gained))
    total = sum(n for _, n in final.values())
    print(f"kept {sum(len(v[0]) for v in final.values())} definitions in {len(final)} files, +{total} matches")
    if a.apply and final:
        with open(build_c.KNR, "a") as f:
            for src, (names, _) in sorted(final.items()):
                f.write(f"{src.relative_to(ROOT).as_posix()} {' '.join(names)}\n")
        print("written:", build_c.KNR.relative_to(ROOT))
    return 0


if __name__ == "__main__":
    sys.exit(main())
