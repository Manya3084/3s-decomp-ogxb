/* DC_Ghost.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * njUnitMatrix 0x30410 size 0x15. Read against the x86: the Xbox calls
 * xb_MatrixIdentity where the PS2 calls sceVu0UnitMatrix. The C is the Xbox
 * code (analysis-ps2map/overrides/DC_Ghost.c).
 * PS2-only callees sceVu0UnitMatrix.
 * njGetMatrix 0x30425 size 0x13.
 * njSetMatrix 0x30494 size 0x1B.
 * njScale 0x304AF size 0x48.
 * njTranslate 0x304F7 size 0x48. Read against the x86: the PS2 code was VU0
 * macro asm; the Xbox code builds a translation matrix with
 * D3DXMatrixTranslation and multiplies it in with D3DXMatrixMultiply (XDK D3DX
 * section). -0x10 is the stack alignment for the local matrix. The C is the
 * Xbox code.
 * njSetBackColor 0x3053F size 0x17.
 * njColorBlendingMode 0x30556 size 0xC.
 * njCalcPoint 0x30562 size 0x31.
 * njCalcPoints 0x30593 size 0x37.
 * njDrawTexture 0x3065C size 0x42. Read against the x86: 0x14 and 0x18 are the
 * vertex record steps of the copy loop. The C is the PS2 C.
 * njDrawSprite 0x3069E size 0x6D. Read against the x86: the unnamed floats at
 * 0x2497E4 and 0x2497E8 are the screen bounds of the off-screen test. The C is
 * the PS2 C.
 * njdp2d_sort 0x3081F size 0x17B. Read against the x86: 0x3C is the njdp2d_w
 * entry size; the unnamed words at 0xCB8840 on are njdp2d_w. The C is the PS2
 * C.
 * njDrawPolygon2D 0x3099A size 0x27.
 * njSetPaletteBankNumG 0x309C1 size 0xE.
 * njSetPaletteData 0x309CF size 0x19.
 * njReLoadTexturePartNumG 0x309E8 size 0x1E.
 * njRotateZ is folded into 0x4384A with 48 other bodies. Unnamed.
 * njSetPaletteMode is folded into 0x4384A with 48 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: matmul,
 * njdp2d_init, njdp2d_draw.
 * sceVu0UnitMatrix has no XBE name and no aligned call.
 * Data: njdp2d_w: defined elsewhere on Xbox.
 * Data: cmtx 0x795C90.
 * Unnamed data used (not checked): njDrawSprite: 0x2497e4,0x2497e8;
 * njdp2d_sort:
 * 0xcb8840,0xcb8842,0xcb8844,0xcb8848,0xcb884c,0xcb8850,0xcb8854,0xcb8858.
 * Globals: cmtx 0x795C90, PrioBase 0xC7E560.
 */

#include "structs.h"

#define NTH_BYTE(value, n) ((((value >> n * 8) & 0xFF) << n * 8))
#define NULL 0

typedef struct {
    Vertex v;
    u32 col;
} _Polygon;

typedef struct {
    // total size: 0x3C
    Vec3 v[4];     // offset 0x0, size 0x30
    uintptr_t col; // offset 0x30, size 0x4
    u32 type;      // offset 0x34, size 0x4
    s32 next;      // offset 0x38, size 0x4
} NJDP2D_PRIM;

typedef struct {
    // total size: 0x1774
    s16 ix1st;             // offset 0x0, size 0x2
    s16 total;             // offset 0x2, size 0x2
    NJDP2D_PRIM prim[100]; // offset 0x4, size 0x1770
} NJDP2D_W;

f32* D3DXVec3Transform(f32* out, const Vec3* v, const MTX* m);
MTX* XB_STDCALL D3DXMatrixScaling(MTX* out, f32 x, f32 y, f32 z);
MTX* XB_STDCALL D3DXMatrixTranslation(MTX* out, f32 x, f32 y, f32 z);
MTX* XB_STDCALL D3DXMatrixMultiply(MTX* out, const MTX* a, const MTX* b);
void xb_MatrixIdentity(f32* m);
s32 flSetRenderState(enum _FLSETRENDERSTATE func, u32 value);
s32 ppgWriteQuadWithST_B(Vertex* pos, u32 col, PPGDataList* tb, s32 tix, s32 cix);
s32 getCP3toFullScreenDrawFlag();
s32 ppgWriteQuadWithST_B2(Vertex* pos, u32 col, PPGDataList* tb, s32 tix, s32 cix);
s32 flLogOut(s8* format, ...);
void ppgSetupCurrentPaletteNumber(Palette* pal, s32 num);
void palCopyGhostDC(s32 ofs, s32 cnt, void* data);
void palUpdateGhostDC();
void ppgRenewDotDataSeqs(Texture* tch, u32 gix, u32* srcRam, u32 code, u32 size);

