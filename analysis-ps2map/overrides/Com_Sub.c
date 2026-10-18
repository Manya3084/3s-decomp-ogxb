/* Located by their bytes and pointers (tools/locate_data.py): Exit_Term_Tbl
 * is 0x249790. ETC_Term_Tbl is 0x2497B4. */

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

/* Rewritten to match retail (tools/permute.py): get_vs_shell_adrs parameter 3: s16 -> s32; get_vs_shell_adrs parameter 2: s16 -> s32. */
s32 Check_Dash_Hit(PLW* wk, u16 Tech_Number) {
    WORK_Other* tmw;
    WORK* em;
    s16 i;
    s16 xx;
    s16 zz;

    if ((Tech_Number != 0) && (Tech_Number != 1)) {
        return 0;
    }

    em = (WORK*)wk->wu.target_adrs;
    for (i = 0; i < 8; i++) {
        if ((get_vs_shell_adrs(em, em->id, i, &tmw) == 0) && (get_vs_shell_adrs((WORK*)wk, em->id, i, &tmw) == 0)) {
            return 0;
        }
        if (tmw->wu.routine_no[1] == 2) {
            continue;
        }

        xx = wk->wu.xyz[0].disp.pos - tmw->wu.xyz[0].disp.pos;
        zz = Setup_Front_or_Back(wk, xx);

        if (Tech_Number == 0) {
            if (zz != 1) {
                if (Check_Hit_Shell(wk, tmw, Tech_Number) != 0) {
                    return 1;
                }
            }
        } else {
            if (zz != 0) {
                if (Check_Hit_Shell(wk, tmw, Tech_Number) != 0) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

/* Rewritten to match retail (tools/permute.py): get_nearing_range parameter 1: s16 -> s32; get_nearing_range parameter 2: s16 -> s32. */
void Short_Range_Attack(PLW* wk, s16 Reaction, u16 Lever_Data, s16 Next_Action, s16 Next_Menu) {
    u16 xx;

    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (Check_Start_Normal_Attack(wk, Reaction, Lever_Data) == 0) {
            CP_Index[wk->wu.id][1]++;
            Check_First_Menu(wk);

            Ck_Distance_LvJ(wk);
            xx = get_nearing_range(wk->player_number, xx = Lever_Data & 0xFF0);
            if (PL_Distance[wk->wu.id] > xx) {
                Next_Another_Menu(wk, Next_Action, Next_Menu);
            }
        }

        break;

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id]) {
            break;
        }
        Lever_Buff[wk->wu.id] = Lever_Data;
        CP_Index[wk->wu.id][1]++;
        break;

    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Reaction_Sub(wk, Reaction, 0);
        break;
    }
}

/* The Xbox does not call Check_Term_ABS_Distance. */
void Jump_Attack_Term(PLW* wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX,
                      s16 Range_JY, s16 J_Lever_Data) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        Setup_Lever_LR(wk, wk->wu.id, Reaction & 0xF000);

        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }
        if ((wk->wu.routine_no[1] == 4) && (wk->wu.cg_type != 0x40)) {
            break;
        }

        hi_jump_flag_clear(wk->wu.id);
        Continue_Menu[wk->wu.id] = 0;

        wk->wu.hf.hit.player = 0;
        CP_Index[wk->wu.id][1]++;
        Check_First_Menu(wk);
        /* Fallthrough */

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);

        Jump_Init(wk, Jump_Dir);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }

        break;

    case 2:
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
        } else {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        }
        break;

    case 3:
        Check_Air_Guard(wk);
        if (Check_Landed(wk, Reaction) != 0) {
            break;
        }

        if (Check_VS_Air_Attack(wk, Range_JX, Range_JY, J_Lever_Data) != 0) {
            break;
        }
        if (Check_Term_Sub(wk, PL_Distance[wk->wu.id], Range_X) == 0) {
            break;
        }
        if (Check_Com_Add_Y(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }
        if (Check_Term_Sub(wk, wk->wu.xyz[1].disp.pos, Range_Y) == 0) {
            break;
        }

        Lever_Data = Check_SP_Jump_Attack(wk, Lever_Data);
        Lever_Buff[wk->wu.id] = Lever_Data;

        CP_Index[wk->wu.id][1]++;
        Stock_Hit_Flag[wk->wu.id] = 0;
        break;

    case 4:
        Check_Air_Guard(wk);
        if (wk->wu.hf.hit.player) {
            Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        }
        Check_Landed(wk, Reaction & 0x7F);
        break;

    case 5:
        if (Check_Landed(wk, Reaction & 0x7F) == 0) {
            switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
            default:
            case 1:
            case 10:
                if (Command_Type_00(wk, 8, 0xFFFF, -1) == -1) {
                    CP_Index[wk->wu.id][1] = 0x63;
                }
            }
        }
        break;
    default:
        Stock_Hit_Flag[wk->wu.id] = wk->wu.hf.hit.player;
        Check_Landed(wk, Reaction & 0xFFF);
        break;
    }
    if (CP_Index[wk->wu.id][1] >= 3) {
        Lever_Buff[wk->wu.id] |= Lever_LR[wk->wu.id];
    }
}

