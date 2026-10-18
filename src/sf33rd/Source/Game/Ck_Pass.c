/* Ck_Pass.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Ck_Passive_Term 0x2319C size 0x26.
 * Check_Attack_Direction 0x231C2 size 0x25.
 * Check_Rolling 0x231E7 size 0x46.
 * Check_Personal_Action 0x2322D size 0x30.
 * Check_Specific_Term 0x2325D size 0x3E.
 * Check_Dash 0x2329B size 0x3A.
 * Check_Limited_Attack 0x232D5 size 0xD4.
 * Check_Limited_Jump_Attack 0x233A9 size 0x27.
 * Setup_Next_Stand_Timer 0x233D0 size 0x57.
 * Setup_Next_Squat_Timer 0x23427 size 0x1D.
 * Check_Catch 0x23444 size 0x6A.
 * Check_Faint 0x234AE size 0x44.
 * Check_Blow_Off 0x234F2 size 0x42.
 * Check_After_Attack 0x23534 size 0x7F.
 * Check_F_Cross_Chop 0x235B3 size 0x64.
 * Check_PL_Unit_AS 0x23617 size 0x14.
 * Check_PL_Unit_A 0x2362B size 0x14.
 * Check_PL_Unit_BS 0x2363F size 0x14.
 * Check_PL_Unit_B 0x23653 size 0x14.
 * Check_PL_Unit_CS 0x23667 size 0x14.
 * Check_PL_Unit_C 0x2367B size 0x14.
 * Check_PL_Unit_DS 0x2368F size 0x14.
 * Check_PL_Unit_D 0x236A3 size 0x14.
 * Check_Special_Technique 0x236B7 size 0xDD.
 * Check_VS_Jump 0x23794 size 0xDC.
 * Check_Stand 0x23870 size 0x69.
 * Check_VS_Squat 0x238D9 size 0x88.
 * Check_Thrown 0x23961 size 0x58.
 * Check_Lie 0x239B9 size 0x3C.
 * VS_RYU_AS 0x239F5 size 0x74.
 * VS_DUDLEY_AS 0x23A69 size 0x86.
 * VS_HUGO_AS 0x23AEF size 0x91.
 * VS_GOUKI_AS 0x23BF0 size 0x5B.
 * VS_MAKOTO_AS 0x23C4B size 0x22.
 * VS_RYU_A 0x23D9C size 0x72.
 * VS_YUN_A 0x23E0E size 0x43.
 * VS_DUDLEY_A 0x23E51 size 0x5B.
 * VS_HUGO_A 0x23F1D size 0xAC.
 * VS_ELENA_A 0x23FC9 size 0x5A.
 * VS_SEAN_A 0x24023 size 0x68.
 * VS_GOUKI_A 0x2408B size 0x5B.
 * VS_CHUN_LI_A 0x240E6 size 0x5B.
 * VS_MAKOTO_A 0x24141 size 0x22.
 * VS_NO12_A 0x24163 size 0x43.
 * VS_RYU_BS 0x24250 size 0xA0.
 * VS_DUDLEY_BS 0x2434A size 0x71.
 * VS_KEN_BS 0x2449F size 0x88.
 * VS_GOUKI_BS 0x2456A size 0x8A.
 * VS_CHUN_LI_BS 0x245F4 size 0x43.
 * VS_YUN_B 0x246ED size 0x5B.
 * VS_DUDLEY_B 0x24748 size 0x5B.
 * VS_ELENA_B 0x247C5 size 0x5B.
 * VS_SEAN_B 0x24820 size 0x81.
 * VS_GOUKI_B 0x24914 size 0x8A.
 * VS_CHUN_LI_B 0x2499E size 0x72.
 * VS_Q_B 0x24A53 size 0x5B.
 * VS_ALEX_CS 0x24AAE size 0x5A.
 * VS_RYU_CS 0x24B08 size 0x8A.
 * VS_DUDLEY_CS 0x24B92 size 0x88.
 * VS_IBUKI_CS 0x24C1A size 0x22.
 * VS_ELENA_CS 0x24C3C size 0x71.
 * VS_GOUKI_CS 0x24D63 size 0x72.
 * VS_CHUN_LI_CS 0x24DD5 size 0x43.
 * VS_ALEX_C 0x24E5B size 0x83.
 * VS_YUN_C 0x24EDE size 0x43.
 * VS_DUDLEY_C 0x24F21 size 0x5B.
 * VS_NECRO_C 0x24F7C size 0x71.
 * VS_IBUKI_C 0x250C4 size 0x22.
 * VS_ELENA_C 0x250E6 size 0x5B.
 * VS_SEAN_C 0x251A6 size 0x74.
 * VS_GOUKI_C 0x2521A size 0x5B.
 * VS_CHUN_LI_C 0x25275 size 0x73.
 * VS_Q_C 0x252E8 size 0x43.
 * VS_NO12_DS 0x253D4 size 0x2F.
 * VS_URIEN_D 0x25403 size 0x22.
 * VS_NO12_D 0x25425 size 0x43.
 * KEN_vs 0x25468 size 0x27C.
 * HUGO_vs 0x256E4 size 0x21E.
 * GILL_vs 0x25902 size 0x284.
 * VS_ALEX_A is folded into 0x23D02 with 1 other bodies. Unnamed.
 * VS_ALEX_AS is folded into 0x241E9 with 1 other bodies. Unnamed.
 * VS_ALEX_B is folded into 0x23D02 with 1 other bodies. Unnamed.
 * VS_ALEX_BS is folded into 0x241E9 with 1 other bodies. Unnamed.
 * VS_ALEX_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_ALEX_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_CHUN_LI_AS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_CHUN_LI_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_CHUN_LI_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_DUDLEY_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_DUDLEY_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_ELENA_AS is folded into 0x23B80 with 1 other bodies. Unnamed.
 * VS_ELENA_BS is folded into 0x23B80 with 1 other bodies. Unnamed.
 * VS_ELENA_D is folded into 0x253B2 with 1 other bodies. Unnamed.
 * VS_ELENA_DS is folded into 0x253B2 with 1 other bodies. Unnamed.
 * VS_GILL_A is folded into 0x23C8F with 2 other bodies. Unnamed.
 * VS_GILL_AS is folded into 0x241A6 with 1 other bodies. Unnamed.
 * VS_GILL_B is folded into 0x23C8F with 2 other bodies. Unnamed.
 * VS_GILL_BS is folded into 0x241A6 with 1 other bodies. Unnamed.
 * VS_GILL_C is folded into 0x23C8F with 2 other bodies. Unnamed.
 * VS_GILL_CS is folded into 0x24527 with 3 other bodies. Unnamed.
 * VS_GILL_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_GILL_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_GOUKI_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_GOUKI_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_HUGO_B is folded into 0x24FED with 1 other bodies. Unnamed.
 * VS_HUGO_BS is folded into 0x243BB with 1 other bodies. Unnamed.
 * VS_HUGO_C is folded into 0x24FED with 1 other bodies. Unnamed.
 * VS_HUGO_CS is folded into 0x243BB with 1 other bodies. Unnamed.
 * VS_HUGO_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_HUGO_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_IBUKI_A is folded into 0x247A3 with 1 other bodies. Unnamed.
 * VS_IBUKI_AS is folded into 0x2445C with 1 other bodies. Unnamed.
 * VS_IBUKI_B is folded into 0x247A3 with 1 other bodies. Unnamed.
 * VS_IBUKI_BS is folded into 0x2445C with 1 other bodies. Unnamed.
 * VS_IBUKI_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_IBUKI_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_KEN_A is folded into 0x2536E with 3 other bodies. Unnamed.
 * VS_KEN_AS is folded into 0x24CCF with 1 other bodies. Unnamed.
 * VS_KEN_B is folded into 0x25163 with 1 other bodies. Unnamed.
 * VS_KEN_C is folded into 0x25163 with 1 other bodies. Unnamed.
 * VS_KEN_CS is folded into 0x24CCF with 1 other bodies. Unnamed.
 * VS_KEN_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_KEN_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_MAKOTO_B is folded into 0x24A10 with 1 other bodies. Unnamed.
 * VS_MAKOTO_BS is folded into 0x24637 with 1 other bodies. Unnamed.
 * VS_MAKOTO_C is folded into 0x24A10 with 1 other bodies. Unnamed.
 * VS_MAKOTO_CS is folded into 0x24637 with 1 other bodies. Unnamed.
 * VS_MAKOTO_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_MAKOTO_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_NECRO_A is folded into 0x23EAC with 1 other bodies. Unnamed.
 * VS_NECRO_AS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_NECRO_B is folded into 0x23EAC with 1 other bodies. Unnamed.
 * VS_NECRO_BS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_NECRO_CS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_NECRO_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_NECRO_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_NO12_AS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_NO12_B is folded into 0x2532B with 1 other bodies. Unnamed.
 * VS_NO12_BS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_NO12_C is folded into 0x2532B with 1 other bodies. Unnamed.
 * VS_NO12_CS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_ORO_A is folded into 0x25141 with 2 other bodies. Unnamed.
 * VS_ORO_AS is folded into 0x24CAD with 2 other bodies. Unnamed.
 * VS_ORO_B is folded into 0x25141 with 2 other bodies. Unnamed.
 * VS_ORO_BS is folded into 0x24CAD with 2 other bodies. Unnamed.
 * VS_ORO_C is folded into 0x25141 with 2 other bodies. Unnamed.
 * VS_ORO_CS is folded into 0x24CAD with 2 other bodies. Unnamed.
 * VS_ORO_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_ORO_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_Q_A is folded into 0x23C6D with 2 other bodies. Unnamed.
 * VS_Q_AS is folded into 0x23C6D with 2 other bodies. Unnamed.
 * VS_Q_BS is folded into 0x23C6D with 2 other bodies. Unnamed.
 * VS_Q_CS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_Q_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_Q_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_REMY_A is folded into 0x2536E with 3 other bodies. Unnamed.
 * VS_REMY_AS is folded into 0x24E18 with 2 other bodies. Unnamed.
 * VS_REMY_B is folded into 0x2536E with 3 other bodies. Unnamed.
 * VS_REMY_BS is folded into 0x24E18 with 2 other bodies. Unnamed.
 * VS_REMY_C is folded into 0x2536E with 3 other bodies. Unnamed.
 * VS_REMY_CS is folded into 0x24E18 with 2 other bodies. Unnamed.
 * VS_REMY_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_REMY_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_RYU_B is folded into 0x2467A with 1 other bodies. Unnamed.
 * VS_RYU_C is folded into 0x2467A with 1 other bodies. Unnamed.
 * VS_RYU_D is folded into 0x25390 with 1 other bodies. Unnamed.
 * VS_RYU_DS is folded into 0x25390 with 1 other bodies. Unnamed.
 * VS_SEAN_AS is folded into 0x24D41 with 2 other bodies. Unnamed.
 * VS_SEAN_BS is folded into 0x24D41 with 2 other bodies. Unnamed.
 * VS_SEAN_CS is folded into 0x24D41 with 2 other bodies. Unnamed.
 * VS_SEAN_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_SEAN_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_URIEN_A is folded into 0x248A1 with 2 other bodies. Unnamed.
 * VS_URIEN_AS is folded into 0x24527 with 3 other bodies. Unnamed.
 * VS_URIEN_B is folded into 0x248A1 with 2 other bodies. Unnamed.
 * VS_URIEN_BS is folded into 0x24527 with 3 other bodies. Unnamed.
 * VS_URIEN_C is folded into 0x248A1 with 2 other bodies. Unnamed.
 * VS_URIEN_CS is folded into 0x24527 with 3 other bodies. Unnamed.
 * VS_URIEN_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_YUN_AS is folded into 0x242F0 with 2 other bodies. Unnamed.
 * VS_YUN_BS is folded into 0x242F0 with 2 other bodies. Unnamed.
 * VS_YUN_CS is folded into 0x242F0 with 2 other bodies. Unnamed.
 * VS_YUN_D is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * VS_YUN_DS is folded into 0x4AFFA with 40 other bodies. Unnamed.
 * Data: PASSIVE_X 0xCB9FB7.
 * Data: Passive_jmp_tbl is 0x2411F8, 21 entries compared.
 * Data: Passive_AS_tbl is 0x241250, 20 entries compared.
 * Data: Passive_A_tbl is 0x2412A0, 20 entries compared.
 * Data: Passive_BS_tbl is 0x2412F0, 20 entries compared.
 * Data: Passive_B_tbl is 0x241340, 20 entries compared.
 * Data: Passive_CS_tbl is 0x241390, 20 entries compared.
 * Data: Passive_C_tbl is 0x2413E0, 20 entries compared.
 * Data: Passive_DS_tbl is 0x241430, 20 entries compared.
 * Data: Passive_D_tbl is 0x241480, 20 entries compared.
 * Unnamed data used (not a difference): Setup_Next_Stand_Timer:
 * 0x248ff0,0x248dd0.
 * Globals: Passive_jmp_tbl 0x2411F8, Passive_AS_tbl 0x241250, Passive_A_tbl
 * 0x2412A0, Passive_BS_tbl 0x2412F0, Passive_B_tbl 0x241340, Passive_CS_tbl
 * 0x241390, Passive_C_tbl 0x2413E0, Passive_DS_tbl 0x241430, Passive_D_tbl
 * 0x241480, Squat_Time_Data 0x249050, PL_Blow_Off_Data 0x249290,
 * Standing_Master_Timer 0x7A8122, EM_Rank 0x7A8124, Passive_Mode 0x7A813F,
 * Attack_Counter 0x7A817C, VS_Tech 0x7A82C8, CP_No 0x7A8308, Attack_Flag
 * 0x7A832C, Last_Attack_Counter 0x7A8338, Demo_Flag 0x7A842D, Standing_Timer
 * 0x7A8752, Counter_Attack 0x7A881C, Squat_Master_Timer 0x7A882E, Area_Number
 * 0x7A8914, Limited_Flag 0x7A8934, p1sw_0 0x7C557C, p2sw_0 0x7C5B90, PASSIVE_X
 * 0xCB9FB7.
 */

