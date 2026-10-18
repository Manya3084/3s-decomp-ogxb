/* Xbox: no c3_hit_disp_check debug display. */
void effect_C3_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.charset_id = 17;
        set_char_base_data(&ewk->wu);
        get_bs2_parts_data(&ewk->wu);
        clear_parts_hit_data(&ewk->wu);
        set_display_car_parts(ewk);

        clear_attack_num(&ewk->wu);
        break;

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            ewk->wu.routine_no[1] = 1;
            break;
        }

        ewk->wu.dir_old = bs2_sync_bomb(&ewk->wu);

        if (EXE_flag == 0 && Game_pause == 0) {
            effC3_main_process(ewk);
        }

        if (ewk->wu.dir_old == 0) {
            hit_push_request(&ewk->wu);
        }

        bs2_display_C3(&ewk->wu);
        break;

    case 2:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (check_effc2_p2_rno(&ewk->wu) == 0) {
                bs2_display_C3(&ewk->wu);
                break;
            }

            ewk->wu.disp_flag = 0;
            clear_parts_hit_data(&ewk->wu);

            if (ewk->wu.type != 3) {
                ewk->wu.routine_no[1] = 1;
            } else {
                ewk->wu.routine_no[1] = 10;
            }

            break;

        case 1:
            ewk->wu.routine_no[0] = 3;
            ewk->wu.routine_no[1] = 0;
            break;

        case 10:
            switch (get_efffC3_nsc(&ewk->wu, (WORK*)ewk->wu.my_effadrs)) {
            case 0:
                ewk->wu.disp_flag = 0;
                break;

            case 1:
                ewk->wu.disp_flag = 1;
                break;

            default:
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[1] = 1;
                break;
            }

            sort_push_request(&ewk->wu);
            break;
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
