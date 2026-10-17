/* cseTsbSetBankAddr, retail sf33rd.xbe 0xF4532 size 0x5.
 * It is interior. The body is a tail jump to mlTsbSetBankAddr.
 * 0xF4510, 0xF451D, and 0xF452A stay unnamed.
 *
 * set_hitmark_color is 0xB59E1 size 0x99 and is interior.
 * hitmark_color is 0x283458 and matches the 256 PlayStation 2 bytes.
 * ColorRAM is 0x7AAD60. The mode call stays sub_0004384A.
 * The data calls stay sub_000309CF. That body passes its three
 * arguments to palCopyGhostDC and tails into palUpdateGhostDC.
 * The PlayStation 2 source calls njSetPaletteData(64, 64, ColorRAM[15])
 * and njSetPaletteData(576, 64, ColorRAM[31]).
 *
 * init_color_trans_req is 0xB564D size 0x1F and is interior.
 * col3rd_w.req starts at 0x7AAC88. reqNum is 0x7AAD08.
 * palCopyGhostDC is 0xB566C size 0x3D and is interior.
 * colPalBuffDC is 0x796080. upBits is 0x7AAD0C.
 * palConvSrcToRam is 0xB56A9 size 0x9C and is interior.
 * palFormConv is 0x7BAD60. palFormSrc is 0x7AAD20. palFormRam is 0x7BAD80.
 * The masks run in B, G, R, A order. The OR is the PlayStation 2 word.
 *
 * palCreateGhost is 0xB5745 size 0x15C and is a scanned start.
 * It stores palFormConv as 0. palFormRam.rs stays 10 and palFormRam.bs
 * stays 0. The PlayStation 2 source sets palFormConv to 1, palFormRam.rs
 * to 0, palFormRam.bs to 10, palFormRam.gl to 5, and palFormRam.gm to 31.
 * Each buffer is 0x2000 bytes and is cleared as 0x800 dwords.
 * The key push stays sub_00097103.
 *
 * palGetChunkGhostDC is 0xB58A1 size 0x6 and is interior.
 * palGetChunkGhostCP3 is 0xB58A7 size 0x6 and is interior.
 * palDC is 0x7AAC60. palCP3 is 0x7AAC74.
 *
 * palUpdateGhostDC is 0xB5903 size 0x78 and is a scanned start.
 * palUpdateGhostCP3 is 0xB597B size 0x66 and is a scanned start.
 * Both lock through sub_00016F71(0, handle, &bits, 2). The row expand
 * is sub_000B58AD. The PlayStation 2 source calls palConvRowTim2CI8Clut.
 * The unlock is sub_0009B78F, which returns 1.
 * 0xB58AD, 0x16F71, 0x9B78F, 0x4384A, 0x309CF, and 0x97103 stay unnamed.
 * init_trans_color_ram at 0xB5A7A stays unnamed.
 */

#include "types.h"

#include <stddef.h>

typedef struct {
    s8 be;
    u8 c_mode;
    u16 total;
    u16 *handle;
    s32 ixNum1st;
    u8 *srcAdrs;
    u32 srcSize;
} Palette;

typedef struct {
    Palette palDC;
    Palette palCP3;
    s16 req[32][2];
    s16 reqNum;
    u32 upBits;
} Col3rd_W;

typedef struct {
    s32 rl;
    s32 rs;
    s32 rm;
    s32 gl;
    s32 gs;
    s32 gm;
    s32 bl;
    s32 bs;
    s32 bm;
    s32 al;
    s32 as;
    s32 am;
} PixelFormat;

typedef struct {
    u32 desc;
    s32 width;
    s32 height;
    s32 pitch;
    void *ptr;
} plContext;

typedef struct {
    u32 magic;
    u32 fileSize;
    u16 free;
    u8 compress;
    u8 c_mode;
    u16 formARGB;
    u16 palettes;
} PPLFileHeader;

