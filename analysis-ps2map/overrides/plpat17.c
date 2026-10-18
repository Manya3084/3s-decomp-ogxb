/* Rewritten to match retail (tools/permute.py): < 85 -> <= 84. */
s32 kabe_check(WORK* wk) {
    s16 tar_pos;

    if (wk->xyz[1].disp.pos <= 84) {
        return 0;
    }

    tar_pos = get_center_position();

    if (wk->rl_flag) {
        tar_pos -= 142;

        if (!(wk->xyz[0].disp.pos > tar_pos)) {
            wk->xyz[0].disp.pos = tar_pos;
            return 1;
        }

        return 0;
    }

    tar_pos += 142;

    if (wk->xyz[0].disp.pos >= tar_pos) {
        wk->xyz[0].disp.pos = tar_pos;
        return 1;
    }

    return 0;
}
