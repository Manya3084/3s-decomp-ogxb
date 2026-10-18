/* Com_Sub.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * End_Pattern 0x281A9 size 0x5.
 * Next_Be_Passive 0x281AE size 0xB.
 * Turn_Over_On 0x281B9 size 0x28.
 * Only_Shot 0x281E1 size 0x23.
 * Lever_Off 0x28204 size 0x2A.
 * Pierce_On 0x2822E size 0x3B.
 * Check_Exit_DENJIN 0x28269 size 0x102.
 * Setup_KA_Jump 0x2836B size 0x74.
 * Setup_KA_Walk 0x283DF size 0x11.
 * Check_Arrival 0x283F0 size 0x4F.
 * Check_Squat 0x2843F size 0x17.
 * Check_Start_Normal_Attack 0x28456 size 0x3C.
 * Setup_Guard_Lever 0x28492 size 0x37. Read against the x86: 4 is the C's rnum
 * = 4.
 * Check_Start_Lever_Attack 0x284C9 size 0x2D.
 * DENJIN_Check 0x284F6 size 0x49.
 * YAGYOU_Check 0x2853F size 0x41.
 * SA_Range_Check 0x28580 size 0x59.
 * Branch_Wait_Area 0x285D9 size 0xE8.
 * Wait_Lie 0x287F6 size 0xF7.
 * Check_Wait_Term 0x288ED size 0x42.
 * Check_Exit_Guard 0x2892F size 0x33.
 * Check_Term_Sub 0x28962 size 0x2D.
 * Correct_Unit_PL 0x2898F size 0x17.
 * Check_Term_Sub_Y 0x289A6 size 0x43.
 * Check_Start_Hi_Jump 0x289E9 size 0x2A.
 * Check_SP_Jump_Attack 0x28A13 size 0x2C. Read against the x86: 0x7FFD is the
 * C's Lever_Data & 0x7FFF with bit 1 dropped, since the result is ORed with 2
 * anyway.
 * Check_Com_Add_Y 0x28A3F size 0x40.
 * Check_Resume_Lever 0x28A7F size 0x3F. Read against the x86: setne / lea
 * [ecx*4 + 4] is the branchless form of the C's rl_waza ? 8 : 4.
 * Setup_Rapid_Time 0x28ABE size 0x4.
 * Check_Rapid_End 0x28AC2 size 0xBA.
 * Check_Start_Command_Attack 0x28B7C size 0x7D. Read against the x86: 0x80 on
 * the high byte of the argument is the C's & 0x8000.
 * Setup_Front_or_Back 0x28BF9 size 0x24.
 * Check_Hit_Shell 0x28C1D size 0x62.
 * Command_Type_06 0x28C7F size 0xA8. Read against the x86: 0x80 on the high
 * byte of the argument is the C's & 0x8000.
 * Setup_Command_01 0x28D27 size 0x36.
 * Check_Store_Direction 0x28D5D size 0x69.
 * Setup_Lv04 0x28DC6 size 0x30.
 * Setup_Lv08 0x28DF6 size 0x2C.
 * Setup_Lv10 0x28E22 size 0x2B.
 * Setup_Lv18 0x28E4D size 0x2C. Read against the x86: 0x22 is the row stride
 * of Level_18_Data. Matches the C.
 * Ck_Distance 0x28E79 size 0x39.
 * Ck_Distance_Height 0x28EB2 size 0x1A.
 * Ck_Area 0x28ECC size 0x36.
 * Ck_Area_Shell 0x28F02 size 0x36.
 * Ck_Distance_Lv 0x28F38 size 0x56.
 * Ck_Distance_LvJ 0x28F8E size 0x56.
 * Next_Another_Menu 0x28FE4 size 0x65.
 * Get_Meoshi_Data 0x29049 size 0x38.
 * Reaction_Exit_Sub 0x29081 size 0x75.
 * Check_SA_Active 0x290F6 size 0xA5. Read against the x86: 0xFF is a byte
 * compare with the C's sa->ok != -1.
 * Decide_Follow_Menu 0x2919B size 0x6F.
 * Devide_Level 0x2920A size 0x44.
 * Check_Dramatic 0x2924E size 0x57.
 * Check_Makoto 0x292A5 size 0x39. Read against the x86: 0xFF is a byte compare
 * with the C's sa->ok != -1.
 * Setup_EM_Rank_Index 0x292DE size 0x19.
 * Flip_Term_Correct 0x292F7 size 0x52.
 * Next_Be_Guard 0x29349 size 0x6E.
 * Check_Flip_Tech 0x293B7 size 0x47. Read against the x86: 0x208 is the stride
 * of save_w. Matches the C.
 * Next_Be_Flip 0x293FE size 0xC2.
 * Compute_Hit_Time 0x294FA size 0x34.
 * Next_Be_Shell_Guard 0x2952E size 0x6B.
 * Check_Behind 0x29599 size 0x26.
 * Setup_Lever_LR 0x295BF size 0x6D. Read against the x86: test dh, 0x40 is the
 * C's & 0x4000.
 * VS_Jump_Term 0x2962C size 0xE1.
 * Exit_Term_0000 0x2970D size 0x5B.
 * Exit_Term_0002 0x29768 size 0x1C.
 * Exit_Term_0008 0x29784 size 0x69.
 * Check_Drop_Term 0x297ED size 0x22.
 * Check_SHINRYU 0x2980F size 0x3B. Read against the x86: 0xFF is a byte
 * compare with the C's sa->ok != -1.
 * Check_BOSS 0x2984A size 0x6F.
 * Check_BOSS_EX 0x298B9 size 0x6F.
 * ETC_Term 0x29928 size 0x87.
 * ETC_Term_0000 0x299AF size 0x1D.
 * ETC_Term_0001 0x299CC size 0x38. Read against the x86: 0xFF is a byte
 * compare with the C's sa->ok != -1.
 * ETC_Term_0002 0x29A04 size 0x1E.
 * ETC_Term_0003 0x29A22 size 0x1D.
 * ETC_Term_0004 0x29A3F size 0x2F.
 * ETC_Term_0005 0x29A6E size 0x28.
 * ETC_Term_0006 0x29A96 size 0x73.
 * ETC_Term_0007 0x29B09 size 0x20.
 * ETC_Term_0008 0x29B29 size 0x20.
 * ETC_Term_0009 0x29B49 size 0x1F.
 * emLevelRemake 0x29B68 size 0x8C. Read against the x86: rewritten for Xbox:
 * after the PS2 adjustment, when Country is 1 (Japan) the cap max drops by
 * exd, by exd >> 1 at difficulty 6 and not at all at 7. The negative and small
 * constants are the local table, stored inline. The C is the Xbox code
 * (analysis-ps2map/overrides/Com_Sub.c). Country. Country. Country. Country.
 * Country.
 * Country.
 * emGetMaxBlocking 0x29BF4 size 0x4A. Read against the x86: 0x208 is the
 * stride of save_w. Matches the C.
 * Lever_On 0x29C3E size 0x7C.
 * Setup_DENJIN_LEVEL 0x29CBA size 0x4C.
 * Search_Back_Term 0x29D06 size 0x80.
 * Forced_Guard 0x29D86 size 0x6E.
 * Small_Jump_Measure 0x29DF4 size 0x20.
 * Check_SA 0x29E14 size 0x68.
 * Check_EX 0x29E7C size 0x68.
 * Check_SA_Full 0x29EE4 size 0x5B.
 * Branch_Unit_Area 0x29F3F size 0x86.
 * Wait_Get_Up 0x29FC5 size 0xFD.
 * Wait_Attack_Complete 0x2A0C2 size 0x105.
 * Check_Term_Sub_Air 0x2A1C7 size 0x3C.
 * Check_Air_Guard 0x2A203 size 0x17A. Read against the x86: or byte
 * [Guard_Type + 1], 0x80 is the C's Guard_Type |= 0x8000.
 * Hadou_Check 0x2A37D size 0x2F.
 * Setup_Rapid_End_Term 0x2A3AC size 0x3F.
 * Rapid_Sub 0x2A3EB size 0x18E.
 * Check_Dash_Hit 0x2A579 size 0xB0.
 * Jump_Init 0x2A629 size 0x6D.
 * Command_Type_00 0x2A696 size 0x24B.
 * Command_Type_01 0x2A8E1 size 0x152.
 * Check_Store_Lever 0x2AA33 size 0x9F.
 * Select_Combo_Speed 0x2AAD2 size 0xA4.
 * Select_Reflection_Time 0x2AB76 size 0xAD. Read against the x86: 0x208 is the
 * stride of save_w. Matches the C.
 * Setup_VS_Catch_Data 0x2AC23 size 0x56.
 * Setup_LP_Data 0x2AC79 size 0x63.
 * Setup_WT_Data 0x2ACDC size 0x63.
 * Check_Meoshi_Attack 0x2AD3F size 0x107.
 * Check_First_Menu 0x2AE46 size 0x2F.
 * Select_Active 0x2AE75 size 0x1BF. Read against the x86: -4 is a frame local
 * and the index - 1 bias folded into lea. No change from the C.
 * Setup_Follow 0x2B034 size 0x6D.
 * Setup_Random 0x2B0A1 size 0x50.
 * Check_Flip_Term 0x2B0F1 size 0xA4.
 * Check_Diagonal_Shell 0x2B195 size 0x105.
 * Check_Shell_Another_in_Flip 0x2B29A size 0xB2.
 * Decide_Shell_Guard 0x2B34C size 0x8D.
 * Decide_Shell_Reaction 0x2B3D9 size 0x90.
 * Check_Exit_Term 0x2B469 size 0x35.
 * Exit_Term_0003 0x2B49E size 0x64.
 * Exit_Term_0004 0x2B502 size 0x64.
 * Exit_Term_0005 0x2B566 size 0x64.
 * Exit_Term_0006 0x2B5CA size 0x64.
 * Exit_Term_0007 0x2B62E size 0x8D.
 * Wait 0x2B6BB size 0xCC.
 * Check_VS_Air_Attack 0x2B787 size 0x166.
 * Rapid_Command_Attack 0x2B8ED size 0x26A.
 * Check_Rapid 0x2BB57 size 0x8E.
 * Select_Passive 0x2BBE5 size 0x333. Read against the x86: +1 is the second
 * element of Jump_Pass_Timer[id]. Matches the C.
 * Check_Guard 0x2BF18 size 0x142.
 * Setup_Shell_Disposal 0x2C05A size 0x5F.
 * Next_End 0x2C156 size 0x40.
 * Reaction_Sub 0x2C196 size 0x275. Read against the x86: test 0xFC is the C's
 * (Stock_Hit_Flag >> 2) != 0.
 * Guard_or_Jump_VS_Shell 0x2C40B size 0xBE. Read against the x86: 0x208 is the
 * stride of save_w. Matches the C.
 * Push_Shot 0x2C4C9 size 0xFB.
 * Com_Random_Select 0x2C5C4 size 0x95.
 * Check_Landed 0x2C659 size 0xB7.
 * Check_Shell 0x2C710 size 0x159.
 * Check_Passive 0x2C869 size 0x131.
 * Approach_Walk 0x2C99A size 0x13E.
 * Walk 0x2CAD8 size 0x144.
 * Provoke 0x2CC1C size 0xD5.
 * Normal_Attack 0x2CCF1 size 0x131.
 * Normal_Attack_SP 0x2CE22 size 0x14C.
 * Adjust_Attack 0x2CF6E size 0x139.
 * Lever_Attack 0x2D0A7 size 0xD6.
 * Lever_Attack_SP 0x2D17D size 0x134.
 * SA_Term 0x2D2B1 size 0x258.
 * Look 0x2D509 size 0x105.
 * EM_Term 0x2D707 size 0x150.
 * SHELL_Term 0x2D857 size 0xFF.
 * Jump 0x2D956 size 0x170. Read against the x86: test byte [wk + 0x38E], 3 is
 * the C's spmv_ng_flag & 0x30000 (spmv_ng_flag is at 0x38C).
 * Hi_Jump 0x2DAC6 size 0x219. Read against the x86: test byte [wk + 0x38E], 3
 * is the C's spmv_ng_flag & 0x30000 (spmv_ng_flag is at 0x38C).
 * Jump_Attack 0x2DCDF size 0x1D6. Read against the x86: test byte [wk +
 * 0x38E], 3 is the C's spmv_ng_flag & 0x30000 (spmv_ng_flag is at 0x38C).
 * Jump_Attack_Term 0x2DEB5 size 0x27A. Read against the x86: test byte [wk +
 * 0x38E], 3 is the C's spmv_ng_flag & 0x30000 (spmv_ng_flag is at 0x38C). The
 * C's Check_Term_ABS_Distance(wk) discards its result and has no side effects,
 * so MSVC dropped the call. Check_Term_ABS_Distance; x86-only offsets 0x38e.
 * Check_Term_ABS_Distance; x86-only offsets 0x38e. Check_Term_ABS_Distance;
 * x86-only offsets 0x38e. Check_Term_ABS_Distance; x86-only offsets 0x38e.
 * Check_Term_ABS_Distance; x86-only offsets 0x38e.
 * Check_Term_ABS_Distance; x86-only offsets 0x38e.
 * Hi_Jump_Attack 0x2E12F size 0x2F4. Read against the x86: test byte [wk +
 * 0x38E], 3 is the C's spmv_ng_flag & 0x30000 (spmv_ng_flag is at 0x38C).
 * Hi_Jump_Attack_Term 0x2E423 size 0x3BC. Read against the x86: test byte [wk
 * + 0x38E], 3 is the C's spmv_ng_flag & 0x30000 (spmv_ng_flag is at 0x38C).
 * ORO_JA_Term 0x2E7DF size 0x31D. Read against the x86: test byte [wk +
 * 0x38E], 3 is the C's spmv_ng_flag & 0x30000 (spmv_ng_flag is at 0x38C).
 * ORO_HJA_Term 0x2EAFC size 0x3C4. Read against the x86: test byte [wk +
 * 0x38E], 3 is the C's spmv_ng_flag & 0x30000 (spmv_ng_flag is at 0x38C).
 * Command_Attack 0x2EEC0 size 0x36C.
 * J_Command_Attack 0x2F22C size 0x246. Read against the x86: test byte [wk +
 * 0x38E], 3 is the C's spmv_ng_flag & 0x30000 (spmv_ng_flag is at 0x38C).
 * ORO_JCA_Term 0x2F472 size 0x340.
 * ORO_HJCA_Term 0x2F7B2 size 0x3A2. Read against the x86: test byte [wk +
 * 0x38E], 3 is the C's spmv_ng_flag & 0x30000 (spmv_ng_flag is at 0x38C).
 * Jump_Command_Attack_Term 0x2FB54 size 0x2C3. Read against the x86: test byte
 * [wk + 0x38E], 3 is the C's spmv_ng_flag & 0x30000 (spmv_ng_flag is at
 * 0x38C).
 * Hi_Jump_Command_Attack_Term 0x2FE17 size 0x2F1. Read against the x86: test
 * byte [wk + 0x38E], 3 is the C's spmv_ng_flag & 0x30000 (spmv_ng_flag is at
 * 0x38C).
 * Keep_Away 0x30108 size 0x84.
 * Check_Ignore_Shell is folded into 0x294C0 with 1 other bodies. Unnamed.
 * Exit_Term_0001 is folded into 0x9B78F with 3 other bodies. Unnamed.
 * Check_Ignore_Shell2 is folded into 0x294C0 with 1 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: Keep_Status,
 * VS_Jump_Guard, Short_Range_Attack, Check_Term_ABS_Distance, Ck_Distance_XX.
 * Check_Ignore_Shell is folded into 0x294C0.
 * Check_Ignore_Shell2 is folded into 0x294C0.
 * Check_Term_ABS_Distance has no XBE name and no aligned call.
 * Data: Lv 0xCB9FB6.
 * Data: Rnd 0xCB9FB5.
 * Data: YAGYOU_Data is 0x249688, 0x10 bytes compared.
 * Data: Correct_VS_Air_Data is 0x249698, 0x28 bytes compared.
 * Data: Hadou_Check_Data is 0x2496C0, 0xA0 bytes compared.
 * Data: Rolling_Lv_Data is 0x249760, 0x24 bytes compared.
 * Data: Follow_Menu_1st_Unit_Data: not located in the XBE, PS2 initializer
 * kept.
 * Data: Follow_Menu_2nd_Unit_Data: not located in the XBE, PS2 initializer
 * kept.
 * Data: PL_Status is 0x249784, 0xA bytes compared.
 * Data: Exit_Term_Tbl: not located in the XBE, PS2 initializer kept.
 * Data: ETC_Term_Tbl: not located in the XBE, PS2 initializer kept.
 * Unnamed data used (not a difference): Reaction_Sub: 0x7a89b4;
 * Check_Air_Guard: 0x2492b0,0x247e68; Branch_Unit_Area: 0x43cf74;
 * Check_Exit_DENJIN: 0x7a8928; Setup_DENJIN_LEVEL: 0x7a8a0c,0x249098;
 * Forced_Guard: 0x2492b0,0x7a87dc; Com_Random_Select: 0x43cf74,0x249518;
 * Check_Store_Direction: 0x7a87d2,0x7a87d4,0x7a87d0; Check_Meoshi_Attack:
 * 0x7a89b4,0x7a880c,0x7a878c; Check_Guard: 0x2492b0,0x247e68; SHELL_Term:
 * 0x249480; SA_Term: 0x43cf74; Branch_Wait_Area: 0x43cf74; Select_Passive:
 * 0x2a7d88,0x29dd88,0x293d88,0x289d88; DENJIN_Check: 0x7a8a0c,0x7a8928;
 * Ck_Area_Shell: 0x7a81e0; Setup_WT_Data: 0x247a00; Check_Exit_Term: 0x249790;
 * Wait_Get_Up: 0x7a89fc; Command_Attack: 0x2495b8,0x2494d0; Wait_Lie:
 * 0x7a89fc; Setup_Lv10: 0x2410ac; Turn_Over_On: 0x7a8a2e; Decide_Follow_Menu:
 * 0x32a5f8,0x32a62c; Guard_or_Jump_VS_Shell: 0x249480,0x249308; Setup_LP_Data:
 * 0x247a20; ETC_Term: 0x2497b4; Select_Reflection_Time: 0x244800,0x247280;
 * Select_Active:
 * 0x26dcf8,0x26daf8,0x26d8f8,0x26d6f8,0x26c2f8,0x26aef8,0x269af8,0x2686f8;
 * Setup_Lv04: 0x241078; Select_Combo_Speed: 0x241600,0x244080; Ck_Area:
 * 0x7a88a0; Setup_Rapid_End_Term: 0x7a8742,0x7a8743; Check_Rapid: 0x248d90;
 * Setup_KA_Jump: 0x249578; Setup_Lv08: 0x241080; Check_Rapid_End:
 * 0x7a8742,0x7a8743,0x7a8740.
 * Globals: Level_18_Data 0x2410C0, Flip_Data 0x247C88, Shell_Guard_Data
 * 0x248C28, VS_Catch_Data 0x249090, VS_Diagonal_Shell_Data 0x249118,
 * Dash_Distance_Data 0x249120, YAGYOU_Data 0x249688, Correct_VS_Air_Data
 * 0x249698, Hadou_Check_Data 0x2496C0, Rolling_Lv_Data 0x249760, PL_Status
 * 0x249784, VS_Shell_Active_Data 0x2B15D8, player_cmd 0x332B88, player_CMD
 * 0x332BD8, Combo_Speed 0x7A80B8, Pattern_Index 0x7A80C8, Flip_Flag 0x7A80D0,
 * Disposal_Again 0x7A810C, Player_id 0x7A810F, My_char 0x7A8114, EM_Rank
 * 0x7A8124, Term_No 0x7A8134, Passive_Flag 0x7A8138, Before_Jump 0x7A813C,
 * Passive_Mode 0x7A813F, Attack_Counter 0x7A817C, Tech_Address 0x7A8190,
 * Present_Mode 0x7A819C, Stock_Hit_Flag 0x7A81AE, PL_Distance 0x7A81C8,
 * Control_Time 0x7A81EE, Lie_Flag 0x7A81F0, Max_vitality 0x7A81F8, CC_Value
 * 0x7A81FC, Shell_Address 0x7A8230, Lever_Squat 0x7A8274, VS_Tech 0x7A82C8,
 * CP_No 0x7A8308, Flip_Counter 0x7A831C, Attack_Flag 0x7A832C, PL_Wins
 * 0x7A832E, Counter_hi 0x7A8330, Last_Attack_Counter 0x7A8338, Weak_PL
 * 0x7A8414, Demo_Flag 0x7A842D, Guard_Type 0x7A8478, Resume_Lever 0x7A8540,
 * CP_Index 0x7A85B0, Lever_Buff 0x7A86B8, Rapid_Index 0x7A86BC, Timer_01
 * 0x7A86CC, Country 0x7A8748, Lever_LR 0x7A874C, Standing_Timer 0x7A8752,
 * Lever_Pool 0x7A87F4, Guard_Counter 0x7A8808, Counter_Attack 0x7A881C,
 * Timer_00 0x7A8820, Shell_Ignore_Timer 0x7A882C, Continue_Menu 0x7A88FA,
 * Area_Number 0x7A8914, Limited_Flag 0x7A8934, Tech_Index 0x7A89AC, Super_Arts
 * 0x7A89FE, Break_Into_CPU 0x7A8A25, bg_w 0x7BC520, save_w 0x7BD3E0, plw
 * 0xC7CEA0, cmd_sel 0xC7D9D0, Rnd 0xCB9FB5, Lv 0xCB9FB6.
 */

