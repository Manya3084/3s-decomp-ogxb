/* ppg_Initialize, retail sf33rd.xbe 0xF22FA.
 * ppgMallocF 0xF2320. ppgMallocR 0xF2334. ppgFree 0xF2348.
 * ppgSetupCurrentDataList 0xF2363. ppgSetupCurrentPaletteNumber 0xF236D.
 * ppgRenewTexChunkSeqs 0xF2A6E. ppgMakeConvTableTexDC 0xF28EC.
 * ppgGetUsingTextureHandle 0xF30BC size 0x38, ppgGetUsingPaletteHandle
 * 0xF30F4 size 0x39, and ppgCheckTextureNumber 0xF312D size 0x3C are
 * interior.
 * A null texture reads ppg_w.cur->tex. A null palette reads ppg_w.cur->pal.
 * The texture reader compares the index with textures. The check subtracts
 * a 16-bit index and compares it with total.
 * ppgCheckTextureDataBe is 0xF3012 size 0x5E. ppgCheckPaletteDataBe is
 * 0xF3070 size 0x4C. Both free a handle through ppgFree when every slot
 * is clear. The texture check also frees offset. ppgTexSrcDataReleased
 * is 0xF3169 size 0x1F. ppgPalSrcDataReleased is 0xF3188 size 0x20.
 * ppgSourceDataReleased is 0xF31A8 size 0x2B. ppgWriteQuadOnly is
 * 0xF239B size 0x5B and copies four vertices of 0x14 bytes through
 * ps2SeqsRenderQuad_A. ppgWriteQuadOnly2 is 0xF23F6 size 0x5B and copies
 * corners 0 and 3 through ps2SeqsRenderQuad_A2. ppgWriteQuadWithST_A is 0xF31D3
 * size 0x28. ppgWriteQuadWithST_A2 is 0xF31FB size 0x28.
 * ppgWriteQuadWithST_B is 0xF3223 size 0x94. ppgWriteQuadWithST_B2 is
 * 0xF32B7 size 0x94. hanPal is the word at 0x7A8084 and hanTex is the
 * word at 0x7A8086. ppgWriteQuadOnly, ppgWriteQuadOnly2,
 * ppgWriteQuadWithST_B, and ppgWriteQuadWithST_B2 are scanned starts.
 * The checks, the three release functions, and the two A writers are
 * interior.
 * ppg_w is 0x7A8080. cur is +0, hanPal is +4, and the heap object is +8.
 * The 1024 s16 conversion values sit at 0x7968B0. The stack cookie is 0x43CF74.
 * The unit is 16. A null address stops. mmHeapInitialize ignores the name.
 * The renew lock flag is 2. The copy is an inlined memcpy of srcSize bytes.
 * 0x16993 and 0x16C67 are flLockTexture and flUnlockTexture, named from the
 * PS2 calls they replace here.
 * ppgDecompress is 0xF2451 size 0x5D and is a scanned start. Case 1 calls decLZ77withSizeCheck and
 * multiplies by dstSize. Case 2 calls zlib_Decompress. The default copies
 * dstSize bytes when the pointers differ and returns srcSize.
 * ppgSetupCmpChunk is 0xF24AE size 0x116 and is a scanned start. pEND is
 * 0x70454E44 and pCMP is 0x70434D50. The failure string is 0x2B3F58.
 * ppgChangeDataEndian is 0xF25C4 size 0xB5 and is a scanned start.
 * Depth 1 returns. Depth 0 swaps nibbles when excdot
 * is set. Any other depth swaps 32-bit words when col4 is set and
 * dendL is clear, and 16-bit words otherwise.
 * ppgSetupTexChunk_1st is 0xF2B0A size 0x1D8. ppgSetupTexChunk_1st_Accnum
 * is 0xF2CE2 size 0x1B. ppgSetupTexChunk_2nd is 0xF2CFD size 0x7C.
 * ppgSetupContextFromPPL is 0xF2D79 size 0x10A. ppgSetupContextFromPPG
 * is 0xF2E83 size 0x18F. ppgSetupTexChunk_1st is a scanned start. The
 * other four are interior.
 * pTEX is 0x70544558. pplColorModeWidth is the four bytes at 0x2B3F38.
 * Pixel depth 0 stores desc 0x14 when bit 0x20 is set and 0x24 otherwise.
 * ppgPullDecBuff is 0xF2359 size 0x5 and ppgPushDecBuff is 0xF235E size
 * 0x5. Both are interior tail jumps, to ppgMallocR and ppgFree.
 * ppgSetupPalChunk is 0xF39EE size 0x2EE. ppgSetupPalChunkDir is 0xF3CDC
 * size 0x149. ppgSetupTexChunkSeqs is 0xF3E25 size 0x15D.
 * ppgSetupTexChunk_3rd is 0xF3F82 size 0x158. ppgReleasePaletteHandle is
 * 0xF40DA size 0x90. ppgReleaseTextureHandle is 0xF416A size 0xB1.
 * All six are interior. pPAL is 0x7050414C. The formARGB tests compare
 * the raw word with 0x8888. A palette decompress or create failure
 * pushes the buffer, and the error handler pushes it again. Tex chunk
 * 3rd does not test desc bit 0x20. The seq loop stores ci_flag in
 * b16[1], replacing the 0x8000 written at init.
 * ppgRenewDotDataSeqs is 0xF2679 size 0x273 and is a scanned start.
 * A null texture reads
 * ppg_w.cur->tex. The index is gix minus ixNum1st. A live handle sets
 * bit 0x2000, then copies one block through dctex_linear at 0x7968B0.
 * Cases 0x40, 0x100, and 0x400 copy bytes. Cases 0x80, 0x200, and 0x800
 * copy words. The word destination is a u16 pointer plus srcSize * ix
 * plus twice the code offset. Cases 0x400 and 0x800 walk the table as
 * u16 values. 0xF42A6 is xb_TsbCommand1.
 * 0x16E46, 0x16F4F, 0x16867, and 0x1693D are flCreatePaletteHandle,
 * flReleasePaletteHandle, flCreateTextureHandle, and flReleaseTextureHandle.
 * ppgWriteQuadUseTrans is 0xF334B size 0x6A3 and is interior. A null list still falls
 * through to ppgWriteQuadWithST_A2. The no-trans path reads the texture
 * size through xb_GetTextureHandleInfo and insets s and t by 0.02 or 0.06. Flip 2
 * stores that s inset in both s coordinates. The trans path insets by
 * 0.02 or 0.06 over 16 times the sub-quad size, uses height for a
 * vertical flip, and stores pos[0].z in both quad z values. Draws go
 * through flSetRenderState, ps2SeqsRenderQuadInit_A, ps2SeqsRenderQuad_Ax, and ps2SeqsRenderQuadEnd.
 * 0x1667D, 0x14D2F, 0xF4753, 0xF4795, and 0xF45CC are xb_GetTextureHandleInfo,
 * flSetRenderState, ps2SeqsRenderQuadInit_A, ps2SeqsRenderQuad_Ax, and
 * ps2SeqsRenderQuadEnd.
 */

#include "types.h"

#include <stddef.h>
#include <string.h>

typedef struct {
    u8 *memHead;
    s32 memSize;
    u32 ownNumber;
    s32 ownUnit;
    s32 remainder;
    s32 remainderMin;
    void *cell_1st;
    void *cell_fin;
    u8 *oriHead;
    s32 oriSize;
    s32 debIndex;
} MEMMAN_OBJ;

typedef struct {
    s8 be;
    u8 c_mode;
    u16 total;
    u16 *handle;
    s32 ixNum1st;
    u8 *srcAdrs;
    u32 srcSize;
} Palette;

