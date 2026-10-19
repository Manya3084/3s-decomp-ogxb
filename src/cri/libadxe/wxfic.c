/* wxfic_cache_file 0x16D430.
 *
 * Opens the name at the first argument. A missing file, or a negative
 * value at +8, formats E0109075 and returns 0. The work object is the
 * second argument. If the aligned name does not fit, this reports
 * E0109076 and returns -1. Otherwise the slot at +0x38 gains the handle,
 * the value at +8, and a copy of the name, and this returns 0.
 * 0x12400E, 0x16D3D0, and 0x169A60 are CreateFileA, xb_wxfic_PaddedLength, and
 * xb_wxfic_CallErrFn. 0x169A60 tail-jumps
 * to 0x169190. The bytes pass the name to 0x16D3D0 in eax. The address
 * is pushed at 0x16DA9D. There is no relative caller.
 */

#include "types.h"

#include <stdio.h>
#include <string.h>

extern s32 XB_STDCALL CreateFileA(const char *name, u32 access, u32 share, void *sec, u32 disp, u32 flags,
                        void *templ);
extern s32 xb_wxfic_PaddedLength(char *path);
extern void xb_wxfic_CallErrFn(const char *obj, const char *msg);
/* D_007A55D8 is 0x7A55D8. */
extern s32 D_007A55D8;
/* D_007A6044 is 0x7A6044. */
extern void (*D_007A6044)(const char *name, s32 prm, s32 handle, s32 arg3);
/* D_007A6048 is 0x7A6048. */
extern s32 D_007A6048;
extern char wxfic_msg[]; /* 0xCE5300 */
extern u8 wxfic_obj[16][0x44]; /* wxfic_obj is 0xCE2760 */
extern s32 wxfic_init_cnt; /* wxfic_init_cnt is 0x7A6040 */
extern void *D_007A55E8;
extern void *D_007A55EC;
extern void *D_007A55F0;
extern void xb_wxfic_BuildPath(char *dst, const char *src);
extern char *SJRBF_GetXtrSize(void *cache);
extern s32 ADXB_GetLpEndPos(void *cache);
extern int _stricmp(const char *a, const char *b);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
u8 *xb_wxfic_NextEntry(u8 *cache);
u8 *xb_wxfic_FindFile(const char *name);
s32 xb_wxfic_GetFileAddr(const char *name);
s32 xb_wxfic_GetFileSize(const char *name);
s32 xb_wxfic_GetFileInfo(const char *name, s32 *size, s32 *prm);

/* xb_wxfic_PaddedLength 0x16D3D0: the name's length with its NUL, rounded
 * up to 4. Static (config/sf33rd/static.txt), so the name comes in eax. */

s32 xb_wxfic_PaddedLength(char *path) {
    s32 len = strlen(path) + 1;

    if (len % 4 != 0) {
        len += 4 - len % 4;
    }

    return len;
}

s32 wxfic_cache_file(u8 *src, u8 *work) {
    u8 *slot;
    s32 len;
    s32 handle;
    s32 prm;
    char *name;

    slot = *(u8 **)(work + 0x38);
    name = *(char **)src;
    prm = *(s32 *)(src + 8);

    if (D_007A55D8 == 0) {
        handle = CreateFileA(name, 0x80000000, 3, 0, 3, 0x60000000, 0);
    } else {
        handle = CreateFileA(name, 0x80000000, 3, 0, 3, 0x10000000, 0);
    }

    if (D_007A6044 != 0) {
        D_007A6044(name, prm, handle, D_007A6048);
    }

    if ((handle == -1) || (prm < 0)) {
        sprintf(wxfic_msg, "E0109075:can not open '%s'.(wxfic_cache_file)", name);
        xb_wxfic_CallErrFn(0, wxfic_msg);
        *(s32 *)(work + 8) = 1;
        *(s32 *)(work + 4) = 6;
        return 0;
    }

    len = xb_wxfic_PaddedLength(name + *(s32 *)(work + 0x28)) + 0x14;
    *(s32 *)(work + 0x20) += len;

    if (*(s32 *)(work + 0x20) > *(s32 *)(work + 0x1C)) {
        xb_wxfic_CallErrFn(0, "E0109076:work is in short.");
        *(s32 *)(work + 8) = 1;
        *(s32 *)(work + 4) = 6;
        return -1;
    }

    *(s32 *)(slot + 4) = prm;
    *(u8 **)(slot + 0xC) = slot + len;
    *(s32 *)slot = handle;
    *(u8 **)(slot + 0x10) = slot + 0x14;
    strcpy((char *)(slot + 0x14), name + *(s32 *)(work + 0x28));
    *(s32 *)(work + 0x30) += 1;
    *(u8 **)(work + 0x38) = *(u8 **)(slot + 0xC);
    return 0;
}

