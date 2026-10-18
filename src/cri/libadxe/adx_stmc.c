/* ADXSTM_Init 0x16DC70. ADXSTMF_SetupHandleMember 0x16DC90.
 * ADXSTMF_CreateCvfsRt 0x16DD30. ADXSTMF_CreateCvfs 0x16DD90.
 * ADXSTM_Create 0x16DDF0.
 * ADXSTMF_ExecHndl 0x16E2B0. ADXSTM_ExecServer 0x16E3F0.
 * ADXSTM_BindFileNw 0x16DE30. ADXSTM_BindFile 0x16DE70.
 * ADXSTM_Seek 0x16DEA0. ADXSTM_Tell 0x16DEC0.
 * adxstm_start_sub 0x16DEE0.
 * ADXSTM_Start 0x16DF10.
 * ADXSTM_Start2 0x16DF40. ADXSTM_StopNw 0x16DF70.
 * ADXSTM_Stop 0x16DFA0.
 * ADXSTM_SetEos 0x16DFF0.
 * adxstm_sj_internal_error 0x16E010. adxstmf_stat_exec 0x16E020.
 * ADXSTM_SetBufSize 0x16E430. ADXSTM_SetReqRdSize 0x16E450.
 * ADXSTM_SetPause 0x16E470. ADXSTM_SetSj 0x16E480.
 * ADXSTM_ReleaseFileNw 0x16E4C0. ADXSTM_ReleaseFile 0x16E4F0.
 * ADXSTM_Destroy 0x16E520.
 *
 * BindFileNw tail-jumps to SVM_Unlock. BindFile waits on ADXT_ExecFsSvr
 * while unk45 is set.
 * Both paths of StopNw tail-jump to SVM_Unlock. Stop waits on
 * ADXT_ExecFsSvr until stat is 1 and the chunk is empty.
 * ReleaseFileNw tail-jumps to SVM_Unlock. ReleaseFile waits on
 * ADXT_ExecFsSvr while unk49 is set.
 * Destroy clears unk0 and then all 0x60 bytes.
 * Init clears 40 objects of 0x60 at 0xCE0EA0 and returns 1.
 * SetupHandleMember calls SJ_GetNumData with id 1 and then id 0,
 * and tail-jumps to ADXCRS_Unlock.
 * CreateCvfsRt is interior for that reason. It scans adxstmf_rtim_num
 * objects from adxstmf_rtim_ofst. CreateCvfs scans adxstmf_nrml_num
 * objects from adxstmf_nrml_ofst. Create uses the realtime range when
 * the offset is below 0x100.
 * ExecHndl calls adxstmf_stat_exec when stat is 2 and unk49 is 1.
 * A zero file_sct stores unk20 and then stat 3.
 * adxstmf_num_rtry at 0x7A6064 is only read. Nothing in .text writes it.
 * adxstm_sj_internal_error increments the counter at 0x7A6068.
 * Its only caller is the null SJ path inside adxstmf_stat_exec.
 * cvFsOpen is 0x16A8F0. ExecHndl calls it with the name, the directory, and 0.
 * ExecServer walks all 40 objects when the test-and-set flag is free.
 *
 * A zero file_sct stores stat 3. Any other count stores stat 2.
 * A non-negative eos is stored at +0x30. A negative eos copies file_sct
 * at +0x14 into that same field.
 * SetSj calls SJ_GetNumData with id 1 and then id 0.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

typedef struct {
    void *data;
    s32 len;
} SJCK;

typedef struct SJ_OBJ SJ_OBJ;
typedef SJ_OBJ *SJ;

typedef struct {
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
} SJ_VTBL;

struct SJ_OBJ {
    SJ_VTBL *vtbl;
};

#define SJ_GetChunk(sj, id, nbyte, ck) ((sj)->vtbl->GetChunk)(sj, id, nbyte, ck)
#define SJ_UngetChunk(sj, id, ck) ((sj)->vtbl->UngetChunk)(sj, id, ck)
#define SJ_PutChunk(sj, id, ck) ((sj)->vtbl->PutChunk)(sj, id, ck)
#define SJ_GetNumData(sj, id) ((sj)->vtbl->GetNumData)(sj, id)

typedef struct {
    s8 unk0;
    s8 stat;
    s8 read_flg;
    s8 unk3;
    SJ sj;
    void *cvfs;
    s32 unkC;
    s32 file_len;
    s32 file_sct;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    SJCK unk24;
    s32 req_rd_size;
    s32 eos;
    u32 unk34;
    void (*eos_callback)(void *);
    void *eos_callback_context;
    s32 unk40;
    s8 pause;
    s8 unk45;
    s8 unk46;
    s8 unk47;
    s8 unk48;
    s8 unk49;
    u8 pad4A[6];
    const char *fname;
    void *dir;
    s32 cur_ofst;
    u32 unk5C;
} ADXSTM_OBJ;

typedef ADXSTM_OBJ *ADXSTM;

_Static_assert(offsetof(SJ_VTBL, GetChunk) == 0x18, "GetChunk");
_Static_assert(offsetof(SJ_VTBL, UngetChunk) == 0x1C, "UngetChunk");
_Static_assert(offsetof(SJ_VTBL, PutChunk) == 0x20, "PutChunk");
_Static_assert(offsetof(SJ_VTBL, GetNumData) == 0x24, "GetNumData");
_Static_assert(offsetof(ADXSTM_OBJ, unk0) == 0, "unk0");
_Static_assert(offsetof(ADXSTM_OBJ, stat) == 1, "stat");
_Static_assert(offsetof(ADXSTM_OBJ, read_flg) == 2, "read_flg");
_Static_assert(offsetof(ADXSTM_OBJ, unk3) == 3, "unk3");
_Static_assert(offsetof(ADXSTM_OBJ, sj) == 4, "sj");
_Static_assert(offsetof(ADXSTM_OBJ, cvfs) == 8, "cvfs");
_Static_assert(offsetof(ADXSTM_OBJ, unkC) == 0xC, "unkC");
_Static_assert(offsetof(ADXSTM_OBJ, file_len) == 0x10, "file_len");
_Static_assert(offsetof(ADXSTM_OBJ, file_sct) == 0x14, "file_sct");
_Static_assert(offsetof(ADXSTM_OBJ, unk18) == 0x18, "unk18");
_Static_assert(offsetof(ADXSTM_OBJ, unk1C) == 0x1C, "unk1C");
_Static_assert(offsetof(ADXSTM_OBJ, unk20) == 0x20, "unk20");
_Static_assert(offsetof(ADXSTM_OBJ, unk24) == 0x24, "unk24");
_Static_assert(offsetof(ADXSTM_OBJ, req_rd_size) == 0x2C, "req_rd_size");
_Static_assert(offsetof(ADXSTM_OBJ, eos) == 0x30, "eos");
_Static_assert(offsetof(ADXSTM_OBJ, unk34) == 0x34, "unk34");
_Static_assert(offsetof(ADXSTM_OBJ, eos_callback) == 0x38, "eos_callback");
_Static_assert(offsetof(ADXSTM_OBJ, eos_callback_context) == 0x3C, "eos_callback_context");
_Static_assert(offsetof(ADXSTM_OBJ, unk40) == 0x40, "unk40");
_Static_assert(offsetof(ADXSTM_OBJ, pause) == 0x44, "pause");
_Static_assert(offsetof(ADXSTM_OBJ, unk45) == 0x45, "unk45");
_Static_assert(offsetof(ADXSTM_OBJ, unk46) == 0x46, "unk46");
_Static_assert(offsetof(ADXSTM_OBJ, unk47) == 0x47, "unk47");
_Static_assert(offsetof(ADXSTM_OBJ, unk48) == 0x48, "unk48");
_Static_assert(offsetof(ADXSTM_OBJ, unk49) == 0x49, "unk49");
_Static_assert(offsetof(ADXSTM_OBJ, fname) == 0x50, "fname");
_Static_assert(offsetof(ADXSTM_OBJ, dir) == 0x54, "dir");
_Static_assert(offsetof(ADXSTM_OBJ, cur_ofst) == 0x58, "cur_ofst");
_Static_assert(offsetof(ADXSTM_OBJ, unk5C) == 0x5C, "unk5C");
_Static_assert(sizeof(ADXSTM_OBJ) == 0x60, "ADXSTM_OBJ");

#define ADXSTMF_MAX_OBJ 40

extern ADXSTM_OBJ adxstmf_obj[ADXSTMF_MAX_OBJ]; /* 0xCE0EA0 */
extern s32 adxstmf_rtim_num; /* 0x43CA4C */
extern s32 adxstmf_rtim_ofst; /* 0x7A605C */
extern s32 adxstmf_nrml_ofst; /* 0x43CA50 */
extern s32 adxstmf_nrml_num; /* 0x43CA54 */
extern s32 adxstmf_execsvr_flg; /* 0x7A6060 */
extern s32 adxstmf_num_rtry; /* 0x7A6064 */
extern s32 adxstm_sj_internal_error_cnt; /* 0x7A6068 */