typedef union {
    u32 b32;
    u16 b16[2];
    u8 b8[4];
} TextureHandle;

typedef struct {
    s8 be;
    u8 flags;
    s16 arCnt;
    s16 arInit;
    u16 total;
    TextureHandle *handle;
    s32 ixNum1st;
    u16 textures;
    u16 accnum;
    u32 *offset;
    u8 *srcAdrs;
    u32 srcSize;
} Texture;

typedef struct {
    Texture *tex;
    Palette *pal;
} PPGDataList;

typedef struct {
    PPGDataList *cur;
    u16 hanPal;
    u16 hanTex;
    MEMMAN_OBJ mm;
} PPG_W;

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
    s32 bitdepth;
    PixelFormat pixelformat;
} plContext;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 s;
    f32 t;
} TexCoord;

typedef struct {
    Vec3 v;
    TexCoord t;
} Vertex;

typedef struct {
    Vec3 v[4];
    TexCoord t[4];
    u32 texCode;
} Sprite;

typedef struct {
    u32 magic;
    u32 fileSize;
    u16 id;
    u8 compress;
    u8 free;
    u32 expSize;
} PPXFileHeader;

typedef struct {
    u32 magic;
    u32 fileSize;
    u8 width;
    u8 height;
    u8 compress;
    u8 pixel;
    u16 formARGB;
    u16 transNums;
} PPGFileHeader;

typedef struct {
    u32 magic;
    u32 fileSize;
    u16 free;
    u8 compress;
    u8 c_mode;
    u16 formARGB;
    u16 palettes;
} PPLFileHeader;

extern s16 dctex_linear[0x400];

#if defined(__i386__)
_Static_assert(sizeof(MEMMAN_OBJ) == 0x2C, "MEMMAN_OBJ");
_Static_assert(sizeof(Palette) == 0x14, "Palette");
_Static_assert(offsetof(Palette, total) == 2, "total");
_Static_assert(offsetof(Palette, handle) == 4, "handle");
_Static_assert(offsetof(Palette, ixNum1st) == 8, "pal ix");
_Static_assert(sizeof(TextureHandle) == 4, "TextureHandle");
_Static_assert(sizeof(Texture) == 0x20, "Texture");
_Static_assert(offsetof(Texture, total) == 6, "tex total");
_Static_assert(offsetof(Texture, handle) == 8, "tex handle");
_Static_assert(offsetof(Texture, ixNum1st) == 0xC, "tex ix");
_Static_assert(offsetof(Texture, textures) == 0x10, "textures");
_Static_assert(offsetof(Texture, offset) == 0x14, "offset");
_Static_assert(offsetof(Texture, srcAdrs) == 0x18, "srcAdrs");
_Static_assert(offsetof(Texture, srcSize) == 0x1C, "srcSize");
_Static_assert(offsetof(Palette, srcAdrs) == 0xC, "pal src");
_Static_assert(offsetof(Palette, srcSize) == 0x10, "pal size");
_Static_assert(sizeof(Vertex) == 0x14, "Vertex");
_Static_assert(sizeof(Sprite) == 0x54, "Sprite");
_Static_assert(sizeof(PPXFileHeader) == 0x10, "PPX");
_Static_assert(offsetof(PPXFileHeader, compress) == 0xA, "compress");
_Static_assert(offsetof(PPXFileHeader, expSize) == 0xC, "expSize");
_Static_assert(sizeof(PixelFormat) == 0x30, "PixelFormat");
_Static_assert(sizeof(plContext) == 0x48, "plContext");
_Static_assert(offsetof(plContext, ptr) == 0x10, "ptr");
_Static_assert(offsetof(plContext, pixelformat) == 0x18, "pixelformat");
_Static_assert(offsetof(PixelFormat, am) == 0x2C, "am");
_Static_assert(sizeof(PPGFileHeader) == 0x10, "PPG");
_Static_assert(offsetof(PPGFileHeader, width) == 8, "width");
_Static_assert(offsetof(PPGFileHeader, height) == 9, "height");
_Static_assert(offsetof(PPGFileHeader, pixel) == 0xB, "pixel");
_Static_assert(offsetof(PPGFileHeader, formARGB) == 0xC, "formARGB");
_Static_assert(sizeof(PPLFileHeader) == 0x10, "PPL");
_Static_assert(offsetof(PPLFileHeader, c_mode) == 0xB, "c_mode");
_Static_assert(offsetof(PPLFileHeader, formARGB) == 0xC, "ppl form");
_Static_assert(offsetof(Texture, accnum) == 0x12, "accnum");
_Static_assert(offsetof(PPG_W, hanPal) == 4, "hanPal");
_Static_assert(offsetof(PPG_W, hanTex) == 6, "hanTex");
_Static_assert(offsetof(PPG_W, mm) == 8, "mm");
_Static_assert(sizeof(dctex_linear) == 0x800, "dctex_linear");
#endif

extern PPG_W ppg_w;

extern void flSetRenderState(s32 kind, u32 texCode);
extern void ps2SeqsRenderQuadInit_A(void);
extern void ps2SeqsRenderQuadEnd(void);
extern void ps2SeqsRenderQuad_Ax(void *quad);
extern void xb_GetTextureHandleInfo(void *dst, u32 handle);
extern void ps2SeqsRenderQuad_A2(Sprite *prm, u32 col);
extern void ps2SeqsRenderQuad_A(Sprite *prm, u32 col);

extern void mmHeapInitialize(MEMMAN_OBJ *mobj, void *adrs, s32 size, s32 unit, const char *name);
extern void *mmAlloc(MEMMAN_OBJ *mobj, s32 size, s32 flag);
extern void mmFree(MEMMAN_OBJ *mobj, void *adrs);
extern void flLockTexture(s32 rect, u32 handle, plContext *bits, s32 flag);
extern void flUnlockTexture(u32 handle);
extern s32 decLZ77withSizeCheck(void *src, void *dst, s32 size);
extern s32 zlib_Decompress(void *src, s32 srcSize, void *dst, s32 dstSize);
extern void flLogOut(const char *text);
extern const u8 pplColorModeWidth[4];
extern u16 flCreatePaletteHandle(plContext *bits, s32 flag);
extern void flReleasePaletteHandle(u32 handle);
extern u16 flCreateTextureHandle(plContext *bits, u32 attribute);
extern void flReleaseTextureHandle(u32 handle);

void ppg_Initialize(void *lcmAdrs, s32 lcmSize) {
    if (lcmAdrs == 0) {
        for (;;) {
        }
    }

    mmHeapInitialize(&ppg_w.mm, lcmAdrs, lcmSize, 16, "- for PPG -");
}

void *ppgMallocF(s32 size) {
    return mmAlloc(&ppg_w.mm, size, 0);
}

void *ppgMallocR(s32 size) {
    return mmAlloc(&ppg_w.mm, size, 1);
}

void ppgFree(void *adrs) {
    mmFree(&ppg_w.mm, adrs);
}

void *ppgPullDecBuff(s32 size) {
    return ppgMallocR(size);
}

void ppgPushDecBuff(void *adrs) {
    ppgFree(adrs);
}

void ppgSetupCurrentDataList(PPGDataList *dlist) {
    ppg_w.cur = dlist;
}

void ppgSetupCurrentPaletteNumber(Palette *pal, s32 num) {
    if (pal == 0) {
        pal = ppg_w.cur->pal;

        if (pal == 0) {
            return;
        }
    }

    if (num < pal->total) {
        ppg_w.hanPal = pal->handle[num];
    }
}

