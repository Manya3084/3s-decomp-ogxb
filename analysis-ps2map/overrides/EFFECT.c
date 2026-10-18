/* The Xbox clears the block with memset. */
void work_init_zero(s32* adrs_int, s32 xx) {
    memset(adrs_int, 0, xx);
}

/* The Xbox has no Debug_w test. */
void move_effect_work(s16 index) {
    WORK* c_addr;
    s16 curr_ix;
    s16 next_ix;

    exec_tm[index] += 1;

    for (curr_ix = head_ix[index]; curr_ix != -1; curr_ix = next_ix) {
        c_addr = (WORK*)frw[curr_ix];
        next_ix = c_addr->behind;

        if (c_addr->timing != exec_tm[index]) {
            c_addr->timing = exec_tm[index];
            effmovejptbl[c_addr->id](c_addr);
        }
    }
}
