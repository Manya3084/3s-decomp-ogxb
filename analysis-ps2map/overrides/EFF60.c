/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32; < 3 -> <= 2. */
void effect_60_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.disp_flag = 1;
        break;

    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }

        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            if (ewk->wu.type <= 2) {
                ewk->wu.disp_flag = 1;
                char_move(&ewk->wu);
            } else {
                ewk->wu.old_rno[1]--;

                if (ewk->wu.old_rno[1] <= 0) {
                    ewk->wu.disp_flag ^= 1;
                    ewk->wu.old_rno[1] = ewk->wu.old_rno[0];

                    if (ewk->wu.hit_stop) {
                        char_move(&ewk->wu);
                    }
                }
            }
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.routine_no[0]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request4(WORK* wk);
s32 obr_no_disp_check(void);
s32 range_x_check(WORK_Other* ewk);

void xb_effect_60_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (obr_no_disp_check() == 0 && range_x_check(ewk)) {
            sort_push_request4(&ewk->wu);
        }

        break;
    }
}
