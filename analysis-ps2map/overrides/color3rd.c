/* Notes from the hand port this file replaced:
 * It is interior. The body is a tail jump to mlTsbSetBankAddr; its C is in
 * AcrSDK/MiddleWare/PS2/CapSndEng/cse.c, the object retail puts it in.
 * 0xF4510, 0xF451D, and 0xF452A are cseSysSetMono, cseSysSetMasterVolume, and
 * cseSeStopAll.
 *
 * set_hitmark_color is 0xB59E1 size 0x99 and is interior.
 * hitmark_color is 0x283458 and matches the 256 PlayStation 2 bytes.
 * ColorRAM is 0x7AAD60. The mode call stays sub_0004384A.
 * The data calls stay njSetPaletteData. That body passes its three
 * arguments to palCopyGhostDC and tails into palUpdateGhostDC.
 * The PlayStation 2 source calls njSetPaletteData(64, 64, ColorRAM[15])
 * and njSetPaletteData(576, 64, ColorRAM[31]).
 *
 * init_color_trans_req is 0xB564D size 0x1F and is interior.
 * col3rd_w.req starts at 0x7AAC88. reqNum is 0x7AAD08.
 * palCopyGhostDC is 0xB566C size 0x3D and is interior.
 * colPalBuffDC is 0x796080. upBits is 0x7AAD0C.
 * palConvSrcToRam is 0xB56A9 size 0x9C and is interior.
 * palFormConv is 0x7BAD60. palFormSrc is 0x7AAD20. palFormRam is 0x7BAD80.
 * The masks run in B, G, R, A order. The OR is the PlayStation 2 word.
 *
 * palCreateGhost is 0xB5745 size 0x15C and is a scanned start.
 * It stores palFormConv as 0. palFormRam.rs stays 10 and palFormRam.bs
 * stays 0. The PlayStation 2 source sets palFormConv to 1, palFormRam.rs
 * to 0, palFormRam.bs to 10, palFormRam.gl to 5, and palFormRam.gm to 31.
 * Each buffer is 0x2000 bytes and is cleared as 0x800 dwords.
 * The key push stays Push_ramcnt_key.
 *
 * palGetChunkGhostDC is 0xB58A1 size 0x6 and is interior.
 * palGetChunkGhostCP3 is 0xB58A7 size 0x6 and is interior.
 * palDC is 0x7AAC60. palCP3 is 0x7AAC74.
 *
 * palUpdateGhostDC is 0xB5903 size 0x78 and is a scanned start.
 * palUpdateGhostCP3 is 0xB597B size 0x66 and is a scanned start.
 * Both lock through flLockPalette(0, handle, &bits, 2). The row expand
 * is palConvRowTim2CI8Clut. The PlayStation 2 source calls palConvRowTim2CI8Clut.
 * The unlock is sub_0009B78F, which returns 1.
 * 0xB58AD, 0x16F71, and 0x309CF are palConvRowTim2CI8Clut, flLockPalette, and
 * njSetPaletteData. 0x9B78F, 0x4384A, and 0x97103 stay unnamed.
 *
 * init_trans_color_ram is 0xB5A7A size 0x726 and is a scanned start.
 * The jump table is 0xB6178 and is inside the size. plcol is 0x7AAD50.
 * hi_meta is 0x7A9EA0. My_char is 0x7A8114. Player_Color is 0x7A8906.
 * Case 3 calls metamor_color_store. Case 8 calls xb_SetColorRamEntry and waits on
 * sub_0009B78F with waitVsyncDummy. Case 10 calls xb_PurgeListEntry(id + 1),
 * copies the loaded bytes to 0x9CA4C0 + id * 0x8E590, and passes
 * cseTSBDataTable[data + 1] to cseTsbSetBankAddr, as the PlayStation 2
 * source does. cseTSBDataTable is 0x32FD28: TSB_SE, the 20 character banks
 * and a trailing zero. The PlayStation 2 case also maps a phd bank, stores
 * sdbd, and waits. Cases 0x50, 0x51, and 0x52 copy the loaded bytes to 0xB84200,
 * 0x7C5CE0, and 0x881400. Case 0x61 copies them to the pointer from
 * xb_GetExtraLoadBuffer. That helper reads the dword at 0x795C14 and returns the
 * dword at +0xC. The PlayStation 2 case 0x61 is empty.
 * 0xD01D3, 0xF44CA, 0xF50C9, 0x59B72, and 0x17792 are metamor_color_store,
 * xb_SetColorRamEntry, xb_PurgeListEntry, waitVsyncDummy, and
 * xb_GetExtraLoadBuffer.
 * 0xB61A0 is push_color_trans_req.
 *
 * q_ldreq_color_data is 0xB61C6 size 0x1B9 and is interior.
 * load_any_color is 0xB637F size 0x40 and is interior.
 * color_file is 0x283558. data and free match in all 161 rows.
 * 110 rows differ only in apfn, by -4. 23 differ only in apfn, by 5.
 * 2 differ only in apfn, by 2. 18 rows match. Eight rows also change
 * type. Index 109 changes type 8 to 0x50. Indices 110 and 111 change
 * type 9 to 0x51 and 0x52. Index 151 changes type 9 to 0x61. Index 152
 * changes type 0x62 to 9. Indices 158, 159, and 160 change type 0x63
 * to 9. Case 0 decrements retry before the 0xFFFF test, and that
 * success still tests retry. When retry reaches 0 the body stores 1
 * at DskDrvErrBe and 1 at 0xC7F4FA, then tails into xb_ShowDiskReadError.
 * Type 10 in case 0 calls sub_0009B78F(0) and xb_GetColorRamEntry(id + 1).
 * A match with data + 1 takes the success store. Case 4 always calls
 * init_trans_color_ram. It does not set rno to 5. There is no case 5,
 * no cseSendBd2SpuWithId, and no cseMemMapSetPhdAddr.
 * fsCheckFileReaded is 0x59B44. fsClose is 0x59AAA.
 * fsOpen is 0x59A4D and fsCheckCommandExecuting is 0x59B09.
 * fsGetFileSize is 0x59ABE. fsCalSectorSize
 * stays fsCalSectorSize. fsRequestFileRead is 0x59B2A.
 * load_it_use_any_key is 0x5A055. The key push stays
 * Push_ramcnt_key. xb_ShowDiskReadError, sub_0009B78F, and xb_GetColorRamEntry stay
 * unnamed. 0xB63BF is counter_write.
 */

