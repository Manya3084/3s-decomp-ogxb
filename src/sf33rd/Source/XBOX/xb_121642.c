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
extern void (*D_00437F84[])(u8* w);
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

/* The save menu (D_007A1618, 0x1E8 bytes): +0 state and +1, +2 its
 * sub-steps (D_00437F84 and the tables after it), +7/+8 the next
 * message's pages, +0xA a timer, +0x12 the pad edges and +0x14 the
 * decided keys (0x100 OK, 0x200 cancel), +0x1E done, +0x20 the kind of
 * data (0 system, 1 replay, 2 the other), +0x22 the caller, +0x23 the
 * answer of a yes/no, +0x30 the file buffer, +0x34, +0x44 an ADXF
 * handle, +0x48 the blocks a save needs, +0x58 on a list of slots,
 * +0x1DC/+0x1DD the message on screen. */
s32 xb_SaveStateResult(void);
s32 xb_SaveNeededBlocks(s32 unused);
s32 xb_SaveFreeBlocks(void);
s32 xb_SaveMenuFileBusy(void);
void xb_SaveStateStartHeader(s32 unused, s32 state);
void xb_SeSelectedThunk(void);
u32 XB_STDCALL XLaunchNewImageA(const char* path, void* data);
extern u8 Present_Mode;
extern u8 save_w[];
extern u8 mpp_w[];
extern u8 bgm_type;
extern u8 sound_mode;
extern s16 bgm_level;
extern s16 se_level;
extern s16 Correct_X[];
extern s16 Correct_Y[];
extern s32 X_Adjust;
extern s32 Y_Adjust;
extern u8 Disp_Size_H;
extern u8 Disp_Size_V;
extern u8 D_007C5959;
void setupSoundMode(void);
void SsBgmHalfVolume(s32 on);
void setSeVolume(void);
void Copy_Save_w(void);
void Copy_Check_w(void);
void xb_SetDisplayArgs(s32 x, s32 y);
void dspwhUnpack(u8 v, u8* h, u8* vv);
void Setup_Disp_Size(s32 a);
s32 Check_SysDir_Page(void);
u32 random_32_com(void);
void xb_GetPressingPlayer(u32 mask);
s32 sub_0009B78F(s32 type);
void xb_SeCursorMoveThunk(void);
void xb_SaveStateStartLoad(s32 a, s32 buf, s32 c);
extern u8 Replay_w[];
extern u8 system_dir[];
static void xb_SaveEncode(u8* buf, s32 size);
static void xb_SaveDecode(u8* w, u8* buf, s32 size);
static void xb_SaveMenuDrawList(u8* w);
extern void (*D_00437F9C[])(u8* w);
extern void (*D_00437FD0[])(u8* w);
extern void (*D_00438004[])(u8* w);
extern void (*D_00438034[])(u8* w);
extern s32 (*D_00438040[])(u8* w, s32 a);
extern u8 Rep_Game_Infor[];
extern u8 Convert_Buff[];
void Save_Game_Data(void);
void sub_0004384A();
void sub_00097103(u16 key);
void xb_SaveStateStartWrite(s32 a, s32 buf);
void xb_SaveStateStartRead(s32 a, s32 buf);
extern void (*D_0043804C[])(u8* w);

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

/* xb_SaveMenuSortList: sorts the slot list (+0x64): by slot when +0x60 is 0,
 * else newest first by each slot's time stamp. */
static void xb_SaveMenuSortList(u8* w) {
    char key[2][16];
    u8* e[2];
    u32 n = (s8)w[0x5A];
    u8* p = w + 0x64;
    u32 cnt;
    u32 j;
    u32 k;
    u8 t;

    if (n - 1 == 0) {
        return;
    }

    for (cnt = n - 1; cnt != 0; p++, cnt--) {
        if (*p == 0xFF) {
            continue;
        }

        for (j = p - (w + 0x64) + 1; j < n; j++) {
            u8* q = &w[0x64 + j];

            if (w[0x60] == 0) {
                if (*p <= *q) {
                    continue;
                }
            } else {
                e[0] = w + 0x78 + *p * 0x10;
                e[1] = w + 0x78 + *q * 0x10;

                for (k = 0; k < 2; k++) {
                    sprintf(key[k], "%04d%02d%02d%02d%02d%02d", *(u16*)(e[k] + 6), e[k][5], e[k][4], e[k][3], e[k][2], e[k][1]);
                }

                if (strcmp(key[0], key[1]) >= 0) {
                    continue;
                }
            }

            t = *p;
            *p = *q;
            *q = t;
        }
    }
}

/* xb_SaveApplySystem: loads the system data from the file buffer into the
 * current mode's save_w and the two copies after the modes, then applies
 * its sound, screen position and size, and directions. */
void xb_SaveApplySystem(u8* w) {
    u8* src = *(u8**)(w + 0x30) + 0x10;
    u8* sw = save_w + Present_Mode * 0x208;
    s32 page;
    s32 r;
    s32 i;

    memcpy(sw, src, 0x208);
    memcpy(sw, src, 0x208);
    memcpy(save_w + 0x820, src, 0x208);
    memcpy(save_w + 0xA28, src, 0x208);
    bgm_type = sw[0x27];
    sound_mode = sw[0x28];
    bgm_level = sw[0x29];
    se_level = sw[0x2A];

    if (mpp_w[0x33] != 0) {
        sw[0x26] = 0;
        mpp_w[0x33] = 0;
        save_w[0x846] = 0;
        save_w[0xA4E] = 0;
    }

    setupSoundMode();
    SsBgmHalfVolume(0);
    setSeVolume();
    Copy_Save_w();
    Copy_Check_w();
    Y_Adjust = (s8)sw[0x21] * 4;
    X_Adjust = (s8)sw[0x20] * 4;
    xb_SetDisplayArgs(Correct_X[0] + X_Adjust, Correct_Y[0] + Y_Adjust);
    dspwhUnpack(sw[0x22], &Disp_Size_H, &Disp_Size_V);
    Setup_Disp_Size(0);
    D_007C5959 = sw[0x23];
    page = Check_SysDir_Page();

    if (page < 9 && page + 1 < 10) {
        for (r = page + 1; r < 10; r++) {
            for (i = 0; i < 7; i++) {
                system_dir[Present_Mode * 0x48 + r * 7 + i] = system_dir[r * 7 + i];
            }
        }
    }
}

