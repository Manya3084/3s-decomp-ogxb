void xb_SetViewportRect(s32 x, s32 y, s32 w, s32 h);

void initRenderState(s32 flag) {
    f32 fogstart = 20000.0f;
    f32 fogend = 30000.0f;

    if (flag == 0) {
        flSetRenderState(FLRENDER_AMBIENT, 0);
        flSetRenderState(FLRENDER_LIGHTING, 0x200);
        flSetRenderState(FLRENDER_MATERIAL, 2);
        flSetRenderState(FLRENDER_FOGCOLOR, 0x80FFFFFF);
        flSetRenderState(FLRENDER_FOGSTART, REINTERPRET_AS_U32(fogstart));
        flSetRenderState(FLRENDER_FOGEND, REINTERPRET_AS_U32(fogend));
        flSetRenderState(FLRENDER_ALPHATEST, 4);
        flSetRenderState(FLRENDER_ZWRITE, 1);
        flSetRenderState(FLRENDER_ZOPE, 1);
    }

    setBlendMode(0, 4, 5);
    setFilterMode(1);
    flSetRenderState(FLRENDER_ALPHAREF, 0);
    xb_SetViewportRect(0, 0, 640, 448);
}
