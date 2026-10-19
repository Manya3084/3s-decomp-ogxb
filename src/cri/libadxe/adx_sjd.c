/* ADXSJD_Init 0x16FB90. ADXSJD_Finish 0x16FBB0.
 * adxsjd_clear 0x16FBD0. ADXSJD_Destroy 0x16FC00.
 * ADXSJD_SetInSj 0x16FC40. ADXSJD_SetMaxDecSmpl 0x16FC70.
 * ADXSJD_TermSupply 0x16FCA0.
 * ADXSJD_Start 0x16FCC0. ADXSJD_Stop 0x16FCE0.
 * adxsjd_get_wr 0x16FEC0. ADXSJD_Create 0x170330.
 * ADXSJD_GetDecNumSmpl 0x170140.
 * ADXSJD_SetLnkSw 0x170160. ADXSJD_EntryTrapFunc 0x170170.
 * ADXSJD_SetTrapNumSmpl 0x170190. ADXSJD_SetTrapCnt 0x1701A0.
 * ADXSJD_SetTrapDtLen 0x1701B0. ADXSJD_GetFormat 0x1701C0.
 * ADXSJD_GetBlkSmpl 0x170200. ADXSJD_GetNumLoop 0x170220.
 * ADXSJD_GetDefOutVol 0x170280.
 * ADXSJD_GetDefPan 0x1702C0.
 * ADXSJD_ExecHndl 0x170700, ADXSJD_ExecServer 0x170730.
 *
 * lnkflg is a dword at +0x9C. adxb is the pointer at +4.
 * used is +0 and state is +1. The object is 0xA0 bytes.
 * ExecServer walks 16 objects from 0xCD5AA0 through 0xCD64A0.
 * ExecHndl sends state 2 to adxsjd_decode_exec and state 1 to
 * adxsjd_decode_prep at 0x16FD00. That prep asks SJ_GetChunk for
 * 0xC800 bytes. Formats 0xA, 0xB, 0xC, 0x14, and 0xF unget the
 * header chunk. It does not read unkE4. ADXB_DecodeHeader is 0x173770
 * in adx_bsc.c.
 * adxsjd_decode_exec is 0x170690. The format word is adxb+0x98.
 * Formats 0xA, 0x14, 0xB, 0xC, and 0xF call 0x1700F0.
 * adxsjd_decexec_end is 0x16FF90. sji is +8, sjo is +0x0C, unk14 is
 * +0x14, and chunks start at +0x1C. flt_func is +0x50. unk58 is +0x58
 * and unk98 is +0x98. PutChunk is vtable +0x20 and UngetChunk is
 * +0x1C. SJ_SplitChunk is named in sj_utl.c.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

#define ADXSJD_MAX_OBJ 16

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
    s32 (*GetNumData)(SJ sj, s32 id);
};

#define SJ_GetChunk(sj, id, nbyte, ck) ((sj)->vtbl->GetChunk)(sj, id, nbyte, ck)
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
    s32 unk38;
    s32 trap_num_samples;
    s32 trap_count;
    s32 trap_dt_len;
    void (*trap_func)(void *);
    void *trap_obj;
    void (*flt_func)(void *obj, s32 ch, s8 *data, s32 len);
    void *flt_obj;
    s8 unk58[0x40];
    s32 unk98;
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
_Static_assert(offsetof(ADXSJD_OBJ, unk38) == 0x38, "unk38");
_Static_assert(offsetof(ADXSJD_OBJ, trap_num_samples) == 0x3C, "trap_num_samples");
_Static_assert(offsetof(ADXSJD_OBJ, trap_count) == 0x40, "trap_count");
_Static_assert(offsetof(ADXSJD_OBJ, trap_dt_len) == 0x44, "trap_dt_len");
_Static_assert(offsetof(ADXSJD_OBJ, trap_func) == 0x48, "trap_func");
_Static_assert(offsetof(ADXSJD_OBJ, trap_obj) == 0x4C, "trap_obj");
_Static_assert(offsetof(ADXSJD_OBJ, flt_func) == 0x50, "flt_func");
_Static_assert(offsetof(ADXSJD_OBJ, flt_obj) == 0x54, "flt_obj");
_Static_assert(offsetof(ADXSJD_OBJ, unk58) == 0x58, "unk58");
_Static_assert(offsetof(ADXSJD_OBJ, unk98) == 0x98, "unk98");
_Static_assert(offsetof(ADXSJD_OBJ, lnkflg) == 0x9C, "lnkflg");
_Static_assert(sizeof(SJCK) == 8, "SJCK");
_Static_assert(offsetof(SJ_VTBL, GetChunk) == 0x18, "GetChunk");
_Static_assert(offsetof(SJ_VTBL, UngetChunk) == 0x1C, "UngetChunk");
_Static_assert(offsetof(SJ_VTBL, PutChunk) == 0x20, "PutChunk");
_Static_assert(sizeof(ADXSJD_OBJ) == 0xA0, "ADXSJD_OBJ");
#endif

extern void ADXB_Init(void);
extern ADXSJD_OBJ adxsjd_obj[ADXSJD_MAX_OBJ]; /* 0xCD5AA0 */