#include "structs.h"

void GILL_vs(PLW* wk);
void KEN_vs(PLW* wk);
void HUGO_vs(PLW* wk);
s32 VS_GILL_AS(PLW* wk);
s32 VS_ALEX_AS(PLW* wk);
s32 VS_RYU_AS(PLW* wk);
s32 VS_YUN_AS(PLW* wk);
s32 VS_DUDLEY_AS(PLW* wk);
s32 VS_NECRO_AS(PLW* wk);
s32 VS_HUGO_AS(PLW* wk);
s32 VS_IBUKI_AS(PLW* wk);
s32 VS_ELENA_AS(PLW* wk);
s32 VS_ORO_AS(PLW* wk);
s32 VS_KEN_AS(PLW* wk);
s32 VS_SEAN_AS(PLW* wk);
s32 VS_URIEN_AS(PLW* wk);
s32 VS_GOUKI_AS(PLW* wk);
s32 VS_CHUN_LI_AS(PLW* wk);
s32 VS_MAKOTO_AS(PLW* wk);
s32 VS_Q_AS(PLW* wk);
s32 VS_NO12_AS(PLW* wk);
s32 VS_REMY_AS(PLW* wk);
s32 VS_GILL_A(PLW* wk);
s32 VS_ALEX_A(PLW* wk);
s32 VS_RYU_A(PLW* wk);
s32 VS_YUN_A(PLW* wk);
s32 VS_DUDLEY_A(PLW* wk);
s32 VS_NECRO_A(PLW* wk);
s32 VS_HUGO_A(PLW* wk);
s32 VS_IBUKI_A(PLW* wk);
s32 VS_ELENA_A(PLW* wk);
s32 VS_ORO_A(PLW* wk);
s32 VS_KEN_A(PLW* wk);
s32 VS_SEAN_A(PLW* wk);
s32 VS_URIEN_A(PLW* wk);
s32 VS_GOUKI_A(PLW* wk);
s32 VS_CHUN_LI_A(PLW* wk);
s32 VS_MAKOTO_A(PLW* wk);
s32 VS_Q_A(PLW* wk);
s32 VS_NO12_A(PLW* wk);
s32 VS_REMY_A(PLW* wk);
s32 VS_GILL_BS(PLW* wk);
s32 VS_ALEX_BS(PLW* wk);
s32 VS_RYU_BS(PLW* wk);
s32 VS_YUN_BS(PLW* wk);
s32 VS_DUDLEY_BS(PLW* wk);
s32 VS_NECRO_BS(PLW* wk);
s32 VS_HUGO_BS(PLW* wk);
s32 VS_IBUKI_BS(PLW* wk);
s32 VS_ELENA_BS(PLW* wk);
s32 VS_ORO_BS(PLW* wk);
s32 VS_KEN_BS(PLW* wk);
s32 VS_SEAN_BS(PLW* wk);
s32 VS_URIEN_BS(PLW* wk);
s32 VS_GOUKI_BS(PLW* wk);
s32 VS_CHUN_LI_BS(PLW* wk);
s32 VS_MAKOTO_BS(PLW* wk);
s32 VS_Q_BS(PLW* wk);
s32 VS_NO12_BS(PLW* wk);
s32 VS_REMY_BS(PLW* wk);
s32 VS_GILL_B(PLW* wk);
s32 VS_ALEX_B(PLW* wk);
s32 VS_RYU_B(PLW* wk);
s32 VS_YUN_B(PLW* wk);
s32 VS_DUDLEY_B(PLW* wk);
s32 VS_NECRO_B(PLW* wk);
s32 VS_HUGO_B(PLW* wk);
s32 VS_IBUKI_B(PLW* wk);
s32 VS_ELENA_B(PLW* wk);
s32 VS_ORO_B(PLW* wk);
s32 VS_KEN_B(PLW* wk);
s32 VS_SEAN_B(PLW* wk);
s32 VS_URIEN_B(PLW* wk);
s32 VS_GOUKI_B(PLW* wk);
s32 VS_CHUN_LI_B(PLW* wk);
s32 VS_MAKOTO_B(PLW* wk);
s32 VS_Q_B(PLW* wk);
s32 VS_NO12_B(PLW* wk);
s32 VS_REMY_B(PLW* wk);
s32 VS_GILL_CS(PLW* wk);
s32 VS_ALEX_CS(PLW* wk);
s32 VS_RYU_CS(PLW* wk);
s32 VS_YUN_CS(PLW* wk);
s32 VS_DUDLEY_CS(PLW* wk);
s32 VS_NECRO_CS(PLW* wk);
s32 VS_HUGO_CS(PLW* wk);
s32 VS_IBUKI_CS(PLW* wk);
s32 VS_ELENA_CS(PLW* wk);
s32 VS_ORO_CS(PLW* wk);
s32 VS_KEN_CS(PLW* wk);
s32 VS_SEAN_CS(PLW* wk);
s32 VS_URIEN_CS(PLW* wk);
s32 VS_GOUKI_CS(PLW* wk);
s32 VS_CHUN_LI_CS(PLW* wk);
s32 VS_MAKOTO_CS(PLW* wk);
s32 VS_Q_CS(PLW* wk);
s32 VS_NO12_CS(PLW* wk);
s32 VS_REMY_CS(PLW* wk);
s32 VS_GILL_C(PLW* wk);
s32 VS_ALEX_C(PLW* wk);
s32 VS_RYU_C(PLW* wk);
s32 VS_YUN_C(PLW* wk);
s32 VS_DUDLEY_C(PLW* wk);
s32 VS_NECRO_C(PLW* wk);
s32 VS_HUGO_C(PLW* wk);
s32 VS_IBUKI_C(PLW* wk);
s32 VS_ELENA_C(PLW* wk);
s32 VS_ORO_C(PLW* wk);
s32 VS_KEN_C(PLW* wk);
s32 VS_SEAN_C(PLW* wk);
s32 VS_URIEN_C(PLW* wk);
s32 VS_GOUKI_C(PLW* wk);
s32 VS_CHUN_LI_C(PLW* wk);
s32 VS_MAKOTO_C(PLW* wk);
s32 VS_Q_C(PLW* wk);
s32 VS_NO12_C(PLW* wk);
s32 VS_REMY_C(PLW* wk);
s32 VS_GILL_DS(PLW* wk);
s32 VS_ALEX_DS(PLW* wk);
s32 VS_RYU_DS(PLW* wk);
s32 VS_YUN_DS(PLW* wk);
s32 VS_DUDLEY_DS(PLW* wk);
s32 VS_NECRO_DS(PLW* wk);
s32 VS_HUGO_DS(PLW* wk);
s32 VS_IBUKI_DS(PLW* wk);
s32 VS_ELENA_DS(PLW* wk);
s32 VS_ORO_DS(PLW* wk);
s32 VS_KEN_DS(PLW* wk);
s32 VS_SEAN_DS(PLW* wk);
s32 VS_URIEN_DS(PLW* wk);
s32 VS_GOUKI_DS(PLW* wk);
s32 VS_CHUN_LI_DS(PLW* wk);
s32 VS_MAKOTO_DS(PLW* wk);
s32 VS_Q_DS(PLW* wk);
s32 VS_NO12_DS(PLW* wk);
s32 VS_REMY_DS(PLW* wk);
s32 VS_GILL_D(PLW* wk);
s32 VS_ALEX_D(PLW* wk);
s32 VS_RYU_D(PLW* wk);
s32 VS_YUN_D(PLW* wk);
s32 VS_DUDLEY_D(PLW* wk);
s32 VS_NECRO_D(PLW* wk);
s32 VS_HUGO_D(PLW* wk);
s32 VS_IBUKI_D(PLW* wk);
s32 VS_ELENA_D(PLW* wk);
s32 VS_ORO_D(PLW* wk);
s32 VS_KEN_D(PLW* wk);
s32 VS_SEAN_D(PLW* wk);
s32 VS_URIEN_D(PLW* wk);
s32 VS_GOUKI_D(PLW* wk);
s32 VS_CHUN_LI_D(PLW* wk);
s32 VS_MAKOTO_D(PLW* wk);
s32 VS_Q_D(PLW* wk);
s32 VS_NO12_D(PLW* wk);
s32 VS_REMY_D(PLW* wk);
extern s8 Passive_Mode;
extern s16 Area_Number[2];
s32 Check_Dash(PLW* wk, WORK* em, s16 VS_Technique);
extern s8 Attack_Flag[2];
static s32 Check_PL_Unit_A(PLW* wk);
s32 Check_Limited_Attack(PLW* wk, WORK* em, s16 VS_Technique, u8 PL_Status, s8 Status_00, s16 Limit_Number);
s32 Check_Special_Technique(PLW* wk, WORK* em, s16 VS_Technique, u8 Kind_of_Tech, u8 SP_Tech_ID, s16 Option, s16 Option2);
static s32 Check_PL_Unit_AS(PLW* wk);
s32 Check_After_Attack(PLW* wk, WORK* em, s16 VS_Technique);
s32 Check_VS_Squat(PLW* wk, WORK* em, s16 VS_Technique, u8 Status_00, u8 Status_01);
s32 Check_Stand(PLW* wk, WORK* em, s16 VS_Technique);
s32 Check_VS_Jump(PLW* wk, PLW* em, s16 Height);
s32 Check_Personal_Action(PLW* wk, WORK* em);
static s32 Check_PL_Unit_B(PLW* wk);
static s32 Check_PL_Unit_BS(PLW* wk);
static s32 Check_PL_Unit_C(PLW* wk);
static s32 Check_PL_Unit_CS(PLW* wk);
static s32 Check_PL_Unit_D(PLW* wk);
static s32 Check_PL_Unit_DS(PLW* wk);
s32 Check_Attack_Direction(PLW* wk, WORK* em);
extern s16 Last_Attack_Counter[2];
extern s16 Attack_Counter[2];
extern s8 Counter_Attack[2];
extern s16 VS_Tech[2];
extern s8 Jump_Pass_Timer[2][4];
s32 Check_Specific_Term(PLW* wk, WORK* em, s16 VS_Technique, u8 Status_00, u8 Status_01, u8 Status_02);
extern s8 Limited_Flag[2];
extern s8 Standing_Timer[2];
extern s8 Standing_Master_Timer[2];
s32 Setup_Next_Stand_Timer(PLW* wk);
extern s8 EM_Rank;
extern const u8 Standing_Time_Data[20][4][8];
s32 random_16_com();
extern s8 Squat_Timer[2];
extern s8 Squat_Master_Timer[2];
s32 Setup_Next_Squat_Timer(PLW* wk);
extern const u8 Squat_Time_Data[8][8];
s32 Setup_Lv08(s16 xx);
s32 Setup_VS_Catch_Data(PLW* wk);
s32 random_32_com();
s32 Check_Catch(PLW* wk, WORK* em, s16 VS_Technique);
extern s8 Demo_Flag;
extern u16 p2sw_0;
extern u16 p1sw_0;
s32 Check_Faint(PLW* wk, PLW* enemy, s16 VS_Technique);
s32 Select_Passive(PLW* wk);
extern const s8 PL_Blow_Off_Data[27];
extern u8 CP_No[2][4];

