/* Xbox-only flag getter (the dword at 0x79A170). */
s32 sub_001100AC(void);

/* Xbox: a tie outside Play_Type 0 goes to player 1 while sub_001100AC is
   set. */
void Judge_Winner() {
    grade_makeup_judgement_gals();

    if (judge_gals[0].grade == judge_gals[1].grade) {
        if (Play_Type == 0) {
            Winner_id = Player_id;
            Loser_id = COM_id;
            return;
        }

        if (sub_001100AC()) {
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
