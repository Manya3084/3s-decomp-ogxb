/* ADXAMP_Destroy 0x16FA10. ADXAMP_Start 0x16FA30. ADXAMP_Stop 0x16FB70.
 *
 * The object is 0x30 bytes. unk1 is the byte at +1, unk2 is the byte at
 * +2, the first SJ list is +4, the second is +0xC, unk14 is +0x14, and
 * unk2C is +0x2C. adxt_start_sj is the only caller of Start.
 * Stop stores 0 at unk1. ADXT_StopWithoutLsc calls it, and so does
 * the unnamed body at 0x1671E0.
 * Destroy locks, clears the object, and tail-jumps to ADXCRS_Unlock.
 * ADXT_Destroy is the only caller. A null handle returns.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

typedef struct {
    void *data;
    s32 len;
} SJCK;

typedef struct SJ_OBJ SJ_OBJ;
typedef SJ_OBJ *SJ;

typedef struct {
    void (*QueryInterface)(void);
    void (*AddRef)(void);
    void (*Release)(void);
    void (*Destroy)(SJ sj);
    void *(*GetUuid)(SJ sj);
    void (*Reset)(SJ sj);
    void (*GetChunk)(SJ sj, s32 id, s32 nbyte, SJCK *ck);
    void (*UngetChunk)(SJ sj, s32 id, SJCK *ck);
    void (*PutChunk)(SJ sj, s32 id, SJCK *ck);
    s32 (*GetNumData)(SJ sj, s32 id);
} SJ_VTBL;

struct SJ_OBJ {
    SJ_VTBL *vtbl;
};

#define SJ_Reset(sj) ((sj)->vtbl->Reset)(sj)
#define SJ_GetChunk(sj, id, nbyte, ck) ((sj)->vtbl->GetChunk)(sj, id, nbyte, ck)
#define SJ_UngetChunk(sj, id, ck) ((sj)->vtbl->UngetChunk)(sj, id, ck)
#define SJ_GetNumData(sj, id) ((sj)->vtbl->GetNumData)(sj, id)

typedef struct {
    char pad0[1];
    s8 unk1;
    s8 unk2;
    char pad3[1];
    SJ unk4[1];
    char pad8[4];
    SJ unkC[1];
    char pad10[4];
    s32 unk14[6];
    s32 unk2C;
} ADXAMP_OBJ;

typedef ADXAMP_OBJ *ADXAMP;

#if defined(__i386__)
_Static_assert(offsetof(SJ_VTBL, Reset) == 0x14, "Reset");
_Static_assert(offsetof(SJ_VTBL, GetChunk) == 0x18, "GetChunk");
_Static_assert(offsetof(SJ_VTBL, UngetChunk) == 0x1C, "UngetChunk");
_Static_assert(offsetof(SJ_VTBL, GetNumData) == 0x24, "GetNumData");
_Static_assert(offsetof(SJCK, len) == 4, "SJCK.len");
_Static_assert(sizeof(SJCK) == 8, "SJCK");
_Static_assert(offsetof(ADXAMP_OBJ, unk1) == 1, "unk1");
_Static_assert(offsetof(ADXAMP_OBJ, unk2) == 2, "unk2");
_Static_assert(offsetof(ADXAMP_OBJ, unk4) == 4, "unk4");
_Static_assert(offsetof(ADXAMP_OBJ, unkC) == 0x0C, "unkC");
_Static_assert(offsetof(ADXAMP_OBJ, unk14) == 0x14, "unk14");
_Static_assert(offsetof(ADXAMP_OBJ, unk2C) == 0x2C, "unk2C");
_Static_assert(sizeof(ADXAMP_OBJ) == 0x30, "ADXAMP_OBJ");
#endif

void ADXAMP_Start(ADXAMP amp) {
    s32 i;
    SJ sj;
    SJCK ck;

    for (i = 0; i < amp->unk2; i++) {
        amp->unk14[i] = 0;
    }

    amp->unk2C = 0;

    for (i = 0; i < amp->unk2; i++) {
        sj = amp->unk4[i];
        SJ_Reset(sj);
        SJ_GetChunk(sj, 0, SJ_GetNumData(sj, 0), &ck);
        memset(ck.data, 0, (size_t)ck.len);
        SJ_UngetChunk(sj, 0, &ck);
    }

    for (i = 0; i < amp->unk2; i++) {
        sj = amp->unkC[i];
        SJ_Reset(sj);
        SJ_GetChunk(sj, 0, SJ_GetNumData(sj, 0), &ck);
        memset(ck.data, 0, (size_t)ck.len);
        SJ_UngetChunk(sj, 0, &ck);
    }

    amp->unk1 = 2;
}

void ADXAMP_Stop(ADXAMP amp) {
    amp->unk1 = 0;
}

extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);

void ADXAMP_Destroy(ADXAMP amp) {
    if (amp != 0) {
        ADXCRS_Lock();
        memset(amp, 0, sizeof(ADXAMP_OBJ));
        ADXCRS_Unlock();
    }
}
