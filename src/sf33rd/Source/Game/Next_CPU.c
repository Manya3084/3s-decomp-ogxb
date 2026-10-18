/* Next_CPU.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Next_CPU_4th_1_Sub 0x67968 size 0x1E.
 * Next_CPU_4th_2_Sub 0x67986 size 0x33.
 * Check_EM_Speech 0x679B9 size 0x2B. Read against the x86: the table read is
 * Boss_Speech_Data, indexed [My_char][VS_Index - 8] with the -8 folded into
 * the base, so the base address falls in Middle_Class_Boss_Data just before
 * it. Boss_Speech_Data is 0x2495E4. The C is the PS2 C.
 * Middle_Class_Boss_Data.
 * Next_CPU_6th 0x679E4 size 0x8.
 * Wait_Load_Complete 0x679EC size 0x44. Read against the x86:
 * sndCheckVTransStatus is the call to 0x9B78F, a body folded with three
 * others. The C is the PS2 C.
 * Wait_Load_Complete2 0x67A30 size 0x44. Read against the x86:
 * sndCheckVTransStatus is the call to 0x9B78F, a body folded with three
 * others. The C is the PS2 C.
 * Wait_Load_Complete3 0x67A74 size 0x44.
 * After_Bonus_1st 0x67AB8 size 0x76.
 * After_Bonus_2nd 0x67B2E size 0xCE.
 * Select_CPU_4th 0x67BFC size 0x13.
 * Next_Bonus_End 0x67C0F size 0x8.
 * Next_Q_3rd 0x67C17 size 0x99.
 * Sel_CPU_Sub 0x67CB0 size 0x148.
 * Setup_EM_List 0x67DF8 size 0x57.
 * Setup_Com_Arts 0x67E4F size 0x2C. Read against the x86: 0xFF is the compare
 * with -1. The C is the PS2 C.
 * Setup_Com_Color 0x67E7B size 0x2B. Read against the x86: the Com_Color_Shot
 * choice is branchless (0x10 plus 0x3F0 masked). The C is the PS2 C.
 * Setup_PL_Color 0x67EA6 size 0x2A5. Read against the x86: 0x1A is a row size,
 * and 0xC0 and 0x50 are steps of the switch compare chain. The C is the PS2 C.
 * Regular_OBJ_Sub 0x6814B size 0x7A. Read against the x86: 4 and 6 are the ix
 * + 4 and ix + 6 arguments, with lea. The C is the PS2 C.
 * Setup_History_OBJ 0x681C5 size 0x1A4. Read against the x86: 0xAC is a
 * per-player record size. The C is the PS2 C.
 * Setup_VS_OBJ 0x68369 size 0x12A.
 * Check_Bonus_Type 0x68493 size 0x5B. Read against the x86: 0x208 is the
 * save_w stride. The C is the PS2 C.
 * Setup_Next_Stage 0x684EE size 0x1F. Read against the x86: 0x17 is the ix +
 * 23 argument, with lea. The C is the PS2 C.
 * Auto_Cut_Sub 0x6850D size 0x4E.
 * Next_CPU_4th_0_Sub 0x6855B size 0xB9.
 * Next_CPU_5th 0x68614 size 0x251.
 * Next_Bonus_1st 0x68865 size 0xAB. Read against the x86: 0x1CA is the + 458
 * of Target_BG_X[3], with lea. The C is the PS2 C.
 * Next_Bonus_3rd 0x68910 size 0x6A.
 * Next_Q_2nd 0x6897A size 0xCD.
 * Setup_Next_Fighter 0x68A47 size 0xB2.
 * Setup_Regular_OBJ 0x68AF9 size 0xC6.
 * Check_Bonus_Stage 0x68BBF size 0x9C.
 * Check_Auto_Cut 0x68C5B size 0x19.
 * Next_CPU_1st 0x68C74 size 0x13E. Read against the x86: 0x1CA is the + 458 of
 * Target_BG_X[3], with lea. The C is the PS2 C.
 * Next_CPU_3rd 0x68DB2 size 0x16B.
 * Next_CPU_4th 0x68F1D size 0x60.
 * Select_CPU_1st 0x68F7D size 0xFA.
 * NC_Cut_Sub 0x69077 size 0x20.
 * Select_CPU_3rd 0x69097 size 0x39B. Read against the x86: 0xB and 0x28 are
 * the + 11 and + 40 Order indexes, with lea. The C is the PS2 C.
 * Next_Bonus_2nd 0x69432 size 0xA4.
 * Next_Q_1st 0x694D6 size 0x43.
 * Next_CPU_2nd 0x69519 size 0x5.
 * After_Bonus 0x6951E size 0x85.
 * Select_CPU_2nd 0x695A3 size 0x93.
 * Next_Q 0x69636 size 0x68.
 * Next_CPU 0x6969E size 0x95.
 * Select_CPU_First 0x69733 size 0x53.
 * BGM_Request is folded into 0x98407.
 * Sound_SE is folded into 0x98407.
 * setup_pos_remake_key is folded into 0x4384A.
 * sndCheckVTransStatus is folded into 0x9B78F.
 * Data: SEL_CPU_X 0xC7E54C.
 * Data: Start_X 0xC7E54E.
 * Data: Arts_Rnd_Data is 0x25F3DC, 0x8 bytes compared.
 * Unnamed data used (not checked): Sel_CPU_Sub: 0x267c08.
 * FadeIn/FadeOut priority is 1 on Xbox (PS2 8) in Next_CPU_4th_0_Sub,
 * Next_CPU_4th_1_Sub, Next_CPU_4th_2_Sub, Next_CPU_5th, Next_Q_3rd.
 * Globals: Boss_Speech_Data 0x2495E4, Arts_Rnd_Data 0x25F3DC,
 * EM_Select_Voice_Data 0x267D88, ID 0x7A80CC, EM_Candidate 0x7A80E0,
 * paring_counter 0x7A8108, Player_id 0x7A810F, Q_Country 0x7A8110, My_char
 * 0x7A8114, VS_Index 0x7A811C, Bonus_Type 0x7A8120, Completion_Bonus 0x7A8130,
 * Time_Over 0x7A8150, Present_Mode 0x7A819C, Sel_PL_Complete 0x7A81BC, COM_id
 * 0x7A81C0, Moving_Plate 0x7A81C2, Cover_Timer 0x7A81F4, G_No 0x7A825C,
 * Suicide 0x7A8268, Stock_Com_Arts 0x7A829A, Sel_EM_Complete 0x7A82A4,
 * Unit_Of_Timer 0x7A82A8, LOSER 0x7A82FD, paring_bonus_r 0x7A8314,
 * Battle_Country 0x7A8356, Order 0x7A8380, Demo_Flag 0x7A842D, Introduce_Boss
 * 0x7A8454, Scene_Cut 0x7A8461, Order_Timer 0x7A8480, EM_id 0x7A8517,
 * Aborigine 0x7A8518, Unsubstantial_BG 0x7A851C, EM_List 0x7A8594, Order_Dir
 * 0x7A85E0, Break_Com 0x7A8680, Ignore_Entry 0x7A86AA, Next_Step 0x7A86D2,
 * Com_Color_Shot 0x7A8758, Last_Selected_EM 0x7A875A, Exit_Timer 0x7A876E,
 * Target_BG_X 0x7A8780, Offset_BG_X 0x7A87B0, Break_Into 0x7A8802,
 * Forbid_Break 0x7A8804, EM_History 0x7A88C0, S_Timer 0x7A88F0, Temporary_EM
 * 0x7A88F2, Cut_Scroll 0x7A88FE, Player_Color 0x7A8906, Time_Stop 0x7A8918,
 * Moving_Plate_Counter 0x7A89CE, Select_Timer 0x7A89D1, Super_Arts 0x7A89FE,
 * SC_No 0x7A8A20, bg_mvxy 0x7BC4C0, base_y_pos 0x7BC516, bg_w 0x7BC520,
 * bgPalCodeOffset 0x7BCC60, p1sw_1 0x7BD3CA, save_w 0x7BD3E0, p2sw_1 0x7C5568,
 * p1sw_0 0x7C557C, p2sw_0 0x7C5B90, plw 0xC7CEA0, SEL_CPU_X 0xC7E54C, Start_X
 * 0xC7E54E, judge_final 0xC7EDC0.
 */

