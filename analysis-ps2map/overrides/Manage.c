/* Xbox-only flag getter (the dword at 0x79A170). */
s32 xb_GetOnlineFlag(void);

/* Xbox: a tie outside Play_Type 0 goes to player 1 while xb_GetOnlineFlag is
   set. */
void Judge_Winner() {
    grade_makeup_judgement_gals();

    if (judge_gals[0].grade == judge_gals[1].grade) {
        if (Play_Type == 0) {
            Winner_id = Player_id;
            Loser_id = COM_id;
            return;
        }

        if (xb_GetOnlineFlag()) {
            Champion = 0;
            Winner_id = 0;
            Loser_id = 1;
            return;
        }

        Winner_id = Champion;
        Loser_id = Champion ^ 1;
        return;
    }

    if (judge_gals[0].grade > judge_gals[1].grade) {
        Winner_id = 0;
        Loser_id = 1;
        return;
    }

    Winner_id = 1;
    Loser_id = 0;
}

/* Rewritten to match retail (tools/permute.py): < 10 -> <= 9. */
s32 Check_Entry_Again() {
    if (Battle_Q[Winner_id]) {
        return 0;
    }

    if (Play_Type == 1) {
        return 1;
    }

    if (VS_Index[WINNER] >= 6) {
        return 0;
    }

    if (VS_Index[WINNER] <= 9) {
        return 1;
    }

    return 0;
}
