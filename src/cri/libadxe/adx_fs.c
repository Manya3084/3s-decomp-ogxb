/* adxf_ChkPrmPt 0x165B80, adxf_CreateAdxFs 0x165BF0, adxf_SetFileInfoEx 0x165C50,
 * adxf_read_sj32 0x165D30, ADXF_ReadNw32 0x165DF0, ADXF_ReadNw 0x165F20,
 * ADXF_Stop 0x165F50, ADXF_StopNw 0x165FF0, adxf_ExecOne 0x166070,
 * ADXF_ExecServer 0x166100, ADXF_GetStat 0x166130, adxf_ChkPrmGfr 0x166150.
 *
 * ptid compares are signed. adxf_ptinfo is the pointer table at 0xCE1F20.
 * nfile is at +8 of a partition record. adxf_SetFileInfoEx does not test adxf.
 * ADXF_ReadNw tests 4-byte alignment. The handle array is 16 objects at
 * 0xCE2320, stride 0x44. adxf_ocbi_fg is 0xCE1EC4. The alloc, history, and
 * ADXSTM callees below are not named yet.
 */

#include "types.h"

#include <stddef.h>
#include <stdint.h>

#define ADXF_PART_MAX 256
#define ADXF_ERR_OK 0
#define ADXF_ERR_FATAL (-1)
#define ADXF_ERR_INTERNAL (-2)
#define ADXF_ERR_PRM (-3)

#define ADXF_OBJ_MAX 16

#define ADXF_STAT_STOP 1
#define ADXF_STAT_READING 2
#define ADXF_STAT_READEND 3
#define ADXF_STAT_ERROR 4

#define ADXF_CMD_READ_NW32 4
#define ADXF_CMD_STOP 5
#define ADXF_CMD_STOP_NW 7

typedef struct ADX_FS {
    s8 used;
    s8 stat;
    s8 sjflag;
    s8 stopnw_flg;
    void *stm;
    void *sj;
    s32 fnsct;
    s32 fsize;
    s32 skpos;
    s32 rdstpos;
    s32 rqsct;
    s32 rdsct;
    void *buf;
    s32 bsize;
    s32 rqrdsct;
    s32 ofst;
    void *dir;
    const char *fname;
    s32 unk3C;
    s32 unk40;
} ADX_FS;

typedef struct ADXF_PTINFO {
    void *next;
    s32 size;
    s32 nfile;
} ADXF_PTINFO;

#if defined(__i386__)
_Static_assert(offsetof(ADX_FS, stm) == 4, "stm");
_Static_assert(offsetof(ADX_FS, sj) == 8, "sj");
_Static_assert(offsetof(ADX_FS, fnsct) == 0x0C, "fnsct");
_Static_assert(offsetof(ADX_FS, fsize) == 0x10, "fsize");
_Static_assert(offsetof(ADX_FS, skpos) == 0x14, "skpos");
_Static_assert(offsetof(ADX_FS, rdstpos) == 0x18, "rdstpos");
_Static_assert(offsetof(ADX_FS, rqsct) == 0x1C, "rqsct");
_Static_assert(offsetof(ADX_FS, rdsct) == 0x20, "rdsct");
_Static_assert(offsetof(ADX_FS, buf) == 0x24, "buf");
_Static_assert(offsetof(ADX_FS, bsize) == 0x28, "bsize");
_Static_assert(offsetof(ADX_FS, rqrdsct) == 0x2C, "rqrdsct");
_Static_assert(sizeof(ADX_FS) == 0x44, "ADX_FS");
_Static_assert(offsetof(ADX_FS, dir) == 0x34, "dir");
_Static_assert(offsetof(ADX_FS, fname) == 0x38, "fname");
_Static_assert(offsetof(ADX_FS, unk3C) == 0x3C, "unk3C");
_Static_assert(offsetof(ADX_FS, unk40) == 0x40, "unk40");
_Static_assert(offsetof(ADXF_PTINFO, nfile) == 8, "nfile");
#endif