_Static_assert(sizeof(adxstmf_obj) == 0xF00, "adxstmf_obj");

s32 ADXSTM_Tell(ADXSTM stm) {
    if (stm->cvfs != 0) {
        return stm->cur_ofst;
    }

    return 0;
}

s32 ADXSTM_Seek(ADXSTM stm, s32 offset) {
    stm->cur_ofst = offset;

    if (offset > stm->file_sct) {
        stm->cur_ofst = stm->file_sct;
    }

    return stm->cur_ofst;
}

extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
extern void SVM_Lock(void);
extern void SVM_Unlock(void);
extern void ADXT_ExecFsSvr(void);
extern void cvFsClose(void *handle);
extern s32 cvFsTell(void *handle);
extern s32 cvFsSeek(void *handle, s32 offset, s32 whence);
extern s32 cvFsReqRd(void *handle, s32 len, void *buf);
extern s32 cvFsGetStat(void *handle);
extern void *cvFsOpen(const char *fname, void *dir, s32 mode);
extern void ADXERR_CallErrFunc2(const char *msg, const char *detail);
extern void SJ_SplitChunk(SJCK *ck, s32 nbyte, SJCK *ck1, SJCK *ck2);
extern s32 SVM_TestAndSet(s32 *mem);

void adxstm_start_sub(ADXSTM stm) {
    stm->unk34 = 0;
    stm->unk3 = 0;

    if (stm->file_sct == 0) {
        stm->stat = 3;
    } else {
        stm->stat = 2;
    }

    stm->read_flg = 0;
    stm->unk24.data = 0;
    stm->unk24.len = 0;
    stm->unk47 = 1;
}

