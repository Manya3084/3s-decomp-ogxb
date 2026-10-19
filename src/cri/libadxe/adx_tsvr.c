/* adxt_set_outpan 0x171430. adxt_stat_decinfo 0x171AD0.
 * adxt_stat_prep 0x1717E0. adxt_stat_playing 0x171900.
 * ADXT_ExecRdErrChk 0x1719B0, ADXT_ExecRdCompChk 0x171A00,
 * ADXT_ExecHndl 0x171DF0.
 *
 * ercode is a word at +0x60. stat 6 is the error state. stm is +0x08,
 * pmode is +0x02, sjd is +0x04, rna is +0x0C, sjf is +0x10, sjo is +0x18,
 * svrfreq is +0x38, outvol is the word at +0x40, maxdecsmpl is the s32
 * at +0x48, lp_skiplen is +0x50, pstwait_flag is +0x70, pstready_flag is
 * +0x71, pause_flag is +0x72, amp is +0x74, lesct is +0x8C, trpnsmpl is
 * +0x90, lsc is +0x94, tvofst is +0x9C, svcnt is +0xA0, and unkA8 is
 * +0xA8. fname_copy, dir, ofst, and fnsct are +0xB0 through +0xBC.
 * adxt_vsync_cnt is 0x7A5374.
 *
 * Stat 1 is adxt_stat_decinfo and stat 4 calls 0x171970. Stat 4 is not
 * named yet. Stat 2 is adxt_stat_prep and stat 3 is adxt_stat_playing.
 * Stat 5 goes straight to the two checks. The ret at 0x171B9B is the
 * channel-count error return inside decinfo.
 * ADXSTM_GetStat is folded into 0x16EC40 and is not named yet. Prep and playing
 * call that same body. ADXRNA_SetPlaySw and ADXRNA_GetNumData are named
 * in adx_rnap.c. ADXRNA_SetTransSw is named there too. 0x170810 is
 * ADXRNA_GetNumRoom. Playing's drained path calls ADXRNA_SetTransSw with 0
 * instead of clearing flush_nsmpl, then stores stat 4.
 * adxt_dbg_nch is 0xCD5A84 and adxt_dbg_ndt is 0xCD5A80.
 * LSC_GetStat is named in lsc.c. ADXSJD_TermSupply, ADXSJD_GetBlkSmpl,
 * and ADXSJD_GetNumChan are named in adx_sjd.c. ADXT_GetNumChan is
 * named in adx_tlk.c. Prep's clear of the output chunk is an inlined
 * memset. ADXRNA_SetOutPan is named in adx_rnap.c. outpan is the word
 * pair at +0x42.
 * Decinfo's stream restart flag is unkA8. GetLpEndOfst is 0x170270.
 * ADXSTM_SetEos is named in adx_stmc.c. EntryEosFunc is 0x16DFD0, which
 * is already SJRBF_EntryErrFunc. The eos callback is
 * 0x1713D0. GetLpEndPos is 0x170260 and GetLpStartPos is 0x170230.
 * The loop trap is adxt_trap_entry_lps (0x171A60) and the non-loop trap
 * is adxt_nlp_trap_entry (0x1715C0). GetTranspose is 0x168070 and SetTranspose is 0x167FE0.
 * On PS2 those two do nothing. GetSpsdInfo is 0x170300. The amp sample
 * rate setter is 0x16FB80. After the transfer switch, a non-null
 * pointer at 0x7A6090 is called with the handle, sample rate, channel
 * count, and total samples.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

#define ADXT_STAT_PREP 2
#define ADXT_STAT_PLAYING 3
#define SJCK_LEN_MAX 0x7FFFFFFF
#define ADXT_STAT_DECEND 4
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
    s32 (*GetNumData)(SJ sj, s32 id);
};

#define SJ_Reset(sj) ((sj)->vtbl->Reset)(sj)
#define SJ_GetChunk(sj, id, nbyte, ck) ((sj)->vtbl->GetChunk)(sj, id, nbyte, ck)
#define SJ_PutChunk(sj, id, ck) ((sj)->vtbl->PutChunk)(sj, id, ck)
#define SJ_GetNumData(sj, id) ((sj)->vtbl->GetNumData)(sj, id)

typedef struct ADX_TALK {
    s8 used;
    s8 stat;
    s8 pmode;
    s8 maxnch;
    void *sjd;
    void *stm;
    void *rna;
    SJ sjf;
    SJ sji;
    SJ sjo[2];
    u8 gap20[0x18];
    s32 svrfreq;
    u8 gap3C[4];
    s16 outvol;
    s16 outpan[2];
    u8 gap46[2];
    s32 maxdecsmpl;
    s32 lpcnt;
    s32 lp_skiplen;
    u8 gap54[0xC];
    s16 ercode;
    u8 gap62[0x0A];
    s8 lpflg;
    u8 gap6D[3];
    s8 pstwait_flag;
    s8 pstready_flag;
    s8 pause_flag;
    u8 gap73[1];
    void *amp;
    u8 gap78[0x14];
    s32 lesct;
    s32 trpnsmpl;
    void *lsc;
    s8 lnkflg;
    u8 gap99[3];
    s32 tvofst;
    s32 svcnt;
    s32 decofst;
    s8 unkA8;
    u8 gapA9[7];
    char *fname_copy;
    void *dir;
    s32 ofst;
    s32 fnsct;
} ADX_TALK;

typedef ADX_TALK *ADXT;

#if defined(__i386__)
_Static_assert(offsetof(ADX_TALK, stat) == 1, "stat");
_Static_assert(offsetof(ADX_TALK, pmode) == 2, "pmode");
_Static_assert(offsetof(ADX_TALK, sjd) == 4, "sjd");
_Static_assert(offsetof(ADX_TALK, stm) == 8, "stm");
_Static_assert(offsetof(ADX_TALK, rna) == 0x0C, "rna");
_Static_assert(offsetof(ADX_TALK, sjf) == 0x10, "sjf");
_Static_assert(offsetof(ADX_TALK, sjo) == 0x18, "sjo");
_Static_assert(offsetof(ADX_TALK, svrfreq) == 0x38, "svrfreq");
_Static_assert(offsetof(ADX_TALK, outvol) == 0x40, "outvol");
_Static_assert(offsetof(ADX_TALK, outpan) == 0x42, "outpan");
_Static_assert(offsetof(ADX_TALK, maxdecsmpl) == 0x48, "maxdecsmpl");
_Static_assert(offsetof(ADX_TALK, lp_skiplen) == 0x50, "lp_skiplen");
_Static_assert(offsetof(ADX_TALK, ercode) == 0x60, "ercode");
_Static_assert(offsetof(ADX_TALK, pstwait_flag) == 0x70, "pstwait_flag");
_Static_assert(offsetof(ADX_TALK, pstready_flag) == 0x71, "pstready_flag");
_Static_assert(offsetof(ADX_TALK, pause_flag) == 0x72, "pause_flag");
_Static_assert(offsetof(ADX_TALK, amp) == 0x74, "amp");
_Static_assert(offsetof(ADX_TALK, lesct) == 0x8C, "lesct");
_Static_assert(offsetof(ADX_TALK, trpnsmpl) == 0x90, "trpnsmpl");
_Static_assert(offsetof(ADX_TALK, lsc) == 0x94, "lsc");
_Static_assert(offsetof(ADX_TALK, tvofst) == 0x9C, "tvofst");
_Static_assert(offsetof(ADX_TALK, svcnt) == 0xA0, "svcnt");
_Static_assert(offsetof(ADX_TALK, unkA8) == 0xA8, "unkA8");
_Static_assert(offsetof(ADX_TALK, fname_copy) == 0xB0, "fname_copy");
_Static_assert(offsetof(ADX_TALK, dir) == 0xB4, "dir");
_Static_assert(offsetof(ADX_TALK, ofst) == 0xB8, "ofst");
_Static_assert(offsetof(ADX_TALK, fnsct) == 0xBC, "fnsct");
_Static_assert(offsetof(SJ_VTBL, Reset) == 0x14, "Reset");
_Static_assert(offsetof(SJ_VTBL, GetChunk) == 0x18, "GetChunk");
_Static_assert(offsetof(SJ_VTBL, PutChunk) == 0x20, "PutChunk");
_Static_assert(offsetof(SJ_VTBL, GetNumData) == 0x24, "GetNumData");
#endif

extern void ADXERR_CallErrFunc1(const char *msg);
extern void ADXERR_CallErrFunc2(const char *msg, const char *detail);
extern void ADXERR_ItoA2(s32 arg0, s32 arg1, char *str, s32 len);
extern s32 ADXT_GetStat(ADXT adxt);
extern s32 ADXT_GetNumChan(ADXT adxt);
extern void ADXT_Stop(ADXT adxt);
extern void adxt_start_stm(ADXT adxt, const char *fname, void *dir, s32 ofst, s32 fnsct);
extern s32 sub_0016EC40(void *stm);
extern s32 LSC_GetStat(void *lsc);
extern void ADXSJD_TermSupply(void *sjd);
extern s32 ADXSJD_GetBlkSmpl(void *sjd);
extern s32 ADXSJD_GetNumChan(void *sjd);
extern s32 ADXSJD_GetSfreq(void *sjd);
extern s32 ADXSJD_GetNumLoop(void *sjd);
extern s32 ADXSJD_GetTotalNumSmpl(void *sjd);
extern s32 ADXSJD_GetOutBps(void *sjd);
extern s32 ADXSJD_GetFormat(void *sjd);
extern s16 ADXSJD_GetDefOutVol(void *sjd);
extern s16 ADXSJD_GetDefPan(void *sjd, s32 channel);
extern void ADXSJD_SetMaxDecSmpl(void *sjd, s32 samples);
extern void ADXSJD_SetTrapNumSmpl(void *sjd, s32 samples);
extern void ADXSJD_SetTrapDtLen(void *sjd, s32 dt_len);
extern void ADXSJD_SetTrapCnt(void *sjd, s32 cnt);
extern void ADXSJD_EntryTrapFunc(void *sjd, void (*func)(void *), void *obj);
extern void ADXRNA_SetOutPan(void *rna, s32 channel, s32 pan);
extern s32 ADXRNA_GetNumData(void *rna);
extern s32 ADXRNA_GetNumRoom(void *rna);
extern void ADXRNA_SetPlaySw(void *rna, s32 sw);
extern void ADXRNA_SetTransSw(void *rna, s32 sw);
extern void ADXRNA_SetNumChan(void *rna, s32 num_chan);
extern void ADXRNA_SetSfreq(void *rna, s32 sfreq);
extern void ADXRNA_SetOutVol(void *rna, s32 vol);
extern void ADXRNA_SetBitPerSmpl(void *rna, s32 bps);
extern void ADXRNA_SetStmHdInfo(void *rna, s32 info);
extern void sub_001725E0(void *rna, s32 num_smpl);
extern s32 sub_0016EC40(void *obj);
extern s32 ADXSJD_GetLpEndOfst(void *sjd);
extern s32 ADXSJD_GetLpEndPos(void *sjd);
extern s32 ADXSJD_GetLpEndPos(void *sjd);
extern s32 ADXSJD_GetLpStartPos(void *sjd);
extern s32 ADXSJD_GetSpsdInfo(void *sjd);
extern void ADXSTM_SetEos(void *stm, s32 eos);
extern void sub_0016DFD0(void *stm, void (*func)(void *), void *obj);
extern void ADXT_GetTranspose(ADXT adxt, s32 *transpose, s32 *detune);
extern void ADXT_SetTranspose(ADXT adxt, s32 transpose, s32 detune);
extern void ADXAMP_SetSfreq(void *amp, s32 sfreq);
extern void (*sub_007A6090)(ADXT adxt, s32 sfreq, s32 num_chan, s32 num_smpl);
extern s32 adxt_vsync_cnt;
extern s32 adxt_dbg_nch;
extern s32 adxt_dbg_ndt;
extern s32 adxt_dbg_rna_ndata;
extern s32 ADXSJD_GetLpStartOfst(void *sjd);
extern void ADXSJD_TakeSnapshot(void *sjd);
extern void ADXSJD_SetDecPos(void *sjd, s32 pos);
extern s32 ADXSJD_GetDecNumSmpl(void *sjd);
extern void ADXSJD_Start(void *sjd);
extern void ADXSJD_Stop(void *sjd);
extern void ADXSJD_ExecHndl(void *sjd);
extern s32 ADXSTM_Seek(void *stm, s32 offset);
extern void ADXT_SetLnkSw(ADXT adxt, s32 sw);
extern s32 ADX_DecodeFooter(u8 *buf, s32 len, s16 *ofst);
extern s32 xb_adx_FindEndCode(u8 *buf, s32 len, s16 *ofst);
extern void SJ_SplitChunk(SJCK *ck, s32 nbyte, SJCK *ck1, SJCK *ck2);
extern void ADXSJD_RestoreSnapshot(void *sjd);

/* adxt_trap_entry 0x1712C0.
 *
 * The loop-end trap of a looping stream: passes the input up to the
 * loop end on, winds the decoder back to the loop start (restoring its
 * snapshot) and sets the next trap; a memory stream (pmode 2) also
 * rewinds its input to the loop start's offset. Streams in pmode 2 or 3
 * with looping off just clear the trap. */

