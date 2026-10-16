"""SPIR-V emission for vertex slots and register combiners.

These tests build modules from synthetic programs and from slots the
decoder already accepts. spirv-val checks the Vulkan 1.0 rules. A final
combiner whose inputs are zero is still the combiner formula, which is
black; the tests do not rewrite it to r0.
"""

from __future__ import annotations

import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

from ogxb.spv import MAGIC, VERSION
from ogxb.spirv import combiner_spirv, emit_vertex, validate_spirv, vertex_spirv
from ogxb.xpu import parse_xpu
from ogxb.xvs import Operand, Slot, decode_slot, format_slot

OP_EXEC_MODE = 16
OP_VARIABLE = 59
OP_DECORATE = 71
OP_EXT_INST = 12
OP_SAMPLE = 87
OP_ACCESS = 65
OP_FNEG = 127
OP_FMUL = 133
OP_FADD = 129
OP_KILL = 252
CLASS_UNIFORM_CONSTANT = 0
CLASS_INPUT = 1
CLASS_UNIFORM = 2
CLASS_OUTPUT = 3
DECO_BUILTIN = 11
DECO_BINDING = 33
DECO_SET = 34
GLSL_TRUNC = 3
GLSL_FLOOR = 8
GLSL_FCLAMP = 43


def _words(blob: bytes):
    data = struct.unpack("<" + "I" * (len(blob) // 4), blob)
    index = 5
    while index < len(data):
        word = data[index]
        count = word >> 16
        if count < 1 or index + count > len(data):
            raise AssertionError("truncated instruction")
        yield word & 0xFFFF, data[index + 1 : index + count]
        index += count


def _ops(blob: bytes) -> set[int]:
    return {op for op, _operands in _words(blob)}


def _ext(blob: bytes) -> set[int]:
    found = set()
    for op, operands in _words(blob):
        if op == OP_EXT_INST and len(operands) >= 4:
            found.add(operands[3])
    return found


def _storage(blob: bytes) -> dict[int, int]:
    counts: dict[int, int] = {}
    for op, operands in _words(blob):
        if op == OP_VARIABLE:
            storage = operands[2]
            counts[storage] = counts.get(storage, 0) + 1
    return counts


def _pairs(blob: bytes) -> list[tuple[int, int]]:
    deco: dict[int, dict[int, int]] = {}
    for op, operands in _words(blob):
        if op == OP_DECORATE and len(operands) >= 3:
            deco.setdefault(operands[0], {})[operands[1]] = operands[2]
    pairs = []
    for item in deco.values():
        if DECO_BINDING in item and DECO_SET in item:
            pairs.append((item[DECO_SET], item[DECO_BINDING]))
    return sorted(pairs)


def _builtins(blob: bytes) -> set[int]:
    found = set()
    for op, operands in _words(blob):
        if op == OP_DECORATE and len(operands) >= 3 and operands[1] == DECO_BUILTIN:
            found.add(operands[2])
    return found


def _check(test: unittest.TestCase, blob: bytes) -> None:
    test.assertEqual(struct.unpack_from("<II", blob, 0), (MAGIC, VERSION))
    error = validate_spirv(blob)
    test.assertIsNone(error, error)


def _put(words: list[int], word: int, lo: int, width: int, value: int) -> None:
    words[word] |= (value & ((1 << width) - 1)) << lo


def _operand(mux: int, reg: int = 0, swizzle: tuple[int, int, int, int] = (0, 1, 2, 3), neg: int = 0) -> Operand:
    return Operand(neg, swizzle, reg, mux)


def _slot(**kwargs) -> Slot:
    base = dict(
        word0=0, ilu=0, mac=0, const_index=0, input_index=0,
        a=_operand(0), b=_operand(0), c=_operand(0),
        mac_mask=0, dest=0, ilu_mask=0, out_mask=0, out_is_reg=1,
        out_addr=0, out_from_ilu=0, a0x=0, final=0,
    )
    base.update(kwargs)
    return Slot(**base)


def _xpu(words: dict[int, int]) -> bytes:
    packed = [0] * 60
    for index, value in words.items():
        packed[index] = value
    return b"PSB0" + struct.pack("<60I", *packed)


class VertexSpirvTest(unittest.TestCase):
    def test_rejected(self) -> None:
        self.assertIsNone(vertex_spirv(b""))
        self.assertIsNone(vertex_spirv(b"\x78\x20\x01\x00"))

    def test_mov_uses_v0_and_the_viewport(self) -> None:
        raw = bytes.fromhex("00000000 1b002000 00000008 0100000f")
        blob = vertex_spirv(b"\x78\x20\x01\x00" + raw)
        self.assertIsNotNone(blob)
        assert blob is not None
        _check(self, blob)
        self.assertEqual(_storage(blob)[CLASS_INPUT], 2)
        self.assertEqual(_storage(blob)[CLASS_UNIFORM], 1)
        self.assertNotIn(CLASS_UNIFORM_CONSTANT, _storage(blob))
        self.assertEqual(_pairs(blob), [(0, 1)])
        self.assertEqual(_builtins(blob), {0, 1})
        self.assertIn(GLSL_TRUNC, _ext(blob))
        self.assertNotIn(OP_EXEC_MODE, _ops(blob))

    def test_paired_mad_rcc_reads_a_constant(self) -> None:
        words = [0, 0, 0, 0]
        _put(words, 1, 25, 3, 3)
        _put(words, 1, 21, 4, 4)
        _put(words, 1, 13, 8, 96)
        _put(words, 1, 9, 4, 3)
        _put(words, 1, 8, 1, 1)
        _put(words, 1, 6, 2, 2)
        _put(words, 1, 4, 2, 1)
        _put(words, 1, 2, 2, 0)
        _put(words, 1, 0, 2, 3)
        _put(words, 2, 28, 4, 10)
        _put(words, 2, 26, 2, 1)
        _put(words, 2, 11, 2, 3)
        _put(words, 2, 17, 2, 3)
        _put(words, 2, 19, 2, 2)
        _put(words, 2, 21, 2, 1)
        _put(words, 2, 23, 2, 0)
        _put(words, 2, 0, 2, 3)
        _put(words, 3, 30, 2, 0)
        _put(words, 3, 28, 2, 1)
        _put(words, 2, 8, 2, 0)
        _put(words, 2, 6, 2, 0)
        _put(words, 2, 4, 2, 0)
        _put(words, 2, 2, 2, 0)
        _put(words, 3, 24, 4, 0xF)
        _put(words, 3, 20, 4, 5)
        _put(words, 3, 16, 4, 0x8)
        _put(words, 3, 12, 4, 0xE)
        _put(words, 3, 11, 1, 1)
        _put(words, 3, 3, 8, 0)
        _put(words, 3, 1, 1, 1)
        slot = decode_slot(struct.pack("<4I", *words))
        self.assertEqual(
            format_slot(4, slot),
            "  4: MAD  R5.xyzw | RCC  R1.x | oPos.xyz from MAC "
            "-R10.zyxw, c[96+A0.x].xyzw, oPos.xxxx A0X",
        )
        blob = emit_vertex([slot])
        _check(self, blob)
        self.assertEqual(_storage(blob)[CLASS_INPUT], 1)
        self.assertEqual(_pairs(blob), [(0, 0), (0, 1)])
        self.assertIn(OP_FMUL, _ops(blob))
        self.assertIn(OP_FADD, _ops(blob))
        self.assertIn(OP_FNEG, _ops(blob))
        self.assertIn(OP_ACCESS, _ops(blob))
        self.assertIn(GLSL_FCLAMP, _ext(blob))
        forced = (words[3] & ~(0xF << 20)) | (1 << 20)
        dropped = decode_slot(struct.pack("<4I", words[0], words[1], words[2], forced))
        self.assertFalse(dropped.mac_writes_dest)
        dropped_blob = emit_vertex([dropped])
        _check(self, dropped_blob)

    def test_arl_then_constant(self) -> None:
        arl = _slot(mac=13, a=_operand(2), input_index=1, mac_mask=0xF, dest=2)
        mov = _slot(mac=1, a=_operand(3), const_index=4, a0x=1, mac_mask=0xF, dest=0, final=1)
        blob = emit_vertex([arl, mov])
        _check(self, blob)
        self.assertIn(GLSL_FLOOR, _ext(blob))
        self.assertIn(OP_ACCESS, _ops(blob))
        self.assertEqual(_storage(blob)[CLASS_INPUT], 2)

    def test_slots_after_final_are_ignored(self) -> None:
        done = _slot(mac=1, a=_operand(2), input_index=0, mac_mask=0xF, dest=0, final=1)
        later = _slot(
            mac=4,
            a=_operand(2),
            b=_operand(3),
            c=_operand(0),
            input_index=3,
            const_index=7,
            mac_mask=0xF,
            dest=1,
        )
        blob = emit_vertex([done, later])
        _check(self, blob)
        self.assertEqual(_storage(blob)[CLASS_INPUT], 2)
        self.assertEqual(_pairs(blob), [(0, 1)])


class CombinerSpirvTest(unittest.TestCase):
    def test_rejected(self) -> None:
        self.assertIsNone(combiner_spirv(b"PSB0"))
        self.assertIsNone(combiner_spirv(b"XXXX" + bytes(240)))

    def test_zero_final_is_the_formula(self) -> None:
        blob = combiner_spirv(_xpu({}))
        self.assertIsNotNone(blob)
        assert blob is not None
        _check(self, blob)
        self.assertIn(GLSL_FCLAMP, _ext(blob))
        self.assertNotIn(OP_SAMPLE, _ops(blob))
        self.assertNotIn(OP_KILL, _ops(blob))
        self.assertEqual(_storage(blob)[CLASS_INPUT], 7)
        self.assertEqual(_storage(blob)[CLASS_OUTPUT], 1)
        self.assertEqual(_pairs(blob), [(0, 0), (1, 0), (1, 1), (1, 2), (1, 3)])
        self.assertIn(OP_EXEC_MODE, _ops(blob))

    def test_projective_and_final_r0(self) -> None:
        shader = parse_xpu(_xpu({8: 0x0C, 53: 1, 54: 1}))
        assert shader is not None
        self.assertEqual(shader.final_d.source, 12)
        blob = combiner_spirv(_xpu({8: 0x0C, 53: 1, 54: 1}))
        assert blob is not None
        _check(self, blob)
        self.assertIn(OP_SAMPLE, _ops(blob))
        self.assertIn(OP_FADD, _ops(blob))

    def test_texture_modes(self) -> None:
        sampled = {1, 2}
        quiet = {0, 3, 4, 5, 6, 8, 9}
        for mode in sampled | quiet:
            blob = combiner_spirv(_xpu({53: 1, 54: mode, 42: 0x1 if mode == 5 else 0}))
            assert blob is not None
            _check(self, blob)
            if mode in sampled:
                self.assertIn(OP_SAMPLE, _ops(blob), mode)
            else:
                self.assertNotIn(OP_SAMPLE, _ops(blob), mode)
            if mode == 5:
                self.assertIn(OP_KILL, _ops(blob))
            else:
                self.assertNotIn(OP_KILL, _ops(blob))