s32 ppgRenewTexChunkSeqs(Texture *tch) {
    plContext bits;
    s32 i;

    if (tch == 0) {
        tch = ppg_w.cur->tex;

        if (tch == 0) {
            return 0;
        }
    }

    if (tch->be == 0) {
        return 0;
    }

    for (i = 0; i < tch->total; i++) {
        if ((tch->handle[i].b16[1] & 0x2000) != 0) {
            tch->handle[i].b16[1] &= 0xDFFF;
            flLockTexture(0, tch->handle[i].b16[0], &bits, 2);
            memcpy(bits.ptr, tch->srcAdrs + (tch->srcSize * (u32)i), (size_t)tch->srcSize);
            flUnlockTexture(tch->handle[i].b16[0]);
        }
    }

    return 1;
}

#define CODE_0(val) ((((val) & 0xF0) << 8) + (((val) & 0xF) << 4))
#define CODE_1(val) ((((val) & 0x38) << 0xA) + (((val) & 7) << 5))

void ppgRenewDotDataSeqs(Texture *tch, u32 gix, u32 *srcRam, u32 code, u32 size) {
    s32 ix;
    s32 i;
    s32 j;
    u16 *dstRam16;
    u16 *srcRam16;
    u16 *tix;
    u8 *dstRam8;
    u8 *srcRam8;

    if (tch == 0) {
        tch = ppg_w.cur->tex;
    }

    if (tch->be == 0) {
        return;
    }

    ix = (s32)gix - tch->ixNum1st;

    if (ix < 0 || ix >= tch->total) {
        return;
    }

    if (tch->handle[ix].b16[0] == 0) {
        return;
    }

    tch->handle[ix].b16[1] |= 0x2000;

    switch (size) {
    case 0x40:
        srcRam8 = (u8 *)srcRam;
        dstRam8 = tch->srcAdrs + (tch->srcSize * (u32)ix) + CODE_0(code);

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                *dstRam8++ = srcRam8[dctex_linear[j + (i << 5)]];
            }

            dstRam8 += 0xF8;
        }

        break;

    case 0x100:
        srcRam8 = (u8 *)srcRam;
        dstRam8 = tch->srcAdrs + (tch->srcSize * (u32)ix) + CODE_0(code);

        for (i = 0; i < 0x10; i++) {
            for (j = 0; j < 0x10; j++) {
                *dstRam8++ = srcRam8[dctex_linear[j + (i << 5)]];
            }

            dstRam8 += 0xF0;
        }

        break;

    case 0x400:
        srcRam8 = (u8 *)srcRam;
        dstRam8 = tch->srcAdrs + (tch->srcSize * (u32)ix) + CODE_1(code);
        tix = (u16 *)dctex_linear;

        for (i = 0; i < 0x20; i++) {
            for (j = 0; j < 0x20; j++) {
                *dstRam8++ = srcRam8[*tix++];
            }

            dstRam8 += 0xE0;
        }

        break;

    case 0x80:
        srcRam16 = (u16 *)srcRam;
        dstRam16 = (u16 *)tch->srcAdrs + ((tch->srcSize * (u32)ix) + (CODE_0(code) * 2));

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                *dstRam16++ = srcRam16[dctex_linear[j + (i << 5)]];
            }

            dstRam16 += 0xF8;
        }

        break;

    case 0x200:
        srcRam16 = (u16 *)srcRam;
        dstRam16 = (u16 *)tch->srcAdrs + ((tch->srcSize * (u32)ix) + (CODE_0(code) * 2));

        for (i = 0; i < 0x10; i++) {
            for (j = 0; j < 0x10; j++) {
                *dstRam16++ = srcRam16[dctex_linear[j + (i << 5)]];
            }

            dstRam16 += 0xF0;
        }

        break;

    case 0x800:
        srcRam16 = (u16 *)srcRam;
        dstRam16 = (u16 *)tch->srcAdrs + ((tch->srcSize * (u32)ix) + (CODE_1(code) * 2));
        tix = (u16 *)dctex_linear;

        for (i = 0; i < 0x20; i++) {
            for (j = 0; j < 0x20; j++) {
                *dstRam16++ = srcRam16[*tix++];
            }

            dstRam16 += 0xE0;
        }

        break;
    }
}

void ppgMakeConvTableTexDC(void) {
    s16 seed[32] = {
        0x0000, 0x0002, 0x0008, 0x000A, 0x0020, 0x0022, 0x0028, 0x002A, 0x0080, 0x0082, 0x0088,
        0x008A, 0x00A0, 0x00A2, 0x00A8, 0x00AA, 0x0200, 0x0202, 0x0208, 0x020A, 0x0220, 0x0222,
        0x0228, 0x022A, 0x0280, 0x0282, 0x0288, 0x028A, 0x02A0, 0x02A2, 0x02A8, 0x02AA,
    };
    s16 seedAdd[16] = {
        0x0000, 0x0004, 0x0010, 0x0014, 0x0040, 0x0044, 0x0050, 0x0054,
        0x0100, 0x0104, 0x0110, 0x0114, 0x0140, 0x0144, 0x0150, 0x0154,
    };
    s32 i;
    s32 j;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 32; j++) {
            dctex_linear[j + (i * 64)] = (s16)(seed[j] + seedAdd[i]);
        }

        for (j = 0; j < 32; j++) {
            dctex_linear[j + (i * 64 + 32)] = (s16)(dctex_linear[j + (i * 64)] + 1);
        }
    }
}

s32 ppgGetUsingTextureHandle(Texture *tch, s32 ixNums) {
    if (tch == 0) {
        tch = ppg_w.cur->tex;

        if (tch == 0) {
            return 0;
        }
    }

    if (tch->be == 0) {
        return 0;
    }

    if (tch->handle == 0) {
        return 0;
    }

    ixNums -= tch->ixNum1st;

    if (ixNums < 0 || ixNums >= tch->textures) {
        return 0;
    }

    return tch->handle[ixNums].b16[0];
}

s32 ppgGetUsingPaletteHandle(Palette *pch, s32 ixNums) {
    if (pch == 0) {
        pch = ppg_w.cur->pal;

        if (pch == 0) {
            return 0;
        }
    }

    if (pch->be == 0) {
        return 0;
    }

    if (pch->handle == 0) {
        return 0;
    }

    ixNums -= pch->ixNum1st;

    if (ixNums < 0 || ixNums >= pch->total) {
        return 0;
    }

    return pch->handle[ixNums];
}

s32 ppgCheckTextureNumber(Texture *tex, s32 num) {
    u16 ix;

    if (tex == 0) {
        tex = ppg_w.cur->tex;

        if (tex == 0) {
            return 0;
        }
    }

    if (tex->be == 0) {
        return 0;
    }

    ix = (u16)((u16)num - (u16)tex->ixNum1st);

    if (ix >= tex->total) {
        return 0;
    }

    if (tex->handle[ix].b16[0] != 0) {
        return 1;
    }

    return 0;
}

s32 ppgCheckTextureDataBe(Texture *tch) {
    s32 i;

    if (tch->be == 0) {
        return 0;
    }

    for (i = 0; i < tch->total; i++) {
        if (tch->handle[i].b16[0] != 0) {
            break;
        }
    }

    if (i == tch->total) {
        if (tch->handle != 0) {
            ppgFree(tch->handle);
        }

        if (tch->offset != 0) {
            ppgFree(tch->offset);
        }

        tch->handle = 0;
        tch->offset = 0;
        tch->be = 0;
    }

    return tch->be;
}

s32 ppgCheckPaletteDataBe(Palette *pch) {
    s32 i;

    if (pch->be == 0) {
        return 0;
    }

    for (i = 0; i < pch->total; i++) {
        if (pch->handle[i] != 0) {
            break;
        }
    }

    if (i == pch->total) {
        if (pch->handle != 0) {
            ppgFree(pch->handle);
        }

        pch->handle = 0;
        pch->be = 0;
    }

    return pch->be;
}

