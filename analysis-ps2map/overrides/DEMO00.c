/* Data read off the retail code: ppgAdxList is 0x7A7ED8, ppgWarList is 0x7A7F18. */

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

    Push_ramcnt_key(key);
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
    Push_ramcnt_key(key);
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

/* Xbox: input state is reset as the logo starts. */
void xb_ResetInputState(void);

s32 CAPCOM_Logo() {
    setTexAdrsMode(0);
    setFilterMode(0);
    ppgSetupCurrentDataList(&ppgCapLogoList);
    Next_Demo = 0;

    switch (D_No[1]) {
    case 0:
        D_No[1] += 1;
        xb_ResetInputState();
        checkAdxFileLoaded();
        checkSelObjFileLoaded();
        break;

    case 1:
        D_No[1] += 1;
        sub_0004384A(1);
        Standby_BGM(67);
        CAPLOGO_Init();
        Push_LDREQ_Queue_Direct(0x16, 2);
        FadeInit();
        break;

    case 2:
        if (Check_LDREQ_Clear() != 0) {
            D_No[1] += 1;
            D_Timer = 10;
        }

        break;

    case 3:
        if (--D_Timer == 0) {
            D_No[1] += 1;
            op_timer0 = 0;
            Go_BGM();
        }

        break;

    case 4:
        if (!CAPLOGO_Move(0)) {
            D_No[1] += 1;
            Push_LDREQ_Queue_Direct(0x17, 2);
            FadeInit();
        }

        break;

    case 5:
        CAPLOGO_Move(1);

        if (FadeIn(1, 6, 1) != 0) {
            D_No[1] += 1;
            D_Timer = 256;
            Push_LDREQ_Queue_Direct(0x18, 2);
        }

        break;

    case 6:
        CAPLOGO_Move(1);

        if (--D_Timer == 0) {
            D_No[1] += 1;
            FadeInit();
        }

        break;

    case 7:
        CAPLOGO_Move(1);

        if (FadeOut(1, 6, 1) != 0) {
            D_No[1] += 1;
        }

        break;

    default:
        TexRelease(600);
        Next_Demo = 1;
        break;
    }

    return Next_Demo;
}

/* Xbox: the screen is 640 by 448 (PS2: flPs2State.DispWidth and DispHeight). */
void Put_Warning(s16 type) {
    Polygon tex[4];
    f32 video_y = 16.0f;

    tex[0].col = tex[1].col = tex[2].col = tex[3].col = 0xFFFFFFFF;

    if (type == 2) {
        tex[0].z = tex[1].z = tex[2].z = tex[3].z = PrioBase[0x14];
    } else {
        tex[0].z = tex[1].z = tex[2].z = tex[3].z = PrioBase[0x1E];
    }

    switch (type) {
    case 0:
        ppgSetupCurrentDataList(&ppgWarList);
        ppgSetupCurrentPaletteNumber(0, 0);
        tex[0].u = tex[1].u = 0.0f;
        tex[0].v = tex[2].v = 0.0f;
        tex[2].u = tex[3].u = 1.0f;
        tex[1].v = tex[3].v = 1.0f;
        tex[0].x = tex[1].x = 0.0f;
        tex[0].y = tex[2].y = 0.0f;
        tex[2].x = tex[3].x = 640.0f;
        tex[1].y = tex[3].y = 448.0f;
        break;

    case 1:
        ppgSetupCurrentDataList(&ppgAdxList);
        ppgSetupCurrentPaletteNumber(0, 0);
        tex[0].u = tex[1].u = 0.0f;
        tex[0].v = tex[2].v = 0.0f;
        tex[2].u = tex[3].u = 1.0f;
        tex[1].v = tex[3].v = 0.875f;
        tex[0].x = tex[1].x = 0.0f;
        tex[0].y = tex[2].y = 0.0f;
        tex[2].x = tex[3].x = 640.0f;
        tex[1].y = tex[3].y = 448.0f;
        break;

    case 2:
    case 3:
    default:
        tex[0].x = tex[1].x = 64.0f;
        tex[0].y = tex[2].y = -32.0f;
        tex[2].x = tex[3].x = 576.0f;
        tex[1].y = tex[3].y = 480.0f;
        break;
    }

    if (type == 2) {
        njDrawTexture(tex, 4, type + 590, 1);
        return;
    }

    njDrawTexture(tex, 4, type + 590, 0);
}