extern s32 mlTsbSetBankAddr(u32 bank, SoundEvent *addr);
extern Col3rd_W col3rd_w;
extern u16 colPalBuffDC[1024];
extern u16 ColorRAM[512][64];
extern PixelFormat palFormSrc;
extern PixelFormat palFormRam;
extern s32 palFormConv;
extern s16 Pull_ramcnt_key(u32 memreq, u8 kokey, u8 group, u8 frre);
extern void *Get_ramcnt_address(s16 key);
extern s32 ppgSetupPalChunkDir(Palette *pch, PPLFileHeader *ppl, u8 *adrs, s32 ixNum1st, s32 unused);
extern void Push_ramcnt_key(s32 key);
extern void sub_0004384A(s32 mode);
extern void njSetPaletteData(s32 ofs, s32 cnt, void *data);
extern void flLockPalette(void *rect, u32 handle, plContext *bits, s32 flag);
extern s32 sub_0009B78F(u32 handle);
extern u32 Get_size_data_ramcnt_key(s16 key);
extern u8 My_char[2];
extern s8 Player_Color[2];
extern COL *plcol[2];
extern u16 hi_meta[2][2][64];
extern SoundEvent *cseTSBDataTable[];
extern void metamor_color_store(s32 wkid);
extern void xb_SetColorRamEntry(void *addr, u32 size, s32 id, s32 index);
extern void xb_PurgeListEntry(s32 bank);
extern void waitVsyncDummy(void);
extern u8 *xb_GetExtraLoadBuffer(void);
extern const col_file_data color_file[161];
extern const u8 lpr_wrdata[3];
extern u16 DskDrvErrBe;
extern u16 D_00C7F4FA;
extern s32 fsCheckCommandExecuting(void);
extern s32 fsOpen(REQ *curr);
extern void fsClose(REQ *curr);
extern u32 fsGetFileSize(u16 fnum);
extern u32 fsCalSectorSize(u32 size);
extern s32 fsRequestFileRead(REQ *curr, u32 sect, void *adrs);
extern s32 fsCheckFileReaded(REQ *curr);
extern s16 load_it_use_any_key(u16 fnum, u8 kokey, u8 group);
extern void xb_ShowDiskReadError(void);
extern s32 xb_GetColorRamEntry(s32 id);
extern void Set_size_data_ramcnt_key(s16 key, u32 size);
void init_trans_color_ram(s16 id, s16 key, u8 type, u16 data);
u16 palConvSrcToRam(u16 col);
void palUpdateGhostCP3(s32 pal, s32 nums);
void palConvRowTim2CI8Clut(u16* src, u32* dst, s32 size);

