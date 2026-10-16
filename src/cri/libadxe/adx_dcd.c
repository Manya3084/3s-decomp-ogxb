/* ADX_DecodeInfo 0x170D10.
 *
 * A short header returns -1. A first word other than 0x8000 returns -2.
 * The copyright offset is big-endian and then increased by 4.
 * Sample rate and total samples are big-endian dwords.
 * A sample bit depth of 0 stores 0 samples per block. Otherwise the
 * count is (block_size - 2) * 8 / sample_bitdepth.
 */

#include "types.h"

#include <stddef.h>

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
} ADXHeader;

#if defined(__i386__)
_Static_assert(offsetof(ADXHeader, encoding_type) == 4, "encoding_type");
_Static_assert(offsetof(ADXHeader, block_size) == 5, "block_size");
_Static_assert(offsetof(ADXHeader, sample_bitdepth) == 6, "sample_bitdepth");
_Static_assert(offsetof(ADXHeader, channel_count) == 7, "channel_count");
_Static_assert(offsetof(ADXHeader, sample_rate_0) == 8, "sample_rate");
_Static_assert(offsetof(ADXHeader, total_samples_0) == 0xC, "total_samples");
#endif

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
