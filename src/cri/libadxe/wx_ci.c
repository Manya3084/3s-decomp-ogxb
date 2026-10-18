/* wxCiGetFileSize 0x169310.
 *
 * A null name reports E0092901 and returns 0. Otherwise the name is
 * copied into a 0x104 buffer and the low half of the size comes from 0x1692E0.
 * 0x168FE0 and 0x169190 are xb_wxci_BuildPath and wxci_call_errfn. The only
 * reference is the
 * pointer at 0x43C900, eight bytes into the device table at 0x43C8F8.
 */

#include "types.h"

#include <string.h>

void wxci_call_errfn(const char *fname, const char *msg);
extern void xb_wxci_BuildPath(char *dst, const char *src);
long long xb_wxci_GetFileSizeByName(char *path);
s32 xb_wxci_IsReading(void);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
extern s32 dat_007A55D8; /* 0x7A55D8 */
void *wxci_alloc(void);
extern void xb_wxci_SetupHandle(void *hn);
void wxci_free(void *hn);
extern s32 xb_wxci_OpenFile(char *path);
long long xb_wxci_GetHandleFileSize(s32 handle);
extern s32 (*wxci_open_cb)(char *path, s32 *size, s32 *mode); /* 0x7A55F0 */
extern char *volatile wxci_build; /* wxci_build is 0x2DFD8C */
extern u8 wxci_obj[40][0x168]; /* wxci_obj is 0xCE5440 */
extern u8 wxci_rootdir[0x104]; /* wxci_rootdir is 0xCE8C80 */
extern u8 D_0043C8F8[];
extern void (*wxci_errfn)(void *obj, const char *msg, const char *fname); /* wxci_errfn is 0x7A55D0 */
extern void *wxci_errobj; /* wxci_errobj is 0x7A55D4 */
extern void (*D_007A55E4)(s32 arg);
extern s32 (*D_007A55EC)(char *path);
extern s32 D_007A55F8;
extern volatile s32 D_007A55FC;
extern u8 D_007A55B4[];
extern void (XB_STDCALL *D_00218DC0)(void *cs);
extern void (XB_STDCALL *D_00218DC4)(void *cs);
extern s32 XB_STDCALL CloseHandle(s32 handle);
extern u32 XB_STDCALL GetFileSize(s32 handle, u32 *hi);
extern s32 XB_STDCALL GetThreadPriority(void *thread);
extern s32 SVM_TestAndSet(s32 *mem);
extern void xb_wxci_WaitTransfer(void *hn);
extern void xb_wxCiExecHndl(void *hn);
s32 wxCiGetFileSize(const char *fname);
s32 xb_wxci_ForceUnlock(void);
void xb_wxci_Relock(s32 n);
void xb_wxci_EnterCs(void);
void xb_wxci_LeaveCs(void);
void wxCiStopTr(void *hn);

s32 wxCiGetFileSize(const char *fname) {
    char path[0x104];

    if (fname == 0) {
        wxci_call_errfn(fname, "E0092901:fname is null.(wxCiGetFileSize)");
        return 0;
    }

    xb_wxci_BuildPath(path, fname);
    return (s32)xb_wxci_GetFileSizeByName(path);
}

