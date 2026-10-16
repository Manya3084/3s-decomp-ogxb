/* adxt_stat_prep 0x1717E0.
 * ADXT_ExecRdErrChk 0x1719B0, ADXT_ExecRdCompChk 0x171A00,
 * ADXT_ExecHndl 0x171DF0.
 *
 * ercode is a word at +0x60. stat 6 is the error state. stm is +0x08,
 * pmode is +0x02, sjd is +0x04, rna is +0x0C, sjo is +0x18, maxdecsmpl
 * is the s32 at +0x48, pstwait_flag is +0x70, pstready_flag is +0x71,
 * pause_flag is +0x72, lsc is +0x94, tvofst is +0x9C, and svcnt is +0xA0.
 * adxt_vsync_cnt is 0x7A5374.
 *
 * Stat 3 calls 0x171900, stat 1 calls 0x171AD0, and stat 4 calls
 * 0x171970. Those three are not named yet. Stat 2 is adxt_stat_prep.
 * Stat 5 goes straight to the two checks. ADXSTM_GetStat is 0x16EC40
 * and is not named yet. Prep calls that same body. The renderer helpers
 * at 0x1707E0, 0x170800, and 0x170810 stay unnamed. LSC_GetStat is named
 * in lsc.c. ADXSJD_TermSupply and ADXSJD_GetBlkSmpl are named in
 * adx_sjd.c. ADXT_GetNumChan is named in adx_tlk.c. Prep's clear of the
 * output chunk is an inlined memset.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

#define ADXT_STAT_PLAYING 3
#define ADXT_STAT_ERROR 6

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

#define SJ_GetChunk(sj, id, nbyte, ck) ((sj)->vtbl->GetChunk)(sj, id, nbyte, ck)
#define SJ_PutChunk(sj, id, ck) ((sj)->vtbl->PutChunk)(sj, id, ck)

typedef struct ADX_TALK {
    s8 used;
    s8 stat;
    s8 pmode;
    s8 maxnch;
    void *sjd;
    void *stm;
    void *rna;
    u8 gap10[8];
    SJ sjo[2];
    u8 gap20[0x28];
    s32 maxdecsmpl;
    u8 gap4C[0x14];
    s16 ercode;
    u8 gap62[0x0E];
    s8 pstwait_flag;
    s8 pstready_flag;
    s8 pause_flag;
    u8 gap73[0x21];
    void *lsc;
    u8 gap98[4];
    s32 tvofst;
    s32 svcnt;
} ADX_TALK;

typedef ADX_TALK *ADXT;

#if defined(__i386__)
_Static_assert(offsetof(ADX_TALK, stat) == 1, "stat");
_Static_assert(offsetof(ADX_TALK, pmode) == 2, "pmode");
_Static_assert(offsetof(ADX_TALK, sjd) == 4, "sjd");
_Static_assert(offsetof(ADX_TALK, stm) == 8, "stm");
_Static_assert(offsetof(ADX_TALK, rna) == 0x0C, "rna");
_Static_assert(offsetof(ADX_TALK, sjo) == 0x18, "sjo");
_Static_assert(offsetof(ADX_TALK, maxdecsmpl) == 0x48, "maxdecsmpl");
_Static_assert(offsetof(ADX_TALK, ercode) == 0x60, "ercode");
_Static_assert(offsetof(ADX_TALK, pstwait_flag) == 0x70, "pstwait_flag");
_Static_assert(offsetof(ADX_TALK, pstready_flag) == 0x71, "pstready_flag");
_Static_assert(offsetof(ADX_TALK, pause_flag) == 0x72, "pause_flag");
_Static_assert(offsetof(ADX_TALK, lsc) == 0x94, "lsc");
_Static_assert(offsetof(ADX_TALK, tvofst) == 0x9C, "tvofst");
_Static_assert(offsetof(ADX_TALK, svcnt) == 0xA0, "svcnt");
_Static_assert(offsetof(SJ_VTBL, GetChunk) == 0x18, "GetChunk");
_Static_assert(offsetof(SJ_VTBL, PutChunk) == 0x20, "PutChunk");
#endif

extern void ADXERR_CallErrFunc1(const char *msg);
extern s32 ADXT_GetStat(ADXT adxt);
extern s32 ADXT_GetNumChan(ADXT adxt);
extern s32 ADXSTM_GetStat(void *stm);
extern s32 LSC_GetStat(void *lsc);
extern void ADXSJD_TermSupply(void *sjd);
extern s32 ADXSJD_GetBlkSmpl(void *sjd);
extern s32 sub_00170800(void *rna);
extern s32 sub_00170810(void *rna);
extern void sub_001707E0(void *rna, s32 sw);
extern s32 sub_0016EC40(void *obj);
extern s32 adxt_vsync_cnt;
extern void sub_00171900(ADXT adxt);
extern void sub_00171AD0(ADXT adxt);
extern void sub_00171970(ADXT adxt);

void ADXT_ExecRdErrChk(ADXT adxt) {
    if (adxt->stm != 0 && ADXSTM_GetStat(adxt->stm) == 4) {
        adxt->ercode = -1;
        adxt->stat = ADXT_STAT_ERROR;
    }

    if (adxt->lsc != 0 && LSC_GetStat(adxt->lsc) == 3) {
        adxt->ercode = -1;
        adxt->stat = ADXT_STAT_ERROR;
    }
}

void ADXT_ExecRdCompChk(ADXT adxt) {
    s8 pmode;

    if (adxt->stm == 0 || ADXT_GetStat(adxt) == 0) {
        return;
    }

    pmode = adxt->pmode;

    if (pmode < 0) {
        return;
    }

    if (pmode <= 1) {
        if (ADXSTM_GetStat(adxt->stm) == 3) {
            ADXSJD_TermSupply(adxt->sjd);
        }
        return;
    }

    if (pmode == 2) {
        ADXSJD_TermSupply(adxt->sjd);
    }
}

void adxt_stat_prep(ADXT adxt) {
    void *rna;
    void *sjd;
    s32 num_data;
    s32 num_room;
    s32 num_chan;
    s32 i;
    s32 size;
    SJCK chunk_info;

    rna = adxt->rna;
    sjd = adxt->sjd;
    num_data = sub_00170800(rna);
    num_room = sub_00170810(rna);

    if ((num_data >= (adxt->maxdecsmpl << 1)) || (ADXSJD_GetBlkSmpl(sjd) >= num_room) ||
        (sub_0016EC40(adxt->sjd) == 3)) {
        if (adxt->pstwait_flag == 0) {
            if (adxt->pause_flag == 0) {
                sub_001707E0(rna, 1);
                adxt->tvofst = 0;
                adxt->svcnt = adxt_vsync_cnt;
            }

            adxt->stat = ADXT_STAT_PLAYING;
        }

        adxt->pstready_flag = 1;
    }

    if (sub_0016EC40(adxt->sjd) != 3) {
        return;
    }

    num_chan = ADXT_GetNumChan(adxt);
    size = (adxt->maxdecsmpl * num_chan) << 1;

    for (i = 0; i < num_chan; i++) {
        SJ sj_obj = adxt->sjo[i];

        SJ_GetChunk(sj_obj, 0, size, &chunk_info);
        memset(chunk_info.data, 0, (size_t)chunk_info.len);
        SJ_PutChunk(sj_obj, 1, &chunk_info);
    }
}

void ADXT_ExecHndl(ADXT adxt) {
    s8 stat;

    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080842 ADXT_ExecHndl: parameter error");
        return;
    }

    stat = adxt->stat;

    if (stat == 3) {
        sub_00171900(adxt);
    } else if (stat == 1) {
        sub_00171AD0(adxt);
    } else if (stat == 2) {
        adxt_stat_prep(adxt);
    } else if (stat == 4) {
        sub_00171970(adxt);
    }

    ADXT_ExecRdCompChk(adxt);
    ADXT_ExecRdErrChk(adxt);
}