#include "structs.h"

#define NULL 0

typedef const s16* const_s16_arr;

typedef const _anon6* const_anon6_p;

typedef const _anon13* const_anon13_p;

typedef s32 (*Term_Tbl_t)(PLW* wk, WORK* em);

s32 sub_000294C0();
extern const _anon6 COM00_Flollow_1st_Unit_Data;
extern const _anon6 COM02_Flollow_1st_Unit_Data;
extern const _anon13 Com00_Follow_Menu;
extern const _anon13 Com02_Follow_Menu;
s32 Exit_Term_0000(PLW* wk, WORK* em);
s32 Exit_Term_0001(PLW* wk, WORK* em);
s32 Exit_Term_0002(PLW* wk, WORK* em);
s32 Exit_Term_0003(PLW* wk, WORK* em);
s32 Exit_Term_0004(PLW* wk, WORK* em);
s32 Exit_Term_0005(PLW* wk, WORK* em);
s32 Exit_Term_0006(PLW* wk, WORK* em);
s32 Exit_Term_0007(PLW* wk, WORK* em);
s32 Exit_Term_0008(PLW* wk, WORK* em);
s32 ETC_Term_0000(PLW* wk, WORK* em);
s32 ETC_Term_0001(PLW* wk, WORK* em);
s32 ETC_Term_0002(PLW* wk, WORK* em);
s32 ETC_Term_0003(PLW* wk, WORK* em);
s32 ETC_Term_0004(PLW* wk, WORK* em);
s32 ETC_Term_0005(PLW* wk, WORK* em);
s32 ETC_Term_0006(PLW* wk, WORK* em);
s32 ETC_Term_0007(PLW* wk, WORK* em);
s32 ETC_Term_0008(PLW* wk, WORK* em);
s32 ETC_Term_0009(PLW* wk, WORK* em);
void Next_Be_Free(PLW* wk);
extern s8 Disposal_Again[2];
extern s8 Turn_Over[2];
extern u8 CP_Index[2][8];
extern u16 Lever_Buff[2];
extern u16 Lever_LR[2];
s32 Setup_Guard_Lever(PLW* wk, u16 Lever);
extern s8 Pierce_Menu[2];
extern u16 DENJIN_No[2];
void Next_Another_Menu(PLW* wk, s16 Next_Action, u16 Next_Menu);
extern const u8 Denjin_Data[4][16];
extern s16 Area_Number[2];
s32 random_16_com();
void Reaction_Exit_Sub(PLW* wk);
s32 Check_Exit_DENJIN(PLW* wk);
extern u8 Stock_Hit_Flag[2];
void Reaction_Sub(PLW* wk, s16 Reaction, s16 Power_Level);
extern u8 DENJIN_Term[2];
extern s8 Attack_Flag[2];
s32 Check_Attack_Direction(PLW* wk, WORK* em);
extern s8 Lie_Flag[2];
void Setup_KA_Jump(PLW* wk);
void Setup_KA_Walk(PLW* wk);
void Jump(PLW* wk, s16 Jump_Dir);
void Approach_Walk(PLW* wk, s16 Target_Pos, s16 Option);
extern const s16 Back_Jump_Data[20];
extern BG bg_w;
void dash_flag_clear(s16 pl_id);
extern s16 Timer_00[2];
extern s8 Standing_Timer[2];
s32 Check_Passive(PLW* wk);
s32 Check_Arrival(PLW* wk, s16 Target_Pos, s16 Option);
extern s8 Flip_Flag[2];
extern s8 Limited_Flag[2];
extern u8 CP_No[2][4];
extern s8 Passive_Flag[2];
void Ck_Distance_Lv(PLW* wk);
extern s16 PL_Distance[2];
extern s16 Timer_01[2];
extern u16 Free_Lever[2];
extern const s16 Hit_Range_Data[];
extern s16 Com_Width_Data[2];
void Next_Be_Guard(PLW* wk, WORK* em, s16 Type_Of_Guard);
extern u16 Lever_Squat[2];
s32 Check_Start_Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data);
void Check_First_Menu(PLW* wk);
extern s8 Combo_Speed[2];
s32 Check_Squat(PLW* wk);
s32 Check_Start_Lever_Attack(PLW* wk, u16 Lever, u16 Lever_Data);
void Be_Catch(PLW* wk);
extern PLW plw[2];
s32 SA_Range_Check(PLW* wk, s16 SA_No, u16 Range);
s32 DENJIN_Check(PLW* wk, u16 SA2, u16* xx, u16 Term_No);
extern s16 Max_vitality;
s32 YAGYOU_Check(PLW* wk, s16* xx, u16 Term_No);
extern const u8 Com_Rnd_Select_Data[6][16];
void Next_End(PLW* wk);
s32 Setup_WT_Data(PLW* wk);
s32 Setup_LP_Data(PLW* wk);
extern s8 Before_Look[2];
extern s8 Rolling_Flag[2];
s32 Check_Blow_Off(PLW* wk, WORK* em, s16 VS_Technique);
s32 Check_Wait_Term(PLW* wk, s16 Option);
extern s8 Guard_Flag[2];
s32 Check_Exit_Guard(PLW* wk, s16 Option);
extern s16 Term_No[2];
s32 Check_Exit_Term(PLW* wk, WORK* em, s16 Exit_No);
s32 Check_Term_Sub(PLW* wk, s16 Distance, s16 Range);
s32 Check_Term_Sub_Y(PLW* wk, s16 Distance, s16 Range);
s32 Select_Passive(PLW* wk);
extern s8 Counter_Attack[2];
extern u32* Shell_Address[2];
s32 Compute_Hit_Time(PLW* wk, WORK_Other* tmw);
extern const u8 Shell_Dodge_Data[][20];
s32 Correct_Unit_PL(PLW* wk);
extern u8 My_char[2];
extern s8 Player_id;
void hi_jump_flag_clear(s16 pl_id);
void Jump_Init(PLW* wk, s16 Jump_Dir);
s32 Check_Diagonal_Shell(PLW* wk);
extern u16 Lever_Pool[2];
s32 Check_Air_Guard(PLW* wk);
s32 Check_Start_Hi_Jump(PLW* wk);
extern char cmd_sel[2];
extern const_s16_arr Tech_Address[2];
extern const_s16_arr* player_CMD[];
extern const_s16_arr* player_cmd[];
extern s16 Tech_Index[2];
s32 Command_Type_00(PLW* wk, s16 Power_Level, u16 Tech_Number, s16 Ex_Shot);
extern s16 Guard_Counter[2];
extern s16 Attack_Counter[2];
s32 Setup_Lv10(s16 xx);
extern s8 Demo_Flag;
extern u8 Weak_PL;
extern u8 CC_Value[2];
s32 emLevelRemake(s32 now, s32 max, s32 exd);
s32 Setup_EM_Rank_Index(PLW* wk);
extern const s8 Guard_Data[20][11][16];
extern u16 Guard_Type[2];
s32 random_16_ex_com();
void Setup_Lever_LR(PLW* wk, s16 PL_id, s16 Lever);
extern s8 Continue_Menu[2];
s32 Check_SP_Jump_Attack(PLW* wk, s16 Lever_Data);
s32 Check_Landed(PLW* wk, s16 Reaction);
s32 Check_VS_Air_Attack(PLW* wk, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data);
s32 Check_Term_ABS_Distance(PLW* wk);
s32 Check_Com_Add_Y(PLW* wk, s16 Pos_Y, s16 Range);
s32 Ck_Distance_Height(PLW* wk);
s32 Select_Reflection_Time(PLW* wk);
s32 Get_Meoshi_Data(PLW* wk);
s32 Check_Start_Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number);
s32 Check_Dash_Hit(PLW* wk, u16 Tech_Number);
extern const u16 Power_Lv_Data[];
s32 Hadou_Check(PLW* wk, u16 Tech_Number);
void Check_Rapid(PLW* wk, u16 Tech_Number);
extern const u8 Dash_Time_Data[20][2];
s32 Command_Type_01(PLW* wk, s16 Power_Level, s16 Ex_Shot);
s32 Command_Type_06(PLW* wk, s16 Power_Level, u16 Tech_Number, s16 Ex_Shot);
void Rapid_Sub(PLW* wk);
s32 Check_Resume_Lever(PLW* wk);
extern u16 Resume_Lever[2][20];
extern s8 Rapid_No[2][4];
s32 Setup_Lv08(s16 xx);
extern s8 Break_Into_CPU;
extern const s8 Rapid_SA_Data[8][8];
s32 random_32_com();
void Setup_Rapid_End_Term(PLW* wk, s16 Tech_Number);
extern s16 Rapid_Index[2];
s32 Setup_Rapid_Time(PLW* wk, u16 Tech_Number);
s32 Check_Rapid_End(PLW* wk);
extern s8 Before_Jump[2];
s32 Check_Guard(PLW* wk);
s32 get_vs_shell_adrs(WORK* wk, s16 id, s16 ix, WORK_Other** tmw);
s32 Setup_Front_or_Back(PLW* wk, s16 xx);
s32 Check_Hit_Shell(PLW* wk, WORK_Other* tmw, u16 Tech_Number);
extern const s16 Dash_Distance_Data[20][2];
void Ck_Distance_LvJ(PLW* wk);
s16 datacmd_conpanecmd(s16 dat);
s16 renbanshot_conpaneshot(const s16* dadr, s16 pow);
extern s8 Super_Arts[2];
void Setup_Command_01(PLW* wk);
extern u16 Lever_Store[2][3];
s32 Check_Store_Direction(PLW* wk, u16 lever, s16 time);
s32 Setup_Lv18(s16 xx);
extern const s8 Combo_Speed_Unit_Data[20][20][32];
extern struct _SAVE_W save_w[6];
extern u8 Present_Mode;
extern s16 time_check[4];
extern u8 time_check_ix;
extern const s8 Reflection_Speed_Unit_Data[20][20][32];
extern const u16 Level_04_Data[3];
extern s16 Control_Time;
extern const u16 Level_08_Data[3][7];
extern const u16 Level_10_Data[9];
extern const u16 Level_18_Data[9][17];
extern const u8 VS_Catch_Data[8];
extern const u8 LOOK_POSITION_Data[8][32];
extern const u8 Wait_Time_Data[4][8];
extern s16 Separate_Area[2][3];
extern s16 Shell_Separate_Area[2][3];
extern u16 Pattern_Index[2];
void Setup_Follow(PLW* wk, s16 Follow_Type);
s32 Check_Meoshi_Attack(PLW* wk, s16 Reaction, s16 Power_Level);
extern s16 Last_Eftype[2];
extern s16 Return_CP_No[2];
extern s16 Return_CP_Index[2];
extern s16 Return_Pattern_Index[2];
extern u16 M_Lv[2];
s16 get_meoshi_lever(s16 data);
s16 get_meoshi_shot(s16 data);
s32 random_32_ex_com();
s32 Check_SA_Active(PLW* wk, s16* pl_id);
extern const u8 SA_Active_A_Unit_Data[4][4][32];
extern const u8 SA_Active_B_Unit_Data[4][4][32];
extern const u8 SA_Active_C_Unit_Data[4][4][32];
extern const u8 SA_Active_D_Unit_Data[4][4][32];
extern const u8 Active_A_Unit_Data[20][8][32];
extern const u8 Active_B_Unit_Data[20][8][32];
extern const u8 Active_C_Unit_Data[20][8][32];
extern const u8 Active_D_Unit_Data[20][8][32];
extern s8 Debug_w[72];
extern s16 VS_Tech[2];
extern s16 Last_Attack_Counter[2];
void Devide_Level(s16 xx);
void Setup_Random(PLW* wk);
extern const u8 Passive_A_Unit_Data_04[20][32][4][16];
extern s8 Jump_Pass_Timer[2][4];
extern const u8 Passive_B_Unit_Data_04[20][32][4][16];
extern const u8 Passive_C_Unit_Data_04[20][32][4][16];
extern const u8 Passive_D_Unit_Data_04[20][16][4][16];
s32 Check_Dramatic(PLW* wk, s16 PL_id);
s32 Check_Thrown(PLW* wk, WORK* em);
s32 Check_Shell(PLW* wk);
s32 Check_Lie(PLW* wk);
extern s8 Passive_Mode;
s32 Ck_Passive_Term(PLW* wk);
s32 Check_Flip_Term(PLW* wk, WORK* tmw);
void Next_Be_Flip(PLW* wk, s16 xx);
s32 Check_Flip_Tech(WORK* em);
s32 Flip_Term_Correct(PLW* wk);
extern const u8 Flip_Data[20][8];
extern s8 EM_Rank;
extern u8 PL_Wins[2];
extern s8 Counter_hi;
void Check_Guard_Type(PLW* wk, WORK* em);
extern u8 Flip_Counter[2];
s32 SetShellFlipLever(PLW* wk);
s32 Check_Flip_GO(PLW* wk, s16 xx);
extern const u8 VS_Diagonal_Shell_Data[8];
s32 Check_Behind(PLW* wk, WORK_Other* tmw);
extern s8 Shell_Ignore_Timer[2];
s32 Ck_Distance_XX(s16 x1, s16 x2);
s32 Decide_Shell_Guard(PLW* wk, WORK_Other* tmw);
void Guard_or_Jump_VS_Shell(PLW* wk, WORK_Other* tmw, s16 xx);
s16 get_att_head_position(WORK* wk);
extern const s8 Shell_Guard_Data[20][10];
s32 Decide_Shell_Reaction(PLW* wk, WORK_Other* tmw, u16 dir_step);
extern const u8 Shell_Change_Data_For_Reaction[];
void Setup_Shell_Disposal(PLW* wk, WORK_Other* tmw);
void Next_Be_Shell_Guard(PLW* wk, WORK* tmw);
extern const u8 VS_Shell_Active_Data[20][4][8][16];
s32 VS_Jump_Term(PLW* wk, WORK* em, s16* xx);
s32 Check_F_Cross_Chop(PLW* wk, WORK* em, s16 VS_Technique);
s32 Check_Special_Technique(PLW* wk, WORK* em, s16 VS_Technique, u8 Kind_of_Tech, u8 SP_Tech_ID, s16 Option, s16 Option2);
s32 Check_Limited_Jump_Attack(PLW* wk, WORK* em, u8 PL_Status, s8 Status_00);
s32 Check_SHINRYU(PLW* wk);
s32 Check_Drop_Term(WORK* em, s16 Y);
s32 Check_VS_Squat(PLW* wk, WORK* em, s16 VS_Technique, u8 Status_00, u8 Status_01);
extern u8 Country;

extern s8 Lv;

extern s8 Rnd;

const u8 YAGYOU_Data[0x10] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3 };

const s16 Correct_VS_Air_Data[0x14] = { 0, 0x20, 0, 0, 0, 0x20, 0x20, 0, 0x20, 0, 0, 0, 0, 0x20, 0, 0, 0, 0, 0, 0 };

const s32 Hadou_Check_Data[20][2] = {
    { 0, 0 },    { 0, 0 }, { 1, 0x1D }, { 0, 0 },    { 1, 0x1F }, { 0, 0 }, { 1, 0x20 },
    { 1, 0x21 }, { 0, 0 }, { 0, 0 },    { 1, 0x1F }, { 1, 0x1D }, { 0, 0 }, { 0, 0 },
    { 1, 0x1F }, { 0, 0 }, { 1, 0x1E }, { 0, 0 },    { 0, 0 },    { 0, 0 },
};

const u16 Rolling_Lv_Data[2][9] = {
    { 4, 1, 8, 2, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF },
    { 4, 2, 8, 1, 4, 2, 8, 1, 0xFFFF },
};

static const_anon6_p Follow_Menu_1st_Unit_Data[13] = {
    &COM00_Flollow_1st_Unit_Data, &COM00_Flollow_1st_Unit_Data, &COM02_Flollow_1st_Unit_Data,
    &COM00_Flollow_1st_Unit_Data, &COM00_Flollow_1st_Unit_Data, &COM00_Flollow_1st_Unit_Data,
    &COM00_Flollow_1st_Unit_Data, &COM00_Flollow_1st_Unit_Data, &COM00_Flollow_1st_Unit_Data,
    &COM00_Flollow_1st_Unit_Data, &COM00_Flollow_1st_Unit_Data, &COM00_Flollow_1st_Unit_Data,
    &COM00_Flollow_1st_Unit_Data,
};

static const_anon13_p Follow_Menu_2nd_Unit_Data[13] = {
    &Com00_Follow_Menu, &Com00_Follow_Menu, &Com02_Follow_Menu, &Com00_Follow_Menu, &Com00_Follow_Menu,
    &Com00_Follow_Menu, &Com00_Follow_Menu, &Com00_Follow_Menu, &Com00_Follow_Menu, &Com00_Follow_Menu,
    &Com00_Follow_Menu, &Com00_Follow_Menu, &Com00_Follow_Menu,
};

const s8 PL_Status[0xA] = { 1, 0, 0, 0, 1, 1, 0, 0, 0, 0 };

const Term_Tbl_t Exit_Term_Tbl[9] = { Exit_Term_0000, Exit_Term_0001, Exit_Term_0002, Exit_Term_0003, Exit_Term_0004,
                                      Exit_Term_0005, Exit_Term_0006, Exit_Term_0007, Exit_Term_0008 };

