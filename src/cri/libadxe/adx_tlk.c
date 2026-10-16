/* adxt_start_sj 0x167910, ADXT_Stop 0x167AC0, ADXT_GetStat 0x167B40,
 * ADXT_GetTimeSfreq2 0x167B60, ADXT_GetTime 0x167C10, ADXT_GetNumChan 0x167DC0,
 * ADXT_SetOutVol 0x167DF0,
 * ADXT_Pause 0x167EF0, ADXT_GetStatPause 0x167FC0, ADXT_SetLnkSw 0x168080,
 * ADXT_Destroy 0x1680C0, ADXT_Create 0x168240.
 *
 * Xbox ADXT fields used here: stat +0x01, pmode +0x02, maxnch +0x03, sjd
 * +0x04, stm +0x08, rna +0x0C, sjf +0x10, sji +0x14, sjo +0x18, ibuf +0x20,
 * ibuflen +0x24, ibufxlen +0x28, obuf +0x2C, obufsize +0x30, obufdist
 * +0x34, svrfreq +0x38, maxsct +0x3C, minsct +0x3E, outvol +0x40 (a word),
 * outpan +0x42, unk46 +0x46, trp +0x54, wpos +0x58, mofst +0x5C, ercode
 * +0x60 (a word), edecpos +0x64, edeccnt +0x68, eshrtcnt +0x6A, lpflg
 * +0x6C, autorcvr +0x6D, pause_flag +0x72, amp +0x74, ampsji +0x78, ampsjo
 * +0x80, time_ofst +0x88, lsc +0x94, lnkflg +0x98 (a byte), tvofst +0x9C,
 * svcnt +0xA0, fname +0xAC. The object is 0xC0 bytes. Sixteen of them
 * start at 0xCE8F60.
 * tvofst is the truncated integer of the float expression, and
 * adxt_time_unit (0xCE9B64) is read as an integer. adxt_diff_av is the float
 * at 0xCE9B60. ADXSJD_SetLnkSw is 0x170160 and stores a dword at sjd+0x9C.
 * adxt_time_mode is 0x7A5330. adxt_vsync_cnt is 0x7A5374.
 * ac3stopfunc is 0x7A5344. adxt_def_svrfreq is 0x7A5338.
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
 * 0x170AE0, ADXSJD_GetDefOutVol is 0x170280, and ADXRNA_SetOutVol is
 * 0x170850. Those callees are not named yet.
 * SJ_Reset is the vtable slot at +0x14. SJ_Destroy is the slot at +0x0C.
 *
 * Create aligns work to 0x40 bytes. The input length is
 * (size - maxnch * 0x40C0 - 0x124) rounded down to 2048. 0x40C0 is
 * obufdist 0x2060 times sizeof(s16). A full table reports
 * "E03100801 ADXT_Create: Too many handles.\n". A channel count of 4 is
 * left as 4. The stored maxnch is the low 8 bits. The sjo and outpan
 * loops count the full argument, and each array has two slots. minsct is
 * the truncated product of maxsct and 0.85f, the constant at 0x2BBBBC.
 * fname at +0xAC receives ibuf + ibuflen + ibufxlen.
 * Destroy calls 0x1678F0 and 0x167900. Those two stay unnamed. Stream
 * teardown calls ADXSTM_EntryEosFunc at 0x16DFD0, then ADXSTM_Destroy at
 * 0x16E520. The other create and destroy callees below stay unnamed.
 * The jmp at 0x1680B0 stays unnamed.
 *
 * adxt_start_sj is 0x167910. It resets each sjo, stores the input SJ,
 * and sets stat to 1. lesct at +0x8C becomes 0x7FFFFFFF and trpnsmpl at
 * +0x90 becomes -1. lpcnt is +0x4C, pstready_flag is +0x71, and decofst
 * is +0xA4. ADXSJD_SetInSj is 0x16FC40, ADXSJD_Start is 0x16FCC0, and
 * ADXAMP_Start is 0x16FA30. Those three stay unnamed.
 *
 * adxt_start_stm is 0x1679B0. SetBufSize gets minsct and maxsct shifted
 * left by 11. SetEos reads 0x43C8D0, which is initialized to 25.
 * ADXT_StopWithoutLsc is 0x167A40. It calls 0x1707C0 with the renderer,
 * 0x1707D0 with 0, and ADXRNA_SetPlaySw with 0. There is no discard
 * call with 1. ADXAMP_Stop is 0x16FB70 and stays unnamed. unkA8 is cleared.
 */

