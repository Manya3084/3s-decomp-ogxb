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
