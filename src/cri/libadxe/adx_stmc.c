/* ADXSTM_BindFileNw 0x16DE30. ADXSTM_BindFile 0x16DE70.
 * ADXSTM_Seek 0x16DEA0. ADXSTM_Tell 0x16DEC0.
 * adxstm_start_sub 0x16DEE0.
 * ADXSTM_Start 0x16DF10.
 * ADXSTM_Start2 0x16DF40. ADXSTM_StopNw 0x16DF70.
 * ADXSTM_Stop 0x16DFA0.
 * ADXSTM_SetEos 0x16DFF0.
 * ADXSTM_SetBufSize 0x16E430. ADXSTM_SetReqRdSize 0x16E450.
 * ADXSTM_SetPause 0x16E470. ADXSTM_SetSj 0x16E480.
 *
 * BindFileNw tail-jumps to SVM_Unlock. BindFile waits on sub_00171EF0
 * while unk45 is set. That callee stays unnamed.
 * Both paths of StopNw tail-jump to SVM_Unlock. Stop waits on
 * sub_00171EF0 until stat is 1 and the chunk is empty.
 *
 * A zero file_sct stores stat 3. Any other count stores stat 2.
 * A non-negative eos is stored at +0x30. A negative eos copies file_sct
 * at +0x14 into that same field.
 * SetSj calls SJ_GetNumData with id 1 and then id 0.
 */

#include "types.h"

#include <stddef.h>

typedef struct {
    void *data;
    s32 len;
} SJCK;

typedef struct SJ_OBJ SJ_OBJ;
typedef SJ_OBJ *SJ;

typedef struct {
    void *gap[9];
    s32 (*GetNumData)(SJ sj, s32 id);
} SJ_VTBL;

struct SJ_OBJ {
    SJ_VTBL *vtbl;
};

#define SJ_GetNumData(sj, id) ((sj)->vtbl->GetNumData)(sj, id)

typedef struct {
    u8 gap0;
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
    u8 gap20[4];
    SJCK unk24;
    s32 req_rd_size;
    s32 eos;
    s32 unk34;
    u8 gap38[8];
    s32 unk40;
    s8 pause;
    s8 unk45;
    u8 gap46;
    s8 unk47;
    s8 unk48;
    u8 gap49[7];
    const char *fname;
    void *dir;
    s32 cur_ofst;
    s32 unk5C;
} ADXSTM_OBJ;

typedef ADXSTM_OBJ *ADXSTM;

_Static_assert(offsetof(SJ_VTBL, GetNumData) == 0x24, "GetNumData");
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
_Static_assert(offsetof(ADXSTM_OBJ, unk24) == 0x24, "unk24");
_Static_assert(offsetof(ADXSTM_OBJ, req_rd_size) == 0x2C, "req_rd_size");
_Static_assert(offsetof(ADXSTM_OBJ, eos) == 0x30, "eos");
_Static_assert(offsetof(ADXSTM_OBJ, unk34) == 0x34, "unk34");
_Static_assert(offsetof(ADXSTM_OBJ, unk40) == 0x40, "unk40");
_Static_assert(offsetof(ADXSTM_OBJ, pause) == 0x44, "pause");
_Static_assert(offsetof(ADXSTM_OBJ, unk45) == 0x45, "unk45");
_Static_assert(offsetof(ADXSTM_OBJ, unk47) == 0x47, "unk47");
_Static_assert(offsetof(ADXSTM_OBJ, unk48) == 0x48, "unk48");
_Static_assert(offsetof(ADXSTM_OBJ, fname) == 0x50, "fname");
_Static_assert(offsetof(ADXSTM_OBJ, dir) == 0x54, "dir");
_Static_assert(offsetof(ADXSTM_OBJ, cur_ofst) == 0x58, "cur_ofst");
_Static_assert(offsetof(ADXSTM_OBJ, unk5C) == 0x5C, "unk5C");

s32 ADXSTM_Tell(ADXSTM stm) {
    if (stm->cvfs == 0) {
        return 0;
    }

    return stm->cur_ofst;
}

s32 ADXSTM_Seek(ADXSTM stm, s32 offset) {
    stm->cur_ofst = offset;

    if (stm->file_sct < offset) {
        stm->cur_ofst = stm->file_sct;
    }

    return stm->cur_ofst;
}

extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern void SVM_Lock(void);
extern void SVM_Unlock(void);
extern void sub_00171EF0(void);

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
    ADXCRS_Lock();
    adxstm_start_sub(stm);
    stm->unk5C = 0xFFFFF;
    ADXCRS_Unlock();
    return 1;
}

s32 ADXSTM_Start2(ADXSTM stm, s32 arg1) {
    ADXCRS_Lock();
    adxstm_start_sub(stm);
    stm->unk5C = arg1;
    ADXCRS_Unlock();
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
    ADXCRS_Lock();
    stm->unk40 = SJ_GetNumData(sj, 1) + SJ_GetNumData(sj, 0);
    ADXCRS_Unlock();
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
        sub_00171EF0();
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
        sub_00171EF0();
    } while (stm->stat != 1 || stm->unk24.data != 0);
}
