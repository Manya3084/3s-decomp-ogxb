/* Rewritten to match retail (tools/permute.py): grade_add_reversal parameter 1: s16 -> s32. */
s32 reversal_check(s8 PL) {
    s8 PLS;

    if (rever_attack[PL]) {
        return 0;
    }

    if (plw[PL].wu.routine_no[1] == 4 && plw[PL].wu.old_rno[1] == 1 && pcon_dp_flag == 0 &&
        plw[PL].wu.routine_no[2] >= 0x10) {
        rever_attack[PL] = 1;

        if (PL == 0) {
            PLS = (1);
        } else {
            PLS = 0;
        }

        combo_window_push(PLS, 5);
        grade_add_reversal(PL);
        return 1;
    }

    return 0;
}

/* Xbox: the operands are the other way round */
void first_attack_pts_check(s8 PL) {
    if (plw[PL].wu.id == first_attack - 1) {
        first_attack = 3;
        bonus_pts[PL] += 2;
    }
}

/* <= 47, as retail compares. */
void super_arts_finish_check(s8 PL) {
    if (arts_finish_check2(PL) != 0) {
        if ((plw[PL].cb->new_dm & 0x3F) <= 47) {
            sa_kind = 2;
        } else {
            sa_kind = 3;
        }

        combo_window_push(PL, 3);
    }
}