#include "types.h"

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define ADXT_ERR_SHRTBUF (-1)
#define ADXT_STAT_DECINFO 1
#define ADXT_PMODE_MEM 2
#define ADXT_PMODE_SLFILE 4
#define ADXT_MAX_OBJ 16
#define ADXT_IBUF_XLEN 0x24
#define ADXT_OBUF_SIZE 0x2000
#define ADXT_OBUF_DIST 0x2060
#define ADXT_PAN_AUTO ((s16)-128)

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
#define SJ_Destroy(sj) ((sj)->vtbl->Destroy)(sj)

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
    SJ sjo[2];
    char *ibuf;
    s32 ibuflen;
    s32 ibufxlen;
    s16 *obuf;
    s32 obufsize;
    s32 obufdist;
    s32 svrfreq;
    s16 maxsct;
    s16 minsct;
    s16 outvol;
    s16 outpan[2];
    s16 unk46;
    u8 gap48[4];
    s32 lpcnt;
    u8 gap50[4];
    s32 trp;
    s32 wpos;
    s32 mofst;
    s16 ercode;
    u8 gap62[2];
    s32 edecpos;
    s16 edeccnt;
    s16 eshrtcnt;
    s8 lpflg;
    s8 autorcvr;
    u8 gap6E[3];
    s8 pstready_flag;
    s8 pause_flag;
    u8 gap73[1];
    void *amp;
    SJ ampsji[2];
    SJ ampsjo[2];
    s32 time_ofst;
    s32 lesct;
    s32 trpnsmpl;
    void *lsc;
    s8 lnkflg;
    u8 gap99[3];
    s32 tvofst;
    s32 svcnt;
    s32 decofst;
    s8 unkA8;
    u8 gapA9[3];
    char *fname;
    char *fname_copy;
    void *dir;
    s32 ofst;
    s32 fnsct;
} ADX_TALK;

