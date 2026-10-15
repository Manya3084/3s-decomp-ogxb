"""x86-32 disassembly through libcapstone 5.

The code buffer is passed as a raw pointer. A C string would stop at the first
zero, and Xbox immediates contain zeros.
"""

from __future__ import annotations

import ctypes
from dataclasses import dataclass

CS_ARCH_X86 = 3
CS_MODE_32 = 1 << 2

_lib = None


class _CsInsn(ctypes.Structure):
    _fields_ = [
        ("id", ctypes.c_uint),
        ("address", ctypes.c_uint64),
        ("size", ctypes.c_uint16),
        ("bytes", ctypes.c_uint8 * 24),
        ("mnemonic", ctypes.c_char * 32),
        ("op_str", ctypes.c_char * 160),
        ("detail", ctypes.c_void_p),
    ]


def _library():
    global _lib
    if _lib is not None:
        return _lib
    lib = ctypes.CDLL("libcapstone.so.5")
    lib.cs_open.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.POINTER(ctypes.c_size_t)]
    lib.cs_open.restype = ctypes.c_int
    lib.cs_close.argtypes = [ctypes.POINTER(ctypes.c_size_t)]
    lib.cs_close.restype = ctypes.c_int
    lib.cs_disasm.argtypes = [
        ctypes.c_size_t,
        ctypes.c_void_p,
        ctypes.c_size_t,
        ctypes.c_uint64,
        ctypes.c_size_t,
        ctypes.POINTER(ctypes.POINTER(_CsInsn)),
    ]
    lib.cs_disasm.restype = ctypes.c_size_t
    lib.cs_free.argtypes = [ctypes.c_void_p, ctypes.c_size_t]
    lib.cs_free.restype = None
    _lib = lib
    return lib


@dataclass(frozen=True)
class Insn:
    address: int
    size: int
    mnemonic: str
    op_str: str

    @property
    def end(self) -> int:
        return self.address + self.size


class Disassembler:
    def __init__(self) -> None:
        self._handle = ctypes.c_size_t()
        err = _library().cs_open(CS_ARCH_X86, CS_MODE_32, ctypes.byref(self._handle))
        if err != 0:
            raise RuntimeError(f"cs_open failed ({err}). libcapstone.so.5 is required.")

    def close(self) -> None:
        if self._handle.value:
            _library().cs_close(ctypes.byref(self._handle))
            self._handle = ctypes.c_size_t()

    def __enter__(self) -> "Disassembler":
        return self

    def __exit__(self, *_) -> None:
        self.close()

    def disasm(self, blob: bytes, va: int, count: int = 0) -> list[Insn]:
        if not blob:
            return []
        raw = ctypes.create_string_buffer(blob)
        found = ctypes.POINTER(_CsInsn)()
        total = _library().cs_disasm(
            self._handle,
            ctypes.cast(raw, ctypes.c_void_p),
            len(blob),
            va,
            count,
            ctypes.byref(found),
        )
        insns = [
            Insn(int(found[i].address), int(found[i].size), found[i].mnemonic.decode(), found[i].op_str.decode())
            for i in range(total)
        ]
        if total:
            _library().cs_free(found, total)
        return insns
