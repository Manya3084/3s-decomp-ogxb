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

/* Shifts and masks, as retail computes the index. */
static u16 x32_mapping_set(PatternMap* map, s32 code) {
    u16 flg = 0;
    u8 num = code & 7;

    if (!((map->x32_map[code >> 6][(code >> 3) & 7]) & (1 << num))) {
        map->x32_map[code >> 6][(code >> 3) & 7] |= (1 << num);
        flg = 1;
    }

    return flg;
}
