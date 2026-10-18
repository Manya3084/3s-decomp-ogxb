/* Xbox: the shell_ix[1] clear is a byte store. */
void effD7_main_process(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;

    if (ewk->wu.hf.hit_flag) {
        ewk->wu.routine_no[1] = 1;
    }

    if (ewk->wu.shell_ix[1]) {
        /* retail clears only the low byte */
        *(u8*)&ewk->wu.shell_ix[1] = 0;
        ewk->wu.kage_flag = 0;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
            break;
        }

        switch (ewk->wu.routine_no[2]) {
        case 0:
            char_move(&ewk->wu);
            add_mvxy_speed(&ewk->wu);
            cal_mvxy_speed(&ewk->wu);

            if (ewk->wu.xyz[1].disp.pos < ewk->wu.shell_ix[2]) {
                ewk->wu.xyz[1].disp.pos = ewk->wu.shell_ix[2];
                ewk->wu.shell_ix[2] -= ewk->wu.shell_ix[3];
                ewk->wu.shell_ix[2] -= random_16() & 3;

                if (ewk->wu.char_index != 0x77) {
                    set_char_move_init(&ewk->wu, 0, 0x77);
                }

                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;

                switch (check_ball_mizushibuki(ewk->wu.xyz[0].disp.pos, ewk->wu.xyz[1].disp.pos)) {
                case 1:
                    effect_03_init(&ewk->wu, 0x84);
                    break;

                case 2:
                    effect_03_init(&ewk->wu, 0x85);
                    break;

                default:
                    sound_effect_request[0x157](ewk, 0x157);
                    break;
                }

                ewk->wu.mvxy.a[0].sp = (ewk->wu.mvxy.a[0].sp * 80) / 100;
                ewk->wu.mvxy.a[1].sp = -(ewk->wu.mvxy.a[1].sp / 2);
                ewk->wu.shell_ix[1] = 1;
                ewk->wu.hit_stop = 1;

                if (screen_range_check_effD7(&ewk->wu)) {
                    ewk->wu.disp_flag = 0;
                    ewk->wu.type = 0;
                    ewk->wu.routine_no[0] = 2;
                    break;
                }
            }

            if (ewk->wu.kage_flag && mwk->wu.routine_no[1] == 4 && mwk->wu.routine_no[2] == 30 &&
                mwk->wu.cg_type == 0x28 && mwk->tk_success == ewk->wu.shell_ix[0] &&
                hit_check_subroutine(&ewk->wu, (WORK*)ewk->my_master, effD7_hit_box[0], effD7_hit_box[1])) {
                mwk->wu.cmwk[7] = 1;
                ewk->wu.type = 0;
                ewk->wu.routine_no[2] = 1;
            }

            break;

        case 1:
            ewk->wu.disp_flag = 0;

            if (mwk->wu.routine_no[1] != 4) {
                ewk->wu.routine_no[2] = 0;
                ewk->wu.xyz[0].disp.pos = mwk->wu.xyz[0].disp.pos;
                ewk->wu.xyz[1].disp.pos = mwk->wu.xyz[1].disp.pos + 136;
                ewk->wu.disp_flag = 1;
                ewk->wu.type = 1;
                ewk->wu.mvxy.a[0].sp = 0x18000;
                ewk->wu.mvxy.d[0].sp = 0;
                ewk->wu.mvxy.a[1].sp = 0x20000;
                ewk->wu.mvxy.d[1].sp = -0x6800;
            } else if (mwk->wu.cmwk[6]) {
                ewk->wu.routine_no[2] = 0;

                if (mwk->wu.rl_flag) {
                    ewk->wu.xyz[0].disp.pos = mwk->wu.xyz[0].disp.pos + 10;
                } else {
                    ewk->wu.xyz[0].disp.pos = mwk->wu.xyz[0].disp.pos - 10;
                }

                ewk->wu.xyz[1].disp.pos = mwk->wu.xyz[1].disp.pos + 136;
                ewk->wu.disp_flag = 1;
                ewk->wu.type = 1;
                set_char_move_init(&ewk->wu, 0, 0x76);
                cal_speeds_to_em(ewk, (PLW*)ewk->wu.target_adrs);
                add_mvxy_speed(&ewk->wu);
                cal_mvxy_speed(&ewk->wu);
            }

            break;
        }

        break;

    case 1:
        if (ewk->wu.hf.hit.player) {
            if (ewk->wu.hf.hit.player & 0x33) {
                ewk->wu.routine_no[1] = 0;

                if (ewk->wu.hf.hit.player & 0x30) {
                    ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
                    ewk->wu.mvxy.a[0].sp /= 3;
                    ewk->wu.mvxy.a[1].sp = 0x10000;
                    ewk->wu.mvxy.d[1].sp = -0x6000;
                } else {
                    ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
                    ewk->wu.mvxy.a[0].sp /= 2;
                    ewk->wu.mvxy.a[1].sp = 0;
                    ewk->wu.mvxy.d[1].sp = -0x6000;
                }
            } else if (ewk->wu.hf.hit.player & 0xC0) {
                ewk->wu.routine_no[1] = 0;
                ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
                ewk->wu.mvxy.a[0].sp = 0x30000;
                ewk->wu.mvxy.a[1].sp = 0x44000;
                ewk->wu.mvxy.d[1].sp = -0x5000;
                ewk->wu.hit_stop = 4;
            }
        } else if (ewk->wu.hf.hit.effect && ((WORK*)ewk->wu.hit_adrs)->id == 0x89) {
            sound_effect_request[0x157](ewk, 0x157);
            ewk->wu.routine_no[1] = 0;
            ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
            ewk->wu.mvxy.a[0].sp = (ewk->wu.mvxy.a[0].sp * 3) / 4;
            ewk->wu.hit_stop = 2;
        } else {
            if (ewk->wu.dmg_work_id != 1) {
                sound_effect_request[0x10B](ewk, 0x10B);
            }

            ewk->wu.routine_no[1] = 2;
            ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
            ewk->wu.disp_flag = 2;
            ewk->wu.type = 0;
            ewk->wu.kage_flag = 0;
            ewk->wu.dir_timer = 8;
            ewk->wu.hit_stop = 2;
        }

        ewk->wu.hit_work_id = ewk->wu.dmg_work_id = 0;
        ewk->wu.hf.hit_flag = 0;
        ewk->refrected = 1;
        break;

    case 2:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
        }

        break;
    }
}
