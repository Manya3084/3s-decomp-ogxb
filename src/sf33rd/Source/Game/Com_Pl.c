/* Com_Pl.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Check_Hamari 0x25B86 size 0x7E.
 * Check_No12_Shell_Guard 0x25C04 size 0x25.
 * Check_Guard_Type 0x25C29 size 0x64.
 * Ck_Exit_Guard_Sub 0x25C8D size 0x2A.
 * Damage_1st 0x25CB7 size 0x284.
 * Check_Flip_GO 0x25F3B size 0x9B.
 * SetShellFlipLever 0x25FD6 size 0x68. Read against the x86: 0x2C5 is the
 * att.dipsw byte the C reads. Matches.
 * Check_Shell_Flip 0x2603E size 0x106.
 * Check_Flip 0x26144 size 0x9D.
 * Check_Flip_Attack 0x261E1 size 0x96.
 * Decide_Exit_Catch 0x26277 size 0x77. Read against the x86: 0x208 is the
 * save_w field the C reads. Matches.
 * Com_Rapid_Sub 0x262EE size 0x57.
 * Command_Attack_SP 0x26345 size 0x16C.
 * Next_Be_Free 0x264B1 size 0x46.
 * Clear_Com_Flag 0x264F7 size 0xC1.
 * Check_At_Count 0x265B8 size 0xD1.
 * Shift_Resume_Lv 0x26689 size 0x44.
 * Store_LR_Sub 0x266CD size 0xA0.
 * Setup_Bullet_Counter 0x2676D size 0x2D.
 * Pattern_Insurance 0x2679A size 0x32.
 * Com_Initialize 0x267CC size 0x1E2.
 * Check_Counter_Attack 0x269AE size 0x60.
 * Ck_Exit_Guard 0x26A0E size 0x10A.
 * Exit_Damage_Sub 0x26B18 size 0x20.
 * Check_Damage 0x26B38 size 0x82.
 * Float_2nd 0x26BBA size 0x42.
 * Float_3rd 0x26BFC size 0x90.
 * Float_4th 0x26C8C size 0x91.
 * Flip_Zero 0x26D1D size 0x7F.
 * Flip_1st 0x26D9C size 0x13.
 * Flip_2nd 0x26DAF size 0x30.
 * Flip_3rd 0x26DDF size 0x102.
 * Flip_4th 0x26EE1 size 0x65.
 * Com_Caught 0x26F46 size 0x124.
 * Check_Caught 0x2706A size 0x45.
 * Com_Catch 0x270AF size 0xD1.
 * Be_Catch 0x27180 size 0x3C.
 * Com_Wait_Lie 0x271BC size 0x21.
 * Next_Be_Float 0x271DD size 0x6D.
 * Check_Store_Lv 0x2724A size 0x7F.
 * Com_Free 0x272C9 size 0xB1.
 * Com_Before_Follow 0x2737A size 0xDE.
 * Com_Before_Passive 0x27458 size 0xE0.
 * Com_Guard 0x27538 size 0xB9.
 * Com_Guard_VS_Shell 0x275F1 size 0xA9.
 * Com_Active 0x2769A size 0xD1.
 * Com_Follow 0x2776B size 0x88.
 * Com_Passive 0x277F3 size 0xD3.
 * Com_VS_Shell 0x278C6 size 0xAC.
 * Damage_2nd 0x27972 size 0x65.
 * Damage_5th 0x279D7 size 0xA0.
 * Damage_6th 0x27A77 size 0x29F.
 * Damage_7th 0x27D16 size 0x97.
 * Damage_8th 0x27DAD size 0xE3.
 * Com_Float 0x27E90 size 0x51.
 * Com_Flip 0x27EE1 size 0x58.
 * Com_Damage 0x27F39 size 0x74.
 * Main_Program 0x27FAD size 0xF0.
 * CPU_Sub 0x2809D size 0x9A.
 * cpu_algorithm 0x28137 size 0x72.
 * Damage_3rd is folded into 0x4384A with 60 other bodies. Unnamed.
 * Damage_4th is folded into 0x4384A with 60 other bodies. Unnamed.
 * Data: Correct_Lv_Data is 0x249610, 0x20 bytes compared.
 * Data: Rapid_Lever_Data: not located in the XBE, PS2 initializer kept.
 * Data: Pattern_Insurance_Data is 0x249638, 0x50 bytes compared.
 * TARGET_PS2 block in Damage_1st: kept the PS2 side of a TARGET_PS2 block.
 * TARGET_PS2 block in Damage_6th: kept the PS2 side of a TARGET_PS2 block.
 * Unnamed data used (not checked): Com_Rapid_Sub: 0x249630.
 * Globals: Area_Unit_Data 0x2414D0, Shell_Area_Unit_Data 0x241548,
 * Exit_Throw_Data 0x247B20, Shell_Renzoku_Flip_Data 0x247D28, Flip_Attack_Data
 * 0x247DC8, Guard_Data 0x247E68, Rapid_Exit_Data 0x248CF0, Faint_Rapid_Data
 * 0x248D30, Rapid_Hit_Data 0x248D70, Arts_Super_Name_Data 0x249170,
 * Float_Attack_Data 0x2491E8, PL_Damage_Data 0x249228, PL_Blow_Off_Data
 * 0x249290, PL_Body_Width_Data 0x2492F4, Pattern_Insurance_Data 0x249638,
 * Get_Up_Data 0x25CD10, Get_Up_Action_Tech_Data 0x25D710,
 * Get_Up_Action_Check_Data 0x25DC10, Receive_Data 0x25DF30, player_cmd
 * 0x332B88, Pattern_Index 0x7A80C8, Flip_Flag 0x7A80D0, Receive_Flag 0x7A80D4,
 * Disposal_Again 0x7A810C, Standing_Master_Timer 0x7A8122, EM_Rank 0x7A8124,
 * Passive_Flag 0x7A8138, Before_Jump 0x7A813C, Passive_Mode 0x7A813F,
 * Last_Eftype 0x7A814C, Play_Mode 0x7A8178, Attack_Counter 0x7A817C,
 * Tech_Address 0x7A8190, Present_Mode 0x7A819C, Bullet_No 0x7A81AC,
 * Shell_Separate_Area 0x7A81E0, Lie_Flag 0x7A81F0, CC_Value 0x7A81FC,
 * Pierce_Menu 0x7A820C, CPU_Rec 0x7A8210, Shell_Address 0x7A8230, Before_Look
 * 0x7A8262, Lever_Squat 0x7A8274, Type_of_Attack 0x7A827C, Allow_a_battle_f
 * 0x7A82B8, VS_Tech 0x7A82C8, CP_No 0x7A8308, Flip_Counter 0x7A831C,
 * Attack_Flag 0x7A832C, Last_Attack_Counter 0x7A8338, Weak_PL 0x7A8414,
 * Demo_Flag 0x7A842D, Attack_Count_Buff 0x7A8430, Guard_Type 0x7A8478,
 * Guard_Flag 0x7A8520, Resume_Lever 0x7A8540, CP_Index 0x7A85B0, Lever_Buff
 * 0x7A86B8, Rapid_Index 0x7A86BC, Replay_Status 0x7A86C8, Timer_01 0x7A86CC,
 * Bullet_Counter 0x7A86DC, Reset_Timer 0x7A86DE, Jump_Pass_Timer 0x7A86E8,
 * Lever_LR 0x7A874C, Standing_Timer 0x7A8752, Attack_Count_No0 0x7A875E,
 * Turn_Over_Timer 0x7A8770, Lever_Store 0x7A87D0, Com_Width_Data 0x7A87DC,
 * Lever_Pool 0x7A87F4, Guard_Counter 0x7A8808, Counter_Attack 0x7A881C,
 * Timer_00 0x7A8820, Shell_Ignore_Timer 0x7A882C, Squat_Master_Timer 0x7A882E,
 * Separate_Area 0x7A88A0, Continue_Menu 0x7A88FA, CPU_Time_Lag 0x7A88FC,
 * Area_Number 0x7A8914, Limited_Flag 0x7A8934, Tech_Index 0x7A89AC,
 * Break_Into_CPU 0x7A8A25, Last_Pattern_Index 0x7A8A28, Attack_Count_Index
 * 0x7A8A2C, Turn_Over 0x7A8A2E, save_w 0x7BD3E0, p1sw_0 0x7C557C, p2sw_0
 * 0x7C5B90, plw 0xC7CEA0, pcon_dp_flag 0xC7D8D0.
 */