void ADXSJD_Init(void) {
    ADXB_Init();
    memset(adxsjd_obj, 0, sizeof(adxsjd_obj));
}

void ADXSJD_Finish(void) {
    memset(adxsjd_obj, 0, sizeof(adxsjd_obj));
}

void adxsjd_clear(ADXSJD sjd) {
    sjd->unk98 = 0;
    sjd->unk2C = 0;
    sjd->unk30 = 0;
    sjd->unk34 = 0;
    sjd->unk38 = 0x7FFFFFFF;
    sjd->trap_num_samples = -1;
    sjd->trap_count = 0;
    sjd->trap_dt_len = 0;
    sjd->unk3 = 0;
}

extern void ADXB_Destroy(ADXB_OBJ *adxb);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);

void ADXSJD_Destroy(ADXSJD sjd) {
    ADXB_OBJ *adxb;

    if (sjd == NULL) {
        return;
    }

    adxb = sjd->adxb;

    if (adxb != NULL) {
        sjd->adxb = NULL;
        ADXB_Destroy(adxb);
    }

    sub_0016AA60();
    memset(sjd, 0, sizeof(ADXSJD_OBJ));
    sub_0016AA70();
}

extern void ADXB_SetAhxInSj(void *adxb, SJ sj);
extern void ADXB_SetAc3InSj(void *adxb, SJ sj);

void ADXSJD_SetInSj(ADXSJD sjd, SJ sj) {
    sjd->sji = sj;
    ADXB_SetAhxInSj(sjd->adxb, sj);
    ADXB_SetAc3InSj(sjd->adxb, sj);
}

extern void ADXB_SetAhxDecSmpl(void *adxb, s32 samples);
extern void ADXB_SetAc3DecSmpl(void *adxb, s32 samples);

void ADXSJD_SetMaxDecSmpl(ADXSJD sjd, s32 samples) {
    sjd->unk38 = samples;
    ADXB_SetAhxDecSmpl(sjd->adxb, samples);
    ADXB_SetAc3DecSmpl(sjd->adxb, samples);
}

extern void ADXB_AhxTermSupply(void *adxb);
extern void ADXB_Ac3TermSupply(void *adxb);

void ADXSJD_TermSupply(ADXSJD sjd) {
    ADXB_AhxTermSupply(sjd->adxb);
    ADXB_Ac3TermSupply(sjd->adxb);
}

void ADXSJD_Start(ADXSJD sjd) {
    adxsjd_clear(sjd);
    sjd->state = 1;
}

extern void ADXB_Stop(ADXB_OBJ *adxb);

void ADXSJD_Stop(ADXSJD sjd) {
    ADXB_Stop(sjd->adxb);
    sjd->state = 0;
}

s32 ADXSJD_GetDecNumSmpl(ADXSJD sjd) {
    return sjd->unk2C;
}

void ADXSJD_SetLnkSw(ADXSJD sjd, s32 sw) {
    sjd->lnkflg = sw;
}