void adxt_trap_entry(ADXT adxt) {
    void *sjd = adxt->sjd;
    SJ sj = adxt->sji;
    SJCK ck;
    s32 lsp = ADXSJD_GetLpStartPos(sjd);
    s32 lso = ADXSJD_GetLpStartOfst(sjd);
    s32 lep = ADXSJD_GetLpEndPos(sjd);

    if ((adxt->pmode == 2 || adxt->pmode == 3) && adxt->lpflg == 0) {
        ADXSJD_SetTrapNumSmpl(adxt->sjd, -1);
        return;
    }

    SJ_GetChunk(sj, 1, adxt->lp_skiplen, &ck);

    if (ck.len < adxt->lp_skiplen) {
        ADXERR_CallErrFunc1("E8101201 adxt_trap_entry: not enough data");
    }

    SJ_PutChunk(sj, 0, &ck);
    ADXSJD_SetTrapCnt(sjd, 0);
    adxt->trpnsmpl = lep - lsp;
    ADXSJD_SetTrapNumSmpl(sjd, adxt->trpnsmpl);
    ADXSJD_SetTrapDtLen(sjd, lso);
    ADXSJD_SetDecPos(sjd, lsp);

    if (adxt->pmode == 2) {
        SJ_Reset(sj);
        SJ_GetChunk(sj, 1, lso, &ck);
        SJ_PutChunk(sj, 0, &ck);
    }

    ADXSJD_RestoreSnapshot(sjd);
    adxt->lpcnt++;
}
#define SJ_UngetChunk(sj, id, ck) ((sj)->vtbl->UngetChunk)(sj, id, ck)

