/* xb_0C8A99.c: Xbox-only code from the run of Xbox-only functions at 0xC8A99, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern char D_00289870[];
s32 xb_LaunchImage(const char* path);

s32 xb_LaunchDefaultXbe(void) {
    return xb_LaunchImage(D_00289870);
}
