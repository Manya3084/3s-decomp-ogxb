/* SJERR_CallErr 0x172A50. Tail jump to SVM_CallErr1. */

extern void SVM_CallErr1(const char *msg);

void SJERR_CallErr(const char *msg) {
    SVM_CallErr1(msg);
}
