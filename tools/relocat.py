#!/usr/bin/env python3
"""Show a function's flagged relocations: the compiled instruction (with the
C's addend) beside the retail instruction at the same offset.

    python3 tools/relocat.py FUNC [FUNC ...]
"""

from __future__ import annotations

import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from objdiff import OBJ, OUT, function_ranges
from ogxb import coff
from ogxb.cap import Disassembler
from ogxb.paths import find_xbe
from ogxb.xbe import load


def main() -> int:
    img = load(find_xbe())
    report = json.loads(OUT.read_text())
    want = set(sys.argv[1:])
    with Disassembler() as d:
        for rel, entry in report.items():
            for f in entry["functions"]:
                if f["name"] not in want or "va" not in f:
                    continue
                obj = coff.read((OBJ / rel).read_bytes())
                for sec in obj.sections:
                    for sym, start, end in function_ranges(sec, obj) if sec.code else []:
                        if coff.undecorate(sym.name) != f["name"]:
                            continue
                        body = sec.data[start:end]
                        va = f["va"]
                        ours = {i.address: i for i in d.disasm(body, va)}
                        theirs = {i.address: i for i in d.disasm(img.bytes_at(va, len(body)), va)}
                        flagged = {int(n.split()[0][1:], 16) for n in f.get("notes", []) if n.startswith("+")}
                        print(f"== {f['name']} {va:#x} ({rel})")
                        for r in sec.relocs:
                            if not start <= r.offset < end:
                                continue
                            o = r.offset - start
                            if o not in flagged:
                                continue
                            ins = max((a for a in ours if a <= va + o), default=None)
                            t = obj.symbols[r.symbol]
                            addend = struct.unpack_from("<i", body, o)[0]
                            a, b = ours.get(ins), theirs.get(ins)
                            if a is None or b is None:
                                continue
                            print(f"  +{o:#x} {coff.undecorate(t.name)}{addend:+#x}: C   {a.mnemonic} {a.op_str}")
                            print(f"  {'':>{len(hex(o)) + 2}} {'':{len(coff.undecorate(t.name)) + len(f'{addend:+#x}')}}  XBE {b.mnemonic} {b.op_str}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
