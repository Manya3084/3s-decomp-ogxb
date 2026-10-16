/* SJRBF_Error 0x16E560. SJRBF_GetUuid 0x16E600 returns uuid.
 * SJRBF_GetBufPtr 0x16EA70 returns buf.
 * SJRBF_GetBufSize 0x16EA80 returns bsize.
 * SJRBF_GetXtrSize 0x16D560 returns xsize. */

#include "types.h"

#include <stddef.h>

typedef struct SJRBF_OBJ {
    u8 gap00[8];
    void *uuid;
    u8 gap0C[0x10];
    s8 *buf;
    s32 bsize;
    s32 xsize;
} SJRBF_OBJ;

typedef SJRBF_OBJ *SJRBF;

#if defined(__i386__)
_Static_assert(offsetof(SJRBF_OBJ, uuid) == 8, "uuid");
_Static_assert(offsetof(SJRBF_OBJ, buf) == 0x1C, "buf");
_Static_assert(offsetof(SJRBF_OBJ, bsize) == 0x20, "bsize");
_Static_assert(offsetof(SJRBF_OBJ, xsize) == 0x24, "xsize");
#endif

extern void SJERR_CallErr(const char *msg);

void SJRBF_Error(void *obj, s32 ecode) {
    (void)obj;
    (void)ecode;
    SJERR_CallErr("SJRBF Error");
}

void *SJRBF_GetUuid(SJRBF sjrbf) {
    return sjrbf->uuid;
}

void *SJRBF_GetBufPtr(SJRBF sjrbf) {
    return sjrbf->buf;
}

s32 SJRBF_GetBufSize(SJRBF sjrbf) {
    return sjrbf->bsize;
}

s32 SJRBF_GetXtrSize(SJRBF sjrbf) {
    return sjrbf->xsize;
}
