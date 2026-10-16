/* wxCiGetFileSize 0x169310.
 *
 * A null name reports E0092901 and returns 0. Otherwise the name is
 * copied into a 0x104 buffer and the low half of the size comes from 0x1692E0.
 * 0x168FE0 and 0x169190 stay unnamed. The only reference is the
 * pointer at 0x43C900, eight bytes into the device table at 0x43C8F8.
 */

#include "types.h"

#include <string.h>

extern void sub_00169190(const char *fname, const char *msg);
extern void sub_00168FE0(char *dst, const char *src);
extern long long sub_001692E0(char *path);
extern s32 sub_00169290(void);
extern void ADXCRS_Lock(void);
extern void ADXCRS_Unlock(void);
extern s32 dat_007A55D8; /* 0x7A55D8 */
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
    return (s32)sub_001692E0(path);
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

/* wxCiReqRd 0x1694F0.
 *
 * A null handle reports E0092912 and returns 0. A negative count
 * reports E0092913 and returns 0. A zero count stores stat 1 and
 * returns 0. The name is on E0092913 and E0092914. A size of
 * 0x7FFFFFFF:FFFFF800 is refreshed from 0x1692E0 and ceiling-divided
 * by the s32 at +8. The request is capped at 0x200 sectors. A zero
 * byte count stores stat 1 unless stat is already 3. Otherwise stat
 * becomes 2. When 0x7A55D8 is 0, a size that is not a multiple of
 * 0x800 reports E0109151, an offset that is not a multiple of 0x800
 * reports E0109152, and a buffer that is not 4-byte aligned reports
 * E0109153. 0x169290 stays unnamed. The only reference is the pointer
 * at 0x43C918.
 */

s32 wxCiReqRd(void *hn, s32 nsct, void *buf) {
    u8 *bytes;
    s32 size_lo;
    s32 size_hi;
    s32 nreq;
    s32 remain;
    s32 count;
    s32 sec;
    s32 pos;
    s32 nbytes;
    long long sz;
    long long unit;
    long long quot;
    long long off;

    if (hn == 0) {
        sub_00169190(hn, "E0092912:handl is null.");
        return 0;
    }

    if (nsct < 0) {
        sub_00169190(hn, "E0092913:nsct < 0.(wxCiReqRd)");
        return 0;
    }

    bytes = hn;
    if (nsct == 0) {
        bytes[1] = 1;
        return 0;
    }

    ADXCRS_Lock();
    if (sub_00169290() == 1) {
        ADXCRS_Unlock();
        return 0;
    }

    nreq = nsct;
    size_lo = *(s32 *)(bytes + 0x10);
    size_hi = *(s32 *)(bytes + 0x14);
    if (size_lo == -2048) {
        if (size_hi == 0x7FFFFFFF) {
            sz = sub_001692E0((char *)(bytes + 0x60));
            size_lo = (s32)sz;
            size_hi = (s32)((unsigned long long)sz >> 32);
            *(s32 *)(bytes + 0x10) = size_lo;
            *(s32 *)(bytes + 0x14) = size_hi;
            unit = (long long)*(s32 *)(bytes + 8);
            quot = sz / unit;
            if ((sz % unit) != 0) {
                quot += 1;
            }
            *(s32 *)(bytes + 0x18) = (s32)quot;
        }

        if ((size_lo == -2048) && (size_hi == 0x7FFFFFFF)) {
            nreq = 0;
        }
    }

    *(void **)(bytes + 4) = buf;
    *(s32 *)(bytes + 0x20) = 0;
    *(s32 *)(bytes + 0x24) = 0;
    remain = *(s32 *)(bytes + 0x18) - *(s32 *)(bytes + 0x1C);
    if (nreq < remain) {
        count = nreq;
    } else {
        count = remain;
    }

    if (count >= 0x200) {
        count = 0x200;
    }

    *(s32 *)(bytes + 0x28) = count;
    pos = *(s32 *)(bytes + 0x1C);
    sec = *(s32 *)(bytes + 8);
    off = (long long)pos * (long long)sec;
    nbytes = sec * count;
    if (nbytes == 0) {
        if (bytes[1] != 3) {
            bytes[1] = 1;
        }
        ADXCRS_Unlock();
        return 0;
    }

    *(s32 *)(bytes + 0x48) = (s32)off;
    *(s32 *)(bytes + 0x4C) = (s32)((unsigned long long)off >> 32);
    *(s32 *)(bytes + 0x50) = nbytes;
    bytes[1] = 2;
    *(s32 *)(bytes + 0x54) = 1;
    *(s32 *)(bytes + 0x58) = 0;
    ADXCRS_Unlock();
    if (dat_007A55D8 == 0) {
        if (((nbytes % 0x800) != 0) || (nbytes < 0)) {
            sub_00169190(0, "E0109151:illegal read size.");
            return 0;
        }

        if ((off % 0x800) != 0) {
            sub_00169190(0, "E0109152:illegal seek position.");
            return 0;
        }

        if (((u32)buf & 3u) != 0) {
            sub_00169190(0, "E0109153:illegal buffer alignment.");
            return 0;
        }
    }

    if (buf == 0) {
        sub_00169190(hn, "E0092914:buf is null.(wxCiReqRd)");
        return 0;
    }

    return *(s32 *)(bytes + 0x28);
}
