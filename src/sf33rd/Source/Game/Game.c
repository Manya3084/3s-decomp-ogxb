/* Game.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Game0_0 0x5A189 size 0x1C. Read against the x86: Xbox starts the save
 * autoload here: after G_No[2] += 1 it calls SaveInit(0, 2). The PS2 build
 * does that in Init_Task_Aload. The C is the Xbox code
 * (analysis-ps2map/overrides/Game.c).
 * Game0_1 0x5A1A5 size 0x42. Read against the x86: Xbox polls SaveMove():
 * while it returns > 0 it draws a frame (sub_0005A0D4, an Xbox-only routine),
 * clears G_Timer, and sets Pause = 1; otherwise it clears Pause and goes on as
 * on PS2. G_Timer is 0x7A8912. The C is the Xbox code
 * (analysis-ps2map/overrides/Game.c).
 * Game0_2 0x5A1E7 size 0x110.
 * Game12_1 0x5A2F7 size 0x1B.
 * Game12_2 0x5A312 size 0x47. Read against the x86: after cpExitTask(3) the
 * Xbox calls sub_001073DC(0), an Xbox-only routine. The C is the Xbox code
 * (analysis-ps2map/overrides/Game.c).
 * Game2_0 0x5A359 size 0x1A6. Read against the x86: Xbox adds sub_0011F0D4(0)
 * when sub_001100AC() is nonzero (sub_001100AC returns the dword at 0x79A170,
 * the flag also read by effect_B8_move), and in modes 1 and 2 it calls
 * All_Clear_ETC only when that flag is clear. Game_difficulty is the byte set
 * to 15 (0x7A8811). The C is the Xbox code (analysis-ps2map/overrides/Game.c).
 * Game2_4 0x5A4FF size 0x5.
 * Game2_6 0x5A504 size 0x23.
 * Game2_7 0x5A527 size 0x1E.
 * Game01_Sub 0x5A545 size 0x8E.
 * Game03 0x5A5D3 size 0x283. Read against the x86: a versus win (Mode_Type 2)
 * runs the Xbox-only sub_0011F2C8, sets G_No 13 and calls sub_0011F0D4(1) when
 * sub_001100AC is set, returning without BG_move; the PS2 replay-info and
 * champion setup for versus is gone. Case 2 takes the same exit while
 * sub_001100AC is set. Winner_Scene is called as on PS2. The C is the Xbox
 * code (analysis-ps2map/overrides/Game.c).
 * Game04 0x5A856 size 0xAD.
 * Game05 0x5A903 size 0x108.
 * Request_Break_Sub 0x5AA0B size 0x3A.
 * Disp_Rank_Sub 0x5AA45 size 0x41.
 * Disp_Ranking 0x5AA86 size 0x100.
 * Game07 0x5AB86 size 0x2F.
 * Game08 0x5ABB5 size 0x170. Read against the x86: 0xFF is the byte store of
 * -1 to Player_Number and Last_Player_id. The C is the PS2 C.
 * Game10 0x5AD25 size 0xD1.
 * Game11 0x5ADF6 size 0x15E.
 * Next_Demo_Loop 0x5AF54 size 0x7A.
 * Loop_Demo_Sub 0x5AFCE size 0x3B.
 * Time_Control 0x5B009 size 0x59.
 * Ck_Coin 0x5B062 size 0x88. Read against the x86: the joining player comes
 * from sub_000615FE, which takes a new START or A (0x4100) with player 1
 * first; the PS2 C tests START (0x4000) itself. The C is the Xbox code
 * (analysis-ps2map/overrides/Game.c).
 * Before_Select_Sub 0x5B0EA size 0x11E. Read against the x86: 0xFF is the byte
 * store of -1 to Player_Number, Last_Player_id, and two bytes at 0x7A829A. The
 * C is the PS2 C.
 * Check_Back_Demo 0x5B337 size 0x4B.
 * Game12 0x5B382 size 0x6B. Read against the x86: calls sub_001100AC first and
 * ignores the result, as Game02 does. The C is the Xbox code
 * (analysis-ps2map/overrides/Game.c).
 * Game01 0x5B3ED size 0x222. Read against the x86: starts with a guard through
 * Xbox-only code (sub_0012055C, sub_0011DA18, sub_0012058B, sub_00120552) that
 * returns early when sub_0012058B says so, calls sub_001100AC, and case 0 adds
 * sub_0011F0D4(0)/sub_00113F7D(1) and sub_0010748A/sub_001073F0(1) around the
 * PS2 setup.
 * Game2_1 0x5B60F size 0x7F. Read against the x86: Xbox has no
 * ppgPurgeFromVRAM calls (the PS2 build makes three); Player_control (0x867D7)
 * and combo_cont_main (0xB5597) are called as on PS2, and
 * hit_check_main_process is a tail jump. The C is the Xbox code
 * (analysis-ps2map/overrides/Game.c).
 * Game2_2 0x5B68E size 0x156.
 * Game2_3 0x5B7E4 size 0x1B.
 * Game2_5 0x5B7FF size 0xB7.
 * Check_Disp_Ranking 0x5B8B6 size 0x4C.
 * Bonus_Sub 0x5B902 size 0x72.
 * Next_Title_Sub 0x5BA6F size 0xDE.
 * Game00 0x5BE6F size 0x54. Read against the x86: while G_No[2] is below 2 it
 * sets the Xbox byte D_007AA5EB (inside mpp_w, past inGame) to 1. The C is the
 * Xbox code (analysis-ps2map/overrides/Game.c).
 * Game02 0x5BEC3 size 0x62. Read against the x86: Xbox calls sub_001100AC()
 * before Cut_Cut_Cut and drops the result. The C is the Xbox code
 * (analysis-ps2map/overrides/Game.c).
 * Game06 0x5BF25 size 0x33B. Read against the x86: 0x208 is the save_w stride.
 * The C is the PS2 C.
 * Game09 0x5C260 size 0x2DA.
 * Loop_Demo 0x5C53A size 0x1ED.
 * Game_Task 0x5C850 size 0x19A. FLAG: x86-only callees xb_GetOnlineFlag,xb_Net
 * Sync_IsDone,xb_ClearTexRenewQueue,xb_LiveWork_Get2330,xb_FlushTexRenewQueue;
 * x86-only offsets -0x1; x86-only globals p1sw_1,p2sw_0.
 * Game12_0 is folded into 0x4384A with 42 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: Game,
 * Wait_Auto_Load.
 * All_Clear_Random_ix is folded into 0x9A8D0.
 * BGM_Request is folded into 0x98407.
 * Bg_On_R is folded into 0xAF4AA.
 * Check_LDREQ_Queue has no XBE name and no aligned call.
 * Check_Off_Vib has no XBE name and no aligned call.
 * Setup_Net_Random_ix is folded into 0x9A8D0.
 * move_pulpul_work has no XBE name and no aligned call.
 * player_face_init is folded into 0x4384A.
 * ppgPurgeFromVRAM has no XBE name and no aligned call.
 * seqsAfterProcess has no XBE name and no aligned call.
 * seqsBeforeProcess has no XBE name and no aligned call.
 * setup_pos_remake_key is folded into 0x4384A.
 * Unnamed data used (not checked): Game_Task:
 * 0x795cd8,0x795cdc,0x795ce0,0x795ce4,0x7be118,0x7c59d4,0x7c59d6.
 * FadeIn/FadeOut priority is 1 on Xbox (PS2 8) in Game06, Game0_2.
 * Globals: stage_bgw_number 0x273FC8, paring_counter 0x7A8108, Player_id
 * 0x7A810F, My_char 0x7A8114, Bonus_Type 0x7A8120, Play_Type 0x7A812D,
 * Demo_PL_Index 0x7A813A, Win_Record 0x7A8164, Operator_Status 0x7A816A,
 * Play_Mode 0x7A8178, Random_ix32_ex 0x7A817A, Request_G_No 0x7A8189,
 * Combo_Demo_Flag 0x7A8198, Present_Mode 0x7A819C, Request_Break 0x7A81B0,
 * Battle_Q 0x7A81B8, COM_id 0x7A81C0, WGJ_Target 0x7A81C4, Request_E_No
 * 0x7A81C6, Control_Time 0x7A81EE, Insert_Y 0x7A81F2, Cover_Timer 0x7A81F4,
 * Bonus_Game_Complete 0x7A81FA, D_No 0x7A8200, Cursor_Y_Pos 0x7A8220,
 * Mode_Type 0x7A825A, G_No 0x7A825C, Suicide 0x7A8268, Bonus_Game_Flag
 * 0x7A8272, Keep_Grade 0x7A8278, Player_Number 0x7A8294, Stock_Com_Arts
 * 0x7A829A, Stop_Update_Score 0x7A82AA, Stock_Com_Color 0x7A82B4,
 * Allow_a_battle_f 0x7A82B8, Disp_Attack_Data 0x7A82F8, Exec_Wipe 0x7A82F9,
 * Stop_Combo 0x7A82FC, LOSER 0x7A82FD, Select_Demo_Index 0x7A82FE,
 * paring_bonus_r 0x7A8314, PL_Wins 0x7A832E, Demo_Type 0x7A8336,
 * Round_Operator 0x7A833C, Request_Disp_Rank 0x7A8360, GO_No 0x7A8424,
 * Bonus_Game_ex_result 0x7A842A, Demo_Flag 0x7A842D, Present_Rank 0x7A8450,
 * Scene_Cut 0x7A8461, E_Number 0x7A8468, Random_ix16 0x7A8470, Winner_id
 * 0x7A8472, Pause_ID 0x7A8514, End_Training 0x7A8515, Demo_Stage_Index
 * 0x7A8516, Fade_Flag 0x7A851A, Unsubstantial_BG 0x7A851C, Pause_Down
 * 0x7A8590, Time_in_Time 0x7A8598, E_Timer 0x7A86A8, Last_Player_id 0x7A86C1,
 * C_No 0x7A86C4, Replay_Status 0x7A86C8, Continue_Coin 0x7A86E0, Score
 * 0x7A8720, Country 0x7A8748, Final_Result_id 0x7A8750, Cont_No 0x7A8754,
 * Round_Level 0x7A876A, WGJ_Score 0x7A8774, Forbid_Reset 0x7A8778,
 * Sel_Arts_Complete 0x7A87E0, Rank_In 0x7A87E8, Break_Into 0x7A8802,
 * judge_flag 0x7A8803, Forbid_Break 0x7A8804, Game_difficulty 0x7A8811, Pause
 * 0x7A8816, Reset_Bootrom 0x7A8817, Round_num 0x7A8818, Bonus_Game_result
 * 0x7A881A, Game_timer 0x7A8830, Limit_Time 0x7A88D6, Lamp_No 0x7A88D8,
 * G_Timer 0x7A8912, Random_ix32 0x7A891E, Rank_Type 0x7A892C, Disp_Cockpit
 * 0x7A8930, Champion 0x7A8931, Game_pause 0x7A89B0, WGJ_Win 0x7A89B2, WINNER
 * 0x7A89BD, S_No 0x7A89C8, End_PL 0x7A89CC, Play_Game 0x7A89EC, E_No 0x7A89F8,
 * Super_Arts 0x7A89FE, Bonus_Game_Work 0x7A8A00, SC_No 0x7A8A20,
 * Demo_Time_Stop 0x7A8A32, mpp_w 0x7AA5C0, seraph_flag 0x7BC4F4, bg_w
 * 0x7BC520, No_Trans 0x7BD3C9, p1sw_1 0x7BD3CA, save_w 0x7BD3E0, task
 * 0x7BE020, Interrupt_Timer 0x7C556C, Screen_PAL 0x7C557A, vm_w 0x7C5580,
 * Turbo 0x7C56A8, Rep_Game_Infor 0x7C56C0, Turbo_Timer 0x7C5980, system_timer
 * 0x7C59D0, p2sw_0 0x7C5B90, Ranking_Data 0xC7C840, plw 0xC7CEA0, appear_type
 * 0xC7D8E8, pcon_rno 0xC7E020, title_tex_flag 0xC7E19E, ca_check_flag
 * 0xC7EAC2.
 */

