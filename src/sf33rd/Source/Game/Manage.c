/* Manage.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Clear_1Stage_Work 0x64B90 size 0x4F.
 * Wait_Seek_Time 0x64BDF size 0x91.
 * Game_Manage_2_1 0x64C70 size 0x4C.
 * Game_Manage_2_2 0x64CBC size 0xCE.
 * Game_Manage_2_3 0x64D8A size 0x3F.
 * Game_Manage_5_0 0x64DC9 size 0x20.
 * Game_Manage_5_2 0x64DE9 size 0x19.
 * Game_Manage_5_4 0x64E02 size 0x60.
 * Game_Manage_5_5 0x64E62 size 0x36.
 * Game_Manage_5_6 0x64E98 size 0x31.
 * Game_Manage_7_0 0x64EC9 size 0x72.
 * Game_Manage_7_1 0x64F3B size 0x19.
 * Check_Disp_Combo 0x64F54 size 0x1E.
 * Game_Manage_7_3 0x64F72 size 0x62. Read against the x86: 0xFF is the s8
 * store of -1 to Event_Judge_Gals, as in the C.
 * Game_Manage_7_5 0x64FD4 size 0x20. Read against the x86: 0xFF is the s8
 * store of -1 to Event_Judge_Gals, as in the C.
 * Game_Manage_7_7 0x64FF4 size 0x17.
 * Game_Manage_7_9 0x6500B size 0x11.
 * Game_Manage_81_1 0x6501C size 0x19.
 * Game_Manage_81_2 0x65035 size 0x54.
 * Game_Manage_81_3 0x65089 size 0x20.
 * Game_Manage_9th 0x650D2 size 0x15E. Read against the x86: 0x208 is the
 * stride of save_w (indexed by Present_Mode), as in the C.
 * Check_Naming 0x65230 size 0x3D. Read against the x86: or cl, 0xFF loads the
 * -1 that the C stores in Rank_In.
 * Check_Ending_Sub 0x6526D size 0x18.
 * Setup_Comp_Bonus 0x65285 size 0x5A.
 * request_center_message 0x652DF size 0x11.
 * Check_Perfect 0x652F0 size 0x55.
 * Update_VS_Data 0x65345 size 0x192. Read against the x86: 0x208 is the stride
 * of save_w (indexed by Present_Mode), as in the C.
 * BGM_Fade_Sub 0x654D7 size 0x63.
 * BGM_Control 0x6553A size 0x73.
 * Setup_BGM_Fade_In 0x655AD size 0x1A.
 * Check_Stage_BGM 0x655C7 size 0x7E.
 * Control_Music_Fade 0x65645 size 0x16.
 * chkComWins 0x6565B size 0x24.
 * Update_BI_Term 0x6567F size 0x75.
 * Ck_Win_Record 0x656F4 size 0x99. Read against the x86: 0x208 is the stride
 * of save_w (indexed by Present_Mode), as in the C.
 * Update_Level_Control 0x6578D size 0x4A.
 * Judge_Next_Disposal 0x657D7 size 0x39. Read against the x86: 0x208 is the
 * stride of save_w (indexed by Present_Mode), as in the C.
 * Check_Entry_Again 0x65810 size 0x3F.
 * Loser_Sub 0x6584F size 0x4C.
 * Be_Continue 0x6589B size 0x3B.
 * Disp_Winner 0x658D6 size 0x53.
 * Pool_Score 0x65929 size 0x84. Read against the x86: 0xC350 is the 50000
 * perfect bonus, 0x64/0x1F4 the *100 and *500, 0x12C the *300 on round_timer's
 * high byte, 0x208 the save_w stride, and 0xFF the Time_Limit == -1 test.
 * Matches the C.
 * Judge_Winner 0x659AD size 0x73.
 * Check_Disp_Winner 0x65A20 size 0x5D. Read against the x86: 0x208 is the
 * stride of save_w (indexed by Present_Mode), as in the C.
 * Check_Fade_Out_BGM 0x65A7D size 0x45. Read against the x86: 0x208 is the
 * stride of save_w (indexed by Present_Mode), as in the C.
 * Check_BI_Grade 0x65AC2 size 0x3A. Read against the x86: 0xAC is the stride
 * of judge_final[PL_id]. Matches the C indexing. vs_cpu_grade is at +0x20,
 * read as [esi*2 + 0xC7EDE0], so judge_final is 0xC7EDC0 (the map row 0xC7EDDE
 * was index-biased).
 * Game_Manage_11th 0x65AFC size 0xD5. Read against the x86: 0xFF is the s8
 * store of -1 to Forbid_Break, as in the C.
 * Game_Manage_12_0 0x65BD1 size 0xF8.
 * Game_Manage_12_1 0x65CC9 size 0x2C.
 * Game_Manage_12_3 0x65CF5 size 0xB3.
 * Game_Manage_12_5 0x65DA8 size 0x4D.
 * Check_Bonus_Perfect 0x65DF5 size 0x2A.
 * Disp_Bonus_Perfect 0x65E1F size 0xEB.
 * Flash_Bonus_Perfect 0x65F0A size 0x18.
 * Setup_Final_Score 0x65F22 size 0x92. Read against the x86: 0x3E8 is the C's
 * *1000.
 * Bonus_Cut_Sub 0x65FB4 size 0xE5. Read against the x86: 0x3E8 is the C's
 * Stock_Bonus_Game_Result * 1000.
 * Check_Time_Over 0x66099 size 0x5A.
 * complete_victory_pause 0x660F3 size 0x8.
 * Game_Manage_1st 0x660FB size 0x1A5. Read against the x86: or cl, 0xFF loads
 * the -1 that the C stores in Request_Disp_Rank.
 * Game_Manage_2_0 0x662A0 size 0x56.
 * Game_Manage_2_4 0x662F6 size 0x18C.
 * setFinishType 0x66482 size 0x6A. Read against the x86: 0x208 is the stride
 * of save_w (indexed by Present_Mode), as in the C.
 * Game_Manage_5_1 0x664EC size 0x2C.
 * Game_Manage_5_3 0x66518 size 0x3E.
 * Game_Manage_5_7 0x66556 size 0x82. Read against the x86: or byte
 * [Round_Result+1], 0x80 is the C's Round_Result |= 0x8000.
 * Game_Manage_7_2 0x665D8 size 0x75.
 * Game_Manage_7_4 0x6664D size 0x36.
 * Game_Manage_7_8 0x66683 size 0x1E.
 * Game_Manage_81_0 0x666A1 size 0x167. Read against the x86: 0xFF is the s8
 * store of -1 to Forbid_Break, as in the C.
 * Game_Manage_8_2 0x66808 size 0x76.
 * Check_Ending 0x6687E size 0x107. Read against the x86: 0x208 is the save_w
 * stride, and -0x14 is a second save_w field written in the same loop. Matches
 * the C.
 * Additional_Bonus 0x66985 size 0x52.
 * Setup_Win_Mark 0x669D7 size 0xC0.
 * Check_Conclusion_Type 0x66A97 size 0x50.
 * Quick_Entry 0x66AE7 size 0x9C. Read against the x86: 0x208 is the save_w
 * stride, and 0x98 the stride of judge_item[Winner_id]. Matches the C.
 * Check_Break_Into_CPU 0x66B83 size 0xC2. Read against the x86: 0x80 on
 * Round_Result's high byte is Round_Result & 0x8000, and 0x208 is the save_w
 * stride. Matches the C.
 * Game_Manage_12_2 0x66C45 size 0xA3. Read against the x86: 0xFF is the s8
 * store of -1 to Forbid_Break, as in the C.
 * Game_Manage_12_4 0x66CE8 size 0x2C5.
 * Game_Manage_12_7 0x66FAD size 0x73. Read against the x86: 0xFF is the s8
 * store of -1 to Forbid_Break, as in the C.
 * Game_Manage_12_8 0x67020 size 0x212.
 * Game_Manage_2nd 0x67232 size 0x36.
 * Game_Manage_3rd 0x67268 size 0x31. Read against the x86: 0xFF is the s8
 * store of -1 to Forbid_Break, as in the C.
 * Game_Manage_4th 0x67299 size 0x173. Read against the x86: 0x208 is the
 * stride of save_w (indexed by Present_Mode), as in the C.
 * Game_Manage_5th 0x6740C size 0x4B.
 * Game_Manage_6th 0x67457 size 0xD5.
 * Game_Manage_7th 0x6752C size 0x59.
 * Game_Manage_8_0 0x67585 size 0x114. Read against the x86: 0x208 is the
 * stride of save_w (indexed by Present_Mode), as in the C.
 * Game_Manage_8_1 0x67699 size 0x2F.
 * Game_Manage_10th 0x676C8 size 0x17D.
 * Game_Manage_12th 0x67845 size 0x61.
 * Game_Manage_8th 0x678A6 size 0x2F.
 * Game_Management 0x678D5 size 0x93.
 * Game_Manage_7_6 is folded into 0x650A9 with 1 other bodies. Unnamed.
 * Game_Manage_8_3 is folded into 0x650A9 with 1 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * Game_Manage_13th.
 * BGM_Request is folded into 0x98407.
 * Sound_SE is folded into 0x98407.
 * grade_makeup_judgement_gals has no XBE name and no aligned call.
 * setup_bonus_car_parts is folded into 0x4384A.
 * setup_pos_remake_key is folded into 0x4384A.
 * Data: Disp_Bonus_Contents 0xC7E550.
 * Data: MANAGE_X 0xC7E551.
 * Data: Comp_Bonus_Data is 0x25F380, 0x2C bytes compared.
 * Data: BIC_SA_Data is 0x25F3AC, 0x8 bytes compared.
 * Data: Ball_Perfect_PTS is 0x25F3B4, 0x28 bytes compared.
 * Unnamed data used (not a difference): Update_BI_Term:
 * 0x7a876c,0x7a8764,0x7a88f4,0x7a8760; Check_Perfect: 0x7a88ae;
 * Check_Conclusion_Type: 0x7a87f0; Additional_Bonus:
 * 0x7a8a18,0x7a89c0,0x7a8920; Clear_1Stage_Work:
 * 0x7a81a8,0x7a80ba,0x7a8a18,0x7a89c0; Check_Break_Into_CPU: 0x7a81b8;
 * Pool_Score: 0x7a8920,0x7a89c0,0x7a8a18; Game_Manage_81_0:
 * 0x7a8920,0x7a89c0,0x7a8a18; Game_Manage_2_4: 0xc7d8ec; Setup_BGM_Fade_In:
 * 0x7a82ac; Quick_Entry: 0xc7f410; Judge_Winner: 0xc7f4c8,0xc7f4d2;
 * Be_Continue: 0x7a8468,0x7a8469,0x7a846a,0x7a846b; Check_Disp_Combo:
 * 0x7bc2d4,0x7bc2d6.
 * Globals: Comp_Bonus_Data 0x25F380, BIC_SA_Data 0x25F3AC, Ball_Perfect_PTS
 * 0x25F3B4, M_No 0x7A80B4, Event_Judge_Gals 0x7A810E, Player_id 0x7A810F,
 * EXE_obroll 0x7A8111, request_message 0x7A8112, My_char 0x7A8114, VS_Index
 * 0x7A811C, Bonus_Type 0x7A8120, EM_Rank 0x7A8124, VS_Win_Record 0x7A8128,
 * Perfect_Flag 0x7A812C, Play_Type 0x7A812D, Time_Over 0x7A8150,
 * gauge_stop_flag 0x7A8154, Stage_Continue 0x7A815C, Win_Record 0x7A8164,
 * Operator_Status 0x7A816A, Play_Mode 0x7A8178, Present_Mode 0x7A819C,
 * Stock_Bonus_Game_Result 0x7A81A4, Request_Break 0x7A81B0, Round_Result
 * 0x7A81B4, Music_Fade 0x7A81BA, Sel_PL_Complete 0x7A81BC, COM_id 0x7A81C0,
 * SC_Personal_Time 0x7A81D8, Control_Time 0x7A81EE, Cover_Timer 0x7A81F4,
 * Max_vitality 0x7A81F8, Bonus_Game_Complete 0x7A81FA, Bonus_Score 0x7A8208,
 * Mode_Type 0x7A825A, G_No 0x7A825C, Suicide 0x7A8268, Bonus_Stage_Level
 * 0x7A8270, Unit_Of_Timer 0x7A82A8, Stop_Update_Score 0x7A82AA,
 * Allow_a_battle_f 0x7A82B8, Conclusion_Type 0x7A82D0, Direction_Working
 * 0x7A82D8, Best_Grade 0x7A82E0, SA_shadow_on 0x7A82EE, Straight_Counter
 * 0x7A82FA, Stop_Combo 0x7A82FC, LOSER 0x7A82FD, CP_No 0x7A8308, message_index
 * 0x7A8310, Stock_Win_Record 0x7A8318, PL_Wins 0x7A832E, Counter_hi 0x7A8330,
 * Round_Operator 0x7A833C, Stock_Player_Color 0x7A8352, Battle_Country
 * 0x7A8356, Request_Disp_Rank 0x7A8360, Order 0x7A8380, Stop_SG 0x7A8428,
 * Bonus_Game_ex_result 0x7A842A, count_end 0x7A842C, Demo_Flag 0x7A842D,
 * Introduce_Boss 0x7A8454, Exit_No 0x7A8460, Scene_Cut 0x7A8461, Winner_id
 * 0x7A8472, Order_Timer 0x7A8480, Pause_ID 0x7A8514, End_Training 0x7A8515,
 * EM_id 0x7A8517, Fade_Flag 0x7A851A, Appear_Q 0x7A85C6, Order_Dir 0x7A85E0,
 * Break_Com 0x7A8680, win_type 0x7A86B0, C_No 0x7A86C4, Next_Step 0x7A86D2,
 * Lost_Round 0x7A86D4, New_Challenger 0x7A86D6, Continue_Coin 0x7A86E0, Score
 * 0x7A8720, Disp_Score_Buff 0x7A8738, Lever_LR 0x7A874C, Loser_id 0x7A875C,
 * Round_Level 0x7A876A, C_Timer 0x7A8794, Result_Timer 0x7A87C0,
 * Sel_Arts_Complete 0x7A87E0, Rank_In 0x7A87E8, Message_Suicide 0x7A87F8,
 * BGM_No 0x7A87FC, Break_Into 0x7A8802, judge_flag 0x7A8803, Forbid_Break
 * 0x7A8804, Round_num 0x7A8818, Bonus_Game_result 0x7A881A, Pause_Hit_Marks
 * 0x7A88AC, EM_History 0x7A88C0, Conclusion_Flag 0x7A88D4, Limit_Time
 * 0x7A88D6, E_07_Flag 0x7A88EC, Lag_Timer 0x7A8904, Player_Color 0x7A8906,
 * paring_ctr_vs 0x7A8908, Final_Bonus_Score 0x7A890C, G_Timer 0x7A8912,
 * Time_Stop 0x7A8918, Continue_Count_Down 0x7A891A, Disp_Cockpit 0x7A8930,
 * Champion 0x7A8931, PB_Status 0x7A8932, Extra_Break 0x7A89A0, Game_pause
 * 0x7A89B0, Stock_My_char 0x7A89B8, WINNER 0x7A89BD, End_PL 0x7A89CC,
 * Continue_Count 0x7A89D2, E_No 0x7A89F8, Complete_Judgement 0x7A8A02,
 * Complete_Victory 0x7A8A04, Lag_Ptr 0x7A8A08, Break_Into_CPU 0x7A8A25,
 * round_timer 0x7AAC38, bg_app 0x7BC4A8, seraph_flag 0x7BC4F4, bg_w 0x7BC520,
 * Appear_end 0x7BCC94, save_w 0x7BD3E0, task 0x7BE020, omop_cockpit 0x7C5C6C,
 * plw 0xC7CEA0, win_sp_flag 0xC7D8E0, sag_inc_timer 0xC7D8E4, appear_type
 * 0xC7D8E8, pcon_rno 0xC7E020, Disp_Bonus_Contents 0xC7E550, MANAGE_X
 * 0xC7E551, judge_final 0xC7EDC0.
 */

