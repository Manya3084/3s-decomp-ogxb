/* ppg_Initialize, retail sf33rd.xbe 0xF22FA.
 * ppgMallocF 0xF2320. ppgMallocR 0xF2334. ppgFree 0xF2348.
 * ppgSetupCurrentDataList 0xF2363. ppgSetupCurrentPaletteNumber 0xF236D.
 * ppgRenewTexChunkSeqs 0xF2A6E.
 * ppg_w is 0x7A8080. cur is +0, hanPal is +4, and the heap object is +8.
 * The unit is 16. A null address stops. mmHeapInitialize ignores the name.
 * The renew lock flag is 2. The copy is an inlined memcpy of srcSize bytes.
 * 0x16993 and 0x16C67 stay unnamed.
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
    u32 desc;
    s32 width;
    s32 height;
    s32 pitch;
    void *ptr;
    s32 bitdepth;
    u8 pixelformat[0x30];
} plContext;

#if defined(__i386__)
_Static_assert(sizeof(MEMMAN_OBJ) == 0x2C, "MEMMAN_OBJ");
_Static_assert(sizeof(Palette) == 0x14, "Palette");
_Static_assert(offsetof(Palette, total) == 2, "total");
_Static_assert(offsetof(Palette, handle) == 4, "handle");
_Static_assert(sizeof(TextureHandle) == 4, "TextureHandle");
_Static_assert(sizeof(Texture) == 0x20, "Texture");
_Static_assert(offsetof(Texture, total) == 6, "tex total");
_Static_assert(offsetof(Texture, handle) == 8, "tex handle");
_Static_assert(offsetof(Texture, srcAdrs) == 0x18, "srcAdrs");
_Static_assert(offsetof(Texture, srcSize) == 0x1C, "srcSize");
_Static_assert(sizeof(plContext) == 0x48, "plContext");
_Static_assert(offsetof(plContext, ptr) == 0x10, "ptr");
_Static_assert(offsetof(PPG_W, hanPal) == 4, "hanPal");
_Static_assert(offsetof(PPG_W, mm) == 8, "mm");
#endif

extern PPG_W ppg_w;

extern void mmHeapInitialize(MEMMAN_OBJ *mobj, void *adrs, s32 size, s32 unit, const char *name);
extern void *mmAlloc(MEMMAN_OBJ *mobj, s32 size, s32 flag);
extern void mmFree(MEMMAN_OBJ *mobj, void *adrs);
extern void sub_00016993(s32 rect, u32 handle, plContext *bits, s32 flag);
extern void sub_00016C67(u32 handle);

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
            sub_00016993(0, tch->handle[i].b16[0], &bits, 2);
            memcpy(bits.ptr, tch->srcAdrs + (tch->srcSize * (u32)i), (size_t)tch->srcSize);
            sub_00016C67(tch->handle[i].b16[0]);
        }
    }

    return 1;
}
