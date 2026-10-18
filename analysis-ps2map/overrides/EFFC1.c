/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32; < 0x91 -> <= 0x90. */
void effect_C1_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16 work;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        setup_shadow_of_the_Effy(&ewk->wu);
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 64;

        if (oya_ptr->char_index == 67) {
            work = oya_ptr->xyz[0].disp.pos;
        } else if (oya_ptr->rl_flag) {
            work = oya_ptr->xyz[0].disp.pos + 74;
        } else {
            work = oya_ptr->xyz[0].disp.pos - 74;
        }

        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work, ewk->wu.xyz[1].disp.pos, 2, 2);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;
            sub_000EF072(ewk);
            sub_000EF088(ewk);
            work = ewk->wu.xyz[0].disp.pos - oya_ptr->xyz[0].disp.pos;

            if (work < 0) {
                work = -work;
            }

            if (work <= 0x90) {
                ewk->wu.routine_no[0]++;
                sub_00098407((ewk->master_id * 0x300) + 0x15E);
                char_move_z(&ewk->wu);
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            sub_000EF088(ewk);
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;

                if (oya_ptr->char_index == 67) {
                    set_char_move_init(&ewk->wu, 0, 37);
                } else {
                    set_char_move_init(&ewk->wu, 0, 38);
                }
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 3:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    }
}