const Term_Tbl_t ETC_Term_Tbl[10] = { ETC_Term_0000, ETC_Term_0001, ETC_Term_0002, ETC_Term_0003, ETC_Term_0004,
                                      ETC_Term_0005, ETC_Term_0006, ETC_Term_0007, ETC_Term_0008, ETC_Term_0009 };

void End_Pattern(PLW* wk) {
    Next_Be_Free(wk);
}

void Next_Be_Passive(PLW* wk, s32 unused) {
    Next_Be_Free(wk);
}

void Turn_Over_On(PLW* wk) {
    Disposal_Again[wk->wu.id] = 1;
    Turn_Over[wk->wu.id] = 1;
    CP_Index[wk->wu.id][0]++;
}

void Only_Shot(PLW* wk, s16 Lever_Data) {
    Lever_Buff[wk->wu.id] = Lever_Data;
    CP_Index[wk->wu.id][0]++;
}

void Lever_On(PLW* wk, u16 LR_Lever, u16 UD_Lever) {
    CP_Index[wk->wu.id][0]++;
    Disposal_Again[wk->wu.id] = 1;
    if ((LR_Lever == 0) || (LR_Lever == 1)) {
        Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, LR_Lever);
    } else {
        Lever_LR[wk->wu.id] = 0;
    }
    Lever_LR[wk->wu.id] |= UD_Lever;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}

void Lever_Off(PLW* wk) {
    CP_Index[wk->wu.id][0]++;
    Disposal_Again[wk->wu.id] = 1;
    Lever_LR[wk->wu.id] = 0;
}

void Pierce_On(PLW* wk) {
    Disposal_Again[wk->wu.id] = 1;
    CP_Index[wk->wu.id][0]++;
    Pierce_Menu[wk->wu.id] = 1;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}

void Setup_DENJIN_LEVEL(PLW* wk) {
    u16 xx;

    Disposal_Again[wk->wu.id] = 1;
    if ((xx = DENJIN_No[wk->wu.id])) {
        Next_Another_Menu(wk, 2, xx);
    } else {
        Next_Another_Menu(wk, 2, Denjin_Data[Area_Number[wk->wu.id]][random_16_com()]);
    }
}

void Push_Shot(PLW* wk, s16 Power_Level) {
    s16 xx;

    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if ((wk->wu.cg_type == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        } else {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            if ((wk->wu.now_koc == 8) && (wk->wu.char_index == 0xD)) {

                xx = wk->wu.cg_ix / wk->wu.cgd_type;
                if (xx >= Power_Level) {
                    CP_Index[wk->wu.id][1] = 0x63;
                }
            }
            if (Check_Exit_DENJIN(wk) != 0) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
        }
        break;
    case 1:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Exit_DENJIN(wk) != 0) {
            CP_Index[wk->wu.id][1] = 0x63;
        }
        /* fallthrough */
    default:
        if ((wk->wu.cg_type == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        } else {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
            Reaction_Sub(wk, 8, Power_Level);
        }
        break;
    }
}

s32 Check_Exit_DENJIN(PLW* wk) {
    s16 xx;
    WORK* em;

    if (!(DENJIN_Term[wk->wu.id] & 1)) {
        if (CP_Index[wk->wu.id][1] == 0) {
            return 0;
        }
    }

    if ((DENJIN_Term[wk->wu.id] & 8)) {
        if (Attack_Flag[wk->wu.id]) {
            return 1;
        }
    }
    em = (WORK*)wk->wu.target_adrs;

    xx = 0;
    if ((em->xyz[0].disp.pos) != (em->old_pos[0])) {
        if (Check_Attack_Direction(wk, em) != 0) {
            xx = -1;
        } else {
            xx = 1;
        }
    }

    if ((DENJIN_Term[wk->wu.id] & 1) && (em->xyz[0].disp.pos != 0)) {
        if (CP_Index[wk->wu.id][2] == 0) {
            CP_Index[wk->wu.id][2]++;
            CP_Index[wk->wu.id][3] = Area_Number[wk->wu.id];
        }
        switch (CP_Index[wk->wu.id][3]) {
        case 0:
        case 1:
        case 2:
            if (em->mvxy.a[1].real.h > 0) {
                return 1;
            }
            if (em->mvxy.a[1].real.h < 0) {
                if (em->xyz[1].disp.pos < 0x29) {
                    return 1;
                }
            }
            break;
        default:
            if ((em->mvxy.a[1].real.h > 0) && (xx == -1)) {
                return 1;
            }
            if (em->mvxy.a[1].real.h < 0) {
                if (em->xyz[1].disp.pos < 0x29) {
                    return 1;
                }
            }
            break;
        }
    }
    if (xx == 0) {
        return 0;
    }

    if ((DENJIN_Term[wk->wu.id] & 2) && (xx == 1)) {
        return 1;
    }

    if ((DENJIN_Term[wk->wu.id] & 4) && (xx == -1)) {
        return 1;
    }

    if ((DENJIN_Term[wk->wu.id] & 0x20) && (Lie_Flag[wk->wu.id] == 0)) {
        return 1;
    }
    return 0;
}

void Keep_Away(PLW* wk, s16 Target_Pos, s16 Option) {
    switch (CP_Index[wk->wu.id][3]) {

    case 0:
        if (Option == 0) {
            if (random_16_com() < 4) {
                Setup_KA_Jump(wk);
            } else {
                Setup_KA_Walk(wk);
            }
        } else {
            if (Option == 1) {
                Setup_KA_Jump(wk);
            } else {
                CP_Index[wk->wu.id][3] = Option + 1;
            }
        }
        /* fallthrough */

    case 1:
    case 2:
        Jump(wk, CP_Index[wk->wu.id][3] - 1);
        break;

    case 3:
    case 4:
        Approach_Walk(wk, Target_Pos, CP_Index[wk->wu.id][3] - 1);
        break;
    }
}

void Setup_KA_Jump(PLW* wk) {
    s16 xx;

    CP_Index[wk->wu.id][3] = 2;
    xx = Back_Jump_Data[wk->player_number];

    if (wk->wu.rl_waza) {
        xx = wk->wu.xyz[0].disp.pos - Back_Jump_Data[wk->player_number];
        if ((bg_w.bgw[1].l_limit2 - bg_w.pos_offset) > xx) {
            CP_Index[wk->wu.id][3] = 1;
        }
    } else {
        xx = wk->wu.xyz[0].disp.pos + Back_Jump_Data[wk->player_number];
        if ((bg_w.bgw[1].r_limit2 + bg_w.pos_offset) < xx) {
            CP_Index[wk->wu.id][3] = 1;
        }
    }
}

void Setup_KA_Walk(PLW* wk) {
    CP_Index[wk->wu.id][3] = 4;
}

void Search_Back_Term(PLW* wk, s16 Move_Value, s16 Next_Action, s16 Next_Menu) {
    if (wk->wu.rl_waza) {
        Move_Value = wk->wu.xyz[0].disp.pos - Move_Value;
        if ((bg_w.bgw[1].l_limit2 - bg_w.pos_offset) > Move_Value) {
            Next_Another_Menu(wk, Next_Action, Next_Menu);
        } else {
            CP_Index[wk->wu.id][0]++;
        }
    } else {
        Move_Value = wk->wu.xyz[0].disp.pos + Move_Value;
        if (((bg_w.bgw[1].r_limit2) + (bg_w.pos_offset)) < (Move_Value)) {
            Next_Another_Menu(wk, Next_Action, Next_Menu);
        } else {
            CP_Index[wk->wu.id][0]++;
        }
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}

void Approach_Walk(PLW* wk, s16 Target_Pos, s16 Option) {
    s16 xx;

    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Timer_00[wk->wu.id] = 0x78;
        /* fallthrough */

    case 1:
        xx = Standing_Timer[wk->wu.id];

        if (Lie_Flag[wk->wu.id] == 0) {
            if (Check_Passive(wk) != 0) {
                break;
            }
        }
        Standing_Timer[wk->wu.id] = xx;

        if (--Timer_00[wk->wu.id] == 0) {
            Next_Be_Free(wk);
        }

        else if (Check_Arrival(wk, Target_Pos, Option) != 0) {
            Disposal_Again[wk->wu.id] = 1;
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;

            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;

            if (CP_No[wk->wu.id][0] != 6) {
                Passive_Flag[wk->wu.id] = 0;
            }
        } else {
            Ck_Distance_Lv(wk);
            if (Option == 3) {
                Lever_Buff[wk->wu.id] ^= 0xC;
            }
        }
    }
}

s32 Check_Arrival(PLW* wk, s16 Target_Pos, s16 Option) {
    if (Option == 3) {
        if (Target_Pos <= PL_Distance[wk->wu.id]) {
            return 1;
        }
        return wk->micchaku_flag;
    }

    if (wk->hos_em_flag) {
        return 1;
    }
    if (Target_Pos >= PL_Distance[wk->wu.id]) {
        return 1;
    }

    return 0;
}

void Walk(PLW* wk, u16 Lever, s16 Time, s16 unused) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Timer_00[wk->wu.id] = Time;
        Timer_01[wk->wu.id] = wk->wu.rl_flag;
        Free_Lever[wk->wu.id] = Setup_Guard_Lever(wk, Lever);
        /* fallthrough */

    case 1:
        if (Lie_Flag[wk->wu.id] == 0) {
            if (Check_Passive(wk) != 0) {
                break;
            }
        }

        if (--Timer_00[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;

            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;

            if (*CP_No[wk->wu.id] != 6) {
                Passive_Flag[wk->wu.id] = 0;
            }
        } else {
            if ((Timer_01[wk->wu.id] != (s16)wk->wu.rl_flag) || (wk->micchaku_flag != 0) || (wk->hos_em_flag != 0)) {
                Next_Be_Free(wk);
            }
            Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
        }
        break;
    }
}

void Forced_Guard(PLW* wk, s16 Guard_Type) {
    WORK* em;
    s16 xx;

    em = (WORK*)wk->wu.target_adrs;

    if (Attack_Flag[wk->wu.id] == 0) {
        Next_Be_Free(wk);
    }
    xx = Hit_Range_Data[em->hit_range];
    xx += Com_Width_Data[wk->wu.id];

    if (PL_Distance[wk->wu.id] > xx) {
        Next_Be_Free(wk);
    }

    Next_Be_Guard(wk, em, Guard_Type);
    Lever_Buff[wk->wu.id] |= Lever_Squat[wk->wu.id];
}

void Provoke(PLW* wk, s16 Lever) {
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (wk->spmv_ng_flag & 1) {
            Next_Be_Free(wk);
            break;
        }

        CP_Index[wk->wu.id][1]++;
        if (Lever != -1) {
            Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, Lever & 1);
            Lever_LR[wk->wu.id] |= Lever & 2;
        }
        /* fallthrough */
    case 1:

        if (wk->permited_koa & 0x80) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = 0x440;
        }
        break;

    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if ((wk->wu.routine_no[1] != 4) || (wk->wu.routine_no[2] != 0x1E)) {
            Reaction_Exit_Sub(wk);
        }
        break;
    }
}

void Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data) {
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (Lever_Data & 2) {
            Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, 1);
        } else {
            Lever_LR[wk->wu.id] = 0;
        }

        Lever_LR[wk->wu.id] |= Lever_Data & 2;
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) != 0) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
        /* fallthrough */

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = Lever_Data;
            Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
        } else {
            Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
        }
        break;

    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}

s32 Small_Jump_Measure(PLW* wk) {
    if (Lever_Squat[wk->wu.id] & 2) {
        return Setup_Guard_Lever(wk, 1);
    }
    return 0;
}

void Normal_Attack_SP(PLW* wk, s16 Reaction, u16 Lever_Data, s16 Time) {
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) != 0) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        Timer_00[wk->wu.id] = Time;
        Check_First_Menu(wk);
        /* fallthrough */

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            Lever_Buff[wk->wu.id] = Lever_Data;
            Lever_Squat[wk->wu.id] = Lever_Data & 2;
            CP_Index[wk->wu.id][1]++;
            Timer_00[wk->wu.id]--;
        } else {
            Lever_Buff[wk->wu.id] = Lever_Squat[wk->wu.id];
        }
        break;

    case 2:
        if (--Timer_00[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_Data;
            Lever_Squat[wk->wu.id] = Lever_Data & 2;
        } else {
            CP_Index[wk->wu.id][1]++;
        }
        break;

    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}

void Adjust_Attack(PLW* wk, s16 Reaction, u16 Lever_Data) {
    u16 xx;

    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) != 0) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
        /* fallthrough */

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            xx = Check_Squat(wk);
            Lever_Buff[wk->wu.id] = Lever_Data | xx;
            Lever_LR[wk->wu.id] = xx;
            Lever_Buff[wk->wu.id] |= Small_Jump_Measure(wk);
            CP_Index[wk->wu.id][1]++;
        } else {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            Lever_Buff[wk->wu.id] |= Small_Jump_Measure(wk);
        }
        break;

    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}

s32 Check_Squat(PLW* wk) {
    if (((WORK*)wk->wu.target_adrs)->pat_status == 0x20) {
        return 0;
    }

    return 2;
}

s32 Check_Start_Normal_Attack(PLW* wk, s16 Reaction, u16 Lever_Data) {
    if (((wk->wu.routine_no[1]) != 4) || ((wk->wu.cg_type) == 0x40)) {
        return 0;
    }

    if (wk->wu.cg_cancel & 4) {
        return 0;
    }

    if (wk->permited_koa & 0x10) {
        return 0;
    }

    if ((wk->wu.cg_cancel & 8) && (Reaction == 0xE)) {
        return 0;
    }

    return 1;
}

void Lever_Attack(PLW* wk, s16 Reaction, u16 Lever, u16 Lever_Data) {
    s16 xx;

    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Lever_Attack(wk, Lever, Lever_Data) != 0) {
            break;
        }
        dash_flag_clear(wk->wu.id);

        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
        /* falltrhough */

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id]) {
            break;
        }

        xx = Setup_Guard_Lever(wk, Lever);
        Lever_Buff[wk->wu.id] = (Lever_Data | xx);
        CP_Index[wk->wu.id][1]++;
        break;

    default:
        if (wk->wu.routine_no[1] == 2) {
            Be_Catch(wk);
        } else {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
            Reaction_Sub(wk, Reaction, 0);
        }
        break;
    }
}

void Lever_Attack_SP(PLW* wk, s16 Reaction, u16 Lever, u16 Lever_Data, s16 Time) {
    s16 xx;

    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Lever_Attack(wk, Lever, Lever_Data) != 0) {
            break;
        }
        dash_flag_clear(wk->wu.id);

        Timer_00[wk->wu.id] = Time;
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
        /* fallthrough */

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id]) {
            break;
        }

        xx = Setup_Guard_Lever(wk, Lever);
        Lever_Buff[wk->wu.id] = (Lever_Data | xx);

        Timer_00[wk->wu.id]--;
        CP_Index[wk->wu.id][1]++;
        break;

    case 2:
        if (--Timer_00[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_Data;
            Lever_Squat[wk->wu.id] = Lever_Data & 2;
        } else {
            CP_Index[wk->wu.id][1]++;
        }
        break;

    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}

s32 Setup_Guard_Lever(PLW* wk, u16 Lever) {
    s32 rnum = 0;

    switch (Lever) {
    case 0:
        if (wk->wu.rl_waza == 0) {
            rnum = 4;
        } else {
            rnum = 8;
        }
        break;
    case 1:
        if (wk->wu.rl_waza == 1) {
            rnum = 4;
        } else {
            rnum = 8;
        }
        break;
    }
    return rnum;
}

s32 Check_Start_Lever_Attack(PLW* wk, u16 Lever, u16 Lever_Data) {
    if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
        return 0;
    }

    if (wk->wu.cg_cancel & 4) {
        return 0;
    }

    if (wk->wu.cg_cancel & 8) {
        return 0;
    }

    return 1;
}

void SA_Term(PLW* wk, u16 SA0, u16 SA1, u16 SA2, u16 Term_No) {
    s16 xx[3];

    if (((Passive_Flag[wk->wu.id]) == 0) && (Check_Passive(wk) != 0)) {
        return;
    }

    xx[0] = SA0;
    xx[1] = SA1;
    xx[2] = SA2;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

    if ((xx[plw[wk->wu.id].sa->kind_of_arts] == -1) || plw[wk->wu.id].metamorphose) {
        CP_Index[wk->wu.id][0]++;
    }

    else if ((plw[wk->wu.id].sa->ok) || (plw[wk->wu.id].sa->mp)) {
        Disposal_Again[wk->wu.id] = 1;
        // Term_No is unsigned however
        if ((Term_No != -1) || (Term_No != 0)) {
            switch (wk->player_number) {

            case 2:
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                DENJIN_Check(wk, SA2, (u16*)&xx[2], Term_No);
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;

            case 11:
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;

            case 1:
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;

            case 5:
                if (((WORK*)wk->wu.target_adrs)->xyz[1].disp.pos >= 0x10) {
                    CP_Index[wk->wu.id][0]++;
                    return;
                }
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;

            case 6:
                if (SA_Range_Check(wk, 0, Term_No) != 0) {
                    return;
                }
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;

            case 8:
                if ((plw[wk->wu.id].sa->kind_of_arts == 2) && (plw[wk->wu.id].wu.vital_new <= (Max_vitality / 2))) {
                    break;
                }
                CP_Index[wk->wu.id][0]++;
                return;

            case 9:
                YAGYOU_Check(wk, &xx[1], Term_No);
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;

            case 14:
                if (SA_Range_Check(wk, 1, Term_No) != 0) {
                    return;
                }
                if (SA_Range_Check(wk, 2, Term_No) != 0) {
                    return;
                }
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;

            default:
                Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
                return;
            }
        }

        Next_Another_Menu(wk, 2, xx[plw[wk->wu.id].sa->kind_of_arts]);
    } else {
        CP_Index[wk->wu.id][0]++;
    }
}

s32 DENJIN_Check(PLW* wk, u16 SA2, u16* xx, u16 Term_No) {
    if (plw[wk->wu.id].sa->kind_of_arts != 2) {
        return 0;
    }

    DENJIN_No[wk->wu.id] = Term_No;
    DENJIN_Term[wk->wu.id] = SA2;
    xx[0] = 0x37;
    return 1;
}

s32 YAGYOU_Check(PLW* wk, s16* xx, u16 Term_No) {
    if (plw[wk->wu.id].sa->kind_of_arts != 1) {
        return 0;
    }

    if (Term_No == 0) {
        Term_No = YAGYOU_Data[random_16_com()];
        Term_No += 0x64;
    }
    xx[0] = Term_No;
    return 1;
}

s32 SA_Range_Check(PLW* wk, s16 SA_No, u16 Range) {
    if (SA_No != plw[wk->wu.id].sa->kind_of_arts) {
        return 0;
    }

    if (Range & 0x8000) {
        if ((PL_Distance[wk->wu.id]) < (Range & 0x7FFF)) {
            CP_Index[wk->wu.id][0]++;
            return 1;
        }

    }

    else if (PL_Distance[wk->wu.id] > Range) {
        CP_Index[wk->wu.id][0]++;
        return 1;
    }

    return 0;
}

