/* xb_unlockpal.c: flUnlockPalette, retail sf33rd.xbe.
 * On the PS2 it uploads a locked palette (flps2vram.c). On the Xbox a
 * palette is written in place and there is nothing to unlock: the name is
 * folded into the body at 0x9B78F that returns 1 (with flBeginRender,
 * flEndRender and seven others). It is in a file of its own so that the
 * callers' calls to it are kept, as retail keeps them. */

#include "types.h"

s32 flUnlockPalette(u32 th) {
    return 1;
}
