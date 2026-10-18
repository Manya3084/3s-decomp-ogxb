/* zlib_Malloc 0x180F0, zlib_Free 0x1810A, zlib_Decompress 0x1811B,
 * zlib_Initialize 0x1818C. zlib_Decompress is the PS2 C but for its loop; its z_stream is
 * zlib.info at 0xCBA920 and the inflate result is the dword at 0xCBA958.
 * Its loop is written without the PS2 `else continue`, which compiles to
 * a different block order.
 * zalloc, zfree, and opaque are the dwords at 0xCBA940, 0xCBA944, and 0xCBA948.
 * The heap object is 0xCBA95C. The unit passed to mmHeapInitialize is 16.
 * mmHeapInitialize is 0xF2236, mmAlloc is 0xF22C4, and mmFree is 0xF2211.
 */

#include "types.h"

#include <stddef.h>

typedef struct MEMMAN_OBJ {
    u8 first;
} MEMMAN_OBJ;

/* 32-bit retail layout: the z_stream fields, zalloc/zfree/opaque at
 * +0x20/+0x24/+0x28, the inflate state at +0x38, and mobj at +0x3C. */
typedef struct {
    struct {
        u8 *next_in;
        u32 avail_in;
        u32 total_in;
        u8 *next_out;
        u32 avail_out;
        u32 total_out;
        char *msg;
        void *state;
        void *(*zalloc)(void *opaque, u32 items, u32 size);
        void (*zfree)(void *opaque, void *adrs);
        void *opaque;
        s32 data_type;
        u32 adler;
        u32 reserved;
    } info;
    s32 state;
    MEMMAN_OBJ mobj;
} ZLIB;

#if defined(__i386__)
_Static_assert(offsetof(ZLIB, info.zalloc) == 0x20, "zalloc");
_Static_assert(offsetof(ZLIB, info.zfree) == 0x24, "zfree");
_Static_assert(offsetof(ZLIB, info.opaque) == 0x28, "opaque");
_Static_assert(offsetof(ZLIB, state) == 0x38, "state");
_Static_assert(offsetof(ZLIB, mobj) == 0x3C, "mobj");
#endif

extern ZLIB zlib;

extern void mmHeapInitialize(MEMMAN_OBJ *mobj, void *adrs, s32 size, s32 unit, const char *name);
extern void *mmAlloc(MEMMAN_OBJ *mobj, s32 size, s32 align);
extern void mmFree(MEMMAN_OBJ *mobj, void *adrs);
extern s32 inflateInit_(void *z, const char *version, s32 stream_size);
extern s32 inflate(void *z, s32 flush);
extern s32 inflateEnd(void *z);

void *zlib_Malloc(void *opaque, u32 items, u32 size) {
    (void)opaque;
    return mmAlloc(&zlib.mobj, (s32)(size * items), 0);
}

void zlib_Free(void *opaque, void *adrs) {
    (void)opaque;
    mmFree(&zlib.mobj, adrs);
}

s32 zlib_Decompress(void *srcBuff, s32 srcSize, void *dstBuff, s32 dstSize) {
    zlib.info.next_in = srcBuff;
    zlib.info.avail_in = srcSize;
    zlib.info.next_out = dstBuff;
    zlib.info.avail_out = dstSize;
    zlib.state = 0;

    if (inflateInit_(&zlib.info, "1.1.4", sizeof(zlib.info)) != 0) {
        return 0;
    }

    for (;;) {
        zlib.state = inflate(&zlib.info, 0);

        if (zlib.state == 1) {
            break;
        }

        if (zlib.state != 0) {
            return 0;
        }
    }

    if (inflateEnd(&zlib.info) != 0) {
        return 0;
    }

    return zlib.info.total_out;
}

void zlib_Initialize(void *tempAdrs, s32 tempSize) {
    if (tempAdrs == 0) {
        for (;;) {
        }
    }

    mmHeapInitialize(&zlib.mobj, tempAdrs, tempSize, 16, "- for zlib -");
    zlib.info.opaque = 0;
    zlib.info.zalloc = zlib_Malloc;
    zlib.info.zfree = zlib_Free;
}