s32 ADXSTM_Start(ADXSTM stm) {
    sub_0016AA60();
    adxstm_start_sub(stm);
    stm->unk5C = 0xFFFFF;
    sub_0016AA70();
    return 1;
}

s32 ADXSTM_Start2(ADXSTM stm, s32 arg1) {
    sub_0016AA60();
    adxstm_start_sub(stm);
    stm->unk5C = arg1;
    sub_0016AA70();
    return 1;
}

s32 ADXSTM_SetBufSize(ADXSTM stm, s32 arg1, s32 arg2) {
    stm->unk1C = arg1;
    stm->unk18 = arg2;
    return 1;
}

s32 ADXSTM_SetReqRdSize(ADXSTM stm, s32 size) {
    stm->req_rd_size = size;
    return 1;
}

void ADXSTM_SetPause(ADXSTM stm, s8 sw) {
    stm->pause = sw;
}

void ADXSTM_SetSj(ADXSTM stm, SJ sj) {
    stm->sj = sj;
    sub_0016AA60();
    stm->unk40 = SJ_GetNumData(sj, 1) + SJ_GetNumData(sj, 0);
    sub_0016AA70();
    stm->unk18 = stm->unk40;
    stm->unk1C = stm->unk40;
}

void ADXSTM_SetEos(ADXSTM stm, s32 eos) {
    if (eos >= 0) {
        stm->eos = eos;
    } else {
        stm->eos = stm->file_sct;
    }
}