#include "structs.h"

void sub_00098407();
void sub_0004384A();
void Game_Manage_1st();
void Game_Manage_2nd();
void Game_Manage_3rd();
void Game_Manage_4th();
void Game_Manage_5th();
void Game_Manage_6th();
void Game_Manage_7th();
void Game_Manage_8th();
void Game_Manage_9th();
void Game_Manage_10th();
void Game_Manage_11th();
void Game_Manage_12th();
void Game_Manage_13th();
extern s8 Break_Into;
extern u8 C_No[4];
void BGM_Fade_Sub();
void BGM_Control();
s32 Switch_Screen(u8 Wipe_Type);
extern s8 EXE_obroll;
extern BG bg_w;
extern s8 win_pause_go;
void appear_work_clear();
extern u8 win_sp_flag;
extern u8 BGM_No[2];
extern u8 Appear_Q;
void Clear_1Stage_Work();
void All_Clear_Suicide();
extern s8 Round_Operator[2];
extern PLW plw[2];
extern u8 Final_Play_Type[2];
extern u8 Play_Type;
extern u8 Battle_Q[2];
extern s16 Control_Time;
extern u16 SC_Personal_Time[2];
extern s8 Player_id;
extern u8 paring_ctr_ori[2];
extern u8 paring_ctr_vs[2][2];
extern u32 Stage_Stock_Score[2];
extern u32 Score[2][3];
extern s8 Request_Disp_Rank[2][4];
extern s8 COM_id;
extern s8 EM_id;
extern s8 Break_Into_CPU;
void eff_hit_flag_clear();
void Check_Stage_BGM();
void Pause_Family_On();
extern s8 Fade_Flag;
void Clear_Flash_No();
extern s8 seraph_flag;
void grade_check_work_stage_init(s16 ix);
extern u8 Mode_Type;
void cpReadyTask(u16 num, void* func_adrs);
void Menu_Task(struct _TASK* task_ptr);
extern struct _TASK task[11];
extern s8 New_Challenger;
extern s8 Operator_Status[2];
extern u16 Lever_LR[2];
extern void Pause_Task(struct _TASK*);
extern u32 Vital_Bonus[2];
extern u32 Time_Bonus[2];
extern u32 Perfect_Bonus[2];
extern u8 Perfect_Counter[2];
extern s8 Stage_SA_Finish[2];
extern s8 Stage_Lost_Round[2];
extern s8 Stage_Perfect_Finish[2];
extern s8 Stage_Cheap_Finish[2];
extern u8 Stage_Time_Finish[2];
extern u8 Disp_Cockpit;
void Game_Manage_2_0();
void Game_Manage_2_1();
void Game_Manage_2_2();
void Game_Manage_2_3();
void Game_Manage_2_4();
extern s8 request_message;
extern s8 SA_shadow_on;
extern s8 Demo_Flag;
extern s8 Cover_Timer;
s32 Wait_Seek_Time();
void Switch_Screen_Init(s32 );
extern u8 Play_Mode;
extern s16 Separate_Area[2][3];
extern s16 Shell_Separate_Area[2][3];
extern u8* Lag_Ptr;
extern s8 Lag_Timer;
s32 Switch_Screen_Revival(u8 Wipe_Type);
extern s8 Suicide[8];
extern u8 Message_Suicide[4];
s32 effect_84_init();
extern s8 Forbid_Break;
extern u8 Extra_Break;
extern s8 Complete_Victory;
extern u8 Conclusion_Flag;
extern s8 Perfect_Flag;
extern u16 Round_Result;
extern s8 Reserve_Cut;
extern s8 Next_Step;
extern s8 judge_flag;
extern s8 Stop_Combo;
extern s8 Stop_SG;
extern s8 Complete_Judgement;
extern s8 Music_Fade;
extern u8 Pause_Hit_Marks;
extern u8 count_end;
extern s16 sag_inc_timer[2];
extern u8 CP_No[2][4];
extern u32 Stock_Score[2];
void grade_check_work_round_init(s16 ix);
extern s16 Appear_end;
extern s8 bg_app;
extern s16 pcon_rno[4];
s32 effect_B2_init();
extern u8 Round_num;
extern s16 C_Timer;
void FadeInit();
s32 FadeOut(u8 type, u8 step, u8 priority);
extern u8 Game_pause;
extern s16 appear_type;
void erase_extra_plef_work();
void compel_bg_init_position();
void win_lose_work_clear();
extern u8 Allow_a_battle_f;
extern u16 vital_inc_timer;
extern u16 vital_dec_timer;
extern u8 My_char[2];
extern u8 Introduce_Boss[2][2];
s32 effect_58_init(s16 id, s16 time0, s16 option);
void Check_Conclusion_Type();
extern u8 PL_Wins[2];
extern s8 Winner_id;
extern struct _SAVE_W save_w[6];
extern u8 Present_Mode;
extern s16 VS_Index[2];
extern u8 E_Number[2][4];
extern s8 Loser_id;
void Update_BI_Term();
extern u8 Conclusion_Type;
void Setup_Win_Mark();
void Check_Perfect(s16 PL_id);
void Update_Level_Control();
void Update_VS_Data();
void Ck_Win_Record();
void SsRequest(u16 ReqNumber);
s32 Judge_Next_Disposal();
extern u8 win_type[2][4];
void Game_Manage_5_0();
void Game_Manage_5_1();
void Game_Manage_5_2();
void Game_Manage_5_3();
void Game_Manage_5_4();
void Game_Manage_5_5();
void Game_Manage_5_6();
void Game_Manage_5_7();
extern s8 Event_Judge_Gals;
s32 Button_Cut_EX(s16* Timer, s16 Limit_Time);
void request_center_message(s16 Kind_of_Message);
void Judge_Winner();
void chkComWins();
void SsBgmFadeOut(u16 time);
s32 effect_J4_init(u8 data2);
extern u8 BGM_Timer[2];
extern s8 Fade_Half_Flag;
void grade_makeup_round_para_dko();
extern s16 omop_cockpit;
s32 effect_92_init(s16 PL_id, s16 win_number);
extern u8 End_Training;
void Quick_Entry();
void Game_Manage_7_0();
void Game_Manage_7_1();
void Game_Manage_7_2();
void Game_Manage_7_3();
void Game_Manage_7_4();
void Game_Manage_7_5();
void Game_Manage_7_6();
void Game_Manage_7_7();
void Game_Manage_7_8();
void Game_Manage_7_9();
void grade_makeup_round_parameter(s16 ix);
s32 Check_Disp_Combo();
s32 Check_Disp_Winner();
void Disp_Winner();
void Check_Fade_Out_BGM(s16 Time);
extern s8 cmb_all_stock[];
extern s8 cmb_calc_now[];
extern u8 Scene_Cut;
void Game_Manage_8_0();
void Game_Manage_8_1();
void Game_Manage_8_2();
void Game_Manage_8_3();
extern u8 Stop_Update_Score;
void Pool_Score(s16 PL_id);
void Additional_Bonus(s16 PL_id);
extern s8 WINNER;
void grade_makeup_stage_parameter(s16 ix);
extern s8 LOSER;
s32 Check_Break_Into_CPU(s16 PL_id);
void Game_Manage_81_0();
void Game_Manage_81_1();
void Game_Manage_81_2();
void Game_Manage_81_3();
extern u8 Order[148];
extern u8 Order_Timer[148];
extern u8 Order_Dir[148];
s32 effect_76_init(s16 dir_old);
s32 effect_G0_init(s16 Order, s16 Time, u32 Score, s16 Pos_Index);
extern u32 Complete_Bonus;
extern s8 Request_Break[2];
s32 Check_Entry_Again();
extern u16 gauge_stop_flag[2];
void cpExitTask(u16 num);
extern u8 G_No[4];
extern s16 G_Timer;
void pulpul_stop();
void effect_work_quick_init();
void SE_All_Off();
void Check_Naming(s16 PL_id);
extern u8 Continue_Coin2[2];
extern u8 M_No[4];
extern u8 E_No[4];
s32 Check_Ending();
extern s8 E_07_Flag[2];
extern s8 Rank_In[2][4];
s32 Check_Ending_Sub();
extern s8 Break_Com[2][20];
extern u8 Pause_ID;
extern u8 End_PL;
void SsBgmControl(s8 , s8 VOLUME);
void Ending_init();
extern u8 Stock_My_char[2];
extern s8 Stock_Player_Color[2];
extern s8 Player_Color[2];
extern u8 Direction_Working[6];
s32 Check_Extra_Setting();
extern s8 Debug_w[72];
u32 Setup_Comp_Bonus();
extern u8 Straight_Counter[2];
extern u8 message_index;
void Finish_SE();
void Control_Music_Fade(s16 Time);
extern u8 Shin_Gouki_BGM;
extern u8 Stage_Continue[2];
extern s16 Stock_Com_Color[2];
extern s8 Stock_Com_Arts[2];
extern u8 EM_History[2][10];
extern u16 Result_Timer[2];
extern u8 Straight_Flag[2];
extern s16 Round_Level;
extern u16 Win_Record[2];
extern volatile s8 BGM_Vol;
void Stage_BGM(u16 Stage_Number, u16 Round_Number);
extern s8 PB_Music_Off;
extern s8 Lost_Round[2];
extern s8 Super_Arts_Finish[2];
extern s8 Perfect_Finish[2];
extern s8 Cheap_Finish[2];
extern u16 Stock_Win_Record[2];
extern u16 VS_Win_Record[2];
extern s16 Limit_Time;
void Loser_Sub();
void Be_Continue();
extern GradeData judge_item[2][2];
extern s8 Best_Grade[2];
extern s16 Sel_PL_Complete[2];
extern s16 Sel_Arts_Complete[2];
extern u8 Continue_Count_Down[2];
extern s8 Continue_Count[2];
s32 effect_56_init(u8 type, u8 kill);
extern s16 Max_vitality;
extern Round_Timer round_timer;
extern u8 Continue_Coin[2];
extern GradeFinalData judge_final[2][2];
s32 Check_BI_Grade(s16 PL_id);
void grade_makeup_judgement_gals();
extern JudgeGals judge_gals[2];
extern s8 Champion;
extern s8 Disp_Win_Name;
extern s8 EM_Rank;
extern u8 Q_Country;
extern s16 Battle_Country;
s32 effect_81_init(s16 Time);
void effect_work_kill_mod_plcol();
void Game_Manage_12_0();
void Game_Manage_12_1();
void Game_Manage_12_2();
void Game_Manage_12_3();
void Game_Manage_12_4();
void Game_Manage_12_5();
void Game_Manage_12_7();
void Game_Manage_12_8();
extern u8 Bonus_Type;
void bcounter_write();
extern s8 Time_Stop;
extern s8 Time_Over;
extern u8 Exit_No;
extern s16 Unit_Of_Timer;
void bcount_cont_init();
void bcount_cont_main();
extern s8 Bonus_Game_Complete;
extern s8 Completion_Bonus[2][2];
extern s16 Stock_Bonus_Game_Result;
extern s16 Bonus_Game_result;
extern u32 Bonus_Score;
extern u32 Final_Bonus_Score;
u32 Setup_Final_Score(s16 Type);
void grade_makeup_bonus_parameter(s16 ix);
u8 Check_Bonus_Perfect();
s16 Cut_Cut_C_Timer();
s32 Bonus_Cut_Sub();
s32 effect_08_init(s8 sc_num, s8 x, s8 y, u16 atr, s16 color_type);
extern u32 Disp_Score_Buff[2];
s32 effect_14_init(s16 id, s16 x, s16 y, s16 atr);
extern u8 PB_Status;
void Disp_Bonus_Perfect();
extern s16 Bonus_Stage_Level;
void Flash_Bonus_Perfect();
s16 Check_Time_Over();
s32 effect_35_init(s16 wait_timer, s16 c_type);
s16 bcounter_down(u8 kind);
extern s16 Bonus_Game_ex_result;
extern s8 Counter_hi;
extern u32 Bonus_Score_Plus;