#include "structs.h"

#define NULL 0

typedef const s16* const_s16_arr;

static u16 CPU_Sub(PLW* wk);
extern u8 Play_Mode;
extern u8 Replay_Status[2];
extern u16 p2sw_0;
extern u16 p1sw_0;
extern u8 CPU_Time_Lag[2];
extern u8 CPU_Rec[2];
void Check_Replay_Status(s16 PL_id, u8 Status);
extern u8 Allow_a_battle_f;
extern u8 pcon_dp_flag;
extern u16 Lever_Buff[2];
extern s8 Lie_Flag[2];
extern s16 Last_Pattern_Index[2];
extern u16 Pattern_Index[2];
void Main_Program(PLW* wk);
u16 check_illegal_lever_data(u16 data);
void Check_Store_Lv(PLW* wk);
void Shift_Resume_Lv(PLW* wk);
void Com_Initialize(PLW* wk);
void Com_Free(PLW* wk);
void Com_Active(PLW* wk);
void Com_Before_Follow(PLW* wk);
void Com_Follow(PLW* wk);
void Com_Before_Passive(PLW* wk);
void Com_Passive(PLW* wk);
void Com_Guard(PLW* wk);
void Com_VS_Shell(PLW* wk);
void Com_Guard_VS_Shell(PLW* wk);
void Com_Damage(PLW* wk);
void Com_Float(PLW* wk);
void Com_Flip(PLW* wk);
void Com_Caught(PLW* wk);
void Com_Wait_Lie(PLW* wk);
void Com_Catch(PLW* wk);
void Ck_Distance(PLW* wk);
extern s16 Area_Number[2];
s32 Ck_Area(PLW* wk);
extern s8 Attack_Flag[2];
extern PLW plw[2];
void Check_At_Count(PLW* wk);
extern s8 Disposal_Again[2];
extern u8 CP_No[2][4];
extern u16 Lever_Squat[2];
extern u16 Lever_Store[2][3];
extern s16 Attack_Counter[2];
extern u8 Bullet_No[2];
extern s16 Last_Attack_Counter[2];
extern s16 Guard_Counter[2];
extern s8 Turn_Over_Timer[2];
extern u8 Attack_Count_Index[2];
extern u8 Flip_Counter[2];
extern u16 Lever_LR[2];
extern const s16 Area_Unit_Data[20][3];
extern s16 Separate_Area[2][3];
extern const s16 Shell_Area_Unit_Data[20][3];
extern s16 Shell_Separate_Area[2][3];
extern s16 Com_Width_Data[2];
extern const s8 PL_Body_Width_Data[20];
void Clear_Com_Flag(PLW* wk);
extern s8 Standing_Master_Timer[2];
s32 Setup_Next_Stand_Timer(PLW* wk);
extern s8 Squat_Master_Timer[2];
s32 Setup_Next_Squat_Timer(PLW* wk);
void Setup_Bullet_Counter(PLW* wk);
extern u16 Resume_Lever[2][20];
extern u8 Attack_Count_Buff[2][4];
static s32 Check_Damage(PLW* wk);
static s32 Check_Caught(PLW* wk);
extern s8 Before_Look[2];
extern s8 Standing_Timer[2];
extern u8 CP_Index[2][8];
void Select_Active(PLW* wk);
s32 Check_Guard(PLW* wk);
s32 Check_Flip(PLW* wk);
extern s16 Timer_00[2];
void Decide_Follow_Menu(PLW* wk);
extern s8 Limited_Flag[2];
extern s8 Counter_Attack[2];
extern const s8 PL_Blow_Off_Data[27];
void Next_Be_Float(PLW* wk);
extern const s16 Hit_Range_Data[];
static s32 Ck_Exit_Guard(PLW* wk, WORK* em);
void Check_Guard_Type(PLW* wk, WORK* em);
extern s8 Passive_Flag[2];
extern s8 Passive_Mode;
s32 Ck_Passive_Term(PLW* wk);
s32 Select_Passive(PLW* wk);
static s32 Check_Counter_Attack(PLW* wk);
void Next_Be_Free(PLW* wk);
extern u8 Type_of_Attack[2];
extern s16 VS_Tech[2];
static s16 Check_Hamari(PLW* wk);
s32 random_32_com();
extern u32* Shell_Address[2];
void Exit_Damage_Sub(PLW* wk);
static s32 Check_No12_Shell_Guard(PLW* wk, WORK_Other* tmw);
s32 Setup_Guard_Lever(PLW* wk, u16 Lever);
extern u16 Guard_Type[2];
static s32 Ck_Exit_Guard_Sub(PLW* wk, WORK* em);
s32 Setup_Lv10(s16 xx);
extern s8 Break_Into_CPU;
extern s8 Demo_Flag;
extern u8 Weak_PL;
extern u8 CC_Value[2];
s32 emLevelRemake(s32 now, s32 max, s32 exd);
extern s8 EM_Rank;
extern const s8 Guard_Data[20][11][16];
s32 random_16_com();
void Computer00(PLW* wk);
void Computer01(PLW* wk);
void Computer02(PLW* wk);
void Computer03(PLW* wk);
void Computer04(PLW* wk);
void Computer05(PLW* wk);
void Computer06(PLW* wk);
void Computer07(PLW* wk);
void Computer08(PLW* wk);
void Computer09(PLW* wk);
void Computer10(PLW* wk);
void Computer11(PLW* wk);
void Computer12(PLW* wk);
void Computer13(PLW* wk);
void Computer14(PLW* wk);
void Computer15(PLW* wk);
void Computer16(PLW* wk);
void Computer17(PLW* wk);
void Computer18(PLW* wk);
void Computer19(PLW* wk);
void Pattern_Insurance(PLW* wk, s16 Kind_Of_Insurance, s16 Forced_Number);
void Follow02(PLW* wk);
void Passive00(PLW* wk);
void Passive01(PLW* wk);
void Passive02(PLW* wk);
void Passive03(PLW* wk);
void Passive04(PLW* wk);
void Passive05(PLW* wk);
void Passive06(PLW* wk);
void Passive07(PLW* wk);
void Passive08(PLW* wk);
void Passive09(PLW* wk);
void Passive10(PLW* wk);
void Passive11(PLW* wk);
void Passive12(PLW* wk);
void Passive13(PLW* wk);
void Passive14(PLW* wk);
void Passive15(PLW* wk);
void Passive16(PLW* wk);
void Passive17(PLW* wk);
void Passive18(PLW* wk);
void Passive19(PLW* wk);
void Shell00(PLW* wk);
void Shell01(PLW* wk);
void Shell11(PLW* wk);
void Shell03(PLW* wk);
void Shell04(PLW* wk);
void Shell05(PLW* wk);
void Shell07(PLW* wk);
void Shell12(PLW* wk);
void Shell13(PLW* wk);
void Shell14(PLW* wk);
void Damage_1st(PLW* wk);
void Damage_2nd(PLW* wk);
void Damage_3rd(PLW* );
void Damage_4th(PLW* );
void Damage_5th(PLW* wk);
void Damage_6th(PLW* wk);
void Damage_7th(PLW* wk);
void Damage_8th(PLW* wk);
s32 Setup_Lv08(s16 xx);
s32 Setup_EM_Rank_Index(PLW* wk);
extern const u8 Receive_Data[20][8];
extern s8 Receive_Flag[2];
s32 Setup_Lv04(s16 xx);
extern const u8 Get_Up_Data[20][4][32];
extern const u8 Get_Up_Action_Check_Data[20][8][5];
s32 Command_Attack_SP(PLW* wk, s8 Pl_Number, s16 Tech_Number, s16 Power_Level);
extern const u16 Get_Up_Action_Tech_Data[20][4][8];
extern const s16 Arts_Super_Name_Data[20][3];
extern s16 Timer_01[2];
extern const u8 Faint_Rapid_Data[8][8];
s32 Com_Rapid_Sub(PLW* wk, s16 Shot, u8* dir_step);
s32 Check_Passive(PLW* wk);
extern s8 Guard_Flag[2];
void Float_2nd(PLW* wk);
void Float_3rd(PLW* wk);
void Float_4th(PLW* wk);
extern u16 Lever_Pool[2];
void Flip_Zero(PLW* wk);
void Flip_1st(PLW* wk);
void Flip_2nd(PLW* wk);
void Flip_3rd(PLW* wk);
void Flip_4th(PLW* wk);
s32 Check_Flip_GO(PLW* wk, s16 xx);
void Next_Be_Guard(PLW* wk, WORK* em, s16 Type_Of_Guard);
extern const s8 PL_Damage_Data[];
static s32 Check_Flip_Attack(PLW* wk);
static s32 Check_Shell_Flip(PLW* wk);
void dash_flag_clear(s16 pl_id);
s32 SetShellFlipLever(PLW* wk);
s32 Check_Shell_Another_in_Flip(PLW* wk);
s32 Flip_Term_Correct(PLW* wk);
extern const u8 Shell_Renzoku_Flip_Data[20][8];
s32 emGetMaxBlocking();
extern s8 Flip_Flag[2];
extern const s8 Flip_Attack_Data[20][8];
extern const u8 Rapid_Exit_Data[8][8];
static s16 Decide_Exit_Catch(PLW* wk);
s32 Setup_Lv18(s16 xx);
extern struct _SAVE_W save_w[6];
extern u8 Present_Mode;
extern const u8 Exit_Throw_Data[20][18];
extern const u8 Rapid_Hit_Data[4][8];
s32 Check_Blow_Off(PLW* wk, WORK* em, s16 VS_Technique);
extern const_s16_arr Tech_Address[2];
extern const_s16_arr* player_cmd[];
extern s16 Tech_Index[2];
void Check_Rapid(PLW* wk, u16 Tech_Number);
extern s16 Rapid_Index[2];
s32 Command_Type_00(PLW* wk, s16 Power_Level, u16 Tech_Number, s16 Ex_Shot);
s32 Command_Type_01(PLW* wk, s16 Power_Level, s16 Ex_Shot);
void Rapid_Sub(PLW* wk);
extern const s8 Float_Attack_Data[4][16];
extern s8 Before_Jump[2];
extern s8 Shell_Ignore_Timer[2];
extern s8 Pierce_Menu[2];
extern s8 Continue_Menu[2];
extern s8 Attack_Count_No0[2];
extern s8 Turn_Over[2];
extern s8 Jump_Pass_Timer[2][4];
extern s16 Last_Eftype[2];
extern u8 Reset_Timer[2];
void Store_LR_Sub(PLW* wk);
extern u8 Bullet_Counter[2];

