/* Rewritten to match retail (tools/permute.py): < 1 -> <= 0; < 1 -> <= 0; < 1 -> <= 0. */
void crow_fuss_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[0] = crow_char_tbl[ewk->wu.direction][0];
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 1);
            ewk->wu.dir_timer = 28;
            ewk->wu.old_rno[1] = ewk->wu.xyz[0].disp.pos + crow_char_tbl[ewk->wu.direction][1];
            ewk->wu.old_rno[2] = ewk->wu.xyz[1].disp.pos + crow_char_tbl[ewk->wu.direction][2];
            cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, ewk->wu.old_rno[1], ewk->wu.old_rno[2], 2, 2);
        }

        break;

    case 2:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.dir_timer = 4;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 2);
        } else {
            sub_000EF072(ewk);
            sub_000EF088(ewk);
        }

        break;

    case 3:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 4:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 3);
            ewk->wu.dir_timer = 48;
            ewk->wu.old_rno[1] = eff78_data_tbl[ewk->wu.type << 1];
            ewk->wu.old_rno[2] = eff78_data_tbl[(ewk->wu.type << 1) + 1];
            cal_all_speed_data(&ewk->wu, ewk->wu.dir_timer, ewk->wu.old_rno[1], ewk->wu.old_rno[2] + 4, 0, 0);
        }

        break;

    case 5:
        ewk->wu.dir_timer--;
        sub_000EF072(ewk);
        sub_000EF088(ewk);
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 2) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 6:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[1];
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0] + 4);
        } else {
            sub_000EF072(ewk);
            sub_000EF088(ewk);
        }

        break;

    case 7:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0] = 1;
            set_char_move_init(&ewk->wu, 0, 4);
        }

        break;
    }
}
