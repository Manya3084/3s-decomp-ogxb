/* System helpers, retail sf33rd.xbe.
 * Disp_Copyright is 0x9ABAE. Country is the byte at 0x7A8748.
 * SSPutStrPro is 0xE9C82.
 *
 * Switch_Screen_Init is 0x9948B size 0x29, interior after the ret.
 * Switch_Screen is 0x994B4 size 0x2B, interior after the ret.
 * Switch_Screen_Revival is 0x994DF size 0x2B, interior after the ret.
 * Convert_User_Setting is 0x9950A size 0x16E and is a scanned start.
 * Clear_Personal_Data is 0x99678 size 0x179, interior after the ret.
 * Check_Count_Cut is 0x997F1 size 0x50, interior after the ret.
 * Disp_Personal_Count is 0x99841 size 0x25, interior after the ret.
 * Setup_Play_Type is 0x99866 size 0x1E, interior after the ret.
 * Clear_Flash_No is 0x99884 size 0x30, interior after the ret.
 * Cut_Cut_Cut is 0x998B4 size 0x37, interior after the ret.
 * Score_Sub is 0x998EB size 0x14B and is a scanned start.
 * Disp_Win_Record_Sub is 0x99A36 size 0xA7 and is a scanned start.
 * Setup_Target_PL is 0x99ADD size 0x25, interior after the ret.
 * Setup_Final_Grade is 0x99B02 size 0x4C, interior after the ret.
 * Clear_Win_Type is 0x99B4E size 0x31, interior after the ret.
 * Clear_Disp_Ranking is 0x99B7F size 0x1E, interior after the ret.
 * Setup_ID is 0x99B9D size 0x24, interior after the ret.
 * Setup_IO_ConvDataDefault is 0x99BC1 size 0x5C and is a scanned start.
 * Disp_Win_Record is 0x9ACFB size 0xAA, interior after the ret.
 * Button_Cut_EX is 0x9ADA5 size 0x38, interior after the ret.
 * Save_Game_Data is 0x99C1D size 0x15A, interior after the ret.
 * Copy_Save_w is 0x99D77 size 0x138, interior after the ret.
 * Copy_Check_w is 0x99EAF size 0x40, interior after the ret.
 * Setup_Default_Game_Option is 0x99EEF size 0x2A, interior after the ret.
 * Check_Change_Contents is 0x99F19 size 0xD7, interior after the ret.
 * Check_Menu_Task is 0x99FF0 size 0x34, interior after the jmp.
 * Setup_Limit_Time is 0x9A024 size 0x4D, interior after the ret.
 * Setup_Training_Difficulty is 0x9A071 size 0x47, interior after the ret.
 * Setup_BG is 0x9A0B8 size 0x61, interior after the ret.
 * Setup_Virtual_BG is 0x9A119 size 0x5A, interior after the ret.
 * BG_move is 0x9A173 size 0x25, interior after the ret.
 * BG_move_Ex is 0x9A198 size 0x5, interior after the ret.
 * Basic_Sub is 0x9A19D size 0x3A, interior after the jmp.
 * Basic_Sub_Ex is 0x9A1D7 size 0x2E, interior after the ret.
 * Check_PL_Load is 0x9A205 size 0x1F, interior after the ret.
 * BG_Draw_System is 0x9A224 size 0x9D and is a scanned start.
 * Check_Demo_Data is 0x9A2C1 size 0x3C, interior after the ret.
 * Cut_Cut_C_Timer is 0x9A307 size 0x23, interior after the jmp.
 * Switch_Priority_76 is 0x9A32A size 0xF, interior after the ret.
 * Cut_Cut_Sub is 0x9A339 size 0x3A, interior after the ret.
 * Cut_Cut_Loser is 0x9A373 size 0x2B, interior after the ret.
 * Reset_Sub0 is 0x9A39E size 0x37, interior after the ret.
 * Setup_Replay_Header is 0x9A3D5 size 0x12B, interior after the ret.
 * Get_Replay_Header is 0x9A500 size 0xD8, interior after the ret.
 * Setup_Replay_Buff is 0x9A5D8 size 0x7F, interior after the ret.
 * Replay is 0x9A657 size 0xFE, interior after the ret.
 * Check_SysDir_Page is 0x9A755 size 0x2A, interior after the ret.
 * Clear_Flash_Init is 0x9A77F size 0x1B, interior after the ret.
 * Clear_Flash_Sub is 0x9A79A size 0x60, interior after the ret.
 * Copy_Key_Disp_Work is 0x9A7FA size 0x36, interior after the ret.
 * Check_Extra_Setting is 0x9A830 size 0x71, interior after the jmp.
 * All_Clear_Timer is 0x9A8A1 size 0x14, interior after the ret.
 * All_Clear_ETC is 0x9A8B5 size 0x1B, interior after the ret.
 * Request_Fade is 0x9A8EB size 0x39, interior after the ret.
 * Check_Fade_Complete_SP is 0x9A924 size 0x10, interior after the ret.
 * Check_Fade_Complete is 0x9A934 size 0x1A, interior after the ret.
 * Check_Partners_Rank is 0x9A94E size 0x2C, interior after the ret.
 * Check_Sort_Score is 0x9A97A size 0x78 and is a scanned start.
 * Check_Sort_Wins is 0x9A9F2 size 0x7A, interior after the jmp.
 * Check_CPU_Grade_Score is 0x9AA6C size 0x44, interior after the jmp.
 * Check_Grade_Score is 0x9AAB0 size 0x46, interior after the ret.
 * Disp_Digit16x24 is 0x9AAF6 size 0xB8 and is a scanned start.
 * Setup_Candidate_Buff is 0x9AC15 size 0x60, interior after the ret.
 * Check_EM_Sub is 0x9AC75 size 0x59 and is a scanned start.
 * All_Clear_Suicide is 0x9ACCE size 0x14, interior after the ret.
 * Clear_Break_Com is 0x9ACE2 size 0x19, interior after the ret.
 * Check_Replay is 0x9AF4E size 0x15B, interior after the ret.
 * Get_Replay is 0x9B0A9 size 0x59 and is a scanned start.
 * Check_Sort_CPU_Grade is 0x9B102 size 0x68, interior after the ret.
 * Check_Sort_Grade is 0x9B16A size 0x68, interior after the ret.
 * Check_EM_Buff is 0x9B1D2 size 0x67 and is a scanned start.
 * Initialize_EM_Candidate is 0x9B239 size 0xA9 and is a scanned start.
 * Check_Replay_Status is 0x9B2E2 size 0x45, interior after the ret.
 * Check_Ranking is 0x9B327 size 0x16A, interior after the ret.
 * Check_Same_CPU is 0x9B491 size 0xA4 and is a scanned start.
 * Ranking_Init is 0x978F9 size 0x21, interior after the ret.
 * Soft_Reset_Sub is 0x9ADF3 size 0xAF, interior after the ret.
 * cpReadyTask is 0xC82BC size 0x27, interior after the ret.
 * cpExitTask is 0xC82E3 size 0x1E, interior after the ret.
 *
 * Forbid_Break is the byte at 0x7A8804. Exec_Wipe is 0x7A82F9.
 * Gap_Timer is 0x7A8316. Stop_SG is 0x7A8428. Escape_SS is 0x7A80CE.
 * Stop_Combo is 0x7A82FC. Switch_Screen_Init reads no argument.
 * p1sw_0 is the word at 0x7C557C and p2sw_0 is the word at 0x7C5B90.
 * p1sw_1 is the word at 0x7BD3CA and p2sw_1 is the word at 0x7C5568.
 * Present_Mode is the byte at 0x7A819C. save_w is 0x7BD3E0, stride 0x208.
 * Convert_Data is 0x265528 and matches the 12 PlayStation 2 words.
 * Convert_User_Setting always converts the switch word.
 * SC_Personal_Time is the word at 0x7A81D8 and stores 481.
 * Score[PL][0] is the dword at PL * 12 + 0x7A8720.
 * Continue_Count is the byte at 0x7A89D2. Continue_Cut is 0x7A8420.
 * DE_X is the word at 0x7A86D8. Operator_Status is the word at 0x7A816A.
 * Play_Type is the byte at 0x7A812D. F_No0 is 0x7A86E2, F_No1 is 0x7A82CE,
 * F_No2 is 0x7A8806, and F_No3 is 0x7A8790 (from Flash_Start, Flash_Please
 * and Exit_Title_Sub_Entry, which each use a different subset). Personal_Disp_Flag is 0x7A85C2.
 * Mode_Type is the byte at 0x7A825A. Stop_Update_Score is 0x7A82AA.
 * Keep_Score is 0x7A8288. Continue_Coin is 0x7A86E0. Coin_Message_Data
 * is 0x25C444 and matches the 14 PlayStation 2 bytes. Score_Sub and
 * Setup_IO_ConvDataDefault check the stack cookie through 0x175BFC.
 * "WIN" is 0x265750 and "WINS" is 0x265754. Win_Record is the word at
 * 0x7A8164. VS_Win_Record is the word at 0x7A8128. Winner_id is the byte
 * at 0x7A8472. Round_Operator is 0x7A833C. Player_id is 0x7A810F.
 * LOSER is 0x7A82FD. Break_Com is 0x7A8680, stride 20. Final_Result_id
 * is 0x7A8750. WGJ_Target is 0x7A81C4. WGJ_Win is 0x7A89B2. WGJ_Score
 * is 0x7A8774. win_type is 0x7A86B0, flash_win_type is 0x7A8458, and
 * sync_win_type is 0x7A85A0. Rank_In is 0x7A87E8. Request_Disp_Rank is
 * 0x7A8360. COM_id is 0x7A81C0. Convert_Buff is 0x7A8940.
 * Time_Limit_Data is 0x265540 and matches the four PlayStation 2 bytes,
 * including -1 as 0xFF. Battle_Number_Data is 0x265544 and matches.
 * Check_Buff is 0x7A8840. Ranking_Data is 0xC7C840. ck_ex_option is
 * 0x7C59A0. useAnalogStickData is the byte at 0x7AA5F4. screen_mode is
 * the byte at 0x7C5959. Game_Default_Data is 0x265548. Its first 32
 * bytes match the PlayStation 2 default, starting with pad shots
 * 0, 1, 2, 11, 3, 4, 5, 11. save_w[1].sum is 0x7BD5E4.
 * Ex_Page_Data is 0x25BF0C and matches 7, 7, 4, 6. Level_18_Data is
 * 0x2410C0 and matches the 306 PlayStation 2 bytes. Column 16 is loaded
 * from 0x2410E0. Limit_Time is the word at 0x7A88D6. Control_Time is
 * the word at 0x7A81EE. task is 0x7BE020, stride 0x14. r_no is at +8
 * and condition is at +0xC, so task[3].r_no is 0x7BE064 and
 * task[3].condition is 0x7BE068.
 * Unsubstantial_BG is 0x7A851C. bg_w is 0x7BC520. bgw[0] is 0x7BC558,
 * stride 0x90. xy[0].disp.pos is 0x7BC572 and old_pos_x is 0x7BC588.
 * Setup_BG and Setup_Virtual_BG call 0x55DC8. BG_move calls 0xB37E6
 * and 0xB36C0. Basic_Sub and Basic_Sub_Ex call 0x4A650. Check_PL_Load
 * calls 0x59CA6. BG_move_Ex tails into scr_calc.
 * bg_disp_off is the byte at 0x7BC982. Screen_Switch_Buffer is the word
 * at 0x7BC98A. Play_Game is the byte at 0x7A89EC. BG_Draw_System calls
 * 0xAFC57 when the display byte is clear. Demo_Timer is the word at
 * 0x7A8828 and Demo_Ptr is the pointer at 0x7A8798. C_Timer is the word
 * at 0x7A8794. Order[56] is the byte at 0x7A83B8 and Order_Timer[56] is
 * the byte at 0x7A84B8. Pause is 0x7A8816. Game_pause is 0x7A89B0.
 * Extra_Break is 0x7A89A0. Play_Mode is 0x7A8178. Replay_Status is
 * 0x7A86C8. System_all_clear_Level_B 0x9A2FD size 0xA: the PS2 C.
 * Rep_Game_Infor[10] is 0x7C5828. Replay_w is 0x7BE120. Its champion
 * byte is 0x7C5564 and full_data is the next byte. Control_Time_Buff
 * is 0x7BE3E0 and Difficulty is 0x7BE3E2. key_buff[0] is 0x7BE4D8.
 * My_char is 0x7A8114. Super_Arts is 0x7A89FE. Player_Color is
 * 0x7A8906. Direction_Working is 0x7A82D8. Vital_Handicap is 0x7A89E0.
 * Random_ix16 is 0x7A8470, Random_ix32 is 0x7A891E, Random_ix16_ex is
 * 0x7A8824, and Random_ix32_ex is 0x7A817A. The com copies are 0x7A82AE,
 * 0x7A8826, 0x7A8768, and 0x7A88EE. Random_ix16_bg is 0x7A85C4.
 * players_timer is 0x7A81F6. old_mes_no2 is 0xCB87C6, old_mes_no3 is
 * 0xCB87CC, old_mes_no_pl is 0xCB87C4, and mes_already is 0x7A8290.
 * Champion is 0x7A8931. New_Challenger is 0x7A86D6. Condense_Buff is
 * 0x7A80BC. Demo_Time_Stop is 0x7A8A32.
 * Setup_Replay_Buff does not store Rec_Time. Replay first stores 1 to the
 * Xbox byte 0x7AA5EE inside mpp_w (xb_unk2B[3]; the PS2 Replay has no such
 * store). Check_SysDir_Page does not read Debug_w. system_timer
 * is the dword at 0x7C59D0. Request_Fade clears 0x7A8519 and 0x7A8462.
 * Present_Data is 0xC7C9E0. Ranking_Data score is at +8 and wins at +0xE.
 * Disp_Digit16x24 checks the stack cookie through 0x175BFC.
 * Middle_Class_Boss_Data is 0x2495D0 and matches the 20 PlayStation 2
 * bytes. Candidate_Buff is 0xC7C820. Suicide is 0x7A8268. Menu_Suicide
 * is 0x7A87A0. EM_Candidate is 0x7A80E0. VS_Index is 0x7A811C.
 * Last_My_char is 0x7A81EC. Stock_My_char is 0x7A89B8.
 * Stock_Player_Color is 0x7A8352. Stock_Win_Record is 0x7A8318.
 * Best_Grade is 0x7A82E0. judge_final[0][0] is 0xC7EDC0 and the next
 * player is 0x158 bytes later. Grade 12 is the low byte at +0x38.
 * Check_Replay does not store Record_Timer. The Replay_w clear is
 * 0x7448 bytes. lag[14] is 0x7C5550. Lag_Timer is 0x7A8904. Lag_Ptr is
 * 0x7A8A08. Turbo_Timer is 0x7C5980. CP_No is 0x7A8308, stride 4.
 * Get_Replay does not call Disp_Rec_Time. Check_Replay_Status has no
 * case 99. 0x9ADDD is Game_Data_Init. 0x9A8D0 and 0x9AEA2 stay unnamed.
 * Soft_Reset_Sub
 * passes 1 as the FadeOut priority and does not ready the debug task.
 * Score_Ranking_Table is 0x265138. vm_w.Access is 0x7C559D and
 * vm_w.Request is 0x7C559E.
 * Demo_Flag is the byte at 0x7A842D. plw is 0xC7CEA0, stride 0x46C, and
 * operator is at +3. permission_player is 0x7C5860, stride 0x18, and
 * cursor_infor is at +0x14. EM_History is 0x7A88C0, stride 10.
 * Game_Data_Init is 0x9ADDD size 0x16. Xbox: no analog-stick check; it
 * clears the byte at 0x7AA5F3 and runs Ranking_Init and Copy_Save_w.
 */