void q_ldreq_color_data(REQ *curr) {
    col_file_data *cfn;
    s32 err;

    cfn = (col_file_data *)&color_file[curr->ix];

    switch (curr->rno) {
    case 0:
        if (fsCheckCommandExecuting() != 0) {
            break;
        }

        if (cfn->type == 10) {
            if (sub_0009B78F(0) == 0) {
                break;
            }

            if (xb_GetColorRamEntry(curr->id + 1) == cfn->data + 1) {
                *curr->result |= lpr_wrdata[curr->id];
                curr->be = 0;
                break;
            }
        }

        curr->rno = 1;
        curr->fnum = cfn->apfn;
        curr->retry -= 1;

        if (cfn->apfn == 0xFFFF) {
            *curr->result |= lpr_wrdata[curr->id];
            curr->be = 0;
        }

        if (curr->retry == 0) {
            DskDrvErrBe = 1;
            D_00C7F4FA = 1;
            xb_ShowDiskReadError();
            return;
        }

        /* fallthrough */

    case 1:
        err = fsOpen(curr);

        if (err == 0) {
            curr->rno = 0;
            break;
        }

        curr->rno = 2;
        /* fallthrough */

    case 2:
        curr->size = (s32)fsGetFileSize(curr->fnum);
        curr->sect = (s32)fsCalSectorSize((u32)curr->size);
        curr->key = Pull_ramcnt_key((u32)curr->sect << 11, curr->kokey, curr->group, curr->frre);
        Set_size_data_ramcnt_key(curr->key, (u32)curr->size);
        curr->rno = 3;
        /* fallthrough */

    case 3:
        err = fsRequestFileRead(curr, (u32)curr->sect, Get_ramcnt_address(curr->key));

        if (err == 0) {
            Push_ramcnt_key(curr->key);
            fsClose(curr);
            curr->rno = 0;
        } else {
            curr->rno = 4;
            curr->be = 1;
        }

        break;

    case 4:
        switch (fsCheckFileReaded(curr)) {
        case 1:
            init_trans_color_ram(curr->id, curr->key, cfn->type, cfn->data);
            fsClose(curr);
            *curr->result |= lpr_wrdata[curr->id];
            curr->be = 0;
            break;

        case 0:
            break;

        default:
            Push_ramcnt_key(curr->key);
            fsClose(curr);
            curr->be = 2;
            curr->rno = 0;
            break;
        }

        break;
    }
}

void load_any_color(u16 ix, u8 kokey) {
    col_file_data *cfn;
    s16 key;

    cfn = (col_file_data *)&color_file[ix];
    key = load_it_use_any_key(cfn->apfn, kokey, 0);

    if (key != 0) {
        init_trans_color_ram(0, key, cfn->type, cfn->data);
    }
}

void set_hitmark_color(void) {
    s16 i;

    for (i = 0; i < 64; i++) {
        ColorRAM[7][i] = ColorRAM[15][i] = palConvSrcToRam(hitmark_color[i]);
        ColorRAM[23][i] = ColorRAM[31][i] = palConvSrcToRam(hitmark_color[i + 64]);
    }

    sub_0004384A(0);
    njSetPaletteData(64, 64, ColorRAM[15]);
    njSetPaletteData(576, 64, ColorRAM[31]);
    palUpdateGhostCP3(7, 1);
    palUpdateGhostCP3(15, 1);
    palUpdateGhostCP3(23, 1);
    palUpdateGhostCP3(31, 1);
}

