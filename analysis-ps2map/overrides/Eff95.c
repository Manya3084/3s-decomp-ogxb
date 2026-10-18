/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request4(WORK* wk);
s32 Ck_Range_Out_S(WORK_Other* ewk, s16 BG_No, s16 R);
extern void (*const D_0025B2C0[])(WORK* wk);

void xb_effect_95_draw(WORK_Other* ewk) {
    if (ewk->wu.routine_no[0] == 3 && Ck_Range_Out_S(ewk, 1, 0x40)) {
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
    sort_push_request4(&ewk->wu);
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init2 parameter 3: s16 -> s32; set_char_move_init2 parameter 4: s16 -> s32. */
void effect_95_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!Continue_Count_Down[LOSER]) {
            ewk->wu.routine_no[0]++;
        }

        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    case 1:
        if (ewk->wu.dmcal_m != (Continue_Count[LOSER])) {
            if (!(ewk->wu.dmcal_m = Continue_Count[LOSER])) {
                if (Continue_Cut[Loser_id]) {
                    ewk->wu.routine_no[0] = 3;
                    ewk->wu.dir_step = 0;
                    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                } else {
                    ewk->wu.old_rno[5] = 6;
                    ewk->wu.old_rno[6] = 6;
                    ewk->wu.dir_step = 9;
                    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                }
            } else if (Continue_Count[LOSER] < 0) {
                ewk->wu.routine_no[0] = 3;
                ewk->wu.dir_step = 0;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            } else {
                ewk->wu.old_rno[5] = 6;
                ewk->wu.old_rno[6] = 6;
                ewk->wu.dir_step = 9;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            }
        } else {
            switch (ewk->wu.vital_new) {
            case 4:
                ewk->wu.old_rno[5] = ewk->wu.old_rno[5] - 1;

                if (ewk->wu.old_rno[5] <= 0) {
                    ewk->wu.old_rno[5] = 6;
                    ewk->wu.dir_step = ewk->wu.dir_step - 1;

                    if (ewk->wu.dir_step <= 0) {
                        ewk->wu.dir_step = 0;
                    }

                    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                }

                break;

            case 8:
                ewk->wu.old_rno[6] = ewk->wu.old_rno[6] - 1;

                if (ewk->wu.old_rno[6] <= 0) {
                    ewk->wu.old_rno[6] = 6;
                }

                RND_95 = (random_16() >> 1) & 3;
                ewk->wu.dir_step = eff95_data_tbl[ewk->wu.old_rno[6]][RND_95];
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                break;

            default:
                RND_95 = (random_16() >> 1) & 7;
                RND_95 = RND_95 + 3;

                if (RND_95 > 9) {
                    RND_95 = 0;
                }

                ewk->wu.dir_step = RND_95;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                break;
            }
        }

        if (Break_Into) {
            ewk->wu.routine_no[0] = 2;
        }

        break;

    case 2:
        break;

    case 3:
        if (!Ck_Range_Out_S(ewk, 1, 64)) {
            break;
        }

        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        return;

    default:
        push_effect_work(&ewk->wu);
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    ewk->wu.position_z;
    sort_push_request4(&ewk->wu);
}
