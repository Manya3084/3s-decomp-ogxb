/* Character select, retail sf33rd.xbe.
 * Switch_Work is 0xEA2D8 size 0xBF.
 * Check_Use_Gill is 0xEA397 size 0x5E.
 * Sel_PL_Cont_2nd is 0xEA3F5 size 0x22.
 * Sel_PL_Cont_3rd is 0xEA417 size 0x1A.
 * Setup_Face_ID is 0xEA431 size 0x14.
 * Setup_1st_Play_Type is 0xEA445 size 0x22.
 * Setup_Face_Sub is 0xEA467 size 0x1B.
 * Setup_Select_Status is 0xEA482 size 0x51.
 * Setup_Aborigine is 0xEA4D3 size 0x2B.
 * Setup_Cursor_Y is 0xEA4FE size 0x39.
 * Setup_BG_General is 0xEA537 size 0x1B.
 * Setup_Face_X is 0xEA552 size 0x22.
 * Setup_Face_Y is 0xEA574 size 0x1D.
 * Face_1st is 0xEA591 size 0x1B.
 * Face_2nd is 0xEA5AC size 0xAB.
 * Face_3rd is 0xEA657 size 0x60.
 * Move_Face_BG is 0xEA6B7 size 0x47.
 * Setup_EFF69 is 0xEA6FE size 0x1E.
 * Go_Away_Red_Lines is 0xEA71C size 0x7F.
 * PL_Sel_3rd is 0xEA79B size 0x1C.
 * Setup_Plates is 0xEA7B7 size 0x80.
 * Mode_Type is 0x7A825A. S_No is 0x7A89C8. Champion is 0x7A8931.
 * p1sw_0 is 0x7C557C, p1sw_1 is 0x7BD3CA, p2sw_0 is 0x7C5B90,
 * and p2sw_1 is 0x7C5568. Record_Data_Tr is 0x7A89BC.
 * Menu_Cursor_X is 0x7A8218. Training_Cursor is 0x7A815A.
 * Request_E_No is 0x7A81C6. Forbid_Break is 0x7A8804.
 * Face_Cursor_Data is 0x267618 and matches the 24 PlayStation 2 bytes.
 * ID_of_Face is 0x7A8240. Play_Type is 0x7A812D.
 * Play_Type_1st is 0x7A9AA4. Aborigine is 0x7A8518.
 * Complete_Face is 0x7A847C. Select_Status is 0x7A81CC.
 * Sel_Arts_Complete is 0x7A87E0. plw operator is +3.
 * permission_player is 0x7C5860, stride 0x18. save_w is 0x7BD3E0,
 * stride 0x208, and PL_Color is +0x2C. Cursor_Y_Data is 0x2AEF4C
 * and matches 80, 104, 128, 80, 104, 128. Cursor_Y_Pos is 0x7A8220.
 * Appear_Cursor is 0x7A81CE. Face_No is 0x7A82A0.
 * Face_MV_Request is 0x7A8188. Face_MV_Time is 0x7A815E.
 * Face_Move is 0x7A81C5. bg_mvxy is 0x7BC4C0.
 * Sel_PL_Complete is 0x7A81BC. ID2 is 0x7A81FB. SP_No is 0x7A89F0.
 * Order is 0x7A8380. Order_Timer is 0x7A8480. Order_Dir is 0x7A85E0.
 * Select_Arts is 0x7A82F0. Move_Super_Arts is 0x7A82F4.
 * Super_Arts is 0x7A89FE. Arts_Y_Data is 0x2AEF58 and matches
 * 0, 1, 2, 2, 0, 1, 1, 2, 0.
 * When Mode_Type is 2, Check_Use_Gill scans save_w[2] and returns
 * without writing the Gill permissions. Sel_PL_Cont_2nd still passes
 * 1 to Switch_Screen_Init and tails into Clear_Flash_No.
 * Sel_PL_Cont_3rd does not test G_No[1].
 * All thirteen are interior. Sel_PL_Cont_3rd follows the tail jmp
 * in Sel_PL_Cont_2nd. Setup_Face_X follows the tail jmp in
 * Setup_BG_General. The other eleven follow a ret.
 * Face_1st, Face_2nd, Face_3rd, Move_Face_BG, Setup_EFF69,
 * Go_Away_Red_Lines, and PL_Sel_3rd are interior. Setup_Plates
 * is a scanned start.
 */