#include "structs.h"

#define MENU_TASK_NUM 3
#define SAVER_TASK_NUM 6
#define ENTRY_TASK_NUM 1
#define PAUSE_TASK_NUM 4

void sub_0009A8D0();
void sub_00098407(s16 Code);
void sub_000AF4AA(u16 s_prm);
void sub_0004384A();
extern u8 D_007AA5EB;
s32 xb_GetOnlineFlag(void);
void xb_DrawSaveFrame(void);
void xb_rebattle_Select(s32 arg);
s16 xb_GetJoiningPlayer(void);
void xb_LiveWork_Set2330(s32 arg);
void xb_ClearRebattleWork(void);
s32 xb_NetSync_IsDone(void);
void xb_NetSync_Step(void);
s32 xb_NetSync_CheckPlayers(void);
void xb_NetSync_SetDone(s32 arg);
void xb_LiveWork_Menu24C0(s32 arg);
void xb_ReleaseScreenTextures(void);
void xb_LiveWork_Set2334(s32 arg);
void Wait_Auto_Load(struct _TASK* );
void Loop_Demo(struct _TASK* );
void Game();
void init_color_trans_req();
extern u8 Process_Counter;
extern u8 Usage;
extern u8 Turbo;
extern u8 sysFF;
extern u8 No_Trans;
extern u8 Turbo_Timer;
extern u8 Play_Game;
extern u8 Game_pause;
extern u32 system_timer;
void init_texcash_before_process();
void seqsBeforeProcess();
u8 nowSoftReset();
extern u8 G_No[4];
void seqsAfterProcess();
void texture_cash_update();
void move_pulpul_work();
void Check_Off_Vib();
void Check_LDREQ_Queue();
void Check_Check_Screen();
void Check_Pos_BG();
void Disp_Sound_Code();
void Game0_0();
void Game0_1();
void Game0_2();
void njSetBackColor(u32 c0, u32 c1, u32 c2);
void BG_Draw_System();
void Basic_Sub();
void Check_Back_Demo();
s32 Title_At_a_Dash();
void SaveInit(s32 file_type, s32 save_mode);
void Disp_Copyright();
s16 TITLE_Move(u16 type);
s32 SaveMove();
extern u8 Pause;
extern s8 Request_G_No;
extern s16 G_Timer;
void Switch_Screen_Init(s32 );
s32 Switch_Screen(u8 Wipe_Type);
extern s8 Cover_Timer;
s32 FadeOut(u8 type, u8 step, u8 priority);
void TexRelease(u32 G_Num);
extern s16 title_tex_flag;
void Purge_mmtm_area(s16 ix);
void Make_texcash_of_list(s16 ix);
void cpReadyTask(u16 num, void* func_adrs);
void Menu_Task(struct _TASK* task_ptr);
void Next_Demo_Loop();
void effect_work_init();
void Game12_0();
void Game12_1();
void Game12_2();
void bg_pos_hosei_sub2(s16 bg_no);
void Bg_Family_Set_appoint(s32 num_of_bg);
void BG_move_Ex(u8 ix);
void SsBgmFadeOut(u16 time);
extern s16 Control_Time;
void cpExitTask(u16 num);
void Setup_Play_Type();
extern u8 S_No[4];
void SsBgmHalfVolume(s16 flag);
extern u8 Mode_Type;
extern s8 Break_Into;
extern s8 Stop_Combo;
extern s16 Random_ix32;
extern u32 Interrupt_Timer;
extern s16 Random_ix32_ex;
void All_Clear_Timer();
void init_slow_flag();
void System_all_clear_Level_B();
void pulpul_stop();
void init_pulpul_work();
s16 Select_Player();
extern s16 Bonus_Game_Flag;
void Game01_Sub();
extern s16 appear_type;
void set_hitmark_color();
extern s8 Debug_w[72];
extern u8 My_char[2];
void Purge_texcash_of_list(s16 ix);
extern s8 Demo_Flag;
extern u8 E_No[4];
extern s8 Demo_Time_Stop;
extern PLW plw[2];
extern s8 Operator_Status[2];
extern s16 Sel_Arts_Complete[2];
extern u8 Play_Type;
void BG_move();
void Game2_0();
void Game2_1();
void Game2_2();
void Game2_3();
void Game2_4();
void Game2_5();
void Game2_6();
void Game2_7();
extern u8 Scene_Cut;
s32 Cut_Cut_Cut();
s32 Check_LDREQ_Clear();
extern u8 Play_Mode;
extern u8 Replay_Status[2];
extern struct _SAVE_W save_w[6];
void All_Clear_ETC();
void Check_Replay();
extern u8 Game_difficulty;
extern u8 C_No[4];
extern u8 Round_num;
extern u16 Keep_Grade[2];
extern u16 Win_Record[2];
s16 grade_get_my_grade(s16 ix);
extern u8 Allow_a_battle_f;
extern s16 Time_in_Time;
void clear_hit_queue();
extern s16 pcon_rno[4];
extern s8 ca_check_flag;
void bg_work_clear();
void win_lose_work_clear();
extern MPP mpp_w;
extern u16 Game_timer;
void set_EXE_flag();
void Player_control();
void TATE00();
s32 Game_Management();
void reqPlayerDraw();
void Basic_Sub_Ex();
extern u8 Disp_Cockpit;
void Time_Control();
void vital_cont_main();
void player_face();
void player_name();
void combo_cont_main();
void stngauge_cont_main();
void spgauge_cont_main();
void Sa_frame_Write();
void Score_Sub();
void Flash_Lamp();
void Disp_Win_Record();
void hit_check_main_process();
void effect_work_quick_init();
extern const u8 stage_bgw_number[22][3];
extern BG bg_w;
void Clear_Flash_No();
extern u8 Stop_Update_Score;
void vital_cont_init();
void count_cont_init(u8 type);
void stngauge_cont_init();
void stngauge_work_clear();
void combo_cont_init();
extern u32 Score[2][3];
extern s8 Suicide[8];
void erase_extra_plef_work();
void compel_bg_init_position();
s32 Wait_Seek_Time();
extern u8 PL_Wins[2];
void Clear_Win_Type();
extern u8 Lamp_No;
void set_kizetsu_status(s16 ix);
void set_super_arts_status(s16 ix);
u32 sag_ikinari_max();
void spgauge_cont_init();
void spgauge_cont_demo_init();
void move_effect_work(s16 index);
s32 Winner_Scene();
extern struct _REP_GAME_INFOR Rep_Game_Infor[11];
extern s8 Winner_id;
extern u8 Country;
extern u8 Screen_PAL;
extern struct _TASK task[11];
extern u8 Battle_Q[2];
extern s8 WINNER;
extern s8 Round_Operator[2];
extern s8 LOSER;
extern u8 E_Number[2][4];
extern s8 Request_E_No;
extern s8 Cursor_Y_Pos[2][4];
s32 Loser_Scene();
extern u8 Cont_No[4];
extern u8 SC_No[4];
s8 Check_Bonus_Stage();
s16 Next_CPU();
extern u8 Bonus_Type;
void BGM_Stop();
extern s16 Stock_Com_Color[2];
extern s8 Player_id;
extern s8 Stock_Com_Arts[2];
extern s8 Last_Player_id;
extern u8 GO_No[4];
void make_texcash_work(s16 ix);
s16 Game_Over();
s32 Check_Disp_Ranking();
s32 Disp_Ranking();
void Clear_Disp_Ranking(s16 PL_id);
extern s8 Forbid_Break;
void Clear_Personal_Data(s16 PL_id);
void grade_check_work_1st_init(s16 ix, s16 ix2);
extern s8 Request_Break[2];
void Request_Break_Sub(s16 PL_id);
extern u8 Present_Mode;
extern RANK_DATA Ranking_Data[20];
extern u8 Pause_ID;
void Menu_Init(struct _TASK* task_ptr);
extern u8 Forbid_Reset;
extern u8 Unsubstantial_BG[4];
void Copy_Check_w();
extern u8 D_No[4];
extern u8 Get_Demo_Index;
extern u8 Combo_Demo_Flag;
void Entry_Task(struct _TASK*);
s32 Ck_Break_Into(u16 Sw_0, u16 Sw_1, s16 PL_id);
s16 Disp_Rank_Sub(s16 PL_id);
extern s8 Rank_Type;
extern u8 Present_Rank[2];
extern s8 Rank_In[2][4];
extern s8 Request_Disp_Rank[2][4];
s32 Ranking();
s32 Switch_Screen_Revival(u8 Wipe_Type);
s32 Continue_Scene();
extern u8 Final_Result_id;
extern u8 WGJ_Target;
extern u16 WGJ_Win;
void grade_final_grade_bonus();
extern u32 WGJ_Score;
extern u8 Continue_Coin[2];
s8 Ending_main(s16 pl_num);
extern u8 End_PL;
s32 Request_Fade(u16 fade_code);
s32 Check_Fade_Complete_SP();
extern s8 Player_Number;
void bbbs_com_initialize();
extern s16 Bonus_Game_Work;
extern s16 Bonus_Game_result;
extern s16 Bonus_Game_ex_result;
extern s8 COM_id;
s32 Check_LDREQ_Queue_BG(s16 ix);
void makeup_bonus_game_level(s16 ix);
s32 effect_35_init(s16 wait_timer, s16 c_type);
s32 effect_J2_init(s16 delay);
s32 effect_58_init(s16 id, s16 time0, s16 option);
s16 Bonus_Sub();
void SE_All_Off();
void effect_work_kill_mod_plcol();
extern s8 Bonus_Game_Complete;
s32 Player_control_bonus();
s32 Player_control_bonus2();
s32 After_Bonus();
s16 Next_Q();
s16 Ck_Coin();
void Next_Title_Sub();
extern s8 Demo_PL_Index;
extern s8 Demo_Stage_Index;
extern s8 Select_Demo_Index;
extern u8 check_screen_L;
extern u8 check_screen_S;
extern s16 Insert_Y;
extern u8 Reset_Bootrom;
s32 CAPCOM_Logo();
void Loop_Demo_Sub();
extern s16 E_Timer;
s16 Title();
s32 Play_Demo();
extern s8 Demo_Type;
void SsAllNoteOff();
void pp_operator_check_flag(u8 fl);
void SsRequest(u16 ReqNumber);
void TexRelease_OP();
extern struct _VM_W vm_w;
extern s8 judge_flag;
extern u8 Pause_Down;
extern u8 Disp_Attack_Data;
extern s8 seraph_flag;
extern u8 End_Training;
extern s8 Exec_Wipe;
void Before_Select_Sub();
void count_cont_main();
extern s16 Limit_Time;
void ToneDown(u8 tone, u8 priority);
void Request_LDREQ_Break();
extern s8 Champion;
u8 Check_LDREQ_Break();
extern s16 Round_Level;
extern s8 Super_Arts[2];
extern s8 Fade_Flag;
extern u8 paring_counter[2];
extern u8 paring_bonus_r[2];
extern s16 Random_ix16;



