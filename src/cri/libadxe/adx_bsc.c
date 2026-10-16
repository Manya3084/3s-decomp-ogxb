/* ADXB_GetFormat 0x172C50, ADXB_GetSfreq 0x172C60, ADXB_GetNumChan 0x172C70,
 * ADXB_GetOutBps 0x172C80,
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
 * GetNumChan returns channel_count. It does not test unkE4.
 * Stop does not read unkE4.
 * ExecHndl sends format 0x14 to 0x1738B0. The other format targets
 * stay unnamed: 0 at 0x173290, 0xA at 0x1739D0, 2 at 0x1751C0,
 * 3 at 0x174FF0, 4 at 0x174BA0, and 1 at 0x174450.
 * ADXB_DecodeHeader is 0x173770. The 0x8000 branch calls
 * ADXB_DecodeHeaderAdx at 0x1734E0. encoding_type >= 5 stores format
 * 0xA. Otherwise format is 0. ahxsetextfunc is the pointer at 0x7A60D0.
 * ADX_DecodeInfo, ADX_DecodeInfoExADPCM2, and ADX_DecodeInfoExVer
 * are named in adx_dcd.c.
 * adxb_get_key is 0x172E10 and always returns 0. The default key
 * words are 0x7A60D4, 0x7A60D8, and 0x7A60DC. SKG_GenerateKey is
 * 0x172B00 and stays unnamed. ADXPD_SetExtPrm is 0x173DB0.
 * ADX_DecodeInfoExIdly is 0x170E90.
 * ADXPD_SetCoef is 0x173D30. ADXPD_SetDly is 0x173D50.
 * ADX_DecodeInfoExLoop is 0x170F70. ADX_DecodeInfoAinf is 0x171130.
 * Those callees stay unnamed.
 * The SPSD check at 0x1752C0 calls 0x175100. The WAV check at
 * 0x174420 calls 0x174140. The AIFF check at 0x174E40 calls 0x174F30.
 * The AU check at 0x1746C0 calls 0x1747B0. Those checks compare
 * SPSD, RIFF/WAVE, FORM/AIFF, and .snd or .sd. There is no AC3
 * check. The leftover path calls 0x1738D0.
 */

#include "types.h"

#include <stddef.h>
#include <stdio.h>

typedef struct {
    u8 pad[0x10];
} ADXB_UNKCC;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    void *unk14;
    s32 unk18;
    s32 unk1C;
    u8 gap20[0xC];
} ADXB_UNK48;

typedef struct ADXB_OBJ {
    s16 unk0;
    s16 unk2;
    s32 stat;
    void *adxpd;
    s8 encoding_type;
    s8 sample_bitdepth;
    s8 channel_count;
    s8 block_size;
    s32 samples_per_block;
    s32 sample_rate;
    s32 total_samples;
    s16 unk1C;
    u8 gap1E[2];
    s32 unk20;
    s16 unk24;
    s16 unk26;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    u8 gap38[4];
    void *unk3C;
    s32 unk40;
    s32 unk44;
    ADXB_UNK48 unk48;
    s32 unk74;
    u8 gap78[0x10];
    s32 unk88;
    s32 unk8C;
    s32 dec_num_sample;
    s32 dec_data_len;
    s16 format;
    s16 unk9A;
    s16 unk9C;
    s16 unk9E;
    s16 unkA0;
    u8 gapA2[0xE];
    s32 unkB0;
    u8 gapB4[0x14];
    s32 unkC8;
    ADXB_UNKCC unkCC;
    s16 unkDC;
    s16 unkDE[2];
} ADXB_OBJ;

typedef ADXB_OBJ *ADXB;

