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
    0x002DF234: "E9040801:partition ID is range outside.(adxf_ChkPrmPt)",
    0x002DF26C: "E9040802:'ptinfo' is NULL.(adxf_ChkPrmPt)",
    0x002DF298: "E02111001:can't create stm handle (adxf_CreateAdxFs)",
    0x002DF2D0: "E9081901:illigal parameter fname=null.(ADXF_Open)",
    0x002DF3E0: "E9040823:'adxf->stm' is NULL.(ADXF_Stop)",
    0x002DF40C: "E9040822:'adxf' is NULL.(ADXF_Stop)",
    0x002DF430: "E2092302:'adxf->stm' is NULL.(ADXF_StopNw)",
    0x002DF45C: "E2092301:'adxf' is NULL.(ADXF_StopNw)",
    0x002DF484: "E9040832:'adxf' is NULL.(ADXF_GetStat)",
    0x002DF4AC: "E9040828:'ptid' is range outside.",
    0x002DF4D0: "E9040828:'flid' is range outside.",
    0x002DF8DC: "E02080813 ADXT_Stop: parameter error",
    0x002DF904: "E02080814 ADXT_GetStat: parameter error",
    0x002DF984: "E02080823 ADXT_SetOutVol: parameter error",
    0x002DF9E0: "E02080846 ADXT_Pause: parameter error",
    0x002DFA08: "E02080847 ADXT_GetStatPause: parameter error",
    0x002DFB10: "E0071301 ADXT_EntryAfs: can't entry ",
    0x002DFB38: "E02080854 ADXT_GetNumFiles: parameter error",
    0x002DFB64: "E02080849 ADXT_ResetEntry: parameter error",
    0x002DFB90: "E8101202 ADXT_StartAfs: can't open ",
    0x002DFBB4: "E02080811 ADXT_StartAfs: parameter error",
    0x002DFBE0: "E02080809 ADXT_StartMem2: parameter error",
    0x002DFC0C: "E8101207: can't create sj (ADXT_StartMem)\n",
    0x002DFC70: "2103102:SVM:svm_unlock:lock type miss match.(type org=%d, type now=%d)",
    0x002DFCB8: "1051001:SVM_SetCbSvr:too many server function",
    0x002DFCE8: "1051002:SVM_DelCbSvr:illegal id",
    0x002DFD08: "2100801:SVM_SetCbSvrId:over write callback function.",
    0x002DFD40: "1071202:SVM_SetCbSvrId:illegal svtype",
    0x002DFD68: "1071201:SVM_SetCbSvrId:illegal id",
    0x00190E58: "%s:%s",
    0x002AFB94: " ",
    0x002E0204: "\nCVFS/XBOX Ver.2.35 Build:Feb 13 2004 21:08:02\n",
    0x002E0234: "cvFsClose #2:vtbl error",
    0x002E024C: "cvFsClose #1:handle error",
    0x002E0268: "cvFsTell #2:vtbl error",
    0x002E0280: "cvFsTell #1:handle error",
    0x002E029C: "cvFsSeek #2:vtbl error",
    0x002E02B4: "cvFsSeek #1:handle error",
    0x002E02D0: "cvFsReqRd #2:vtbl error",
    0x002E02E8: "cvFsReqRd #1:handle error",
    0x002E0304: "cvFsGetStat #2:vtbl error",
    0x002E0320: "cvFsGetStat #1:handle error",
    0x002E033C: "cvFsSetDefDev #2:unknown device name",
    0x002E0364: "cvFsSetDefDev #1:illegal device name",
    0x002E0420: "cvFsAddDev #3:failed added a device",
    0x002E0444: "cvFsAddDev #2:illegal I/F func name",
    0x002E0468: "cvFsAddDev #1:illegal device name",
    0x002E1304: "SJRBF Error",
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