extern s8 PASSIVE_X;

void (*const Passive_jmp_tbl[21])() = { GILL_vs, KEN_vs, KEN_vs, KEN_vs, KEN_vs, KEN_vs, HUGO_vs,
                                        KEN_vs,  KEN_vs, KEN_vs, KEN_vs, KEN_vs, KEN_vs, KEN_vs,
                                        KEN_vs,  KEN_vs, KEN_vs, KEN_vs, KEN_vs, KEN_vs, KEN_vs };

s32 (*const Passive_AS_tbl[20])(PLW* wk) = { VS_GILL_AS,    VS_ALEX_AS,   VS_RYU_AS,   VS_YUN_AS,   VS_DUDLEY_AS,
                                             VS_NECRO_AS,   VS_HUGO_AS,   VS_IBUKI_AS, VS_ELENA_AS, VS_ORO_AS,
                                             VS_YUN_AS,     VS_KEN_AS,    VS_SEAN_AS,  VS_URIEN_AS, VS_GOUKI_AS,
                                             VS_CHUN_LI_AS, VS_MAKOTO_AS, VS_Q_AS,     VS_NO12_AS,  VS_REMY_AS };

s32 (*const Passive_A_tbl[20])(PLW* wk) = { VS_GILL_A,    VS_ALEX_A,   VS_RYU_A,   VS_YUN_A,   VS_DUDLEY_A,
                                            VS_NECRO_A,   VS_HUGO_A,   VS_IBUKI_A, VS_ELENA_A, VS_ORO_A,
                                            VS_YUN_A,     VS_KEN_A,    VS_SEAN_A,  VS_URIEN_A, VS_GOUKI_A,
                                            VS_CHUN_LI_A, VS_MAKOTO_A, VS_Q_A,     VS_NO12_A,  VS_REMY_A };

