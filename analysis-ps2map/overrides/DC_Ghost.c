f32* D3DXVec3Transform(f32* out, const Vec3* v, const MTX* m);
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

/* Xbox: xb_MatrixIdentity stores the identity (PS2: sceVu0UnitMatrix). */
void njUnitMatrix(MTX* mtx) {
    if (mtx == NULL) {
        mtx = &cmtx;
    }

    xb_MatrixIdentity(mtx->a);
}
