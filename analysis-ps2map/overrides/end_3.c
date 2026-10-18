/* Rewritten to match retail (tools/permute.py): < 449 -> <= 448. */
void end_300_0003() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        overwrite_panel(0xFFFFFFFF, 0x17);
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_3_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_3_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0x9D);
        effect_E6_init(0xB3);
        Rewrite_End_Message(4);
        /* fallthrough */

    case 1:
        if (Request_Fade(2)) {
            bgw_ptr->r_no_1++;
            end_no_cut = 1;
        }

        break;

    case 2:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
        }

        break;

    case 3:
        bgw_ptr->xy[1].cal -= 0x4000;

        if (bgw_ptr->xy[1].disp.pos <= 448) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1C00000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}