void ADXSTM_BindFileNw(ADXSTM stm, const char *fname, void *dir, s32 arg3, s32 file_sct) {
    SVM_Lock();
    stm->unkC = arg3;
    stm->file_len = file_sct << 11;
    stm->file_sct = file_sct;
    stm->fname = fname;
    stm->dir = dir;
    stm->unk45 = 1;
    SVM_Unlock();
}

void ADXSTM_BindFile(ADXSTM stm, const char *fname, void *dir, s32 arg3, s32 file_sct) {
    ADXSTM_BindFileNw(stm, fname, dir, arg3, file_sct);

    do {
        ADXT_ExecFsSvr();
    } while (stm->unk45 != 0);
}

void ADXSTM_StopNw(ADXSTM stm) {
    SVM_Lock();

    if (stm->stat == 2 && stm->read_flg == 1) {
        stm->unk48 = 1;

        if (stm->unk47 == 1) {
            stm->unk47 = 0;
        }
    } else {
        stm->stat = 1;
    }

    SVM_Unlock();
}

void ADXSTM_Stop(ADXSTM stm) {
    ADXSTM_StopNw(stm);

    do {
        ADXT_ExecFsSvr();
    } while (stm->stat != 1 || stm->unk24.data != 0);
}

void ADXSTM_ReleaseFileNw(ADXSTM stm) {
    ADXSTM_StopNw(stm);
    SVM_Lock();

    if (stm->unk49 == 1) {
        stm->unk46 = 1;
    }

    stm->unk45 = 0;
    SVM_Unlock();
}

void ADXSTM_ReleaseFile(ADXSTM stm) {
    ADXSTM_Stop(stm);
    ADXSTM_ReleaseFileNw(stm);

    while (stm->unk49 != 0) {
        ADXT_ExecFsSvr();
    }
}

void ADXSTM_Destroy(ADXSTM stm) {
    if (stm != 0) {
        ADXSTM_Stop(stm);
        ADXSTM_ReleaseFile(stm);
        stm->unk0 = 0;
        memset(stm, 0, sizeof(ADXSTM_OBJ));
    }
}

s32 ADXSTM_Init(void) {
    memset(adxstmf_obj, 0, sizeof(adxstmf_obj));
    return 1;
}

void ADXSTMF_SetupHandleMember(ADXSTM stm, s32 offset, s32 arg2, s32 file_len, SJ sj) {
    s32 file_sct;

    sub_0016AA60();
    file_sct = file_len / 2048;

    if (file_len - file_sct * 2048 > 0) {
        file_sct += 1;
    }

    stm->stat = 1;
    stm->read_flg = 0;
    stm->sj = sj;
    stm->cvfs = (void *)offset;
    stm->unkC = arg2;
    stm->req_rd_size = 0x200;
    stm->unk5C = 0xFFFFF;
    stm->file_sct = file_sct;
    stm->eos = file_sct;
    stm->cur_ofst = 0;
    stm->file_len = file_len;

    if (sj != 0) {
        stm->unk40 = SJ_GetNumData(sj, 1) + SJ_GetNumData(sj, 0);
        stm->unk18 = stm->unk40;
        stm->unk1C = stm->unk40;
    }

    stm->unk0 = 1;
    stm->pause = 0;
    sub_0016AA70();
}