/* The Xbox has no Debug_w tests. */
void Select_Active(PLW* wk) {
    s16 pl_id;

    Lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        Lv = 7;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }

    Lv = emLevelRemake(Lv, 8, 0);

    Rnd = (u8)random_32_ex_com();

    if (Check_SA_Active(wk, &pl_id) != 0) {
        Lv = Setup_Lv04(0);
        if (Break_Into_CPU == 2) {
            Lv = 3;
        }
        if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
            Lv = 2;
        }

        Lv = emLevelRemake(Lv, 4, 0);

        switch (Area_Number[wk->wu.id]) {
        case 0:
            Pattern_Index[wk->wu.id] = SA_Active_A_Unit_Data[pl_id - 1][Lv][Rnd];
            break;
        case 1:
            Pattern_Index[wk->wu.id] = SA_Active_B_Unit_Data[pl_id - 1][Lv][Rnd];
            break;
        case 2:
            Pattern_Index[wk->wu.id] = SA_Active_C_Unit_Data[pl_id - 1][Lv][Rnd];
            break;
        default:
            Pattern_Index[wk->wu.id] = SA_Active_D_Unit_Data[pl_id - 1][Lv][Rnd];
            break;
        }
    } else {
        switch (Area_Number[wk->wu.id]) {
        case 0:
            Pattern_Index[wk->wu.id] = Active_A_Unit_Data[wk->player_number][Lv][Rnd];
            break;

        case 1:
            Pattern_Index[wk->wu.id] = Active_B_Unit_Data[wk->player_number][Lv][Rnd];
            break;

        case 2:
            Pattern_Index[wk->wu.id] = Active_C_Unit_Data[wk->player_number][Lv][Rnd];
            break;

        default:
            Pattern_Index[wk->wu.id] = Active_D_Unit_Data[wk->player_number][Lv][Rnd];
            break;
        }
    }

}