#include "types.h"

extern u8 Country;
extern s32 SSPutStrPro(s32 kind, s32 x, s32 y, s32 color, s32 alpha, const char *text);

void Disp_Copyright(void) {
    s32 xres;
    u8 country = Country;

    if (country == 0 || country > 8) {
        return;
    }

    if (country <= 3 || country >= 7) {
        SSPutStrPro(1, 386, 208, 9, -1, "@CAPCOM CO., LTD. 1999, 2004 ALL RIGHTS RESERVED.");
        return;
    }

    xres = SSPutStrPro(1, 386, 212, 9, -1, "@CAPCOM U.S.A., INC. 1999, 2004 ALL RIGHTS RESERVED.");
    SSPutStrPro(0, xres, 202, 9, -1, "@CAPCOM CO., LTD. 1999, 2004,");
}

typedef struct {
    u8 Shot[8];
    u8 Vibration;
    u8 free[3];
} _PAD_INFOR;

typedef struct {
    s8 contents[4][8];
} _EXTRA_OPTION;

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

typedef struct {
    s16 vs_cpu_result[16];
    s16 vs_cpu_grade[16];
    u8 raw[0x6C];
} GradeFinalData;

/* Xbox layout (include/structs.h): five Xbox bytes follow inGame, so
 * useAnalogStickData is +0x34. */
typedef struct {
    u8 raw[0x29];
    s8 initTrainingData;
    s8 inGame;
    u8 xb_unk2B[5];
    u8 mid[4];
    s8 useAnalogStickData;
} MPP;

typedef struct {
    u8 raw[0x18];
    u8 sound_mode;
    u8 screen_mode;
} _SYSTEM_W;

typedef struct {
    u8 raw[0x1D];
    s8 Access;
    s8 Request;
} _VM_W;

typedef struct {
    u8 raw[8];
    u8 r_no[4];
    u16 condition;
    u8 rest[0x14 - 0xE];
} _TASK;

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

struct _player_infor {
    u8 my_char;
    s8 sa;
    s8 color;
    s8 player_type;
};

struct _REP_GAME_INFOR {
    struct _player_infor player_infor[2];
    s8 stage;
    s8 Direction_Working;
    s8 Vital_Handicap[2];
    s16 Random_ix16;
    s16 Random_ix32;
    s16 Random_ix16_ex;
    s16 Random_ix32_ex;
    s8 *fname;
    u8 winner;
    u8 play_type;
    u16 players_timer;
    s16 old_mes_no2;
    s16 old_mes_no3;
    s16 old_mes_no_pl;
    s16 mes_already;
};

typedef struct {
    u8 raw_head[0x2C0];
    s16 Control_Time_Buff;
    u8 Difficulty;
    u8 raw_mid[5];
    struct _REP_GAME_INFOR game_infor;
    u8 raw_io[0xCC];
    struct {
        u16 key_buff[2][7198];
    } io_unit;
    s8 lag[14];
    u8 raw_tail[6];
    u8 champion;
    u8 full_data;
} _REPLAY_W;

typedef struct _SAVE_W {
    _PAD_INFOR Pad_Infor[2];
    u8 Difficulty;
    s8 Time_Limit;
    u8 Battle_Number[2];
    u8 Damage_Level;
    u8 Handicap;
    u8 Partner_Type[2];
    s8 Adjust_X;
    s8 Adjust_Y;
    u8 Screen_Size;
    u8 Screen_Mode;
    u8 GuardCheck;
    u8 Auto_Save;
    u8 AnalogStick;
    u8 BgmType;
    u8 SoundMode;
    u8 BGM_Level;
    u8 SE_Level;
    u8 Extra_Option;
    u8 PL_Color[2][20];
    _EXTRA_OPTION extra_option;
    RANK_DATA Ranking[20];
    u32 sum;
} _SAVE_W;

typedef struct {
    u8 first_x;
    u8 first_y;
} _cursor_infor;

typedef struct {
    u8 ok[20];
    _cursor_infor cursor_infor[2];
} Permission;

typedef struct {
    u8 raw[3];
    u8 operator;
} WORK;

typedef struct {
    WORK wu;
    u8 raw[0x46C - 4];
} PLW;

