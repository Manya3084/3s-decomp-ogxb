/* Win.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Win_1st 0x9D0FC size 0xED.
 * Win_3rd 0x9D1E9 size 0xC6. Read against the x86: 0xFF is the byte store of
 * Forbid_Break = -1. The C is the PS2 C.
 * Win_4th 0x9D2AF size 0x27.
 * Win_5th 0x9D2D6 size 0x5E.
 * Win_6th 0x9D334 size 0x8.
 * Lose_2nd 0x9D33C size 0x90.
 * Lose_3rd 0x9D3CC size 0x5C. Read against the x86: 0xFF is the byte store of
 * Forbid_Break = -1. The C is the PS2 C.
 * Setup_Wins_OBJ 0x9D428 size 0xAF.
 * Win_2nd 0x9D4D7 size 0x133.
 * Loser_Scene 0x9D60A size 0x64.
 * Winner_Scene 0x9D66E size 0x64.
 * BGM_Request is folded into 0x98407.
 * setup_pos_remake_key is folded into 0x4384A.
 * Data: WIN_X 0x7BD3C8.
 * Globals: PL_Color_Data 0x267F4C, M_No 0x7A80B4, My_char 0x7A8114,
 * VS_Win_Record 0x7A8128, Play_Type 0x7A812D, Win_Record 0x7A8164, Play_Mode
 * 0x7A8178, Cover_Timer 0x7A81F4, Mode_Type 0x7A825A, LOSER 0x7A82FD, M_Timer
 * 0x7A8320, Order 0x7A8380, Scene_Cut 0x7A8461, Winner_id 0x7A8472,
 * Order_Timer 0x7A8480, Unsubstantial_BG 0x7A851C, Order_Dir 0x7A85E0,
 * Ignore_Entry 0x7A86AA, Replay_Status 0x7A86C8, Next_Step 0x7A86D2,
 * Continue_Coin 0x7A86E0, Score 0x7A8720, Last_Selected_EM 0x7A875A, WGJ_Score
 * 0x7A8774, Target_BG_X 0x7A8780, Offset_BG_X 0x7A87B0, Break_Into 0x7A8802,
 * Forbid_Break 0x7A8804, Game_pause 0x7A89B0, WGJ_Win 0x7A89B2, WINNER
 * 0x7A89BD, bg_mvxy 0x7BC4C0, base_y_pos 0x7BC516, bg_w 0x7BC520, WIN_X
 * 0x7BD3C8.
 */

#include "structs.h"

void sub_00098407(s16 Code);
void sub_0004384A(s16 );
void Win_1st();
void Win_2nd();
void Win_3rd();
void Win_4th();
void Win_5th();
void Win_6th();
extern s8 Break_Into;
extern u8 Scene_Cut;
s32 Cut_Cut_Cut();
extern u8 M_No[4];
s32 Check_Exit_Check();
extern s8 Debug_w[72];
s32 Switch_Screen(u8 Wipe_Type);
extern u8 Play_Mode;
extern u8 Replay_Status[2];
extern u8 Game_pause;
extern s8 Cover_Timer;
void All_Clear_Suicide();
extern s16 base_y_pos;
extern u8 Unsubstantial_BG[4];
void System_all_clear_Level_B();
void Purge_mmtm_area(s16 ix);
void Make_texcash_of_list(s16 ix);
s32 load_any_texture_patnum(u16 patnum, u8 kokey, u8 _unused);
void Setup_BG(s16 BG_INDEX, s16 X, s16 Y);
void bg_etc_write(s16 type);
extern const u8 PL_Color_Data[20];
extern u8 My_char[2];
extern s8 Winner_id;
extern u8 Play_Type;
extern s8 Last_Selected_EM[2];
void pulpul_stop();
extern u8 Order[148];
extern u8 Order_Timer[148];
s32 effect_76_init(s16 dir_old);
extern u8 Order_Dir[148];
extern u32 WGJ_Score;
extern u8 Continue_Coin[2];
extern u32 Score[2][3];
extern u16 WGJ_Win;
extern u16 Win_Record[2];
s32 effect_L1_init(s16 flag);
void Setup_Wins_OBJ();
s32 effect_B8_init(s8 WIN_PL_NO, s16 timer);
extern s8 WINNER;
void Clear_Flash_No();
void Switch_Screen_Init(s32 );
s32 Switch_Screen_Revival(u8 Wipe_Type);
extern s16 M_Timer;
extern s8 Forbid_Break;
extern s8 Ignore_Entry[2];
extern s8 LOSER;
extern s16 Target_BG_X[6];
extern BG bg_w;
extern s16 Offset_BG_X[6];
extern s8 Next_Step;
extern MVXY bg_mvxy;
s32 effect_58_init(s16 id, s16 time0, s16 option);
extern u8 Mode_Type;
void Push_LDREQ_Queue_Player(s16 id, s16 ix);
void SsBgmFadeOut(u16 time);
void Lose_2nd();
void Lose_3rd();
s32 Cut_Cut_Loser();
extern u16 VS_Win_Record[2];

