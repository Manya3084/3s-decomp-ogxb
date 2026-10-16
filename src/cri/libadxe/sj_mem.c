/* SJMEM_Error 0x16F690. */

#include "types.h"

extern void SJERR_CallErr(const char *msg);

void SJMEM_Error(void *obj, s32 ecode) {
    (void)obj;
    (void)ecode;
    SJERR_CallErr("SJMEM Error");
}