void ADXSJD_EntryTrapFunc(ADXSJD sjd, void (*func)(void *), void *obj) {
    sjd->trap_func = func;
    sjd->trap_obj = obj;
}

void ADXSJD_SetTrapNumSmpl(ADXSJD sjd, s32 samples) {
    sjd->trap_num_samples = samples;
}

void ADXSJD_SetTrapCnt(ADXSJD sjd, s32 cnt) {
    sjd->trap_count = cnt;
}

void ADXSJD_SetTrapDtLen(ADXSJD sjd, s32 dt_len) {
    sjd->trap_dt_len = dt_len;
}

/* GetFormat 0x1701C0, GetSfreq 0x1701D0, GetNumChan 0x1701E0,
 * GetOutBps 0x1701F0, GetBlkSmpl 0x170200, GetTotalNumSmpl 0x170210,
 * and GetNumLoop 0x170220. Each replaces its argument with adxb
 * and tail-jumps.
 * ADXT_GetNumChan jumps to GetNumChan. ADXT_GetTimeSfreq2's PLAYEND path
 * stores GetTotalNumSmpl in *ncount, stores GetSfreq in *tscale, and
 * divides 16 by GetOutBps. GetBlkSmpl and GetNumLoop are the same
 * shape. The ADXB callees are named in adx_bsc.c.
 */

extern s32 ADXB_GetFormat(void *adxb);
extern s32 sub_00172C60(void *adxb);
extern s32 ADXB_GetNumChan(void *adxb);
extern void *SJRBF_GetBufPtr(SJ sj);
extern void *ADXB_GetPcmBuf(void *adxb);
extern s32 ADXB_GetOutBps(void *adxb);
extern s32 sub_00172CE0(void *adxb);
extern s32 ADXB_GetTotalNumSmpl(void *adxb);
extern s32 ADXB_GetNumLoop(void *adxb);
extern s32 ADXB_GetAinfLen(void *adxb);
extern s16 ADXB_GetDefOutVol(void *adxb);
extern s16 ADXB_GetDefPan(void *adxb, s32 arg1);

s32 ADXSJD_GetFormat(ADXSJD sjd) {
    return ADXB_GetFormat(sjd->adxb);
}

s32 ADXSJD_GetSfreq(ADXSJD sjd) {
    return sub_00172C60(sjd->adxb);
}

s32 ADXSJD_GetNumChan(ADXSJD sjd) {
    return ADXB_GetNumChan(sjd->adxb);
}

s32 ADXSJD_GetOutBps(ADXSJD sjd) {
    return ADXB_GetOutBps(sjd->adxb);
}

s32 ADXSJD_GetBlkSmpl(ADXSJD sjd) {
    return sub_00172CE0(sjd->adxb);
}

s32 ADXSJD_GetTotalNumSmpl(ADXSJD sjd) {
    return ADXB_GetTotalNumSmpl(sjd->adxb);
}

s32 ADXSJD_GetNumLoop(ADXSJD sjd) {
    return ADXB_GetNumLoop(sjd->adxb);
}

void *adxsjd_get_wr(ADXSJD sjd, s32 *arg1, s32 *arg2, s32 *arg3) {
    SJ first_out;
    SJ *sjo;
    SJCK *chunk;
    s32 i;
    s32 len;
    s32 limit;

    first_out = sjd->sjo[0];
    sjo = sjd->sjo;
    chunk = sjd->chunks;

    for (i = 0; i < ADXB_GetNumChan(sjd->adxb); i++) {
        SJ_GetChunk(sjo[i], 0, 0x4000, &chunk[i]);
    }

    *arg1 = (s32)(sjd->chunks[0].data - (s8 *)SJRBF_GetBufPtr(first_out)) / 2;

    limit = sjd->unk38;
    len = sjd->chunks[0].len / 2;

    if (len < limit) {
        limit = len;
    }

    *arg2 = limit;

    if (sjd->trap_num_samples >= 0) {
        *arg3 = sjd->trap_num_samples - sjd->trap_count;
    } else {
        *arg3 = 0x1FFFFFFF;
    }

    return ADXB_GetPcmBuf(sjd->adxb);
}