void Game_Task(struct _TASK* task_ptr) {
    s16 ix;
    s16 ff;

    void (*Main_Jmp_Tbl[3])(struct _TASK*) = { Wait_Auto_Load, Loop_Demo, Game };

    init_color_trans_req();
    ff = Process_Counter;

    if ((Usage == 7) && !Turbo) {
        ff = sysFF;
    }

    for (ix = 0; ix < ff; ix++) {
        if (ix == ff - 1) {
            No_Trans = 0;

            if (Turbo != 0 && (Process_Counter > 1) && (Turbo_Timer != 5)) {
                Play_Game = 0;
                break;
            }
        } else {
            No_Trans = 1;
        }

        Play_Game = 0;

        if (Game_pause != 0x81) {
            system_timer += 1;
        }

        init_texcash_before_process();
        seqsBeforeProcess();

        if (nowSoftReset() == 0) {
            Main_Jmp_Tbl[G_No[0]](task_ptr);
        }

        seqsAfterProcess();
        texture_cash_update();
        move_pulpul_work();
        Check_Off_Vib();
        Check_LDREQ_Queue();
    }

    Check_Check_Screen();
    Check_Pos_BG();
    Disp_Sound_Code();
}

/* Xbox: sets the Xbox byte D_007AA5EB (inside mpp_w, past inGame) during
   the title states 0 and 1. */
void Game00() {
    void (*Game00_Jmp_Tbl[3])() = { Game0_0, Game0_1, Game0_2 };

    Game00_Jmp_Tbl[G_No[2]]();
    njSetBackColor(0, 0, 0);
    BG_Draw_System();
    Basic_Sub();
    Check_Back_Demo();

    if (G_No[2] < 2) {
        D_007AA5EB = 1;
    }
}