/* adxt_trap_entry_lps 0x171A60.
 *
 * The loop trap: winds the decoder back to the loop start and sets the
 * next trap at the loop end. */

void adxt_trap_entry_lps(ADXT adxt) {
    void *sjd = adxt->sjd;
    s32 lsp = ADXSJD_GetLpStartPos(sjd);
    s32 lso = ADXSJD_GetLpStartOfst(sjd);
    s32 lep = ADXSJD_GetLpEndPos(sjd);

    ADXSJD_TakeSnapshot(sjd);
    ADXSJD_SetTrapCnt(sjd, 0);
    adxt->trpnsmpl = lep - lsp;
    ADXSJD_SetTrapNumSmpl(sjd, adxt->trpnsmpl);
    ADXSJD_SetTrapDtLen(sjd, lso);
    ADXSJD_SetDecPos(sjd, lsp);
    ADXSJD_EntryTrapFunc(sjd, (void (*)(void *))adxt_trap_entry, adxt);
}

/* adxt_eos_entry 0x1713D0.
 *
 * The stream's end-of-stream callback. Looping (lpflg) seeks the stream
 * back to the loop start's sector; otherwise the trap and the end are
 * cleared. */

void adxt_eos_entry(ADXT adxt) {
    void *stm = adxt->stm;
    void *sjd = adxt->sjd;
    s32 ofst;

    if (stm == 0 || sjd == 0) {
        return;
    }

    ofst = ADXSJD_GetLpStartOfst(sjd);

    if (adxt->lpflg == 0) {
        ADXSJD_SetTrapNumSmpl(adxt->sjd, -1);
        ADXSTM_SetEos(adxt->stm, 0x7FFFFFFF);
        return;
    }

    ADXSTM_Seek(stm, ofst / 0x800);
}