void init_trans_color_ram(s16 id, s16 key, u8 type, u16 data) {
    u16 *ldadrs;
    u16 *tradrs;
    s16 i;
    s16 j;
    s32 n;
    s32 size;
    u8 *loaded;
    u8 *image;
    u32 nbytes;

    switch (type) {
    case 1:
        plcol[id] = (COL *)Get_ramcnt_address(key);

        if (My_char[id] == 0) {
            for (i = 0; i < 64; i++) {
                ColorRAM[id * 16][i] = palConvSrcToRam(plcol[id]->col[0][Player_Color[id]][i]);
                ColorRAM[(id * 16) + 8][i] = palConvSrcToRam(plcol[id]->col[1][Player_Color[id]][i]);
            }

            for (i = 0; i < 6; i++) {
                for (j = 0; j < 64; j++) {
                    ColorRAM[i + ((id * 16) + 1)][j] = palConvSrcToRam(plcol[id]->col[0][i + 16][j]);
                    ColorRAM[i + ((id * 16) + 9)][j] = palConvSrcToRam(plcol[id]->col[1][i + 16][j]);
                }
            }
        } else {
            tradrs = plcol[id]->col[0][Player_Color[id]];
            ldadrs = ColorRAM[id * 16];

            for (i = 0; i < 64; i++) {
                ldadrs[i] = ldadrs[i + 512] = palConvSrcToRam(tradrs[i]);
            }

            ldadrs += 64;
            tradrs = plcol[id]->col[0][16];

            for (i = 0; i < 384; i++) {
                ldadrs[i] = ldadrs[i + 512] = palConvSrcToRam(tradrs[i]);
            }
        }

        tradrs = plcol[id]->col[0][22];

        if (id != 0) {
            ldadrs = ColorRAM[506];
        } else {
            ldadrs = ColorRAM[502];
        }

        for (i = 0; i < 256; i++) {
            ldadrs[i] = palConvSrcToRam(tradrs[i]);
        }

        Push_ramcnt_key(key);
        palUpdateGhostCP3(id * 16, 16);

        if (id != 0) {
            palUpdateGhostCP3(506, 4);
        } else {
            palUpdateGhostCP3(502, 4);
        }

        break;

    case 2:
        size = (s32)Get_size_data_ramcnt_key(key) / 2;
        tradrs = (u16 *)Get_ramcnt_address(key);
        ldadrs = (u16 *)ColorRAM[data];

        for (n = 0; n < size; n++) {
            ldadrs[n] = palConvSrcToRam(tradrs[n]);
        }

        Push_ramcnt_key(key);

        if (data == 32) {
            ColorRAM[511][0] = 0;

            for (i = 1; i < 64; i++) {
                ColorRAM[511][i] = 0x8000;
            }
        }

        palUpdateGhostCP3(data, size / 64);
        break;

    case 3: {
        COL_x1000 *dadr = (COL_x1000 *)Get_ramcnt_address(key);

        if (id == 2) {
            for (i = 0; i < 64; i++) {
                hi_meta[0][0][i] = dadr->col[0][Player_Color[0]][i];
                hi_meta[0][1][i] = dadr->col[0][Player_Color[0]][i];
                hi_meta[1][0][i] = dadr->col[0][Player_Color[1]][i];
                hi_meta[1][1][i] = dadr->col[0][Player_Color[1]][i];
            }

            metamor_color_store(0);
            metamor_color_store(1);
        } else {
            if (My_char[(id + 1) & 1] == 0) {
                for (i = 0; i < 64; i++) {
                    hi_meta[id][0][i] = dadr->col[0][Player_Color[id]][i];
                    hi_meta[id][1][i] = dadr->col[1][Player_Color[id]][i];
                }
            } else {
                for (i = 0; i < 64; i++) {
                    hi_meta[id][0][i] = dadr->col[0][Player_Color[id]][i];
                    hi_meta[id][1][i] = dadr->col[0][Player_Color[id]][i];
                }
            }

            metamor_color_store(id);
        }

        Push_ramcnt_key(key);
        break;
    }

    case 4: {
        COL_x80 *adr = (COL_x80 *)Get_ramcnt_address(key);
        u16 *src = adr[Player_Color[id]].col;
        u16 *dst = ColorRAM[data + (id * 16)];

        for (i = 0; i < 64; i++) {
            dst[i] = palConvSrcToRam(src[i]);
        }

        dst = ColorRAM[data + (id * 16) + 8];

        for (i = 0; i < 64; i++) {
            dst[i] = palConvSrcToRam(src[i]);
        }

        Push_ramcnt_key(key);
        palUpdateGhostCP3(data + (id * 16), 1);
        palUpdateGhostCP3(data + (id * 16) + 8, 1);
        break;
    }

    case 5: {
        COL_x180 *adr = (COL_x180 *)Get_ramcnt_address(key);
        u16 *src = adr[Player_Color[id]].col[0];
        u16 *dst = ColorRAM[data + (id * 16)];

        for (i = 0; i < 192; i++) {
            dst[i] = palConvSrcToRam(src[i]);
        }

        dst = ColorRAM[data + (id * 16) + 8];

        for (i = 0; i < 192; i++) {
            dst[i] = palConvSrcToRam(src[i]);
        }

        Push_ramcnt_key(key);
        palUpdateGhostCP3(data + (id * 16), 3);
        palUpdateGhostCP3(data + (id * 16) + 8, 3);
        break;
    }

    case 6: {
        COL_x100 *adr = (COL_x100 *)Get_ramcnt_address(key);
        u16 *src = adr[Player_Color[id]].col[0];
        u16 *dst = ColorRAM[data + (id * 16)];

        for (i = 0; i < 128; i++) {
            dst[i] = palConvSrcToRam(src[i]);
        }

        dst = ColorRAM[data + (id * 16) + 8];

        for (i = 0; i < 128; i++) {
            dst[i] = palConvSrcToRam(src[i]);
        }

        Push_ramcnt_key(key);
        palUpdateGhostCP3(data + (id * 16), 2);
        palUpdateGhostCP3(data + (id * 16) + 8, 2);
        break;
    }

    case 7: {
        COL_x2800 *adrs = (COL_x2800 *)Get_ramcnt_address(key);

        ldadrs = ColorRAM[40];
        tradrs = ColorRAM[41];

        for (i = 0; i < 16; i++) {
            ldadrs[i] = palConvSrcToRam(adrs->col[My_char[0]][Player_Color[0]][i]);
            tradrs[i] = palConvSrcToRam(adrs->col[My_char[1]][Player_Color[1]][i]);
        }

        Push_ramcnt_key(key);
        palUpdateGhostCP3(40, 2);
        break;
    }

    case 8:
        xb_SetColorRamEntry(Get_ramcnt_address(key), Get_size_data_ramcnt_key(key), 0, 0);

        while (sub_0009B78F(1) == 0) {
            waitVsyncDummy();
        }

        Push_ramcnt_key(key);
        break;

    case 10:
        xb_PurgeListEntry((u8)id + 1);
        loaded = Get_ramcnt_address(key);
        nbytes = Get_size_data_ramcnt_key(key);
        image = (u8 *)0x9CA4C0 + (s32)id * 0x8E590;

        if ((s32)nbytes > 0) {
            for (n = 0; n < (s32)nbytes; n++) {
                image[n] = loaded[n];
            }
        }

        cseTsbSetBankAddr((u32)(id + 1), cseTSBDataTable[data + 1]);
        xb_SetColorRamEntry(image, nbytes, id + 1, data + 1);
        Push_ramcnt_key(key);
        break;

    case 0xB:
    case 0xC:
        break;

    case 0x50:
    case 0x51:
    case 0x52:
        loaded = Get_ramcnt_address(key);
        nbytes = Get_size_data_ramcnt_key(key);

        if (type == 0x50) {
            image = (u8 *)0xB84200;
        } else if (type == 0x51) {
            image = (u8 *)0x7C5CE0;
        } else {
            image = (u8 *)0x881400;
        }

        if ((s32)nbytes > 0) {
            for (n = 0; n < (s32)nbytes; n++) {
                image[n] = loaded[n];
            }
        }

        Push_ramcnt_key(key);
        break;

    case 0x61:
        image = xb_GetExtraLoadBuffer();
        loaded = Get_ramcnt_address(key);
        nbytes = Get_size_data_ramcnt_key(key);

        if ((s32)nbytes > 0) {
            for (n = 0; n < (s32)nbytes; n++) {
                image[n] = loaded[n];
            }
        }

        Push_ramcnt_key(key);
        break;
    }
}

