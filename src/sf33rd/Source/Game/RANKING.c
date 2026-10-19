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
 * and Ranking_01_5th fades with 1638.
 * Setup_grade is 0x97297 size 0xFB, interior after the jmp.
 * Name_Sub is 0x97392 size 0x56, interior after the ret.
 * Setup_Face is 0x973E8 size 0x6D, interior after the ret.
 * Setup_Score is 0x97455 size 0xE2 and is a scanned start.
 * Setup_Wins is 0x97537 size 0x1A0, interior after the ret.
 * Setup_Wins2 is 0x976D7 size 0x17B, interior after the jmp.
 * Setup_Name is 0x9799D size 0x3A, interior after the ret.
 * Ranking_00_2nd is 0x979D7 size 0x362, interior after the ret.
 * Ranking_01_2nd is 0x97D39 size 0x342, interior after the ret.
 * Rank is 0x7A8332. Rank_X is 0x7A8228. Rank_Pos_X is 0x7A836E.
 * Rank_Pos_Y is 0x7A891C. Flash_Rank_Time is 0x7A8151.
 * Flash_Rank_Interval is 0x7A8354. Order[85] is 0x7A83D5.
 * Order_Timer[85] is 0x7A84D5. Order_Dir[85] is 0x7A8635.
 * base_y_pos is 0x7BC516. Ranking_Data is 0xC7C840. G_No[1] is 0x7A825D.
 * My_char[0] is 0x7A8114. bg_w.stage is the byte at 0x7BC523.
 * Setup_Score and Setup_Wins2 check the stack cookie through 0x175BFC.
 * Setup_Wins tails into 0x175BFC. The C does not call it.
 * The PlayStation 2 grade test against 0xFF is a sign-extended compare
 * with 255, so this build keeps that byte.
 * Ranking_00_2nd and Ranking_01_2nd fold the Rank_Pos adds around
 * Setup_Name and Setup_Face. Setup_Face adds the flash interval once,
 * shifted. 0x5457C, 0x59E20, and 0x5A0C0 are effect_76_init,
 * Push_LDREQ_Queue_Player, and Push_LDREQ_Queue_BG. 0x98407 stays
 * unnamed because Sound_SE and BGM_Request share that body. 0x9A2FD is
 * System_all_clear_Level_B.
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

typedef struct {
    u8 name[3];
    u8 pad;
    u16 player;
    u32 score;
    s8 cpu_grade;
    s8 grade;
    u16 wins;
    u8 player_color;
    u8 all_clear;
    u8 tail[2];
} RANK_DATA;

#if defined(__i386__)
_Static_assert(sizeof(RANK_DATA) == 0x14, "RANK_DATA");
_Static_assert(__builtin_offsetof(RANK_DATA, player) == 4, "player");
_Static_assert(__builtin_offsetof(RANK_DATA, score) == 8, "score");
_Static_assert(__builtin_offsetof(RANK_DATA, cpu_grade) == 0xC, "cpu_grade");
_Static_assert(__builtin_offsetof(RANK_DATA, grade) == 0xD, "grade");
_Static_assert(__builtin_offsetof(RANK_DATA, wins) == 0xE, "wins");
_Static_assert(__builtin_offsetof(RANK_DATA, all_clear) == 0x11, "all_clear");
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
extern s8 Rank;
extern s8 Rank_X;
extern s16 Rank_Pos_X;
extern s16 Rank_Pos_Y;
extern s8 Flash_Rank_Time;
extern s8 Flash_Rank_Interval;
extern u8 Order[148];
extern u8 Order_Timer[148];
extern u8 Order_Dir[148];
extern s16 base_y_pos;
extern RANK_DATA Ranking_Data[20];
extern u8 G_No[4];
extern u8 My_char[2];