void Check_SA(PLW* wk, s16 Next_Action, s16 Next_Menu) {
    if (plw[wk->wu.id].sa->ok) {
        CP_Index[wk->wu.id][0]++;
    } else {
        CP_No[wk->wu.id][0] = Next_Action;
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}

void Check_EX(PLW* wk, s16 Next_Action, s16 Next_Menu) {
    if (plw[wk->wu.id].sa->ex) {
        CP_Index[wk->wu.id][0]++;
    } else {
        CP_No[wk->wu.id][0] = Next_Action;
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}

void Check_SA_Full(PLW* wk, s16 Next_Action, s16 Next_Menu) {
    Disposal_Again[wk->wu.id] = 1;

    if (wk->permited_koa & 0x40) {
        CP_Index[wk->wu.id][0]++;
    } else {
        CP_No[wk->wu.id][0] = Next_Action;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}

void Branch_Unit_Area(PLW* wk, s16 Next_Action, s16 Menu_00, s16 Menu_01, s16 Menu_02, s16 Menu_03) {
    s16 xx[4];

    CP_No[wk->wu.id][0] = Next_Action;
    xx[0] = Menu_00;
    xx[1] = Menu_01;
    xx[2] = Menu_02;
    xx[3] = Menu_03;

    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    Disposal_Again[wk->wu.id] = 1;
    Next_Another_Menu(wk, Next_Action, xx[Area_Number[wk->wu.id]]);
}

void Com_Random_Select(PLW* wk, s16 Next_Action, s16 Menu_00, s16 Menu_01, s16 Menu_02, s16 Menu_03, s16 Rnd_Type) {
    s16 xx[4];
    s16 zz;

    zz = Com_Rnd_Select_Data[Rnd_Type][random_16_com()];

    xx[0] = Menu_00;
    xx[1] = Menu_01;
    xx[2] = Menu_02;
    xx[3] = Menu_03;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

    if (xx[zz] == 0xFF) {
        Next_End(wk);
    } else {
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, xx[zz]);
    }
}

void Branch_Wait_Area(PLW* wk, s16 Time_00, s16 Time_01, s16 Time_02, s16 Time_03) {
    s16 xx[4];

    switch (CP_Index[wk->wu.id][1]) {
    case 0:

        CP_Index[wk->wu.id][1]++;

        xx[0] = Time_00;
        xx[1] = Time_01;
        xx[2] = Time_02;
        xx[3] = Time_03;
        Timer_00[wk->wu.id] = xx[Area_Number[wk->wu.id]];
        break;

    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;

        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;

        if (CP_No[wk->wu.id][0] != 6) {
            Passive_Flag[wk->wu.id] = 0;
        }
        break;
    }
}

void Wait(PLW* wk, s16 Time) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        CP_Index[wk->wu.id][1]++;

        if (Time == 0) {
            Timer_00[wk->wu.id] = Setup_WT_Data(wk);
        } else {
            Timer_00[wk->wu.id] = Time;
        }

        break;

    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;

        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;

        if (CP_No[wk->wu.id][0] != 6) {
            Passive_Flag[wk->wu.id] = 0;
        }
        break;
    }
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
}

void Look(PLW* wk, s16 Time) {
    Passive_Flag[wk->wu.id] = 0;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;

        if (Time == 0) {
            Timer_00[wk->wu.id] = Setup_LP_Data(wk);
        } else {
            Timer_00[wk->wu.id] = Time;
        }

        if (Lever_LR[wk->wu.id] & 2) {
            Timer_00[wk->wu.id] += 0x32;
        }

        break;

    default:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }

        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;

        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
        Before_Look[wk->wu.id] = 1;
        break;
    }
}

void Wait_Lie(PLW* wk, u16 Lever_Data) {
    WORK* em;

    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Rolling_Flag[wk->wu.id] = 0;

        if (Lever_Data != 0) {
            Free_Lever[wk->wu.id] = Setup_Guard_Lever(wk, 1);
            Free_Lever[wk->wu.id] |= Lever_Data & 2;
        } else {
            Free_Lever[wk->wu.id] = 0;
        }
        /* fallthrough */

    default:
        Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];

        em = (WORK*)wk->wu.target_adrs;
        if ((Check_Blow_Off(wk, em, 0) == 0) || (Lie_Flag[wk->wu.id] != 0)) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;

            Flip_Flag[wk->wu.id] = 0;

            Limited_Flag[wk->wu.id] = 0;
        }
        break;
    }
}

void Wait_Get_Up(PLW* wk, u16 Lever_Data, s16 Option) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Rolling_Flag[wk->wu.id] = 0;

        if (Lever_Data != 0) {
            Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, 1);
            Lever_LR[wk->wu.id] |= Lever_Data & 2;
        } else {
            Lever_LR[wk->wu.id] = 0;
        }

        /* fallthrough */

    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

        if (Check_Wait_Term(wk, Option) != 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;

            Disposal_Again[wk->wu.id] = 1;
            Passive_Flag[wk->wu.id] = 1;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
        }
        break;
    }
}

s32 Check_Wait_Term(PLW* wk, s16 Option) {
    WORK* em;

    em = (WORK*)wk->wu.target_adrs;

    if ((em->routine_no[1] == 1) && (em->pat_status == 0x18)) {
        return 0;
    }
    if (Lie_Flag[wk->wu.id] == 0) {
        return 1;
    }
    if (Option != 0) {
        return 0;
    }
    if (em->cg_type == 0xB) {
        return 1;
    }
    return 0;
}

void Wait_Attack_Complete(PLW* wk, u16 Lever_Data, s16 Option) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);

        if (Lever_Data != 0) {
            Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, 1);
            Lever_LR[wk->wu.id] |= Lever_Data & 2;
            Guard_Flag[wk->wu.id] = 1;
        } else {
            Lever_LR[wk->wu.id] = 0;
        }

        /* fallthrough */

    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

        if (Check_Exit_Guard(wk, Option) == 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Guard_Flag[wk->wu.id] = 0;

            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            if (Option == 0) {
                Passive_Flag[wk->wu.id] = 0;
            }
        }
        break;
    }
}

s32 Check_Exit_Guard(PLW* wk, s16 Option) {
    WORK* em;

    if (wk->wu.routine_no[1] == 1) {
        return 1;
    }

    if (Option == 0) {
        em = (WORK*)wk->wu.target_adrs;
        if (em->routine_no[1] != 4) {
            return 0;
        }
        return 1;
    }
    return Attack_Flag[wk->wu.id];
}

void EM_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Exit_Number, s16 Next_Action, s16 Next_Menu) {
    WORK* em;

    em = (WORK*)wk->wu.target_adrs;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        Term_No[wk->wu.id] = 0;
        /* fallthrough */

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }

        switch (Check_Exit_Term(wk, em, Exit_Number)) {
        case 0:
            if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], Range_X) == 0) {
                break;
            }

            if (Exit_Number != 8) {
                if (Check_Term_Sub_Y(wk, em->xyz[1].disp.pos, Range_Y) == 0) {
                    break;
                }
            } else {
                if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
                    break;
                }
            }

            Disposal_Again[wk->wu.id] = 1;
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;

            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
            break;

        case 1:
            Disposal_Again[wk->wu.id] = 1;
            Next_Another_Menu(wk, Next_Action, Next_Menu);
            break;

        case 2:
            break;

        case 3:
            Select_Passive(wk);
            break;

        default:
            Counter_Attack[wk->wu.id] = 1;
            Select_Passive(wk);
            break;
        }

        break;
    }
}

void SHELL_Term(PLW* wk, s16 Next_Command, s16 Exit_Number, s16 Next_Action, s16 Next_Menu, s16 unused) {
    WORK* em;
    WORK_Other* tmw;
    s16 xx;

    em = (WORK*)Shell_Address[wk->wu.id];
    tmw = (WORK_Other*)Shell_Address[wk->wu.id];

    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        CP_Index[wk->wu.id][1]++;
        Term_No[wk->wu.id] = 0;
        /* fallthrough */

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (Check_Exit_Term(wk, em, Exit_Number) == 1) {
            Next_Another_Menu(wk, Next_Action, Next_Menu);
        } else {
            xx = Compute_Hit_Time(wk, tmw);
            if (xx < Shell_Dodge_Data[Next_Command][wk->player_number]) {
                Disposal_Again[wk->wu.id] = 1;
                CP_Index[wk->wu.id][0]++;
                CP_Index[wk->wu.id][1] = 0;
                CP_Index[wk->wu.id][2] = 0;
                CP_Index[wk->wu.id][3] = 0;

                Flip_Flag[wk->wu.id] = 0;
                Limited_Flag[wk->wu.id] = 0;
            }
        }
        break;
    }
}

s32 Check_Term_Sub_Air(PLW* wk, s16 Distance, s16 Range) {
    if (Range == -1) {
        return 1;
    }
    if (!(Range & 0x8000)) {
        if (Distance >= Range) {
            return 1;
        }
        return 0;
    } else {
        Range += Correct_Unit_PL(wk);

        if (Distance <= (Range & 0x7FFF)) {
            return 1;
        }
        return 0;
    }
}

s32 Check_Term_Sub(PLW* wk, s16 Distance, s16 Range) {
    if (Range == -1) {
        return 1;
    }
    if (!(Range & 0x8000)) {
        if (Distance >= Range) {
            return 1;
        }
        return 0;
    } else {
        if (Distance <= (Range & 0x7FFF)) {
            return 1;
        }
        return 0;
    }
}

s32 Correct_Unit_PL(PLW* wk) {
    return Correct_VS_Air_Data[My_char[Player_id]];
}

s32 Check_Term_Sub_Y(PLW* wk, s16 Distance, s16 Range) {
    WORK* em;

    if (Range == -1) {
        return 1;
    }

    em = (WORK*)wk->wu.target_adrs;
    if (!(Range & 0x8000)) {
        if (Distance >= Range) {
            return 1;
        }
        return 0;
    } else {
        if (em->mvxy.a[1].real.h > 0) {
            return 0;
        }
        if (Distance <= (Range & 0x7FFF)) {
            return 1;
        }
        return 0;
    }
}

void Jump(PLW* wk, s16 Jump_Dir) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }

        if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            CP_Index[wk->wu.id][1]++;
            hi_jump_flag_clear(wk->wu.id);
            Check_First_Menu(wk);
        }

        break;

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        Jump_Init(wk, Jump_Dir);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }

        break;

    case 2:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];

        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            Check_Air_Guard(wk);
        }
        break;

    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (wk->wu.xyz[1].disp.pos) {
            break;
        }

        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        break;
    }
}

void Hi_Jump(PLW* wk, s16 Pl_Number, s16 Jump_Dir) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }

        if (Check_Start_Hi_Jump(wk) == 0) {
            CP_Index[wk->wu.id][1]++;
            if (cmd_sel[wk->wu.id]) {
                Tech_Address[wk->wu.id] = player_CMD[Pl_Number][2];
            } else {
                Tech_Address[wk->wu.id] = player_cmd[Pl_Number][2];
            }
            Check_First_Menu(wk);
        }

        break;

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        Tech_Index[wk->wu.id] = 0xC;

        Jump_Init(wk, Jump_Dir);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }

        Lever_Buff[wk->wu.id] = 0;

        break;

    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (Command_Type_00(wk, 8, 0xFFFF, -1) == -1) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
            break;
        }

        if (!(Lever_Buff[wk->wu.id] & 2)) {
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
        }
        break;

    case 3:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            Check_Air_Guard(wk);
        }
        break;

    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Check_Air_Guard(wk);

        if (wk->wu.xyz[1].disp.pos) {
            break;
        }
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        break;
    }
}

s32 Check_Start_Hi_Jump(PLW* wk) {
    if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
        return 0;
    }

    if (wk->wu.cg_cancel & 4) {
        return 0;
    }

    if (wk->wu.cg_cancel & 1) {
        return 0;
    }

    return 1;
}

s32 Check_Air_Guard(PLW* wk) {
    WORK* em;
    s16 xx;
    s16 zz;

    em = (WORK*)wk->wu.target_adrs;

    if (Lever_LR[wk->wu.id]) {
        return Lever_LR[wk->wu.id];
    }
    if (Guard_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
        return Lever_LR[wk->wu.id];
    }
    if (Attack_Flag[wk->wu.id] == 0) {
        return Lever_LR[wk->wu.id];
    }

    xx = Hit_Range_Data[em->hit_range] + 0x20;
    xx += Com_Width_Data[wk->wu.id];
    if (PL_Distance[wk->wu.id] > xx) {
        return 0;
    }

    Guard_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
    Lv = Setup_Lv10(0);
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }

    Rnd = random_16_com();
    Lv += CC_Value[0];

    if (Lv >= 7) {
        Lv = 0xA;
    }

    Lv = emLevelRemake(Lv, 0xB, 1);

    zz = Setup_EM_Rank_Index(wk);

    if (Guard_Data[zz][Lv][Rnd] == 3) {
        return Lever_LR[wk->wu.id] = 0;
    }
    Guard_Type[wk->wu.id] = Guard_Data[zz][Lv][random_16_ex_com()];

    Lever_LR[wk->wu.id] = Setup_Guard_Lever(wk, 1);
    Lever_LR[wk->wu.id] |= 2;
    return Guard_Type[wk->wu.id] |= 0x8000;
}

void Jump_Attack(PLW* wk, s16 Reaction, s16 Time_Data, u16 Lever_Data, s16 Jump_Dir) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }

        if ((wk->wu.routine_no[1] == 4) && (wk->wu.cg_type != 0x40)) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        Timer_00[wk->wu.id] = Time_Data;
        Continue_Menu[wk->wu.id] = 0;
        wk->wu.hf.hit.player = 0;
        hi_jump_flag_clear(wk->wu.id);
        Check_First_Menu(wk);
        /* fallthrough */

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }

        Timer_00[wk->wu.id] = Time_Data;
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Jump_Init(wk, Jump_Dir);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }

        break;

    case 2:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }

        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        }

        break;

    case 3:
        Check_Air_Guard(wk);

        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }

        Lever_Data = Check_SP_Jump_Attack(wk, Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;

        break;

    default:
        Check_Air_Guard(wk);
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 3) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}

void Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX,
                      s16 Range_JY, s16 J_Lever_Data) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);

        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }
        if ((wk->wu.routine_no[1] == 4) && (wk->wu.cg_type != 0x40)) {
            break;
        }

        hi_jump_flag_clear(wk->wu.id);
        Continue_Menu[wk->wu.id] = 0;

        wk->wu.hf.hit.player = 0;
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
        /* Fallthrough */

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);

        Jump_Init(wk, Jump_Dir);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }

        break;

    case 2:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        } else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        }
        break;

    case 3:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        if (Check_VS_Air_Attack(wk, Range_JX, Range_JY, J_Lever_Data) != 0) {
            break;
        }
        Check_Term_ABS_Distance(wk);

        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], Range_X) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }

        Lever_Data = Check_SP_Jump_Attack(wk, Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;

        CP_Index[wk->wu.id][1]++;
        Stock_Hit_Flag[wk->wu.id] = 0;
        break;

    case 4:
        Check_Air_Guard(wk);
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0x7F);
        break;

    case 5:
        if (Check_Landed(wk, Reaction & 0x7F) == 0) {
            switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
            default:
            case 1:
            case 10:
                if (Command_Type_00(wk, 8, 0xFFFF, -1) == -1) {
                    CP_Index[wk->wu.id][1] = 0x63;
                }
            }
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 3) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}

s32 Check_SP_Jump_Attack(PLW* wk, s16 Lever_Data) {
    u16 xx;

    if (!(Lever_Data & 0x8000)) {
        return Lever_Data;
    }

    xx = Setup_Guard_Lever(wk, 0);
    xx |= Lever_Data & 0x7FFF;
    return xx | 2;
}

s32 Check_VS_Air_Attack(PLW* wk, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data) {
    WORK* em;

    if ((Range_JX == -1) && (Range_JY == -1)) {
        return 0;
    }
    if (J_Lever_Data == -1) {
        return 0;
    }

    em = (WORK*)wk->wu.target_adrs;
    if ((em->pat_status != 0xE) && (em->pat_status != 0x14) && (em->pat_status != 0x1A) && (em->xyz[1].disp.pos <= 0)) {
        return 0;
    }

    if (Check_Term_Sub_Air(wk, PL_Distance[wk->wu.id], Range_JX) == 0) {
        return 0;
    }
    if (Check_Term_Sub(wk, Ck_Distance_Height(wk), Range_JY) != 0) {
        switch (CP_Index[wk->wu.id][2]) {
        case 0:
            CP_Index[wk->wu.id][2]++;
            Timer_01[wk->wu.id] = Select_Reflection_Time(wk);
            Timer_01[wk->wu.id]++;
            break;
        default:
            if (--Timer_01[wk->wu.id] != 0) {
                break;
            }

            if (J_Lever_Data & 0x4000) {
                CP_Index[wk->wu.id][1] += 2;
                if (cmd_sel[wk->wu.id]) {
                    Tech_Address[wk->wu.id] = player_CMD[wk->player_number][J_Lever_Data & 0x3FFF];
                } else {
                    Tech_Address[wk->wu.id] = player_cmd[wk->player_number][J_Lever_Data & 0x3FFF];
                }
                Continue_Menu[wk->wu.id] = 1;
                return -1;
            }

            Lever_Buff[wk->wu.id] = J_Lever_Data;
            CP_Index[wk->wu.id][1]++;
            Continue_Menu[wk->wu.id] = 1;
            return 1;
        }
    }

    return 0;
}

void Hi_Jump_Attack(PLW* wk, s16 Reaction, s16 Time_Data, u16 Lever_Data, s16 Jump_Dir) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }
        if (Check_Start_Hi_Jump(wk) == 0) {
            Continue_Menu[wk->wu.id] = 0;
            wk->wu.hf.hit.player = 0;
            CP_Index[wk->wu.id][1]++;
            if (cmd_sel[wk->wu.id]) {
                Tech_Address[wk->wu.id] = player_CMD[wk->player_number][2];
            } else {
                Tech_Address[wk->wu.id] = player_cmd[wk->player_number][2];
            }
            Timer_00[wk->wu.id] = Time_Data;
            Check_First_Menu(wk);
        }

        break;

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        Tech_Index[wk->wu.id] = 0xC;

        dash_flag_clear(wk->wu.id);
        Jump_Init(wk, Jump_Dir);
        Lever_Pool[wk->wu.id] &= 0xC;
        Lever_Buff[wk->wu.id] = 0;
        Check_Air_Guard(wk);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }

        break;

    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (Command_Type_00(wk, 8, 0xFFFF, -1) == -1) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
            break;
        }

        if (Lever_Buff[wk->wu.id] & 2) {
            return;
        }
        Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];

        break;

    case 3:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }

        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id] | 1;
        }

        break;

    case 4:
        Check_Air_Guard(wk);

        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }

        Lever_Data = Check_SP_Jump_Attack(wk, Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1] += 2;
        if (Reaction & 0x80) {
            CP_Index[wk->wu.id][1]++;
        }

        break;

    case 6:
        Check_Air_Guard(wk);
        if (Attack_Flag[wk->wu.id]) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        if (wk->wu.hf.hit.player == 0) {
            break;
        }

        if (!(wk->wu.cg_cancel & 8)) {
            break;
        }

        Lever_Buff[wk->wu.id] = Get_Meoshi_Data(wk);

        break;

    default:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 4) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}

