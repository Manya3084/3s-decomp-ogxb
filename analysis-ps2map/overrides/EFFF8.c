/* The Xbox breaks out of the switch where the PS2 returns. */
void effect_F8_move(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[2].disp.pos = 26;
        ewk->wu.next_z = mwk->position_z;
        if (mwk->rl_flag) {
            ewk->wu.position_x = mwk->position_x + paring_b_mark_data[ewk->wu.direction][ewk->master_player][0];
        } else {
            ewk->wu.position_x = mwk->position_x - paring_b_mark_data[ewk->wu.direction][ewk->master_player][0];
        }

        ewk->wu.position_y = mwk->position_y + paring_b_mark_data[ewk->wu.direction][ewk->master_player][1];
        if (ewk->wu.position_z == ewk->wu.xyz[2].disp.pos) {
            ewk->wu.position_z = ewk->wu.next_z;
        } else {
            ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
        }

        set_char_move_init(&ewk->wu, 0, 3);
        sort_push_request(&ewk->wu);
        return;

    case 1:
        if ((ewk->wu.dead_f == 1) || (Suicide[0] != 0)) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] += 1;
            return;
        }

        if ((EXE_flag == 0) && (Game_pause == 0)) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0] += 1;
                return;
            }
        }

        sort_push_request(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        return;

    default:
        push_effect_work(&ewk->wu);
        return;
    }
}
