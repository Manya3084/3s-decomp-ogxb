/* adxf_SetCmdHstry 0x165B10, adxf_ChkPrmPt 0x165B80, adxf_AllocAdxFs 0x165BC0,
 * adxf_CreateAdxFs 0x165BF0, adxf_SetFileInfoEx 0x165C50, adxf_CloseSjStm 0x165CE0,
 * adxf_read_sj32 0x165D30, ADXF_ReadNw32 0x165DF0, ADXF_ReadNw 0x165F20,
 * ADXF_Stop 0x165F50, ADXF_StopNw 0x165FF0, adxf_ExecOne 0x166070,
 * ADXF_ExecServer 0x166100, ADXF_GetStat 0x166130, adxf_ChkPrmGfr 0x166150,
 * ADXF_GetFnameRangeEx 0x1661A0, ADXF_GetFnameFromPt 0x166280,
 * adxf_SetAfsFileInfo 0x166290, ADXF_Close 0x166350, ADXF_CloseAll 0x1663C0,
 * adxf_CloseLdptnwHn 0x1663F0, ADXF_Open 0x1666C0, ADXF_OpenAfs 0x166720,
 * adxf_LoadPtBothNw 0x166780, ADXF_LoadPtNwEx 0x166940,
 * ADXF_LoadPartitionNw 0x166970, ADXF_Init 0x16DB40, ADXF_Finish 0x16DBE0.
 *
 * ptid compares are signed. adxf_ptinfo is the pointer table at 0xCE1F20.
 * nfile is at +8 of a partition record. A record's rev is the byte at +0x0F,
 * fname starts at +0x10, curdir is +0x110, ofst is +0x114, and top is +0x118.
 * rev == 1 reads dword sizes at +0x11C. Any other rev reads a word top and
 * word sizes at +0x11A. There is no separate ADXF_GetFnameRange wrapper.
 * adxf_SetFileInfoEx does not test adxf. ADXF_ReadNw tests 4-byte alignment.
 * The handle array is 16 objects at 0xCE2320, stride 0x44. adxf_ocbi_fg is
 * 0xCE1EC4. adxf_ldpt_work is 0xCEA400. adxf_ldptnw_hn is 0xCE1F00, adxf_ldptnw_ptid is 0xCE1DA0,
 * adxf_flno is 0xCE1F04, adxf_hstry_no is 0xCE1EC0, and the command history
 * is 16 records of 0x10 at 0xCE1DC0. ncall is 16 words at 0xCE1EE0. The
 * init counter is 0x7A6058. The build pointer is 0x2E1260. adxf_ldpt_rdsct
 * is 0x7A51BC, and adxf_ldpt_buf is 0x7A51B8. ADXSTM_Destroy is 0x16E520.
 * ADXSTM_SetEos is named in adx_stmc.c. The other ADXSTM callees stay unnamed.
 */

#include "types.h"

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define ADXF_PART_MAX 256
#define ADXF_ERR_OK 0
#define ADXF_ERR_FATAL (-1)
#define ADXF_ERR_INTERNAL (-2)
#define ADXF_ERR_PRM (-3)

#define ADXF_OBJ_MAX 16
#define ADXF_CMD_HSTRY_MAX 16
#define ADXF_CMD_NUM_MAX 16

#define ADXF_STAT_STOP 1
#define ADXF_STAT_READING 2
#define ADXF_STAT_READEND 3
#define ADXF_STAT_ERROR 4

#define ADXF_FNAME_MAX 256

#define ADXF_CMD_OPEN 1
#define ADXF_CMD_OPEN_AFS 2
#define ADXF_CMD_CLOSE 3
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
    u16 nentry;
    s8 type;
    s8 rev;
    char fname[ADXF_FNAME_MAX];
    void *curdir;
    s32 ofst;
    s32 top;
} ADXF_PTINFO;