/* The Xbox has no Debug_w tests. */
s32 Select_Passive(PLW* wk) {
    u16 xx;

    if (VS_Tech[wk->wu.id] == 0xB) {
        Area_Number[wk->wu.id] = Ck_Area_Shell(wk);
    }
    if (VS_Tech[wk->wu.id] == 0x1E) {
        Area_Number[wk->wu.id] = Ck_Area_Shell(wk);
    }

    Last_Attack_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
    Standing_Timer[wk->wu.id] = 0;
    Devide_Level(VS_Tech[wk->wu.id] >> 0xC);
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 1;
    }
    VS_Tech[wk->wu.id] &= 0xFFF;

    Setup_Random(wk);

    switch (Area_Number[wk->wu.id]) {
    case 0:
        xx = Passive_A_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];

        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][0] = 0x78;

            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][0] = 0;
        break;

    case 1:
        xx = Passive_B_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];

        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][1] = 0x78;

            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][1] = 0;
        break;

    case 2:
        xx = Passive_C_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];

        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][2] = 0x78;

            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][2] = 0;
        break;

    default:
        xx = Passive_D_Unit_Data_04[wk->player_number][VS_Tech[wk->wu.id]][Lv][Rnd];

        if (xx == 0xFF) {
            Counter_Attack[wk->wu.id] = 0;
            Passive_Flag[wk->wu.id] = 0;
            Jump_Pass_Timer[wk->wu.id][3] = 0x78;

            return -1;
        }
        Pattern_Index[wk->wu.id] = xx;
        Jump_Pass_Timer[wk->wu.id][3] = 0;
        break;
    }

    Passive_Flag[wk->wu.id] = 1;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = Select_Reflection_Time(wk);

    if ((VS_Tech[wk->wu.id] == 0x19) || (VS_Tech[wk->wu.id] == 0x13) || (Timer_00[wk->wu.id] == 0)) {
        CP_No[wk->wu.id][0] = 6;
        CP_Index[wk->wu.id][0] = 0;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
    } else {
        CP_No[wk->wu.id][0] = 5;
    }
    return 1;
}

/* The Xbox breaks out of the switch where the PS2 returns. */
void Rapid_Sub(PLW* wk) {
    if (Check_Rapid_End(wk) != 0) {
        return;
    }

    switch (Rapid_No[wk->wu.id][0]) {
    case 0:
        break;
    case 2:
        switch (Rapid_No[wk->wu.id][1]) {
        case 0:
            Rapid_No[wk->wu.id][1]++;
            Timer_00[wk->wu.id] = 1;
            Timer_01[wk->wu.id] = 3;
            break;
        case 1:
            if (--Timer_00[wk->wu.id] == 0) {
                Lever_Buff[wk->wu.id] = Rapid_Index[wk->wu.id];
                Timer_00[wk->wu.id] = 2;

                if (--Timer_01[wk->wu.id] == 0) {
                    Rapid_No[wk->wu.id][1]++;
                    Timer_01[wk->wu.id] = 0x18;
                }
            }
            break;
        case 2:
            if (--Timer_01[wk->wu.id] == 0) {
                Rapid_No[wk->wu.id][1]++;
                Timer_00[wk->wu.id] = 1;
                Timer_01[wk->wu.id] = 2;
            }
            break;
        default:
            if (--Timer_00[wk->wu.id] == 0) {
                Lever_Buff[wk->wu.id] = Rapid_Index[wk->wu.id];
                Timer_00[wk->wu.id] = Timer_01[wk->wu.id];
            }
            break;
        }
        break;
    default:
        switch (Rapid_No[wk->wu.id][1]) {
        case 0:
            Rapid_No[wk->wu.id][1]++;
            Timer_00[wk->wu.id] = 1;
            Timer_01[wk->wu.id] = 2;
            break;
        default:
            if (--Timer_00[wk->wu.id] == 0) {
                Lever_Buff[wk->wu.id] = Rapid_Index[wk->wu.id];
                Timer_00[wk->wu.id] = Timer_01[wk->wu.id];
            }
            break;
        }
        break;
    }
}

/* Rewritten to match retail: each < N is <= N - 1. */
s32 Check_Ignore_Shell(WORK_Other* tmw) {
    if (tmw->wu.type == 0xDE) {
        return 1;
    }
    if ((tmw->wu.type >= 0x24) && (tmw->wu.type <= 0x27)) {
        return 1;
    }
    if ((tmw->wu.type >= 0xD) && (tmw->wu.type <= 0xF)) {
        return 1;
    }
    if ((tmw->wu.type == 0x54) || (tmw->wu.type == 0x55)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x4D) && (tmw->wu.type <= 0x50)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x7A) && (tmw->wu.type <= 0x7E)) {
        return 1;
    }

    return 0;
}

