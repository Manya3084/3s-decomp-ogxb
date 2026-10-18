/* Rewritten to match retail (tools/permute.py): <= 0 -> < 1. */
void Damage_31000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK*)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;

        if (wk->wu.xyz[1].disp.pos < 1) {
            wk->wu.xyz[1].disp.pos = 1;
        }

        set_char_move_init(&wk->wu, 6, 10);
        setup_butt_own_data(&wk->wu);
        get_sky_dm_timer(wk);
        break;

    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
        /* fallthrough */

    case 2:
        set_dm_hos_flag_sky(wk);
        first_flight_union(wk, 3, 3);

        if (wk->wu.routine_no[3] != 3) {
            break;
        }

        wk->wu.dir_timer = 10;
        wk->wu.cg_hit_ix = 1;
        wk->wu.cg_ja = wk->wu.hit_ix_table[1];
        set_jugde_area(&wk->wu);
        break;

    case 3:
        if (wk->wu.dir_timer & 1) {
            char_move(&wk->wu);
        }

        wk->wu.cg_hit_ix = 1;
        wk->wu.cg_ja = wk->wu.hit_ix_table[1];
        set_jugde_area(&wk->wu);

        if (--wk->wu.dir_timer >= 0) {
            break;
        }

        set_char_move_init(&wk->wu, 6, 17);
        wk->wu.cg_wca_ix++;
        char_move_wca(&wk->wu);
        wk->wu.routine_no[2] = 18;
        wk->wu.routine_no[3] = 2;
        setup_butt_own_data(&wk->wu);
        cal_initial_speed_y(&wk->wu, _buttobi_time_table[wk->as->char_ix][wk->wu.dm_attlv], wk->wu.xyz[1].disp.pos);
        get_sky_dm_timer(wk);
        break;
    }
}