s32 (*const Passive_BS_tbl[20])(PLW* wk) = { VS_GILL_BS,    VS_ALEX_BS,   VS_RYU_BS,   VS_YUN_BS,   VS_DUDLEY_BS,
                                             VS_NECRO_BS,   VS_HUGO_BS,   VS_IBUKI_BS, VS_ELENA_BS, VS_ORO_BS,
                                             VS_YUN_BS,     VS_KEN_BS,    VS_SEAN_BS,  VS_URIEN_BS, VS_GOUKI_BS,
                                             VS_CHUN_LI_BS, VS_MAKOTO_BS, VS_Q_BS,     VS_NO12_BS,  VS_REMY_BS };

s32 (*const Passive_B_tbl[20])(PLW* wk) = { VS_GILL_B,    VS_ALEX_B,   VS_RYU_B,   VS_YUN_B,   VS_DUDLEY_B,
                                            VS_NECRO_B,   VS_HUGO_B,   VS_IBUKI_B, VS_ELENA_B, VS_ORO_B,
                                            VS_YUN_B,     VS_KEN_B,    VS_SEAN_B,  VS_URIEN_B, VS_GOUKI_B,
                                            VS_CHUN_LI_B, VS_MAKOTO_B, VS_Q_B,     VS_NO12_B,  VS_REMY_B };

s32 (*const Passive_CS_tbl[20])(PLW* wk) = { VS_GILL_CS,    VS_ALEX_CS,   VS_RYU_CS,   VS_YUN_CS,   VS_DUDLEY_CS,
                                             VS_NECRO_CS,   VS_HUGO_CS,   VS_IBUKI_CS, VS_ELENA_CS, VS_ORO_CS,
                                             VS_YUN_CS,     VS_KEN_CS,    VS_SEAN_CS,  VS_URIEN_CS, VS_GOUKI_CS,
                                             VS_CHUN_LI_CS, VS_MAKOTO_CS, VS_Q_CS,     VS_NO12_CS,  VS_REMY_CS };

s32 (*const Passive_C_tbl[20])(PLW* wk) = { VS_GILL_C,    VS_ALEX_C,   VS_RYU_C,   VS_YUN_C,   VS_DUDLEY_C,
                                            VS_NECRO_C,   VS_HUGO_C,   VS_IBUKI_C, VS_ELENA_C, VS_ORO_C,
                                            VS_YUN_C,     VS_KEN_C,    VS_SEAN_C,  VS_URIEN_C, VS_GOUKI_C,
                                            VS_CHUN_LI_C, VS_MAKOTO_C, VS_Q_C,     VS_NO12_C,  VS_REMY_C };