#if defined(__i386__)
_Static_assert(offsetof(SJ_VTBL, Destroy) == 0x0C, "SJ_Destroy");
_Static_assert(offsetof(SJ_VTBL, Reset) == 0x14, "SJ_Reset");
_Static_assert(offsetof(ADX_TALK, stat) == 0x01, "stat");
_Static_assert(offsetof(ADX_TALK, pmode) == 0x02, "pmode");
_Static_assert(offsetof(ADX_TALK, maxnch) == 0x03, "maxnch");
_Static_assert(offsetof(ADX_TALK, sjd) == 0x04, "sjd");
_Static_assert(offsetof(ADX_TALK, stm) == 0x08, "stm");
_Static_assert(offsetof(ADX_TALK, rna) == 0x0C, "rna");
_Static_assert(offsetof(ADX_TALK, sjf) == 0x10, "sjf");
_Static_assert(offsetof(ADX_TALK, sji) == 0x14, "sji");
_Static_assert(offsetof(ADX_TALK, sjo) == 0x18, "sjo");
_Static_assert(offsetof(ADX_TALK, ibuf) == 0x20, "ibuf");
_Static_assert(offsetof(ADX_TALK, ibuflen) == 0x24, "ibuflen");
_Static_assert(offsetof(ADX_TALK, ibufxlen) == 0x28, "ibufxlen");
_Static_assert(offsetof(ADX_TALK, obuf) == 0x2C, "obuf");
_Static_assert(offsetof(ADX_TALK, obufsize) == 0x30, "obufsize");
_Static_assert(offsetof(ADX_TALK, obufdist) == 0x34, "obufdist");
_Static_assert(offsetof(ADX_TALK, svrfreq) == 0x38, "svrfreq");
_Static_assert(offsetof(ADX_TALK, maxsct) == 0x3C, "maxsct");
_Static_assert(offsetof(ADX_TALK, minsct) == 0x3E, "minsct");
_Static_assert(offsetof(ADX_TALK, outvol) == 0x40, "outvol");
_Static_assert(offsetof(ADX_TALK, outpan) == 0x42, "outpan");
_Static_assert(offsetof(ADX_TALK, unk46) == 0x46, "unk46");
_Static_assert(offsetof(ADX_TALK, lpcnt) == 0x4C, "lpcnt");
_Static_assert(offsetof(ADX_TALK, trp) == 0x54, "trp");
_Static_assert(offsetof(ADX_TALK, wpos) == 0x58, "wpos");
_Static_assert(offsetof(ADX_TALK, mofst) == 0x5C, "mofst");
_Static_assert(offsetof(ADX_TALK, ercode) == 0x60, "ercode");
_Static_assert(offsetof(ADX_TALK, edecpos) == 0x64, "edecpos");
_Static_assert(offsetof(ADX_TALK, edeccnt) == 0x68, "edeccnt");
_Static_assert(offsetof(ADX_TALK, eshrtcnt) == 0x6A, "eshrtcnt");
_Static_assert(offsetof(ADX_TALK, lpflg) == 0x6C, "lpflg");
_Static_assert(offsetof(ADX_TALK, autorcvr) == 0x6D, "autorcvr");
_Static_assert(offsetof(ADX_TALK, pstready_flag) == 0x71, "pstready_flag");
_Static_assert(offsetof(ADX_TALK, pause_flag) == 0x72, "pause_flag");
_Static_assert(offsetof(ADX_TALK, amp) == 0x74, "amp");
_Static_assert(offsetof(ADX_TALK, ampsji) == 0x78, "ampsji");
_Static_assert(offsetof(ADX_TALK, ampsjo) == 0x80, "ampsjo");
_Static_assert(offsetof(ADX_TALK, time_ofst) == 0x88, "time_ofst");
_Static_assert(offsetof(ADX_TALK, lesct) == 0x8C, "lesct");
_Static_assert(offsetof(ADX_TALK, trpnsmpl) == 0x90, "trpnsmpl");
_Static_assert(offsetof(ADX_TALK, lsc) == 0x94, "lsc");
_Static_assert(offsetof(ADX_TALK, lnkflg) == 0x98, "lnkflg");
_Static_assert(offsetof(ADX_TALK, tvofst) == 0x9C, "tvofst");
_Static_assert(offsetof(ADX_TALK, svcnt) == 0xA0, "svcnt");
_Static_assert(offsetof(ADX_TALK, decofst) == 0xA4, "decofst");
_Static_assert(offsetof(ADX_TALK, unkA8) == 0xA8, "unkA8");
_Static_assert(offsetof(ADX_TALK, fname) == 0xAC, "fname");
_Static_assert(offsetof(ADX_TALK, fname_copy) == 0xB0, "fname_copy");
_Static_assert(offsetof(ADX_TALK, dir) == 0xB4, "dir");
_Static_assert(offsetof(ADX_TALK, ofst) == 0xB8, "ofst");
_Static_assert(offsetof(ADX_TALK, fnsct) == 0xBC, "fnsct");
_Static_assert(sizeof(ADX_TALK) == 0xC0, "ADX_TALK");
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
extern void sub_001678F0(ADXT adxt);
extern void sub_00167900(ADXT adxt);
extern void ADXRNA_Destroy(void *rna);
extern void ADXSJD_Destroy(void *sjd);
extern void ADXSTM_EntryEosFunc(void *stm, s32 arg1, s32 arg2);
extern void ADXSTM_Destroy(void *stm);
extern void LSC_Destroy(void *lsc);
extern void ADXAMP_Destroy(void *amp);
extern void *SJRBF_Create(void *buf, s32 bsize, s32 xlen);
extern void *ADXSTM_Create(void *sj, s32 arg1);
extern void *ADXSJD_Create(void *sjf, s32 maxnch, SJ *sjo);
extern void *ADXRNA_Create(SJ *sjo, s32 maxnch);
extern void *LSC_Create(void *sjf);
extern void LSC_SetStmHndl(void *lsc, void *stm);
extern s32 adxt_def_svrfreq;
extern ADX_TALK adxt_obj[ADXT_MAX_OBJ];
extern void ADXSJD_SetInSj(void *sjd, SJ sj);
extern void ADXSJD_Start(void *sjd);
extern void ADXAMP_Start(void *amp);
extern void ADXAMP_Stop(void *amp);
extern void ADXSTM_SetBufSize(void *stm, s32 minsize, s32 maxsize);
extern void ADXSTM_SetEos(void *stm, s32 eos);
extern void ADXSTM_Seek(void *stm, s32 pos);
extern void ADXSTM_StopNw(void *stm);
extern void ADXSTM_BindFileNw(void *stm, const char *fname, void *dir, s32 ofst, s32 nsct);
extern void ADXSTM_Start(void *stm);
extern void sub_001707C0(void *rna);
extern void sub_001707D0(void *rna, s32 sw);
extern s32 adxt_eos_sct;

