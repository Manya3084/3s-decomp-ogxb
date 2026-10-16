/* ADXSJD_SetLnkSw 0x170160.
 * ADXSJD_ExecHndl 0x170700, ADXSJD_ExecServer 0x170730.
 *
 * lnkflg is a dword at +0x9C. adxb is the pointer at +4.
 * used is +0 and state is +1. The object is 0xA0 bytes.
 * ExecServer walks 10 objects from 0xCD5AA0 through 0xCD64A0.
 * ExecHndl sends state 2 to adxsjd_decode_exec and state 1 to 0x16FD00.
 * adxsjd_decode_exec is 0x170690. The format word is adxb+0x98.
 * Formats 0xA, 0x14, 0xB, 0xC, and 0xF call 0x1700F0.
 * adxsjd_decexec_end is 0x16FF90. sji is +8, sjo is +0x0C, unk14 is
 * +0x14, and chunks start at +0x1C. flt_func is +0x50. PutChunk is
 * vtable +0x20 and UngetChunk is +0x1C. SJ_SplitChunk is 0x171E90.
 */

#include "types.h"

#include <stddef.h>

#define ADXSJD_MAX_OBJ 10

typedef struct ADXB_OBJ {
    u8 gap00[0x98];
    s16 format;
} ADXB_OBJ;

typedef struct {
    s8 *data;
    s32 len;
} SJCK;

typedef struct SJ_VTBL SJ_VTBL;
typedef struct SJ_OBJ {
    SJ_VTBL *vtbl;
} SJ_OBJ;
typedef SJ_OBJ *SJ;

struct SJ_VTBL {
    void (*QueryInterface)(void);
    void (*AddRef)(void);
    void (*Release)(void);
    void (*Destroy)(SJ sj);
    void *(*GetUuid)(SJ sj);
    void (*Reset)(SJ sj);
    void (*GetChunk)(SJ sj, s32 id, s32 nbyte, SJCK *ck);
    void (*UngetChunk)(SJ sj, s32 id, SJCK *ck);
    void (*PutChunk)(SJ sj, s32 id, SJCK *ck);
};

#define SJ_UngetChunk(sj, id, ck) ((sj)->vtbl->UngetChunk)(sj, id, ck)
#define SJ_PutChunk(sj, id, ck) ((sj)->vtbl->PutChunk)(sj, id, ck)

typedef struct ADXSJD_OBJ {
    s8 used;
    s8 state;
    s8 maxnch;
    s8 unk3;
    ADXB_OBJ *adxb;
    SJ sji;
    SJ sjo[2];
    SJCK unk14;
    SJCK chunks[2];
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    u8 gap38[8];
    s32 trap_count;
    s32 trap_dt_len;
    u8 gap48[8];
    void (*flt_func)(void *obj, s32 ch, s8 *data, s32 len);
    void *flt_obj;
    u8 gap58[0x44];
    s32 lnkflg;
} ADXSJD_OBJ;

typedef ADXSJD_OBJ *ADXSJD;

#if defined(__i386__)
_Static_assert(offsetof(ADXB_OBJ, format) == 0x98, "format");
_Static_assert(offsetof(ADXSJD_OBJ, used) == 0, "used");
_Static_assert(offsetof(ADXSJD_OBJ, state) == 1, "state");
_Static_assert(offsetof(ADXSJD_OBJ, adxb) == 4, "adxb");
_Static_assert(offsetof(ADXSJD_OBJ, sji) == 8, "sji");
_Static_assert(offsetof(ADXSJD_OBJ, sjo) == 0x0C, "sjo");
_Static_assert(offsetof(ADXSJD_OBJ, unk14) == 0x14, "unk14");
_Static_assert(offsetof(ADXSJD_OBJ, chunks) == 0x1C, "chunks");
_Static_assert(offsetof(ADXSJD_OBJ, unk2C) == 0x2C, "unk2C");
_Static_assert(offsetof(ADXSJD_OBJ, unk30) == 0x30, "unk30");
_Static_assert(offsetof(ADXSJD_OBJ, unk34) == 0x34, "unk34");
_Static_assert(offsetof(ADXSJD_OBJ, trap_count) == 0x40, "trap_count");
_Static_assert(offsetof(ADXSJD_OBJ, trap_dt_len) == 0x44, "trap_dt_len");
_Static_assert(offsetof(ADXSJD_OBJ, flt_func) == 0x50, "flt_func");
_Static_assert(offsetof(ADXSJD_OBJ, flt_obj) == 0x54, "flt_obj");
_Static_assert(offsetof(ADXSJD_OBJ, lnkflg) == 0x9C, "lnkflg");
_Static_assert(sizeof(SJCK) == 8, "SJCK");
_Static_assert(offsetof(SJ_VTBL, UngetChunk) == 0x1C, "UngetChunk");
_Static_assert(offsetof(SJ_VTBL, PutChunk) == 0x20, "PutChunk");
_Static_assert(sizeof(ADXSJD_OBJ) == 0xA0, "ADXSJD_OBJ");
#endif

void ADXSJD_SetLnkSw(ADXSJD sjd, s32 sw) {
    sjd->lnkflg = sw;
}