/* Xbox: the save autoload starts here (PS2: in Init_Task_Aload). */
void Game0_0() {
    if (Title_At_a_Dash() != 0) {
        G_No[2] += 1;
        SaveInit(0, 2);
    }
}

/* The save test is inverted, as the retail branch layout has it. */
void Game0_1() {
    Disp_Copyright();
    TITLE_Move(1);

    if (SaveMove() <= 0) {
        Pause = 0;

        if (Request_G_No) {
            G_No[2] += 1;
        }
        return;
    }

    xb_DrawSaveFrame();
    G_Timer = 0;
    Pause = 1;
}

void Game0_2() {
    switch (G_No[3]) {
    case 0:
        Disp_Copyright();
        TITLE_Move(1);
        G_No[3] += 1;
        Switch_Screen_Init(1);
        break;

    case 1:
        if (Switch_Screen(1) != 0) {
            G_No[3] += 1;
            Cover_Timer = 23;
            return;
        }

        TITLE_Move(1);
        Disp_Copyright();
        break;

    case 2:
        FadeOut(1, 0xFF, 1);
        G_No[3] += 1;
        break;

    case 3:
        FadeOut(1, 0xFF, 1);
        G_No[3] += 1;
        TexRelease(601);
        title_tex_flag = 0;
        break;

    case 4:
        FadeOut(1, 0xFF, 1);
        G_No[3] += 1;
        Purge_mmtm_area(2);
        Make_texcash_of_list(2);
        break;

    case 5:
        FadeOut(1, 0xFF, 1);
        sub_00098407(65);
        G_No[1] = 0xC;
        G_No[2] = 0;
        G_No[3] = 0;
        cpReadyTask(MENU_TASK_NUM, Menu_Task);
        break;
    }
}

void Check_Back_Demo() {
    if (++G_Timer < 1800) {
        return;
    }

    if (G_No[1] == 12 || (G_No[2] == 2 && G_No[3] >= 2)) {
        return;
    }

    TexRelease(0x259);
    title_tex_flag = 0;
    Next_Demo_Loop();
    effect_work_init();
}

/* Xbox: calls xb_GetOnlineFlag first, as Game02 does. */
void Game12() {
    void (*Game12_Jmp_Tbl[3])() = { Game12_0, Game12_1, Game12_2 };

    xb_GetOnlineFlag(); /* Xbox only; the result is not used */
    Game12_Jmp_Tbl[G_No[2]]();
    BG_Draw_System();
    Basic_Sub();
    bg_pos_hosei_sub2(0);
    bg_pos_hosei_sub2(1);
    bg_pos_hosei_sub2(2);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(2);
    BG_move_Ex(0);
}

void Game12_0() {
    // Do nothing
}

void Game12_1() {
    G_No[2] += 1;
    Switch_Screen_Init(1);
    SsBgmFadeOut(0x1000);
}

/* Xbox: calls xb_LiveWork_Set2330(0) after cpExitTask(3). */
void Game12_2() {
    if (Switch_Screen(1) != 0) {
        G_No[1] = 1;
        G_No[2] = 0;
        G_No[3] = 0;
        Control_Time = 481;
        Cover_Timer = 23;
        effect_work_init();
        cpExitTask(3);
        xb_LiveWork_Set2330(0);
    }
}

/* Xbox: Game01 starts with a guard through Xbox-only code (it returns when
   xb_NetSync_CheckPlayers says so), and case 0 adds Xbox-only calls. */
void Game01() {
    if (xb_NetSync_IsDone() == 0) {
        xb_NetSync_Step();

        if (xb_NetSync_CheckPlayers() == 0) {
            return;
        }

        xb_NetSync_SetDone(1);
    }

    xb_GetOnlineFlag(); /* Xbox only; the result is not used */
    BG_Draw_System();
    Basic_Sub();
    Setup_Play_Type();

    switch (G_No[2]) {
    case 0:
        if (xb_GetOnlineFlag()) {
            xb_rebattle_Select(0);
            xb_LiveWork_Menu24C0(1);
        }

        Switch_Screen(1);
        G_No[2] += 1;
        S_No[0] = 0;
        S_No[1] = 0;
        S_No[2] = 0;
        S_No[3] = 0;
        xb_ReleaseScreenTextures();

        if (xb_GetOnlineFlag()) {
            xb_LiveWork_Set2334(1);
        }

        SsBgmHalfVolume(0);

        if (Mode_Type == 0) {
            sub_00098407(53);
        } else {
            sub_00098407(66);
        }

        Break_Into = 0;
        Stop_Combo = 0;

        if (Mode_Type != 2) {
            Random_ix32 = Interrupt_Timer;
            Random_ix32_ex = Interrupt_Timer;
        } else {
            sub_0009A8D0();
            All_Clear_Timer();
        }

        init_slow_flag();
        System_all_clear_Level_B();
        pulpul_stop();
        init_pulpul_work();
        break;

    case 1:
        Switch_Screen(1);
        G_No[2] += 1;
        break;

    case 2:
        if (Select_Player()) {
            G_No[2] += 1;
            Bonus_Game_Flag = 0;
            Switch_Screen_Init(0);
        }

        break;

    default:
        Select_Player();

        if (Switch_Screen(0) != 0) {
            Game01_Sub();
            Cover_Timer = 5;
            appear_type = 1;
            set_hitmark_color();

            if (Debug_w[0x1D]) {
                My_char[0] = Debug_w[0x1D] - 1;
            }

            if (Debug_w[0x1E]) {
                My_char[1] = Debug_w[0x1E] - 1;
            }

            Purge_texcash_of_list(3);
            Make_texcash_of_list(3);

            if (Demo_Flag) {
                G_No[1] = 2;
                G_No[2] = 0;
                G_No[3] = 0;
                E_No[0] = 4;
                E_No[1] = 0;
                E_No[2] = 0;
                E_No[3] = 0;
            } else {
                Demo_Time_Stop = 1;
                plw[0].wu.operator = 0;
                Operator_Status[0] = 0;
                plw[1].wu.operator = 0;
                Operator_Status[1] = 0;
            }

            if (plw[0].wu.operator != 0) {
                Sel_Arts_Complete[0] = -1;
            }

            if (plw[1].wu.operator != 0) {
                Sel_Arts_Complete[1] = -1;
            }

            if ((plw[0].wu.operator != 0) && (plw[1].wu.operator != 0)) {
                Play_Type = 1;
            } else {
                Play_Type = 0;
            }
        }

        break;
    }

    BG_move();
}

void Game02() {
    void (*Game02_Jmp_Tbl[8])() = { Game2_0, Game2_1, Game2_2, Game2_3, Game2_4, Game2_5, Game2_6, Game2_7 };

    xb_GetOnlineFlag(); /* Xbox only; the result is not used */
    Scene_Cut = Cut_Cut_Cut();
    Game02_Jmp_Tbl[G_No[2]]();
    BG_move_Ex(3);
}

/* Xbox: calls xb_GetOnlineFlag (the dword at 0x79A170) and xb_rebattle_Select. */
void Game2_0() {
    s16 ix;

    BG_Draw_System();
    Switch_Screen(0);

    if (Check_LDREQ_Clear() == 0) {
        return;
    }

    /* Xbox only */
    if (xb_GetOnlineFlag()) {
        xb_rebattle_Select(0);
    }

    System_all_clear_Level_B();

    switch (Mode_Type) {
    case 0:
        Play_Mode = 0;
        Replay_Status[0] = 0;
        Replay_Status[1] = 0;
        break;

    case 1:
        for (ix = 0; ix < 2; ix++) {
            if (save_w[1].Partner_Type[ix]) {
                plw[ix].wu.operator = 0;
                Operator_Status[ix] = 0;
            }
        }

        cpExitTask(1);
        /* fallthrough */

    case 2:
        Play_Mode = 1;
        sub_0009A8D0();
        All_Clear_Timer();

        /* Xbox: skipped while the xb_GetOnlineFlag flag is set */
        if (!xb_GetOnlineFlag()) {
            All_Clear_ETC();
        }

        break;

    case 5:
        Play_Mode = 3;
        All_Clear_Timer();
        break;
    }

    Check_Replay();

    if (Demo_Flag == 0) {
        Play_Mode = 0;
        Replay_Status[0] = 0;
        Replay_Status[1] = 0;
    }

    Game_difficulty = 15;
    Game_pause = 0;
    Demo_Time_Stop = 0;
    C_No[0] = 0;
    C_No[1] = 0;
    C_No[2] = 0;
    C_No[3] = 0;
    G_No[2] = 6;
    G_Timer = 10;
    Round_num = 0;
    Keep_Grade[0] = 0;
    Keep_Grade[1] = 0;

    if (Win_Record[0]) {
        Keep_Grade[0] = grade_get_my_grade(0) + 1;
    }

    if (Win_Record[1]) {
        Keep_Grade[1] = grade_get_my_grade(1) + 1;
    }

    Allow_a_battle_f = 0;
    Time_in_Time = 60;
    init_slow_flag();
    clear_hit_queue();
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    sub_0004384A();
    sub_0004384A(3);
}