#include "types.h"

typedef struct {
    u8 raw[0x2C];
    u8 PL_Color[2][20];
    u8 rest[0x208 - 0x54];
} SAVE_W;

typedef struct {
    u8 ok[20];
    u8 cursor[4];
} Permission;

typedef struct {
    u8 raw[3];
    u8 operator;
} WORK;

typedef struct {
    WORK wu;
    u8 rest[0x46C - 4];
} PLW;

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
    u8 raw[0x38];
    BGW bgw[7];
} BG;

typedef union {
    s32 sp;
} Reg32SpReal;

typedef struct {
    Reg32SpReal a[2];
    Reg32SpReal d[2];
    s16 kop[2];
    u16 index;
} MVXY;

#if defined(__i386__)
_Static_assert(sizeof(SAVE_W) == 0x208, "SAVE_W");
_Static_assert(__builtin_offsetof(SAVE_W, PL_Color) == 0x2C, "PL_Color");
_Static_assert(sizeof(Permission) == 0x18, "Permission");
_Static_assert(__builtin_offsetof(WORK, operator) == 3, "operator");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BGW, xy) == 0x18, "xy");
_Static_assert(__builtin_offsetof(BGW, old_pos_x) == 0x30, "old_pos_x");
_Static_assert(__builtin_offsetof(BG, bgw) == 0x38, "bgw");
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(MVXY, d) == 8, "MVXY.d");
#endif

extern u8 Mode_Type;
extern u8 S_No[4];
extern s8 Champion;
extern u16 p1sw_0;
extern u16 p1sw_1;
extern u16 p2sw_0;
extern u16 p2sw_1;
extern u8 Record_Data_Tr;
extern s8 Menu_Cursor_X[2];
extern s8 Training_Cursor;
extern s8 Request_E_No;
extern s8 Forbid_Break;
extern const s8 Face_Cursor_Data[3][8];
extern s8 ID_of_Face[3][8];
extern u8 Play_Type;
extern s16 Play_Type_1st;
extern u8 Aborigine;
extern s8 Complete_Face;
extern s8 Select_Status[2];
extern s16 Sel_Arts_Complete[2];
extern PLW plw[2];
extern Permission permission_player[6];
extern SAVE_W save_w[3];
extern const s16 Cursor_Y_Data[6];
extern s8 Cursor_Y_Pos[2][4];
extern BG bg_w;
extern s8 Appear_Cursor;
extern u8 Face_No[2];
extern s8 Face_MV_Request;
extern s8 Face_MV_Time;
extern s8 Face_Move;
extern MVXY bg_mvxy;
extern s16 Sel_PL_Complete[2];
extern s8 ID2;
extern u8 SP_No[2][4];
extern u8 Order[148];
extern u8 Order_Timer[148];
extern u8 Order_Dir[148];
extern s8 Select_Arts[2];
extern s16 Move_Super_Arts[2];
extern s8 Super_Arts[2];
extern const u8 Arts_Y_Data[3][3];

void sub_000CB4DE(s16 ix);
void Training_Disp_Work_Clear(void);
s32 Switch_Screen(u8 kind);
void Switch_Screen_Init(s32 page);
s32 Switch_Screen_Revival(u8 kind);
void Clear_Flash_No(void);
void sub_00040A14(s16 ix);
void Zoomf_Init(void);
void sub_000B3886(void);
void sub_000B3661(void);
s32 sub_00055E1C(s8 move, s16 time);
s32 sub_00040621(s16 dir_old);
s32 sub_00054E10(s16 pl_id, s16 plate_id, s16 pos_id, s16 time, s16 target_bg);

