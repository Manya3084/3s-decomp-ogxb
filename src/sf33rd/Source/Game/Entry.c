/* Entry.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Disp_00_0 0x57E82 size 0x56.
 * Entry_01_Sub 0x57ED8 size 0x6C.
 * Exit_Title_Sub_Entry 0x57F44 size 0x42.
 * Entry_03_2nd 0x57F86 size 0xC8.
 * Naming_Init 0x5804E size 0x2F. Read against the x86: 0x32 is the per-player
 * name work size, the index multiplier. The C is the PS2 C.
 * Name_In_Sub0 0x5807D size 0x38.
 * Setup_Next_Step 0x580B5 size 0x117.
 * In_Game_Sub 0x581CC size 0xA9.
 * In_Over_Sub 0x58275 size 0x37.
 * Flash_Start 0x582AC size 0xFD.
 * Flash_Please 0x583A9 size 0x9B.
 * Ck_Break_Into_SP 0x58444 size 0x34.
 * Break_Into_02 0x58478 size 0x5E.
 * Break_Into_04 0x584D6 size 0x5C.
 * Break_Into_05 0x58532 size 0xD9.
 * Break_Into_07 0x5860B size 0x52.
 * Break_Into_08 0x5865D size 0x6F. Read against the x86: setl / dec / and 0x32
 * / add 0xA is the branchless form of the C's Continue_Count >= 0 ? 60 : 10.
 * Continue_Score_Sub 0x58726 size 0x29.
 * Correct_BI_Data 0x5874F size 0x38.
 * Entry_00 0x58787 size 0x4E.
 * Entry_01 0x587D5 size 0x87. FLAG: x86-only callees xb_Get7A1808.
 * Entry_04_2nd 0x5885C size 0xF0.
 * Naming_Cut_Sub_1P 0x5894C size 0x3E.
 * Naming_Cut_Sub_2P 0x5898A size 0x3F.
 * Name_In_Sub 0x589C9 size 0x74.
 * Entry_Continue_Sub 0x58A3D size 0xA1.
 * Break_Into_Sub 0x58ADE size 0x86.
 * Ck_Break_Into 0x58B64 size 0x9C.
 * Loser_Sub_1P 0x58C00 size 0x63.
 * Loser_Sub_2P 0x58C63 size 0x62.
 * Credit_Sub_1P 0x58CC5 size 0x3E.
 * Credit_Sub_2P 0x58D03 size 0x3F.
 * Credit_Continue_1P 0x58D42 size 0x24.
 * Credit_Continue_2P 0x58D66 size 0x24.
 * Entry_Common_Sub 0x58D8A size 0x2D.
 * Loser_Scene_Sub 0x58DB7 size 0x2D.
 * Entry_Main_Sub 0x58DE4 size 0x276.
 * Entry_02 0x5905A size 0x25.
 * Entry_03_1st 0x5907F size 0x25.
 * Entry_04_1st 0x590A4 size 0x2E.
 * Entry_06_1st 0x590D2 size 0x25.
 * Entry_06_2nd 0x590F7 size 0x112.
 * Entry_07_1st 0x59209 size 0x25.
 * Entry_07_2nd 0x5922E size 0xED.
 * Entry_08_1st 0x5931B size 0x2C.
 * Entry_08_2nd 0x59347 size 0x123. FLAG: x86-only constants 0xff.
 * Entry_10_1st 0x5946A size 0xBA.
 * Entry_10_2nd 0x59524 size 0x123. FLAG: x86-only constants 0xff.
 * Entry_03 0x59647 size 0x13.
 * Entry_04 0x5965A size 0x13.
 * Entry_06 0x5966D size 0x13.
 * Entry_07 0x59680 size 0x13.
 * Entry_08 0x59693 size 0x13.
 * Entry_10 0x596A6 size 0x2E.
 * Entry_Task 0x596D4 size 0x7F.
 * Break_Into_09 is folded into 0x586CC with 1 other bodies. Unnamed.
 * Break_Into_10 is folded into 0x586CC with 1 other bodies. Unnamed.
 * Break_Into_09 is folded into 0x586CC.
 * Break_Into_10 is folded into 0x586CC.
 * Sound_SE is folded into 0x98407.
 * Data: letter_stack: defined elsewhere on Xbox.
 * Data: letter_counter: defined elsewhere on Xbox.
 * Data: letter_ptr: defined elsewhere on Xbox.
 * Data: Coin_Message_Data is 0x25C444, 0xE bytes compared.
 * Unnamed data used (not checked): Disp_00_0: 0x25c454,0x25c464,0x25c474;
 * In_Game_Sub: 0x25c488; In_Over_Sub: 0x25c488; Flash_Start:
 * 0x25c498,0x25c4ac,0x25c4c0; Flash_Please: 0x25c4d0; Entry_Continue_Sub:
 * 0x25c4c0; Loser_Sub_1P: 0x25c4c0; Loser_Sub_2P: 0x25c4c0; Entry_Task:
 * 0xc805f2,0xc80600,0xc80628.
 * Globals: Stage_Lost_Round 0x7A80BA, Player_id 0x7A810F, Play_Type 0x7A812D,
 * Operator_Status 0x7A816A, Stage_Stock_Score 0x7A8170, Request_G_No 0x7A8189,
 * Stage_Perfect_Finish 0x7A81A8, Request_Break 0x7A81B0, Request_E_No
 * 0x7A81C6, Insert_Y 0x7A81F2, Cover_Timer 0x7A81F4, Naming_Cut 0x7A8204, G_No
 * 0x7A825C, Unit_Of_Timer 0x7A82A8, Stop_Update_Score 0x7A82AA, F_No1
 * 0x7A82CE, Stop_Combo 0x7A82FC, LOSER 0x7A82FD, Perfect_Finish 0x7A8304,
 * Request_Disp_Rank 0x7A8360, Continue_Cut 0x7A8420, E_Number 0x7A8468,
 * Fade_Flag 0x7A851A, ENTRY_X 0x7A85C0, Break_Com 0x7A8680, E_Timer 0x7A86A8,
 * Ignore_Entry 0x7A86AA, Lost_Round 0x7A86D4, New_Challenger 0x7A86D6, DE_X
 * 0x7A86D8, Continue_Coin 0x7A86E0, F_No0 0x7A86E2, Score 0x7A8720,
 * Stage_SA_Finish 0x7A8760, Stage_Cheap_Finish 0x7A8764, Cheap_Finish
 * 0x7A876C, F_No3 0x7A8790, Sel_Arts_Complete 0x7A87E0, Rank_In 0x7A87E8,
 * Break_Into 0x7A8802, Forbid_Break 0x7A8804, F_No2 0x7A8806, Pause 0x7A8816,
 * Conclusion_Flag 0x7A88D4, E_07_Flag 0x7A88EC, Super_Arts_Finish 0x7A88F4,
 * Continue_Count_Down 0x7A891A, Champion 0x7A8931, Extra_Break 0x7A89A0,
 * F_Timer 0x7A89A4, Game_pause 0x7A89B0, WINNER 0x7A89BD, Select_Timer
 * 0x7A89D1, Continue_Count 0x7A89D2, E_No 0x7A89F8, Personal_Timer 0x7A8A10,
 * Name_00 0x7A9D78, name_wk 0x7A9E20, rank_name_w 0x7A9E90, end_name_cut
 * 0x7AAC04, No_Trans 0x7BD3C9, p1sw_1 0x7BD3CA, save_w 0x7BD3E0, p2sw_1
 * 0x7C5568, p1sw_0 0x7C557C, p2sw_0 0x7C5B90, Ranking_Data 0xC7C840, plw
 * 0xC7CEA0.
 */

