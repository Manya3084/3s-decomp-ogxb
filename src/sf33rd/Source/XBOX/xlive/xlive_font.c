/* xlive_font.c: Xbox-only code from Capcom's xlive_font.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0xFB063 to 0xFB883.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern u8* D_00798B78;
void sub_0004384A(void* a, void* b);
void xb_xlive_font_ResetState(void);
void xb_xlive_font_Clear(void);

void xb_xlive_font_SetPos(s16 x, s16 y) {
    u8* p = D_00798B78;

    *(s16*)(p + 0x10) = x;
    *(s16*)(p + 0x12) = y;
    sub_0004384A(p + 0x10, p + 0x12);
}

void xb_xlive_font_SetScale(f32 scale) {
    *(f32*)(D_00798B78 + 0x14) = scale;
}

void xb_xlive_font_SetAttr(u16 attr) {
    *(u16*)(D_00798B78 + 0x1E) = attr;
}

void xb_xlive_font_Reset(void) {
    xb_xlive_font_ResetState();
    xb_xlive_font_Clear();
}
