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

/* Xbox-only functions in this object (moved from src/sf33rd/Source/XBOX/xb_03070B.c; analysis-ps2map/xbgen.py checked each). */
extern s16 D_00CB8840;
extern s16 D_00CB8842;

void xb_ClearOverlayIndex(void) {
    D_00CB8840 = -1;
    D_00CB8842 = 0;
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