void ppgTexSrcDataReleased(Texture *tex) {
    if (tex == 0) {
        tex = ppg_w.cur->tex;
    }

    tex->srcAdrs = 0;
    tex->srcSize = 0;
    ppgCheckTextureDataBe(tex);
}

void ppgPalSrcDataReleased(Palette *pal) {
    if (pal == 0) {
        pal = ppg_w.cur->pal;
    }

    pal->srcAdrs = 0;
    pal->srcSize = 0;
    ppgCheckPaletteDataBe(pal);
}

void ppgSourceDataReleased(PPGDataList *dlist) {
    if (dlist == 0) {
        dlist = ppg_w.cur;
    }

    if (dlist->tex != 0) {
        ppgTexSrcDataReleased(dlist->tex);
    }

    if (dlist->pal != 0) {
        ppgPalSrcDataReleased(dlist->pal);
    }
}

void ppgWriteQuadOnly(Vertex *pos, u32 col, u32 texCode) {
    Sprite prm;
    s32 i;

    flSetRenderState(4, texCode);
    ps2SeqsRenderQuadInit_A();

    for (i = 0; i < 4; i++) {
        prm.v[i] = pos[i].v;
        prm.t[i] = pos[i].t;
    }

    ps2SeqsRenderQuad_A(&prm, col);
    ps2SeqsRenderQuadEnd();
}

void ppgWriteQuadOnly2(Vertex *pos, u32 col, u32 texCode) {
    Sprite prm;

    flSetRenderState(4, texCode);
    ps2SeqsRenderQuadInit_A();
    prm.v[0] = pos[0].v;
    prm.t[0] = pos[0].t;
    prm.v[3] = pos[3].v;
    prm.t[3] = pos[3].t;
    ps2SeqsRenderQuad_A2(&prm, col);
    ps2SeqsRenderQuadEnd();
}

s32 ppgWriteQuadWithST_A(Vertex *pos, u32 col) {
    ppgWriteQuadOnly(pos, col, (u32)ppg_w.hanTex | ((u32)ppg_w.hanPal << 16));
    return 1;
}

s32 ppgWriteQuadWithST_A2(Vertex *pos, u32 col) {
    ppgWriteQuadOnly2(pos, col, (u32)ppg_w.hanTex | ((u32)ppg_w.hanPal << 16));
    return 1;
}

s32 ppgWriteQuadWithST_B(Vertex *pos, u32 col, PPGDataList *tb, s32 tix, s32 cix) {
    u16 texhan;
    u16 palhan;

    palhan = 0;

    if (tb == 0) {
        tb = ppg_w.cur;

        if (tb == 0) {
            return ppgWriteQuadWithST_A(pos, col);
        }
    }

    if (tix < 0) {
        texhan = ppg_w.hanTex;
    } else {
        texhan = tb->tex->handle[tix - tb->tex->ixNum1st].b16[0];

        if (texhan == 0) {
            return 0;
        }
    }

    if ((tb->tex->handle[tix - tb->tex->ixNum1st].b16[1] & 0x4000) != 0) {
        if (cix < 0) {
            palhan = ppg_w.hanPal;
        } else {
            palhan = tb->pal->handle[cix];
        }
    }

    ppgWriteQuadOnly(pos, col, (u32)texhan | ((u32)palhan << 16));
    return 1;
}

s32 ppgWriteQuadWithST_B2(Vertex *pos, u32 col, PPGDataList *tb, s32 tix, s32 cix) {
    u16 texhan;
    u16 palhan;

    palhan = 0;

    if (tb == 0) {
        tb = ppg_w.cur;

        if (tb == 0) {
            return ppgWriteQuadWithST_A2(pos, col);
        }
    }

    if (tix < 0) {
        texhan = ppg_w.hanTex;
    } else {
        texhan = tb->tex->handle[tix - tb->tex->ixNum1st].b16[0];

        if (texhan == 0) {
            return 0;
        }
    }

    if ((tb->tex->handle[tix - tb->tex->ixNum1st].b16[1] & 0x4000) != 0) {
        if (cix < 0) {
            palhan = ppg_w.hanPal;
        } else {
            palhan = tb->pal->handle[cix];
        }
    }

    ppgWriteQuadOnly2(pos, col, (u32)texhan | ((u32)palhan << 16));
    return 1;
}

static u32 revert_u32(u32 val) {
    return ((val & 0xFFu) << 24) | ((val & 0xFF00u) << 8) | ((val >> 8) & 0xFF00u) | (val >> 24);
}

static u16 revert_u16(u16 val) {
    return (u16)((val >> 8) | ((val & 0xFFu) << 8));
}

