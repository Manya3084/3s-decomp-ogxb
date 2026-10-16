/* SJRBF_Error 0x16E560. */

#include "types.h"

extern void SJERR_CallErr(const char *msg);

void SJRBF_Error(void *obj, s32 ecode) {
    (void)obj;
    (void)ecode;
    SJERR_CallErr("SJRBF Error");
}
