/* Data: PrioBaseOriginal is 0xC7E780 (appSetupBasePriority fills it). */
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

/* On bad data the Xbox returns; it does not log and hang. It draws no DebugLine boxes. */
s32 seqsStoreChip(f32 x, f32 y, s32 w, s32 h, s32 gix, s32 code, s32 attr, s32 alpha, s32 id) {
    Sprite2* chip;
    s32 u;
    s32 v;

    f32 dx;
    f32 dy;

    chip = &seqs_w.chip[seqs_w.sprTotal];
    chip->v[0].x = x;
    chip->v[0].y = y;
    chip->v[1].x = x + w;
    chip->v[1].y = y - h;
    chip->v[0].z = chip->v[1].z = 0.0f;
    njCalcPoint(NULL, &chip->v[0], &chip->v[0]);
    njCalcPoint(NULL, &chip->v[1], &chip->v[1]);

    if ((chip->v[0].x >= 384.0f) || (chip->v[1].x < 0.0f) || (chip->v[0].y >= 224.0f) || (chip->v[1].y < 0.0f)) {
        return 1;
    }

    if (!(attr & 0x2000)) {
        u = (code & 0xF) * 16;
        v = code & 0xF0;
        chip->texCode = ppgGetUsingTextureHandle(NULL, gix + (code >> 8));
    } else {
        u = (code & 7) * 32;
        v = (code & 0x38) * 4;
        chip->texCode = ppgGetUsingTextureHandle(NULL, gix + (code >> 6));
    }

    appRenewTempPriority_1_Chip();

    if (attr & 0x8000) {
        dx = (((chip->v[1].x - chip->v[0].x) / w) > 1.5f) ? 0.34f : 0.68f;
        chip->t[1].s = (u - dx) / 256.0f;
        chip->t[0].s = (u + w - dx) / 256.0f;
    } else {
        dx = (((chip->v[1].x - chip->v[0].x) / w) > 1.0f) ? 0.0f : 0.5f;
        chip->t[0].s = (u + dx) / 256.0f;
        chip->t[1].s = (u + w + dx) / 256.0f;
    }

    if (attr & 0x4000) {
        dy = (((chip->v[1].y - chip->v[0].y) / h) > 1.5f) ? 0.34f : 0.68f;
        chip->t[1].t = (v - dy) / 256.0f;
        chip->t[0].t = (v + h - dy) / 256.0f;
    } else {
        dy = (((chip->v[1].y - chip->v[0].y) / h) > 1.0f) ? 0.0f : 0.5f;
        chip->t[0].t = (v + dy) / 256.0f;
        chip->t[1].t = (v + h + dy) / 256.0f;
    }

    chip->texCode |= ppgGetUsingPaletteHandle(NULL, attr & 0x1FF) << 16;
    chip->vtxColor = curr_bright | ((0xFF - alpha) << 24);
    chip->id = id;
    seqs_w.sprTotal += 1;

    if (seqs_w.sprTotal > 0x400) {
        // The number of OBJ fragments has exceeded the planned number
        return 0;
    }

    return 1;
}

/* On bad data the Xbox returns; it does not log and hang. It draws no DebugLine boxes. */
void mlt_obj_melt2(MultiTexture* mt, u16 cg_number) {
    u32* textbl;
    u16* trsbas;
    TileMapEntry* trsptr;
    TEX* texptr;
    TEX_GRP_LD* grplds;
    s32 count;
    s32 n;
    s32 i;
    s32 cd16;
    s32 cd32;
    s32 size;
    s32 attr;
    s32 palt;
    s32 wh;
    s32 dd;

    u16* spA4;

    ppgSetupCurrentDataList(&mt->texList);
    grplds = &texgrplds[obj_group_table[cg_number]];

    if (grplds->ok == 0) {
        // The trans data is not valid. Group number: %d\n
        return;
    }

    n = *(u32*)grplds->trans_table / 4;
    textbl = (u32*)grplds->texture_table;
    cd16 = 0;
    cd32 = 0;

    for (i = 0; i < n; i++) {
        trsbas = (u16*)(grplds->trans_table + ((u32*)grplds->trans_table)[i]);
        count = *trsbas;
        trsbas++;
        trsptr = (TileMapEntry*)trsbas;

        while (count != 0) {
            attr = trsptr->attr;

            if (!(attr & 0x1000)) {
                texptr = (TEX*)((uintptr_t)textbl + ((u32*)textbl)[trsptr->code]);
                dd = (((texptr->wh & 0xE0) << 5) - 0x400) | (((texptr->wh & 0x1C) << 6) - 0x100);
                wh = (texptr->wh & 3) + 1;
                size = (wh * wh) << 6;
                palt = attr & 3;

                switch (wh) {
                case 1:
                case 2:
                    lz_ext_p6_fx(&((u8*)texptr)[1], mt->mltbuf, size);
                    njReLoadTexturePartNumG(mt->mltgidx16 + (cd16 >> 8), (s8*)mt->mltbuf, cd16 & 0xFF, size);
                    attr = (attr & 0xC000) | 0x1000 | dd;
                    trsptr->attr |= 0x1000;
                    attr |= palt;
                    search_trsptr(grplds->trans_table, i, n, trsptr->code, palt, cd16, attr);
                    trsptr->code = cd16;
                    trsptr->attr = attr;
                    cd16 += 1;
                    break;

                case 4:
                    lz_ext_p6_fx(&((u8*)texptr)[1], mt->mltbuf, size);
                    njReLoadTexturePartNumG(mt->mltgidx32 + (cd32 >> 6), (s8*)mt->mltbuf, cd32 & 0x3F, size);
                    attr = (attr & 0xC000) | 0x3000 | dd;
                    trsptr->attr |= 0x1000;
                    attr |= palt;
                    search_trsptr(grplds->trans_table, i, n, trsptr->code, palt, cd32, attr);
                    trsptr->code = cd32;
                    trsptr->attr = attr;
                    cd32 += 1;
                    break;
                }
            }

            count -= 1;
            spA4 = (u16*)trsptr++;
        }
    }

    ppgRenewTexChunkSeqs(NULL);
}

