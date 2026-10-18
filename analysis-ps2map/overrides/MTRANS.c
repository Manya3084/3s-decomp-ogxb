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

/* When the code is not cached the Xbox returns 0; it does not log and hang. The cache entry is on the left of each comparison. */
static s32 get_mltbuf16_ext(MultiTexture* mt, u32 code, u32 palt) {
    PatternState* mc = mt->mltcsh16;
    s32 i;

    for (i = 0; i < tpu_free->x16; i++) {
        if ((mc[tpu_free->x16_used[i]].cs.code == code) && (mc[tpu_free->x16_used[i]].state == palt)) {
            return tpu_free->x16_used[i];
        }
    }

    return 0;
}

/* When the code is not cached the Xbox returns 0; it does not log and hang. The cache entry is on the left of each comparison. */
static s32 get_mltbuf32_ext(MultiTexture* mt, u32 code, u32 palt) {
    PatternState* mc = mt->mltcsh32;
    s32 i;

    for (i = 0; i < tpu_free->x32; i++) {
        if ((mc[tpu_free->x32_used[i]].cs.code == code) && (mc[tpu_free->x32_used[i]].state == palt)) {
            return tpu_free->x32_used[i];
        }
    }

    return 0;
}

/* When the cache is full the Xbox sets *ret to 0 and returns 0; it does not log and hang. */
static s32 get_mltbuf16(MultiTexture* mt, u32 code, u32 palt, s32* ret) {
    s32 i;
    s32 b = -1;
    PatternState* mc = mt->mltcsh16;

    i = mt->mltnum16;

    while (1) {
        if ((mc->cs.code == code) && (mc->state == palt)) {
            mc->time = mt->mltcshtime16;
            *ret = mt->mltnum16 - i;
            return 0;
        }

        if ((mc->cs.code == -1) && (b < 0)) {
            b = i;
        }

        mc++;
        i -= 1;

        if (i <= 0) {
            if (b >= 0) {
                b = mt->mltnum16 - b;
                mt->mltcsh16[b].time = mt->mltcshtime16;
                mt->mltcsh16[b].state = palt;
                mt->mltcsh16[b].cs.code = code;
                *ret = b;
                return 1;
            }

            // CG cache is full. 16x16: %d\n
            *ret = 0;
            return 0;
        }
    }
}

/* When the cache is full the Xbox sets *ret to 0 and returns 0; it does not log and hang. */
static s32 get_mltbuf32(MultiTexture* mt, u32 code, u32 palt, s32* ret) {
    s32 i;
    s32 b = -1;
    PatternState* mc = mt->mltcsh32;

    i = mt->mltnum32;

    while (1) {
        if ((mc->cs.code == code) && (mc->state == palt)) {
            mc->time = mt->mltcshtime32;
            *ret = mt->mltnum32 - i;
            return 0;
        }

        if ((mc->cs.code == -1) && (b < 0)) {
            b = i;
        }

        mc++;
        i -= 1;

        if (i <= 0) {
            if (b >= 0) {
                b = mt->mltnum32 - b;
                mt->mltcsh32[b].time = mt->mltcshtime32;
                mt->mltcsh32[b].state = palt;
                mt->mltcsh32[b].cs.code = code;
                *ret = b;
                return 1;
            }

            // CG cache is full. 32x32 : %d\n
            *ret = 0;
            return 0;
        }
    }
}

/* When the cache is full the Xbox sets *ret to 0 and returns 0; it does not log and hang. The cache entry is on the left of each comparison. */
static s32 get_mltbuf16_ext_2(MultiTexture* mt, u32 code, u32 palt, s32* ret, PatternInstance* cp) {
    PatternState* mc = mt->mltcsh16;
    s32 i;

    for (i = 0; i < mt->tpu->x16; i++) {
        if ((mc[mt->tpu->x16_used[i]].cs.code == code) && (mc[mt->tpu->x16_used[i]].state == palt)) {
            *ret = mt->tpu->x16_used[i];

            if (x16_mapping_set(&cp->map, *ret)) {
                cp->x16 += 1;
                mc[mt->tpu->x16_used[i]].time += 1;
            }

            return 0;
        }
    }

    if ((i != mt->mltnum16) && (mt->tpf->x16 != 0)) {
        mt->tpf->x16 -= 1;
        mt->tpu->x16_used[i] = mt->tpf->x16_free[mt->tpf->x16];
        mt->tpu->x16 += 1;
        mc[mt->tpu->x16_used[i]].cs.code = code;
        mc[mt->tpu->x16_used[i]].state = palt;
        *ret = mt->tpu->x16_used[i];
        mc[mt->tpu->x16_used[i]].time = 1;

        if (x16_mapping_set(&cp->map, *ret)) {
            cp->x16 += 1;
        }

        return 1;
    }

    // CG cache is full. x16 EXT2\n
    *ret = 0;
    return 0;
}

/* When the cache is full the Xbox sets *ret to 0 and returns 0; it does not log and hang. The cache entry is on the left of each comparison. */
static s32 get_mltbuf32_ext_2(MultiTexture* mt, u32 code, u32 palt, s32* ret, PatternInstance* cp) {
    PatternState* mc = mt->mltcsh32;
    s32 i;

    for (i = 0; i < mt->tpu->x32; i++) {
        if ((mc[mt->tpu->x32_used[i]].cs.code == code) && (mc[mt->tpu->x32_used[i]].state == palt)) {
            *ret = mt->tpu->x32_used[i];

            if (x32_mapping_set(&cp->map, *ret)) {
                cp->x32 += 1;
                mc[mt->tpu->x32_used[i]].time += 1;
            }

            return 0;
        }
    }

    if ((i != mt->mltnum32) && (mt->tpf->x32 != 0)) {
        mt->tpf->x32 -= 1;
        mt->tpu->x32_used[i] = mt->tpf->x32_free[mt->tpf->x32];
        mt->tpu->x32 += 1;
        mc[mt->tpu->x32_used[i]].cs.code = code;
        mc[mt->tpu->x32_used[i]].state = palt;
        *ret = mt->tpu->x32_used[i];
        mc[mt->tpu->x32_used[i]].time += 1;

        if (x32_mapping_set(&cp->map, *ret)) {
            cp->x32 += 1;
        }

        return 1;
    }

    *ret = 0;
    return 0;
}

/* Shifts and masks, as retail computes the index. */
static u16 x16_mapping_set(PatternMap* map, s32 code) {
    u16 num;
    u16 flg;

    flg = 0;
    num = code & 0xF;

    if (!((1 << (num)) & (map->x16_map[code >> 8][(code >> 4) & 0xF]))) {
        map->x16_map[code >> 8][(code >> 4) & 0xF] |= (1 << num);
        flg = 1;
    }

    return flg;
}
