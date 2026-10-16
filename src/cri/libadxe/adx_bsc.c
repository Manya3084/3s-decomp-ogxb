/* ADXB_GetStat 0x172EE0, ADXB_Start 0x172F60, ADXB_Reset 0x172FA0,
 * ADXB_GetDecDtLen 0x172FD0, ADXB_GetDecNumSmpl 0x172FE0.
 *
 * stat is the s32 at +4. adxpd is +8. unk8C is +0x8C.
 * dec_num_sample is +0x90. dec_data_len is +0x94.
 * ADXPD_Reset is 0x173EF0 and stays unnamed.
 */

#include "types.h"

#include <stddef.h>

typedef struct ADXB_OBJ {
    s16 unk0;
    s16 unk2;
    s32 stat;
    void *adxpd;
    u8 gap0C[0x80];
    s32 unk8C;
    s32 dec_num_sample;
    s32 dec_data_len;
} ADXB_OBJ;

typedef ADXB_OBJ *ADXB;

#if defined(__i386__)
_Static_assert(offsetof(ADXB_OBJ, stat) == 4, "stat");
_Static_assert(offsetof(ADXB_OBJ, adxpd) == 8, "adxpd");
_Static_assert(offsetof(ADXB_OBJ, unk8C) == 0x8C, "unk8C");
_Static_assert(offsetof(ADXB_OBJ, dec_num_sample) == 0x90, "dec_num_sample");
_Static_assert(offsetof(ADXB_OBJ, dec_data_len) == 0x94, "dec_data_len");
#endif

extern void ADXPD_Reset(void *adxpd);

s32 ADXB_GetStat(ADXB adxb) {
    return adxb->stat;
}

void ADXB_Start(ADXB adxb) {
    if (adxb->stat == 0) {
        adxb->stat = 1;
    }
}

void ADXB_Reset(ADXB adxb) {
    if (adxb->stat == 3) {
        ADXPD_Reset(adxb->adxpd);
        adxb->unk8C = 0;
        adxb->stat = 0;
    }
}

s32 ADXB_GetDecDtLen(ADXB adxb) {
    return adxb->dec_data_len;
}

s32 ADXB_GetDecNumSmpl(ADXB adxb) {
    return adxb->dec_num_sample;
}
