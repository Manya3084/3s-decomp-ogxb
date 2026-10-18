/* xb_0611EA.c: Xbox-only code from the run of Xbox-only functions at 0x611EA, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

extern u16 p1sw_0;
extern u16 p1sw_1;
extern u16 p2sw_0;
extern u16 p2sw_1;
extern u8 D_00C7E9A0[];
extern u8 Interface_Type[4];
extern u16 D_007C59D4;
extern u16 D_007BE118;
extern u16 D_007C59D6;
extern u16 D_007C56B8;
extern s8 D_007AA5F6;
extern s8 D_007AA5F7;
extern s8 D_007AA5F8;
extern s8 D_007AA5F9;
extern s8 D_007AA5FA;
extern s8 D_007AA5FB;
extern s8 D_007AA5FC;
extern s8 D_007AA5FD;
extern s32 D_007AA600;

void xb_ResetInputState(void) {
    memset(D_00C7E9A0, 0, 0xD8);
    memset(Interface_Type, 0, 4);
    p2sw_0 = 0;
    p2sw_1 = 0;
    p1sw_0 = 0;
    p1sw_1 = 0;
    D_007C59D4 = 0;
    D_007BE118 = 0;
    D_007C59D6 = 0;
    D_007C56B8 = 0;
    D_007AA5F9 = -1;
    D_007AA5F8 = -1;
    D_007AA5F7 = -1;
    D_007AA5F6 = -1;
    D_007AA5FD = -1;
    D_007AA5FC = -1;
    D_007AA5FB = -1;
    D_007AA5FA = -1;
    D_007AA600 = 0;
}

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
