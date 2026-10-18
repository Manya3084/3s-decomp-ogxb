/* Xbox: cmb_calc_now is sized here, so Check_Disp_Combo reads both players' bytes as one word. */
extern s8 cmb_calc_now[2];

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

/* Xbox: no Debug_w[47] test. */
s32 Check_Ending_Sub() {
    return VS_Index[WINNER] > 9;
}

/* The Xbox has no Debug_w test. */
void Game_Manage_12_5() {
    switch (C_No[2]) {
    case 0:
        if (--C_Timer == 0) {
            C_No[2]++;
            C_Timer = 20;
        }

        break;

    case 1:
        if (Scene_Cut) {
            C_Timer = 1;
        }

        if (--C_Timer == 0) {
            C_No[2]++;
        }

        break;

    default:
        MANAGE_X = 1;
        break;
    }
}

/* The Xbox has no Debug_w test. */
s32 Check_Break_Into_CPU(s16 PL_id) {

    Break_Into_CPU = 0;
    Battle_Q[PL_id] = 0;

    if (Round_Result & 0x8000) {
        return 0;
    }

    if (Break_Com[PL_id][17]) {
        return 0;
    }

    if (Continue_Coin[PL_id]) {
        return 0;
    }

    if (VS_Index[PL_id] < 7 || VS_Index[PL_id] >= 9) {
        return 0;
    }

    if (Straight_Flag[PL_id]) {
        return 0;
    }

    if (judge_final[Player_id][0].sp_point < 2) {
        return 0;
    }

    if (Super_Arts_Finish[PL_id] < BIC_SA_Data[0][save_w[Present_Mode].Battle_Number[Play_Type]]) {
        return 0;
    }

    if (Check_BI_Grade(PL_id)) {
        Break_Into_CPU = 2;
        return Battle_Q[PL_id] = 1;
    }

    return 0;
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void Game_Manage_4th() {
    switch (Conclusion_Type) {
    case 0:
        C_No[0] = 6;
        Setup_Win_Mark();
        Check_Perfect(Winner_id);
        setFinishType();
        PL_Wins[Winner_id]++;
        Update_Level_Control();
        Update_VS_Data();
        Ck_Win_Record();
        break;

    case 1:
        SsRequest(121);
        SsRequest(139);

        if (Judge_Next_Disposal()) {
            C_No[0] = 4;
            return;
        }

        C_No[0] = 5;
        Round_Result |= 1024;
        setFinishType();
        win_type[0][PL_Wins[0]] = 5;
        win_type[1][PL_Wins[1]] = 5;
        PL_Wins[0]++;
        PL_Wins[1]++;

        if (PL_Wins[0] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            Winner_id = 0;
            Loser_id = 1;
            Update_VS_Data();
            Ck_Win_Record();
            break;
        }

        if (PL_Wins[1] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            Winner_id = 1;
            Loser_id = 0;
            Update_VS_Data();
            Ck_Win_Record();
        }

        break;

    default:
        SsRequest(143);

        if (plw[0].wu.vital_new != plw[1].wu.vital_new || Mode_Type == 3 || Mode_Type == 4) {
            C_No[0] = 6;
            Round_Result |= 1;
            setFinishType();
            win_type[Winner_id][PL_Wins[Winner_id]] = 1;
            Check_Perfect(Winner_id);
            PL_Wins[Winner_id]++;
            Update_Level_Control();
            Update_VS_Data();
            Ck_Win_Record();
            break;
        }

        C_No[0] = 4;
        break;
    }
}