#if defined(__i386__)
_Static_assert(sizeof(_PAD_INFOR) == 0xC, "_PAD_INFOR");
_Static_assert(__builtin_offsetof(_PAD_INFOR, Shot) == 0, "Shot");
_Static_assert(sizeof(_EXTRA_OPTION) == 0x20, "_EXTRA_OPTION");
_Static_assert(sizeof(RANK_DATA) == 0x14, "RANK_DATA");
_Static_assert(__builtin_offsetof(RANK_DATA, player) == 4, "player");
_Static_assert(__builtin_offsetof(RANK_DATA, score) == 8, "score");
_Static_assert(__builtin_offsetof(RANK_DATA, cpu_grade) == 0xC, "cpu_grade");
_Static_assert(__builtin_offsetof(RANK_DATA, grade) == 0xD, "grade");
_Static_assert(__builtin_offsetof(RANK_DATA, wins) == 0xE, "wins");
_Static_assert(__builtin_offsetof(RANK_DATA, player_color) == 0x10, "player_color");
_Static_assert(__builtin_offsetof(RANK_DATA, all_clear) == 0x11, "all_clear");
_Static_assert(sizeof(_SAVE_W) == 0x208, "_SAVE_W");
_Static_assert(__builtin_offsetof(_SAVE_W, Pad_Infor) == 0, "Pad_Infor");
_Static_assert(__builtin_offsetof(_SAVE_W, Difficulty) == 0x18, "Difficulty");
_Static_assert(__builtin_offsetof(_SAVE_W, Time_Limit) == 0x19, "Time_Limit");
_Static_assert(__builtin_offsetof(_SAVE_W, Battle_Number) == 0x1A, "Battle_Number");
_Static_assert(__builtin_offsetof(_SAVE_W, Damage_Level) == 0x1C, "Damage_Level");
_Static_assert(__builtin_offsetof(_SAVE_W, Handicap) == 0x1D, "Handicap");
_Static_assert(__builtin_offsetof(_SAVE_W, Partner_Type) == 0x1E, "Partner_Type");
_Static_assert(__builtin_offsetof(_SAVE_W, Adjust_X) == 0x20, "Adjust_X");
_Static_assert(__builtin_offsetof(_SAVE_W, Adjust_Y) == 0x21, "Adjust_Y");
_Static_assert(__builtin_offsetof(_SAVE_W, Screen_Size) == 0x22, "Screen_Size");
_Static_assert(__builtin_offsetof(_SAVE_W, Screen_Mode) == 0x23, "Screen_Mode");
_Static_assert(__builtin_offsetof(_SAVE_W, GuardCheck) == 0x24, "GuardCheck");
_Static_assert(__builtin_offsetof(_SAVE_W, Auto_Save) == 0x25, "Auto_Save");
_Static_assert(__builtin_offsetof(_SAVE_W, AnalogStick) == 0x26, "AnalogStick");
_Static_assert(__builtin_offsetof(_SAVE_W, BgmType) == 0x27, "BgmType");
_Static_assert(__builtin_offsetof(_SAVE_W, SoundMode) == 0x28, "SoundMode");
_Static_assert(__builtin_offsetof(_SAVE_W, BGM_Level) == 0x29, "BGM_Level");
_Static_assert(__builtin_offsetof(_SAVE_W, SE_Level) == 0x2A, "SE_Level");
_Static_assert(__builtin_offsetof(_SAVE_W, PL_Color) == 0x2C, "PL_Color");
_Static_assert(__builtin_offsetof(_SAVE_W, extra_option) == 0x54, "extra_option");
_Static_assert(__builtin_offsetof(_SAVE_W, Ranking) == 0x74, "Ranking");
_Static_assert(__builtin_offsetof(_SAVE_W, sum) == 0x204, "sum");
_Static_assert(__builtin_offsetof(MPP, initTrainingData) == 0x29, "initTrainingData");
_Static_assert(__builtin_offsetof(MPP, useAnalogStickData) == 0x34, "useAnalogStickData");
_Static_assert(__builtin_offsetof(BG, stage) == 3, "bg_w.stage");
_Static_assert(sizeof(struct _REP_GAME_INFOR) == 0x24, "_REP_GAME_INFOR");
_Static_assert(__builtin_offsetof(struct _REP_GAME_INFOR, players_timer) == 0x1A, "players_timer");
_Static_assert(__builtin_offsetof(_REPLAY_W, Control_Time_Buff) == 0x2C0, "Control_Time_Buff");
_Static_assert(__builtin_offsetof(_REPLAY_W, Difficulty) == 0x2C2, "Replay Difficulty");
_Static_assert(__builtin_offsetof(_REPLAY_W, game_infor) == 0x2C8, "game_infor");
_Static_assert(__builtin_offsetof(_REPLAY_W, io_unit) == 0x3B8, "io_unit");
_Static_assert(__builtin_offsetof(_REPLAY_W, lag) == 0x7430, "lag");
_Static_assert(__builtin_offsetof(_REPLAY_W, champion) == 0x7444, "champion");
_Static_assert(__builtin_offsetof(_REPLAY_W, full_data) == 0x7445, "full_data");
_Static_assert(sizeof(_REPLAY_W) == 0x7448, "_REPLAY_W");
_Static_assert(sizeof(GradeFinalData) == 0xAC, "GradeFinalData");
_Static_assert(__builtin_offsetof(GradeFinalData, vs_cpu_grade) == 0x20, "vs_cpu_grade");
_Static_assert(__builtin_offsetof(_SYSTEM_W, sound_mode) == 0x18, "sound_mode");
_Static_assert(__builtin_offsetof(_SYSTEM_W, screen_mode) == 0x19, "screen_mode");
_Static_assert(__builtin_offsetof(_VM_W, Access) == 0x1D, "Access");
_Static_assert(__builtin_offsetof(_VM_W, Request) == 0x1E, "Request");
_Static_assert(sizeof(_TASK) == 0x14, "_TASK");
_Static_assert(__builtin_offsetof(_TASK, r_no) == 8, "r_no");
_Static_assert(__builtin_offsetof(_TASK, condition) == 0xC, "condition");
_Static_assert(sizeof(XY) == 4, "XY");
_Static_assert(__builtin_offsetof(XY, disp.pos) == 2, "XY.disp.pos");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BGW, position_x) == 0xA, "position_x");
_Static_assert(__builtin_offsetof(BGW, position_y) == 0xC, "position_y");
_Static_assert(__builtin_offsetof(BGW, xy) == 0x18, "xy");
_Static_assert(__builtin_offsetof(BGW, wxy) == 0x20, "wxy");
_Static_assert(__builtin_offsetof(BGW, old_pos_x) == 0x30, "old_pos_x");
_Static_assert(sizeof(BG) == 0x428, "BG");
_Static_assert(__builtin_offsetof(BG, bgw) == 0x38, "bgw");
_Static_assert(sizeof(Permission) == 0x18, "Permission");
_Static_assert(__builtin_offsetof(Permission, cursor_infor) == 0x14, "cursor_infor");
_Static_assert(__builtin_offsetof(WORK, operator) == 3, "operator");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
#endif

extern void WipeInit(void);
extern s32 WipeOut(u8 type);
extern s32 WipeIn(u8 type);
extern void SSPutDec(u16 x, u16 y, u8 atr, u8 dec, u8 size);

extern s8 Forbid_Break;
extern s8 Exec_Wipe;
extern u8 Gap_Timer;
extern s8 Stop_SG;
extern s8 Escape_SS;
extern s8 Stop_Combo;
extern u16 p1sw_0;
extern u16 p1sw_1;
extern u16 p2sw_0;
extern u16 p2sw_1;
extern u8 Present_Mode;
extern _SAVE_W save_w[6];
extern const u16 Convert_Data[12];
extern s8 Lost_Round[2];
extern s8 Super_Arts_Finish[2];
extern s8 Perfect_Finish[2];
extern s8 Cheap_Finish[2];
extern s8 Completion_Bonus[2][2];
extern u8 Stage_Continue[2];
extern u8 Introduce_Boss[2][2];
extern s8 Introduce_Break_Into[2];
extern u32 Score[2][3];
extern u32 Stock_Score[2];
extern u32 Stage_Stock_Score[2];
extern u8 Continue_Coin[2];
extern u16 Win_Record[2];
extern u16 VS_Win_Record[2];
extern u16 Stock_Win_Record[2];
extern s16 VS_Index[2];
extern u8 Used_char[2];
extern s16 Arts_Y[2];
extern s8 Continue_Count[2];
extern u8 Continue_Coin2[2];
extern s16 Sel_PL_Complete[2];
extern s16 Sel_Arts_Complete[2];
extern s8 Sel_EM_Complete[2];
extern s8 Personal_Continue_Flag[2];
extern s8 Last_Player_id;
extern s8 Last_Super_Arts[2];
extern s8 Last_My_char[2];
extern s8 Last_My_char2[2];
extern s8 Last_Selected_EM[2];
extern s8 Select_Start[2];
extern u8 paring_ctr_vs[2][2];
extern u8 Straight_Counter[2];
extern u8 Straight_Flag[2];
extern u16 SC_Personal_Time[2];
extern u8 E_Number[2][4];
extern s8 E_07_Flag[2];
extern s8 Request_Break[2];
extern s8 Cursor_X[2];
extern s8 Cursor_Y[2];
extern Permission permission_player[6];
extern u8 EM_History[2][10];
extern u8 Continue_Cut[2];
extern s16 DE_X[2];
extern s8 Operator_Status[2];
extern u8 Play_Type;
extern u8 F_No0[2];
extern u8 F_No1[2];
extern u8 F_No2[2];
extern u8 F_No3[2];
extern s8 Personal_Disp_Flag;
extern s8 Demo_Flag;
extern PLW plw[2];
extern s16 omop_cockpit;
extern u8 Mode_Type;
extern u8 Stop_Update_Score;
extern u32 Keep_Score[2];
extern const u8 Coin_Message_Data[7][2];
extern void score8x16_put(u16 x, u16 y, u8 atr, u8 chr);
extern void SSPutStr(u16 x, u16 y, u8 atr, const s8 *str);
extern s8 Winner_id;
extern s8 Round_Operator[2];
extern s8 Player_id;
extern s8 LOSER;
extern s8 Break_Com[2][20];
extern u8 Final_Result_id;
extern u8 WGJ_Target;
extern u16 WGJ_Win;
extern u32 WGJ_Score;
extern u8 win_type[2][4];
extern u8 flash_win_type[2][4];
extern u8 sync_win_type[2][4];
extern s8 Request_Disp_Rank[2][4];
extern s8 Rank_In[2][4];
extern s8 COM_id;
extern s8 Convert_Buff[4][2][12];
extern const s8 Time_Limit_Data[4];
extern const s8 Battle_Number_Data[4];
extern s8 Check_Buff[4][2][12];
extern RANK_DATA Ranking_Data[20];
extern RANK_DATA Present_Data[2];
extern void score16x24_put(u16 x, u16 y, u8 atr, u8 chr);
extern const u8 Middle_Class_Boss_Data[20];
extern u8 Candidate_Buff[16];
extern u8 EM_Candidate[2][2][10];
extern s8 Suicide[8];
extern u8 Menu_Suicide[4];
extern u8 Stock_My_char[2];
extern s8 Stock_Player_Color[2];
extern s8 Best_Grade[2];
extern GradeFinalData judge_final[2][2];
extern s8 Lag_Timer;
extern s8 *Lag_Ptr;
extern u8 Turbo_Timer;
extern u8 CP_No[2][4];
extern s16 random_16(void);
extern void Bg_Kakikae_Set(void);
extern _EXTRA_OPTION ck_ex_option;
extern MPP mpp_w;
extern _SYSTEM_W sys_w;
extern const struct _SAVE_W Game_Default_Data;
extern const u8 Ex_Page_Data[4];
extern const u16 Level_18_Data[9][17];
extern s16 Limit_Time;
extern s16 Control_Time;
extern _TASK task[];
extern u8 Unsubstantial_BG[];
extern BG bg_w;
extern void Bg_Family_Set_Ex(s16 xx);
extern void bg_pos_hosei_sub2(s32 bg_no);
extern void Bg_Family_Set_appoint(s32 num_of_bg);
extern void move_effect_work(s16 index);
extern s32 Check_LDREQ_Queue_Player(s16 id);
extern void scr_calc(u8 bgnm);
extern void scr_trans(u8 bgnm);
extern void Family_Move(void);
extern void Ending_Family_Move(void);
extern u8 bg_disp_off;
extern u16 Screen_Switch_Buffer;
extern u8 Play_Game;
extern u16 Demo_Timer[2];
extern u16 *Demo_Ptr[2];
extern s16 C_Timer;
extern u8 Order[148];
extern u8 Order_Timer[148];
extern u8 Pause;
extern u8 Game_pause;
extern u8 Extra_Break;
extern u8 Play_Mode;
extern u8 Replay_Status[2];
extern u8 My_char[2];
extern s8 Super_Arts[2];
extern s8 Player_Color[2];
extern u8 Direction_Working[6];
extern s8 Vital_Handicap[6][2];
extern s16 Random_ix16;
extern s16 Random_ix32;
extern s16 Random_ix16_ex;
extern s16 Random_ix32_ex;
extern s16 Random_ix16_com;
extern s16 Random_ix32_com;
extern s16 Random_ix16_ex_com;
extern s16 Random_ix32_ex_com;
extern s16 Random_ix16_bg;
extern u16 players_timer;
extern s16 old_mes_no2;
extern s16 old_mes_no3;
extern s16 old_mes_no_pl;
extern s16 mes_already;
extern s8 Champion;
extern s8 New_Challenger;
extern u16 Condense_Buff[2];
extern s8 Demo_Time_Stop;
extern u32 system_timer;
extern u16 Game_timer;
extern u8 Fade_R_No0;
extern u8 Fade_R_No1;
extern u16 Fade_Number;
extern s8 Fade_Flag;
extern u8 Synchro_No;
extern s16 Flash_Synchro;
extern s16 Synchro_Level;
extern struct _REP_GAME_INFOR Rep_Game_Infor[11];
extern _REPLAY_W Replay_w;
extern void fade_cont_init(void);
extern void fade_cont_main(void);
extern void Menu_Task(_TASK *task_ptr);
extern void cpExitTask(u16 num);
extern void cpReadyTask(u16 num, void (*func_adrs)(_TASK *task_ptr));
extern void Game_Task(_TASK *task_ptr);
extern void Next_Title_Sub(void);
extern void Bg_TexInit(void);
extern void Purge_mmtm_area(s32 kind);
extern void Make_texcash_of_list(s32 kind);
extern void pulpul_stop(void);
extern void init_pulpul_work(void);
extern void pp_operator_check_flag(u8 fl);
extern void Init_Load_Request_Queue_1st(void);
extern void sub_0004384A(s32 key);
extern s32 FadeOut(u8 type, u8 step, u8 priority);
extern void sound_all_off(void);
extern void SsBgmHalfVolume(s16 flag);
extern _VM_W vm_w;
extern const RANK_DATA Score_Ranking_Table[20];

