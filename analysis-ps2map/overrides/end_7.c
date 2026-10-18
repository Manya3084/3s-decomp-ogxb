/* Rewritten to match retail (tools/permute.py): < 289 -> <= 288. */
void end_700_2000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_7_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_7_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        effect_E6_init(0x59);
        Rewrite_End_Message(3);
        break;

    case 1:
        bgw_ptr->xy[0].cal -= 0x8000;

        if (bgw_ptr->xy[0].disp.pos <= 288) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1200000;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void end_07000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        end_w.timer = timer_7_tbl[end_w.r_no_2];
        common_end_init01();
        sub_00098407(0x31);
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 >= 4) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }

            end_w.timer = timer_7_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }

        end_700_move();
        end_701_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}
