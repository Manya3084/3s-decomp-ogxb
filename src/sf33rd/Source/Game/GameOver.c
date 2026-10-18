/* GameOver.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * GameOver_1st 0x5C9EA size 0x11B.
 * GameOver_3rd 0x5CB05 size 0x8.
 * Setup_Result_OBJ 0x5CB0D size 0x66.
 * GameOver_2nd 0x5CB73 size 0x1D3. Read against the x86: 0xFF is the byte
 * store of Forbid_Break = -1. The C is the PS2 C.
 * Game_Over 0x5CD46 size 0x4F.
 * BGM_Request is folded into 0x98407.
 * Data: GAME_OVER_X 0xC7F4F8.
 * FadeIn/FadeOut priority is 1 on Xbox (PS2 8) in GameOver_2nd.
 * Globals: PL_Color_Data 0x267F4C, Player_id 0x7A810F, My_char 0x7A8114,
 * Cover_Timer 0x7A81F4, Suicide 0x7A8268, LOSER 0x7A82FD, Order 0x7A8380,
 * GO_No 0x7A8424, Scene_Cut 0x7A8461, E_Number 0x7A8468, Winner_id 0x7A8472,
 * Order_Timer 0x7A8480, Unsubstantial_BG 0x7A851C, Break_Com 0x7A8680,
 * Ignore_Entry 0x7A86AA, Next_Step 0x7A86D2, Target_BG_X 0x7A8780, Offset_BG_X
 * 0x7A87B0, Result_Timer 0x7A87C0, Break_Into 0x7A8802, Forbid_Break 0x7A8804,
 * G_Timer 0x7A8912, WINNER 0x7A89BD, bg_mvxy 0x7BC4C0, bg_w 0x7BC520,
 * GAME_OVER_X 0xC7F4F8.
 */

#include "structs.h"

void sub_00098407(s16 Code);
void GameOver_1st();
void GameOver_2nd();
void GameOver_3rd();
extern u8 Scene_Cut;
s32 Cut_Cut_Loser();
extern u8 GO_No[4];
extern s8 Break_Into;
extern u8 Unsubstantial_BG[4];
extern s16 Target_BG_X[6];
extern BG bg_w;
extern s16 Offset_BG_X[6];
extern MVXY bg_mvxy;
s32 effect_A9_init(s16 Char_Index, s16 Option, s16 Pos_Index, s16 Option2);
extern s8 Next_Step;
s32 effect_58_init(s16 id, s16 time0, s16 option);
extern s8 Break_Com[2][20];
extern s8 WINNER;
s32 effect_76_init(s16 dir_old);
extern u8 Order[148];
extern u8 Order_Timer[148];
extern s16 G_Timer;
extern s8 Forbid_Break;
void FadeInit();
s32 FadeOut(u8 type, u8 step, u8 priority);
extern s8 Cover_Timer;
extern s8 Suicide[8];
void Setup_BG(s16 BG_INDEX, s16 X, s16 Y);
void bg_etc_write(s16 type);
extern const u8 PL_Color_Data[20];
extern u8 My_char[2];
extern s8 Winner_id;
void Setup_Result_OBJ();
s32 FadeIn(u8 type, u8 step, u8 priority);
extern s8 Ignore_Entry[2];
extern s8 LOSER;
extern u8 E_Number[2][4];
extern u16 Result_Timer[2];
extern s8 Player_id;
void SsBgmFadeOut(u16 time);
s32 effect_L1_init(s16 flag);

extern u8 GAME_OVER_X;

/* The Xbox has no Check_Exit_Check and Debug_w test. */
s16 Game_Over() {
    void (*GameOver_Jmp_Tbl[3])() = { GameOver_1st, GameOver_2nd, GameOver_3rd };

    GAME_OVER_X = 0;
    Scene_Cut = Cut_Cut_Loser();
    GameOver_Jmp_Tbl[GO_No[0]]();

    if (Break_Into) {
        return 0;
    }

    return GAME_OVER_X;
}

