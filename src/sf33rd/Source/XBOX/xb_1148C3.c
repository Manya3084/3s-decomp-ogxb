/* xb_1148C3.c: Xbox-only code from 0x1148C3. xb_xlive_stat_Commit matches only apart from
 * the functions around it, so a file of Capcom's starts here.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern u8* D_00798CAC;
u8* XB_FASTCALL xb_LiveWork_Get2408(u8* self);
s32 XB_FASTCALL xb_LiveObj_GetHandle50(u8* self);
extern u8* D_00799148;
void xb_xlive_disp_DrawBox20(f32 x, f32 y, f32 s, s32 text, f32 alpha, s32 flags, s32 c);

void xb_xlive_stat_Commit(void) {
    s32 h = xb_LiveObj_GetHandle50(xb_LiveWork_Get2408(D_00798CAC));

    xb_xlive_disp_DrawBox20(0.0f, 95.0f, 0.6f, *(s32*)(D_00799148 + h * 4 + 0x28), 1.0f, 0, 0);
}