void Switch_Screen_Init(void) {
    WipeInit();
    Forbid_Break = 1;
    Exec_Wipe = 1;
    Gap_Timer = 4;
    Stop_SG = 1;
    Escape_SS = 1;
}

s32 Switch_Screen(u8 Wipe_Type) {
    if (WipeOut(Wipe_Type) && --Gap_Timer <= 0) {
        Exec_Wipe = 0;
        Stop_Combo = 0;
        return 1;
    }

    return 0;
}

s32 Switch_Screen_Revival(u8 Wipe_Type) {
    if (WipeIn(Wipe_Type) && --Gap_Timer <= 0) {
        Exec_Wipe = 0;
        Stop_Combo = 0;
        return 1;
    }

    return 0;
}

u16 Convert_User_Setting(s16 PL_id) {
    u16 sw;
    u16 answer;

    if (PL_id == 0) {
        sw = p1sw_0;
    } else {
        sw = p2sw_0;
    }

    answer = sw & 0x400F;

    if (sw & 0x10) {
        answer |= Convert_Data[save_w[Present_Mode].Pad_Infor[PL_id].Shot[0]];
    }

    if (sw & 0x20) {
        answer |= Convert_Data[save_w[Present_Mode].Pad_Infor[PL_id].Shot[1]];
    }

    if (sw & 0x40) {
        answer |= Convert_Data[save_w[Present_Mode].Pad_Infor[PL_id].Shot[2]];
    }

    if (sw & 0x80) {
        answer |= Convert_Data[save_w[Present_Mode].Pad_Infor[PL_id].Shot[3]];
    }

    if (sw & 0x100) {
        answer |= Convert_Data[save_w[Present_Mode].Pad_Infor[PL_id].Shot[4]];
    }

    if (sw & 0x200) {
        answer |= Convert_Data[save_w[Present_Mode].Pad_Infor[PL_id].Shot[5]];
    }

    if (sw & 0x400) {
        answer |= Convert_Data[save_w[Present_Mode].Pad_Infor[PL_id].Shot[6]];
    }

    if (sw & 0x800) {
        answer |= Convert_Data[save_w[Present_Mode].Pad_Infor[PL_id].Shot[7]];
    }

    return answer;
}

void Clear_Personal_Data(s16 PL_id) {
    s16 xx;

    Lost_Round[PL_id] = 0;
    Super_Arts_Finish[PL_id] = 0;
    Perfect_Finish[PL_id] = 0;
    Cheap_Finish[PL_id] = 0;
    Completion_Bonus[PL_id][0] = 0;
    Completion_Bonus[PL_id][1] = 0;
    Stage_Continue[PL_id] = 0;
    Introduce_Boss[PL_id][0] = 0;
    Introduce_Boss[PL_id][1] = 0;
    Introduce_Break_Into[PL_id] = 0;
    Score[PL_id][0] = 0;
    Stock_Score[PL_id] = 0;
    Stage_Stock_Score[PL_id] = 0;
    Continue_Coin[PL_id] = 0;
    Win_Record[PL_id] = 0;
    VS_Win_Record[PL_id] = 0;
    Stock_Win_Record[PL_id] = 0;
    VS_Index[PL_id] = 0;
    Used_char[PL_id] = 0xFF;
    Arts_Y[PL_id] = 0;
    Continue_Count[PL_id] = 0;
    Continue_Coin2[PL_id] = 0;
    Sel_PL_Complete[PL_id] = 0;
    Sel_Arts_Complete[PL_id] = 0;
    Sel_EM_Complete[PL_id] = 0;
    Personal_Continue_Flag[PL_id] = 0;
    Last_Player_id = -1;
    Last_Super_Arts[PL_id] = 0;
    Last_My_char[PL_id] = -1;
    Last_My_char2[PL_id] = -1;
    Last_Selected_EM[PL_id] = 1;
    Select_Start[PL_id] = 0;
    paring_ctr_vs[0][PL_id] = 0;
    Straight_Counter[PL_id] = 0;
    Straight_Flag[PL_id] = 0;
    SC_Personal_Time[PL_id] = 481;
    E_Number[PL_id][0] = 0;
    E_Number[PL_id][1] = 0;
    E_Number[PL_id][2] = 0;
    E_Number[PL_id][3] = 0;
    E_07_Flag[PL_id] = 0;
    Request_Break[PL_id] = 0;

    if (PL_id == 0) {
        Cursor_X[0] = permission_player[Present_Mode].cursor_infor[0].first_x;
        Cursor_Y[0] = permission_player[Present_Mode].cursor_infor[0].first_y;
    } else {
        Cursor_X[1] = permission_player[Present_Mode].cursor_infor[1].first_x;
        Cursor_Y[1] = permission_player[Present_Mode].cursor_infor[1].first_y;
    }

    for (xx = 0; xx < 10; xx++) {
        EM_History[PL_id][xx] = 0;
    }
}

s16 Check_Count_Cut(s16 PL_id, s16 Limit) {
    s16 xx;

    Continue_Cut[PL_id] = 0;

    if (Continue_Count[PL_id] >= (Limit)) {
        return 0;
    }

    if (PL_id) {
        xx = p2sw_0 & ~p2sw_1;
    } else {
        xx = p1sw_0 & ~p1sw_1;
    }

    return xx & 0xFF0;
}

void Disp_Personal_Count(s16 PL_id, s8 counter) {
    SSPutDec(DE_X[PL_id] + 14, 0, 9, counter, 0);
}

void Setup_Play_Type(void) {
    if (Operator_Status[0] & 0x7F && Operator_Status[1] & 0x7F) {
        Play_Type = 1;
    } else {
        Play_Type = 0;
    }
}

void Clear_Flash_No(void) {
    F_No0[0] = F_No1[0] = F_No2[0] = F_No3[0] = 0;
    F_No0[1] = F_No1[1] = F_No2[1] = F_No3[1] = 0;
    Personal_Disp_Flag = 0;
}

s32 Cut_Cut_Cut(void) {
    if (Demo_Flag == 0) {
        return 0;
    }

    if (plw[0].wu.operator && (p1sw_0 & 0xFF0)) {
        return 1;
    }

    if (plw[1].wu.operator && (p2sw_0 & 0xFF0)) {
        return 1;
    }

    return 0;
}

void Score_Sub(void) {
    u32 Score_Buff;
    s8 i;
    s8 j;
    s32 xx;
    s8 First_Digit;
    s8 Digit[8];
    s16 PL_id;

    if (Mode_Type == 3 || Mode_Type == 4) {
        return;
    }

    if (omop_cockpit == 0) {
        return;
    }

    for (PL_id = 0; PL_id < 2; PL_id++) {
        if ((Mode_Type != 1 && Mode_Type != 5) && plw[PL_id].wu.operator == 0) {
            continue;
        }

        if (Stop_Update_Score) {
            Score_Buff = Keep_Score[PL_id];
        } else {
            Score_Buff = Score[PL_id][Play_Type];
            Score_Buff += Continue_Coin[PL_id];
            Keep_Score[PL_id] = Score_Buff;
        }

        First_Digit = -1;
        xx = 10000000;

        for (i = 7; i > 0; i--) {
            Digit[i] = Score_Buff / xx;
            Score_Buff -= Digit[i] * xx;

            if (First_Digit < 0 && Digit[i]) {
                First_Digit = i;
            }

            xx /= 10;
        }

        Digit[0] = Score_Buff;

        if (First_Digit < 0) {
            First_Digit = 1;
        }

        for (i = Coin_Message_Data[3][PL_id] - First_Digit, j = First_Digit; j >= 0; j--, i++) {
            score8x16_put(i, 0, 8, Digit[j]);
        }
    }
}

