/* Rewritten to match retail (tools/permute.py): effect_27_init parameter 2: s16 -> s32. */
void eff26_03(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;

        if (eff_hit_flag[oya->wu.type]) {
            ewk->wu.routine_no[1] = 3;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
            goto case_3;
        }

    case 1:
        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (oya->wu.routine_no[1] > 1) {
            ewk->wu.routine_no[1]++;
            piece_set(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
        }

        break;

    case 2:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 3:
    case_3:
        ewk->wu.routine_no[1]++;

        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[0] = 99;
            break;
        }

        ewk->wu.disp_flag = 1;

    case 4:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            if (ewk->wu.old_rno[2] & 1 && ewk->wu.old_rno[5] > 0) {
                effect_27_init(ewk, ewk->wu.old_rno[5]);
            }

            ewk->wu.routine_no[0] = 2;
        }

        break;
    }
}

/* Rewritten to match retail (tools/permute.py): effect_27_init parameter 2: s16 -> s32. */
void eff26_04(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_flag[oya->wu.type]) {
            ewk->wu.routine_no[1] = 2;
            goto case_2;
        }

        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (oya->wu.routine_no[1] > 1) {
            ewk->wu.routine_no[1]++;
            piece_set(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
        }

        break;

    case 1:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
    case_2:
        ewk->wu.routine_no[1]++;

        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[0] = 99;
            break;
        }

        /* fallthrough */

    case 3:
        if (eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            ewk->wu.routine_no[1]++;

            if (ewk->wu.old_rno[2] & 1 && ewk->wu.old_rno[5] > 0) {
                effect_27_init(ewk, ewk->wu.old_rno[5]);
            }

            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[3]);
        }

        /* fallthrough */

    case 4:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[0] = 2;
        }

        break;
    }
}

/* Rewritten to match retail (tools/permute.py): effect_27_init parameter 2: s16 -> s32. */
void eff26_05(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;

        if (eff_hit_flag[oya->wu.type]) {
            ewk->wu.routine_no[2] = 3;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
            goto case_3;
        }

        /* fallthrough */

    case 1:
        if (ewk->wu.hit_stop && !EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (oya->wu.routine_no[1] > 1) {
            ewk->wu.routine_no[1]++;
            piece_set(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[1]);
        }

        break;

    case 2:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 3:
    case_3:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;

        if (eff_hit_flag[ewk->wu.type]) {
            ewk->wu.routine_no[1] = 7;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[7]);
            break;
        }

        /* fallthrough */

    case 4:
        if (!eff_hit_check(ewk, ewk->wu.old_rno[4])) {
            break;
        }

        ewk->wu.routine_no[1]++;

        if (ewk->wu.old_rno[2] & 1 && ewk->wu.old_rno[5] > 0) {
            effect_27_init(ewk, ewk->wu.old_rno[5]);
        }

        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[3]);
        break;

    case 5:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 7:
        if (!EXE_obroll) {
            char_move(&ewk->wu);
        }

        break;
    }
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request4(WORK* wk);
s32 obr_no_disp_check(void);
s32 range_x_check(WORK_Other* ewk);

void xb_effect_26_draw(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (obr_no_disp_check() == 0 && range_x_check(ewk)) {
            sort_push_request4(&ewk->wu);
        }

        break;
    }
}