void Hi_Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX,
                         s16 Range_JY, u16 J_Lever_Data) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }
        if (Check_Start_Hi_Jump(wk) != 0) {
            break;
        }

        Continue_Menu[wk->wu.id] = 0;
        wk->wu.hf.hit.player = 0;
        CP_Index[wk->wu.id][1]++;
        if (cmd_sel[wk->wu.id]) {
            Tech_Address[wk->wu.id] = player_CMD[wk->player_number][2];
        } else {
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][2];
        }
        Check_First_Menu(wk);

        break;

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        Tech_Index[wk->wu.id] = 0xC;

        dash_flag_clear(wk->wu.id);
        Jump_Init(wk, Jump_Dir);
        Lever_Pool[wk->wu.id] &= 0xC;
        Lever_Buff[wk->wu.id] = 0;
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }

        break;

    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (Command_Type_00(wk, 8, 0xFFFF, -1) == -1) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
        } else {
            if (Lever_Buff[wk->wu.id] & 2) {
                return;
            }
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
        }
        break;

    case 3:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }

        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id] | 1;
        }

        break;

    case 4:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        if (Check_VS_Air_Attack(wk, Range_JX, Range_JY, J_Lever_Data) != 0) {
            break;
        }

        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], Range_X) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }

        Lever_Data = Check_SP_Jump_Attack(wk, Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        if (Reaction & 0x80) {
            CP_Index[wk->wu.id][1] = 8;
        }
        break;

    case 5:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;

    case 6:
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:

            if (Command_Type_00(wk, 8, 0xFFFF, -1) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
        }

        break;

    case 7:
        if (--Combo_Speed[wk->wu.id]) {
            break;
        }
        Lever_Buff[wk->wu.id] = Tech_Address[wk->wu.id][8];
        CP_Index[wk->wu.id][1]++;
        break;

    case 8:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;

    default:
        if (Attack_Flag[wk->wu.id]) {
            break;
        }

        CP_Index[wk->wu.id][1] = 8;
        if (wk->wu.hf.hit.player == 0) {
            break;
        }

        if (wk->wu.cg_cancel & 8) {
            Lever_Buff[wk->wu.id] = Get_Meoshi_Data(wk);
        }
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 4) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}

s32 Check_Com_Add_Y(PLW* wk, s16 Pos_Y, s16 Range) {
    if (Range == -1) {
        return 1;
    }
    if (!(Range & 0x8000)) {
        if (Pos_Y >= Range) {
            return 1;
        }
        return 0;
    } else {
        if (wk->wu.mvxy.a[1].real.h >= 0) {
            return 0;
        }
        if (Pos_Y <= (Range & 0x7FFF)) {
            return 1;
        }
        return 0;
    }
}

void ORO_JA_Term(PLW* wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Lever_Data, s16 RJX,
                 s16 RJY, u16 JLD) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }

        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);

        if ((wk->wu.routine_no[1] == 4) && (wk->wu.cg_type != 0x40)) {
            break;
        }

        hi_jump_flag_clear(wk->wu.id);
        Continue_Menu[wk->wu.id] = 0;

        wk->wu.hf.hit.player = 0;
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
        /* fallthrough */

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);

        Jump_Init(wk, Jump_Dir);
        Check_Air_Guard(wk);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }

        break;

    case 2:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        } else {

            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Timer_00[wk->wu.id] = 2;
        }
        break;

    case 3:
        Check_Air_Guard(wk);

        if (Lever_Data != 0xFFFF) {
            if (Check_Landed(wk, Reaction) != 0) {
                break;
            }
            if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
                break;
            }
            if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, JY) == 0) {
                break;
            }
        }
        if ((wk->air_jump_ok_time == 0) && (wk->wu.position_y >= 0x30)) {
            Jump_Init(wk, Jump_Dir2);

            if ((Lever_Data) == 0xFFFF) {
                CP_Index[wk->wu.id][1] += 2;
            } else {
                CP_Index[wk->wu.id][1]++;
            }
        }

        break;

    case 4:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }

        Lever_Buff[wk->wu.id] = Lever_Data;

        CP_Index[wk->wu.id][1]++;
        Stock_Hit_Flag[wk->wu.id] = 0;
        break;

    case 5:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0x7F);
        break;

    case 6:
        if (Check_Landed(wk, Reaction & 0x7F) != 0) {
            break;
        }

        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, 8, 0xFFFF, -1) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
        }

        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 3) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}

void ORO_HJA_Term(PLW* wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Lever_Data, s16 RJX,
                  s16 RJY, u16 JLD) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }
        if (Check_Start_Hi_Jump(wk) == 0) {
            Continue_Menu[wk->wu.id] = 0;
            CP_Index[wk->wu.id][1]++;
            if (cmd_sel[wk->wu.id]) {
                Tech_Address[wk->wu.id] = player_CMD[wk->player_number][2];
            } else {
                Tech_Address[wk->wu.id] = player_cmd[wk->player_number][2];
            }
            Check_First_Menu(wk);
        }
        break;

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id == 0]) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;

            Jump_Init(wk, Jump_Dir);
            Lever_Pool[wk->wu.id] &= 0xC;
            Lever_Buff[wk->wu.id] = 0;
            Check_Air_Guard(wk);
            if (Check_Diagonal_Shell(wk) != 0) {
                Next_Be_Free(wk);
            }
        }
        break;

    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Lever_Buff[wk->wu.id] = 2;
        Lever_Pool[wk->wu.id] |= 1;
        break;

    case 3:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        } else {

            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Timer_00[wk->wu.id] = 2;
        }
        break;

    case 4:
        Check_Air_Guard(wk);

        if (Lever_Data != 0xFFFF) {
            if (Check_Landed(wk, Reaction) != 0) {
                break;
            }
            if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
                break;
            }
            if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, JY) == 0) {
                break;
            }
        }
        if ((wk->air_jump_ok_time == 0) && (wk->wu.position_y >= 0x30)) {
            Jump_Init(wk, Jump_Dir2);

            if ((Lever_Data) == 0xFFFF) {
                CP_Index[wk->wu.id][1] += 2;
            } else {
                CP_Index[wk->wu.id][1]++;
            }
        }

        break;

    case 5:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }

        Lever_Buff[wk->wu.id] = Lever_Data;

        CP_Index[wk->wu.id][1]++;
        Stock_Hit_Flag[wk->wu.id] = 0;
        break;

    case 6:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0x7F);
        break;

    case 7:
        if (Check_Landed(wk, Reaction & 0x7F) != 0) {
            break;
        }

        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, 8, 0xFFFF, -1) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
        }

        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 3) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}

void Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        dash_flag_clear(wk->wu.id);
        if (cmd_sel[wk->wu.id]) {
            Tech_Address[wk->wu.id] = player_CMD[wk->player_number][Tech_Number & 0xFF];
        } else {
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
        }
        Tech_Index[wk->wu.id] = 0xC;
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

        if (Check_Start_Command_Attack(wk, Reaction, Tech_Number & 0x80FF) != 0) {
            break;
        }
        if (Check_Dash_Hit(wk, Tech_Number & 0x80FF) != 0) {
            Next_Be_Free(wk);
        }

        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);

        if (Power_Level & 0x4000) {
            Free_Lever[wk->wu.id] = Power_Lv_Data[(Power_Level & 0xF) - 8];
        } else {
            Free_Lever[wk->wu.id] = 0;
        }
        /* Fallthrough */

    case 1:
        if (--Combo_Speed[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            break;
        }

        if (Hadou_Check(wk, Tech_Number & 0x80FF) != 0) {
            if (Check_Passive(wk) == 0) {
                Combo_Speed[wk->wu.id] = 1;
            }
            break;
        } else {
            CP_Index[wk->wu.id][1]++;
            Check_Rapid(wk, Tech_Number);
        }
        /* Fallthrough */
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {

        default:
        case 1:

            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                if ((Tech_Number & 0xF) == 0 || (Tech_Number & 0xF) == 1) {
                    if (Reaction == 0xC) {
                        CP_Index[wk->wu.id][1] = 0x63;
                        Timer_00[wk->wu.id] = Dash_Time_Data[wk->player_number][Tech_Number];
                    } else {
                        CP_Index[wk->wu.id][1] = 4;
                    }
                } else {
                    CP_Index[wk->wu.id][1] = 3;
                }
            }
            break;

        case 2:
            if (Command_Type_01(wk, Power_Level & 0xF, Ex_Shot) != 0) {
                CP_Index[wk->wu.id][1]++;
            }
            break;

        case 7:
            if (Command_Type_06(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) != 0) {
                CP_Index[wk->wu.id][1]++;
            }
            break;
        }
        break;

    case 3:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (plw[wk->wu.id].tsukami_f) {
            break;
        }
        if (((wk->wu.cg_type) == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        } else {
            Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
            Rapid_Sub(wk);
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
            Reaction_Sub(wk, Reaction, Power_Level);
        }
        break;

    case 4:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (((wk->wu.cg_type) == 0x40) || (wk->running_f == 0)) {
            Reaction_Exit_Sub(wk);
        }
        break;

    case 5:
        if (PL_Distance[wk->wu.id] > 0x70) {
            Lever_Buff[wk->wu.id] = 0x40;
        }
        if (((wk->wu.cg_type) == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        }
        break;

    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (--Timer_00[wk->wu.id] == 0) {
            Reaction_Exit_Sub(wk);
        }
        break;
    }
}

s32 Hadou_Check(PLW* wk, u16 Tech_Number) {
    if (Hadou_Check_Data[wk->player_number][0] == 0) {
        return 0;
    }

    if (Tech_Number != Hadou_Check_Data[wk->player_number][1]) {
        return 0;
    }

    return Check_Resume_Lever(wk);
}

s32 Check_Resume_Lever(PLW* wk) {
    u16 Target_Lever;
    s16 xx;

    if (wk->wu.rl_waza) {
        Target_Lever = 8;
    } else {
        Target_Lever = 4;
    }

    for (xx = 0; xx <= 8; xx++) {
        if (Target_Lever == Resume_Lever[wk->wu.id][xx]) {
            return 1;
        }
    }
    return 0;
}

void J_Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }

        dash_flag_clear(wk->wu.id);

        if (cmd_sel[wk->wu.id]) {
            Tech_Address[wk->wu.id] = player_CMD[wk->player_number][Tech_Number & 0xFF];
        } else {
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
        }

        Tech_Index[wk->wu.id] = 0xC;
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

        if (Check_Start_Command_Attack(wk, Reaction, Tech_Number & 0x80FF) != 0) {
            break;
        }
        if (Check_Dash_Hit(wk, Tech_Number & 0x80FF) != 0) {
            Next_Be_Free(wk);
        }

        Continue_Menu[wk->wu.id] = 0;
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
        /* Fallthough */

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (--Combo_Speed[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            break;
        }
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
            break;
        }
        CP_Index[wk->wu.id][1]++;
        /* Fallthough */
    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {

        case 2:
            if (Command_Type_01(wk, Power_Level & 0xF, Ex_Shot) != 0) {
                CP_Index[wk->wu.id][1]++;
            }
            break;

        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;

    case 3:
        Check_Rapid(wk, Tech_Number);
        CP_Index[wk->wu.id][1]++;
        return;

    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        if ((wk->wu.cg_type == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        } else {
            Rapid_Sub(wk);
            if (Reaction == 0xC) {
                Reaction_Sub(wk, Reaction, Power_Level);
                break;
            }
            Check_Landed(wk, Reaction & 0xFFF);
        }
        break;
    }
}

void Rapid_Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Shot, u16 Time) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        dash_flag_clear(wk->wu.id);
        if (cmd_sel[wk->wu.id]) {
            Tech_Address[wk->wu.id] = player_CMD[wk->player_number][Tech_Number & 0xFF];
        } else {
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
        }
        Tech_Index[wk->wu.id] = 0xC;
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];

        if (Check_Start_Command_Attack(wk, Reaction, Tech_Number & 0x80FF) != 0) {
            break;
        }
        if (Check_Dash_Hit(wk, Tech_Number & 0x80FF) != 0) {
            Next_Be_Free(wk);
        }

        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
        Free_Lever[wk->wu.id] = 0;
        /* Fallthough */

    case 1:
        if (--Combo_Speed[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            break;
        }
        CP_Index[wk->wu.id][1]++;

        Rapid_No[wk->wu.id][0] = 0;
        Rapid_No[wk->wu.id][1] = 0;
        Timer_00[wk->wu.id] = Time;

    case 2:
        switch (Rapid_No[wk->wu.id][0]) {

        case 0:
            Rapid_No[wk->wu.id][0] = 1;
            Lever_Buff[wk->wu.id] = Shot;
            break;
        case 1:
            Rapid_No[wk->wu.id][0] = 0;
            Lever_Buff[wk->wu.id] = 0;
            break;
        }
        if (wk->wu.sp_tech_id == Tech_Number) {
            CP_Index[wk->wu.id][1] = 3;
        }
        break;

    case 3:
        if (--Timer_00[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1] = 4;
        }

        else {
            switch (Rapid_No[wk->wu.id][0]) {

            case 0:
                Rapid_No[wk->wu.id][0] = 1;
                Lever_Buff[wk->wu.id] = Shot;
                break;
            case 1:
                Rapid_No[wk->wu.id][0] = 0;
                Lever_Buff[wk->wu.id] = 0;
                break;
            }
            if (wk->wu.sp_tech_id != Tech_Number) {
                CP_Index[wk->wu.id][1] = 4;
            }
        }
        break;

    case 4:
        if (wk->wu.sp_tech_id == Tech_Number) {
            break;
        }
        if ((wk->wu.cg_type == 0x40) || (wk->wu.routine_no[1] == 0)) {
            Reaction_Exit_Sub(wk);
        }
        break;
    }
}

void Check_Rapid(PLW* wk, u16 Tech_Number) {
    if (!(Tech_Number & 0xF00)) {
        Rapid_No[wk->wu.id][0] = 0;
    } else {
        Lv = Setup_Lv08(0);
        if (Break_Into_CPU == 2) {
            Lv = 7;
        }
        Rapid_No[wk->wu.id][0] = Rapid_SA_Data[emLevelRemake(Lv, 8, 0)][random_32_com() & 7];
        Rapid_No[wk->wu.id][1] = 0;
        Setup_Rapid_End_Term(wk, Tech_Number);
        Rapid_Index[wk->wu.id] = 0xFF0;
    }
}

void Setup_Rapid_End_Term(PLW* wk, s16 Tech_Number) {
    Rapid_No[wk->wu.id][2] = (Tech_Number & 0xF00) >> 8;
    if ((Tech_Number & 0xF00) == 0x400) {
        Rapid_No[wk->wu.id][3] = Setup_Rapid_Time(wk, Tech_Number);
    }
}

s32 Setup_Rapid_Time(PLW* wk, u16 Tech_Number) {
    return 60;
}

void Rapid_Sub(PLW* wk) {
    if (Check_Rapid_End(wk) != 0) {
        return;
    }

    switch (Rapid_No[wk->wu.id][0]) {
    case 0:
        break;
    case 2:
        switch (Rapid_No[wk->wu.id][1]) {
        case 0:
            Rapid_No[wk->wu.id][1]++;
            Timer_00[wk->wu.id] = 1;
            Timer_01[wk->wu.id] = 3;
            return;
        case 1:
            if (--Timer_00[wk->wu.id] == 0) {
                Lever_Buff[wk->wu.id] = Rapid_Index[wk->wu.id];
                Timer_00[wk->wu.id] = 2;

                if (--Timer_01[wk->wu.id] == 0) {
                    Rapid_No[wk->wu.id][1]++;
                    Timer_01[wk->wu.id] = 0x18;
                }
            }
            break;
        case 2:
            if (--Timer_01[wk->wu.id] == 0) {
                Rapid_No[wk->wu.id][1]++;
                Timer_00[wk->wu.id] = 1;
                Timer_01[wk->wu.id] = 2;
            }
            break;
        default:
            if (--Timer_00[wk->wu.id] == 0) {
                Lever_Buff[wk->wu.id] = Rapid_Index[wk->wu.id];
                Timer_00[wk->wu.id] = Timer_01[wk->wu.id];
            }
            break;
        }
        break;
    default:
        switch (Rapid_No[wk->wu.id][1]) {
        case 0:
            Rapid_No[wk->wu.id][1]++;
            Timer_00[wk->wu.id] = 1;
            Timer_01[wk->wu.id] = 2;
            break;
        default:
            if (--Timer_00[wk->wu.id] == 0) {
                Lever_Buff[wk->wu.id] = Rapid_Index[wk->wu.id];
                Timer_00[wk->wu.id] = Timer_01[wk->wu.id];
            }
            break;
        }
        break;
    }
}

s32 Check_Rapid_End(PLW* wk) {
    switch (Rapid_No[wk->wu.id][2]) {
    case 1:
        if (wk->wu.mvxy.a[1].real.h < 0) {
            Rapid_No[wk->wu.id][0] = 0;
            return 1;
        }
        break;
    case 2:
        switch (Rapid_No[wk->wu.id][3]) {
        case 0:
            if (plw[wk->wu.id].caution_flag) {
                Rapid_No[wk->wu.id][3]++;
            }
            break;
        case 1:
            if (plw[wk->wu.id].caution_flag == 0) {
                Rapid_No[wk->wu.id][0] = 0;
                return 1;
            }
            break;
        }
        break;
    case 4:
        switch (Rapid_No[wk->wu.id][3]) {
        case 0:
            if (wk->wu.cg_ja.atix) {
                Rapid_No[wk->wu.id][3]++;
            }
            break;
        case 1:
            if (--Rapid_No[wk->wu.id][3] == 0) {
                Rapid_No[wk->wu.id][0] = 0;
                return 1;
            }
            break;
        }
        break;
    }
    return 0;
}

s32 Check_Start_Command_Attack(PLW* wk, s16 Reaction, u16 Tech_Number) {
    if (Before_Jump[wk->wu.id]) {
        return Before_Jump[wk->wu.id] = 0;
    }

    if (wk->wu.routine_no[1] == 2) {
        return 1;
    }
    if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
        return 0;
    }

    if ((Tech_Number == 0) || (Tech_Number == 1)) {
        if (wk->wu.cg_cancel & 2) {
            return 0;
        }
        return 1;
    }
    if ((Tech_Number & 0x8000) && (wk->wu.cg_cancel & 0x40)) {
        return 0;
    }
    if (wk->wu.cg_cancel & 0x20) {
        return 0;
    }
    if ((wk->wu.cg_cancel & 8) && (Reaction == 0xE)) {
        return 0;
    }
    return 1;
}

void ORO_JCA_Term(PLW* wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Tech_Number,
                  s16 Power_Level, s16 Ex_Shot, s16 RJX, s16 RJY, u16 JLD) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Continue_Menu[wk->wu.id] = 0;
            CP_Index[wk->wu.id][1]++;
            if (cmd_sel[wk->wu.id]) {
                Tech_Address[wk->wu.id] = player_CMD[wk->player_number][Tech_Number & 0xFF];
            } else {
                Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
            }
            Check_First_Menu(wk);
        }

        break;

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;
            dash_flag_clear(wk->wu.id);

            Jump_Init(wk, Jump_Dir);
            Check_Air_Guard(wk);
            if (Check_Diagonal_Shell(wk) != 0) {
                Next_Be_Free(wk);
            }
        }
        break;

    case 2:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }

        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Timer_00[wk->wu.id] = 2;
        }
        break;

    case 3:
        Check_Air_Guard(wk);

        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, JY) == 0) {
            break;
        }

        Jump_Init(wk, Jump_Dir2);
        if (--Timer_00[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
        }
        break;

    case 4:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        CP_Index[wk->wu.id][1] += 2;
        break;

    case 5:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0x7F);
        break;

    case 6:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Rapid_Sub(wk);
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
}