/* On bad data the Xbox returns; it does not log and hang. It draws no DebugLine boxes. */
void mlt_obj_disp(MultiTexture* mt, WORK* wk, s32 base_y) {
    u16* trsbas;
    TileMapEntry* trsptr;
    s32 rnum;
    s32 attr;
    s32 palo;
    s32 count;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    s32 dw;
    s32 dh;

    ppgSetupCurrentDataList(&mt->texList);
    n = wk->cg_number;
    i = obj_group_table[n];

    if (i == 0) {
        return;
    }

    if (texgrplds[i].ok == 0) {
        // The trans data is not valid. Group number: %d\n
        return;
    }

    n -= texgrpdat[i].num_of_1st;
    trsbas = (u16*)(texgrplds[i].trans_table + ((u32*)texgrplds[i].trans_table)[n]);
    count = *trsbas;
    trsbas++;
    trsptr = (TileMapEntry*)trsbas;
    x = y = 0.0f;
    attr = flptbl[wk->cg_flip ^ wk->rl_flag];
    palo = wk->colcd & 0xF;

    if (wk->my_bright_type) {
        curr_bright = bright_type[wk->my_bright_type - 1][wk->my_bright_level];
    } else {
        curr_bright = 0xFFFFFF;
    }

    mlt_obj_matrix(wk, base_y);

    while (count--) {
        if (attr & 0x8000) {
            x += trsptr->x;
        } else {
            x -= trsptr->x;
        }

        if (attr & 0x4000) {
            y -= trsptr->y;
        } else {
            y += trsptr->y;
        }

        dw = ((trsptr->attr & 0xC00) >> 7) + 8;
        dh = ((trsptr->attr & 0x300) >> 5) + 8;

        if (!(trsptr->attr & 0x2000)) {

            rnum = seqsStoreChip(x - (dw * BOOL(attr & 0x8000)),
                                 y + (dh * BOOL(attr & 0x4000)),
                                 dw,
                                 dh,
                                 mt->mltgidx16,
                                 trsptr->code,
                                 palo + ((trsptr->attr ^ attr) & 0xE00F),
                                 wk->my_clear_level,
                                 mt->id);
        } else {

            rnum = seqsStoreChip(x - dw * BOOL(attr & 0x8000),
                                 y + dh * BOOL(attr & 0x4000),
                                 dw,
                                 dh,
                                 mt->mltgidx32,
                                 trsptr->code,
                                 palo + ((trsptr->attr ^ attr) & 0xE00F),
                                 wk->my_clear_level,
                                 mt->id);
        }

        if (rnum == 0) {
            break;
        }

        trsptr += 1;
    }

    seqs_w.up[mt->id] = 1;
    appRenewTempPriority(wk->position_z);
}

/* On bad data the Xbox returns; it does not log and hang. It draws no DebugLine boxes. */
void mlt_obj_disp_rgb(MultiTexture* mt, WORK* wk, s32 base_y) {
    u16* trsbas;
    TileMapEntry* trsptr;
    s32 rnum;
    s32 attr;
    s32 count;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    s32 dw;
    s32 dh;

    ppgSetupCurrentDataList(&mt->texList);
    n = wk->cg_number;
    i = obj_group_table[n];

    if (i == 0) {
        return;
    }

    if (texgrplds[i].ok == 0) {
        // The trans data is not valid. Group number: %d\n
        return;
    }

    n -= texgrpdat[i].num_of_1st;
    trsbas = (u16*)(texgrplds[i].trans_table + ((u32*)texgrplds[i].trans_table)[n]);
    count = *trsbas;
    trsbas++;
    trsptr = (TileMapEntry*)trsbas;
    x = y = 0.0f;
    attr = flptbl[wk->cg_flip ^ wk->rl_flag];

    if (wk->my_bright_type) {
        curr_bright = bright_type[wk->my_bright_type - 1][wk->my_bright_level];
    } else {
        curr_bright = 0xFFFFFF;
    }

    mlt_obj_matrix(wk, base_y);

    while (count--) {
        if (attr & 0x8000) {
            x += trsptr->x;
        } else {
            x -= trsptr->x;
        }

        if (attr & 0x4000) {
            y -= trsptr->y;
        } else {
            y += trsptr->y;
        }

        dw = ((trsptr->attr & 0xC00) >> 7) + 8;
        dh = ((trsptr->attr & 0x300) >> 5) + 8;

        if (!(trsptr->attr & 0x2000)) {

            rnum = seqsStoreChip(x - (dw * BOOL(attr & 0x8000)),
                                 y + (dh * BOOL(attr & 0x4000)),
                                 dw,
                                 dh,
                                 mt->mltgidx16,
                                 trsptr->code,
                                 (trsptr->attr ^ attr) & 0xE000,
                                 wk->my_clear_level,
                                 mt->id);
        } else {

            rnum = seqsStoreChip(x - (dw * BOOL(attr & 0x8000)),
                                 y + (dh * BOOL(attr & 0x4000)),
                                 dw,
                                 dh,
                                 mt->mltgidx32,
                                 trsptr->code,
                                 (trsptr->attr ^ attr) & 0xE000,
                                 wk->my_clear_level,
                                 mt->id);
        }

        if (rnum == 0) {
            break;
        }

        trsptr++;
    }

    seqs_w.up[mt->id] = 1;
    appRenewTempPriority(wk->position_z);
}