extern u8 WIN_X;

s32 Winner_Scene() {
    void (*Win_Jmp_Tbl[6])() = {
        Win_1st, Win_2nd, Win_3rd, Win_4th, Win_5th, Win_6th,
    };

    if (Break_Into) {
        return 0;
    }

    WIN_X = 0;
    Scene_Cut = Cut_Cut_Cut();
    Win_Jmp_Tbl[M_No[0]]();

    if ((Check_Exit_Check() == 0) && (Debug_w[0x18] == 0xFF)) {
        WIN_X = 0;
    }

    return WIN_X;
}

void Win_1st() {
    s16 ix;

    Switch_Screen(0);
    Play_Mode = 1;
    Replay_Status[0] = 0;
    Replay_Status[1] = 0;
    M_No[0] += 1;
    M_No[1] = 0;
    Game_pause = 0;
    sub_00098407(55);
    Cover_Timer = 23;
    All_Clear_Suicide();
    base_y_pos = 40;

    for (ix = 0; ix < 4; ix++) {
        Unsubstantial_BG[ix] = 0;
    }

    System_all_clear_Level_B();
    Purge_mmtm_area(4);
    Make_texcash_of_list(4);
    load_any_texture_patnum(0x7F30, 0xC, 0);
    Setup_BG(0, 0x200, 0);
    bg_etc_write(PL_Color_Data[My_char[Winner_id]]);
    Setup_BG(2, 0x300, 0);
    Setup_BG(1, 0x200, 0);
    Setup_BG(3, 0x2C0, 0);

    if (Play_Type == 0) {
        Last_Selected_EM[Winner_id] = 1;
    }

    pulpul_stop();
    sub_0004384A(5);
}

void Win_2nd() {
    Switch_Screen(0);
    M_No[0] += 1;

    Order[0x37] = 1;
    Order_Timer[0x37] = 1;
    effect_76_init(0x37);

    Order[0x35] = 3;
    Order_Timer[0x35] = 1;
    effect_76_init(0x35);

    Order[0x34] = 3;
    Order_Timer[0x34] = 1;
    effect_76_init(0x34);

    Order[0x2B] = 3;
    Order_Timer[0x2B] = 1;
    effect_76_init(0x2B);

    Order[0x3A] = 3;
    Order_Timer[0x3A] = 1;
    effect_76_init(0x3A);

    Order[0x2C] = 3;
    Order_Timer[0x2C] = 1;
    effect_76_init(0x2C);

    Order[0x2D] = 1;
    Order_Dir[0x2D] = 4;
    Order_Timer[0x2D] = 0x1E;
    effect_76_init(0x2D);

    Order[0x38] = 6;
    Order_Timer[0x38] = 1;
    effect_76_init(0x38);

    WGJ_Score = Continue_Coin[Winner_id] + Score[Winner_id][Play_Type];
    WGJ_Win = Win_Record[Winner_id];

    effect_L1_init(1);
    effect_L1_init(2);
    effect_L1_init(3);
    effect_L1_init(4);
    effect_L1_init(5);
    effect_L1_init(6);

    Setup_Wins_OBJ();
    effect_B8_init(WINNER, 0x3C);
}

