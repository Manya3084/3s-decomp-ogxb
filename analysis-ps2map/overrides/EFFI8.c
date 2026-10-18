/* Rewritten to match retail (tools/permute.py): >= 689 -> > 688; <= 399 -> < 400; >= -7 -> > -8. */
s32 check_ball_mizushibuki(s16 xx, s16 yy) {
    s16 ix;
    s16 iy;
    u16 ans;

    if (bg_w.stage == 10) {
        return 2;
    }

    if (Bonus_Game_Flag != 21) {
        return 0;
    }

    yy -= 6;

    if (xx > 688 || xx < 400) {
        return 0;
    }

    if ((yy > -8) || (yy < -24)) {
        return 0;
    }

    if ((ix = (xx - 400) / 64) > 4) {
        ix = 4;
    }

    if ((iy = (yy + 24) / 2) > 7) {
        iy = 7;
    }

    ans = cbm_table[iy][ix];

    if ((ix = ((xx - 400) % 64) / 4) > 15) {
        ix = 15;
    }

    if (ans << ix & 0x8000) {
        return 1;
    }

    return 0;
}