/* wxCiOpen 0x16A050.
 *
 * A null name reports E0092908 and returns 0. A non-zero rw reports
 * E0092909 and returns 0. A failed alloc reports E0092910 and returns 0.
 * The handle is 0x168 bytes. The second argument is unused. The callback
 * at 0x7A55F0 may supply a size and a mode. Mode 2 stores 2 at +0x164,
 * clears +0x2C, and the fallback open temporarily replaces the first
 * byte of the path at +0x60 with 'z'. The fallback ceiling-divides the
 * new size by the s32 at +8. 0x169370, 0x1693B0, 0x169430, 0x169E20, and
 * 0x169F20 are wxci_alloc, xb_wxci_SetupHandle, wxci_free, xb_wxci_OpenFile,
 * and xb_wxci_GetHandleFileSize. The only reference is the pointer at
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
        wxci_call_errfn(fname, "E0092908:fname is null.(wxCiOpen)");
        return 0;
    }

    if (rw != 0) {
        wxci_call_errfn(0, "E0092909:rw is illigal.(wxCiOpen)");
        return 0;
    }

    hn = wxci_alloc();
    if (hn == 0) {
        wxci_call_errfn(0, "E0092910:not enough handle resource.(wxCiOpen)");
        return 0;
    }

    memset(hn, 0, (size_t)0x168);
    bytes = hn;
    xb_wxci_BuildPath(path, fname);
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
    xb_wxci_SetupHandle(hn);
    if (*(s32 *)(bytes + 0x30) != 0) {
        return hn;
    }

    dst = (char *)(bytes + 0x60);
    if (*(s32 *)(bytes + 0x164) == 2) {
        saved = dst[0];
        dst[0] = 'z';
        opened = xb_wxci_OpenFile(dst);
        dst[0] = saved;
    } else {
        opened = xb_wxci_OpenFile(dst);
    }

    *(s32 *)(bytes + 0x30) = opened;
    if (opened == 0) {
        bytes[1] = 3;
        *(s32 *)(bytes + 0x5C) = 0;
        wxci_free(hn);
        return 0;
    }

    sz = xb_wxci_GetHandleFileSize(opened);
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
 * E0109153. 0x169290 is xb_wxci_IsReading. The only reference is the pointer
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
        wxci_call_errfn(hn, "E0092912:handl is null.");
        return 0;
    }

    if (nsct < 0) {
        wxci_call_errfn(hn, "E0092913:nsct < 0.(wxCiReqRd)");
        return 0;
    }

    bytes = hn;
    if (nsct == 0) {
        bytes[1] = 1;
        return 0;
    }

    sub_0016AA60();
    if (xb_wxci_IsReading() == 1) {
        sub_0016AA70();
        return 0;
    }

    nreq = nsct;
    size_lo = *(s32 *)(bytes + 0x10);
    size_hi = *(s32 *)(bytes + 0x14);
    if (size_lo == -2048) {
        if (size_hi == 0x7FFFFFFF) {
            sz = xb_wxci_GetFileSizeByName((char *)(bytes + 0x60));
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
        sub_0016AA70();
        return 0;
    }

    *(s32 *)(bytes + 0x48) = (s32)off;
    *(s32 *)(bytes + 0x4C) = (s32)((unsigned long long)off >> 32);
    *(s32 *)(bytes + 0x50) = nbytes;
    bytes[1] = 2;
    *(s32 *)(bytes + 0x54) = 1;
    *(s32 *)(bytes + 0x58) = 0;
    sub_0016AA70();
    if (dat_007A55D8 == 0) {
        if (((nbytes % 0x800) != 0) || (nbytes < 0)) {
            wxci_call_errfn(0, "E0109151:illegal read size.");
            return 0;
        }

        if ((off % 0x800) != 0) {
            wxci_call_errfn(0, "E0109152:illegal seek position.");
            return 0;
        }

        if (((u32)buf & 3u) != 0) {
            wxci_call_errfn(0, "E0109153:illegal buffer alignment.");
            return 0;
        }
    }

    if (buf == 0) {
        wxci_call_errfn(hn, "E0092914:buf is null.(wxCiReqRd)");
        return 0;
    }

    return *(s32 *)(bytes + 0x28);
}

/* The small wxCi entry points and helpers. Forty handles of 0x168 bytes
 * are at 0xCE5440: +0 in use, +1 state (2 while reading), +8 the sector
 * length, +0x10 the 64-bit size, +0x1C the position, +0x20 the 64-bit
 * transfer count, +0x2C the cached-file flag, +0x30 the file handle, +0x44
 * an event handle. 0x7A55B4 is the critical section; 0x7A55F8 enables it
 * and 0x7A55FC counts its depth. */

void *wxCiGetInterface(void) {
    return D_0043C8F8;
}

void xb_wxci_Init(void) {
    (void)wxci_build;
    memset(wxci_rootdir, 0, sizeof(wxci_rootdir));
    memset(wxci_obj, 0, sizeof(wxci_obj));
}

void wxci_call_errfn(const char *fname, const char *msg) {
    if (wxci_errfn != 0) {
        wxci_errfn(wxci_errobj, msg, fname);
    }
}

s32 xb_wxci_IsReading(void) {
    s32 i;

    for (i = 0; i < 40; i++) {
        if (wxci_obj[i][0] != 0 && wxci_obj[i][1] == 2) {
            return 1;
        }
    }

    return 0;
}

void wxCiEntryErrFunc(void (*func)(void *obj, const char *msg, const char *fname), void *obj) {
    wxci_errfn = func;
    wxci_errobj = obj;
}

long long xb_wxci_GetFileSizeByName(char *path) {
    long long size;

    if (D_007A55EC != 0) {
        size = D_007A55EC(path);

        if (!(size < 0)) {
            return size;
        }
    }

    return 0x7FFFFFFFFFFFF800LL;
}

long long xb_wxci_GetHandleSize64(void *hn) {
    return *(long long *)((u8 *)hn + 0x10);
}

void *wxci_alloc(void) {
    s32 i;
    void *hn = 0;

    for (i = 0; i < 40; i++) {
        if (wxci_obj[i][0] == 0) {
            hn = wxci_obj[i];
            break;
        }
    }

    return hn;
}

void wxci_free(void *hn) {
    if (*(s32 *)((u8 *)hn + 0x44) != 0) {
        CloseHandle(*(s32 *)((u8 *)hn + 0x44));
    }

    memset(hn, 0, 0x168);
}

