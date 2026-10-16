/* ADXCRS_Init 0x16E550 stores 0 at adxcrs_lvl (0x7A606C).
 * Lock and Unlock do not touch that level.
 * ADXCRS_Lock 0x16AA60 and ADXCRS_Unlock 0x16AA70.
 * Each one is a tail jump to SVM_Lock or SVM_Unlock.
 */

#include "types.h"

extern s32 adxcrs_lvl;

void SVM_Lock(void);
void SVM_Unlock(void);

void ADXCRS_Init(void) {
    adxcrs_lvl = 0;
}

void ADXCRS_Lock(void) {
    SVM_Lock();
}

void ADXCRS_Unlock(void) {
    SVM_Unlock();
}