/* On bad data the Xbox returns; it does not log and hang. It draws no DebugLine boxes. */
void mlt_obj_trans_ext(MultiTexture* mt, WORK* wk, s32 base_y) {
    u32* textbl;
    u16* trsbas;
    TileMapEntry* trsptr;
    TEX* texptr;
    s32 rnum;
    s32 attr;
    s32 palo;
    s32 count;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    s16 ix;
    PatternCode cc;
    PatternInstance* cp;

    n = wk->cg_number;
    i = obj_group_table[n];

    if (i == 0) {
        return;
    }

    if (texgrplds[i].ok == 0) {
        // The trans data is not valid. Group number: %d\n
        return;
    }

    n -= texgrpdat[i].num_of_1st;
    trsbas = (u16*)(texgrplds[i].trans_table + ((u32*)texgrplds[i].trans_table)[n]);
    textbl = (u32*)texgrplds[i].texture_table;
    count = *trsbas;
    trsbas++;
    trsptr = (TileMapEntry*)trsbas;
    x = y = 0.0f;
    attr = flptbl[wk->cg_flip ^ wk->rl_flag];
    palo = wk->colcd;

    if (wk->my_bright_type) {
        curr_bright = bright_type[wk->my_bright_type - 1][wk->my_bright_level];
    } else {
        curr_bright = 0xFFFFFF;
    }

    mlt_obj_matrix(wk, base_y);
    cc.parts.group = 0;
    cc.parts.offset = wk->cg_number;
    ix = check_patcash_ex_trans(mt->cpat, cc.code);

    if (ix < 0) {
        {
            s32 size;
            s32 code;
            s32 wh;
            s32 dw;
            s32 dh;

            (void)dw;
            (void)dh;

            ix = get_free_patcash_index(mt->cpat);
            cp = &mt->cpat->patt[ix];
            mt->cpat->adr[mt->cpat->kazu] = cp;
            mt->cpat->kazu += 1;
            cp->curr_disp = 1;
            cp->time = mt->mltcshtime16;
            cp->cg.code = cc.code;
            cp->x16 = 0;
            cp->x32 = 0;
            work_init_zero((s32*)&cp->map, sizeof(PatternMap));
            cc.parts.group = i;

            while (count--) {
                if (attr & 0x8000) {
                    x += trsptr->x;
                } else {
                    x -= trsptr->x;
                }

                if (attr & 0x4000) {
                    y -= trsptr->y;
                } else {
                    y += trsptr->y;
                }

                texptr = (TEX*)((uintptr_t)textbl + ((u32*)textbl)[trsptr->code]);
                dw = (texptr->wh & 0xE0) >> 2;
                dh = (texptr->wh & 0x1C) * 2;
                wh = (texptr->wh & 3) + 1;
                size = (wh * wh) << 6;
                cc.parts.offset = trsptr->code;

                switch (wh) {
                case 1:
                case 2:
                    if (get_mltbuf16_ext_2(mt, cc.code, 0, &code, cp) != 0) {
                        lz_ext_p6_fx(&((u8*)texptr)[1], mt->mltbuf, size);
                        njReLoadTexturePartNumG(mt->mltgidx16 + (code >> 8), (s8*)mt->mltbuf, code & 0xFF, size);
                    }


                    rnum = seqsStoreChip(x - (dw * BOOL(attr & 0x8000)),
                                         y + (dh * BOOL(attr & 0x4000)),
                                         dw,
                                         dh,
                                         mt->mltgidx16,
                                         code,
                                         palo | ((trsptr->attr ^ attr) & 0xC000),
                                         wk->my_clear_level,
                                         mt->id);
                    break;

                case 4:
                    if (get_mltbuf32_ext_2(mt, cc.code, 0, &code, cp) != 0) {
                        lz_ext_p6_fx(&((u8*)texptr)[1], mt->mltbuf, size);
                        njReLoadTexturePartNumG(mt->mltgidx32 + (code >> 6), (s8*)mt->mltbuf, code & 0x3F, size);
                    }


                    rnum = seqsStoreChip(x - (dw * BOOL(attr & 0x8000)),
                                         y + (dh * BOOL(attr & 0x4000)),
                                         dw,
                                         dh,
                                         mt->mltgidx32,
                                         code,
                                         palo | (((trsptr->attr ^ attr) & 0xC000) | 0x2000),
                                         wk->my_clear_level,
                                         mt->id);
                    break;
                }

                if (rnum == 0) {
                    break;
                }

                trsptr++;
            }

            seqs_w.up[mt->id] = 1;
            appRenewTempPriority(wk->position_z);
            return;
        }
    }

    {
        s32 size;
        s32 code;
        s32 wh;
        s32 dw;
        s32 dh;

        (void)dw;
        (void)dh;

        cp = mt->cpat->adr[ix];
        cp->curr_disp = 1;
        cp->time = mt->mltcshtime16;

        makeup_tpu_free(mt->mltnum16 / 256, mt->mltnum32 / 64, &cp->map);
        cc.parts.group = i;

        while (count--) {
            if (attr & 0x8000) {
                x += trsptr->x;
            } else {
                x -= trsptr->x;
            }

            if (attr & 0x4000) {
                y -= trsptr->y;
            } else {
                y += trsptr->y;
            }

            texptr = (TEX*)((uintptr_t)textbl + ((u32*)textbl)[trsptr->code]);
            dw = (texptr->wh & 0xE0) >> 2;
            dh = (texptr->wh & 0x1C) * 2;
            wh = (texptr->wh & 3) + 1;
            size = (wh * wh) << 6;
            cc.parts.offset = trsptr->code;

            switch (wh) {
            case 1:
            case 2:
                code = get_mltbuf16_ext(mt, cc.code, 0);


                rnum = seqsStoreChip(x - (dw * BOOL(attr & 0x8000)),
                                     y + (dh * BOOL(attr & 0x4000)),
                                     dw,
                                     dh,
                                     mt->mltgidx16,
                                     code,
                                     palo | ((trsptr->attr ^ attr) & 0xC000),
                                     wk->my_clear_level,
                                     mt->id);
                break;

            case 4:
                code = get_mltbuf32_ext(mt, cc.code, 0);


                rnum = seqsStoreChip(x - (dw * BOOL(attr & 0x8000)),
                                     y + (dh * BOOL(attr & 0x4000)),
                                     dw,
                                     dh,
                                     mt->mltgidx32,
                                     code,
                                     palo | (((trsptr->attr ^ attr) & 0xC000) | 0x2000),
                                     wk->my_clear_level,
                                     mt->id);
                break;
            }

            if (rnum == 0) {
                break;
            }

            trsptr++;
        }

        seqs_w.up[mt->id] = 1;
        appRenewTempPriority(wk->position_z);
    }
}