extern NJDP2D_W njdp2d_w;

extern MTX cmtx;

/* Xbox: xb_MatrixIdentity stores the identity (PS2: sceVu0UnitMatrix). */
void njUnitMatrix(MTX* mtx) {
    if (mtx == NULL) {
        mtx = &cmtx;
    }

    xb_MatrixIdentity(mtx->a);
}

void njGetMatrix(MTX* m) {
    *m = cmtx;
}

void njSetMatrix(MTX* md, MTX* ms) {
    if (md == NULL) {
        md = &cmtx;
    }

    *md = *ms;
}

/* The matrix is 16-byte aligned. */
void njScale(MTX* mtx, f32 x, f32 y, f32 z) {
    XB_ALIGN16 MTX m;

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    D3DXMatrixScaling(&m, x, y, z);
    D3DXMatrixMultiply(mtx, &m, mtx);
}

/* The matrix is 16-byte aligned. */
void njTranslate(MTX* mtx, f32 x, f32 y, f32 z) {
    XB_ALIGN16 MTX m;

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    D3DXMatrixTranslation(&m, x, y, z);
    D3DXMatrixMultiply(mtx, &m, mtx);
}

void njSetBackColor(u32 c0, u32 c1, u32 c2) {
    c0 = c0 | c1 | c2;
    flSetRenderState(FLRENDER_BACKCOLOR, NTH_BYTE(c0, 3) | NTH_BYTE(c0, 2) | NTH_BYTE(c0, 1) | NTH_BYTE(c0, 0));
}

void njColorBlendingMode(s32 target, s32 mode) {
    target = target;
    mode = mode;
    flSetRenderState(FLRENDER_ALPHABLENDMODE, 0x32);
}

/* Xbox: D3DXVec3Transform transforms the point into a 4-vector. */
void njCalcPoint(MTX* mtx, Vec3* ps, Vec3* pd) {
    f32 v0[4];

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    D3DXVec3Transform(v0, ps, mtx);
    pd->x = v0[0];
    pd->y = v0[1];
    pd->z = v0[2];
}

void njCalcPoints(MTX* mtx, Vec3* ps, Vec3* pd, s32 num) {
    s32 i;

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    for (i = 0; i < num; i++) {
        njCalcPoint(mtx, ps++, pd++);
    }
}

void njRotateZ(s32 /* unused */, s32 /* unused */) {
    // Do nothing
}

void njDrawTexture(Polygon* polygon, s32 /* unused */, s32 tex, s32 /* unused */) {
    Vertex vtx[4];
    s32 i;

    for (i = 0; i < 4; i++) {
        vtx[i] = ((_Polygon*)polygon)[i].v;
    }

    ppgWriteQuadWithST_B(vtx, polygon[0].col, NULL, tex, -1);
}

void njDrawSprite(Polygon* polygon, s32 /* unused */, s32 tex, s32 /* unused */) {
    Vertex vtx[4];

    if ((getCP3toFullScreenDrawFlag() != 0) &&
        ((polygon[0].x >= 384.0f) || (polygon[3].x < 0.0f) || (polygon[0].y >= 224.0f) || (polygon[3].y < 0.0f))) {
        return;
    }

    vtx[0] = ((_Polygon*)polygon)[0].v;
    vtx[3] = ((_Polygon*)polygon)[3].v;

    ppgWriteQuadWithST_B2(vtx, polygon[0].col, 0, tex, -1);
}