s32 (*const Passive_DS_tbl[20])(PLW* wk) = { VS_GILL_DS,    VS_ALEX_DS,   VS_RYU_DS,   VS_YUN_DS,   VS_DUDLEY_DS,
                                             VS_NECRO_DS,   VS_HUGO_DS,   VS_IBUKI_DS, VS_ELENA_DS, VS_ORO_DS,
                                             VS_YUN_DS,     VS_KEN_DS,    VS_SEAN_DS,  VS_URIEN_DS, VS_GOUKI_DS,
                                             VS_CHUN_LI_DS, VS_MAKOTO_DS, VS_Q_DS,     VS_NO12_DS,  VS_REMY_DS };

s32 (*const Passive_D_tbl[20])(PLW* wk) = { VS_GILL_D,    VS_ALEX_D,   VS_RYU_D,   VS_YUN_D,   VS_DUDLEY_D,
                                            VS_NECRO_D,   VS_HUGO_D,   VS_IBUKI_D, VS_ELENA_D, VS_ORO_D,
                                            VS_YUN_D,     VS_KEN_D,    VS_SEAN_D,  VS_URIEN_D, VS_GOUKI_D,
                                            VS_CHUN_LI_D, VS_MAKOTO_D, VS_Q_D,     VS_NO12_D,  VS_REMY_D };

s32 Ck_Passive_Term(PLW* wk) {
    PASSIVE_X = 0;
    Passive_jmp_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
    return PASSIVE_X;
}

void KEN_vs(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    switch (Passive_Mode + Area_Number[wk->wu.id]) {
    case 0:
        Check_Dash(wk, em, 1);
        break;

    case 1:
        Check_Dash(wk, em, 1);
        break;

    case 2:
        Check_Dash(wk, em, 1);
        break;

    case 3:
        Check_Dash(wk, em, 1);
        break;

    case 4:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_A(wk)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 12, 32, 3, 0)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 7, 32, 5, 0)) {
                break;
            }

            if (Check_Special_Technique(wk, em, 15, 0, 33, 1, -1)) {
                break;
            }
        } else {
            if (Check_PL_Unit_AS(wk)) {
                break;
            }

            if (Check_After_Attack(wk, em, 28)) {
                break;
            }

            if (Check_VS_Squat(wk, em, 29, 33, 32)) {
                break;
            }

            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }

        if (Check_VS_Jump(wk, (PLW*)em, 16)) {
            break;
        }

        Check_Personal_Action(wk, em);
        break;

    case 5:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_B(wk)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 12, 32, 3, 0)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 7, 32, 5, 0)) {
                break;
            }

            if (Check_Special_Technique(wk, em, 15, 0, 33, 1, -1)) {
                break;
            }
        } else {
            if (Check_PL_Unit_BS(wk)) {
                break;
            }

            if (Check_After_Attack(wk, em, 28)) {
                break;
            }

            if (Check_VS_Squat(wk, em, 29, 33, 32)) {
                break;
            }

            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }

        if (Check_VS_Jump(wk, (PLW*)em, 32)) {
            break;
        }

        Check_Personal_Action(wk, em);
        break;

    case 6:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_C(wk)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 12, 32, 3, 0)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 7, 32, 5, 0)) {
                break;
            }
        } else {
            if (Check_PL_Unit_CS(wk)) {
                break;
            }

            if (Check_After_Attack(wk, em, 28)) {
                break;
            }

            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }

        if (Check_VS_Jump(wk, (PLW*)em, 64)) {
            break;
        }

        Check_Personal_Action(wk, em);

        break;

    default:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_D(wk)) {
                break;
            }
        } else {
            if (Check_PL_Unit_DS(wk)) {
                break;
            }

            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }

        Check_Personal_Action(wk, em);
        break;
    }
}

void HUGO_vs(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    switch (Passive_Mode + Area_Number[wk->wu.id]) {
    case 0:
        Check_Dash(wk, em, 1);
        break;

    case 1:
        Check_Dash(wk, em, 1);
        break;

    case 2:
        Check_Dash(wk, em, 1);
        break;

    case 3:
        Check_Dash(wk, em, 1);
        break;

    case 4:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_A(wk)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 7, 32, 3, 0)) {
                break;
            }

            if (Check_Special_Technique(wk, em, 15, 0, 33, 1, -1)) {
                break;
            }
        } else {
            if (Check_PL_Unit_AS(wk)) {
                break;
            }

            if (Check_After_Attack(wk, em, 28)) {
                break;
            }

            if (Check_VS_Squat(wk, em, 29, 33, 32)) {
                break;
            }

            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }

        Check_VS_Jump(wk, (PLW*)em, 16);
        break;

    case 5:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_B(wk)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 7, 32, 3, 0)) {
                break;
            }

            if (Check_Special_Technique(wk, em, 15, 0, 33, 1, -1)) {
                break;
            }
        } else {
            if (Check_PL_Unit_BS(wk)) {
                break;
            }

            if (Check_After_Attack(wk, em, 28)) {
                break;
            }

            if (Check_VS_Squat(wk, em, 29, 33, 32)) {
                break;
            }

            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }

        Check_VS_Jump(wk, (PLW*)em, 32);
        break;

    case 6:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_C(wk)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 7, 32, 3, 0)) {
                break;
            }
        } else {
            if (Check_PL_Unit_CS(wk)) {
                break;
            }

            if (Check_After_Attack(wk, em, 28)) {
                break;
            }

            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }

        Check_VS_Jump(wk, (PLW*)em, 64);
        break;

    default:
        if (Attack_Flag[wk->wu.id]) {
            Check_PL_Unit_D(wk);
            break;
        } else {
            if (Check_PL_Unit_DS(wk)) {
                break;
            }

            Check_Stand(wk, em, 4105);
            break;
        }
    }
}

void GILL_vs(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    switch (Passive_Mode + Area_Number[wk->wu.id]) {
    case 0:
        Check_Dash(wk, em, 1);
        break;

    case 1:
        Check_Dash(wk, em, 1);
        break;

    case 2:
        Check_Dash(wk, em, 1);
        break;

    case 3:
        Check_Dash(wk, em, 1);
        break;

    case 4:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_A(wk)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 12, 32, 3, 0)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 7, 32, 5, 0)) {
                break;
            }

            if (Check_Special_Technique(wk, em, 15, 0, 33, 1, -1)) {
                break;
            }
        } else {
            if (Check_PL_Unit_AS(wk)) {
                break;
            }

            if (Check_After_Attack(wk, em, 28)) {
                break;
            }

            if (Check_VS_Squat(wk, em, 29, 33, 32)) {
                break;
            }

            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }

        Check_VS_Jump(wk, (PLW*)em, 16);
        break;

    case 5:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_B(wk)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 12, 32, 3, 0)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 7, 32, 5, 0)) {
                break;
            }

            if (Check_Special_Technique(wk, em, 15, 0, 33, 1, -1)) {
                break;
            }
        } else {
            if (Check_PL_Unit_BS(wk)) {
                break;
            }

            if (Check_After_Attack(wk, em, 28)) {
                break;
            }

            if (Check_VS_Squat(wk, em, 29, 33, 32)) {
                break;
            }

            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }

        Check_VS_Jump(wk, (PLW*)em, 32);
        break;

    case 6:
        if (Attack_Flag[wk->wu.id]) {
            if (Check_PL_Unit_C(wk)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 12, 32, 3, 0)) {
                break;
            }

            if (Check_Limited_Attack(wk, em, 7, 32, 5, 0)) {
                break;
            }
        } else {
            if (Check_PL_Unit_CS(wk)) {
                break;
            }

            if (Check_After_Attack(wk, em, 28)) {
                break;
            }

            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }

        Check_VS_Jump(wk, (PLW*)em, 64);
        break;

    default:
        if (Attack_Flag[wk->wu.id]) {
            Check_PL_Unit_D(wk);
            break;
        } else {
            if (Check_PL_Unit_DS(wk)) {
                break;
            }

            if (Check_Stand(wk, em, 4105)) {
                break;
            }
        }

        Check_VS_Squat(wk, em, 7, 33, 32);
        break;
    }
}

