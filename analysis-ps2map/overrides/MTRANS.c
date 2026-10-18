/* Xbox: the matrix is 16-byte aligned on the stack */
void appRenewTempPriority(s32 z) {
    XB_ALIGN16 MTX mtx;
    njGetMatrix(&mtx);
    PrioBase[z] = mtx.a[3][2];
}

/* When the cache is full the Xbox returns 0; it does not log and hang. */
static s32 get_free_patcash_index(PatternCollection* padr) {
    s16 i;

    for (i = 0; i < 0x40; i++) {
        if (padr->patt[i].time == 0) {
            return i;
        }
    }

    return 0;
}
