/* xb_061F5E.c: Xbox-only code from the run of Xbox-only functions at 0x61F5E, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

extern s16 D_00C7E764;
extern u8 D_00C7E768[];

s32 xb_GetTexRenewBufferSize(void) {
    return 0xD000;
}

void xb_ClearTexRenewQueue(void) {
    D_00C7E764 = 0;
    memset(D_00C7E768, 0, 0x18);
}
