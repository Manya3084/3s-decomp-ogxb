/* adx_bsps.c: the SPSD path of the ADX decoder. ADXB_CheckSpsd 0x1752C0. */

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

s32 ADXB_CheckSpsd(u8 *hdr) {
    return memcmp(hdr, "SPSD", 4) == 0;
}

/* ADX_DecodeInfoSpsd 0x175010.
 *
 * Reads an SPSD header: data offset (byte 7 x 16), channels, rate and
 * format (byte 8: 16-bit, 8-bit or 4-bit). Retail then overwrites the
 * format's block size, samples per block, sample count and bit depth
 * with the 16-bit values, so only the format number differs. */

s32 ADX_DecodeInfoSpsd(u8 *hdr, s32 len, s16 *ofst, s8 *enc, s8 *bits, s8 *blk, s8 *nch, s32 *sfreq, s32 *nsmpl,
                       s32 *spb, s16 *fmt) {
    (void)len;

    *ofst = hdr[7] << 4;
    *nch = (hdr[9] & 3) + 1;
    *sfreq = *(u16 *)(hdr + 0x2A);

    switch (hdr[8]) {
    case 0:
        *bits = 16;
        *blk = *nch * 2;
        *spb = 1;
        *nsmpl = *(s32 *)(hdr + 0xC) / 2;
        *fmt = 0;
        break;
    case 1:
        *bits = 8;
        *blk = *nch;
        *spb = 1;
        *nsmpl = *(s32 *)(hdr + 0xC);
        *fmt = 1;
        break;
    case 2:
    case 3:
        *bits = 4;
        *blk = *nch;
        *spb = 2;
        *nsmpl = *(s32 *)(hdr + 0xC) * 2;
        *fmt = 2;
        break;
    }

    *blk = 2;
    *spb = 1;
    *nsmpl = *(s32 *)(hdr + 0xC) / 2;
    *bits = 16;
    *enc = (s8)0xFF;
    return 0;
}

/* ADXB_DecodeHeaderSpsd 0x175100.
 *
 * Sets the decoder up for an SPSD file (format 2). */

s32 ADXB_DecodeHeaderSpsd(ADXB adxb, u8 *hdr, s32 len) {
    s16 ofst;

    adxb->unk2 = 1;

    if (ADX_DecodeInfoSpsd(hdr, len, &ofst, &adxb->encoding_type, &adxb->sample_bitdepth, &adxb->block_size,
                           &adxb->channel_count, &adxb->sample_rate, &adxb->total_samples, &adxb->samples_per_block,
                           &adxb->unk9A) < 0) {
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
    adxb->format = 2;
    return ofst;
}