void ORO_HJCA_Term(PLW* wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Tech_Number,
                   s16 Power_Level, s16 Ex_Shot, s16 RJX, s16 RJY, u16 JLD) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }
        if (Check_Start_Hi_Jump(wk) != 0) {
            break;
        }

        Continue_Menu[wk->wu.id] = 0;
        CP_Index[wk->wu.id][1]++;
        if (cmd_sel[wk->wu.id]) {
            Tech_Address[wk->wu.id] = player_CMD[wk->player_number][Tech_Number & 0x7FFF];
        } else {
            Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0x7FFF];
        }
        Check_First_Menu(wk);

        break;

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id == 0]) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;

            Jump_Init(wk, Jump_Dir);
            Lever_Pool[wk->wu.id] &= 0xC;
            Lever_Buff[wk->wu.id] = 0;
            Check_Air_Guard(wk);
            if (Check_Diagonal_Shell(wk) != 0) {
                Next_Be_Free(wk);
            }
        }
        break;

    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Lever_Buff[wk->wu.id] = 2;
        Lever_Pool[wk->wu.id] |= 1;
        break;

    case 3:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }

        else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Timer_00[wk->wu.id] = 2;
        }
        break;

    case 4:
        Check_Air_Guard(wk);

        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }
        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, JY) == 0) {
            break;
        }

        Jump_Init(wk, Jump_Dir2);
        if (--Timer_00[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
        }
        break;

    case 5:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        if (Check_VS_Air_Attack(wk, RJX, RJY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        CP_Index[wk->wu.id][1] += 2;
        break;

    case 6:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0x7F);
        return;

    case 7:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Rapid_Sub(wk);
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
}

void Jump_Command_Attack_Term(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RX, s16 RY,
                              s16 Jump_Dir, s16 JRX, s16 JRY, u16 JLD) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Continue_Menu[wk->wu.id] = 0;
            CP_Index[wk->wu.id][1]++;
            if (cmd_sel[wk->wu.id]) {
                Tech_Address[wk->wu.id] = player_CMD[wk->player_number][Tech_Number & 0xFF];
            } else {
                Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
            }
            Check_First_Menu(wk);
        }

        break;

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;

            Jump_Init(wk, Jump_Dir);
            Check_Rapid(wk, Tech_Number);

            if (Check_Diagonal_Shell(wk) != 0) {
                Next_Be_Free(wk);
            }
        }
        break;

    case 2:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        break;

    case 3:
        Check_Air_Guard(wk);
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        if (Check_VS_Air_Attack(wk, JRX, JRY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        CP_Index[wk->wu.id][1] += 2;
        break;

    case 4:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;

    case 5:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Rapid_Sub(wk);
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
}

void Hi_Jump_Command_Attack_Term(PLW* wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RX, s16 RY,
                                 s16 Jump_Dir, s16 JRX, s16 JRY, u16 JLD) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }
        if (Check_Start_Hi_Jump(wk) == 0) {
            Continue_Menu[wk->wu.id] = 0;
            CP_Index[wk->wu.id][1]++;
            if (cmd_sel[wk->wu.id]) {
                Tech_Address[wk->wu.id] = player_CMD[wk->player_number][Tech_Number & 0x7FFF];
            } else {
                Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0x7FFF];
            }
            Check_First_Menu(wk);
        }

        break;

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id == 0]) {
            CP_Index[wk->wu.id][1]++;
            Tech_Index[wk->wu.id] = 0xC;

            Jump_Init(wk, Jump_Dir);
            Lever_Pool[wk->wu.id] &= 0xC;
            Lever_Buff[wk->wu.id] = 0;
            Check_Air_Guard(wk);
            if (Check_Diagonal_Shell(wk) != 0) {
                Next_Be_Free(wk);
            }
        }
        break;

    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }
        CP_Index[wk->wu.id][1]++;
        Lever_Buff[wk->wu.id] = 2;
        Lever_Pool[wk->wu.id] |= 1;
        break;

    case 3:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id] | 1;
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        }
        break;

    case 4:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        if (Check_VS_Air_Attack(wk, JRX, JRY, JLD) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], RX) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, RY) == 0) {
            break;
        }
        CP_Index[wk->wu.id][1] += 2;
        break;

    case 5:
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0xFFF);
        break;

    case 6:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, Ex_Shot) == -1) {
                CP_Index[wk->wu.id][1] = 0x63;
            }
            break;
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
}

s32 Check_Landed(PLW* wk, s16 Reaction) {
    if ((wk->wu.old_pos[1] != 0) && (wk->wu.xyz[1].disp.pos == 0)) {
        Lever_Buff[wk->wu.id] = 0;
        if (Continue_Menu[wk->wu.id]) {
            Next_End(wk);
            Before_Jump[wk->wu.id] = 1;
            return 1;
        } else {
            Reaction_Sub(wk, Reaction, 0);

            Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
            Check_Guard(wk);

            Before_Jump[wk->wu.id] = 1;
            return 1;
        }
    }
    if ((wk->wu.old_pos[1] == 0) && (wk->wu.xyz[1].disp.pos == 0) && (wk->wu.routine_no[1] != 4)) {
        Lever_Buff[wk->wu.id] = 0;
        if (Continue_Menu[wk->wu.id]) {
            Next_End(wk);
            Before_Jump[wk->wu.id] = 1;
            return 1;
        } else {
            Reaction_Sub(wk, Reaction, 0);
            if (Check_Guard(wk) != 0) {
                return 1;
            }
            Before_Jump[wk->wu.id] = 1;
            return 1;
        }
    }
    return 0;
}

s32 Check_Dash_Hit(PLW* wk, u16 Tech_Number) {
    WORK_Other* tmw;
    WORK* em;
    s16 i;
    s16 xx;
    s16 zz;

    if ((Tech_Number != 0) && (Tech_Number != 1)) {
        return 0;
    }

    em = (WORK*)wk->wu.target_adrs;
    for (i = 0; i < 8; i++) {
        if ((get_vs_shell_adrs(em, em->id, i, &tmw) == 0) && (get_vs_shell_adrs((WORK*)wk, em->id, i, &tmw) == 0)) {
            return 0;
        }
        if (tmw->wu.routine_no[1] == 2) {
            continue;
        }

        xx = wk->wu.xyz[0].disp.pos - tmw->wu.xyz[0].disp.pos;
        zz = Setup_Front_or_Back(wk, xx);

        if (Tech_Number == 0) {
            if (zz != 1) {
                if (Check_Hit_Shell(wk, tmw, Tech_Number) != 0) {
                    return 1;
                }
            }
        } else {
            if (zz != 0) {
                if (Check_Hit_Shell(wk, tmw, Tech_Number) != 0) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

s32 Setup_Front_or_Back(PLW* wk, s16 xx) {
    if (wk->wu.rl_waza == 0) {
        if (xx >= 0) {
            return 0;
        }
        return 1;
    } else {
        if (xx >= 0) {
            return 1;
        }
        return 0;
    }
}

s32 Check_Hit_Shell(PLW* wk, WORK_Other* tmw, u16 Tech_Number) {
    s16 xx;

    if (wk->wu.rl_waza == 1) {
        Tech_Number ^= 1;
    }

    if (Tech_Number == 0) {
        xx = wk->wu.xyz[0].disp.pos - Dash_Distance_Data[wk->player_number][Tech_Number];
        if (xx <= tmw->wu.xyz[0].disp.pos) {
            return 1;
        }
        return 0;
    } else {
        xx = wk->wu.xyz[0].disp.pos + Dash_Distance_Data[wk->player_number][Tech_Number];
        if (xx >= tmw->wu.xyz[0].disp.pos) {
            return 1;
        }
        return 0;
    }
}

void Jump_Init(PLW* wk, s16 Jump_Dir) {
    switch (Jump_Dir) {
    case 0:
        Ck_Distance_LvJ(wk);
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        break;
    case 2:
        Lever_Pool[wk->wu.id] = 1;
        Lever_Buff[wk->wu.id] = 1;
        break;

    default:
        Ck_Distance_LvJ(wk);
        Lever_Pool[wk->wu.id] ^= 0xC;
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        break;
    }
}

s32 Command_Type_00(PLW* wk, s16 Power_Level, u16 Tech_Number, s16 Ex_Shot) {
    if (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 4] != 0x1C) {
        Lever_Buff[wk->wu.id] = Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 3] & 0x7FFF;
        Lever_Buff[wk->wu.id] = datacmd_conpanecmd(Lever_Buff[wk->wu.id]);

        if (wk->wu.rl_waza) {
            if (Lever_Buff[wk->wu.id] & 0xC) {
                Lever_Buff[wk->wu.id] ^= 0xC;
            }
        }
        Tech_Index[wk->wu.id] += 4;
        return 1;
    } else {
        Lever_Buff[wk->wu.id] = Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 3] & 0x7FFF;
        if (wk->wu.rl_waza) {
            if (Lever_Buff[wk->wu.id] & 0xC) {
                Lever_Buff[wk->wu.id] ^= 0xC;
            }
        }
        if (Tech_Address[wk->wu.id][7] == 0x80) {
            return -1;
        }
        Tech_Index[wk->wu.id] = 7;

        if ((plw[wk->wu.id].sa->ex) && ((Ex_Shot == 0x70) || (Ex_Shot == 0x700))) {
            Lever_Buff[wk->wu.id] |= Ex_Shot;
        } else {
            Lever_Buff[wk->wu.id] |= renbanshot_conpaneshot(Tech_Address[wk->wu.id], Power_Level);
        }

        if ((My_char[wk->wu.id] == 2) && ((Tech_Number) == 0x8015) && (Power_Level != 8)) {
            CP_Index[wk->wu.id][0]++;
            Lever_LR[wk->wu.id] = Lever_Buff[wk->wu.id] & 0xFF0;

            if (Power_Level == 0xA) {
                CP_Index[wk->wu.id][1] = 1;
            } else {
                CP_Index[wk->wu.id][1] = 0;
            }
        } else {
            if (CP_No[wk->wu.id][0] == 0xA) {
                Rapid_Index[wk->wu.id] = Lever_Buff[wk->wu.id] & 0xFF0;
                Lever_Pool[wk->wu.id] = Lever_Buff[wk->wu.id] & 0xFF0;
            }
            if ((wk->player_number == 6) && ((Tech_Number) == 0x8016)) {
                CP_Index[wk->wu.id][1] = 5;
            } else {
                if ((wk->player_number == 7) && ((Tech_Number) == 0x1F)) {
                    Reaction_Exit_Sub(wk);
                } else {
                    CP_Index[wk->wu.id][1]++;
                }
            }
        }
        return 0;
    }
}

s32 Command_Type_06(PLW* wk, s16 Power_Level, u16 Tech_Number, s16 Ex_Shot) {
    s16 xx;

    xx = 0;

    if (Tech_Number & 0x8000) {
        if ((My_char[wk->wu.id] == 6) && (Super_Arts[wk->wu.id] == 0)) {
            xx = 1;
        }
    }
    Lever_Buff[wk->wu.id] = Rolling_Lv_Data[xx][CP_Index[wk->wu.id][2]];
    CP_Index[wk->wu.id][2]++;

    if ((Rolling_Lv_Data[xx][CP_Index[wk->wu.id][2]]) == 0xFFFF) {
        Lever_Buff[wk->wu.id] |= renbanshot_conpaneshot(Tech_Address[wk->wu.id], Power_Level);
        return 1;
    }

    return 0;
}

s32 Command_Type_01(PLW* wk, s16 Power_Level, s16 Ex_Shot) {
    switch (CP_Index[wk->wu.id][2]) {
    case 0:
        CP_Index[wk->wu.id][2]++;
        Timer_01[wk->wu.id] = Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 1] + 2;
        Lever_Pool[wk->wu.id] = Tech_Address[wk->wu.id][Tech_Index[wk->wu.id] + 3];
        Setup_Command_01(wk);

        if (wk->wu.rl_waza) {
            if (Lever_Pool[wk->wu.id] & 0xC) {
                Lever_Pool[wk->wu.id] ^= 0xC;
            }
        }
        /* fallthrough */

    case 1:
        if (wk->permited_koa & 2) {
            CP_Index[wk->wu.id][2]++;
        } else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Timer_00[wk->wu.id]++;
            break;
        }

    default:
        if (++Timer_00[wk->wu.id] < Timer_01[wk->wu.id]) {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        } else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            Tech_Index[wk->wu.id] += 4;
            if (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]] == 0x1C) {
                return 1;
            }
        }
        break;
    }
    return 0;
}

void Setup_Command_01(PLW* wk) {
    switch (Lever_Pool[wk->wu.id]) {
    case 2:
        Timer_00[wk->wu.id] = Lever_Store[wk->wu.id][0];
        break;
    default:
        Timer_00[wk->wu.id] = Lever_Store[wk->wu.id][2];
        break;
    }
}

void Check_Store_Lever(PLW* wk, u16 Tech_Number, s16 Next_Action, s16 Next_Menu) {
    s16 time;
    u16 lever;

    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    if (cmd_sel[wk->wu.id]) {
        Tech_Address[wk->wu.id] = player_CMD[wk->player_number][Tech_Number & 0xFF];
    } else {
        Tech_Address[wk->wu.id] = player_cmd[wk->player_number][Tech_Number & 0xFF];
    }
    time = Tech_Address[wk->wu.id][13] + 2;
    lever = Tech_Address[wk->wu.id][15];

    if (Check_Store_Direction(wk, lever, time) != 0) {
        CP_Index[wk->wu.id][0]++;
    } else {
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
}

s32 Check_Store_Direction(PLW* wk, u16 lever, s16 time) {
    if (wk->wu.rl_waza) {
        if (lever & 0xC) {
            lever ^= 0xC;
        }
    }

    switch (lever) {
    case 2:
        if (time <= Lever_Store[wk->wu.id][0]) {
            return 1;
        }
        break;
    case 8:
        if (time <= Lever_Store[wk->wu.id][1]) {
            return 1;
        }
        break;
    case 4:
        if (time <= Lever_Store[wk->wu.id][2]) {
            return 1;
        }
        break;
    }
    return 0;
}

s32 Select_Combo_Speed(PLW* wk) {
    s8 xx;
    s8 zz;

    xx = (u8)random_32_com();

    Lv = Setup_Lv18(8);
    Lv += CC_Value[0];

    if (Break_Into_CPU == 2) {
        Lv = 0x13;
    }

    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }

    Lv = emLevelRemake(Lv, 0x14, 2);

    if ((Break_Into_CPU == 1) || (Break_Into_CPU == 2)) {
        return zz = Combo_Speed_Unit_Data[17][Lv][xx];
    }
    return zz = Combo_Speed_Unit_Data[wk->player_number][Lv][xx];
}

s32 Select_Reflection_Time(PLW* wk) {
    s8 Lv;
    s8 xx;
    s8 zz;

    xx = (u8)random_32_com();
    Lv = Setup_Lv18(save_w[Present_Mode].Difficulty + 0);
    Lv += CC_Value[0];
    if (Break_Into_CPU == 2) {
        Lv = 0x13;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }

    Lv = emLevelRemake(Lv, 0x14, 2);

    time_check[time_check_ix] = xx;
    time_check_ix++;
    time_check_ix &= 3;

    if ((Break_Into_CPU == 1) || (Break_Into_CPU == 2)) {
        return zz = Reflection_Speed_Unit_Data[17][Lv][xx];
    }
    return zz = Reflection_Speed_Unit_Data[My_char[wk->wu.id]][Lv][xx];
}

s32 Setup_Lv04(s16 xx) {
    s16 i;
    s16* zz;

    zz = (s16*)&Level_04_Data[xx];

    for (i = 0; i < 3; i++) {
        if (Control_Time <= zz[i]) {
            return i;
        }
    }
    return 3;
}

s32 Setup_Lv08(s16 xx) {
    s16 i;
    s16* zz;

    zz = (s16*)&Level_08_Data[xx];

    for (i = 0; i < 7; i++) {
        if (Control_Time <= zz[i]) {
            break;
        }
    }
    return i;
}

s32 Setup_Lv10(s16 xx) {
    s16 i;
    s16* zz;

    zz = (s16*)&Level_10_Data[xx];

    for (i = 0; i < 9; i++) {
        if (Control_Time <= zz[i]) {
            break;
        }
    }
    return i;
}

s32 Setup_Lv18(s16 xx) {
    s16 i;
    s16* zz;

    zz = (s16*)&Level_18_Data[xx];

    for (i = 0; i < 17; i++) {
        if (Control_Time <= zz[i]) {
            break;
        }
    }
    return i;
}

s32 Setup_VS_Catch_Data(PLW* wk) {
    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    return VS_Catch_Data[emLevelRemake(Lv, 8, 0)];
}

s32 Setup_LP_Data(PLW* wk) {
    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    return LOOK_POSITION_Data[emLevelRemake(Lv, 8, 0)][random_32_com()];
}

