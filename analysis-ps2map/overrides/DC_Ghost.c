f32* sub_001948E0(f32* out, const Vec3* v, const MTX* m);
MTX* sub_0019496B(MTX* out, f32 x, f32 y, f32 z);
MTX* sub_001949C7(MTX* out, f32 x, f32 y, f32 z);
MTX* sub_00194A23(MTX* out, const MTX* a, const MTX* b);

/* Xbox: D3DX math instead of VU0 macro code. sub_0019496B fills a scaling
 * matrix (D3DXMatrixScaling) and sub_00194A23 multiplies (D3DXMatrixMultiply). */
void njScale(MTX* mtx, f32 x, f32 y, f32 z) {
    MTX m;

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    sub_0019496B(&m, x, y, z);
    sub_00194A23(mtx, &m, mtx);
}

/* Xbox: sub_001949C7 fills a translation matrix (D3DXMatrixTranslation). */
void njTranslate(MTX* mtx, f32 x, f32 y, f32 z) {
    MTX m;

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    sub_001949C7(&m, x, y, z);
    sub_00194A23(mtx, &m, mtx);
}

/* Xbox: sub_001948E0 transforms the point into a 4-vector (D3DXVec3Transform). */
void njCalcPoint(MTX* mtx, Vec3* ps, Vec3* pd) {
    f32 v0[4];

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    sub_001948E0(v0, ps, mtx);
    pd->x = v0[0];
    pd->y = v0[1];
    pd->z = v0[2];
}