/* On bad data the Xbox returns; it does not log and hang. It draws no DebugLine boxes. */
void mlt_obj_trans(MultiTexture* mt, WORK* wk, s32 base_y) {
    u32* textbl;
    u16* trsbas;
    TileMapEntry* trsptr;
    TEX* texptr;
    s32 rnum;
    s32 attr;
    s32 count;
    s32 palo;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    PatternCode cc;
    s32 size;
    s32 code;
    s32 wh;
    s32 dw;
    s32 dh;

    ppgSetupCurrentDataList(&mt->texList);

    if (mt->ext) {
        mlt_obj_trans_ext(mt, wk, base_y);
        return;
    }

    n = wk->cg_number;
    i = obj_group_table[n];

    if (i == 0) {
        return;
    }

    if (texgrplds[i].ok == 0) {
        // The trans data is not valid. Group number: %d\n
        return;
    }

    n -= texgrpdat[i].num_of_1st;
    trsbas = (u16*)(texgrplds[i].trans_table + ((u32*)texgrplds[i].trans_table)[n]);
    textbl = (u32*)texgrplds[i].texture_table;
    count = *trsbas;
    trsbas++;
    trsptr = (TileMapEntry*)trsbas;
    x = y = 0.0f;
    attr = flptbl[wk->cg_flip ^ wk->rl_flag];
    palo = wk->colcd;

    if (wk->my_bright_type) {
        curr_bright = bright_type[wk->my_bright_type - 1][wk->my_bright_level];
    } else {
        curr_bright = 0xFFFFFF;
    }

    mlt_obj_matrix(wk, base_y);
    cc.parts.group = i;

    while (count--) {
        if (attr & 0x8000) {
            x += trsptr->x;
        } else {
            x -= trsptr->x;
        }

        if (attr & 0x4000) {
            y -= trsptr->y;
        } else {
            y += trsptr->y;
        }

        texptr = (TEX*)((uintptr_t)textbl + ((u32*)textbl)[trsptr->code]);
        dw = (texptr->wh & 0xE0) >> 2;
        dh = (texptr->wh & 0x1C) * 2;
        wh = (texptr->wh & 3) + 1;
        size = (wh * wh) << 6;
        cc.parts.offset = trsptr->code;

        switch (wh) {
        case 1:
        case 2:
            if (get_mltbuf16(mt, cc.code, 0, &code) != 0) {
                lz_ext_p6_fx(&((u8*)texptr)[1], mt->mltbuf, size);
                njReLoadTexturePartNumG(mt->mltgidx16 + (code >> 8), (s8*)mt->mltbuf, code & 0xFF, size);
            }


            rnum = seqsStoreChip(x - (dw * BOOL(attr & 0x8000)),
                                 y + (dh * BOOL(attr & 0x4000)),
                                 dw,
                                 dh,
                                 mt->mltgidx16,
                                 code,
                                 palo | ((trsptr->attr ^ attr) & 0xC000),
                                 wk->my_clear_level,
                                 mt->id);
            break;

        case 4:
            if (get_mltbuf32(mt, cc.code, 0, &code) != 0) {
                lz_ext_p6_fx(&((u8*)texptr)[1], mt->mltbuf, size);
                njReLoadTexturePartNumG(mt->mltgidx32 + (code >> 6), (s8*)mt->mltbuf, code & 0x3F, size);
            }


            rnum = seqsStoreChip(x - (dw * BOOL(attr & 0x8000)),
                                 y + (dh * BOOL(attr & 0x4000)),
                                 dw,
                                 dh,
                                 mt->mltgidx32,
                                 code,
                                 palo | (((trsptr->attr ^ attr) & 0xC000) | 0x2000),
                                 wk->my_clear_level,
                                 mt->id);
            break;
        }

        if (rnum == 0) {
            break;
        }

        trsptr++;
    }

    seqs_w.up[mt->id] = 1;
    appRenewTempPriority(wk->position_z);
}

