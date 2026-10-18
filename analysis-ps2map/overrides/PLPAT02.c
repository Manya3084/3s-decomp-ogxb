/* Rewritten to match retail (tools/permute.py): grade_add_personal_action parameter 1: s16 -> s32; < 3 -> <= 2. */
void Att_PL02_TOKUSHUKOUDOU(PLW* wk) {
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

        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }

        if (wk->wu.cg_type == 64) {
            wk->wu.routine_no[3]++;

            if (wk->tk_success <= 2) {
                wk->tk_success++;
                wk->py->recover = (wk->py->recover * 110) / 100;
                grade_add_personal_action(wk->wu.id);
            }
        }

        break;

    default:
        char_move(&wk->wu);
        break;
    }
}
