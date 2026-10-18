/* Rewritten to match retail (tools/permute.py): < 337 -> <= 336. */
void end_900_5000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        effect_E6_init(0x2A);
        bgw_ptr->free = 0x1E;
        bgw_ptr->xy[0].disp.pos = end_9_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_9_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Rewrite_End_Message(6);
        end_fade_flag = 1;
        end_fade_timer = timer_9_tbl[end_w.r_no_2] - 120;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        bgw_ptr->xy[1].cal -= 0x8000;

        if (bgw_ptr->xy[1].disp.pos <= 336) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1500000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 3:
        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void end_09000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_9_tbl[end_w.r_no_2];
        sub_00098407(0x32);
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 == 6) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }

            end_w.timer = timer_9_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }

        end_900_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}