extern s32 SJRBF_GetBufSize(SJ sj);
extern s32 SJRBF_GetXtrSize(SJ sj);
extern ADXB_OBJ *ADXB_Create(s32 maxnch, void *buf, s32 buf_size, s32 buf_size_xtr);
extern void ADXB_EntryGetWrFunc(void *adxb, void *(*get_wr)(ADXSJD sjd, s32 *arg1, s32 *arg2, s32 *arg3),
                                void *object);

ADXSJD ADXSJD_Create(SJ sj, s32 maxnch, SJ *sjo) {
    ADXSJD sjd;
    SJ out;
    void *buf_ptr;
    s32 i;
    s32 y;
    s32 buf_size;
    s32 xtr_size;

    out = sjo[0];

    for (i = 0; i < ADXSJD_MAX_OBJ; i++) {
        if (adxsjd_obj[i].used == 0) {
            break;
        }
    }

    if (i == ADXSJD_MAX_OBJ) {
        return NULL;
    }

    sjd = &adxsjd_obj[i];
    buf_ptr = SJRBF_GetBufPtr(out);
    buf_size = SJRBF_GetBufSize(out) / 2;
    xtr_size = SJRBF_GetXtrSize(out) / 2;
    sjd->adxb = ADXB_Create(maxnch, buf_ptr, buf_size, buf_size + xtr_size);

    if (sjd->adxb == NULL) {
        return NULL;
    }

    ADXB_EntryGetWrFunc(sjd->adxb, adxsjd_get_wr, sjd);
    sjd->sji = sj;
    sjd->maxnch = (s8)maxnch;

    for (y = 0; y < maxnch; y++) {
        sjd->sjo[y] = sjo[y];
    }

    sjd->state = 0;
    adxsjd_clear(sjd);
    sjd->trap_func = NULL;
    sjd->trap_obj = NULL;
    sjd->flt_func = NULL;
    sjd->flt_obj = NULL;
    sjd->used = 1;
    return sjd;
}

s16 ADXSJD_GetDefOutVol(ADXSJD sjd) {
    if (ADXB_GetAinfLen(sjd->adxb) > 0 && (sjd->state == 2 || sjd->state == 3)) {
        return ADXB_GetDefOutVol(sjd->adxb);
    }

    return 0;
}

s16 ADXSJD_GetDefPan(ADXSJD sjd, s32 arg1) {
    if (ADXB_GetAinfLen(sjd->adxb) > 0 && (sjd->state == 2 || sjd->state == 3)) {
        return ADXB_GetDefPan(sjd->adxb, arg1);
    }

    return -0x80;
}

extern ADXSJD_OBJ adxsjd_obj[ADXSJD_MAX_OBJ];
extern s32 ADXB_GetStat(void *adxb);
extern s32 ADXB_GetDecDtLen(void *adxb);
extern s32 ADXB_GetDecNumSmpl(void *adxb);
extern void ADXB_Reset(void *adxb);
extern void ADXB_ExecHndl(void *adxb);
extern s32 ADXB_GetFormat(void *adxb);
extern s32 ADXB_DecodeHeader(void *adxb, void *header, s32 len);
extern void ADXERR_CallErrFunc2(const char *msg, const char *detail);
extern void SJ_SplitChunk(SJCK *ck, s32 nbyte, SJCK *ck1, SJCK *ck2);
extern void adxsjd_decexec_extra(ADXSJD sjd);
extern s32 ADX_DecodeFooter(void *buf, s32 len, s16 *ofst);
extern void ADXB_EntryData(void *adxb, s8 *data, s32 len);
extern void ADXB_Start(void *adxb);

#define SJ_GetNumData(sj, id) ((sj)->vtbl->GetNumData)(sj, id)

