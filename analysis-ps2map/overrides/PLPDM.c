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

/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void Damage_27000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 1, wk->dm_ix);
        setup_butt_own_data(&wk->wu);
        wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        break;

    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
        /* fallthrough */

    default:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void Damage_14000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK*)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 1, wk->dm_ix);
        setup_butt_own_data(&wk->wu);
        wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        break;

    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
        /* fallthrough */

    case 2:
        wk->dm_hos_flag = 1;
        first_TtktV_union(wk, 3, 4);
        break;

    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void Damage_21000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.dm_rl = ((WORK*)wk->wu.dmg_adrs)->rl_flag;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 1, wk->dm_ix);
        setup_butt_own_data(&wk->wu);
        wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;
        break;

    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init(&wk->wu);
        /* fallthrough */

    case 2:
        wk->dm_hos_flag = 1;
        first_TtktV_union(wk, 3, 2);
        break;

    case 3:
        char_move(&wk->wu);
        buttobi_chakuchi_cg_type_check(wk);
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void Damage_12000(PLW* wk) {
    set_dm_hos_flag_grd(wk);

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        wk->dm_ix = wk->as->char_ix + wk->wu.dm_attlv;
        set_char_move_init(&wk->wu, 1, wk->dm_ix);
        wk->dm_step_tbl = _dm_step_data[_select_hit_dsd[wk->wu.dm_impact][get_weight_point(&wk->wu)]];
        wk->zuru_timer = 0;
        wk->zuru_ix_counter = 0;

        if (wk->wu.dm_attribute) {
            setup_accessories(wk, wk->wu.pat_status);

            if (wk->wu.dm_attribute != 2) {
                effect_D9_init(wk, (u8)wk->wu.dm_attribute);
            }
        }

        break;

    case 1:
        wk->wu.routine_no[3]++;
        setup_smoke_type(wk);

        if (wk->wu.pat_status == 32) {
            wk->wu.cmwk[14] = _damage_pause_table[1][wk->wu.dm_attlv];
        } else {
            wk->wu.cmwk[14] = _damage_pause_table[0][wk->wu.dm_attlv];
        }
        if (wk->wu.dm_jump_att_flag) {
            wk->wu.cmwk[14] = _damage_pause_table[2][wk->wu.dm_attlv];
        }

        char_move_wca(&wk->wu);
        add_dm_step_tbl(wk, 1);
        break;

    case 2:
        add_dm_step_tbl(wk, 1);

        if (--wk->wu.cmwk[14] <= 0) {
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
            break;
        }

        /* fallthrough */

    default:
        char_move(&wk->wu);
        break;
    }

    if (wk->wu.cg_type == 0xFF || wk->wu.cg_type == 0x40) {
        wk->guard_flag = 0;
    }
}

/* An if/else, as the retail branch layout has it. */
void add_dm_step_tbl(PLW* wk, s8 flag) {
    if (flag) {
        if (wk->wu.dm_rl) {
            wk->wu.xyz[0].disp.pos += *wk->dm_step_tbl++;
        } else {
            wk->wu.xyz[0].disp.pos -= *wk->dm_step_tbl++;
        }
        return;
    }

    wk->dm_step_tbl++;
}

/* The Xbox does not call check_dmpat_to_dmpat. */
s32 setup_kuuchuu_nmdm(PLW* wk) {
    if (wk->dead_flag) {
        return 0;
    }

    if (((PLW*)wk->wu.target_adrs)->dead_flag == 0) {
        return 0;
    }

    wk->wu.routine_no[2] = 17;
    wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
    set_char_move_init(&wk->wu, 6, 0);
    setup_butt_own_data(&wk->wu);
    cal_initial_speed_y(&wk->wu, _buttobi_time_table[wk->as->char_ix][wk->wu.dm_attlv], wk->wu.xyz[1].disp.pos);
    return 1;
}
