/* mmSystemInitialize, retail sf33rd.xbe 0xF2134.
 * mmRoundUp 0xF213C. mmRoundOff 0xF214E.
 * mmInitialNumber is 0x7968AC. The store is an and with zero.
 */

#include "types.h"

extern u32 mmInitialNumber;

void mmSystemInitialize(void) {
    mmInitialNumber = 0;
}

u32 mmRoundUp(u32 unit, u32 num) {
    return ~(unit - 1) & (num + unit - 1);
}

u32 mmRoundOff(u32 unit, u32 num) {
    return num & ~(unit - 1);
}
