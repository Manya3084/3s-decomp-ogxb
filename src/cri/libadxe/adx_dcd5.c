/* adx_dcd5.c: the 4-bit ADX block decoders, 0x1752E0 to 0x175AF3.
 * The PS2 decompilation has no C for these.
 *
 * A block is 18 bytes: a big-endian scale word, then 16 bytes of 32
 * samples, high nibble first. Bit 15 of the scale word marks the end of
 * the stream. An encrypted stream XORs the scale with a key that steps
 * as key = (key * mul + add) & 0x7FFF per block. Each sample is
 * ((coef1 * prev1 + coef2 * prev2) >> 12) + nibble * scale, clipped to
 * 16 bits. AdxQtbl is 0x2E2768.
 */

#include "types.h"

extern s32 D_007A6094; /* ADX_SetDecodeSteAsMonoSw */

static const s32 AdxQtbl[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -7, -6, -5, -4, -3, -2, -1 };

#define ADX_CLIP(t, v) t = (v > 32767) ? ((v < -32768) ? -32768 : 32767) : ((v < -32768) ? -32768 : v)

s32 ADX_DecodeMono4(u8 *src, s32 nblk, s16 *dst, s16 *dly, s16 coef1, s16 coef2, u16 *key, s16 kmul, s16 kadd) {
    s32 d0 = dly[0];
    s32 d1 = dly[1];
    s32 i;
    s32 j;
    u16 hdr;
    s32 scale;
    s32 b;
    s32 v;
    s32 t;

    for (i = 0; i < nblk; i++) {
        hdr = (*(u16 *)src >> 8) | (*(u16 *)src << 8);

        if (hdr & 0x8000) {
            return i;
        }

        scale = (s16)(((*key ^ hdr) & 0x1FFF) + 1);
        *key = (*key * kmul + kadd) & 0x7FFF;
        src += 2;

        for (j = 0; j < 16; j++) {
            b = (s8)*src++;
            v = ((coef1 * d0 + coef2 * d1) >> 12) + (b >> 4) * scale;
            ADX_CLIP(t, v);
            *dst++ = t;
            d1 = d0;
            d0 = t;
            v = ((coef1 * d0 + coef2 * d1) >> 12) + AdxQtbl[b & 0xF] * scale;
            ADX_CLIP(t, v);
            *dst++ = t;
            d1 = d0;
            d0 = t;
        }
    }

    dly[0] = d0;
    dly[1] = d1;
    return nblk;
}

/* Stereo: nblk blocks, alternating left and right. Each pair shares the
 * key, which steps once per block. */
s32 ADX_DecodeSte4AsMono(u8 *src, s32 nblk, s16 *dst0, s16 *dly0, s16 *dst1, s16 *dly1, s16 coef1, s16 coef2,
                         u16 *key, s16 kmul, s16 kadd) {
    s32 l0 = dly0[0];
    s32 l1 = dly0[1];
    s32 r0 = dly1[0];
    s32 r1 = dly1[1];
    s32 npair = nblk / 2;
    s32 i;
    s32 j;
    u16 hdr;
    s32 lscale;
    s32 rscale;
    s32 lb;
    s32 rb;
    s32 v;
    s32 t;
    s32 lt;
    s32 rt;

    for (i = 0; i < npair; i++) {
        hdr = (*(u16 *)src >> 8) | (*(u16 *)src << 8);

        if (hdr & 0x8000) {
            return i * 2;
        }

        lscale = (s16)(((*key ^ hdr) & 0x1FFF) + 1);
        *key = (*key * kmul + kadd) & 0x7FFF;
        hdr = (*(u16 *)(src + 0x12) >> 8) | (*(u16 *)(src + 0x12) << 8);

        if (hdr & 0x8000) {
            return i * 2;
        }

        rscale = (s16)(((*key ^ hdr) & 0x1FFF) + 1);
        *key = (*key * kmul + kadd) & 0x7FFF;
        src += 2;

        for (j = 0; j < 16; j++) {
            lb = (s8)src[0];
            rb = (s8)src[0x12];
            src++;
            v = ((coef1 * l0 + coef2 * l1) >> 12) + (lb >> 4) * lscale;
            ADX_CLIP(lt, v);
            v = ((coef1 * r0 + coef2 * r1) >> 12) + (rb >> 4) * rscale;
            ADX_CLIP(rt, v);
            l1 = l0;
            l0 = lt;
            r1 = r0;
            r0 = rt;
            v = (lt + rt) * 7 / 10;
            ADX_CLIP(t, v);
            *dst0++ = t;
            *dst1++ = t;
            v = ((coef1 * l0 + coef2 * l1) >> 12) + AdxQtbl[lb & 0xF] * lscale;
            ADX_CLIP(lt, v);
            v = ((coef1 * r0 + coef2 * r1) >> 12) + AdxQtbl[rb & 0xF] * rscale;
            ADX_CLIP(rt, v);
            l1 = l0;
            l0 = lt;
            r1 = r0;
            r0 = rt;
            v = (lt + rt) * 7 / 10;
            ADX_CLIP(t, v);
            *dst0++ = t;
            *dst1++ = t;
        }

        src += 0x12;
    }

    dly0[0] = l0;
    dly0[1] = l1;
    dly1[0] = r0;
    dly1[1] = r1;
    return nblk;
}

