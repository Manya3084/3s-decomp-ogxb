"""The C89 fixes tools/build_c.py applies before handing a file to VC7.1."""

from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

import build_c
from ogxb import coff


class Prep(unittest.TestCase):
    def prep(self, text: str) -> str:
        with tempfile.TemporaryDirectory() as d:
            old_src, old_prep = build_c.SRC, build_c.PREP
            build_c.SRC, build_c.PREP = Path(d) / "src", Path(d) / "prep"
            try:
                src = build_c.SRC / "x.c"
                src.parent.mkdir(parents=True)
                src.write_text(text)
                out = build_c.prepare(src)
                return out.read_text() if out != src else text
            finally:
                build_c.SRC, build_c.PREP = old_src, old_prep

    def test_unnamed_parameters_get_names(self):
        out = self.prep("void f(WORK *wk, s32 /* unused */) {\n}\ns16 g(s32) {\n}\nvoid h(DADD*) {\n}\n")
        self.assertIn("s32 xb_unused1)", out)
        self.assertIn("s16 g(s32 xb_unused2)", out)
        self.assertIn("DADD* xb_unused3", out)
        self.assertIn("WORK *wk", out)

    def test_named_and_void_parameters_stay(self):
        text = "void f(void) {\n}\nvoid g(unsigned int x, const char *s) {\n}\n"
        self.assertEqual(self.prep(text), text)

    def test_static_prototype_without_body_loses_static(self):
        out = self.prep("static void A(s32 x);\nstatic void B(void);\nstatic void B(void) {\n}\n#if 0\nstatic void A(s32 x) {\n}\n#endif\n")
        self.assertIn("\nvoid A(s32 x);", out)
        self.assertIn("static void B(void);", out)

    def test_designators_in_field_order_become_positional(self):
        out = self.prep("typedef struct {\n    s16 a;\n    s32 b;\n} T;\nconst T t[] = { { .a = 1, .b = 2 } };\nconst T u = { .b = 2, .a = 1 };\n")
        self.assertIn("{ 1, 2 }", out)
        self.assertIn("{ .b = 2, .a = 1 }", out)


class Undecorate(unittest.TestCase):
    def test_msvc_c_names(self):
        self.assertEqual(coff.undecorate("_effect_96_init"), "effect_96_init")
        self.assertEqual(coff.undecorate("_ReadFile@20"), "ReadFile")
        self.assertEqual(coff.undecorate("@__security_check_cookie@4"), "__security_check_cookie")


if __name__ == "__main__":
    unittest.main()
