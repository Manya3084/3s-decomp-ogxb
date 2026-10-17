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
 * Play_Type is the byte at 0x7A812D. F_No0 is 0x7A8790, F_No1 is 0x7A8806,
 * F_No2 is 0x7A82CE, and F_No3 is 0x7A86E2. Personal_Disp_Flag is 0x7A85C2.
 * Mode_Type is the byte at 0x7A825A. Stop_Update_Score is 0x7A82AA.
 * Keep_Score is 0x7A8288. Continue_Coin is 0x7A86E0. Coin_Message_Data
 * is 0x25C444 and matches the 14 PlayStation 2 bytes. Score_Sub and
 * Setup_IO_ConvDataDefault check the stack cookie through 0x175BFC.
 * "WIN" is 0x265750 and "WINS" is 0x265754. Win_Record is the word at
 * 0x7A8164. VS_Win_Record is the word at 0x7A8128. Winner_id is the byte
 * at 0x7A8472. Round_Operator is 0x7A833C. Player_id is 0x7A810F.
 * LOSER is 0x7A82FD. Break_Com is 0x7A8680, stride 20. Final_Result_id
 * is 0x7A8750. WGJ_Target is 0x7A81C4. WGJ_Win is 0x7A89B2. WGJ_Score
 * is 0x7A8774. win_type is 0x7A8458, flash_win_type is 0x7A85A0, and
 * sync_win_type is 0x7A86B0. Request_Disp_Rank is 0x7A87E8. Rank_In is
 * 0x7A8360. COM_id is 0x7A81C0. Convert_Buff is 0x7A8940.
 * Time_Limit_Data is 0x265540 and matches the four PlayStation 2 bytes,
 * including -1 as 0xFF. Battle_Number_Data is 0x265544 and matches.
 * Check_Buff is 0x7A8840. Ranking_Data is 0xC7C840. ck_ex_option is
 * 0x7C59A0. useAnalogStickData is the byte at 0x7AA5F4. screen_mode is
 * the byte at 0x7C5959. Game_Default_Data is 0x265548. Its first 32
 * bytes match the PlayStation 2 default, starting with pad shots
 * 0, 1, 2, 11, 3, 4, 5, 11. save_w[1].sum is 0x7BD5E4.
 * Demo_Flag is the byte at 0x7A842D. plw is 0xC7CEA0, stride 0x46C, and
 * operator is at +3. permission_player is 0x7C5860, stride 0x18, and
 * cursor_infor is at +0x14. EM_History is 0x7A88C0, stride 10.
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
    u8 raw[0x14];
} RANK_DATA;

typedef struct {
    u8 raw[0x2F];
    s8 useAnalogStickData;
} MPP;

typedef struct {
    u8 raw[0x19];
    u8 screen_mode;
} _SYSTEM_W;

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
    u8 pad[0x54 - 0x2B];
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
_Static_assert(__builtin_offsetof(_SAVE_W, extra_option) == 0x54, "extra_option");
_Static_assert(__builtin_offsetof(_SAVE_W, Ranking) == 0x74, "Ranking");
_Static_assert(__builtin_offsetof(_SAVE_W, sum) == 0x204, "sum");
_Static_assert(__builtin_offsetof(MPP, useAnalogStickData) == 0x2F, "useAnalogStickData");
_Static_assert(__builtin_offsetof(_SYSTEM_W, screen_mode) == 0x19, "screen_mode");
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
extern _EXTRA_OPTION ck_ex_option;
extern MPP mpp_w;
extern _SYSTEM_W sys_w;
extern const struct _SAVE_W Game_Default_Data;

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