extern u8 Disp_Bonus_Contents;

extern s8 MANAGE_X;

const u32 Comp_Bonus_Data[11] = { 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000, 110000, 120000, 130000 };

const u8 BIC_SA_Data[2][4] = { { 3, 5, 7, 9 }, { 1, 1, 1, 1 } };

const u32 Ball_Perfect_PTS[2][5] = { { 20000, 30000, 50000, 80000, 120000 }, { 10000, 20000, 40000, 80000, 160000 } };

;

s32 Game_Management() {
    void (*Management_Jmp_Tbl[13])() = { Game_Manage_1st, Game_Manage_2nd,  Game_Manage_3rd,  Game_Manage_4th,
                                         Game_Manage_5th, Game_Manage_6th,  Game_Manage_7th,  Game_Manage_8th,
                                         Game_Manage_9th, Game_Manage_10th, Game_Manage_11th, Game_Manage_12th,
                                         Game_Manage_13th };

    if (Break_Into) {
        return 0;
    }

    MANAGE_X = 0;
    Management_Jmp_Tbl[C_No[0]]();
    BGM_Fade_Sub();
    BGM_Control();
    return MANAGE_X;
}

void Game_Manage_1st() {
    Switch_Screen(0);
    EXE_obroll = 0;

    if (bg_w.stage == 21 || bg_w.stage == 20) {
        C_No[0] = 11;
    } else {
        C_No[0] = 1;
    }

    win_pause_go = 0;
    appear_work_clear();
    win_sp_flag = 0;
    BGM_No[1] = 0;
    BGM_No[0] = 0;
    Appear_Q = 0;
    Clear_1Stage_Work();
    All_Clear_Suicide();
    Round_Operator[0] = 0;
    Round_Operator[1] = 0;

    if (plw[0].wu.operator) {
        Round_Operator[0] = 1;
        Final_Play_Type[0] = Play_Type;
    }

    if (plw[1].wu.operator) {
        Round_Operator[1] = 1;
        Final_Play_Type[1] = Play_Type;
    }

    Battle_Q[0] = 0;
    Battle_Q[1] = 0;

    if (Play_Type == 0) {
        Control_Time = SC_Personal_Time[Player_id];
        paring_ctr_ori[Player_id] = paring_ctr_vs[0][Player_id] = 0;
        Stage_Stock_Score[Player_id] = Score[Player_id][0];
        Request_Disp_Rank[COM_id][0] = -1;
        Request_Disp_Rank[COM_id][1] = -1;
        Request_Disp_Rank[COM_id][2] = -1;
        Request_Disp_Rank[COM_id][3] = -1;

        if (EM_id == 17) {
            Break_Into_CPU = 2;
        } else {
            Break_Into_CPU = 0;
        }
    }

    eff_hit_flag_clear();
    Check_Stage_BGM();
    Pause_Family_On();
    Fade_Flag = 0;
    Clear_Flash_No();
    seraph_flag = 0;
    grade_check_work_stage_init(0);
    grade_check_work_stage_init(1);

    if (Mode_Type == 3 || Mode_Type == 4) {
        cpReadyTask(3, Menu_Task);
        task[3].r_no[0] = 7;
        plw[New_Challenger].wu.operator = 0;
        Operator_Status[New_Challenger] = 0;
        Lever_LR[0] = 0;
        Lever_LR[1] = 0;
        return;
    }

    if (Mode_Type != 2) {
        cpReadyTask(4, Pause_Task);
        sub_0004384A(3);
    }
}

void Clear_1Stage_Work() {
    s16 xx;

    for (xx = 0; xx < 2; xx++) {
        Vital_Bonus[xx] = 0;
        Time_Bonus[xx] = 0;
        Perfect_Bonus[xx] = 0;
        Perfect_Counter[xx] = 0;
        Stage_SA_Finish[xx] = 0;
        Stage_Lost_Round[xx] = 0;
        Stage_Perfect_Finish[xx] = 0;
        Stage_Cheap_Finish[xx] = 0;
        Stage_Time_Finish[xx] = 0;
    }

    Disp_Cockpit = 0;
}

