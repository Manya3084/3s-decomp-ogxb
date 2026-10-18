/* ADX_GetCoefficient 0x170C60. ADX_DecodeInfo 0x170D10.
 * ADX_DecodeInfoExADPCM2 0x170DE0.
 * ADX_DecodeInfoExVer 0x170E30. ADX_DecodeInfoExIdly 0x170E90.
 * ADX_DecodeInfoExLoop 0x170F70. ADX_DecodeInfoAinf 0x171130.
 * ADX_DecodeFooter 0x171280: a footer needs 16 bytes and the big-endian
 * marker 0x8001; the big-endian size plus 4 is stored.
 *
 * GetCoefficient matches the PS2 formula. sqrt(2) is the square root
 * of the qword 2.0 at 0x2686F0. The 2*pi factor is the float at
 * 0x219094. coef1 stores r*8192 and coef2 stores r*r*-4096. Both
 * truncations go through _ftol2 at 0x175B40.
 *
 * A short header returns -1. A first word other than 0x8000 returns -2.
 * The copyright offset is big-endian and then increased by 4.
 * Sample rate and total samples are big-endian dwords.
 * A sample bit depth of 0 stores 0 samples per block. Otherwise the
 * count is (block_size - 2) * 8 / sample_bitdepth.
 * ExADPCM2 requires 0x12 bytes and a signed copyright offset of at
 * least 0xE, then stores the big-endian high-pass word.
 * ExVer requires 0x14 bytes and a signed copyright offset of at
 * least 0x10, then stores the version and flags bytes.
 * ExIdly returns -1 when ExVer fails. Version 4 and above requires
 * 0x20 bytes and a signed copyright offset of at least 0x1C, then
 * stores the four big-endian words at 0x18. An older version stores 0.
 * ExLoop returns the version-decode code unchanged. Version 4 reads
 * from byte 0x20 and needs 0x3C bytes. Any other version reads from
 * byte 0x14 and needs 0x30 bytes. The loop count must be 1.
 * Ainf returns the version-decode code unchanged. Version 4 needs
 * 0x48 bytes. Any other version needs 0x3C. The block magic is AINF.
 */

#include "types.h"

#include <math.h>
#include <stddef.h>
#include <string.h>

#define PI 3.14159265f
#define PI_2 (PI * 2)

typedef struct {
    u8 magic_0;
    u8 magic_1;
    u8 copyright_offset_0;
    u8 copyright_offset_1;
    u8 encoding_type;
    u8 block_size;
    u8 sample_bitdepth;
    u8 channel_count;
    u8 sample_rate_0;
    u8 sample_rate_1;
    u8 sample_rate_2;
    u8 sample_rate_3;
    u8 total_samples_0;
    u8 total_samples_1;
    u8 total_samples_2;
    u8 total_samples_3;
    u8 high_pass_0;
    u8 high_pass_1;
    u8 version;
    u8 flags;
    u8 pad14[4];
    u8 unk18_0;
    u8 unk18_1;
    u8 unk1A_0;
    u8 unk1A_1;
    u8 unk1C_0;
    u8 unk1C_1;
    u8 unk1E_0;
    u8 unk1E_1;
} ADXHeader;

typedef struct {
    u8 pad0[0x10];
} ADX_UNK;

#if defined(__i386__)
_Static_assert(offsetof(ADXHeader, encoding_type) == 4, "encoding_type");
_Static_assert(offsetof(ADXHeader, block_size) == 5, "block_size");
_Static_assert(offsetof(ADXHeader, sample_bitdepth) == 6, "sample_bitdepth");
_Static_assert(offsetof(ADXHeader, channel_count) == 7, "channel_count");
_Static_assert(offsetof(ADXHeader, sample_rate_0) == 8, "sample_rate");
_Static_assert(offsetof(ADXHeader, total_samples_0) == 0xC, "total_samples");
_Static_assert(offsetof(ADXHeader, high_pass_0) == 0x10, "high_pass");
_Static_assert(offsetof(ADXHeader, version) == 0x12, "version");
_Static_assert(offsetof(ADXHeader, flags) == 0x13, "flags");
_Static_assert(offsetof(ADXHeader, unk18_0) == 0x18, "unk18");
_Static_assert(offsetof(ADXHeader, unk1A_0) == 0x1A, "unk1A");
_Static_assert(offsetof(ADXHeader, unk1C_0) == 0x1C, "unk1C");
_Static_assert(offsetof(ADXHeader, unk1E_0) == 0x1E, "unk1E");
_Static_assert(sizeof(ADX_UNK) == 0x10, "ADX_UNK");
#endif