void adxt_start_sj(ADXT adxt, SJ sj) {
    s32 i;
    void *amp;

    for (i = 0; i < adxt->maxnch; i++) {
        SJ_Reset(adxt->sjo[i]);
    }

    ADXSJD_SetInSj(adxt->sjd, sj);
    adxt->sji = sj;
    ADXSJD_Start(adxt->sjd);
    adxt->stat = ADXT_STAT_DECINFO;
    adxt->lpcnt = 0;
    adxt->pstready_flag = 0;
    adxt->lesct = 0x7FFFFFFF;
    adxt->trpnsmpl = -1;
    adxt->tvofst = 0;
    adxt->decofst = 0;
    adxt->svcnt = adxt_vsync_cnt;

    amp = adxt->amp;

    if (amp != 0) {
        ADXAMP_Start(amp);
    }
}

void adxt_start_stm(ADXT adxt, const char *fname, void *dir, s32 ofst, s32 fnsct) {
    ADXSTM_SetBufSize(adxt->stm, adxt->minsct << 11, adxt->maxsct << 11);
    ADXSTM_SetEos(adxt->stm, adxt_eos_sct);
    ADXSTM_EntryEosFunc(adxt->stm, 0, 0);
    ADXSTM_Seek(adxt->stm, 0);
    ADXSTM_StopNw(adxt->stm);
    ADXSTM_ReleaseFileNw(adxt->stm);
    ADXSTM_BindFileNw(adxt->stm, fname, dir, ofst, fnsct);
    ADXSTM_Start(adxt->stm);
    adxt_start_sj(adxt, adxt->sjf);
}

void ADXT_StopWithoutLsc(ADXT adxt) {
    SJ sj;
    void *amp;

    ADXCRS_Lock();
    sub_001707C0(adxt->rna);
    sub_001707D0(adxt->rna, 0);
    ADXRNA_SetPlaySw(adxt->rna, 0);
    ADXSJD_Stop(adxt->sjd);

    if (adxt->pmode == ADXT_PMODE_MEM) {
        sj = adxt->sji;

        if (sj != 0) {
            adxt->sji = 0;
            SJ_Destroy(sj);
        }
    }

    amp = adxt->amp;

    if (amp != 0) {
        ADXAMP_Stop(amp);
    }

    adxt->sji = 0;
    adxt->stat = 0;
    adxt->unkA8 = 0;
    ADXCRS_Unlock();
}

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

void ADXT_Destroy(ADXT adxt) {
    s32 i;
    void *rna;
    void *sjd;
    void *stm;
    void *lsc;
    SJ sjf;
    SJ sj;
    void *amp;

    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080805 ADXT_Destroy: parameter error");
        return;
    }

    sub_001678F0(adxt);
    sub_00167900(adxt);

    if (adxt->used == 1) {
        ADXT_Stop(adxt);
    }

    rna = adxt->rna;

    if (rna != 0) {
        adxt->rna = 0;
        ADXRNA_Destroy(rna);
    }

    sjd = adxt->sjd;

    if (sjd != 0) {
        adxt->sjd = 0;
        ADXSJD_Destroy(sjd);
    }

    stm = adxt->stm;

    if (stm != 0) {
        adxt->stm = 0;
        ADXSTM_EntryEosFunc(stm, 0, 0);
        ADXSTM_Destroy(stm);
    }

    lsc = adxt->lsc;

    if (lsc != 0) {
        adxt->lsc = 0;
        LSC_Destroy(lsc);
    }

    ADXCRS_Lock();
    sjf = adxt->sjf;

    if (sjf != 0) {
        adxt->sjf = 0;
        SJ_Destroy(sjf);
    }

    for (i = 0; i < adxt->maxnch; i++) {
        sj = adxt->sjo[i];

        if (sj != 0) {
            adxt->sjo[i] = 0;
            SJ_Destroy(sj);
        }

        sj = adxt->ampsji[i];

        if (sj != 0) {
            adxt->ampsji[i] = 0;
            SJ_Destroy(sj);
        }

        sj = adxt->ampsjo[i];

        if (sj != 0) {
            adxt->ampsjo[i] = 0;
            SJ_Destroy(sj);
        }
    }

    amp = adxt->amp;

    if (amp != 0) {
        adxt->amp = 0;
        ADXAMP_Destroy(amp);
    }

    memset(adxt, 0, sizeof(ADX_TALK));
    adxt->used = 0;
    ADXCRS_Unlock();
}