void Game_Manage_2nd() {
    void (*SC2_Jmp_Tbl[5])() = { Game_Manage_2_0, Game_Manage_2_1, Game_Manage_2_2, Game_Manage_2_3, Game_Manage_2_4 };

    SC2_Jmp_Tbl[C_No[1]]();
}

void Game_Manage_2_0() {
    Switch_Screen(0);
    request_message = 0;
    SA_shadow_on = 0;

    if (Demo_Flag == 0) {
        C_No[1] = 2;
        return;
    }

    if (--Cover_Timer > 0) {
        return;
    }

    if (Wait_Seek_Time() == 0) {
        Cover_Timer = 1;
        return;
    }

    C_No[1]++;
    Switch_Screen_Init(0);
}

s32 Wait_Seek_Time() {
    s16 ix;
    s16 ix2;

    switch (Play_Mode) {
    case 1:
        if (Mode_Type != 2) {
            for (ix = 0; ix < 2; ix++) {
                for (ix2 = 0; ix2 < 3; ix2++) {
                    Separate_Area[ix][ix2] = 0;
                    Shell_Separate_Area[ix][ix2] = 0;
                }
            }

            return 1;
        }

        Lag_Ptr[0] = Lag_Timer;
        Lag_Ptr++;
        Lag_Timer = 1;
        return 1;

    case 3:
        if (Mode_Type == 3) {
            return 1;
        }

        if (Mode_Type == 4) {
            return 1;
        }

        for (ix = 0; ix < 2; ix++) {
            for (ix2 = 0; ix2 < 3; ix2++) {
                Separate_Area[ix][ix2] = 0;
                Shell_Separate_Area[ix][ix2] = 0;
            }
        }

        if (--Lag_Timer == 0) {
            Lag_Timer = Lag_Ptr[0];
            Lag_Ptr++;
            return 1;
        }

        return 0;

    default:
        return 1;
    }
}

void Game_Manage_2_1() {
    switch (C_No[2]) {
    case 0:
        if (!Switch_Screen_Revival(0)) {
            break;
        }

        if (Mode_Type == 3 || Mode_Type == 4) {
            C_No[2]++;
            break;
        }

        C_No[1]++;

        break;

    case 1:
        if (task[3].r_no[0] == 10) {
            C_No[1]++;
            C_No[2] = 0;
        }

        break;
    }
}

void Game_Manage_2_2() {
    s16 ix;

    Suicide[0] = 0;
    Suicide[6] = 0;

    for (ix = 0; ix < 4; ix++) {
        Message_Suicide[ix] = 0;
    }

    if (effect_84_init()) {
        return;
    }

    C_No[1]++;
    Forbid_Break = 0;
    Extra_Break = 0;
    Complete_Victory = 0;
    Conclusion_Flag = 0;
    Perfect_Flag = 0;
    Round_Result = 0;
    Reserve_Cut = 0;
    Next_Step = 0;
    judge_flag = 0;
    Stop_Combo = 0;

    if (Demo_Flag) {
        Stop_SG = 0;
    }

    Complete_Judgement = 0;
    Music_Fade = 0;
    Pause_Hit_Marks = 0;
    count_end = 0;
    sag_inc_timer[0] = sag_inc_timer[1] = 0;
    CP_No[0][0] = 0;
    CP_No[1][0] = 0;
    Stock_Score[0] = Score[0][0];
    Stock_Score[1] = Score[1][0];
    grade_check_work_round_init(0);
    grade_check_work_round_init(1);
}

void Game_Manage_2_3() {
    if (Appear_end < 2) {
        return;
    }

    if (bg_app) {
        return;
    }

    appear_work_clear();
    win_sp_flag = 0;

    if (pcon_rno[0] != 0) {
        return;
    }

    if (pcon_rno[1] != 1) {
        return;
    }

    C_No[1]++;
    effect_B2_init();
}

void Game_Manage_2_4() {
    switch (C_No[2]) {
    case 0:
        if (Round_num) {
            C_No[2] = 3;
            return;
        }

        C_No[2]++;
        C_Timer = 3;
        Forbid_Break = 1;
        FadeInit();
        FadeOut(0, 0xFF, 8);
        Disp_Cockpit = 1;

        if (Mode_Type == 3 || Mode_Type == 4) {
            Score[0][2] = 0;
            Score[1][2] = 0;
            Game_pause = 0;
            pcon_rno[0] = 0;
            pcon_rno[1] = 0;
            pcon_rno[2] = 0;
            pcon_rno[3] = 0;
            appear_type = 0;
            erase_extra_plef_work();
            compel_bg_init_position();
            win_lose_work_clear();
        }

        break;

    case 1:
        FadeOut(0, 0xFF, 8);

        if (--C_Timer == 0) {
            C_No[2]++;
            Clear_Flash_No();
        }

        break;

    case 2:
        C_No[2]++;
        Forbid_Break = 0;
        break;

    case 3:
        if (Next_Step == 0) {
            break;
        }

        C_No[0]++;
        C_No[1] = 0;
        C_No[2] = 0;
        Allow_a_battle_f = 1;
        vital_inc_timer = 50;
        vital_dec_timer = 40;
        sag_inc_timer[0] = sag_inc_timer[1] = 0;

        if (Play_Type == 0 && (EM_id == 0 || (My_char[Player_id] == 0 && EM_id == 1)) &&
            !(Introduce_Boss[Player_id][1] & 0x80)) {
            Introduce_Boss[Player_id][1] |= 128;
            Check_Stage_BGM();
        }

        if (Demo_Flag == 0) {
            effect_58_init(10, 60, 0);
        }

        break;
    }
}

void Game_Manage_3rd() {
    if (Demo_Flag == 0) {
        return;
    }

    if (Conclusion_Flag == 0) {
        return;
    }

    C_No[0]++;
    Forbid_Break = -1;
    Allow_a_battle_f = 0;
    count_end = 1;
    Check_Conclusion_Type();
}

void setFinishType() {
    if (Play_Type == 0 && Mode_Type == 0 && PL_Wins[Winner_id] >= save_w[Present_Mode].Battle_Number[Play_Type] &&
        VS_Index[Winner_id] > 8 && plw[Winner_id].wu.operator != 0 && E_Number[Loser_id][0] != 2) {
        E_Number[Loser_id][0] = 99;
    }

    Update_BI_Term();
}

void Game_Manage_4th() {
    switch (Conclusion_Type) {
    case 0:
        C_No[0] = 6;
        Setup_Win_Mark();
        Check_Perfect(Winner_id);
        setFinishType();
        PL_Wins[Winner_id]++;
        Update_Level_Control();
        Update_VS_Data();
        Ck_Win_Record();
        break;

    case 1:
        SsRequest(121);
        SsRequest(139);

        if (Judge_Next_Disposal()) {
            C_No[0] = 4;
            break;
        }

        C_No[0] = 5;
        Round_Result |= 1024;
        setFinishType();
        win_type[0][PL_Wins[0]] = 5;
        win_type[1][PL_Wins[1]] = 5;
        PL_Wins[0]++;
        PL_Wins[1]++;

        if (PL_Wins[0] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            Winner_id = 0;
            Loser_id = 1;
            Update_VS_Data();
            Ck_Win_Record();
            break;
        }

        if (PL_Wins[1] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            Winner_id = 1;
            Loser_id = 0;
            Update_VS_Data();
            Ck_Win_Record();
        }

        break;

    default:
        SsRequest(143);

        if (plw[0].wu.vital_new != plw[1].wu.vital_new || Mode_Type == 3 || Mode_Type == 4) {
            C_No[0] = 6;
            Round_Result |= 1;
            setFinishType();
            win_type[Winner_id][PL_Wins[Winner_id]] = 1;
            Check_Perfect(Winner_id);
            PL_Wins[Winner_id]++;
            Update_Level_Control();
            Update_VS_Data();
            Ck_Win_Record();
            break;
        }

        C_No[0] = 4;
        break;
    }
}

void Game_Manage_5th() {
    void (*SC5_Jmp_Tbl[8])() = { Game_Manage_5_0, Game_Manage_5_1, Game_Manage_5_2, Game_Manage_5_3,
                                 Game_Manage_5_4, Game_Manage_5_5, Game_Manage_5_6, Game_Manage_5_7 };

    SC5_Jmp_Tbl[C_No[1]]();
}

void Game_Manage_5_0() {
    if (Complete_Victory) {
        C_No[1]++;
        C_Timer = 30;
        Event_Judge_Gals = 0;
    }
}

void Game_Manage_5_1() {
    if (Button_Cut_EX(&C_Timer, 10)) {
        C_No[1]++;
        request_center_message(3);
        SsRequest(154);
    }
}

void Game_Manage_5_2() {
    if (!request_message) {
        C_No[1]++;
        C_Timer = 30;
    }
}

void Game_Manage_5_3() {
    if (Button_Cut_EX(&C_Timer, 10)) {
        C_No[1]++;
        Judge_Winner();
        chkComWins();
        Stop_Combo = 1;
        Switch_Screen_Init(0);
        SsBgmFadeOut(2048);
    }
}

void Game_Manage_5_4() {
    if (Switch_Screen(0)) {
        C_No[1]++;
        Cover_Timer = 5;
        Suicide[6] = 1;
        judge_flag = 1;
        effect_J4_init(0xFF);
        compel_bg_init_position();
        pcon_rno[0] = 0;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
        pcon_rno[3] = 0;
        appear_type = 3;
    }
}

void Game_Manage_5_5() {
    Switch_Screen(0);

    if (--Cover_Timer == 0) {
        C_No[1]++;
        pcon_rno[1] = 3;
        pcon_rno[2] = 1;
        Clear_Flash_No();
        Switch_Screen_Init(0);
    }
}

void Game_Manage_5_6() {
    if (Switch_Screen_Revival(0)) {
        C_No[1]++;
        C_Timer = 60;
        Stop_SG = 0;
        BGM_No[0] = 3;
        BGM_Timer[0] = 1;
    }
}

void Game_Manage_5_7() {
    if (--C_Timer != 0) {
        return;
    }

    if (Wait_Seek_Time() == 0) {
        C_Timer = 1;
        return;
    }

    C_No[0] = 6;
    C_No[1] = 7;
    C_Timer = 30;
    Fade_Half_Flag = 1;
    Complete_Judgement = 1;
    Round_Result |= 0x8000;
    win_type[Winner_id][PL_Wins[Winner_id]] = 6;
    setFinishType();
    Check_Perfect(Winner_id);
    PL_Wins[Winner_id]++;
    Update_Level_Control();
    Update_VS_Data();
}