/* adxt_nlp_trap_entry 0x1715C0.
 *
 * The link trap for a non-looping stream: with linking on, it finds the
 * end of this file's data in the input (its footer, then the end code
 * in the first or the second chunk), passes the data up to it on and
 * restarts the decoder on the next file's header. */

void adxt_nlp_trap_entry(ADXT adxt) {
    void *sjd;
    SJ sj;
    SJCK ck1;
    SJCK ck2;
    SJCK ck3;
    SJCK ck4;
    s16 flen;
    s32 elen;
    s32 elen2;
    s32 pos;
    s32 r1;
    s32 r2;

    sjd = adxt->sjd;
    sj = adxt->sji;

    if (adxt->lnkflg == 0) {
        return;
    }

    elen = 0;
    SJ_GetChunk(sj, 1, 0x7FFFFFFF, &ck1);
    SJ_GetChunk(sj, 1, 0x7FFFFFFF, &ck2);

    if (ADX_DecodeFooter((u8 *)ck1.data, ck1.len, &flen) != 0) {
        ADXT_SetLnkSw(adxt, 0);
        SJ_UngetChunk(sj, 1, &ck2);
        SJ_UngetChunk(sj, 1, &ck1);
        return;
    }

    pos = flen;
    r1 = xb_adx_FindEndCode((u8 *)(ck1.data + pos), ck1.len - pos, &flen);

    if (r1 == 0) {
        r2 = -1;
    } else {
        r2 = xb_adx_FindEndCode((u8 *)ck2.data, ck2.len, (s16 *)&elen);
    }

    pos += flen;
    elen2 = (s16)elen;

    if (r1 != 0 && r2 != 0) {
        SJ_UngetChunk(sj, 1, &ck2);
        SJ_UngetChunk(sj, 1, &ck1);
        ADXT_SetLnkSw(adxt, 0);
        return;
    }

    if (r1 == 0) {
        SJ_UngetChunk(sj, 1, &ck2);
        SJ_SplitChunk(&ck1, pos, &ck1, &ck3);
        SJ_PutChunk(sj, 0, &ck1);
        SJ_UngetChunk(sj, 1, &ck3);
    } else {
        SJ_PutChunk(sj, 0, &ck1);
        SJ_SplitChunk(&ck2, elen2, &ck2, &ck4);
        SJ_PutChunk(sj, 0, &ck2);
        SJ_UngetChunk(sj, 1, &ck4);
    }

    adxt->decofst += ADXSJD_GetDecNumSmpl(sjd);
    ADXSJD_Stop(sjd);
    ADXSJD_Start(sjd);
    ADXSJD_ExecHndl(sjd);

    if (sub_0016EC40(sjd) != 2) {
        ADXT_SetLnkSw(adxt, 0);
        return;
    }

    ADXSJD_SetMaxDecSmpl(sjd, adxt->maxdecsmpl);
    ADXSJD_SetTrapNumSmpl(sjd, ADXSJD_GetTotalNumSmpl(sjd));
    ADXSJD_SetTrapDtLen(sjd, 0);
    ADXSJD_SetTrapCnt(sjd, 0);
}

