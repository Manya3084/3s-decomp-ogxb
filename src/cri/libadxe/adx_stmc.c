/* adxstm_start_sub 0x16DEE0. ADXSTM_Start 0x16DF10.
 * ADXSTM_SetEos 0x16DFF0.
 *
 * A zero file_sct stores stat 3. Any other count stores stat 2.
 * A non-negative eos is stored at +0x30. A negative eos copies file_sct
 * at +0x14 into that same field.
 */

#include "types.h"

#include <stddef.h>

typedef struct {
    void *data;
    s32 len;
} SJCK;

typedef struct {
    u8 gap0;
    s8 stat;
    s8 read_flg;
    s8 unk3;
    u8 gap4[0x10];
    s32 file_sct;
    u8 gap18[0xC];
    SJCK unk24;
    u8 gap2C[4];
    s32 eos;
    s32 unk34;
    u8 gap38[0xF];
    s8 unk47;
    u8 gap48[0x14];
    s32 unk5C;
} ADXSTM_OBJ;

typedef ADXSTM_OBJ *ADXSTM;

_Static_assert(offsetof(ADXSTM_OBJ, stat) == 1, "stat");
_Static_assert(offsetof(ADXSTM_OBJ, read_flg) == 2, "read_flg");
_Static_assert(offsetof(ADXSTM_OBJ, unk3) == 3, "unk3");
_Static_assert(offsetof(ADXSTM_OBJ, file_sct) == 0x14, "file_sct");
_Static_assert(offsetof(ADXSTM_OBJ, unk24) == 0x24, "unk24");
_Static_assert(offsetof(ADXSTM_OBJ, eos) == 0x30, "eos");
_Static_assert(offsetof(ADXSTM_OBJ, unk34) == 0x34, "unk34");
_Static_assert(offsetof(ADXSTM_OBJ, unk47) == 0x47, "unk47");
_Static_assert(offsetof(ADXSTM_OBJ, unk5C) == 0x5C, "unk5C");

extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);

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

void ADXSTM_SetEos(ADXSTM stm, s32 eos) {
    if (eos >= 0) {
        stm->eos = eos;
    } else {
        stm->eos = stm->file_sct;
    }
}