extern void System_all_clear_Level_B(void);
extern void bg_etc_write(s16 type);
extern void bg_pos_hosei2(void);
extern void Bg_Family_Set(void);
extern void make_texcash_work(s16 ix);
extern void sub_0004384A(s32 key);
extern void Purge_mmtm_area(s32 kind);
extern void Make_texcash_of_list(s32 kind);
extern void sub_00098407(s16 code);
extern void effect_58_init(s16 id, s16 time0, s16 option);
extern void effect_67_init(s16 id, s16 x, s16 y, s16 time0, s16 chr, s16 prio, s16 no, s16 col);
extern void Game01_Sub(void);
extern void effect_76_init(s16 dir);
extern void Setup_Demo_PL(void);
extern void Setup_Demo_Arts(void);
extern void Setup_Demo_Stage(void);
extern void Push_LDREQ_Queue_Player(s16 id, s16 ix);
extern void Push_LDREQ_Queue_BG(s32 stage);
extern s32 Switch_Screen(u8 wipe_type);
extern void Switch_Screen_Init(void);
extern void Clear_Personal_Data(s16 pl_id);
extern void BG_Draw_System(void);
extern void SsBgmFadeOut(u16 time);

void Ranking_00_1st(void);
void Ranking_00_2nd(void);
void Ranking_00_3rd(void);
void Setup_grade(s16 y);
void Setup_Name(s16 y);
void Name_Sub(s16 xx, s16 y);
void Setup_Face(s16 y);
void Setup_Score(s16 y);
void Setup_Wins(s16 y);
void Setup_Wins2(s16 y);
void Ranking_00_4th(void);
void Ranking_00_5th(void);
void Ranking_00_6th(void);
void Ranking_01_1st(void);
void Ranking_01_2nd(void);
void Ranking_01_4th(void);
void Ranking_01_5th(void);
void Ranking_Sub(void);
void Ranking_00(void);
void Ranking_01(void);

/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const RANK_DATA Score_Ranking_Table[20] = { { { 28, 13, 22 }, 0,
                                              15,
                                              100000,
                                              10,
                                              0,
                                              10,
                                              0,
                                              1 },
                                            { { 22, 24, 24 }, 0,
                                              16,
                                              90000,
                                              9,
                                              0,
                                              9,
                                              1,
                                              0 },
                                            { { 23, 14, 24 }, 0,
                                              17,
                                              80000,
                                              8,
                                              0,
                                              8,
                                              2,
                                              1 },
                                            { { 24, 23, 30 }, 0,
                                              18,
                                              70000,
                                              7,
                                              0,
                                              7,
                                              3,
                                              0 },
                                            { { 34, 24, 20 }, 0,
                                              19,
                                              60000,
                                              6,
                                              0,
                                              6,
                                              4,
                                              0 },
                                            { { 20, 10, 18 }, 0,
                                              15,
                                              100000,
                                              10,
                                              10,
                                              10,
                                              0,
                                              1 },
                                            { { 21, 29, 1 }, 0,
                                              16,
                                              90000,
                                              9,
                                              9,
                                              9,
                                              1,
                                              0 },
                                            { { 34, 30, 20 }, 0,
                                              17,
                                              80000,
                                              8,
                                              8,
                                              8,
                                              2,
                                              1 },
                                            { { 27, 10, 24 }, 0,
                                              18,
                                              70000,
                                              7,
                                              7,
                                              7,
                                              3,
                                              0 },
                                            { { 0, 0, 8 }, 0,
                                              19,
                                              60000,
                                              6,
                                              6,
                                              6,
                                              4,
                                              0 },
                                            { { 18, 12, 17 }, 0,
                                              15,
                                              100000,
                                              11,
                                              0,
                                              10,
                                              0,
                                              1 },
                                            { { 28, 14, 29 }, 0,
                                              5,
                                              90000,
                                              9,
                                              0,
                                              9,
                                              1,
                                              0 },
                                            { { 23, 14, 24 }, 0,
                                              4,
                                              80000,
                                              8,
                                              0,
                                              8,
                                              2,
                                              1 },
                                            { { 24, 23, 30 }, 0,
                                              10,
                                              70000,
                                              7,
                                              0,
                                              7,
                                              3,
                                              0 },
                                            { { 34, 24, 20 }, 0,
                                              8,
                                              60000,
                                              6,
                                              0,
                                              6,
                                              4,
                                              0 },
                                            { { 18, 23, 14 }, 0,
                                              19,
                                              100000,
                                              11,
                                              11,
                                              10,
                                              0,
                                              1 },
                                            { { 21, 29, 1 }, 0,
                                              1,
                                              90000,
                                              9,
                                              9,
                                              9,
                                              1,
                                              0 },
                                            { { 34, 30, 20 }, 0,
                                              4,
                                              80000,
                                              8,
                                              8,
                                              8,
                                              2,
                                              1 },
                                            { { 27, 10, 24 }, 0,
                                              10,
                                              70000,
                                              7,
                                              7,
                                              7,
                                              3,
                                              0 },
                                            { { 18, 23, 14 }, 0,
                                              8,
                                              60000,
                                              6,
                                              6,
                                              6,
                                              4,
                                              0 } };

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
            Game01_Sub();
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
    System_all_clear_Level_B();

    if (Rank_Type == 0) {
        bg_etc_write(1);
    } else {
        bg_etc_write(6);
    }

    bg_pos_hosei2();
    Bg_Family_Set();
}

