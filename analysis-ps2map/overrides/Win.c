/* The Xbox has no Check_Exit_Check and Debug_w test, and returns an s16. */
s16 Loser_Scene() {
    void (*Lose_Jmp_Tbl[6])() = { Win_1st, Lose_2nd, Lose_3rd, Win_4th, Win_5th, Win_6th };

    WIN_X = 0;
    Scene_Cut = Cut_Cut_Loser();
    Lose_Jmp_Tbl[M_No[0]]();

    if (Break_Into) {
        return 0;
    }

    return WIN_X;
}

/* The Xbox has no Check_Exit_Check and Debug_w test, and returns an s16. */
s16 Winner_Scene() {
    void (*Win_Jmp_Tbl[6])() = {
        Win_1st, Win_2nd, Win_3rd, Win_4th, Win_5th, Win_6th,
    };

    if (Break_Into) {
        return 0;
    }

    WIN_X = 0;
    Scene_Cut = Cut_Cut_Cut();
    Win_Jmp_Tbl[M_No[0]]();

    return WIN_X;
}

/* The Xbox has no Debug_w tests. */
void Win_3rd() {
    switch (M_No[1]) {
    case 0:
        Switch_Screen(0);
        M_No[1] += 1;
        Clear_Flash_No();
        Switch_Screen_Init(1);

        break;

    case 1:
        if (Switch_Screen_Revival(1) != 0) {
            M_No[0] += 1;
            M_Timer = 90;
            Forbid_Break = -1;
            Ignore_Entry[LOSER] = 0;
            Target_BG_X[2] = bg_w.bgw[2].wxy[0].disp.pos - 384;
            Offset_BG_X[2] = 0;
            Next_Step = 0;
            bg_mvxy.a[0].sp = -0x100000;
            bg_mvxy.d[0].sp = 0x800;

            effect_58_init(0xE, 0x14, 2);

            if (Mode_Type == 0) {
                Push_LDREQ_Queue_Player(Winner_id, My_char[Winner_id]);
            }
        }

        break;
    }
}
