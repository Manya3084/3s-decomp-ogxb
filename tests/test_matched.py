"""Lock the matched sample to the retail sf33rd.xbe bytes.

The name table is checked with or without the disc. The byte compare runs
only when SF33RD_XBE or xbe.path points at the retail file.
"""

from __future__ import annotations

import re
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

from matched_bytes import MATCHED
from ogxb.paths import ROOT, find_xbe
from ogxb.xbe import load

FUNCS = ROOT / "config" / "sf33rd" / "symbols" / "funcs.txt"
NAME = re.compile(
    r"^([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;.*\btype:func\b.*\bsize:(0x[0-9A-Fa-f]+)"
)

STRINGS = {
    0x002390DC: "- for zlib -",
    0x0026511C: "- for Ramcnt -",
    0x002657B4: "@CAPCOM CO., LTD. 1999, 2004 ALL RIGHTS RESERVED.",
    0x0026577C: "@CAPCOM U.S.A., INC. 1999, 2004 ALL RIGHTS RESERVED.",
    0x0026575C: "@CAPCOM CO., LTD. 1999, 2004,",
    0x002DF904: "E02080814 ADXT_GetStat: parameter error",
    0x002DFA08: "E02080847 ADXT_GetStatPause: parameter error",
    0x002DF9E0: "E02080846 ADXT_Pause: parameter error",
    0x002DF234: "E9040801:partition ID is range outside.(adxf_ChkPrmPt)",
    0x002DF26C: "E9040802:'ptinfo' is NULL.(adxf_ChkPrmPt)",
    0x002DFCB8: "1051001:SVM_SetCbSvr:too many server function",
}


def funcs_table() -> dict[str, tuple[int, int]]:
    found = {}
    for line in FUNCS.read_text().splitlines():
        match = NAME.match(line.strip())
        if match:
            found[match.group(1)] = (int(match.group(2), 16), int(match.group(3), 16))
    return found


class MatchedSampleTest(unittest.TestCase):
    def test_funcs_txt_matches_the_sample(self) -> None:
        table = funcs_table()
        self.assertEqual(set(table), {item[0] for item in MATCHED})
        for name, va, size, _imms, _blob in MATCHED:
            self.assertEqual(table[name], (va, size))

    def test_retail_bytes(self) -> None:
        path = find_xbe()
        if path is None or not path.is_file():
            self.skipTest("sf33rd.xbe not configured")
        image = load(path)
        for va, text in STRINGS.items():
            self.assertEqual(image.cstr(va), text)
        for name, va, size, imms, blob in MATCHED:
            data = image.bytes_at(va, size)
            self.assertEqual(data.hex(), blob, name)
            for imm in imms:
                self.assertIn(imm.to_bytes(4, "little"), data, f"{name} missing {imm:#x}")


if __name__ == "__main__":
    unittest.main()