/* Rewritten to match retail: each < N is <= N - 1. */
s32 Check_Ignore_Shell2(WORK_Other* tmw) {
    if (tmw->wu.type == 0xDE) {
        return 1;
    }
    if ((tmw->wu.type >= 0x24) && (tmw->wu.type <= 0x27)) {
        return 1;
    }
    if ((tmw->wu.type >= 0xD) && (tmw->wu.type <= 0xF)) {
        return 1;
    }
    if ((tmw->wu.type == 0x54) || (tmw->wu.type == 0x55)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x4D) && (tmw->wu.type <= 0x50)) {
        return 1;
    }
    if ((tmw->wu.type >= 0x7A) && (tmw->wu.type <= 0x7E)) {
        return 1;
    }

    return 0;
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void Hi_Jump(PLW* wk, s16 Pl_Number, s16 Jump_Dir) {
    switch (CP_Index[wk->wu.id][1]) {

    case 0:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (wk->spmv_ng_flag & 0x30000) {
            Next_Be_Free(wk);
            break;
        }

        if (Check_Start_Hi_Jump(wk) == 0) {
            CP_Index[wk->wu.id][1]++;
            if (cmd_sel[wk->wu.id]) {
                Tech_Address[wk->wu.id] = player_CMD[Pl_Number][2];
            } else {
                Tech_Address[wk->wu.id] = player_cmd[Pl_Number][2];
            }
            Check_First_Menu(wk);
        }

        break;

    case 1:
        if (Check_Passive(wk) != 0) {
            break;
        }
        if (--Combo_Speed[wk->wu.id] != 0) {
            break;
        }

        CP_Index[wk->wu.id][1]++;
        Tech_Index[wk->wu.id] = 0xC;

        Jump_Init(wk, Jump_Dir);
        if (Check_Diagonal_Shell(wk) != 0) {
            Next_Be_Free(wk);
        }

        Lever_Buff[wk->wu.id] = 0;

        break;

    case 2:
        if (Check_Passive(wk) != 0) {
            break;
        }

        if (Command_Type_00(wk, 8, 0xFFFF, -1) == -1) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
            return;
        }

        if (!(Lever_Buff[wk->wu.id] & 2)) {
            Lever_Buff[wk->wu.id] |= Lever_Pool[wk->wu.id];
        }
        break;

    case 3:
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        if (wk->wu.xyz[1].disp.pos > 0) {
            CP_Index[wk->wu.id][1]++;
            Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
            Check_Air_Guard(wk);
        }
        break;

    default:
        Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
        Check_Air_Guard(wk);

        if (wk->wu.xyz[1].disp.pos) {
            break;
        }
        CP_Index[wk->wu.id][0]++;
        CP_Index[wk->wu.id][1] = 0;
        CP_Index[wk->wu.id][2] = 0;
        CP_Index[wk->wu.id][3] = 0;
        break;
    }
}

/* Xbox: no time_check record (the PS2 timing display).
 * Reflection_Speed_Unit_Data is 0x244800. */
s32 Select_Reflection_Time(PLW* wk) {
    s8 Lv;
    s8 xx;
    s8 zz;

    xx = (u8)random_32_com();
    Lv = Setup_Lv18(save_w[Present_Mode].Difficulty + 0);
    Lv += CC_Value[0];
    if (Break_Into_CPU == 2) {
        Lv = 0x13;
    }
    if ((Demo_Flag == 0) && (Weak_PL == wk->wu.id)) {
        Lv = 2;
    }

    Lv = emLevelRemake(Lv, 0x14, 2);


    if ((Break_Into_CPU == 1) || (Break_Into_CPU == 2)) {
        return zz = Reflection_Speed_Unit_Data[17][Lv][xx];
    }
    return zz = Reflection_Speed_Unit_Data[My_char[wk->wu.id]][Lv][xx];
}