void Switch_Work(void) {
    if (Mode_Type != 3 && Mode_Type != 4) {
        return;
    }

    switch (S_No[3]) {
    case 0:
        if (Champion) {
            p1sw_0 = 0;
        } else {
            p2sw_0 = 0;
        }

        break;

    case 1:
        S_No[3]++;
        sub_000CB4DE(0);
        Record_Data_Tr = 0;
        Training_Disp_Work_Clear();
        Menu_Cursor_X[0] = 0;
        Training_Cursor = 0;

        if (Champion) {
            p1sw_0 = p2sw_0;
            p1sw_1 = p2sw_0;
        } else {
            p2sw_0 = p1sw_0;
            p2sw_1 = p1sw_0;
        }

        break;

    case 2:
        if (Champion) {
            p1sw_0 = p2sw_0;
        } else {
            p2sw_0 = p1sw_0;
        }

        break;
    }
}

void Check_Use_Gill(void) {
    s16 ix;

    if (Mode_Type == 2) {
        for (ix = 1; ix < 20; ix++) {
            if (save_w[2].PL_Color[0][ix] == 0) {
                return;
            }
        }

        return;
    }

    permission_player[1].ok[0] = 0;
    permission_player[4].ok[0] = 0;
    permission_player[5].ok[0] = 0;

    for (ix = 1; ix < 20; ix++) {
        if (save_w[1].PL_Color[0][ix] == 0) {
            return;
        }
    }

    permission_player[1].ok[0] = 1;
    permission_player[4].ok[0] = 1;
    permission_player[5].ok[0] = 1;
}

void Sel_PL_Cont_2nd(void) {
    Switch_Screen(1);
    Switch_Screen_Init(1);
    S_No[0]++;
    Request_E_No = 1;
    Clear_Flash_No();
}

void Sel_PL_Cont_3rd(void) {
    if (!Switch_Screen_Revival(0)) {
        return;
    }

    S_No[0]++;
    Forbid_Break = 0;
}

void Setup_Face_ID(void) {
    s16 x;
    s16 y;

    for (y = 0; y < 3; y++) {
        for (x = 0; x < 8; x++) {
            ID_of_Face[y][x] = Face_Cursor_Data[y][x];
        }
    }
}

void Setup_1st_Play_Type(void) {
    if (Play_Type == 1) {
        Play_Type_1st = 99;
        return;
    }

    Play_Type_1st = Aborigine;
}

void Setup_Face_Sub(void) {
    s16 x;

    Complete_Face = 19;

    for (x = 1; x < 20; x++) {
        sub_00040A14(x);
    }
}

void Setup_Select_Status(void) {
    if (plw[0].wu.operator) {
        Select_Status[0] = 1;
    } else {
        Select_Status[0] = 0;
    }

    if (plw[1].wu.operator) {
        Select_Status[0] |= 2;
    }

    if (Sel_Arts_Complete[0] != -1 && plw[0].wu.operator != 0) {
        Select_Status[1] = 1;
    } else {
        Select_Status[1] = 0;
    }

    if (Sel_Arts_Complete[1] != -1 && plw[1].wu.operator != 0) {
        Select_Status[1] |= 2;
    }
}

u8 Setup_Aborigine(void) {
    if (Select_Status[0] == 3) {
        return Aborigine = 153;
    }

    if (Select_Status[0] == 1) {
        return Aborigine = 0;
    }

    return Aborigine = 1;
}

void Setup_Cursor_Y(void) {
    s16 i;
    s16 j;

    for (i = 2, j = 0; i >= 0; i--, j++) {
        Cursor_Y_Pos[0][i] = (s8)Cursor_Y_Data[j];
    }

    for (i = 2, j = 3; i >= 0; i--, j++) {
        Cursor_Y_Pos[1][i] = (s8)Cursor_Y_Data[j];
    }
}

void Setup_BG_General(void) {
    Zoomf_Init();
    bg_w.bgw[0].old_pos_x = bg_w.bgw[0].xy[0].disp.pos;
    sub_000B3886();
    sub_000B3661();
}

s16 Setup_Face_X(void) {
    if (Play_Type == 1) {
        return 604;
    }

    if (Aborigine == 0) {
        return 512;
    }

    return 696;
}

