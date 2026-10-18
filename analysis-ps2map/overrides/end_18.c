/* The Xbox returns where the PS2 breaks out of the switch. */
void end_1800_0009() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];
        bgw_ptr->free = 0;
        Rewrite_End_Message(0);
        break;

    case 1:
        bgw_ptr->free++;
        bgw_ptr->free &= 1;

        if (bgw_ptr->free) {
            bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
            return;
        }

        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0] + 512;
        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void end_18000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        sub_00098407(0x32);
        end_w.timer = timer_18_tbl[end_w.r_no_2];
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 >= 11) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }

            end_w.timer = timer_18_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_1800_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}
