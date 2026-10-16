/* SJRBF_Error 0x16E560. SJRBF_Init 0x16E570. SJRBF_Finish 0x16E5A0.
 * SJRBF_Destroy 0x16E5D0.
 * SJRBF_GetUuid 0x16E600 returns uuid. SJRBF_Reset 0x16E610.
 * SJRBF_GetNumData 0x16E640. SJRBF_GetChunk 0x16E680.
 * SJRBF_EntryErrFunc 0x16DFD0.
 * SJRBF_GetBufPtr 0x16EA70 returns buf.
 * SJRBF_GetBufSize 0x16EA80 returns bsize. SJRBF_Create 0x16EA90.
 * SJRBF_GetXtrSize 0x16D560 returns xsize. */

#include "types.h"

#include <stddef.h>
#include <string.h>

typedef struct SJRBF_OBJ {
    void *vtbl;
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
    void (*err_func)(void *obj, s32 ecode);
    void *err_obj;
} SJRBF_OBJ;

typedef SJRBF_OBJ *SJRBF;

typedef struct {
    s8 *data;
    s32 len;
} SJCK;

#if defined(__i386__)
_Static_assert(offsetof(SJRBF_OBJ, vtbl) == 0, "vtbl");
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
_Static_assert(offsetof(SJRBF_OBJ, err_func) == 0x38, "err_func");
_Static_assert(offsetof(SJRBF_OBJ, err_obj) == 0x3C, "err_obj");
_Static_assert(sizeof(SJRBF_OBJ) == 0x40, "SJRBF_OBJ");
_Static_assert(offsetof(SJCK, len) == 4, "SJCK.len");
_Static_assert(sizeof(SJCK) == 8, "SJCK");
#endif

#define SJRBF_MAX_OBJ 256
#define SJ_ERR_PRM (-3)

extern void SJERR_CallErr(const char *msg);
/* "\nSJ/XBOX Ver.6.19 Build:Feb 13 2004 21:07:54\n" */
extern char *volatile sj_build; /* 0x2E12C0 */
extern s32 sjrbf_init_cnt; /* 0x7A6074 */
extern SJRBF_OBJ sjrbf_obj[SJRBF_MAX_OBJ]; /* 0xCDCEA0 */
extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern char sjrbf_vtbl[]; /* 0x43CA58 */
extern char sjrbf_uuid[]; /* 0x2E12C4 */

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

s32 SJRBF_GetNumData(SJRBF sjrbf, s32 id) {
    if (id == 1) {
        return sjrbf->unkC;
    } else if (id == 0) {
        return sjrbf->unk10;
    }

    if (sjrbf->err_func != NULL) {
        sjrbf->err_func(sjrbf->err_obj, SJ_ERR_PRM);
    }

    return 0;
}

void SJRBF_EntryErrFunc(SJRBF sjrbf, void (*func)(void *obj, s32 ecode), void *obj) {
    sjrbf->err_func = func;
    sjrbf->err_obj = obj;
}

void SJRBF_GetChunk(SJRBF sjrbf, s32 id, s32 nbyte, SJCK *ck) {
    ADXCRS_Lock();

    if (id == 0) {
        ck->len = sjrbf->unk10;

        if (ck->len > sjrbf->bsize - sjrbf->unk14 + sjrbf->xsize) {
            ck->len = sjrbf->bsize - sjrbf->unk14 + sjrbf->xsize;
        }

        if (ck->len > nbyte) {
            ck->len = nbyte;
        }

        ck->data = sjrbf->buf + sjrbf->unk14;
        sjrbf->unk14 = (sjrbf->unk14 + ck->len) % sjrbf->bsize;
        sjrbf->unk10 -= ck->len;
        sjrbf->unk28 += ck->len;
    } else if (id == 1) {
        ck->len = sjrbf->unkC;

        if (ck->len > sjrbf->bsize - sjrbf->unk18 + sjrbf->xsize) {
            ck->len = sjrbf->bsize - sjrbf->unk18 + sjrbf->xsize;
        }

        if (ck->len > nbyte) {
            ck->len = nbyte;
        }

        ck->data = sjrbf->buf + sjrbf->unk18;
        sjrbf->unk18 = (sjrbf->unk18 + ck->len) % sjrbf->bsize;
        sjrbf->unkC -= ck->len;
        sjrbf->unk30 += ck->len;
    } else {
        ck->len = 0;
        ck->data = NULL;

        if (sjrbf->err_func != NULL) {
            sjrbf->err_func(sjrbf->err_obj, SJ_ERR_PRM);
        }
    }

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

SJRBF SJRBF_Create(s8 *buf, s32 bsize, s32 xsize) {
    SJRBF sjrbf;
    s32 i;

    ADXCRS_Lock();

    for (i = 0; i < SJRBF_MAX_OBJ; i++) {
        if (sjrbf_obj[i].used == 0) {
            break;
        }
    }

    sjrbf = NULL;

    if (i != SJRBF_MAX_OBJ) {
        sjrbf = &sjrbf_obj[i];
        sjrbf->used = 1;
        sjrbf->vtbl = sjrbf_vtbl;
        sjrbf->buf = buf;
        sjrbf->bsize = bsize;
        sjrbf->xsize = xsize;
        sjrbf->uuid = sjrbf_uuid;
        sjrbf->err_func = SJRBF_Error;
        sjrbf->err_obj = sjrbf;
        SJRBF_Reset(sjrbf);
    }

    ADXCRS_Unlock();
    return sjrbf;
}