s32 ppgWriteQuadUseTrans(Vertex *pos, u32 col, PPGDataList *tb, s32 tix, s32 cix, s32 flip, s32 pal) {
    struct {
        f32 x0;
        f32 y0;
        f32 z0;
        f32 x3;
        f32 y3;
        f32 z3;
        f32 s0;
        f32 t0;
        f32 s3;
        f32 t3;
        u32 col;
    } quad;
    s32 info[0x12];
    PPGFileHeader *ppg;
    TextureHandle *ent;
    u16 *phan;
    u16 palhan;
    u16 texhan;
    u16 ix_ofs;
    u16 transTotal;
    u8 *tran;
    u32 ppgw;
    u32 ppgh;
    u32 sx;
    u32 sy;
    u32 xs;
    u32 ys;
    u32 iPoint;
    u32 cofs;
    f32 tw;
    f32 th;
    f32 pxs;
    f32 pys;
    f32 s_add;
    f32 t_add;
    f32 inv_w;
    f32 inv_h;
    f32 inv_w16;
    f32 inv_h16;
    f32 x0;
    f32 x3;
    f32 y0;
    f32 y3;
    f32 sadd;
    f32 tadd;

    if ((pos[0].v.x >= 384.0f) || (pos[3].v.x < 0.0f) || (pos[0].v.y >= 224.0f) || (pos[3].v.y < 0.0f)) {
        return 0;
    }

    if (tb == 0) {
        tb = ppg_w.cur;

        if (tb == 0) {
            return ppgWriteQuadWithST_A2(pos, col);
        }
    }

    ent = &tb->tex->handle[tix - tb->tex->ixNum1st];
    texhan = ent->b16[0];
    ix_ofs = ent->b16[1];

    if (texhan == 0) {
        return 0;
    }

    palhan = 0;
    phan = 0;

    if ((ix_ofs & 0x4000) != 0) {
        phan = tb->pal->handle;

        if (phan == 0) {
            return 0;
        }
    }

    if (tb->tex->srcAdrs != 0) {
        ppg = (PPGFileHeader *)(tb->tex->srcAdrs + tb->tex->offset[ix_ofs & 0xFFF]);
        transTotal = revert_u16(ppg->transNums);

        if (transTotal != 0) {
            tran = (u8 *)(ppg + 1);
            ppgw = ppg->width;
            ppgh = ppg->height;
            pxs = pos[3].v.x - pos[0].v.x;
            pys = pos[3].v.y - pos[0].v.y;
            inv_w = 1.0f / (f32)ppgw;
            inv_h = 1.0f / (f32)ppgh;
            inv_w16 = 1.0f / (f32)(ppgw * 16);
            inv_h16 = 1.0f / (f32)(ppgh * 16);
            quad.col = col;
            ps2SeqsRenderQuadInit_A();

            while (transTotal != 0) {
                if ((ix_ofs & 0x4000) != 0) {
                    palhan = phan[*tran + pal];
                }

                tran++;
                iPoint = *tran++;
                cofs = *tran++;
                xs = (cofs >> 4) + 1;
                ys = (cofs & 0xF) + 1;
                sx = iPoint % ppgw;
                sy = iPoint / ppgw;

                if ((flip & 1) != 0) {
                    x3 = pos[0].v.x + (f32)(ppgw - sx) * pxs * inv_w;
                    x0 = pos[0].v.x + (f32)(ppgw - (sx + xs)) * pxs * inv_w;
                } else {
                    x0 = pos[0].v.x + (f32)sx * pxs * inv_w;
                    x3 = pos[0].v.x + (f32)(sx + xs) * pxs * inv_w;
                }

                if ((flip & 2) != 0) {
                    y3 = pos[0].v.y + (f32)(ppgh - sy) * pys * inv_h;
                    y0 = pos[0].v.y + (f32)(ppgh - (sy + ys)) * pys * inv_h;
                } else {
                    y0 = pos[0].v.y + (f32)sy * pys * inv_h;
                    y3 = pos[0].v.y + (f32)(sy + ys) * pys * inv_h;
                }

                if ((x0 < 384.0f) && (x3 >= 0.0f) && (y0 < 224.0f) && (y3 >= 0.0f)) {
                    flSetRenderState(4, (u32)texhan | ((u32)palhan << 16));
                    sadd = ((x3 - x0) / (f32)(xs * 16) > 1.0f ? 0.02f : 0.06f) * inv_w16;
                    tadd = ((y3 - y0) / (f32)(ys * 16) > 1.0f ? 0.02f : 0.06f) * inv_h16;

                    if ((flip & 1) != 0) {
                        quad.s3 = (f32)sx * inv_w - sadd;
                        quad.s0 = (f32)(sx + xs) * inv_w - sadd;
                    } else {
                        quad.s0 = (f32)sx * inv_w + sadd;
                        quad.s3 = (f32)(sx + xs) * inv_w + sadd;
                    }

                    if ((flip & 2) != 0) {
                        quad.t3 = (f32)sy * inv_h - tadd;
                        quad.t0 = (f32)(sy + ys) * inv_h - tadd;
                    } else {
                        quad.t0 = (f32)sy * inv_h + tadd;
                        quad.t3 = (f32)(sy + ys) * inv_h + tadd;
                    }

                    quad.x0 = x0;
                    quad.y0 = y0;
                    quad.x3 = x3;
                    quad.y3 = y3;
                    quad.z0 = pos[0].v.z;
                    quad.z3 = pos[0].v.z;
                    ps2SeqsRenderQuad_Ax(&quad);
                }

                transTotal--;
            }

            ps2SeqsRenderQuadEnd();
            return 1;
        }
    }

    if ((ix_ofs & 0x4000) != 0) {
        if (cix < 0) {
            palhan = ppg_w.hanPal;
        } else {
            palhan = phan[cix];
        }
    }

    xb_GetTextureHandleInfo(info, texhan);
    tw = (f32)info[1];
    th = (f32)info[2];
    s_add = ((pos[3].v.x - pos[0].v.x) / tw > 1.0f ? 0.02f : 0.06f) / tw;
    t_add = ((pos[3].v.y - pos[0].v.y) / th > 1.0f ? 0.02f : 0.06f) / th;

    switch (flip) {
    case 0:
        pos[0].t.s = s_add;
        pos[0].t.t = t_add;
        pos[3].t.t = 1.0f + t_add;
        pos[3].t.s = 1.0f + s_add;
        break;

    case 1:
        pos[3].t.s = -s_add;
        pos[0].t.t = t_add;
        pos[0].t.s = 1.0f - s_add;
        pos[3].t.t = 1.0f + t_add;
        break;

    case 2:
        pos[0].t.s = s_add;
        pos[3].t.t = -t_add;
        pos[0].t.t = 1.0f - t_add;
        pos[3].t.s = s_add;
        break;

    default:
        pos[0].t.t = 1.0f - t_add;
        pos[0].t.s = 1.0f - s_add;
        pos[3].t.s = -s_add;
        pos[3].t.t = -t_add;
        break;
    }

    quad.x0 = pos[0].v.x;
    quad.y0 = pos[0].v.y;
    quad.z0 = pos[0].v.z;
    quad.x3 = pos[3].v.x;
    quad.y3 = pos[3].v.y;
    quad.z3 = pos[3].v.z;
    quad.s0 = pos[0].t.s;
    quad.t0 = pos[0].t.t;
    quad.s3 = pos[3].t.s;
    quad.t3 = pos[3].t.t;
    quad.col = col;
    flSetRenderState(4, (u32)texhan | ((u32)palhan << 16));
    ps2SeqsRenderQuadInit_A();
    ps2SeqsRenderQuad_Ax(&quad);
    ps2SeqsRenderQuadEnd();
    return 1;
}

s32 ppgDecompress(s32 koCmpr, void *srcAdrs, s32 srcSize, void *dstAdrs, s32 dstSize) {
    u8 *src;
    u8 *dst;
    s32 i;
    s32 rnum;

    rnum = 0;

    switch (koCmpr) {
    default:
        if (srcAdrs != dstAdrs) {
            src = srcAdrs;
            dst = dstAdrs;

            for (i = 0; i < dstSize; i++) {
                *dst++ = *src++;
            }
        }

        rnum = srcSize;
        break;

    case 1:
        rnum = decLZ77withSizeCheck(srcAdrs, dstAdrs, dstSize);
        rnum *= dstSize;
        break;

    case 2:
        rnum = zlib_Decompress(srcAdrs, srcSize, dstAdrs, dstSize);
        break;
    }

    return rnum;
}

s32 ppgSetupCmpChunk(u8 *srcAdrs, s32 num, u8 *dstAdrs) {
    PPXFileHeader *ppx;
    u8 *cmpAdrs;
    s32 cmpSize;
    s32 mltSize;
    s32 koCmpr;
    s32 ofs;

    ofs = 0;

    for (;;) {
        ppx = (PPXFileHeader *)(srcAdrs + ofs);

        if (0x70454E44u == revert_u32(ppx->magic)) {
            return -1;
        }

        if (0x70434D50u != revert_u32(ppx->magic)) {
            ofs += (s32)((revert_u32(ppx->fileSize) + 3) & ~3u);
            continue;
        }

        if (num > 0) {
            num -= 1;
            ofs += (s32)((revert_u32(ppx->fileSize) + 3) & ~3u);
            continue;
        }

        break;
    }

    mltSize = (s32)revert_u32(ppx->expSize);
    cmpSize = (s32)revert_u32(ppx->fileSize) - 0x10;
    cmpAdrs = (u8 *)ppx + 0x10;
    koCmpr = ppx->compress & 3;

    if (mltSize != ppgDecompress(koCmpr, cmpAdrs, cmpSize, dstAdrs, mltSize)) {
        flLogOut("圧縮データの解凍に失敗しました。\n");

        for (;;) {
        }
    }

    return 1;
}

void ppgChangeDataEndian(u8 *adrs, s32 size, s32 dendL, s32 col4, s32 depth, s32 excdot) {
    s32 i;
    u32 *c4;
    u16 *c2;

    if (depth == 1) {
        return;
    }

    if (depth != 0) {
        if (dendL == 0) {
            if (col4 != 0) {
                c4 = (u32 *)adrs;

                for (i = 0; i < size / 4; i++) {
                    c4[i] = revert_u32(c4[i]);
                }
            } else {
                c2 = (u16 *)adrs;

                for (i = 0; i < size / 2; i++) {
                    c2[i] = (u16)((c2[i] >> 8) | ((c2[i] & 0xFF) << 8));
                }
            }
        }

        return;
    }

    if (excdot != 0) {
        for (i = 0; i < size; i++) {
            adrs[i] = (u8)(((adrs[i] << 4) & 0xF0) | ((adrs[i] >> 4) & 0xF));
        }
    }
}

