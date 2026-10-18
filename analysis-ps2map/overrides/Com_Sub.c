s32 emLevelRemake(s32 now, s32 max, s32 exd) {
    s32 RemakeLevelForDifficulty[8] = { -30, -10, 0, 0, 0, 0, 20, 60 };
    s32 difficulty = save_w[Present_Mode].Difficulty;

    now += (max - exd) * RemakeLevelForDifficulty[difficulty] / 100;

    /* Xbox: in Japan the cap also drops by exd, by half of it at difficulty
       6 and not at all at 7. */
    if (Country == 1) {
        switch (difficulty) {
        case 6:
            exd >>= 1;
            /* fallthrough */
        default:
            max -= exd;
            break;
        case 7:
            break;
        }
    }

    if (now < 0) {
        now = 0;
    }
    if (now >= max) {
        now = max - 1;
    }

    return now;
}

/* Rewritten to match retail (tools/permute.py): < 0x31 -> <= 0x30. */
s32 ETC_Term_0002(PLW* wk, WORK* em) {
    if (plw[wk->wu.id].wu.vital_new <= 0x30) {
        return 1;
    }
    return 0;
}

/* Rewritten to match retail (tools/permute.py): < 0x31 -> <= 0x30. */
s32 Flip_Term_Correct(PLW* wk) {
    s16 xx = 0;

    if (plw[wk->wu.id].wu.vital_new <= 0x30) {
        xx += 1;
    }
    if ((PL_Wins[wk->wu.id]) < (PL_Wins[wk->wu.id ^ 1])) {
        xx += 2;
    }
    if (Counter_hi < 0xF) {
        xx += 1;
    }
    if (Check_Makoto(wk) != 0) {
        xx += 20;
    }

    return xx;
}

/* Rewritten to match retail (tools/permute.py): < 0x19 -> <= 0x18. */
void VS_Jump_Guard(PLW* wk) {
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Guard(wk) == 0) {
            dash_flag_clear(wk->wu.id);
            CP_Index[wk->wu.id][1]++;
        }

        break;

    default:
        if (Check_Guard(wk) != 0) {
            break;
        }

        if (((WORK*)wk->wu.target_adrs)->xyz[1].disp.pos <= 0x18) {
            CP_Index[wk->wu.id][0]++;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;

            Passive_Flag[wk->wu.id] = 0;
            Flip_Flag[wk->wu.id] = 0;
            Limited_Flag[wk->wu.id] = 0;
        }

        break;
    }
}

/* Rewritten to match retail (tools/permute.py): Tech_Number != Hadou_Check_Data[wk->player_number][1] -> Hadou_Check_Data[wk->player_number][1] != Tech_Number. */
s32 Hadou_Check(PLW* wk, u16 Tech_Number) {
    if (Hadou_Check_Data[wk->player_number][0] == 0) {
        return 0;
    }

    if (Hadou_Check_Data[wk->player_number][1] != Tech_Number) {
        return 0;
    }

    return Check_Resume_Lever(wk);
}

/* Rewritten to match retail (tools/permute.py): SA_No != plw[wk->wu.id].sa->kind_of_arts -> plw[wk->wu.id].sa->kind_of_arts != SA_No. */
s32 SA_Range_Check(PLW* wk, s16 SA_No, u16 Range) {
    if (plw[wk->wu.id].sa->kind_of_arts != SA_No) {
        return 0;
    }

    if (Range & 0x8000) {
        if ((PL_Distance[wk->wu.id]) < (Range & 0x7FFF)) {
            CP_Index[wk->wu.id][0]++;
            return 1;
        }

    }

    else if (PL_Distance[wk->wu.id] > Range) {
        CP_Index[wk->wu.id][0]++;
        return 1;
    }

    return 0;
}

/* Rewritten to match retail (tools/permute.py): wk->wu.cg_meoshi == Last_Eftype[wk->wu.id] -> Last_Eftype[wk->wu.id] == wk->wu.cg_meoshi. */
s32 Check_Meoshi_Attack(PLW* wk, s16 Reaction, s16 Power_Level) {
    if (Last_Eftype[wk->wu.id] == wk->wu.cg_meoshi) {
        return 0;
    }

    if (wk->permited_koa & 0x10) {
        Last_Eftype[wk->wu.id] = wk->wu.cg_meoshi;

        M_Lv[wk->wu.id] = Get_Meoshi_Data(wk);

        if (Pattern_Index[wk->wu.id] != 0) {
            Return_CP_No[wk->wu.id] = CP_No[wk->wu.id][0];
            Return_CP_Index[wk->wu.id] = CP_Index[wk->wu.id][0] + 1;
            CP_Index[wk->wu.id][1] = 0;
            CP_Index[wk->wu.id][2] = 0;
            CP_Index[wk->wu.id][3] = 0;
            Return_Pattern_Index[wk->wu.id] = Pattern_Index[wk->wu.id];
        }
        CP_No[wk->wu.id][0] = 6;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        Pattern_Index[wk->wu.id] = 0;
        return 1;
    }
    return 0;
}