#include "structs.h"

void sub_00098407();
void sub_0004384A(s16 );
s32 sub_0009B78F(s32 type);
void Next_CPU_1st();
void Next_CPU_2nd();
void Next_CPU_3rd();
void Next_CPU_4th();
void Next_CPU_5th();
void Next_CPU_6th();
void Next_Bonus_1st();
void Next_Bonus_2nd();
void Next_Bonus_3rd();
void Next_Bonus_End();
void Wait_Load_Complete();
void Wait_Load_Complete2();
extern s8 Break_Into;
extern u8 Scene_Cut;
s32 Cut_Cut_Cut();
extern u8 SC_No[4];
extern s8 Time_Over;
s32 Check_Exit_Check();
extern s8 Debug_w[72];
extern s16 Target_BG_X[6];
extern BG bg_w;
extern s16 Offset_BG_X[6];
extern MVXY bg_mvxy;
extern s8 Sel_EM_Complete[2];
extern s8 Player_id;
extern s8 Temporary_EM[2];
extern s8 Last_Selected_EM[2];
extern s8 Select_Timer;
void Setup_EM_List();
extern s16 VS_Index[2];
s32 effect_A9_init(s16 Char_Index, s16 Option, s16 Pos_Index, s16 Option2);
void Setup_History_OBJ();
void Setup_Next_Stage(s16 dir_step);
void Setup_Regular_OBJ(s16 PL_id);
extern s8 Moving_Plate[2];
extern u8 G_No[4];
extern u8 Order[148];
extern u8 Order_Timer[148];
extern s8 Time_Stop;
extern s16 Unit_Of_Timer;
s32 effect_A5_init();
s32 random_16();
s32 effect_58_init(s16 id, s16 time0, s16 option);
extern const u16 EM_Select_Voice_Data[4];
extern s8 Next_Step;
extern s8 Suicide[8];
extern s8 Cut_Scroll;
void NC_Cut_Sub();
void Sel_CPU_Sub(s16 PL_id, u16 sw, u16 );
extern u16 p2sw_1;
extern u16 p2sw_0;
extern u16 p1sw_1;
extern u16 p1sw_0;
extern u8 My_char[2];
void Push_LDREQ_Queue_Player(s16 id, s16 ix);
extern s8 COM_id;
void Setup_Next_Fighter();
extern s16 S_Timer;
void SsBgmFadeOut(u16 time);
u8 Check_EM_Speech();
void FadeInit();
void Next_CPU_4th_0_Sub();
void Next_CPU_4th_1_Sub();
void Next_CPU_4th_2_Sub();
s32 FadeIn(u8 type, u8 step, u8 priority);
extern s8 Forbid_Break;
extern s32 bgPalCodeOffset[8];
extern s16 Exit_Timer;
void Setup_BG(s16 BG_INDEX, s16 X, s16 Y);
void Setup_VS_OBJ(s16 Option);
void Switch_Screen_Init(s32 );
s32 Switch_Screen(u8 Wipe_Type);
extern s8 Cover_Timer;
extern u8 Order_Dir[148];
s32 effect_76_init(s16 dir_old);
s32 Switch_Screen_Revival(u8 Wipe_Type);
s32 effect_43_init(s16 Time, s16 Target_BG);
extern u8 Introduce_Boss[2][2];
extern const u8 Boss_Speech_Data[20][2];
s32 Check_PL_Load();
s32 Check_LDREQ_Queue_BG(s16 ix);
s32 adx_now_playend();
void init_omop();
void After_Bonus_1st();
void After_Bonus_2nd();
void All_Clear_Suicide();
void System_all_clear_Level_B();
extern s16 base_y_pos;
void bg_etc_write(s16 type);
void Setup_Virtual_BG(s16 BG_INDEX, s16 X, s16 Y);
extern u8 Unsubstantial_BG[4];
void Purge_mmtm_area(s16 ix);
void Purge_com_player_from_mm();
void Make_texcash_of_list(s16 ix);
void Clear_Flash_No();
extern s8 Ignore_Entry[2];
extern s8 LOSER;
void Select_CPU_1st();
void Select_CPU_2nd();
void Select_CPU_3rd();
void Select_CPU_4th();
void Push_LDREQ_Queue_Direct(s16 ix, s16 id);
extern u8 Aborigine;
void Check_Auto_Cut();
extern s8 Demo_Flag;
u16 Check_Demo_Data(s16 PL_id);
s32 Check_LDREQ_Queue_Direct(s16 ix);
s32 effect_38_init(s16 PL_id, s16 dir_old, s16 Your_Char, s16 Play_Status, s16 Target_BG);
u32 check_use_all_SA();
u32 check_without_SA();
extern s8 EM_id;
s32 effect_98_init(s16 PL_id, s16 dir_old, s16 master_player, s16 Target_BG);
extern s8 Super_Arts[2];
s32 effect_75_init(s16 dir_old, s16 ID, s16 Target_BG);
extern u8 Bonus_Type;
void Next_Q_1st();
void Next_Q_2nd();
void Next_Q_3rd();
void Setup_ID();
void effect_work_quick_init();
extern s8 Moving_Plate_Counter[2];
extern u8 EM_List[2][2];
extern s16 ID;
extern const u8 Voice_EM_Random_Data[16];
extern u8 EM_Candidate[2][2][10];
extern u8 paring_counter[2];
extern u8 paring_bonus_r[2];
extern s16 Battle_Country;
extern u8 Q_Country;
void Push_LDREQ_Queue_BG(s16 ix);
extern s8 Stock_Com_Arts[2];
s8 Setup_Com_Arts();
void Setup_Com_Color();
void Setup_PL_Color(s16 PL_id, u16 sw);
extern s16 Com_Color_Shot;
extern s16 Stock_Com_Color[2];
extern s8 Break_Com[2][20];
extern PLW plw[2];
extern s16 Sel_PL_Complete[2];
extern struct _SAVE_W save_w[6];
extern u8 Present_Mode;
extern s8 Player_Color[2];
void Regular_OBJ_Sub(s16 PL_id, s16 Dir);
s32 effect_42_init(s16 Type);
s32 chkNameAkuma(s32 plnum, s32 rnum);
s32 effect_E0_init(s16 Direction, s16 dm_vital, s16 Pos_Type);
extern u8 EM_History[2][10];
extern GradeFinalData judge_final[2][2];
s32 effect_K6_init(s16 PL_id, s16 dir_old, s16 dm_vital, s16 Target_BG);
s32 effect_39_init(s16 PL_id, s16 dir_old, s16 Your_Char, s16 Target_BG, s16 Option);
s8 Check_Bonus_Type();
extern s8 Completion_Bonus[2][2];
extern u8 Usage;
s32 Auto_Cut_Sub();