void Game_Manage_6th() {
    switch (C_No[1]) {
    case 0:
        if (!Complete_Victory) {
            break;
        }

        C_No[1]++;
        C_Timer = 60;
        pcon_rno[1] = 3;
        pcon_rno[2] = 0;
        grade_makeup_round_para_dko();

        if (Mode_Type != 3 && Mode_Type != 4 && omop_cockpit) {
            effect_58_init(6, 1, Winner_id + 100);
            effect_92_init(0, PL_Wins[0] - 1);
            effect_92_init(1, PL_Wins[1] - 1);
            break;
        }

        break;

    case 1:
        if (--C_Timer != 0) {
            break;
        }

        if (Mode_Type == 3 || Mode_Type == 4) {
            C_No[0] = 12;
            End_Training = 1;
            break;
        }

        C_No[0] = 7;
        C_No[1] = 0;
        Round_num++;
        Quick_Entry();
        break;
    }
}

void Game_Manage_7th() {
    void (*SC7_Jmp_Tbl[10])() = { Game_Manage_7_0, Game_Manage_7_1, Game_Manage_7_2, Game_Manage_7_3, Game_Manage_7_4,
                                  Game_Manage_7_5, Game_Manage_7_6, Game_Manage_7_7, Game_Manage_7_8, Game_Manage_7_9 };

    SC7_Jmp_Tbl[C_No[1]]();
}

void Game_Manage_7_0() {
    if (!Complete_Victory) {
        return;
    }

    C_No[1]++;
    C_Timer = 1;
    grade_makeup_round_parameter(Winner_id);

    if (Mode_Type != 3 && Mode_Type != 4 && omop_cockpit) {
        effect_58_init(6, 1, Winner_id + 100);
        effect_92_init(Winner_id, PL_Wins[Winner_id] - 1);
    }
}

void Game_Manage_7_1() {
    if (--C_Timer == 0) {
        C_No[1]++;
        C_Timer = 10;
    }
}

void Game_Manage_7_2() {
    if (!Button_Cut_EX(&C_Timer, 0x7FFF)) {
        return;
    }

    if (Check_Disp_Combo()) {
        C_Timer = 1;
        return;
    }

    C_No[1]++;

    if (Check_Disp_Winner() == 0) {
        C_Timer = 50;
    } else {
        Disp_Winner();
        C_Timer = 90;
    }

    if (Round_Operator[Winner_id] == 0 && Perfect_Flag == 0) {
        Check_Fade_Out_BGM(182);
    }
}

s32 Check_Disp_Combo() {
    if (cmb_all_stock[0] != 0 || cmb_calc_now[0] != 0 || cmb_calc_now[1] != 0) {
        return 1;
    }

    if (PL_Wins[Winner_id] < save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
        return 0;
    }

    return 0;
}

void Game_Manage_7_3() {
    if (Play_Type == 0 && Perfect_Flag == 0) {
        if (--C_Timer) {
            return;
        }
    } else {
        if (--C_Timer) {
            return;
        }
    }

    Message_Suicide[1] = 1;

    if (Mode_Type == 3 || Mode_Type == 4) {
        C_No[0] = 12;
        End_Training = 1;
        return;
    }

    if (Perfect_Flag) {
        C_No[1]++;
        C_Timer = 10;
        return;
    }

    C_No[0]++;
    C_No[1] = 0;
    Event_Judge_Gals = -1;
}

void Game_Manage_7_4() {
    if (--C_Timer == 0) {
        C_No[1]++;
        request_center_message(4);
        effect_58_init(6, 1, 155);
        effect_58_init(6, 60, 156);
    }
}

void Game_Manage_7_5() {
    if (!request_message) {
        C_No[1]++;
        C_Timer = 6;
        Event_Judge_Gals = -1;
    }
}

void Game_Manage_7_6() {
    if (Scene_Cut) {
        C_Timer = 1;
    }

    if (--C_Timer == 0) {
        C_No[0]++;
        C_No[1] = 0;
    }
}

void Game_Manage_7_7() {
    if (--C_Timer == 0) {
        C_No[1]++;
        Event_Judge_Gals = 3;
    }
}

void Game_Manage_7_8() {
    if (Event_Judge_Gals == 0) {
        C_No[1]++;
        C_Timer = 30;
        Ck_Win_Record();
    }
}

void Game_Manage_7_9() {
    if (--C_Timer == 0) {
        C_No[1] = 0;
    }
}

void Game_Manage_8th() {
    void (*SC8_Jmp_Tbl[4])() = { Game_Manage_8_0, Game_Manage_8_1, Game_Manage_8_2, Game_Manage_8_3 };

    SC8_Jmp_Tbl[C_No[1]]();
}