const u16 Correct_Lv_Data[16] = { 0, 1, 2, 2, 4, 5, 6, 5, 8, 9, 10, 9, 8, 5, 10, 0 };

const u8 Rapid_Lever_Data[2] = { 8, 4 };

const u8 Pattern_Insurance_Data[20][4] = {
    { 67, 157, 10, 3 }, { 69, 175, 9, 3 },  { 74, 132, 10, 3 }, { 71, 135, 10, 3 },  { 67, 141, 11, 3 },
    { 66, 101, 10, 3 }, { 63, 146, 10, 3 }, { 75, 213, 11, 3 }, { 70, 213, 10, 3 },  { 100, 131, 10, 3 },
    { 69, 137, 10, 3 }, { 89, 254, 13, 3 }, { 85, 230, 10, 3 }, { 80, 167, 11, 3 },  { 150, 252, 12, 3 },
    { 68, 163, 13, 3 }, { 69, 166, 13, 3 }, { 82, 181, 13, 3 }, { 108, 203, 13, 3 }, { 78, 175, 13, 3 }
};

/* The Xbox has no Debug_w[0x21] test. */
u16 cpu_algorithm(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    u16 sw = CPU_Sub(wk);

    if (Play_Mode == 1 && Replay_Status[wk->wu.id] != 99) {
        if (wk->wu.id) {
            p2sw_0 = sw;
        } else {
            p1sw_0 = sw;
        }

        if (CPU_Time_Lag[wk->wu.id]) {
            CPU_Rec[wk->wu.id] = 1;
            return sw;
        }

        CPU_Rec[wk->wu.id] = 1;

        Check_Replay_Status(wk->wu.id, 1);
    }

    return sw;
}

/* The Xbox does not call Disp_Lever and does not call Disp_Mode. */
static u16 CPU_Sub(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Allow_a_battle_f == 0 || pcon_dp_flag == 1) {
        return 0;
    }

    Lever_Buff[wk->wu.id] = 0;

    if (em->pat_status == 0x26) {
        Lie_Flag[wk->wu.id] = 1;
    } else {
        Lie_Flag[wk->wu.id] = 0;
    }

    Last_Pattern_Index[wk->wu.id] = Pattern_Index[wk->wu.id];
    Main_Program(wk);
    Lever_Buff[wk->wu.id] = check_illegal_lever_data(Lever_Buff[wk->wu.id]);
    Check_Store_Lv(wk);
    Shift_Resume_Lv(wk);
    return Lever_Buff[wk->wu.id];
}

void Main_Program(PLW* wk) {
    void (*Com_Jmp_Tbl[16])(PLW*) = { Com_Initialize, Com_Free,           Com_Active,   Com_Before_Follow,
                                      Com_Follow,     Com_Before_Passive, Com_Passive,  Com_Guard,
                                      Com_VS_Shell,   Com_Guard_VS_Shell, Com_Damage,   Com_Float,
                                      Com_Flip,       Com_Caught,         Com_Wait_Lie, Com_Catch };

    Ck_Distance(wk);
    Area_Number[wk->wu.id] = Ck_Area(wk);
    Attack_Flag[wk->wu.id] = plw[wk->wu.id ^ 1].caution_flag;
    Check_At_Count(wk);
    Disposal_Again[wk->wu.id] = 0;
    Com_Jmp_Tbl[CP_No[wk->wu.id][0]](wk);

    if (Disposal_Again[wk->wu.id]) {
        Com_Jmp_Tbl[CP_No[wk->wu.id][0]](wk);
    }
}

/* Xbox: no time_check reset (the PS2 timing display). Bullet_No is
 * 0x7A81AC, Turn_Over_Timer is 0x7A8770, Area_Unit_Data is 0x2414D0,
 * Shell_Area_Unit_Data is 0x241548, and PL_Body_Width_Data is 0x2492F4. */
void Com_Initialize(PLW* wk) {
    const s16* xx;
    s16 i;

    CP_No[wk->wu.id][0] = 1;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Lever_Squat[wk->wu.id] = 0;
    Lever_Store[wk->wu.id][0] = 0;
    Lever_Store[wk->wu.id][1] = 0;
    Lever_Store[wk->wu.id][2] = 0;
    Attack_Counter[wk->wu.id] = 0;
    Bullet_No[wk->wu.id] = 0;
    Last_Attack_Counter[wk->wu.id] = -1;
    Guard_Counter[wk->wu.id] = -1;
    Turn_Over_Timer[wk->wu.id] = 1;
    Attack_Count_Index[wk->wu.id] = 0;
    Flip_Counter[wk->wu.id] = 0;
    Lever_LR[0] = 0;
    Lever_LR[1] = 0;
    xx = Area_Unit_Data[wk->player_number];
    Separate_Area[wk->wu.id][0] = xx[0];
    Separate_Area[wk->wu.id][1] = xx[1];
    Separate_Area[wk->wu.id][2] = xx[2];
    xx = Shell_Area_Unit_Data[wk->player_number];
    Shell_Separate_Area[wk->wu.id][0] = xx[0];
    Shell_Separate_Area[wk->wu.id][1] = xx[1];
    Shell_Separate_Area[wk->wu.id][2] = xx[2];
    Com_Width_Data[wk->wu.id] = PL_Body_Width_Data[wk->player_number];
    Clear_Com_Flag(wk);
    Standing_Master_Timer[wk->wu.id] = Setup_Next_Stand_Timer(wk);
    Squat_Master_Timer[wk->wu.id] = Setup_Next_Squat_Timer(wk);
    Squat_Master_Timer[wk->wu.id] = 0;
    Setup_Bullet_Counter(wk);

    for (i = 0; i < 20; i++) {
        Resume_Lever[wk->wu.id][i] = 0;
    }

    for (i = 0; i < 3; i++) {
        Attack_Count_Buff[wk->wu.id][i] = -1;
    }
}