extern void ADXERR_CallErrFunc1(const char *msg);
extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern ADX_FS *adxf_AllocAdxFs(void);
extern void adxf_SetCmdHstry(s32 cmd, s32 phase, void *prm0, s32 prm1, s32 prm2);
extern void adxf_CloseSjStm(ADX_FS *adxf);
extern void *ADXSTM_Create(void *para, s32 maxsct);
extern void ADXSTM_BindFile(void *stm, const char *fname, void *dir, s32 ofst, s32 nsct);
extern s32 ADXSTM_GetStat(void *stm);
extern void ADXSTM_ReleaseFile(void *stm);
extern s32 ADXSTM_GetFileLen(void *stm);
extern s32 ADXSTM_GetFileSct(void *stm);
extern void ADXSTM_Stop(void *stm);
extern s32 ADXSTM_Tell(void *stm);
extern void ADXSTM_StopNw(void *stm);
extern void ADXSTM_SetEos(void *stm, s32 eos);
extern void ADXSTM_SetSj(void *stm, void *sj);
extern void ADXSTM_SetReqRdSize(void *stm, s32 size);
extern void ADXSTM_SetPause(void *stm, s32 sw);
extern void ADXSTM_Seek(void *stm, s32 pos);
extern void ADXSTM_Start2(void *stm, s32 nsct);
extern void *SJRBF_Create(void *buf, s32 bsize, s32 arg2);
extern void ADXF_Ocbi(void *buf, s32 bsize);
extern s32 adxf_ocbi_fg;
extern ADX_FS adxf_obj[ADXF_OBJ_MAX];
extern ADXF_PTINFO *adxf_ptinfo[];

s32 adxf_ChkPrmPt(s32 ptid, void *ptinfo) {
    if (ptid < 0 || ptid >= ADXF_PART_MAX) {
        ADXERR_CallErrFunc1("E9040801:partition ID is range outside.(adxf_ChkPrmPt)");
        return ADXF_ERR_PRM;
    }

    if (ptinfo == 0) {
        ADXERR_CallErrFunc1("E9040802:'ptinfo' is NULL.(adxf_ChkPrmPt)");
        return ADXF_ERR_PRM;
    }

    return ADXF_ERR_OK;
}

ADX_FS *adxf_CreateAdxFs(void) {
    ADX_FS *adxf;
    void *stm;

    adxf = adxf_AllocAdxFs();

    if (adxf == 0) {
        return 0;
    }

    stm = ADXSTM_Create(0, 0x100);
    adxf->stm = stm;

    if (stm == 0) {
        ADXERR_CallErrFunc1("E02111001:can't create stm handle (adxf_CreateAdxFs)");
        return 0;
    }

    adxf->rdstpos = 0;
    adxf->rqsct = 0;
    adxf->rdsct = 0;
    adxf->sjflag = 0;
    adxf->sj = 0;
    adxf->stopnw_flg = 0;
    adxf->stat = ADXF_STAT_STOP;
    adxf->rqrdsct = 0x200;
    adxf->used = 1;
    return adxf;
}

s32 adxf_SetFileInfoEx(ADX_FS *adxf, const char *fname, void *dir) {
    if (fname == 0) {
        ADXERR_CallErrFunc1("E9081901:illigal parameter fname=null.(ADXF_Open)");
        return ADXF_ERR_FATAL;
    }

    adxf->fname = fname;
    adxf->dir = dir;
    adxf->skpos = 0;
    ADXSTM_BindFile(adxf->stm, fname, dir, 0, 0xFFFFF);

    if (ADXSTM_GetStat(adxf->stm) == 4) {
        ADXSTM_ReleaseFile(adxf->stm);
        return ADXF_ERR_FATAL;
    }

    adxf->fsize = ADXSTM_GetFileLen(adxf->stm);
    adxf->unk40 = adxf->fnsct = ADXSTM_GetFileSct(adxf->stm);
    adxf->unk3C = 0;
    return ADXF_ERR_OK;
}