s32 ppgSetupTexChunk_1st(Texture *tch, u8 *adrs, s32 size, s32 ixNum1st, s32 ixNums, s32 ar, s32 arcnt) {
    PPGFileHeader *ppg;
    s32 i;
    s32 ofs;

    if (tch == 0) {
        tch = ppg_w.cur->tex;
    }

    if (tch->be != 0) {
        for (;;) {
        }
    }

    tch->be = 0;
    tch->textures = 0;
    tch->accnum = 0;
    tch->ixNum1st = ixNum1st;
    tch->total = (u16)ixNums;
    tch->flags = (u8)(ar != 0);
    tch->arCnt = 0;
    tch->arInit = (s16)arcnt;
    tch->offset = 0;
    tch->srcAdrs = adrs;
    tch->srcSize = (u32)size;
    tch->handle = ppgMallocF(ixNums * 4);

    if (tch->handle == 0) {
        flLogOut("テクスチャハンドル記憶領域が確保できませんでした。\n");
        goto error_handler;
    }

    for (i = 0; i < ixNums; i++) {
        tch->handle[i].b16[0] = 0;
        tch->handle[i].b16[1] = 0x8000;
    }

    ofs = 0;

    for (;;) {
        ppg = (PPGFileHeader *)(tch->srcAdrs + ofs);

        if (0x70454E44u != revert_u32(ppg->magic)) {
            if (0x70544558u == revert_u32(ppg->magic)) {
                tch->textures += 1;
            }

            ofs += (s32)((revert_u32(ppg->fileSize) + 3) & ~3u);
        } else {
            break;
        }
    }

    if (tch->textures == 0) {
        flLogOut("テクスチャデータが見つかりませんでした。\n");
        goto error_handler;
    }

    tch->offset = ppgMallocF(tch->textures * 4);

    if (tch->offset == 0) {
        flLogOut("テクスチャデータオフセットテーブルの記憶領域が確保できませんでした。\n");
        goto error_handler;
    }

    ofs = 0;

    for (;;) {
        ppg = (PPGFileHeader *)(tch->srcAdrs + ofs);

        if (0x70454E44u != revert_u32(ppg->magic)) {
            if (0x70544558u == revert_u32(ppg->magic)) {
                tch->offset[tch->accnum++] = (u32)ofs;
            }

            ofs += (s32)((revert_u32(ppg->fileSize) + 3) & ~3u);
        } else {
            break;
        }
    }

    tch->accnum = 0;
    tch->be = 1;
    return 1;

error_handler:
    if (tch->handle != 0) {
        ppgFree(tch->handle);
    }

    if (tch->offset != 0) {
        ppgFree(tch->offset);
    }

    tch->handle = 0;
    tch->offset = 0;

    for (;;) {
    }
}

s32 ppgSetupTexChunk_1st_Accnum(Texture *tch, u16 accnum) {
    if (tch == 0) {
        tch = ppg_w.cur->tex;
    }

    tch->accnum = accnum;
    return 0;
}

s32 ppgSetupTexChunk_2nd(Texture *tch, s32 ixNum) {
    PPGFileHeader *ppg;
    TextureHandle *hnof;

    if (tch == 0) {
        tch = ppg_w.cur->tex;
    }

    if (tch->textures <= tch->accnum) {
        flLogOut("ハンドル取得処理がテクスチャチャンクに格納されているデータ数以上に呼ばれました。\n");

        for (;;) {
        }
    }

    hnof = tch->handle + (ixNum - tch->ixNum1st);
    hnof->b16[1] = tch->accnum++;

    if (tch->srcAdrs == 0) {
        flLogOut("テクスチャチャンクデータが既に失われています。\n");

        for (;;) {
        }
    }

    ppg = (PPGFileHeader *)(tch->srcAdrs + tch->offset[hnof->b16[1]]);

    if ((ppg->pixel & 3) <= 1) {
        hnof->b16[1] |= 0x4000;
    }

    return tch->accnum;
}

void ppgSetupContextFromPPL(PPLFileHeader *ppl, plContext *bits) {
    bits->desc = 0;
    bits->width = pplColorModeWidth[ppl->c_mode & 3] < 17 ? 16 : 256;
    bits->height = 1;
    bits->bitdepth = ppl->formARGB != 0x8888 ? 2 : 4;
    bits->pitch = bits->width * bits->bitdepth;
    bits->ptr = 0;

    switch (revert_u16(ppl->formARGB)) {
    case 0x1555:
        bits->pixelformat.rl = 5;
        bits->pixelformat.rs = 0xA;
        bits->pixelformat.rm = 0x1F;
        bits->pixelformat.gl = 5;
        bits->pixelformat.gs = 5;
        bits->pixelformat.gm = 0x1F;
        bits->pixelformat.bl = 5;
        bits->pixelformat.bs = 0;
        bits->pixelformat.bm = 0x1F;
        bits->pixelformat.al = 1;
        bits->pixelformat.as = 0xF;
        bits->pixelformat.am = 1;
        break;

    case 0x565:
        bits->pixelformat.rl = 5;
        bits->pixelformat.rs = 0xB;
        bits->pixelformat.rm = 0x1F;
        bits->pixelformat.gl = 6;
        bits->pixelformat.gs = 5;
        bits->pixelformat.gm = 0x3F;
        bits->pixelformat.bl = 5;
        bits->pixelformat.bs = 0;
        bits->pixelformat.bm = 0x1F;
        bits->pixelformat.al = 0;
        bits->pixelformat.as = 0;
        bits->pixelformat.am = 0;
        break;

    case 0x4444:
        bits->pixelformat.rl = 4;
        bits->pixelformat.rs = 8;
        bits->pixelformat.rm = 0xF;
        bits->pixelformat.gl = 4;
        bits->pixelformat.gs = 4;
        bits->pixelformat.gm = 0xF;
        bits->pixelformat.bl = 4;
        bits->pixelformat.bs = 0;
        bits->pixelformat.bm = 0xF;
        bits->pixelformat.al = 4;
        bits->pixelformat.as = 0xC;
        bits->pixelformat.am = 0xF;
        break;

    default:
        bits->pixelformat.rl = 8;
        bits->pixelformat.rs = 0x10;
        bits->pixelformat.rm = 0xFF;
        bits->pixelformat.gl = 8;
        bits->pixelformat.gs = 8;
        bits->pixelformat.gm = 0xFF;
        bits->pixelformat.bl = 8;
        bits->pixelformat.bs = 0;
        bits->pixelformat.bm = 0xFF;
        bits->pixelformat.al = 8;
        bits->pixelformat.as = 0x18;
        bits->pixelformat.am = 0xFF;
        break;
    }
}

