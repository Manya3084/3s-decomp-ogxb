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

/* The Xbox breaks out of the switch where the PS2 returns. */
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
        break;

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
