/* xb_11D590.c: Xbox-only code from 0x11D590, the network sync state
 * setters. They match only outside the file that defines
 * xb_NetSync_SetState, so they are taken to be another module.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

void xb_NetSync_SetState(s32 state);

s32 xb_NetSync_SetState7(void) {
    xb_NetSync_SetState(7);
    return 1;
}

s32 xb_NetSync_SetState8(void) {
    xb_NetSync_SetState(8);
    return 1;
}
