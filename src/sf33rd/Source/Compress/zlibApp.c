/* zlib_Malloc 0x180F0, zlib_Free 0x1810A, zlib_Initialize 0x1818C.
 * zalloc, zfree, and opaque are the dwords at 0xCBA940, 0xCBA944, and 0xCBA948.
 * The heap object is 0xCBA95C. The unit passed to mmHeapInitialize is 16.
 * mmHeapInitialize 0xF2236, mmAlloc 0xF22C4, and mmFree 0xF2211 are not named yet.
 */

#include "types.h"

#include <stddef.h>

typedef struct MEMMAN_OBJ {
    u8 first;
} MEMMAN_OBJ;

/* 32-bit retail layout. zalloc/zfree/opaque are +0x20/+0x24/+0x28. mobj is +0x3C. */
typedef struct {
    u8 gap[0x20];
    void *(*zalloc)(void *opaque, u32 items, u32 size);
    void (*zfree)(void *opaque, void *adrs);
    void *opaque;
    u8 gap2C[0x10];
    MEMMAN_OBJ mobj;
} ZLIB;

#if defined(__i386__)
_Static_assert(offsetof(ZLIB, zalloc) == 0x20, "zalloc");
_Static_assert(offsetof(ZLIB, zfree) == 0x24, "zfree");
_Static_assert(offsetof(ZLIB, opaque) == 0x28, "opaque");
_Static_assert(offsetof(ZLIB, mobj) == 0x3C, "mobj");
#endif

extern ZLIB zlib;

extern void mmHeapInitialize(MEMMAN_OBJ *mobj, void *adrs, s32 size, s32 unit, const char *name);
extern void *mmAlloc(MEMMAN_OBJ *mobj, s32 size, s32 align);
extern void mmFree(MEMMAN_OBJ *mobj, void *adrs);

void *zlib_Malloc(void *opaque, u32 items, u32 size) {
    (void)opaque;
    return mmAlloc(&zlib.mobj, (s32)(size * items), 0);
}

void zlib_Free(void *opaque, void *adrs) {
    (void)opaque;
    mmFree(&zlib.mobj, adrs);
}

void zlib_Initialize(void *tempAdrs, s32 tempSize) {
    if (tempAdrs == 0) {
        for (;;) {
        }
    }

    mmHeapInitialize(&zlib.mobj, tempAdrs, tempSize, 16, "- for zlib -");
    zlib.opaque = 0;
    zlib.zalloc = zlib_Malloc;
    zlib.zfree = zlib_Free;
}
