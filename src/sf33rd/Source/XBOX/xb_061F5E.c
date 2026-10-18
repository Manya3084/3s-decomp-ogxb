/* xb_061F5E.c: Xbox-only code from the run of Xbox-only functions at 0x61F5E, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

s32 xb_GetTexRenewBufferSize(void) {
    return 0xD000;
}
