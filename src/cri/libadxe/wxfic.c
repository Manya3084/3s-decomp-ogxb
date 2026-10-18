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
extern s32 dat_007A55D8; /* 0x7A55D8 */
extern void (*dat_007A6044)(const char *name, s32 prm, s32 handle, s32 arg3); /* 0x7A6044 */
extern s32 dat_007A6048; /* 0x7A6048 */
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

    if (dat_007A55D8 == 0) {
        handle = CreateFileA(name, 0x80000000, 3, 0, 3, 0x60000000, 0);
    } else {
        handle = CreateFileA(name, 0x80000000, 3, 0, 3, 0x10000000, 0);
    }

    if (dat_007A6044 != 0) {
        dat_007A6044(name, prm, handle, dat_007A6048);
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