/* The cache directory. Sixteen caches of 0x44 bytes are at 0xCE2760: +0 in
 * use, +4 state, +0x18 the work buffer, +0x1C its size, +0x20 the used
 * part, +0x24 the directory name (in the work), +0x28 its length, +0x30 the
 * file count, +0x34 the first entry and +0x38 the cursor. An entry holds
 * the handle, the size, the value at the source's +8, the next entry and
 * the name. The count and name getters are the folded bodies 0x16D550
 * (ADXB_GetLpEndPos) and 0x16D560 (SJRBF_GetXtrSize).
 * xb_wxfic_AddFileSize 0x16D400, xb_wxfic_NextEntry 0x16D570 (static: the
 * cache comes in ecx), xb_wxfic_CompareNoCase 0x16D590, xb_wxfic_FindFile
 * 0x16D5E0, xb_wxfic_GetFileInfo 0x16D6C0, xb_wxfic_GetFileAddr 0x16D720,
 * xb_wxfic_GetFileSize 0x16D760 and xb_wxfic_Init 0x16D7A0. */

s32 xb_wxfic_AddFileSize(u8 *src, u8 *work) {
    *(s32 *)(work + 0x1C) += xb_wxfic_PaddedLength(*(char **)src + *(s32 *)(work + 0x28)) + 0x14;
    return 0;
}

u8 *xb_wxfic_NextEntry(u8 *cache) {
    u8 *entry = *(u8 **)(cache + 0x38);
    u8 *next = *(u8 **)(entry + 0xC);

    *(u8 **)(cache + 0x38) = next;

    if (next == 0) {
        *(u8 **)(cache + 0x38) = *(u8 **)(cache + 0x34);
    }

    return entry;
}

s32 xb_wxfic_CompareNoCase(const u8 *a, const u8 *b, s32 n) {
    s32 i;
    s32 d = 0;

    for (i = 0; i < n; i++) {
        d = (a[i] & 0xDF) - (b[i] & 0xDF);

        if (d != 0) {
            break;
        }
    }

    return d;
}

u8 *xb_wxfic_FindFile(const char *name) {
    char path[0x104];
    u8 *cache;
    u8 *entry;
    char *dir;
    s32 dlen;
    s32 n;
    s32 i;
    s32 j;

    xb_wxfic_BuildPath(path, name);

    for (j = 0; j < 16; j++) {
        cache = wxfic_obj[j];

        if (*(s32 *)cache == 0 || *(s32 *)(cache + 4) == 1) {
            continue;
        }

        dir = SJRBF_GetXtrSize(cache);
        dlen = strlen(dir);

        if ((s32)strlen(path) < dlen || xb_wxfic_CompareNoCase((u8 *)dir, (u8 *)path, dlen) != 0) {
            continue;
        }

        n = ADXB_GetLpEndPos(cache);
        *(u8 **)(cache + 0x38) = *(u8 **)(cache + 0x34);

        for (i = 0; i < n; i++) {
            entry = xb_wxfic_NextEntry(cache);

            if (_stricmp(path + dlen, *(char **)(entry + 0x10)) == 0) {
                return entry;
            }
        }
    }

    return 0;
}

