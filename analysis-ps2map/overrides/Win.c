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
