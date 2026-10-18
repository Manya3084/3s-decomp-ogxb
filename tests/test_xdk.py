"""Lock the XDK symbol list for retail sf33rd.xbe.

The text is checked with or without the disc. Prefix bytes are compared
only when SF33RD_XBE or xbe.path points at the retail file.
"""

from __future__ import annotations

import re
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

from ogxb.paths import ROOT, find_xbe
from ogxb.xbe import load

XDK = ROOT / "config" / "sf33rd" / "symbols" / "xdk.txt"
FUNCS = ROOT / "config" / "sf33rd" / "symbols" / "funcs.txt"
LINE = re.compile(r"^([A-Za-z0-9_]+) = (0x[0-9A-F]+); // (.+)$")
FUNC_NAME = re.compile(r"^([A-Za-z_.$][\w.$]*)\s*=")

ADDRESS_COUNT = 3894
OFFSET_COUNT = 6


def parse(text: str) -> tuple[list[tuple[str, int, dict[str, str]]], list[tuple[str, int, dict[str, str]]]]:
    addresses = []
    offsets = []
    mode = "addr"
    for raw in text.splitlines():
        if raw.startswith("// Field offsets"):
            mode = "off"
            continue
        if not raw or raw.startswith("//"):
            continue
        match = LINE.match(raw)
        if not match:
            raise AssertionError(f"bad line: {raw}")
        fields = {}
        for part in match.group(3).split():
            key, value = part.split(":", 1)
            fields[key] = value
        row = (match.group(1), int(match.group(2), 16), fields)
        (addresses if mode == "addr" else offsets).append(row)
    return addresses, offsets


def in_section(image, va: int, raw: bool) -> bool:
    for section in image.sections:
        if raw:
            if section.raw_size and section.va <= va and va + 8 <= section.va + section.raw_size:
                return True
        else:
            span = max(section.virtual_size, section.raw_size)
            if section.va <= va < section.va + span:
                return True
    return False


class XdkTest(unittest.TestCase):
    def test_symbol_list(self) -> None:
        text = XDK.read_text()
        self.assertNotIn("/mnt/", text)
        self.assertNotIn("/home/", text)
        self.assertNotIn("/tmp/", text)
        addresses, offsets = parse(text)
        self.assertEqual(len(addresses), ADDRESS_COUNT)
        self.assertEqual(len(offsets), OFFSET_COUNT)
        names = [name for name, _va, _fields in addresses + offsets]
        self.assertEqual(len(names), len(set(names)))
        self.assertEqual(addresses, sorted(addresses, key=lambda row: (row[1], row[0])))
        self.assertEqual(offsets, sorted(offsets, key=lambda row: (row[1], row[0])))

        by_name = {name: (va, fields) for name, va, fields in addresses}
        self.assertEqual(by_name["mainCRTStartup"][0], 0x125FF7)
        self.assertEqual(by_name["mainCRTStartup"][1]["conv"], "cdecl")
        self.assertEqual(by_name["mainCRTStartup"][1]["calls"], "0")
        self.assertEqual(by_name["mainXapiStartup"][0], 0x125F83)
        self.assertEqual(by_name["CreateThread"][0], 0x124F9C)
        self.assertEqual(by_name["Direct3D_CreateDevice"], (0x181A20, by_name["Direct3D_CreateDevice"][1]))
        self.assertEqual(by_name["Direct3D_CreateDevice"][1]["calls"], "1")
        self.assertEqual(by_name["QueryPerformanceFrequency"][0], 0x123331)
        self.assertEqual(by_name["QueryPerformanceFrequency"][1]["calls"], "7")
        self.assertEqual(by_name["XGetVideoFlags"][0], 0x123345)
        self.assertEqual(by_name["XGetVideoFlags"][1]["calls"], "1")
        self.assertEqual(by_name["XGetAVPack"][0], 0x12338E)
        self.assertEqual(by_name["XGetAVPack"][1]["calls"], "3")
        self.assertEqual(by_name["XGetVideoStandard"][0], 0x123396)
        self.assertEqual(by_name["XGetVideoStandard"][1]["calls"], "2")
        self.assertEqual(by_name["XCalculateSignatureBegin"][0], 0x125323)
        self.assertEqual(by_name["XCalculateSignatureBegin"][1]["calls"], "5")
        self.assertEqual(by_name["XCalculateSignatureUpdate"][0], 0x125337)
        self.assertEqual(by_name["XCalculateSignatureUpdate"][1]["calls"], "6")
        self.assertEqual(by_name["XCalculateSignatureEnd"][0], 0x125385)
        self.assertEqual(by_name["XCalculateSignatureEnd"][1]["calls"], "5")
        self.assertEqual(by_name["XInputGetState"][0], 0x2121C5)
        self.assertEqual(by_name["XInputGetState"][1]["calls"], "3")
        self.assertEqual(by_name["_tls_index"][0], 0x7A4A88)
        self.assertEqual(by_name["_tls_index"][1]["bss"], "1")
        self.assertNotIn("prefix", by_name["_tls_index"][1])
        aliases = {name for name, va, _fields in addresses if va == 0x191FA0}
        self.assertEqual(aliases, {"D3DRS_FogEnable", "D3D_g_DeferredRenderState"})

        for name, _va, fields in addresses:
            self.assertIn(fields["kind"], ("func", "var"))
            self.assertIn("sect", fields)
            int(fields["calls"], 10)
            if fields["kind"] == "func":
                self.assertIn(fields["conv"], ("stdcall", "cdecl", "fastcall", "thiscall"))
            has_prefix = "prefix" in fields
            has_bss = fields.get("bss") == "1"
            self.assertNotEqual(has_prefix, has_bss)
            if has_prefix:
                self.assertEqual(len(fields["prefix"]), 16)
                int(fields["prefix"], 16)

        offset_names = {name for name, _va, _fields in offsets}
        self.assertEqual(
            offset_names,
            {
                "_tls_array",
                "XapiLastErrorCode_OFFSET",
                "D3DDevice__m_VertexShader_OFFSET",
                "D3DDevice__m_SwapCallback_OFFSET",
                "D3DDevice__m_VBlankCallback_OFFSET",
                "D3DDevice__m_VerticalBlankEvent_OFFSET",
            },
        )
        for _name, va, fields in offsets:
            self.assertEqual(fields["kind"], "offset")
            self.assertLess(va, 0x10000)

        func_names = set()
        for raw in FUNCS.read_text().splitlines():
            match = FUNC_NAME.match(raw)
            if match:
                func_names.add(match.group(1))
        self.assertEqual(func_names.intersection(names), set())

        path = find_xbe()
        if path is None or not path.is_file():
            return
        image = load(path)
        self.assertEqual(by_name["mainCRTStartup"][0], image.entry)
        for name, va, fields in addresses:
            if "prefix" in fields:
                self.assertTrue(in_section(image, va, raw=True), name)
                self.assertEqual(image.bytes_at(va, 8).hex(), fields["prefix"], name)
            else:
                self.assertTrue(in_section(image, va, raw=False), name)
                self.assertFalse(in_section(image, va, raw=True), name)
        for name, va, _fields in offsets:
            self.assertFalse(in_section(image, va, raw=False), name)


if __name__ == "__main__":
    unittest.main()