typedef struct ADXF_PTINFO_SMALL {
    void *next;
    s32 size;
    s32 nfile;
    u16 nentry;
    s8 type;
    s8 rev;
    char fname[ADXF_FNAME_MAX];
    void *curdir;
    s32 ofst;
    u16 top;
    u16 file_sizes[1];
} ADXF_PTINFO_SMALL;

typedef struct {
    u8 cmdid;
    u8 fg;
    u16 ncall;
    s32 prm[3];
} ADXF_CMD_HSTRY;

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
_Static_assert(offsetof(ADXF_PTINFO, rev) == 0x0F, "rev");
_Static_assert(offsetof(ADXF_PTINFO, fname) == 0x10, "pt fname");
_Static_assert(offsetof(ADXF_PTINFO, curdir) == 0x110, "curdir");
_Static_assert(offsetof(ADXF_PTINFO, ofst) == 0x114, "pt ofst");
_Static_assert(offsetof(ADXF_PTINFO, top) == 0x118, "top");
_Static_assert(sizeof(ADXF_PTINFO) == 0x11C, "ADXF_PTINFO");
_Static_assert(offsetof(ADXF_PTINFO_SMALL, top) == 0x118, "small top");
_Static_assert(offsetof(ADXF_PTINFO_SMALL, file_sizes) == 0x11A, "file_sizes");
_Static_assert(sizeof(ADXF_CMD_HSTRY) == 0x10, "ADXF_CMD_HSTRY");
#endif

extern void ADXERR_CallErrFunc1(const char *msg);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
extern void sub_001725E0(void *buf, s32 bsize);
extern void *ADXSTM_Create(void *para, s32 maxsct);
extern void ADXSTM_BindFile(void *stm, const char *fname, void *dir, s32 ofst, s32 nsct);
extern s32 sub_0016EC40(void *stm);
extern void ADXSTM_ReleaseFile(void *stm);
extern void ADXSTM_Destroy(void *stm);
extern s32 sub_00172CE0(void *stm);
extern s32 sub_00172C60(void *stm);
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
extern ADXF_PTINFO *adxf_ptinfo[ADXF_PART_MAX];
extern ADX_FS *adxf_ldptnw_hn;
extern s32 adxf_ldptnw_ptid;
extern s32 adxf_flno;
char *volatile adxf_build = "\nADXF/XBOX Ver.7.13 Build:Feb 13 2004 21:08:38\n";
extern s32 adxf_init_cnt;
extern ADXF_CMD_HSTRY adxf_cmd_hstry[ADXF_CMD_HSTRY_MAX];
extern s16 adxf_cmd_ncall[ADXF_CMD_NUM_MAX];
extern s32 adxf_hstry_no;
extern s32 adxf_ldpt_rdsct;
extern void *adxf_ldpt_buf;

/* adxf_SetCmdHstry 0x165B10.
 *
 * Matches the PS2 body. hstry_no % 16 is the MSVC signed-modulo
 * sequence: and with 0x8000000F, then the negative adjustment.
 * That adjustment is an imm8 or. The incremented history number
 * is stored after the record fields. ncall is a 16-bit table.
 * The record is 0x10 bytes. The ret at 0x165B70 is followed by
 * int3s through 0x165B7F.
 */

void adxf_SetCmdHstry(s32 cmd, s32 phase, void *prm0, s32 prm1, s32 prm2) {
    ADXF_CMD_HSTRY *cmd_hstry;

    adxf_hstry_no %= ADXF_CMD_HSTRY_MAX;
    cmd_hstry = &adxf_cmd_hstry[adxf_hstry_no];

    if (phase == 0) {
        adxf_cmd_ncall[cmd] += 1;
    }

    adxf_hstry_no += 1;
    cmd_hstry->cmdid = (u8)cmd;
    cmd_hstry->fg = (u8)phase;
    cmd_hstry->ncall = (u16)adxf_cmd_ncall[cmd];
    cmd_hstry->prm[0] = (s32)(intptr_t)prm0;
    cmd_hstry->prm[1] = prm1;
    cmd_hstry->prm[2] = prm2;
}

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

