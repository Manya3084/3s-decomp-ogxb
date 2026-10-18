/* xb_030438.c: Xbox-only code from the run of Xbox-only functions at 0x30438, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern f32 D_00795CC0;
extern f32 D_00795CC4;
extern f32 D_00795CC8;

void xb_GetButtonScale(f32* x, f32* y, f32* z) {
    *x = D_00795CC0;
    *y = D_00795CC4;
    *z = D_00795CC8;
}

void xb_SetButtonScale(f32 x, f32 y, f32 z) {
    D_00795CC0 = x;
    D_00795CC4 = y;
    D_00795CC8 = z;
}