s32 Setup_WT_Data(PLW* wk) {
    Lv = Setup_Lv04(0);
    if (Break_Into_CPU == 2) {
        Lv = 3;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    return Wait_Time_Data[emLevelRemake(Lv, 4, 0)][random_16_com() & 7];
}

void Ck_Distance(PLW* wk) {
    PL_Distance[wk->wu.id] = ((WORK*)wk->wu.target_adrs)->xyz[0].disp.pos - wk->wu.xyz[0].disp.pos;
    if (PL_Distance[wk->wu.id] < 0) {
        PL_Distance[wk->wu.id] = PL_Distance[wk->wu.id] * -1;
    }
}

s32 Ck_Distance_Height(PLW* wk) {
    s16 xx;

    xx = ((WORK*)wk->wu.target_adrs)->xyz[1].disp.pos - wk->wu.xyz[1].disp.pos;
    if (xx < 0) {
        xx = xx * -1;
    }
    return xx;
}

s32 Ck_Area(PLW* wk) {
    s16 i;

    for (i = 0; i < 3; i++) {
        if (PL_Distance[wk->wu.id] <= Separate_Area[wk->wu.id][i]) {
            return i;
        }
    }
    return 3;
}

s32 Ck_Area_Shell(PLW* wk) {
    s16 i;

    for (i = 0; i < 3; i++) {
        if (PL_Distance[wk->wu.id] <= Shell_Separate_Area[wk->wu.id][i]) {
            return i;
        }
    }

    return 3;
}

void Ck_Distance_Lv(PLW* wk) {
    PL_Distance[wk->wu.id] = ((WORK*)wk->wu.target_adrs)->xyz[0].disp.pos - wk->wu.xyz[0].disp.pos;

    if (PL_Distance[wk->wu.id] > 0) {
        Lever_Buff[wk->wu.id] = 8;
    } else {
        Lever_Buff[wk->wu.id] = 4;
        PL_Distance[wk->wu.id] = PL_Distance[wk->wu.id] * -1;
    }
}

void Ck_Distance_LvJ(PLW* wk) {
    PL_Distance[wk->wu.id] = ((WORK*)wk->wu.target_adrs)->xyz[0].disp.pos - wk->wu.xyz[0].disp.pos;

    if (PL_Distance[wk->wu.id] > 0) {
        Lever_Pool[wk->wu.id] = 9;
    } else {
        Lever_Pool[wk->wu.id] = 5;
        PL_Distance[wk->wu.id] = PL_Distance[wk->wu.id] * -1;
    }
}

void Next_End(PLW* wk) {
    if (Check_Guard(wk) != 0) {
        return;
    }

    CP_Index[wk->wu.id][0] = 0xFF;
    CP_Index[wk->wu.id][1] = 0;
    CP_Index[wk->wu.id][2] = 0;
    CP_Index[wk->wu.id][3] = 0;
}

void Next_Another_Menu(PLW* wk, s16 Next_Action, u16 Next_Menu) {
    if (Next_Action != 1) {
        CP_No[wk->wu.id][0] = Next_Action;
        Pattern_Index[wk->wu.id] = Next_Menu;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
    } else {
        Next_Be_Free(wk);
    }
}

void Reaction_Sub(PLW* wk, s16 Reaction, s16 Power_Level) {
    switch (Reaction & 0x7F) {
    case 9:
        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        } else if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Next_End(wk);
        }
        break;

    case 10:
        if ((Stock_Hit_Flag[wk->wu.id] >> 2) != 0) {
            Next_End(wk);
            break;
        }
        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        } else {
            if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
                Reaction_Exit_Sub(wk);
            }
        }
        break;

    case 11:
        if (plw[wk->wu.id].caution_flag) {
            break;
        }
        if (plw[wk->wu.id].tsukami_f) {
            break;
        }

        if ((Stock_Hit_Flag[wk->wu.id] >> 2) != 0) {
            Next_End(wk);
            break;
        }
        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        } else if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Next_End(wk);
        }
        break;

    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        if ((Stock_Hit_Flag[wk->wu.id] >> 2) != 0) {
            Setup_Follow(wk, Reaction & 0xFFF);
            break;
        }
        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        } else if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Setup_Follow(wk, Reaction & 0xFFF);
        }
        break;

    case 12:
        Reaction_Exit_Sub(wk);
        Counter_Attack[wk->wu.id] = 1;
        break;

    case 14:
        Reaction_Exit_Sub(wk);
        Counter_Attack[wk->wu.id] = 1;
        break;

    case 13:

        if ((Stock_Hit_Flag[wk->wu.id] >> 2) != 0) {
            Next_End(wk);
            break;
        }
        if (wk->permited_koa & 0x10) {
            if (Check_Meoshi_Attack(wk, Reaction, Power_Level) != 0) {
                break;
            }
        }
        Last_Eftype[wk->wu.id] = -1;

        if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            if (Stock_Hit_Flag[wk->wu.id]) {
                if ((CP_No[wk->wu.id][0] == 6) && (Pattern_Index[wk->wu.id] == 0)) {
                    CP_No[wk->wu.id][0] = Return_CP_No[wk->wu.id];
                    CP_Index[wk->wu.id][0] = Return_CP_Index[wk->wu.id];
                    CP_Index[wk->wu.id][1] = 0;
                    CP_Index[wk->wu.id][2] = 0;
                    CP_Index[wk->wu.id][3] = 0;
                    Pattern_Index[wk->wu.id] = Return_Pattern_Index[wk->wu.id];
                } else {
                    Reaction_Exit_Sub(wk);
                }
            } else {
                Next_End(wk);
            }
        }
        break;

    default:

        if (plw[wk->wu.id].caution_flag) {
            break;
        }
        if (plw[wk->wu.id].tsukami_f) {
            break;
        }

        if (Stock_Hit_Flag[wk->wu.id]) {
            Reaction_Exit_Sub(wk);
        }

        else if ((wk->wu.routine_no[1] != 4) || (wk->wu.cg_type == 0x40)) {
            Reaction_Exit_Sub(wk);
        }

        break;
    }
}

s32 Check_Meoshi_Attack(PLW* wk, s16 Reaction, s16 Power_Level) {
    if (wk->wu.cg_meoshi == Last_Eftype[wk->wu.id]) {
        return 0;
    }

    if (wk->permited_koa & 0x10) {
        Last_Eftype[wk->wu.id] = wk->wu.cg_meoshi;

        M_Lv[wk->wu.id] = Get_Meoshi_Data(wk);

        if (Pattern_Index[wk->wu.id] != 0) {
            Return_CP_No[wk->wu.id] = CP_No[wk->wu.id][0];
            Return_CP_Index[wk->wu.id] = CP_Index[wk->wu.id][0] + 1;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Return_Pattern_Index[wk->wu.id] = Pattern_Index[wk->wu.id];
        }
        CP_No[wk->wu.id][0] = 6;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Pattern_Index[wk->wu.id] = 0;
        return 1;
    }
    return 0;
}

s32 Get_Meoshi_Data(PLW* wk) {
    u16 lever;
    u16 shot;

    lever = get_meoshi_lever(wk->wu.cg_meoshi);
    shot = get_meoshi_shot(wk->wu.cg_meoshi);

    if (wk->wu.rl_flag) {
        lever ^= 0xC;
    }

    return shot | lever;
}

void Reaction_Exit_Sub(PLW* wk) {
    CP_Index[wk->wu.id][0]++;
    CP_Index[wk->wu.id][1] = 0;
    CP_Index[wk->wu.id][2] = 0;
    CP_Index[wk->wu.id][3] = 0;

    Flip_Flag[wk->wu.id] = 0;
    Counter_Attack[wk->wu.id] = 0;
    Limited_Flag[wk->wu.id] = 0;
    Before_Jump[wk->wu.id] = 0;
    if (CP_No[wk->wu.id][0] != 6) {
        Passive_Flag[wk->wu.id] = 0;
    }
}

void Check_First_Menu(PLW* wk) {
    if (CP_Index[wk->wu.id][0] == 0) {
        Combo_Speed[wk->wu.id] = 1;
    } else {
        Combo_Speed[wk->wu.id] = Select_Combo_Speed(wk);
    }
}

void Select_Active(PLW* wk) {
    s16 pl_id;

    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }

    Lv = emLevelRemake(Lv, 8, 0);

    Rnd = (u8)random_32_ex_com();

    if (Check_SA_Active(wk, &pl_id) != 0) {
        Lv = Setup_Lv04(0);
        if (Break_Into_CPU == 2) {
            Lv = 3;
        }
        if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
            Lv = 2;
        }

        Lv = emLevelRemake(Lv, 4, 0);

        switch (Area_Number[wk->wu.id]) {
        case 0:
            Pattern_Index[wk->wu.id] = SA_Active_A_Unit_Data[pl_id - 1][Lv][Rnd];
            break;
        case 1:
            Pattern_Index[wk->wu.id] = SA_Active_B_Unit_Data[pl_id - 1][Lv][Rnd];
            break;
        case 2:
            Pattern_Index[wk->wu.id] = SA_Active_C_Unit_Data[pl_id - 1][Lv][Rnd];
            break;
        default:
            Pattern_Index[wk->wu.id] = SA_Active_D_Unit_Data[pl_id - 1][Lv][Rnd];
            break;
        }
    } else {
        switch (Area_Number[wk->wu.id]) {
        case 0:
            Pattern_Index[wk->wu.id] = Active_A_Unit_Data[wk->player_number][Lv][Rnd];
            break;

        case 1:
            Pattern_Index[wk->wu.id] = Active_B_Unit_Data[wk->player_number][Lv][Rnd];
            break;

        case 2:
            Pattern_Index[wk->wu.id] = Active_C_Unit_Data[wk->player_number][Lv][Rnd];
            break;

        default:
            Pattern_Index[wk->wu.id] = Active_D_Unit_Data[wk->player_number][Lv][Rnd];
            break;
        }
    }

    if (Debug_w[0x36]) {
        Pattern_Index[wk->wu.id] = (u16)Debug_w[0x36] - 1;
    }
}

s32 Check_SA_Active(PLW* wk, s16* pl_id) {
    if (wk->sa->ok != -1) {
        return 0;
    }
    if (My_char[wk->wu.id] == 9) {
        if (plw[wk->wu.id].sa->kind_of_arts == 0) {
            return *pl_id = 3;
        }
        return *pl_id = 2;
    }
    if ((My_char[wk->wu.id] == 3) && (plw[wk->wu.id].sa->kind_of_arts == 2)) {
        return *pl_id = 1;
    }
    if ((My_char[wk->wu.id] == 0xA) && (plw[wk->wu.id].sa->kind_of_arts == 2)) {
        return *pl_id = 1;
    }
    if ((My_char[wk->wu.id] == 0x11) && (plw[wk->wu.id].sa->kind_of_arts == 2)) {
        return *pl_id = 4;
    }
    return 0;
}

void Setup_Follow(PLW* wk, s16 Follow_Type) {
    CP_No[wk->wu.id][0] = 3;
    CP_No[wk->wu.id][1] = Follow_Type;

    if (wk->wu.hf.hit.player == 0) {
        CP_No[wk->wu.id][2] = 0;
    } else {
        CP_No[wk->wu.id][2] = 1;
    }

    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = Select_Reflection_Time(wk);
    Timer_00[wk->wu.id]++;
}

void Decide_Follow_Menu(PLW* wk) {
    s8 xx;
    const _anon6* Menu_Add_Ptr0;
    const _anon13* Menu_Add_Ptr1;

    Menu_Add_Ptr0 = Follow_Menu_1st_Unit_Data[wk->player_number];
    Rnd = (u8)random_32_com();
    xx = Menu_Add_Ptr0->xxxx[CP_No[wk->wu.id][1]][CP_No[wk->wu.id][2]][Rnd];

    Menu_Add_Ptr1 = Follow_Menu_2nd_Unit_Data[wk->player_number];
    Pattern_Index[wk->wu.id] = Menu_Add_Ptr1->zzzz[xx][Area_Number[wk->wu.id]];
}

s32 Select_Passive(PLW* wk) {
    u16 xx;

    if (VS_Tech[wk->wu.id] == 0xB) {
        Area_Number[wk->wu.id] = Ck_Area_Shell(wk);
    }
    if (VS_Tech[wk->wu.id] == 0x1E) {
        Area_Number[wk->wu.id] = Ck_Area_Shell(wk);
    }

    Last_Attack_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
    Standing_Timer[wk->wu.id] = 0;
    Devide_Level(VS_Tech[wk->wu.id] >> 0xC);
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 1;
    }
    VS_Tech[wk->wu.id] &= 0xFFF;

    Setup_Random(wk);

    switch (Area_Number[wk->wu.id]) {
    case 0:
        xx = Passive_A_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];

        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][0] = 0x78;

            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][0] = 0;
        break;

    case 1:
        xx = Passive_B_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];

        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][1] = 0x78;

            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][1] = 0;
        break;

    case 2:
        xx = Passive_C_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];

        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][2] = 0x78;

            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][2] = 0;
        break;

    default:
        xx = Passive_D_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];

        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][3] = 0x78;

            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][3] = 0;
        break;
    }

    Passive_Flag[wk->wu.id] = 1;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = Select_Reflection_Time(wk);

    if (Debug_w[0x37]) {
        Pattern_Index[wk->wu.id] = (u16)Debug_w[0x37] - 1;
    }

    if ((VS_Tech[wk->wu.id] == 0x19) || (VS_Tech[wk->wu.id] == 0x13) || (Timer_00[wk->wu.id] == 0)) {
        CP_No[wk->wu.id][0] = 6;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
    } else {
        CP_No[wk->wu.id][0] = 5;
    }
    return 1;
}

void Devide_Level(s16 xx) {
    switch (xx) {
    case 0:
        Lv = Setup_Lv04(0);
        if (Break_Into_CPU == 2) {
            Lv = 3;
        }
        break;
    default:
        Lv = Setup_Lv08(2);
        if (Break_Into_CPU == 2) {
            Lv = 7;
        }
        break;
    }
}

void Setup_Random(PLW* wk) {
    if (VS_Tech[wk->wu.id] == 0x20) {
        Rnd = (u8)random_16_com() & 7;
        VS_Tech[wk->wu.id] = 0x1C;
    } else {
        Rnd = (u8)random_16_com();
        Rnd = Check_Dramatic(wk, wk->wu.id);
    }
}

s32 Check_Dramatic(PLW* wk, s16 PL_id) {
    if (plw[wk->wu.id].sa->ok) {
        return Rnd | 8;
    }

    if ((plw[PL_id].wu.vital_new <= 0x30) || (plw[PL_id ^ 1].wu.vital_new <= 0x30)) {
        return Rnd | 8;
    }
    return Rnd;
}

s32 Check_Passive(PLW* wk) {
    WORK* em;

    if ((Counter_Attack[wk->wu.id] != 0) || (Pierce_Menu[wk->wu.id] != 0)) {
        return 0;
    }

    em = (WORK*)wk->wu.target_adrs;

    if (Check_Blow_Off(wk, em, 0) != 0) {
        *CP_No[wk->wu.id] = 0xE;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        return -1;
    }
    if (Check_Thrown(wk, em) != 0) {
        if (Select_Passive(wk) != -1) {
            return 1;
        }
    }

    if (Check_Shell(wk) != 0) {
        return 1;
    }
    if ((Passive_Flag[wk->wu.id]) || (Flip_Flag[wk->wu.id])) {
        return Check_Guard(wk);
    }
    if (Check_Lie(wk) == 1) {
        return 1;
    }

    if (PL_Status[em->routine_no[1]] == 0) {
        return Check_Shell(wk);
    }

    Passive_Mode = 4;

    if (Ck_Passive_Term(wk) != 0) {
        if (Select_Passive(wk) != -1) {
            return 1;
        }
    }

    if (Check_Guard(wk) != 0) {
        return 1;
    }
    if ((Passive_Flag[wk->wu.id]) || (Flip_Flag[wk->wu.id])) {
        return 0;
    }

    Passive_Mode = 0;

    if (Ck_Passive_Term(wk) != 0) {
        return Select_Passive(wk);
    }

    return 0;
}

s32 Check_Guard(PLW* wk) {
    WORK* em;
    s16 xx;
    s16 zz;

    em = (WORK*)wk->wu.target_adrs;

    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }

    if (Guard_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
        return 0;
    }

    xx = Hit_Range_Data[em->hit_range];
    xx += Com_Width_Data[wk->wu.id];

    if (PL_Distance[wk->wu.id] > xx) {
        return 0;
    }

    Lv = Setup_Lv10(0);
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }
    Lv += CC_Value[0];
    if (Break_Into_CPU == 2) {
        Lv = 0xA;
    }

    Rnd = random_16_com();

    zz = Setup_EM_Rank_Index(wk);

    Lv = emLevelRemake(Lv, 0xB, 1);

    if (Guard_Data[zz][Lv][Rnd] == 3) {
        Guard_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
        return 0;
    }

    if (Check_Flip_Term(wk, NULL) != 0) {
        Next_Be_Flip(wk, 0);
    } else {
        Next_Be_Guard(wk, em, Guard_Data[zz][Lv][random_16_ex_com()]);
    }

    return 1;
}

s32 Check_Makoto(PLW* wk) {
    if (wk->player_number != 0x10) {
        return 0;
    }
    if (wk->sa->ok != -1) {
        return 0;
    }
    if (plw[wk->wu.id].sa->kind_of_arts == 2) {
        return 1;
    }

    return 0;
}

s32 Check_Flip_Term(PLW* wk, WORK* tmw) {
    WORK* em;
    s16 xx;

    if (tmw != NULL) {
        em = tmw;
    } else {
        em = (WORK*)wk->wu.target_adrs;
    }

    if (Check_Flip_Tech(em) == 0) {
        return 0;
    }

    Lv = Setup_Lv08(0);

    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }

    Rnd = random_32_com();
    Rnd -= Flip_Term_Correct(wk);

    xx = Setup_EM_Rank_Index(wk);

    if (Rnd >= (Flip_Data[xx][emLevelRemake(Lv, 8, 0)])) {
        return 0;
    }

    return 1;
}

s32 Setup_EM_Rank_Index(PLW* wk) {
    if (EM_Rank != 0) {
        return 0x11;
    }

    return wk->player_number;
}

s32 Flip_Term_Correct(PLW* wk) {
    s16 xx = 0;

    if (plw[wk->wu.id].wu.vital_new < 0x31) {
        xx += 1;
    }
    if ((PL_Wins[wk->wu.id]) < (PL_Wins[wk->wu.id ^ 1])) {
        xx += 2;
    }
    if (Counter_hi < 0xF) {
        xx += 1;
    }
    if (Check_Makoto(wk) != 0) {
        xx += 20;
    }

    return xx;
}

void Next_Be_Guard(PLW* wk, WORK* em, s16 Type_Of_Guard) {
    CP_No[wk->wu.id][0] = 7;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = 10;

    dash_flag_clear(wk->wu.id);
    Guard_Type[wk->wu.id] = Type_Of_Guard;
    Check_Guard_Type(wk, em);
}

s32 Check_Flip_Tech(WORK* em) {
    s32 rnum = 1;

    switch (save_w[Present_Mode].Difficulty) {
    case 0:
        rnum = 0;
        break;
    default:
        if (em->kind_of_waza & 0xF8) {
            rnum = 0;
        }
        /* fallthrough */
    case 6:
        if (em->kind_of_waza == 0) {
            rnum = 0;
        }
        if (em->kind_of_waza == 1) {
            rnum = 0;
        }
        break;
    case 7:
        break;
    }

    return rnum;
}

void Next_Be_Flip(PLW* wk, s16 xx) {
    WORK* em;

    em = (WORK*)wk->wu.target_adrs;

    CP_No[wk->wu.id][0] = 0xC;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = 9;

    Flip_Counter[wk->wu.id] = 0;

    if (xx) {
        if (xx == 8) {
            SetShellFlipLever(wk);
        } else {
            if ((em->pat_status == 0x21) || (em->pat_status == 0x20)) {
                Lever_Buff[wk->wu.id] = 2;
            } else {
                Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 0);
            }
        }
        CP_No[wk->wu.id][2] = 1;

        Timer_01[wk->wu.id] = xx;
    } else {
        Check_Flip_GO(wk, 0);
    }
}

s32 Check_Diagonal_Shell(PLW* wk) {
    WORK_Other* tmw;
    WORK* em;
    s16 i;

    Lv = Setup_Lv08(0);
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }

    Rnd = random_16_com();
    Lv += *CC_Value;

    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if (Rnd > VS_Diagonal_Shell_Data[emLevelRemake(Lv, 8, 0)]) {
        return 0;
    }

    em = (WORK*)wk->wu.target_adrs;

    for (i = 0; i < 8; i++) {
        if ((get_vs_shell_adrs(em, em->id, i, &tmw) == 0) && (get_vs_shell_adrs(&wk->wu, em->id, i, &tmw) == 0)) {
            return 0;
        }

        if (tmw->wu.routine_no[1] == 2) {
            continue;
        }
        if (wk->wu.rl_waza == tmw->wu.rl_flag) {
            continue;
        }

        if (Check_Behind(wk, tmw) != 0) {
            continue;
        }

        if (tmw->wu.charset_id == 2) {
            continue;
        }
        if (sub_000294C0(tmw) != 0) {
            return 1;
        }
    }
    return 0;
}

s32 Check_Ignore_Shell2(WORK_Other* tmw) {
    if (tmw->wu.type == 0xDE) {
        return 1;
    }
    if ((tmw->wu.type >= 0x24) && (tmw->wu.type < 0x28)) {
        return 1;
    }
    if ((tmw->wu.type >= 0xD) && (tmw->wu.type < 0x10)) {
        return 1;
    }
    if ((tmw->wu.type == 0x54) || (tmw->wu.type == 0x55)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x4D) && (tmw->wu.type < 0x51)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x7A) && (tmw->wu.type < 0x7F)) {
        return 1;
    }

    return 0;
}