#include "structs.h"

void sub_00098407(s16 Code);
s32 xb_Get7A1808(void);
void Entry_00();
void Entry_01();
void Entry_02();
void Entry_03();
void Entry_04();
void Entry_06();
void Entry_07();
void Entry_08();
void Entry_10();
extern u8 Pause;
u8 nowSoftReset();
extern u8 No_Trans;
extern u8 E_No[4];
extern s16 E_Timer;
void Disp_00_0();
extern struct _SAVE_W save_w[6];
void SSPutStr(u16 x, u16 y, u8 atr, const s8* str);
extern s16 Insert_Y;
extern u8 G_No[4];
extern s8 Break_Into;
extern u16 p1sw_1;
extern u16 p1sw_0;
void Entry_01_Sub(s16 PL_id);
extern u16 p2sw_1;
extern u16 p2sw_0;
extern s8 Request_E_No;
void Exit_Title_Sub_Entry();
extern s8 Request_G_No;
extern PLW plw[2];
extern s8 Operator_Status[2];
extern s8 Champion;
extern s8 Ignore_Entry[2];
extern u8 Continue_Coin[2];
void grade_check_work_1st_init(s16 ix, s16 ix2);
extern u8 F_No1[2];
extern u8 F_No2[2];
extern u8 F_No3[2];
extern u8 E_Number[2][4];
void Entry_Main_Sub(s16 PL_id, s16 Jump_Index);
void Entry_03_1st();
void Entry_03_2nd();
u8 Check_LDREQ_Break();
void Switch_Screen_Init(s32 );
s32 Switch_Screen(u8 Wipe_Type);
extern s8 Cover_Timer;
extern s8 New_Challenger;
extern s16 Sel_Arts_Complete[2];
void Entry_04_1st();
void Entry_04_2nd();
extern u8 Game_pause;
extern s8 LOSER;
void Correct_BI_Data();
void Entry_06_1st();
void Entry_06_2nd();
extern s8 E_07_Flag[2];
extern s8 Fade_Flag;
void Entry_07_1st();
void Entry_07_2nd();
void Entry_08_1st();
void Entry_08_2nd();
void Clear_Personal_Data(s16 PL_id);
extern s8 Request_Disp_Rank[2][4];
void cpExitTask(u16 num);
void Entry_10_1st();
void Entry_10_2nd();
void Setup_Final_Grade();
s32 Check_Ranking(s16 PL_id);
extern s8 WINNER;
extern s8 Rank_In[2][4];
extern s16 ENTRY_X;
void Entry_Common_Sub(s16 PL_id, s16 Jump_Index);
s32 Credit_Continue_2P();
void Break_Into_Sub(s16 PL_id, s16 Jump_Index);
s32 Credit_Continue_1P();
extern s8 Request_Break[2];
void Entry_Continue_Sub(s16 PL_id);
extern s8 Personal_Timer[2];
void Naming_Init(s16 PL_id);
extern s8 Forbid_Break;
void Naming_Cut_Sub_1P();
void Naming_Cut_Sub_2P();
s16 Name_Input(s16 pl_id);
void Name_In_Sub(s16 PL_id);
extern s8 Naming_Cut[2];
void In_Game_Sub(s16 PL_id);
void In_Over_Sub(s16 PL_id);
void Loser_Scene_Sub(s16 PL_id, s16 Jump_Index);
extern s16 Name_00[2];
extern NAME_WK name_wk[2];
extern s8 end_name_cut[2];
s32 Ck_Break_Into_SP(u16 Sw_0, u16 Sw_1, s16 PL_id);
void Name_In_Sub0(s16 PL_id, s16 xx);
extern RANK_DATA Ranking_Data[20];
extern RANK_NAME_W rank_name_w[2];
s32 Credit_Sub_2P();
s32 Credit_Sub_1P();
s32 Loser_Sub_2P();
s32 Loser_Sub_1P();
s32 Ck_Break_Into(u16 Sw_0, u16 Sw_1, s16 PL_id);
extern s16 DE_X[2];
s32 Flash_Start(s16 PL_id);
s32 Flash_Please(s16 PL_id);
extern u8 Continue_Count_Down[2];
void Disp_Personal_Count(s16 PL_id, s8 counter);
extern s8 Continue_Count[2];
s16 Check_Count_Cut(s16 PL_id, s16 Limit);
extern u8 Continue_Cut[2];
void Setup_Next_Step(s16 PL_id);
extern s8 Break_Com[2][20];
void Clear_Flash_No();
extern u8 F_No0[2];
extern s16 F_Timer[2];
void Break_Into_02(s16 );
void Break_Into_04(s16 );
void Break_Into_05(s16 PL_id);
void Break_Into_07(s16 PL_id);
void Break_Into_08(s16 PL_id);
void Break_Into_09(s16 PL_id);
void Break_Into_10(s16 PL_id);
extern u8 Extra_Break;
void Continue_Score_Sub(s16 PL_id);
extern s8 Select_Timer;
extern s16 Unit_Of_Timer;
s32 effect_A2_init();
void sound_all_off();
void Request_LDREQ_Break();
extern s8 Stop_Combo;
extern u8 Play_Type;
extern u8 Conclusion_Flag;
extern u32 Score[2][3];
extern u32 Stage_Stock_Score[2];
extern u8 Stop_Update_Score;
extern s8 Super_Arts_Finish[2];
extern s8 Player_id;
extern s8 Stage_SA_Finish[2];
extern s8 Lost_Round[2];
extern s8 Stage_Lost_Round[2];
extern s8 Perfect_Finish[2];
extern s8 Stage_Perfect_Finish[2];
extern s8 Cheap_Finish[2];
extern s8 Stage_Cheap_Finish[2];

