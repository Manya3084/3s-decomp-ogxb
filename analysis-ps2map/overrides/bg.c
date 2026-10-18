/* Notes from the hand port this file replaced:
 * Zoomf_Init 0xAF2BA size 0x37, interior after the ret.
 * Zoom_Value_Set 0xAF2F1 size 0x75, interior after the ret.
 * Frame_Adgjust 0xAF366 size 0x96, interior after the ret.
 * Scrn_Pos_Init 0xAF3FC size 0x40, interior after the ret.
 * Scrn_Move_Set 0xAF43C size 0x23, interior after the ret.
 * Family_Init 0xAF45F size 0x1C, interior after the ret.
 * Scrn_Renew 0xAF4DC size 0xD, interior after the ret.
 * Irl_Family 0xAF4E9 size 0x37, interior after the ret.
 * Irl_Scrn 0xAF520 size 0x69, interior after the ret.
 * Frame_Up 0xAFAE3 size 0x43, interior after the ret.
 * Frame_Down 0xAFB26 size 0x43, interior after the ret.
 * scr_calc 0xAF086 size 0xE0, interior after the ret.
 * scr_calc2 0xAF166 size 0xE0, interior after the ret.
 * Pause_Family_On 0xAF246 size 0x74, interior after the ret.
 * Family_Move 0xAF589 size 0x38, a scanned start.
 * Ending_Family_Move 0xAF5C1 size 0x40, a scanned start.
 * Bg_Disp_Switch 0xAF601 size 0xA, interior after the ret.
 *
 * zoom_add is the word at 0x7BC4A6. scr_sc is the float at 0x7C55F4.
 * sca_x is the dword at 0x7C55F0 and sca_y is the dword at 0x7C584C.
 * scrn_adgjust_x is the word at 0x7BC51E. scrn_adgjust_y is the word at
 * 0x7BC4EA. bg_pos is 0x7C5BA0 and fm_pos is 0x7C5620, eight entries of
 * 0x10 bytes. bg_prm is 0x7C5960 and end_prm is 0x7BC960, stride 4.
 * Screen_Switch is the word at 0x7BC988. Screen_Switch_Buffer is the word
 * at 0x7BC98A. 1.0f is 0x2190AC and 64.0f is 0x2193F0. Frame_Down's clamp
 * constant is 0x273F44.
 *
 * Frame_Adgjust's >= 0x40 path multiplies in 32 bits, shifts, masks with
 * 0xFFFF01FF, negates, and stores the low word. The < 0x40 path masks with
 * 0x1FF. The stored word matches the PS2 u16 product. Frame_Up and
 * Frame_Down are the only callers. Irl_Scrn does not emit the PS2 statements
 * that only name a shift. 0xAF47B is both Family_Set_R and Family_Set_W.
 * 0xAF4AA is both Bg_On_R and Bg_On_W. 0xAF4C2 is both Bg_Off_R and Bg_Off_W.
 * Those three stay unnamed.
 *
 * scr_calc reads bg_prm. scr_calc2 reads end_prm[bgnm + 1]. Both store
 * BgMATRIX[bgnm + 1]. BgMATRIX is 0x795D00 and each entry is 0x40 bytes, so
 * index 1 is 0x795D40 and index 8 is 0x795F00. -1.0f is 0x2190D4. 224.0f is
 * 0x2497E4. use_family is 0x273F90 and matches the 22 PS2 bytes. bg_w.stage
 * is the byte at 0x7BC523. ending_use_family is 0x288C10 and matches the 20
 * PS2 bytes. end_w.type is the word at 0x7AABF6. bg_disp_off is the byte at
 * 0x7BC982. The matrix calls stay unnamed. Family_Move and
 * Ending_Family_Move do not keep the unused assign from the PS2 for-loop.
 * Bg_Texture_Load_Ending is 0xAE974 size 0x321 and is a scanned start.
 * It prints the ending tag, copies ending_map_tbl into scr_bcm, and loads
 * through load_it_use_any_key2. Cases 14, 15, and 19 store tokusyu_stage 5, 6, and
 * 7. bgRWWorkUpdate is 0xAEC95 size 0x4E and bgAkebonoDraw is 0xAECE3 size
 * 0xD5. Both are interior. ppgCalScrPosition is 0xAEDB8 size 0x142 and is a
 * scanned start. Its UVs are the cell offset divided by 128, with no 0.5
 * bias. y, xs, and ys arrive in ebx, edi, and esi. bgDrawOneChip is 0xAFA5B
 * size 0x88 and is a scanned start. rw_dat is 0x7BC9A4. Each entry is 0x14
 * bytes, with rw_cnt at +8 and gbix at +0xC. rw_num is the byte at
 * 0x7BCC45. scrDrawPos is 0x7BCB40. bg_priority is 0x7BC990. tokusyu_stage
 * is the byte at 0x7BCC44. gouki_end_gbix is 0x7BCC50. ending_flag is the
 * byte at 0x7BC981. ppgBgList is 0x7A7E60, ppgRwBgList is 0x7A7E38, and
 * ppgAkeList is 0x7A8060. 0xAE547 and 0xAE7DB are Bg_TexInit and
 * Ed_Kakikae_Set.
 */

