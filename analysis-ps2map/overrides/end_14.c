/* Rewritten to match retail (tools/permute.py): >= 8 -> > 7. */
void end_e00_1000_col_sub() {
    if (bgw_ptr->l_limit > 7) {
        return;
    }

    bgw_ptr->free--;

    if (bgw_ptr->free > 0) {
        return;
    }

    bgw_ptr->l_limit++;

    if (bgw_ptr->l_limit < 7) {
        bgw_ptr->free = 8;
        g_number[1] = end_e00_1000_col_tbl[bgw_ptr->l_limit];
    }
}

/* Rewritten to match retail (tools/permute.py): < 353 -> <= 352. */
void end_e02_3000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 768;
        bgw_ptr->xy[1].disp.pos = 408;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 1:
        bgw_ptr->xy[1].cal += -0x18000;

        if (bgw_ptr->xy[1].disp.pos <= 352) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1600000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 2:
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 1 -> <= 0. */
void end_e00_3000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4C2(1);
        bgw_ptr->xy[0].disp.pos = 256;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x1A);
        bgw_ptr->free = 0x30;
        Rewrite_End_Message(0);
        break;

    case 1:
        break;

    case 2:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        } else {
            Frame_Up(0xC0, 0x30, 1);
        }

        break;

    case 3:
        if (Request_Fade(3)) {
            end_no_cut = 1;
            bgw_ptr->r_no_1++;
        }

        break;

    case 4:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
            end_w.timer = 10;
            overwrite_panel(0xFFFFFFFF, 0x17);
            Frame_Down(0xC0, 0x30, 0x10);
        }

        break;

    case 5:
        Frame_Down(0xC0, 0x30, 3);
        overwrite_panel(0xFFFFFFFF, 0x17);
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 273 -> <= 272; < -311 -> <= -312. */
void end_e01_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(2);
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        bgw_ptr->free = 0x3C;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        bgw_ptr->xy[1].cal -= 0x18000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;

        if (bgw_ptr->xy[1].disp.pos <= 272) {
            bgw_ptr->r_no_1++;
            sub_000AF4C2(2);
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 3:
        bgw_ptr->xy[1].cal -= 0x18000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 4:
        bgw_ptr->r_no_1++;
        bgw_ptr->free = 7;
        bgw_ptr->l_limit = 0;
        /* fallthrough */

    case 5:
        if (end_e00_0000_col_sub2()) {
            bgw_ptr->r_no_1++;
        }

        /* fallthrough */

    case 6:
        bgw_ptr->xy[1].cal -= 0x4000;

        if (bgw_ptr->xy[1].disp.pos <= -312) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0xFEC80000;
            end_w.timer = 20;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 7:
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 697 -> <= 696. */
void end_e00_7000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        overwrite_panel(0xFFFFFFFF, 0x17);
        bgw_ptr->r_no_1++;
        nosekae = 2;
        *scr_bcm = ending_map_tbl[20][1];
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->xy[1].disp.pos += 48;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        sub_000AF4AA(1);
        end_fade_flag = 1;
        end_fade_timer = timer_e_tbl[end_w.r_no_2] - 120;
        Rewrite_End_Message(5);
        /* fallthrough */

    case 1:
        overwrite_panel(0xFFFFFFFF, 0x17);

        if (Request_Fade(2)) {
            end_no_cut = 1;
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
        }

        /* fallthrough */

    case 3:
        bgw_ptr->xy[1].cal -= 0x3000;

        if (bgw_ptr->xy[1].disp.pos <= 696) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2B80000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 4:
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 273 -> <= 272; < 713 -> <= 712; < -223 -> <= -224. */
void end_e00_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1);
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[0].disp.pos += 64;
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->free = 0x3C;
        Rewrite_End_Message(1);
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        bgw_ptr->xy[1].cal -= 0x18000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;

        if (bgw_ptr->xy[1].disp.pos <= 272) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x19);
            gxy.xy[1].disp.pos = bgw_ptr->xy[1].disp.pos;
            nosekae = 1;
            *scr_bcm = ending_map_tbl[20][0];
        }

        break;

    case 3:
        bgw_ptr->xy[1].cal -= 0x18000;
        gxy.xy[1].cal = gxy.xy[1].cal - 0x18000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;

        if (bgw_ptr->xy[1].disp.pos < 0) {
            bgw_ptr->xy[1].disp.pos = 0;
        }

        if (gxy.xy[1].disp.pos <= -224) {
            bgw_ptr->xy[1].disp.pos = 752;
        }

        break;

    case 4:
        bgw_ptr->r_no_1++;
        bgw_ptr->free = 7;
        bgw_ptr->l_limit = 0;
        g_kakikae[0] = 1;
        /* fallthrough */

    case 5:
        if (end_e00_0000_col_sub()) {
            bgw_ptr->r_no_1++;
        }

        /* fallthrough */

    case 6:
        bgw_ptr->xy[1].cal -= 0x4000;

        if (bgw_ptr->xy[1].disp.pos <= 712) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2C80000;
            end_w.timer = 20;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 7:
        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void end_14000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        nosekae = 0;
        g_kakikae[0] = 0;
        g_kakikae[1] = 0;
        g_number[0] = 0;
        g_number[1] = 0;
        gxy.xy[1].disp.pos = 0;
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        end_w.timer = timer_e_tbl[end_w.r_no_2];
        common_end_init01();
        sub_00098407(0x32);
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 == 8) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }

            end_w.timer = timer_e_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_e00_move();
        end_e01_move();
        end_e02_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}