void init_color_trans_req(void) {
    s16 i;

    for (i = 0; i < 32; i++) {
        col3rd_w.req[i][0] = col3rd_w.req[i][1] = 0;
    }

    col3rd_w.reqNum = 0;
}

void palCopyGhostDC(s32 ofs, s32 cnt, void *data) {
    s32 i;
    u16 *srcAdrs = data;
    u16 *dstAdrs = &colPalBuffDC[ofs];

    for (i = 0; i < cnt; i++) {
        *dstAdrs++ = *srcAdrs++;
    }

    col3rd_w.upBits = col3rd_w.upBits | (1 << (ofs / 64));
}

u16 palConvSrcToRam(u16 col) {
    u8 cA;
    u8 cR;
    u8 cG;
    u8 cB;

    if (palFormConv == 0) {
        return col;
    }

    cA = palFormSrc.am & (col >> palFormSrc.as);
    cR = palFormSrc.rm & (col >> palFormSrc.rs);
    cG = palFormSrc.gm & (col >> palFormSrc.gs);
    cB = palFormSrc.bm & (col >> palFormSrc.bs);
    return (cA << palFormRam.as) | (cR << palFormRam.rs) | (cG << palFormRam.gs) | (cB << palFormRam.bs);
}

void palCreateGhost(void) {
    PPLFileHeader ppl;
    s32 key;
    s32 size;
    s32 i;
    u8 *adrs;

    palFormConv = 0;
    palFormSrc.rl = 5;
    palFormSrc.rs = 10;
    palFormSrc.rm = 31;
    palFormSrc.gl = 5;
    palFormSrc.gs = 5;
    palFormSrc.gm = 31;
    palFormSrc.bl = 5;
    palFormSrc.bs = 0;
    palFormSrc.bm = 31;
    palFormSrc.al = 1;
    palFormSrc.as = 15;
    palFormSrc.am = 1;
    palFormRam.rl = 5;
    palFormRam.rs = 10;
    palFormRam.rm = 31;
    palFormRam.gl = 5;
    palFormRam.gs = 5;
    palFormRam.gm = 31;
    palFormRam.bl = 5;
    palFormRam.bs = 0;
    palFormRam.bm = 31;
    palFormRam.al = 1;
    palFormRam.as = 15;
    palFormRam.am = 1;
    col3rd_w.upBits = 0;
    ppl.magic = 0;
    ppl.fileSize = 0;
    ppl.free = 0;
    ppl.compress = 0;
    ppl.c_mode = 2;
    ppl.formARGB = 0x5515;

    ppl.palettes = 0x1000;
    size = 0x2000;
    key = Pull_ramcnt_key(size, 2, 0, 1);
    adrs = (u8 *)Get_ramcnt_address((s16)key);

    for (i = 0; i < size; i++) {
        adrs[i] = 0;
    }

    ppgSetupPalChunkDir(&col3rd_w.palDC, &ppl, adrs, 0, 1);
    Push_ramcnt_key(key);

    ppl.palettes = 2;
    size = 0x2000;
    key = Pull_ramcnt_key(size, 2, 0, 1);
    adrs = (u8 *)Get_ramcnt_address((s16)key);

    for (i = 0; i < size; i++) {
        adrs[i] = 0;
    }

    ppgSetupPalChunkDir(&col3rd_w.palCP3, &ppl, adrs, 0, 1);
    Push_ramcnt_key(key);
}

