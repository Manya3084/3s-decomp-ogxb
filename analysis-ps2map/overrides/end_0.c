/* Rewritten to match retail (tools/permute.py): < 1 -> <= 0. */
void end_001_0004() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_0_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0xAE);
        effect_E6_init(0xAF);
        bgw_ptr->speed_y = 0x340000 / gill_time[2];
        bgw_ptr->l_limit = gill_time[2];
        break;

    case 1:
        bgw_ptr->xy[1].cal += bgw_ptr->speed_y;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;

        if (!bgw_ptr->l_limit--) {
            bgw_ptr->r_no_1++;
            bgw_ptr->frame_deff = 0;
            bgw_ptr->l_limit = gill_time[8];
        }

        break;

    case 2:
        bgw_ptr->r_no_1++;
        break;

    case 3:
        if (end_etc_flag) {
            bgw_ptr->r_no_1++;
            bgw_ptr->r_limit = gill_time[6];
        }

        /* fallthrough */

    case 4:
        bgw_ptr->r_no_1++;
        /* fallthrough */

    case 5:
    case 6:
        bgw_ptr->r_limit--;

        if (bgw_ptr->r_limit <= 0) {
            bgw_ptr->frame_deff++;
            bgw_ptr->frame_deff &= 0x1F;
            bgw_ptr->r_limit = end00_quake_timer[bgw_ptr->frame_deff];
            bgw_ptr->xy[0].disp.pos = end_0_pos[end_w.r_no_2][0];
            bgw_ptr->xy[1].disp.pos = 48;
            bgw_ptr->xy[1].disp.pos += end00_quake_tbl2[bgw_ptr->frame_deff];
            bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
            bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        }

        break;
    }
}