void Com_Free(PLW* wk) {
    s16 xx;

    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

    if (Check_Damage(wk)) {
        return;
    }

    if (Check_Caught(wk)) {
        return;
    }

    CP_No[wk->wu.id][0] = 2;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;

    if (Before_Look[wk->wu.id]) {
        xx = Standing_Timer[wk->wu.id];
    } else {
        xx = 0;
    }

    Clear_Com_Flag(wk);
    Standing_Timer[wk->wu.id] = xx;

    for (xx = 0; xx <= 7; xx++) {
        CP_Index[wk->wu.id][xx] = 0;
    }

    Select_Active(wk);
}

void Com_Before_Follow(PLW* wk) {
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

    if (Check_Damage(wk)) {
        return;
    }

    if (Check_Caught(wk)) {
        return;
    }

    if (Check_Guard(wk)) {
        return;
    }

    if (Check_Flip(wk)) {
        return;
    }

    if (--Timer_00[wk->wu.id] != 0) {
        return;
    }

    Decide_Follow_Menu(wk);
    CP_No[wk->wu.id][0] = 4;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    CP_Index[wk->wu.id][0] = 0;
    CP_Index[wk->wu.id][1] = 0;
    CP_Index[wk->wu.id][2] = 0;
    CP_Index[wk->wu.id][3] = 0;
    Clear_Com_Flag(wk);
}

void Com_Before_Passive(PLW* wk) {
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

    if (Check_Damage(wk)) {
        return;
    }

    if (Check_Caught(wk)) {
        return;
    }

    if (Check_Flip(wk)) {
        return;
    }

    if (!Limited_Flag[wk->wu.id] && !Counter_Attack[wk->wu.id]) {
        if (Check_Guard(wk)) {
            return;
        }
    }

    if (--Timer_00[wk->wu.id] != 0) {
        return;
    }

    CP_No[wk->wu.id][0] = 6;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    CP_Index[wk->wu.id][0] = 0;
    CP_Index[wk->wu.id][1] = 0;
    CP_Index[wk->wu.id][2] = 0;
    CP_Index[wk->wu.id][3] = 0;
}

void Com_Guard(PLW* wk) {
    WORK* em;
    u16 xx;

    if (Check_Damage(wk)) {
        return;
    }

    if (Check_Caught(wk)) {
        return;
    }

    if (Check_Flip(wk)) {
        return;
    }

    if (wk->wu.routine_no[1] == 1 && XB_PAST(PL_Blow_Off_Data, 27, 0x249290, wk->wu.routine_no[2]) == 2) {
        Next_Be_Float(wk);
        return;
    }

    em = (WORK*)wk->wu.target_adrs;
    xx = Hit_Range_Data[em->hit_range];
    xx += Com_Width_Data[wk->wu.id];

    if (Ck_Exit_Guard(wk, em)) {
        Check_Guard_Type(wk, em);
        return;
    }

    Passive_Flag[wk->wu.id] = 0;
    Passive_Mode = 4;

    if (Ck_Passive_Term(wk)) {
        Select_Passive(wk);
        Counter_Attack[wk->wu.id] |= 2;
        return;
    }

    if (!Check_Counter_Attack(wk)) {
        Next_Be_Free(wk);
        return;
    }

    if (Select_Passive(wk) == -1) {
        Next_Be_Free(wk);
    }
}

static s32 Check_Counter_Attack(PLW* wk) {
    s16 xx;
    WORK* em;

    if (Area_Number[wk->wu.id] >= 3) {
        return 0;
    }

    em = (WORK*)wk->wu.target_adrs;
    xx = Type_of_Attack[wk->wu.id] & 0xF8;

    if (xx == 8) {
        VS_Tech[wk->wu.id] = 28;
        return 1;
    }

    if (xx == 24) {
        VS_Tech[wk->wu.id] = 14;
        return 1;
    }

    if (xx == 32) {
        VS_Tech[wk->wu.id] = 14;
        return 1;
    }

    if (xx == 48) {
        VS_Tech[wk->wu.id] = 14;
        return 1;
    }

    return Check_Hamari(wk);
}

/* Rewritten to match retail (tools/permute.py): tech != Attack_Count_Buff[wk->wu.id][xx] -> Attack_Count_Buff[wk->wu.id][xx] != tech. */
static s16 Check_Hamari(PLW* wk) {
    u8 tech;
    s16 Rnd;
    s16 limit;
    s16 xx;

    if (Area_Number[wk->wu.id] >= 2) {
        return 0;
    }

    tech = Attack_Count_Buff[wk->wu.id][0];
    Rnd = random_32_com() & 1;
    limit = Rnd + 3;

    if (((PLW*)wk->wu.target_adrs)->player_number == 4 && tech == 3) {
        limit--;
    } else if (tech != 0 && tech != 1) {
        return 0;
    }

    for (xx = 1; xx < limit; xx++) {
        if (Attack_Count_Buff[wk->wu.id][xx] != tech) {
            return 0;
        }
    }

    return VS_Tech[wk->wu.id] = 32;
}

void Com_Guard_VS_Shell(PLW* wk) {
    WORK_Other* tmw;
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Caught(wk)) {
        return;
    }

    if (Check_Flip(wk)) {
        return;
    }

    tmw = (WORK_Other*)Shell_Address[wk->wu.id];

    Check_Guard_Type(wk, &tmw->wu);

    if (Timer_00[wk->wu.id] == 0) {
        if (wk->player_number != 18) {
            if (wk->wu.routine_no[1] != 1) {
                Exit_Damage_Sub(wk);
            }
        } else if (Check_No12_Shell_Guard(wk, tmw) != 0) {
            Exit_Damage_Sub(wk);
        }

        if (tmw->wu.routine_no[0] == 2) {
            Exit_Damage_Sub(wk);
        }

        if (tmw->wu.id != 13) {
            Exit_Damage_Sub(wk);
        }

        Timer_00[wk->wu.id] = 1;
        return;
    }

    Timer_00[wk->wu.id]--;
}

static s32 Check_No12_Shell_Guard(PLW* wk, WORK_Other* tmw) {
    s16 pos_x;

    if (wk->wu.rl_flag) {
        pos_x = wk->wu.xyz[0].disp.pos - 48;

        if (tmw->wu.xyz[0].disp.pos < pos_x) {
            return 1;
        }
    } else {
        pos_x = wk->wu.xyz[0].disp.pos + 48;

        if (tmw->wu.xyz[0].disp.pos > pos_x) {
            return 1;
        }
    }

    return 0;
}

void Check_Guard_Type(PLW* wk, WORK* em) {
    Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 1);

    switch (Guard_Type[wk->wu.id]) {
    case 0:
        if (em->pat_status >= 0xE && em->pat_status <= 0x1E) {
            break;
        }

        if (em->att.guard & 16 || !(em->att.guard & 8)) {
            break;
        }

        Lever_Buff[wk->wu.id] |= 2;
        break;

    case 1:
        break;

    case 2:
        Lever_Buff[wk->wu.id] |= 2;
        break;
    }
}

static s32 Ck_Exit_Guard(PLW* wk, WORK* em) {
    s16 Lv;

    if (--Timer_00[wk->wu.id]) {
        return 1;
    }

    Timer_00[wk->wu.id] = 1;

    if (Ck_Exit_Guard_Sub(wk, em)) {
        if (Guard_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
            return 1;
        }

        Guard_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
        Lv = Setup_Lv10(0);

        if (Break_Into_CPU == 2) {
            Lv = 10;
        }

        if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
            Lv = 2;
        }

        Lv += CC_Value[0];
        Lv = emLevelRemake(Lv, 11, 1);

        if (EM_Rank != 0) {
            Guard_Type[wk->wu.id] = Guard_Data[17][Lv][random_16_com()];
        } else {
            Guard_Type[wk->wu.id] = Guard_Data[wk->player_number][Lv][random_16_com()];
        }

        return 1;
    }

    return 0;
}

