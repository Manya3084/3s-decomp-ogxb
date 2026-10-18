/* The Xbox returns where the PS2 breaks out of the switch. */
void Att_PL07_SA2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;

    default:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);

        switch (wk->wu.cg_type) {
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            break;

        case 30:
            wk->wu.mvxy.index = wk->as->data_ix;
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            return;

        case 88:
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            break;
        }

        break;
    }
}
