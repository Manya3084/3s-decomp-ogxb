/* SJMEM_Error 0x16F690. SJMEM_Init 0x16F6A0. SJMEM_Finish 0x16F6C0.
 * SJMEM_Destroy 0x16F6E0. */

#include "types.h"

#include <stddef.h>
#include <string.h>

typedef struct SJMEM_OBJ {
    void *vtbl;
    s32 used;
    void *uuid;
    s32 unkC;
    s32 unk10;
    s8 *buf;
    s32 bsize;
    void (*err_func)(void *obj, s32 ecode);
    void *err_obj;
} SJMEM_OBJ;

typedef SJMEM_OBJ *SJMEM;

#if defined(__i386__)
_Static_assert(offsetof(SJMEM_OBJ, vtbl) == 0, "vtbl");
_Static_assert(offsetof(SJMEM_OBJ, used) == 4, "used");
_Static_assert(offsetof(SJMEM_OBJ, uuid) == 8, "uuid");
_Static_assert(offsetof(SJMEM_OBJ, unkC) == 0x0C, "unkC");
_Static_assert(offsetof(SJMEM_OBJ, unk10) == 0x10, "unk10");
_Static_assert(offsetof(SJMEM_OBJ, buf) == 0x14, "buf");
_Static_assert(offsetof(SJMEM_OBJ, bsize) == 0x18, "bsize");
_Static_assert(offsetof(SJMEM_OBJ, err_func) == 0x1C, "err_func");
_Static_assert(offsetof(SJMEM_OBJ, err_obj) == 0x20, "err_obj");
_Static_assert(sizeof(SJMEM_OBJ) == 0x24, "SJMEM_OBJ");
#endif

#define SJMEM_MAX_OBJ 32

extern void SJERR_CallErr(const char *msg);
extern s32 sjmem_init_cnt; /* 0x7A607C */
extern SJMEM_OBJ sjmem_obj[SJMEM_MAX_OBJ]; /* 0xCD64A0 */

void SJMEM_Error(void *obj, s32 ecode) {
    (void)obj;
    (void)ecode;
    SJERR_CallErr("SJMEM Error");
}

void SJMEM_Init(void) {
    if (sjmem_init_cnt == 0) {
        memset(sjmem_obj, 0, sizeof(sjmem_obj));
    }

    sjmem_init_cnt += 1;
}

void SJMEM_Finish(void) {
    if (--sjmem_init_cnt == 0) {
        memset(sjmem_obj, 0, sizeof(sjmem_obj));
    }
}

void SJMEM_Destroy(SJMEM sjmem) {
    if (sjmem != NULL) {
        memset(sjmem, 0, sizeof(SJMEM_OBJ));
        sjmem->used = 0;
    }
}
