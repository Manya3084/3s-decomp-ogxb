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

/* Rewritten to match retail (tools/permute.py): grade_makeup_round_parameter parameter 1: s16 -> s32. */
void Game_Manage_7_0() {
    if (!Complete_Victory) {
        return;
    }

    C_No[1]++;
    C_Timer = 1;
    grade_makeup_round_parameter(Winner_id);

    if (Mode_Type != 3 && Mode_Type != 4 && omop_cockpit) {
        effect_58_init(6, 1, Winner_id + 100);
        effect_92_init(Winner_id, PL_Wins[Winner_id] - 1);
    }
}

/* Rewritten to match retail (tools/permute.py): grade_makeup_stage_parameter parameter 1: s16 -> s32. */
void Game_Manage_8_0() {
    Round_num++;
    Quick_Entry();
    Stop_Update_Score = 1;

    if (Round_Operator[Winner_id] != 0 || Mode_Type == 1 || Mode_Type == 5) {
        Pool_Score(Winner_id);

        if (PL_Wins[Winner_id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            C_No[1]++;
            Additional_Bonus(WINNER);
            grade_makeup_stage_parameter(WINNER);
            grade_makeup_stage_parameter(LOSER);
            Check_Break_Into_CPU(WINNER);
            return;
        }

        C_No[1] = 3;
        C_Timer = 1;
        return;
    }

    C_No[1] = 3;
    C_Timer = 30;

    if (PL_Wins[Winner_id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
        grade_makeup_stage_parameter(WINNER);
        grade_makeup_stage_parameter(LOSER);
    }
}