// `col` needs to be `uintptr_t` because it sometimes stores a pointer to `WORK`
void njdp2d_sort(f32* pos, f32 pri, uintptr_t col, s32 flag) {
    s32 i;
    s32 ix = njdp2d_w.total;
    s32 prev;

    if (ix >= 100) {
        // Have to write the string as raw bytes here.
        // Otherwise MWCC removes a single byte for some reason
        //
        // Original:
        // flLogOut("２Ｄポリゴンの表示要求がバッファをオーバーしました\n");

        // The 2D polygon display request has exceeded the buffer\n
        flLogOut(
            "\x82\x51\x82\x63\x83\x7C\x83\x8A\x83\x53\x83\x93\x82\xCC\x95\x5C\x8E\xA6\x97\x76\x8B\x81\x82\xAA\x83\x6F"
            "\x83\x62\x83\x74\x83\x40\x82\xF0\x83\x49\x81\x5B\x83\x6F\x81\x5B\x82\xB5\x82\xDC\x82\xB5\x82\xBD\xA");
        return;
    }

    if (flag == 0) {
        njdp2d_w.prim[ix].v[0].z = njdp2d_w.prim[ix].v[1].z = njdp2d_w.prim[ix].v[2].z = njdp2d_w.prim[ix].v[3].z = pri;
        njdp2d_w.prim[ix].v[0].x = pos[0];
        njdp2d_w.prim[ix].v[0].y = pos[1];
        njdp2d_w.prim[ix].v[1].x = pos[2];
        njdp2d_w.prim[ix].v[1].y = pos[3];
        njdp2d_w.prim[ix].v[2].x = pos[4];
        njdp2d_w.prim[ix].v[2].y = pos[5];
        njdp2d_w.prim[ix].v[3].x = pos[6];
        njdp2d_w.prim[ix].v[3].y = pos[7];
        njdp2d_w.prim[ix].type = 0;
        njdp2d_w.prim[ix].col = col;
    }

    if (flag == 1) {
        njdp2d_w.prim[ix].v[0].z = pri;
        njdp2d_w.prim[ix].v[0].y = pos[0];
        njdp2d_w.prim[ix].type = 1;
        njdp2d_w.prim[ix].col = col;
    }

    njdp2d_w.prim[ix].next = -1;

    if (njdp2d_w.ix1st == -1) {
        njdp2d_w.ix1st = njdp2d_w.total;
    } else {
        i = njdp2d_w.ix1st;
        prev = -1;

        while (1) {
            if (pri > njdp2d_w.prim[i].v[0].z) {
                if (prev == -1) {
                    njdp2d_w.ix1st = ix;
                    njdp2d_w.prim[ix].next = i;
                } else {
                    njdp2d_w.prim[prev].next = ix;
                    njdp2d_w.prim[ix].next = i;
                }

                break;
            }

            if (njdp2d_w.prim[i].next == -1) {
                njdp2d_w.prim[i].next = ix;
                break;
            }

            prev = i;
            i = njdp2d_w.prim[i].next;
        }
    }

    njdp2d_w.total += 1;
}

void njDrawPolygon2D(PAL_CURSOR* p, s32 /* unused */, f32 pri, u32 attr) {
    if (attr & 0x20) {
        njdp2d_sort((f32*)p->p, pri, p->col->color, 0);
    }
}

void njSetPaletteBankNumG(u32 globalIndex, s32 bank) {
    globalIndex = globalIndex;
    ppgSetupCurrentPaletteNumber(0, bank);
}

void njSetPaletteMode(u32 mode) {
    mode = mode;
}

void njSetPaletteData(s32 offset, s32 count, void* data) {
    palCopyGhostDC(offset, count, data);
    palUpdateGhostDC();
}

s32 njReLoadTexturePartNumG(u32 gix, s8* srcAdrs, u32 ofs, u32 size) {
    ppgRenewDotDataSeqs(0, gix, (u32*)srcAdrs, ofs, size);
    return 1;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

static void matmul(MTX* dst, const MTX* a, const MTX* b) {
    MTX result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.a[i][j] =
                a->a[i][0] * b->a[0][j] + a->a[i][1] * b->a[1][j] + a->a[i][2] * b->a[2][j] + a->a[i][3] * b->a[3][j];
        }
    }

    memcpy(dst, &result, sizeof(MTX));
}

void njdp2d_init() {
    njdp2d_w.ix1st = -1;
    njdp2d_w.total = 0;
}

void njdp2d_draw() {
    Quad prm;
    s32 i;

    ps2SeqsRenderQuadInit_B();
    setZ_Operation(1);

    for (i = njdp2d_w.ix1st; i != -1; i = njdp2d_w.prim[i].next) {
        switch (njdp2d_w.prim[i].type) {
        case 0:
            prm.v[0] = njdp2d_w.prim[i].v[0];
            prm.v[1] = njdp2d_w.prim[i].v[1];
            prm.v[2] = njdp2d_w.prim[i].v[2];
            prm.v[3] = njdp2d_w.prim[i].v[3];

            ps2SeqsRenderQuad_B(&prm, njdp2d_w.prim[i].col);
            break;

        case 1:
            shadow_drawing((WORK*)njdp2d_w.prim[i].col, njdp2d_w.prim[i].v[0].y);
            break;
        }
    }

    njdp2d_init();
    ps2SeqsRenderQuadEnd();
}
#endif
