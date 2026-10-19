/* xb_121642.c: Xbox-only code from 0x121642, the save menu's entry points.
 * SaveInit matches only apart from the functions before it, so a file of
 * Capcom's starts here. Capcom's source is lost; each body was checked
 * against retail. save_sw_get is static: SaveMove passes the work in eax. */

#include "types.h"
#include <stdio.h>
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
void xb_DrawSaveScreen(u8* w);
s32 xb_GetLocalizedText(s32 i);
void xb_PrintSetScale(f32 scale);
void xb_PrintSetColor(u8 a, u8 b);
void xb_PrintSetAttr(s16 attr);
void xb_PrintSetPos(s16 x, s16 y);
s32 xb_PrintString(const char* fmt, ...);
s32 xb_PrintAt(s32 x, s32 y, const char* s, s32 unused);
void xb_DrawScreenShot(s32 x, s32 y, s32 prio, s32 w, s32 h, u8 a, s32 uv);
extern f32 PrioBase[];

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

/* xb_DrawSaveScreen 0x122081: the save menu's message for w[0x1DD]. Each
 * line of the localized text is printed at (x, y), 28 pixels apart. "%n"
 * in a line is the number at w + 0x4C, drawn in attribute 3; "%a" and "%b"
 * are the controller button icons (screenshot UV 4 and 5) drawn inline;
 * any other escape leaves a two-space gap. */
void xb_DrawSaveScreen(u8* w) {
    char line[0x50];
    char num[0x20];
    char out[0x50];
    char** text;
    char* s;
    char* p;
    s32 x;
    s32 y;
    s32 y1;
    u32 i;
    s32 msg = w[0x1DD];

    if (msg == 0) {
        return;
    }

    xb_GetLocalizedText(1);
    text = (char**)xb_GetLocalizedText(msg);
    xb_PrintSetScale(PrioBase[6]);
    xb_PrintSetColor(0x14, 0x14);
    xb_PrintSetAttr(0);

    switch (w[0x22]) {
    case 2:
        x = 0x3C;
        y = 0xC8;
        break;
    default:
        x = 0x30;
        y = 0x11F;
        break;
    }

    s = *text;

    if (s == 0) {
        return;
    }

    y1 = y - 1;

    do {
        text++;
        out[0] = 0;
        p = s;
        s = line;
        strcpy(s, p);

        for (p = strchr(line, '%'); p != 0; p = strchr(s, '%')) {
            *p = 0;

            if (p[1] == 'n') {
                strcat(out, s);
                sprintf(num, "%d", *(s32*)(w + 0x4C));
                xb_PrintSetAttr(3);
                xb_PrintSetPos(x + strlen(out) * 10, y);
                xb_PrintString(num);
                xb_PrintSetAttr(0);

                for (i = 0; i < strlen(num); i++) {
                    strcat(out, " ");
                }

                s = p + 2;
            } else if (p[1] == 'a') {
                strcat(out, s);
                xb_DrawScreenShot(((strlen(out) * 5 + 10) * 4 + x >> 1) + 2, y1, 6, 0x14, 0x14, 0, 4);
                strcat(out, "  ");
                s = p + 2;
            } else if (p[1] == 'b') {
                strcat(out, s);
                xb_DrawScreenShot(((strlen(out) * 5 + 10) * 4 + x >> 1) + 2, y1, 6, 0x14, 0x14, 0, 5);
                strcat(out, "  ");
                s = p + 2;
            } else {
                strcat(out, s);
                strcat(out, "  ");
                s = p + 2;
            }
        }

        strcat(out, s);
        xb_PrintAt(x, y, out, 0);
        y += 0x1C;
        y1 += 0x1C;
    } while ((s = *text) != 0);
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