void ppgSetupContextFromPPG(PPGFileHeader *ppg, plContext *bits) {
    bits->desc = 0;
    bits->width = ppg->width * 16;
    bits->height = ppg->height * 16;

    switch (ppg->pixel & 3) {
    case 0:
        if ((ppg->pixel & 0x20) != 0) {
            bits->desc = 0x14;
        } else {
            bits->desc = 0x24;
        }

        bits->bitdepth = 0;
        bits->pitch = bits->width / 2;
        break;

    case 1:
        bits->desc |= 4;
        bits->bitdepth = 1;
        bits->pitch = bits->width;
        break;

    case 2:
        bits->bitdepth = 2;
        bits->pitch = bits->width * 2;
        break;

    default:
        bits->bitdepth = 4;
        bits->pitch = bits->width * 4;
        break;
    }

    switch (revert_u16(ppg->formARGB)) {
    case 0x1555:
        bits->pixelformat.rl = 5;
        bits->pixelformat.rs = 0xA;
        bits->pixelformat.rm = 0x1F;
        bits->pixelformat.gl = 5;
        bits->pixelformat.gs = 5;
        bits->pixelformat.gm = 0x1F;
        bits->pixelformat.bl = 5;
        bits->pixelformat.bs = 0;
        bits->pixelformat.bm = 0x1F;
        bits->pixelformat.al = 1;
        bits->pixelformat.as = 0xF;
        bits->pixelformat.am = 1;
        break;

    case 0x565:
        bits->pixelformat.rl = 5;
        bits->pixelformat.rs = 0xB;
        bits->pixelformat.rm = 0x1F;
        bits->pixelformat.gl = 6;
        bits->pixelformat.gs = 5;
        bits->pixelformat.gm = 0x3F;
        bits->pixelformat.bl = 5;
        bits->pixelformat.bs = 0;
        bits->pixelformat.bm = 0x1F;
        bits->pixelformat.al = 0;
        bits->pixelformat.as = 0;
        bits->pixelformat.am = 0;
        break;

    case 0x4444:
        bits->pixelformat.rl = 4;
        bits->pixelformat.rs = 8;
        bits->pixelformat.rm = 0xF;
        bits->pixelformat.gl = 4;
        bits->pixelformat.gs = 4;
        bits->pixelformat.gm = 0xF;
        bits->pixelformat.bl = 4;
        bits->pixelformat.bs = 0;
        bits->pixelformat.bm = 0xF;
        bits->pixelformat.al = 4;
        bits->pixelformat.as = 0xC;
        bits->pixelformat.am = 0xF;
        break;

    case 0x8888:
        bits->pixelformat.rl = 8;
        bits->pixelformat.rs = 0x10;
        bits->pixelformat.rm = 0xFF;
        bits->pixelformat.gl = 8;
        bits->pixelformat.gs = 8;
        bits->pixelformat.gm = 0xFF;
        bits->pixelformat.bl = 8;
        bits->pixelformat.bs = 0;
        bits->pixelformat.bm = 0xFF;
        bits->pixelformat.al = 8;
        bits->pixelformat.as = 0x18;
        bits->pixelformat.am = 0xFF;
        break;

    default:
        bits->pixelformat.rl = 0;
        bits->pixelformat.rs = 0;
        bits->pixelformat.rm = 0;
        bits->pixelformat.gl = 0;
        bits->pixelformat.gs = 0;
        bits->pixelformat.gm = 0;
        bits->pixelformat.bl = 0;
        bits->pixelformat.bs = 0;
        bits->pixelformat.bm = 0;
        bits->pixelformat.al = 0;
        bits->pixelformat.as = 0;
        bits->pixelformat.am = 0;
        break;
    }
}

s32 ppgSetupPalChunk(Palette *pch, u8 *adrs, s32 size, s32 ixNum1st, s32 num, s32 unused) {
    PPLFileHeader *ppl;
    plContext bits;
    s32 i;
    s32 col_items;
    s32 koCmpr;
    s32 cmpSize;
    s32 mltSize;
    u8 *cmpAdrs;
    void *mltAdrs;
    s32 ofs;

    (void)unused;
    ofs = 0;
    koCmpr = 0;
    mltAdrs = 0;

    if (pch == 0) {
        pch = ppg_w.cur->pal;
    }

    if (pch->be != 0) {
        for (;;) {
        }
    }

    pch->be = 0;
    pch->ixNum1st = ixNum1st;
    pch->srcAdrs = adrs;
    pch->srcSize = (u32)size;
    pch->handle = 0;

    for (;;) {
        ppl = (PPLFileHeader *)(adrs + ofs);

        if (0x70454E44u == revert_u32(ppl->magic)) {
            return -1;
        }

        if (0x7050414Cu != revert_u32(ppl->magic)) {
            ofs += (s32)((revert_u32(ppl->fileSize) + 3) & ~3u);
            continue;
        }

        if (num > 0) {
            num -= 1;
            ofs += (s32)((revert_u32(ppl->fileSize) + 3) & ~3u);
            continue;
        }

        break;
    }

    cmpSize = (s32)revert_u32(ppl->fileSize) - 0x10;
    cmpAdrs = (u8 *)ppl + 0x10;
    pch->c_mode = ppl->c_mode & 3;
    pch->total = revert_u16(ppl->palettes);
    col_items = pplColorModeWidth[pch->c_mode] + 1;
    koCmpr = ppl->compress & 3;
    ppgSetupContextFromPPL(ppl, &bits);
    pch->handle = ppgMallocF(pch->total * 2);

    if (pch->handle != 0) {
        for (i = 0; i < pch->total; i++) {
            pch->handle[i] = 0;
        }

        mltSize = bits.bitdepth * (pch->total * col_items);

        if (koCmpr != 0) {
            mltAdrs = ppgPullDecBuff(mltSize);
        } else {
            mltAdrs = cmpAdrs;
        }

        if (mltAdrs == 0) {
            flLogOut("パレットデータ解凍領域の確保に失敗しました。\n");
            goto error_handler;
        }

        if (mltSize != ppgDecompress(koCmpr, cmpAdrs, cmpSize, mltAdrs, mltSize)) {
            flLogOut("パレットデータの解凍に失敗しました。\n");
            ppgPushDecBuff(mltAdrs);
            goto error_handler;
        }

        ppgChangeDataEndian(mltAdrs, mltSize, ppl->c_mode & 4, ppl->formARGB == 0x8888, bits.bitdepth, 0);

        if (koCmpr == 0) {
            ppl->c_mode |= 4;
        }

        bits.ptr = mltAdrs;

        for (i = 0; i < pch->total; i++) {
            pch->handle[i] = flCreatePaletteHandle(&bits, 0);

            if (pch->handle[i] == 0) {
                flLogOut("パレットハンドルの取得に失敗しました。\n");

                if (koCmpr == 0) {
                    goto error_handler;
                }

                ppgPushDecBuff(mltAdrs);
                goto error_handler;
            }

            bits.ptr = (u8 *)bits.ptr + (col_items * bits.bitdepth);
        }

        if (koCmpr != 0) {
            ppgPushDecBuff(mltAdrs);
        }

        pch->be = 1;
        return 1;
    }

error_handler:
    if (pch->handle != 0) {
        for (i = 0; i < pch->total; i++) {
            if (pch->handle[i] != 0) {
                flReleasePaletteHandle(pch->handle[i]);
            }
        }

        ppgFree(pch->handle);
    }

    if ((koCmpr != 0) && (mltAdrs != 0)) {
        ppgPushDecBuff(mltAdrs);
    }

    pch->handle = 0;

    for (;;) {
    }
}

s32 ppgSetupPalChunkDir(Palette *pch, PPLFileHeader *ppl, u8 *adrs, s32 ixNum1st, s32 unused) {
    plContext bits;
    s32 i;

    (void)unused;

    if (pch == 0) {
        pch = ppg_w.cur->pal;
    }

    if (pch->be != 0) {
        for (;;) {
        }
    }

    pch->be = 0;
    pch->ixNum1st = ixNum1st;
    pch->srcAdrs = 0;
    pch->c_mode = ppl->c_mode & 3;
    ppgSetupContextFromPPL(ppl, &bits);
    pch->srcSize = (u32)(bits.pitch * bits.height);
    pch->total = revert_u16(ppl->palettes);
    pch->handle = ppgMallocF(pch->total * 2);

    if (pch->handle != 0) {
        for (i = 0; i < pch->total; i++) {
            pch->handle[i] = 0;
        }

        ppgChangeDataEndian(adrs, pch->total * bits.pitch * bits.height, ppl->c_mode & 4, ppl->formARGB == 0x8888,
                            bits.bitdepth, 0);
        ppl->c_mode |= 4;

        for (i = 0; i < pch->total; i++) {
            bits.ptr = adrs;
            pch->handle[i] = flCreatePaletteHandle(&bits, 0);

            if (pch->handle[i] == 0) {
                goto error_handler;
            }

            adrs += pch->srcSize;
        }

        pch->be = 1;
        return 1;
    }

error_handler:
    if (pch->handle != 0) {
        for (i = 0; i < pch->total; i++) {
            if (pch->handle[i] != 0) {
                flReleasePaletteHandle(pch->handle[i]);
            }
        }

        ppgFree(pch->handle);
    }

    pch->handle = 0;
    flLogOut("パレットハンドルの取得に失敗しました。( dir )\n");

    for (;;) {
    }
}

