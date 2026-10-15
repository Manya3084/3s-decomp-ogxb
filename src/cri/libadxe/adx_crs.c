/* ADXCRS_Lock 0x16AA60 and ADXCRS_Unlock 0x16AA70.
 * Each one is a tail jump to SVM_Lock or SVM_Unlock.
 */

void SVM_Lock(void);
void SVM_Unlock(void);

void ADXCRS_Lock(void) {
    SVM_Lock();
}

void ADXCRS_Unlock(void) {
    SVM_Unlock();
}