s32 xb_wxfic_GetFileInfo(const char *name, s32 *size, s32 *prm) {
    char path[0x104];
    u8 *entry;

    xb_wxfic_BuildPath(path, name);
    entry = xb_wxfic_FindFile(path);

    if (entry == 0) {
        return 0;
    }

    if (size != 0) {
        *size = *(s32 *)(entry + 4);
    }

    if (prm != 0) {
        *prm = *(s32 *)(entry + 8);
    }

    return *(s32 *)entry;
}

s32 xb_wxfic_GetFileAddr(const char *name) {
    char path[0x104];
    u8 *entry;

    xb_wxfic_BuildPath(path, name);
    entry = xb_wxfic_FindFile(path);

    if (entry == 0) {
        return 0;
    }

    return *(s32 *)entry;
}

s32 xb_wxfic_GetFileSize(const char *name) {
    char path[0x104];
    u8 *entry;

    xb_wxfic_BuildPath(path, name);
    entry = xb_wxfic_FindFile(path);

    if (entry == 0) {
        return -1;
    }

    return *(s32 *)(entry + 4);
}

void xb_wxfic_Init(void) {
    sub_0016AA60();

    if (wxfic_init_cnt == 0) {
        memset(wxfic_obj, 0, sizeof(wxfic_obj));
        D_007A55E8 = xb_wxfic_GetFileAddr;
        D_007A55EC = xb_wxfic_GetFileSize;
        D_007A55F0 = xb_wxfic_GetFileInfo;
    }

    wxfic_init_cnt++;
    sub_0016AA70();
}

/* The directory cache. A wxfic object (16 of 0x44 bytes at 0xCE2760):
 * +0 in use, +4 state (1 building, 2 ready, 6 failed), +0xC the work is
 * the cache's own heap (+0x10), +0x18 the work, +0x1C its size, +0x20
 * bytes used, +0x24 the root path in the work (+0x28 its length), +0x2C
 * how deep to recurse, +0x34 and +0x38 the first entry. 0x7A6054 is a
 * spin lock around directory walks; 0x7A60B4 and 0x7A60B8 hold the walk
 * callback and its object. */

typedef struct {
    u32 attr;
    u32 times[6];
    u32 size_hi;
    u32 size_lo;
    u32 reserved[2];
    char name[0x100];
} WxFindData;

typedef struct {
    char *path;
    u32 size_hi;
    u32 size_lo;
} WxWalkInfo;

extern volatile s32 D_007A6054;
extern s32 (*D_007A60B4)(WxWalkInfo *info, void *obj);
extern void *D_007A60B8;
extern void (*D_007A604C)(void *cache);
extern char D_00CF4E90[];
extern s32 XB_STDCALL FindFirstFileA(const char *pattern, WxFindData *fd);
extern s32 XB_STDCALL FindNextFileA(s32 h, WxFindData *fd);
extern s32 XB_STDCALL CloseHandle(s32 h);
extern void XB_STDCALL Sleep(u32 ms);
extern void *XB_STDCALL HeapCreate(u32 flags, u32 initial, u32 max);
extern void *XB_STDCALL RtlAllocateHeap(void *heap, u32 flags, u32 size);
extern long XB_STDCALL InterlockedIncrement(volatile long *p);

/* Retail inlines this spin (lock xadd). */
#define xb_wxfic_Lock()                                                  \
    while (InterlockedIncrement((volatile long *)&D_007A6054) != 1) {    \
        D_007A6054--;                                                    \
        Sleep(10);                                                       \
    }

/* xb_wxfic_SetWalkCallback 0x172880. */

s32 xb_wxfic_SetWalkCallback(s32 (*fn)(WxWalkInfo *info, void *obj), void *obj) {
    D_007A60B4 = fn;
    D_007A60B8 = obj;
    return 0;
}

