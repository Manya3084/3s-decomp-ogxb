/* LSC_LockCrs 0x173A00. LSC_UnlockCrs 0x173A10.
 *
 * The PS2 lock calls SJCRS_Lock and stores zero so the call cannot be a
 * tail call. This build tail-jumps to ADXCRS_Lock and ignores the pointer.
 * Unlock is the same tail jump to ADXCRS_Unlock. The scanner does not split
 * after that jump, so Unlock sits inside the Lock span.
 */

#include "types.h"

extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);

void LSC_LockCrs(s32 *unused) {
    (void)unused;
    ADXCRS_Lock();
}

void LSC_UnlockCrs(s32 *unused) {
    (void)unused;
    ADXCRS_Unlock();
}