void ADX_GetCoefficient(s32 high_pass, s32 sample_rate, s16 *coef1, s16 *coef2) {
    f32 f21;
    f32 f20;
    f32 r;

    f21 = sqrtf(2.0f) - cosf((PI_2 * (f32)high_pass) / (f32)sample_rate);
    f20 = sqrtf(2.0f) - 1.0f;
    r = (f21 - sqrtf((f21 + f20) * (f21 - f20))) / f20;
    *coef1 = (s16)(2 * r * 4096);
    *coef2 = (s16)(-r * r * 4096);
}

s32 ADX_DecodeInfo(ADXHeader *hdr, s32 len, s16 *audio_offset, s8 *encoding_type, s8 *sample_bitdepth,
                   s8 *block_size, s8 *channel_count, s32 *sample_rate, s32 *total_samples, s32 *samples_per_block) {
    if (len < 16) {
        return -1;
    }

    if ((u16)((hdr->magic_0 << 8) | hdr->magic_1) != 0x8000) {
        return -2;
    }

    *audio_offset = (s16)(((hdr->copyright_offset_0 << 8) | hdr->copyright_offset_1) + 4);
    *encoding_type = (s8)hdr->encoding_type;
    *block_size = (s8)hdr->block_size;
    *sample_bitdepth = (s8)hdr->sample_bitdepth;
    *channel_count = (s8)hdr->channel_count;
    *sample_rate = (s32)(((u32)hdr->sample_rate_0 << 24) | ((u32)hdr->sample_rate_1 << 16) |
                        ((u32)hdr->sample_rate_2 << 8) | hdr->sample_rate_3);
    *total_samples = (s32)(((u32)hdr->total_samples_0 << 24) | ((u32)hdr->total_samples_1 << 16) |
                           ((u32)hdr->total_samples_2 << 8) | hdr->total_samples_3);

    if (*sample_bitdepth == 0) {
        *samples_per_block = 0;
    } else {
        *samples_per_block = (*block_size - 2) * 8 / *sample_bitdepth;
    }

    return 0;
}

s32 ADX_DecodeInfoExADPCM2(ADXHeader *hdr, s32 len, s16 *high_pass_frequency) {
    s16 copyright;

    if (len < 0x12) {
        return -1;
    }

    if ((u16)((hdr->magic_0 << 8) | hdr->magic_1) != 0x8000) {
        return -2;
    }

    copyright = (s16)((hdr->copyright_offset_0 << 8) | hdr->copyright_offset_1);
    if (copyright < 0xE) {
        return -1;
    }

    *high_pass_frequency = (s16)((hdr->high_pass_0 << 8) | hdr->high_pass_1);
    return 0;
}

s32 ADX_DecodeInfoExVer(ADXHeader *hdr, s32 len, s8 *version, s8 *flags) {
    s16 copyright;

    if (len < 0x14) {
        return -1;
    }

    if ((u16)((hdr->magic_0 << 8) | hdr->magic_1) != 0x8000) {
        return -2;
    }

    copyright = (s16)((hdr->copyright_offset_0 << 8) | hdr->copyright_offset_1);
    if (copyright < 0x10) {
        return -1;
    }

    *version = (s8)hdr->version;
    *flags = (s8)hdr->flags;
    return 0;
}

s32 ADX_DecodeInfoExIdly(ADXHeader *hdr, s32 len, s16 *arg2, s16 *arg3) {
    s8 version;
    s8 flags;
    s16 copyright;

    if (ADX_DecodeInfoExVer(hdr, len, &version, &flags) != 0) {
        return -1;
    }

    if ((u8)version >= 4) {
        if (len < 0x20) {
            return -1;
        }

        if ((u16)((hdr->magic_0 << 8) | hdr->magic_1) != 0x8000) {
            return -2;
        }

        copyright = (s16)((hdr->copyright_offset_0 << 8) | hdr->copyright_offset_1);
        if (copyright < 0x1C) {
            return -1;
        }

        arg2[0] = (s16)((hdr->unk18_0 << 8) | hdr->unk18_1);
        arg3[0] = (s16)((hdr->unk1A_0 << 8) | hdr->unk1A_1);
        arg2[1] = (s16)((hdr->unk1C_0 << 8) | hdr->unk1C_1);
        arg3[1] = (s16)((hdr->unk1E_0 << 8) | hdr->unk1E_1);
    } else {
        arg3[1] = 0;
        arg2[1] = 0;
        arg3[0] = 0;
        arg2[0] = 0;
    }

    return 0;
}