s32 adxf_read_sj32(ADX_FS *adxf, s32 nsct, void *sj) {
    s32 rqsct;

    if (ADXSTM_GetStat(adxf->stm) != ADXF_STAT_STOP) {
        ADXSTM_Stop(adxf->stm);
    }

    ADXCRS_Lock();
    adxf->rdstpos = adxf->ofst + adxf->skpos;
    rqsct = adxf->fnsct - adxf->skpos;

    if (nsct < rqsct) {
        rqsct = nsct;
    }

    adxf->rqsct = rqsct;
    adxf->rdsct = 0;

    if (rqsct == 0) {
        adxf->stat = ADXF_STAT_READEND;
        ADXCRS_Unlock();
        return 0;
    }

    ADXSTM_SetEos(adxf->stm, -1);
    ADXSTM_SetSj(adxf->stm, sj);
    ADXSTM_SetReqRdSize(adxf->stm, adxf->rqrdsct);
    adxf->stat = ADXF_STAT_READING;
    adxf->stopnw_flg = 0;
    ADXSTM_SetPause(adxf->stm, 0);
    ADXSTM_Seek(adxf->stm, adxf->skpos);
    ADXSTM_Start2(adxf->stm, adxf->rqsct);
    ADXCRS_Unlock();
    return adxf->rqsct;
}

s32 ADXF_ReadNw32(ADX_FS *adxf, s32 nsct, void *buf) {
    void *sj;
    s32 bsize;
    s32 read;

    adxf_SetCmdHstry(ADXF_CMD_READ_NW32, 0, adxf, nsct, (s32)(intptr_t)buf);

    if (adxf == 0) {
        ADXERR_CallErrFunc1("E9040816:'adxf' is NULL.(ADXF_ReadNw32)");
        return ADXF_ERR_PRM;
    }

    if (nsct < 0) {
        ADXERR_CallErrFunc1("E9040817:'nsct' is negative.(ADXF_ReadNw32)");
        return ADXF_ERR_PRM;
    }

    if (buf == 0) {
        ADXERR_CallErrFunc1("E9040818:'buf' is NULL.(ADXF_ReadNw32)");
        return ADXF_ERR_PRM;
    }

    if (adxf->stat == ADXF_STAT_READING) {
        return ADXF_ERR_OK;
    }

    if (adxf->sj != 0) {
        ADXERR_CallErrFunc1("E9040821:'sj' must be NULL.(ADXF_ReadNw32)");
        return ADXF_ERR_FATAL;
    }

    bsize = nsct << 11;
    sj = SJRBF_Create(buf, bsize, 0);

    if (sj == 0) {
        return ADXF_ERR_INTERNAL;
    }

    ADXCRS_Lock();
    adxf->buf = buf;
    adxf->bsize = bsize;
    adxf->sj = sj;

    if (adxf_ocbi_fg == 1) {
        ADXF_Ocbi(buf, bsize);
    }

    ADXCRS_Unlock();
    read = adxf_read_sj32(adxf, nsct, adxf->sj);

    if (read <= 0) {
        ADXCRS_Lock();

        if (adxf->sj != 0) {
            /* Destroy is vtable slot +0x0C. */
            void (**vtbl)(void *) = *(void (***)(void *))adxf->sj;
            vtbl[3](adxf->sj);
            adxf->sj = 0;
        }

        ADXCRS_Unlock();
    }

    adxf->sjflag = 0;
    adxf_SetCmdHstry(ADXF_CMD_READ_NW32, 1, adxf, nsct, (s32)(intptr_t)buf);
    return read;
}

s32 ADXF_ReadNw(ADX_FS *adxf, s32 nsct, void *buf) {
    if (((uintptr_t)buf & 3) != 0) {
        ADXERR_CallErrFunc1("E0120401:'buf' isn't 4byte alignment.(ADXF_ReadNw)");
        return ADXF_ERR_PRM;
    }

    return ADXF_ReadNw32(adxf, nsct, buf);
}

