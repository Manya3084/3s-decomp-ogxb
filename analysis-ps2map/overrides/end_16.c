/* The Xbox returns where the PS2 breaks out of the switch. */
void end_16000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        c_kakikae = 0;
        c_number = 0;
        common_end_init00(pl_num);
        common_end_init01();
        sub_00098407(0x31);
        end_w.timer = timer_16_tbl[end_w.r_no_2];
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

            end_w.timer = timer_16_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
        }

        end_1600_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}
