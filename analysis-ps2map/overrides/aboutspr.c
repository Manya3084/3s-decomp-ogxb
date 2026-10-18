/* Rewritten to match retail (tools/permute.py): < 0x48 -> <= 0x47. */
s32 sort_push_request4(WORK* wk) {

    if (wk->my_mts == 0) {
        return 0;
    }

    if (wk->disp_flag == 0 || wk->cg_number == 0) {
        return 1;
    }

    if ((wk->disp_flag == 2) && ((wk->blink_timing + Game_timer) & 1)) {
        return 1;
    }

    wk->current_colcd = wk->my_col_code;

    if (wk->extra_col_2) {
        wk->current_colcd = wk->extra_col_2;
    }

    if (wk->extra_col) {
        wk->current_colcd = wk->extra_col;
    }

    if ((wk->id != 0x4C) && (wk->id != 0x46)) {
        if (judge_flag) {
            if (wk->position_z <= 0x47) {
                wk->my_bright_type = 1;
                wk->my_bright_level = 7;
            }
        } else {
            wk->my_bright_type = 0;
            wk->my_bright_level = 0;
        }
    }

    Mtrans_use_trans_mode(wk, 0);

    if (wk->kage_flag) {
        shadow_setup(wk, 0);
    }

    return 2;
}