/* Xbox: the PS2 tests reduce to these once Attack_Flag is known set (MSVC folded the rest) */
static s32 Ck_Exit_Guard_Sub(PLW* wk, WORK* em) {
    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }

    if (wk->wu.routine_no[1] != 1) {
        return em->routine_no[1] == 4;
    }

    return 1;
}

void Com_Active(PLW* wk) {
    void (*Char_Jmp_Tbl[20])(PLW*) = { Computer00, Computer01, Computer02, Computer03, Computer04,
                                       Computer05, Computer06, Computer07, Computer08, Computer09,
                                       Computer10, Computer11, Computer12, Computer13, Computer14,
                                       Computer15, Computer16, Computer17, Computer18, Computer19 };

    if (Check_Damage(wk)) {
        return;
    }

    if (Check_Caught(wk)) {
        return;
    }

    if (Check_Flip(wk)) {
        return;
    }

    Pattern_Insurance(wk, 0, 0);
    Char_Jmp_Tbl[wk->player_number](wk);
}

void Com_Follow(PLW* wk) {
    void (*Follow_Jmp_Tbl[20])(PLW*) = { Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02,
                                         Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02,
                                         Follow02, Follow02, Follow02, Follow02, Follow02, Follow02 };

    if (Check_Damage(wk)) {
        return;
    }

    if (Check_Caught(wk)) {
        return;
    }

    if (Check_Flip(wk)) {
        return;
    }

    Pattern_Insurance(wk, 3, 2);
    Follow_Jmp_Tbl[wk->player_number](wk);
}

void Com_Passive(PLW* wk) {
    void (*Passive_Jmp_Tbl[20])(PLW*) = { Passive00, Passive01, Passive02, Passive03, Passive04, Passive05, Passive06,
                                          Passive07, Passive08, Passive09, Passive10, Passive11, Passive12, Passive13,
                                          Passive14, Passive15, Passive16, Passive17, Passive18, Passive19 };

    if (Check_Damage(wk)) {
        return;
    }

    if (Check_Caught(wk)) {
        return;
    }

    if (Check_Flip(wk)) {
        return;
    }

    Pattern_Insurance(wk, 1, 1);
    Passive_Jmp_Tbl[wk->player_number](wk);
}

void Com_VS_Shell(PLW* wk) {
    void (*VS_Shell_Jmp_Tbl[20])(PLW*) = { Shell00, Shell01, Shell11, Shell03, Shell04, Shell05, Shell03,
                                           Shell07, Shell03, Shell03, Shell03, Shell11, Shell12, Shell13,
                                           Shell14, Shell11, Shell11, Shell11, Shell11, Shell11 };

    if (Check_Damage(wk)) {
        return;
    }

    if (Check_Caught(wk)) {
        return;
    }

    if (Check_Flip(wk)) {
        return;
    }

    Pattern_Insurance(wk, 2, 0);
    VS_Shell_Jmp_Tbl[wk->player_number](wk);
}

void Com_Damage(PLW* wk) {
    void (*Damage_Jmp_Tbl[10])(PLW*) = { Damage_1st, Damage_2nd, Damage_3rd, Damage_4th, Damage_5th,
                                         Damage_6th, Damage_7th, Damage_7th, Damage_7th, Damage_8th };

    if (Check_Caught(wk)) {
        return;
    }

    if (Check_Flip(wk)) {
        return;
    }

    Damage_Jmp_Tbl[CP_No[wk->wu.id][1]](wk);
}

void Damage_1st(PLW* wk) {
    u8 Lv;
    u8 Rnd;
    u8 xx;
    WORK* em;

    Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 1);
    Lever_Buff[wk->wu.id] |= 2;

    switch (CP_No[wk->wu.id][2]) {
    case 0:
        if (wk->py->flag) {
            CP_No[wk->wu.id][1] = 9;
            break;
        }

        if (XB_PAST(PL_Blow_Off_Data, 27, 0x249290, wk->wu.routine_no[2]) == 0) {
            CP_No[wk->wu.id][1] = 1;
            break;
        }

        CP_No[wk->wu.id][2]++;
        Lv = Setup_Lv08(0);

        if (Break_Into_CPU == 2) {
            Lv = 7;
        }

        if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
            Lv = 0;
        }

        Rnd = random_32_com();
        xx = Setup_EM_Rank_Index(wk);

        if (Receive_Data[xx][emLevelRemake(Lv, 8, 0)] > Rnd) {
            Receive_Flag[wk->wu.id] = 1;
            break;
        }

        break;

    case 1:
        if (wk->wu.routine_no[3] == 0) {
            CP_No[wk->wu.id][2] = 0;
            break;
        }

        Lv = Setup_Lv04(0);

        if (Break_Into_CPU == 2) {
            Lv = 3;
        }

        if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
            Lv = 0;
        }

        Rnd = random_32_com();
        CP_No[wk->wu.id][1] = Get_Up_Data[wk->player_number][emLevelRemake(Lv, 4, 0)][Rnd] + 1;
        CP_No[wk->wu.id][2] = 0;

        if (Get_Up_Action_Check_Data[wk->player_number][CP_No[wk->wu.id][1] - 1][Area_Number[wk->wu.id]] == -1) {
            CP_No[wk->wu.id][1] = Get_Up_Action_Check_Data[wk->player_number][CP_No[wk->wu.id][1]][5];
        }

        if (CP_No[wk->wu.id][1] != 0) {
            break;
        }

        Lv = Setup_Lv10(0);

        if (Break_Into_CPU == 2) {
            Lv = 10;
        }

        if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
            Lv = 0;
        }

        Rnd = random_16_com();
        Lv += CC_Value[0];
        Lv = emLevelRemake(Lv, 11, 1);
        em = (WORK*)wk->wu.target_adrs;

        if (EM_Rank != 0) {
            Guard_Type[wk->wu.id] = Guard_Data[17][Lv][Rnd];
        } else {
            Guard_Type[wk->wu.id] = Guard_Data[wk->player_number][Lv][Rnd];
        }

        Check_Guard_Type(wk, em);
        break;
    }
}

void Damage_2nd(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    Check_Guard_Type(wk, em);

    if (wk->wu.routine_no[2] == 0x19) {
        CP_No[wk->wu.id][1] = 9;
        CP_No[wk->wu.id][2] = 0;
        return;
    }

    if (Receive_Flag[wk->wu.id] != 0 && plw[wk->wu.id].uot_cd_ok_flag != 0) {
        Lever_Buff[wk->wu.id] = 2;
    }

    if (wk->wu.routine_no[1] != 1) {
        Exit_Damage_Sub(wk);
    }
}

void Damage_3rd(PLW* /* unused */) {}

void Damage_4th(PLW* /* unused */) {}

void Damage_5th(PLW* wk) {
    if (wk->wu.routine_no[3] == 0) {
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        return;
    }

    switch (CP_No[wk->wu.id][2]) {
    case 0:
        if (wk->wu.routine_no[1] != 1) {
            Exit_Damage_Sub(wk);
            break;
        }

        if (wk->wu.cg_type == 9) {
            CP_No[wk->wu.id][2]++;
            CP_Index[wk->wu.id][1] = 0;
        }

        break;

    case 1:
        if (Command_Attack_SP(wk, wk->player_number, 46, 8)) {
            CP_No[wk->wu.id][2]++;
        }

        break;

    default:
        if (wk->wu.routine_no[1] != 4 || wk->wu.cg_type == 64) {
            Exit_Damage_Sub(wk);
        }

        break;
    }
}