/* adxf_AllocAdxFs 0x165BC0.
 *
 * Indexes adxf_obj directly (a temp pointer gives the pointer-only loop). The scan is 16 objects at 0xCE2320, stride
 * 0x44, and the cursor stops at 0xCE2760. used is the byte at +0.
 * A free object is returned. None free returns 0. The found path
 * multiplies the index by the stride. The lea esp, [esp] is an
 * alignment nop. The only caller is adxf_CreateAdxFs at 0x165BF2.
 * The previous byte is the ChkPrmPt ret, so this name is interior.
 */

ADX_FS *adxf_AllocAdxFs(void) {
    s32 i;
    ADX_FS *start = 0;

    for (i = 0; i < ADXF_OBJ_MAX; i++) {
        if (adxf_obj[i].used == 0) {
            start = &adxf_obj[i];
            break;
        }
    }

    return start;
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

    if (sub_0016EC40(adxf->stm) == 4) {
        ADXSTM_ReleaseFile(adxf->stm);
        return ADXF_ERR_FATAL;
    }

    adxf->fsize = sub_00172CE0(adxf->stm);
    adxf->unk40 = adxf->fnsct = sub_00172C60(adxf->stm);
    adxf->unk3C = 0;
    return ADXF_ERR_OK;
}

/* adxf_CloseSjStm 0x165CE0.
 *
 * Matches the PS2 body. A null sj, or a nonzero sjflag, returns.
 * When adxf_ocbi_fg at 0xCE1EC4 is 1, this calls the empty ret at
 * 0x1725E0 with buf and bsize. That address stays unnamed. The sj
 * pointer is cleared, then this tail-jumps through vtable +0x0C.
 * Callers are ADXF_Stop at 0x165FC6 and adxf_ExecOne at 0x1660AF
 * and 0x1660DF. The ret at 0x165D21 is followed by int3s through
 * 0x165D2F.
 */

void adxf_CloseSjStm(ADX_FS *adxf) {
    void *sj;
    void (**vtbl)(void *);

    if (adxf->sj == 0 || adxf->sjflag != 0) {
        return;
    }

    if (adxf_ocbi_fg == 1) {
        sub_001725E0(adxf->buf, adxf->bsize);
    }

    sj = adxf->sj;
    adxf->sj = 0;
    vtbl = *(void (***)(void *))sj;
    vtbl[3](sj);
}

