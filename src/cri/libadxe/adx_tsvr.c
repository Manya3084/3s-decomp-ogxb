/* ADXT_ExecRdErrChk 0x1719B0, ADXT_ExecRdCompChk 0x171A00,
 * ADXT_ExecHndl 0x171DF0.
 *
 * ercode is a word at +0x60. stat 6 is the error state. stm is +0x08,
 * pmode is +0x02, sjd is +0x04, and lsc is +0x94.
 *
 * Stat 3 calls 0x171900, stat 1 calls 0x171AD0, stat 2 calls 0x1717E0,
 * and stat 4 calls 0x171970. Those four are not named yet. Stat 5 goes
 * straight to the two checks. ADXSTM_GetStat is 0x16EC40, LSC_GetStat is
 * 0x170B60, and ADXSJD_TermSupply is 0x16FCA0. Those callees are not
 * named yet.
 */

#include "types.h"

#include <stddef.h>

#define ADXT_STAT_ERROR 6

typedef struct ADX_TALK {
    s8 used;
    s8 stat;
    s8 pmode;
    s8 maxnch;
    void *sjd;
    void *stm;
    u8 gap0C[0x54];
    s16 ercode;
    u8 gap62[0x32];
    void *lsc;
} ADX_TALK;

typedef ADX_TALK *ADXT;

#if defined(__i386__)
_Static_assert(offsetof(ADX_TALK, stat) == 1, "stat");
_Static_assert(offsetof(ADX_TALK, pmode) == 2, "pmode");
_Static_assert(offsetof(ADX_TALK, sjd) == 4, "sjd");
_Static_assert(offsetof(ADX_TALK, stm) == 8, "stm");
_Static_assert(offsetof(ADX_TALK, ercode) == 0x60, "ercode");
_Static_assert(offsetof(ADX_TALK, lsc) == 0x94, "lsc");
#endif

extern void ADXERR_CallErrFunc1(const char *msg);
extern s32 ADXT_GetStat(ADXT adxt);
extern s32 ADXSTM_GetStat(void *stm);
extern s32 LSC_GetStat(void *lsc);
extern void ADXSJD_TermSupply(void *sjd);
extern void sub_00171900(ADXT adxt);
extern void sub_00171AD0(ADXT adxt);
extern void sub_001717E0(ADXT adxt);
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
        sub_001717E0(adxt);
    } else if (stat == 4) {
        sub_00171970(adxt);
    }

    ADXT_ExecRdCompChk(adxt);
    ADXT_ExecRdErrChk(adxt);
}