s32 ppgSetupTexChunkSeqs(Texture *tch, PPGFileHeader *ppg, u8 *adrs, s32 ixNum1st, s32 ixNums, u32 attribute) {
    plContext bits;
    s32 i;
    s32 ci_flag;
    s32 bytes;

    ci_flag = 0;

    if (tch == 0) {
        tch = ppg_w.cur->tex;
    }

    if (tch->be != 0) {
        for (;;) {
        }
    }

    tch->be = 0;
    tch->textures = (u16)ixNums;
    tch->accnum = (u16)ixNums;
    tch->ixNum1st = ixNum1st;
    tch->total = (u16)ixNums;
    tch->flags = 0x80;
    tch->arCnt = 0;
    tch->arInit = 0;
    tch->handle = 0;
    tch->offset = 0;
    tch->srcAdrs = 0;
    tch->srcSize = 0;
    tch->handle = ppgMallocF(ixNums * 4);

    if (tch->handle == 0) {
        flLogOut("テクスチャハンドル記憶領域が確保できませんでした。\n");

        for (;;) {
        }
    }

    for (i = 0; i < ixNums; i++) {
        tch->handle[i].b16[0] = 0;
        tch->handle[i].b16[1] = 0x8000;
    }

    ppgSetupContextFromPPG(ppg, &bits);
    tch->srcAdrs = adrs;
    tch->srcSize = (u32)(bits.pitch * bits.height);
    bytes = (s32)tch->srcSize * ixNums;

    for (i = 0; i < bytes; i++) {
        adrs[i] = 0;
    }

    if (bits.bitdepth < 2) {
        ci_flag = 0x4000;
    }

    for (i = 0; i < ixNums; i++) {
        bits.ptr = adrs;
        tch->handle[i].b16[1] = (u16)ci_flag;
        tch->handle[i].b16[0] = flCreateTextureHandle(&bits, attribute);

        if (tch->handle[i].b16[0] == 0) {
            goto error_handler;
        }

        adrs += tch->srcSize;
    }

    tch->be = 1;
    return 1;

error_handler:
    for (i = 0; i < ixNums; i++) {
        if (tch->handle[i].b16[0] != 0) {
            flReleaseTextureHandle(tch->handle[i].b16[0]);
        }
    }

    ppgFree(tch->handle);
    tch->handle = 0;
    flLogOut("スプライト用テクスチャハンドルの取得に失敗しました。\n");

    for (;;) {
    }
}

s32 ppgSetupTexChunk_3rd(Texture *tch, s32 ixNum, u32 attribute) {
    plContext bits;
    PPGFileHeader *ppg;
    TextureHandle *hnof;
    s32 koCmpr;
    s32 cmpSize;
    s32 mltSize;
    u8 *cmpAdrs;
    void *mltAdrs;

    if (tch == 0) {
        tch = ppg_w.cur->tex;
    }

    if ((tch->flags & 1) != 0) {
        tch->arCnt = tch->arInit;
    }

    hnof = tch->handle + (ixNum - tch->ixNum1st);

    if (hnof->b16[0] != 0) {
        return 1;
    }

    if (tch->srcAdrs == 0) {
        flLogOut("テクスチャチャンクデータが既に失われています。\n");

        for (;;) {
        }
    }

    ppg = (PPGFileHeader *)(tch->srcAdrs + tch->offset[hnof->b16[1] & 0xFFF]);
    ppgSetupContextFromPPG(ppg, &bits);
    koCmpr = ppg->compress & 3;
    cmpSize = (s32)revert_u16(ppg->transNums) * 3 + 0x10;
    cmpAdrs = (u8 *)ppg + cmpSize;
    cmpSize = (s32)revert_u32(ppg->fileSize) - cmpSize;
    mltSize = bits.pitch * bits.height;
    mltAdrs = ppgPullDecBuff(mltSize);

    if (mltAdrs == 0) {
        flLogOut("テクスチャデータ展開領域が確保できませんでした。\n");

        for (;;) {
        }
    }

    if (mltSize != ppgDecompress(koCmpr, cmpAdrs, cmpSize, mltAdrs, mltSize)) {
        flLogOut("テクスチャデータの解凍に失敗しました。\n");
        ppgPushDecBuff(mltAdrs);

        for (;;) {
        }
    }

    ppgChangeDataEndian(mltAdrs, mltSize, ppg->pixel & 4, ppg->formARGB == 0x8888, bits.bitdepth, 0);
    bits.ptr = mltAdrs;
    hnof->b16[0] = flCreateTextureHandle(&bits, attribute);
    ppgPushDecBuff(mltAdrs);

    if (hnof->b16[0] == 0) {
        flLogOut("テクスチャハンドルの取得に失敗しました。\n");

        for (;;) {
        }
    }

    return 1;
}

s32 ppgReleasePaletteHandle(Palette *pch, s32 ixNum) {
    s32 i;
    s32 ix;

    if (pch == 0) {
        pch = ppg_w.cur->pal;
    }

    if (pch == 0) {
        return 0;
    }

    if (pch->be == 0) {
        return 0;
    }

    if (ixNum < 0) {
        for (i = 0; i < pch->total; i++) {
            if (pch->handle[i] != 0) {
                flReleasePaletteHandle(pch->handle[i]);
            }

            pch->handle[i] = 0;
        }
    } else {
        ix = ixNum - pch->ixNum1st;

        if ((ix >= 0) && (ix < pch->total)) {
            if (pch->handle[ix] != 0) {
                flReleasePaletteHandle(pch->handle[ix]);
            }

            pch->handle[ix] = 0;
        }
    }

    return ppgCheckPaletteDataBe(pch);
}

s32 ppgReleaseTextureHandle(Texture *tch, s32 ixNum) {
    s32 i;
    s32 ix;

    if (tch == 0) {
        tch = ppg_w.cur->tex;
    }

    if (tch == 0) {
        return 0;
    }

    if (tch->be == 0) {
        return 0;
    }

    if (ixNum < 0) {
        for (i = 0; i < tch->total; i++) {
            if (tch->handle[i].b16[0] != 0) {
                flReleaseTextureHandle(tch->handle[i].b16[0]);
            }

            tch->handle[i].b16[0] = 0;

            if ((tch->flags & 0x80) != 0) {
                tch->handle[i].b16[1] = 0;
            }
        }
    } else {
        ix = ixNum - tch->ixNum1st;

        if ((ix >= 0) && (ix < tch->total)) {
            if (tch->handle[ix].b16[0] != 0) {
                flReleaseTextureHandle(tch->handle[ix].b16[0]);
            }

            tch->handle[ix].b16[0] = 0;

            if ((tch->flags & 0x80) != 0) {
                tch->handle[ix].b16[1] = 0;
            }
        }
    }

    return ppgCheckTextureDataBe(tch);
}