extern u8 letter_stack[40];

extern u8 letter_counter;

extern u8* letter_ptr;

const u8 Coin_Message_Data[7][2] = { { 5, 30 }, { 2, 27 }, { 7, 32 }, { 17, 37 }, { 6, 31 }, { 5, 42 }, { 0, 0 } };

/* The Xbox runs one step: no sysFF fast-forward loop. */
void Entry_Task(struct _TASK* /* unused */) {
    void (*Main_Jmp_Tbl[11])() = { Entry_00, Entry_01, Entry_02, Entry_03, Entry_04, Entry_03,
                                   Entry_06, Entry_07, Entry_08, Entry_03, Entry_10 };

    if (Pause || nowSoftReset()) {
        return;
    }

    No_Trans = 0;
    letter_counter = 0;
    letter_ptr = letter_stack;
    Main_Jmp_Tbl[E_No[0]]();
}

void Entry_00() {
    switch (E_No[1]) {
    case 0:
        break;

    case 1:
        E_No[1] += 1;
        E_Timer = 50;
        Disp_00_0();
        break;

    case 2:
        if (--E_Timer == 0) {
            E_No[1] += 1;
            E_Timer = 30;
            break;
        }

        Disp_00_0();
        break;

    case 3:
        if (!--E_Timer) {
            E_No[1] -= 1;
            E_Timer = 50;
            Disp_00_0();
            break;
        }

        break;
    }
}

void Disp_00_0() {
    if (save_w[1].extra_option.contents[3][5] == 0) {
        return;
    }

    SSPutStr(15, Insert_Y, 9, "PRESS START BUTTON");

    if (!(G_No[1] == 3 || G_No[1] == 5)) {
        return;
    }

    SSPutStr(5, 0, 9, "PRESS 1P START");
    SSPutStr(30, 0, 9, "PRESS 2P START");
}

void Entry_01() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        E_No[1] = 1;
        Break_Into = 0;
        break;

    case 1:
        Entry_00();

        if (xb_Get7A1808() == 0) {
            return;
        }

        if (~p1sw_1 & p1sw_0 & 0x4000) {
            Entry_01_Sub(0);
            return;
        }

        if (~p2sw_1 & p2sw_0 & 0x4000) {
            Entry_01_Sub(1);
            return;
        }

        break;

    case 2:
        if (Request_E_No) {
            E_No[2] += 1;
            return;
        }

        break;

    default:
        Exit_Title_Sub_Entry();
        break;
    }
}

void Entry_01_Sub(s16 PL_id) {
    E_No[2] += 1;
    Request_G_No = 1;
    plw[PL_id].wu.operator = 1;
    Operator_Status[PL_id] = 1;
    Champion = PL_id;
    plw[PL_id ^ 1].wu.operator = 0;
    Operator_Status[PL_id ^ 1] = 0;
    Ignore_Entry[0] = 0;
    Ignore_Entry[1] = 0;

    if (Continue_Coin[PL_id] == 0) {
        grade_check_work_1st_init(PL_id, 0);
    }
}

void Exit_Title_Sub_Entry() {
    s16 i;
    s16 j;

    E_No[0] = 2;
    E_No[1] = 0;
    E_No[2] = 0;
    E_No[3] = 0;
    F_No1[0] = F_No2[0] = F_No3[0] = 0;
    F_No1[1] = F_No2[1] = F_No3[1] = 0;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            E_Number[i][j] = 0;
        }
    }
}

void Entry_02() {
    switch (E_No[1]) {
    case 0:
        E_No[1] += 1;
        break;
    }

    Entry_Main_Sub(0, 2);
    Entry_Main_Sub(1, 2);
}

void Entry_03() {
    switch (E_No[1]) {
    case 0:
        Entry_03_1st();
        break;

    default:
        Entry_03_2nd();
        break;
    }
}

void Entry_03_1st() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        break;
    }

    Entry_Main_Sub(0, 4);
    Entry_Main_Sub(1, 4);
}

/* Xbox: case 0 breaks out where the PS2 returns. */
void Entry_03_2nd() {
    switch (E_No[2]) {
    case 0:
        if (--E_Timer == 0) {
            if (Check_LDREQ_Break() == 0) {
                E_No[2] += 1;
                Switch_Screen_Init(1);
                break;
            }

            E_Timer = 1;
            break;
        }

        break;

    case 1:
        if (Switch_Screen(1) != 0) {
            Cover_Timer = 23;
            G_No[1] = 1;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 2;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;
            plw[New_Challenger].wu.operator = 1;
            Operator_Status[New_Challenger] = 1;
            Sel_Arts_Complete[Champion] = -1;

            if (Continue_Coin[New_Challenger] == 0) {
                grade_check_work_1st_init(New_Challenger, 0);
            }
        }

        break;
    }
}