ADXSTM ADXSTMF_CreateCvfsRt(s32 arg0, s32 offset, s32 file_len, SJ sj) {
    ADXSTM stm;
    s32 i;

    stm = 0;

    for (i = 0; i < adxstmf_rtim_num; i++) {
        stm = &adxstmf_obj[adxstmf_rtim_ofst + i];

        if (stm->unk0 == 0) {
            break;
        }
    }

    if (i == adxstmf_rtim_num) {
        return 0;
    }

    ADXSTMF_SetupHandleMember(stm, arg0, offset, file_len, sj);
    return stm;
}

ADXSTM ADXSTMF_CreateCvfs(s32 arg0, s32 offset, s32 file_len, SJ sj) {
    ADXSTM stm;
    s32 i;

    stm = 0;

    for (i = 0; i < adxstmf_nrml_num; i++) {
        stm = &adxstmf_obj[adxstmf_nrml_ofst + i];

        if (stm->unk0 == 0) {
            break;
        }
    }

    if (i == adxstmf_nrml_num) {
        return 0;
    }

    ADXSTMF_SetupHandleMember(stm, arg0, offset, file_len, sj);
    return stm;
}

ADXSTM ADXSTM_Create(SJ sj, s32 offset) {
    ADXSTM stm;

    if (offset < 0x100) {
        stm = ADXSTMF_CreateCvfsRt(0, 0, 0, sj);
    } else {
        stm = ADXSTMF_CreateCvfs(0, 0, 0, sj);
    }

    return stm;
}

void adxstm_sj_internal_error(void) {
    adxstm_sj_internal_error_cnt += 1;
}

void adxstmf_stat_exec(ADXSTM stm) {
    SJCK chunk_0;
    SJCK chunk_1;
    SJ sj;
    s32 len;
    s32 cvfs_stat;
    s32 nbyte;
    s32 stream_len;

    sj = stm->sj;
    cvfs_stat = cvFsGetStat(stm->cvfs);
    SVM_Lock();

    if (stm->read_flg == 1) {
        if (cvfs_stat == 1) {
            stm->read_flg = 0;
            SVM_Unlock();
            nbyte = stm->unk20 << 11;
            SJ_SplitChunk(&stm->unk24, nbyte, &chunk_0, &chunk_1);
            SJ_PutChunk(sj, 1, &chunk_0);
            SJ_UngetChunk(sj, 0, &chunk_1);
            stm->cur_ofst += stm->unk20;
            stm->unk34 += nbyte;
            stm->unk24.len = 0;
            stm->unk24.data = 0;
            stream_len = stm->file_sct;

            if (stm->cur_ofst == stm->eos) {
                if (stm->eos_callback != 0) {
                    stm->eos_callback(stm->eos_callback_context);
                }
            }

            if ((stm->cur_ofst >= stream_len) ||
                (((stm->unk34 >> 11) >= stm->unk5C) && (stm->unk5C <= 0xFFFFEu))) {
                stm->stat = 3;
            }

            stm->unk3 = 0;
            return;
        } else if (cvfs_stat == 3) {
            stm->read_flg = 0;
            SVM_Unlock();
            SJ_UngetChunk(sj, 0, &stm->unk24);
            stm->unk24.data = 0;
            stm->unk24.len = 0;
        } else {
            SVM_Unlock();
            return;
        }
    } else {
        stm->read_flg = 1;
        stm->unk24.data = 0;
        stm->unk24.len = 0;
        SVM_Unlock();

        if (stm->pause == 1) {
            stm->read_flg = 0;
            return;
        }

        if (stm->unk48 == 1) {
            stm->read_flg = 0;
            return;
        }

        if (stm->file_sct == 0) {
            stm->unk20 = 0;
            stm->stat = 3;
            stm->read_flg = 0;
            return;
        }

        if ((sj == 0) || (sj->vtbl == 0)) {
            stm->read_flg = 0;
            adxstm_sj_internal_error();
            return;
        }

        if ((stm->unk40 - SJ_GetNumData(sj, 0)) >= stm->unk1C) {
            stm->read_flg = 0;
            return;
        }

        SJ_GetChunk(sj, 0, stm->unk18, &chunk_1);
        len = chunk_1.len / 2048;

        if (len > (stm->eos - stm->cur_ofst)) {
            len = stm->eos - stm->cur_ofst;
        }

        if (len > (stm->file_sct - stm->cur_ofst)) {
            len = stm->file_sct - stm->cur_ofst;
        }

        if (len > stm->req_rd_size) {
            len = stm->req_rd_size;
        }

        cvFsSeek(stm->cvfs, stm->unkC + stm->cur_ofst, 0);
        stm->unk20 = cvFsReqRd(stm->cvfs, len, chunk_1.data);
        stm->unk24.data = chunk_1.data;
        stm->unk24.len = chunk_1.len;

        if (stm->unk20 > 0) {
            return;
        }

        SJ_UngetChunk(sj, 0, &stm->unk24);
        stm->unk24.data = 0;
        stm->unk24.len = 0;
        stm->read_flg = 0;

        if (cvFsGetStat(stm->cvfs) != 3) {
            return;
        }
    }

    if (adxstmf_num_rtry >= 0) {
        if (stm->unk3 >= adxstmf_num_rtry) {
            stm->stat = 4;
        } else {
            stm->unk3 += 1;
        }
    }
}