/* On bad data the Xbox returns; it does not log and hang. It draws no DebugLine boxes. */
void mlt_obj_trans_cp3_ext(MultiTexture* mt, WORK* wk, s32 base_y) {
    u32* textbl;
    u16* trsbas;
    TileMapEntry* trsptr;
    TEX* texptr;
    s32 rnum;
    s32 flip;
    s32 palo;
    s32 count;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    s16 ix;
    PatternCode cc;
    PatternInstance* cp;

    n = wk->cg_number;
    i = obj_group_table[n];

    if (i == 0) {
        return;
    }

    if (texgrplds[i].ok == 0) {
        // The trans data is not valid. Group number: %d\n
        return;
    }

    n -= texgrpdat[i].num_of_1st;
    trsbas = (u16*)(texgrplds[i].trans_table + ((u32*)texgrplds[i].trans_table)[n]);
    textbl = (u32*)texgrplds[i].texture_table;
    count = *trsbas;
    trsbas++;
    trsptr = (TileMapEntry*)trsbas;
    x = y = 0.0f;
    flip = flptbl[wk->cg_flip ^ wk->rl_flag];
    palo = wk->colcd;

    if (wk->my_bright_type) {
        curr_bright = bright_type[wk->my_bright_type - 1][wk->my_bright_level];
    } else {
        curr_bright = 0xFFFFFF;
    }

    mlt_obj_matrix(wk, base_y);
    cc.parts.group = 0;
    cc.parts.offset = wk->cg_number;
    ix = check_patcash_ex_trans(mt->cpat, cc.code);

    if (ix < 0) {
        {
            s32 size;
            s32 code;
            s32 wh;
            s32 dw;
            s32 dh;
            s32 attr;
            s32 palt;

            (void)dw;
            (void)dh;

            ix = get_free_patcash_index(mt->cpat);
            cp = &mt->cpat->patt[ix];
            mt->cpat->adr[mt->cpat->kazu] = cp;
            mt->cpat->kazu += 1;
            cp->curr_disp = 1;
            cp->time = mt->mltcshtime16;
            cp->cg.code = cc.code;
            cp->x16 = 0;
            cp->x32 = 0;
            work_init_zero((s32*)&cp->map, sizeof(PatternMap));
            cc.parts.group = i;

            while (count--) {
                if (flip & 0x8000) {
                    x += trsptr->x;
                } else {
                    x -= trsptr->x;
                }

                if (flip & 0x4000) {
                    y -= trsptr->y;
                } else {
                    y += trsptr->y;
                }

                texptr = (TEX*)((uintptr_t)textbl + ((u32*)textbl)[trsptr->code]);
                dw = (texptr->wh & 0xE0) >> 2;
                dh = (texptr->wh & 0x1C) * 2;
                wh = (texptr->wh & 3) + 1;
                size = (wh * wh) << 6;
                attr = trsptr->attr;
                palt = (attr & 0x1FF) + palo;
                attr = (attr ^ flip) & 0xC000;
                cc.parts.offset = trsptr->code;

                switch (wh) {
                case 1:
                case 2:
                    if (get_mltbuf16_ext_2(mt, cc.code, 0, &code, cp) != 0) {
                        lz_ext_p6_fx(&((u8*)texptr)[1], mt->mltbuf, size);
                        njReLoadTexturePartNumG(mt->mltgidx16 + (code >> 8), (s8*)mt->mltbuf, code & 0xFF, size);
                    }


                    rnum = seqsStoreChip(x - (dw * BOOL(flip & 0x8000)),
                                         y + (dh * BOOL(flip & 0x4000)),
                                         dw,
                                         dh,
                                         mt->mltgidx16,
                                         code,
                                         attr | palt,
                                         wk->my_clear_level,
                                         mt->id);
                    break;

                case 4:
                    if (get_mltbuf32_ext_2(mt, cc.code, 0, &code, cp) != 0) {
                        lz_ext_p6_fx(&((u8*)texptr)[1], mt->mltbuf, size);
                        njReLoadTexturePartNumG(mt->mltgidx32 + (code >> 6), (s8*)mt->mltbuf, code & 0x3F, size);
                    }


                    rnum = seqsStoreChip(x - (dw * BOOL(flip & 0x8000)),
                                         y + (dh * BOOL(flip & 0x4000)),
                                         dw,
                                         dh,
                                         mt->mltgidx32,
                                         code,
                                         (attr | 0x2000) | palt,
                                         wk->my_clear_level,
                                         mt->id);
                    break;
                }

                if (rnum == 0) {
                    break;
                }

                trsptr++;
            }

            seqs_w.up[mt->id] = 1;
            appRenewTempPriority(wk->position_z);
        }

        return;
    }

    {
        s32 size;
        s32 code;
        s32 wh;
        s32 dw;
        s32 dh;
        s32 attr;
        s32 palt;

        (void)dw;
        (void)dh;

        cp = mt->cpat->adr[ix];
        cp->curr_disp = 1;
        cp->time = mt->mltcshtime16;
        makeup_tpu_free(mt->mltnum16 / 256, mt->mltnum32 / 64, &cp->map);
        cc.parts.group = i;

        while (count--) {
            if (flip & 0x8000) {
                x += trsptr->x;
            } else {
                x -= trsptr->x;
            }

            if (flip & 0x4000) {
                y -= trsptr->y;
            } else {
                y += trsptr->y;
            }

            texptr = (TEX*)((uintptr_t)textbl + ((u32*)textbl)[trsptr->code]);
            dw = (texptr->wh & 0xE0) >> 2;
            dh = (texptr->wh & 0x1C) * 2;
            wh = (texptr->wh & 3) + 1;
            size = (wh * wh) << 6;
            attr = trsptr->attr;
            palt = (attr & 0x1FF) + palo;
            attr = (attr ^ flip) & 0xC000;
            cc.parts.offset = trsptr->code;

            switch (wh) {
            case 1:
            case 2:
                code = get_mltbuf16_ext(mt, cc.code, 0);


                rnum = seqsStoreChip(x - (dw * BOOL(flip & 0x8000)),
                                     y + (dh * BOOL(flip & 0x4000)),
                                     dw,
                                     dh,
                                     mt->mltgidx16,
                                     code,
                                     attr | palt,
                                     wk->my_clear_level,
                                     mt->id);
                break;

            case 4:
                code = get_mltbuf32_ext(mt, cc.code, 0);


                rnum = seqsStoreChip(x - (dw * BOOL(flip & 0x8000)),
                                     y + (dh * BOOL(flip & 0x4000)),
                                     dw,
                                     dh,
                                     mt->mltgidx32,
                                     code,
                                     (attr | 0x2000) | palt,
                                     wk->my_clear_level,
                                     mt->id);
                break;
            }

            if (rnum == 0) {
                break;
            }

            trsptr++;
        }

        seqs_w.up[mt->id] = 1;
        appRenewTempPriority(wk->position_z);
    }
}