void Damage_6th(PLW* wk) {
    u8 Lv;
    u8 Rnd;

    if (wk->wu.routine_no[3] == 0) {
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        return;
    }

    if (wk->wu.routine_no[2] == 0x19) {
        CP_No[wk->wu.id][1] = 9;
        CP_No[wk->wu.id][2] = 0;
        return;
    }

    Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 1);
    Lever_Buff[wk->wu.id] |= 2;

    switch (CP_No[wk->wu.id][2]) {
    case 0:
        if (wk->wu.routine_no[1] != 1) {
            Exit_Damage_Sub(wk);
            break;
        }

        if (wk->wu.cg_type == 12) {
            if (Get_Up_Action_Check_Data[wk->player_number][CP_No[wk->wu.id][1] - 1][Area_Number[wk->wu.id]] == -1) {
                CP_No[wk->wu.id][1] = Get_Up_Action_Check_Data[wk->player_number][CP_No[wk->wu.id][1]][5];
            }

            CP_No[wk->wu.id][2]++;
            CP_Index[wk->wu.id][1] = 0;
            Lv = Setup_Lv04(0);

            if (Break_Into_CPU == 2) {
                Lv = 3;
            }

            if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
                Lv = 0;
            }

            Lv = emLevelRemake(Lv, 4, 0);
            Rnd = random_32_com() & 3;
            Rnd *= 2;

            CP_Index[wk->wu.id][0] = Get_Up_Action_Tech_Data[wk->player_number][Lv][Rnd];
            CP_Index[wk->wu.id][7] = Get_Up_Action_Tech_Data[wk->player_number][Lv][Rnd + 1];

            if (CP_Index[wk->wu.id][0] == 0xFF) {
                CP_Index[wk->wu.id][0] = Get_Up_Action_Tech_Data[wk->player_number][Lv][0];
                CP_Index[wk->wu.id][7] = 8;

                if (plw[wk->wu.id].sa->ok &&
                    Arts_Super_Name_Data[wk->player_number][plw[wk->wu.id].sa->kind_of_arts] != -1) {
                    CP_Index[wk->wu.id][0] = Arts_Super_Name_Data[wk->player_number][plw[wk->wu.id].sa->kind_of_arts];
                }
            }
        }

        break;

    case 1:
        if (Command_Attack_SP(wk, wk->player_number, CP_Index[wk->wu.id][0], CP_Index[wk->wu.id][7])) {
            CP_No[wk->wu.id][2]++;
        }

        break;

    default:
        if (Command_Attack_SP(wk, wk->player_number, CP_Index[wk->wu.id][0], CP_Index[wk->wu.id][7])) {
            Exit_Damage_Sub(wk);
        }

        break;
    }
}

void Damage_7th(PLW* wk) {
    WORK* em;

    switch (CP_No[wk->wu.id][2]) {
    case 0:
        if (wk->wu.routine_no[1] != 1) {
            Exit_Damage_Sub(wk);
            break;
        }

        CP_No[wk->wu.id][2]++;

        switch (CP_No[wk->wu.id][1]) {
        case 6:
            Guard_Type[wk->wu.id] = 0;
            break;

        case 7:
            Guard_Type[wk->wu.id] = 1;
            break;

        default:
            Guard_Type[wk->wu.id] = 2;
            break;
        }

        break;

    default:
        em = (WORK*)wk->wu.target_adrs;
        Check_Guard_Type(wk, em);

        if (wk->wu.cg_type != 0x40 && wk->wu.routine_no[1] != 0) {
            break;
        }

        if (Attack_Flag[wk->wu.id] != 0) {
            break;
        }

        if (Attack_Flag[wk->wu.id] == 0) {
            Exit_Damage_Sub(wk);
            break;
        }

        if (wk->tsukamarenai_flag == 0) {
            Exit_Damage_Sub(wk);
        }

        break;
    }
}

void Damage_8th(PLW* wk) {
    s16 Rnd;
    s16 Lv;

    if (wk->wu.routine_no[1] != 1) {
        Exit_Damage_Sub(wk);
        return;
    }

    switch (CP_No[wk->wu.id][2]) {
    case 0:
        if (wk->wu.routine_no[2] == 0x19 && wk->wu.routine_no[3] != 0) {
            CP_No[wk->wu.id][2] += 1;
            Timer_00[wk->wu.id] = 1;
            Lv = Setup_Lv08(0);

            if (Break_Into_CPU == 2) {
                Lv = 7;
            }

            if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
                Lv = 0;
            }

            Timer_01[wk->wu.id] = Faint_Rapid_Data[emLevelRemake(Lv, 8, 0)][(Rnd = random_16_com() & 7)];
        }

        break;

    case 1:
        Lever_Buff[wk->wu.id] = Com_Rapid_Sub(wk, 0, &CP_No[wk->wu.id][3]);
        break;
    }
}

void Exit_Damage_Sub(PLW* wk) {
    Clear_Com_Flag(wk);

    if (Check_Passive(wk)) {
        return;
    }

    Next_Be_Free(wk);
}

static s32 Check_Damage(PLW* wk) {
    if (Counter_Attack[wk->wu.id] & 2) {
        return 0;
    }

    if (wk->wu.routine_no[1] == 1 && CP_No[wk->wu.id][0] != 7 && CP_No[wk->wu.id][0] != 9 &&
        Guard_Flag[wk->wu.id] == 0) {
        CP_No[wk->wu.id][0] = 10;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        Receive_Flag[wk->wu.id] = 0;
        Lever_Buff[wk->wu.id] = 2;
        Clear_Com_Flag(wk);
        return 1;
    }

    return 0;
}

void Com_Float(PLW* wk) {
    void (*Float_Jmp_Tbl[4])(PLW*) = { Damage_2nd, Float_2nd, Float_3rd, Float_4th };

    if (Check_Caught(wk)) {
        return;
    }

    if (Check_Flip(wk)) {
        return;
    }

    Float_Jmp_Tbl[CP_No[wk->wu.id][1]](wk);
}

void Float_2nd(PLW* wk) {
    switch (CP_No[wk->wu.id][2]) {
    case 0:
        CP_No[wk->wu.id][2]++;
        Lever_Buff[wk->wu.id] = 16;
        break;

    default:
        if (wk->wu.routine_no[1] == 0) {
            Next_Be_Free(wk);
            break;
        }

        Check_Damage(wk);
        break;
    }
}

void Float_3rd(PLW* wk) {
    if (wk->wu.routine_no[1] != 1) {
        Next_Be_Free(wk);
    }

    switch (CP_No[wk->wu.id][2]) {
    case 0:
        CP_No[wk->wu.id][2]++;
        Timer_00[wk->wu.id] = 4;
        Lever_Pool[wk->wu.id] = Setup_Guard_Lever(wk, 0);
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        break;

    default:
        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }

        Timer_00[wk->wu.id] = 3;
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        break;
    }
}

void Float_4th(PLW* wk) {
    if (wk->wu.routine_no[1] != 1) {
        Next_Be_Free(wk);
    }

    switch (CP_No[wk->wu.id][2]) {
    case 0:
        CP_No[wk->wu.id][2]++;
        Timer_00[wk->wu.id] = 4;
        Lever_Pool[wk->wu.id] = Setup_Guard_Lever(wk, 1);
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        break;

    default:
        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }

        Timer_00[wk->wu.id] = 3;
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        break;
    }
}

void Com_Flip(PLW* wk) {
    void (*Flip_Jmp_Tbl[5])(PLW*) = { Flip_Zero, Flip_1st, Flip_2nd, Flip_3rd, Flip_4th };

    if (Check_Damage(wk)) {
        return;
    }

    if (Check_Caught(wk)) {
        return;
    }

    Flip_Jmp_Tbl[CP_No[wk->wu.id][1]](wk);
}

void Flip_Zero(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    switch (CP_No[wk->wu.id][2]) {
    case 0:
        if (em->routine_no[1] != 4) {
            Exit_Damage_Sub(wk);
            break;
        }

        if (!Check_Flip_GO(wk, 0)) {
            break;
        }

        CP_No[wk->wu.id][2]++;
        Timer_00[wk->wu.id] = 9;
        break;

    case 1:
        if (Check_Flip(wk)) {
            break;
        }

        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }

        Exit_Damage_Sub(wk);
        break;
    }
}