#if defined(__i386__)
_Static_assert(offsetof(ADXB_OBJ, stat) == 4, "stat");
_Static_assert(offsetof(ADXB_OBJ, adxpd) == 8, "adxpd");
_Static_assert(offsetof(ADXB_OBJ, encoding_type) == 0x0C, "encoding_type");
_Static_assert(offsetof(ADXB_OBJ, sample_bitdepth) == 0x0D, "sample_bitdepth");
_Static_assert(offsetof(ADXB_OBJ, channel_count) == 0x0E, "channel_count");
_Static_assert(offsetof(ADXB_OBJ, block_size) == 0x0F, "block_size");
_Static_assert(offsetof(ADXB_OBJ, samples_per_block) == 0x10, "samples_per_block");
_Static_assert(offsetof(ADXB_OBJ, sample_rate) == 0x14, "sample_rate");
_Static_assert(offsetof(ADXB_OBJ, total_samples) == 0x18, "total_samples");
_Static_assert(offsetof(ADXB_OBJ, unk1C) == 0x1C, "unk1C");
_Static_assert(offsetof(ADXB_OBJ, unk20) == 0x20, "unk20");
_Static_assert(offsetof(ADXB_OBJ, unk24) == 0x24, "unk24");
_Static_assert(offsetof(ADXB_OBJ, unk26) == 0x26, "unk26");
_Static_assert(offsetof(ADXB_OBJ, unk34) == 0x34, "unk34");
_Static_assert(offsetof(ADXB_OBJ, unk3C) == 0x3C, "unk3C");
_Static_assert(offsetof(ADXB_OBJ, unk40) == 0x40, "unk40");
_Static_assert(offsetof(ADXB_OBJ, unk44) == 0x44, "unk44");
_Static_assert(offsetof(ADXB_OBJ, unk48) == 0x48, "unk48");
_Static_assert(offsetof(ADXB_UNK48, unk4) == 4, "unk48.unk4");
_Static_assert(offsetof(ADXB_UNK48, unk8) == 8, "unk48.unk8");
_Static_assert(offsetof(ADXB_UNK48, unk10) == 0x10, "unk48.unk10");
_Static_assert(offsetof(ADXB_UNK48, unk14) == 0x14, "unk48.unk14");
_Static_assert(offsetof(ADXB_UNK48, unk1C) == 0x1C, "unk48.unk1C");
_Static_assert(offsetof(ADXB_OBJ, unk74) == 0x74, "unk74");
_Static_assert(offsetof(ADXB_OBJ, unk88) == 0x88, "unk88");
_Static_assert(offsetof(ADXB_OBJ, unk8C) == 0x8C, "unk8C");
_Static_assert(offsetof(ADXB_OBJ, unkB0) == 0xB0, "unkB0");
_Static_assert(offsetof(ADXB_OBJ, unkC8) == 0xC8, "unkC8");
_Static_assert(offsetof(ADXB_OBJ, unkCC) == 0xCC, "unkCC");
_Static_assert(offsetof(ADXB_OBJ, unkDC) == 0xDC, "unkDC");
_Static_assert(offsetof(ADXB_OBJ, unkDE) == 0xDE, "unkDE");
_Static_assert(sizeof(ADXB_UNKCC) == 0x10, "unkCC");
_Static_assert(offsetof(ADXB_OBJ, dec_num_sample) == 0x90, "dec_num_sample");
_Static_assert(offsetof(ADXB_OBJ, dec_data_len) == 0x94, "dec_data_len");
_Static_assert(offsetof(ADXB_OBJ, format) == 0x98, "format");
_Static_assert(offsetof(ADXB_OBJ, unk9A) == 0x9A, "unk9A");
_Static_assert(offsetof(ADXB_OBJ, unk9C) == 0x9C, "unk9C");
_Static_assert(offsetof(ADXB_OBJ, unk9E) == 0x9E, "unk9E");
_Static_assert(offsetof(ADXB_OBJ, unkA0) == 0xA0, "unkA0");
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
extern s32 ADX_DecodeInfo(void *header, s32 len, s16 *audio_offset, s8 *encoding_type, s8 *sample_bitdepth,
                          s8 *block_size, s8 *channel_count, s32 *sample_rate, s32 *total_samples,
                          s32 *samples_per_block);
