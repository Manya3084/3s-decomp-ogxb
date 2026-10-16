/* SJRBF_Error 0x16E560. SJRBF_Init 0x16E570. SJRBF_Finish 0x16E5A0.
 * SJRBF_Destroy 0x16E5D0.
 * SJRBF_GetUuid 0x16E600 returns uuid. SJRBF_Reset 0x16E610.
 * SJRBF_GetBufPtr 0x16EA70 returns buf.
 * SJRBF_GetBufSize 0x16EA80 returns bsize.
 * SJRBF_GetXtrSize 0x16D560 returns xsize. */

#include "types.h"

#include <stddef.h>
#include <string.h>

typedef struct SJRBF_OBJ {
    u8 gap00[4];
    s32 used;
    void *uuid;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s8 *buf;
    s32 bsize;
    s32 xsize;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    u8 gap38[8];
} SJRBF_OBJ;

typedef SJRBF_OBJ *SJRBF;

#if defined(__i386__)
_Static_assert(offsetof(SJRBF_OBJ, used) == 4, "used");
_Static_assert(offsetof(SJRBF_OBJ, uuid) == 8, "uuid");
_Static_assert(offsetof(SJRBF_OBJ, unkC) == 0x0C, "unkC");
_Static_assert(offsetof(SJRBF_OBJ, unk10) == 0x10, "unk10");
_Static_assert(offsetof(SJRBF_OBJ, unk14) == 0x14, "unk14");
_Static_assert(offsetof(SJRBF_OBJ, unk18) == 0x18, "unk18");
_Static_assert(offsetof(SJRBF_OBJ, buf) == 0x1C, "buf");
_Static_assert(offsetof(SJRBF_OBJ, bsize) == 0x20, "bsize");
_Static_assert(offsetof(SJRBF_OBJ, xsize) == 0x24, "xsize");
_Static_assert(offsetof(SJRBF_OBJ, unk28) == 0x28, "unk28");
_Static_assert(offsetof(SJRBF_OBJ, unk2C) == 0x2C, "unk2C");
_Static_assert(offsetof(SJRBF_OBJ, unk30) == 0x30, "unk30");
_Static_assert(offsetof(SJRBF_OBJ, unk34) == 0x34, "unk34");
_Static_assert(sizeof(SJRBF_OBJ) == 0x40, "SJRBF_OBJ");
#endif

#define SJRBF_MAX_OBJ 256

extern void SJERR_CallErr(const char *msg);
/* "\nSJ/XBOX Ver.6.19 Build:Feb 13 2004 21:07:54\n" */
extern char *volatile sj_build; /* 0x2E12C0 */
extern s32 sjrbf_init_cnt; /* 0x7A6074 */
extern SJRBF_OBJ sjrbf_obj[SJRBF_MAX_OBJ]; /* 0xCDCEA0 */
extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);

void SJRBF_Error(void *obj, s32 ecode) {
    (void)obj;
    (void)ecode;
    SJERR_CallErr("SJRBF Error");
}

void SJRBF_Init(void) {
    (void)sj_build;

    ADXCRS_Lock();

    if (sjrbf_init_cnt == 0) {
        memset(sjrbf_obj, 0, sizeof(sjrbf_obj));
    }

    sjrbf_init_cnt += 1;
    ADXCRS_Unlock();
}

void SJRBF_Finish(void) {
    ADXCRS_Lock();

    if (--sjrbf_init_cnt == 0) {
        memset(sjrbf_obj, 0, sizeof(sjrbf_obj));
    }

    ADXCRS_Unlock();
}

void SJRBF_Destroy(SJRBF sjrbf) {
    ADXCRS_Lock();

    if (sjrbf != NULL) {
        memset(sjrbf, 0, sizeof(SJRBF_OBJ));
        sjrbf->used = 0;
    }

    ADXCRS_Unlock();
}

void *SJRBF_GetUuid(SJRBF sjrbf) {
    return sjrbf->uuid;
}

void SJRBF_Reset(SJRBF sjrbf) {
    ADXCRS_Lock();
    sjrbf->unk34 = 0;
    sjrbf->unkC = 0;
    sjrbf->unk14 = 0;
    sjrbf->unk18 = 0;
    sjrbf->unk28 = 0;
    sjrbf->unk2C = 0;
    sjrbf->unk30 = 0;
    sjrbf->unk10 = sjrbf->bsize;
    ADXCRS_Unlock();
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
