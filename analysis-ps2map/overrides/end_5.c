/* Rewritten to match retail (tools/permute.py): < 193 -> <= 192. */
void end_5_bg1_move_sub() {
    bgw_ptr->xy[0].cal += 0xFFF00000;
    bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;

    if (bgw_ptr->xy[0].disp.pos <= 192) {
        if (bgw_ptr->xy[1].disp.pos == 768) {
            bgw_ptr->xy[0].disp.pos = bgw_ptr->abs_x = 448;
            bgw_ptr->xy[1].disp.pos = 512;
            return;
        }

        bgw_ptr->xy[0].disp.pos = bgw_ptr->abs_x = 704;
        bgw_ptr->xy[1].disp.pos = 768;
    }
}

/* Rewritten to match retail (tools/permute.py): < -1855 -> <= -1856. */
void end_500_0008() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        /* fallthrough */

    case 1:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();

        if (bgw_ptr->xy[0].disp.pos < -240) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x12);
        }

        break;

    case 2:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();

        if (bgw_ptr->xy[0].disp.pos < -624) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x14);
        }

        break;

    case 3:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();

        if (bgw_ptr->xy[0].disp.pos < -1008) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x15);
        }

        break;

    case 4:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();

        if (bgw_ptr->xy[0].disp.pos < -1376) {
            bgw_ptr->r_no_1++;
            end_etc_flag = 0;
            effect_E6_init(0x13);
        }

        break;

    case 5:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();

        if (bgw_ptr->xy[0].disp.pos < -1472) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 6:
        end_5_bg0_move_sub();

        if (bgw_ptr->xy[0].disp.pos <= -1856) {
            bgw_ptr->r_no_1++;
            end_w.timer = 18;
        }

        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 1 -> <= 0; < 193 -> <= 192; < -127 -> <= -128. */
void end_500_0007() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        overwrite_panel(0xFF000000, 0x17);
        bgw_ptr->r_no_1++;
        sub_000AF4C2(1);
        bgw_ptr->xy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = 768;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        effect_E6_init(0xF);
        effect_E6_init(0x49);
        break;

    case 1:
        break;

    case 2:
        bgw_ptr->r_no_1++;
        bgw_ptr->free = 0x28;
        break;

    case 3:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 4:
        end_5_bg0_move_sub();

        if (bgw_ptr->xy[0].disp.pos <= 192) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x11);
            bg_w.quake_y_index = 0;
            bgw_ptr->frame_deff = 4;
        }

        break;

    case 5:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();

        if (bgw_ptr->xy[0].disp.pos <= -128) {
            bgw_ptr->r_no_1++;
            end_w.timer = 0;
        }

        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void end_05000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        end_w.timer = timer_5_tbl[end_w.r_no_2];
        common_end_init01();
        sub_00098407(0x32);
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 == 13) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }

            end_w.timer = timer_5_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_500_move();
        end_501_move();
        /* fallthough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}