void Setup_grade(s16 y) {
    s16 Char_Index;

    switch (Rank_Type) {
    case 0:
        Char_Index = Ranking_Data[Rank].cpu_grade;
        break;

    case 5:
    case 10:
    case 15:
        Char_Index = Ranking_Data[Rank].grade;
        break;
    }

    effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, (s16)(Char_Index + 98), 10, y, 0);

    if (Rank_Type == 0) {
        Rank_Pos_X += 16;

        if (Ranking_Data[Rank].all_clear) {
            Rank_Pos_Y += 16;
            effect_67_init(26, (s16)(Rank_Pos_X - 4), (s16)(Rank_Pos_Y + 3), 180, 74, 10, y, 0);
            Rank_Pos_Y -= 16;
        }

        Rank_Pos_X -= 16;
    }

    Rank_Pos_X += 48;
}

void Name_Sub(s16 xx, s16 y) {
    effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, Ranking_Data[Rank].name[xx], 10, y, 0);
    Flash_Rank_Time += Flash_Rank_Interval;
    Rank_Pos_X += 24;
}

void Setup_Face(s16 y) {
    Rank_Pos_Y += 16;
    effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, (s16)(Ranking_Data[Rank].player + 47), 10, y, 1);
    Flash_Rank_Time += Flash_Rank_Interval;
    Rank_Pos_X += 40;
    Rank_Pos_Y -= 16;
    Rank_X += 2;
    Flash_Rank_Time += Flash_Rank_Interval;
}

void Setup_Score(s16 y) {
    s16 i;
    s16 First_Digit;
    u32 xx;
    u32 Score_Buff;
    s16 Digit[8];

    Score_Buff = Ranking_Data[Rank].score;
    First_Digit = -1;

    for (i = 7, xx = 10000000; i > 0; i--, xx /= 10) {
        Digit[i] = (s16)(Score_Buff / xx);
        Score_Buff -= xx * Digit[i];

        if ((First_Digit < 0) && Digit[i]) {
            First_Digit = i;
        }
    }

    Digit[0] = (s16)Score_Buff;

    if (First_Digit < 0) {
        First_Digit = 0;
    }

    for (i = 0, xx = 7; i < 8; i++, xx--) {
        Flash_Rank_Time += Flash_Rank_Interval;
        Rank_Pos_X += 16;

        if (First_Digit >= (s16)xx) {
            effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, (s16)(Digit[xx] + 75), 10, y, 0);
        }
    }

    Rank_Pos_X += 24;
}

void Setup_Wins(s16 y) {
    u32 Score_Buff;
    s16 Digit[3];

    Score_Buff = Ranking_Data[Rank].wins;
    Digit[2] = (s16)(Score_Buff / 100);
    Score_Buff -= Digit[2] * 100;
    Digit[1] = (s16)(Score_Buff / 10);
    Digit[0] = (s16)(Score_Buff -= Digit[1] * 10);

    if (Digit[2]) {
        effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, (s16)(Digit[2] + 130), 10, y, 0);
        Rank_Pos_X += 16;
        effect_67_init(26, (s16)(Rank_Pos_X + 3), Rank_Pos_Y, 180, (s16)(Digit[1] + 130), 10, y, 0);
        Rank_Pos_X += 16;
    } else {
        Rank_Pos_X += 16;

        if (Digit[1]) {
            effect_67_init(26, (s16)(Rank_Pos_X + 3), Rank_Pos_Y, 180, (s16)(Digit[1] + 130), 10, y, 0);
        }

        Rank_Pos_X += 16;
    }

    Rank_X += 1;
    Flash_Rank_Time += Flash_Rank_Interval;
    effect_67_init(26, (s16)(Rank_Pos_X + 6), Rank_Pos_Y, 180, (s16)(Digit[0] + 130), 10, y, 0);
    Rank_Pos_X += 40;
    Rank_X += 1;
    Flash_Rank_Time += Flash_Rank_Interval;
    effect_67_init(24, Rank_Pos_X, Rank_Pos_Y, 180, 6, 10, y, 0);
    Rank_Pos_X += 64;
    Rank_X += 1;
}

