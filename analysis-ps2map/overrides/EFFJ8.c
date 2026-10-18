/* Rewritten to match retail (tools/permute.py): < 0x30001 -> <= 0x30000. */
s16 dragonfly_r_move_2(WORK_Other* ewk) {
    char_move(&ewk->wu);
    sub_000EF072(ewk);
    sub_000EF088(ewk);

    if (ewk->wu.xyz[0].disp.pos > bg_w.bgw[1].r_limit2 + bg_w.pos_offset + 24) {
        dragonfly_stop_timer(ewk);
        return 99;
    }

    if (ewk->wu.mvxy.a[0].sp <= 0x30000) {
        return 1;
    }

    return 0;
}

/* Rewritten to match retail (tools/permute.py): < -0x2FFFF -> <= -0x30000. */
s16 dragonfly_l_move_2(WORK_Other* ewk) {
    char_move(&ewk->wu);
    sub_000EF072(ewk);
    sub_000EF088(ewk);

    if (ewk->wu.xyz[0].disp.pos <= bg_w.bgw[1].l_limit2 - bg_w.pos_offset - 24) {
        dragonfly_stop_timer(ewk);
        return 99;
    }

    if (ewk->wu.mvxy.a[0].sp <= -0x30000) {
        return 1;
    }

    return 0;
}