void Game_Manage_8_0() {
    Round_num++;
    Quick_Entry();
    Stop_Update_Score = 1;

    if (Round_Operator[Winner_id] != 0 || Mode_Type == 1 || Mode_Type == 5) {
        Pool_Score(Winner_id);

        if (PL_Wins[Winner_id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            C_No[1]++;
            Additional_Bonus(WINNER);
            grade_makeup_stage_parameter(WINNER);
            grade_makeup_stage_parameter(LOSER);
            Check_Break_Into_CPU(WINNER);
            return;
        }

        C_No[1] = 3;
        C_Timer = 1;
        return;
    }

    C_No[1] = 3;
    C_Timer = 30;

    if (PL_Wins[Winner_id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
        grade_makeup_stage_parameter(WINNER);
        grade_makeup_stage_parameter(LOSER);
    }
}

void Game_Manage_8_1() {
    void (*SC81_Jmp_Tbl[4])() = { Game_Manage_81_0, Game_Manage_81_1, Game_Manage_81_2, Game_Manage_81_3 };

    SC81_Jmp_Tbl[C_No[2]]();
}

void Game_Manage_81_0() {
    s16 ix;
    s16 time;
    s16 pos_id;
    s16 pos_id2;

    Check_Fade_Out_BGM(546);
    C_No[2]++;
    C_Timer = 20;
    Forbid_Break = -1;
    ix = 0;
    pos_id = 0;
    pos_id2 = 0;
    time = 1;
    Order[74] = 1;
    Order_Timer[74] = time;
    Order_Dir[74] = pos_id++;
    effect_76_init(74);
    time += 5;

    if (Perfect_Flag) {
        Order[76] = 1;
        Order_Timer[76] = time;
        Order_Dir[76] = pos_id++;
        effect_76_init(76);
        Order[81] = 0;
        effect_G0_init(81, time, Perfect_Bonus[Winner_id], pos_id2++);
        time += 5;
    }

    Order[78] = 1;
    Order_Timer[78] = time;
    Order_Dir[78] = pos_id++;
    effect_76_init(78);
    Order[83] = 0;
    effect_G0_init(83, time, Vital_Bonus[Winner_id], pos_id2++);
    time += 5;
    Order[79] = 1;
    Order_Timer[79] = time;
    Order_Dir[79] = pos_id++;
    effect_76_init(79);
    Order[84] = 0;
    effect_G0_init(84, time, Time_Bonus[Winner_id], pos_id2++);
    time += 5;
    Order[75] = 1;
    Order_Timer[75] = time;
    Order_Dir[75] = pos_id++;
    effect_76_init(75);
    Order[80] = 0;
    Order_Dir[80] = 1;
    effect_G0_init(80, time, Complete_Bonus, pos_id2);
}

void Game_Manage_81_1() {
    if (Order_Dir[80] == 0) {
        C_No[2]++;
        C_Timer = 20;
    }
}

void Game_Manage_81_2() {
    if (Scene_Cut) {
        C_Timer = 1;
    }

    if (--C_Timer != 0) {
        return;
    }

    C_No[2]++;
    Stop_Update_Score = 0;
    Order_Dir[80] = 1;
    Order[81] = 1;
    Order[83] = 1;
    Order[84] = 1;
    Order[80] = 1;
    sub_00098407(100);
}

void Game_Manage_81_3() {
    if (Order_Dir[80] == 0) {
        C_No[1]++;
        C_No[2] = 0;
        C_Timer = 50;
    }
}

void Game_Manage_8_2() {
    if (Request_Break[Winner_id ^ 1]) {
        C_Timer = 1;
    }

    if (Scene_Cut) {
        C_Timer = 1;
    }

    if (--C_Timer != 0) {
        return;
    }

    if (Check_Entry_Again()) {
        Forbid_Break = 0;
    }

    Disp_Cockpit = 0;
    Suicide[2] = 1;
    gauge_stop_flag[0] = 1;
    gauge_stop_flag[1] = 1;
    C_No[0]++;
    C_No[1] = 0;
    C_Timer = 30;
}

void Game_Manage_8_3() {
    if (Scene_Cut) {
        C_Timer = 1;
    }

    if (--C_Timer == 0) {
        C_No[0]++;
        C_No[1] = 0;
    }
}

void Game_Manage_9th() {
    switch (C_No[1]) {
    case 0:
        if (PL_Wins[Winner_id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            C_No[0]++;
            C_No[1] = 0;
            C_Timer = 75;
            cpExitTask(4);

            if (Play_Type != 1 && Round_Operator[WINNER] && Battle_Q[WINNER]) {
                C_No[0] = 10;
            }

            break;
        }

        C_No[1]++;
        C_Timer = 60;
        Stop_Combo = 1;
        BGM_Timer[1] = 1;
        break;

    case 1:
        if (Scene_Cut) {
            C_Timer = 1;
        }

        if (--C_Timer > 0) {
            break;
        }

        C_No[1]++;
        Game_pause = 1;
        Switch_Screen_Init(0);

        if (judge_flag) {
            SsBgmFadeOut(2048);
        }

        /* fallthrough */

    default:
        if (Switch_Screen(0)) {
            BGM_No[0] = 1;
            BGM_Timer[0] = 1;
            G_No[2] = 5;
            G_No[3] = 0;
            G_Timer = 4;
            Cover_Timer = 5;
            C_No[0] = 1;
            C_No[1] = C_No[2] = C_No[3] = 0;
            Suicide[0] = 1;
            Suicide[6] = 1;
            judge_flag = 0;
        }

        break;
    }
}

void Game_Manage_10th() {
    switch (C_No[1]) {
    case 0:
        if (Button_Cut_EX(&C_Timer, 0x7FFF)) {
            C_No[1]++;
            Cover_Timer = 25;
            pulpul_stop();
            Stop_Combo = 1;
            Game_pause = 1;
            Switch_Screen_Init(0);
        }

        break;

    case 1:
        if (Switch_Screen(0)) {
            effect_work_quick_init();
            judge_flag = 0;
            SE_All_Off();
            Check_Naming(0);
            Check_Naming(1);
            pcon_rno[0] = 0;
            pcon_rno[1] = 0;
            pcon_rno[2] = 0;
            pcon_rno[3] = 0;
            appear_type = 1;
            Continue_Coin2[WINNER] = 0;

            if (Mode_Type == 1 || Mode_Type == 5 || Round_Operator[WINNER]) {
                G_No[1] = 3;
                G_No[2] = 0;
                G_No[3] = 0;
                M_No[0] = 0;
                M_No[1] = 0;
                M_No[2] = 0;
                M_No[3] = 0;
                E_No[0] = 5;
                E_No[1] = 0;
                E_No[2] = 0;
                E_No[3] = 0;
                Check_Ending();
                Continue_Coin2[WINNER] = 0;
                Clear_Flash_No();
                break;
            }

            G_No[1] = 4;
            G_No[2] = 0;
            G_No[3] = 0;
            M_No[0] = 0;
            M_No[1] = 0;
            M_No[2] = 0;
            M_No[3] = 0;
            E_No[0] = 6;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;
            E_07_Flag[0] = 0;
            E_07_Flag[1] = 0;
            Clear_Flash_No();
        }

        break;
    }
}

void Check_Naming(s16 PL_id) {
    if (Mode_Type != 0) {
        return;
    }

    if (E_Number[PL_id][0] == 2) {
        return;
    }

    if (E_Number[PL_id][0] == 3) {
        return;
    }

    Rank_In[PL_id][0] = -1;
    Rank_In[PL_id][1] = -1;
    Rank_In[PL_id][2] = -1;
    Rank_In[PL_id][3] = -1;
}

s32 Check_Ending() {
    s16 xx;

    if (Play_Type == 1) {
        return 0;
    }

    if (Check_Ending_Sub()) {
        G_No[1] = 8;
        G_No[2] = 0;
        E_No[0] = 10;
        Break_Com[WINNER][0] = 1;
        Extra_Break = 0;
        Pause_ID = WINNER;
        End_PL = My_char[WINNER];
        plw[WINNER].wu.operator = 0;
        Operator_Status[WINNER] = 0;
        SsBgmControl(0, 0);
        Control_Time = 481;
        Ending_init();
        Stock_My_char[WINNER] = My_char[WINNER];
        Stock_Player_Color[WINNER] = Player_Color[WINNER];

        if (Direction_Working[Present_Mode]) {
            return 1;
        }

        if (Check_Extra_Setting() == 0) {
            for (xx = 1; xx < 5; xx++) {
                save_w[xx].PL_Color[0][My_char[WINNER]] = 1;
                save_w[xx].PL_Color[1][My_char[WINNER]] = 1;
            }

            if (My_char[WINNER] == 0) {
                save_w[Present_Mode].Extra_Option = 1;
            }
        }

        return 1;
    }

    return 0;
}

s32 Check_Ending_Sub() {
    if (VS_Index[WINNER] > 9) {
        return 1;
    }

    if (Debug_w[47]) {
        return 1;
    }

    return 0;
}

void Additional_Bonus(s16 PL_id) {
    Complete_Bonus = Setup_Comp_Bonus();
    Score[PL_id][Play_Type] += Perfect_Bonus[Winner_id];
    Score[PL_id][Play_Type] += Vital_Bonus[Winner_id];
    Score[PL_id][Play_Type] += Time_Bonus[Winner_id];
    Score[PL_id][Play_Type] += Complete_Bonus;

    if (Score[PL_id][Play_Type] >= 99999900) {
        Score[PL_id][Play_Type] = 99999900;
    }
}

u32 Setup_Comp_Bonus() {
    u32 xx;
    u16 zz;

    if (Play_Type == 1) {
        if (PL_Wins[Loser_id]) {
            return 0;
        }

        return 30000;
    }

    if (PL_Wins[Loser_id]) {
        return Straight_Counter[Winner_id] = 0;
    }

    Straight_Counter[Winner_id]++;

    if (Straight_Counter[Winner_id] >= 12) {
        Straight_Counter[Winner_id] = 11;
    }

    zz = Straight_Counter[Winner_id];
    xx = Comp_Bonus_Data[zz - 1];
    return xx;
}

void request_center_message(s16 Kind_of_Message) {
    request_message = 1;
    message_index = Kind_of_Message;
}

void Setup_Win_Mark() {
    if (Round_Result & 0x200) {
        win_type[Winner_id][PL_Wins[Winner_id]] = 7;
        SsRequest(121);
        SsRequest(140);
        Finish_SE();
        return;
    }

    if (Round_Result & 0x180) {
        Control_Music_Fade(150);
        win_type[Winner_id][PL_Wins[Winner_id]] = 4;
        SsRequest(140);
        Finish_SE();
        return;
    }

    if (Round_Result & 0x800) {
        if (Shin_Gouki_BGM == 0) {
            Control_Music_Fade(150);
        } else {
            Shin_Gouki_BGM = 0;
        }

        win_type[Winner_id][PL_Wins[Winner_id]] = 4;
        SsRequest(0x8CU);
        Finish_SE();
        return;
    }

    win_type[Winner_id][PL_Wins[Winner_id]] = 1;
    SsRequest(121);
    SsRequest(140);
    Finish_SE();
}

void Check_Perfect(s16 PL_id) {
    if (Mode_Type == 3 || Mode_Type == 4) {
        return;
    }

    if (plw[PL_id].wu.vitality != plw[PL_id].wu.vital_new) {
        return;
    }

    Perfect_Flag = 1;
    Perfect_Counter[Winner_id]++;
    Round_Result |= 2;
    win_type[PL_id][PL_Wins[PL_id]] = 3;
}

void Update_VS_Data() {
    if (PL_Wins[Winner_id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
        WINNER = Winner_id;
        LOSER = Loser_id;
        Stock_My_char[LOSER] = My_char[LOSER];
        Stock_Player_Color[LOSER] = Player_Color[LOSER];

        if (Play_Type != 0) {
            return;
        }

        if (Round_Operator[WINNER]) {
            SC_Personal_Time[WINNER] = Control_Time;
            Stage_Continue[WINNER] = 0;
            Request_Disp_Rank[LOSER][0] = -1;
            Request_Disp_Rank[LOSER][1] = -1;
            Request_Disp_Rank[LOSER][2] = -1;
            Request_Disp_Rank[LOSER][3] = -1;
            Stock_Com_Color[WINNER] = -1;
            Stock_Com_Arts[WINNER] = -1;
            EM_History[WINNER][VS_Index[WINNER]] = EM_id;
            Result_Timer[WINNER] += 30;

            if (EM_id == 17) {
                Break_Com[WINNER][EM_id] = (s8)(VS_Index[WINNER]);
            } else {
                VS_Index[WINNER]++;
                Break_Com[WINNER][EM_id] = 1;
            }

            if (PL_Wins[LOSER]) {
                Straight_Counter[WINNER] = 0;
                Straight_Flag[WINNER] = 1;
            }

            if (++Round_Level <= 7) {
                return;
            }

            Round_Level = 7;
            return;
        }

        Score[LOSER][0] = Stage_Stock_Score[LOSER];
        SC_Personal_Time[LOSER] = Control_Time;
        Win_Record[LOSER] = 0;
        Straight_Counter[LOSER] = 0;
        Straight_Flag[LOSER] = 1;
        return;
    }

    Score[Loser_id][0] = Stock_Score[Loser_id];
}

void BGM_Fade_Sub() {
    switch (BGM_No[1]) {
    case 1:
        if (--BGM_Timer[1] == 0) {
            BGM_No[1]++;
            BGM_Timer[1] = 1;
            BGM_Vol = -128;
        }

        break;

    case 0:
        break;

    default:
        if (--BGM_Timer[1] == 0) {
            BGM_Timer[1] = 2;

            if (++BGM_Vol == 0) {
                BGM_No[1] = 0;
            }
        }

        if (!Music_Fade) {
            SsBgmControl(0, BGM_Vol);
        }

        break;
    }
}

void BGM_Control() {
    switch (BGM_No[0]) {
    case 0:
        return;

    case 1:
        if (--BGM_Timer[0] == 0) {
            BGM_No[0]++;
        }

        /* fallthrough */

    case 2:
        BGM_No[0] = 0;

        if (Play_Type == 0 && EM_id == 17) {
            Stage_BGM(17, Round_num);
            break;
        }

        Stage_BGM(bg_w.stage, Round_num);
        break;

    case 3:
        if (--BGM_Timer[0] == 0) {
            BGM_No[0]++;
        }

        /* fallthrough */

    case 4:
        BGM_No[0] = 0;
        sub_00098407(56);
        break;
    }
}

void Setup_BGM_Fade_In(s16 Time) {
    if (!PB_Music_Off) {
        BGM_No[1] = 1;
        BGM_Timer[1] = Time;
    }
}

void Check_Stage_BGM() {
    if (Play_Type == 1) {
        Stage_BGM(bg_w.stage, Round_num);
        return;
    }

    switch (EM_id) {
    case 1:
        if (My_char[Player_id] != 0) {
            Stage_BGM(bg_w.stage, Round_num);
        }

        /* fallthrough */

    case 0:
        if (Introduce_Boss[Player_id][1] & 0x80) {
            Stage_BGM(bg_w.stage, Round_num);
        }

        break;

    case 17:
        Stage_BGM(17, Round_num);
        break;

    default:
        Stage_BGM(bg_w.stage, Round_num);
        break;
    }
}

void Control_Music_Fade(s16 Time) {
    Setup_BGM_Fade_In(Time);
    SsBgmControl(0, -128);
}

void Check_Conclusion_Type() {
    if (Play_Type == 1) {
        return;
    }

    switch (Conclusion_Type) {
    case 0:
        chkComWins();
        break;

    case 1:
        Lost_Round[Player_id]++;
        Stage_Lost_Round[Player_id]++;
        break;

    case 2:
        if (plw[0].wu.vital_new != plw[1].wu.vital_new) {
            Stage_Time_Finish[Winner_id]++;
            chkComWins();
        }

        break;
    }
}

void chkComWins() {
    if (Round_Operator[Winner_id] == 0) {
        Lost_Round[Loser_id]++;
        Stage_Lost_Round[Loser_id]++;
    }
}

void Update_BI_Term() {
    if (Play_Type == 1) {
        return;
    }

    if (plw[Winner_id].sa_healing) {
        Super_Arts_Finish[Winner_id]++;
        Stage_SA_Finish[Winner_id]++;
        return;
    }

    if (plw[Winner_id].wu.vitality == plw[Winner_id].wu.vital_new) {
        Perfect_Finish[Winner_id]++;
        Stage_Perfect_Finish[Winner_id]++;

        if (Round_Result & 0x980) {
            Super_Arts_Finish[Winner_id]++;
            Stage_SA_Finish[Winner_id]++;
        }

        return;
    }

    if (Round_Result & 0x200) {
        Cheap_Finish[Winner_id]++;
        Stage_Cheap_Finish[Winner_id]++;
        return;
    }

    if (Round_Result & 0x980) {
        Super_Arts_Finish[Winner_id]++;
        Stage_SA_Finish[Winner_id]++;
    }
}

void Ck_Win_Record() {
    if (PL_Wins[Winner_id] < save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
        return;
    }

    switch (Mode_Type) {
    case 0:
        if (Play_Type == 1) {
            Win_Record[Loser_id] = 0;

            if (++Win_Record[Winner_id] > 999) {
                Win_Record[Winner_id] = 999;
            }

            Stock_Win_Record[Winner_id] = Win_Record[Winner_id];
        }

        break;

    case 1:
        if (++VS_Win_Record[Winner_id] > 999) {
            VS_Win_Record[Winner_id] = 999;
        }

        break;
    }
}

void Update_Level_Control() {
    if (Round_Operator[Winner_id]) {
        if ((Round_Operator[Loser_id]) != 0) {
            return;
        }

        Control_Time += 40;

        if (Control_Time > Limit_Time) {
            Control_Time = Limit_Time;
        }

        return;
    }

    if ((Control_Time -= 40) < 0) {
        Control_Time = 0;
    }
}

s32 Judge_Next_Disposal() {
    if (Mode_Type == 3 || Mode_Type == 4) {
        return 0;
    }

    if (PL_Wins[0] != PL_Wins[1]) {
        return 0;
    }

    if (PL_Wins[0] >= save_w[Present_Mode].Battle_Number[Play_Type]) {
        return 1;
    }

    return 0;
}

void Quick_Entry() {
    s8 grade;

    if (Check_Entry_Again()) {
        Forbid_Break = 0;
        Extra_Break = 0;
    }

    if (PL_Wins[Winner_id] < save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
        return;
    }

    if (plw[LOSER].wu.operator) {
        Loser_Sub();

        if (Mode_Type != 0) {
            plw[LOSER].wu.operator = 1;
        }

        Be_Continue();
    }

    if (Play_Type == 1) {
        grade = judge_item[Winner_id][1].grade;

        if (grade > Best_Grade[Winner_id]) {
            Best_Grade[Winner_id] = grade;
        }
    }
}

s32 Check_Entry_Again() {
    if (Battle_Q[Winner_id]) {
        return 0;
    }

    if (Play_Type == 1) {
        return 1;
    }

    if (VS_Index[WINNER] >= 6) {
        return 0;
    }

    if (VS_Index[WINNER] < 10) {
        return 1;
    }

    return 0;
}

void Loser_Sub() {
    plw[LOSER].wu.operator = 0;
    Operator_Status[LOSER] = 0;
    Sel_PL_Complete[LOSER] = 0;
    Sel_Arts_Complete[LOSER] = 0;

    if (Play_Type == 0) {
        if (--Round_Level < 0) {
            Round_Level = 0;
        }

        Stage_Continue[LOSER]++;
    }
}

void Be_Continue() {
    if (Mode_Type != 0) {
        return;
    }

    Continue_Count_Down[LOSER] = 0;
    Continue_Count[LOSER] = 9;
    E_Number[LOSER][0] = 5;
    E_Number[LOSER][0] = 5;
    E_Number[LOSER][1] = 0;
    E_Number[LOSER][2] = 0;
    E_Number[LOSER][3] = 0;
}

void Disp_Winner() {
    if (Play_Type == 1) {
        effect_56_init(My_char[Winner_id] + 7, 1);
        SsRequest(141);
        return;
    }

    if (Round_Operator[Winner_id]) {
        effect_56_init(5, 1);
        SsRequest(141);
        return;
    }

    effect_56_init(6, 1);
    SsRequest(142);
}

void Pool_Score(s16 PL_id) {
    u32 Score_Buff;

    if (Perfect_Flag) {
        Perfect_Bonus[Winner_id] += 50000;
    }

    Score_Buff = plw[PL_id].wu.vital_new * 100 / Max_vitality;
    Score_Buff *= 500;
    Vital_Bonus[Winner_id] += Score_Buff;

    if (save_w[Present_Mode].Time_Limit == -1) {
        Time_Bonus[Winner_id] = 0;
        return;
    }

    Time_Bonus[Winner_id] += round_timer.size.half.h * 300;
}

s32 Check_Break_Into_CPU(s16 PL_id) {
    if (Debug_w[70] == 9) {
        Break_Into_CPU = 2;
        return Battle_Q[PL_id] = 1;
    }

    Break_Into_CPU = 0;
    Battle_Q[PL_id] = 0;

    if (Round_Result & 0x8000) {
        return 0;
    }

    if (Break_Com[PL_id][17]) {
        return 0;
    }

    if (Continue_Coin[PL_id]) {
        return 0;
    }

    if (VS_Index[PL_id] < 7 || VS_Index[PL_id] >= 9) {
        return 0;
    }

    if (Straight_Flag[PL_id]) {
        return 0;
    }

    if (judge_final[Player_id][0].sp_point < 2) {
        return 0;
    }

    if (Super_Arts_Finish[PL_id] < BIC_SA_Data[0][save_w[Present_Mode].Battle_Number[Play_Type]]) {
        return 0;
    }

    if (Check_BI_Grade(PL_id)) {
        Break_Into_CPU = 2;
        return Battle_Q[PL_id] = 1;
    }

    return 0;
}

void Judge_Winner() {
    grade_makeup_judgement_gals();

    if (judge_gals[0].grade == judge_gals[1].grade) {
        if (Play_Type == 0) {
            Winner_id = Player_id;
            Loser_id = COM_id;
            return;
        }

        Winner_id = Champion;
        Loser_id = Champion ^ 1;
        return;
    }

    if (judge_gals[0].grade > judge_gals[1].grade) {
        Winner_id = 0;
        Loser_id = 1;
        return;
    }

    Winner_id = 1;
    Loser_id = 0;
}

s32 Check_Disp_Winner() {
    if (Mode_Type == 3 || Mode_Type == 4) {
        return Disp_Win_Name = 0;
    }

    if (PL_Wins[Winner_id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
        return Disp_Win_Name = 1;
    }

    if (Conclusion_Type == 0) {
        return Disp_Win_Name = 0;
    }

    return Disp_Win_Name = 1;
}

void Check_Fade_Out_BGM(s16 Time) {
    if (Music_Fade) {
        return;
    }

    if (PL_Wins[Winner_id] < save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
        return;
    }

    Music_Fade = 1;
    SsBgmFadeOut(Time);
}

s32 Check_BI_Grade(s16 PL_id) {
    s16 ix;

    for (ix = 0; ix < VS_Index[PL_id]; ix++) {
        if (judge_final[PL_id][0].vs_cpu_grade[ix] < 9) {
            return 0;
        }
    }

    return 1;
}

void Game_Manage_11th() {
    switch (C_No[1]) {
    case 0:
        Forbid_Break = -1;
        C_No[1]++;
        EM_Rank = 2;
        Q_Country = Battle_Country;
        C_Timer = 90;
        effect_81_init(30);
        break;

    case 1:
        if (--C_Timer == 0) {
            C_No[1]++;
            C_Timer = 150;
            C_Timer = 60;
        }

        break;

    case 2:
        if (--C_Timer == 0) {
            C_No[1]++;
        }

        break;

    case 3:
        C_No[1]++;
        Switch_Screen_Init(0);
        break;

    case 4:
        if (Switch_Screen(0)) {
            G_No[1] = 11;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 9;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;
            effect_work_kill_mod_plcol();
            Cover_Timer = 21;
        }

        break;
    }
}

void Game_Manage_12th() {
    void (*SC12_Jmp_Tbl[10])() = { Game_Manage_12_0, Game_Manage_12_1, Game_Manage_12_2, Game_Manage_12_3,
                                   Game_Manage_12_4, Game_Manage_12_5, Game_Manage_12_1, Game_Manage_12_7,
                                   Game_Manage_12_8, Game_Manage_12_5 };

    SC12_Jmp_Tbl[C_No[1]]();

    if (Bonus_Type == 20) {
        bcounter_write();
    }
}

void Game_Manage_12_0() {
    s16 ix;

    Suicide[0] = 0;
    Suicide[6] = 0;
    Suicide[5] = 0;

    if (effect_84_init()) {
        return;
    }

    C_No[1]++;
    Extra_Break = 0;
    request_message = 0;
    Complete_Victory = 0;
    Conclusion_Flag = 0;
    Perfect_Flag = 0;
    Round_Result = 0;
    Reserve_Cut = 0;
    Next_Step = 0;
    judge_flag = 0;
    Stop_Combo = 0;

    if (Demo_Flag) {
        Stop_SG = 0;
    }

    Complete_Judgement = 0;
    Music_Fade = 0;
    Round_Operator[0] = plw[0].wu.operator;
    Round_Operator[1] = plw[1].wu.operator;
    CP_No[0][0] = 0;
    CP_No[1][0] = 0;

    for (ix = 0; ix < 4; ix++) {
        Message_Suicide[ix] = 0;
    }

    Stock_Score[Player_id] = Score[Player_id][0];

    if (Bonus_Type == 20) {
        C_No[1] = 6;
        Time_Stop = 1;
        Time_Over = 0;
        Exit_No = 0;
        Unit_Of_Timer = 0;
        sub_0004384A();
        bcount_cont_init();
    }
}

void Game_Manage_12_1() {
    bcount_cont_main();

    if (Next_Step != 0) {
        C_No[1]++;
        C_No[2] = 0;
        C_No[3] = 0;
        Allow_a_battle_f = 1;
        Disp_Bonus_Contents = 0;
    }
}

void Game_Manage_12_2() {
    bcount_cont_main();

    if (!Bonus_Game_Complete) {
        return;
    }

    C_No[1]++;
    C_No[2] = 0;
    C_Timer = 30;
    Allow_a_battle_f = 0;
    Forbid_Break = -1;
    Completion_Bonus[Player_id][1] = -128;
    Stock_Bonus_Game_Result = Bonus_Game_result;
    Bonus_Score = 0;
    Final_Bonus_Score = Setup_Final_Score(21);
    effect_58_init(6, 10, 169);
    grade_makeup_bonus_parameter(Player_id);

    if (Check_Bonus_Perfect()) {
        C_Timer = 20;
    } else {
        C_No[1] = 4;
    }

    cpExitTask(4);
}

void Game_Manage_12_3() {
    switch (C_No[2]) {
    case 0:
        if (Cut_Cut_C_Timer() == 0) {
            C_No[2]++;
            C_Timer = 10;
            request_center_message(4);
            effect_58_init(6, 1, 155);
            effect_58_init(6, 60, 156);
        }

        break;

    case 1:
        if (request_message == 0) {
            C_No[2]++;
            C_Timer = 6;
        }

        break;

    case 2:
        if (--C_Timer == 0) {
            C_No[2]++;
            C_Timer = 20;
        }

        break;

    case 3:
        if (Cut_Cut_C_Timer() == 0) {
            C_No[1]++;
            C_No[2] = 0;
            C_No[3] = 0;
            C_Timer = 30;
        }

        break;
    }
}

void Game_Manage_12_4() {
    switch (C_No[2]) {
    case 0:
        if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
            C_No[2]++;
            C_Timer = 20;
            effect_08_init(7, 0, 1, 15, 0);
            Disp_Score_Buff[0] = Bonus_Score;
            effect_14_init(0, 35, 11, 15);
        }

        break;

    case 1:
        if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
            C_No[2]++;
            C_Timer = 1;
            Bonus_Score = 0;
        }

        break;

    case 2:
        if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
            if (Bonus_Game_result == 0 && !(PB_Status & 2)) {
                C_No[2] = 4;
                C_Timer = 30;
                break;
            }

            if (Bonus_Game_result == 0) {
                Bonus_Game_result = 1;
            } else {
                Bonus_Score += 1000;
                Score[Player_id][0] += 1000;
                Disp_Score_Buff[0] = Bonus_Score;
                sub_00098407(100);
            }

            if (--Bonus_Game_result == 0) {
                C_No[2]++;

                if (PB_Status) {
                    C_No[3] = 1;
                    C_Timer = 10;
                    break;
                }

                C_No[3] = 0;
                C_Timer = 20;
                break;
            }

            C_Timer = 3;
        }

        break;

    case 3:
        switch (C_No[3]) {
        case 0:
            if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
                C_No[2]++;
                C_Timer = 30;
                Bonus_Game_result = Stock_Bonus_Game_Result;
            }

            break;

        case 1:
            if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
                C_No[3]++;
                C_Timer = 10;
                Disp_Bonus_Perfect();
            }

            break;

        case 2:
            if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
                C_No[3]++;
                C_Timer = 40;

                if (PB_Status & 1) {
                    Score[Player_id][0] += Ball_Perfect_PTS[0][Bonus_Stage_Level];
                }

                if (PB_Status & 2) {
                    Score[Player_id][0] += Ball_Perfect_PTS[1][Bonus_Stage_Level];
                }

                if (Score[Player_id][0] >= 99999900) {
                    Score[Player_id][0] = 99999900;
                }

                Flash_Bonus_Perfect();
                break;
            }

            break;

        default:
            if (--C_Timer == 0) {
                C_No[2]++;
                C_Timer = 30;
            }

            break;
        }

        break;

    default:
        if (Cut_Cut_C_Timer() == 0) {
            C_No[1]++;
            C_No[2] = 0;
            C_No[3] = 0;
            C_Timer = 10;
            Forbid_Break = 0;
            Suicide[5] = 1;
            Check_Fade_Out_BGM(546);
        }

        break;
    }
}

