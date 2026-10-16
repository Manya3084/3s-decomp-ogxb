"""Scanner and shader-header tests that do not need the disc."""

from __future__ import annotations

import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

from ogxb.cap import Disassembler
from ogxb.funcs import function_starts
from ogxb.strings import c_strings, imm_sites
from ogxb.xvs import decode_program, decode_slot, format_slot, parse_xvu


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


def _put(words: list[int], word: int, lo: int, width: int, value: int) -> None:
    words[word] |= (value & ((1 << width) - 1)) << lo


class XvuTest(unittest.TestCase):
    def test_header(self) -> None:
        blob = b"\x78\x20\x02\x00" + bytes(32)
        self.assertEqual(parse_xvu(blob), 2)
        self.assertIsNone(parse_xvu(blob + b"\x00"))
        self.assertIsNone(parse_xvu(b"\x00\x00\x01\x00" + bytes(16)))

    def test_mov_from_input(self) -> None:
        # MOV R0.xyzw, v0.xyzw, FINAL. Source A is an input. Identity swizzle
        # is selectors x,y,z,w packed at the bottom of word 1.
        raw = bytes.fromhex("00000000 1b002000 00000008 0100000f")
        slot = decode_slot(raw)
        self.assertEqual(slot.mac, 1)
        self.assertEqual(slot.ilu, 0)
        self.assertEqual(slot.a.mux, 2)
        self.assertEqual(slot.a.swizzle, (0, 1, 2, 3))
        self.assertEqual(slot.mac_mask, 0xF)
        self.assertEqual(slot.dest, 0)
        self.assertEqual(slot.final, 1)
        self.assertTrue(slot.mac_writes_dest)
        self.assertIsNone(slot.ilu_dest)
        self.assertEqual(format_slot(0, slot), "  0: MOV  R0.xyzw v0.xyzw FINAL")

    def test_paired_mac_and_ilu(self) -> None:
        # MAD R5.xyzw, -R10.zyxw, c[96+A0.x], oPos and RCC R1.x. The ILU
        # source is R12, which reads as oPos. That register number is split
        # across word 2 and word 3. The output is oPos.xyz from the MAC, and
        # FINAL is clear. A paired ILU write targets R1 even though the dest
        # field says R5. The same slot with dest R1 drops the MAC write.
        words = [0, 0, 0, 0]
        _put(words, 1, 25, 3, 3)  # RCC
        _put(words, 1, 21, 4, 4)  # MAD
        _put(words, 1, 13, 8, 96)
        _put(words, 1, 9, 4, 3)
        _put(words, 1, 8, 1, 1)  # negate A
        _put(words, 1, 6, 2, 2)  # A.x from z
        _put(words, 1, 4, 2, 1)  # A.y from y
        _put(words, 1, 2, 2, 0)  # A.z from x
        _put(words, 1, 0, 2, 3)  # A.w from w
        _put(words, 2, 28, 4, 10)  # A register
        _put(words, 2, 26, 2, 1)  # A from R
        _put(words, 2, 11, 2, 3)  # B from the constant file
        _put(words, 2, 17, 2, 3)
        _put(words, 2, 19, 2, 2)
        _put(words, 2, 21, 2, 1)
        _put(words, 2, 23, 2, 0)
        _put(words, 2, 0, 2, 3)  # C register 12, high half (R12 == oPos)
        _put(words, 3, 30, 2, 0)  # C register 12, low half
        _put(words, 3, 28, 2, 1)  # C from R
        _put(words, 2, 8, 2, 0)
        _put(words, 2, 6, 2, 0)
        _put(words, 2, 4, 2, 0)
        _put(words, 2, 2, 2, 0)  # C swizzle xxxx
        _put(words, 3, 24, 4, 0xF)
        _put(words, 3, 20, 4, 5)
        _put(words, 3, 16, 4, 0x8)  # ILU .x
        _put(words, 3, 12, 4, 0xE)  # output .xyz
        _put(words, 3, 11, 1, 1)
        _put(words, 3, 3, 8, 0)  # oPos
        _put(words, 3, 1, 1, 1)  # A0.x
        raw = struct.pack("<4I", *words)
        slot = decode_slot(raw)
        self.assertEqual(slot.const_index, 96)
        self.assertEqual(slot.input_index, 3)
        self.assertEqual(slot.a.neg, 1)
        self.assertEqual(slot.a.reg, 10)
        self.assertEqual(slot.a.swizzle, (2, 1, 0, 3))
        self.assertEqual(slot.b.mux, 3)
        self.assertEqual(slot.c.reg, 12)
        self.assertEqual(slot.c.mux, 1)
        self.assertEqual(slot.c.swizzle, (0, 0, 0, 0))
        self.assertEqual(slot.ilu_dest, 1)
        self.assertTrue(slot.mac_writes_dest)
        self.assertEqual(slot.out_addr, 0)
        self.assertEqual(slot.a0x, 1)
        self.assertEqual(slot.final, 0)
        self.assertEqual(
            format_slot(4, slot),
            "  4: MAD  R5.xyzw | RCC  R1.x | oPos.xyz from MAC "
            "-R10.zyxw, c[96+A0.x].xyzw, oPos.xxxx A0X",
        )
        forced = (words[3] & ~(0xF << 20)) | (1 << 20)
        dropped = decode_slot(struct.pack("<4I", words[0], words[1], words[2], forced))
        self.assertEqual(dropped.dest, 1)
        self.assertFalse(dropped.mac_writes_dest)
        self.assertEqual(dropped.ilu_dest, 1)

    def test_program_stops_at_the_header_count(self) -> None:
        one = bytes.fromhex("00000000 1b002000 00000008 0100000f")
        blob = b"\x78\x20\x01\x00" + one
        slots = decode_program(blob)
        self.assertIsNotNone(slots)
        assert slots is not None
        self.assertEqual(len(slots), 1)
        self.assertIsNone(decode_program(blob + b"\x00"))
        self.assertEqual(decode_program(b"\x78\x20\x00\x00"), [])
        with self.assertRaises(ValueError):
            decode_slot(b"")

    def test_arl_skips_the_temporary(self) -> None:
        words = [0, 0, 0, 0]
        _put(words, 1, 21, 4, 13)
        _put(words, 1, 6, 2, 0)
        _put(words, 1, 4, 2, 1)
        _put(words, 1, 2, 2, 2)
        _put(words, 1, 0, 2, 3)
        _put(words, 2, 28, 4, 4)
        _put(words, 2, 26, 2, 1)
        _put(words, 3, 24, 4, 0xF)
        _put(words, 3, 20, 4, 2)
        slot = decode_slot(struct.pack("<4I", *words))
        self.assertEqual(slot.dest, 2)
        self.assertFalse(slot.mac_writes_dest)
        self.assertEqual(format_slot(0, slot), "  0: ARL  R4.xyzw")

    def test_ilu_alone_uses_the_dest_field(self) -> None:
        words = [0, 0, 0, 0]
        _put(words, 1, 25, 3, 1)
        _put(words, 2, 8, 2, 0)
        _put(words, 2, 6, 2, 1)
        _put(words, 2, 4, 2, 2)
        _put(words, 2, 2, 2, 3)
        _put(words, 3, 28, 2, 2)
        _put(words, 3, 20, 4, 4)
        _put(words, 3, 16, 4, 0xF)
        slot = decode_slot(struct.pack("<4I", *words))
        self.assertEqual(slot.ilu_dest, 4)
        self.assertFalse(slot.mac_writes_dest)
        self.assertEqual(format_slot(1, slot), "  1: NOP  | MOV  R4.xyzw v0.xyzw")


if __name__ == "__main__":
    unittest.main()
