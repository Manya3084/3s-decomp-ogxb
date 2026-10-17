/* Ranking screen, retail sf33rd.xbe.
 * Ranking_00_3rd is 0x97146 size 0x19, interior after the ret.
 * Ranking_00_4th is 0x9715F size 0x27, interior after the ret.
 * Ranking_00_5th is 0x97186 size 0x20, interior after the ret.
 * Ranking_00_6th is 0x971A6 size 0x2E, interior after the ret.
 * Ranking_01_4th is 0x971D4 size 0x19, interior after the ret.
 * Ranking_01_5th is 0x971ED size 0x86, interior after the ret.
 * Ranking_Sub is 0x97273 size 0x24, interior after the jmp.
 * Setup_Ranking_Obj is 0x97852 size 0x2C, interior after the ret.
 * Setup_Score_Obj is 0x9787E size 0x7B, interior after the ret.
 * Ranking_00_1st is 0x9791A size 0x2A, interior after the ret.
 * Ranking_01_1st is 0x97944 size 0x59, interior after the ret.
 * Ranking_00 is 0x9807B size 0x44 and is a scanned start.
 * Ranking_01 is 0x980BF size 0x36 and is a scanned start.
 * Ranking is 0x980F5 size 0x31 and is a scanned start.
 * D_No[0] is 0x7A8200. D_Timer is the word at 0x7A892E.
 * Flash_Sign[0] is 0x7A819A. Ranking_X is the dword at 0x7A829C.
 * Rank_Type is the byte at 0x7A892C. Demo_Type is 0x7A8336.
 * Demo_Flag is 0x7A842D. Suicide[0] is 0x7A8268.
 * Present_Rank[0] is 0x7A8450. Cover_Timer is 0x7A81F4.
 * Ranking does not test Debug_w[24]. Ranking_00_6th fades with 546
 * and Ranking_01_5th fades with 1638. 0x979D7 and 0x97D39 stay
 * unnamed. 0x98407 stays unnamed because Sound_SE and BGM_Request
 * share that body. 0x9A2FD stays unnamed.
 */

#include "types.h"

typedef union {
    s32 cal;
    struct {
        s16 low;
        s16 pos;
    } disp;
} XY;

typedef struct {
    u8 raw0[0xA];
    s16 position_x;
    s16 position_y;
    u8 raw1[0x18 - 0xE];
    XY xy[2];
    XY wxy[2];
    u8 raw2[0x30 - 0x28];
    s16 old_pos_x;
    u8 raw3[0x90 - 0x32];
} BGW;

typedef struct {
    u8 raw0[3];
    s8 stage;
    u8 raw1[0x38 - 4];
    BGW bgw[7];
} BG;

#if defined(__i386__)
_Static_assert(sizeof(XY) == 4, "XY");
_Static_assert(__builtin_offsetof(XY, disp.pos) == 2, "XY.disp.pos");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BGW, xy) == 0x18, "xy");
_Static_assert(sizeof(BG) == 0x428, "BG");
_Static_assert(__builtin_offsetof(BG, bgw) == 0x38, "bgw");
#endif

extern u8 D_No[4];
extern s16 D_Timer;
extern s8 Flash_Sign[2];
extern s32 Ranking_X;
extern s8 Rank_Type;
extern s8 Demo_Type;
extern s8 Demo_Flag;
extern s8 Suicide[8];
extern u8 Present_Rank[2];
extern s8 Cover_Timer;
extern BG bg_w;

extern void sub_000979D7(void);
extern void sub_00097D39(void);
extern void sub_0009A2FD(void);
extern void sub_000B3CE5(s16 type);
extern void sub_000B3886(void);
extern void sub_000B3661(void);
extern void sub_000EF72E(s16 ix);
extern void sub_0004384A(s32 key);
extern void sub_00061CDD(s32 kind);
extern void sub_00061CAB(s32 kind);
extern void sub_00098407(s16 code);
extern void sub_0003E138(s16 id, s16 time0, s16 option);
extern void sub_0003FC4C(s16 id, s16 x, s16 y, s16 time0, s16 chr, s16 prio, s16 no, s16 col);
extern void sub_0005A545(void);
extern s32 Switch_Screen(u8 wipe_type);
extern void Switch_Screen_Init(void);
extern void Clear_Personal_Data(s16 pl_id);
extern void BG_Draw_System(void);
extern void SsBgmFadeOut(u16 time);

void Ranking_00_1st(void);
void Ranking_00_3rd(void);
void Ranking_00_4th(void);
void Ranking_00_5th(void);
void Ranking_00_6th(void);
void Ranking_01_1st(void);
void Ranking_01_4th(void);
void Ranking_01_5th(void);
void Ranking_Sub(void);
void Ranking_00(void);
void Ranking_01(void);