void Win_3rd() {
    switch (M_No[1]) {
    case 0:
        Switch_Screen(0);
        M_No[1] += 1;
        Clear_Flash_No();
        Switch_Screen_Init(1);

        break;

    case 1:
        if (Switch_Screen_Revival(1) != 0) {
            M_No[0] += 1;
            M_Timer = 90;
            Forbid_Break = -1;
            Ignore_Entry[LOSER] = 0;
            Target_BG_X[2] = bg_w.bgw[2].wxy[0].disp.pos - 384;
            Offset_BG_X[2] = 0;
            Next_Step = 0;
            bg_mvxy.a[0].sp = -0x100000;
            bg_mvxy.d[0].sp = 0x800;

            effect_58_init(0xE, 0x14, 2);

            if (Debug_w[0x1D]) {
                My_char[0] = Debug_w[0x1D] - 1;
            }

            if (Debug_w[0x1E]) {
                My_char[1] = Debug_w[0x1E] - 1;
            }

            if (Mode_Type == 0) {
                Push_LDREQ_Queue_Player(Winner_id, My_char[Winner_id]);
            }
        }

        break;
    }
}

void Win_4th() {
    if (--M_Timer == 0) {
        M_No[0] += 1;
        M_No[1] = 0;
        M_Timer = 0xAA;
        Forbid_Break = 0;
    }
}

void Win_5th() {
    switch (M_No[1]) {
    case 0:
        if (Scene_Cut) {
            M_Timer = 9;
        }

        if (M_Timer < 10) {
            M_Timer = 9;
            M_No[1] += 1;

            if (Mode_Type == 0) {
                SsBgmFadeOut(0x1000);
            }
        }

        break;
    }

    if (--M_Timer == 0) {
        M_No[0] += 1;
        WIN_X = 1;
    }
}

void Win_6th() {
    WIN_X = 1;
}

s32 Loser_Scene() {
    void (*Lose_Jmp_Tbl[6])() = { Win_1st, Lose_2nd, Lose_3rd, Win_4th, Win_5th, Win_6th };

    WIN_X = 0;
    Scene_Cut = Cut_Cut_Loser();
    Lose_Jmp_Tbl[M_No[0]]();

    if ((Check_Exit_Check() == 0) && (Debug_w[0x18] == 0xFF)) {
        WIN_X = 0;
    }

    if (Break_Into) {
        return 0;
    }

    return WIN_X;
}

void Lose_2nd() {
    Switch_Screen(0);
    M_No[0] += 1;

    Order[0x37] = 1;
    Order_Timer[0x37] = 1;
    effect_76_init(0x37);

    Order[0x40] = 3;
    Order_Timer[0x40] = 1;
    effect_76_init(0x40);

    Order[0x36] = 3;
    Order_Timer[0x36] = 1;
    effect_76_init(0x36);

    Order[0x39] = 3;
    Order_Timer[0x39] = 1;
    effect_76_init(0x39);

    Order[0x2D] = 1;
    Order_Dir[0x2D] = 4;
    Order_Timer[0x2D] = 30;
    effect_76_init(0x2D);

    effect_B8_init(WINNER, 0x3C);
}

void Lose_3rd() {
    switch (M_No[1]) {
    case 0:
        Switch_Screen(0);
        M_No[1] += 1;
        Clear_Flash_No();
        Switch_Screen_Init(1);
        break;

    case 1:
        if (Switch_Screen_Revival(1) != 0) {
            M_No[0] += 1;
            M_Timer = 90;
            Forbid_Break = -1;
            Ignore_Entry[LOSER] = 0;
        }

        break;
    }
}

void Setup_Wins_OBJ() {
    if (Mode_Type == 1) {
        WGJ_Win = VS_Win_Record[Winner_id];
    } else {
        WGJ_Win = Win_Record[Winner_id];
    }

    if ((WGJ_Win == 0) || (Mode_Type == 2)) {
        return;
    }

    effect_L1_init(0);

    if (WGJ_Win > 1) {
        effect_76_init(0x2F);
        Order[0x2F] = 3;
        Order_Timer[0x2F] = 1;

        effect_76_init(0x31);
        Order[0x31] = 3;
        Order_Timer[0x31] = 1;
    } else {
        effect_76_init(0x2E);
        Order[0x2E] = 3;
        Order_Timer[0x2E] = 1;

        effect_76_init(0x30);
        Order[0x30] = 3;
        Order_Timer[0x30] = 1;
    }
}
