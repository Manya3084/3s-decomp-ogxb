/* xb_0C7E80.c: Xbox-only code from the run of Xbox-only functions at 0xC7E80, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

void xb_PoolFree(void);
extern s8 D_007AA5F1;

s32 xb_GetJapaneseNames(void) {
    return D_007AA5F1;
}

void xb_PoolFreeThunk(void) {
    xb_PoolFree();
}

s32 xb_IsJapaneseNames(void) {
    return D_007AA5F1 != 0;
}
