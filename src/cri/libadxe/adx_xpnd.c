/* ADXPD_SetCoef 0x173D30. ADXPD_SetDly 0x173D50.
 * ADXPD_GetDly 0x173D80. ADXPD_SetExtPrm 0x173DB0.
 * ADXPD_GetExtPrm 0x173DD0. ADXPD_Destroy 0x173E00.
 * ADXPD_GetStat 0x173E20. ADXPD_EntryMono 0x173E30.
 * ADXPD_EntrySte 0x173E70. ADXPD_Start 0x173EB0.
 *
 * ADXPD_Start follows ADXPD_EntrySte. There is no separate EntryPl2.
 *
 * The high-pass argument is a value. 0x170C60 receives that value, the
 * sample rate, and the words at +0x30 and +0x32.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} ADXPD_OBJ_SUB;

typedef struct {
    s32 used;
    s32 unk4;
    s32 mode;
    s32 stat;
    s32 num_blk;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    ADXPD_OBJ_SUB unk28;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
    s16 unk38;
    s16 unk3A;
} ADXPD_OBJ;

typedef ADXPD_OBJ *ADXPD;

#if defined(__i386__)
_Static_assert(offsetof(ADXPD_OBJ, stat) == 0xC, "stat");
_Static_assert(offsetof(ADXPD_OBJ, num_blk) == 0x10, "num_blk");
_Static_assert(offsetof(ADXPD_OBJ, unk14) == 0x14, "unk14");
_Static_assert(offsetof(ADXPD_OBJ, unk18) == 0x18, "unk18");
_Static_assert(offsetof(ADXPD_OBJ, unk28) == 0x28, "unk28");
_Static_assert(offsetof(ADXPD_OBJ_SUB, unk2) == 2, "unk28.unk2");
_Static_assert(offsetof(ADXPD_OBJ_SUB, unk4) == 4, "unk28.unk4");
_Static_assert(offsetof(ADXPD_OBJ_SUB, unk6) == 6, "unk28.unk6");
_Static_assert(offsetof(ADXPD_OBJ, unk30) == 0x30, "unk30");
_Static_assert(offsetof(ADXPD_OBJ, unk32) == 0x32, "unk32");
_Static_assert(offsetof(ADXPD_OBJ, unk34) == 0x34, "unk34");
_Static_assert(offsetof(ADXPD_OBJ, unk36) == 0x36, "unk36");
_Static_assert(offsetof(ADXPD_OBJ, unk38) == 0x38, "unk38");
_Static_assert(sizeof(ADXPD_OBJ_SUB) == 8, "unk28");
_Static_assert(sizeof(ADXPD_OBJ) == 0x3C, "ADXPD_OBJ");
#endif

extern void ADX_GetCoefficient(s32 high_pass, s32 sample_rate, s16 *coef1, s16 *coef2);

void ADXPD_SetCoef(ADXPD adxpd, s32 sample_rate, s16 high_pass) {
    ADX_GetCoefficient(high_pass, sample_rate, &adxpd->unk30, &adxpd->unk32);
}

void ADXPD_SetDly(ADXPD adxpd, s16 *arg1, s16 *arg2) {
    adxpd->unk28.unk0 = arg1[0];
    adxpd->unk28.unk2 = arg2[0];
    adxpd->unk28.unk4 = arg1[1];
    adxpd->unk28.unk6 = arg2[1];
}

void ADXPD_GetDly(ADXPD adxpd, s16 *arg1, s16 *arg2) {
    arg1[0] = adxpd->unk28.unk0;
    arg2[0] = adxpd->unk28.unk2;
    arg1[1] = adxpd->unk28.unk4;
    arg2[1] = adxpd->unk28.unk6;
}

void ADXPD_SetExtPrm(ADXPD adxpd, s16 arg1, s16 arg2, s16 arg3) {
    adxpd->unk34 = arg1;
    adxpd->unk36 = arg2;
    adxpd->unk38 = arg3;
}

void ADXPD_GetExtPrm(ADXPD adxpd, u16 *arg1, u16 *arg2, u16 *arg3) {
    *arg1 = (u16)adxpd->unk34;
    *arg2 = (u16)adxpd->unk36;
    *arg3 = (u16)adxpd->unk38;
}

void ADXPD_Destroy(ADXPD adxpd) {
    if (adxpd != NULL) {
        adxpd->used = 0;
        memset(adxpd, 0, sizeof(*adxpd));
    }
}

s32 ADXPD_GetStat(ADXPD adxpd) {
    return adxpd->stat;
}

s32 ADXPD_EntryMono(ADXPD adxpd, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (adxpd->stat == 0) {
        adxpd->unk18 = arg1;
        adxpd->unk1C = arg2;
        adxpd->unk14 = 1;
        adxpd->unk20 = arg3;
        adxpd->unk24 = arg4;
        return 1;
    }

    return 0;
}

s32 ADXPD_EntrySte(ADXPD adxpd, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (adxpd->stat == 0) {
        adxpd->unk18 = arg1;
        adxpd->unk1C = arg2;
        adxpd->unk14 = 2;
        adxpd->unk20 = arg3;
        adxpd->unk24 = arg4;
        return 1;
    }

    return 0;
}

void ADXPD_Start(ADXPD adxpd) {
    if (adxpd->stat == 0) {
        adxpd->num_blk = 0;
        adxpd->stat = 1;
    }
}