s32 Check_Special_Technique(PLW* wk, WORK* em, s16 VS_Technique, u8 Kind_of_Tech, u8 SP_Tech_ID, s16 Option,
                            s16 Option2) {
    u8 xx;

    if (Option == 8 && Attack_Flag[wk->wu.id] != 0) {
        return 0;
    }

    if (VS_Technique != 23 && Check_Attack_Direction(wk, em)) {
        return 0;
    }

    if (Last_Attack_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
        return 0;
    }

    xx = em->kind_of_waza & 0xF8;

    if (xx == Kind_of_Tech && (em->sp_tech_id == SP_Tech_ID)) {
        if ((Option2 == -1 || !(Option2 & 8))) {
            if (Option2 == (em->kind_of_waza & 6)) {
                Last_Attack_Counter[(wk->wu.id)] = Attack_Counter[(wk->wu.id)];
                return 0;
            }
        } else if (!((Option2 & 6) & (em->kind_of_waza & 6))) {
            return 0;
        }

        if (Option == 8) {
            Counter_Attack[(wk->wu.id)] = 1;
        }

        if (Option == 1) {
            Counter_Attack[(wk->wu.id)] = 1;
        }

        VS_Tech[wk->wu.id] = VS_Technique;

        return PASSIVE_X = 1;
    }

    return 0;
}

s32 Check_Attack_Direction(PLW* wk, WORK* em) {
    if (wk->wu.xyz[0].disp.pos < em->xyz[0].disp.pos) {
        if (em->xyz[0].disp.pos > em->old_pos[0]) {
            return 1;
        }
    } else if (em->xyz[0].disp.pos < em->old_pos[0]) {
        return 1;
    }

    return 0;
}

s32 Check_VS_Jump(PLW* wk, PLW* em, s16 Height) {
    if (em->wu.routine_no[1] == 1) {
        return 0;
    }

    if (em->wu.sp_tech_id == 33) {
        return 0;
    }

    if (Jump_Pass_Timer[wk->wu.id][Area_Number[wk->wu.id]]) {
        Jump_Pass_Timer[wk->wu.id][Area_Number[wk->wu.id]]--;
        return 0;
    }

    if ((em->wu.mvxy.a[1].real.h) < 0 && (em->wu.xyz[1].disp.pos <= Height)) {
        return 0;
    }

    if (Check_Specific_Term(wk, &em->wu, 4099, 14, 20, 26)) {
        return Counter_Attack[wk->wu.id] = 1;
    }

    if (em->wu.xyz[1].disp.pos == 0) {
        return 0;
    }

    if ((em->wu.xyz[1].disp.pos < 32) && (em->wu.mvxy.a[1].real.h > 0)) {
        return 0;
    }

    if (em->micchaku_flag) {
        VS_Tech[wk->wu.id] = 18;
        return PASSIVE_X = 1;
    }

    if (Check_Specific_Term(wk, &em->wu, 18, 22, 28, 16)) {
        return 1;
    }

    VS_Tech[wk->wu.id] = 0;
    return 0;
}

s32 Check_Rolling(PLW* wk, WORK* em) {
    if (em->pat_status != 34) {
        return 0;
    }

    if (Check_Attack_Direction(wk, em)) {
        VS_Tech[wk->wu.id] = 6;
    } else {
        VS_Tech[wk->wu.id] = 5;
    }

    return PASSIVE_X = 1;
}

s32 Check_Personal_Action(PLW* wk, WORK* em) {
    if (em->routine_no[1] != 4) {
        return 0;
    }
    if (em->routine_no[2] != 30) {
        return 0;
    }

    VS_Tech[wk->wu.id] = 4105;

    return PASSIVE_X = 1;
}

s32 Check_Specific_Term(PLW* wk, WORK* em, s16 VS_Technique, u8 Status_00, u8 Status_01, u8 Status_02) {
    VS_Tech[wk->wu.id] = VS_Technique;

    if (em->pat_status == Status_00) {
        return PASSIVE_X = 1;
    }

    if (em->pat_status == Status_01) {
        return PASSIVE_X = 1;
    }

    if (em->pat_status == Status_02) {
        return PASSIVE_X = 1;
    }

    return 0;
}

s32 Check_Dash(PLW* wk, WORK* em, s16 VS_Technique) {
    if ((em->routine_no[1] == 0) && (em->routine_no[2] == 5) && (em->routine_no[3] != 0)) {
        VS_Tech[wk->wu.id] = VS_Technique;

        return PASSIVE_X = 1;
    }

    return 0;
}

s32 Check_Limited_Attack(PLW* wk, WORK* em, s16 VS_Technique, u8 PL_Status, s8 Status_00, s16 Limit_Number) {
    s16 xx;

    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }

    if (Last_Attack_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
        return 0;
    }

    if ((em->pat_status != PL_Status) || em->kind_of_waza != Status_00) {
        return 0;
    }

    xx = (em->cg_ix / em->cgd_type);

    if ((((PLW*)em)->player_number == 17) && (VS_Technique == 7)) {
        Limit_Number += 1;
    }

    if ((((PLW*)em)->player_number == 10) && (VS_Technique == 7)) {
        Limit_Number += 1;
    }

    if ((((PLW*)em)->player_number == 3) && (VS_Technique == 7)) {
        Limit_Number += 2;
    }

    if (xx > Limit_Number) {
        return 0;
    }

    VS_Tech[wk->wu.id] = VS_Technique;
    Limited_Flag[wk->wu.id] = 1;
    Counter_Attack[wk->wu.id] = 1;

    return PASSIVE_X = 1;
}

s32 Check_Limited_Jump_Attack(PLW* wk, WORK* em, u8 PL_Status, s8 Status_00) {
    if ((em->pat_status != PL_Status) || (em->kind_of_waza != Status_00)) {
        return 0;
    }

    return 1;
}

s32 Check_Stand(PLW* wk, WORK* em, s16 VS_Technique) {
    if (Attack_Flag[wk->wu.id]) {
        return 0;
    }

    if (em->routine_no[1] != 0) {
        return 0;
    }

    if ((Standing_Timer[wk->wu.id] += 1) < Standing_Master_Timer[wk->wu.id]) {
        return 0;
    }

    Standing_Master_Timer[wk->wu.id] = Setup_Next_Stand_Timer(wk);
    VS_Tech[wk->wu.id] = VS_Technique;

    return PASSIVE_X = 1;
}

s32 Setup_Next_Stand_Timer(PLW* wk) {
    if (EM_Rank != 0) {
        return Standing_Time_Data[17][Area_Number[wk->wu.id]][(random_16_com() & 7)];
    }

    return Standing_Time_Data[wk->player_number][Area_Number[wk->wu.id]][(random_16_com() & 7)];
}