void Entry_04() {
    switch (E_No[1]) {
    case 0:
        Entry_04_1st();
        break;

    default:
        Entry_04_2nd();
        break;
    }
}

void Entry_04_1st() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        break;
    }

    if (Game_pause != 0x81) {
        Entry_Main_Sub(0, 5);
        Entry_Main_Sub(1, 5);
    }
}

/* Xbox: case 0 breaks out where the PS2 returns. */
void Entry_04_2nd() {
    switch (E_No[2]) {
    case 0:
        if (--E_Timer == 0) {
            if (Check_LDREQ_Break() == 0) {
                E_No[2] += 1;
                Switch_Screen_Init(1);
                break;
            }

            E_Timer = 1;
            break;
        }

        break;

    case 1:
        if (Switch_Screen(0) != 0) {
            E_No[2] += 1;
            Cover_Timer = 23;
            G_No[1] = 1;
            G_No[2] = 0;
            G_No[3] = 0;

            if (E_No[3] == 0xFF) {
                E_Number[LOSER][0] = 1;
                E_Number[LOSER][1] = 0;
                E_Number[LOSER][2] = 0;
                E_Number[LOSER][3] = 0;
            } else {
                Correct_BI_Data();
            }

            E_No[0] = 2;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;
            Game_pause = 0;
            plw[New_Challenger].wu.operator = 1;
            Operator_Status[New_Challenger] = 1;

            if (Continue_Coin[New_Challenger] == 0) {
                grade_check_work_1st_init(New_Challenger, 0);
            }
        }

        break;
    }
}

void Entry_06() {
    switch (E_No[1]) {
    case 0:
        Entry_06_1st();
        break;

    default:
        Entry_06_2nd();
        break;
    }
}

void Entry_06_1st() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        break;
    }

    Entry_Main_Sub(0, 7);
    Entry_Main_Sub(1, 7);
}

void Entry_06_2nd() {
    if (E_07_Flag[0] == 0) {
        Entry_Main_Sub(0, 7);
    }

    if (E_07_Flag[1] == 0) {
        Entry_Main_Sub(1, 7);
    }

    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        Switch_Screen_Init(1);
        break;

    case 1:
        if (Switch_Screen(1) != 0) {
            E_No[2] += 1;
            Cover_Timer = 23;
            return;
        }

        break;

    default:
        Switch_Screen(1);
        G_No[1] = 1;
        G_No[2] = 0;
        G_No[3] = 0;
        E_No[0] = 2;
        E_No[1] = 0;
        E_No[2] = 0;
        E_No[3] = 0;
        Fade_Flag = 0;

        if (E_07_Flag[0]) {
            plw[0].wu.operator = 1;
            Operator_Status[0] = 1;

            if (Continue_Coin[0] == 0) {
                grade_check_work_1st_init(0, 0);
            }
        }

        if (E_07_Flag[1]) {
            plw[1].wu.operator = 1;
            Operator_Status[1] = 1;

            if (Continue_Coin[1] == 0) {
                grade_check_work_1st_init(1, 0);
            }
        }

        E_07_Flag[0] = 0;
        E_07_Flag[1] = 0;

        if (E_Number[LOSER][0] == 5) {
            E_Number[LOSER][0] = 1;
        }

        break;
    }
}

void Entry_07() {
    switch (E_No[1]) {
    case 0:
        Entry_07_1st();
        break;

    default:
        Entry_07_2nd();
        break;
    }
}

void Entry_07_1st() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        break;
    }

    Entry_Main_Sub(0, 8);
    Entry_Main_Sub(1, 8);
}

void Entry_07_2nd() {
    if (E_07_Flag[0] == 0) {
        Entry_Main_Sub(0, 8);
    }

    if (E_07_Flag[1] == 0) {
        Entry_Main_Sub(1, 8);
    }

    switch (E_No[2]) {
    case 0:
        if (!--E_Timer) {
            E_No[2] += 1;
            Switch_Screen_Init(1);
        }

        break;

    default:
        if (Switch_Screen(1) != 0) {
            Cover_Timer = 23;
            G_No[1] = 1;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 2;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;

            if (E_07_Flag[0]) {
                plw[0].wu.operator = 1;
                Operator_Status[0] = 1;

                if (Continue_Coin[0] == 0) {
                    grade_check_work_1st_init(0, 0);
                }
            }

            if (E_07_Flag[1]) {
                plw[1].wu.operator = 1;
                Operator_Status[1] = 1;

                if (Continue_Coin[1] == 0) {
                    grade_check_work_1st_init(1, 0);
                }
            }

            E_07_Flag[0] = 0;
            E_07_Flag[1] = 0;
        }

        break;
    }
}

void Entry_08() {
    switch (E_No[1]) {
    case 0:
        Entry_08_1st();
        break;

    default:
        Entry_08_2nd();
        break;
    }
}

void Entry_08_1st() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        /* fallthrough */

    case 1:
        Entry_Main_Sub(0, 9);
        Entry_Main_Sub(1, 9);
        break;
    }
}

