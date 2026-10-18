/* Rewritten to match retail (tools/permute.py): < 85 -> <= 84. */
s32 kabe_check(WORK* wk) {
    s16 tar_pos;

    if (wk->xyz[1].disp.pos <= 84) {
        return 0;
    }

    tar_pos = get_center_position();

    if (wk->rl_flag) {
        tar_pos -= 142;

        if (!(wk->xyz[0].disp.pos > tar_pos)) {
            wk->xyz[0].disp.pos = tar_pos;
            return 1;
        }

        return 0;
    }

    tar_pos += 142;

    if (wk->xyz[0].disp.pos >= tar_pos) {
        wk->xyz[0].disp.pos = tar_pos;
        return 1;
    }

    return 0;
}

/* Rewritten to match retail (tools/permute.py): grade_add_personal_action parameter 1: s16 -> s32; < 3 -> <= 2. */
void Att_PL17_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;

    case 1:
        char_move(&wk->wu);

        switch (wk->wu.cg_type) {
        case 40:
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
            break;

        case 10:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 10;

            if (wk->tk_dageki > 10) {
                wk->tk_dageki = 10;
            }

            grade_add_personal_action(wk->wu.id);
            break;

        case 20:
            wk->wu.cg_type = 0;
            wk->tk_dageki += 10;

            if (wk->tk_dageki > 20) {
                wk->tk_dageki = 20;
            }

            break;

        case 30:
            wk->wu.routine_no[3]++;

            if (wk->tk_success <= 2) {
                wk->tk_success++;
                wk->py->recover = (wk->py->recover * 110) / 100;
            }

            break;
        }

        break;

    default:
        char_move(&wk->wu);
        break;
    }
}