/* xb_SaveApplyDirection: loads the system directions from the file buffer. */
void xb_SaveApplyDirection(u8* w) {
    s32 page;
    s32 r;
    s32 i;

    memcpy(system_dir + Present_Mode * 0x48, *(u8**)(w + 0x30) + 0x10, 0x48);
    page = Check_SysDir_Page();

    if (page < 9 && page + 1 < 10) {
        for (r = page + 1; r < 10; r++) {
            for (i = 0; i < 7; i++) {
                system_dir[Present_Mode * 0x48 + r * 7 + i] = system_dir[r * 7 + i];
            }
        }
    }
}

/* xb_SaveMenuCheckHeader: 0 when slot +0xA's header is a valid date (and, but
 * for replays, two characters below 20), else 1. */
static s32 xb_SaveMenuCheckHeader(u8* w) {
    u8* e = w + 0x78 + *(s16*)(w + 0xA) * 0x10;
    s32 i;

    if (*(u16*)(e + 6) > 9999 || e[5] < 1 || e[5] > 12 || e[4] < 1 || e[4] > 31 || e[3] > 23 || e[2] > 59 ||
        e[1] > 59 || e[0] > 6) {
        return 1;
    }

    if (w[0x20] != 1) {
        for (i = 0; i < 2; i++) {
            s32 c = ((s32*)(e + 8))[i];

            if (c < 0 || c >= 20) {
                return 1;
            }
        }
    }

    return 0;
}

/* xb_SaveEncode: scrambles a file of size bytes for writing: a header
 * of 0x406, the key, the sum of the plain words and 0x5963, then each
 * word XORed with a key that steps by key * 0xB0 mod 0xFF53. */
static void xb_SaveEncode(u8* buf, s32 size) {
    u16* p = (u16*)buf;
    u16* sum;
    u16 key = random_32_com();
    s32 n;

    *p++ = 0x406;
    *p++ = key;
    *p = 0;
    sum = p++;
    *p++ = 0x5963;

    for (n = (size - 16) / 2; n > 0; n--) {
        *sum += *p;
        *p++ ^= key;

        if (key == 0) {
            key = 1;
        }

        key = key * 0xB0 % 0xFF53;
    }
}

/* xb_SaveDecode: unscrambles a read file and notes a bad header
 * (+0x1DF) or sum (+0x1DE). */
static void xb_SaveDecode(u8* w, u8* buf, s32 size) {
    u16* p = (u16*)buf;
    u16 key;
    u16 chk;
    s32 sum = 0;
    s32 n;

    w[0x1DF] = *p++ != 0x406;
    key = *p++;
    chk = *p;
    p += 2;

    for (n = (size - 16) / 2; n > 0; n--) {
        *p ^= key;
        sum += *p++;

        if (key == 0) {
            key = 1;
        }

        key = key * 0xB0 % 0xFF53;
    }

    w[0x1DE] = chk != (u16)sum;
}