s32 ADXF_Stop(ADX_FS *adxf) {
    void *stm;

    adxf_SetCmdHstry(ADXF_CMD_STOP, 0, adxf, -1, -1);

    if (adxf == 0) {
        ADXERR_CallErrFunc1("E9040822:'adxf' is NULL.(ADXF_Stop)");
        return ADXF_ERR_PRM;
    }

    if (adxf->stat == ADXF_STAT_STOP) {
        return adxf->skpos;
    }

    if (adxf->stat == ADXF_STAT_READEND) {
        adxf->stat = ADXF_STAT_STOP;
        return adxf->skpos;
    }

    stm = adxf->stm;

    if (stm == 0) {
        ADXERR_CallErrFunc1("E9040823:'adxf->stm' is NULL.(ADXF_Stop)");
        return ADXF_ERR_FATAL;
    }

    ADXSTM_Stop(stm);
    ADXCRS_Lock();
    adxf->rdsct = ADXSTM_Tell(adxf->stm) - adxf->skpos;
    adxf_CloseSjStm(adxf);
    adxf->stat = ADXF_STAT_STOP;
    ADXCRS_Unlock();
    adxf_SetCmdHstry(ADXF_CMD_STOP, 1, adxf, -1, -1);
    return adxf->skpos;
}

s32 ADXF_StopNw(ADX_FS *adxf) {
    void *stm;

    adxf_SetCmdHstry(ADXF_CMD_STOP_NW, 0, adxf, -1, -1);

    if (adxf == 0) {
        ADXERR_CallErrFunc1("E2092301:'adxf' is NULL.(ADXF_StopNw)");
        return ADXF_ERR_PRM;
    }

    if (adxf->stat == ADXF_STAT_STOP) {
        return adxf->skpos;
    }

    if (adxf->stat == ADXF_STAT_READEND) {
        adxf->stat = ADXF_STAT_STOP;
        return adxf->skpos;
    }

    stm = adxf->stm;

    if (stm == 0) {
        ADXERR_CallErrFunc1("E2092302:'adxf->stm' is NULL.(ADXF_StopNw)");
        return ADXF_ERR_FATAL;
    }

    ADXSTM_StopNw(stm);
    adxf->stopnw_flg = 1;
    adxf_SetCmdHstry(ADXF_CMD_STOP_NW, 1, adxf, -1, -1);
    return adxf->skpos;
}

void adxf_ExecOne(ADX_FS *adxf) {
    s32 stat;

    if (adxf->stat == ADXF_STAT_READING) {
        adxf->stat = (s8)ADXSTM_GetStat(adxf->stm);
        adxf->rdsct = ADXSTM_Tell(adxf->stm) - adxf->skpos;

        if (adxf->stat == ADXF_STAT_READEND || adxf->stat == ADXF_STAT_ERROR) {
            adxf->skpos += adxf->rdsct;
            adxf_CloseSjStm(adxf);
        }
    }

    if (adxf->stopnw_flg == 1) {
        stat = ADXSTM_GetStat(adxf->stm);

        if (stat == ADXF_STAT_STOP) {
            adxf->rdsct = ADXSTM_Tell(adxf->stm) - adxf->skpos;
            adxf_CloseSjStm(adxf);
            adxf->stat = (s8)stat;
            adxf->stopnw_flg = 0;
        }
    }
}

void ADXF_ExecServer(void) {
    s32 i;

    ADXCRS_Lock();

    for (i = 0; i < ADXF_OBJ_MAX; i++) {
        if (adxf_obj[i].used == 1) {
            adxf_ExecOne(&adxf_obj[i]);
        }
    }

    ADXCRS_Unlock();
}

s32 ADXF_GetStat(ADX_FS *adxf) {
    if (adxf == 0) {
        ADXERR_CallErrFunc1("E9040832:'adxf' is NULL.(ADXF_GetStat)");
        return ADXF_ERR_PRM;
    }

    return adxf->stat;
}

s32 adxf_ChkPrmGfr(s32 ptid, s32 flid) {
    ADXF_PTINFO *ptinfo;

    if (ptid < 0 || ptid >= ADXF_PART_MAX) {
        ADXERR_CallErrFunc1("E9040828:'ptid' is range outside.");
        return ADXF_ERR_PRM;
    }

    ptinfo = adxf_ptinfo[ptid];

    if (ptinfo == 0) {
        ADXERR_CallErrFunc1("E9040828:'ptid' is range outside.");
        return ADXF_ERR_PRM;
    }

    if (flid < 0 || flid >= ptinfo->nfile) {
        ADXERR_CallErrFunc1("E9040828:'flid' is range outside.");
        return ADXF_ERR_PRM;
    }

    return ADXF_ERR_OK;
}
