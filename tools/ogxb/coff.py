"""Read MSVC COFF objects (i386): sections, symbols, and relocations."""

from __future__ import annotations

import struct
from dataclasses import dataclass, field

REL_DIR32 = 0x06
REL_DIR32NB = 0x07
REL_SECTION = 0x0A
REL_SECREL = 0x0B
REL_REL32 = 0x14

CODE = 0x20
DATA = 0x40
BSS = 0x80
COMDAT = 0x1000
DISCARDABLE = 0x02000000


@dataclass
class Reloc:
    offset: int
    symbol: int
    type: int


@dataclass
class CoffSection:
    index: int  # 1-based, as symbols refer to it
    name: str
    flags: int
    size: int
    data: bytes
    relocs: list[Reloc] = field(default_factory=list)

    @property
    def code(self) -> bool:
        return bool(self.flags & CODE)


@dataclass
class Symbol:
    index: int
    name: str
    value: int
    section: int  # 1-based; 0 undefined, negative special
    type: int
    storage: int  # 2 external, 3 static

    @property
    def function(self) -> bool:
        return (self.type & 0x20) == 0x20

    @property
    def defined(self) -> bool:
        return self.section > 0


@dataclass
class Coff:
    sections: list[CoffSection]
    symbols: dict[int, Symbol]

    def section(self, index: int) -> CoffSection:
        return self.sections[index - 1]


def _name(raw: bytes, strings: bytes) -> str:
    if raw[:4] == b"\0\0\0\0":
        off = struct.unpack_from("<I", raw, 4)[0]
        end = strings.index(b"\0", off)
        return strings[off:end].decode("latin1")
    return raw.rstrip(b"\0").decode("latin1")


def read(data: bytes) -> Coff:
    machine, nsec, _, symptr, nsym, opt, _ = struct.unpack_from("<HHIIIHH", data, 0)
    if machine != 0x14C:
        raise ValueError(f"not an i386 object (machine {machine:#x})")
    strings = data[symptr + nsym * 18:]
    sections = []
    for i in range(nsec):
        o = 20 + opt + i * 40
        raw_name = data[o:o + 8]
        _, _, size, rptr, relptr, _, nrel, _, flags = struct.unpack_from("<IIIIIIHHI", data, o + 8)
        name = raw_name.rstrip(b"\0").decode("latin1")
        if name.startswith("/"):
            name = _name(b"\0\0\0\0" + struct.pack("<I", int(name[1:])), strings)
        body = data[rptr:rptr + size] if rptr and not flags & BSS else bytes(size)
        relocs = [Reloc(*struct.unpack_from("<IIH", data, relptr + r * 10)) for r in range(nrel)]
        sections.append(CoffSection(i + 1, name, flags, size, body, relocs))
    symbols = {}
    i = 0
    while i < nsym:
        o = symptr + i * 18
        value, secn, typ, storage, naux = struct.unpack_from("<IhHBB", data, o + 8)
        symbols[i] = Symbol(i, _name(data[o:o + 8], strings), value, secn, typ, storage)
        i += 1 + naux
    return Coff(sections, symbols)


def undecorate(name: str) -> str:
    """C names as MSVC emits them: _name (cdecl), _name@N (stdcall), @name@N (fastcall)."""
    if name.startswith("?"):
        return name
    if name.startswith("@"):
        return name[1:].rsplit("@", 1)[0]
    if name.startswith("_"):
        name = name[1:]
        head, _, tail = name.rpartition("@")
        if head and tail.isdigit():
            return head
    return name
