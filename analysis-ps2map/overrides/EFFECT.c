/* The Xbox clears the block with memset. */
void work_init_zero(s32* adrs_int, s32 xx) {
    memset(adrs_int, 0, xx);
}
