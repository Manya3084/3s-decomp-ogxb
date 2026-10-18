/* Rewritten to match retail (tools/permute.py): setup_mvxy_data parameter 2: u16 -> s16. */
void Att_MOONSALT_KNEE_DROP(PLW* wk) {
    PLW* twk;
    s16 ex;
    s16 ey;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->data_ix);
        twk = (PLW*)wk->wu.target_adrs;

        if (wk->wu.rl_flag) {
            ex = twk->wu.position_x - mnd_em_tall[twk->player_number][0];
        } else {
            ex = twk->wu.position_x + mnd_em_tall[twk->player_number][0];
        }

        ey = mnd_em_tall[twk->player_number][1];
        wk->wu.mvxy.a[0].sp = 0;
        cal_delta_speed(&wk->wu, wk->as->r_no, ex, ey, 2, 2);

        if (wk->wu.rl_flag == 0) {
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }

        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
        }

        break;

    case 2:
        jumping_union_process(&wk->wu, 3);
        break;

    case 3:
        char_move(&wk->wu);
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): Bg_Y_Sitei parameter 2: s16 -> s32. */
void Att_JYOUKA(PLW* wk) {
    s16 x1;
    s16 y1;

    wk->wu.swallow_no_effect = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        if (Bonus_Game_Flag == 20) {
            wk->wu.routine_no[3] = 10;
            wk->wu.rl_flag = wk->wu.rl_waza;
            set_char_move_init(&wk->wu, 5, wk->as->char_ix);
            x1 = bg_w.bgw[1].wxy[0].disp.pos;
            y1 = 80;
            cal_all_speed_data(&wk->wu, 20, x1, y1, 1, 2);

            if (wk->wu.rl_flag == 0) {
                wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
                wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
            }

            effect_I3_init(&wk->wu, 3);
            wk->sfwing_pos = 88;
            Bg_Y_Sitei(1, wk->sfwing_pos);
            break;
        }

        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, (wk->as->char_ix));
        x1 = bg_w.bgw[1].wxy[0].disp.pos;
        y1 = 40;
        cal_all_speed_data(&wk->wu, 20, x1, y1, 1, 1);

        if (wk->wu.rl_flag == 0) {
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }

        effect_I3_init(&wk->wu, 3);

        break;

    case 1:
    case 10:
        if ((setup_kuzureochi(wk) == 0) && (char_move(&wk->wu), wk->wu.cg_type == 20)) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }

        break;

    case 2:
        if (wk->resurrection_resv) {
            set_char_move_init2(&wk->wu, 5, 60, 8, 1);
            reset_mvxy_data(&wk->wu);
            wk->wu.routine_no[3] = 3;
            break;
        }
        char_move(&wk->wu);
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);

        if (wk->wu.cg_type == 30) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            reset_mvxy_data(&wk->wu);
        }

        break;

    case 3:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            wk->wu.mvxy.d[1].sp = 0xFFFFA000;
            add_mvxy_speed(&wk->wu);
        }

        break;

    case 4:
        jumping_union_process(&wk->wu, 5);
        break;

    case 5:
        char_move(&wk->wu);
        break;

    case 11:
        wk->sfwing_pos += 2;
        char_move(&wk->wu);
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);

        if (wk->wu.cg_type == 30) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            reset_mvxy_data(&wk->wu);
        }

        Bg_Y_Sitei(1, wk->sfwing_pos);
        break;

    case 12:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3] = 4;
            wk->wu.cg_type = 0;
            wk->wu.mvxy.d[1].sp = 0xFFFFA000;
            add_mvxy_speed(&wk->wu);
        }

        break;
    }
}
