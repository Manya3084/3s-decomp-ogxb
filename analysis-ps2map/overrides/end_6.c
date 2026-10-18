/* Rewritten to match retail (tools/permute.py): < 625 -> <= 624. */
void end_600_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1 << (bgw_ptr->fam_no));
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        bgw_ptr->free = 0;
        bgw_ptr->old_pos_x = 0;
        Rewrite_End_Message(2);
        break;

    case 1:
        bgw_ptr->xy[1].cal -= 0x8000;

        if (bgw_ptr->xy[1].disp.pos <= 624) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2700000;
        }

        /* fallthrough */

    case 2:
        bgw_ptr->old_pos_x++;

        if (bgw_ptr->old_pos_x > 2) {
            bgw_ptr->old_pos_x = 0;
            bgw_ptr->free++;
            bgw_ptr->free &= 7;
            bgw_ptr->xy[0].disp.pos = end_600_1000_tbl[bgw_ptr->free][0] + 0x100;
            bgw_ptr->xy[1].disp.pos += end_600_1000_tbl[bgw_ptr->free][1];
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void end_06000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        end_w.timer = timer_6_tbl[end_w.r_no_2];
        common_end_init01();
        sub_00098407(0x32);
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 >= 6) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }

            end_w.timer = timer_6_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }

        end_600_move();
        end_601_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}