void Disp_Win_Record_Sub(u16 win_record, s16 zz) {
    s16 xx;
    s16 Wins_Buff;
    s16 First_Digit;

    switch (win_record) {
    case 1:
        SSPutStr(zz, 0, 9, (const s8 *)"WIN");
        break;

    default:
        SSPutStr(zz, 0, 9, (const s8 *)"WINS");
        break;
    }

    First_Digit = 0;
    Wins_Buff = win_record;
    xx = Wins_Buff / 100;

    if (xx > 0) {
        First_Digit = 1;
        SSPutDec(zz - 4, 0, 9, xx, 1);
    }

    Wins_Buff -= xx * 100;
    xx = Wins_Buff / 10;

    if (First_Digit != 0 || xx > 0) {
        SSPutDec(zz - 3, 0, 9, xx, 1);
    }

    Wins_Buff -= xx * 10;

    SSPutDec(zz - 2, 0, 9, Wins_Buff, 1);
}

s32 Setup_Target_PL(void) {
    if (Play_Type == 1) {
        return Winner_id;
    }

    if (Round_Operator[0]) {
        return 0;
    }

    if (plw[0].wu.operator) {
        return 0;
    }

    return 1;
}

void Setup_Final_Grade(void) {
    if (Break_Com[Player_id][0] == 0) {
        Final_Result_id = LOSER;
        WGJ_Target = LOSER;
        WGJ_Win = Win_Record[LOSER];
        WGJ_Score = Continue_Coin[LOSER] + Score[LOSER][0];
    }
}

void Clear_Win_Type(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        win_type[0][i] = 0;
        win_type[1][i] = 0;
        flash_win_type[0][i] = 0;
        flash_win_type[1][i] = 0;
        sync_win_type[0][i] = 0;
        sync_win_type[1][i] = 0;
    }
}

void Clear_Disp_Ranking(s16 PL_id) {
    s16 ix;

    for (ix = 0; ix <= 3; ix++) {
        Request_Disp_Rank[PL_id][ix] = -1;
        Rank_In[PL_id][ix] = -1;
    }
}

void Setup_ID(void) {
    if (Operator_Status[0] == 0) {
        COM_id = 0;
        Player_id = 1;
    } else {
        COM_id = 1;
        Player_id = 0;
    }
}

void Setup_IO_ConvDataDefault(s32 id) {
    const u8 ioConvInitData[12] = { 0, 1, 2, 11, 3, 4, 5, 11, 0, 0, 0, 0 };
    s32 ix;

    for (ix = 0; ix < 12; ix++) {
        Convert_Buff[1][id][ix] = ioConvInitData[ix];
    }
}

void Disp_Win_Record(void) {
    s16 PL_id;
    s16 zz;

    if (omop_cockpit == 0) {
        return;
    }

    switch (Mode_Type) {
    case 0:
        if (Play_Type == 1) {
            if (Win_Record[0] != 0 || Win_Record[1] != 0) {
                if (Win_Record[0]) {
                    PL_id = 0;
                    zz = 5;
                } else {
                    PL_id = 1;
                    zz = 43;
                }
            } else {
                break;
            }
        } else if (Win_Record[Player_id] == 0) {
            break;
        } else {
            PL_id = Player_id;

            if (Player_id == 0) {
                zz = 5;
            } else {
                zz = 43;
            }
        }

        Disp_Win_Record_Sub(Win_Record[PL_id], zz);
        break;

    case 1:
    case 2:
        if (VS_Win_Record[0] > 0) {
            Disp_Win_Record_Sub(VS_Win_Record[0], 5);
        }

        if (VS_Win_Record[1] > 0) {
            Disp_Win_Record_Sub(VS_Win_Record[1], 43);
        }

        break;
    }
}

s32 Button_Cut_EX(s16 *Timer, s16 Limit_Time) {
    s16 PL_id = Setup_Target_PL();
    u16 xx;

    if (PL_id) {
        xx = p2sw_0;
    } else {
        xx = p1sw_0;
    }

    --*Timer;

    if (*Timer == 0) {
        return 1;
    }

    if ((xx & 0xFF0) && Limit_Time >= *Timer) {
        return 1;
    }

    return 0;
}

void Save_Game_Data(void) {
    s16 ix;

    save_w[1].Difficulty = Convert_Buff[0][0][0];
    save_w[1].Time_Limit = Time_Limit_Data[Convert_Buff[0][0][1]];
    save_w[1].Battle_Number[0] = Battle_Number_Data[Convert_Buff[0][0][2]];
    save_w[1].Battle_Number[1] = Battle_Number_Data[Convert_Buff[0][0][3]];
    save_w[1].Damage_Level = Convert_Buff[0][0][4];
    save_w[1].GuardCheck = Convert_Buff[0][0][5];
    save_w[1].AnalogStick = Convert_Buff[0][0][6];
    save_w[1].Handicap = Convert_Buff[0][0][7];
    save_w[1].Partner_Type[0] = Convert_Buff[0][0][8];
    save_w[1].Partner_Type[1] = Convert_Buff[0][0][9];
    mpp_w.useAnalogStickData = save_w[1].AnalogStick;
    save_w[4].GuardCheck = save_w[1].GuardCheck;
    save_w[5].GuardCheck = save_w[1].GuardCheck;

    for (ix = 0; ix < 8; ix++) {
        save_w[1].Pad_Infor[0].Shot[ix] = Convert_Buff[1][0][ix];
        save_w[1].Pad_Infor[1].Shot[ix] = Convert_Buff[1][1][ix];
    }

    save_w[1].Pad_Infor[0].Vibration = Convert_Buff[1][0][8];
    save_w[1].Pad_Infor[1].Vibration = Convert_Buff[1][1][8];
    save_w[4].Pad_Infor[0] = save_w[1].Pad_Infor[0];
    save_w[4].Pad_Infor[1] = save_w[1].Pad_Infor[1];
    save_w[5].Pad_Infor[0] = save_w[1].Pad_Infor[0];
    save_w[5].Pad_Infor[1] = save_w[1].Pad_Infor[1];
    save_w[1].Adjust_X = Convert_Buff[2][0][0];
    save_w[1].Adjust_Y = Convert_Buff[2][0][1];
    save_w[1].Screen_Size = Convert_Buff[2][0][2];
    save_w[1].Screen_Mode = Convert_Buff[2][0][3];
    save_w[1].Auto_Save = Convert_Buff[3][0][2];
    save_w[1].SoundMode = Convert_Buff[3][1][0];
    save_w[1].BGM_Level = Convert_Buff[3][1][1];
    save_w[1].SE_Level = Convert_Buff[3][1][2];
    save_w[1].BgmType = Convert_Buff[3][1][3];
}

void Copy_Save_w(void) {
    s16 ix;

    Convert_Buff[0][0][0] = save_w[1].Difficulty;
    Convert_Buff[0][0][2] = save_w[1].Battle_Number[0];
    Convert_Buff[0][0][3] = save_w[1].Battle_Number[1];
    Convert_Buff[0][0][4] = save_w[1].Damage_Level;
    Convert_Buff[0][0][5] = save_w[1].GuardCheck;
    Convert_Buff[0][0][6] = save_w[1].AnalogStick;
    Convert_Buff[0][0][7] = save_w[1].Handicap;
    Convert_Buff[0][0][8] = save_w[1].Partner_Type[0];
    Convert_Buff[0][0][9] = save_w[1].Partner_Type[1];
    mpp_w.useAnalogStickData = save_w[1].AnalogStick;

    switch (save_w[1].Time_Limit) {
    case 30:
        Convert_Buff[0][0][1] = 0;
        break;
    case 60:
        Convert_Buff[0][0][1] = 1;
        break;
    case 99:
        Convert_Buff[0][0][1] = 2;
        break;
    default:
        Convert_Buff[0][0][1] = 3;
        break;
    }

    for (ix = 0; ix < 8; ix++) {
        Convert_Buff[1][0][ix] = save_w[1].Pad_Infor[0].Shot[ix];
        Convert_Buff[1][1][ix] = save_w[1].Pad_Infor[1].Shot[ix];
    }

    Convert_Buff[1][0][8] = save_w[1].Pad_Infor[0].Vibration;
    Convert_Buff[1][1][8] = save_w[1].Pad_Infor[1].Vibration;
    Convert_Buff[2][0][0] = save_w[1].Adjust_X;
    Convert_Buff[2][0][1] = save_w[1].Adjust_Y;
    Convert_Buff[2][0][2] = save_w[1].Screen_Size;
    Convert_Buff[2][0][3] = save_w[1].Screen_Mode;
    sys_w.screen_mode = save_w[1].Screen_Mode;
    Convert_Buff[3][0][2] = save_w[1].Auto_Save;
    Convert_Buff[3][1][0] = save_w[1].SoundMode;
    Convert_Buff[3][1][1] = save_w[1].BGM_Level;
    Convert_Buff[3][1][2] = save_w[1].SE_Level;
    Convert_Buff[3][1][3] = save_w[1].BgmType;

    for (ix = 0; ix < 20; ix++) {
        Ranking_Data[ix] = save_w[1].Ranking[ix];
    }
}

void Copy_Check_w(void) {
    s16 ix;
    s16 ix2;

    for (ix = 0; ix < 4; ix++) {
        for (ix2 = 0; ix2 < 12; ix2++) {
            Check_Buff[ix][0][ix2] = Convert_Buff[ix][0][ix2];
            Check_Buff[ix][1][ix2] = Convert_Buff[ix][1][ix2];
        }
    }

    ck_ex_option = save_w[1].extra_option;
}

void Setup_Default_Game_Option(void) {
    s16 ix;

    for (ix = 0; ix < 6; ix++) {
        save_w[ix] = Game_Default_Data;
        save_w[ix].sum = 0;
    }
}

