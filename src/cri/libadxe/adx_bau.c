/* adx_bau.c: the Sun AU path of the ADX decoder. ADXB_CheckAu 0x1746C0 and
 * ADXB_ExecOneAu 0x174BA0 (the 8- and 16-bit bodies are folded with the
 * AIFF ones at 0x174990 and 0x174870). */

#include "types.h"

#include <string.h>

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
    s32 unk20;
    s32 unk24;
    s32 unk28;
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
    s32 unk38;
    void *unk3C;
    s32 unk40;
    s32 unk44;
    ADXB_UNK48 unk48;
    s32 unk74;
    void *(*get_wr)(void *object, s32 *arg1, s32 *arg2, s32 *arg3);
    void *object;
    void (*add_wr)(s32 arg0, s32 len, s32 samples);
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 dec_num_sample;
    s32 dec_data_len;
    s16 format;
    s16 unk9A;
    s16 unk9C;
    s16 unk9E;
    s16 unkA0;
    s16 unkA2;
    s16 unkA4;
    s16 unkA6;
    s16 unkA8[2];
    s16 unkAC[2];
    s32 unkB0;
    s32 ahx_dec_samples;
    s32 ahx_dec_frames;
    s32 unkBC;
    s32 ac3_dec_samples;
    s32 ac3_dec_frames;
    s32 unkC8;
    ADXB_UNKCC unkCC;
    s16 unkDC;
    s16 unkDE[2];
} ADXB_OBJ;

typedef ADXB_OBJ *ADXB;

extern void ADXB_ExecOneAuUlaw(void *adxb);
extern void ADXB_ExecOneAu8(void *adxb);
extern void ADXB_ExecOneAu16(void *adxb);

s32 ADXB_CheckAu(u8 *hdr) {
    if (memcmp(hdr, ".snd", 4) == 0 || memcmp(hdr, ".sd", 4) == 0) {
        return 1;
    }

    return 0;
}

void ADXB_ExecOneAu(void *adxb) {
    s16 fmt = *(s16 *)((u8 *)adxb + 0x9A);

    if (fmt == 2) {
        ADXB_ExecOneAuUlaw(adxb);
    } else if (fmt == 1) {
        ADXB_ExecOneAu8(adxb);
    } else {
        ADXB_ExecOneAu16(adxb);
    }
}

#define AU_BE32(p) ((u32)(p)[0] << 24 | (u32)(p)[1] << 16 | (u32)(p)[2] << 8 | (p)[3])

/* AU_GetInfo 0x174490.
 *
 * Reads a Sun AU (.snd) header: sample rate, channels, bits and sample
 * count, and the format (2 for 8-bit mu-law, 1 for 8-bit linear, 0 for
 * 16-bit linear). Returns the start of the sample data, or 0 if this is
 * not a supported AU file or its header is longer than len. */

u8 *AU_GetInfo(u8 *hdr, s32 len, s32 *sfreq, s32 *nch, s32 *bits, s32 *nsmpl, s32 *fmt) {
    u32 magic = hdr[0] | hdr[1] << 8 | hdr[2] << 16 | hdr[3] << 24;
    s32 hoff;
    s32 dsize;

    if (magic != 0x64732E && magic != 0x646E732E) {
        return 0;
    }

    hoff = AU_BE32(hdr + 4);

    if (hoff > len) {
        return 0;
    }

    dsize = AU_BE32(hdr + 8);

    switch (AU_BE32(hdr + 0xC)) {
    case 1:
        *fmt = 2;
        *bits = 8;
        break;
    case 2:
        *fmt = 1;
        *bits = 8;
        break;
    case 3:
        *fmt = 0;
        *bits = 16;
        break;
    default:
        return 0;
    }

    *sfreq = AU_BE32(hdr + 0x10);
    *nch = AU_BE32(hdr + 0x14);

    switch (*fmt) {
    case 2:
    case 1:
        *nsmpl = dsize / *nch;
        break;
    case 0:
        *nsmpl = dsize / 2 / *nch;
        break;
    default:
        *nsmpl = 0x7FFF0000;
        break;
    }

    return hdr + hoff;
}

/* ADX_DecodeInfoAu 0x1746F0.
 *
 * The AU counterpart of ADX_DecodeInfoWav. */

s32 ADX_DecodeInfoAu(u8 *hdr, s32 len, s16 *ofst, s8 *enc, s8 *bits, s8 *blk, s8 *nch, s32 *sfreq, s32 *nsmpl,
                     s32 *spb, s32 *fmt) {
    s32 n_ch;
    s32 n_bits;
    s32 n_smpl;
    u8 *data;

    if (len < 8) {
        *ofst = 0;
        return -1;
    }

    if ((data = AU_GetInfo(hdr, len, &len, &n_ch, &n_bits, &n_smpl, fmt)) == 0) {
        return -1;
    }

    if ((*ofst = data - hdr) <= 0) {
        return -1;
    }

    *sfreq = len;
    *nch = n_ch;
    *bits = n_bits;
    *nsmpl = n_smpl;
    *enc = (s8)0xFF;
    *blk = *bits * *nch / 8;
    *spb = 1;
    return 0;
}

/* ADXB_DecodeHeaderAu 0x1747B0.
 *
 * Sets the decoder up for an AU file (format 4); returns the data
 * offset, or 0. */

s32 ADXB_DecodeHeaderAu(ADXB adxb, u8 *hdr, s32 len) {
    s16 ofst;
    s32 fmt;

    adxb->unk2 = 1;

    if (ADX_DecodeInfoAu(hdr, len, &ofst, &adxb->encoding_type, &adxb->sample_bitdepth, &adxb->block_size,
                         &adxb->channel_count, &adxb->sample_rate, &adxb->total_samples, &adxb->samples_per_block,
                         &fmt) < 0) {
        return 0;
    }

    adxb->unk48.unk8 = adxb->channel_count;
    adxb->unk48.unkC = adxb->block_size;
    adxb->unk48.unk10 = adxb->samples_per_block;
    adxb->unk48.unk14 = adxb->unk3C;
    adxb->unk48.unk18 = adxb->unk40;
    adxb->unk48.unk1C = adxb->unk44;
    adxb->unk1C = 0;
    adxb->unk26 = 0;
    adxb->unk24 = 0;
    adxb->unk34 = 0;
    adxb->unk30 = 0;
    adxb->unk2C = 0;
    adxb->unk28 = 0;
    adxb->unk20 = 0;
    adxb->unk8C = 0;
    adxb->unk88 = 0;
    adxb->format = 4;
    adxb->unk9A = fmt;
    return ofst;
}
