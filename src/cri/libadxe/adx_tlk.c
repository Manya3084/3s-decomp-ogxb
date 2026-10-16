/* ADXT_Stop 0x167AC0, ADXT_GetStat 0x167B40, ADXT_GetTimeSfreq2 0x167B60,
 * ADXT_GetTime 0x167C10, ADXT_GetNumChan 0x167DC0, ADXT_SetOutVol 0x167DF0,
 * ADXT_Pause 0x167EF0, ADXT_GetStatPause 0x167FC0, ADXT_SetLnkSw 0x168080.
 *
 * Xbox ADXT fields used here: stat +0x01, pmode +0x02, sjd +0x04, stm +0x08,
 * rna +0x0C, sji +0x14, outvol +0x40 (a word), pause_flag +0x72, time_ofst
 * +0x88, lsc +0x94, lnkflg +0x98 (a byte), tvofst +0x9C, svcnt +0xA0.
 * tvofst is the truncated integer of the float expression, and
 * adxt_time_unit (0xCE9B64) is read as an integer. adxt_diff_av is the float
 * at 0xCE9B60. ADXSJD_SetLnkSw is 0x170160 and stores a dword at sjd+0x9C.
 * adxt_time_mode is 0x7A5330. adxt_vsync_cnt is 0x7A5374.
 * ac3stopfunc is 0x7A5344.
 *
 * GetTimeSfreq2 adds time_ofst on every path and does not add a second
 * offset. Stat 3 and 4 call 0x1707F0, a jump to the unnamed body at
 * 0x16C050. The scanner splits GetTimeSfreq2 at 0x167C00: the C2 inside
 * `add eax, edx` sits in front of a 16-byte-aligned address. The ret is
 * 0x167C02.
 * GetTime's out-of-range path calls that same helper and stores the
 * truncated quotient in tvofst. It does not test an adjust switch or
 * recurse. 1000.0f is 0x219620, 60.0f is 0x2B4E30, and -60.0f is 0x2DF954.
 * _ftol is 0x175B40 and is not named.
 *
 * On the pause path (sw == 1) this build also calls 0x16BF80. That function
 * is not named yet. A null argument there reports
 * "E1205:Illegal parameter (MWRNA=NULL)".
 * ADXRNA_SetPlaySw's thunk is 0x1707E0.
 * ADXSJD_Stop is 0x16FCE0, ADXSTM_ReleaseFileNw is 0x16E4C0, LSC_Stop is
 * 0x170AE0, ADXT_StopWithoutLsc is 0x167A40, ADXSJD_GetDefOutVol is 0x170280,
 * and ADXRNA_SetOutVol is 0x170850. Those callees are not named yet.
 * SJ_Reset is the vtable slot at +0x14.
 */

#include "types.h"

#include <stddef.h>

#define ADXT_ERR_SHRTBUF (-1)
#define ADXT_PMODE_SLFILE 4

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
};

#define SJ_Reset(sj) ((sj)->vtbl->Reset)(sj)

typedef struct ADX_TALK {
    s8 used;
    s8 stat;
    s8 pmode;
    s8 maxnch;
    void *sjd;
    void *stm;
    void *rna;
    void *sjf;
    SJ sji;
    u8 gap18[0x28];
    s16 outvol;
    u8 gap42[0x30];
    s8 pause_flag;
    u8 gap73[0x15];
    s32 time_ofst;
    u8 gap8C[8];
    void *lsc;
    s8 lnkflg;
    u8 gap99[3];
    s32 tvofst;
    s32 svcnt;
} ADX_TALK;