void Setup_Wins2(s16 y) {
    u32 Score_Buff;
    s16 Digit[3];

    Score_Buff = Ranking_Data[Rank].wins;
    Digit[2] = (s16)(Score_Buff / 100);
    Score_Buff -= Digit[2] * 100;
    Digit[1] = (s16)(Score_Buff / 10);
    Digit[0] = (s16)(Score_Buff -= Digit[1] * 10);

    if (Digit[2]) {
        effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, (s16)(Digit[2] + 75), 10, y, 0);
        Rank_Pos_X += 16;
        effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, (s16)(Digit[1] + 75), 10, y, 0);
        Rank_Pos_X += 16;
    } else {
        Rank_Pos_X += 16;

        if (Digit[1]) {
            effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, (s16)(Digit[1] + 75), 10, y, 0);
        }

        Rank_Pos_X += 16;
    }

    Rank_X += 1;
    Flash_Rank_Time += Flash_Rank_Interval;
    effect_67_init(26, Rank_Pos_X, Rank_Pos_Y, 180, (s16)(Digit[0] + 75), 10, y, 0);
    Rank_Pos_X += 40;
    effect_67_init(24, Rank_Pos_X, (s16)(Rank_Pos_Y + 8), 180, 11, 10, y, 0);
    Rank_X += 1;
    Flash_Rank_Time += Flash_Rank_Interval;
}

void Setup_Ranking_Obj(void) {
    effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos - 143), (s16)(bg_w.bgw[0].xy[1].disp.pos + 32), 180, 4, 30,
        0, 0);
}

void Setup_Score_Obj(void) {
    if (Rank_Type == 0) {
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos, (s16)(bg_w.bgw[0].xy[1].disp.pos + 200), 180, 0, 10, 1, 0);
        effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos - 384), (s16)(bg_w.bgw[0].xy[1].disp.pos + 200), 180, 1,
            10, 1, 0);
        return;
    }

    effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos, (s16)(bg_w.bgw[0].xy[1].disp.pos + 200), 180, 2, 10, 1, 0);
    effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos - 384), (s16)(bg_w.bgw[0].xy[1].disp.pos + 200), 180, 3, 10,
        1, 0);
}

void Ranking_00_1st(void) {
    make_texcash_work(14);
    D_No[1]++;
    Demo_Type = 0;
    Flash_Sign[0] = 1;
    Ranking_Sub();
    sub_0004384A(4);
}

void Ranking_01_1st(void) {
    Switch_Screen(1);
    sub_00098407(57);
    Purge_mmtm_area(4);
    Make_texcash_of_list(2);
    make_texcash_work(14);
    D_No[1]++;
    Suicide[0] = 0;
    Present_Rank[0] = 99;
    Present_Rank[1] = 99;
    Ranking_Sub();
    effect_58_init(1, 1, -1);
    sub_0004384A(4);
}

void Setup_Name(s16 y) {
    Name_Sub(0, y);
    Name_Sub(1, y);
    Name_Sub(2, y);

    if (Rank_Type == 0) {
        (void)Rank_Pos_X;
    } else {
        Rank_Pos_X += 16;
    }

    Rank_X += 3;
}