extern s32 ADX_DecodeInfoExVer(void *header, s32 len, s8 *version, s8 *flags);
extern s32 ADX_DecodeInfoExADPCM2(void *header, s32 len, s16 *high_pass);
extern s32 ADX_DecodeInfoExIdly(void *header, s32 len, s16 *dly0, s16 *dly1);
extern s32 ADX_DecodeInfoExLoop(void *header, s32 len, s32 *loop_unk20, s16 *loop_unk24, s16 *loop_unk26,
                                s32 *loop_unk28, s32 *loop_unk2C, s32 *loop_unk30, s32 *loop_unk34);
extern s32 ADX_DecodeInfoAinf(void *header, s32 len, s32 *unk_c8, ADXB_UNKCC *unk_cc, s16 *unk_dc, s16 *unk_de);
extern void SKG_GenerateKey(void *buf, s32 len, s16 *k0, s16 *km, s16 *ka);
extern s16 adxb_def_k0;
extern s16 adxb_def_km;
extern s16 adxb_def_ka;
extern void ADXPD_SetExtPrm(void *adxpd, s16 arg1, s16 arg2, s16 arg3);
extern void ADXPD_SetCoef(void *adxpd, s32 sample_rate, s16 high_pass);
extern void ADXPD_SetDly(void *adxpd, s16 *dly0, s16 *dly1);
extern void ADXERR_CallErrFunc2(const char *msg, const char *detail);
extern void (*ahxsetextfunc)(s32 arg0, s16 *arg1);
extern s32 ADXB_CheckSpsd(void *header);
extern s32 ADXB_DecodeHeaderSpsd(ADXB adxb, void *header, s32 len);
extern s32 ADXB_CheckWav(void *header);
extern s32 ADXB_DecodeHeaderWav(ADXB adxb, void *header, s32 len);
extern s32 ADXB_CheckAiff(void *header);
extern s32 ADXB_DecodeHeaderAiff(ADXB adxb, void *header, s32 len);
extern s32 ADXB_CheckAu(void *header);
extern s32 ADXB_DecodeHeaderAu(ADXB adxb, void *header, s32 len);
extern s32 sub_001738D0(ADXB adxb, void *header, s32 len);

s32 ADXB_GetFormat(ADXB adxb) {
    return adxb->format;
}

s32 ADXB_GetSfreq(ADXB adxb) {
    return adxb->sample_rate;
}

