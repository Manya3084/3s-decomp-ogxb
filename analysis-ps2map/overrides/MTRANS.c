/* Xbox: the matrix is 16-byte aligned on the stack */
void appRenewTempPriority(s32 z) {
    XB_ALIGN16 MTX mtx;
    njGetMatrix(&mtx);
    PrioBase[z] = mtx.a[3][2];
}