void Ranking_00_3rd(void) {
    if (Flash_Sign[0] == 1) {
        D_No[1]++;
        D_Timer = 1;
    }
}

void Ranking_00_4th(void) {
    if (!(--D_Timer)) {
        D_No[1]++;
        D_Timer = 30;
        Flash_Sign[0] = 0;
        Flash_Sign[1] = 1;
    }
}

void Ranking_00_5th(void) {
    if (--D_Timer == 0) {
        D_No[1]++;
        D_Timer = 300;
        Flash_Sign[1] = 0;
    }
}

void Ranking_00_6th(void) {
    if (--D_Timer == 0) {
        D_Timer = 1;
        Ranking_X = 1;
        return;
    }

    if (D_Timer == 60) {
        SsBgmFadeOut(546);
    }
}

void Ranking_01_4th(void) {
    if (!(--D_Timer)) {
        D_No[1]++;
        D_Timer = 240;
    }
}

void Ranking_01_5th(void) {
    switch (D_No[2]) {
    case 0:
        if (!(--D_Timer)) {
            D_No[2] += 1;

            if (Demo_Flag == 0 && Demo_Type == 0) {
                Clear_Personal_Data(0);
                Clear_Personal_Data(1);
            }

            Switch_Screen_Init();
            SsBgmFadeOut(1638);
        }

        break;

    case 1:
        if (Switch_Screen(0) != 0) {
            D_No[2] += 1;
            sub_0005A545();
            Cover_Timer = 24;
            return;
        }

        break;

    default:
        Switch_Screen(1);
        Ranking_X = 1;
        break;
    }
}

void Ranking_Sub(void) {
    sub_0009A2FD();

    if (Rank_Type == 0) {
        sub_000B3CE5(1);
    } else {
        sub_000B3CE5(6);
    }

    sub_000B3886();
    sub_000B3661();
}

void Setup_Ranking_Obj(void) {
    sub_0003FC4C(24, (s16)(bg_w.bgw[0].xy[0].disp.pos - 143), (s16)(bg_w.bgw[0].xy[1].disp.pos + 32), 180, 4, 30,
        0, 0);
}

void Setup_Score_Obj(void) {
    if (Rank_Type == 0) {
        sub_0003FC4C(24, bg_w.bgw[0].xy[0].disp.pos, (s16)(bg_w.bgw[0].xy[1].disp.pos + 200), 180, 0, 10, 1, 0);
        sub_0003FC4C(24, (s16)(bg_w.bgw[0].xy[0].disp.pos - 384), (s16)(bg_w.bgw[0].xy[1].disp.pos + 200), 180, 1,
            10, 1, 0);
        return;
    }

    sub_0003FC4C(24, bg_w.bgw[0].xy[0].disp.pos, (s16)(bg_w.bgw[0].xy[1].disp.pos + 200), 180, 2, 10, 1, 0);
    sub_0003FC4C(24, (s16)(bg_w.bgw[0].xy[0].disp.pos - 384), (s16)(bg_w.bgw[0].xy[1].disp.pos + 200), 180, 3, 10,
        1, 0);
}

void Ranking_00_1st(void) {
    sub_000EF72E(14);
    D_No[1]++;
    Demo_Type = 0;
    Flash_Sign[0] = 1;
    Ranking_Sub();
    sub_0004384A(4);
}

void Ranking_01_1st(void) {
    Switch_Screen(1);
    sub_00098407(57);
    sub_00061CDD(4);
    sub_00061CAB(2);
    sub_000EF72E(14);
    D_No[1]++;
    Suicide[0] = 0;
    Present_Rank[0] = 99;
    Present_Rank[1] = 99;
    Ranking_Sub();
    sub_0003E138(1, 1, -1);
    sub_0004384A(4);
}

void Ranking_00(void) {
    void (*Ranking_00_tbl[6])(void) = { Ranking_00_1st, sub_000979D7, Ranking_00_3rd,
        Ranking_00_4th, Ranking_00_5th, Ranking_00_6th };

    Ranking_X = 0;
    Ranking_00_tbl[D_No[1]]();
}

void Ranking_01(void) {
    void (*Ranking_01_tbl[5])(void) = { Ranking_01_1st, sub_00097D39, Ranking_00_3rd, Ranking_01_4th,
        Ranking_01_5th };

    Ranking_01_tbl[D_No[1]]();
}

s32 Ranking(void) {
    void (*main_jmp_tbl[2])(void) = { Ranking_01, Ranking_00 };

    Ranking_X = 0;
    main_jmp_tbl[D_No[0]]();
    BG_Draw_System();
    return Ranking_X;
}
