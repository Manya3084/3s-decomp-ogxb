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
    _PAD_INFOR Pad_Infor[2];
    u8 raw[0x208 - 0x18];
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
_Static_assert(sizeof(_SAVE_W) == 0x208, "_SAVE_W");
_Static_assert(__builtin_offsetof(_SAVE_W, Pad_Infor) == 0, "Pad_Infor");
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