extern u8 SEL_CPU_X;

extern s16 Start_X;

const u8 Arts_Rnd_Data[8] = { 0, 0, 0, 1, 1, 1, 2, 2 };

s16 Next_CPU() {
    void (*Next_CPU_Tbl[12])() = { Next_CPU_1st,   Next_CPU_2nd,   Next_CPU_3rd,       Next_CPU_4th,
                                   Next_CPU_5th,   Next_CPU_6th,   Next_Bonus_1st,     Next_Bonus_2nd,
                                   Next_Bonus_3rd, Next_Bonus_End, Wait_Load_Complete, Wait_Load_Complete2 };

    if (Break_Into) {
        return 0;
    }

    SEL_CPU_X = 0;
    Scene_Cut = Cut_Cut_Cut();
    Next_CPU_Tbl[SC_No[0]]();
    Time_Over = 0;

    if (Check_Exit_Check() == 0 && Debug_w[0x18] == 0xFF) {
        SEL_CPU_X = 0;
    }

    return SEL_CPU_X;
}

void Next_CPU_1st() {
    u16 Rnd;

    SC_No[0]++;
    Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 458;
    Offset_BG_X[3] = 0;
    Start_X = bg_w.bgw[3].wxy[0].disp.pos;
    bg_mvxy.a[0].sp = 0x40000;
    bg_mvxy.d[0].sp = 0;
    Sel_EM_Complete[Player_id] = 0;
    Temporary_EM[Player_id] = Last_Selected_EM[Player_id];
    Select_Timer = 32;
    Setup_EM_List();

    if (VS_Index[Player_id] == 0) {
        effect_A9_init(32, 0, 0, 0);
    } else {
        Setup_History_OBJ();

        if (VS_Index[Player_id] < 9) {
            Setup_Next_Stage(58);
        } else {
            Setup_Next_Stage(59);
        }
    }

    Setup_Regular_OBJ(Player_id);
    Moving_Plate[Player_id] = 0;

    if (G_No[1] == 5) {
        sub_00098407(57);
        Order[56] = 3;
        Order_Timer[56] = 1;
    }

    Time_Stop = 1;
    Unit_Of_Timer = 50;
    effect_A5_init();
    Rnd = random_16() & 3;
    effect_58_init(6, 10, EM_Select_Voice_Data[Rnd]);
    Next_Step = 0;
    Suicide[2] = 1;
    Cut_Scroll = 2;
    effect_58_init(13, 1, 3);
    effect_58_init(16, 5, 2);
    sub_0004384A(5);
}

void Next_CPU_2nd() {
    NC_Cut_Sub();
}

void Next_CPU_3rd() {
    switch (SC_No[1]) {
    case 0:
        if (Player_id) {
            Sel_CPU_Sub(1, ~p2sw_1 & p2sw_0, p2sw_0);
        } else {
            Sel_CPU_Sub(0, ~p1sw_1 & p1sw_0, p1sw_0);
        }

        if (!Sel_EM_Complete[Player_id]) {
            break;
        }

        SC_No[1]++;
        SC_No[2] = 0;

        if (Debug_w[0x1D]) {
            My_char[0] = Debug_w[0x1D] - 1;
        }

        if (Debug_w[0x1E]) {
            My_char[1] = Debug_w[0x1E] - 1;
        }

        Push_LDREQ_Queue_Player(COM_id, My_char[COM_id]);
        Setup_Next_Fighter();

        if (Debug_w[0x1D]) {
            My_char[0] = Debug_w[0x1D] - 1;
        }

        if (Debug_w[0x1E]) {
            My_char[1] = Debug_w[0x1E] - 1;
        }

        if (VS_Index[Player_id] < 8) {
            S_Timer = 50;
            break;
        }

        SC_No[1] = 2;
        S_Timer = 100;
        break;

    case 1:
        switch (SC_No[2]) {
        case 0:
            if (S_Timer < 10) {
                S_Timer = 9;
                SC_No[2]++;
                SsBgmFadeOut(0x1000);
            }

            break;
        }

        if ((S_Timer -= 1) == 0) {
            SC_No[0]++;
            SC_No[1] = 0;
            SC_No[2] = 0;
        }

        break;

    case 2:
        if ((S_Timer -= 1) < 71) {
            if (Check_EM_Speech() == 0) {
                SC_No[1]++;
            } else {
                SC_No[0] = 4;
                SC_No[1] = 0;
            }

            SC_No[2] = 0;
            break;
        }

        break;

    case 3:
        switch (SC_No[2]) {
        case 0:
            if (Scene_Cut) {
                S_Timer = 9;
            }

            if (S_Timer < 10) {
                S_Timer = 9;
                SC_No[2]++;
                SsBgmFadeOut(0x1000U);
            }

            break;
        }

        if ((S_Timer -= 1) == 0) {
            SC_No[0]++;
            SC_No[1] = 0;
            SC_No[2] = 0;
        }

        break;
    }
}

void Next_CPU_4th() {
    switch (SC_No[1]) {
    case 0:
        FadeInit();
        Next_CPU_4th_0_Sub();
        break;

    case 1:
        Next_CPU_4th_1_Sub();
        break;

    case 2:
        Next_CPU_4th_2_Sub();
        break;

    default:
        if (Scene_Cut) {
            S_Timer = 1;
        }

        if ((S_Timer -= 1) != 0) {
            break;
        }

        if (G_No[1] == 5 || G_No[1] == 10) {
            SC_No[0] = 10;
            break;
        }

        SC_No[0] = 6;
        break;
    }
}

