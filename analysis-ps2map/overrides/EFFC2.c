/* The Xbox does not call bs2_status_disp and does not call effect_00_init. */
void effect_C2_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[2] = 0;
        ewk->wu.routine_no[3] = 2;
        Bonus_Game_result = 0;
        ewk->wu.charset_id = 17;
        set_char_base_data(&ewk->wu);
        ewk->wu.vital_new = ewk->master_id == 0;
        setup_prio_ix(ewk);
        get_bs2_parts_data(&ewk->wu);
        setup_vital_bonus2(&ewk->wu);
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.cg_number = 9;
        effect_C3_init(ewk, 3);
        effect_C3_init(ewk, 4);
        effect_C3_init(ewk, 5);
        effect_C3_init(ewk, 6);
        effect_C3_init(ewk, 7);
        effect_C3_init(ewk, 1);
        effect_C3_init(ewk, 2);
        clear_attack_num(&ewk->wu);
        ewk->wu.dir_old = 0;
        ewk->wu.direction = 0;
        ewk->wu.dir_timer = 0;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[2] = 0;
        effect_J9_init(ewk, 8);
        break;

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            ewk->wu.routine_no[1] = 10;
            ewk->wu.hit_stop = 0;
            break;
        }

        if (ewk->wu.dir_timer) {
            effC2_main_process_second(ewk, (PLW*)ewk->wu.target_adrs);
        } else {
            effC2_main_process_first(ewk, (PLW*)ewk->wu.target_adrs);
        }

        set_bs2_floor(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            switch (ewk->wu.routine_no[1]) {
            case 0:
                if (--ewk->wu.hit_stop > 0) {
                    break;
                }

                ewk->wu.routine_no[1] = 9;
                ewk->wu.routine_no[2] = 0;
                Bonus_Game_result |= 2;
                ewk->wu.xyz[1].disp.pos = 80;
                ewk->wu.next_y = 64;
                ewk->wu.position_z = 25;
                illegal_setup_effK2(&ewk->wu, 4);
                c2_last_char_and_mvxy(ewk);
                setup_demojump((PLW*)ewk->wu.target_adrs, 2);
                break;

            case 9:
                switch (ewk->wu.routine_no[2]) {
                case 0:
                    char_move(&ewk->wu);
                    add_mvxy_speed(&ewk->wu);
                    cal_mvxy_speed(&ewk->wu);

                    if (ewk->wu.mvxy.a[1].sp <= 0 && (ewk->wu.xyz[1].disp.pos <= ewk->wu.next_y)) {
                        ewk->wu.xyz[1].disp.pos = ewk->wu.next_y;
                        ewk->wu.routine_no[2] = 1;
                        char_move_cmja(&ewk->wu);
                    }

                    break;

                case 1:
                    char_move(&ewk->wu);

                    switch (ewk->wu.cg_type) {
                    case 1:
                        if (ewk->wu.mvxy.a[0].sp > 0) {
                            add_mvxy_speed_direct(&ewk->wu, 128, 0);
                        } else {
                            add_mvxy_speed_direct(&ewk->wu, -128, 0);
                        }

                        break;

                    case 2:
                        if (ewk->wu.mvxy.a[0].sp > 0) {
                            add_mvxy_speed_direct(&ewk->wu, 256, 0);
                        } else {
                            add_mvxy_speed_direct(&ewk->wu, -256, 0);
                        }

                        break;

                    case 0xFF:
                        ewk->wu.routine_no[2] = 2;
                        break;
                    }

                    break;
                }

                break;

            default:
                ewk->wu.routine_no[0] = 3;
                ewk->wu.routine_no[1] = 0;
                break;
            }

            ewk->wu.next_x = 0;
            set_c2_quake(&ewk->wu);
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos + ewk->wu.next_x;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