/* Xbox: no ppgPurgeFromVRAM calls. */
void Game2_1() {
    mpp_w.inGame = 1;

    if (Game_pause != 0x81) {
        Game_timer += 1;
    }

    set_EXE_flag();
    Player_control();
    TATE00();
    Game_Management();
    BG_Draw_System();
    reqPlayerDraw();
    Basic_Sub_Ex();

    if (Disp_Cockpit) {
        Time_Control();
        vital_cont_main();
        player_face();
        player_name();
        combo_cont_main();
        stngauge_cont_main();
        spgauge_cont_main();
        Sa_frame_Write();
        Score_Sub();
        Flash_Lamp();
        Disp_Win_Record();
    }

    hit_check_main_process();
}

void Game2_2() {
    s16 i;

    BG_Draw_System();
    Switch_Screen(0);

    if (Check_LDREQ_Clear() == 0) {
        return;
    }

    SsBgmHalfVolume(0);
    All_Clear_Timer();
    Check_Replay();
    Game_difficulty = 15;
    Game_timer = 0;
    Game_pause = 0;
    Demo_Time_Stop = 0;
    C_No[0] = 0;
    C_No[1] = 0;
    C_No[2] = 0;
    C_No[3] = 0;
    G_Timer = 10;
    Round_num = 0;
    Keep_Grade[0] = 0;
    Keep_Grade[1] = 0;

    if (Win_Record[0]) {
        Keep_Grade[0] = grade_get_my_grade(0) + 1;
    }

    if (Win_Record[1]) {
        Keep_Grade[1] = grade_get_my_grade(1) + 1;
    }

    Allow_a_battle_f = 0;
    Time_in_Time = 60;
    init_slow_flag();
    effect_work_quick_init();
    clear_hit_queue();
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    sub_0004384A();
    Game01_Sub();
    appear_type = 1;
    TATE00();

    for (i = 0; i < 3; i++) {
        if (stage_bgw_number[bg_w.stage][i] > 0) {
            sub_000AF4AA(1 << i);
        }
    }

    if (bg_w.stage == 7) {
        sub_000AF4AA(4);
    }

    G_No[2] = 7;
}

void Game2_3() {
    Game2_1();

    if (--G_Timer == 0) {
        G_No[2] = 1;
        Clear_Flash_No();
    }
}

void Game2_4() {
    BG_Draw_System();
}

void Game2_5() {
    BG_Draw_System();

    switch (G_No[3]) {
    case 0:
        Switch_Screen(0);
        G_No[3] += 1;
        Stop_Update_Score = 0;
        vital_cont_init();
        count_cont_init(0);
        stngauge_cont_init();
        stngauge_work_clear();
        combo_cont_init();
        count_cont_init(1);
        Score[0][2] = 0;
        Score[1][2] = 0;
        Suicide[0] = 1;
        Game_pause = 0;
        pcon_rno[0] = 0;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
        pcon_rno[3] = 0;
        appear_type = 0;
        erase_extra_plef_work();
        compel_bg_init_position();
        win_lose_work_clear();
        TATE00();
        break;

    default:
        Game2_1();

        if (--G_Timer == 0) {
            G_No[2] = 1;
            Clear_Flash_No();
        }

        break;
    }
}

void Game2_6() {
    BG_Draw_System();
    Switch_Screen(0);

    if (Wait_Seek_Time() != 0) {
        G_No[2] = 3;
        TATE00();
    }
}

void Game2_7() {
    BG_Draw_System();
    Switch_Screen(0);

    if (Wait_Seek_Time() != 0) {
        G_No[2] = 3;
    }
}

void Game01_Sub() {
    Disp_Cockpit = 0;
    Stop_Update_Score = 0;
    vital_cont_init();
    count_cont_init(0);
    Score[0][1] = 0;
    Score[0][2] = 0;
    Score[1][1] = 0;
    Score[1][2] = 0;
    PL_Wins[0] = 0;
    PL_Wins[1] = 0;
    combo_cont_init();
    Clear_Win_Type();
    Lamp_No = 0;
    set_kizetsu_status(0);
    set_kizetsu_status(1);
    set_super_arts_status(0);
    set_super_arts_status(1);

    if (Demo_Flag && (sag_ikinari_max() != 0)) {
        spgauge_cont_init();
    } else {
        spgauge_cont_demo_init();
    }

    stngauge_cont_init();
}

/* Xbox: a versus win (Mode_Type 2), and case 2 while xb_GetOnlineFlag is set,
   go to G_No 13 through xb_ClearRebattleWork and return without BG_move; the PS2
   replay-info and champion setup for versus is gone. */
void Game03() {
    BG_Draw_System();
    move_effect_work(4);
    move_effect_work(5);
    Play_Mode = 0;
    Replay_Status[0] = 0;
    Replay_Status[1] = 0;

    switch (G_No[2]) {
    case 0:
        if (Winner_Scene() != 0) {
            switch (Mode_Type) {
            case 1:
                G_No[2] += 1;
                Rep_Game_Infor[10].play_type = 1;
                Rep_Game_Infor[10].winner = Winner_id;
                Switch_Screen_Init(0);

                if (Country == 3) {
                    if (Screen_PAL == 8) {
                        Rep_Game_Infor[10].play_type = 3;
                    } else {
                        Rep_Game_Infor[10].play_type = 4;
                    }
                }

                break;

            case 2:
                xb_ClearRebattleWork();
                G_No[1] = 13;
                G_No[2] = 0;

                if (xb_GetOnlineFlag()) {
                    xb_rebattle_Select(1);
                }

                return;

            case 5:
                G_No[2] = 5;
                cpReadyTask(MENU_TASK_NUM, Menu_Task);
                task[3].r_no[0] = 8;
                break;

            default:
                G_No[1] = 5;
                G_No[2] = 0;
                G_No[3] = 0;
                E_No[0] = 9;
                E_No[1] = 0;
                E_No[2] = 0;
                E_No[3] = 0;

                if (Battle_Q[WINNER]) {
                    G_No[1] = 0xB;
                    G_No[2] = 3;
                    G_No[3] = 0;
                }

                Cover_Timer = 24;

                if (Round_Operator[LOSER]) {
                    E_Number[LOSER][0] = 1;
                    E_Number[LOSER][1] = 0;
                    E_Number[LOSER][2] = 0;
                    E_Number[LOSER][3] = 0;
                }

                break;
            }
        }

        break;

    case 1:
        if (Switch_Screen(1) != 0) {
            G_No[2] += 1;
            E_No[0] = 1;
            E_No[1] = 2;
            E_No[2] = 2;
            E_No[3] = 0;
            Request_E_No = 0;
            cpReadyTask(MENU_TASK_NUM, Menu_Task);
            task[3].r_no[1] = 16;
            Cursor_Y_Pos[0][0] = 0;
            Cursor_Y_Pos[1][0] = 0;
            G_Timer = 4;
        }

        break;

    case 2:
        Switch_Screen(1);

        if (--G_Timer == 0) {
            Cover_Timer = 10;
            G_No[1] = 12;
            G_No[2] = 0;
            G_No[3] = 0;
        }

        if (xb_GetOnlineFlag()) {
            xb_ClearRebattleWork();
            G_No[1] = 13;
            G_No[2] = 0;
            return;
        }

        if (xb_GetOnlineFlag()) {
            xb_rebattle_Select(1);
        }

        break;

    case 3:
        if (Switch_Screen(1) != 0) {
            G_No[2] += 1;
            task[7].r_no[0] = 1;
            G_Timer = 4;
        }

        break;

    case 4:
        Switch_Screen(1);

        if (--G_Timer == 0) {
            // Do nothing
        }

        break;

    case 5:
        // Do nothing
        break;
    }

    BG_move();
}

