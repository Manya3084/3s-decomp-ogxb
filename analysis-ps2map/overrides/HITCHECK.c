/* Rewritten to match retail (tools/permute.py): < 31 -> <= 30. */
s32 check_pat_status(WORK* wk) {
    if (wk->pat_status >= 14 && wk->pat_status <= 30) {
        return 1;
    }

    return 0;
}