s32 Check_Change_Contents(void) {
    s16 ix;
    s16 ix2;
    s16 page;

    Check_Buff[3][0][0] = Convert_Buff[3][0][0];

    for (ix = 4; ix < 12; ix++) {
        Check_Buff[3][1][ix] = Convert_Buff[3][1][ix];
    }

    for (ix = 0; ix < 4; ix++) {
        for (ix2 = 0; ix2 < 12; ix2++) {
            if (Convert_Buff[ix][0][ix2] != Check_Buff[ix][0][ix2]) {
                return 1;
            }

            if (Convert_Buff[ix][1][ix2] != Check_Buff[ix][1][ix2]) {
                return 1;
            }
        }
    }

    for (page = 0; page < 4; page++) {
        for (ix = Ex_Page_Data[page]; ix < 8; ix++) {
            ck_ex_option.contents[page][ix] = save_w[1].extra_option.contents[page][ix];
        }
    }

    for (ix = 0; ix < 4; ix++) {
        for (ix2 = 0; ix2 < 8; ix2++) {
            if (ck_ex_option.contents[ix][ix2] != save_w[1].extra_option.contents[ix][ix2]) {
                return 1;
            }
        }
    }

    return 0;
}

s32 Check_Menu_Task(void) {
    _TASK *task_ptr = &task[3];

    if (Mode_Type == 3 || Mode_Type == 4) {
        if (task[3].r_no[0] == 7 && task[3].r_no[1] == 7) {
            return 1;
        }

        return 0;
    }

    if (task_ptr->condition == 1) {
        return 1;
    }

    return 0;
}

void Setup_Limit_Time(void) {
    s16 limit;

    limit = Level_18_Data[save_w[Present_Mode].Difficulty][16];
    limit += 20;

    if (Country == 1) {
        Limit_Time = 1241;
    } else {
        Limit_Time = 1061;
    }

    if (limit > Limit_Time) {
        Limit_Time = limit;
    }
}

void Setup_Training_Difficulty(void) {
    s16 unit_time;
    s16 min_time;

    unit_time = Limit_Time - 481;
    unit_time = unit_time / 5;
    min_time = 481 - (unit_time * 2);

    if (min_time < 0) {
        min_time = 0;
    }

    Control_Time = min_time + (unit_time * save_w[Present_Mode].Difficulty);
}

void Setup_BG(s16 BG_INDEX, s16 X, s16 Y) {
    Unsubstantial_BG[BG_INDEX] = 1;
    bg_w.bgw[BG_INDEX].xy[0].disp.pos = X;
    bg_w.bgw[BG_INDEX].xy[1].disp.pos = Y;
    bg_w.bgw[BG_INDEX].wxy[0].disp.pos = X;
    bg_w.bgw[BG_INDEX].wxy[1].disp.pos = Y;
    bg_w.bgw[BG_INDEX].xy[0].disp.low = 0;
    bg_w.bgw[BG_INDEX].xy[1].disp.low = 0;
    bg_w.bgw[BG_INDEX].position_x = X;
    bg_w.bgw[BG_INDEX].position_y = Y;
    Bg_Family_Set_Ex(BG_INDEX);
}

void Setup_Virtual_BG(s16 BG_INDEX, s16 X, s16 Y) {
    bg_w.bgw[BG_INDEX].xy[0].disp.pos = X;
    bg_w.bgw[BG_INDEX].xy[1].disp.pos = Y;
    bg_w.bgw[BG_INDEX].wxy[0].disp.pos = X;
    bg_w.bgw[BG_INDEX].wxy[1].disp.pos = Y;
    bg_w.bgw[BG_INDEX].xy[0].disp.low = 0;
    bg_w.bgw[BG_INDEX].xy[1].disp.low = 0;
    bg_w.bgw[BG_INDEX].position_x = X;
    bg_w.bgw[BG_INDEX].position_y = Y;
    Bg_Family_Set_Ex(BG_INDEX);
}

void BG_move(void) {
    s16 ix;

    for (ix = 0; ix < 4; ix++) {
        if (Unsubstantial_BG[ix]) {
            bg_pos_hosei_sub2(ix);
            Bg_Family_Set_appoint(ix);
        }
    }
}

void BG_move_Ex(u8 ix) {
    scr_calc(ix);
}

void Basic_Sub(void) {
    bg_w.bgw[0].old_pos_x = bg_w.bgw[0].xy[0].disp.pos;
    move_effect_work(0);
    move_effect_work(1);
    move_effect_work(2);
    move_effect_work(3);
    move_effect_work(4);
    move_effect_work(5);
}

void Basic_Sub_Ex(void) {
    move_effect_work(0);
    move_effect_work(1);
    move_effect_work(2);
    move_effect_work(3);
    move_effect_work(4);
    move_effect_work(5);
}

s32 Check_PL_Load(void) {
    if (!Check_LDREQ_Queue_Player(0) || !Check_LDREQ_Queue_Player(1)) {
        return 0;
    }

    return 1;
}

void BG_Draw_System(void) {
    u8 i;
    u16 mask = 1;

    if (bg_disp_off == 0) {
        for (i = 0; i < 4; i++, mask *= 2) {
            if (Screen_Switch_Buffer & mask) {
                scr_trans(i);
            }
        }
    } else {
        for (i = 0; i < 4; i++, mask *= 2) {
            if (Screen_Switch_Buffer & mask) {
                scr_calc(i);
            }
        }
    }

    if (Play_Game == 0) {
        for (i = 0; i < 4; i++) {
            if (Unsubstantial_BG[i]) {
                scr_calc(i);
            }
        }
    } else if (Play_Game == 1) {
        Family_Move();
    } else {
        Ending_Family_Move();
    }
}

u16 Check_Demo_Data(s16 PL_id) {
    u16 ans;

    if (Demo_Timer[PL_id] == 0) {
        ans = *Demo_Ptr[PL_id];
        Demo_Ptr[PL_id]++;
    } else {
        Demo_Timer[PL_id]--;
        return 0;
    }

    if (ans & 0x8000) {
        Demo_Timer[PL_id] = ans & 0x7FFF;
        return 0;
    }

    return ans;
}

void Bg_Close(void);
void effect_work_init(void);

void System_all_clear_Level_B(void) {
    Bg_Close();
    effect_work_init();
}

s16 Cut_Cut_C_Timer(void) {
    C_Timer--;

    if (!Cut_Cut_Cut()) {
        return C_Timer;
    }

    return C_Timer = 0;
}

void Switch_Priority_76(void) {
    Order[56] = 7;
    Order_Timer[56] = 1;
}

s32 Cut_Cut_Sub(s16 xx) {
    if (Demo_Flag == 0) {
        return 1;
    }

    if (plw[0].wu.operator && (p1sw_0 & 0xFF0)) {
        return xx;
    }

    if (plw[1].wu.operator && (p2sw_0 & 0xFF0)) {
        return xx;
    }

    return 1;
}

s32 Cut_Cut_Loser(void) {
    if (Round_Operator[0] && (p1sw_0 & 0xFF0)) {
        return 1;
    }

    if (Round_Operator[1] && (p2sw_0 & 0xFF0)) {
        return 1;
    }

    return 0;
}

void Reset_Sub0(void) {
    Pause = 0;
    Game_pause = 0;
    Play_Game = 0;
    Forbid_Break = 0;
    Extra_Break = 0;
    Mode_Type = 0;
    Present_Mode = 1;
    Play_Mode = 0;
    Replay_Status[0] = 0;
    Replay_Status[1] = 0;
}

void Setup_Replay_Header(void) {
    s16 ix;

    Rep_Game_Infor[10].stage = bg_w.stage;
    Rep_Game_Infor[10].Direction_Working = Direction_Working[Present_Mode];
    Rep_Game_Infor[10].Vital_Handicap[0] = Vital_Handicap[Present_Mode][0];
    Rep_Game_Infor[10].Vital_Handicap[1] = Vital_Handicap[Present_Mode][1];

    for (ix = 0; ix < 2; ix++) {
        Rep_Game_Infor[10].player_infor[ix].my_char = My_char[ix];
        Rep_Game_Infor[10].player_infor[ix].sa = Super_Arts[ix];
        Rep_Game_Infor[10].player_infor[ix].color = Player_Color[ix];
        Rep_Game_Infor[10].player_infor[ix].player_type = plw[ix].wu.operator;
        Rep_Game_Infor[10].Vital_Handicap[ix] = Vital_Handicap[Present_Mode][ix];
    }

    Rep_Game_Infor[10].Random_ix16 = Random_ix16;
    Rep_Game_Infor[10].Random_ix32 = Random_ix32;
    Rep_Game_Infor[10].Random_ix16_ex = Random_ix16_ex;
    Rep_Game_Infor[10].Random_ix32_ex = Random_ix32_ex;
    Rep_Game_Infor[10].players_timer = players_timer;
    Random_ix16_com = Random_ix16;
    Random_ix32_com = Random_ix32;
    Random_ix16_ex_com = Random_ix16_ex;
    Random_ix32_ex_com = Random_ix32_ex;
    Random_ix16_bg = Random_ix16;
    Rep_Game_Infor[10].old_mes_no2 = old_mes_no2;
    Rep_Game_Infor[10].old_mes_no3 = old_mes_no3;
    Rep_Game_Infor[10].old_mes_no_pl = old_mes_no_pl;
    Rep_Game_Infor[10].mes_already = mes_already;
    Replay_w.champion = Champion;
    Replay_w.full_data = 0;
}

void Get_Replay_Header(void) {
    Random_ix16 = Rep_Game_Infor[10].Random_ix16;
    Random_ix32 = Rep_Game_Infor[10].Random_ix32;
    Random_ix16_ex = Rep_Game_Infor[10].Random_ix16_ex;
    Random_ix32_ex = Rep_Game_Infor[10].Random_ix32_ex;
    players_timer = Rep_Game_Infor[10].players_timer;
    old_mes_no2 = Rep_Game_Infor[10].old_mes_no2;
    old_mes_no3 = Rep_Game_Infor[10].old_mes_no3;
    old_mes_no_pl = Rep_Game_Infor[10].old_mes_no_pl;
    mes_already = Rep_Game_Infor[10].mes_already;
    Random_ix16_com = Random_ix16;
    Random_ix32_com = Random_ix32;
    Random_ix16_ex_com = Random_ix16_ex;
    Random_ix32_ex_com = Random_ix32_ex;
    Random_ix16_bg = Random_ix16;
    Champion = Replay_w.champion;
    New_Challenger = Champion ^ 1;
    Control_Time = Replay_w.Control_Time_Buff;
    save_w[Present_Mode].Difficulty = Replay_w.Difficulty;
}

void Setup_Replay_Buff(s16 PL_id, u16 sw_buff) {
    u16 buff;
    u16 timer;

    if (Condense_Buff[PL_id] == 0xFFFF) {
        Demo_Timer[PL_id] = 1;
        Condense_Buff[PL_id] = sw_buff;
        return;
    }

    timer = (u16)(Demo_Timer[PL_id] - 1);
    timer = (u16)(timer << 12);
    buff = Condense_Buff[PL_id] & 0xFFF;
    buff |= timer;
    *Demo_Ptr[PL_id] = buff;
    Demo_Ptr[PL_id]++;

    if (&Replay_w.io_unit.key_buff[PL_id][7197] < Demo_Ptr[PL_id]) {
        Replay_Status[PL_id] = 99;
        Replay_w.full_data |= (u8)(PL_id + 1);
        return;
    }

    Demo_Timer[PL_id] = 1;
    Condense_Buff[PL_id] = sw_buff;
}

