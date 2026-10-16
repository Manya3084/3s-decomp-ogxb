/* ADXSTM_SetEos 0x16DFF0.
 *
 * A non-negative eos is stored at +0x30. A negative eos copies file_sct
 * at +0x14 into that same field.
 */

#include "types.h"

#include <stddef.h>

typedef struct {
    u8 gap0[0x14];
    s32 file_sct;
    u8 gap18[0x18];
    s32 eos;
} ADXSTM_OBJ;

typedef ADXSTM_OBJ *ADXSTM;

_Static_assert(offsetof(ADXSTM_OBJ, file_sct) == 0x14, "file_sct");
_Static_assert(offsetof(ADXSTM_OBJ, eos) == 0x30, "eos");

void ADXSTM_SetEos(ADXSTM stm, s32 eos) {
    if (eos >= 0) {
        stm->eos = eos;
    } else {
        stm->eos = stm->file_sct;
    }
}
