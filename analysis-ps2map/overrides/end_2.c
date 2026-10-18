/* Rewritten to match retail (tools/permute.py): < 129 -> <= 128. */
void end_202_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->speed_x = 0xC000;
        effect_E6_init(0x7B);
        break;

    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos <= 128) {
            bgw_ptr->r_no_1++;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 193 -> <= 192. */
void end_200_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Rewrite_End_Message(2);
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        bgw_ptr->speed_x = 0x4000;
        bgw_ptr->free = 3;
        bgw_ptr->l_limit = 0;
        break;

    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos <= 192) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x7C);
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 193 -> <= 192. */
void end_201_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(2);
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->speed_x = 0x4000;
        bgw_ptr->free = 4;
        bgw_ptr->l_limit = 0;
        break;

    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos <= 192) {
            bgw_ptr->r_no_1++;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 513 -> <= 512. */
void end_200_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Rewrite_End_Message(1);
        sub_000AF4AA(1);
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        bgw_ptr->free = 0x1E;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->speed_y = 0xC000;
        }

        break;

    case 2:
        bgw_ptr->xy[1].cal -= bgw_ptr->speed_y;

        if (bgw_ptr->xy[1].disp.pos <= 512) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2000000;
        }

        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void end_02000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_2_tbl[end_w.r_no_2];
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

            end_w.timer = timer_2_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_200_move();
        end_201_move();
        end_202_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}
