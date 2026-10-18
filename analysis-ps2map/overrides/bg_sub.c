/* Rewritten to match retail (tools/permute.py): < 0x180 -> <= 0x17f; < 0x40 -> <= 0x3f. */
void bg_base_x_move_sub() {
    s16 work[2];
    s8 st[2];
    s8 i;
    s16 bg_pos;

    bg_pos = ideal_w.iw[0].disp.pos - bg_w.pos_offset;

    if (plw[0].wu.scr_mv_x < ideal_w.iw[0].disp.pos) {
        work[0] = plw[0].wu.scr_mv_x - *&satse[plw[0].player_number];
    } else {
        work[0] = plw[0].wu.scr_mv_x + *&satse[plw[0].player_number];
    }

    work[0] -= bg_pos;

    if (plw[1].wu.scr_mv_x < ideal_w.iw[0].disp.pos) {
        work[1] = plw[1].wu.scr_mv_x - *&satse[plw[1].player_number];
    } else {
        work[1] = plw[1].wu.scr_mv_x + *&satse[plw[1].player_number];
    }

    work[1] -= bg_pos;

    if (work[0] < 0) {
        work[0] = 0;
    } else if (work[0] > 0x17F) {
        work[0] = 0x17F;
    }

    if (work[1] < 0) {
        work[1] = 0;
    } else if (work[1] > 0x17F) {
        work[1] = 0x17F;
    }

    for (i = 0; i < 2; i++) {
        if (0 <= work[i] && work[i] <= 0x3f) {
            st[i] = 1;
        } else if (work[i] >= 0x140 && work[i] <= 0x17f) {
            st[i] = 2;
        } else {
            st[i] = 0;
        }
    }

    scr_x_mv_jp[(st[0] << 4) + st[1]]();
}
