/* <= 32, as retail compares. */
s32 kabe_check3(PLW* wk) {
    if (get_lever_dir(wk) != 1) {
        return 0;
    }

    if (wk->wu.xyz[1].disp.pos <= 32) {
        return 0;
    }

    return (wk->wu.rl_flag + wk->micchaku_flag == 2);
}
