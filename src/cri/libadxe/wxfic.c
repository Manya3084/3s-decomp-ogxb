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
