/* xb_121642.c: Xbox-only code from 0x121642, the save menu's entry points.
 * SaveInit matches only apart from the functions before it, so a file of
 * Capcom's starts here. Capcom's source is lost; each body was checked
 * against retail. save_sw_get is static: SaveMove passes the work in eax. */

#include "types.h"
#include <string.h>

extern u8 D_007A1618[0x1E8];
extern s32 D_007A1800;
extern u8 D_007A1808;
extern s32 D_007A15CC;
extern u8 D_007BD60D;
extern u16 D_007BE0A6;
extern void (*D_00437F84[])(void* w);
extern u16 PLsw[2][2];
extern u8 Forbid_Reset;
void xb_SaveStateReset(s32 a, s32 b);
s16 Pull_ramcnt_key(u32 memreq, u8 kokey, u8 group, u8 frre);
u32 Get_ramcnt_address(s16 key);
s32 xb_GetJapaneseNames(void);
void xb_SaveStateRun(void);
void xb_DrawSaveScreen(void* w);

void SaveInit(u8 a, u8 b) {
    u32 adrs;

    memset(D_007A1618, 0, sizeof(D_007A1618));
    D_007A1618[0x20] = a;
    D_007A1618[0x22] = b;
    Forbid_Reset = 1;
    D_007A1618[0x1E] = 1;
    D_007A1618[0x26] = D_007BD60D;
    xb_SaveStateReset(a, 0);

    if (D_007A1800 != 0) {
        D_007A1618[0x50] = (u8)D_007A1800 - 1;
    }

    D_007A1618[0x51] = 2;
    *(s32*)(D_007A1618 + 0x28) = Pull_ramcnt_key(0x10000, 2, 0, 0);
    adrs = (Get_ramcnt_address(*(s16*)(D_007A1618 + 0x28)) + 0xFFF) / 0x1000 * 0x1000;
    *(u32*)(D_007A1618 + 0x2C) = adrs;
    *(u32*)(D_007A1618 + 0x30) = adrs;
    *(u32*)(D_007A1618 + 0x38) = adrs + 0x10000;
    *(u32*)(D_007A1618 + 0x3C) = adrs + 0x10000;
    *(u32*)(D_007A1618 + 0x40) = adrs + 0x10000;
    *(u32*)(D_007A1618 + 0x34) = adrs;

    D_007A15CC = xb_GetJapaneseNames() == 0;
}

/* save_sw_get 0x12170C: the save menu pad edges and repeats for both
 * players. Static: SaveMove passes the work in eax. */
static void save_sw_get(u8* w) {
    u16* pad;
    u8* rep;
    u16 cur;
    s32 cnt;

    *(u16*)(w + 0x16) = 0;
    *(u16*)(w + 0x14) = 0;
    *(u16*)(w + 0x12) = 0;
    rep = w + 0x1C;
    pad = PLsw[0];

    for (cnt = 2; cnt != 0; cnt--) {
        cur = pad[0];
        *(u16*)(w + 0x12) |= cur;
        *(u16*)(w + 0x14) |= ~pad[1] & pad[0];

        if (rep[-2] == 0) {
            if (cur &= 0xF) {
                rep[-2] = 1;
                rep[0] = 20;
                *(u16*)(w + 0x16) |= cur;
            }
        } else if (cur &= 0xF) {
            if (--rep[0] == 0) {
                rep[0] = 4;
                *(u16*)(w + 0x16) |= cur;
            }
        } else {
            rep[-2] = 0;
        }

        pad += 2;
        rep++;
    }
}

s32 SaveMove(void) {
    if (D_007A1808 != 0 && D_007A1618[0x22] == 2) {
        Forbid_Reset = 0;
        return 0;
    }

    save_sw_get(D_007A1618);
    D_00437F84[(s8)D_007A1618[0]](D_007A1618);
    xb_SaveStateRun();
    xb_DrawSaveScreen(D_007A1618);
    D_007BE0A6 = 0;
    return (s8)D_007A1618[0x1E];
}