void Next_CPU_4th_0_Sub() {
    FadeIn(0, 4, 1);
    SC_No[1]++;
    Forbid_Break = 0;
    bgPalCodeOffset[0] = 144;
    sub_00098407(51);
    S_Timer = 178;
    Exit_Timer = 2;
    bg_w.bgw[0].wxy[0].disp.pos += 512;
    bg_w.bgw[1].wxy[1].disp.pos = 512;
    bg_w.bgw[3].wxy[1].disp.pos += 512;
    Setup_BG(0, bg_w.bgw[0].wxy[0].disp.pos, bg_w.bgw[0].wxy[1].disp.pos);
    Setup_BG(1, bg_w.bgw[1].wxy[0].disp.pos + 512, bg_w.bgw[1].wxy[1].disp.pos);
    Setup_BG(3, bg_w.bgw[3].wxy[0].disp.pos, bg_w.bgw[3].wxy[1].disp.pos);
    Setup_VS_OBJ(0);
    Suicide[0] = 1;
    FadeInit();
}

void Next_CPU_4th_1_Sub() {
    FadeIn(0, 4, 1);

    if ((Exit_Timer -= 1) == 0) {
        SC_No[1]++;
    }
}

void Next_CPU_4th_2_Sub() {
    S_Timer--;

    if (!FadeIn(0, 4, 1)) {
        return;
    }

    SC_No[1]++;

    if (S_Timer < 0) {
        S_Timer = 1;
    }
}

void Next_CPU_5th() {
    switch (SC_No[1]) {
    case 0:
        SC_No[1]++;
        Switch_Screen_Init(1);
        break;

    case 1:
        if (Switch_Screen(1) != 0) {
            SC_No[1]++;
            Cover_Timer = 9;
        }

        break;

    case 2:
        Switch_Screen(1);
        SC_No[1]++;
        bgPalCodeOffset[0] = 144;
        bg_w.bgw[0].wxy[0].disp.pos += 512;
        bg_w.bgw[1].wxy[1].disp.pos = 512;
        bg_w.bgw[3].wxy[1].disp.pos += 512;
        Setup_BG(0, bg_w.bgw[0].wxy[0].disp.pos, bg_w.bgw[0].wxy[1].disp.pos);
        Setup_BG(1, bg_w.bgw[1].wxy[0].disp.pos, bg_w.bgw[1].wxy[1].disp.pos);
        Setup_BG(3, bg_w.bgw[3].wxy[0].disp.pos, bg_w.bgw[3].wxy[1].disp.pos);
        Setup_VS_OBJ(1);
        Suicide[0] = 1;
        Next_Step = 0;
        Order[67] = 1;
        Order_Timer[67] = 10;
        Order_Dir[67] = 8;
        effect_76_init(67);
        Order[68] = 1;
        Order_Timer[68] = 10;
        Order_Dir[68] = 4;
        effect_76_init(68);
        break;

    case 3:
        Switch_Screen(1);

        if ((Cover_Timer -= 1) == 0) {
            SC_No[1]++;
            Switch_Screen_Init(1);
        }

        break;

    case 4:
        if (Switch_Screen_Revival(1) != 0) {
            SC_No[1]++;
            Forbid_Break = 0;
        }

        break;

    case 5:
        if ((Next_Step & 0x80) != 0) {
            SC_No[1]++;
            S_Timer = 8;
            SsBgmFadeOut(0x1000);
        }

        break;

    case 6:
        if (!(S_Timer -= 1)) {
            FadeInit();
            FadeIn(0, 4, 1);
            SC_No[1]++;
            Forbid_Break = 0;
            Suicide[3] = 1;
            effect_43_init(1, 0);
            sub_00098407(0x33);
            S_Timer = 0xb2;
        }

        break;

    case 7:
        S_Timer--;

        if (FadeIn(0, 4, 1)) {
            SC_No[1]++;

            if (S_Timer < 0) {
                S_Timer = 1;
            }

            Introduce_Boss[Player_id][VS_Index[Player_id] - 8] |= 1;
        }

        break;

    default:
        if (Scene_Cut) {
            S_Timer = 1;
        }

        if ((S_Timer -= 1) == 0) {
            SC_No[0] = 10;
        }

        break;
    }
}

u8 Check_EM_Speech() {
    if (Introduce_Boss[Player_id][VS_Index[Player_id] - 8] & 1) {
        return 0;
    }

    return Boss_Speech_Data[My_char[Player_id]][VS_Index[Player_id] - 8];
}

void Next_CPU_6th() {
    SEL_CPU_X = 1;
}

void Wait_Load_Complete() {
    if (!Check_PL_Load()) {
        return;
    }

    if (!Check_LDREQ_Queue_BG(bg_w.stage + 0)) {
        return;
    }

    if (!adx_now_playend()) {
        return;
    }

    if (!sub_0009B78F(0)) {
        return;
    }

    SEL_CPU_X = 1;
    init_omop();
    SC_No[0] = 5;
}

void Wait_Load_Complete2() {
    if (!Check_PL_Load()) {
        return;
    }

    if (!Check_LDREQ_Queue_BG(bg_w.stage + 0)) {
        return;
    }

    if (!adx_now_playend()) {
        return;
    }

    if (!sub_0009B78F(0)) {
        return;
    }

    SEL_CPU_X = 2;
    init_omop();
    SC_No[0] = 10;
}

void Wait_Load_Complete3() {
    if (!Check_PL_Load()) {
        return;
    }

    if (!Check_LDREQ_Queue_BG(bg_w.stage + 0)) {
        return;
    }

    if (!adx_now_playend()) {
        return;
    }

    if (!sub_0009B78F(0)) {
        return;
    }

    SEL_CPU_X = 2;
    init_omop();
    SC_No[0] = 7;
}

s32 After_Bonus() {
    void (*After_Bonus_Tbl[11])() = { After_Bonus_1st, After_Bonus_2nd, Next_CPU_1st,        Next_CPU_2nd,
                                      Next_CPU_3rd,    Next_CPU_4th,    Wait_Load_Complete2, Next_Bonus_End,
                                      Next_Bonus_End,  Next_Bonus_End,  Wait_Load_Complete3 };

    if (Break_Into) {
        return 0;
    }

    SEL_CPU_X = 0;
    Scene_Cut = Cut_Cut_Cut();
    After_Bonus_Tbl[SC_No[0]]();
    Time_Over = 0;
    return SEL_CPU_X;
}

void After_Bonus_1st() {
    Switch_Screen(0);
    SC_No[0]++;
    Cover_Timer = 23;
    All_Clear_Suicide();
    System_all_clear_Level_B();
    base_y_pos = 40;
    bg_etc_write(2);
    Setup_Virtual_BG(0, 0x100, 0);
    Setup_BG(2, 0x300, 0);
    Setup_BG(1, 0x200, 0);
    Setup_BG(3, 0x2C0, 0);
    Unsubstantial_BG[0] = 1;
    sub_0004384A(5);
}

