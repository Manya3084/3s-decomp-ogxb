/* adx_baif.c: the AIFF path of the ADX decoder. ADXB_CheckAiff 0x174E40 and
 * ADXB_ExecOneAiff 0x174FF0. */

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

extern void ADXB_ExecOneAiff8(void *adxb);
extern void ADXB_ExecOneAiff16(void *adxb);

s32 ADXB_CheckAiff(u8 *hdr) {
    if (memcmp(hdr, "FORM", 4) == 0 && memcmp(hdr + 8, "AIFF", 4) == 0) {
        return 1;
    }

    return 0;
}

void ADXB_ExecOneAiff(void *adxb) {
    if (*(s16 *)((u8 *)adxb + 0x9A) == 1) {
        ADXB_ExecOneAiff8(adxb);
    } else {
        ADXB_ExecOneAiff16(adxb);
    }
}

#define AIFF_LE32(p) ((u32)(p)[0] | (u32)(p)[1] << 8 | (u32)(p)[2] << 16 | (u32)(p)[3] << 24)
#define AIFF_BE32(p) ((u32)(p)[0] << 24 | (u32)(p)[1] << 16 | (u32)(p)[2] << 8 | (p)[3])
#define AIFF_BE16(p) ((p)[0] << 8 | (p)[1])

/* AIFF_GetInfo 0x174BD0.
 *
 * Static (config/sf33rd/static.txt): the header comes in eax. Walks the
 * FORM/AIFF chunks for COMM (channels, sample count, bits, and the
 * rate from the top 16 bits of its 80-bit float) and SSND; returns the
 * start of the sample data, or 0. */

static u8 *AIFF_GetInfo(u8 *hdr, s32 *sfreq, s32 *nch, s32 *bits, s32 *nsmpl) {
    u8 *p;
    u8 *end;
    u8 *data = 0;
    s32 got_comm = 0;
    s32 got_ssnd = 0;
    u32 id;
    s32 size;

    if (AIFF_LE32(hdr) != 0x4D524F46 || AIFF_LE32(hdr + 8) != 0x46464941) {
        return 0;
    }

    p = hdr + 0xC;
    end = p - 4 + AIFF_BE32(hdr + 4);

    while (p < end) {
        id = AIFF_LE32(p);
        size = AIFF_BE32(p + 4);
        p += 8;

        if (id == 0x444E5353) {
            if (!got_ssnd) {
                got_ssnd = 1;
                data = p + 4 + AIFF_BE32(p);
                p += 4;

                if (got_comm) {
                    break;
                }
            }
        } else if (id == 0x4D4D4F43) {
            if (!got_comm) {
                if (size < 0x12) {
                    return 0;
                }

                *nch = AIFF_BE16(p);
                *nsmpl = AIFF_BE32(p + 2);
                *bits = AIFF_BE16(p + 6);
                *sfreq = (u32)AIFF_BE16(p + 10) >> (0x400E - AIFF_BE16(p + 8));
                p += 0x12;
                got_comm = 1;

                if (got_ssnd) {
                    break;
                }
            }
        } else {
            p += (size + 1) & ~1;
        }
    }

    return data;
}

/* ADX_DecodeInfoAiff 0x174E70.
 *
 * The AIFF counterpart of ADX_DecodeInfoWav; it needs 0x1000 bytes. */

s32 ADX_DecodeInfoAiff(u8 *hdr, s32 len, s16 *ofst, s8 *enc, s8 *bits, s8 *blk, s8 *nch, s32 *sfreq, s32 *nsmpl,
                       s32 *spb) {
    s32 n_ch;
    s32 n_bits;
    s32 n_smpl;
    u8 *data;

    if (len < 0x1000) {
        *ofst = 0;
        return -1;
    }

    if ((data = AIFF_GetInfo(hdr, &len, &n_ch, &n_bits, &n_smpl)) == 0) {
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

/* ADXB_DecodeHeaderAiff 0x174F30.
 *
 * Sets the decoder up for an AIFF file (format 3, 8-bit or 16-bit). */

s32 ADXB_DecodeHeaderAiff(ADXB adxb, u8 *hdr, s32 len) {
    s16 ofst;

    adxb->unk2 = 1;

    if (ADX_DecodeInfoAiff(hdr, len, &ofst, &adxb->encoding_type, &adxb->sample_bitdepth, &adxb->block_size,
                           &adxb->channel_count, &adxb->sample_rate, &adxb->total_samples,
                           &adxb->samples_per_block) < 0) {
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
    adxb->format = 3;
    adxb->unk9A = adxb->sample_bitdepth == 8;
    return ofst;
}
