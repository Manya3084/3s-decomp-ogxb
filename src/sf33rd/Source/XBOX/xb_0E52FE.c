/* xb_0E52FE.c: Xbox-only code from the run of Xbox-only functions at 0xE52FE, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

s32 load_it_use_any_key2(s32 ix, void* out, s32* size, s32 a, s32 b);
s32 flLogOut(const char* fmt, ...);
extern void* D_007A7E98[];
void ppgLoadMsgTex(void);
void ppgScrPal(void);
void ppgSetupCurrentDataList(void* list);
extern char D_002AEE14[];
void ppgSetupTexChunk_1st(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void ppgSetupTexChunk_2nd(void* a, s32 i);
void ppgSetupTexChunk_3rd(void* a, s32 i, s32 b);
void sub_00097103(s32 key);
void ppgSourceDataReleased(void* a);

void xb_LoadExitScreen(void) {
    s32 adr;
    s32 key;
    s32 tex;
    s32 i;
    s32 n = 4;

    D_007A7E98[0] = ppgLoadMsgTex;
    D_007A7E98[1] = ppgScrPal;
    ppgSetupCurrentDataList(D_007A7E98);
    tex = load_it_use_any_key2(0xF, &adr, &key, 2, 0);

    if (tex == 0) {
        flLogOut(D_002AEE14);
        while (1) {}
    }

    ppgSetupTexChunk_1st(0, adr, tex, 0, n, 0, 0);

    for (i = 0; n != 0; i++, n--) {
        ppgSetupTexChunk_2nd(0, i);
        ppgSetupTexChunk_3rd(0, i, 1);
    }

    sub_00097103(key);
    ppgSourceDataReleased(0);
}

/* xb_DrawBorderedRect 0xE96DC (was xb_DrawTexturedRect).
 *
 * Fills the w x h rectangle at (x, y) with col and draws a white frame
 * t pixels thick round it (an outer rectangle and two bands), at
 * PrioBase[prio]. Nothing is drawn while No_Trans is set. */

typedef struct {
    f32 x;
    f32 y;
} XB_PT2;

typedef struct {
    XB_PT2* p;
    u32* col;
    u32* tex;
    u32 num;
} XB_PALCURSOR;

extern u8 No_Trans;
extern f32 PrioBase[];
void njColorBlendingMode(s32 target, s32 mode);
void njDrawPolygon2D(XB_PALCURSOR* p, s32 n, f32 pri, u32 attr, s32 flag);

void xb_DrawBorderedRect(s32 x, s32 y, s32 prio, s32 w, s32 h, u32 col, s32 t, s32 flag) {
    XB_PT2 v[4];
    u32 c[4];
    XB_PALCURSOR pc;
    s32 half;

    if (No_Trans) {
        return;
    }

    njColorBlendingMode(0, 1);
    pc.p = v;
    pc.col = c;
    c[0] = c[1] = c[2] = c[3] = col;
    pc.num = 4;
    v[0].x = v[2].x = x;
    v[0].y = v[1].y = y;
    v[1].x = v[3].x = x + w;
    v[2].y = v[3].y = y + h;
    njDrawPolygon2D(&pc, 4, PrioBase[prio], 0x60, flag);

    c[0] = c[1] = c[2] = c[3] = 0xFFFFFFFF;
    half = t / 2;
    v[0].x = v[2].x = x - half;
    v[0].y = v[1].y = y - half;
    v[1].x = v[3].x = half + x + w;
    v[2].y = v[3].y = half + y + h;
    njDrawPolygon2D(&pc, 4, PrioBase[prio], 0x60, flag);

    v[0].x = v[2].x = x - t;
    v[0].y = v[1].y = y + t;
    v[1].x = v[3].x = w + x + t;
    v[2].y = v[3].y = y - t + h;
    njDrawPolygon2D(&pc, 4, PrioBase[prio], 0x60, flag);

    v[0].x = v[2].x = x + t;
    v[0].y = v[1].y = y - t;
    v[1].x = v[3].x = x - t + w;
    v[2].y = v[3].y = y + h + t;
    njDrawPolygon2D(&pc, 4, PrioBase[prio], 0x60, flag);
}
