/* The Xbox does not call effect_00_init. */
void effect_J9_move(WORK_Other* ewk) {
    WORK* c2wk = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.charset_id = 17;
        set_char_base_data(&ewk->wu);
        ewk->wu.my_col_mode = 0x4400;
        ewk->wu.my_col_code = 0x21FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.position_z = ewk->wu.my_priority = 68;
        ewk->wu.next_x = 0;
        break;

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, 0x44);
            break;

        case 1:
            ewk->wu.next_x = get_c2_quake(c2wk);

            if (c2wk->char_index == 0x47) {
                ewk->wu.next_x = 0;
                ewk->wu.routine_no[1]++;
                set_char_move_init(&ewk->wu, 0, 0x45);
            }

            break;

        default:
            ewk->wu.xyz[0].disp.pos = c2wk->xyz[0].disp.pos;
            break;
        }

        player_hosei_data(ewk, c2wk->dir_timer);
        effJ9_trans(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