void After_Bonus_2nd() {
    switch (SC_No[1]) {
    case 0:
        Switch_Screen(0);
        Purge_mmtm_area(7);
        Purge_com_player_from_mm();
        Make_texcash_of_list(7);
        SC_No[1]++;
        effect_76_init(55);
        Order[55] = 3;
        Order_Timer[55] = 1;
        effect_76_init(56);
        Order[56] = 3;
        Order_Timer[56] = 1;
        /* fallthrough */

    case 1:
        Switch_Screen(1);

        if ((Cover_Timer -= 1) == 0) {
            SC_No[1]++;
            Clear_Flash_No();
            Switch_Screen_Init(1);
        }

        break;

    case 2:
        if (Switch_Screen_Revival(1) != 0) {
            SC_No[0]++;
            SC_No[1] = 0;
            S_Timer = 30;
            sub_00098407(57);
            Forbid_Break = 0;
            Ignore_Entry[LOSER] = 0;
        }

        break;
    }
}

s16 Select_CPU_First() {
    void (*Select_CPU_First_Tbl[4])() = { Select_CPU_1st, Select_CPU_2nd, Select_CPU_3rd, Select_CPU_4th };

    if (Break_Into) {
        return 0;
    }

    SEL_CPU_X = 0;
    Select_CPU_First_Tbl[SC_No[0]]();
    Time_Over = 0;
    return SEL_CPU_X;
}

void Select_CPU_1st() {
    SC_No[0]++;
    Sel_EM_Complete[Player_id] = 0;
    Temporary_EM[Player_id] = Last_Selected_EM[Player_id];
    Select_Timer = 32;
    Setup_EM_List();
    Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 458;
    Offset_BG_X[3] = 0;

    if (VS_Index[Player_id] == 0) {
        bg_mvxy.a[0].sp = 0xA0000;
        bg_mvxy.d[0].sp = 0x18000;
        effect_A9_init(32, 0, 0, 1);
    } else {
        Setup_History_OBJ();
        bg_mvxy.a[0].sp = 0x40000;
        bg_mvxy.d[0].sp = 0;

        if (VS_Index[Player_id] < 9) {
            Setup_Next_Stage(58);
        } else {
            Setup_Next_Stage(59);
        }

        effect_76_init(66);
        Order[66] = 3;
        Order_Timer[66] = 1;
    }

    Setup_Regular_OBJ(Player_id);
    Moving_Plate[Player_id] = 0;

    if (VS_Index[Player_id] >= 8) {
        Push_LDREQ_Queue_Direct(9, 2);
    }

    sub_0004384A(5);
}

void Select_CPU_2nd() {
    u16 Rnd;

    switch (SC_No[1]) {
    case 0:
        SC_No[1]++;
        Order[Aborigine + 13] = 5;
        Order_Timer[Aborigine + 13] = 1;
        Order[Aborigine + 31] = 5;
        Order_Timer[Aborigine + 31] = 1;
        Order[Aborigine + 25] = 5;
        Order_Timer[Aborigine + 25] = 1;
        Order[37] = 4;
        Order_Timer[37] = 1;
        Rnd = random_16() & 3;
        effect_58_init(6, 10, EM_Select_Voice_Data[Rnd]);
        Cut_Scroll = 2;
        Next_Step = 0;
        effect_58_init(12, 1, 3);
        /* fallthrough */

    case 1:
        NC_Cut_Sub();
        break;
    }
}

void NC_Cut_Sub() {
    Check_Auto_Cut();

    if (Next_Step) {
        SC_No[0]++;
        SC_No[1] = 0;
        Time_Stop = 0;
    }
}

void Select_CPU_3rd() {
    switch (SC_No[1]) {
    case 0:
        if (Demo_Flag == 0) {
            if (Player_id) {
                Sel_CPU_Sub(1, Check_Demo_Data(1), 0);
            } else {
                Sel_CPU_Sub(0, Check_Demo_Data(0), 0);
            }
        } else if (Player_id) {
            Sel_CPU_Sub(1, ~p2sw_1 & p2sw_0, p2sw_0);
        } else {
            Sel_CPU_Sub(0, ~p1sw_1 & p1sw_0, p1sw_0);
        }

        if (!Sel_EM_Complete[Player_id]) {
            break;
        }

        SC_No[1]++;

        if (Debug_w[29]) {
            My_char[0] = Debug_w[29] - 1;
        }

        if (Debug_w[30]) {
            My_char[1] = Debug_w[30] - 1;
        }

        Push_LDREQ_Queue_Player(COM_id, My_char[COM_id]);
        Setup_Next_Fighter();

        if (Debug_w[29]) {
            My_char[0] = Debug_w[29] - 1;
        }

        if (Debug_w[30]) {
            My_char[1] = Debug_w[30] - 1;
        }

        if (VS_Index[Player_id] < 8) {
            S_Timer = 50;
        } else {
            SC_No[1] = 2;
            S_Timer = 100;
        }

        break;

    case 1:
        if ((S_Timer -= 1) == 0) {
            SC_No[1] = 4;
        }

        break;

    case 2:
        if ((S_Timer -= 1) < 51) {
            if (Check_LDREQ_Queue_Direct(9)) {
                SC_No[1]++;
            } else {
                S_Timer = 1;
            }
        }

        break;

    case 3:
        if (Scene_Cut) {
            S_Timer = 1;
        }

        if ((S_Timer -= 1) == 0) {
            SC_No[1]++;
        }

        break;

    case 4:
        SC_No[1] = 6;
        Order[Player_id + 11] = 4;
        Order_Timer[Player_id + 11] = 5;
        effect_38_init(COM_id, COM_id + 11, My_char[COM_id], 1, 2);
        Order[COM_id + 11] = 1;
        Order_Timer[COM_id + 11] = 1;

        if (check_use_all_SA() == 0 && check_without_SA() == 0 && EM_id != 0) {
            effect_98_init(COM_id, COM_id + 0x28, Super_Arts[COM_id], 2);
            Order[COM_id + 40] = 1;
            Order_Timer[COM_id + 40] = 1;
        }

        effect_75_init(42, 3, 2);
        Order[42] = 3;
        Order_Timer[42] = 1;
        Order_Dir[42] = 3;
        Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 480;
        Offset_BG_X[3] = 0;

        if (8 <= VS_Index[Player_id] && Check_EM_Speech()) {
            SC_No[1] = 5;
            Order[67] = 1;
            Order_Timer[67] = 10;
            Order_Dir[67] = 8;
            effect_76_init(67);
            Order[68] = 1;
            Order_Timer[68] = 10;
            Order_Dir[68] = 4;
            effect_76_init(68);
        }

        Next_Step = 0;
        Cut_Scroll = 2;
        bg_mvxy.a[0].sp = 0x200000;
        bg_mvxy.d[0].sp = 0x18000;
        effect_58_init(12, 1, 3);
        break;

    case 5:
        if (Next_Step & 0x80) {
            SC_No[1] = 7;
            S_Timer = 20;
            Introduce_Boss[Player_id][VS_Index[Player_id] - 8] = 1;
        }

        break;

    case 6:
        if (Next_Step & 1) {
            SC_No[1]++;
            S_Timer = 20;
        }

        break;

    case 7:
        switch (SC_No[2]) {
        case 0:
            if (Scene_Cut) {
                S_Timer = 9;
            }

            if (S_Timer < 10) {
                S_Timer = 9;
                SC_No[2]++;
                SsBgmFadeOut(0x1000);
            }

            break;
        }

        if ((S_Timer -= 1) == 0) {
            SC_No[0]++;
            SC_No[1] = 0;
            SC_No[2] = 0;
        }

        break;
    }
}