s32 ADXB_GetNumChan(ADXB adxb) {
    return adxb->channel_count;
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

s32 adxb_get_key(ADXB adxb, u8 version, u8 flags, s32 total_samples, s16 *k0, s16 *km, s16 *ka) {
    char text[9];

    if (version >= 4) {
        if (flags >= 0x10) {
            sprintf(text, "%08X", total_samples);
            SKG_GenerateKey(text, 8, k0, km, ka);
        } else if (flags >= 8) {
            if ((adxb->unk9C == 0) && (adxb->unk9E == 0) && (adxb->unkA0 == 0)) {
                adxb->unk9C = adxb_def_k0;
                adxb->unk9E = adxb_def_km;
                adxb->unkA0 = adxb_def_ka;
            }

            *k0 = adxb->unk9C;
            *km = adxb->unk9E;
            *ka = adxb->unkA0;
        } else {
            *k0 = 0;
            *km = 0;
            *ka = 0;
        }
    } else {
        *k0 = 0;
        *km = 0;
        *ka = 0;
    }

    return 0;
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

s32 ADXB_DecodeHeaderAdx(ADXB adxb, void *header, s32 len) {
    s16 sp10[2];
    s16 sp20[2];
    s16 sp30;
    s16 sp32;
    s16 sp34;
    s16 sp36;
    s16 audio_offset;
    s8 version;
    s8 flags;
    s16 sp44;
    s16 sp46;
    s16 sp48;

    adxb->unk2 = 1;

    if (ADX_DecodeInfo(header, len, &audio_offset, &adxb->encoding_type, &adxb->sample_bitdepth, &adxb->block_size,
                       &adxb->channel_count, &adxb->sample_rate, &adxb->total_samples, &adxb->samples_per_block) < 0) {
        return 0;
    }

    if (adxb->encoding_type >= 5) {
        if (adxb->unkB0 == 0) {
            ADXERR_CallErrFunc2("E1060101 ADXB_DecodeHeaderAdx: ", "can't play AHX data by this handle");
            return -1;
        }

        adxb->sample_bitdepth = 8;
        adxb->block_size = (s8)(adxb->channel_count * 0xC0);
        adxb->samples_per_block = 0x60;
        adxb->format = 0xA;
        adxb->unk1C = 0;
        adxb->unk24 = 0;
        adxb->unk26 = 0;
        adxb->unk20 = 0;
        adxb->unk28 = 0;
        adxb->unk2C = 0;
        adxb->unk30 = 0;
        adxb->unk34 = 0;
        adxb->unk88 = 0;

        if (ADX_DecodeInfoExVer(header, len, &version, &flags) < 0) {
            return 0;
        }

        sp30 = 0;

        if (adxb_get_key(adxb, (u8)version, (u8)flags, adxb->total_samples, &sp32, &sp34, &sp36) < 0) {
            return -1;
        }

        if (ahxsetextfunc != 0) {
            ahxsetextfunc(adxb->unkB0, &sp30);
        }
    } else {
        if (ADX_DecodeInfoExVer(header, len, &version, &flags) < 0) {
            return 0;
        }

        if (adxb_get_key(adxb, (u8)version, (u8)flags, adxb->total_samples, &sp44, &sp46, &sp48) < 0) {
            return -1;
        }

        ADXPD_SetExtPrm(adxb->adxpd, sp44, sp46, sp48);

        if (ADX_DecodeInfoExADPCM2(header, len, &adxb->unk1C) < 0) {
            return 0;
        }

        if (ADX_DecodeInfoExIdly(header, len, sp10, sp20) < 0) {
            return 0;
        }

        ADXPD_SetCoef(adxb->adxpd, adxb->sample_rate, adxb->unk1C);
        ADXPD_SetDly(adxb->adxpd, sp10, sp20);
        ADX_DecodeInfoExLoop(header, len, &adxb->unk20, &adxb->unk24, &adxb->unk26, &adxb->unk28, &adxb->unk2C,
                             &adxb->unk30, &adxb->unk34);
        ADX_DecodeInfoAinf(header, len, &adxb->unkC8, &adxb->unkCC, &adxb->unkDC, adxb->unkDE);
        adxb->format = 0;
    }

    adxb->unk48.unk8 = adxb->channel_count;
    adxb->unk48.unkC = adxb->block_size;
    adxb->unk48.unk10 = adxb->samples_per_block;
    adxb->unk48.unk14 = adxb->unk3C;
    adxb->unk48.unk18 = adxb->unk40;
    adxb->unk48.unk1C = adxb->unk44;
    adxb->unk8C = 0;

    return audio_offset;
}

s32 ADXB_DecodeHeader(ADXB adxb, void *header, s32 len) {
    u8 *bytes = header;
    u16 magic;

    magic = (u16)((bytes[0] << 8) | bytes[1]);

    if (magic == 0x8000) {
        return ADXB_DecodeHeaderAdx(adxb, header, len);
    }

    if (ADXB_CheckSpsd(header) != 0) {
        return ADXB_DecodeHeaderSpsd(adxb, header, len);
    }

    if (ADXB_CheckWav(header) != 0) {
        return ADXB_DecodeHeaderWav(adxb, header, len);
    }

    if (ADXB_CheckAiff(header) != 0) {
        return ADXB_DecodeHeaderAiff(adxb, header, len);
    }

    if (ADXB_CheckAu(header) != 0) {
        return ADXB_DecodeHeaderAu(adxb, header, len);
    }

    return sub_001738D0(adxb, header, len);
}