#if defined(__i386__)
_Static_assert(sizeof(Palette) == 0x14, "Palette");
_Static_assert(offsetof(Palette, total) == 2, "total");
_Static_assert(offsetof(Palette, handle) == 4, "handle");
_Static_assert(offsetof(Col3rd_W, palCP3) == 0x14, "palCP3");
_Static_assert(offsetof(Col3rd_W, req) == 0x28, "req");
_Static_assert(offsetof(Col3rd_W, reqNum) == 0xA8, "reqNum");
_Static_assert(offsetof(Col3rd_W, upBits) == 0xAC, "upBits");
_Static_assert(sizeof(PixelFormat) == 0x30, "PixelFormat");
_Static_assert(offsetof(PixelFormat, bs) == 0x1C, "bs");
_Static_assert(offsetof(PixelFormat, as) == 0x28, "as");
_Static_assert(sizeof(PPLFileHeader) == 0x10, "PPL");
_Static_assert(offsetof(PPLFileHeader, c_mode) == 0xB, "c_mode");
_Static_assert(offsetof(PPLFileHeader, formARGB) == 0xC, "form");
_Static_assert(offsetof(PPLFileHeader, palettes) == 0xE, "palettes");
_Static_assert(offsetof(plContext, ptr) == 0x10, "ptr");
#endif

typedef struct SoundEvent SoundEvent;

extern s32 mlTsbSetBankAddr(u32 bank, SoundEvent *addr);
extern Col3rd_W col3rd_w;
extern u16 colPalBuffDC[1024];
extern u16 ColorRAM[512][64];
extern PixelFormat palFormSrc;
extern PixelFormat palFormRam;
extern s32 palFormConv;
extern s16 Pull_ramcnt_key(u32 memreq, u8 kokey, u8 group, u8 frre);
extern void *Get_ramcnt_address(s16 key);
extern s32 ppgSetupPalChunkDir(Palette *pch, PPLFileHeader *ppl, u8 *adrs, s32 ixNum1st, s32 unused);
extern void sub_00097103(s32 key);
extern void sub_0004384A(s32 mode);
extern void sub_000309CF(s32 ofs, s32 cnt, void *data);
extern void sub_00016F71(void *rect, u32 handle, plContext *bits, s32 flag);
extern void sub_000B58AD(u16 *src, void *dst, s32 count);
extern s32 sub_0009B78F(u32 handle);

s32 cseTsbSetBankAddr(u32 bank, SoundEvent *addr) {
    return mlTsbSetBankAddr(bank, addr);
}

u16 palConvSrcToRam(u16 col);
void palUpdateGhostCP3(s32 pal, s32 nums);

const u16 hitmark_color[128] = {
    0,     64478, 64408, 64338, 64268, 64200, 64068, 63942, 63808, 58332, 52186, 54104, 51988, 47888, 41740, 49424,
    64478, 58270, 54174, 49950, 45662, 43550, 43486, 41310, 64478, 64346, 64214, 64148, 64016, 63884, 63752, 61506,
    36944, 64478, 64470, 64402, 64332, 64200, 63940, 61568, 55296, 32768, 32768, 32768, 32768, 32768, 32768, 32768,
    64478, 62302, 60190, 60124, 58012, 57882, 55770, 53658, 64478, 62302, 60190, 60124, 58012, 57882, 55770, 53658,
    0,     64478, 64472, 60298, 54148, 50054, 45896, 39690, 37512, 58332, 52186, 54104, 51988, 47888, 41740, 49424,
    64478, 62302, 60190, 60124, 58012, 57882, 55770, 53658, 64478, 64346, 64214, 64148, 64016, 63884, 63752, 61506,
    36944, 64478, 64470, 64402, 64332, 64200, 63940, 61568, 55296, 32768, 32768, 32768, 32768, 32768, 32768, 32768,
    64478, 58270, 54174, 49950, 45662, 43550, 43486, 41310, 64478, 58206, 56094, 53982, 53918, 51806, 49694, 47582
};

void set_hitmark_color(void) {
    s16 i;

    for (i = 0; i < 64; i++) {
        ColorRAM[7][i] = ColorRAM[15][i] = palConvSrcToRam(hitmark_color[i]);
        ColorRAM[23][i] = ColorRAM[31][i] = palConvSrcToRam(hitmark_color[i + 64]);
    }

    sub_0004384A(0);
    sub_000309CF(64, 64, ColorRAM[15]);
    sub_000309CF(576, 64, ColorRAM[31]);
    palUpdateGhostCP3(7, 1);
    palUpdateGhostCP3(15, 1);
    palUpdateGhostCP3(23, 1);
    palUpdateGhostCP3(31, 1);
}

void init_color_trans_req(void) {
    s16 i;

    for (i = 0; i < 32; i++) {
        col3rd_w.req[i][0] = col3rd_w.req[i][1] = 0;
    }

    col3rd_w.reqNum = 0;
}