s32 adxf_read_sj32(ADX_FS *adxf, s32 nsct, void *sj) {
    s32 rqsct;

    if (sub_0016EC40(adxf->stm) != ADXF_STAT_STOP) {
        ADXSTM_Stop(adxf->stm);
    }

    sub_0016AA60();
    adxf->rdstpos = adxf->ofst + adxf->skpos;
    rqsct = adxf->fnsct - adxf->skpos;

    if (nsct < rqsct) {
        rqsct = nsct;
    }

    adxf->rqsct = rqsct;
    adxf->rdsct = 0;

    if (rqsct == 0) {
        adxf->stat = ADXF_STAT_READEND;
        sub_0016AA70();
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
    sub_0016AA70();
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

    sub_0016AA60();
    adxf->buf = buf;
    adxf->bsize = bsize;
    adxf->sj = sj;

    if (adxf_ocbi_fg == 1) {
        ADXF_Ocbi(buf, bsize);
    }

    sub_0016AA70();
    read = adxf_read_sj32(adxf, nsct, adxf->sj);

    if (read <= 0) {
        sub_0016AA60();

        if (adxf->sj != 0) {
            /* Destroy is vtable slot +0x0C. */
            void (**vtbl)(void *) = *(void (***)(void *))adxf->sj;
            vtbl[3](adxf->sj);
            adxf->sj = 0;
        }

        sub_0016AA70();
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
    sub_0016AA60();
    adxf->rdsct = ADXSTM_Tell(adxf->stm) - adxf->skpos;
    adxf_CloseSjStm(adxf);
    adxf->stat = ADXF_STAT_STOP;
    sub_0016AA70();
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
        adxf->stat = (s8)sub_0016EC40(adxf->stm);
        adxf->rdsct = ADXSTM_Tell(adxf->stm) - adxf->skpos;

        if (adxf->stat == ADXF_STAT_READEND || adxf->stat == ADXF_STAT_ERROR) {
            adxf->skpos += adxf->rdsct;
            adxf_CloseSjStm(adxf);
        }
    }

    if (adxf->stopnw_flg == 1) {
        stat = sub_0016EC40(adxf->stm);

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

    sub_0016AA60();

    for (i = 0; i < ADXF_OBJ_MAX; i++) {
        if (adxf_obj[i].used == 1) {
            adxf_ExecOne(&adxf_obj[i]);
        }
    }

    sub_0016AA70();
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

s32 ADXF_GetFnameRangeEx(s32 ptid, s32 flid, char *fname, void **dir, s32 *ofst, s32 *fnsct) {
    ADXF_PTINFO *ptinfo;
    ADXF_PTINFO_SMALL *small;
    s32 ret;
    s32 nsct;
    s32 i;
    u32 offset;

    ret = adxf_ChkPrmGfr(ptid, flid);

    if (ret < 0) {
        *dir = 0;
        *ofst = -1;
        *fnsct = -1;
        return ret;
    }

    ptinfo = adxf_ptinfo[ptid];
    small = (ADXF_PTINFO_SMALL *)ptinfo;

    if (ptinfo->rev == 1) {
        u32 *sizes = (u32 *)(ptinfo + 1);

        offset = (u32)ptinfo->top;

        for (i = 0; i < flid; i++) {
            offset += sizes[i];
        }

        nsct = (s32)sizes[flid];
    } else {
        offset = small->top;

        for (i = 0; i < flid; i++) {
            offset += small->file_sizes[i];
        }

        nsct = small->file_sizes[flid];
    }

    *fnsct = nsct;
    strncpy(fname, ptinfo->fname, ADXF_FNAME_MAX);
    *dir = ptinfo->curdir;
    *ofst = ptinfo->ofst + (s32)offset;
    return ret;
}

char *ADXF_GetFnameFromPt(s32 ptid) {
    return adxf_ptinfo[ptid]->fname;
}

s32 adxf_SetAfsFileInfo(ADX_FS *adxf, s32 ptid, s32 flid) {
    char fname[ADXF_FNAME_MAX];
    void *dir;
    s32 ofst;
    s32 fnsct;

    if (ADXF_GetFnameRangeEx(ptid, flid, fname, &dir, &ofst, &fnsct) < 0) {
        return ADXF_ERR_PRM;
    }

    adxf->ofst = ofst;
    adxf->dir = dir;
    adxf->fname = ADXF_GetFnameFromPt(ptid);
    adxf->skpos = 0;
    adxf->unk40 = fnsct;
    adxf->unk3C = ofst;
    ADXSTM_BindFile(adxf->stm, adxf->fname, adxf->dir, adxf->unk3C, adxf->unk40);

    if (sub_0016EC40(adxf->stm) == 4) {
        ADXSTM_ReleaseFile(adxf->stm);
        return ADXF_ERR_FATAL;
    }

    adxf->fnsct = fnsct;
    adxf->fsize = fnsct << 11;
    return ADXF_ERR_OK;
}

void ADXF_Close(ADX_FS *adxf) {
    void *stm;

    adxf_SetCmdHstry(ADXF_CMD_CLOSE, 0, adxf, -1, -1);

    if (adxf == 0) {
        return;
    }

    if (adxf->stat == ADXF_STAT_READING) {
        ADXF_Stop(adxf);
    }

    stm = adxf->stm;

    if (stm != 0) {
        adxf->used = 0;
        adxf->stm = 0;
        ADXSTM_ReleaseFile(stm);
        ADXSTM_Destroy(stm);
    }

    memset(adxf, 0, sizeof(ADX_FS));
    adxf_SetCmdHstry(ADXF_CMD_CLOSE, 1, adxf, -1, -1);
}

void ADXF_CloseAll(void) {
    s32 i;

    for (i = 0; i < ADXF_OBJ_MAX; i++) {
        if (adxf_obj[i].used == 1) {
            ADXF_Close(&adxf_obj[i]);
        }
    }
}

void adxf_CloseLdptnwHn(void) {
    ADXF_Close(adxf_ldptnw_hn);
    adxf_ldptnw_hn = 0;
    adxf_ldptnw_ptid = -1;
    adxf_flno = 0;
    adxf_ldpt_rdsct = 0;
}

ADX_FS *ADXF_Open(char *fname, void *atr) {
    ADX_FS *adxf;

    adxf_SetCmdHstry(ADXF_CMD_OPEN, 0, fname, (s32)(intptr_t)atr, -1);
    adxf = adxf_CreateAdxFs();

    if (adxf != 0) {
        if (adxf_SetFileInfoEx(adxf, fname, atr) < 0) {
            ADXF_Close(adxf);
            adxf = 0;
        }
    }

    adxf_SetCmdHstry(ADXF_CMD_OPEN, 1, fname, (s32)(intptr_t)atr, -1);
    return adxf;
}

ADX_FS *ADXF_OpenAfs(s32 ptid, s32 flid) {
    ADX_FS *adxf;

    adxf_SetCmdHstry(ADXF_CMD_OPEN_AFS, 0, (void *)(intptr_t)ptid, flid, -1);
    adxf = adxf_CreateAdxFs();

    if (adxf != 0 && adxf_SetAfsFileInfo(adxf, ptid, flid) < 0) {
        ADXF_Close(adxf);
        adxf = 0;
    }

    adxf_SetCmdHstry(ADXF_CMD_OPEN_AFS, 1, (void *)(intptr_t)ptid, flid, -1);
    return adxf;
}

s32 adxf_LoadPtBothNw(s32 ptid, s32 arg1, s32 arg2, char *fname, void *dir, ADXF_PTINFO *ptinfo, void *tmpbuf,
                      s32 tbsize, s32 rev) {
    s32 ofst;
    s32 fnsct;
    s32 err;

    if (tmpbuf == 0) {
        ADXERR_CallErrFunc1("E1110701:'tmpbuf' is null.(load partition)");
        return ADXF_ERR_PRM;
    }

    if (tbsize <= 0) {
        ADXERR_CallErrFunc1("E1110702:'tbsize' <= 0.(load partition)");
        return ADXF_ERR_PRM;
    }

    err = adxf_ChkPrmPt(ptid, ptinfo);

    if (err < 0) {
        return err;
    }

    if (adxf_ldptnw_ptid >= 0) {
        ADXERR_CallErrFunc1("E0042401:multi-load partition.(load partition)");
        return ADXF_ERR_FATAL;
    }

    adxf_ldptnw_ptid = ptid;
    adxf_flno = 0;
    memset(ptinfo, 0, sizeof(ADXF_PTINFO));
    adxf_ptinfo[ptid] = ptinfo;
    ptinfo->next = 0;

    if (fname == 0) {
        adxf_ldptnw_hn = ADXF_OpenAfs(arg1, arg2);

        if (adxf_ldptnw_hn == 0) {
            ADXERR_CallErrFunc1("E9040804:can't open file.(load partition)");
            return ADXF_ERR_FATAL;
        }

        err = ADXF_GetFnameRangeEx(arg1, arg2, ptinfo->fname, &dir, &ofst, &fnsct);

        if (err < 0) {
            return err;
        }

        ptinfo->ofst = ofst;
    } else {
        adxf_ldptnw_hn = ADXF_Open(fname, dir);

        if (adxf_ldptnw_hn == 0) {
            ADXERR_CallErrFunc1("E9040804:can't open file.(load partition)");
            return ADXF_ERR_FATAL;
        }

        strncpy(ptinfo->fname, fname, ADXF_FNAME_MAX);
    }

    ptinfo->type = 0;
    ptinfo->curdir = dir;
    ptinfo->rev = (s8)rev;
    adxf_ldpt_buf = tmpbuf;
    adxf_ldpt_rdsct = tbsize / 2048;
    err = ADXF_ReadNw(adxf_ldptnw_hn, adxf_ldpt_rdsct, adxf_ldpt_buf);

    if (err < 0) {
        ADXF_Close(adxf_ldptnw_hn);
        return err;
    }

    ptinfo->nfile = 0;
    return ADXF_ERR_OK;
}

s32 ADXF_LoadPtNwEx(s32 ptid, char *fname, void *dir, void *ptinfo, void *tmpbuf, s32 tbsize) {
    return adxf_LoadPtBothNw(ptid, 0, 0, fname, dir, (ADXF_PTINFO *)ptinfo, tmpbuf, tbsize, 0);
}

/* ADXF_LoadPartitionNw 0x166970.
 *
 * PS2 aligns (&adxf_ldpt_work + 0x40) with ~0x3F. Xbox loads 0xCEA420
 * and masks with ~0x1F, then passes sector count 0x800. The only caller
 * is 0x59A13. The ret at 0x16699A is followed by int3s through 0x16699F.
 */

extern u8 adxf_ldpt_work[];

s32 ADXF_LoadPartitionNw(s32 ptid, char *fname, void *dir, void *ptinfo) {
    void *tmpbuf = (void *)(((uintptr_t)adxf_ldpt_work + 0x20) & ~0x1F);

    return ADXF_LoadPtNwEx(ptid, fname, dir, ptinfo, tmpbuf, 0x800);
}

void ADXF_Init(void) {
    (void)adxf_build;

    if (adxf_init_cnt == 0) {
        memset(adxf_obj, 0, sizeof(adxf_obj));
        memset(adxf_ptinfo, 0, sizeof(adxf_ptinfo));
        memset(adxf_cmd_hstry, 0xFF, sizeof(adxf_cmd_hstry));
        memset(adxf_cmd_ncall, 0, sizeof(adxf_cmd_ncall));
        adxf_hstry_no = 0;
        adxf_ocbi_fg = 0;
        adxf_flno = 0;
        adxf_ldptnw_hn = 0;
        adxf_ldptnw_ptid = -1;
    }

    adxf_init_cnt += 1;
}

void ADXF_Finish(void) {
    if (--adxf_init_cnt == 0) {
        ADXF_CloseAll();
        adxf_ldptnw_hn = 0;
        adxf_flno = 0;
        adxf_ocbi_fg = 0;
        adxf_hstry_no = 0;
        memset(adxf_cmd_ncall, 0, sizeof(adxf_cmd_ncall));
        memset(adxf_cmd_hstry, 0xFF, sizeof(adxf_cmd_hstry));
        memset(adxf_ptinfo, 0, sizeof(adxf_ptinfo));
        memset(adxf_obj, 0, sizeof(adxf_obj));
        adxf_ldptnw_ptid = -1;
    }
}

/* xb_adxf_SectorCount 0x165AE0 rounds a byte count up to 2048-byte
 * sectors; ADXF_GetPtStat 0x166930 forwards to ADXF_GetPtStatEx. */

s32 xb_adxf_SectorCount(s32 nbyte) {
    s32 nsct = nbyte / 2048;

    if (nbyte % 2048 > 0) {
        nsct++;
    }

    return nsct;
}

/* ADXF_GetPtStatEx 0x166420.
 *
 * The PS2 decomp's portable C, read against the x86: polls the partition
 * load, checks the AFS header in the first read, then takes each file's
 * size (in sectors, 16-bit for a rev 0 partition) from the table until
 * every file is known, reading on as needed. The second argument is
 * unused. */

s32 ADXF_GetPtStatEx(s32 ptid, void *unused) {
    ADXF_PTINFO *ptinfo;
    s32 *top_rev1 = NULL;
    u16 *top_rev0 = NULL;
    s32 *fsizes_rev1 = NULL;
    u16 *fsizes_rev0 = NULL;
    u8 *bytes;
    s32 stat;
    s32 nfile;
    s32 nsct;
    s32 end;
    s32 i;
    s8 rev;

    (void)unused;

    if (ptid != adxf_ldptnw_ptid) {
        ADXERR_CallErrFunc1("E0041303:illigal parameter 'ptid'.(ADXF_GetPtStat)");
        return ADXF_ERR_PRM;
    }

    stat = ADXF_GetStat(adxf_ldptnw_hn);

    if (stat != ADXF_STAT_READEND) {
        return stat;
    }

    ptinfo = adxf_ptinfo[ptid];
    rev = ptinfo->rev;

    if (rev == 1) {
        top_rev1 = &ptinfo->top;
        fsizes_rev1 = &ptinfo->top + 1;
    } else {
        top_rev0 = (u16 *)&ptinfo->top;
        fsizes_rev0 = (u16 *)&ptinfo->top + 1;
    }

    if (ptinfo->nfile == 0) {
        bytes = adxf_ldpt_buf;

        if (memcmp(bytes, "AFS", 3) != 0) {
            ADXERR_CallErrFunc1("E0040701:Illigal format(not AFS).(ADXF_GetPtStat)");
            adxf_CloseLdptnwHn();
            return ADXF_STAT_ERROR;
        }

        if ((bytes[4] | (bytes[5] << 8) | (bytes[6] << 16) | (bytes[7] << 24)) > 0x10000) {
            ADXERR_CallErrFunc1("E0040702:Illigal number of file.(ADXF_GetPtStat)");
            adxf_CloseLdptnwHn();
            return ADXF_STAT_ERROR;
        }

        ptinfo->nentry = bytes[4] | (bytes[5] << 8);
        nfile = ptinfo->nentry;
        ptinfo->nfile = nfile;

        if (rev == 1) {
            ptinfo->size = ((u32)(nfile * 4 + 0x120) >> 2) << 2;
        } else {
            ptinfo->size = ((u32)(nfile * 2 + 0x11C) >> 2) << 2;
        }

        bytes = adxf_ldpt_buf;

        if (rev == 1) {
            *top_rev1 = (bytes[8] | (bytes[9] << 8) | (bytes[10] << 16) | (bytes[11] << 24)) / 2048;
        } else {
            *top_rev0 = (bytes[8] | (bytes[9] << 8) | (bytes[10] << 16) | (bytes[11] << 24)) / 2048;
        }

        i = 3;
    } else {
        i = 1;
    }

    end = (adxf_ldpt_rdsct << 11) / 4;

    for (; i < end; i += 2) {
        bytes = (u8 *)adxf_ldpt_buf + i * 4;

        if (ptinfo->rev == 1) {
            fsizes_rev1[adxf_flno] =
                xb_adxf_SectorCount(bytes[0] | (bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24));
        } else {
            nsct = xb_adxf_SectorCount(bytes[0] | (bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24));

            if (nsct & 0xFFFF0000) {
                ADXERR_CallErrFunc1("E2122501:AFS file has 128MB or more of inside file.(ADXF_GetPtStat)");
                adxf_CloseLdptnwHn();
                return ADXF_STAT_ERROR;
            }

            fsizes_rev0[adxf_flno] = nsct;
        }

        if (++adxf_flno >= ptinfo->nfile) {
            stat = ADXF_STAT_READEND;
            adxf_CloseLdptnwHn();
            break;
        }
    }

    if (i < end) {
        return stat;
    }

    if (ADXF_ReadNw(adxf_ldptnw_hn, adxf_ldpt_rdsct, adxf_ldpt_buf) < 0) {
        stat = ADXF_STAT_ERROR;
        adxf_CloseLdptnwHn();
        return stat;
    }

    return adxf_ldptnw_hn->stat;
}

s32 ADXF_GetPtStat(s32 ptid, void *stat) {
    return ADXF_GetPtStatEx(ptid, stat);
}