/* adxt_stat_decend 0x171970.
 *
 * At the end of decoding: once the output has drained, playback stops
 * and the handle goes to stat 5 (play end). */

void adxt_stat_decend(ADXT adxt) {
    adxt_dbg_rna_ndata = ADXRNA_GetNumData(adxt->rna);

    if (ADXRNA_GetNumData(adxt->rna) <= 0) {
        ADXRNA_SetPlaySw(adxt->rna, 0);
        adxt->stat = 5;
    }
}

void ADXT_ExecRdErrChk(ADXT adxt) {
    if (adxt->stm != 0 && sub_0016EC40(adxt->stm) == 4) {
        adxt->ercode = -1;
        adxt->stat = ADXT_STAT_ERROR;
    }

    if (adxt->lsc != 0 && LSC_GetStat(adxt->lsc) == 3) {
        adxt->ercode = -1;
        adxt->stat = ADXT_STAT_ERROR;
    }
}

void ADXT_ExecRdCompChk(ADXT adxt) {
    if (adxt->stm == 0 || ADXT_GetStat(adxt) == 0) {
        return;
    }

    switch (adxt->pmode) {
    case 0:
    case 1:
        if (sub_0016EC40(adxt->stm) == 3) {
            ADXSJD_TermSupply(adxt->sjd);
        }
        break;

    case 2:
        ADXSJD_TermSupply(adxt->sjd);
        break;
    }
}

