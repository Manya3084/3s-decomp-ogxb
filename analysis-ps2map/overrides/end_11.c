/* Rewritten to match retail (tools/permute.py): < 33 -> <= 32. */
void end_b01_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_b_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];

        if (end_w.r_no_2 == 1) {
            bgw_ptr->speed_y = 0x100000;
            break;
        }

        bgw_ptr->speed_y = -0x40000;
        break;

    case 1:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(2U);
        /* fallthrough */

    case 2:
        bgw_ptr->xy[1].cal += bgw_ptr->speed_y;
        bgw_ptr->abs_y += bgw_ptr->speed_y;

        if (bgw_ptr->xy[1].disp.pos <= 32) {
            bgw_ptr->xy[1].disp.pos = 288;
        }

        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void end_11000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        sub_00098407(0x31);
        end_w.timer = timer_b_tbl[end_w.r_no_2];
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 >= 7) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }

            end_w.timer = timer_b_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }

        if (bg_w.quake_y_index > 0) {
            bg_w.quake_y_index--;
        }

        end_b00_move();
        end_b01_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}