s32 Check_Shell(PLW* wk) {
    WORK_Other* tmw;
    WORK* em;
    s16 i;
    s16 xx;
    s16 zz;

    if (Shell_Ignore_Timer[wk->wu.id]) {
        Shell_Ignore_Timer[wk->wu.id]--;
        return 0;
    }
    if (CP_No[wk->wu.id][0] == 8) {
        return 0;
    }

    em = (WORK*)wk->wu.target_adrs;

    for (i = 0; i < 8; i++) {
        if ((get_vs_shell_adrs(em, em->id, i, &tmw) == 0) && (get_vs_shell_adrs(&wk->wu, em->id, i, &tmw) == 0)) {
            return 0;
        }

        if (tmw->wu.routine_no[1] == 2) {
            continue;
        }
        if (wk->wu.rl_waza == tmw->wu.rl_flag) {
            continue;
        }
        if (tmw->wu.routine_no[0] != 1) {
            continue;
        }
        if (Check_Behind(wk, tmw) == 0) {
            if (tmw->wu.charset_id == 2) {
                continue;
            }
            if (sub_000294C0(tmw) == 0) {
                xx = Compute_Hit_Time(wk, tmw);

                zz = Ck_Distance_XX(wk->wu.xyz[0].disp.pos, tmw->wu.xyz[0].disp.pos);

                if (Decide_Shell_Guard(wk, tmw) != 0) {
                    return 0;
                }

                CP_No[wk->wu.id][0] = 8;
                CP_No[wk->wu.id][1] = 0;
                CP_No[wk->wu.id][2] = 0;
                CP_No[wk->wu.id][3] = 0;

                CP_Index[wk->wu.id][0] = 0;
                CP_Index[wk->wu.id][1] = 0;
                CP_Index[wk->wu.id][2] = 0;
                CP_Index[wk->wu.id][3] = 0;

                Shell_Address[wk->wu.id] = (u32*)tmw;

                Guard_or_Jump_VS_Shell(wk, tmw, xx);

                return 1;
            }
        }
    }

    return 0;
}

s32 Check_Shell_Another_in_Flip(PLW* wk) {
    WORK_Other* tmw;
    WORK* em;
    s32 i;
    s32 xx = 0;

    em = (WORK*)wk->wu.target_adrs;

    for (i = 0; i < 8; i++) {
        if ((get_vs_shell_adrs(em, em->id, i, &tmw) == 0) && (get_vs_shell_adrs(&wk->wu, em->id, i, &tmw) == 0)) {
            return 0;
        }

        if (tmw->wu.routine_no[1] == 2) {
            continue;
        }
        if (wk->wu.rl_waza == tmw->wu.rl_flag) {
            continue;
        }
        if (tmw->wu.routine_no[0] != 1) {
            continue;
        }
        if (Check_Behind(wk, tmw) != 0) {
            continue;
        }

        if (tmw->wu.charset_id == 2) {
            continue;
        }
        if (sub_000294C0(tmw) != 0) {
            continue;
        }

        xx = Compute_Hit_Time(wk, tmw);

        Shell_Address[wk->wu.id] = (u32*)tmw;

        break;
    }
    return xx;
}

s32 Check_Ignore_Shell(WORK_Other* tmw) {
    if (tmw->wu.type == 0xDE) {
        return 1;
    }
    if ((tmw->wu.type >= 0x24) && (tmw->wu.type < 0x28)) {
        return 1;
    }
    if ((tmw->wu.type >= 0xD) && (tmw->wu.type < 0x10)) {
        return 1;
    }
    if ((tmw->wu.type == 0x54) || (tmw->wu.type == 0x55)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x4D) && (tmw->wu.type < 0x51)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x7A) && (tmw->wu.type < 0x7F)) {
        return 1;
    }

    return 0;
}

s32 Compute_Hit_Time(PLW* wk, WORK_Other* tmw) {
    s32 lx1;
    s32 divsp;
    s16 x2;

    lx1 = get_att_head_position(&tmw->wu);
    lx1 <<= 16;

    lx1 -= wk->wu.xyz[0].cal;

    if (tmw->wu.mvxy.a[0].sp != 0) {
        divsp = tmw->wu.mvxy.a[0].sp;
    } else {
        divsp = 0x48000;
    }

    x2 = lx1 / divsp;

    if (x2 < 0) {
        x2 = x2 * -1;
    }

    return x2;
}

s32 Decide_Shell_Guard(PLW* wk, WORK_Other* tmw) {
    s16 xx;

    Lv = Setup_Lv10(0);

    if (Break_Into_CPU == 2) {
        Lv = 9;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }

    Rnd = random_32_com();

    xx = Setup_EM_Rank_Index(wk);
    if (Shell_Guard_Data[xx][emLevelRemake(Lv, 0xA, 0)] > Rnd) {
        return 0;
    }
    Shell_Ignore_Timer[wk->wu.id] = 0x3C;
    return 1;
}

void Guard_or_Jump_VS_Shell(PLW* wk, WORK_Other* tmw, s16 xx) {
    if (xx <= Shell_Dodge_Data[0][wk->player_number]) {
        if (Check_Flip_Term(wk, &tmw->wu) != 0) {
            Pattern_Index[wk->wu.id] = 9;
        } else {
            Pattern_Index[wk->wu.id] = 0;
        }
    } else {
        switch (save_w[Present_Mode].Difficulty) {
        case 7:
            if (wk->wu.vital_new < 4) {
                if (!(random_32_com() & 0xF)) {
                    Pattern_Index[wk->wu.id] = 9;
                    break;
                }
            }
            /* fallthrough */
        case 6:
            if (wk->wu.vital_new < 2) {
                if (!(random_32_com() & 7)) {
                    Pattern_Index[wk->wu.id] = 9;
                    break;
                }
            }
            /* fallthrough */
        default:
            Pattern_Index[wk->wu.id] = Decide_Shell_Reaction(wk, tmw, Shell_Change_Data_For_Reaction[tmw->wu.type]);
            break;
        }
    }

    Setup_Shell_Disposal(wk, tmw);
}

void Setup_Shell_Disposal(PLW* wk, WORK_Other* tmw) {
    switch (Pattern_Index[wk->wu.id]) {
    case 0:
        Next_Be_Shell_Guard(wk, &tmw->wu);
        break;
    case 9:
        Passive_Flag[wk->wu.id] = 1;
        break;
    case 10:
        Pattern_Index[wk->wu.id] = Decide_Shell_Reaction(wk, tmw, 0);

        if (Pattern_Index[wk->wu.id] == 0) {
            Next_Be_Shell_Guard(wk, &tmw->wu);
        }

        break;
    }
}

void Next_Be_Shell_Guard(PLW* wk, WORK* tmw) {
    CP_No[wk->wu.id][0] = 9;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = 0xA;

    dash_flag_clear(wk->wu.id);
    Guard_Type[wk->wu.id] = 0;
    Check_Guard_Type(wk, tmw);
}

s32 Decide_Shell_Reaction(PLW* wk, WORK_Other* tmw, u16 dir_step) {
    if (dir_step == 0xFF) {
        return 0;
    }

    Lv = Setup_Lv08(0);

    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 4;
    }

    Rnd = random_16_com();

    return VS_Shell_Active_Data[wk->player_number][dir_step][emLevelRemake(Lv, 8, 0)][Rnd];
}

s32 Check_Behind(PLW* wk, WORK_Other* tmw) {
    if (wk->wu.rl_waza == 0) {
        if (wk->wu.xyz[0].disp.pos < tmw->wu.xyz[0].disp.pos) {
            return 1;
        }
        return 0;
    } else {
        if (wk->wu.xyz[0].disp.pos > tmw->wu.xyz[0].disp.pos) {
            return 1;
        }
        return 0;
    }
}

void Setup_Lever_LR(PLW* wk, s16 PL_id, s16 Lever) {
    if (Lever == 0) {
        Lever_LR[PL_id] = 0;
    } else {
        if (Lever & 0x1000) {
            Lever_LR[PL_id] = 1;
        }

        else if (Lever & 0x2000) {
            Lever_LR[PL_id] |= 2;
        }

        if (Lever & 0x4000) {
            Lever_LR[PL_id] |= Setup_Guard_Lever(wk, 0);
        } else {
            if (Lever & 0x8000) {
                Lever_LR[PL_id] |= Setup_Guard_Lever(wk, 1);
            }
        }
    }
}

s32 Check_Exit_Term(PLW* wk, WORK* em, s16 Exit_No) {
    s16 xx;

    if (VS_Jump_Term(wk, em, &xx) != 0) {
        return xx;
    }
    return Exit_Term_Tbl[Exit_No](wk, em);
}

s32 VS_Jump_Term(PLW* wk, WORK* em, s16* xx) {
    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }

    switch (My_char[em->id]) {
    case 1:
        if (Check_F_Cross_Chop(wk, em, 0xF) != 0) {
            return *xx = 3;
        }
        break;
    case 3:
    case 10:
        if (Check_Special_Technique(wk, em, 0, 0, 0x2b, -1, -1) != 0) {
            return *xx = 2;
        }
        break;
    case 5:
        if (Check_Special_Technique(wk, em, 0, 0, 0x2A, -1, -1) != 0) {
            return *xx = 2;
        }
        if (Check_Limited_Jump_Attack(wk, em, 0x14, 4) != 0) {
            VS_Tech[wk->wu.id] = 0xF;
            return *xx = 3;
        }
        break;
    case 8:
        if (Check_Limited_Jump_Attack(wk, em, 0x14, 5) != 0) {
            VS_Tech[wk->wu.id] = 0xF;
            return *xx = 3;
        }
        break;
    case 9:
        if (Check_Special_Technique(wk, em, 0xF, 8, 0x2C, 1, -1) != 0) {
            return *xx = 3;
        }
        break;
    }
    return 0;
}

s32 Exit_Term_0000(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0x1E;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }

    return 0;
}

s32 Exit_Term_0001(PLW* wk, WORK* em) {
    return 1;
}

s32 Exit_Term_0002(PLW* wk, WORK* em) {
    if (em->routine_no[1] == 2) {
        return 1;
    }
    if (em->id != 0xD) {
        return 1;
    }
    return 0;
}

s32 Exit_Term_0003(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0xA;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Check_SHINRYU(wk)) {
            return 0;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }

    return 0;
}

s32 Exit_Term_0004(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 1;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Check_SHINRYU(wk)) {
            return 0;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }

    return 0;
}

s32 Exit_Term_0005(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 5;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Check_SHINRYU(wk)) {
            return 0;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }

    return 0;
}

s32 Exit_Term_0006(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0x3C;
        break;
    default:
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        if (Check_SHINRYU(wk)) {
            return 0;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }

    return 0;
}

s32 Exit_Term_0007(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0x1E;
        /* fallthrough */
    default:
        if (Check_Drop_Term(em, 0x28) != 0) {
            if (Area_Number[wk->wu.id] >= 3) {
                return 1;
            }
            VS_Tech[wk->wu.id] = 0x1A;
            return -1;
        }
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        Timer_00[wk->wu.id] = 1;
        return 1;
    }

    return 0;
}

s32 Exit_Term_0008(PLW* wk, WORK* em) {
    switch (Term_No[wk->wu.id]) {
    case 0:
        Term_No[wk->wu.id]++;
        Timer_00[wk->wu.id] = 0xb4;
        /* fallthough */
    default:
        if ((wk->wu.old_pos[1] == 0) && (wk->wu.xyz[1].disp.pos == 0) && (wk->wu.routine_no[1] != 4)) {
            return 1;
        }
        if (--Timer_00[wk->wu.id] == 0) {
            return 1;
        }
    }

    return 0;
}

s32 Check_Drop_Term(WORK* em, s16 Y) {
    if (em->mvxy.a[1].real.h >= 0) {
        return 0;
    }
    if (em->xyz[1].disp.pos >= Y) {
        return 0;
    }
    return 1;
}

s32 Check_SHINRYU(PLW* wk) {
    PLW* em;

    em = (PLW*)wk->wu.target_adrs;

    if (em->sa->ok != -1) {
        return 0;
    }
    if (My_char[em->wu.id] != 0xB) {
        return 0;
    }
    if (plw[em->wu.id].sa->kind_of_arts != 1) {
        return 0;
    }
    return 1;
}

void Check_BOSS(PLW* wk, u32 Next_Action, u16 Next_Menu) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Break_Into_CPU == 1) {
        Disposal_Again[wk->wu.id] = 1;
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;

        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
    } else {
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
}

void Check_BOSS_EX(PLW* wk, u32 Next_Action, u16 Next_Menu) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Break_Into_CPU != 1) {
        Disposal_Again[wk->wu.id] = 1;
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;

        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
    } else {
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
}

void ETC_Term(PLW* wk, s16 Exit_No, u32 Next_Action, u16 Next_Menu) {
    s16 xx;
    WORK* em = (WORK*)wk->wu.target_adrs;

    xx = ETC_Term_Tbl[Exit_No](wk, em);

    if (xx == -1) {
        return;
    }

    if (xx) {
        Disposal_Again[wk->wu.id] = 1;
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;

        Flip_Flag[wk->wu.id] = 0;
        Limited_Flag[wk->wu.id] = 0;
    } else {
        Disposal_Again[wk->wu.id] = 1;
        Next_Another_Menu(wk, Next_Action, Next_Menu);
    }
}

s32 ETC_Term_0000(PLW* wk, WORK* em) {
    if (Check_VS_Squat(wk, em, 0x1D, 0x21, 0x20) != 0) {
        return 1;
    }
    return 0;
}

s32 ETC_Term_0001(PLW* wk, WORK* em) {
    if (wk->sa->ok != -1) {
        return 1;
    }
    if (My_char[wk->wu.id] != 9) {
        return 1;
    }
    if (plw[wk->wu.id].sa->kind_of_arts) {
        return 1;
    }
    return 0;
}

s32 ETC_Term_0002(PLW* wk, WORK* em) {
    if (plw[wk->wu.id].wu.vital_new < 0x31) {
        return 1;
    }
    return 0;
}

s32 ETC_Term_0003(PLW* wk, WORK* em) {
    if ((em->pat_status != 0x20) && (em->pat_status != 0x21) && (em->pat_status != 2)) {
        return 1;
    }
    return 0;
}

s32 ETC_Term_0004(PLW* wk, WORK* em) {
    if (em->vital_new >= 0x50) {
        return 0;
    }
    if (plw[wk->wu.id].wu.vital_new < 0x78) {
        return 0;
    }
    return 1;
}

s32 ETC_Term_0005(PLW* wk, WORK* em) {
    if (em->vital_new < plw[wk->wu.id].wu.vital_new) {
        return 1;
    }
    return 0;
}

s32 ETC_Term_0006(PLW* wk, WORK* em) {
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        Timer_00[wk->wu.id] = 0x78;
        /* fallthrough */
    case 1:
        if (--Timer_00[wk->wu.id] == 0) {
            return 1;
        }
        if (PL_Distance[wk->wu.id] < 0x70) {
            return 1;
        }
        Lever_Buff[wk->wu.id] = 0x40;
        return -1;
    }
    return -1;
}

s32 ETC_Term_0007(PLW* wk, WORK* em) {
    if (plw[wk->wu.id].sa->kind_of_arts == 2) {
        return 1;
    }

    return 0;
}

s32 ETC_Term_0008(PLW* wk, WORK* em) {
    if (plw[wk->wu.id].sa->kind_of_arts == 1) {
        return 1;
    }

    return 0;
}

s32 ETC_Term_0009(PLW* wk, WORK* em) {
    if (plw[wk->wu.id].sa->kind_of_arts == 0) {
        return 1;
    }

    return 0;
}

s32 emLevelRemake(s32 now, s32 max, s32 exd) {
    s32 RemakeLevelForDifficulty[8] = { -30, -10, 0, 0, 0, 0, 20, 60 };
    s32 difficulty = save_w[Present_Mode].Difficulty;

    now += (max - exd) * RemakeLevelForDifficulty[difficulty] / 100;

    /* Xbox: in Japan the cap also drops by exd, by half of it at difficulty
       6 and not at all at 7. */
    if (Country == 1) {
        switch (difficulty) {
        case 6:
            exd >>= 1;
            /* fallthrough */
        default:
            max -= exd;
            break;
        case 7:
            break;
        }
    }

    if (now < 0) {
        now = 0;
    }
    if (now >= max) {
        now = max - 1;
    }

    return now;
}

s32 emGetMaxBlocking() {
    s32 RapidBlockingTimes[8] = { 2, 2, 3, 3, 3, 4, 6, 10 };

    return RapidBlockingTimes[save_w[Present_Mode].Difficulty];
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void Keep_Status(PLW* wk, u16 Lever_Data, s16 Option_Data) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Timer_00[wk->wu.id] = 0xA;

        Free_Lever[wk->wu.id] = Lever_Data;
        if (Option_Data != -1) {
            Free_Lever[wk->wu.id] |= Setup_Guard_Lever(wk, Option_Data);
        }
        Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];

        break;

    default:
        Lever_Buff[wk->wu.id] = Free_Lever[wk->wu.id];
        if (--Timer_00[wk->wu.id]) {
            break;
        }
        Timer_00[wk->wu.id] = 1;

        if (Attack_Flag[wk->wu.id] == 0) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;

            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;

            if (CP_No[wk->wu.id][0] != 6) {
                Passive_Flag[wk->wu.id] = 0;
            }
        }
        break;
    }
}

void VS_Jump_Guard(PLW* wk) {
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Guard(wk) == 0) {
            dash_flag_clear(wk->wu.id);
            CP_Index[wk->wu.id][1]++;
        }

        break;

    default:
        if (Check_Guard(wk) != 0) {
            break;
        }

        if (((WORK*)wk->wu.target_adrs)->xyz[1].disp.pos < 0x19) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;

            Passive_Flag[wk->wu.id] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
        }

        break;
    }
}

void Short_Range_Attack(PLW* wk, s16 Reaction, u16 Lever_Data, s16 Next_Action, s16 Next_Menu) {
#if defined(TARGET_PS2)
    u16 get_nearing_range(s32 pnum, s32 kos);
#endif

    u16 xx;

    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) == 0) {
            CP_Index[wk->wu.id][1]++;
            Check_First_Menu(wk);

            Ck_Distance_LvJ(wk);
            xx = get_nearing_range(wk->player_number, xx = Lever_Data & 0xFF0);
            if (PL_Distance[wk->wu.id] > xx) {
                Next_Another_Menu(wk, Next_Action, Next_Menu);
            }
        }

        break;

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id]) {
            break;
        }
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        break;

    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}

s32 Check_Term_ABS_Distance(PLW* wk) {
    if (Turn_Over[wk->wu.id]) {
        return 1;
    }

    if (My_char[wk->wu.id] == 5) {
        return 0;
    }

    if (PL_Distance[wk->wu.id] < 0x31) {
        return 1;
    }

    if (wk->wu.mvxy.a[1].real.h >= 0) {
        return 0;
    }

    if (wk->wu.xyz[1].disp.pos < 0x31) {
        return 1;
    }

    return 0;
}

s32 Ck_Distance_XX(s16 x1, s16 x2) {
    s16 xx;

    xx = x1 - x2;
    if (xx < 0) {
        xx = xx * -1;
    }

    return xx;
}
#endif
