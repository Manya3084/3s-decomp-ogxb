/* Continue.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Continue_2nd 0x3018C size 0x17.
 * Continue_4th 0x301A3 size 0x17.
 * Continue_5th 0x301BA size 0x8.
 * Setup_Continue_OBJ 0x301C2 size 0x97.
 * Check_Exit_Continue 0x30259 size 0x4B. Read against the x86: the unnamed
 * bytes are the per-player continue status array at 0x7A8468, 4 bytes apart.
 * The C is the PS2 C.
 * Continue_1st 0x302A4 size 0x111.
 * Continue_3rd 0x303B5 size 0x17.
 * Continue_Scene 0x303CC size 0x44.
 * BGM_Request is folded into 0x98407.
 * Data: CONTINUE_X 0xCB9FB4.
 * Globals: Suicide 0x7A8268, LOSER 0x7A82FD, Order 0x7A8380, Scene_Cut
 * 0x7A8461, E_Number 0x7A8468, Order_Timer 0x7A8480, Next_Step 0x7A86D2,
 * Cont_No 0x7A8754, Cont_Timer 0x7A8762, Target_BG_X 0x7A8780, Offset_BG_X
 * 0x7A87B0, Continue_Count_Down 0x7A891A, Continue_Count 0x7A89D2, bg_mvxy
 * 0x7BC4C0, bg_w 0x7BC520, CONTINUE_X 0xCB9FB4.
 */

#include "structs.h"

void sub_00098407(s16 Code);
void Continue_1st();
void Continue_2nd();
void Continue_3rd();
void Continue_4th();
void Continue_5th();
extern u8 Cont_No[4];
extern s16 Target_BG_X[6];
extern BG bg_w;
extern s16 Offset_BG_X[6];
extern MVXY bg_mvxy;
extern s8 Next_Step;
void Setup_Continue_OBJ();
s32 effect_A9_init(s16 Char_Index, s16 Option, s16 Pos_Index, s16 Option2);
s32 effect_76_init(s16 dir_old);
extern u8 Order[148];
extern u8 Order_Timer[148];
s32 effect_58_init(s16 id, s16 time0, s16 option);
extern s8 Suicide[8];
extern s16 Cont_Timer;
extern u8 Scene_Cut;
extern u8 Continue_Count_Down[2];
extern s8 LOSER;
extern s8 Continue_Count[2];
static s16 Check_Exit_Continue();
s32 effect_49_init(s16 vital_new);
s32 effect_95_init(s16 vital_new);
extern u8 E_Number[2][4];

extern u8 CONTINUE_X;

/* The Xbox has no Check_Exit_Check and Debug_w test. */
s32 Continue_Scene() {
    void (*Continue_Jmp_Tbl[5])() = { Continue_1st, Continue_2nd, Continue_3rd, Continue_4th, Continue_5th };

    CONTINUE_X = 0;
    Continue_Jmp_Tbl[Cont_No[0]]();

    return CONTINUE_X;
}

void Continue_1st() {
    switch (Cont_No[1]) {
    case 0:
        Cont_No[1] += 1;
        Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 0x1CA;
        Target_BG_X[1] = bg_w.bgw[1].wxy[0].disp.pos + 0x1CA;
        Offset_BG_X[3] = 0;
        Offset_BG_X[1] = 0;
        bg_mvxy.a[0].sp = 0xE0000;
        bg_mvxy.d[0].sp = 0;
        Next_Step = 0;

        Setup_Continue_OBJ();
        effect_A9_init(0x37, 0, 0x13, 0);
        sub_00098407(58);
        effect_76_init(0x38);
        Order[0x38] = 3;
        Order_Timer[0x38] = 1;
        effect_58_init(0xC, 1, 3);
        effect_58_init(0xC, 1, 1);
        Suicide[2] = 1;
        effect_58_init(0x10, 5, 2);

        break;

    case 1:
        if (Next_Step) {
            Cont_No[1] += 1;
            Cont_Timer = 0x14;
        }

        break;

    case 2:
        if (Scene_Cut) {
            Cont_Timer = 1;
        }

        if (--Cont_Timer == 0) {
            Cont_No[0] += 1;
            Cont_No[1] = 0;
            Continue_Count_Down[LOSER] = 0;
        }

        break;
    }
}

void Continue_2nd() {
    if (Continue_Count[LOSER] < 0) {
        Cont_No[0] += 1;
    }
}

void Continue_3rd() {
    if ((Cont_Timer = Check_Exit_Continue())) {
        Cont_No[0] += 1;
    }
}

void Continue_4th() {
    if (--Cont_Timer == 0) {
        Cont_No[0] += 1;
        CONTINUE_X = 1;
    }
}

void Continue_5th() {
    CONTINUE_X = 1;
}

void Setup_Continue_OBJ() {
    effect_49_init(4);
    effect_49_init(8);

    effect_95_init(4);
    effect_95_init(8);
    effect_95_init(1);
    effect_95_init(2);

    effect_76_init(0x3B);
    Order[0x3B] = 3;
    Order_Timer[0x3B] = 1;

    effect_76_init(0x3C);
    Order[0x3C] = 3;
    Order_Timer[0x3C] = 1;

    effect_76_init(0x3D);
    Order[0x3D] = 3;
    Order_Timer[0x3D] = 1;

    effect_76_init(0x3E);
    Order[0x3E] = 3;
    Order_Timer[0x3E] = 1;

    effect_76_init(0x3F);
    Order[0x3F] = 3;
    Order_Timer[0x3F] = 1;
}

static s16 Check_Exit_Continue() {
    if (((E_Number[0][0]) == 2) || ((E_Number[1][0]) == 2)) {
        return 0;
    }

    if (E_Number[LOSER ^ 1][0] == 0) {
        return 0x3C;
    }

    if ((E_Number[LOSER ^ 1][0] != 3) && (E_Number[LOSER ^ 1][0] != 0)) {
        return 0;
    }

    if ((E_Number[LOSER][0] != 3) && (E_Number[LOSER][0] != 0)) {
        return 0;
    }

    return 1;
}
