/* mmSystemInitialize, retail sf33rd.xbe 0xF2134.
 * mmInitialNumber is 0x7968AC. The store is an and with zero.
 */

#include "types.h"

extern u32 mmInitialNumber;

void mmSystemInitialize(void) {
    mmInitialNumber = 0;
}