void Game04() {
    s16 i;

    BG_Draw_System();
    move_effect_work(4);
    move_effect_work(5);

    switch (G_No[2]) {
    case 0:
        if (Loser_Scene() != 0) {
            if (Mode_Type == 5) {
                G_No[2] = 5;
                cpReadyTask(MENU_TASK_NUM, Menu_Task);
                task[3].r_no[0] = 8;
            } else {
                G_No[1] = 7;
                G_No[2] = 0;
                G_No[3] = 0;
                E_No[0] = 7;
                Cont_No[0] = 0;
                E_Number[LOSER][0] = 1;

                for (i = 1; i < 4; i++) {
                    E_No[i] = 0;
                    Cont_No[i] = 0;
                    E_Number[LOSER][i] = 0;
                }
            }
        }

        break;

    default:
        // Do nothing
        break;
    }

    BG_move();
}

void Game05() {
    BG_Draw_System();
    Basic_Sub();
    Setup_Play_Type();

    switch (G_No[2]) {
    case 0:
        G_No[2] += 1;
        SC_No[0] = 0;
        SC_No[1] = 0;
        SC_No[2] = 0;
        SC_No[3] = 0;

        if (Check_Bonus_Stage()) {
            SC_No[0] = 6;
        }

        Stop_Combo = 0;
        init_slow_flag();
        pulpul_stop();
        break;

    case 1:
        if (Next_CPU()) {
            G_No[2] += 1;
            Switch_Screen_Init(0);
        }

        break;

    default:
        Next_CPU();

        if (Switch_Screen(0) != 0) {
            Cover_Timer = 24;
            Purge_texcash_of_list(3);
            Make_texcash_of_list(3);

            if (Bonus_Type == 0) {
                Game01_Sub();
            }

            BGM_Stop();

            if (Bonus_Type == 0) {
                G_No[1] = 2;
                G_No[2] = 0;
                E_No[0] = 4;
                E_No[1] = 0;
                E_No[2] = 0;
                E_No[3] = 0;
                Bonus_Game_Flag = 0;
            } else {
                G_No[1] = 9;
                G_No[2] = 0;
                G_No[3] = 0;
                E_No[0] = 4;
                E_No[1] = 0;
                E_No[2] = 0;
                E_No[3] = 0;
            }
        }

        break;
    }

    BG_move();
}

void Game06() {
    s16 xx;

    BG_Draw_System();
    Basic_Sub_Ex();

    if (!Break_Into) {
        switch (G_No[2]) {
        case 0:
            G_No[2] += 1;
            Game_pause = 0;
            Stock_Com_Color[Player_id] = -1;
            Stock_Com_Arts[Player_id] = -1;
            Last_Player_id = -1;
            Control_Time = 481;
            E_No[0] = 8;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;

            for (xx = 0; xx < 4; xx++) {
                GO_No[xx] = 0;
            }

            make_texcash_work(13);
            break;

        case 1:
            if (Game_Over()) {
                G_Timer = 60;

                if (Check_Disp_Ranking() != 0) {
                    G_No[2] += 1;
                } else {
                    G_No[2] = 3;
                }
            }

            break;

        case 2:
            if (Disp_Ranking() != 0) {
                G_No[2] += 1;
                G_Timer = 1;
            }

            break;

        case 3:
            if (--G_Timer == 0) {
                G_No[2] += 1;
                Clear_Disp_Ranking(0);
                Clear_Disp_Ranking(1);
                Switch_Screen_Init(1);
            }

            break;

        case 4:
            if (Switch_Screen(1) != 0) {
                Cover_Timer = 24;
                Forbid_Break = 0;
                Clear_Flash_No();
                Clear_Personal_Data(LOSER);
                grade_check_work_1st_init(LOSER, 0);
                grade_check_work_1st_init(LOSER, 1);

                if (Request_Break[0] != 0 || Request_Break[1] != 0) {
                    Request_Break_Sub(0);
                    Request_Break_Sub(1);
                    G_No[1] = 1;
                    G_No[2] = 0;
                    G_No[3] = 0;
                    E_No[0] = 2;
                    E_No[1] = 0;
                    E_No[2] = 0;
                    E_No[3] = 0;
                    break;
                }

                for (xx = 0; xx < 20; xx++) {
                    save_w[Present_Mode].Ranking[xx] = Ranking_Data[xx];
                }

                if (save_w[Present_Mode].Auto_Save) {
                    G_No[2] = 5;
                    G_No[3] = 0;
                    G_Timer = 4;
                    Pause_ID = Player_id;
                    cpReadyTask(MENU_TASK_NUM, Menu_Task);
                    System_all_clear_Level_B();
                    Menu_Init(&task[3]);
                    task[3].r_no[0] = 9;
                    task[3].r_no[1] = 0;
                    Forbid_Reset = 1;
                    make_texcash_work(12);
                    Unsubstantial_BG[0] = 1;
                    Copy_Check_w();
                    cpExitTask(SAVER_TASK_NUM);
                } else {
                    G_No[2] = 6;
                }
            }

            break;

        case 5:
            if (G_No[3] == 0) {
                FadeOut(1, 0xFF, 1);

                if (--G_Timer == 0) {
                    G_No[3] = 1;
                }
            }

            break;

        case 6:
            Switch_Screen(1);
            G_No[0] = 1;
            G_No[1] = 0x63;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 0;
            E_No[1] = 0x63;
            E_No[2] = 0;
            E_No[3] = 0;
            D_No[0] = 0;
            D_No[1] = 0;
            D_No[2] = 0;
            D_No[3] = 0;
            Get_Demo_Index = 0;
            Combo_Demo_Flag = 0;
            cpReadyTask(ENTRY_TASK_NUM, Entry_Task);
            Purge_mmtm_area(5);
            Make_texcash_of_list(5);
            System_all_clear_Level_B();
            break;
        }

        BG_move();
    }
}

void Request_Break_Sub(s16 PL_id) {
    if ((Request_Break[PL_id] != 0) && (Ck_Break_Into(0, 0, PL_id) != 0)) {
        plw[PL_id].wu.operator = 1;
        Operator_Status[PL_id] = 1;
    }
}

s32 Check_Disp_Ranking() {
    s16 rank_type = Disp_Rank_Sub(0);

    if (rank_type != -1) {
        Rank_Type = rank_type;
        Present_Rank[0] = Rank_In[0][rank_type];
        Present_Rank[1] = Rank_In[1][rank_type];
        return 1;
    }

    rank_type = Disp_Rank_Sub(1);

    if (rank_type != -1) {
        Rank_Type = rank_type;
        Present_Rank[1] = Rank_In[1][rank_type];
        return 1;
    }

    return 0;
}

s16 Disp_Rank_Sub(s16 PL_id) {
    if (Request_Disp_Rank[PL_id][3] >= 0) {
        return 15;
    }

    if (Request_Disp_Rank[PL_id][2] >= 0) {
        return 10;
    }

    if (Request_Disp_Rank[PL_id][1] >= 0) {
        return 5;
    }

    if (Request_Disp_Rank[PL_id][0] >= 0) {
        return 0;
    }

    return -1;
}

s32 Disp_Ranking() {
    switch (G_No[3]) {
    case 0:
        G_No[3] += 1;
        Switch_Screen_Init(1);
        sub_00098407(57);
        break;

    case 1:
        if (Switch_Screen(1) != 0) {
            Cover_Timer = 24;
            G_No[3] += 1;
            D_No[0] = 1;
            D_No[1] = 0;
            D_No[2] = 0;
            D_No[3] = 0;
            Clear_Personal_Data(0);
            grade_check_work_1st_init(0, 0);
            grade_check_work_1st_init(0, 1);
            Clear_Personal_Data(1);
            grade_check_work_1st_init(1, 0);
            grade_check_work_1st_init(1, 1);
        }

        break;

    case 2:
        Switch_Screen(1);
        Ranking();

        if (--Cover_Timer == 0) {
            G_No[3] += 1;
            Switch_Screen_Init(1);
        }

        break;

    case 3:
        Ranking();

        if (Switch_Screen_Revival(1) != 0) {
            G_No[3] += 1;
            Forbid_Break = 0;
        }

        break;

    default:
        if (Ranking() != 0) {
            BGM_Stop();
            return 1;
        }

        break;
    }

    return 0;
}