s32 Check_Flip_GO(PLW* wk, s16 xx) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (em->att_hit_ok || xx) {
        if (em->pat_status == 0x21 || em->pat_status == 0x20) {
            Lever_Buff[wk->wu.id] = 2;
        } else {
            Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 0);
        }

        if (xx == 0 && Resume_Lever[wk->wu.id][0] == Lever_Buff[wk->wu.id]) {
            Next_Be_Guard(wk, em, 0);
            Flip_Counter[wk->wu.id] = 255;
            return 0;
        }

        Flip_Counter[wk->wu.id]++;
        return 1;
    }

    return 0;
}

void Flip_1st(PLW* wk) {
    if (wk->wu.xyz[1].disp.pos <= 0) {
        Exit_Damage_Sub(wk);
    }
}

void Flip_2nd(PLW* wk) {
    PLW* em;

    if (XB_PAST(PL_Damage_Data, 50, 0x249228, wk->wu.routine_no[2]) != 0) {
        return;
    }

    em = (PLW*)wk->wu.target_adrs;
    wk->player_number << 0;

    if (Check_Flip_Attack(wk) != 0) {
        if (Select_Passive(wk) == -1) {
            Exit_Damage_Sub(wk);
        }
    } else {
        Exit_Damage_Sub(wk);
    }
}

void Flip_3rd(PLW* wk) {
    s16 next_disposal;

    if (XB_PAST(PL_Damage_Data, 50, 0x249228, wk->wu.routine_no[2]) == 0) {
        return;
    }

    next_disposal = Check_Shell_Flip(wk);

    switch (next_disposal) {
    case 0:
        CP_No[wk->wu.id][1] = 2;
        return;

    case 1:
        Timer_00[wk->wu.id] = 15;
        /* fallthrough */

    case 3:
        CP_No[wk->wu.id][1] = 4;
        return;

    case 2:
        CP_No[wk->wu.id][0] = 9;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        Timer_00[wk->wu.id] = 10;
        Flip_Counter[wk->wu.id] = 255;
        dash_flag_clear(wk->wu.id);
        Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 1);

        if (((WORK*)wk->wu.dmg_adrs)->att.guard & 0x10) {
            break;
        }

        Lever_Buff[wk->wu.id] |= 2;
        break;

    default:
        Flip_Counter[wk->wu.id] = 255;
        Next_Be_Free(wk);
        break;
    }
}

void Flip_4th(PLW* wk) {
    if (--Timer_00[wk->wu.id] != 0) {
        return;
    }

    if (SetShellFlipLever(wk) == 0) {
        Flip_Counter[wk->wu.id] = 255;
        Next_Be_Free(wk);
        return;
    }

    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 1;
    Timer_00[wk->wu.id] = 9;
}

s32 SetShellFlipLever(PLW* wk) {
    WORK* tmw;

    Lever_Buff[wk->wu.id] = 0;
    tmw = (WORK*)Shell_Address[wk->wu.id];

    if (tmw == NULL) {
        return 0;
    }

    if (tmw->be_flag == 0 || tmw->id != 13) {
        return 0;
    }

    if (!(tmw->att.guard & 3)) {
        return 0;
    }

    Lever_Buff[wk->wu.id] = 2;

    if (tmw->att.guard & 2) {
        Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 0);
    }

    return 1;
}

static s32 Check_Shell_Flip(PLW* wk) {
    WORK* shell;
    s32 Rnd;
    s32 Lv;
    s32 xx;
    s32 res;

    res = 0;
    Flip_Counter[wk->wu.id]++;

    if (Timer_01[wk->wu.id] != 8) {
        return 0;
    }

    shell = (WORK*)wk->wu.dmg_adrs;

    if (shell == NULL) {
        res = 1;
    } else if (shell->be_flag != 0 && shell->id == 13) {
        // do nothing
    } else {
        res = 1;
    }

    if (res || shell->vital_new < 256) {
        if ((xx = Check_Shell_Another_in_Flip(wk)) == 0) {
            if (res) {
                return -1;
            }

            return 0;
        }

        if (xx > 16) {
            return 0;
        }

        res = 1;
        shell = (WORK*)Shell_Address[wk->wu.id];
        wk->wu.dmg_adrs = (u32*)shell;
    }

    Rnd = random_32_com();
    Rnd -= Flip_Term_Correct(wk);
    Lv = emLevelRemake(Setup_Lv08(0), 8, 0);

    if (Rnd >= Shell_Renzoku_Flip_Data[wk->player_number][Lv]) {
        return 2;
    }

    if (Flip_Counter[wk->wu.id] < emGetMaxBlocking()) {
        if (res == 0) {
            return 1;
        }

        xx -= 8;

        if (xx > 0) {
            Timer_00[wk->wu.id] = xx;
            return 3;
        }
    }

    return 0;
}

s32 Check_Flip(PLW* wk) {
    if (Flip_Flag[wk->wu.id]) {
        return 0;
    }

    if (wk->wu.routine_no[1] != 0) {
        return 0;
    }

    if (XB_PAST(PL_Damage_Data, 50, 0x249228, wk->wu.routine_no[2]) == 0) {
        return 0;
    }

    if (Flip_Counter[wk->wu.id] == 0xFF) {
        return 0;
    }

    CP_No[wk->wu.id][0] = 12;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = 15;

    if (Timer_01[wk->wu.id] == 8) {
        CP_No[wk->wu.id][1] = 3;
    } else {
        CP_No[wk->wu.id][1] = 2;
    }

    if (wk->wu.xyz[1].disp.pos > 0) {
        CP_No[wk->wu.id][1] = 1;
    }

    return 1;
}

static s32 Check_Flip_Attack(PLW* wk) {
    s16 Lv = Setup_Lv08(0);
    s16 Rnd;
    s16 xx;

    if (Break_Into_CPU == 2) {
        Lv = 7;
    }

    if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
        Lv = 0;
    }

    Rnd = random_32_com();
    Rnd -= Flip_Term_Correct(wk);
    xx = Setup_EM_Rank_Index(wk);

    if (Rnd >= Flip_Attack_Data[xx][emLevelRemake(Lv, 8, 0)]) {
        return 0;
    }

    Flip_Flag[wk->wu.id] = 0;
    VS_Tech[wk->wu.id] = 13;
    Counter_Attack[wk->wu.id] = 1;
    return 1;
}

void Com_Caught(PLW* wk) {
    s16 Rnd;
    s16 Lv;
    WORK* em = (WORK*)wk->wu.target_adrs;

    switch (CP_No[wk->wu.id][1]) {
    case 0:
        CP_No[wk->wu.id][1]++;
        CP_No[wk->wu.id][2] = 0;

        if (em->sp_tech_id == 1) {
            Timer_00[wk->wu.id] = 12;
            Lv = Setup_Lv08(0);

            if (Break_Into_CPU == 2) {
                Lv = 7;
            }

            if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
                Lv = 0;
            }

            Timer_01[wk->wu.id] = Rapid_Exit_Data[emLevelRemake(Lv, 8, 0)][(Rnd = random_16_com() & 7)];
            break;
        }

        Timer_00[wk->wu.id] = Decide_Exit_Catch(wk);
        Timer_01[wk->wu.id] = 1;
        break;

    case 1:
        if (wk->wu.routine_no[1] != 3) {
            if (wk->wu.routine_no[1] == 0) {
                Next_Be_Free(wk);
                break;
            }

            Check_Damage(wk);
            break;
        }

        Lever_Buff[wk->wu.id] = Com_Rapid_Sub(wk, 0xFF0, &CP_No[wk->wu.id][2]);
        break;
    }
}

static s16 Decide_Exit_Catch(PLW* wk) {
    s16 Rnd;
    s16 xx;
    s16 Lv = Setup_Lv18(save_w[Present_Mode].Difficulty + 0);

    Lv += CC_Value[0];

    if (Break_Into_CPU == 2) {
        Lv = 17;
    }

    Rnd = (u8)random_32_com();
    xx = Setup_EM_Rank_Index(wk);

    if (Rnd >= Exit_Throw_Data[xx][emLevelRemake(Lv, 18, 0)]) {
        return 0;
    }

    return 1;
}