void Entry_08_2nd() {
    if (E_07_Flag[0] == 0) {
        Entry_Main_Sub(0, 9);
    }

    if (E_07_Flag[1] == 0) {
        Entry_Main_Sub(1, 9);
    }

    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;

        if ((E_Number[LOSER][0] == 8) && (E_Number[LOSER][1] == 1)) {
            Clear_Personal_Data(LOSER);
        }

        Switch_Screen_Init(1);
        break;

    default:
        if (Switch_Screen(1) != 0) {
            Cover_Timer = 23;
            G_No[1] = 1;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 2;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;

            if (E_07_Flag[0]) {
                plw[0].wu.operator = 1;
                Operator_Status[0] = 1;

                if (Continue_Coin[0] == 0) {
                    grade_check_work_1st_init(0, 0);
                }
            }

            if (E_07_Flag[1]) {
                plw[1].wu.operator = 1;
                Operator_Status[1] = 1;

                if (Continue_Coin[1] == 0) {
                    grade_check_work_1st_init(1, 0);
                }
            }

            E_07_Flag[0] = 0;
            E_07_Flag[1] = 0;
            Request_Disp_Rank[0][0] = -1;
            Request_Disp_Rank[0][1] = -1;
            Request_Disp_Rank[1][0] = -1;
            Request_Disp_Rank[1][1] = -1;
        }

        break;
    }
}

void Entry_10() {
    if ((E_Number[0][0] == 0x63) && (E_Number[1][0] == 0x63)) {
        cpExitTask(1);
        return;
    }

    switch (E_No[1]) {
    case 0:
        Entry_10_1st();
        break;

    default:
        Entry_10_2nd();
        break;
    }
}

void Entry_10_1st() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        break;

    case 1:
        E_No[2] += 1;
        Setup_Final_Grade();

        if (Check_Ranking(WINNER) != 0) {
            E_Number[WINNER][0] = 2;
            E_Number[WINNER][1] = 0;
            E_Number[WINNER][2] = 0;
            E_Number[WINNER][3] = 0;
            Request_Disp_Rank[WINNER][0] = Rank_In[WINNER][0];
            Request_Disp_Rank[WINNER][1] = Rank_In[WINNER][1];
            Request_Disp_Rank[WINNER][2] = Rank_In[WINNER][2];
            Request_Disp_Rank[WINNER][3] = Rank_In[WINNER][3];
        } else {
            E_Number[WINNER][0] = 8;
            E_Number[WINNER][1] = 0;
        }

        /* fallthrough */

    default:
        Entry_Main_Sub(0, 10);
        Entry_Main_Sub(1, 10);
        break;
    }
}

void Entry_10_2nd() {
    if (E_07_Flag[0] == 0) {
        Entry_Main_Sub(0, 10);
    }

    if (E_07_Flag[1] == 0) {
        Entry_Main_Sub(1, 10);
    }

    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;

        if ((E_Number[LOSER][0] == 8) && (E_Number[LOSER][1] == 1)) {
            Clear_Personal_Data(LOSER);
        }

        Switch_Screen_Init(1);
        break;

    default:
        if (Switch_Screen(1) != 0) {
            Cover_Timer = 23;
            G_No[1] = 1;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 2;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;

            if (E_07_Flag[0]) {
                plw[0].wu.operator = 1;
                Operator_Status[0] = 1;

                if (Continue_Coin[0] == 0) {
                    grade_check_work_1st_init(0, 0);
                }
            }

            if (E_07_Flag[1]) {
                plw[1].wu.operator = 1;
                Operator_Status[1] = 1;

                if (Continue_Coin[1] == 0) {
                    grade_check_work_1st_init(1, 0);
                }
            }

            E_07_Flag[0] = 0;
            E_07_Flag[1] = 0;
            Request_Disp_Rank[0][0] = -1;
            Request_Disp_Rank[0][1] = -1;
            Request_Disp_Rank[1][0] = -1;
            Request_Disp_Rank[1][1] = -1;
        }

        break;
    }
}

void Entry_Main_Sub(s16 PL_id, s16 Jump_Index) {
    ENTRY_X = 0;

    switch (E_Number[PL_id][0]) {
    case 0:
        if (!Ignore_Entry[LOSER]) {
            if ((E_No[0] == 10) || (E_No[0] == 8)) {
                E_Number[PL_id][0] = 99;
                return;
            }

            if (plw[PL_id].wu.operator == 0) {
                Entry_Common_Sub(PL_id, Jump_Index);
                return;
            }
        }

        break;

    case 1:
        if (PL_id) {
            if (Credit_Continue_2P() != 0) {
                Break_Into_Sub(PL_id, Jump_Index);
            }
        } else if (Credit_Continue_1P() != 0) {
            Break_Into_Sub(PL_id, Jump_Index);
        }

        if (Request_Break[PL_id]) {
            E_Number[PL_id][0] = 0;
            E_Number[PL_id][1] = 0;
            E_Number[PL_id][2] = 0;
            E_Number[PL_id][3] = 0;
            return;
        }

        if ((E_Number[PL_id][0] == 1) && (E_07_Flag[PL_id ^ 1] == 0)) {
            Entry_Continue_Sub(PL_id);
            return;
        }

        break;

    case 2:
        switch (E_Number[PL_id][1]) {
        case 0:
            E_Number[PL_id][1] += 1;
            Personal_Timer[PL_id] = 30;
            break;

        case 1:
            if (!--Personal_Timer[PL_id]) {
                E_Number[PL_id][1] += 1;
                Naming_Init(PL_id);
                return;
            }

            break;

        case 2:
            if (Forbid_Break != 1) {
                if (PL_id == 0) {
                    Naming_Cut_Sub_1P();
                } else {
                    Naming_Cut_Sub_2P();
                }

                if (Name_Input(PL_id)) {
                    Name_In_Sub(PL_id);

                    if (Naming_Cut[PL_id]) {
                        Clear_Personal_Data(PL_id);
                        return;
                    }

                    E_Number[PL_id][2] = 0;
                    E_Number[PL_id][3] = 0;

                    if (E_No[0] == 8) {
                        E_Number[PL_id][0] = 8;
                        E_Number[PL_id][1] = 1;
                        return;
                    }

                    E_Number[PL_id][0] = 8;
                    E_Number[PL_id][1] = 0;
                    return;
                }
            }

            break;
        }

        break;

    case 3:
        switch (E_Number[PL_id][1]) {
        case 0:
            if ((E_No[0] == 8) || (E_No[0] == 2)) {
                E_Number[PL_id][0] = 2;
                E_Number[PL_id][1] = 2;
                E_Number[PL_id][2] = 0;
                E_Number[PL_id][3] = 0;
                Naming_Init(PL_id);
                return;
            }

            break;

        case 1:
            if ((E_No[0] == 8) || (E_No[0] == 2)) {
                E_Number[PL_id][0] = 8;
                E_Number[PL_id][1] = 1;
                E_Number[PL_id][2] = 0;
                E_Number[PL_id][3] = 0;

                if (E_No[0] == 2) {
                    E_Number[PL_id][1] = 0;
                    return;
                }
            }

            break;
        }

        break;

    case 8:
        switch (E_Number[PL_id][1]) {
        case 0:
            In_Game_Sub(PL_id);
            break;

        case 1:
            In_Over_Sub(PL_id);
            break;
        }

        break;

    case 5:
        Loser_Scene_Sub(PL_id, Jump_Index);
        break;
    }
}