void scr_calc(u8 bgnm) {
    njUnitMatrix((void *)0);
    njScale((void *)0, Frame_Zoom_X, Frame_Zoom_Y, 1.0f);
    njScale((void *)0, scr_sc, scr_sc, 1.0f);
    njTranslate((void *)0, 0.0f, 224.0f, 0.0f);
    njScale((void *)0, 1.0f, -1.0f, 1.0f);
    njTranslate((void *)0,
        (f32)(s16)-bg_prm[bgnm].bg_h_shift,
        (f32)(s16)-bg_prm[bgnm].bg_v_shift,
        0.0f);
    njGetMatrix(&BgMATRIX[bgnm + 1]);
}

void scr_calc2(u8 bgnm) {
    njUnitMatrix((void *)0);
    njScale((void *)0, Frame_Zoom_X, Frame_Zoom_Y, 1.0f);
    njScale((void *)0, scr_sc, scr_sc, 1.0f);
    njTranslate((void *)0, 0.0f, 224.0f, 0.0f);
    njScale((void *)0, 1.0f, -1.0f, 1.0f);
    njTranslate((void *)0,
        (f32)(s16)-end_prm[bgnm + 1].bg_h_shift,
        (f32)(s16)-end_prm[bgnm + 1].bg_v_shift,
        0.0f);
    njGetMatrix(&BgMATRIX[bgnm + 1]);
}

void Pause_Family_On(void) {
    njUnitMatrix((void *)0);
    njScale((void *)0, Frame_Zoom_X, Frame_Zoom_Y, 1.0f);
    njTranslate((void *)0, 0.0f, 224.0f, 0.0f);
    njScale((void *)0, 1.0f, -1.0f, 1.0f);
    njGetMatrix(&BgMATRIX[8]);
}

void Zoomf_Init(void) {
    zoom_add = 64;
    scr_sc = 1.0f;
    sca_x = 0;
    sca_y = 1023;
    scrn_adgjust_x = 0;
    scrn_adgjust_y = 0;
}

void Zoom_Value_Set(u16 zadd) {
    f32 work;
    u16 add;

    if (zadd < 0x40) {
        scr_sc = 64.0f / zadd;
        return;
    }

    if (zadd == 0x40) {
        scr_sc = 1.0f;
        return;
    }

    add = (u16)(zadd & 0x3F);
    work = 1.0f / (64.0f / add);
    add = (u16)(zadd & 0xFFC0);
    add >>= 6;
    scr_sc = 1.0f / (add + work);
}

void Frame_Adgjust(u16 pos_x, u16 pos_y) {
    u16 buff;

    if (zoom_add >= 0x40) {
        buff = (u16)(zoom_add - 0x40);
        buff = (u16)(buff * pos_x);
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_x = (s16)-buff;
    } else {
        buff = (u16)(0x40 - zoom_add);
        buff = (u16)(buff * pos_x);
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_x = (s16)buff;
    }

    if (zoom_add >= 0x40) {
        buff = (u16)(zoom_add - 0x40);
        buff = (u16)(buff * (pos_y + 0x15));
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_y = (s16)-buff;

        if (scrn_adgjust_y == -0x14) {
            scrn_adgjust_y = (s16)(scrn_adgjust_y + 1);
        }
    } else {
        buff = (u16)(0x40 - zoom_add);
        buff = (u16)(buff * (pos_y + 0x15));
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_y = (s16)buff;

        if (scrn_adgjust_y == -0x14) {
            scrn_adgjust_y = (s16)(scrn_adgjust_y + 1);
        }
    }
}

