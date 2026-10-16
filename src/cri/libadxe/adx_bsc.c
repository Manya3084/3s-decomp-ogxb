/* ADXB_GetFormat 0x172C50, ADXB_GetSfreq 0x172C60, ADXB_GetOutBps 0x172C80,
 * ADXB_GetBlkSmpl 0x172CE0, ADXB_GetTotalNumSmpl 0x172CF0,
 * ADXB_GetNumLoop 0x172D00, ADXB_GetStat 0x172EE0, ADXB_EntryData 0x172EF0,
 * ADXB_Start 0x172F60,
 * ADXB_Stop 0x172F80, ADXB_Reset 0x172FA0, ADXB_GetDecDtLen 0x172FD0,
 * ADXB_GetDecNumSmpl 0x172FE0, ADXB_ExecHndl 0x173330.
 *
 * stat is the s32 at +4. adxpd is +8. sample_bitdepth is +0x0D,
 * channel_count is +0x0E, and block_size is +0x0F. samples_per_block
 * is +0x10, sample_rate is +0x14, and total_samples is +0x18.
 * unk24 is the word at +0x24. unk48 is +0x48. unk74 is +0x74.
 * unk8C is +0x8C. dec_num_sample is +0x90. dec_data_len is +0x94.
 * format is the word at +0x98. unk9A is the word at +0x9A.
 * ADXPD_Stop is 0x173ED0 and ADXPD_Reset is 0x173EF0. Both stay unnamed.
 * Stop does not read unkE4.
 * ExecHndl sends format 0x14 to 0x1738B0. The other format targets
 * stay unnamed: 0 at 0x173290, 0xA at 0x1739D0, 2 at 0x1751C0,
 * 3 at 0x174FF0, 4 at 0x174BA0, and 1 at 0x174450.
 */

#include "types.h"

#include <stddef.h>

typedef struct {
    s32 unk0;
    s32 unk4;
} ADXB_UNK48;

typedef struct ADXB_OBJ {
    s16 unk0;
    s16 unk2;
    s32 stat;
    void *adxpd;
    u8 gap0C[1];
    s8 sample_bitdepth;
    s8 channel_count;
    s8 block_size;
    s32 samples_per_block;
    s32 sample_rate;
    s32 total_samples;
    u8 gap1C[8];
    s16 unk24;
    u8 gap26[0x22];
    ADXB_UNK48 unk48;
    u8 gap50[0x24];
    s32 unk74;
    u8 gap78[0x14];
    s32 unk8C;
    s32 dec_num_sample;
    s32 dec_data_len;
    s16 format;
    s16 unk9A;
} ADXB_OBJ;

typedef ADXB_OBJ *ADXB;

#if defined(__i386__)
_Static_assert(offsetof(ADXB_OBJ, stat) == 4, "stat");
_Static_assert(offsetof(ADXB_OBJ, adxpd) == 8, "adxpd");
_Static_assert(offsetof(ADXB_OBJ, sample_bitdepth) == 0x0D, "sample_bitdepth");
_Static_assert(offsetof(ADXB_OBJ, channel_count) == 0x0E, "channel_count");
_Static_assert(offsetof(ADXB_OBJ, block_size) == 0x0F, "block_size");
_Static_assert(offsetof(ADXB_OBJ, samples_per_block) == 0x10, "samples_per_block");
_Static_assert(offsetof(ADXB_OBJ, sample_rate) == 0x14, "sample_rate");
_Static_assert(offsetof(ADXB_OBJ, total_samples) == 0x18, "total_samples");
_Static_assert(offsetof(ADXB_OBJ, unk24) == 0x24, "unk24");
_Static_assert(offsetof(ADXB_OBJ, unk48) == 0x48, "unk48");
_Static_assert(offsetof(ADXB_UNK48, unk4) == 4, "unk48.unk4");
_Static_assert(offsetof(ADXB_OBJ, unk74) == 0x74, "unk74");
_Static_assert(offsetof(ADXB_OBJ, unk8C) == 0x8C, "unk8C");
_Static_assert(offsetof(ADXB_OBJ, dec_num_sample) == 0x90, "dec_num_sample");
_Static_assert(offsetof(ADXB_OBJ, dec_data_len) == 0x94, "dec_data_len");
_Static_assert(offsetof(ADXB_OBJ, format) == 0x98, "format");
_Static_assert(offsetof(ADXB_OBJ, unk9A) == 0x9A, "unk9A");
#endif

extern void ADXPD_Stop(void *adxpd);
extern void ADXPD_Reset(void *adxpd);
extern void ADXB_ExecOneAdx(ADXB adxb);
extern void ADXB_ExecOneAhx(ADXB adxb);
extern void ADXB_ExecOneSpsd(ADXB adxb);
extern void ADXB_ExecOneAiff(ADXB adxb);
extern void ADXB_ExecOneAu(ADXB adxb);
extern void ADXB_ExecOneWav(ADXB adxb);
extern void sub_001738B0(ADXB adxb);

s32 ADXB_GetFormat(ADXB adxb) {
    return adxb->format;
}

s32 ADXB_GetSfreq(ADXB adxb) {
    return adxb->sample_rate;
}

s32 ADXB_GetOutBps(ADXB adxb) {
    s16 format;
    s16 kind;

    format = adxb->format;

    if (format == 0) {
        return 16;
    }

    if (format == 2) {
        kind = adxb->unk9A;

        if (kind == 2) {
            return 4;
        }

        return (kind == 1) ? 8 : 16;
    }

    if (format == 1) {
        kind = adxb->unk9A;
        return (kind == 2) ? 4 : 16;
    }

    return 16;
}

s32 ADXB_GetBlkSmpl(ADXB adxb) {
    return adxb->samples_per_block;
}

s32 ADXB_GetTotalNumSmpl(ADXB adxb) {
    return adxb->total_samples;
}

s32 ADXB_GetNumLoop(ADXB adxb) {
    return adxb->unk24;
}

s32 ADXB_GetStat(ADXB adxb) {
    return adxb->stat;
}

void ADXB_EntryData(ADXB adxb, s32 arg1, s32 arg2) {
    adxb->unk74 = 0;
    adxb->dec_num_sample = 0;
    adxb->dec_data_len = 0;

    if (adxb->format == 0) {
        adxb->unk48.unk0 = arg1;
        adxb->unk48.unk4 = arg2 / adxb->block_size;
    } else {
        adxb->unk48.unk0 = arg1;
        adxb->unk48.unk4 = arg2 / ((adxb->sample_bitdepth / 8) * adxb->channel_count);
    }
}

void ADXB_Start(ADXB adxb) {
    if (adxb->stat == 0) {
        adxb->stat = 1;
    }
}

void ADXB_Stop(ADXB adxb) {
    ADXPD_Stop(adxb->adxpd);
    adxb->stat = 0;
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

void ADXB_ExecHndl(ADXB adxb) {
    if (adxb->format == 0) {
        ADXB_ExecOneAdx(adxb);
    } else if (adxb->format == 0xA) {
        ADXB_ExecOneAhx(adxb);
    } else if (adxb->format == 2) {
        ADXB_ExecOneSpsd(adxb);
    } else if (adxb->format == 3) {
        ADXB_ExecOneAiff(adxb);
    } else if (adxb->format == 4) {
        ADXB_ExecOneAu(adxb);
    } else if (adxb->format == 1) {
        ADXB_ExecOneWav(adxb);
    } else if (adxb->format == 0x14) {
        sub_001738B0(adxb);
    }
}
