/* xb_011000.c: Xbox-only code from the run of Xbox-only functions at 0x11000, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern u8 D_00CBA9A0[];
extern u8 D_00CCA9A0[];
void xb_memset_bytes(void* p, u8 v, s32 n);
void xb_PoolCreate(s32* pool, u8* buf, s32 n, u32 base, u32 size, u32 align, s32 top);

s32 xb_PoolUsedSize(u8* pool) {
    return *(s32*)(pool + 0x10) - *(s32*)(pool + 0xC);
}

s32 xb_PoolInit(u32* pool, u32 base, u32 size, u32 align) {
    pool[5] = align;
    pool[0] = base;
    pool[1] = (base + align - 1) & ~(align - 1);
    pool[2] = (base + ((size + align - 1) & ~(align - 1)) + align - 1) & ~(align - 1);
    pool[3] = pool[1];
    pool[4] = pool[2];
    return 1;
}

u32 xb_PoolAllocAligned(u32* pool, u32 size, s32 top) {
    u32 ret;

    size = (size + pool[5] - 1) & ~(pool[5] - 1);

    if (pool[3] + size > pool[4]) {
        ret = 0;
    } else if (top != 0) {
        pool[4] -= size;
        ret = pool[4];
    } else {
        ret = pool[3];
        pool[3] += size;
    }

    return ret;
}

s32 xb_PoolGetBlock(u8* pool, s32 n, s32* block) {
    block[0] = ((s32*)pool)[n + 3];
    block[1] = n;
    return 1;
}

void xb_InitWorkPool(s32 a, s32 b, s32 c) {
    xb_PoolCreate((s32*)D_00CCA9A0, D_00CBA9A0, 0x1000, a, b, c, 1);
}

void xb_PoolCreate(s32* pool, u8* buf, s32 n, u32 base, u32 size, u32 align, s32 top) {
    pool[0] = n;
    pool[2] = (s32)buf;
    pool[1] = size;
    pool[3] = top;
    pool[6] = align;

    if (top) {
        pool[5] = (base + align - 1) & ~(align - 1);
    } else {
        pool[5] = (base + size) & ~(align - 1);
    }

    pool[4] = pool[5];
    pool[7] = 0;
    pool[8] = 0;
    pool[9] = 0xFFFF;
    xb_memset_bytes(buf, 0, n << 4);
}
