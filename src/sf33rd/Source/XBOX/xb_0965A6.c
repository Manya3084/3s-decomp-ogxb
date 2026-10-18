/* xb_0965A6.c: Xbox-only code from the run of Xbox-only functions at 0x965A6, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

void xb_DrawTexturedRect(s32 a, s32 b, s32 c, s32 d, s32 e, u32 color, s32 f, s32 g);
void xb_DrawPadRemovedText(s32 x, s32 y, s32 step, s32 pl);

void xb_DrawPadRemovedBox(s32 pl) {
    xb_DrawTexturedRect(0xAC, 0x70, 3, 0x124, 0xC0, 0xF8402020, 2, 8);
    xb_DrawPadRemovedText(0x84, 0x54, 0x10, pl);
}