void ADXSTMF_ExecHndl(ADXSTM stm) {
    void *cvfs;
    s32 cur_pos;

    if (stm->read_flg == 0) {
        if (stm->unk48 == 1) {
            stm->unk48 = 0;

            if (stm->unk47 == 0) {
                stm->stat = 1;
            }
        }

        if (stm->unk46 == 1) {
            cvfs = stm->cvfs;

            if (cvfs != 0) {
                stm->cvfs = 0;
                cvFsClose(cvfs);
            }

            stm->unk46 = 0;
            stm->unk49 = 0;
        }

        SVM_Lock();

        if (stm->unk45 == 1) {
            stm->unk49 = 1;
            SVM_Unlock();

            if (stm->cvfs == 0) {
                stm->cvfs = cvFsOpen(stm->fname, stm->dir, 0);

                if (stm->cvfs == 0) {
                    ADXERR_CallErrFunc2("E02110501 adxstmf_stat_exec: can't open ", stm->fname);
                    stm->stat = 4;
                    stm->unk49 = 0;
                    stm->unk45 = 0;
                    return;
                }

                cvFsSeek(stm->cvfs, 0, 2);
                cur_pos = cvFsTell(stm->cvfs);
                cvFsSeek(stm->cvfs, 0, 0);

                if (stm->file_len == 0x7FFFF800) {
                    stm->file_sct = cur_pos;
                    stm->file_len = stm->file_sct << 11;
                } else {
                    if (stm->unkC > cur_pos) {
                        stm->unkC = cur_pos;
                    }

                    if ((stm->file_sct + stm->unkC) > cur_pos) {
                        stm->file_sct = cur_pos - stm->unkC;
                        stm->file_len = stm->file_sct << 11;
                    }
                }

                ADXSTM_Seek(stm, 0);
                stm->unk45 = 0;
            }
        } else {
            SVM_Unlock();
        }

        if (stm->unk47 == 1) {
            stm->unk47 = 0;
        }
    }

    if ((stm->stat == 2) && (stm->unk49 == 1)) {
        adxstmf_stat_exec(stm);
    }
}

void ADXSTM_ExecServer(void) {
    ADXSTM stm;
    s32 i;

    if (SVM_TestAndSet(&adxstmf_execsvr_flg) == 0) {
        return;
    }

    for (i = 0; i < ADXSTMF_MAX_OBJ; i++) {
        stm = &adxstmf_obj[i];

        if (stm->unk0 == 1) {
            ADXSTMF_ExecHndl(stm);
        }
    }

    adxstmf_execsvr_flg = 0;
}
