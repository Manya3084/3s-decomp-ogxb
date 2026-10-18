/* DEMO00.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * CAPLOGO_Init 0x30A06 size 0xA9. Read against the x86: the logo is loaded
 * from file 80 (0x50; PS2 75), part of the Xbox file renumbering. The C is the
 * Xbox code (analysis-ps2map/overrides/DEMO00.c).
 * Put_char 0x30AAF size 0x1A3. Read against the x86: 0x44 is the ucomiss
 * parity mask (lahf; test ah, 0x44). The C is the PS2 C.
 * Warning_Init 0x30C52 size 0x108. Read against the x86: Xbox loads warning
 * file 18 when Country is 3 and 17 otherwise, where the PS2 build loads 12;
 * the C is changed to match (analysis-ps2map/overrides/DEMO00.c). 0x24E is the
 * 590 texture base.
 * Put_Warning 0x30D5A size 0x16A. Read against the x86: 0x250 is texture 592
 * passed to the draw call. The C is the PS2 C.
 * Pal_Cursor_Put 0x30EC4 size 0x203. Read against the x86: 0x74 is the
 * frame-pointer bias of MSVC's aligned stack frame. No change from the C.
 * Warning 0x310C7 size 0x1D8.
 * CAPLOGO_Move 0x3129F size 0x83.
 * CAPCOM_Logo 0x31322 size 0x194.
 * Push_ramcnt_key is folded into 0x97103.
 * mmDebWriteTag is folded into 0x4384A.
 * setup_pos_remake_key is folded into 0x4384A.
 * Data: caplogo is 0x32A660, 2 pointers whose arrays were compared.
 * Data: caplogo00 is 0x2497F0, 0x44 bytes compared.
 * Data: caplogo01 is 0x249838, 0x44 bytes compared.
 * Data: picon_no: defined elsewhere on Xbox.
 * Data: picon_level: defined elsewhere on Xbox.
 * TARGET_PS2 block in Put_char: kept the PS2 side of a TARGET_PS2 block.
 * Unnamed data used (not checked): CAPLOGO_Init:
 * 0x24987c,0x2498ac,0x7a7f58,0x7a7f5c; Put_char: 0x2190d4; Warning_Init:
 * 0x2498bc,0x2498e8,0xcb8830; Put_Warning:
 * 0x2190ac,0x2193f0,0x2197e0,0x2197e4,0x2498f4,0x2498f8,0x2498fc,0x249900;
 * Pal_Cursor_Put:
 * 0x21909c,0x2193f0,0x249904,0x249908,0x24990c,0x249910,0x249914,0x249918.
 * FadeIn/FadeOut priority is 1 on Xbox (PS2 8) in CAPCOM_Logo, Warning.
 * Globals: caplogo 0x32A660, ppgAdxPal 0x7A7E80, ppgCapLogoTex 0x7A7EA0,
 * ppgCapLogoPal 0x7A7F40, ppgWarTex 0x7A7FE0, ppgWarPal 0x7A8040, D_No
 * 0x7A8200, Next_Demo 0x7A8300, Country 0x7A8748, D_Timer 0x7A892E, No_Trans
 * 0x7BD3C9, p1sw_0 0x7C557C, Frame_Zoom_Y 0x7C5854, p2sw_0 0x7C5B90,
 * Frame_Zoom_X 0x7C5B94, op_timer0 0xC7E4F0, PrioBase 0xC7E560.
 */

#include "structs.h"

#define NULL 0

void sub_00097103(s16 key);
void sub_0004384A();
void setTexAdrsMode(s32 mode);
void setFilterMode(s32 mode);
extern s32 Next_Demo;
extern u8 D_No[4];
extern s16 D_Timer;
void FadeInit();
void Put_Warning(s16 type);
s32 FadeIn(u8 type, u8 step, u8 priority);
extern u8 Usage;
extern u16 p1sw_0;
extern u16 p2sw_0;
s32 FadeOut(u8 type, u8 step, u8 priority);
void TexRelease(u32 G_Num);
void ppgSetupCurrentDataList(PPGDataList* dlist);
extern PPGDataList ppgCapLogoList;
void checkAdxFileLoaded();
void checkSelObjFileLoaded();
void Standby_BGM(u16 num);
void CAPLOGO_Init();
void Push_LDREQ_Queue_Direct(s16 ix, s16 id);
s32 Check_LDREQ_Clear();
extern s16 op_timer0;
void Go_BGM();
s16 CAPLOGO_Move(u16 type);
extern Texture ppgCapLogoTex;
extern Palette ppgCapLogoPal;
s32 load_it_use_any_key2(u16 fnum, void** adrs, s16* key, u8 kokey, u8 group);
s32 flLogOut(s8* format, ...);
s32 ppgSetupPalChunk(Palette* pch, u8* adrs, s32 size, s32 ixNum1st, s32 num, s32 );
s32 ppgSetupTexChunk_1st(Texture* tch, u8* adrs, ssize_t size, s32 ixNum1st, s32 ixNums, s32 ar, s32 arcnt);
s32 ppgSetupTexChunk_2nd(Texture* tch, s32 ixNum);
s32 ppgSetupTexChunk_3rd(Texture* tch, s32 ixNum, u32 attribute);
void ppgSourceDataReleased(PPGDataList* dlist);
extern u8 Game_pause;
void njSetPaletteBankNumG(u32 globalIndex, s32 bank);
void Put_char(const f32* ptr, u32 indexG, u16 prio, s16 x, s16 y, f32 zx, f32 zy);
extern u8 No_Trans;
extern f32 PrioBase[128];
extern f32 Frame_Zoom_X;
extern f32 Frame_Zoom_Y;
void njDrawTexture(Polygon* polygon, s32 , s32 tex, s32 );
extern PPGDataList ppgWarList;
extern Texture ppgWarTex;
extern Palette ppgWarPal;
extern PPGDataList ppgAdxList;
extern Palette ppgAdxPal;
extern u8 Country;
void ppgSetupCurrentPaletteNumber(Palette* pal, s32 num);
extern FLPS2State flPs2State;
void njDrawPolygon2D(PAL_CURSOR* p, s32 , f32 pri, u32 attr);