s32 Com_Rapid_Sub(PLW* wk, s16 Shot, u8* dir_step) {
    u16 xx;

    if (--Timer_00[wk->wu.id] == 0) {
        Timer_00[wk->wu.id] = Timer_01[wk->wu.id];
        xx = Rapid_Lever_Data[dir_step[0]];
        xx |= Shot;
        dir_step[0]++;
        dir_step[0] &= 1;
        return xx;
    }

    return 0;
}

static s32 Check_Caught(PLW* wk) {
    if (wk->wu.routine_no[1] == 3) {
        CP_No[wk->wu.id][0] = 13;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        Clear_Com_Flag(wk);
        return 1;
    }

    return 0;
}

void Com_Catch(PLW* wk) {
    WORK* em;
    s16 Rnd;
    s16 Lv;

    switch (CP_No[wk->wu.id][1]) {
    case 0:
        CP_No[wk->wu.id][1]++;
        CP_No[wk->wu.id][2] = 0;
        Timer_00[wk->wu.id] = 1;
        Lv = Setup_Lv04(0);

        if (Break_Into_CPU == 2) {
            Lv = 3;
        }

        Timer_01[wk->wu.id] = Rapid_Hit_Data[emLevelRemake(Lv, 4, 0)][(Rnd = random_16_com() & 7)];
        break;

    case 1:
        em = (WORK*)wk->wu.target_adrs;

        if (wk->wu.routine_no[1] != 2 || em->routine_no[1] != 3) {
            Next_Be_Free(wk);
            break;
        }

        Lever_Buff[wk->wu.id] = Com_Rapid_Sub(wk, 0xFF0, &CP_No[wk->wu.id][2]);
        break;
    }
}

void Be_Catch(PLW* wk) {
    CP_No[wk->wu.id][0] = 15;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Clear_Com_Flag(wk);
}

void Com_Wait_Lie(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Blow_Off(wk, em, 0)) {
        return;
    }

    Exit_Damage_Sub(wk);
}

s32 Command_Attack_SP(PLW* wk, s8 Pl_Number, s16 Tech_Number, s16 Power_Level) {
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Tech_Address[wk->wu.id] = player_cmd[Pl_Number][Tech_Number & 0xFF];
        Tech_Index[wk->wu.id] = 0xC;
        Check_Rapid(wk, Tech_Number);
        Rapid_Index[wk->wu.id] = 0x110;
        Lever_Pool[wk->wu.id] = 0x110;
        break;

    case 1:
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, -1) == -1) {
                CP_Index[wk->wu.id][1] = 99;
            }

            break;

        case 2:
            if (Command_Type_01(wk, Power_Level & 0xF, -1)) {
                CP_Index[wk->wu.id][1]++;
            }

            break;
        }

        if (CP_Index[wk->wu.id][1] == 2) {
            return 1;
        }

        break;

    case 2:
        if (wk->wu.cg_type == 64) {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            CP_Index[wk->wu.id][1]++;
        }

        /* fallthrough */

    default:
        Rapid_Sub(wk);

        if (wk->wu.routine_no[1] == 0 && plw[wk->wu.id].caution_flag == 0) {
            return 1;
        }
    }

    return 0;
}

void Next_Be_Free(PLW* wk) {
    CP_No[wk->wu.id][0] = 1;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}

void Next_Be_Float(PLW* wk) {
    s16 Rnd;
    s16 Lv;

    CP_No[wk->wu.id][0] = 11;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Clear_Com_Flag(wk);
    Lv = Setup_Lv04(0);
    Rnd = random_16_com();
    CP_No[wk->wu.id][1] = Float_Attack_Data[emLevelRemake(Lv, 4, 0)][Rnd];
}

void Clear_Com_Flag(PLW* wk) {
    Passive_Flag[wk->wu.id] = 0;
    Flip_Flag[wk->wu.id] = 0;
    Counter_Attack[wk->wu.id] = 0;
    Limited_Flag[wk->wu.id] = 0;
    Guard_Flag[wk->wu.id] = 0;
    Before_Jump[wk->wu.id] = 0;
    Shell_Ignore_Timer[wk->wu.id] = 0;
    Pierce_Menu[wk->wu.id] = 0;
    Continue_Menu[wk->wu.id] = 0;
    Standing_Timer[wk->wu.id] = 0;
    Before_Look[wk->wu.id] = 0;
    Attack_Count_No0[wk->wu.id] = 0;
    Turn_Over[wk->wu.id] = 0;
    Jump_Pass_Timer[wk->wu.id][0] = 0;
    Jump_Pass_Timer[wk->wu.id][1] = 0;
    Jump_Pass_Timer[wk->wu.id][2] = 0;
    Jump_Pass_Timer[wk->wu.id][3] = 0;
    Last_Eftype[wk->wu.id] = 0;
}

void Check_At_Count(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    s16 ix;

    if (Attack_Count_No0[wk->wu.id] == 0) {
        if (Attack_Flag[wk->wu.id]) {
            Attack_Counter[wk->wu.id]++;
            Attack_Count_No0[wk->wu.id] = 1;
            Type_of_Attack[wk->wu.id] = em->kind_of_waza;
            Attack_Count_Buff[wk->wu.id][Attack_Count_Index[wk->wu.id]] = em->kind_of_waza;
            Attack_Count_Index[wk->wu.id]++;
            Attack_Count_Index[wk->wu.id] &= 3;
        }
    } else if (Attack_Flag[wk->wu.id] == 0) {
        Attack_Count_No0[wk->wu.id] = 0;
    }

    if (Attack_Flag[wk->wu.id]) {
        Reset_Timer[wk->wu.id] = 120;
        return;
    }

    if (--Reset_Timer[wk->wu.id] == 0) {
        for (ix = 0; ix < 4; ix++) {
            Attack_Count_Buff[wk->wu.id][ix] = ix;
        }
    }
}

void Shift_Resume_Lv(PLW* wk) {
    s16 xx;

    for (xx = 18; xx >= 0; xx--) {
        Resume_Lever[wk->wu.id][xx + 1] = Resume_Lever[wk->wu.id][xx];
    }

    Resume_Lever[wk->wu.id][0] = Lever_Buff[wk->wu.id];
}

void Check_Store_Lv(PLW* wk) {
    s16 xx = Lever_Buff[wk->wu.id] & 0xF;

    switch (xx) {
    case 2:
        Lever_Store[wk->wu.id][0]++;
        break;

    case 6:
    case 10:
        Store_LR_Sub(wk);
        Lever_Store[wk->wu.id][0]++;
        break;

    case 4:
    case 8:
        Store_LR_Sub(wk);
        break;

    default:
        Lever_Store[wk->wu.id][0] = 0;
        Lever_Store[wk->wu.id][1] = 0;
        Lever_Store[wk->wu.id][2] = 0;
        break;
    }
}

void Store_LR_Sub(PLW* wk) {
    if (wk->wu.rl_waza) {
        if (Lever_Buff[wk->wu.id] & 8) {
            Lever_Store[wk->wu.id][1]++;
            Lever_Store[wk->wu.id][2] = 0;
        }

        if (Lever_Buff[wk->wu.id] & 4) {
            Lever_Store[wk->wu.id][1] = 0;
            Lever_Store[wk->wu.id][2]++;
        }
    } else {
        if (Lever_Buff[wk->wu.id] & 4) {
            Lever_Store[wk->wu.id][1]++;
            Lever_Store[wk->wu.id][2] = 0;
        }

        if (Lever_Buff[wk->wu.id] & 8) {
            Lever_Store[wk->wu.id][1] = 0;
            Lever_Store[wk->wu.id][2]++;
        }
    }
}

void Setup_Bullet_Counter(PLW* wk) {
    Bullet_Counter[wk->wu.id] = 3;
    Bullet_Counter[wk->wu.id] += random_32_com() & 1;
}

void Pattern_Insurance(PLW* wk, s16 Kind_Of_Insurance, s16 Forced_Number) {
    if (Pattern_Insurance_Data[wk->player_number][Kind_Of_Insurance] < Pattern_Index[wk->wu.id]) {
        Pattern_Index[wk->wu.id] = Forced_Number;
    }
}
