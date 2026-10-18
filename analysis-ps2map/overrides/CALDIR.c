/* Rewritten to match retail (tools/permute.py): >= 0x80 -> > 0x7f; >= 0x80 -> > 0x7f. */
s16 cal_move_quantity2(s16 x1, s16 x2, s16 y1, s16 y2) {
    s16 kakudo;
    MS ms;

    if ((y1 -= x1) < 0) {
        y1 = -y1;
    }

    if ((y2 -= x2) < 0) {
        y2 = -y2;
    }

    x1 = y1;
    x2 = y2;

    if (y1 > y2) {
        while (y1 > 0x7f) {
            y1 >>= 1;
            y2 >>= 1;
        }
    } else {
        while (y2 > 0x7f) {
            y1 >>= 1;
            y2 >>= 1;
        }
    }

    kakudo = dir_sel_table[y1][y2];
    ms.psi = (x1 * rate_256_table[kakudo][0]);
    ms.psi += (x2 * rate_256_table[kakudo][1]);
    return ms.pss.h;
}

/* Rewritten to match retail (tools/permute.py): >= 0x80 -> > 0x7f; >= 0x80 -> > 0x7f. */
s16 caldir_pos_256(s16 x1, s16 x2, s16 y1, s16 y2) {
    s16 yhan;
    s16 tent = yhan = 0;

    switch (((y1 -= x1) < 0) + (((y2 -= x2) < 0) << 1)) {
    case 1:
        y1 = -y1;
        yhan = 1;
        break;

    case 2:
        y2 = -y2;
        yhan = 1;
        tent = 0x80;
        break;

    case 3:
        y1 = -y1;
        y2 = -y2;
        tent = 0x80;
        break;
    }

    if (y1 > y2) {
        while (y1 > 0x7f) {
            y1 >>= 1;
            y2 >>= 1;
        }
    } else {
        while (y2 > 0x7f) {
            y1 >>= 1;
            y2 >>= 1;
        }
    }

    tent += dir_sel_table[y1][y2];

    if (yhan) {
        tent = -tent;
        tent &= 0xFF;
    }

    return tent;
}
