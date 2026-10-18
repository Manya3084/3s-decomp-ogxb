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

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 xb_FindEffect42(s16 num) {
    s16 ix;
    WORK_Other* ewk;

    for (ix = head_ix[4]; ix != -1; ix = ewk->wu.behind) {
        ewk = (WORK_Other*)frw[ix];

        if (ewk->wu.id == 0x42) {
            if (num == (ewk->master_priority & 0x3FFF)) {
                return 1;
            }

            break;
        }
    }

    return 0;
}
