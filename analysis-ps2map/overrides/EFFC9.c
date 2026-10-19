/* Data read off the retail tables: ag_char_table is 0x32E1B8, _ag_00_char_table is 0x308270, _ag_01_char_table is 0x308280, _ag_02_char_table is 0x308290, _ag_03_char_table is 0x3082A0, _ag_04_char_table is 0x3082B0, _ag_05_char_table is 0x3082C0, _ag_06_char_table is 0x3082D0, _ag_07_char_table is 0x3082E0. */

/* Located by their bytes (tools/locate_data.py): efy_data is 0x2542F0. */

/* Xbox-only: the drawing half of effect_C9_move, called through the effect
   draw table by xb_draw_effect_work. Case 0 repeats the set-up of the move
   function without advancing it. */
void xb_effect_C9_draw(WORK_Other* ewk) {
    s16 scrc;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        scrc = get_center_position();
        ewk->wu.xyz[0].disp.pos = app_pos_hosei[ewk->wu.type][0] + scrc;
        ewk->wu.xyz[1].disp.pos = app_pos_hosei[ewk->wu.type][1];
        ewk->wu.xyz[2].disp.pos = app_pos_hosei[ewk->wu.type][2] + 32;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = judge_gals_kage_tbl[ewk->wu.charset_id][0];
        ewk->wu.kage_hy = judge_gals_kage_tbl[ewk->wu.charset_id][1];
        ewk->wu.kage_prio = judge_gals_kage_tbl[ewk->wu.charset_id][2];
        ewk->wu.kage_char = judge_gals_kage_tbl[ewk->wu.charset_id][3];

        if (ewk->wu.type == 1) {
            ewk->wu.kage_hy -= 2;
        }

        set_char_move_init(&ewk->wu, 0, 0);

        if (ewk->wu.charset_id == 7) {
            ewk->wu.next_x = efy_data[0];
            ewk->wu.xyz[0].disp.pos += efy_data[1];
            ewk->wu.next_y = ewk->wu.xyz[1].disp.pos;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
        sort_push_request(&ewk->wu);
        break;

    case 1:
        if ((ewk->wu.dead_f == 1) || (Suicide[0] != 0)) {
            break;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): effect_37_init parameter 2: u8 -> s32. */
void effect_C9_move(WORK_Other* ewk) {
    s16 scrc;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 1;
        scrc = get_center_position();
        ewk->wu.xyz[0].disp.pos = app_pos_hosei[ewk->wu.type][0] + scrc;
        ewk->wu.xyz[1].disp.pos = app_pos_hosei[ewk->wu.type][1];
        ewk->wu.xyz[2].disp.pos = app_pos_hosei[ewk->wu.type][2] + 32;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = judge_gals_kage_tbl[ewk->wu.charset_id][0];
        ewk->wu.kage_hy = judge_gals_kage_tbl[ewk->wu.charset_id][1];
        ewk->wu.kage_prio = judge_gals_kage_tbl[ewk->wu.charset_id][2];
        ewk->wu.kage_char = judge_gals_kage_tbl[ewk->wu.charset_id][3];

        if (ewk->wu.type == 1) {
            ewk->wu.kage_hy -= 2;
        }

        set_char_move_init(&ewk->wu, 0, 0);

        if (ewk->wu.charset_id == 7) {
            ewk->wu.next_x = efy_data[0];
            ewk->wu.xyz[0].disp.pos += efy_data[1];
            ewk->wu.next_y = ewk->wu.xyz[1].disp.pos;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
        sort_push_request(&ewk->wu);
        break;

    case 1:
        if ((ewk->wu.dead_f == 1) || (Suicide[0] != 0)) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }

        if ((EXE_flag == 0) && (Game_pause == 0)) {
            char_move(&ewk->wu);

            switch (ewk->wu.routine_no[1]) {
            case 0:
                if (ewk->wu.charset_id == 7) {
                    switch (ewk->wu.routine_no[2]) {
                    case 0:
                        ewk->wu.next_x -= 1;

                        if (ewk->wu.next_x > 0) {
                            break;
                        }

                        ewk->wu.routine_no[2] += 1;
                        /* fallthrough */

                    case 1:
                        ewk->wu.mvxy.a[0].sp = efy_data[2];
                        ewk->wu.mvxy.d[0].sp = efy_data[3];
                        ewk->wu.mvxy.a[1].sp = efy_data[4];
                        ewk->wu.mvxy.d[1].sp = efy_data[5];
                        ewk->wu.mvxy.kop[0] = 2;
                        ewk->wu.routine_no[2] += 1;
                        /* fallthrough */

                    case 2:
                        add_mvxy_speed(&ewk->wu);
                        cal_mvxy_speed(&ewk->wu);

                        if (ewk->wu.xyz[1].disp.pos <= ewk->wu.next_y) {
                            ewk->wu.routine_no[2] += 1;
                            ewk->wu.xyz[1].disp.pos = ewk->wu.next_y;
                            ewk->wu.mvxy.d[1].sp = 0;
                            ewk->wu.mvxy.a[1].sp = 0;
                            ewk->wu.mvxy.kop[0] = 1;
                            effect_03_init(&ewk->wu, 110);
                            sound_effect_request[309](ewk, 309);
                            char_move_z(&ewk->wu);
                        }

                        break;

                    default:
                        add_mvxy_speed(&ewk->wu);
                        cal_mvxy_speed(&ewk->wu);
                        break;
                    }
                }

                if (Event_Judge_Gals) {
                    ewk->wu.routine_no[1] += 1;
                    set_char_move_init(&ewk->wu, 0, 1);
                }

                break;

            case 1:
                if (ewk->wu.cg_type == 0xFF) {
                    ewk->wu.routine_no[1] += 1;
                    set_char_move_init(&ewk->wu, 0, 2);
                    effect_37_init(&ewk->wu, ewk->wu.charset_id, EJG_index[ewk->wu.type]);
                }

                break;

            case 2:
                if (ewk->wu.cg_type == 0xFF) {
                    ewk->wu.routine_no[1] += 1;
                    Event_Judge_Gals -= 1;
                }

                break;
            }
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