static const f32 caplogo00[17] = { 0.25f, 0.25f, 1.0f,  0.5f,   0.0f, 0.0f,   192.0f, 64.0f, 0.0f,
                                   0.5f,  1.0f,  0.75f, 192.0f, 0.0f, 256.0f, 64.0f,  -1.0f };

static const f32 caplogo01[17] = { 0.0f,  0.0f,  1.0f, 0.25f,  0.0f, 0.0f,  256.0f, 64.0f, 0.0f,
                                   0.25f, 0.25f, 0.5f, 256.0f, 0.0f, 64.0f, 64.0f,  -1.0f };

static const f32* caplogo[2] = { caplogo00, caplogo01 };

extern s16 picon_no;

extern f32 picon_level;

s32 Warning() {
    setTexAdrsMode(0);
    setFilterMode(1);
    Next_Demo = 0;

    switch (D_No[1]) {
    case 0:
        D_No[1] = 5;
        D_No[1] = 9;
        D_Timer = 120;
        FadeInit();
        Next_Demo = 0;
        break;

    case 5:
        Put_Warning(1);
        Next_Demo = 0;

        if (FadeIn(1, 8, 1) != 0) {
            D_No[1] += 1;
            D_Timer = 120;
        }

        break;

    case 6:
        if ((Usage == 7) && (((p1sw_0 & 0x4FF0) | (p2sw_0 & 0x4FF0)) != 0)) {
            D_Timer = 2;
            D_No[1] = 7;
            FadeInit();
        }

        Put_Warning(1);
        Next_Demo = 0;

        if (!--D_Timer) {
            D_No[1] += 1;
            D_Timer = 180;
        }

        break;

    case 7:
        if (((p1sw_0 & 0x4FF0) | (p2sw_0 & 0x4FF0)) != 0) {
            D_Timer = 1;
        }

        if (!--D_Timer) {
            D_No[1] += 1;
            FadeInit();
        }

        Put_Warning(1);
        Next_Demo = 0;
        break;

    case 8:
        Put_Warning(1);
        Next_Demo = 0;

        if (FadeOut(1, 8, 1) != 0) {
            D_No[1] += 1;
        }

        break;

    default:
        D_No[1] = 0;
        TexRelease(590);
        Next_Demo = 1;
        break;
    }

    return Next_Demo;
}

s32 CAPCOM_Logo() {
    setTexAdrsMode(0);
    setFilterMode(0);
    ppgSetupCurrentDataList(&ppgCapLogoList);
    Next_Demo = 0;

    switch (D_No[1]) {
    case 0:
        D_No[1] += 1;
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

s16 CAPLOGO_Move(u16 type) {
    s16 rnum = 0;

    switch (type) {
    case 0:
        if (!Game_pause && (op_timer0 != 61)) {
            njSetPaletteBankNumG(600, op_timer0 / 2);
            op_timer0 += 1;
            rnum = 1;
        }

        Put_char(caplogo[type], 600, 9, -16, 80, 1.0f, 1.0f);
        break;

    default:
        njSetPaletteBankNumG(600, 0x1F);
        Put_char(caplogo[type], 600, 9, 48, 88, 1.0f, 1.0f);
        break;
    }

    return rnum;
}

void Put_char(const f32* ptr, u32 indexG, u16 prio, s16 x, s16 y, f32 zx, f32 zy) {
    Polygon tex[4];
    s16 off_x;
    s16 off_y;

    if (No_Trans) {
        return;
    }

    tex[0].col = tex[1].col = tex[2].col = tex[3].col = 0xFFFFFFFF;
    tex[0].z = tex[1].z = tex[2].z = tex[3].z = PrioBase[prio];

    while (*ptr != -1.0f) {
        tex[0].u = tex[1].u = *ptr++;
        tex[0].v = tex[2].v = *ptr++;
        tex[2].u = tex[3].u = *ptr++;
        tex[1].v = tex[3].v = *ptr++;

        off_x = (u32)*ptr++;
        off_y = (u32)*ptr++;

        tex[0].x = tex[1].x = Frame_Zoom_X * (x + off_x * zx);
        tex[0].y = tex[2].y = Frame_Zoom_Y * (y + off_y * zy);
        tex[2].x = tex[3].x = Frame_Zoom_X * (x + (off_x * zx) + ((u32)*ptr++ * zx));
        tex[1].y = tex[3].y = Frame_Zoom_Y * (y + (off_y * zy) + ((u32)*ptr++ * zy));
        njDrawTexture(tex, 4, indexG, 1);
    }
}

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
        tex[2].x = tex[3].x = flPs2State.DispWidth;
        tex[1].y = tex[3].y = flPs2State.DispHeight;
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
        tex[2].x = tex[3].x = flPs2State.DispWidth;
        tex[1].y = tex[3].y = flPs2State.DispHeight;
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

    njDrawPolygon2D(&pal_cursor, 4, prio, 0x60);
}
