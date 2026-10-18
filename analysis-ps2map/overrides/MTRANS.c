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

/* When the code is not cached the Xbox returns 0; it does not log and hang. */
static s32 get_mltbuf16_ext(MultiTexture* mt, u32 code, u32 palt) {
    PatternState* mc = mt->mltcsh16;
    s32 i;

    for (i = 0; i < tpu_free->x16; i++) {
        if ((code == mc[tpu_free->x16_used[i]].cs.code) && (palt == mc[tpu_free->x16_used[i]].state)) {
            return tpu_free->x16_used[i];
        }
    }

    return 0;
}

/* When the code is not cached the Xbox returns 0; it does not log and hang. */
static s32 get_mltbuf32_ext(MultiTexture* mt, u32 code, u32 palt) {
    PatternState* mc = mt->mltcsh32;
    s32 i;

    for (i = 0; i < tpu_free->x32; i++) {
        if ((code == mc[tpu_free->x32_used[i]].cs.code) && (palt == mc[tpu_free->x32_used[i]].state)) {
            return tpu_free->x32_used[i];
        }
    }

    return 0;
}
