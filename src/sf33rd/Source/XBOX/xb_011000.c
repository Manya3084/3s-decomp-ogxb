/* xb_011000.c: Xbox-only code from the run of Xbox-only functions at 0x11000, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

s32 xb_PoolCreate(void* buf, void* end, s32 unit, s32 a, s32 b, s32 c, s32 d);
extern u8 D_00CBA9A0[];
extern u8 D_00CCA9A0[];

s32 xb_PoolUsedSize(u8* pool) {
    return *(s32*)(pool + 0x10) - *(s32*)(pool + 0xC);
}

s32 xb_InitWorkPool(s32 a, s32 b, s32 c) {
    return xb_PoolCreate(D_00CCA9A0, D_00CBA9A0, 0x1000, a, b, c, 1);
}