/* On bad data the Xbox returns; it does not log and hang. It draws no DebugLine boxes. */
void mlt_obj_trans_cp3(MultiTexture* mt, WORK* wk, s32 base_y) {
    u32* textbl;
    u16* trsbas;
    TileMapEntry* trsptr;
    TEX* texptr;
    s32 rnum;
    s32 flip;
    s32 count;
    s32 palo;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    PatternCode cc;
    s32 size;
    s32 code;
    s32 wh;
    s32 dw;
    s32 dh;
    s32 attr;
    s32 palt;

    ppgSetupCurrentDataList(&mt->texList);

    if (mt->ext) {
        mlt_obj_trans_cp3_ext(mt, wk, base_y);
        return;
    }

    n = wk->cg_number;
    i = obj_group_table[n];

    if (i == 0) {
        return;
    }

    if (texgrplds[i].ok == 0) {
        // The trans data is not valid. Group number: %d\n
        return;
    }

    n -= texgrpdat[i].num_of_1st;
    trsbas = (u16*)(texgrplds[i].trans_table + ((u32*)texgrplds[i].trans_table)[n]);
    textbl = (u32*)texgrplds[i].texture_table;
    count = *trsbas;
    trsbas++;
    trsptr = (TileMapEntry*)trsbas;
    x = y = 0.0f;
    flip = flptbl[wk->cg_flip ^ wk->rl_flag];
    palo = wk->colcd;

    if (wk->my_bright_type) {
        curr_bright = bright_type[wk->my_bright_type - 1][wk->my_bright_level];
    } else {
        curr_bright = 0xFFFFFF;
    }

    mlt_obj_matrix(wk, base_y);
    cc.parts.group = i;

    while (count--) {
        if (flip & 0x8000) {
            x += trsptr->x;
        } else {
            x -= trsptr->x;
        }

        if (flip & 0x4000) {
            y -= trsptr->y;
        } else {
            y += trsptr->y;
        }

        texptr = (TEX*)((uintptr_t)textbl + ((u32*)textbl)[trsptr->code]);
        dw = (s32)(texptr->wh & 0xE0) >> 2;
        dh = (texptr->wh & 0x1C) * 2;
        wh = (texptr->wh & 3) + 1;
        size = (wh * wh) << 6;
        attr = trsptr->attr;
        palt = (attr & 0x1FF) + palo;
        attr = (attr ^ flip) & 0xC000;
        cc.parts.offset = trsptr->code;

        switch (wh) {
        case 1:
        case 2:
            if (get_mltbuf16(mt, cc.code, 0, &code) != 0) {
                lz_ext_p6_fx(&((u8*)texptr)[1], mt->mltbuf, size);
                njReLoadTexturePartNumG(mt->mltgidx16 + (code >> 8), (s8*)mt->mltbuf, code & 0xFF, size);
            }


            rnum = seqsStoreChip(x - (dw * BOOL(flip & 0x8000)),
                                 y + (dh * BOOL(flip & 0x4000)),
                                 dw,
                                 dh,
                                 mt->mltgidx16,
                                 code,
                                 attr | palt,
                                 wk->my_clear_level,
                                 mt->id);
            break;

        case 4:
            if (get_mltbuf32(mt, cc.code, 0, &code) != 0) {
                lz_ext_p6_fx(&((u8*)texptr)[1], mt->mltbuf, size);
                njReLoadTexturePartNumG(mt->mltgidx32 + (code >> 6), (s8*)mt->mltbuf, code & 0x3F, size);
            }


            rnum = seqsStoreChip(x - (dw * BOOL(flip & 0x8000)),
                                 y + (dh * BOOL(flip & 0x4000)),
                                 dw,
                                 dh,
                                 mt->mltgidx32,
                                 code,
                                 attr | 0x2000 | palt,
                                 wk->my_clear_level,
                                 mt->id);
            break;
        }

        if (rnum == 0) {
            break;
        }

        trsptr++;
    }

    seqs_w.up[mt->id] = 1;
    appRenewTempPriority(wk->position_z);
}