s32 ADX_DecodeInfoExLoop(ADXHeader *hdr, s32 len, s32 *arg2, s16 *arg3, s16 *arg4, s32 *arg5, s32 *arg6, s32 *arg7,
                         s32 *arg8) {
    s8 version;
    s8 flags;
    s32 err;
    s32 need;
    s32 pos;
    u8 *bytes;

    bytes = (u8 *)hdr;
    *arg3 = 0;
    err = ADX_DecodeInfoExVer(hdr, len, &version, &flags);
    if (err != 0) {
        return err;
    }

    need = 0x30;
    if (version == 4) {
        need = 0x3C;
    }

    if (len < need) {
        return -1;
    }

    if ((u16)((bytes[0] << 8) | bytes[1]) != 0x8000) {
        return -2;
    }

    if ((s16)((bytes[2] << 8) | bytes[3]) < (need - 4)) {
        return -1;
    }

    pos = (version != 4) ? 0x14 : 0x20;
    *arg2 = (s16)((bytes[pos] << 8) | bytes[pos + 1]);
    pos += 2;
    *arg3 = (s16)((bytes[pos] << 8) | bytes[pos + 1]);
    pos += 2;

    if (*arg3 != 1) {
        return -2;
    }

    pos += 2;
    *arg4 = (s16)((bytes[pos] << 8) | bytes[pos + 1]);
    pos += 2;
    *arg5 = (s32)(((u32)bytes[pos] << 24) | ((u32)bytes[pos + 1] << 16) | ((u32)bytes[pos + 2] << 8) | bytes[pos + 3]);
    pos += 4;
    *arg6 = (s32)(((u32)bytes[pos] << 24) | ((u32)bytes[pos + 1] << 16) | ((u32)bytes[pos + 2] << 8) | bytes[pos + 3]);
    pos += 4;
    *arg7 = (s32)(((u32)bytes[pos] << 24) | ((u32)bytes[pos + 1] << 16) | ((u32)bytes[pos + 2] << 8) | bytes[pos + 3]);
    pos += 4;
    *arg8 = (s32)(((u32)bytes[pos] << 24) | ((u32)bytes[pos + 1] << 16) | ((u32)bytes[pos + 2] << 8) | bytes[pos + 3]);
    return 0;
}

s32 ADX_DecodeInfoAinf(ADXHeader *hdr, s32 len, s32 *arg2, ADX_UNK *arg3, s16 *arg4, s16 *arg5) {
    s8 version;
    s8 flags;
    s32 need;
    s32 err;
    s32 pos;
    u32 magic;
    u8 *bytes;

    bytes = (u8 *)hdr;
    *arg2 = 0;
    err = ADX_DecodeInfoExVer(hdr, len, &version, &flags);
    if (err != 0) {
        return err;
    }

    need = 0x3C;
    if (version == 4) {
        need = 0x48;
    }

    if (len < need) {
        return -1;
    }

    if ((u16)((bytes[0] << 8) | bytes[1]) != 0x8000) {
        return -2;
    }

    if ((s16)((bytes[2] << 8) | bytes[3]) < (need - 4)) {
        return -1;
    }

    pos = (version != 4) ? 0x14 : 0x20;
    pos += 4;
    magic = ((u32)bytes[pos] << 24) | ((u32)bytes[pos + 1] << 16) | ((u32)bytes[pos + 2] << 8) | bytes[pos + 3];
    pos += 4;
    if (magic != 0x41494E46) {
        return -2;
    }

    *arg2 = (s32)(((u32)bytes[pos] << 24) | ((u32)bytes[pos + 1] << 16) | ((u32)bytes[pos + 2] << 8) | bytes[pos + 3]);
    pos += 4;
    memcpy(arg3, bytes + pos, sizeof(*arg3));
    pos += (s32)sizeof(*arg3);
    *arg4 = (s16)((bytes[pos] << 8) | bytes[pos + 1]);
    pos += 4;
    arg5[0] = (s16)((bytes[pos] << 8) | bytes[pos + 1]);
    pos += 2;
    arg5[1] = (s16)((bytes[pos] << 8) | bytes[pos + 1]);
    return 0;
}

s32 ADX_DecodeFooter(u8 *buf, s32 len, s16 *ofst) {
    u16 w;

    if (len < 16) {
        return -1;
    }

    if ((u16)((buf[0] << 8) | buf[1]) != 0x8001) {
        return -2;
    }

    w = *(u16 *)(buf + 2);
    *ofst = (u16)((w >> 8) | (w << 8)) + 4;
    return 0;
}