/* <= 1, as retail compares. */
void Frame_Up(u16 x, u16 y, u16 add) {
    if (zoom_add <= 1) {
        scr_sc = 64.0f;
        return;
    }

    zoom_add = (u16)(zoom_add - add);
    Zoom_Value_Set(zoom_add);
    Frame_Adgjust(x, y);
}

void Frame_Down(u16 x, u16 y, u16 add) {
    if (zoom_add >= 0xFFC0) {
        scr_sc = 0.0009775171f;
        return;
    }

    zoom_add = (u16)(zoom_add + add);
    Zoom_Value_Set(zoom_add);
    Frame_Adgjust(x, y);
}

void Scrn_Pos_Init(void) {
    u8 i;

    for (i = 0; i < 8; i++) {
        bg_pos[i].scr_x.long_pos = 0;
        bg_pos[i].scr_x_buff.long_pos = 0;
        bg_pos[i].scr_y.long_pos = 0;
        bg_pos[i].scr_y_buff.long_pos = 0;
        bg_prm[i].bg_h_shift = 0;
        bg_prm[i].bg_v_shift = 0;
        end_prm[i].bg_h_shift = 0;
        end_prm[i].bg_v_shift = 0;
    }
}

void Scrn_Move_Set(s8 bgnm, s16 x, s16 y) {
    bg_pos[bgnm].scr_x.word_pos.h = x;
    bg_pos[bgnm].scr_y.word_pos.h = (s16)(y + 16);
}

void Family_Init(void) {
    u8 i;

    for (i = 0; i < 8; i++) {
        fm_pos[i].scr_x.long_pos = 0;
        fm_pos[i].scr_y.long_pos = 0;
        fm_pos[i].scr_x_buff.long_pos = 0;
        fm_pos[i].scr_y_buff.long_pos = 0;
    }
}

void Scrn_Renew(void) {
    Screen_Switch_Buffer = Screen_Switch;
}

void Irl_Family(void) {
    u8 i;

    for (i = 0; i < 8; i++) {
        fm_pos[i].scr_x_buff.long_pos = fm_pos[i].scr_x.long_pos;
        fm_pos[i].scr_y_buff.long_pos = fm_pos[i].scr_y.long_pos;
        bg_pos[i].scr_x_buff.long_pos = bg_pos[i].scr_x.long_pos;
        bg_pos[i].scr_y_buff.long_pos = bg_pos[i].scr_y.long_pos;
    }
}

void Irl_Scrn(void) {
    s8 i;

    for (i = 0; i < 8; i++) {
        bg_prm[i].bg_h_shift = (u16)(scrn_adgjust_x + bg_pos[i].scr_x_buff.word_pos.h);
        end_prm[i].bg_h_shift = (u16)(scrn_adgjust_x + fm_pos[i].scr_x_buff.word_pos.h);
        bg_prm[i].bg_v_shift = (u16)(bg_pos[i].scr_y_buff.word_pos.h - scrn_adgjust_y);
        end_prm[i].bg_v_shift = (u16)(fm_pos[i].scr_y_buff.word_pos.h - scrn_adgjust_y);
    }
}

/* The mask shifts after the index increments. */
void Family_Move(void) {
    u8 fam_ix;
    u8 i;
    u8 mask;

    fam_ix = use_family[bg_w.stage];
    mask = 0x80;

    for (i = 0; i < 8; i++, mask >>= 1) {
        if (fam_ix & mask) {
            scr_calc(i);
        }
    }
}

/* The mask shifts after the index increments. */
void Ending_Family_Move(void) {
    u8 mask_val;
    u8 i;
    u8 mask;

    mask_val = ending_use_family[end_w.type];
    mask = 0x80;

    for (i = 0; i < 8; i++, mask >>= 1) {
        if (mask_val & mask) {
            scr_calc2(i);
        }
    }

    scr_calc(3);
}