/* On bad data the Xbox returns; it does not log and hang. It draws no DebugLine boxes. */
void mlt_obj_trans_rgb_ext(MultiTexture* mt, WORK* wk, s32 base_y) {
    u32* textbl;
    u16* trsbas;
    TileMapEntry* trsptr;
    TEX* texptr;
    s32 rnum;
    s32 flip;
    s32 palo;
    s32 count;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    s16 ix;
    PatternCode cc;
    PatternInstance* cp;

    (void)textbl;

    n = wk->cg_number;
    i = obj_group_table[n];

    if (i == 0) {
        return;
    }

    if (texgrplds[i].ok == 0) {
        // The trans data is not valid. Group number: %d\n
        return;
    }

    n -= texgrpdat[i].num_of_1st;
    trsbas = (u16*)(texgrplds[i].trans_table + ((u32*)texgrplds[i].trans_table)[n]);
    textbl = (u32*)texgrplds[i].texture_table;
    count = *trsbas;
    trsbas++;
    trsptr = (TileMapEntry*)trsbas;
    x = y = 0.0f;
    flip = flptbl[wk->cg_flip ^ wk->rl_flag];
    palo = wk->colcd;

    if (wk->my_bright_type) {
        curr_bright = bright_type[wk->my_bright_type - 1][wk->my_bright_level];
    } else {
        curr_bright = 0xFFFFFF;
    }

    mlt_obj_matrix(wk, base_y);
    cc.parts.group = wk->colcd;
    cc.parts.offset = wk->cg_number;
    ix = check_patcash_ex_trans(mt->cpat, cc.code);

    if (ix < 0) {
        {
            s32 size;
            s32 code;
            s32 attr;
            s32 palt;
            s32 wh;
            s32 dw;
            s32 dh;

            ix = get_free_patcash_index(mt->cpat);
            cp = &mt->cpat->patt[ix];
            mt->cpat->adr[mt->cpat->kazu] = cp;
            mt->cpat->kazu += 1;
            cp->curr_disp = 1;
            cp->time = mt->mltcshtime16;
            cp->cg.code = cc.code;
            cp->x16 = 0;
            cp->x32 = 0;
            work_init_zero((s32*)&cp->map, sizeof(PatternMap));
            cc.parts.group = i;

            while (count--) {
                if (flip & 0x8000) {
                    x += trsptr->x;
                } else {
                    x -= trsptr->x;
                }

                if (flip & 0x4000) {
                    y -= trsptr->y;
                } else {
                    y += trsptr->y;
                }

                texptr = (TEX*)((uintptr_t)textbl + ((u32*)textbl)[trsptr->code]);
                dw = (texptr->wh & 0xE0) >> 2;
                dh = (texptr->wh & 0x1C) * 2;
                wh = (texptr->wh & 3) + 1;
                size = (wh * wh) << 6;
                attr = trsptr->attr;
                palt = (attr & 0x1FF) + palo;
                attr = (attr ^ flip) & 0xC000;
                cc.parts.offset = trsptr->code;

                switch (wh) {
                case 1:
                case 2:
                    if (get_mltbuf16_ext_2(mt, cc.code, palt, &code, cp) != 0) {
                        lz_ext_p6_cx(&((u8*)texptr)[1], (u16*)mt->mltbuf, size, (u16*)(ColorRAM[palt]));
                        njReLoadTexturePartNumG(mt->mltgidx16 + (code >> 8), (s8*)mt->mltbuf, code & 0xFF, size * 2);
                    }

                    rnum = seqsStoreChip(x - (dw * BOOL(flip & 0x8000)),
                                         y + (dh * BOOL(flip & 0x4000)),
                                         dw,
                                         dh,
                                         mt->mltgidx16,
                                         code,
                                         attr,
                                         wk->my_clear_level,
                                         mt->id);
                    break;

                case 4:
                    if (get_mltbuf32_ext_2(mt, cc.code, palt, &code, cp) != 0) {
                        lz_ext_p6_cx(&((u8*)texptr)[1], (u16*)mt->mltbuf, size, (u16*)(ColorRAM[palt]));
                        njReLoadTexturePartNumG(mt->mltgidx32 + (code >> 6), (s8*)mt->mltbuf, code & 0x3F, size * 2);
                    }

                    rnum = seqsStoreChip(x - (dw * BOOL(flip & 0x8000)),
                                         y + (dh * BOOL(flip & 0x4000)),
                                         dw,
                                         dh,
                                         mt->mltgidx32,
                                         code,
                                         attr | 0x2000,
                                         wk->my_clear_level,
                                         mt->id);
                    break;
                }

                if (rnum == 0) {
                    break;
                }

                trsptr++;
            }

            seqs_w.up[mt->id] = 1;
            appRenewTempPriority(wk->position_z);
        }

        return;
    }

    {
        s32 size;
        s32 code;
        s32 attr;
        s32 palt;
        s32 wh;
        s32 dw;
        s32 dh;

        cp = mt->cpat->adr[ix];
        cp->curr_disp = 1;
        cp->time = mt->mltcshtime16;
        makeup_tpu_free(mt->mltnum16 / 256, mt->mltnum32 / 64, &cp->map);
        cc.parts.group = i;

        while (count--) {
            if (flip & 0x8000) {
                x += trsptr->x;
            } else {
                x -= trsptr->x;
            }

            if (flip & 0x4000) {
                y -= trsptr->y;
            } else {
                y += trsptr->y;
            }

            texptr = (TEX*)((uintptr_t)textbl + ((u32*)textbl)[trsptr->code]);
            dw = (texptr->wh & 0xE0) >> 2;
            dh = (texptr->wh & 0x1C) * 2;
            wh = (texptr->wh & 3) + 1;
            size = (wh * wh) << 6;
            attr = trsptr->attr;
            palt = (attr & 0x1FF) + palo;
            attr = (attr ^ flip) & 0xC000;
            cc.parts.offset = trsptr->code;

            switch (wh) {
            case 1:
            case 2:
                code = get_mltbuf16_ext(mt, cc.code, palt);

                rnum = seqsStoreChip(x - (dw * BOOL(flip & 0x8000)),
                                     y + (dh * BOOL(flip & 0x4000)),
                                     dw,
                                     dh,
                                     mt->mltgidx16,
                                     code,
                                     attr,
                                     wk->my_clear_level,
                                     mt->id);
                break;

            case 4:
                code = get_mltbuf32_ext(mt, cc.code, palt);

                rnum = seqsStoreChip(x - (dw * BOOL(flip & 0x8000)),
                                     y + (dh * BOOL(flip & 0x4000)),
                                     dw,
                                     dh,
                                     mt->mltgidx32,
                                     code,
                                     attr | 0x2000,
                                     wk->my_clear_level,
                                     mt->id);
                break;
            }

            if (rnum == 0) {
                break;
            }

            trsptr++;
        }

        seqs_w.up[mt->id] = 1;
        appRenewTempPriority(wk->position_z);
    }
}