void Replay(s16 PL_id) {
    u16 sw;
    u16 buff;

    mpp_w.xb_unk2B[3] = 1;

    if (&Replay_w.io_unit.key_buff[PL_id][7198] < Demo_Ptr[PL_id]) {
        Replay_Status[0] = 2;
        Replay_Status[1] = 2;

        if (Mode_Type == 5) {
            cpExitTask(4);
            cpReadyTask(3, Menu_Task);
            task[3].r_no[0] = 13;
        }

        Demo_Time_Stop = 1;
        return;
    }

    if (Game_pause == 0x81) {
        return;
    }

    if (Demo_Timer[PL_id] == 0) {
        sw = *Demo_Ptr[PL_id];
        Demo_Ptr[PL_id]++;
        buff = sw;
        sw &= 0xFFF;
        Condense_Buff[PL_id] = sw;
        buff &= 0xF000;
        buff >>= 12;
        Demo_Timer[PL_id] = (u16)(buff + 1);
    }

    if (plw[PL_id].wu.operator == 0) {
        if (PL_id) {
            p2sw_0 = 0;
        } else {
            p1sw_0 = 0;
        }
    } else if (PL_id) {
        p2sw_0 = Condense_Buff[PL_id];
    } else {
        p1sw_0 = Condense_Buff[PL_id];
    }

    Demo_Timer[PL_id]--;
}

s16 Check_SysDir_Page(void) {
    s16 ix;
    s16 count = 0;

    for (ix = 0; ix < 20; ix++) {
        if (save_w[1].PL_Color[0][ix]) {
            count++;
        }
    }

    count /= 5;

    if (count > 3) {
        count = 3;
    }

    return (s16)(count + 6);
}

void Clear_Flash_Init(s16 level) {
    Synchro_No = 0;
    Flash_Synchro = 0;
    Synchro_Level = level;
}

s16 Clear_Flash_Sub(void) {
    switch (Synchro_No) {
    case 0:
        Flash_Synchro -= Synchro_Level;

        if (Flash_Synchro < 1) {
            Synchro_No = 1;
            Flash_Synchro = 1;
        }

        break;

    case 1:
        Flash_Synchro += Synchro_Level;

        if (Flash_Synchro > 127) {
            Synchro_No = 0;
            Flash_Synchro = 127;
        }

        break;
    }

    return Flash_Synchro;
}

void Copy_Key_Disp_Work(void) {
    s16 ix;

    for (ix = 0; ix < 8; ix++) {
        Convert_Buff[1][0][ix] = save_w[1].Pad_Infor[0].Shot[ix];
        Convert_Buff[1][1][ix] = save_w[1].Pad_Infor[1].Shot[ix];
    }

    Convert_Buff[1][0][8] = save_w[1].Pad_Infor[0].Vibration;
    Convert_Buff[1][1][8] = save_w[1].Pad_Infor[1].Vibration;
}

s32 Check_Extra_Setting(void) {
    s16 ix;
    s16 page;

    for (page = 0; page < 4; page++) {
        for (ix = Ex_Page_Data[page]; ix < 8; ix++) {
            save_w[1].extra_option.contents[page][ix] = save_w[0].extra_option.contents[page][ix];
        }
    }

    for (page = 0; page < 4; page++) {
        for (ix = 0; ix < 4; ix++) {
            if (save_w[1].extra_option.contents[page][ix] != save_w[0].extra_option.contents[page][ix]) {
                return 1;
            }
        }
    }

    return 0;
}

void All_Clear_Timer(void) {
    system_timer = 0;
    Game_timer = 0;
    players_timer = 0;
}

void All_Clear_ETC(void) {
    old_mes_no2 = 0;
    old_mes_no3 = 0;
    old_mes_no_pl = 0;
    mes_already = 0;
}

s32 Request_Fade(u16 fade_code) {
    if (Fade_Flag == 0) {
        Fade_Flag = 1;
        Fade_R_No0 = 0;
        Fade_R_No1 = 0;
        Fade_Number = fade_code;
        Forbid_Break = 1;
        fade_cont_init();
        return 1;
    }

    return 0;
}

s32 Check_Fade_Complete_SP(void) {
    fade_cont_main();
    return Fade_Flag ^ 1;
}

s32 Check_Fade_Complete(void) {
    if (Fade_Flag) {
        fade_cont_main();
        return 0;
    }

    Forbid_Break = 1;
    return 1;
}

void Check_Partners_Rank(s16 dir_step, s16 PL_id) {
    if (Rank_In[PL_id][dir_step] > Rank_In[PL_id ^ 1][dir_step]) {
        return;
    }

    Rank_In[PL_id ^ 1][dir_step]++;

    if (Rank_In[PL_id ^ 1][dir_step] > 4) {
        Rank_In[PL_id ^ 1][dir_step] = -1;
    }
}

s32 Check_Sort_Score(s16 PL_id) {
    s16 i;
    s16 j;

    for (i = 0; i < 5; i++) {
        if (Ranking_Data[i].score < Present_Data[PL_id].score) {
            for (j = 3; j >= i; j--) {
                Ranking_Data[j + 1] = Ranking_Data[j];
            }

            Ranking_Data[i] = Present_Data[PL_id];
            return i;
        }
    }

    return -1;
}

s32 Check_Sort_Wins(s16 PL_id) {
    s16 i;
    s16 j;

    for (i = 0; i < 5; i++) {
        if (Ranking_Data[i + 5].wins < Present_Data[PL_id].wins) {
            for (j = 3; j >= i; j--) {
                Ranking_Data[j + 6] = Ranking_Data[j + 5];
            }

            Ranking_Data[i + 5] = Present_Data[PL_id];
            return i;
        }
    }

    return -1;
}

s32 Check_CPU_Grade_Score(s16 PL_id, s16 i) {
    if (Ranking_Data[i + 10].cpu_grade > Present_Data[PL_id].cpu_grade) {
        return 0;
    }

    if (Ranking_Data[i + 10].cpu_grade < Present_Data[PL_id].cpu_grade) {
        return 1;
    }

    if (Ranking_Data[i + 10].score >= Present_Data[PL_id].score) {
        return 0;
    }

    return 1;
}

s32 Check_Grade_Score(s16 PL_id, s16 i) {
    if (Ranking_Data[i + 15].grade > Present_Data[PL_id].grade) {
        return 0;
    }

    if (Ranking_Data[i + 15].grade < Present_Data[PL_id].grade) {
        return 1;
    }

    if (Ranking_Data[i + 15].wins >= Present_Data[PL_id].wins) {
        return 0;
    }

    return 1;
}

void Disp_Digit16x24(u32 Score_Buff, s16 Disp_X, s16 Disp_Y, s16 Color) {
    s16 i;
    s16 j;
    s32 xx;
    s16 First_Digit;
    s16 Digit[8];

    if (Score_Buff == 0) {
        score16x24_put(Disp_X, Disp_Y, 15, 0);
    }

    for (i = 7, xx = 10000000, First_Digit = -1; i > 0; i--, xx /= 10) {
        Digit[i] = (s16)(Score_Buff / (u32)xx);
        Score_Buff -= (u32)xx * (u32)Digit[i];

        if (First_Digit < 0 && Digit[i]) {
            First_Digit = i;
        }
    }

    Digit[0] = (s16)Score_Buff;
    i = (s16)(Disp_X - (First_Digit * 2));

    for (j = First_Digit; j >= 0; j--, i = (s16)(i + 2)) {
        score16x24_put((u16)i, (u16)Disp_Y, (u8)Color, (u8)Digit[j]);
    }
}

void Setup_Candidate_Buff(s16 PL_id) {
    s16 em;
    s16 ix;

    for (em = 0, ix = 1; ix <= 19; ix++) {
        if (My_char[PL_id] == 0 && ix == 1) {
            continue;
        }

        if (ix == My_char[PL_id]) {
            continue;
        }

        if (ix == 17) {
            continue;
        }

        if (ix == Middle_Class_Boss_Data[My_char[PL_id]]) {
            continue;
        }

        if (Break_Com[PL_id][ix]) {
            continue;
        }

        Candidate_Buff[em] = (u8)ix;
        em++;

        if (em > 15) {
            break;
        }
    }
}

s32 Check_EM_Sub(s16 ix, s16 ok_urien, s16 Rnd) {
    s16 em;

    if (Candidate_Buff[Rnd] == 0xFF) {
        return 0;
    }

    em = (s16)Candidate_Buff[Rnd];

    switch (em) {
    case 2:
    case 11:
    case 6:
    case 8:
        if (ix < 4) {
            return 0;
        }

        return 1;

    case 14:
        if (ix < 6) {
            return 0;
        }

        return 1;

    case 13:
        if (ok_urien != 0 && ix < 4) {
            return 0;
        }

        return 1;

    default:
        return 1;
    }
}

void All_Clear_Suicide(void) {
    s16 ix;

    for (ix = 0; ix < 8; ix++) {
        Suicide[ix] = 0;
    }

    for (ix = 0; ix < 4; ix++) {
        Menu_Suicide[ix] = 0;
    }
}

void Clear_Break_Com(s16 PL_id) {
    s16 x;

    for (x = 0; x <= 19; x++) {
        Break_Com[PL_id][x] = 0;
    }
}

