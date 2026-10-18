/* Rewritten to match retail (tools/permute.py): < 161 -> <= 160. */
void end_402_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        bgw_ptr->speed_x = 0x8000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos <= 160) {
            bgw_ptr->r_no_1++;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 161 -> <= 160. */
void end_401_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        effect_E6_init(0x5D);
        effect_H1_init();
        bgw_ptr->speed_x = 0xC000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos <= 160) {
            bgw_ptr->r_no_1++;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void end_04000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_4_tbl[end_w.r_no_2];
        sub_00098407(0x31);
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 >= 5) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }

            if (end_w.r_no_2 == 2) {
                end_no_cut = 1;
            }

            end_w.timer = timer_4_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_400_move();
        end_401_move();
        end_402_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}