s32 Check_VS_Squat(PLW* wk, WORK* em, s16 VS_Technique, u8 Status_00, u8 Status_01) {
    if (Attack_Flag[wk->wu.id]) {
        return Squat_Timer[wk->wu.id] = 0;
    }

    if (em->routine_no[1] != 0) {
        return Squat_Timer[wk->wu.id] = 0;
    }

    if (em->xyz[1].disp.pos) {
        return Squat_Timer[wk->wu.id] = 0;
    }

    if (em->pat_status != Status_00 && em->pat_status != Status_01) {
        return Squat_Timer[wk->wu.id] = 0;
    }

    if ((Squat_Timer[wk->wu.id] += 1) < Squat_Master_Timer[wk->wu.id]) {
        return 0;
    }

    Squat_Master_Timer[wk->wu.id] = Setup_Next_Squat_Timer(wk);
    VS_Tech[wk->wu.id] = VS_Technique;

    return PASSIVE_X = 1;
}

s32 Setup_Next_Squat_Timer(PLW* wk) {
    return Squat_Time_Data[Setup_Lv08(0)][(random_16_com() & 7)];
}

s32 Check_Thrown(PLW* wk, WORK* em) {
    s16 Rnd;
    s16 x;

    if (em->xyz[1].disp.pos) {
        return 0;
    }

    x = Setup_VS_Catch_Data(wk);
    Rnd = random_32_com();

    if (x < Rnd) {
        return 0;
    }

    switch (Area_Number[wk->wu.id]) {
    case 0:
        if (Check_Catch(wk, em, 25)) {
            return 1;
        }

        break;

    case 1:
        if (Check_Catch(wk, em, 25)) {
            return 1;
        }

        break;

    default:
        break;
    }

    return 0;
}

s32 Check_Catch(PLW* wk, WORK* em, s16 VS_Technique) {
    u16 xx;

    if (Demo_Flag == 0) {
        return 0;
    }

    if (em->routine_no[1] != 0) {
        return 0;
    }

    if (em->xyz[1].disp.pos) {
        return 0;
    }

    if (wk->wu.id == 0) {
        xx = p2sw_0;
    } else {
        xx = p1sw_0;
    }

    if (wk->wu.rl_waza) {
        if (!(xx & 4)) {
            return 0;
        }
    } else if (!(xx & 8)) {
        return 0;
    }

    Counter_Attack[wk->wu.id] = 1;
    VS_Tech[wk->wu.id] = VS_Technique;

    return PASSIVE_X = 1;
}

s32 Check_Lie(PLW* wk) {
    WORK* em;
    PLW* enemy;

    em = (WORK*)wk->wu.target_adrs;
    enemy = (PLW*)wk->wu.target_adrs;

    if (Check_Faint(wk, enemy, 2)) {
        return Select_Passive(wk);
    }

    if (Check_Specific_Term(wk, em, 0, 38, 38, 38)) {
        return Select_Passive(wk);
    }

    return 0;
}

s32 Check_Faint(PLW* wk, PLW* enemy, s16 VS_Technique) {
    Counter_Attack[wk->wu.id] = 1;
    VS_Tech[wk->wu.id] = VS_Technique;

    if ((enemy->wu.routine_no[1] == 1) && (enemy->wu.routine_no[2] == 25)) {
        return 1;
    }

    return Counter_Attack[wk->wu.id] = 0;
}

s32 Check_Blow_Off(PLW* wk, WORK* em, s16 VS_Technique) {
    if (em->routine_no[1] != 1) {
        return 0;
    }

    if (PL_Blow_Off_Data[em->routine_no[2]] == 0) {
        return 0;
    }

    if (em->xyz[1].disp.pos == 0) {
        return 0;
    }

    VS_Tech[(wk->wu.id)] = VS_Technique;

    return PASSIVE_X = 1;
}

s32 Check_After_Attack(PLW* wk, WORK* em, s16 VS_Technique) {
    u8 xx;

    if (CP_No[wk->wu.id][0] == 7) {
        return 0;
    }

    if (Last_Attack_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
        return 0;
    }

    if (em->xyz[1].disp.pos) {
        return 0;
    }

    if (em->routine_no[1] != 4) {
        return 0;
    }

    Last_Attack_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];

    if (!(em->kind_of_waza & 32) && !(em->kind_of_waza & 48) && !(em->kind_of_waza & 40) && !(em->kind_of_waza & 56) &&
        !(em->kind_of_waza & 8)) {
        xx = em->kind_of_waza & 6;

        if (xx == 0) {
            return 0;
        }

        if (xx == 2) {
            return 0;
        }
    }

    VS_Tech[wk->wu.id] = VS_Technique;

    return PASSIVE_X = 1;
}

s32 Check_F_Cross_Chop(PLW* wk, WORK* em, s16 VS_Technique) {
    if (Last_Attack_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
        return 0;
    }

    if ((em->kind_of_waza) != 4) {
        return 0;
    }

    if ((em->pat_status != 22) && (em->pat_status != 20) && (em->pat_status != 26) && (em->pat_status != 28)) {
        return 0;
    }

    VS_Tech[wk->wu.id] = VS_Technique;
    Counter_Attack[wk->wu.id] = 1;

    return PASSIVE_X = 1;
}

static s32 Check_PL_Unit_AS(PLW* wk) {
    return Passive_AS_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 64, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ALEX_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 24, 23, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 24, 22, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 56, 37, -1, -1)) {
        return 1;
    }

    if (Check_Rolling(wk, em)) {
        return 1;
    }

    return 0;
}

s32 VS_RYU_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 32, 4, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_YUN_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 29, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 36, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 24, 74, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_DUDLEY_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 2, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 32, 13, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 11, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 32, 12, -1, 0)) {
        return 1;
    }

    return 0;
}

s32 VS_NECRO_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_HUGO_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 14, 8, 61, -1, -1)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 32, 5, 32767)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 32, 4, 32767)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 19, 24, 58, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 24, 61, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_IBUKI_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 28, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 25, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ELENA_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 17, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 14, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 32, 15, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ORO_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 39, -1, 0)) {
        return 1;
    }

    return 0;
}

s32 VS_KEN_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 8, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 6, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_SEAN_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 32, 8, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_URIEN_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 65, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 64, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_GOUKI_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 69, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_CHUN_LI_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_MAKOTO_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 14, 24, 95, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_Q_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 25, 24, 88, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_NO12_AS(PLW* wk) {
    return 0;
}

s32 VS_REMY_AS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 101, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    return 0;
}

static s32 Check_PL_Unit_A(PLW* wk) {
    return Passive_A_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 64, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 63, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ALEX_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 25, 24, 22, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 24, 115, 1, 0)) {
        return 1;
    }

    if (Check_F_Cross_Chop(wk, em, 15)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 73, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 30, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 40, 72, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_RYU_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 48, 3, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 16, 32, 4, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_YUN_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 20, 8, 52, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 25, 24, 74, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_DUDLEY_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 2, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 18, 8, 75, 1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 32, 12, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_NECRO_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 38, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 40, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 17, 24, 24, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 32, 41, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_HUGO_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 19, 24, 58, 1, -1)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 32, 5, 32767)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 32, 4, 32767)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 19, 24, 62, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 19, 56, 55, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 24, 61, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_IBUKI_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 24, 26, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ELENA_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 18, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 19, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ORO_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 15, 8, 44, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_KEN_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_SEAN_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 21, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 32, 1, -1)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 0, 5, 32767)) {
        return 1;
    }

    if (Check_Rolling(wk, em)) {
        return 1;
    }

    return 0;
}