void Naming_Init(s16 PL_id) {
    Naming_Cut[PL_id] = 0;
    Name_00[PL_id] = 0;
    name_wk[PL_id].r_no_0 = 0;
    name_wk[PL_id].r_no_1 = 0;
    end_name_cut[PL_id] = 0;
}

void Naming_Cut_Sub_1P() {
    if (!Naming_Cut[0] && (Ck_Break_Into_SP(p1sw_0, p1sw_1, 0) != 0)) {
        Game_pause = 0;
        Naming_Cut[0] = 1;
        Request_Break[0] = 1;
    }
}

void Naming_Cut_Sub_2P() {
    if (!Naming_Cut[1] && (Ck_Break_Into_SP(p2sw_0, p2sw_1, 1) != 0)) {
        Game_pause = 0;
        Naming_Cut[1] = 1;
        Request_Break[1] = 1;
    }
}

void Name_In_Sub(s16 PL_id) {
    if (Rank_In[PL_id][0] >= 0) {
        Name_In_Sub0(PL_id, Rank_In[PL_id][0] + 0);
    }

    if (Rank_In[PL_id][1] >= 0) {
        Name_In_Sub0(PL_id, Rank_In[PL_id][1] + 5);
    }

    if (Rank_In[PL_id][2] >= 0) {
        Name_In_Sub0(PL_id, Rank_In[PL_id][2] + 10);
    }

    if (Rank_In[PL_id][3] >= 0) {
        Name_In_Sub0(PL_id, Rank_In[PL_id][3] + 15);
    }
}

void Name_In_Sub0(s16 PL_id, s16 xx) {
    Ranking_Data[xx].name[0] = rank_name_w[PL_id].code[0];
    Ranking_Data[xx].name[1] = rank_name_w[PL_id].code[1];
    Ranking_Data[xx].name[2] = rank_name_w[PL_id].code[2];
}

void Entry_Common_Sub(s16 PL_id, s16 Jump_Index) {
    if (PL_id) {
        if (Credit_Sub_2P() != 0) {
            Break_Into_Sub(PL_id, Jump_Index);
        }
    } else if (Credit_Sub_1P() != 0) {
        Break_Into_Sub(PL_id, Jump_Index);
    }
}

void Loser_Scene_Sub(s16 PL_id, s16 Jump_Index) {
    if (PL_id) {
        if (Loser_Sub_2P() != 0) {
            Break_Into_Sub(PL_id, Jump_Index);
        }
    } else if (Loser_Sub_1P() != 0) {
        Break_Into_Sub(PL_id, Jump_Index);
    }
}

s32 Loser_Sub_1P() {
    if ((Ck_Break_Into(p1sw_0, p1sw_1, 0) == 0) && !Request_Break[0]) {
        if (LOSER == 0) {
            if (save_w[1].extra_option.contents[3][5]) {
                SSPutStr(DE_X[0], 0, 9, "     CONTINUE?");
            }
        } else {
            Flash_Start(0);
        }
    }

    return ENTRY_X;
}

s32 Loser_Sub_2P() {
    if ((Ck_Break_Into(p2sw_0, p2sw_1, 1) == 0) && !Request_Break[1]) {
        if (LOSER == 1) {
            if (save_w[1].extra_option.contents[3][5]) {
                SSPutStr(DE_X[1], 0, 9, "     CONTINUE?");
            }
        } else {
            Flash_Start(1);
        }
    }

    return ENTRY_X;
}

s32 Credit_Sub_1P() {
    if (Ck_Break_Into(p1sw_0, p1sw_1, 0) == 0) {
        if (Request_Break[0]) {
            Flash_Please(0);
        } else {
            Flash_Start(0);
        }
    }

    return ENTRY_X;
}

s32 Credit_Sub_2P() {
    if (Ck_Break_Into(p2sw_0, p2sw_1, 1) == 0) {
        if (Request_Break[1]) {
            Flash_Please(1);
        } else {
            Flash_Start(1);
        }
    }

    return ENTRY_X;
}

s32 Credit_Continue_1P() {
    Ck_Break_Into(p1sw_0, p1sw_1, 0);
    return ENTRY_X;
}

s32 Credit_Continue_2P() {
    Ck_Break_Into(p2sw_0, p2sw_1, 1);
    return ENTRY_X;
}

void Entry_Continue_Sub(s16 PL_id) {
    if ((Continue_Count_Down[PL_id] == 0) && save_w[1].extra_option.contents[3][5]) {
        SSPutStr(DE_X[PL_id], 0, 9, "     CONTINUE?");
        Disp_Personal_Count(PL_id, Continue_Count[PL_id]);
    }

    switch (E_Number[PL_id][1]) {
    case 0:
        if (Continue_Count_Down[PL_id] == 0) {
            E_Number[PL_id][1] += 1;
            Personal_Timer[PL_id] = 60;
            return;
        }

        break;

    case 1:
        if (Check_Count_Cut(PL_id, 8)) {
            Continue_Cut[PL_id] = 1;
        } else if (--Personal_Timer[PL_id]) {
            break;
        }

        if (--Continue_Count[PL_id] >= 0) {
            Personal_Timer[PL_id] = 60;
            return;
        }

        Setup_Next_Step(PL_id);

        break;
    }
}

