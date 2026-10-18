/* Rewritten to match retail (tools/permute.py): < 625 -> <= 624. */
void end_600_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1 << (bgw_ptr->fam_no));
        bgw_ptr->xy[0].disp.pos = end_6_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_6_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        bgw_ptr->free = 0;
        bgw_ptr->old_pos_x = 0;
        Rewrite_End_Message(2);
        break;

    case 1:
        bgw_ptr->xy[1].cal -= 0x8000;

        if (bgw_ptr->xy[1].disp.pos <= 624) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2700000;
        }

        /* fallthrough */

    case 2:
        bgw_ptr->old_pos_x++;

        if (bgw_ptr->old_pos_x > 2) {
            bgw_ptr->old_pos_x = 0;
            bgw_ptr->free++;
            bgw_ptr->free &= 7;
            bgw_ptr->xy[0].disp.pos = end_600_1000_tbl[bgw_ptr->free][0] + 0x100;
            bgw_ptr->xy[1].disp.pos += end_600_1000_tbl[bgw_ptr->free][1];
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}
