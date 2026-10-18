/* Rewritten to match retail (tools/permute.py): < 401 -> <= 400. */
void end_1001_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_10_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_10_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0x4D);
        bgw_ptr->speed_y = 0x8000;
        bgw_ptr->free = 0xB4;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        bgw_ptr->xy[1].cal -= bgw_ptr->speed_y;

        if (bgw_ptr->xy[1].disp.pos <= 400) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1900000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 3:
        break;
    }
}