void Select_CPU_4th() {
    SEL_CPU_X = 1;
    Next_Step = 1;
    init_omop();
}

void Next_Bonus_1st() {
    u16 Rnd;

    SC_No[0]++;
    Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 458;
    Offset_BG_X[3] = 0;
    Start_X = bg_w.bgw[3].wxy[0].disp.pos;
    bg_mvxy.a[0].sp = 0x40000;
    bg_mvxy.d[0].sp = 0;
    Setup_History_OBJ();
    Setup_Next_Stage(60);
    sub_00098407(57);
    Order[56] = 3;
    Order_Timer[56] = 1;
    Rnd = random_16() & 3;
    effect_58_init(6, 10, EM_Select_Voice_Data[Rnd]);
    Suicide[2] = 1;
    Next_Step = 0;
    Cut_Scroll = 2;
    effect_58_init(13, 1, 3);
    effect_58_init(16, 5, 2);
    sub_0004384A(5);
}

void Next_Bonus_2nd() {
    switch (SC_No[1]) {
    case 0:
        Check_Auto_Cut();

        if (Next_Step) {
            SC_No[1]++;
            SC_No[2] = 0;
            S_Timer = 90;
            effect_58_init(6, 5, 160);
        }

        break;

    case 1:
        switch (SC_No[2]) {
        case 0:
            if (Scene_Cut) {
                S_Timer = 9;
            }

            if (S_Timer < 10) {
                S_Timer = 9;
                SC_No[2]++;
                SsBgmFadeOut(0x1000);
            }

            break;
        }

        if ((S_Timer -= 1) == 0) {
            SC_No[0]++;
            SC_No[1] = 0;
            SC_No[2] = 0;
        }

        break;
    }
}

void Next_Bonus_3rd() {
    switch (SC_No[1]) {
    case 0:
        My_char[COM_id] = Bonus_Type;
        Next_CPU_4th_0_Sub();
        break;

    case 1:
        Next_CPU_4th_1_Sub();
        break;

    case 2:
        Next_CPU_4th_2_Sub();
        break;

    default:
        if (Scene_Cut) {
            S_Timer = 1;
        }

        if ((S_Timer -= 1) == 0) {
            if (Check_PL_Load() == 0) {
                S_Timer = 1;
                break;
            }

            SC_No[0] = 11;
        }

        break;
    }
}

void Next_Bonus_End() {
    SEL_CPU_X = 2;
}

s16 Next_Q() {
    void (*Next_Q_Tbl[6])() = {
        Next_Q_1st, Next_Q_2nd, Next_Q_3rd, Wait_Load_Complete, Wait_Load_Complete, Next_CPU_6th
    };

    if (Break_Into) {
        return 0;
    }

    SEL_CPU_X = 0;
    Scene_Cut = Cut_Cut_Cut();
    Next_Q_Tbl[SC_No[0]]();

    if (Check_Exit_Check() == 0 && Debug_w[0x18] == 0xFF) {
        SEL_CPU_X = 0;
    }

    Time_Over = 0;
    return SEL_CPU_X;
}

void Next_Q_1st() {
    After_Bonus_1st();
    Setup_ID();
    EM_id = 17;
    Setup_Next_Fighter();
    Purge_mmtm_area(8);
    Purge_com_player_from_mm();
    Make_texcash_of_list(7);
    Push_LDREQ_Queue_Player(COM_id, 17);
    sub_0004384A(5);
}

void Next_Q_2nd() {
    switch (SC_No[1]) {
    case 0:
        SC_No[1]++;
        /* fallthrough */

    case 1:
        Switch_Screen(0);

        if ((Cover_Timer -= 1) == 5) {
            SC_No[1]++;
            effect_work_quick_init();
            bg_w.bgw[0].wxy[0].disp.pos += 512;
            Setup_BG(0, bg_w.bgw[0].wxy[0].disp.pos, bg_w.bgw[0].wxy[1].disp.pos);
            Setup_VS_OBJ(1);
        }

        break;

    case 2:
        Switch_Screen(0);

        if ((Cover_Timer -= 1) == 0) {
            SC_No[1]++;
            Clear_Flash_No();
            Switch_Screen_Init(1);
        }

        break;

    case 3:
        if (Switch_Screen_Revival(1U) != 0) {
            SC_No[0]++;
            SC_No[1] = 0;
            S_Timer = 10;
            Forbid_Break = 0;
            Ignore_Entry[LOSER] = 0;
        }

        break;
    }
}

void Next_Q_3rd() {
    switch (SC_No[1]) {
    case 0:
        if ((S_Timer -= 1) == 0) {
            SC_No[1]++;
        }

        break;

    case 1:
        FadeInit();
        FadeIn(0, 4, 1);
        SC_No[1]++;
        Forbid_Break = 0;
        effect_43_init(1, 0);
        bgPalCodeOffset[0] = 144;
        sub_00098407(51);
        S_Timer = 180;
        effect_58_init(15, 5, 0);
        return;

    case 2:
        Next_CPU_4th_2_Sub();
        return;

    default:
        if (Scene_Cut) {
            S_Timer = 1;
        }

        if ((S_Timer -= 1) == 0) {
            SC_No[0]++;
        }

        break;
    }
}

void Sel_CPU_Sub(s16 PL_id, u16 sw, u16 /* unused */) {
    u16 lever_sw;

    if (Sel_EM_Complete[PL_id]) {
        return;
    }

    if (Moving_Plate[PL_id]) {
        return;
    }

    if (Time_Over) {
        sw = 16;
    }

    if (VS_Index[PL_id] >= 8) {
        sw = 16;
    }

    lever_sw = sw & 3;

    if (lever_sw & 2) {
        if (Temporary_EM[Player_id] == 2) {
            return;
        }

        sub_00098407(PL_id + 96);
        Moving_Plate[PL_id] = 2;
        Moving_Plate_Counter[PL_id] = 2;
        Temporary_EM[Player_id] = 2;
    }

    if (lever_sw & 1) {
        if (Temporary_EM[Player_id] == 1) {
            return;
        }

        sub_00098407(PL_id + 96);
        Moving_Plate[PL_id] = 1;
        Moving_Plate_Counter[PL_id] = 2;
        Temporary_EM[Player_id] = 1;
    }

    if (sw & 0xFF0) {
        Sel_EM_Complete[PL_id] = 1;
        EM_id = EM_List[Player_id][Temporary_EM[Player_id] - 1];
        My_char[COM_id] = EM_id;
        Time_Stop = 2;

        if (VS_Index[PL_id] < 8) {
            sub_00098407(ID + 98);
            sub_00098407(Voice_EM_Random_Data[random_16()]);
        }

        Last_Selected_EM[PL_id] = Temporary_EM[PL_id];
    }
}