void Setup_Next_Step(s16 PL_id) {
    s16 xx;

    E_Number[PL_id][1] = 0;
    E_Number[PL_id][2] = 0;
    E_Number[PL_id][3] = 0;

    for (xx = 0; xx < 20; xx++) {
        Break_Com[PL_id][xx] = 0;
    }

    if (E_No[0] != 7) {
        Setup_Final_Grade();

        if (Check_Ranking(PL_id) != 0) {
            E_Number[PL_id][0] = 2;
            Request_Disp_Rank[PL_id][0] = Rank_In[PL_id][0];
            Request_Disp_Rank[PL_id][1] = Rank_In[PL_id][1];
            Request_Disp_Rank[PL_id][2] = Rank_In[PL_id][2];
            Request_Disp_Rank[PL_id][3] = Rank_In[PL_id][3];
            return;
        }

        E_Number[PL_id][0] = 8;
        E_Number[PL_id][1] = 0;
        return;
    }

    Setup_Final_Grade();

    if (Check_Ranking(PL_id) != 0) {
        Request_Disp_Rank[PL_id][0] = Rank_In[PL_id][0];
        Request_Disp_Rank[PL_id][1] = Rank_In[PL_id][1];
        Request_Disp_Rank[PL_id][2] = Rank_In[PL_id][2];
        Request_Disp_Rank[PL_id][3] = Rank_In[PL_id][3];

        if (E_Number[PL_id ^ 1][0] != 0) {
            E_Number[PL_id][0] = 2;
            return;
        }

        E_Number[PL_id][0] = 3;
        E_Number[PL_id][1] = 0;
        return;
    }

    if (E_Number[PL_id ^ 1][0] != 0) {
        E_Number[PL_id][0] = 8;
        E_Number[PL_id][1] = 0;
        return;
    }

    E_Number[PL_id][0] = 3;
    E_Number[PL_id][1] = 1;
}

void In_Game_Sub(s16 PL_id) {
    switch (E_Number[PL_id][2]) {
    case 0:
        E_Number[PL_id][2] += 1;
        Personal_Timer[PL_id] = 30;
        break;

    case 1:
        if (--Personal_Timer[PL_id] == 0) {
            E_Number[PL_id][2] += 1;
            Personal_Timer[PL_id] = 60;
            return;
        }

        break;

    case 2:
        if (save_w[1].extra_option.contents[3][5]) {
            SSPutStr(DE_X[PL_id], 0, 9, "     GAME OVER");
        }

        if (--Personal_Timer[PL_id] == 0) {
            E_Number[PL_id][2] += 1;
            Personal_Timer[PL_id] = 30;
            return;
        }

        break;

    default:
        if (--Personal_Timer[PL_id] == 0) {
            if ((E_No[0] == 10) || (E_No[0] == 8)) {
                E_Number[PL_id][0] = 99;
                return;
            }

            Clear_Personal_Data(PL_id);
            Clear_Flash_No();
        }

        break;
    }
}

void In_Over_Sub(s16 PL_id) {
    switch (E_Number[PL_id][2]) {
    case 0:
        E_Number[PL_id][2] += 1;
        break;
    }

    if (save_w[1].extra_option.contents[3][5]) {
        SSPutStr(DE_X[PL_id], 0, 9, "     GAME OVER");
    }
}

s32 Flash_Start(s16 PL_id) {
    switch (F_No1[PL_id]) {
    case 0:
        F_No1[PL_id] += 1;
        F_No0[PL_id] = 0;
        F_No2[PL_id] = 0;
        F_No3[PL_id] = 0;
        F_Timer[PL_id] = 1;

        if ((E_No[0] == 6) && (PL_id == LOSER)) {
            F_No1[PL_id] = 3;
        }

        break;

    case 1:
        if (!--F_Timer[PL_id]) {
            F_No1[PL_id] += 1;
            F_Timer[PL_id] = 50;

            if (save_w[1].extra_option.contents[3][5]) {
                if (PL_id) {
                    SSPutStr(DE_X[1], 0, 9, "   PRESS 2P START");
                } else {
                    SSPutStr(DE_X[0], 0, 9, "   PRESS 1P START");
                }
            }
        }

        break;

    case 2:
        if (--F_Timer[PL_id]) {
            if (save_w[1].extra_option.contents[3][5]) {
                if (PL_id) {
                    SSPutStr(DE_X[1], 0, 9, "   PRESS 2P START");
                } else {
                    SSPutStr(DE_X[0], 0, 9, "   PRESS 1P START");
                }
            }
        } else {
            F_No1[PL_id] -= 1;
            F_Timer[PL_id] = 30;
        }

        break;

    case 3:
        F_No1[PL_id] = 99;
        /* fallthrough */

    default:
        if (save_w[1].extra_option.contents[3][5]) {
            SSPutStr(DE_X[1], 0, 9, "     CONTINUE?");
        }

        break;
    }

    return 0;
}

s32 Flash_Please(s16 PL_id) {
    if (E_No[0] == 6 || E_No[0] == 8) {
        return 0;
    }

    switch (F_No3[PL_id]) {
    case 0:
        F_No3[PL_id] += 1;
        F_No1[PL_id] = 0;
        F_Timer[PL_id] = 1;
        break;

    case 1:
        if (--F_Timer[PL_id] == 0) {
            F_No3[PL_id] += 1;
            F_Timer[PL_id] = 50;
        }

        break;

    default:
        if (--F_Timer[PL_id]) {
            SSPutStr(DE_X[PL_id], 0, 9, "    PLEASE WAIT");
        } else {
            F_No3[PL_id] -= 1;
            F_Timer[PL_id] = 30;
        }

        break;
    }

    return 0;
}

