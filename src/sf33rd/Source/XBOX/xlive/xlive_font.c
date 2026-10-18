/* xlive_font.c: Xbox-only code from Capcom's xlive_font.cpp. Its _assert path names it, and the
 * code that pushes the path places it at 0xFB063 to 0xFB883.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

void xb_xlive_font_ResetState(void);
void xb_xlive_font_Clear(void);

void xb_xlive_font_Reset(void) {
    xb_xlive_font_ResetState();
    xb_xlive_font_Clear();
}