void palCopyGhostDC(s32 ofs, s32 cnt, void *data) {
    s32 i;
    u16 *srcAdrs = data;
    u16 *dstAdrs = &colPalBuffDC[ofs];

    for (i = 0; i < cnt; i++) {
        *dstAdrs++ = *srcAdrs++;
    }

    col3rd_w.upBits = col3rd_w.upBits | (1 << (ofs / 64));
}

u16 palConvSrcToRam(u16 col) {
    u8 cA;
    u8 cR;
    u8 cG;
    u8 cB;

    if (palFormConv == 0) {
        return col;
    }

    cA = palFormSrc.am & (col >> palFormSrc.as);
    cR = palFormSrc.rm & (col >> palFormSrc.rs);
    cG = palFormSrc.gm & (col >> palFormSrc.gs);
    cB = palFormSrc.bm & (col >> palFormSrc.bs);
    return (cA << palFormRam.as) | (cR << palFormRam.rs) | (cG << palFormRam.gs) | (cB << palFormRam.bs);
}

void palCreateGhost(void) {
    PPLFileHeader ppl;
    s32 key;
    s32 size;
    s32 i;
    u8 *adrs;

    palFormConv = 0;
    palFormSrc.rl = 5;
    palFormSrc.rs = 10;
    palFormSrc.rm = 31;
    palFormSrc.gl = 5;
    palFormSrc.gs = 5;
    palFormSrc.gm = 31;
    palFormSrc.bl = 5;
    palFormSrc.bs = 0;
    palFormSrc.bm = 31;
    palFormSrc.al = 1;
    palFormSrc.as = 15;
    palFormSrc.am = 1;
    palFormRam.rl = 5;
    palFormRam.rs = 10;
    palFormRam.rm = 31;
    palFormRam.gl = 5;
    palFormRam.gs = 5;
    palFormRam.gm = 31;
    palFormRam.bl = 5;
    palFormRam.bs = 0;
    palFormRam.bm = 31;
    palFormRam.al = 1;
    palFormRam.as = 15;
    palFormRam.am = 1;
    col3rd_w.upBits = 0;
    ppl.magic = 0;
    ppl.fileSize = 0;
    ppl.free = 0;
    ppl.compress = 0;
    ppl.c_mode = 2;
    ppl.formARGB = 0x5515;

    ppl.palettes = 0x1000;
    size = 0x2000;
    key = Pull_ramcnt_key(size, 2, 0, 1);
    adrs = (u8 *)Get_ramcnt_address((s16)key);

    for (i = 0; i < size; i++) {
        adrs[i] = 0;
    }

    ppgSetupPalChunkDir(&col3rd_w.palDC, &ppl, adrs, 0, 1);
    sub_00097103(key);

    ppl.palettes = 2;
    size = 0x2000;
    key = Pull_ramcnt_key(size, 2, 0, 1);
    adrs = (u8 *)Get_ramcnt_address((s16)key);

    for (i = 0; i < size; i++) {
        adrs[i] = 0;
    }

    ppgSetupPalChunkDir(&col3rd_w.palCP3, &ppl, adrs, 0, 1);
    sub_00097103(key);
}

Palette *palGetChunkGhostDC(void) {
    return &col3rd_w.palDC;
}

Palette *palGetChunkGhostCP3(void) {
    return &col3rd_w.palCP3;
}

void palUpdateGhostDC(void) {
    plContext bits;
    s32 i;
    u16 *srcAdrs;
    void *dstAdrs;

    for (i = 0; i < col3rd_w.palDC.total; i++) {
        if (col3rd_w.upBits & (1 << i)) {
            sub_00016F71(0, col3rd_w.palDC.handle[i], &bits, 2);
            dstAdrs = bits.ptr;
            srcAdrs = &colPalBuffDC[(i << 6)];
            sub_000B58AD(srcAdrs, dstAdrs, 0x40);
            sub_0009B78F(col3rd_w.palDC.handle[i]);
        }
    }

    col3rd_w.upBits = 0;
}

void palUpdateGhostCP3(s32 pal, s32 nums) {
    plContext bits;
    s32 i;
    u16 *srcAdrs;
    void *dstAdrs;

    for (i = pal; i < (pal + nums); i++) {
        sub_00016F71(0, col3rd_w.palCP3.handle[i], &bits, 2);
        dstAdrs = bits.ptr;
        srcAdrs = ColorRAM[i];
        sub_000B58AD(srcAdrs, dstAdrs, 0x40);
        sub_0009B78F(col3rd_w.palCP3.handle[i]);
    }
}