void Break_Into_Sub(s16 PL_id, s16 Jump_Index) {
    switch (Jump_Index) {
    case 0:
    case 1:
    case 2:
    case 3:
        Break_Into_02(PL_id);
        break;

    case 4:
    case 6:
        Break_Into_04(PL_id);
        break;

    case 5:
        Break_Into_05(PL_id);
        break;

    case 7:
        Break_Into_07(PL_id);
        break;

    case 8:
        Break_Into_08(PL_id);
        break;

    case 9:
        Break_Into_09(PL_id);
        break;

    case 10:
        Break_Into_10(PL_id);
        break;

    default:
        break;
    }
}

s32 Ck_Break_Into(u16 Sw_0, u16 Sw_1, s16 PL_id) {
    if ((E_No[0] != 10) && Request_Break[PL_id ^ 1]) {
        return 0;
    }

    if (Request_Break[PL_id]) {
        if (Forbid_Break || Extra_Break) {
            return 0;
        }

        Game_pause = 1;
        New_Challenger = PL_id;
        Champion = New_Challenger ^ 1;
        Request_Break[PL_id] = 0;
        return ENTRY_X = 1;
    }

    if (!(~Sw_1 & Sw_0 & 0x4000)) {
        return 0;
    }

    Continue_Score_Sub(PL_id);

    if (Forbid_Break || Extra_Break) {
        Request_Break[PL_id] = 1;
    } else {
        Game_pause = 1;
        New_Challenger = PL_id;
        Champion = New_Challenger ^ 1;
        return ENTRY_X = 1;
    }

    return 0;
}

s32 Ck_Break_Into_SP(u16 Sw_0, u16 Sw_1, s16 PL_id) {
    if (!(~Sw_1 & Sw_0 & 0x4000)) {
        return 0;
    }

    New_Challenger = PL_id;
    Champion = New_Challenger ^ 1;
    return ENTRY_X = 1;
}

void Break_Into_02(s16 /* unused */) {
    plw[New_Challenger].wu.operator = 1;
    Operator_Status[New_Challenger] = 1;
    E_Number[New_Challenger][0] = 0;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;

    if (Continue_Coin[New_Challenger] == 0) {
        grade_check_work_1st_init(New_Challenger, 0);
    }

    Select_Timer = 48;
    Unit_Of_Timer = 50;
}

void Break_Into_04(s16 /* unused */) {
    Break_Into = 1;
    E_No[1] += 1;
    E_No[2] = 0;
    E_Timer = 150;
    E_Number[New_Challenger][0] = 0;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;
    effect_A2_init(0);
    sound_all_off();
    sub_00098407(0xB6);
    Request_LDREQ_Break();
}

void Break_Into_05(s16 PL_id) {
    Break_Into = 1;
    Stop_Combo = 1;
    E_No[1] += 1;
    E_No[2] = 0;
    E_Number[New_Challenger][0] = 0;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;

    if ((Play_Type == 0) && (Conclusion_Flag != 0) && (plw[Champion].wu.operator == 0)) {
        E_Timer = 1;

        if (LOSER != New_Challenger) {
            E_No[3] = 0xFF;
        } else {
            E_No[3] = 0;
        }
    } else {
        E_Timer = 150;

        if (Conclusion_Flag == 0) {
            Score[Champion][0] = Stage_Stock_Score[Champion];
        }

        effect_A2_init(0);
        sound_all_off();
        sub_00098407(0xB6);
        Request_LDREQ_Break();
    }

    Stop_Update_Score = 1;
    cpExitTask(4);
}

void Break_Into_07(s16 PL_id) {
    E_Number[New_Challenger][0] = 0;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;
    E_07_Flag[PL_id] = 1;

    if (E_07_Flag[0] != 0 && E_07_Flag[1] != 0) {
        return;
    }

    E_No[1] += 1;
    E_No[2] = 0;
    Break_Into = 1;
}

void Break_Into_08(s16 PL_id) {
    E_Number[New_Challenger][0] = 0;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;
    E_07_Flag[PL_id] = 1;

    if (E_07_Flag[0] != 0 && E_07_Flag[1] != 0) {
        return;
    }

    Break_Into = 1;
    E_No[1] += 1;
    E_No[2] = 0;

    if (Continue_Count[PL_id ^ 1] >= 0) {
        E_Timer = 60;
        return;
    }

    E_Timer = 10;
}

void Break_Into_09(s16 PL_id) {
    E_Number[New_Challenger][0] = 0;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;
    E_07_Flag[PL_id] = 1;

    if (E_07_Flag[0] != 0 && E_07_Flag[1] != 0) {
        return;
    }

    Break_Into = 1;
    E_No[1] += 1;
    E_No[2] = 0;
    Champion = New_Challenger;
}

void Break_Into_10(s16 PL_id) {
    E_Number[New_Challenger][0] = 0;
    E_Number[New_Challenger][1] = 0;
    E_Number[New_Challenger][2] = 0;
    E_Number[New_Challenger][3] = 0;
    E_07_Flag[PL_id] = 1;

    if (E_07_Flag[0] != 0 && E_07_Flag[1] != 0) {
        return;
    }

    Break_Into = 1;
    E_No[1] += 1;
    E_No[2] = 0;
    Champion = New_Challenger;
}

void Continue_Score_Sub(s16 PL_id) {
    if ((E_Number[PL_id][0] == 1) || (E_Number[PL_id][0] == 5)) {
        Continue_Coin[PL_id] += 1;

        if (Continue_Coin[PL_id] >= 99) {
            Continue_Coin[PL_id] = 99;
        }
    }
}

void Correct_BI_Data() {
    Super_Arts_Finish[Player_id] -= Stage_SA_Finish[Player_id];
    Lost_Round[Player_id] -= Stage_Lost_Round[Player_id];
    Perfect_Finish[Player_id] -= Stage_Perfect_Finish[Player_id];
    Cheap_Finish[Player_id] -= Stage_Cheap_Finish[Player_id];
}
