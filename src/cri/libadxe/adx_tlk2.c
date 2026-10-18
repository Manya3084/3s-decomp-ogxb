/* ADXT_StartAfs 0x1687D0, ADXT_StartMem2 0x1688B0, ADXT_StartMem 0x168930.
 *
 * fname is a pointer at +0xAC. The copy, dir, ofst, and fnsct that StartAfs
 * stores are +0xB0, +0xB4, +0xB8, and +0xBC. ercode is a word at +0x60.
 * unkA8 is the byte at +0xA8. ADXT_STAT_DECINFO is 1, ADXT_STAT_ERROR is 6,
 * ADXT_PMODE_AFS is 1, and ADXT_PMODE_MEM is 2.
 *
 * GetFnameRangeEx lives in adx_fs.c. SetLnkSw is named in adx_tlk.c.
 * SJMEM_Create is named in sj_mem.c. adxt_start_sj is named
 * in adx_tlk.c.
 */

#include "types.h"

#include <stddef.h>

#define ADXT_STAT_DECINFO 1
#define ADXT_STAT_ERROR 6
#define ADXT_ERR_SHRTBUF (-1)
#define ADXT_PMODE_AFS 1
#define ADXT_PMODE_MEM 2

typedef struct ADX_TALK {
    s8 used;
    s8 stat;
    s8 pmode;
    u8 gap03[5];
    void *stm;
    u8 gap0C[0x54];
    s16 ercode;
    u8 gap62[0x46];
    s8 unkA8;
    u8 gapA9[3];
    char *fname;
    char *fname_copy;
    void *dir;
    s32 ofst;
    s32 fnsct;
} ADX_TALK;

typedef ADX_TALK *ADXT;

#if defined(__i386__)
_Static_assert(offsetof(ADX_TALK, stat) == 1, "stat");
_Static_assert(offsetof(ADX_TALK, pmode) == 2, "pmode");
_Static_assert(offsetof(ADX_TALK, stm) == 8, "stm");
_Static_assert(offsetof(ADX_TALK, ercode) == 0x60, "ercode");
_Static_assert(offsetof(ADX_TALK, unkA8) == 0xA8, "unkA8");
_Static_assert(offsetof(ADX_TALK, fname) == 0xAC, "fname");
_Static_assert(offsetof(ADX_TALK, fname_copy) == 0xB0, "fname_copy");
_Static_assert(offsetof(ADX_TALK, dir) == 0xB4, "dir");
_Static_assert(offsetof(ADX_TALK, ofst) == 0xB8, "ofst");
_Static_assert(offsetof(ADX_TALK, fnsct) == 0xBC, "fnsct");
#endif

extern void ADXERR_CallErrFunc1(const char *msg);
extern void ADXERR_CallErrFunc2(const char *msg, char *detail);
extern void ADXERR_ItoA2(s32 patid, s32 fid, char *str, s32 len);
extern void ADXT_Stop(ADXT adxt);
extern void ADXT_SetLnkSw(ADXT adxt, s32 sw);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
extern s32 ADXF_GetFnameRangeEx(s32 ptid, s32 flid, char *fname, void **dir, s32 *ofst, s32 *fnsct);
extern void *SJMEM_Create(void *data, s32 len);
extern void adxt_start_sj(ADXT adxt, void *sj);

void ADXT_StartAfs(ADXT adxt, s32 patid, s32 fid) {
    char error[16];
    void *dir;
    s32 ofst;
    s32 fnsct;

    if (adxt == 0) {
        ADXERR_CallErrFunc1("E02080811 ADXT_StartAfs: parameter error");
        return;
    }

    ADXT_Stop(adxt);

    if (ADXF_GetFnameRangeEx(patid, fid, adxt->fname, &dir, &ofst, &fnsct) != 0) {
        return;
    }

    if (adxt->stm == 0) {
        ADXERR_ItoA2(patid, fid, error, 16);
        ADXERR_CallErrFunc2("E8101202 ADXT_StartAfs: can't open ", error);
        adxt->ercode = (s16)ADXT_ERR_SHRTBUF;
        adxt->stat = ADXT_STAT_ERROR;
        return;
    }

    adxt->fname_copy = adxt->fname;
    adxt->dir = dir;
    adxt->ofst = ofst;
    adxt->fnsct = fnsct;
    adxt->stat = ADXT_STAT_DECINFO;
    adxt->unkA8 = 1;
    adxt->pmode = ADXT_PMODE_AFS;
    ADXT_SetLnkSw(adxt, 0);
}

void ADXT_StartMem2(ADXT adxt, void *adxdat, s32 datlen) {
    void *sj;

    if (adxt == 0 || adxdat == 0 || datlen < 0) {
        ADXERR_CallErrFunc1("E02080809 ADXT_StartMem2: parameter error");
        return;
    }

    ADXT_Stop(adxt);
    sub_0016AA60();
    sj = SJMEM_Create(adxdat, datlen);

    if (sj == 0) {
        sub_0016AA70();
        ADXERR_CallErrFunc1("E8101207: can't create sj (ADXT_StartMem)\n");
        return;
    }

    adxt_start_sj(adxt, sj);
    adxt->pmode = ADXT_PMODE_MEM;
    ADXT_SetLnkSw(adxt, 0);
    sub_0016AA70();
}

void ADXT_StartMem(ADXT adxt, void *adxdat) {
    ADXT_StartMem2(adxt, adxdat, 0x40000000);
}
