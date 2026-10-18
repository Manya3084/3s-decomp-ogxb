/* The Xbox returns where the PS2 breaks out of the switch. */
void bg0000_demo() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->free = 0x1E;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1 += 1;
        }

        break;

    case 2:
        if (bgw_ptr->u_line) {
            bgw_ptr->wxy[0].cal += bgw_ptr->speed_x;

            if (bgw_ptr->wxy[0].disp.pos > 0x1D0) {
                bgw_ptr->r_no_1 += 1;
                bgw_ptr->wxy[0].disp.pos = 0x1D0;
                bgw_ptr->wxy[0].disp.low = 0;
                bgw_ptr->xy[0].cal = bgw_ptr->wxy[0].cal;
                bgw_ptr->old_pos_x = 0x1D0;
                return;
            }
        } else {
            bgw_ptr->wxy[0].cal -= bgw_ptr->speed_x;

            if (bgw_ptr->wxy[0].disp.pos < 0x1D0) {
                bgw_ptr->r_no_1 += 1;
                bgw_ptr->wxy[0].disp.pos = 0x1D0;
                bgw_ptr->wxy[0].disp.low = 0;
                bgw_ptr->xy[0].cal = bgw_ptr->wxy[0].cal;
                bgw_ptr->old_pos_x = 0x1D0;
                break;
            }
        }
        break;

    case 3:
        bg_app = 0;
        bgw_ptr->r_no_0 = 2;
        break;
    }
}