s32 ADX_DecodeSte4AsSte(u8 *src, s32 nblk, s16 *dst0, s16 *dly0, s16 *dst1, s16 *dly1, s16 coef1, s16 coef2,
                        u16 *key, s16 kmul, s16 kadd) {
    s32 l0 = dly0[0];
    s32 l1 = dly0[1];
    s32 r0 = dly1[0];
    s32 r1 = dly1[1];
    s32 npair = nblk / 2;
    s32 i;
    s32 j;
    u16 hdr;
    s32 lscale;
    s32 rscale;
    s32 lb;
    s32 rb;
    s32 v;
    s32 lt;
    s32 rt;

    for (i = 0; i < npair; i++) {
        hdr = (*(u16 *)src >> 8) | (*(u16 *)src << 8);

        if (hdr & 0x8000) {
            return i * 2;
        }

        lscale = (s16)(((*key ^ hdr) & 0x1FFF) + 1);
        *key = (*key * kmul + kadd) & 0x7FFF;
        hdr = (*(u16 *)(src + 0x12) >> 8) | (*(u16 *)(src + 0x12) << 8);

        if (hdr & 0x8000) {
            return i * 2;
        }

        rscale = (s16)(((*key ^ hdr) & 0x1FFF) + 1);
        *key = (*key * kmul + kadd) & 0x7FFF;
        src += 2;

        for (j = 0; j < 16; j++) {
            lb = (s8)src[0];
            rb = (s8)src[0x12];
            src++;
            v = ((coef1 * l0 + coef2 * l1) >> 12) + (lb >> 4) * lscale;
            ADX_CLIP(lt, v);
            v = ((coef1 * r0 + coef2 * r1) >> 12) + (rb >> 4) * rscale;
            ADX_CLIP(rt, v);
            l1 = l0;
            l0 = lt;
            r1 = r0;
            r0 = rt;
            *dst0++ = lt;
            *dst1++ = rt;
            v = ((coef1 * l0 + coef2 * l1) >> 12) + AdxQtbl[lb & 0xF] * lscale;
            ADX_CLIP(lt, v);
            v = ((coef1 * r0 + coef2 * r1) >> 12) + AdxQtbl[rb & 0xF] * rscale;
            ADX_CLIP(rt, v);
            l1 = l0;
            l0 = lt;
            r1 = r0;
            r0 = rt;
            *dst0++ = lt;
            *dst1++ = rt;
        }

        src += 0x12;
    }

    dly0[0] = l0;
    dly0[1] = l1;
    dly1[0] = r0;
    dly1[1] = r1;
    return nblk;
}

s32 ADX_DecodeSte4(u8 *src, s32 nblk, s16 *dst0, s16 *dly0, s16 *dst1, s16 *dly1, s16 coef1, s16 coef2, u16 *key,
                   s16 kmul, s16 kadd) {
    if (D_007A6094 == 0) {
        return ADX_DecodeSte4AsSte(src, nblk, dst0, dly0, dst1, dly1, coef1, coef2, key, kmul, kadd);
    }

    return ADX_DecodeSte4AsMono(src, nblk, dst0, dly0, dst1, dly1, coef1, coef2, key, kmul, kadd);
}
