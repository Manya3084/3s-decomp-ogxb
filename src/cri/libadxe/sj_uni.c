/* SJUNI_Init 0x171F50. SJUNI_Finish 0x171F70.
 * SJUNI_Destroy 0x171F90. SJUNI_EntryErrFunc 0x171FB0.
 * SJUNI_Reset 0x171FD0. SJUNI_GetNumData 0x172030.
 * SJUNI_GetChunk 0x172080. SJUNI_PutChunk 0x172190.
 * SJUNI_UngetChunk 0x172270. SJUNI_IsGetChunk 0x172340.
 *
 * Sixty-four objects of 0x30 bytes sit at 0xCD4E80, the exclusive end of
 * the LSC table. The counter is 0x7A609C. A zero count clears 0x300 dwords.
 * Finish is interior: Init ends on a bare ret, so the scanner does not
 * split. Finish decrements the counter and clears the same table at zero.
 * Destroy clears one object as 0xC dwords, then stores used at +4.
 * It does not take the stream lock. The locked clear at 0x16FA10 is
 * a different body. The vtable is 0x43CC90. Its GetUuid slot is the
 * already-named SJRBF_GetUuid. Reset links the work chunks and clears
 * the four lists. It does not take the stream lock. GetNumData rejects
 * an id below 0 or at least 4, then sums ck.len. GetChunk takes
 * ADXCRS_Lock. The PS2 body takes SJCRS_Lock. Both unlocks here are calls.
 * PutChunk and UngetChunk tail-jump to ADXCRS_Unlock on the locked paths.
 * IsGetChunk does not take the lock. It stores zero into rbyte before
 * the id check.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

#define SJUNI_MAX_OBJ 64
#define SJUNI_MODE_JOIN 1
#define SJ_ERR_PRM (-3)

typedef struct {
    s8 *data;
    s32 len;
} SJCK;

typedef struct SJUNI_CK {
    struct SJUNI_CK *next;
    s32 unk4;
    SJCK ck;
} SJUNI_CK;

typedef struct {
    void *vtbl;
    s8 used;
    s8 mode;
    s8 pad[2];
    void *uuid;
    SJUNI_CK *work;
    s32 chunk_count;
    SJUNI_CK *chain_pool;
    SJUNI_CK *unk18[4];
    void (*err_func)(void *obj, s32 ecode);
    void *err_obj;
} SJUNI_OBJ;

#if defined(__i386__)
_Static_assert(sizeof(SJCK) == 8, "SJCK");
_Static_assert(sizeof(SJUNI_CK) == 0x10, "SJUNI_CK");
_Static_assert(offsetof(SJUNI_CK, ck) == 8, "ck");
_Static_assert(sizeof(SJUNI_OBJ) == 0x30, "SJUNI_OBJ");
_Static_assert(offsetof(SJUNI_OBJ, used) == 4, "used");
_Static_assert(offsetof(SJUNI_OBJ, mode) == 5, "mode");
_Static_assert(offsetof(SJUNI_OBJ, work) == 0x0C, "work");
_Static_assert(offsetof(SJUNI_OBJ, chunk_count) == 0x10, "chunk_count");
_Static_assert(offsetof(SJUNI_OBJ, chain_pool) == 0x14, "chain_pool");
_Static_assert(offsetof(SJUNI_OBJ, unk18) == 0x18, "unk18");
_Static_assert(offsetof(SJUNI_OBJ, err_func) == 0x28, "err_func");
_Static_assert(offsetof(SJUNI_OBJ, err_obj) == 0x2C, "err_obj");
#endif

extern s32 sjuni_init_cnt;
extern SJUNI_OBJ sjuni_obj[SJUNI_MAX_OBJ];

void SJUNI_Init(void) {
    if (sjuni_init_cnt == 0) {
        memset(sjuni_obj, 0, sizeof(sjuni_obj));
    }

    sjuni_init_cnt += 1;
}

void SJUNI_Finish(void) {
    if (--sjuni_init_cnt == 0) {
        memset(sjuni_obj, 0, sizeof(sjuni_obj));
    }
}

void SJUNI_Destroy(SJUNI_OBJ *sjuni) {
    if (sjuni != 0) {
        memset(sjuni, 0, sizeof(SJUNI_OBJ));
        sjuni->used = 0;
    }
}

void SJUNI_EntryErrFunc(SJUNI_OBJ *sjuni, void (*func)(void *obj, s32 ecode), void *obj) {
    sjuni->err_func = func;
    sjuni->err_obj = obj;
}

void SJUNI_Reset(SJUNI_OBJ *sjuni) {
    s32 i;
    SJUNI_CK *work = sjuni->work;

    sjuni->chain_pool = work;

    for (i = 0; i < sjuni->chunk_count - 1; i++) {
        work[i].next = &work[i + 1];
        work[i].ck.data = 0;
        work[i].ck.len = 0;
    }

    work[i].next = 0;
    work[i].ck.data = 0;
    work[i].ck.len = 0;

    for (i = 0; i < 4; i++) {
        sjuni->unk18[i] = 0;
    }
}

s32 SJUNI_GetNumData(SJUNI_OBJ *sjuni, s32 id) {
    SJUNI_CK *chunk;
    s32 num_data;

    if (id < 0 || id >= 4) {
        if (sjuni->err_func != 0) {
            sjuni->err_func(sjuni->err_obj, SJ_ERR_PRM);
        }

        return 0;
    }

    chunk = sjuni->unk18[id];
    num_data = 0;

    while (chunk != 0) {
        num_data += chunk->ck.len;
        chunk = chunk->next;
    }

    return num_data;
}

extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern void SJ_SplitChunk(SJCK *ck, s32 nbyte, SJCK *ck1, SJCK *ck2);

void SJUNI_GetChunk(SJUNI_OBJ *sjuni, s32 id, s32 nbyte, SJCK *ck) {
    SJCK sjck0;
    SJCK sjck1;
    SJUNI_CK *cur;

    if (id < 0 || id >= 4) {
        if (sjuni->err_func != 0) {
            sjuni->err_func(sjuni->err_obj, SJ_ERR_PRM);
        }

        ck->data = 0;
        ck->len = 0;
        return;
    }

    ADXCRS_Lock();
    cur = sjuni->unk18[id];

    if (cur != 0) {
        sjck0 = cur->ck;

        if (nbyte >= sjck0.len) {
            *ck = sjck0;
            sjuni->unk18[id] = cur->next;
            cur->next = sjuni->chain_pool;
            sjuni->chain_pool = cur;
        } else if (sjuni->mode == SJUNI_MODE_JOIN) {
            SJ_SplitChunk(&sjck0, nbyte, &sjck0, &sjck1);
            *ck = sjck0;
            cur->ck = sjck1;
        } else {
            ck->data = 0;
            ck->len = 0;
        }
    } else {
        ck->data = 0;
        ck->len = 0;
    }

    ADXCRS_Unlock();
}

void SJUNI_UngetChunk(SJUNI_OBJ *sjuni, s32 id, SJCK *ck) {
    SJUNI_CK *temp;

    if (id < 0 || id >= 4) {
        if (sjuni->err_func != 0) {
            sjuni->err_func(sjuni->err_obj, SJ_ERR_PRM);
        }

        return;
    }

    if (ck->len <= 0 || ck->data == 0) {
        return;
    }

    ADXCRS_Lock();
    temp = sjuni->unk18[id];

    if (sjuni->mode == SJUNI_MODE_JOIN && temp != 0 && ck->data + ck->len == temp->ck.data) {
        temp->ck.data = ck->data;
        temp->ck.len += ck->len;
    } else {
        temp = sjuni->chain_pool;

        if (temp == 0) {
            if (sjuni->err_func != 0) {
                sjuni->err_func(sjuni->err_obj, SJ_ERR_PRM);
            }
        } else {
            sjuni->chain_pool = sjuni->chain_pool->next;
            temp->ck = *ck;
            temp->next = 0;
            temp->next = sjuni->unk18[id];
            sjuni->unk18[id] = temp;
        }
    }

    ADXCRS_Unlock();
}

s32 SJUNI_IsGetChunk(SJUNI_OBJ *sjuni, s32 id, s32 nbyte, s32 *rbyte) {
    SJCK ck;

    *rbyte = 0;

    if (id < 0 || id >= 4) {
        if (sjuni->err_func != 0) {
            sjuni->err_func(sjuni->err_obj, SJ_ERR_PRM);
        }

        return 0;
    }

    if (sjuni->unk18[id] == 0) {
        return 0;
    }

    ck = sjuni->unk18[id]->ck;
    *rbyte = ck.len;

    if (sjuni->mode == SJUNI_MODE_JOIN) {
        return ck.len >= nbyte;
    }

    return ck.len == nbyte;
}

void SJUNI_PutChunk(SJUNI_OBJ *sjuni, s32 id, SJCK *ck) {
    SJUNI_CK *last;
    SJUNI_CK *cur;
    SJUNI_CK **next_of_last;

    if (id < 0 || id >= 4) {
        if (sjuni->err_func != 0) {
            sjuni->err_func(sjuni->err_obj, SJ_ERR_PRM);
        }

        return;
    }

    if (ck->len <= 0 || ck->data == 0) {
        return;
    }

    ADXCRS_Lock();
    next_of_last = &sjuni->unk18[id];
    cur = *next_of_last;
    last = 0;

    while (cur != 0) {
        last = cur;
        cur = cur->next;
        next_of_last = &last->next;
    }

    if (sjuni->mode == SJUNI_MODE_JOIN && last != 0 && last->ck.data + last->ck.len == ck->data) {
        last->ck.len += ck->len;
    } else {
        last = sjuni->chain_pool;

        if (last == 0) {
            if (sjuni->err_func != 0) {
                sjuni->err_func(sjuni->err_obj, SJ_ERR_PRM);
            }
        } else {
            sjuni->chain_pool = sjuni->chain_pool->next;
            last->ck = *ck;
            last->next = 0;
            *next_of_last = last;
        }
    }

    ADXCRS_Unlock();
}
