/* xb_0F50C9.c: Xbox-only code from 0xF50C9. xb_PurgeListEntry matches only apart from
 * the functions around it, so a file of Capcom's starts here.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern s32 D_007A7CF0[];
extern u8 D_00797BA8[];
s32 xb_LiveWork_Get2334(void);
void xb_StopAllSeSlots(void);
void xb_StopSeById(s16 id);
void XB_STDCALL xb_UnRegisterWaveBank(s32 engine, s32 bank);
s32 XB_STDCALL xb_XactCall_1B7FB7(s32 a);

void xb_PurgeListEntry(u8 id) {
    s32* e;

    D_007A7CF0[id] = -1;
    e = (s32*)(D_00797BA8 + id * 24);

    if (e[1] == 1) {
        if (xb_LiveWork_Get2334()) {
            xb_StopAllSeSlots();
        } else {
            xb_StopSeById(id);
        }

        if (e[5]) {
            xb_UnRegisterWaveBank(*(s32*)D_00797BA8, e[6]);
            e[6] = 0;
            e[5] = 0;
            ((u8*)e)[9] = 0xFF;
        }
        xb_XactCall_1B7FB7(e[4]);
        e[4] = 0;
        e[3] = 0;
        e[1] = 0;
    }
}
