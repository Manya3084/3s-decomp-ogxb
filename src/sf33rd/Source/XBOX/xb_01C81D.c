/* xb_01C81D.c: Xbox-only code from the run of Xbox-only functions at 0x1C81D, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern s32 D_00795C80;
void sub_0009B78F(void);

void xb_PushPauseCount(void) {
    sub_0009B78F();
    D_00795C80++;
}

void xb_PopPauseCount(void) {
    sub_0009B78F();
    D_00795C80--;
}