void Game07() {
    BG_Draw_System();
    Basic_Sub();

    switch (G_No[2]) {
    case 0:
        if (Continue_Scene() != 0) {
            G_No[1] = 6;
            G_No[2] = 0;
        }

        break;
    }

    BG_move();
}

void Game08() {
    BG_Draw_System();

    switch (G_No[2]) {
    case 0:
        Switch_Screen(0);
        G_No[2] = 1;
        Game_pause = 0;
        Final_Result_id = WINNER;
        WGJ_Target = WINNER;
        WGJ_Win = Win_Record[WINNER];
        grade_final_grade_bonus();
        WGJ_Score = Continue_Coin[WINNER] + Score[WINNER][0];
        Purge_mmtm_area(6);
        cpExitTask(MENU_TASK_NUM);
        cpExitTask(PAUSE_TASK_NUM);
        break;

    case 1:
        if (Ending_main(End_PL) && (Request_Fade(9) != 0)) {
            G_No[2] += 1;
        }

        break;

    case 2:
        if (Check_Fade_Complete_SP() != 0) {
            G_No[2] += 1;
            G_Timer = 10;
            Suicide[4] = 1;
        }

        break;

    case 3:
        if (--G_Timer == 0) {
            G_No[1] = 6;
            G_No[2] = 0;
            E_No[0] = 8;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;
            Clear_Personal_Data(0);
            Clear_Personal_Data(1);
            plw[0].wu.operator = 0;
            plw[1].wu.operator = 0;
            Operator_Status[0] = 0;
            Operator_Status[1] = 0;
            Last_Player_id = Player_Number = -1;
            Purge_mmtm_area(6);
            System_all_clear_Level_B();
        }

        break;
    }

    move_effect_work(4);
}

void Game09() {
    switch (G_No[2]) {
    case 0:
        BG_Draw_System();
        Switch_Screen(0);
        System_all_clear_Level_B();
        Bonus_Game_Flag = Bonus_Type;
        Game_difficulty = 15;
        Game_timer = 0;
        Game_pause = 0;
        Demo_Time_Stop = 0;
        C_No[0] = 0;
        C_No[1] = 0;
        C_No[2] = 0;
        C_No[3] = 0;
        G_No[2] += 1;
        G_Timer = 19;
        Round_num = 0;
        Allow_a_battle_f = 0;
        Time_in_Time = 60;
        init_slow_flag();
        clear_hit_queue();
        pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
        bbbs_com_initialize();
        ca_check_flag = 1;
        Bonus_Game_Work = 20;
        Bonus_Game_result = 0;
        Bonus_Game_ex_result = 0;
        bg_work_clear();
        win_lose_work_clear();

        if (Bonus_Game_Flag == 0x15) {
            My_char[COM_id] = 12;
        } else {
            My_char[COM_id] = My_char[Player_id];
        }

        break;

    case 1:
        BG_Draw_System();
        Switch_Screen(1);

        if (--G_Timer == 0) {
            if (Check_LDREQ_Queue_BG((u16)bg_w.stage) == 0) {
                G_Timer = 1;
            } else {
                G_No[2] += 1;
                Clear_Flash_No();

                if (Bonus_Type == 0x15) {
                    makeup_bonus_game_level(COM_id);
                    effect_35_init(0x3C, 5);
                    effect_J2_init(0x78);
                    effect_35_init(0xB4, 7);
                    effect_58_init(6, 0xB4, 0xA1);
                } else {
                    effect_35_init(0x3C, 6);
                    effect_35_init(0x78, 7);
                    effect_58_init(6, 0x78, 0xA1);
                }

                TATE00();
                Switch_Screen_Init(0);
                Bonus_Sub();
            }
        }

        break;

    case 2:
        Bonus_Sub();

        if (Switch_Screen_Revival(1) != 0) {
            G_No[2] += 1;
            Forbid_Break = 0;
        }

        break;

    case 3:
        if (Bonus_Sub()) {
            G_No[2] += 1;
            Cover_Timer = 24;
            Stop_Combo = 1;
            Switch_Screen_Init(0);
        }

        break;

    case 4:
        Bonus_Sub();

        if (Switch_Screen(0) != 0) {
            G_No[2] += 1;
            G_Timer = 3;
            SE_All_Off();
            Clear_Flash_No();
            effect_work_kill_mod_plcol();
        }

        break;

    default:
        Switch_Screen(0);
        Bonus_Sub();

        if (--G_Timer == 0) {
            Cover_Timer = 24;
            Suicide[0] = 1;
            System_all_clear_Level_B();
            G_No[1] = 10;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 9;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;
        }

        break;
    }

    BG_move();
}

s16 Bonus_Sub() {
    s16 x;

    mpp_w.inGame = 1;
    Scene_Cut = Cut_Cut_Cut();
    Bonus_Game_Complete = 0;

    if (Game_pause != 0x81) {
        Game_timer += 1;
    }

    set_EXE_flag();
    Time_Control();

    if (Bonus_Type == 0x15) {
        Bonus_Game_Complete = Player_control_bonus();
    } else {
        Bonus_Game_Complete = Player_control_bonus2();
    }

    TATE00();
    x = 0;
    x = Game_Management();
    BG_Draw_System();
    reqPlayerDraw();
    Basic_Sub_Ex();
    hit_check_main_process();
    return x;
}

void Game10() {
    BG_Draw_System();
    Basic_Sub();
    Setup_Play_Type();

    switch (G_No[2]) {
    case 0:
        Switch_Screen(0);
        G_No[2] += 1;
        SC_No[0] = 0;
        SC_No[1] = 0;
        SC_No[2] = 0;
        SC_No[3] = 0;
        Stop_Combo = 0;
        init_slow_flag();
        break;

    case 1:
        if (After_Bonus() != 0) {
            G_No[2] += 1;
            Switch_Screen_Init(0);
        }

        break;

    default:
        After_Bonus();

        if (Switch_Screen(0) != 0) {
            Cover_Timer = 24;
            Game01_Sub();
            BGM_Stop();
            G_No[1] = 2;
            G_No[2] = 0;
            E_No[0] = 4;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;
            Bonus_Game_Flag = 0;
            Purge_texcash_of_list(3);
            Make_texcash_of_list(3);
        }

        break;
    }

    BG_move();
}

void Game11() {
    BG_Draw_System();
    Basic_Sub();
    Setup_Play_Type();

    switch (G_No[2]) {
    case 0:
        Switch_Screen(0);
        G_No[2] += 1;
        SC_No[0] = 0;
        SC_No[1] = 0;
        SC_No[2] = 0;
        SC_No[3] = 0;
        Stop_Combo = 0;
        Bonus_Type = 0;
        init_slow_flag();
        break;

    case 1:
        if (Next_Q()) {
            G_No[2] += 1;
            Switch_Screen_Init(0);
        }

        break;

    case 2:
        Next_Q();

        if (Switch_Screen(0) != 0) {
            Cover_Timer = 24;
            Game01_Sub();
            BGM_Stop();
            Purge_texcash_of_list(3);
            Make_texcash_of_list(3);

            if (Bonus_Type == 0) {
                G_No[1] = 2;
                G_No[2] = 0;
                E_No[0] = 4;
                E_No[1] = 0;
                E_No[2] = 0;
                E_No[3] = 0;
                Bonus_Game_Flag = 0;
            } else {
                G_No[1] = 9;
                G_No[2] = 0;
                G_No[3] = 0;
                E_No[0] = 4;
                E_No[1] = 0;
                E_No[2] = 0;
                E_No[3] = 0;
            }
        }

        break;

    case 3:
        G_No[2] += 1;
        SC_No[0] = 0;
        SC_No[1] = 0;
        SC_No[2] = 0;
        SC_No[3] = 0;
        Stop_Combo = 0;
        Bonus_Type = 0;
        init_slow_flag();
        Switch_Screen_Init(0);
        break;

    case 4:
        if (Switch_Screen(0) != 0) {
            G_No[2] = 1;
            Cover_Timer = 24;
        }

        break;
    }

    BG_move();
}