void Ranking_00_2nd(void) {
    s16 Char_Index;

    D_No[1]++;
    D_Timer = 1;
    Rank_X = 0;
    Flash_Rank_Time = 0;
    Rank_Pos_X = (s16)(bg_w.bgw[0].xy[0].disp.pos - 104);
    Rank_Pos_Y = (s16)(bg_w.bgw[0].xy[1].disp.pos + 160);

    if (Rank_Type >= 10) {
        Order[85] = 3;
        Order_Timer[85] = 1;
        Order_Dir[85] = (u8)Rank_Type;
        effect_76_init(85);
        effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos + 128), (s16)(bg_w.bgw[0].xy[1].disp.pos + 80), 180, 10,
            35, 5, 0);
        effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos + 120), (s16)(bg_w.bgw[0].xy[1].disp.pos + 40), 180, 13,
            35, 5, 0);
        effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos - 144), (s16)(bg_w.bgw[0].xy[1].disp.pos + 68), 180, 7,
            30, 5, 0);
        base_y_pos = 40;

        switch (Rank_Type) {
        case 10:
            Char_Index = Ranking_Data[10].cpu_grade;
            break;

        case 15:
            Char_Index = Ranking_Data[15].grade;
            break;
        }

        effect_67_init(0, (s16)(bg_w.bgw[0].xy[0].disp.pos - 136), (s16)(bg_w.bgw[0].xy[1].disp.pos + 60), 180,
            Char_Index, 10, 6, 1);
        Rank_Pos_X = (s16)(bg_w.bgw[0].xy[0].disp.pos - 72);
        Rank_Pos_Y = (s16)(bg_w.bgw[0].xy[1].disp.pos + 120);
        Rank_Pos_X += 16;
        Rank_Pos_Y -= 48;
        Rank = Rank_Type;
        Rank_Pos_Y -= 1;
        Setup_Name(5);
        Rank_Pos_Y += 1;
        Rank_Pos_X += 16;
        Rank_Pos_Y += 1;
        Rank_Pos_Y += 256;
        Setup_Face(5);
        Rank_Pos_Y -= 256;
        Rank_Pos_Y -= 1;
        Rank_Pos_X -= 32;
        Rank_Pos_Y -= 40;

        if (Rank_Type == 10) {
            Rank_Pos_X -= 80;
            Setup_Score(5);
        } else {
            Rank_Pos_X -= 32;
            Setup_Wins2(5);
        }
    } else {
        effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos - 143), (s16)(bg_w.bgw[0].xy[1].disp.pos + 32), 180, 4,
            30, 5, 0);

        for (Rank = Rank_Type; Rank < (Rank_Type + 5); Rank++) {
            if ((Present_Rank[0] == (Rank - Rank_Type)) || (Present_Rank[1] == (Rank - Rank_Type))) {
                Flash_Rank_Interval = 1;
            } else {
                Flash_Rank_Interval = 0;
            }

            Setup_Name(5);

            if (Rank_Type == 0) {
                Setup_Score(5);
                Rank_Pos_X += 3;
                Setup_grade(5);
                Rank_Pos_X -= 3;
            } else {
                Setup_Wins(5);
                Setup_grade(5);
            }

            Setup_Face(5);
            Rank_Pos_X = (s16)(bg_w.bgw[0].xy[0].disp.pos - 104);
            Rank_Pos_Y -= 32;
            Rank_X = 0;
            Flash_Rank_Time = 0;
        }

        if ((Present_Rank[0] < 5) || (Present_Rank[1] < 5)) {
            D_No[1] += 1;
        } else {
            D_No[1] = 4;
        }
    }

    switch (Rank_Type) {
    case 0:
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos, (s16)(bg_w.bgw[0].xy[1].disp.pos + 200), 180, 0, 10, 5, 0);
        effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos + 168), (s16)(bg_w.bgw[0].xy[1].disp.pos + 32), 180, 5,
            20, 5, 0);
        return;

    case 5:
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos, (s16)(bg_w.bgw[0].xy[1].disp.pos + 200), 180, 2, 10, 5, 0);
        effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos + 168), (s16)(bg_w.bgw[0].xy[1].disp.pos + 32), 180, 5,
            20, 5, 0);
        return;

    case 10:
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos, (s16)(bg_w.bgw[0].xy[1].disp.pos + 200), 180, 1, 10, 5, 0);
        return;

    case 15:
        effect_67_init(24, bg_w.bgw[0].xy[0].disp.pos, (s16)(bg_w.bgw[0].xy[1].disp.pos + 200), 180, 3, 10, 5, 0);
    }
}

