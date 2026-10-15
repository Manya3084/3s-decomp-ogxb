"""Retail XBE image. Layout follows the public XBE header."""

from __future__ import annotations

import struct
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path

RETAIL_EP = 0xA8FC57AB
RETAIL_KT = 0x5B6D40B6
DEBUG_EP = 0x94859D4B
DEBUG_KT = 0xEFB1F152
CHIHIRO_EP = 0x40B5C16E
CHIHIRO_KT = 0x2290059D

_KEYS = (
    ("retail", RETAIL_EP, RETAIL_KT),
    ("debug", DEBUG_EP, DEBUG_KT),
    ("chihiro", CHIHIRO_EP, CHIHIRO_KT),
)


@dataclass(frozen=True)
class Section:
    name: str
    flags: int
    va: int
    virtual_size: int
    raw: int
    raw_size: int

    @property
    def executable(self) -> bool:
        return bool(self.flags & 4)


@dataclass(frozen=True)
class Library:
    name: str
    major: int
    minor: int
    build: int
    flags: int


@dataclass(frozen=True)
class Import:
    index: int
    va: int
    ordinal: int


@dataclass
class Image:
    path: Path
    data: bytes
    base: int
    header_size: int
    image_size: int
    sections: list[Section]
    libraries: list[Library]
    key_kind: str
    entry: int
    thunk_va: int
    imports: list[Import]
    title_id: int
    title: str
    debug_path: str
    rsds_path: str
    rsds_age: int
    timedate: int

    def section(self, name: str) -> Section:
        for item in self.sections:
            if item.name == name:
                return item
        raise KeyError(name)

    def va_offset(self, va: int) -> int | None:
        for item in self.sections:
            span = max(item.virtual_size, item.raw_size)
            if item.va <= va < item.va + span:
                off = item.raw + (va - item.va)
                if 0 <= off < len(self.data):
                    return off
        off = va - self.base
        if self.base <= va < self.base + self.header_size and 0 <= off < len(self.data):
            return off
        return None

    def bytes_at(self, va: int, size: int) -> bytes:
        off = self.va_offset(va)
        if off is None:
            raise ValueError(f"VA {va:#x} is not in a section")
        return self.data[off : off + size]

    def cstr(self, va: int, limit: int = 512) -> str:
        off = self.va_offset(va)
        if off is None:
            return ""
        return self.data[off : off + limit].split(b"\x00", 1)[0].decode("latin1", "replace")

    @property
    def text(self) -> tuple[Section, bytes]:
        section = self.section(".text")
        return section, self.data[section.raw : section.raw + section.raw_size]

    @property
    def xdk_build(self) -> int:
        builds = [item.build for item in self.libraries if item.major == 1]
        return max(builds) if builds else 0

    @property
    def built(self) -> datetime:
        return datetime.fromtimestamp(self.timedate, timezone.utc)


def _u32(data: bytes, offset: int) -> int:
    return struct.unpack_from("<I", data, offset)[0]


def _u16(data: bytes, offset: int) -> int:
    return struct.unpack_from("<H", data, offset)[0]


def load(path: Path) -> Image:
    data = path.read_bytes()
    if data[:4] != b"XBEH":
        raise ValueError(f"{path} is not an XBE")
    base = _u32(data, 0x104)
    header_size = _u32(data, 0x108)
    image_size = _u32(data, 0x10C)
    timedate = _u32(data, 0x114)
    cert_va = _u32(data, 0x118)
    num_sections = _u32(data, 0x11C)
    sections_va = _u32(data, 0x120)
    entry_raw = _u32(data, 0x128)
    debug_va = _u32(data, 0x14C)
    thunk_raw = _u32(data, 0x158)
    num_libs = _u32(data, 0x160)
    libs_va = _u32(data, 0x164)

    sections: list[Section] = []
    header_off = sections_va - base
    for index in range(num_sections):
        off = header_off + index * 0x38
        flags, va, vsize, raw, rsize, name_va = struct.unpack_from("<6I", data, off)
        name_off = name_va - base
        name = data[name_off : name_off + 32].split(b"\x00", 1)[0].decode("latin1")
        sections.append(Section(name, flags, va, vsize, raw, rsize))

    def early_off(va: int) -> int | None:
        for item in sections:
            span = max(item.virtual_size, item.raw_size)
            if item.va <= va < item.va + span:
                off = item.raw + (va - item.va)
                if 0 <= off < len(data):
                    return off
        off = va - base
        if base <= va < base + header_size and 0 <= off < len(data):
            return off
        return None

    def early_cstr(va: int) -> str:
        off = early_off(va)
        if off is None:
            return ""
        return data[off : off + 512].split(b"\x00", 1)[0].decode("latin1", "replace")

    key_kind = ""
    entry = 0
    thunk_va = 0
    for kind, ep_key, kt_key in _KEYS:
        ep = entry_raw ^ ep_key
        kt = thunk_raw ^ kt_key
        if base <= ep < base + image_size and base <= kt < base + image_size:
            key_kind, entry, thunk_va = kind, ep, kt
            break
    if not key_kind:
        raise ValueError("entry point did not decode with a known XOR key")

    libraries: list[Library] = []
    lib_off = libs_va - base
    for index in range(num_libs):
        off = lib_off + index * 0x10
        name = data[off : off + 8].split(b"\x00", 1)[0].decode("latin1")
        libraries.append(
            Library(
                name,
                _u16(data, off + 8),
                _u16(data, off + 10),
                _u16(data, off + 12),
                _u16(data, off + 14),
            )
        )

    cert_off = cert_va - base
    title_id = _u32(data, cert_off + 8)
    title_raw = data[cert_off + 0x0C : cert_off + 0x0C + 0x50]
    title = title_raw.decode("utf-16le", "replace").split("\x00", 1)[0]

    thunk_off = None
    for item in sections:
        span = max(item.virtual_size, item.raw_size)
        if item.va <= thunk_va < item.va + span:
            thunk_off = item.raw + (thunk_va - item.va)
            break
    if thunk_off is None:
        raise ValueError("kernel thunk table is outside the image")
    imports: list[Import] = []
    cursor = thunk_off
    while cursor + 4 <= len(data):
        word = _u32(data, cursor)
        if word == 0:
            break
        if not word & 0x80000000:
            raise ValueError(f"thunk {word:#x} is not an ordinal")
        imports.append(Import(len(imports), thunk_va + 4 * len(imports), word & 0x7FFFFFFF))
        cursor += 4
        if len(imports) > 400:
            raise ValueError("kernel thunk table did not end")

    rsds_at = data.find(b"RSDS")
    rsds_age = 0
    rsds_path = ""
    if rsds_at >= 0 and rsds_at + 24 < len(data):
        rsds_age = _u32(data, rsds_at + 20)
        rsds_path = data[rsds_at + 24 : rsds_at + 24 + 300].split(b"\x00", 1)[0].decode("latin1", "replace")

    return Image(
        path=path,
        data=data,
        base=base,
        header_size=header_size,
        image_size=image_size,
        sections=sections,
        libraries=libraries,
        key_kind=key_kind,
        entry=entry,
        thunk_va=thunk_va,
        imports=imports,
        title_id=title_id,
        title=title,
        debug_path=early_cstr(debug_va),
        rsds_path=rsds_path,
        rsds_age=rsds_age,
        timedate=timedate,
    )