void GameOver_1st() {
    switch (GO_No[1]) {
    case 0:
        GO_No[1] += 1;
        Unsubstantial_BG[3] = 1;
        Target_BG_X[3] = bg_w.bgw[3].wxy[0].disp.pos + 466;
        Offset_BG_X[3] = 0;
        Target_BG_X[1] = bg_w.bgw[1].wxy[0].disp.pos + 458;
        Offset_BG_X[1] = 0;
        bg_mvxy.a[0].sp = 0xE0000;
        bg_mvxy.d[0].sp = 0;
        effect_A9_init(0x20, 5, 0x12, 0);
        sub_00098407(59);
        Next_Step = 0;

        effect_58_init(0xC, 1, 3);
        effect_58_init(0xC, 1, 1);
        effect_58_init(0xF, 5, 2);
        effect_58_init(0x10, 5, 2);

        if (Break_Com[WINNER][0]) {
            effect_76_init(0x38);
            Order[0x38] = 3;
            Order_Timer[0x38] = 1;
            return;
        }

        break;

    case 1:
        if (Next_Step) {
            GO_No[1] += 1;
            G_Timer = 420; // 7 minutes?
            return;
        }

        break;

    case 2:
        if (Scene_Cut) {
            G_Timer = 1;
        }
        // fallthrough

    default:
        if (--G_Timer == 0) {
            GO_No[0] += 1;
            GO_No[1] = 0;
        }

        break;
    }
}

void GameOver_2nd() {
    s16 temp_v1_3;
    s16 temp_v1_4;
    s8 temp_v1_2;
    u32 temp_v1;

    switch (GO_No[1]) {
    case 0:
        GO_No[1] += 1;
        /* fallthrough */

    case 1:
        GO_No[1] += 1;
        Forbid_Break = 0;
        FadeInit();
        return;

    case 2:
        if (FadeOut(1, 8, 1) != 0) {
            GO_No[1] += 1;
            Cover_Timer = 5;
            Suicide[3] = 1;
            Suicide[2] = 0;

            if (Break_Com[WINNER][0]) {
                Setup_BG(0, 0x200, 0);
                bg_etc_write(PL_Color_Data[My_char[Winner_id]]);
            }

            Setup_Result_OBJ();
            effect_76_init(0x41);
            Order[0x41] = 3;
            Order_Timer[0x41] = 1;
            return;
        }

        break;

    case 3:
        FadeOut(1, 8, 1);

        if (--Cover_Timer == 0) {
            GO_No[1] += 1;
            Forbid_Break = -1;
            FadeInit();
            return;
        }

        break;

    case 4:
        if (FadeIn(1, 8, 1) != 0) {
            Forbid_Break = 0;
            sub_00098407(54);
            Ignore_Entry[LOSER] = 0;

            if ((E_Number[0][0] != 2) && (E_Number[1][0] != 2)) {
                GO_No[1] += 2;
                G_Timer = 60;
                return;
            }

            GO_No[1] += 1;
            return;
        }

        break;

    case 5:
        if ((E_Number[0][0] != 2) && (E_Number[1][0] != 2)) {
            GO_No[1] += 1;
            G_Timer = 60;
            return;
        }

        break;

    case 6:
        if (--G_Timer == 0) {
            GO_No[1] += 1;
            G_Timer = Result_Timer[Player_id];
            return;
        }

        break;

    case 7:
        if (Scene_Cut) {
            G_Timer = 1;
        }
        /* fallthrough */

    default:
        if (--G_Timer == 0) {
            GO_No[0] += 1;
            SsBgmFadeOut(0x222);
            GAME_OVER_X = 1;
        }

        break;
    }
}

void GameOver_3rd() {
    GAME_OVER_X = 1;
}

void Setup_Result_OBJ() {
    effect_76_init(0x32);
    Order[0x32] = 3;
    Order_Timer[0x32] = 1;

    effect_76_init(0x33);
    Order[0x33] = 3;
    Order_Timer[0x33] = 1;

    effect_L1_init(7);
    effect_L1_init(8);
    effect_L1_init(9);
    effect_L1_init(0xA);
    effect_L1_init(0xB);
    effect_L1_init(0xC);
    effect_L1_init(0xD);
    effect_L1_init(0xE);
}
