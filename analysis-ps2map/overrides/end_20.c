/* Written from the x86; the PS2 decompilation has no C for this function. */
void sea_write() {
    s16 i;
    u16 j;
    s32 work;

    e_line_step = 64;

    for (i = 0, j = 0; j < 0x800; j += 4, i++) {
        work = (e_line_step * rate_256_table[(u8)(j + ls_cnt1)][0]) >> 4;

        if (No_Trans == 0) {
            sea_trans(i, (s16)(work >> 16));
        }
    }

    ls_cnt1 = (ls_cnt1 + 2) & 0x1FF;
}
