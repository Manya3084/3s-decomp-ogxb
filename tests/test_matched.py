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
    0x0025FB2C: "\nMAIN TITLE\n\n",
    0x002E1294: "E02110501 adxstmf_stat_exec: can't open ",
    0x002DFE60: "E0092901:fname is null.(wxCiGetFileSize)",
    0x002E0590: "E01100301:fname is null.(mfCiOpen)",
    0x002E056C: "E01100302:rw is illigal.(mfCiOpen)",
    0x002E053C: "E01100303:not enough handle resource.(mfCiOpen)",
    0x002E04FC: "E01100308:length of '%s' is not 17 bytes.(mfci_get_adr_size)",
    0x002E04C0: "E01100309:illegal file name format '%s'(mfci_get_adr_size)",
    0x002E0EA0: "E1229:IDirectSoundBuffer_Stop return error in mwSndStop",
    0x002E0700: "E1205:Illegal parameter (MWRNA=NULL)",
    0x002E0770: "E1211:mwRnaSetNumChan Illegal parameter(NCH>MAXNCH)",
    0x002E0728: "E1213:mwlRnaAddWrPos rna->sj=NULL",
    0x002E074C: "E1212:mwlRnaStartTrans rna->sj=NULL",
    0x002E07A8: "E1215:mwRnaCalcSfreq Illegal parameter(trnsps or(and) detune is too big.)",
    0x002E0808: "E1201:mwRnaCreate Illegal parameter (MAXNCH)",
    0x002E0838: "E1204:mwRnaCreate Cannot open MWSND",
    0x002E085C: "E1203:mwRnaCreate Not enough instance (MWRNA)",
    0x002E088C: "E1202:mwRnaCreate Illegal parameter (SJ)",
    0x002E0F6C: "E1221:Illigal parameter(MAXNCH) in mwSndOpenPort",
    0x002E0FA0: "E1222:Not enough instance(MWSND) in mwSndOpenPort",
    0x002E0FD4: "E1227:IDirectSoundBuffer_SetCurrentPosition return error",
    0x002E1010: "E1228:IDirectSoundBuffer_SetFrequency return error in mwSndPlay",
    0x002E1050: "E1225:dsb(member in handle) is NULL",
    0x002E10A0: "E1230:IDirectSoundBuffer_SetVolume return error in mwSndSetVol",
    0x002E10E0: "E1232:IDirectSoundBuffer_SetPan return error in mwSndSetBalance",
    0x002E01DC: "E0092908:fname is null.(wxCiOpen)",
    0x002E01B8: "E0092909:rw is illigal.(wxCiOpen)",
    0x002E0188: "E0092910:not enough handle resource.(wxCiOpen)",
    0x002DFE8C: "E0092912:handl is null.",
    0x002DFF28: "E0092913:nsct < 0.(wxCiReqRd)",
    0x002DFEA4: "E0092914:buf is null.(wxCiReqRd)",
    0x002DFEC8: "E0109151:illegal read size.",
    0x002DFEE4: "E0109153:illegal buffer alignment.",
    0x002DFF08: "E0109152:illegal seek position.",
    0x002E11F8: "E0109075:can not open '%s'.(wxfic_cache_file)",
    0x002E1228: "E0109076:work is in short.",
    0x002E0630: "E01100307:handl is null.",
    0x002E0610: "E01100308:nsct < 0.(mfCiReqRd)",
    0x002E05EC: "E01100309:buf is null.(mfCiReqRd)",
    0x002DF234: "E9040801:partition ID is range outside.(adxf_ChkPrmPt)",
    0x002DF26C: "E9040802:'ptinfo' is NULL.(adxf_ChkPrmPt)",
    0x002DF298: "E02111001:can't create stm handle (adxf_CreateAdxFs)",
    0x002DF2D0: "E9081901:illigal parameter fname=null.(ADXF_Open)",
    0x002DF304: "E9040821:'sj' must be NULL.(ADXF_ReadNw32)",
    0x002DF330: "E9040818:'buf' is NULL.(ADXF_ReadNw32)",
    0x002DF358: "E9040817:'nsct' is negative.(ADXF_ReadNw32)",
    0x002DF384: "E9040816:'adxf' is NULL.(ADXF_ReadNw32)",
    0x002DF3AC: "E0120401:'buf' isn't 4byte alignment.(ADXF_ReadNw)",
    0x002DF3E0: "E9040823:'adxf->stm' is NULL.(ADXF_Stop)",
    0x002DF40C: "E9040822:'adxf' is NULL.(ADXF_Stop)",
    0x002DF430: "E2092302:'adxf->stm' is NULL.(ADXF_StopNw)",
    0x002DF45C: "E2092301:'adxf' is NULL.(ADXF_StopNw)",
    0x002DF484: "E9040832:'adxf' is NULL.(ADXF_GetStat)",
    0x002DF4AC: "E9040828:'ptid' is range outside.",
    0x002DF4D0: "E9040828:'flid' is range outside.",
    0x002DF5DC: "E9040804:can't open file.(load partition)",
    0x002DF608: "E0042401:multi-load partition.(load partition)",
    0x002DF638: "E1110702:'tbsize' <= 0.(load partition)",
    0x002DF660: "E1110701:'tmpbuf' is null.(load partition)",
    0x002DF8DC: "E02080813 ADXT_Stop: parameter error",
    0x002DF904: "E02080814 ADXT_GetStat: parameter error",
    0x002DF92C: "E02080815 ADXT_GetTime: parameter error",
    0x002DF958: "E02080820 ADXT_GetNumChan: parameter error",
    0x002DF984: "E02080823 ADXT_SetOutVol: parameter error",
    0x002DF9B0: "E02080844 ADXT_ClearErrCode: parameter error",
    0x002DF9E0: "E02080846 ADXT_Pause: parameter error",
    0x002DFA08: "E02080847 ADXT_GetStatPause: parameter error",
    0x002DFA38: "E02080805 ADXT_Destroy: parameter error",
    0x002DFA60: "E02080812 ADXT_StartSj: parameter error",
    0x002DFA88: "E02080804 ADXT_Create: parameter error",
    0x002DFAB0: "E03100801 ADXT_Create: Too many handles.\n",
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
    0x002E0400: "cvFsOpen #1:illegal file name",
    0x002E03DC: "cvFsOpen #3:failed handle alloced",
    0x002E03BC: "cvFsOpen #4:device not found",
    0x002E038C: "cvFsOpen #5:vtbl error",
    0x002E03A4: "cvFsOpen #6:open failed",
    0x002E033C: "cvFsSetDefDev #2:unknown device name",
    0x002E0364: "cvFsSetDefDev #1:illegal device name",
    0x002E0420: "cvFsAddDev #3:failed added a device",
    0x002E0444: "cvFsAddDev #2:illegal I/F func name",
    0x002E0468: "cvFsAddDev #1:illegal device name",
    0x002E1304: "SJRBF Error",
    0x002E13C0: "SJMEM Error",
    0x002E1410: "E0002: Not enough instance (LSC_Create)\n",
    0x002E143C: "E0001: Illigal parameter=sj (LSC_Create)\n",
    0x002E1468: "E0011: Illigal parameter fname=%s\n",
    0x002E148C: "E0003: Illigal parameter lsc=NULL\n",
    0x002E1588: "\nLSC/XBOX Ver.2.15 Build:Feb 13 2004 21:08:01\n",
    0x002E1264: "\nADXF/XBOX Ver.7.13 Build:Feb 13 2004 21:08:38\n",
    0x002DFAE0: "\nADXT/XBOX Ver.9.15 Build:Feb 13 2004 21:08:09\n",
    0x002E14B0: "E0010: Illigal parameter min=%d\n",
    0x002E13CC: "E03010901 ADXB_DecodeHeader: ",
    0x002E13EC: "Can not decode this file format.",
    0x002E1E58: "%08X",
    0x002E1E60: "E1060101 ADXB_DecodeHeaderAdx: ",
    0x002E1E80: "can't play AHX data by this handle",
    0x002E1508: "E9081001 adxt_stat_decinfo: can't play this number of channels",
    0x002E1548: "E02080842 ADXT_ExecHndl: parameter error",
    0x002DF77C: "E2003050210 : NULL pointer is specified.",
    0x002DF748: "E2003052112 : The parameter 'trno' is out of range.",
    0x002DF71C: "E2003050209 : NULL pointer is specified.",
    0x002DF6F0: "E2003110701 : NULL pointer is specified.",
    0x002DF6C0: "E2003110703 : Illegal speaker ID is specified.",
    0x002DF7A8: "E2003050211 : NULL pointer is specified.",
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
