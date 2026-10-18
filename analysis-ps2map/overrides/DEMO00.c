/* picon_no is 0xCB8830 and picon_level is 0xCB8834. */
void Warning_Init() {
    void* loadAdrs;
    u32 loadSize;
    s16 key;
    s16 i;

    sub_0004384A("\nWARNING\n\n");
    ppgWarList.tex = &ppgWarTex;
    ppgWarList.pal = &ppgWarPal;
    ppgAdxList.tex = &ppgWarTex;
    ppgAdxList.pal = &ppgAdxPal;
    ppgSetupCurrentDataList(&ppgWarList);
    /* Xbox: two warning files, 18 when Country is 3, else 17 (PS2: 12). */
    loadSize = load_it_use_any_key2((Country == 3) ? 18 : 17, &loadAdrs, &key, 2, 1);

    if (loadSize == 0) {
        flLogOut("警告文のテクスチャが読み込めませんでした。\n");
        while (1) {}
    }

    ppgSetupPalChunk(&ppgWarPal, loadAdrs, loadSize, 0, 0, 1);
    ppgSetupPalChunk(&ppgAdxPal, loadAdrs, loadSize, 0, 1, 1);
    ppgSetupTexChunk_1st(0, loadAdrs, loadSize, 590, 4, 0, 0);

    for (i = 0; i < ppgWarTex.textures; i++) {
        ppgSetupTexChunk_2nd(0, i + 590);
        ppgSetupTexChunk_3rd(0, i + 590, 1);
    }

    sub_00097103(key);
    ppgSourceDataReleased(0);
    picon_no = 0;
}

/* Xbox: the logo is file 80 (PS2 75). */
void CAPLOGO_Init() {
    void* loadAdrs;
    u32 loadSize;
    s16 key;

    sub_0004384A("\nCAPCOM LOGO\n\n");
    ppgCapLogoList.tex = &ppgCapLogoTex;
    ppgCapLogoList.pal = &ppgCapLogoPal;
    ppgSetupCurrentDataList(&ppgCapLogoList);
    loadSize = load_it_use_any_key2(80, &loadAdrs, &key, 2, 1); // CapLogo.ppg (PS2 file 75)

    if (loadSize == 0) {
        flLogOut("カプロゴのテクスチャが読み込めませんでした。\n");
        while (1) {}
    }

    ppgSetupPalChunk(NULL, loadAdrs, loadSize, 0, 0, 1);
    ppgSetupTexChunk_1st(NULL, loadAdrs, loadSize, 600, 1, 0, 0);
    ppgSetupTexChunk_2nd(NULL, 600);
    ppgSetupTexChunk_3rd(NULL, 600, 1);
    sub_00097103(key);
    ppgSourceDataReleased(0);
}

void njDrawPolygon2D(PAL_CURSOR* p, s32 n, f32 pri, u32 attr, s32 flag);

/* Xbox: the polygon is type 2. */
void Pal_Cursor_Put(s16 type) {
    PAL_CURSOR_TBL pal_cursor_tbl[3] = {
        { { { 48.0f, 64.0f }, { 48.0f, 99.0f }, { 144.0f, 99.0f }, { 144.0f, 64.0f } },
          { 0xA0FF0000, 0xA0FF0000, 0xA0FF0000, 0xA0FF0000 } },
        { { { 48.0f, 296.0f }, { 48.0f, 332.0f }, { 286.0f, 332.0f }, { 286.0f, 296.0f } },
          { 0xA0FF0000, 0xA0FF0000, 0xA0FF0000, 0xA0FF0000 } },
        { { { 48.0f, 379.0f }, { 48.0f, 415.0f }, { 286.0f, 415.0f }, { 286.0f, 379.0f } },
          { 0xA0FF0000, 0xA0FF0000, 0xA0FF0000, 0xA0FF0000 } }
    };

    f32 pal_alpha_tbl[4] = { 255.0f, 48.0f, 178.5f, 48.0f };
    PAL_CURSOR pal_cursor;
    f32 prio;
    PAL_CURSOR_TBL* pal_cursorwk;
    s16 i;

    switch (picon_no) {
    case 0:
        picon_no += 1;
        picon_level = pal_alpha_tbl[0];
        break;

    case 1:
        picon_level -= (pal_alpha_tbl[0] - pal_alpha_tbl[2]) / pal_alpha_tbl[1];

        if (picon_level <= pal_alpha_tbl[2]) {
            picon_level = pal_alpha_tbl[2];
            picon_no = 2;
        }

        break;

    case 2:
        picon_level += (pal_alpha_tbl[0] - pal_alpha_tbl[2]) / pal_alpha_tbl[3];

        if (!(picon_level < pal_alpha_tbl[0])) {
            picon_no = 1;
            picon_level = pal_alpha_tbl[0];
        }

        break;
    }

    if (No_Trans) {
        return;
    }

    pal_cursorwk = pal_cursor_tbl;
    prio = PrioBase[0x50];
    pal_cursor.p = pal_cursorwk[type].pal_cursor_p;
    pal_cursor.col = pal_cursorwk[type].pal_cursor_col;
    pal_cursor.num = 4;

    for (i = 0; i < 4; i++) {
        pal_cursor.col[i].argb.a = picon_level;
    }

    njDrawPolygon2D(&pal_cursor, 4, prio, 0x60, 2);
}
