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
