/* xb_03070B.c: Xbox-only code from the run of Xbox-only functions at 0x3070B, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern s16 D_00CB8840;
extern s16 D_00CB8842;

void xb_ClearOverlayIndex(void) {
    D_00CB8840 = -1;
    D_00CB8842 = 0;
}