void adxt_set_outpan(ADXT adxt) {
    s32 i;
    s32 num_chan;
    s32 def_pan[2];

    num_chan = ADXSJD_GetNumChan(adxt->sjd);

    for (i = 0; i < 2; i++) {
        def_pan[i] = ADXSJD_GetDefPan(adxt->sjd, i);
    }

    if (num_chan == 1) {
        if (adxt->outpan[0] == -0x80) {
            if (def_pan[0] == -0x80) {
                ADXRNA_SetOutPan(adxt->rna, 0, 0);
            } else {
                goto lbl1;
            lbl2:
                ADXRNA_SetOutPan(adxt->rna, 0, adxt->outpan[0]);
            }
        } else {
            if (def_pan[0] == -0x80) {
                goto lbl2;
            lbl1:
                ADXRNA_SetOutPan(adxt->rna, 0, def_pan[0]);
            } else {
                ADXRNA_SetOutPan(adxt->rna, 0, (s16)(adxt->outpan[0] & 0xFFFF) + def_pan[0]);
            }
        }
    } else {
        if (adxt->outpan[0] == -0x80) {
            if (def_pan[0] == -0x80) {
                ADXRNA_SetOutPan(adxt->rna, 0, -0xF);
            } else {
                goto lbl3;
            lbl4:
                ADXRNA_SetOutPan(adxt->rna, 0, adxt->outpan[0]);
            }
        } else {
            if (def_pan[0] == -0x80) {
                goto lbl4;
            lbl3:
                ADXRNA_SetOutPan(adxt->rna, 0, def_pan[0]);
            } else {
                ADXRNA_SetOutPan(adxt->rna, 0, adxt->outpan[0] + def_pan[0]);
            }
        }

        if (adxt->outpan[1] == -0x80) {
            if (def_pan[1] == -0x80) {
                ADXRNA_SetOutPan(adxt->rna, 1, 0xF);
            } else {
                goto lbl5;
            lbl6:
                ADXRNA_SetOutPan(adxt->rna, 1, adxt->outpan[1]);
            }
        } else {
            if (def_pan[1] == -0x80) {
                goto lbl6;
            lbl5:
                ADXRNA_SetOutPan(adxt->rna, 1, def_pan[1]);
            } else {
                ADXRNA_SetOutPan(adxt->rna, 1, (s16)(adxt->outpan[1] & 0xFFFF) + def_pan[1]);
            }
        }
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
    num_data = ADXRNA_GetNumData(rna);
    num_room = ADXRNA_GetNumRoom(rna);

    if ((num_data >= (adxt->maxdecsmpl << 1)) || (ADXSJD_GetBlkSmpl(sjd) >= num_room) ||
        (sub_0016EC40(adxt->sjd) == 3)) {
        if (adxt->pstwait_flag == 0) {
            if (adxt->pause_flag == 0) {
                ADXRNA_SetPlaySw(rna, 1);
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

void adxt_stat_playing(ADXT adxt) {
    s32 i;
    s32 num_chan;

    if (sub_0016EC40(adxt->sjd) != 3) {
        return;
    }

    num_chan = ADXSJD_GetNumChan(adxt->sjd);
    adxt_dbg_nch = num_chan;

    for (i = 0; i < num_chan; i++) {
        SJ sj_obj = adxt->sjo[i];

        adxt_dbg_ndt = SJ_GetNumData(sj_obj, 1);

        if (adxt_dbg_ndt >= 64) {
            break;
        }
    }

    if (i == num_chan) {
        ADXRNA_SetTransSw(adxt->rna, 0);
        adxt->stat = ADXT_STAT_DECEND;
    }
}

void adxt_stat_decinfo(ADXT adxt) {
    void *sjd = adxt->sjd;
    s32 transpose = 0;
    s32 detune = 0;
    s32 div = 2048;
    char num_chan_str[32];
    s32 num_smpl;
    s32 sfreq;
    s32 num_chan;
    s32 num_loop;
    s32 blk_smpl;
    s32 max_dec_smpl;
    s32 lp_end_ofst;

    if ((adxt->pmode == 0 || adxt->pmode == 1) && (adxt->unkA8 == 1)) {
        if (sub_0016EC40(adxt->stm) == 2) {
            return;
        }

        if (adxt->sjf != 0) {
            SJ_Reset(adxt->sjf);
        }

        adxt_start_stm(adxt, adxt->fname_copy, adxt->dir, adxt->ofst, adxt->fnsct);
        adxt->unkA8 = 0;
    }

    if (sub_0016EC40(sjd) != 2) {
        return;
    }

    num_chan = ADXSJD_GetNumChan(sjd);

    if (num_chan > adxt->maxnch) {
        ADXERR_ItoA2(num_chan, adxt->maxnch, num_chan_str, 16);
        ADXERR_CallErrFunc2(
            "E9081001 adxt_stat_decinfo: can't play this number of channels", num_chan_str);
        ADXT_Stop(adxt);
        return;
    }

    sfreq = ADXSJD_GetSfreq(sjd);
    num_loop = ADXSJD_GetNumLoop(sjd);

    if (num_loop > 0) {
        adxt->maxdecsmpl = (sfreq / adxt->svrfreq) * 3;
    } else {
        adxt->maxdecsmpl = ((sfreq / adxt->svrfreq) * 3) / 2;
    }

    blk_smpl = ADXSJD_GetBlkSmpl(sjd) * 2;
    max_dec_smpl = ((adxt->maxdecsmpl + blk_smpl) / blk_smpl) * blk_smpl;
    adxt->maxdecsmpl = max_dec_smpl;
    ADXSJD_SetMaxDecSmpl(sjd, max_dec_smpl);

    if (num_loop > 0) {
        if (adxt->pmode == 2) {
            adxt->lp_skiplen = 0;
        } else {
            lp_end_ofst = ADXSJD_GetLpEndOfst(sjd);
            adxt->lp_skiplen = div - (lp_end_ofst % div);
            lp_end_ofst += 0x7FF;
            adxt->lp_skiplen %= div;
            adxt->lesct = lp_end_ofst / div;
            ADXSTM_SetEos(adxt->stm, adxt->lesct);
            sub_0016DFD0(adxt->stm, (void (*)(void *))adxt_eos_entry, adxt);
        }

        ADXSJD_GetLpEndPos(sjd);
        adxt->trpnsmpl = ADXSJD_GetLpStartPos(sjd);
        ADXSJD_SetTrapNumSmpl(sjd, adxt->trpnsmpl);
        ADXSJD_SetTrapDtLen(sjd, 0);
        ADXSJD_SetTrapCnt(sjd, 0);
        ADXSJD_EntryTrapFunc(sjd, (void (*)(void *))adxt_trap_entry_lps, adxt);
    } else {
        if (adxt->stm != 0) {
            ADXSTM_SetEos(adxt->stm, SJCK_LEN_MAX);
        }

        ADXSJD_SetTrapNumSmpl(sjd, ADXSJD_GetTotalNumSmpl(sjd));
        ADXSJD_SetTrapDtLen(sjd, 0);
        ADXSJD_SetTrapCnt(sjd, 0);
        ADXSJD_EntryTrapFunc(sjd, (void (*)(void *))adxt_nlp_trap_entry, adxt);
    }

    sfreq = ADXSJD_GetSfreq(sjd);
    num_chan = ADXSJD_GetNumChan(sjd);
    num_smpl = ADXSJD_GetTotalNumSmpl(sjd);
    ADXRNA_SetBitPerSmpl(adxt->rna, ADXSJD_GetOutBps(sjd));
    ADXRNA_SetSfreq(adxt->rna, sfreq);
    ADXRNA_SetNumChan(adxt->rna, num_chan);
    sub_001725E0(adxt->rna, num_smpl);
    ADXRNA_SetOutVol(adxt->rna, adxt->outvol + ADXSJD_GetDefOutVol(adxt->sjd));
    ADXT_GetTranspose(adxt, &transpose, &detune);

    if ((transpose != 0) || (detune != 0)) {
        ADXT_SetTranspose(adxt, transpose, detune);
    }

    adxt_set_outpan(adxt);

    if (adxt->amp != 0) {
        ADXAMP_SetSfreq(adxt->amp, sfreq);
    }

    if (ADXSJD_GetFormat(sjd) == 2) {
        ADXRNA_SetStmHdInfo(adxt->rna, ADXSJD_GetSpsdInfo(sjd));
    }

    ADXRNA_SetTransSw(adxt->rna, 1);

    if (sub_007A6090 != 0) {
        sub_007A6090(adxt, sfreq, num_chan, num_smpl);
    }

    adxt->stat = ADXT_STAT_PREP;
}

void ADXT_ExecHndl(ADXT adxt) {
    s8 stat;

    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080842 ADXT_ExecHndl: parameter error");
        return;
    }

    stat = adxt->stat;

    if (stat == 3) {
        adxt_stat_playing(adxt);
    } else if (stat == 1) {
        adxt_stat_decinfo(adxt);
    } else if (stat == 2) {
        adxt_stat_prep(adxt);
    } else if (stat == 4) {
        adxt_stat_decend(adxt);
    }

    ADXT_ExecRdCompChk(adxt);
    ADXT_ExecRdErrChk(adxt);
}
