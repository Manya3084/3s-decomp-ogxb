void njDrawPolygon2D(PAL_CURSOR* p, s32 n, f32 pri, u32 attr, s32 flag);

/* Data: njdp2d_w is 0xCB8840 (ix1st, total, then the 0x3C-byte entries). */
f32* XB_STDCALL D3DXVec3Transform(f32* out, const Vec3* v, const MTX* m);
MTX* XB_STDCALL D3DXMatrixScaling(MTX* out, f32 x, f32 y, f32 z);
MTX* XB_STDCALL D3DXMatrixTranslation(MTX* out, f32 x, f32 y, f32 z);
MTX* XB_STDCALL D3DXMatrixMultiply(MTX* out, const MTX* a, const MTX* b);
void xb_MatrixIdentity(f32* m);

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

/* Xbox: D3DXVec3Transform transforms the point into a 4-vector; its first three floats are copied to pd as a Vec3. */
void njCalcPoint(MTX* mtx, Vec3* ps, Vec3* pd) {
    f32 v0[4];

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    D3DXVec3Transform(v0, ps, mtx);
    *pd = *(Vec3*)v0;
}

/* Xbox: xb_MatrixIdentity stores the identity (PS2: sceVu0UnitMatrix). */
void njUnitMatrix(MTX* mtx) {
    if (mtx == NULL) {
        mtx = &cmtx;
    }

    xb_MatrixIdentity(mtx->a);
}

/* Xbox-only functions in this object (moved from src/sf33rd/Source/XBOX/xb_030438.c; analysis-ps2map/xbgen.py checked each). */
extern f32 D_00795CC0;
extern f32 D_00795CC4;
extern f32 D_00795CC8;

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

s32 ps2SeqsRenderQuadInit_B(void);
void ps2SeqsRenderQuad_B(Quad* q, u32 col);
void xb_DrawColoredQuad(void* q);

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

/* Xbox: the fifth argument is njdp2d_sort's primitive type. */
void njDrawPolygon2D(PAL_CURSOR* p, s32 /* unused */, f32 pri, u32 attr, s32 flag) {
    if (attr & 0x20) {
        njdp2d_sort((f32*)p->p, pri, p->col->color, flag);
    }
}