void Setup_EM_List() {
    if (My_char[Player_id] == 0) {
        EM_Candidate[Player_id][0][9] = 1;
        EM_Candidate[Player_id][1][9] = 1;
    } else {
        EM_Candidate[Player_id][0][9] = 0;
        EM_Candidate[Player_id][1][9] = 0;
    }

    EM_List[Player_id][0] = EM_Candidate[Player_id][0][VS_Index[Player_id]];
    EM_List[Player_id][1] = EM_Candidate[Player_id][1][VS_Index[Player_id]];
}

void Setup_Next_Fighter() {
    paring_counter[COM_id] = 0;
    paring_bonus_r[COM_id] = 0;
    My_char[COM_id] = EM_id;

    if (EM_id == 17) {
        Battle_Country = Q_Country;
        bg_w.stage = Q_Country;
    } else {
        Battle_Country = EM_id;

        if (My_char[Player_id] == 0 && EM_id == 1) {
            Battle_Country = 0;
        }

        bg_w.stage = Battle_Country;
    }

    if (Debug_w[31]) {
        Battle_Country = bg_w.stage = Debug_w[31] - 1;
    }

    Push_LDREQ_Queue_BG(bg_w.stage + 0);
    bg_w.area = 0;
    Super_Arts[COM_id] = Stock_Com_Arts[Player_id] = Setup_Com_Arts();

    if (Debug_w[32]) {
        Super_Arts[COM_id] = bg_w.stage = Debug_w[32] - 1;
    }

    Setup_Com_Color();
    Setup_PL_Color(COM_id, Com_Color_Shot);
}

s8 Setup_Com_Arts() {
    if (EM_id == 0) {
        return 1;
    }

    if (Stock_Com_Arts[Player_id] == -1) {
        return Arts_Rnd_Data[random_16() & 7];
    }

    return Stock_Com_Arts[Player_id];
}

void Setup_Com_Color() {
    Com_Color_Shot = Stock_Com_Color[Player_id];

    if (Break_Com[Player_id][EM_id]) {
        Com_Color_Shot = 1024;
        return;
    }

    Com_Color_Shot = 16;
}

void Setup_PL_Color(s16 PL_id, u16 sw) {
    s8 id_0;
    s8 id_1;
    u16 sw_new;

    sw_new = 0;

    if (plw[PL_id ^ 1].wu.operator == 0) {
        id_0 = -1;
        id_1 = 1;
    } else {
        id_0 = My_char[PL_id];
        id_1 = My_char[PL_id ^ 1];
    }

    if (Sel_PL_Complete[PL_id ^ 1] == 0) {
        id_0 = 127;
    }

    if (plw[PL_id].wu.operator != 0 && My_char[PL_id] == 0) {
        sw_new = 0;
    } else {
        if (Debug_w[53]) {
            if (PL_id == 0) {
                sw_new = p1sw_0;
            } else {
                sw_new = p2sw_0;
            }
        }

        if (save_w[Present_Mode].PL_Color[PL_id][My_char[PL_id]]) {
            if (PL_id == 0) {
                sw_new = p1sw_0;
            } else {
                sw_new = p2sw_0;
            }
        }
    }

    if (My_char[PL_id] == 0) {
        switch (sw) {
        case 16:
        case 32:
        case 64:
            if (Player_Color[PL_id ^ 1] == 0 && id_0 == id_1) {
                Player_Color[PL_id] = 1;
            } else {
                Player_Color[PL_id] = 0;
            }

            break;

        default:
            if (Player_Color[PL_id ^ 1] == 1 && id_0 == id_1) {
                Player_Color[PL_id] = 0;
            } else {
                Player_Color[PL_id] = 1;
            }

            break;
        }

        return;
    }

    if (sw_new & 0x4000) {
        switch (sw) {
        case 16:
            if (Player_Color[PL_id ^ 1] == 7 && id_0 == id_1) {
                Player_Color[PL_id] = 10;
                break;
            }

            Player_Color[PL_id] = 7;
            break;

        case 32:
            if (Player_Color[PL_id ^ 1] == 8 && id_0 == id_1) {
                Player_Color[PL_id] = 11;
                break;
            }

            Player_Color[PL_id] = 8;
            break;

        case 64:
            if (Player_Color[PL_id ^ 1] == 9 && id_0 == id_1) {
                Player_Color[PL_id] = 12;
                break;
            }

            Player_Color[PL_id] = 9;
            break;

        case 256:
            if (Player_Color[PL_id ^ 1] == 10 && id_0 == id_1) {
                Player_Color[PL_id] = 7;
                break;
            }

            Player_Color[PL_id] = 10;
            break;

        case 512:
            if (Player_Color[PL_id ^ 1] == 11 && id_0 == id_1) {
                Player_Color[PL_id] = 8;
                break;
            }

            Player_Color[PL_id] = 11;
            break;

        default:
            if (Player_Color[PL_id ^ 1] == 12 && id_0 == id_1) {
                Player_Color[PL_id] = 9;
                break;
            }

            Player_Color[PL_id] = 12;
            break;
        }
    } else {
        switch (sw) {
        case 592:
            if (Player_Color[PL_id ^ 1] == 6 && id_0 == id_1) {
                Player_Color[PL_id] = 0;
                break;
            }

            Player_Color[PL_id] = 6;
            break;

        case 16:
            if (Player_Color[PL_id ^ 1] == 0 && id_0 == id_1) {
                Player_Color[PL_id] = 3;
                break;
            }

            Player_Color[PL_id] = 0;
            break;

        case 32:
            if (Player_Color[PL_id ^ 1] == 1 && id_0 == id_1) {
                Player_Color[PL_id] = 4;
                break;
            }

            Player_Color[PL_id] = 1;
            break;

        case 64:
            if (Player_Color[PL_id ^ 1] == 2 && id_0 == id_1) {
                Player_Color[PL_id] = 5;
                break;
            }

            Player_Color[PL_id] = 2;
            break;

        case 256:
            if (Player_Color[PL_id ^ 1] == 3 && id_0 == id_1) {
                Player_Color[PL_id] = 0;
                break;
            }

            Player_Color[PL_id] = 3;
            break;

        case 512:
            if (Player_Color[PL_id ^ 1] == 4 && id_0 == id_1) {
                Player_Color[PL_id] = 1;
                break;
            }

            Player_Color[PL_id] = 4;
            break;

        default:
            if (Player_Color[PL_id ^ 1] == 5 && id_0 == id_1) {
                Player_Color[PL_id] = 2;
                break;
            }

            Player_Color[PL_id] = 5;
            break;
        }
    }
}

