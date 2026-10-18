f32* D3DXVec3Transform(f32* out, const Vec3* v, const MTX* m);
MTX* D3DXMatrixScaling(MTX* out, f32 x, f32 y, f32 z);
MTX* D3DXMatrixTranslation(MTX* out, f32 x, f32 y, f32 z);
MTX* D3DXMatrixMultiply(MTX* out, const MTX* a, const MTX* b);

/* Xbox: D3DX math instead of VU0 macro code: a D3DXMatrixScaling matrix,
 * multiplied in with D3DXMatrixMultiply. */
void njScale(MTX* mtx, f32 x, f32 y, f32 z) {
    MTX m;

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    D3DXMatrixScaling(&m, x, y, z);
    D3DXMatrixMultiply(mtx, &m, mtx);
}

/* Xbox: a D3DXMatrixTranslation matrix, multiplied in with D3DXMatrixMultiply. */
void njTranslate(MTX* mtx, f32 x, f32 y, f32 z) {
    MTX m;

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
