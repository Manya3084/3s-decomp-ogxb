/* adx_bwav.c: the WAV (RIFF PCM) path of the ADX decoder. ADX_DecodeInfoWav
 * 0x173FF0, ADXB_DecodeHeaderWav 0x174140, ADXB_CheckWav 0x174420 and
 * ADXB_ExecOneWav 0x174450. The chunk ids are reached through the pointers
 * at 0x43CD54 ("fmt ") and 0x43CD58 ("data"). */

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

extern char *D_0043CD54;
extern char *D_0043CD58;
extern void ADXB_ExecOneWav4(ADXB adxb);
extern void ADXB_ExecOneWav8(ADXB adxb);
extern void ADXB_ExecOneSpsd(ADXB adxb);

s32 ADX_DecodeInfoWav(u8 *hdr, s32 len, s16 *ofst, s8 *enc, s8 *bits, s8 *blk, s8 *nch, s32 *sfreq, s32 *nsmpl,
                      s32 *spb, s16 *fmt) {
    u8 *wf;
    s32 i;
    s32 j;
    s32 dsize;

    for (i = 0; i < len; i++) {
        if (memcmp(hdr + i, D_0043CD54, 4) == 0) {
            break;
        }
    }

    if (i == len || i % 4 != 0 || *(s16 *)(wf = hdr + i + 8) > 1) {
        return -1;
    }

    for (j = 0; j < len; j++) {
        if (memcmp(hdr + j, D_0043CD58, 4) == 0) {
            break;
        }
    }

    if (j == len) {
        return -1;
    }

    dsize = *(s32 *)(hdr + j + 4);
    *ofst = (s16)(j + 8);
    *enc = (s8)0xFF;
    *sfreq = *(s32 *)(wf + 4);
    *nch = wf[2];
    *bits = wf[0xE];
    *blk = wf[0xC];
    *nsmpl = dsize / *blk;
    *spb = 1;

    if (*bits == 16) {
        *fmt = 0;
    } else if (*bits == 8) {
        *fmt = 1;
    } else if (*bits == 4) {
        *blk = *nch * 2;
        *spb = 4;
        *nsmpl = dsize / 2 / *nch;
        *bits = 16;
        *fmt = 2;
    }

    if (*bits == 0 || *blk == 0 || *nch <= 0 || *nch > 2) {
        return -1;
    }

    return (*sfreq != 0) - 1;
}

s32 ADXB_DecodeHeaderWav(ADXB adxb, u8 *hdr, s32 len) {
    s16 ofst;

    adxb->unk2 = 1;

    if (ADX_DecodeInfoWav(hdr, len, &ofst, &adxb->encoding_type, &adxb->sample_bitdepth, &adxb->block_size,
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
    adxb->format = 1;
    return ofst;
}

s32 ADXB_CheckWav(u8 *hdr) {
    if (memcmp(hdr, "RIFF", 4) == 0 && memcmp(hdr + 8, "WAVE", 4) == 0) {
        return 1;
    }

    return 0;
}

void ADXB_ExecOneWav(ADXB adxb) {
    if (adxb->unk9A == 2) {
        ADXB_ExecOneWav4(adxb);
    } else if (adxb->unk9A == 1) {
        ADXB_ExecOneWav8(adxb);
    } else if (adxb->unk9A == 0) {
        ADXB_ExecOneSpsd(adxb);
    }
}
