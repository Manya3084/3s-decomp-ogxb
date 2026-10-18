/* rebattle.c: Xbox-only code from Capcom's srcnet/rebattle.c (its _assert
 * path names it, at 0x11F725 and on).
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

s32 xb_NetSync_SetState7(void);
s32 xb_NetSync_SetState8(void);

void xb_rebattle_Select(s32 sel) {
    if (sel == 1) {
        xb_NetSync_SetState7();
        return;
    }

    if (sel == 0) {
        xb_NetSync_SetState8();
    }
}