#if defined(__i386__)
_Static_assert(offsetof(SJ_VTBL, Reset) == 0x14, "SJ_Reset");
_Static_assert(offsetof(ADX_TALK, stat) == 0x01, "stat");
_Static_assert(offsetof(ADX_TALK, pmode) == 0x02, "pmode");
_Static_assert(offsetof(ADX_TALK, sjd) == 0x04, "sjd");
_Static_assert(offsetof(ADX_TALK, stm) == 0x08, "stm");
_Static_assert(offsetof(ADX_TALK, rna) == 0x0C, "rna");
_Static_assert(offsetof(ADX_TALK, sji) == 0x14, "sji");
_Static_assert(offsetof(ADX_TALK, outvol) == 0x40, "outvol");
_Static_assert(offsetof(ADX_TALK, pause_flag) == 0x72, "pause_flag");
_Static_assert(offsetof(ADX_TALK, time_ofst) == 0x88, "time_ofst");
_Static_assert(offsetof(ADX_TALK, lsc) == 0x94, "lsc");
_Static_assert(offsetof(ADX_TALK, lnkflg) == 0x98, "lnkflg");
_Static_assert(offsetof(ADX_TALK, tvofst) == 0x9C, "tvofst");
_Static_assert(offsetof(ADX_TALK, svcnt) == 0xA0, "svcnt");
#endif

typedef struct ADX_TALK *ADXT;

extern s32 adxt_time_mode;
extern s32 adxt_vsync_cnt;
extern s32 adxt_time_unit;
extern f32 adxt_diff_av;

extern void ADXERR_CallErrFunc1(const char *msg);
extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern void ADXRNA_SetPlaySw(void *rna, s32 sw);
extern void ADXRNA_SetOutVol(void *rna, s32 vol);
extern void sub_0016BF80(void *rna);
extern void sub_001707F0(void *rna, s32 *ncount, s32 *tscale);
extern void (*ac3stopfunc)(ADXT adxt);
extern void ADXSJD_Stop(void *sjd);
extern void ADXSJD_SetLnkSw(void *sjd, s32 sw);
extern s32 ADXSJD_GetSfreq(void *sjd);
extern s32 ADXSJD_GetNumChan(void *sjd);
extern s32 ADXSJD_GetOutBps(void *sjd);
extern s32 ADXSJD_GetTotalNumSmpl(void *sjd);
extern s16 ADXSJD_GetDefOutVol(void *sjd);
extern void ADXSTM_ReleaseFileNw(void *stm);
extern void LSC_Stop(void *lsc);
extern void ADXT_StopWithoutLsc(ADXT adxt);

void ADXT_Stop(ADXT adxt) {
    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080813 ADXT_Stop: parameter error");
        return;
    }

    if (ac3stopfunc != 0) {
        ADXSJD_Stop(adxt->sjd);
        ac3stopfunc(adxt);
    }

    if (adxt->stm != 0) {
        ADXSTM_ReleaseFileNw(adxt->stm);
    }

    if (adxt->pmode == ADXT_PMODE_SLFILE) {
        LSC_Stop(adxt->lsc);

        if (adxt->sji != 0) {
            SJ_Reset(adxt->sji);
        }
    }

    ADXT_StopWithoutLsc(adxt);
}

s32 ADXT_GetStat(ADXT adxt) {
    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080814 ADXT_GetStat: parameter error");
        return ADXT_ERR_SHRTBUF;
    }

    return adxt->stat;
}

void ADXT_GetTimeSfreq2(ADXT adxt, s32 *ncount, s32 *tscale) {
    s8 stat = adxt->stat;

    if (stat == 3 || stat == 4) {
        sub_001707F0(adxt->rna, ncount, tscale);
    } else if (stat == 5) {
        *ncount = ADXSJD_GetTotalNumSmpl(adxt->sjd);
        *tscale = ADXSJD_GetSfreq(adxt->sjd);
        *ncount *= 16 / ADXSJD_GetOutBps(adxt->sjd);
    } else {
        *ncount = 0;
        *tscale = 1;
    }

    *ncount += adxt->time_ofst;
}