s16 Setup_Face_Y(void) {
    if (Play_Type == 1) {
        return 0;
    }

    if (Aborigine == 0) {
        return -24;
    }

    return 0;
}

void Face_1st(void) {
    if (Select_Status[0] == 3) {
        Face_No[0] = 3;
    } else {
        Face_No[0] = 1;
    }

    Appear_Cursor = 1;
}

void Face_2nd(void) {
    if (Select_Status[0] == 3 && Face_MV_Request == 0) {
        Face_No[0] = 3;
        Face_MV_Time = 1;

        if (Aborigine == 1) {
            Face_MV_Request = 2;
            bg_mvxy.a[0].sp = -0x90000;
            bg_mvxy.d[0].sp = -0x8000;
            return;
        }

        Face_MV_Request = 1;
        bg_mvxy.a[0].sp = 0x90000;
        bg_mvxy.d[0].sp = 0x8000;
        return;
    }

    if (Sel_PL_Complete[Aborigine]) {
        Face_MV_Time = 5;
        Face_No[0]++;

        if (Aborigine == 0) {
            Face_MV_Request = 4;
            bg_mvxy.a[0].sp = -0xC0000;
            bg_mvxy.d[0].sp = -0x8000;
            return;
        }

        Face_MV_Request = 3;
        bg_mvxy.a[0].sp = 0xC0000;
        bg_mvxy.d[0].sp = 0x8000;
    }
}

void Face_3rd(void) {
    if (Select_Status[0] != 3) {
        return;
    }

    if (Face_MV_Request != 0) {
        return;
    }

    Face_No[0]++;
    Face_MV_Time = 1;

    if (Aborigine == 1) {
        Face_MV_Request = 2;
        bg_mvxy.a[0].sp = -0xC0000;
        bg_mvxy.d[0].sp = -0x8000;
        return;
    }

    Face_MV_Request = 1;
    bg_mvxy.a[0].sp = 0xC0000;
    bg_mvxy.d[0].sp = 0x8000;
}

void Move_Face_BG(void) {
    switch (Face_No[1]) {
    case 0:
        if (Face_MV_Request) {
            Face_No[1]++;
            Face_Move = Face_MV_Request;
            sub_00055E1C((s8)(Face_Move - 1), Face_MV_Time);
        }

        break;

    default:
        Face_MV_Request = Face_Move;

        if (!Face_MV_Request) {
            Face_No[1] = 0;
        }

        break;
    }
}

void Setup_EFF69(void) {
    s16 xx;

    for (xx = 0; xx < 5; xx++) {
        Order[xx] = 0;
        sub_00040621(xx);
    }
}

void Go_Away_Red_Lines(void) {
    Order[0] = 2;
    Order_Timer[0] = 1;
    Order_Dir[0] = 8;
    Order[2] = 2;
    Order_Timer[2] = 1;
    Order_Dir[2] = 8;
    Order[1] = 2;
    Order_Timer[1] = 1;
    Order_Dir[1] = 8;
    Order[3] = 2;
    Order_Timer[3] = 1;
    Order_Dir[3] = 8;
    Order[5] = 2;
    Order[6] = 2;
    Order_Timer[5] = 1;
    Order_Timer[6] = 1;
    Order_Dir[5] = 8;
    Order_Dir[6] = 8;
}

void PL_Sel_3rd(void) {
    if (Sel_Arts_Complete[ID2] < 0) {
        SP_No[ID2][1]++;
    }
}

void Setup_Plates(s8 PL_id, s16 Time) {
    Move_Super_Arts[PL_id] = 3;
    Select_Arts[PL_id] = 3;
    sub_00054E10(PL_id, 0, Arts_Y_Data[Super_Arts[PL_id]][0], Time, 2);
    sub_00054E10(PL_id, 1, Arts_Y_Data[Super_Arts[PL_id]][1], Time, 2);
    sub_00054E10(PL_id, 2, Arts_Y_Data[Super_Arts[PL_id]][2], Time, 2);
}