/* On bad data the Xbox returns; it does not log and hang. It draws no DebugLine boxes. */
void mlt_obj_trans_rgb(MultiTexture* mt, WORK* wk, s32 base_y) {
    u32* textbl;
    u16* trsbas;
    TileMapEntry* trsptr;
    TEX* texptr;
    s32 rnum;
    s32 flip;
    s32 palo;
    s32 count;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    PatternCode cc;
    s32 size;
    s32 code;
    s32 attr;
    s32 palt;
    s32 wh;
    s32 dw;
    s32 dh;

    ppgSetupCurrentDataList(&mt->texList);

    if (mt->ext) {
        mlt_obj_trans_rgb_ext(mt, wk, base_y);
        return;
    }

    n = wk->cg_number;
    i = obj_group_table[n];

    if (i == 0) {
        return;
    }

    if (texgrplds[i].ok == 0) {
        // The trans data is not valid. Group number: %d\n
        return;
    }

    n -= texgrpdat[i].num_of_1st;
    trsbas = (u16*)(texgrplds[i].trans_table + ((u32*)texgrplds[i].trans_table)[n]);
    textbl = (u32*)texgrplds[i].texture_table;
    count = *trsbas;
    trsbas++;
    trsptr = (TileMapEntry*)trsbas;
    x = y = 0.0f;
    flip = flptbl[wk->cg_flip ^ wk->rl_flag];
    palo = wk->colcd;

    if (wk->my_bright_type) {
        curr_bright = bright_type[wk->my_bright_type - 1][wk->my_bright_level];
    } else {
        curr_bright = 0xFFFFFF;
    }

    mlt_obj_matrix(wk, base_y);
    cc.parts.group = i;

    while (count--) {
        if (flip & 0x8000) {
            x += trsptr->x;
        } else {
            x -= trsptr->x;
        }

        if (flip & 0x4000) {
            y -= trsptr->y;
        } else {
            y += trsptr->y;
        }

        texptr = (TEX*)((uintptr_t)textbl + ((u32*)textbl)[trsptr->code]);
        dw = (texptr->wh & 0xE0) >> 2;
        dh = (texptr->wh & 0x1C) * 2;
        wh = (texptr->wh & 3) + 1;
        size = (wh * wh) << 6;
        attr = trsptr->attr;
        palt = (attr & 0x1FF) + palo;
        attr = (attr ^ flip) & 0xC000;
        cc.parts.offset = trsptr->code;

        switch (wh) {
        case 1:
        case 2:
            if (get_mltbuf16(mt, cc.code, palt, &code) != 0) {
                lz_ext_p6_cx(&((u8*)texptr)[1], (u16*)mt->mltbuf, size, (u16*)(ColorRAM[palt]));
                njReLoadTexturePartNumG(mt->mltgidx16 + (code >> 8), (s8*)mt->mltbuf, code & 0xFF, size * 2);
            }

            rnum = seqsStoreChip(x - (dw * BOOL(flip & 0x8000)),
                                 y + (dh * BOOL(flip & 0x4000)),
                                 dw,
                                 dh,
                                 mt->mltgidx16,
                                 code,
                                 attr,
                                 wk->my_clear_level,
                                 mt->id);
            break;

        case 4:
            if (get_mltbuf32(mt, cc.code, palt, &code) != 0) {
                lz_ext_p6_cx(&((u8*)texptr)[1], (u16*)mt->mltbuf, size, (u16*)(ColorRAM[palt]));
                njReLoadTexturePartNumG(mt->mltgidx32 + (code >> 6), (s8*)mt->mltbuf, code & 0x3F, size * 2);
            }

            rnum = seqsStoreChip(x - (dw * BOOL(flip & 0x8000)),
                                 y + (dh * BOOL(flip & 0x4000)),
                                 dw,
                                 dh,
                                 mt->mltgidx32,
                                 code,
                                 attr | 0x2000,
                                 wk->my_clear_level,
                                 mt->id);
            break;
        }

        if (rnum == 0) {
            break;
        }

        trsptr++;
    }

    seqs_w.up[mt->id] = 1;
    appRenewTempPriority(wk->position_z);
}

/* Xbox: no Debug_w checks; each changed texture is renewed with
   ppgRenewTexChunkSeqs. keep != val is val != keep. */
void seqsAfterProcess() {
    s32 i;
    u32 keep = 0;
    u32 val = 0;

    if (seqs_w.sprTotal != 0) {
        for (i = 0; i < 24; i++) {
            if (seqs_w.up[i] && ppgRenewTexChunkSeqs(mts[i].texList.tex) == 0) {
                seqs_w.up[i] = 0;
            }
        }

        if (seqs_w.sprMax < seqs_w.sprTotal) {
            seqs_w.sprMax = seqs_w.sprTotal;
        }

        ps2SeqsRenderQuadInit_A();

        for (i = 0; i < seqs_w.sprTotal; i++) {
            if (seqs_w.up[seqs_w.chip[i].id]) {
                val = seqs_w.chip[i].texCode;

                if (val != keep) {
                    keep = val;
                    flSetRenderState(FLRENDER_TEXSTAGE0, val);
                }

                ps2SeqsRenderQuad_Ax(&seqs_w.chip[i]);
            }
        }

        ps2SeqsRenderQuadEnd();
    }
}

void njDrawPolygon2D(PAL_CURSOR* p, s32 n, f32 pri, u32 attr, s32 flag);


/* Xbox: the polygon is type 2, and the far corner is the double sum,
   rounded once (PS2 rounds each argument to float first). */
void draw_box(f64 arg0, f64 arg1, f64 arg2, f64 arg3, u32 col, u32 attr, s16 prio) {
    Vec3 point[2];
    PAL_CURSOR line;
    PAL_CURSOR_P xy[4];
    PAL_CURSOR_COL cc[4];

    point[0].x = arg0;
    point[0].y = arg1;
    point[0].z = 0.0f;
    point[1].x = arg0 + arg2;
    point[1].y = arg1 + arg3;
    point[1].z = 0.0f;
    njCalcPoints(NULL, point, point, 2);
    line.p = xy;
    line.col = cc;
    line.tex = NULL;
    line.num = 4;
    line.p[0].x = line.p[2].x = point[0].x;
    line.p[1].x = line.p[3].x = point[1].x;
    line.p[0].y = line.p[1].y = point[0].y;
    line.p[2].y = line.p[3].y = point[1].y;
    line.col[0].color = line.col[1].color = line.col[2].color = line.col[3].color = col;
    njDrawPolygon2D(&line, 4, PrioBase[prio], attr, 2);
    appRenewTempPriority(prio);
}
