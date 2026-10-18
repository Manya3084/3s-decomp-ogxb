/* Written from the x86; the PS2 decompilation has no C for this function. */
void sea_write() {
    s16 i;
    u16 j;
    s32 work;

    e_line_step = 64;

    for (i = 0, j = 0; j < 0x800; j += 4, i++) {
        work = (e_line_step * rate_256_table[(u8)(j + ls_cnt1)][0]) >> 4;

        if (No_Trans == 0) {
            sea_trans(i, (s16)(work >> 16));
        }
    }

    ls_cnt1 = (ls_cnt1 + 2) & 0x1FF;
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void end_20000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_20_tbl[end_w.r_no_2];
        sub_00098407(0x31);
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

            end_w.timer = timer_20_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_2000_move();
        end_2001_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}