s32 wxCiTell(void *hn) {
    if (hn == 0) {
        wxci_call_errfn(hn, "E0092912:handl is null.");
        return 0;
    }

    return *(s32 *)((u8 *)hn + 0x1C);
}

s32 wxCiGetStat(void *hn) {
    if (hn == 0) {
        wxci_call_errfn(hn, "E0092912:handl is null.");
        return 0;
    }

    return ((s8 *)hn)[1];
}

s32 wxCiGetSctLen(void *hn) {
    if (hn == 0) {
        wxci_call_errfn(hn, "E0040301:handl is null.");
        return 0;
    }

    return *(s32 *)((u8 *)hn + 8);
}

s32 wxCiGetNumTr(void *hn) {
    if (hn == 0) {
        wxci_call_errfn(hn, "E0092912:handl is null.");
        return 0;
    }

    return *(s32 *)((u8 *)hn + 0x20);
}

void xb_wxfic_CallErrFn(const char *fname, const char *msg) {
    wxci_call_errfn(fname, msg);
}

void xb_wxfic_BuildPath(char *dst, const char *src) {
    xb_wxci_BuildPath(dst, src);
}

s32 xb_wxci_GetNumTrUpper(void *hn) {
    return (s32)(*(unsigned long long *)((u8 *)hn + 0x20) >> 32);
}

s32 xb_wxci_GetFileSizeThunk(const char *fname) {
    return wxCiGetFileSize(fname);
}

void xb_wxci_EnterCs(void) {
    if (D_007A55F8 > 0) {
        D_00218DC4(D_007A55B4);
        D_007A55FC++;
    }
}

void xb_wxci_LeaveCs(void) {
    if (D_007A55F8 > 0) {
        if (--D_007A55FC < 0) {
            wxci_call_errfn(0, "E2003062702 : Unlock was performed before lock.");
            return;
        }

        D_00218DC0(D_007A55B4);
    }
}

void wxCiStopTr(void *hn) {
    if (hn == 0) {
        wxci_call_errfn(hn, "E0092912:handl is null.");
        return;
    }

    if (((u8 *)hn)[1] != 0) {
        if (((u8 *)hn)[1] == 2) {
            xb_wxci_WaitTransfer(hn);
            ((u8 *)hn)[1] = 0;
        }

        *(s32 *)((u8 *)hn + 0x54) = 0;
    }
}

void xb_wxci_CloseFileHandle(s32 handle) {
    s32 n = xb_wxci_ForceUnlock();

    xb_wxci_EnterCs();
    CloseHandle(handle);
    xb_wxci_LeaveCs();
    xb_wxci_Relock(n);
}

long long xb_wxci_GetHandleFileSize(s32 handle) {
    u32 lo;
    u32 hi;

    xb_wxci_EnterCs();
    lo = GetFileSize(handle, &hi);
    xb_wxci_LeaveCs();
    return (long long)hi * 0x100000000LL + lo;
}

void wxCiExecServer(void) {
    s32 i;

    for (i = 0; i < 40; i++) {
        if (wxci_obj[i][0] == 1) {
            xb_wxCiExecHndl(wxci_obj[i]);
        }
    }

    if (xb_wxci_IsReading() != 1 && D_007A55E4 != 0) {
        D_007A55E4(0);
    }
}

void xb_wxci_Close(void *hn) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 0x2C) == 0 && *(s32 *)(bytes + 0x30) != 0) {
        xb_wxci_CloseFileHandle(*(s32 *)(bytes + 0x30));
        *(s32 *)(bytes + 0x30) = 0;
    }

    sub_0016AA60();
    bytes[0] = 0;
    wxci_free(hn);
    sub_0016AA70();
}

void wxCiClose(void *hn) {
    u8 *bytes = hn;

    if (hn != 0) {
        wxCiStopTr(hn);

        if (*(s32 *)(bytes + 0x2C) == 0) {
            xb_wxci_Close(hn);
        } else if (bytes[0] == 1) {
            bytes[0] = 0;
            wxci_free(hn);
        }
    }
}

s32 xb_wxci_TestAndSet(s32 *mem) {
    return SVM_TestAndSet(mem);
}

s32 xb_wxci_IsTimeCritical(void) {
    return GetThreadPriority((void *)-2) == 15;
}

s32 xb_wxci_ForceUnlock(void) {
    s32 n = 0;

    while (xb_wxci_IsTimeCritical() == 1) {
        sub_0016AA70();
        n++;
        xb_wxfic_CallErrFn(0, "E02082301 : force unlocked.\n");
    }

    return n;
}

void xb_wxci_Relock(s32 n) {
    for (; n > 0; n--) {
        sub_0016AA60();
    }
}