void Setup_Regular_OBJ(s16 PL_id) {
    s16 em_id;

    if (VS_Index[Player_id] < 8) {
        Regular_OBJ_Sub(PL_id, 2);
        Regular_OBJ_Sub(PL_id, 1);
        effect_A9_init(16, 5, 10, 0);
        effect_42_init(9);
        effect_42_init(10);
        Order[9] = 0;
        Order[10] = 0;
        Order_Timer[9] = 1;
        Order_Timer[10] = 1;
        return;
    }

    effect_A9_init(33, EM_List[PL_id][1], 5, 0);
    effect_A9_init(12, EM_List[PL_id][1], 21, 0);
    effect_A9_init(57, 0, 22, 0);
    em_id = EM_List[PL_id][1];

    if (chkNameAkuma(em_id, 1)) {
        em_id = 23;
    }

    effect_A9_init(34, em_id, 20, 0);
}

void Regular_OBJ_Sub(s16 PL_id, s16 Dir) {
    s16 ix = Dir - 1;
    s16 x;

    effect_A9_init(33, EM_List[PL_id][ix], ix + 4, 0);
    x = chkNameAkuma(EM_List[PL_id][ix], 9);
    effect_A9_init(34, x + EM_List[PL_id][ix], ix + 6, 0);
    effect_A9_init(12, EM_List[PL_id][ix], ix + 8, 0);
    effect_E0_init(Dir, 0, 0);
    effect_E0_init(Dir, 1, 0);
}

void Setup_History_OBJ() {
    s16 q_index = Break_Com[Player_id][17];
    s16 xx;
    s16 ix;
    s16 grade;

    effect_A9_init(79, 12, 11, 0);
    Offset_BG_X[3] = 88;
    effect_A9_init(79, 13, 12, 0);
    Offset_BG_X[3] += 80;

    for (xx = 0; xx < VS_Index[Player_id]; xx++) {
        effect_A9_init(79, 13, 12, 0);
        effect_A9_init(79, xx, 13, 0);
        effect_A9_init(79, 10, 14, 0);
        ix = chkNameAkuma(EM_History[Player_id][xx], 6);
        effect_A9_init(81, ix + EM_History[Player_id][xx], 15, 0);
        effect_A9_init(12, EM_History[Player_id][xx], 16, 0);
        grade = judge_final[Player_id][0].vs_cpu_grade[xx];

        if (grade == -1) {
            grade = 0;
        }

        effect_A9_init(80, grade, 17, 0);
        Offset_BG_X[3] += 88;

        if (q_index == 0 || (q_index - 1) != xx) {
            continue;
        }

        effect_A9_init(79, 13, 12, 0);
        effect_A9_init(81, 17, 15, 0);
        effect_A9_init(12, 17, 16, 0);
        grade = judge_final[Player_id]->vs_cpu_grade[15];

        if (grade == -1) {
            grade = 0;
        }

        effect_A9_init(80, grade, 17, 0);
        Offset_BG_X[3] += 88;
    }

    Offset_BG_X[3] -= 40;
}

void Setup_VS_OBJ(s16 Option) {
    effect_38_init(0, 11, My_char[0], 1, 0);
    Order[11] = 3;
    Order_Timer[11] = 1;
    effect_38_init(1, 12, My_char[1], 1, 0);
    Order[12] = 3;
    Order_Timer[12] = 1;
    effect_K6_init(0, 35, 35, 0);
    Order[35] = 3;
    Order_Timer[35] = 1;
    effect_K6_init(1, 36, 35, 0);
    Order[36] = 3;
    Order_Timer[36] = 1;
    effect_39_init(0, 17, My_char[0], 0, 0);
    Order[17] = 3;
    Order_Timer[17] = 1;
    effect_39_init(1, 18, My_char[1], 0, 0);
    Order[18] = 3;
    Order_Timer[18] = 1;
    effect_K6_init(0, 29, 29, 0);
    Order[29] = 3;
    Order_Timer[29] = 1;
    effect_K6_init(1, 30, 29, 0);
    Order[30] = 3;
    Order_Timer[30] = 1;

    if (My_char[0] != 20) {
        effect_75_init(42, 3, 0);
    }

    Order[42] = 3;
    Order_Timer[42] = 1;
    Order_Dir[42] = 5;

    if (Option == 0) {
        effect_43_init(1, 0);
    }
}

/* Rewritten to match retail (tools/permute.py): Push_LDREQ_Queue_BG parameter 1: s16 -> s32. */
s8 Check_Bonus_Stage() {
    Setup_ID();
    Bonus_Type = Check_Bonus_Type();

    if (Bonus_Type == 0) {
        return 0;
    }

    bg_w.stage = Bonus_Type;
    bg_w.area = 0;

    if (Bonus_Type == 21) {
        My_char[COM_id] = 0xC;
    } else {
        My_char[COM_id] = My_char[Player_id];
    }

    Setup_Com_Color();
    Setup_PL_Color(COM_id, Com_Color_Shot);
    Push_LDREQ_Queue_Player(COM_id, My_char[COM_id]);
    Push_LDREQ_Queue_BG(Bonus_Type + 0);
    return Completion_Bonus[Player_id][Bonus_Type - 20] = 1;
}

s8 Check_Bonus_Type() {
    if (Usage == 7 && Debug_w[0x2E] != 0) {
        if (Debug_w[0x2E] == 1) {
            Completion_Bonus[Player_id][0] = 0;
            return 20;
        }

        if (Debug_w[0x2E] == 2) {
            Completion_Bonus[Player_id][1] = 0;
            return 21;
        }

        return 0;
    }

    if (save_w[Present_Mode].extra_option.contents[0][5] == 0) {
        return 0;
    }

    if (VS_Index[Player_id] >= 6) {
        if (Completion_Bonus[Player_id][1] & 0x80) {
            return 0;
        }

        return 21;
    }

    if (VS_Index[Player_id] >= 3) {
        if (Completion_Bonus[Player_id][0] & 0x80) {
            return 0;
        }

        return 20;
    }

    return 0;
}

void Setup_Next_Stage(s16 dir_step) {
    s16 ix;

    for (ix = 0; ix < 4; ix++) {
        effect_A9_init(dir_step, ix, ix + 23, 0);
    }
}

void Check_Auto_Cut() {
    if (!Auto_Cut_Sub()) {
        return;
    }

    if ((Cut_Scroll -= 1) < 0) {
        Cut_Scroll = 0;
    }
}

s32 Auto_Cut_Sub() {
    if (plw[0].wu.operator && ~p1sw_1 & p1sw_0 & 0xFF0) {
        return 1;
    }

    if (plw[1].wu.operator && ~p2sw_1 & p2sw_0 & 0xFF0) {
        return 1;
    }

    return 0;
}