void ADXT_GetTime(ADXT adxt, s32 *ncount, s32 *tscale) {
    s32 samples;
    s32 sfreq;
    s8 stat;

    if (adxt == 0 || ncount == 0 || tscale == 0) {
        ADXERR_CallErrFunc1("E02080815 ADXT_GetTime: parameter error");
        return;
    }

    if (adxt_time_mode == 0) {
        ADXT_GetTimeSfreq2(adxt, ncount, tscale);
        return;
    }

    adxt_diff_av = 0.0f;
    stat = adxt->stat;

    if (stat == 3 || stat == 4) {
        if (adxt->pause_flag == 0) {
            *ncount = ((adxt_vsync_cnt - adxt->svcnt) * 100) + adxt->tvofst;
        } else {
            *ncount = adxt->tvofst;
        }

        ADXT_GetTimeSfreq2(adxt, &samples, &sfreq);
        adxt_diff_av = (((f32)samples / (f32)sfreq) - ((f32)*ncount / (f32)adxt_time_unit)) * 1000.0f;

        if (adxt_diff_av > 60.0f || adxt_diff_av < -60.0f) {
            sub_001707F0(adxt->rna, &samples, &sfreq);
            adxt->tvofst = (s32)((f32)samples / (f32)sfreq * (f32)adxt_time_unit);
            adxt->svcnt = adxt_vsync_cnt;
        }
    } else if (stat == 5) {
        samples = ADXSJD_GetTotalNumSmpl(adxt->sjd);
        sfreq = ADXSJD_GetSfreq(adxt->sjd);
        samples *= 16 / ADXSJD_GetOutBps(adxt->sjd);
        *ncount = (s32)((f32)samples / (f32)sfreq * (f32)adxt_time_unit) + adxt->tvofst + 1;
    } else {
        *ncount = 0;
    }

    *ncount += adxt->time_ofst;
    *tscale = adxt_time_unit;
}

s32 ADXT_GetNumChan(ADXT adxt) {
    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080820 ADXT_GetNumChan: parameter error");
        return -1;
    }

    if (adxt->stat < 2) {
        return 0;
    }

    return ADXSJD_GetNumChan(adxt->sjd);
}

void ADXT_SetOutVol(ADXT adxt, s32 vol) {
    s16 defvol;

    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080823 ADXT_SetOutVol: parameter error");
        return;
    }

    adxt->outvol = (s16)vol;
    defvol = ADXSJD_GetDefOutVol(adxt->sjd);
    ADXRNA_SetOutVol(adxt->rna, (s32)defvol + (s32)adxt->outvol);
}

void ADXT_Pause(ADXT adxt, s32 sw) {
    s32 ncount;
    s32 tscale;
    s32 time_mode_temp;
    s8 stat;

    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080846 ADXT_Pause: parameter error");
        return;
    }

    stat = adxt->stat;

    if (sw == adxt->pause_flag) {
        return;
    }

    ADXCRS_Lock();
    adxt->pause_flag = (s8)sw;

    if (stat == 3 || stat == 4) {
        if (sw == 1) {
            ADXRNA_SetPlaySw(adxt->rna, 0);
            sub_0016BF80(adxt->rna);
        } else {
            ADXRNA_SetPlaySw(adxt->rna, 1);
            adxt->svcnt = adxt_vsync_cnt;
        }

        time_mode_temp = adxt_time_mode;
        adxt_time_mode = 0;
        ADXT_GetTime(adxt, &ncount, &tscale);
        adxt_time_mode = time_mode_temp;
        adxt->tvofst = (s32)((f32)ncount / (f32)tscale * (f32)adxt_time_unit);
    }

    ADXCRS_Unlock();
}

void ADXT_SetLnkSw(ADXT adxt, s32 sw) {
    adxt->lnkflg = (s8)sw;

    if (adxt->sjd != 0) {
        ADXSJD_SetLnkSw(adxt->sjd, sw);
    }
}

s32 ADXT_GetStatPause(ADXT adxt) {
    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080847 ADXT_GetStatPause: parameter error");
        return 0;
    }

    return adxt->pause_flag;
}
