/* Rewritten to match retail (tools/permute.py): < 337 -> <= 336. */
void end_900_5000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        effect_E6_init(0x2A);
        bgw_ptr->free = 0x1E;
        bgw_ptr->xy[0].disp.pos = end_9_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_9_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Rewrite_End_Message(6);
        end_fade_flag = 1;
        end_fade_timer = timer_9_tbl[end_w.r_no_2] - 120;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        bgw_ptr->xy[1].cal -= 0x8000;

        if (bgw_ptr->xy[1].disp.pos <= 336) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1500000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 3:
        break;
    }
}