void Bg_Disp_Switch(u8 on_off) {
    bg_disp_off = on_off;
}

void Bg_Texture_Load_Ending(s16 type) {
    void *loadAdrs;
    u32 loadSize;
    s32 accnum;
    u32 tgbix[2];
    u32 prio;
    u32 mask;
    u32 pmask;
    s16 key1;
    u8 i;
    u8 j;
    u8 k;
    u8 x;
    u8 shift;

    sub_0004384A("\nENDING\n\n");
    rw_num = 0;
    Bg_TexInit();
    ending_flag = 1;

    for (i = 0; i < end_use_real_scr[type]; i++) {
        scr_bcm[i] = ending_map_tbl[type][i];
    }

    loadSize = load_it_use_any_key2(bgtex_ending_file[type], &loadAdrs, &key1, 2, 0);
    pmask = 0xFF000000;
    shift = 0x18;

    for (j = 0; j < 4; j++) {
        prio = ending_priority[0];
        prio &= pmask;
        prio >>= shift;
        bg_priority[j] = (u8)prio;
        shift = (u8)(shift - 8);
        pmask >>= 8;
    }

    accnum = 0;

    for (j = 0; j < bg_w.scrno; j++) {
        tgbix[0] = bgtex_ending_gbix[type][j * 2];
        tgbix[1] = bgtex_ending_gbix[type][(j * 2) + 1];
        mask = 0x80000000;
        ppgSetupCurrentDataList(&ppgBgList[j]);
        ppgSetupTexChunk_1st((void *)0, loadAdrs, loadSize, (j * 64) + 100, 64, 0, 0);
        ppgSetupTexChunk_1st_Accnum((void *)0, (u16)accnum);

        for (k = 0; k < 2; k++) {
            for (i = 0; i < 32; i++) {
                if (mask & tgbix[k]) {
                    accnum = ppgSetupTexChunk_2nd((void *)0, i + ((j * 64) + 100 + (k * 32)));
                    ppgSetupTexChunk_3rd((void *)0, i + ((j * 64) + 100 + (k * 32)), 1);
                }

                mask >>= 1;
            }

            mask = 0x80000000;
        }
    }

    x = ending_rewrite_scr[type];

    if (x != 0) {
        ppgSetupCurrentDataList(&ppgRwBgList);
        ppgSetupTexChunk_1st((void *)0, loadAdrs, loadSize, (j * 64) + 100, x, 0, 0);
        ppgSetupTexChunk_1st_Accnum((void *)0, (u16)accnum);

        for (i = 0; i < x; i++) {
            accnum = ppgSetupTexChunk_2nd((void *)0, i + ((j * 64) + 100));
            ppgSetupTexChunk_3rd((void *)0, i + ((j * 64) + 100), 1);
        }
    }

    switch (type) {
    case 14:
        tokusyu_stage = 5;

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                gouki_end_gbix[j + (i * 4)] = (u8)(j + ((i * 8) + 100));
            }
        }

        ppgSetupCurrentDataList(&ppgAkeList);
        ppgSetupPalChunk((void *)0, loadAdrs, loadSize, 0, 0, 1);
        ppgSetupTexChunk_1st((void *)0, loadAdrs, loadSize, 0x1A0, 0x18, 0, 0);
        ppgSetupTexChunk_1st_Accnum((void *)0, (u16)accnum);

        for (i = 0; i < 0x18; i++) {
            accnum = ppgSetupTexChunk_2nd((void *)0, i + 0x1A0);
            ppgSetupTexChunk_3rd((void *)0, i + 0x1A0, 1);
        }

        break;

    case 15:
        tokusyu_stage = 6;
        break;

    case 19:
        tokusyu_stage = 7;
        ppgSetupCurrentDataList(&ppgAkeList);
        ppgSetupPalChunk((void *)0, loadAdrs, loadSize, 0, 0, 1);
        ppgSetupTexChunk_1st((void *)0, loadAdrs, loadSize, 0xE4, 1, 0, 0);
        ppgSetupTexChunk_1st_Accnum((void *)0, (u16)accnum);
        accnum = ppgSetupTexChunk_2nd((void *)0, 0xE4);
        ppgSetupTexChunk_3rd((void *)0, 0xE4, 1);
        break;

    default:
        tokusyu_stage = 7;
        break;
    }

    sub_00097103(key1);
    Ed_Kakikae_Set(type);
    ppgSourceDataReleased(&ppgBgList[0]);
    ppgSourceDataReleased(&ppgBgList[1]);
    ppgSourceDataReleased(&ppgBgList[2]);
    ppgSourceDataReleased(&ppgRwBgList);
    ppgSourceDataReleased(&ppgAkeList);
}

