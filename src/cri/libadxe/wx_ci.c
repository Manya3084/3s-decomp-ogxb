/* wxCiGetFileSize 0x169310.
 *
 * A null name reports E0092901 and returns 0. Otherwise the name is
 * copied into a 0x104 buffer and the size comes from 0x1692E0.
 * 0x168FE0 and 0x169190 stay unnamed. The only reference is the
 * pointer at 0x43C900, eight bytes into the device table at 0x43C8F8.
 */

#include "types.h"

#include <string.h>

extern void sub_00169190(const char *fname, const char *msg);
extern void sub_00168FE0(char *dst, const char *src);
extern s32 sub_001692E0(char *path);
extern void *sub_00169370(void);
extern void sub_001693B0(void *hn);
extern void sub_00169430(void *hn);
extern s32 sub_00169E20(char *path);
extern long long sub_00169F20(s32 handle);
extern s32 (*wxci_open_cb)(char *path, s32 *size, s32 *mode); /* 0x7A55F0 */

s32 wxCiGetFileSize(const char *fname) {
    char path[0x104];

    if (fname == 0) {
        sub_00169190(fname, "E0092901:fname is null.(wxCiGetFileSize)");
        return 0;
    }

    sub_00168FE0(path, fname);
    return sub_001692E0(path);
}

/* wxCiOpen 0x16A050.
 *
 * A null name reports E0092908 and returns 0. A non-zero rw reports
 * E0092909 and returns 0. A failed alloc reports E0092910 and returns 0.
 * The handle is 0x168 bytes. The second argument is unused. The callback
 * at 0x7A55F0 may supply a size and a mode. Mode 2 stores 2 at +0x164,
 * clears +0x2C, and the fallback open temporarily replaces the first
 * byte of the path at +0x60 with 'z'. The fallback ceiling-divides the
 * new size by the s32 at +8. 0x169370, 0x1693B0, 0x169430, 0x169E20,
 * and 0x169F20 stay unnamed. The only reference is the pointer at
 * 0x43C908.
 */

void *wxCiOpen(const char *fname, void *arg1, s32 rw) {
    char path[0x104];
    void *hn;
    u8 *bytes;
    char *src;
    char *dst;
    char ch;
    char saved;
    s32 mode;
    s32 size_lo;
    s32 size_hi;
    s32 cb_ret;
    s32 opened;
    long long sz;
    long long unit;
    long long quot;

    (void)arg1;
    if (fname == 0) {
        sub_00169190(fname, "E0092908:fname is null.(wxCiOpen)");
        return 0;
    }

    if (rw != 0) {
        sub_00169190(0, "E0092909:rw is illigal.(wxCiOpen)");
        return 0;
    }

    hn = sub_00169370();
    if (hn == 0) {
        sub_00169190(0, "E0092910:not enough handle resource.(wxCiOpen)");
        return 0;
    }

    memset(hn, 0, (size_t)0x168);
    bytes = hn;
    sub_00168FE0(path, fname);
    src = path;
    dst = (char *)(bytes + 0x60);
    do {
        ch = *src;
        src += 1;
        *dst = ch;
        dst += 1;
    } while (ch != 0);

    mode = 0;
    if (wxci_open_cb != 0) {
        cb_ret = wxci_open_cb(path, &size_lo, &mode);
        if (cb_ret != 0) {
            *(s32 *)(bytes + 0x2C) = 1;
            size_hi = (s32)(((long long)size_lo) >> 32);
        } else {
            cb_ret = 0;
            size_lo = -2048;
            size_hi = 0x7FFFFFFF;
        }
    } else {
        cb_ret = 0;
        size_lo = -2048;
        size_hi = 0x7FFFFFFF;
    }

    if (mode == 2) {
        cb_ret = 0;
        *(s32 *)(bytes + 0x164) = 2;
        *(s32 *)(bytes + 0x2C) = 0;
    }

    *(s32 *)(bytes + 0x30) = cb_ret;
    *(s32 *)(bytes + 0x10) = size_lo;
    *(s32 *)(bytes + 0x14) = size_hi;
    sub_001693B0(hn);
    if (*(s32 *)(bytes + 0x30) != 0) {
        return hn;
    }

    dst = (char *)(bytes + 0x60);
    if (*(s32 *)(bytes + 0x164) == 2) {
        saved = dst[0];
        dst[0] = 'z';
        opened = sub_00169E20(dst);
        dst[0] = saved;
    } else {
        opened = sub_00169E20(dst);
    }

    *(s32 *)(bytes + 0x30) = opened;
    if (opened == 0) {
        bytes[1] = 3;
        *(s32 *)(bytes + 0x5C) = 0;
        sub_00169430(hn);
        return 0;
    }

    sz = sub_00169F20(opened);
    *(s32 *)(bytes + 0x10) = (s32)sz;
    *(s32 *)(bytes + 0x14) = (s32)((unsigned long long)sz >> 32);
    unit = (long long)*(s32 *)(bytes + 8);
    quot = sz / unit;
    if ((sz % unit) != 0) {
        quot += 1;
    }

    *(s32 *)(bytes + 0x18) = (s32)quot;
    return hn;
}
