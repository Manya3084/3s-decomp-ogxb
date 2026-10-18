/* xb_05A0D4.c: Xbox-only code from the run of Xbox-only functions at 0x5A0D4, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

typedef struct {
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    u32 col;
} XB_RECT16;
s32 flSetRenderState(s32 state, u32 value);
void xb_DrawQuadWithSavedStates(XB_RECT16* r);

void xb_DrawSaveFrame(void) {
    XB_RECT16 r;

    flSetRenderState(0x6C, 0);
    r.x0 = 0x20;
    r.y0 = 0xC;
    r.x1 = 0x160;
    r.y1 = 0xD4;
    r.col = 0xDF000000;
    xb_DrawQuadWithSavedStates(&r);
    r.col = 0xFFFFFFFF;
    r.x0 = 0x1C;
    r.y0 = 0xA;
    r.x1 = 0x20;
    r.y1 = 0xD6;
    xb_DrawQuadWithSavedStates(&r);
    r.x0 = 0x160;
    r.x1 = 0x164;
    xb_DrawQuadWithSavedStates(&r);
    r.x0 = 0x20;
    r.y0 = 0xA;
    r.x1 = 0x160;
    r.y1 = 0xC;
    xb_DrawQuadWithSavedStates(&r);
    r.y0 = 0xD4;
    r.y1 = 0xD6;
    xb_DrawQuadWithSavedStates(&r);
    flSetRenderState(0x6C, 1);
}