Palette *palGetChunkGhostDC(void) {
    return &col3rd_w.palDC;
}

Palette *palGetChunkGhostCP3(void) {
    return &col3rd_w.palCP3;
}

void palUpdateGhostDC(void) {
    plContext bits;
    s32 i;
    u16 *srcAdrs;
    void *dstAdrs;

    for (i = 0; i < col3rd_w.palDC.total; i++) {
        if (col3rd_w.upBits & (1 << i)) {
            flLockPalette(0, col3rd_w.palDC.handle[i], &bits, 2);
            dstAdrs = bits.ptr;
            srcAdrs = &colPalBuffDC[(i << 6)];
            palConvRowTim2CI8Clut(srcAdrs, dstAdrs, 0x40);
            sub_0009B78F(col3rd_w.palDC.handle[i]);
        }
    }

    col3rd_w.upBits = 0;
}

void palUpdateGhostCP3(s32 pal, s32 nums) {
    plContext bits;
    s32 i;
    u16 *srcAdrs;
    void *dstAdrs;

    for (i = pal; i < (pal + nums); i++) {
        flLockPalette(0, col3rd_w.palCP3.handle[i], &bits, 2);
        dstAdrs = bits.ptr;
        srcAdrs = ColorRAM[i];
        palConvRowTim2CI8Clut(srcAdrs, dstAdrs, 0x40);
        sub_0009B78F(col3rd_w.palCP3.handle[i]);
    }
}

/* The Xbox converts each 16-bit TIM2 colour into a 32-bit ARGB entry (alpha 0xFF when bit 15 is set) in row order; it has no PS2 CLUT swizzle. */
void palConvRowTim2CI8Clut(u16* src, u32* dst, s32 size) {
    s32 i;
    u32 col;

    for (i = 0; i < size; i++) {
        col = *src++;
        *dst++ = ((((((col & 0x7C00) << 3) | (col & 0x3E0)) << 3) | (col & 0x1F)) << 3) | ((col & 0x8000) ? 0xFF000000 : 0);
    }
}