void Loop_Demo(struct _TASK* /* unused */) {
    if (Ck_Coin()) {
        Next_Title_Sub();
        return;
    }

    switch (G_No[1]) {
    case 0:
        G_No[1] += 1;
        G_No[2] = 0;
        G_No[3] = 0;
        D_No[0] = 0;
        D_No[1] = 0;
        D_No[2] = 0;
        D_No[3] = 0;
        E_No[1] = 0x63;
        Demo_PL_Index = 0;
        Demo_Stage_Index = 0;
        Select_Demo_Index = 0;
        check_screen_L = 0;
        check_screen_S = 0;
        Insert_Y = 23;
        Demo_Flag = 0;
        Play_Mode = 0;
        Replay_Status[0] = 0;
        Replay_Status[1] = 0;
        Present_Mode = 0;
        title_tex_flag = 0;
        Reset_Bootrom = 0;
        break;

    case 1:
        Basic_Sub();

        if (CAPCOM_Logo() != 0) {
            Loop_Demo_Sub();
            Insert_Y = 23;
            E_No[1] = 2;
            E_Timer = 1;
            return;
        }

        break;

    case 2:
        Basic_Sub();

        if (Title()) {
            Loop_Demo_Sub();
            Insert_Y = 17;
            D_No[0] = 1;
            return;
        }

        break;

    case 3:
        if (Play_Demo() != 0) {
            Switch_Screen(1);
            Loop_Demo_Sub();
            Rank_Type = 0;
            Demo_Type = 0;
            SsAllNoteOff();
            return;
        }

        break;

    case 4:
        Basic_Sub();

        if (Ranking() != 0) {
            Switch_Screen(1);
            Loop_Demo_Sub();
            sub_0004384A(3);
            return;
        }

        break;

    case 5:
        if (Play_Demo() != 0) {
            Loop_Demo_Sub();
            Demo_Type = 1;
            Rank_Type = 5;
            Demo_Type = 1;
            SsAllNoteOff();
            return;
        }

        break;

    case 6:
        Basic_Sub();

        if (Ranking() != 0) {
            Switch_Screen(1);
            Loop_Demo_Sub();
            System_all_clear_Level_B();
            Purge_mmtm_area(6);
            Game_pause = 0;
            G_No[1] = 1;
            E_No[1] = 0x63;
            return;
        }

        break;

    default:
        Switch_Screen(1);

        if (--Cover_Timer <= 0) {
            Next_Demo_Loop();
        }

        break;
    }
}

void Next_Demo_Loop() {
    G_No[0] = 1;
    G_No[1] = 1;
    G_No[2] = 0;
    D_No[0] = 0;
    D_No[1] = 0;
    D_No[2] = 0;
    D_No[3] = 0;
    E_No[0] = 0;
    E_No[1] = 0x63;
    E_No[2] = 0;
    E_No[3] = 0;
    Demo_PL_Index = 0;
    Demo_Stage_Index = 0;
    Select_Demo_Index = 0;
    Demo_Flag = 0;
    Present_Mode = 0;
    Game_pause = 0;
    Play_Mode = 0;
    Replay_Status[0] = 0;
    Replay_Status[1] = 0;
    System_all_clear_Level_B();
    Purge_mmtm_area(6);
}

void Loop_Demo_Sub() {
    G_No[1] += 1;
    G_No[2] = 0;
    D_No[0] = 0;
    D_No[1] = 0;
    D_No[2] = 0;
    D_No[3] = 0;
    E_No[1] = 1;
    Play_Game = 0;
    pulpul_stop();
    pp_operator_check_flag(1);
}

void Next_Title_Sub() {
    s16 ix;

    if (G_No[1] != 0x63) {
        SsAllNoteOff();
    }

    if (Demo_Flag == 0) {
        SsRequest(106);
    }

    TexRelease(0x258);
    TexRelease_OP();
    System_all_clear_Level_B();
    Purge_mmtm_area(6);
    G_Timer = 0;

    for (ix = 0; ix < 4; ix++) {
        vm_w.r_no[ix] = 0;
        G_No[ix] = 0;
        E_No[ix] = 0;
        D_No[ix] = 0;
        task->r_no[ix] = 0;
    }

    G_No[0] = 2;
    E_No[0] = 1;
    task->r_no[0] = 1;
    Demo_Flag = 1;
    Game_pause = 0;
    judge_flag = 0;
    Pause_Down = 0;
    Disp_Attack_Data = 0;
    seraph_flag = 0;
    End_Training = 0;
    Forbid_Reset = 0;
    Exec_Wipe = 0;
    Present_Mode = 1;
    Insert_Y = 23;
    Before_Select_Sub();
    cpReadyTask(ENTRY_TASK_NUM, Entry_Task);
    sub_0004384A(2);
}

void Time_Control() {
    count_cont_main();

    if ((Allow_a_battle_f == 0) || (Demo_Time_Stop != 0) || (Bonus_Game_Flag != 0)) {
        return;
    }

    if (Game_pause != 0x81) {
        if (Control_Time >= Limit_Time) {
            Control_Time = Limit_Time;
            return;
        }

        if (--Time_in_Time == 0) {
            Time_in_Time = 60;
            Control_Time += 1;
        }
    }
}

/* Xbox: the joining player comes from xb_GetJoiningPlayer (START or A; PS2 START
   only). */
s16 Ck_Coin() {
    s16 PL_id;

    switch (G_No[3]) {
    case 0:
        PL_id = xb_GetJoiningPlayer();

        if (PL_id == -1) {
            return 0;
        }

        ToneDown(0xFF, 0);
        Request_LDREQ_Break();
        G_No[3] = 1;
        plw[PL_id].wu.operator = 1;
        Operator_Status[PL_id] = 1;
        Champion = PL_id;
        plw[PL_id ^ 1].wu.operator = 0;
        Operator_Status[PL_id ^ 1] = 0;
        return 0;

    default:
    case 1:
        ToneDown(0xFF, 0);
        PL_id = Check_LDREQ_Break();
        return PL_id ^ 1;
    }
}

void Before_Select_Sub() {
    s16 xx;

    Request_G_No = 0;
    Request_E_No = 0;
    Allow_a_battle_f = 0;
    Bonus_Type = 0;

    if (Demo_Flag == 0) {
        Control_Time = 2048;
        Round_Level = 7;
    } else {
        Control_Time = 481;
    }

    Super_Arts[0] = 0;
    Super_Arts[1] = 0;
    Exec_Wipe = 0;
    Fade_Flag = 0;
    Stock_Com_Color[0] = -1;
    Stock_Com_Arts[0] = -1;
    Stock_Com_Color[1] = -1;
    Stock_Com_Arts[1] = -1;
    Bonus_Game_Flag = 0;
    Combo_Demo_Flag = 0;
    paring_counter[0] = 0;
    paring_bonus_r[0] = 0;
    paring_counter[1] = 0;
    paring_bonus_r[1] = 0;
    Clear_Disp_Ranking(0);
    Clear_Disp_Ranking(1);
    Clear_Personal_Data(0);
    grade_check_work_1st_init(0, 0);
    grade_check_work_1st_init(0, 1);
    Clear_Personal_Data(1);
    grade_check_work_1st_init(1, 0);
    grade_check_work_1st_init(1, 1);
    Last_Player_id = Player_Number = -1;
    Round_Level = 3;
    Time_in_Time = 60;

    if (Mode_Type != 2) {
        xx = system_timer;
        Random_ix16 = xx & 0x3F;
        Random_ix32 = xx & 0x7F;
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void Game() {
    void (*Game_Jmp_Tbl[13])() = { Game00, Game01, Game02, Game03, Game04, Game05, Game06,
                                   Game07, Game08, Game09, Game10, Game11, Game12 };

    if (G_No[1] == 2 || G_No[1] == 9) {
        Play_Game = 1;
    } else if (G_No[1] == 8) {
        Play_Game = 2;
    }

    Game_Jmp_Tbl[G_No[1]]();
}

void Wait_Auto_Load(struct _TASK* /* unused */) {
    Basic_Sub();
    BG_Draw_System();
    bg_pos_hosei_sub2(0);
    Bg_Family_Set_appoint(0);
    BG_move_Ex(0);
}
#endif