/* adxsjd_decexec_start 0x170440.
 *
 * The PS2 decomp's portable C, read against the x86 (format 0x14
 * replaces the PS2's 0xF): runs the trap callback once its sample count
 * is reached, then hands the decoder its next input chunk. At an ADX
 * footer (0x8001) it ends the stream, passes the footer on and, when
 * linking, skips the zero padding to the next file's header. */

void adxsjd_decexec_start(ADXSJD sjd) {
    void *adxb = sjd->adxb;
    SJ sji = sjd->sji;
    SJCK sp;
    s16 flen;
    s32 n;
    s32 more;

    if (sjd->trap_num_samples >= 0 && sjd->trap_count >= sjd->trap_num_samples && sjd->trap_func != 0) {
        sjd->trap_func(sjd->trap_obj);
    }

    if (sjd->unk3 == 1 && SJ_GetNumData(sji, 1) == 0) {
        sjd->state = 3;
        return;
    }

    SJ_GetChunk(sji, 1, 0x7FFFFFFF, &sjd->unk14);

    if (ADXB_GetFormat(adxb) == 0 && sjd->unk14.len >= 4 &&
        (((u8 *)sjd->unk14.data)[0] << 8 | ((u8 *)sjd->unk14.data)[1]) == 0x8001) {
        sjd->state = 3;

        if (ADX_DecodeFooter(sjd->unk14.data, sjd->unk14.len, &flen) == 0) {
            if (flen > sjd->unk14.len) {
                SJ_UngetChunk(sji, 1, &sjd->unk14);
                return;
            }

            SJ_SplitChunk(&sjd->unk14, flen, &sjd->unk14, &sp);
            SJ_PutChunk(sji, 0, &sjd->unk14);
            SJ_UngetChunk(sji, 1, &sp);
        }

        if (sjd->lnkflg == 0) {
            return;
        }

        for (;;) {
            SJ_GetChunk(sji, 1, 0x7FFFFFFF, &sjd->unk14);

            if (sjd->unk14.len == 0) {
                return;
            }

            for (n = 0; n < sjd->unk14.len && sjd->unk14.data[n] == 0; n++) {
            }

            more = n < sjd->unk14.len;
            SJ_SplitChunk(&sjd->unk14, n, &sjd->unk14, &sp);
            SJ_PutChunk(sji, 0, &sjd->unk14);
            SJ_UngetChunk(sji, 1, &sp);

            if (more) {
                return;
            }
        }
    }

    if (sjd->unk34 >= ADXSJD_GetTotalNumSmpl(sjd)) {
        sjd->state = 3;
        SJ_UngetChunk(sji, 1, &sjd->unk14);
        return;
    }

    if (ADXSJD_GetBlkSmpl(sjd) > SJ_GetNumData(sjd->sjo[0], 0) / 2) {
        SJ_UngetChunk(sji, 1, &sjd->unk14);
        return;
    }

    if (ADXB_GetFormat(adxb) == 0xA) {
        SJ_UngetChunk(sji, 1, &sjd->unk14);
    }

    if (ADXB_GetFormat(adxb) == 0x14) {
        SJ_UngetChunk(sji, 1, &sjd->unk14);
    }

    ADXB_EntryData(adxb, sjd->unk14.data, sjd->unk14.len);
    ADXB_Start(adxb);
}

