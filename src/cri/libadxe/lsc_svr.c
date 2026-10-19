/* lsc_StatWait 0x173A20. lsc_StatRead 0x173B00.
 * lsc_StatEnd 0x173B70. lsc_ExecHndl 0x173C00.
 *
 * The PS2 tree keeps the first three as asm; their C here is written from
 * the x86, with the PS2 callees. lsc_StatWait inlines strlen for the name
 * checksum. ADXSTM_GetStat is folded into 0x16EC40 and called as
 * ADXSTM_GetStat. lsc_ExecHndl is the PS2 C.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

#define LSC_MAX_STM 16

typedef struct {
    s32 id;
    const char *fname;
    s32 unk8;
    void *dir;
    s32 unk10;
    s32 unk14;
    s32 stat;
    s32 rd_sct;
} LSC_STM;

typedef struct LSC_OBJ {
    s8 used;
    s8 stat;
    s8 unk2;
    s8 lp_flg;
    s8 unk4;
    u8 pad5[3];
    void *sj;
    s32 unkC;
    s32 unk10;
    s32 flow_limit;
    s32 unk18;
    s32 last_stm_index;
    s32 unk20;
    s32 num_stm;
    void *stm_hndl;
    s32 unk2C;
    s32 pad30;
    s32 unk34;
    LSC_STM stm[LSC_MAX_STM];
} LSC_OBJ;

extern void LSC_CallErrFunc(const char *fmt, ...);
extern void LSC_CallStatFunc(void);
extern s32 LSC_EntryFileRange(LSC_OBJ *lsc, const char *fname, void *dir, s32 ofst, s32 fnsct);
extern void ADXSTM_StopNw(void *stm);
extern void ADXSTM_ReleaseFileNw(void *stm);
extern void ADXSTM_BindFileNw(void *stm, const char *fname, void *dir, s32 ofst, s32 file_sct);
extern void ADXSTM_SetEos(void *stm, s32 eos);
extern s32 ADXSTM_SetBufSize(void *stm, s32 min, s32 max);
extern s32 ADXSTM_Seek(void *stm, s32 offset);
extern s32 ADXSTM_Start(void *stm);
extern s32 ADXSTM_Tell(void *stm);
extern s32 ADXSTM_GetStat(void *stm); /* ADXSTM_GetStat */

void lsc_StatWait(LSC_OBJ *lsc) {
    LSC_STM *stm = &lsc->stm[lsc->unk20];
    u32 len;
    u32 i;
    s32 sum;

    if (lsc->num_stm <= 0) {
        return;
    }

    ADXSTM_StopNw(lsc->stm_hndl);
    ADXSTM_ReleaseFileNw(lsc->stm_hndl);

    len = strlen(stm->fname);
    sum = 0;

    for (i = 0; i < len; i++) {
        sum += (u8)stm->fname[i];
    }

    if (sum != stm->unk8) {
        LSC_CallErrFunc("E0013: '%s' is different from entry file name.(LSC_ExecServer)\n", stm->fname);
        return;
    }

    ADXSTM_BindFileNw(lsc->stm_hndl, stm->fname, stm->dir, stm->unk10, stm->unk14);
    ADXSTM_SetEos(lsc->stm_hndl, stm->unk14);
    lsc->unk2C = stm->unk14;
    stm->rd_sct = 0;
    lsc->unk2 = 0;
    ADXSTM_SetBufSize(lsc->stm_hndl, lsc->flow_limit, lsc->unk18);
    ADXSTM_Seek(lsc->stm_hndl, 0);
    ADXSTM_Start(lsc->stm_hndl);
    lsc->unk2 = 1;
    stm->stat = 1;
}

void lsc_StatRead(LSC_OBJ *lsc) {
    LSC_STM *stm;
    s32 stat;

    if (lsc->stm_hndl == NULL) {
        LSC_CallErrFunc("E0007: lsc->fp=NULL\n");
        return;
    }

    stm = &lsc->stm[lsc->unk20];
    stat = ADXSTM_GetStat(lsc->stm_hndl);

    if (stat == 4) {
        lsc->stat = 3;
        return;
    }

    if (stat == 2) {
        stm->rd_sct = ADXSTM_Tell(lsc->stm_hndl);
        return;
    }

    if (stat == 3) {
        stm->rd_sct = lsc->unk2C;
        stm->stat = 2;
    }
}

void lsc_StatEnd(LSC_OBJ *lsc) {
    LSC_STM *stm;
    const char *fname = NULL;
    void *dir = NULL;
    s32 ofst = 0;
    s32 fnsct = 0;

    if (lsc->stm_hndl == NULL) {
        return;
    }

    if (lsc->lp_flg == 1) {
        stm = &lsc->stm[lsc->unk20];
        fname = stm->fname;
        dir = stm->dir;
        ofst = stm->unk10;
        fnsct = stm->unk14;
    }

    lsc->num_stm--;
    lsc->unk20 = (lsc->unk20 + 1) % LSC_MAX_STM;

    if (lsc->num_stm <= 0) {
        LSC_CallStatFunc();
        lsc->stat = 1;
    }

    if (lsc->lp_flg == 1) {
        LSC_EntryFileRange(lsc, fname, dir, ofst, fnsct);
    }
}

void lsc_ExecHndl(LSC_OBJ *lsc) {
    if ((lsc->unk4 == 1) || (lsc->stat != 2) || (lsc->num_stm <= 0)) {
        return;
    }

    if (lsc->stm[lsc->unk20].stat == 1) {
        lsc_StatRead(lsc);
    }

    if (lsc->stm[lsc->unk20].stat == 2) {
        lsc_StatEnd(lsc);
    }

    if (lsc->stm[lsc->unk20].stat != 0) {
        return;
    }

    lsc_StatWait(lsc);
}