void bgRWWorkUpdate(void) {
    s32 i;

    for (i = 0; i < rw_num; i++) {
        rw_dat[i].rw_cnt--;

        if (rw_dat[i].rw_cnt == 0) {
            if (*rw_dat[i].rwd_ptr == -1) {
                rw_dat[i].rwd_ptr = rw_dat[i].brw_ptr;
            }

            rw_dat[i].rw_cnt = *rw_dat[i].rwd_ptr++;
            rw_dat[i].gbix = *rw_dat[i].rwd_ptr++;
        }
    }
}

void bgAkebonoDraw(void) {
    s32 i;

    scrDrawPos[0].x = 0.0f;
    scrDrawPos[0].y = 0.0f;
    scrDrawPos[3].x = 128.0f;
    scrDrawPos[3].y = 224.0f;
    scrDrawPos[0].z = scrDrawPos[3].z = PrioBase[bg_priority[3]];
    scrDrawPos[0].s = scrDrawPos[0].t = 0.0f;
    scrDrawPos[3].s = 1.0f;
    scrDrawPos[3].t = 0.875f;

    for (i = 0; i < 3; i++) {
        ppgWriteQuadUseTrans(scrDrawPos, 0xFFFFFFFF, (void *)0, i, i, 0, 0);
        scrDrawPos[0].x += 128.0f;
        scrDrawPos[3].x += 128.0f;
    }
}

void ppgCalScrPosition(s32 x, s32 y, s32 xs, s32 ys) {
    Vec3 point[2];

    point[0].x = (f32)x;
    point[0].y = (f32)y;
    point[1].x = (f32)(x + xs);
    point[1].y = (f32)(y + ys);
    point[0].z = point[1].z = 0;
    njCalcPoints(0, point, point, 2);
    scrDrawPos[0].x = scrDrawPos[2].x = point[0].x;
    scrDrawPos[0].y = scrDrawPos[1].y = point[0].y;
    scrDrawPos[1].x = scrDrawPos[3].x = point[1].x;
    scrDrawPos[2].y = scrDrawPos[3].y = point[1].y;
    scrDrawPos[0].z = scrDrawPos[1].z = scrDrawPos[2].z = scrDrawPos[3].z = point[0].z;
    scrDrawPos[0].s = (f32)(x & 0x7F) / 128.0f;
    scrDrawPos[0].t = (f32)(y & 0x7F) / 128.0f;
    scrDrawPos[3].s = (f32)((x & 0x7F) + xs) / 128.0f;
    scrDrawPos[3].t = (f32)((y & 0x7F) + ys) / 128.0f;
    scrDrawPos[1].s = scrDrawPos[3].s;
    scrDrawPos[2].s = scrDrawPos[0].s;
    scrDrawPos[1].t = scrDrawPos[0].t;
    scrDrawPos[2].t = scrDrawPos[3].t;
}

void bgDrawOneChip(s32 x, s32 y, s32 xs, s32 ys, s32 gbix, u32 vtxCol, s32 ofsPal) {
    if (No_Trans != 0) {
        return;
    }

    if (ppgCheckTextureNumber((void *)0, gbix) == 0) {
        return;
    }

    ppgCalScrPosition(x, y, xs, ys);

    if (!(scrDrawPos[0].x < 384.0f && scrDrawPos[3].x >= 0.0f && scrDrawPos[0].y < 224.0f &&
          scrDrawPos[3].y >= 0.0f)) {
        return;
    }

    ppgWriteQuadUseTrans(scrDrawPos, vtxCol, (void *)0, gbix, 0, 0, ofsPal);
}
