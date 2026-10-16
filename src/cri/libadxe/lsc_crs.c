/* LSC_LockCrs 0x173A00.
 *
 * The PS2 body calls SJCRS_Lock and stores zero so the call cannot be a
 * tail call. This build tail-jumps to ADXCRS_Lock and ignores the pointer.
 */

#include "types.h"

extern void ADXCRS_Lock(void);

void LSC_LockCrs(s32 *unused) {
    (void)unused;
    ADXCRS_Lock();
}
