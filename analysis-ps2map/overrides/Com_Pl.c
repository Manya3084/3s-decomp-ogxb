/* Rewritten to match retail (tools/permute.py): tech != Attack_Count_Buff[wk->wu.id][xx] -> Attack_Count_Buff[wk->wu.id][xx] != tech. */
static s16 Check_Hamari(PLW* wk) {
    u8 tech;
    s16 Rnd;
    s16 limit;
    s16 xx;

    if (Area_Number[wk->wu.id] >= 2) {
        return 0;
    }

    tech = Attack_Count_Buff[wk->wu.id][0];
    Rnd = random_32_com() & 1;
    limit = Rnd + 3;

    if (((PLW*)wk->wu.target_adrs)->player_number == 4 && tech == 3) {
        limit--;
    } else if (tech != 0 && tech != 1) {
        return 0;
    }

    for (xx = 1; xx < limit; xx++) {
        if (Attack_Count_Buff[wk->wu.id][xx] != tech) {
            return 0;
        }
    }

    return VS_Tech[wk->wu.id] = 32;
}

/* Xbox: the PS2 tests reduce to these once Attack_Flag is known set (MSVC folded the rest) */
static s32 Ck_Exit_Guard_Sub(PLW* wk, WORK* em) {
    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }

    if (wk->wu.routine_no[1] != 1) {
        return em->routine_no[1] == 4;
    }

    return 1;
}

/* The Xbox does not call Disp_Lever and does not call Disp_Mode. */
static u16 CPU_Sub(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;

    if (Allow_a_battle_f == 0 || pcon_dp_flag == 1) {
        return 0;
    }

    Lever_Buff[wk->wu.id] = 0;

    if (em->pat_status == 0x26) {
        Lie_Flag[wk->wu.id] = 1;
    } else {
        Lie_Flag[wk->wu.id] = 0;
    }

    Last_Pattern_Index[wk->wu.id] = Pattern_Index[wk->wu.id];
    Main_Program(wk);
    Lever_Buff[wk->wu.id] = check_illegal_lever_data(Lever_Buff[wk->wu.id]);
    Check_Store_Lv(wk);
    Shift_Resume_Lv(wk);
    return Lever_Buff[wk->wu.id];
}

/* The Xbox has no Debug_w[0x21] test. */
u16 cpu_algorithm(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    u16 sw = CPU_Sub(wk);

    if (Play_Mode == 1 && Replay_Status[wk->wu.id] != 99) {
        if (wk->wu.id) {
            p2sw_0 = sw;
        } else {
            p1sw_0 = sw;
        }

        if (CPU_Time_Lag[wk->wu.id]) {
            CPU_Rec[wk->wu.id] = 1;
            return sw;
        }

        CPU_Rec[wk->wu.id] = 1;

        Check_Replay_Status(wk->wu.id, 1);
    }

    return sw;
}