s32 VS_URIEN_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 8, 8, 65, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 64, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 63, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_GOUKI_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 16, 32, 4, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 13, 64, 47, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_CHUN_LI_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 78, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 114, 1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 21, 8, 77, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_MAKOTO_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 25, 24, 95, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_Q_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 25, 24, 88, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_NO12_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 17, 8, 105, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 22, 8, 107, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_REMY_A(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    return 0;
}

static s32 Check_PL_Unit_BS(PLW* wk) {
    return Passive_BS_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 64, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ALEX_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 24, 23, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 24, 22, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 56, 37, -1, -1)) {
        return 1;
    }

    if (Check_Rolling(wk, em)) {
        return 1;
    }

    return 0;
}

s32 VS_RYU_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 2, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 48, 3, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 16, 32, 4, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_YUN_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 29, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 36, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 24, 74, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_DUDLEY_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 32, 13, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 11, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 32, 12, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_NECRO_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_HUGO_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 32, 5, 32767)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 32, 4, 32767)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 19, 24, 58, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 24, 61, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_IBUKI_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 28, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 25, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ELENA_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 17, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 14, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 32, 15, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ORO_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 39, -1, 0)) {
        return 1;
    }

    return 0;
}

s32 VS_KEN_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 2, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 8, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 6, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_SEAN_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 32, 8, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_URIEN_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 65, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 64, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_GOUKI_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 2, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 16, 32, 4, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 69, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_CHUN_LI_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 78, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 76, -1, 0)) {
        return 1;
    }

    return 0;
}

s32 VS_MAKOTO_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 92, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 24, 95, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_Q_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 25, 24, 88, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_NO12_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_REMY_BS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 101, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    return 0;
}

static s32 Check_PL_Unit_B(PLW* wk) {
    return Passive_B_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 64, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 63, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ALEX_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 25, 24, 22, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 24, 115, 1, 0)) {
        return 1;
    }

    if (Check_F_Cross_Chop(wk, em, 15)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 73, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 30, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 40, 72, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_RYU_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 16, 32, 4, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_YUN_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 31, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 20, 8, 52, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 25, 24, 74, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_DUDLEY_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 18, 8, 75, 1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 32, 12, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_NECRO_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 38, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 40, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 17, 24, 24, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 32, 41, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_HUGO_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 19, 24, 58, 1, -1)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 32, 5, 32767)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 32, 4, 32767)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 19, 24, 62, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 19, 56, 55, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 24, 61, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_IBUKI_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 24, 26, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ELENA_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 18, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 19, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ORO_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 15, 8, 44, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_KEN_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_SEAN_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 15, 8, 32, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 21, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 20, 1, -1)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 0, 5, 32767)) {
        return 1;
    }

    if (Check_Rolling(wk, em)) {
        return 1;
    }

    return 0;
}

s32 VS_URIEN_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 8, 8, 65, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 64, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 63, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_GOUKI_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 16, 32, 4, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 16, 32, 5, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 13, 64, 47, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_CHUN_LI_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 78, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 76, 1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 114, 1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 21, 8, 77, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_MAKOTO_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 92, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 25, 24, 95, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_Q_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 84, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 21, 8, 87, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 25, 24, 88, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_NO12_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 22, 8, 107, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 17, 8, 105, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_REMY_B(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    return 0;
}

static s32 Check_PL_Unit_CS(PLW* wk) {
    return Passive_CS_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 65, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 64, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ALEX_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 24, 23, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 24, 22, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 56, 37, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_RYU_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 48, 3, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 16, 32, 4, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_YUN_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 29, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 36, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 24, 74, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_DUDLEY_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 2, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 32, 13, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 11, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 32, 12, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_NECRO_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_HUGO_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 32, 5, 32767)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 32, 4, 32767)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 19, 24, 58, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 24, 61, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_IBUKI_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 32, 25, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ELENA_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 17, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 14, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 32, 15, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ORO_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 39, -1, 0)) {
        return 1;
    }

    return 0;
}

s32 VS_KEN_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 8, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 6, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_SEAN_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 32, 8, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_URIEN_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 65, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 64, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_GOUKI_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 1, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 16, 32, 4, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 23, 32, 69, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_CHUN_LI_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 78, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 76, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_MAKOTO_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 92, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 24, 95, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_Q_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_NO12_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_REMY_CS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 23, 8, 101, -1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    return 0;
}

static s32 Check_PL_Unit_C(PLW* wk) {
    return Passive_C_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 64, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 63, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ALEX_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 24, 115, 1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 30, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 73, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 40, 72, 1, -1)) {
        return 1;
    }

    if (Check_F_Cross_Chop(wk, em, 15)) {
        return 1;
    }

    return 0;
}

s32 VS_RYU_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 16, 32, 4, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_YUN_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 31, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 20, 8, 52, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_DUDLEY_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 18, 8, 75, 1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 14, 32, 12, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_NECRO_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 38, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 40, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 17, 24, 24, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 32, 41, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_HUGO_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 61, -1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 19, 24, 58, 1, -1)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 32, 5, 32767)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 32, 4, 32767)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 19, 24, 62, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 19, 56, 55, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 24, 61, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_IBUKI_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 24, 26, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ELENA_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 18, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 19, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ORO_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 15, 8, 44, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_KEN_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_SEAN_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 15, 8, 32, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 21, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 20, 1, -1)) {
        return 1;
    }

    if (Check_Limited_Attack(wk, em, 24, 0, 5, 32767)) {
        return 1;
    }

    return 0;
}

s32 VS_URIEN_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 8, 8, 65, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 64, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 63, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_GOUKI_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 24, 8, 2, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 16, 32, 4, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_CHUN_LI_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 76, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 114, 1, 0)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 21, 8, 77, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 11, 8, 78, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_MAKOTO_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 92, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 25, 24, 95, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_Q_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 24, 8, 84, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 21, 8, 87, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_NO12_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 22, 8, 107, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 17, 8, 105, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_REMY_C(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 8, 0, 1, -1)) {
        return 1;
    }

    return 0;
}

static s32 Check_PL_Unit_DS(PLW* wk) {
    return Passive_DS_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_ALEX_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_RYU_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_YUN_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_DUDLEY_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_NECRO_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_IBUKI_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_HUGO_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_ELENA_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ORO_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_KEN_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_SEAN_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_URIEN_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_GOUKI_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_CHUN_LI_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_MAKOTO_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_Q_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_NO12_DS(PLW* wk) {
    PLW* em = (PLW*)wk->wu.target_adrs;

    if (Check_VS_Jump(wk, em, 32)) {
        VS_Tech[wk->wu.id] = 15;
        return 1;
    }

    return 0;
}

s32 VS_REMY_DS(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

static s32 Check_PL_Unit_D(PLW* wk) {
    return Passive_D_tbl[((PLW*)wk->wu.target_adrs)->player_number](wk);
}

s32 VS_GILL_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_ALEX_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_RYU_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 11, 32, 5, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_YUN_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_DUDLEY_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_NECRO_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_HUGO_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_IBUKI_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_ELENA_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 2, 48, 16, -1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_ORO_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_KEN_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_SEAN_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_URIEN_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 12, 8, 63, 1, 12)) {
        return 1;
    }

    return 0;
}

s32 VS_GOUKI_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_CHUN_LI_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_MAKOTO_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_Q_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}

s32 VS_NO12_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Check_Special_Technique(wk, em, 8, 8, 105, 1, -1)) {
        return 1;
    }

    if (Check_Special_Technique(wk, em, 15, 8, 107, 1, -1)) {
        return 1;
    }

    return 0;
}

s32 VS_REMY_D(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    return 0;
}
