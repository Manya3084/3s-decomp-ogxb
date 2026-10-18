/* DC_Ghost.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * njUnitMatrix 0x30410 size 0x15. Read against the x86: the Xbox calls
 * xb_MatrixIdentity where the PS2 calls sceVu0UnitMatrix. The C is the Xbox
 * code (analysis-ps2map/overrides/DC_Ghost.c).
 * PS2-only callees sceVu0UnitMatrix.
 * njGetMatrix 0x30425 size 0x13.
 * xb_GetButtonScale 0x30438 size 0x31.
 * xb_SetButtonScale 0x30469 size 0x2B.
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
 * xb_SetButtonImageScale 0x305CA size 0x92. FLAG: x86-only callees
 * njScale,xb_GetButtonScale,xb_SetButtonScale,njTranslate.
 * njDrawTexture 0x3065C size 0x42. Read against the x86: 0x14 and 0x18 are the
 * vertex record steps of the copy loop. The C is the PS2 C.
 * njDrawSprite 0x3069E size 0x6D. Read against the x86: the unnamed floats at
 * 0x2497E4 and 0x2497E8 are the screen bounds of the off-screen test. The C is
 * the PS2 C.
 * njdp2d_init 0x3070B size 0x11.
 * njdp2d_draw 0x3071C size 0x103. FLAG: x86-only callees xb_DrawColoredQuad;
 * PS2-only callees njdp2d_init; x86-only constants 0x3c.
 * njdp2d_sort 0x3081F size 0x17B. Read against the x86: 0x3C is the njdp2d_w
 * entry size; the unnamed words at 0xCB8840 on are njdp2d_w. The C is the PS2
 * C.
 * njDrawPolygon2D 0x3099A size 0x27.
 * njSetPaletteBankNumG 0x309C1 size 0xE.
 * njSetPaletteData 0x309CF size 0x19.
 * njReLoadTexturePartNumG 0x309E8 size 0x1E.
 * njRotateZ is folded into 0x4384A with 60 other bodies. Unnamed.
 * njSetPaletteMode is folded into 0x4384A with 60 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: matmul.
 * sceVu0UnitMatrix has no XBE name and no aligned call.
 * Data: njdp2d_w 0xCB8840.
 * Data: cmtx 0x795C90.
 * Unnamed data used (not checked): xb_SetButtonImageScale:
 * 0x2190d4,0x2497dc,0x2497e0; njDrawSprite: 0x2497e4,0x2497e8.
 * Globals: cmtx 0x795C90, PrioBase 0xC7E560, njdp2d_w 0xCB8840.
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

f32* XB_STDCALL D3DXVec3Transform(f32* out, const Vec3* v, const MTX* m);
MTX* XB_STDCALL D3DXMatrixScaling(MTX* out, f32 x, f32 y, f32 z);
MTX* XB_STDCALL D3DXMatrixTranslation(MTX* out, f32 x, f32 y, f32 z);
MTX* XB_STDCALL D3DXMatrixMultiply(MTX* out, const MTX* a, const MTX* b);
void xb_MatrixIdentity(f32* m);
extern f32 D_00795CC0;
extern f32 D_00795CC4;
extern f32 D_00795CC8;
s32 ps2SeqsRenderQuadInit_B(void);
void ps2SeqsRenderQuad_B(Quad* q, u32 col);
void xb_DrawColoredQuad(void* q);
s32 flSetRenderState(enum _FLSETRENDERSTATE func, u32 value);
s32 ppgWriteQuadWithST_B(Vertex* pos, u32 col, PPGDataList* tb, s32 tix, s32 cix);
s32 getCP3toFullScreenDrawFlag();
s32 ppgWriteQuadWithST_B2(Vertex* pos, u32 col, PPGDataList* tb, s32 tix, s32 cix);
void setZ_Operation(s32 flag);
void ps2SeqsRenderQuadEnd();
void shadow_drawing(WORK* wk, s16 bsy);
extern f32 PrioBase[128];
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

/* Xbox: D3DXVec3Transform transforms the point into a 4-vector; its first three floats are copied to pd as a Vec3. */
void njCalcPoint(MTX* mtx, Vec3* ps, Vec3* pd) {
    f32 v0[4];

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    D3DXVec3Transform(v0, ps, mtx);
    *pd = *(Vec3*)v0;
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

void njdp2d_init() {
    njdp2d_w.ix1st = -1;
    njdp2d_w.total = 0;
}

/* Xbox: draws only the entries whose type is in mask, and clears the type of
   each one drawn. Types 4 and 16 are textured quads (ps2SeqsRenderQuad_B),
   2 and 8 flat quads from corners 0 and 3 (xb_DrawColoredQuad), 1 a shadow.
   ps2SeqsRenderQuadInit_B is ps2SeqsRenderQuadInit_B, called per quad, and
   njdp2d_init is left to the caller. */
void njdp2d_draw(u32 mask) {
    Quad prm;
    struct {
        Vec3 v0;
        Vec3 v1;
        u32 col;
        u32 type;
    } cq;
    s32 i;

    setZ_Operation(1);

    for (i = njdp2d_w.ix1st; i != -1; i = njdp2d_w.prim[i].next) {
        if (!(njdp2d_w.prim[i].type & mask)) {
            continue;
        }

        switch (njdp2d_w.prim[i].type) {
        case 4:
        case 16:
            prm.v[0] = njdp2d_w.prim[i].v[0];
            prm.v[1] = njdp2d_w.prim[i].v[1];
            prm.v[2] = njdp2d_w.prim[i].v[2];
            prm.v[3] = njdp2d_w.prim[i].v[3];
            ps2SeqsRenderQuadInit_B();
            ps2SeqsRenderQuad_B(&prm, njdp2d_w.prim[i].col);
            ps2SeqsRenderQuadEnd();
            njdp2d_w.prim[i].type = 0;
            break;

        case 2:
        case 8:
            cq.v0 = njdp2d_w.prim[i].v[0];
            cq.v1 = njdp2d_w.prim[i].v[3];
            cq.col = njdp2d_w.prim[i].col;
            cq.type = njdp2d_w.prim[i].type;
            ps2SeqsRenderQuadInit_B();
            xb_DrawColoredQuad(&cq);
            ps2SeqsRenderQuadEnd();
            njdp2d_w.prim[i].type = 0;
            break;

        case 1:
            shadow_drawing((WORK*)njdp2d_w.prim[i].col, njdp2d_w.prim[i].v[0].y);
            njdp2d_w.prim[i].type = 0;
            break;
        }
    }
}

/* Xbox: no overflow message, and the flag is the primitive type. 1 is a
 * single point; 2, 4, 8, and 16 take the quad, with 8 and 16 becoming 2
 * and 4 above PrioBase[7]. Any other flag is not queued. */
void njdp2d_sort(f32* pos, f32 pri, uintptr_t col, s32 flag) {
    s32 i;
    s32 ix = njdp2d_w.total;
    s32 prev;

    if (ix >= 100) {
        return;
    }

    switch (flag) {
    case 1:
        njdp2d_w.prim[ix].v[0].z = pri;
        njdp2d_w.prim[ix].v[0].y = pos[0];
        njdp2d_w.prim[ix].col = col;
        break;

    case 2:
    case 4:
    case 8:
    case 16:
        njdp2d_w.prim[ix].v[0].z = njdp2d_w.prim[ix].v[1].z = njdp2d_w.prim[ix].v[2].z = njdp2d_w.prim[ix].v[3].z = pri;
        njdp2d_w.prim[ix].v[0].x = pos[0];
        njdp2d_w.prim[ix].v[0].y = pos[1];
        njdp2d_w.prim[ix].v[1].x = pos[2];
        njdp2d_w.prim[ix].v[1].y = pos[3];
        njdp2d_w.prim[ix].v[2].x = pos[4];
        njdp2d_w.prim[ix].v[2].y = pos[5];
        njdp2d_w.prim[ix].v[3].x = pos[6];
        njdp2d_w.prim[ix].v[3].y = pos[7];
        njdp2d_w.prim[ix].col = col;

        if (pri > PrioBase[7]) {
            if (flag == 8) {
                flag = 2;
            }

            if (flag == 16) {
                flag = 4;
            }
        }

        break;

    default:
        return;
    }

    njdp2d_w.prim[ix].next = -1;
    njdp2d_w.prim[ix].type = flag;

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

void xb_GetButtonScale(f32* x, f32* y, f32* z) {
    *x = D_00795CC0;
    *y = D_00795CC4;
    *z = D_00795CC8;
}

void xb_SetButtonScale(f32 x, f32 y, f32 z) {
    D_00795CC0 = x;
    D_00795CC4 = y;
    D_00795CC8 = z;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_SetButtonImageScale(void) {
    f32 x;
    f32 y;
    f32 z;

    njScale(0, 1.6666666f, -2.0f, 1.0f);
    xb_GetButtonScale(&x, &y, &z);
    xb_SetButtonScale(0.0f, 0.0f, 0.0f);
    njTranslate(0, x, y, z);
    njScale(0, 1.0f, -1.0f, 1.0f);
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
#endif