ADXT ADXT_Create(s32 maxnch, void *work, s32 worksize) {
    ADXT adxt;
    s32 ix;
    s32 i;
    uintptr_t aligned;
    s32 size;

    aligned = ((uintptr_t)work + 0x3F) & ~(uintptr_t)0x3F;
    size = worksize - (s32)(aligned - (uintptr_t)work);

    if (maxnch < 0 || work == 0 || worksize < 0) {
        ADXERR_CallErrFunc1("E02080804 ADXT_Create: parameter error");
        return 0;
    }

    for (ix = 0; ix < ADXT_MAX_OBJ; ix++) {
        if (adxt_obj[ix].used == 0) {
            break;
        }
    }

    if (ix == ADXT_MAX_OBJ) {
        ADXERR_CallErrFunc1("E03100801 ADXT_Create: Too many handles.\n");
        return 0;
    }

    adxt = &adxt_obj[ix];
    memset(adxt, 0, sizeof(ADX_TALK));
    adxt->maxnch = (s8)maxnch;
    adxt->obuf = (s16 *)aligned;
    adxt->ibuf = (char *)aligned + maxnch * 0x40C0;
    adxt->ibuflen = (size - maxnch * 0x40C0 - 0x124) / 2048 * 2048;
    adxt->ibufxlen = ADXT_IBUF_XLEN;
    adxt->fname = adxt->ibuf + adxt->ibuflen + adxt->ibufxlen;
    adxt->obufsize = ADXT_OBUF_SIZE;
    adxt->obufdist = ADXT_OBUF_DIST;
    adxt->sji = 0;
    adxt->sjf = SJRBF_Create(adxt->ibuf, adxt->ibuflen, adxt->ibufxlen);

    if (adxt->sjf == 0) {
        ADXT_Destroy(adxt);
        return 0;
    }

    adxt->stm = ADXSTM_Create(adxt->sjf, 0);

    if (adxt->stm == 0) {
        ADXT_Destroy(adxt);
        return 0;
    }

    for (i = 0; i < maxnch; i++) {
        adxt->sjo[i] = SJRBF_Create(adxt->obuf + adxt->obufdist * i, adxt->obufsize * 2,
                                    (adxt->obufdist - adxt->obufsize) * 2);

        if (adxt->sjo[i] == 0) {
            ADXT_Destroy(adxt);
            return 0;
        }
    }

    adxt->sjd = ADXSJD_Create(adxt->sjf, maxnch, adxt->sjo);

    if (adxt->sjd == 0) {
        ADXT_Destroy(adxt);
        return 0;
    }

    adxt->rna = ADXRNA_Create(adxt->sjo, maxnch);

    if (adxt->rna == 0) {
        ADXT_Destroy(adxt);
        return 0;
    }

    adxt->lsc = LSC_Create(adxt->sjf);

    if (adxt->lsc == 0) {
        ADXT_Destroy(adxt);
        return 0;
    }

    LSC_SetStmHndl(adxt->lsc, adxt->stm);
    ADXCRS_Lock();
    adxt->svrfreq = adxt_def_svrfreq;
    adxt->maxsct = (s16)(adxt->ibuflen / 2048);
    adxt->minsct = (s16)(s32)((f32)adxt->maxsct * 0.85f);
    adxt->outvol = 0;

    for (i = 0; i < maxnch; i++) {
        adxt->outpan[i] = ADXT_PAN_AUTO;
    }

    adxt->unk46 = 0;
    adxt->lpflg = 1;
    adxt->trp = 0;
    adxt->wpos = 0;
    adxt->mofst = 0;
    adxt->ercode = 0;
    adxt->edecpos = 0;
    adxt->edeccnt = 0;
    adxt->eshrtcnt = 0;
    adxt->autorcvr = 1;
    adxt->pause_flag = 0;
    adxt->time_ofst = 0;
    ADXT_SetLnkSw(adxt, 0);
    adxt->used = 1;
    ADXCRS_Unlock();
    return adxt;
}
