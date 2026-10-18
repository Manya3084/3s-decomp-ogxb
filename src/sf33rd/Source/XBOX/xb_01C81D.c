/* xb_01C81D.c: Xbox-only code from the run of Xbox-only functions at 0x1C81D, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include <string.h>

extern s32 D_00795C80;
void sub_0009B78F(void);
extern f32 D_00795C60[];
void flSetRenderState(s32 state, s32 value);
extern s32 D_00329D28[];
void xb_SetViewportFloat(s32 a, s32 b, s32 c, s32 d, s32 e, f32 f, f32 g);
extern u8 D_00795C20[];

void xb_SetScreenRect(void* rect) {
    memcpy(D_00795C60, rect, 0x18);
}

void xb_GetScreenRect(void* rect) {
    memcpy(rect, D_00795C60, 0x18);
}

void xb_ApplyScreenRect(void) {
    xb_SetViewportFloat((s32)D_00795C20, (s32)D_00795C60[0], (s32)D_00795C60[1], (s32)D_00795C60[2],
                        (s32)D_00795C60[3], D_00795C60[4], D_00795C60[5]);
}

void xb_PushPauseCount(void) {
    sub_0009B78F();
    D_00795C80++;
}

void xb_PopPauseCount(void) {
    sub_0009B78F();
    D_00795C80--;
}

void xb_SetOverlayBlend(s32 i) {
    flSetRenderState(0x6D, D_00329D28[i]);
}