/* xb_wxfic_WalkDir 0x1728A0.
 *
 * Calls the walk callback for each file in dir, counting them, and
 * descends depth levels of subdirectories (not "." ones). A negative
 * callback result stops the walk and is returned. */

s32 xb_wxfic_WalkDir(const char *dir, s32 depth, s32 *count) {
    char pattern[0x104];
    char path[0x104];
    WxFindData fd;
    WxWalkInfo info;
    s32 h;
    s32 r;

    sprintf(pattern, "%s\\*", dir);

    if ((h = FindFirstFileA(pattern, &fd)) == -1) {
        return 0;
    }

    do {
        if (fd.attr & 0x10) {
            if (depth == 0 || fd.name[0] == '.') {
                continue;
            }

            sprintf(path, D_00CF4E90, dir, fd.name);
            r = xb_wxfic_WalkDir(path, depth - 1, count);
        } else {
            sprintf(path, D_00CF4E90, dir, fd.name);
            info.path = path;
            info.size_lo = fd.size_lo;
            info.size_hi = fd.size_hi;

            if (count != 0) {
                (*count)++;
            }

            if (D_007A60B4 == 0) {
                continue;
            }

            r = D_007A60B4(&info, D_007A60B8);
        }

        if (r < 0) {
            return r;
        }
    } while (FindNextFileA(h, &fd));

    CloseHandle(h);
    return 0;
}

/* xb_wxfic_WalkPath 0x1729D0.
 *
 * xb_wxfic_WalkDir from path without its trailing backslash. */

s32 xb_wxfic_WalkPath(const char *path, s32 depth, s32 *count) {
    char buf[0x104];
    char *end;

    if (count != 0) {
        *count = 0;
    }

    if (path == 0) {
        return -1;
    }

    strcpy(buf, path);
    end = &buf[strlen(buf) - 1];

    if (*end == '\\') {
        *end = 0;
    }

    return xb_wxfic_WalkDir(buf, depth, count);
}

/* xb_wxfic_AllocWork 0x16D350.
 *
 * Static (config/sf33rd/static.txt): the cache comes in esi. Allocates
 * the work from a heap of its own when the cache owns it, then clears
 * it. */

static s32 xb_wxfic_AllocWork(u8 *e) {
    void *heap;
    void *p;

    if (*(s32 *)(e + 0xC) != 0) {
        if ((heap = HeapCreate(0, 0x1000, 0)) == 0) {
            xb_wxfic_CallErrFn(0, "E0109072:can not create heap.");
            return -1;
        }

        if ((p = RtlAllocateHeap(heap, 0, *(u32 *)(e + 0x1C))) == 0) {
            xb_wxfic_CallErrFn(0, "E0109073:can not allocate memory.");
            return -1;
        }

        *(void **)(e + 0x10) = heap;
        *(void **)(e + 0x18) = p;
    }

    memset(*(void **)(e + 0x18), 0, *(u32 *)(e + 0x1C));
    return 0;
}

/* xb_wxfic_CalcWorkSize 0x16D7F0.
 *
 * The work a cache of path needs: the root name plus every file's
 * entry (xb_wxfic_AddFileSize). */

s32 xb_wxfic_CalcWorkSize(const char *path, s32 depth) {
    u8 ctx[0x44];
    char buf[0x104];
    s32 len;
    s32 r;

    memset(ctx, 0, sizeof(ctx));

    if (path != 0) {
        strcpy(buf, path);
    } else {
        memset(buf, 0, sizeof(buf));
    }

    xb_wxfic_BuildPath(buf, path);
    len = strlen(buf);

    if (buf[len - 1] == '\\') {
        buf[--len] = 0;
    }

    *(s32 *)(ctx + 0x28) = len;
    *(s32 *)(ctx + 0x1C) = xb_wxfic_PaddedLength(buf);
    xb_wxfic_Lock()
    xb_wxfic_SetWalkCallback((s32 (*)(WxWalkInfo *, void *))xb_wxfic_AddFileSize, ctx);

    if ((r = xb_wxfic_WalkPath(buf, depth, 0)) < 0) {
        return r;
    }

    D_007A6054--;
    return *(s32 *)(ctx + 0x1C);
}

