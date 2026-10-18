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

    if (wk->wu.routine_no[1] == 1) {
        return 1;
    }

    return em->routine_no[1] == 4;
}
