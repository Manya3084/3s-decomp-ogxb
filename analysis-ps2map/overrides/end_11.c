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