void adxsjd_decode_prep(ADXSJD sjd) {
    SJCK ck_0;
    SJCK ck_1;
    s32 header_len;
    s32 format;
    s32 nbyte;
    s8 state;
    SJ sji = sjd->sji;
    ADXB_OBJ *adxb = sjd->adxb;

    SJ_GetChunk(sji, 1, 0xC800, &ck_0);

    for (nbyte = 0; nbyte < ck_0.len; nbyte++) {
        if (ck_0.data[nbyte] != 0) {
            break;
        }
    }

    SJ_SplitChunk(&ck_0, nbyte, &ck_1, &ck_0);
    SJ_PutChunk(sji, 0, &ck_1);

    if (ck_0.len < 16) {
        SJ_UngetChunk(sji, 1, &ck_0);
        return;
    }

    header_len = ADXB_DecodeHeader(adxb, ck_0.data, ck_0.len);

    if ((header_len == 0) || (ck_0.len < header_len)) {
        SJ_UngetChunk(sji, 1, &ck_0);
        return;
    }

    if (header_len < 0) {
        SJ_UngetChunk(sji, 1, &ck_0);
        ADXERR_CallErrFunc2("E03010901 ADXB_DecodeHeader: ", "Can not decode this file format.");
        state = 4;
    } else {
        sjd->unk98 = header_len;

        if (ADXB_GetFormat(adxb) == 4) {
            sjd->unk3 = 1;
        }

        if (ADXB_GetFormat(adxb) == 2) {
            memcpy(sjd->unk58, ck_0.data, (ck_0.len < 0x40) ? (size_t)ck_0.len : 0x40);
        }

        format = ADXB_GetFormat(adxb);

        if ((format == 0xA) || (format == 0xB) || (format == 0xC) || (format == 0x14) || (format == 0xF)) {
            SJ_UngetChunk(sji, 1, &ck_0);
        } else {
            SJ_SplitChunk(&ck_0, header_len, &ck_0, &ck_1);
            SJ_PutChunk(sji, 0, &ck_0);
            SJ_UngetChunk(sji, 1, &ck_1);
        }

        state = 2;
    }

    sjd->state = state;
}

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

/* adxsjd_decexec_extra 0x1700F0, ADXSJD_SetDecPos 0x170150,
 * ADXSJD_GetLpStartPos 0x170230, ADXSJD_GetLpStartOfst 0x170240,
 * ADXSJD_GetLpEndPos 0x170260 (ADXB_GetLpEndPos is folded at 0x16D550),
 * ADXSJD_GetLpEndOfst 0x170270, ADXSJD_GetSpsdInfo 0x170300,
 * ADXSJD_TakeSnapshot 0x170310, ADXSJD_RestoreSnapshot 0x170320. */

extern s32 ADXB_GetLpStartPos(void *adxb);
extern s32 ADXB_GetLpStartOfst(void *adxb);
extern s32 ADXB_GetLpEndPos(void *adxb);
extern s32 ADXB_GetLpEndOfst(void *adxb);
extern void ADXB_TakeSnapshot(void *adxb);
extern void ADXB_RestoreSnapshot(void *adxb);

void adxsjd_decexec_extra(ADXSJD sjd) {
    ADXB_OBJ *adxb = sjd->adxb;
    s32 total = ADXB_GetTotalNumSmpl(adxb);
    s32 dtlen = ADXB_GetDecDtLen(adxb);
    s32 nsmpl = ADXB_GetDecNumSmpl(adxb);
    s32 pos = sjd->unk34;

    if (nsmpl >= total - pos) {
        nsmpl = total - pos;
    }

    sjd->unk2C += nsmpl;
    sjd->unk30 += dtlen;
    sjd->unk34 = pos + nsmpl;
}

void ADXSJD_SetDecPos(ADXSJD sjd, s32 pos) {
    sjd->unk34 = pos;
}

s32 ADXSJD_GetLpStartPos(ADXSJD sjd) {
    return ADXB_GetLpStartPos(sjd->adxb);
}

s32 ADXSJD_GetLpStartOfst(ADXSJD sjd) {
    if (sjd == 0) {
        return 0;
    }

    return ADXB_GetLpStartOfst(sjd->adxb);
}

s32 ADXSJD_GetLpEndPos(ADXSJD sjd) {
    return ADXB_GetLpEndPos(sjd->adxb);
}

s32 ADXSJD_GetLpEndOfst(ADXSJD sjd) {
    return ADXB_GetLpEndOfst(sjd->adxb);
}

void *ADXSJD_GetSpsdInfo(ADXSJD sjd) {
    return sjd->unk58;
}

void ADXSJD_TakeSnapshot(ADXSJD sjd) {
    ADXB_TakeSnapshot(sjd->adxb);
}

void ADXSJD_RestoreSnapshot(ADXSJD sjd) {
    ADXB_RestoreSnapshot(sjd->adxb);
}
