/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void effect_E0_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 64)) {
            return;
        }

        ewk->wu.disp_flag = 1;

        if (ewk->wu.dm_vital == 1) {
            ewk->wu.routine_no[0] = 4;
        } else {
            ewk->wu.routine_no[0]++;
        }

        break;

    case 1:
        if (Sel_EM_Complete[Player_id]) {
            if (VS_Index[Player_id] >= 8) {
                ewk->wu.routine_no[0] = 4;
            } else {
                ewk->wu.routine_no[0] = 2;
            }

            ewk->wu.dir_timer = 1;
        } else if (Moving_Plate[Player_id] != 0 && ewk->wu.dm_vital == 0) {
            if (--Moving_Plate_Counter[Player_id] == 0) {
                Moving_Plate[Player_id] = 0;
            }

            Setup_Char_E0(ewk);
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }

        break;

    case 2:
        if (--ewk->wu.dir_timer != 0) {
            break;
        }

        ewk->wu.routine_no[0]++;
        ewk->wu.dir_timer = 20;

        if (Temporary_EM[Player_id] == ewk->wu.direction) {
            ewk->wu.char_index = ((ewk->wu.direction - 1) * 4) + 38;
        } else {
            ewk->wu.char_index = ((ewk->wu.direction - 1) * 4) + 37;
        }

        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 3:
        if (Exec_Wipe == 0) {
            char_move(&ewk->wu);
        }

        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
            Sel_EM_Complete[Player_id] |= ~0x7F;
            ewk->wu.char_index = ((ewk->wu.direction - 1) * 4) + 35;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }

        break;

    case 4:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 64)) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            return;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request4(&ewk->wu);
        return;

    default:
        push_effect_work(&ewk->wu);
        return;
    }

    if (ewk->wu.dm_vital == 0 && Exec_Wipe == 0) {
        char_move(&ewk->wu);
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}
