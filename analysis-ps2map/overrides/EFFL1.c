/* The Xbox does not call grade_data_disp. */
void effect_L1_move(WORK_Other_CONN* ewk) {
    s16 i;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = effL1_base_data[ewk->wu.type][3];
        ewk->wu.dir_timer = effL1_base_data[ewk->wu.type][4];
        ewk->wu.old_cgnum = 0;
        ewk->wu.my_col_code = 0x90;

        if (effL1_base_data[ewk->wu.type][2]) {
            Setup_Color_L1((WORK_Other*)ewk);
        }

        ewk->wu.my_family = effL1_base_data[ewk->wu.type][1];
        ewk->wu.position_z = ewk->wu.my_priority = effL1_base_data[ewk->wu.type][0];
        ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos;
        ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos;
        effL1_item_init[ewk->wu.type](ewk);
        effL1_trans(&ewk->wu);
        break;

    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[2] != 0) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.type = 0;
            ewk->wu.disp_flag = 0;
            break;
        }

        switch (ewk->wu.type) {
        case 1:
            if (--ewk->wu.dir_timer < 0) {
                ewk->wu.dir_timer = 0;
                ewk->wu.disp_flag = 1;
            }

            break;

        case 10:
            if (--ewk->wu.dir_timer < 0) {
                ewk->wu.dir_timer = ewk->wu.dir_step;
                ewk->wu.direction = (ewk->wu.direction + 1) & ewk->wu.dir_old;

                for (i = 0; i < ewk->num_of_conn; i++) {
                    ewk->conn[i].chr = ewk->conn[ewk->num_of_conn + ewk->wu.direction].chr;
                }
            }

            break;
        }

        effL1_trans(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_L1_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.dead_f != 1 && Suicide[2] == 0) {
            effL1_trans(&ewk->wu);
        }

        break;
    }
}
