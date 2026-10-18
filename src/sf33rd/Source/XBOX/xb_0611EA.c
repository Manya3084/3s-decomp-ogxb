/* xb_0611EA.c: Xbox-only code from the run of Xbox-only functions at 0x611EA, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern u16 p1sw_0;
extern u16 p1sw_1;
extern u16 p2sw_0;
extern u16 p2sw_1;

s32 xb_GetJoiningPlayer(void) {
    s32 r = -1;

    if ((p2sw_0 & 0x4100) & ~p2sw_1) {
        r = 1;
    }

    if ((p1sw_0 & 0x4100) & ~p1sw_1) {
        r = 0;
    }

    return r;
}
