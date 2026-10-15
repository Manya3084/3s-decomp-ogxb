"""Scanner and shader-header tests that do not need the disc."""

from __future__ import annotations

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

from ogxb.cap import Disassembler
from ogxb.funcs import function_starts
from ogxb.strings import c_strings, imm_sites
from ogxb.xvs import parse_xvu


class FuncsTest(unittest.TestCase):
    def test_two_padded_functions(self) -> None:
        # push ebp / mov ebp, esp / xor eax, eax / pop ebp / ret / int3
        # push ebp / mov ebp, esp / inc eax / pop ebp / ret
        blob = bytes(
            [
                0x55, 0x8B, 0xEC, 0x33, 0xC0, 0x5D, 0xC3, 0xCC,
                0x55, 0x8B, 0xEC, 0x40, 0x5D, 0xC3,
            ]
        )
        with Disassembler() as dis:
            starts = function_starts(blob, 0x11000, 0x11000, dis)
        self.assertEqual(starts, [0x11000, 0x11008])

    def test_disasm_keeps_zero_immediates(self) -> None:
        # mov eax, 0x10000
        blob = bytes([0xB8, 0x00, 0x00, 0x01, 0x00, 0xC3])
        with Disassembler() as dis:
            insns = dis.disasm(blob, 0x11000, 1)
        self.assertEqual(insns[0].mnemonic, "mov")
        self.assertIn("0x10000", insns[0].op_str)
        self.assertEqual(insns[0].size, 5)


class StringTest(unittest.TestCase):
    def test_push_site(self) -> None:
        text = b"\x90\x68\x20\x00\x01\x00\xc3"
        sites = imm_sites(text, 0x11000)
        self.assertEqual(sites[0x10020], [(0x11001, "push")])
        blob = b"\x00Game.c\x00"
        self.assertEqual(c_strings(blob, 0x20000), [(0x20001, "Game.c")])


class XvuTest(unittest.TestCase):
    def test_header(self) -> None:
        blob = b"\x78\x20\x02\x00" + bytes(32)
        self.assertEqual(parse_xvu(blob), 2)
        self.assertIsNone(parse_xvu(blob + b"\x00"))
        self.assertIsNone(parse_xvu(b"\x00\x00\x01\x00" + bytes(16)))


if __name__ == "__main__":
    unittest.main()
