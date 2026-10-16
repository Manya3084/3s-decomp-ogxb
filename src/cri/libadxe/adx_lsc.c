/* ADXT_EntryAfs 0x168680, ADXT_GetNumFiles 0x168770, ADXT_ResetEntry 0x1687A0.
 *
 * EntryAfs does not test adxt. lsc is +0x94. The fname buffer pointer is +0xAC.
 * ADXT_STAT_STOP is 0. GetFnameRangeEx and GetFnameFromPt live in adx_fs.c.
 * LSC_EntryFileRange is 0x1709C0, LSC_GetNumStm is 0x170B80, and
 * LSC_ResetEntry is 0x170AB0. Those three are not named yet.
 */

#include "types.h"

#include <stddef.h>

#define ADXT_STAT_STOP 0

typedef struct ADX_TALK {
    s8 used;
    s8 stat;
    u8 gap02[0x92];
    void *lsc;
    u8 gap98[0x14];
    char *fname;
} ADX_TALK;

typedef ADX_TALK *ADXT;

#if defined(__i386__)
_Static_assert(offsetof(ADX_TALK, stat) == 1, "stat");
_Static_assert(offsetof(ADX_TALK, lsc) == 0x94, "lsc");
_Static_assert(offsetof(ADX_TALK, fname) == 0xAC, "fname");
#endif

extern void ADXERR_CallErrFunc1(const char *msg);
extern void ADXERR_CallErrFunc2(const char *msg, char *detail);
extern void ADXERR_ItoA2(s32 patid, s32 fid, char *str, s32 len);
extern s32 ADXF_GetFnameRangeEx(s32 ptid, s32 flid, char *fname, void **dir, s32 *ofst, s32 *fnsct);
extern const char *ADXF_GetFnameFromPt(s32 ptid);
extern s32 LSC_EntryFileRange(void *lsc, const char *fname, void *dir, s32 ofst, s32 fnsct);
extern s32 LSC_GetNumStm(void *lsc);
extern void LSC_ResetEntry(void *lsc);

void ADXT_EntryAfs(ADXT adxt, s32 patid, s32 fid) {
    char error[16];
    void *dir;
    s32 ofst;
    s32 fnsct;

    if (ADXF_GetFnameRangeEx(patid, fid, adxt->fname, &dir, &ofst, &fnsct) == 0) {
        LSC_EntryFileRange(adxt->lsc, ADXF_GetFnameFromPt(patid), dir, ofst, fnsct);
        return;
    }

    ADXERR_ItoA2(patid, fid, error, 16);
    ADXERR_CallErrFunc2("E0071301 ADXT_EntryAfs: can't entry ", error);
}

s32 ADXT_GetNumFiles(ADXT adxt) {
    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080854 ADXT_GetNumFiles: parameter error");
        return -1;
    }

    return LSC_GetNumStm(adxt->lsc);
}

void ADXT_ResetEntry(ADXT adxt) {
    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080849 ADXT_ResetEntry: parameter error");
        return;
    }

    if (adxt->stat != ADXT_STAT_STOP) {
        return;
    }

    LSC_ResetEntry(adxt->lsc);
}