void Game_Manage_12_5() {
    switch (C_No[2]) {
    case 0:
        if (Debug_w[70] != 2 && --C_Timer == 0) {
            C_No[2]++;
            C_Timer = 20;
        }

        break;

    case 1:
        if (Scene_Cut) {
            C_Timer = 1;
        }

        if (--C_Timer == 0) {
            C_No[2]++;
        }

        break;

    default:
        MANAGE_X = 1;
        break;
    }
}

void Game_Manage_12_7() {
    bcount_cont_main();

    if (Check_Time_Over()) {
        return;
    }

    if (!Bonus_Game_Complete) {
        return;
    }

    C_No[1]++;
    C_No[2] = 0;
    C_No[3] = 0;
    C_Timer = 30;
    Allow_a_battle_f = 0;
    Forbid_Break = -1;
    Completion_Bonus[Player_id][0] = -128;
    Final_Bonus_Score = Setup_Final_Score(20);
    grade_makeup_bonus_parameter(Player_id);
    effect_58_init(6, 10, 169);
}

void Game_Manage_12_8() {
    switch (C_No[2]) {
    case 0:
        switch (C_No[3]) {
        case 0:
            Next_Step = 0;

            if (effect_35_init(60, 10) == 0) {
                C_No[3]++;
            }

            break;

        case 1:
            if (Next_Step) {
                C_No[3]++;
                C_Timer = 20;
            }

            break;

        case 2:
            if (C_Timer < 11 && Scene_Cut != 0) {
                C_Timer = 1;
            }

            if (--C_Timer == 0) {
                C_No[2]++;
                C_No[3] = 0;
                C_Timer = 30;
            }

            break;
        }

        break;

    case 1:
        if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
            C_No[2]++;
            C_Timer = 20;
            Score[Player_id][0] += Bonus_Score;
            effect_08_init(7, 0, 1, 15, 0);
            Disp_Score_Buff[0] = Bonus_Score;
            effect_14_init(0, 35, 11, 15);

            if (Bonus_Game_result == 0) {
                C_No[2] = 99;
                C_Timer = 120;
            }
        }

        break;

    case 2:
        if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
            C_No[2]++;
            C_Timer = 1;
        }

        break;

    case 3:
        if (Bonus_Cut_Sub() == 0 && --C_Timer == 0) {
            if (bcounter_down(0) == 0) {
                C_No[2]++;
                C_Timer = 30;
                C_Timer = 3;
                Bonus_Score += 1000;
                Score[Player_id][0] += 1000;
                Disp_Score_Buff[0] = Bonus_Score;
                sub_00098407(100);
                break;
            }

            C_Timer = 3;
            Bonus_Score += 1000;
            Score[Player_id][0] += 1000;
            Disp_Score_Buff[0] = Bonus_Score;
            sub_00098407(100);
        }

        break;

    case 4:
        if (--C_Timer == 0) {
            C_No[2]++;
            C_Timer = 30;
        }

        break;

    default:
        if (Debug_w[70] != 2 && Cut_Cut_C_Timer() == 0) {
            C_No[1]++;
            C_No[2] = 0;
            C_No[3] = 0;
            C_Timer = 10;
            Forbid_Break = 0;
            Suicide[5] = -128;
            Check_Fade_Out_BGM(546);
        }

        break;
    }
}