/* GetSfreq 0x1701D0, GetNumChan 0x1701E0, GetOutBps 0x1701F0, and
 * GetTotalNumSmpl 0x170210. Each replaces its argument with adxb and tail-jumps.
 * ADXT_GetNumChan jumps to GetNumChan. ADXT_GetTimeSfreq2's PLAYEND path
 * stores GetTotalNumSmpl in *ncount, stores GetSfreq in *tscale, and
 * divides 16 by GetOutBps. The same-shaped thunks at 0x1701C0
 * and 0x170200 stay unnamed. The ADXB callees are named in adx_bsc.c.
 */

extern s32 ADXB_GetSfreq(void *adxb);
extern s32 ADXB_GetNumChan(void *adxb);
extern s32 ADXB_GetOutBps(void *adxb);
extern s32 ADXB_GetTotalNumSmpl(void *adxb);

s32 ADXSJD_GetSfreq(ADXSJD sjd) {
    return ADXB_GetSfreq(sjd->adxb);
}

s32 ADXSJD_GetNumChan(ADXSJD sjd) {
    return ADXB_GetNumChan(sjd->adxb);
}

s32 ADXSJD_GetOutBps(ADXSJD sjd) {
    return ADXB_GetOutBps(sjd->adxb);
}

s32 ADXSJD_GetTotalNumSmpl(ADXSJD sjd) {
    return ADXB_GetTotalNumSmpl(sjd->adxb);
}

extern ADXSJD_OBJ adxsjd_obj[ADXSJD_MAX_OBJ];
extern s32 ADXB_GetStat(void *adxb);
extern s32 ADXB_GetDecDtLen(void *adxb);
extern s32 ADXB_GetDecNumSmpl(void *adxb);
extern void ADXB_Reset(void *adxb);
extern void ADXB_ExecHndl(void *adxb);
extern void SJ_SplitChunk(SJCK *ck, s32 nbyte, SJCK *ck1, SJCK *ck2);
extern void adxsjd_decexec_start(ADXSJD sjd);
extern void adxsjd_decexec_extra(ADXSJD sjd);
extern void adxsjd_decode_prep(ADXSJD sjd);

void adxsjd_decexec_end(ADXSJD sjd) {
    ADXB_OBJ *adxb;
    SJ sji;
    s32 total_num_smpl;
    s32 dec_dt_len;
    s32 dec_num_smpl;
    SJCK sp;
    SJCK sp10;
    s32 i;

    adxb = sjd->adxb;
    sji = sjd->sji;
    total_num_smpl = ADXB_GetTotalNumSmpl(adxb);
    dec_dt_len = ADXB_GetDecDtLen(adxb);
    dec_num_smpl = ADXB_GetDecNumSmpl(adxb);
    total_num_smpl -= sjd->unk34;

    if (dec_num_smpl >= total_num_smpl) {
        dec_num_smpl = total_num_smpl;
    }

    SJ_SplitChunk(&sjd->unk14, dec_dt_len, &sp, &sp10);
    SJ_PutChunk(sji, 0, &sp);
    SJ_UngetChunk(sji, 1, &sp10);

    for (i = 0; i < ADXB_GetNumChan(adxb); i++) {
        SJ_SplitChunk(&sjd->chunks[i], dec_num_smpl * 2, &sp, &sp10);

        if (sjd->flt_func != 0) {
            sjd->flt_func(sjd->flt_obj, i, sp.data, sp.len);
        }

        SJ_PutChunk(sjd->sjo[i], 1, &sp);
        SJ_UngetChunk(sjd->sjo[i], 0, &sp10);
    }

    sjd->unk2C += dec_num_smpl;
    sjd->unk30 += dec_dt_len;
    sjd->unk34 += dec_num_smpl;
    sjd->trap_count += dec_num_smpl;
    sjd->trap_dt_len += dec_dt_len;
    ADXB_Reset(adxb);
}

void adxsjd_decode_exec(ADXSJD sjd) {
    ADXB_OBJ *adxb;
    s16 format;

    adxb = sjd->adxb;

    if (ADXB_GetStat(adxb) == 0) {
        adxsjd_decexec_start(sjd);
    }

    ADXB_ExecHndl(adxb);

    if (ADXB_GetStat(adxb) == 3) {
        adxsjd_decexec_end(sjd);
    }

    format = adxb->format;

    if (format == 0xA || format == 0x14 || format == 0xB || format == 0xC || format == 0xF) {
        adxsjd_decexec_extra(sjd);
    }
}

void ADXSJD_ExecHndl(ADXSJD sjd) {
    s8 state;

    state = sjd->state;

    if (state == 2) {
        adxsjd_decode_exec(sjd);
    } else if (state == 1) {
        adxsjd_decode_prep(sjd);
    }
}

void ADXSJD_ExecServer(void) {
    s32 i;

    for (i = 0; i < ADXSJD_MAX_OBJ; i++) {
        if (adxsjd_obj[i].used == 1) {
            ADXSJD_ExecHndl(&adxsjd_obj[i]);
        }
    }
}