void Check_Replay(void) {
    s16 ix;
    s32 n;
    u8 *dst;

    if (!Demo_Flag) {
        return;
    }

    switch (Play_Mode) {
    case 1:
        Turbo_Timer = 1;
        Replay_Status[0] = 1;
        Replay_Status[1] = 1;

        if (plw[0].wu.operator == 0) {
            Replay_Status[0] = 0;
            CP_No[0][0] = 0;
        }

        if (plw[1].wu.operator == 0) {
            Replay_Status[1] = 0;
            CP_No[1][0] = 0;
        }

        Condense_Buff[0] = 0xFFFF;
        Condense_Buff[1] = 0xFFFF;
        dst = (u8 *)&Replay_w;

        for (n = 0; n < (s32)sizeof(Replay_w); n++) {
            dst[n] = 0;
        }

        if (Mode_Type == 3 || Mode_Type == 4) {
            for (ix = 0; ix < 0x1C1E; ix++) {
                Replay_w.io_unit.key_buff[0][ix] = 0xF000;
                Replay_w.io_unit.key_buff[1][ix] = 0xF000;
            }
        }

        Setup_Replay_Header();

        for (ix = 0; ix < 14; ix++) {
            Replay_w.lag[ix] = 1;
        }

        Lag_Ptr = Replay_w.lag;
        Lag_Timer = 1;
        Bg_Kakikae_Set();
        break;

    case 3:
        Turbo_Timer = 1;
        Replay_Status[0] = 3;
        Replay_Status[1] = 3;
        CP_No[0][0] = 0;
        CP_No[1][0] = 0;
        Vital_Handicap[Present_Mode][0] = Rep_Game_Infor[10].Vital_Handicap[0];
        Vital_Handicap[Present_Mode][1] = Rep_Game_Infor[10].Vital_Handicap[1];
        Get_Replay_Header();
        Lag_Ptr = Replay_w.lag;
        Lag_Timer = *Lag_Ptr;
        Lag_Ptr += 1;
        Bg_Kakikae_Set();
        break;

    default:
        return;
    }

    Demo_Timer[0] = 0;
    Demo_Timer[1] = 0;
    Demo_Ptr[0] = Replay_w.io_unit.key_buff[0];
    Demo_Ptr[1] = Replay_w.io_unit.key_buff[1];
}

void Get_Replay(s16 PL_id) {
    u16 sw_buff;

    if (Game_pause == 0x81) {
        return;
    }

    if (PL_id) {
        sw_buff = p2sw_0;
    } else {
        sw_buff = p1sw_0;
    }

    if (Condense_Buff[PL_id] == sw_buff) {
        if (Demo_Timer[PL_id] >= 16) {
            Setup_Replay_Buff(PL_id, sw_buff);
        } else {
            Demo_Timer[PL_id]++;
        }
    } else {
        Setup_Replay_Buff(PL_id, sw_buff);
    }
}

s32 Check_Sort_CPU_Grade(s16 PL_id) {
    s16 i;
    s16 j;

    for (i = 0; i < 5; i++) {
        if (!Check_CPU_Grade_Score(PL_id, i)) {
            continue;
        }

        for (j = 3; j >= i; j--) {
            Ranking_Data[j + 11] = Ranking_Data[j + 10];
        }

        Ranking_Data[i + 10] = Present_Data[PL_id];
        return i;
    }

    return -1;
}

s32 Check_Sort_Grade(s16 PL_id) {
    s16 i;
    s16 j;

    for (i = 0; i < 5; i++) {
        if (!Check_Grade_Score(PL_id, i)) {
            continue;
        }

        for (j = 3; j >= i; j--) {
            Ranking_Data[j + 16] = Ranking_Data[j + 15];
        }

        Ranking_Data[i + 15] = Present_Data[PL_id];
        return i;
    }

    return -1;
}

s16 Check_EM_Buff(s16 ix, s16 ok_urien) {
    s16 em;
    s16 Rnd = random_16();
    s16 Next;

    if (Check_EM_Sub(ix, ok_urien, Rnd)) {
        em = (s16)Candidate_Buff[Rnd];
        Candidate_Buff[Rnd] = 0xFF;
        return em;
    }

    Next = (s16)(random_16() & 1);

    if (Next == 0) {
        Next = -1;
    }

    for (;;) {
        if (Check_EM_Sub(ix, ok_urien, Rnd)) {
            em = (s16)Candidate_Buff[Rnd];
            Candidate_Buff[Rnd] = 0xFF;
            return em;
        }

        Rnd = (s16)(Rnd + Next);

        if (Rnd < 0) {
            Rnd = 15;
        }

        if (Rnd > 15) {
            Rnd = 0;
        }
    }
}

void Initialize_EM_Candidate(s16 PL_id) {
    s16 ix;
    s16 ok_urien = random_16();

    for (ix = 0; ix < 16; ix++) {
        Candidate_Buff[ix] = 0xFF;
    }

    Setup_Candidate_Buff(PL_id);

    for (ix = 0; ix < 8; ix++) {
        EM_Candidate[PL_id][0][ix] = (u8)Check_EM_Buff(ix, ok_urien);
        EM_Candidate[PL_id][1][ix] = (u8)Check_EM_Buff(ix, ok_urien);
    }

    EM_Candidate[PL_id][0][8] = Middle_Class_Boss_Data[My_char[PL_id]];
    EM_Candidate[PL_id][1][8] = Middle_Class_Boss_Data[My_char[PL_id]];

    if (My_char[PL_id] != 0) {
        EM_Candidate[PL_id][0][9] = 0;
        EM_Candidate[PL_id][1][9] = 0;
    } else {
        EM_Candidate[PL_id][0][9] = 1;
        EM_Candidate[PL_id][1][9] = 1;
    }
}

void Check_Replay_Status(s16 PL_id, u8 Status) {
    if (Demo_Flag == 0) {
        return;
    }

    switch (Status) {
    case 1:
        Get_Replay(PL_id);
        break;

    case 3:
        Replay(PL_id);
        break;

    case 2:
        if (PL_id) {
            p2sw_0 = 0;
            break;
        }

        p1sw_0 = 0;
        break;
    }
}

s32 Check_Ranking(s16 PL_id) {
    Present_Data[PL_id].name[0] = 12;
    Present_Data[PL_id].name[1] = 10;
    Present_Data[PL_id].name[2] = 25;
    Present_Data[PL_id].player = Stock_My_char[PL_id];
    Present_Data[PL_id].player_color = (u8)Stock_Player_Color[PL_id];
    Present_Data[PL_id].score = Continue_Coin[PL_id] + Score[PL_id][0];
    Present_Data[PL_id].wins = Stock_Win_Record[PL_id];
    Present_Data[PL_id].cpu_grade = (s8)judge_final[PL_id]->vs_cpu_grade[12];
    Present_Data[PL_id].grade = Best_Grade[PL_id];

    if (Break_Com[PL_id][0]) {
        Present_Data[PL_id].all_clear = 1;
    } else {
        Present_Data[PL_id].all_clear = 0;
    }

    Rank_In[PL_id][0] = (s8)Check_Sort_Score(PL_id);

    if (Rank_In[PL_id][0] >= 0 && Rank_In[PL_id ^ 1][0] >= 0) {
        Check_Partners_Rank(0, PL_id);
    }

    Rank_In[PL_id][1] = (s8)Check_Sort_Wins(PL_id);

    if (Rank_In[PL_id][1] >= 0 && Rank_In[PL_id ^ 1][1] >= 0) {
        Check_Partners_Rank(1, PL_id);
    }

    Rank_In[PL_id][2] = (s8)Check_Sort_CPU_Grade(PL_id);

    if (Rank_In[PL_id][2]) {
        Rank_In[PL_id][2] = -1;
    } else {
        Rank_In[PL_id ^ 1][2] = -1;
    }

    Rank_In[PL_id][3] = (s8)Check_Sort_Grade(PL_id);

    if (Rank_In[PL_id][3]) {
        Rank_In[PL_id][3] = -1;
    } else {
        Rank_In[PL_id ^ 1][3] = -1;
    }

    if (Rank_In[PL_id][0] >= 0 || Rank_In[PL_id][1] >= 0 || Rank_In[PL_id][2] >= 0 || Rank_In[PL_id][3] >= 0) {
        return 1;
    }

    return 0;
}

void Check_Same_CPU(s16 PL_id) {
    s16 ix;
    s16 ok_urien;

    if (VS_Index[PL_id] >= 9) {
        return;
    }

    if (Last_My_char[PL_id] == My_char[PL_id]) {
        return;
    }

    ok_urien = random_16();

    for (ix = 0; ix < 16; ix++) {
        Candidate_Buff[ix] = 0xFF;
    }

    Setup_Candidate_Buff(PL_id);

    for (ix = VS_Index[PL_id]; ix < 8; ix++) {
        EM_Candidate[PL_id][0][ix] = (u8)Check_EM_Buff(ix, ok_urien);
        EM_Candidate[PL_id][1][ix] = (u8)Check_EM_Buff(ix, ok_urien);
    }

    EM_Candidate[PL_id][0][8] = Middle_Class_Boss_Data[My_char[PL_id]];
    EM_Candidate[PL_id][1][8] = Middle_Class_Boss_Data[My_char[PL_id]];
}

void Ranking_Init(void) {
    s16 ix;
    s16 ix2;

    for (ix = 0; ix < 4; ix++) {
        for (ix2 = 0; ix2 < 20; ix2++) {
            save_w[ix].Ranking[ix2] = Score_Ranking_Table[ix2];
        }
    }
}

void Soft_Reset_Sub(void) {
    FadeOut(1, 0xFF, 1);
    sound_all_off();
    SsBgmHalfVolume(0);

    if (task[5].condition == 0) {
        cpReadyTask(5, Game_Task);
    }

    Next_Title_Sub();
    Bg_TexInit();
    Purge_mmtm_area(6);
    Make_texcash_of_list(6);
    pulpul_stop();
    init_pulpul_work();
    pp_operator_check_flag(1);
    Init_Load_Request_Queue_1st();
    cpExitTask(3);
    cpExitTask(6);
    cpExitTask(4);
    sub_0004384A(2);
    Reset_Sub0();
    task[0].r_no[0] = 1;
    task[0].r_no[1] = 0;
    task[0].r_no[2] = 0;
    task[0].r_no[3] = 0;
    vm_w.Request = 0;
    vm_w.Access = 0;
}

extern u8 D_007AA5F3;
void Ranking_Init(void);

void Game_Data_Init(void) {
    Setup_Default_Game_Option();
    D_007AA5F3 = 0;
    Ranking_Init();
    Copy_Save_w();
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void setup_pos_remake_key(s16 key);
void xb_ExitAllTasks(void);
void xb_ExitGameTask(struct _TASK* task_ptr);

void xb_SoftResetAndExit(void) {
    FadeOut(1, 0xFF, 1);
    sound_all_off();
    SsBgmHalfVolume(0);
    Next_Title_Sub();
    Bg_TexInit();
    Purge_mmtm_area(6);
    Make_texcash_of_list(6);
    pulpul_stop();
    init_pulpul_work();
    pp_operator_check_flag(1);
    Init_Load_Request_Queue_1st();
    cpExitTask(3);
    cpExitTask(6);
    cpExitTask(4);
    xb_ExitAllTasks();
    cpReadyTask(11, xb_ExitGameTask);
    task[11].r_no[0] = 0;
    setup_pos_remake_key(2);
    Reset_Sub0();
    task->r_no[0] = 1;
    task->r_no[1] = 0;
    task->r_no[2] = 0;
    task->r_no[3] = 0;
    vm_w.Request = 0;
    vm_w.Access = 0;
}