u8 Check_Bonus_Perfect() {
    PB_Status = 0;

    if (Stock_Bonus_Game_Result >= 20) {
        PB_Status |= 1;
    }

    if (Bonus_Game_ex_result >= 20) {
        PB_Status |= 2;
    }

    return PB_Status;
}

void Disp_Bonus_Perfect() {
    switch (PB_Status) {
    case 1:
        effect_08_init(6, 0, 5, 15, 0);
        Disp_Score_Buff[0] = Ball_Perfect_PTS[0][Bonus_Stage_Level];
        effect_14_init(0, 35, 15, 15);
        break;

    case 2:
        effect_08_init(6, 0, 5, 26, 1);
        Disp_Score_Buff[1] = Ball_Perfect_PTS[1][Bonus_Stage_Level];
        effect_14_init(1, 35, 15, 26);
        break;

    case 3:
        effect_08_init(6, 0, 5, 15, 0);
        Disp_Score_Buff[0] = Ball_Perfect_PTS[0][Bonus_Stage_Level];
        effect_14_init(0, 35, 15, 15);
        effect_08_init(6, 0, 9, 26, 1);
        Disp_Score_Buff[1] = Ball_Perfect_PTS[1][Bonus_Stage_Level];
        effect_14_init(1, 35, 19, 26);
        break;
    }

    SsRequest(Winner_id + 102);
}

void Flash_Bonus_Perfect() {
    switch (PB_Status) {
    case 1:
        Suicide[5] = 1;
        break;

    case 2:
        Suicide[5] = 1;
        break;

    case 3:
        Suicide[5] = 1;
        break;
    }
}

u32 Setup_Final_Score(s16 Type) {
    u32 xx;

    if (Type == 21) {
        xx = Bonus_Game_result * 1000;

        if (Stock_Bonus_Game_Result >= 20) {
            xx += Ball_Perfect_PTS[0][Bonus_Stage_Level];
        }

        if (Bonus_Game_ex_result >= 20) {
            xx += Ball_Perfect_PTS[1][Bonus_Stage_Level];
        }

        xx += Score[Player_id][0];

        if (xx >= 99999900) {
            xx = 99999900;
        }

        return xx;
    }

    switch (Bonus_Game_result) {
    case 2:
        xx = 30000;
        break;

    case 3:
        xx = 50000;
        break;

    default:
        xx = 0;
        break;
    }

    Bonus_Score = xx;
    xx += Counter_hi * 1000;
    Bonus_Score_Plus = xx;
    xx += Score[Player_id][0];

    if (xx >= 99999900) {
        xx = 99999900;
    }

    return xx;
}

s32 Bonus_Cut_Sub() {
    if (Scene_Cut) {
        sub_00098407(100);
        Bonus_Game_result = 0;
        Score[Player_id][0] = Final_Bonus_Score;

        if (Score[Player_id][0] >= 99999900) {
            Score[Player_id][0] = 99999900;
        }

        if (Disp_Bonus_Contents == 0) {
            effect_08_init(7, 0, 1, 15, 0);
        }

        if (Bonus_Type == 21) {
            if (Disp_Bonus_Contents == 0) {
                Disp_Score_Buff[0] = Stock_Bonus_Game_Result * 1000;
                effect_14_init(0, 35, 11, 15);
            }

            Disp_Bonus_Perfect();
            Flash_Bonus_Perfect();
            C_No[2] = 3;
            C_No[3] = 99;
            return C_Timer = 90;
        }

        bcounter_down(1);

        if (Disp_Bonus_Contents == 0) {
            Disp_Score_Buff[0] = Bonus_Score_Plus;
            effect_14_init(0, 35, 11, 15);
        }

        C_No[2] = 4;
        C_No[3] = 99;
        return C_Timer = 90;
    }

    return 0;
}

s16 Check_Time_Over() {
    s16 return_x = 0;

    switch (C_No[2]) {
    case 0:
        if (Time_Over) {
            C_No[2]++;
            C_Timer = 60;
            request_center_message(2);
            SsRequest(143);
            return_x = 1;
        }

        break;

    case 1:
        if (--C_Timer == 0) {
            C_No[2]++;
            Game_pause = 0;
            Suicide[5] = 1;
        }

        break;
    }

    return return_x;
}

void complete_victory_pause() {
    Complete_Victory = 1;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void Game_Manage_13th() {}
#endif