/* The weekdays and the character codes of the slot list. */
const char* D_00438058[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
const char* D_00437F30[21] = { "GIL", "ALX", "RYU", "YUN", "DUD", "NCR", "HUG", "IBK", "ELE", "ORO", "YAN",
                               "KEN", "SEN", "URN", "GOK", "CHN", "MAK", " Q ", "TWE", "REM", "AKM" };

/* xb_SaveMenuDrawList: draws four slots of the list from +0x58, the one at
 * +0x59 highlighted, with the arrows when there are more. */
static void xb_SaveMenuDrawList(u8* w) {
    s32 n;
    s32 top;
    s32 i;
    u32 slot;
    u8* e;
    s8 c0;
    s8 c1;

    xb_GetLocalizedText(1);
    xb_PrintSetScale(PrioBase[6]);
    xb_PrintSetColor(0x16, 0x10);
    w[0x5E] += w[0x5D] == 1 ? 0xF : 1;

    if ((s8)w[0x5E] >= 0x3C) {
        w[0x5E] = 0;
    }

    if ((s8)++w[0x5F] >= 0x1E) {
        w[0x5F] = 0;
    }

    n = (s8)w[0x5A];
    top = (s8)w[0x58];

    for (i = 0; i < 4 && i + top < n; i++) {
        xb_PrintSetAttr(i == (s8)w[0x59] ? 3 : 0);
        xb_PrintSetPos(0x37, i * 0x16 + 0xA0);
        slot = w[0x64 + i + top];

        if (slot >= 0xFF) {
            xb_PrintString("------------------- NEW FILE -------------------");
            continue;
        }

        e = w + 0x78 + slot * 0x10;
        xb_PrintString("[FILE %02d]  ", slot + 1);

        if (e[0] >= 0xFE) {
            xb_PrintString("BROKEN FILE");
            continue;
        }

        xb_PrintString("%04d-%02d-%02d %02d:%02d:%02d (%s)", *(u16*)(e + 6), e[5], e[4], e[3], e[2], e[1], D_00438058[e[0]]);
        c0 = e[8];
        c1 = e[0xC];

        if (D_007A15CC != 0) {
            if (c0 == 0xE) {
                c0 += 6;
            }

            if (c1 == 0xE) {
                c1 += 6;
            }
        }

        if (w[0x20] == 2) {
            xb_PrintString("  %s vs %s", D_00437F30[c0], D_00437F30[c1]);
        }
    }

    xb_PrintSetAttr(5);

    if (top > 0) {
        xb_PrintSetPos(0x3F, 0x86);
        xb_PrintString("\x81\xA3");
    }

    if (top + 4 < n) {
        xb_PrintSetPos(0x3F, 0xFC);
        xb_PrintString("\x81\xA5");
    }
}

/* xb_SaveMenuSetMessage: shows message msg. */
static void xb_SaveMenuSetMessage(u8* w, u8 msg) {
    w[0x1DC] = 0;
    w[0x1DD] = msg;
}

/* xb_SaveMenuMessageWait: shows message msg and waits for a key (step 8). */
static void xb_SaveMenuMessageWait(u8* w, u8 msg) {
    w[1] = 8;
    w[2] = 0;
    xb_SaveMenuSetMessage(w, msg);
}

/* xb_SaveMenuStart: state 0, the menu's start: once no file is being read,
 * notes the blocks a save needs and goes to state 1, 3 or 4 by caller. */
void xb_SaveMenuStart(u8* w) {
    switch (w[1]) {
    case 0:
        if (xb_SaveMenuFileBusy()) {
            break;
        }

        w[1]++;
        /* fallthrough */

    case 1:
        if (xb_SaveMenuFileBusy()) {
            break;
        }

        w[1]++;
        *(s32*)(w + 0x48) = xb_SaveNeededBlocks(0);
        /* fallthrough */

    case 2:
    case 3:
        switch (w[0x22]) {
        case 2:
            w[0] = 3;
            break;

        case 3:
            w[0] = 4;
            break;

        default:
            w[0] = 1;
            break;
        }

        w[1] = 0;
        w[2] = 0;
        break;
    }
}

/* xb_save_1217F8: waits ten frames, then step 1. */
void xb_save_1217F8(u8* w) {
    switch ((s8)w[2]) {
    case 0:
        w[2]++;
        *(s16*)(w + 0xA) = 10;
        /* fallthrough */

    case 1:
        if (--*(s16*)(w + 0xA) <= 0) {
            w[1] = 1;
        }

        break;
    }
}

void xb_save_121826(u8* w) {
    w[1] = (w[0x20] != 0) + 2;
    w[2] = 0;
    w[0x52] = 0;
    w[0x23] = 0;
    xb_SaveMenuSetMessage(w, 0);
}

void xb_save_121849(u8* w) {
    w[7] = 0xC;
    xb_SaveMenuMessageWait(w, 7);
}

/* xb_SaveMenuLaunchDashboard: the save drive is full: to the dashboard's memory
 * screen for drive U, asking for the blocks at +0x48. */
void xb_SaveMenuLaunchDashboard(u8* w) {
    s32 ld[0x300];

    memset(ld, 0, sizeof(ld));
    ld[3] = *(s32*)(w + 0x48);
    ld[0] = 2;
    ld[2] = 'U';
    XLaunchNewImageA(0, ld);
}

static void xb_SaveMenuQuit(u8* w) {
    w[0] = 1;
    w[1] = 0xC;
    xb_SaveMenuSetMessage(w, 0);
}

/* xb_save_1218C4: state 2 step 0: lists the used slots of the 16-byte
 * entries at +0x78 into +0x64, after a free slot (0xFF) when the caller
 * may make one. */
void xb_save_1218C4(u8* w) {
    u8* e = w + 0x78;
    u8* d = w + 0x64;
    s32 n = (s8)w[0x5A];
    s32 i;

    w[1] = 1;
    w[0x58] = 0;
    w[0x59] = 0;
    w[0x5D] = 0;
    w[0x60] = 0;

    if (w[0x22] != 0 && n < (s8)w[0x5B]) {
        w[0x5A]++;
        *d++ = 0xFF;
    }

    for (i = 0; n > 0; i++, e += 0x10) {
        if (*e != 0xFF) {
            *d++ = i;
            n--;
        }
    }
}

void xb_save_121923(u8* w) {
    w[2] = 0;
    w[0x5D] = 0;
    w[0x23] = 0;
    w[1] = 2;

    if (w[0x22] == 0) {
        xb_SaveMenuSetMessage(w, w[0x20] == 1 ? 0x24 : 0x35);
    } else {
        xb_SaveMenuSetMessage(w, w[0x20] == 1 ? 0x1A : 0x2B);
    }
}

void xb_save_121960(u8* w) {
    xb_SaveMenuMessageWait(w, w[0x20] == 1 ? 0x20 : 0x31);
}

/* xb_save_12197B: once the message is gone, state 5. */
void xb_save_12197B(u8* w) {
    if (w[0x1DC] == 0) {
        w[0] = 5;
        w[1] = 0;
        w[0x52] = 0xFF;
    }
}

static s32 xb_SaveMenuBootBuffer(u8* w) {
    return ((s8)w[0x50] << 15) + *(s32*)(w + 0x34);
}

/* xb_save_12199F: state 3 step 0: clears the save request, sets the
 * mode to 1, and goes on after a frame. */
void xb_save_12199F(u8* w) {
    switch ((s8)w[2]) {
    case 0:
        w[2]++;
        D_007A1800 = 0;
        *(s16*)(w + 0xA) = 1;
        Present_Mode = 1;
        /* fallthrough */

    case 1:
        if (--*(s16*)(w + 0xA) <= 0) {
            w[1] = 1;
            w[2] = 0;
        }

        break;
    }
}

void xb_save_1219DF(u8* w) {
    if (w[0x1DC] == 0) {
        w[0] = 5;
        w[1] = 0;
        D_007A1808 = 1;
    }
}

static s32 xb_SaveMenuOK(void) {
    return *(s32*)(D_007A1618 + 0x14) & 0x100;
}

static s32 xb_SaveMenuCancel(void) {
    return *(s32*)(D_007A1618 + 0x14) & 0x200;
}

/* xb_SaveMenuWaitOK: waits for the message, then for OK. Returns 0 when OK
 * is pressed. */
static s32 xb_SaveMenuWaitOK(u8* w) {
    switch ((s8)w[3]) {
    case 0:
        if (w[0x1DC] == 0) {
            w[3]++;
        }

        break;

    case 1:
        if (xb_SaveMenuOK()) {
            xb_SeSelectedThunk();
            return 0;
        }

        break;
    }

    return 1;
}

/* xb_SaveMenuYesNo: a yes/no: 0 while undecided, then the answer (1 OK,
 * 2 cancel). */
static s32 xb_SaveMenuYesNo(u8* w) {
    switch ((s8)w[3]) {
    case 0:
        if (xb_SaveMenuOK()) {
            xb_SeSelectedThunk();
            w[0x23] = 1;
            w[3]++;
        } else if (xb_SaveMenuCancel()) {
            xb_SeSelectedThunk();
            w[0x23] = 2;
            w[3]++;
        }

        break;

    case 1:
        return w[0x23];
    }

    return 0;
}

/* xb_SaveApplyReplay: the replay data from the file buffer into Replay_w. */
void xb_SaveApplyReplay(u8* w) {
    memcpy(Replay_w, *(u8**)(w + 0x30) + 0x10, 0x1D12 * 4);
}

void xb_save_12239B(u8* w) {
    xb_SaveMenuSetMessage(w, 5);
    w[1] = 4;
    w[2] = 0;
    w[7] = 0xA;
    w[8] = 9;
}

void xb_save_122625(u8* w) {
    xb_SaveMenuSetMessage(w, 6);
    w[1] = 4;
    w[2] = 0;
    w[7] = 0xB;
    w[8] = 5;
}

void xb_save_1227E9(u8* w) {
    xb_SaveMenuSetMessage(w, w[0x20] == 1 ? 0x1E : 0x2F);
    w[1] = 5;
    w[2] = 0;
    w[7] = 0xA;
    w[8] = 9;
}

void xb_save_1229C0(u8* w) {
    xb_SaveMenuSetMessage(w, w[0x20] == 1 ? 0x21 : 0x32);
    w[1] = 5;
    w[2] = 0;
    w[7] = 0xB;
    w[8] = 6;
}

void xb_save_1229EB(u8* w) {
    xb_SaveMenuSetMessage(w, 0x14);
    w[1] = 8;
    w[2] = 0;
    w[7] = 2;
    w[8] = 4;
}

void xb_save_122A08(u8* w) {
    xb_SaveMenuSetMessage(w, 0xD);
    w[1] = 8;
    w[2] = 0;
    w[7] = 7;
    w[8] = 5;
}

void xb_save_122AAD(u8* w) {
    xb_SaveMenuSetMessage(w, 0x17);
    w[1] = 8;
    w[2] = 0;
    w[7] = 0xA;
    w[8] = 3;
}

void xb_save_122ACA(u8* w) {
    xb_SaveMenuSetMessage(w, 0x12);
    w[1] = 8;
    w[2] = 0;
    w[7] = 0xA;
    w[8] = 6;
}

/* xb_SavePrepareDirection: the current mode's system direction data to the file
 * buffer. */
void xb_SavePrepareDirection(u8* w) {
    u8* buf = *(u8**)(w + 0x30);

    memcpy(buf + 0x10, system_dir + Present_Mode * 0x48, 0x48);
    xb_SaveEncode(buf, 0x58);
}

s32 xb_SaveCheckDirection(u8* w, s32 unused) {
    xb_SaveDecode(w, *(u8**)(w + 0x30), 0x58);

    if (w[0x1DF] != 0 || w[0x1DE] != 0) {
        return -1;
    }

    return 0;
}

s32 xb_SaveCheckReplay(u8* w, s32 unused) {
    xb_SaveDecode(w, *(u8**)(w + 0x30), 0x7458);

    if (w[0x1DF] != 0 || w[0x1DE] != 0) {
        return -1;
    }

    return 0;
}

static void xb_SaveApply(u8* w) {
    D_0043804C[w[0x20]](w);
}

static void xb_SavePrepare(u8* w) {
    D_00438034[w[0x20]](w);
}

static s32 xb_SaveCheck(u8* w, s32 a) {
    return D_00438040[w[0x20]](w, a);
}

/* The state machine's results (xb_SaveStateResult): 0 done, -1 busy,
 * -0x100 failed, -0xFD no such file (or no room). */
#define XB_SAVE_BUSY -1
#define XB_SAVE_FAILED -0x100
#define XB_SAVE_NOFILE -0xFD

/* xb_save_1223B8: state 1 step 2: looks for the data and says what
 * comes next (load: found, or not; save: overwrite, or room). */
void xb_save_1223B8(u8* w) {
    s32 r;
    s32 free;

    switch ((s8)w[2]) {
    case 0:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;
        xb_SaveMenuSetMessage(w, 0);
        /* fallthrough */

    case 1:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;
        xb_SaveStateReset(w[0x20], 0);
        xb_SaveStateStartHeader(0, *(s32*)(w + 0x30));
        /* fallthrough */

    case 2:
        r = xb_SaveStateResult();
        *(s32*)(w + 0x1D8) = r;

        if (r == XB_SAVE_FAILED) {
            w[7] = 0xC;
            xb_SaveMenuMessageWait(w, w[0x22] == 0 ? 0xC : 7);
        } else if (r == XB_SAVE_NOFILE) {
            if (w[0x22] == 0) {
                w[7] = 0xC;
                xb_SaveMenuMessageWait(w, 0xB);
            } else if ((free = xb_SaveFreeBlocks()) < *(s32*)(w + 0x48)) {
                *(s32*)(w + 0x4C) = *(s32*)(w + 0x48) - free;
                xb_save_12239B(w);
            } else {
                xb_SaveMenuSetMessage(w, 4);
                w[7] = 7;
                w[1] = 4;
                w[2] = 0;
                w[8] = 0xC;
            }
        } else if (r == 0) {
            if (w[0x22] == 0) {
                xb_SaveMenuSetMessage(w, 8);
                w[7] = 6;
            } else {
                xb_SaveMenuSetMessage(w, 1);
                w[7] = 7;
            }

            w[1] = 4;
            w[2] = 0;
            w[8] = 0xC;
        }

        break;
    }
}

/* xb_save_1224A0: state 1 step 3: reads the header of each slot (10 for
 * replays, else 20) into +0x78, marking a broken one 0xFE, then lists
 * them (state 2), or says there is nothing to load. */
void xb_save_1224A0(u8* w) {
    s32 r;

    switch ((s8)w[2]) {
    case 0:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;
        *(s16*)(w + 0xA) = 0;
        *(s16*)(w + 0xC) = 0;
        w[0x5B] = w[0x20] == 1 ? 10 : 20;
        xb_SaveMenuSetMessage(w, w[0x20] == 1 ? 0x18 : 0x29);
        memset(w + 0x78, 0xFF, 0x140);
        /* fallthrough */

    case 1:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;
        xb_SaveStateReset(w[0x20], *(s16*)(w + 0xA));
        xb_SaveStateStartHeader(0, (s32)(w + 0x78 + *(s16*)(w + 0xA) * 0x10));
        /* fallthrough */

    case 2:
        r = xb_SaveStateResult();
        *(s32*)(w + 0x1D8) = r;

        if (r == XB_SAVE_FAILED) {
            w[0x78 + *(s16*)(w + 0xA) * 0x10] = 0xFE;
        } else if (r == XB_SAVE_NOFILE) {
            goto next;
        } else if (r != 0) {
            break;
        }

        (*(s16*)(w + 0xC))++;

        if (xb_SaveMenuCheckHeader(w)) {
            w[0x78 + *(s16*)(w + 0xA) * 0x10] = 0xFE;
        }

    next:
        if (++*(s16*)(w + 0xA) < (s8)w[0x5B]) {
            w[2]--;
            break;
        }

        if (w[0x22] == 0 && *(s16*)(w + 0xC) == 0) {
            xb_SaveMenuMessageWait(w, w[0x20] == 1 ? 0x27 : 0x38);
            w[7] = 0xC;
        } else {
            w[0x5A] = w[0xC];
            w[0] = 2;
            w[1] = 0;
            w[2] = 0;
            xb_SaveMenuSetMessage(w, 0);
        }

        break;
    }
}

/* xb_save_1225E2: a yes/no; OK goes to step +7, cancel to +8. */
void xb_save_1225E2(u8* w) {
    switch ((s8)w[2]) {
    case 0:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;
        w[3] = 0;
        /* fallthrough */

    case 1:
        switch (xb_SaveMenuYesNo(w)) {
        case 1:
            w[1] = w[7];
            w[2] = 0;
            break;

        case 2:
            w[1] = w[8];
            w[2] = 0;
            break;
        }

        break;
    }
}

/* xb_SaveMenuList: state 2 step 2: the slot list. OK picks a slot (load:
 * not a broken one; save: a new file takes the first free slot), cancel
 * leaves, key 0x20 changes the order, and up, down and the page keys
 * move the cursor (+0x59) and the list's top (+0x58), wrapping. */
void xb_SaveMenuList(u8* w) {
    s32 top;
    s32 cur;
    s32 n;
    u32 slot;
    u32 i;
    u16 sw;

    switch ((s8)w[2]) {
    case 0:
        if (w[0x1DC] != 0) {
            return;
        }

        w[2]++;
        /* fallthrough */

    case 1:
        top = (s8)w[0x58];
        cur = (s8)w[0x59];

        if (xb_SaveMenuOK()) {
            slot = w[0x64 + cur + top];

            if (w[0x22] == 0) {
                if (w[0x78 + slot * 0x10] == 0xFE) {
                    xb_SeSelectedThunk();
                    return;
                }

                w[1] = 3;
                xb_GetPressingPlayer(0x100);
            } else {
                if (slot == 0xFF) {
                    slot = 0;

                    for (i = 0; i < w[0x5B]; i++) {
                        if (w[0x78 + i * 0x10] == 0xFF) {
                            slot = i;
                            break;
                        }
                    }
                }

                w[1] = 4;
            }

            w[2] = 0;
            xb_SaveMenuSetMessage(w, 0);
            w[0x5C] = slot;
            w[0x5D] = 1;
            xb_SeSelectedThunk();
            return;
        }

        if (xb_SaveMenuCancel()) {
            xb_SaveMenuQuit(w);
            xb_SeSelectedThunk();
            return;
        }

        if (w[0x14] & 0x20) {
            w[0x60] ^= 1;
            xb_SaveMenuSortList(w);
            xb_SeSelectedThunk();
            return;
        }

        sw = *(u16*)(w + 0x16);
        n = (s8)w[0x5A];

        if (sw & 2) {
            if (cur + top + 1 >= n) {
                cur = 0;
                top = 0;
            } else if (cur + 1 >= 4) {
                top++;
            } else {
                cur++;
            }
        } else if (sw & 1) {
            if (cur + top == 0) {
                goto to_end;
            } else if (cur == 0) {
                top--;
            } else {
                cur--;
            }
        } else if (sw & 8) {
            if (cur + top + 1 >= n) {
                cur = 0;
                top = 0;
            } else if (cur + top + 4 >= n) {
                if (n > 4) {
                    cur = 3;
                    top = n - 4;
                } else {
                    top = 0;
                    cur = n - 1;
                }
            } else if (top + 4 > n - 4) {
                cur = cur + top - n + 8;
                top = n - 4;
            } else {
                top += 4;
            }
        } else if (sw & 4) {
            if (cur + top == 0) {
            to_end:
                if (n > 4) {
                    cur = 3;
                    top = n - 4;
                } else {
                    cur = n - 1;
                }
            } else if (top - 4 >= 0) {
                top -= 4;
            } else if (cur + top < 4) {
                cur = 0;
                top = 0;
            } else {
                cur = cur + top - 4;
                top = 0;
            }
        }

        if (top != (s8)w[0x58] || cur != (s8)w[0x59]) {
            w[0x58] = top;
            w[0x59] = cur;
            xb_SeCursorMoveThunk();
        }

        break;
    }
}

/* xb_save_122814: state 2 step 4: writes the save to slot +0x5C. */
void xb_save_122814(u8* w) {
    s32 r;
    s32 free;

    switch ((s8)w[2]) {
    case 0:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;
        xb_SaveMenuSetMessage(w, 0);
        /* fallthrough */

    case 1:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;
        xb_SaveStateReset(w[0x20], (s8)w[0x5C]);
        xb_SaveStateStartLoad((s8)w[0x50], *(s32*)(w + 0x30), 0);
        /* fallthrough */

    case 2:
        r = xb_SaveStateResult();
        *(s32*)(w + 0x1D8) = r;

        if (r == XB_SAVE_FAILED) {
            xb_SaveMenuMessageWait(w, 0);

            if (w[0x22] == 0) {
                xb_SaveMenuMessageWait(w, w[0x20] == 1 ? 0x28 : 0x39);
            } else {
                xb_SaveMenuMessageWait(w, w[0x20] == 1 ? 0x20 : 0x31);
            }
        } else if (r == XB_SAVE_NOFILE) {
            if ((free = xb_SaveFreeBlocks()) < *(s32*)(w + 0x48)) {
                *(s32*)(w + 0x4C) = *(s32*)(w + 0x48) - free;
                xb_save_1227E9(w);
            } else {
                w[1] = 7;
                w[2] = 0;
            }
        } else if (r == 0) {
            w[1] = 5;
            w[2] = 0;
            w[7] = 7;
            w[8] = 1;
            xb_SaveMenuSetMessage(w, 0x1F);
        }

        break;
    }
}

/* xb_save_122908: a yes/no that leaves when the check on +0x50 fails. */
void xb_save_122908(u8* w) {
    switch ((s8)w[2]) {
    case 0:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;
        w[3] = 0;
        /* fallthrough */

    case 1:
        if (sub_0009B78F((s8)w[0x50]) == 0) {
            xb_SaveMenuQuit(w);
            return;
        }

        switch (xb_SaveMenuYesNo(w)) {
        case 1:
            w[1] = w[7];
            w[2] = 0;
            break;

        case 2:
            w[1] = w[8];
            w[2] = 0;
            break;
        }

        break;
    }
}

/* xb_save_122963: after the result message: done (+0x1F) on success,
 * else back out. */
void xb_save_122963(u8* w) {
    switch ((s8)w[2]) {
    case 0:
        if (w[0x1DC] != 0) {
            break;
        }

        if (*(s32*)(w + 0x1D8) == 0) {
            w[0x1F] = 1;
        }

        w[2]++;
        w[3] = 0;
        /* fallthrough */

    case 1:
        if (xb_SaveMenuWaitOK(w)) {
            break;
        }

        if (*(s32*)(w + 0x1D8) != 0) {
            xb_SaveMenuQuit(w);
            return;
        }

        w[1] = 0xC;
        xb_SaveMenuSetMessage(w, 0);
        break;
    }
}

/* xb_save_122A25: state 3 step 1: reads the system data at boot. */
void xb_save_122A25(u8* w) {
    s32 r;

    switch ((s8)w[2]) {
    case 0:
        w[2]++;
        xb_SaveMenuSetMessage(w, 0);
        /* fallthrough */

    case 1:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;
        /* fallthrough */

    case 2:
        w[2]++;
        *(s32*)(w + 0x30) = xb_SaveMenuBootBuffer(w);
        w[0x20] = 0;
        xb_SaveStateReset(0, 0);
        xb_SaveStateStartHeader(0, *(s32*)(w + 0x30));
        /* fallthrough */

    case 3:
        r = xb_SaveStateResult();
        *(s32*)(w + 0x1D8) = r;

        if (r == XB_SAVE_FAILED) {
            break;
        }

        if (r == XB_SAVE_NOFILE) {
            xb_save_122A08(w);
        } else if (r == 0) {
            xb_save_1229EB(w);
        }

        break;
    }
}

/* xb_save_122AE7: a message; OK goes to step +7. */
void xb_save_122AE7(u8* w) {
    switch ((s8)w[2]) {
    case 0:
        if (w[0x1DC] != 0) {
            return;
        }

        w[2]++;
        w[3] = 0;
        /* fallthrough */

    case 1:
        if (xb_SaveMenuWaitOK(w) == 0) {
            w[1] = w[7];
            w[2] = 0;
        }

        break;
    }
}

/* xb_SaveMenuEnd: state 5, the end: after an optional "save now?"
 * (+0x25), waits for the file reads to end, frees the menu's memory
 * (+0x28) and reports done: +0x1E is 0 when +0x1F (success) is set,
 * else -1. */
void xb_SaveMenuEnd(u8* w) {
    switch ((s8)w[1]) {
    case 0:
        if (w[0x25] == 0) {
            goto close;
        }

        w[1]++;
        w[0x22] = 1;
        xb_SaveMenuSetMessage(w, 0);
        /* fallthrough */

    case 1:
        if (w[0x1DC] != 0) {
            break;
        }

        w[1]++;
        w[3] = 0;
        /* fallthrough */

    case 2:
        switch (xb_SaveMenuYesNo(w)) {
        case 1:
            xb_SaveMenuSetMessage(w, 0);
            goto close;

        case 2:
            xb_SaveMenuQuit(w);
            return;
        }

        break;

    case 10:
    close:
        w[1] = 0xB;
        *(s16*)(w + 0xA) = 10;
        /* fallthrough */

    case 11:
        if (xb_SaveMenuFileBusy()) {
            break;
        }

        if (--*(s16*)(w + 0xA) > 0) {
            break;
        }

        Convert_Buff[0x4A] = save_w[0x22D];
        Forbid_Reset = 0;
        sub_00097103(*(u16*)(w + 0x28));
        w[0x1E] = (w[0x1F] != 0) - 1;
        break;
    }
}

/* xb_SavePrepareSystem: the system data (the current mode's save_w) into the
 * file buffer, scrambled. */
void xb_SavePrepareSystem(u8* w) {
    u8* buf = *(u8**)(w + 0x30);

    memset(buf, 0, 0x218);
    Save_Game_Data();
    memcpy(buf + 0x10, save_w + Present_Mode * 0x208, 0x208);
    xb_SaveEncode(buf, 0x218);
}

/* xb_SavePrepareReplay: a replay into the file buffer: the two characters (also
 * kept at +0x7460), the game info, the settings and directions it was
 * played with, then Replay_w, scrambled. */
void xb_SavePrepareReplay(u8* w) {
    u8* buf = *(u8**)(w + 0x30);
    u8* sw = save_w + Present_Mode * 0x208;
    s32 chr[2];
    s32 i;

    for (i = 0; i < 2; i++) {
        chr[i] = Rep_Game_Infor[0x168 + i * 4];
        ((s32*)(buf + 0x7460))[i] = chr[i];
    }

    memcpy(Replay_w + 0x2C8, Rep_Game_Infor + 0x168, 0x24);
    memcpy(Replay_w + 0x2EC, sw, 0x18);
    Replay_w[0x304] = sw[0x19];
    *(u16*)(Replay_w + 0x305) = *(u16*)(sw + 0x1A);
    Replay_w[0x307] = sw[0x1C];
    memcpy(Replay_w + 0x308, sw + 0x54, 0x20);
    memcpy(Replay_w + 0x328, system_dir + Present_Mode * 0x48, 0x48);
    memcpy(buf + 0x10, Replay_w, 0x1D12 * 4);
    xb_SaveEncode(buf, 0x7458);
}

/* xb_SaveCheckSystem: checks read system data. When it is bad and a is 0,
 * the buffer takes the defaults (save_w[0]) instead. Returns -1 for bad
 * data kept. */
s32 xb_SaveCheckSystem(u8* w, s32 a) {
    u8* buf = *(u8**)(w + 0x30);

    xb_SaveDecode(w, buf, 0x218);

    if (w[0x1DF] == 0 && w[0x1DE] == 0) {
        return 0;
    }

    if (a != 0) {
        return -1;
    }

    memset(buf, 0, 0x218);
    memcpy(buf + 0x10, save_w, 0x208);
    return 0;
}

/* xb_save_122DE0: state 1 step 6: loads the file and applies it. */
void xb_save_122DE0(u8* w) {
    s32 r;

    switch ((s8)w[2]) {
    case 0:
        w[2]++;
        xb_SaveMenuSetMessage(w, 0);
        /* fallthrough */

    case 1:
        if (w[0x1DC] != 0) {
            return;
        }

        w[2]++;
        /* fallthrough */

    case 2:
        w[2]++;
        xb_SaveStateStartLoad(0, *(s32*)(w + 0x30), 1);
        /* fallthrough */

    case 3:
        r = xb_SaveStateResult();
        *(s32*)(w + 0x1D8) = r;

        if (r != XB_SAVE_FAILED) {
            if (r != 0) {
                return;
            }

            if (xb_SaveCheck(w, 1) == 0) {
                xb_SaveApply(w);
                sub_0004384A(w + 0x1C8 + (s8)w[0x50] * 8);
                w[7] = 0xC;
                xb_SaveMenuMessageWait(w, 0xA);
                w[2]++;
                return;
            }

            *(s32*)(w + 0x1D8) = XB_SAVE_FAILED;
        }

        w[7] = 0xC;
        xb_SaveMenuMessageWait(w, 0xC);
        break;
    }
}

/* xb_save_122E91: state 1 step 7: saves the data. */
void xb_save_122E91(u8* w) {
    s32 r;

    switch ((s8)w[2]) {
    case 0:
        w[2]++;
        xb_SaveMenuSetMessage(w, 0);
        /* fallthrough */

    case 1:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;
        xb_SavePrepare(w);
        xb_SaveStateStartWrite((s8)w[0x50], *(s32*)(w + 0x30));
        /* fallthrough */

    case 2:
        r = xb_SaveStateResult();
        *(s32*)(w + 0x1D8) = r;

        if (r == XB_SAVE_FAILED) {
            w[7] = 0xC;
            xb_SaveMenuMessageWait(w, 7);
        } else if (r == 0) {
            xb_SaveCheck(w, 0);
            xb_SaveApply(w);
            w[7] = 0xC;
            xb_SaveMenuMessageWait(w, 3);
            w[0x25] = 0;
        }

        break;
    }
}

/* xb_SaveMenuKind: state 1. */
void xb_SaveMenuKind(u8* w) {
    D_00437F9C[(s8)w[1]](w);
}

/* xb_SaveMenuSlots: state 2, with its screen. */
void xb_SaveMenuSlots(u8* w) {
    D_00437FD0[(s8)w[1]](w);
    xb_SaveMenuDrawList(w);
}

/* xb_SaveMenuBoot: state 3. */
void xb_SaveMenuBoot(u8* w) {
    D_00438004[(s8)w[1]](w);
}

/* xb_save_122F35: state 2 step 3: loads slot +0x5C and applies it. */
void xb_save_122F35(u8* w) {
    s32 r;

    switch ((s8)w[2]) {
    case 0:
        w[2]++;
        xb_SaveMenuSetMessage(w, 0);
        /* fallthrough */

    case 1:
        if (w[0x1DC] != 0) {
            return;
        }

        w[2]++;
        xb_SaveStateReset(w[0x20], (s8)w[0x5C]);
        xb_SaveStateStartRead((s8)w[0x50], *(s32*)(w + 0x30));
        /* fallthrough */

    case 2:
        r = xb_SaveStateResult();
        *(s32*)(w + 0x1D8) = r;

        if (r != XB_SAVE_FAILED) {
            if (r != 0) {
                return;
            }

            if (xb_SaveCheck(w, 1) == 0) {
                xb_SaveApply(w);
                xb_SaveMenuMessageWait(w, w[0x20] == 1 ? 0x26 : 0x37);
                return;
            }

            *(s32*)(w + 0x1D8) = XB_SAVE_FAILED;
        }

        xb_SaveMenuMessageWait(w, w[0x20] == 1 ? 0x28 : 0x39);
        break;
    }
}

/* xb_save_122FE7: state 2 step 7: saves to slot +0x5C, rereads its
 * header (+0x1B8) and puts it in the list. */
void xb_save_122FE7(u8* w) {
    s32 r;

    switch ((s8)w[2]) {
    case 0:
        w[2]++;
        xb_SaveMenuSetMessage(w, 0);
        /* fallthrough */

    case 1:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;
        xb_SavePrepare(w);
        xb_SaveStateReset(w[0x20], (s8)w[0x5C]);
        xb_SaveStateStartWrite(0, *(s32*)(w + 0x30));
        /* fallthrough */

    case 2:
        r = xb_SaveStateResult();
        *(s32*)(w + 0x1D8) = r;

        if (r == XB_SAVE_FAILED) {
            goto fail;
        }

        if (r != 0) {
            break;
        }

        w[2]++;
        xb_SaveStateStartHeader(0, (s32)(w + 0x1B8));
        break;

    case 3:
        r = xb_SaveStateResult();
        *(s32*)(w + 0x1D8) = r;

        if (r == XB_SAVE_FAILED) {
            goto fail;
        }

        if (r != 0) {
            break;
        }

        xb_SaveCheck(w, 0);
        xb_SaveApply(w);
        xb_SaveMenuMessageWait(w, w[0x20] == 1 ? 0x1C : 0x2D);
        w[0x64 + (s8)w[0x58] + (s8)w[0x59]] = w[0x5C];
        memcpy(w + 0x78 + (s8)w[0x5C] * 0x10, w + 0x1B8, 0x10);
        break;

    fail:
        xb_SaveMenuMessageWait(w, w[0x20] == 1 ? 0x20 : 0x31);
        break;
    }
}

/* xb_save_12311A: state 3 step 2: loads the system data at boot. */
void xb_save_12311A(u8* w) {
    s32 r;

    switch ((s8)w[2]) {
    case 0:
        w[2]++;
        xb_SaveMenuSetMessage(w, 0);
        /* fallthrough */

    case 1:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;
        /* fallthrough */

    case 2:
        w[2]++;
        *(s32*)(w + 0x30) = xb_SaveMenuBootBuffer(w);
        xb_SaveStateStartLoad(0, *(s32*)(w + 0x30), 1);
        /* fallthrough */

    case 3:
        r = xb_SaveStateResult();
        *(s32*)(w + 0x1D8) = r;

        if (r != XB_SAVE_FAILED) {
            if (r != 0) {
                break;
            }

            if (xb_SaveCheck(w, 1) == 0) {
                xb_SaveApply(w);
                sub_0004384A(w + 0x1C8 + (s8)w[0x50] * 8);
                xb_SaveMenuSetMessage(w, 0x16);
                w[2]++;
                break;
            }

            *(s32*)(w + 0x1D8) = XB_SAVE_FAILED;
        }

        xb_SaveMenuSetMessage(w, 0x13);
        w[1] = 9;
        w[2] = 0;
        w[7] = 6;
        break;

    case 4:
        if (xb_SaveMenuWaitOK(w)) {
            break;
        }

        w[1] = 0xA;
        xb_SaveMenuSetMessage(w, 0);
        break;
    }
}

/* xb_save_1231F8: state 3 step 7: saves the system data at boot, when
 * there is room. */
void xb_save_1231F8(u8* w) {
    s32 r;
    s32 free;

    switch ((s8)w[2]) {
    case 0:
        w[2]++;
        xb_SaveMenuSetMessage(w, 0);
        /* fallthrough */

    case 1:
        if (w[0x1DC] != 0) {
            break;
        }

        w[2]++;

        if ((free = xb_SaveFreeBlocks()) < *(s32*)(w + 0x48)) {
            *(s32*)(w + 0x4C) = *(s32*)(w + 0x48) - free;
            xb_SaveMenuSetMessage(w, 0x10);
            w[1] = 8;
            w[8] = 0xB;
            w[7] = 0xA;
            w[2] = 0;
            break;
        }

        xb_SavePrepare(w);
        xb_SaveStateStartWrite(0, *(s32*)(w + 0x30));
        /* fallthrough */

    case 2:
        r = xb_SaveStateResult();
        *(s32*)(w + 0x1D8) = r;

        if (r == XB_SAVE_BUSY) {
            break;
        }

        if (r != 0) {
            xb_SaveMenuSetMessage(w, 0x11);
            w[1] = 9;
            w[7] = 5;
        } else {
            xb_SaveCheck(w, 0);
            xb_SaveApply(w);
            xb_SaveMenuSetMessage(w, 0xF);
            w[1] = 9;
            w[0x25] = 0;
            w[7] = 0xA;
        }

        w[2] = 0;
        break;
    }
}

/* The save menu's states (w[0]) and the steps of states 1 (load or save
 * a kind of data), 2 (the slot list) and 3 (boot), and the per-kind
 * prepare, check and apply routines. Entry 4 is the shared empty body. */
void (*D_00437F84[6])(u8* w) = { xb_SaveMenuStart, xb_SaveMenuKind, xb_SaveMenuSlots,
                                 xb_SaveMenuBoot, (void (*)(u8*))sub_0004384A, xb_SaveMenuEnd };
void (*D_00437F9C[13])(u8* w) = { xb_save_1217F8, xb_save_121826, xb_save_1223B8, xb_save_1224A0, xb_save_1225E2,
                                  xb_save_12239B, xb_save_122DE0, xb_save_122E91, xb_save_122AE7, xb_save_122625,
                                  xb_save_121849, xb_SaveMenuLaunchDashboard, xb_save_12197B };
void (*D_00437FD0[13])(u8* w) = { xb_save_1218C4, xb_save_121923, xb_SaveMenuList, xb_save_122F35, xb_save_122814,
                                  xb_save_122908, xb_save_1227E9, xb_save_122FE7, xb_save_122963, xb_save_1229C0,
                                  xb_save_121960, xb_SaveMenuLaunchDashboard, xb_save_12197B };
void (*D_00438004[12])(u8* w) = { xb_save_12199F, xb_save_122A25, xb_save_12311A, xb_save_1229EB,
                                  xb_save_122AAD, xb_save_122ACA, xb_save_122A08, xb_save_1231F8,
                                  xb_save_1225E2, xb_save_122AE7, xb_save_1219DF, xb_SaveMenuLaunchDashboard };
void (*D_00438034[3])(u8* w) = { xb_SavePrepareSystem, xb_SavePrepareDirection, xb_SavePrepareReplay };
s32 (*D_00438040[3])(u8* w, s32 a) = { xb_SaveCheckSystem, xb_SaveCheckDirection, xb_SaveCheckReplay };
void (*D_0043804C[3])(u8* w) = { xb_SaveApplySystem, xb_SaveApplyDirection, xb_SaveApplyReplay };

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
