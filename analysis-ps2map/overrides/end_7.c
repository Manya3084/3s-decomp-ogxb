/* Rewritten to match retail (tools/permute.py): < 289 -> <= 288. */
void end_700_2000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_7_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_7_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        effect_E6_init(0x59);
        Rewrite_End_Message(3);
        break;

    case 1:
        bgw_ptr->xy[0].cal -= 0x8000;

        if (bgw_ptr->xy[0].disp.pos <= 288) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1200000;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    }
}
