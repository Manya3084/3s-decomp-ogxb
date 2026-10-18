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

extern s32 CreateFileA(const char *name, u32 access, u32 share, void *sec, u32 disp, u32 flags,
                        void *templ);
extern s32 xb_wxfic_PaddedLength(char *path);
extern void xb_wxfic_CallErrFn(const char *obj, const char *msg);
extern s32 dat_007A55D8; /* 0x7A55D8 */
extern void (*dat_007A6044)(const char *name, s32 prm, s32 handle, s32 arg3); /* 0x7A6044 */
extern s32 dat_007A6048; /* 0x7A6048 */
extern char wxfic_msg[]; /* 0xCE5300 */

s32 wxfic_cache_file(u8 *src, u8 *work) {
    char *name;
    char *path;
    char *dst;
    char ch;
    s32 prm;
    s32 handle;
    s32 len;
    s32 used;
    u32 flags;
    u8 *slot;

    name = *(char **)src;
    prm = *(s32 *)(src + 8);
    if (dat_007A55D8 != 0) {
        flags = 0x10000000;
    } else {
        flags = 0x60000000;
    }

    handle = CreateFileA(name, 0x80000000, 3, 0, 3, flags, 0);
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

    path = name + *(s32 *)(work + 0x28);
    len = xb_wxfic_PaddedLength(path);
    used = *(s32 *)(work + 0x20) + len + 0x14;
    *(s32 *)(work + 0x20) = used;
    if (used > *(s32 *)(work + 0x1C)) {
        xb_wxfic_CallErrFn(0, "E0109076:work is in short.");
        *(s32 *)(work + 8) = 1;
        *(s32 *)(work + 4) = 6;
        return -1;
    }

    slot = *(u8 **)(work + 0x38);
    *(s32 *)(slot + 4) = prm;
    *(u8 **)(slot + 0xC) = slot + len + 0x14;
    *(s32 *)slot = handle;
    *(u8 **)(slot + 0x10) = slot + 0x14;
    dst = (char *)(slot + 0x14);
    do {
        ch = *path;
        path += 1;
        *dst = ch;
        dst += 1;
    } while (ch != 0);

    *(s32 *)(work + 0x30) += 1;
    *(u8 **)(work + 0x38) = *(u8 **)(slot + 0xC);
    return 0;
}