void Ranking_01_2nd(void) {
    s16 Char_Index;

    Switch_Screen(1);
    D_No[1]++;
    D_Timer = 420;
    Rank_X = 0;
    Flash_Rank_Time = 0;
    Rank_Pos_X = (s16)(bg_w.bgw[0].xy[0].disp.pos - 104);
    Rank_Pos_Y = (s16)(bg_w.bgw[0].xy[1].disp.pos + 160);
    Setup_Ranking_Obj();
    Setup_Score_Obj();

    if (Rank_Type == 0) {
        effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos + 168), (s16)(bg_w.bgw[0].xy[1].disp.pos + 32), 180, 5,
            20, 0, 0);
    } else {
        effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos + 168), (s16)(bg_w.bgw[0].xy[1].disp.pos + 32), 180, 5,
            20, 0, 0);
    }

    for (Rank = Rank_Type; Rank < (Rank_Type + 5); Rank++) {
        if ((Present_Rank[0] == (Rank - Rank_Type)) || (Present_Rank[1] == (Rank - Rank_Type))) {
            Flash_Rank_Interval = 1;
        } else {
            Flash_Rank_Interval = 0;
        }

        Setup_Name(0);

        if (Rank_Type == 0) {
            Setup_Score(0);
            Rank_Pos_X += 4;
            Setup_grade(0);
            Rank_Pos_X -= 4;
        } else {
            Setup_Wins(0);
            Setup_grade(0);
        }

        Setup_Face(0);
        Rank_Pos_X = (s16)(bg_w.bgw[0].xy[0].disp.pos - 104);
        Rank_Pos_Y -= 32;
        Rank_X = 0;
        Flash_Rank_Time = 0;
    }

    Order[85] = 1;
    Order_Timer[85] = 180;
    Order_Dir[85] = (u8)(Rank_Type + 10);
    effect_76_init(85);
    effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos + 512), (s16)(bg_w.bgw[0].xy[1].disp.pos + 80), 180, 10, 35,
        0, 0);
    effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos + 504), (s16)(bg_w.bgw[0].xy[1].disp.pos + 40), 180, 13, 35,
        0, 0);
    effect_67_init(24, (s16)(bg_w.bgw[0].xy[0].disp.pos + 240), (s16)(bg_w.bgw[0].xy[1].disp.pos + 68), 180, 7, 30,
        0, 0);
    base_y_pos = 40;

    switch (Rank_Type) {
    case 0:
        Char_Index = Ranking_Data[10].cpu_grade;
        break;

    case 5:
        Char_Index = Ranking_Data[15].grade;
        break;
    }

    effect_67_init(0, (s16)(bg_w.bgw[0].xy[0].disp.pos + 248), (s16)(bg_w.bgw[0].xy[1].disp.pos + 60), 180,
        Char_Index, 10, 2, 1);
    Rank_Pos_X = (s16)(bg_w.bgw[0].xy[0].disp.pos + 312);
    Rank_Pos_Y = (s16)(bg_w.bgw[0].xy[1].disp.pos + 120);
    Rank_Pos_X += 16;
    Rank_Pos_Y -= 48;
    Rank = (s8)(Rank_Type + 10);
    Rank_Pos_Y -= 1;
    Setup_Name(0);
    Rank_Pos_Y += 1;
    Rank_Pos_X += 16;
    Rank_Pos_Y += 1;
    Rank_Pos_Y += 256;
    Setup_Face(0);
    Rank_Pos_Y -= 256;
    Rank_Pos_Y -= 1;
    Rank_Pos_X -= 32;
    Rank_Pos_Y -= 40;

    if (Rank_Type == 0) {
        Rank_Pos_X -= 80;
        Setup_Score(0);
    } else {
        Rank_Pos_X -= 32;
        Setup_Wins2(0);
    }

    Rank -= 10;

    if ((Present_Rank[0] < 5) || (Present_Rank[1] < 5)) {
        D_No[1]++;
    } else {
        D_No[1] = 4;
    }

    if (G_No[1] < 6) {
        Setup_Demo_PL();
        Setup_Demo_Arts();
        Setup_Demo_Stage();
        Push_LDREQ_Queue_Player(0, My_char[0]);
        Push_LDREQ_Queue_Player(1, My_char[1]);
        Push_LDREQ_Queue_BG(bg_w.stage);
    }
}

void Ranking_00(void) {
    void (*Ranking_00_tbl[6])(void) = { Ranking_00_1st, Ranking_00_2nd, Ranking_00_3rd,
        Ranking_00_4th, Ranking_00_5th, Ranking_00_6th };

    Ranking_X = 0;
    Ranking_00_tbl[D_No[1]]();
}

void Ranking_01(void) {
    void (*Ranking_01_tbl[5])(void) = { Ranking_01_1st, Ranking_01_2nd, Ranking_00_3rd, Ranking_01_4th,
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