/* xb_wxfic_CreateCache 0x16D900.
 *
 * Static (config/sf33rd/static.txt): depth comes in ecx and the work in
 * eax. Takes a free cache, sizes or adopts its work and stores the root
 * path at its start. When no cache is free, or the work is too small,
 * it returns 0 still holding the server lock, as in retail. */

static u8 *xb_wxfic_CreateCache(s32 depth, u8 *work, const char *path, s32 wsize) {
    char buf[0x104];
    u8 *e;
    s32 i;
    s32 len;
    s32 n;

    sub_0016AA60();

    for (i = 0; i < 16; i++) {
        if (*(s32 *)wxfic_obj[i] == 0) {
            break;
        }
    }

    if (i == 16) {
        return 0;
    }

    e = wxfic_obj[i];
    *(s32 *)(e + 0x2C) = depth;
    *(s32 *)(e + 0x30) = 0;

    if (work == 0) {
        *(s32 *)(e + 0xC) = 1;
        wsize = xb_wxfic_CalcWorkSize(path, depth);
    } else {
        *(u8 **)(e + 0x18) = work;
    }

    *(s32 *)(e + 0x1C) = wsize;
    xb_wxfic_AllocWork(e);

    if (path != 0) {
        strcpy(buf, path);
    } else {
        memset(buf, 0, sizeof(buf));
    }

    xb_wxfic_BuildPath(buf, path);
    len = strlen(buf);

    if (buf[len - 1] == '\\') {
        buf[--len] = 0;
    }

    *(s32 *)(e + 0x28) = len;
    *(u8 **)(e + 0x24) = *(u8 **)(e + 0x18);
    strcpy(*(char **)(e + 0x24), buf);
    n = xb_wxfic_PaddedLength(*(char **)(e + 0x24));

    if (*(s32 *)(e + 0x20) + n > *(s32 *)(e + 0x1C)) {
        xb_wxfic_CallErrFn(0, "E0109071:work is in short.");
        return 0;
    }

    *(s32 *)(e + 0x20) = n;
    *(u8 **)(e + 0x34) = *(u8 **)(e + 0x18) + n;
    *(u8 **)(e + 0x38) = *(u8 **)(e + 0x18) + n;
    *(s32 *)e = 1;
    sub_0016AA70();
    return e;
}

/* xb_wxfic_CacheDir 0x16DA60.
 *
 * Static (config/sf33rd/static.txt): the cache comes in esi. Walks its
 * root and adds every file (wxfic_cache_file). */

static s32 xb_wxfic_CacheDir(u8 *e) {
    s32 r;

    xb_wxfic_Lock()
    xb_wxfic_SetWalkCallback((s32 (*)(WxWalkInfo *, void *))wxfic_cache_file, e);

    if ((r = xb_wxfic_WalkPath(*(char **)(e + 0x24), *(s32 *)(e + 0x2C), 0)) < 0) {
        return r;
    }

    D_007A6054--;
    return 0;
}

/* xb_wxfic_Create 0x16DAD0.
 *
 * Builds a cache of path's files (depth levels down) in work, or in a
 * heap of its own when work is 0. */

u8 *xb_wxfic_Create(const char *path, s32 depth, u8 *work, s32 wsize) {
    u8 *e;

    if (wxfic_init_cnt == 0) {
        xb_wxfic_Init();
    }

    if ((e = xb_wxfic_CreateCache(depth, work, path, wsize)) == 0) {
        return 0;
    }

    *(s32 *)(e + 4) = 1;
    xb_wxfic_CacheDir(e);
    *(u8 **)(e + 0x38) = *(u8 **)(e + 0x34);

    if (D_007A604C != 0) {
        D_007A604C(e);
    }

    if (*(s32 *)(e + 4) != 6) {
        *(s32 *)(e + 4) = 2;
    }

    return e;
}
