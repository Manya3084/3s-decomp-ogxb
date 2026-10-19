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
#include <stdio.h>

void wxci_call_errfn(const char *fname, const char *msg);
void xb_wxci_BuildPath(char *dst, const char *src);
long long xb_wxci_GetFileSizeByName(char *path);
s32 xb_wxci_IsReading(void);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
extern s32 dat_007A55D8; /* 0x7A55D8 */
void *wxci_alloc(void);
void xb_wxci_SetupHandle(void *hn);
void wxci_free(void *hn);
s32 xb_wxci_OpenFile(char *path);
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
void xb_wxci_WaitTransfer(void *hn);
void xb_wxCiExecHndl(void *hn);
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

/* The read path. */

typedef struct {
    u32 lo;
    u32 hi;
} WxU64;

extern s32 D_007A55DC;
extern s32 D_007A55E0;
extern s32 (*D_007A55F4)(s32 file, void *buf, u32 n, u32 *nread, void *ovl);
extern char wxfic_msg[];
extern s32 XB_STDCALL GetOverlappedResult(s32 file, void *ovl, u32 *n, s32 wait);
extern u32 XB_STDCALL GetLastError(void);
extern s32 XB_STDCALL ReadFile(s32 file, void *buf, u32 n, u32 *nread, void *ovl);
extern u32 XB_STDCALL SetFilePointer(s32 file, s32 lo, s32 *hi, u32 method);
extern s32 XB_STDCALL CreateEventA(void *attr, s32 manual, s32 initial, const char *name);
extern void QueryPerformanceCounter(WxU64 *out);
extern void QueryPerformanceFrequency(WxU64 *out);

#define WX_TICKS(v) ((long long)(((unsigned long long)(v).hi << 32) | (v).lo))

/* xb_wxci_BuildPath 0x168FE0.
 *
 * The full path of src: a drive path is kept, a rooted one gets the
 * root's drive, and a relative one the root directory; no name gives the
 * root itself. */

void xb_wxci_BuildPath(char *dst, const char *src) {
    if (src == 0) {
        strcpy(dst, (char *)wxci_rootdir);
        return;
    }

    if (*src == 0) {
        strcpy(dst, (char *)wxci_rootdir);
    } else if (*src == '\\') {
        dst[0] = wxci_rootdir[0];
        dst[1] = wxci_rootdir[1];
        dst[2] = 0;
    } else if (src[1] == ':') {
        dst[0] = 0;
    } else {
        strcpy(dst, (char *)wxci_rootdir);
    }

    strcat(dst, src);
}

/* xb_wxci_WaitWithUnlock 0x169090.
 *
 * Waits about a millisecond with the server lock released. */

void xb_wxci_WaitWithUnlock(void) {
    WxU64 start;
    WxU64 now;
    WxU64 freq;
    s32 n;

    n = xb_wxci_ForceUnlock();
    QueryPerformanceCounter(&start);
    n += xb_wxci_ForceUnlock();
    QueryPerformanceCounter(&now);
    QueryPerformanceFrequency(&freq);

    while (WX_TICKS(now) - WX_TICKS(start) <= WX_TICKS(freq) / 1000 && WX_TICKS(now) > WX_TICKS(start)) {
        n += xb_wxci_ForceUnlock();
        QueryPerformanceCounter(&now);
        QueryPerformanceFrequency(&freq);
    }

    xb_wxci_Relock(n);
}

/* xb_wxci_CheckOverlapped 0x1691B0.
 *
 * Polls the handle's overlapped read: on completion takes the byte
 * count (or ends the handle when a stop was requested at 0x7A55E0); on
 * an error other than "still pending" reports it and ends the handle.
 * With synchronous reads (0x7A55D8) the busy flag just follows
 * 0x7A55DC. */

void xb_wxci_CheckOverlapped(void *hn) {
    u8 *bytes = hn;
    u32 nread;
    u32 err;

    if (dat_007A55D8 != 0) {
        *(s32 *)(bytes + 0x58) = D_007A55DC;
        return;
    }

    if (GetOverlappedResult(*(s32 *)(bytes + 0x30), bytes + 0x34, &nread, 0) != 0) {
        *(s32 *)(bytes + 0x58) = 0;

        if (D_007A55E0 == 1) {
            bytes[1] = 3;
            D_007A55E0 = 0;
        } else {
            *(s32 *)(bytes + 0x50) = nread;
        }

        return;
    }

    err = GetLastError();

    if (err == 0x26) {
        wxci_call_errfn(0, "E02052003:Reached the end of the file during asynchronous operation.\n");
        bytes[1] = 3;
    } else if (err == 0x3E3) {
        wxci_call_errfn(0, "E02052004:The file reading was aborted.\n");
        bytes[1] = 3;
    } else if (err != 0x3E4 && err != 0x3E5) {
        sprintf(wxfic_msg, "E02052005:The reading error occurred. (%d)\n", err);
        wxci_call_errfn(0, wxfic_msg);
        bytes[1] = 3;
    }

    if (bytes[1] == 3) {
        *(s32 *)(bytes + 0x58) = 0;
    }
}

/* xb_wxci_SetupHandle 0x1693B0.
 *
 * Resets a handle for a new file of the size at +0x10: 0x800-byte
 * sectors, position 0, no transfer, and a fresh event for its
 * overlapped reads. */

void xb_wxci_SetupHandle(void *hn) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 0x44) != 0) {
        CloseHandle(*(s32 *)(bytes + 0x44));
    }

    *(s32 *)(bytes + 8) = 0x800;
    *(s32 *)(bytes + 0x18) =
        (s32)((((long long)*(s32 *)(bytes + 0x14) << 32 | *(u32 *)(bytes + 0x10)) + 0x7FF) / 0x800);
    *(s32 *)(bytes + 0x1C) = 0;
    *(s32 *)(bytes + 4) = 0;
    *(s32 *)(bytes + 0x28) = 0;
    *(s32 *)(bytes + 0x20) = 0;
    *(s32 *)(bytes + 0x24) = 0;
    bytes[1] = 0;
    *(s32 *)(bytes + 0x54) = 0;
    *(s32 *)(bytes + 0x58) = 0;
    memset(bytes + 0x34, 0, 0x14);
    *(s32 *)(bytes + 0x44) = CreateEventA(0, 1, 0, 0);
    bytes[0] = 1;
}

/* wxCiSeek 0x169450.
 *
 * Moves the sector position (from the start, the current position or the
 * end), clamped to the file. */

s32 wxCiSeek(void *hn, s32 ofst, s32 whence) {
    u8 *bytes = hn;
    s32 pos;

    if (hn == 0) {
        wxci_call_errfn(hn, "E0092912:handl is null.");
        return 0;
    }

    sub_0016AA60();

    if (whence == 0) {
        *(s32 *)(bytes + 0x1C) = ofst;
    } else if (whence == 2) {
        *(s32 *)(bytes + 0x1C) = *(s32 *)(bytes + 0x18) + ofst;
    } else if (whence == 1) {
        *(s32 *)(bytes + 0x1C) += ofst;
    }

    pos = *(s32 *)(bytes + 0x1C);

    if (pos >= *(s32 *)(bytes + 0x18)) {
        pos = *(s32 *)(bytes + 0x18);
    }

    *(s32 *)(bytes + 0x1C) = pos;
    *(s32 *)(bytes + 0x1C) = pos > 0 ? pos : 0;
    sub_0016AA70();
    return *(s32 *)(bytes + 0x1C);
}

/* xb_wxci_WaitTransfer 0x1696F0.
 *
 * Waits for the handle's read to finish, giving up (and ending the
 * handle) after 25000 waits. */

void xb_wxci_WaitTransfer(void *hn) {
    u8 *bytes = hn;
    s32 i;

    for (i = 0; *(s32 *)(bytes + 0x58) != 0;) {
        xb_wxci_CheckOverlapped(hn);
        xb_wxci_WaitWithUnlock();

        if (++i >= 25000) {
            wxci_call_errfn(0, "E0109232:Timeout. (Waiting for transmission)");
            sub_0016AA60();
            bytes[1] = 3;
            *(s32 *)(bytes + 0x58) = 0;
            sub_0016AA70();
            return;
        }
    }
}

/* xb_wxci_CallReadHook 0x169B10.
 *
 * ReadFile, or the read hook at 0x7A55F4 when one is set. Static
 * (config/sf33rd/static.txt): retail passes all but the file in
 * registers. */

static s32 xb_wxci_CallReadHook(s32 file, void *buf, u32 n, u32 *nread, void *ovl) {
    if (D_007A55F4 != 0) {
        return D_007A55F4(file, buf, n, nread, ovl);
    }

    return ReadFile(file, buf, n, nread, ovl);
}

/* xb_wxci_StartRead 0x169B40.
 *
 * Issues the handle's read: overlapped from the offset at +0x48, or
 * synchronously after a seek when 0x7A55D8 is set. A failure is
 * reported and ends the handle unless the read is merely pending. */

s32 xb_wxci_StartRead(void *hn) {
    u8 *bytes = hn;
    s32 lo;
    s32 hi;
    u32 nread;
    s32 ok;
    u32 err;

    sub_0016AA60();
    *(s32 *)(bytes + 0x54) = 0;
    *(s32 *)(bytes + 0x58) = 1;
    D_007A55DC = 1;
    sub_0016AA70();

    if (dat_007A55D8 == 0) {
        *(s32 *)(bytes + 0x3C) = *(s32 *)(bytes + 0x48);
        *(s32 *)(bytes + 0x40) = *(s32 *)(bytes + 0x4C);
        ok = ReadFile(*(s32 *)(bytes + 0x30), *(void **)(bytes + 4), *(u32 *)(bytes + 0x50), 0, bytes + 0x34);
    } else {
        lo = *(s32 *)(bytes + 0x48);
        hi = *(s32 *)(bytes + 0x4C);
        xb_wxci_EnterCs();
        SetFilePointer(*(s32 *)(bytes + 0x30), lo, &hi, 0);
        xb_wxci_LeaveCs();
        ok = xb_wxci_CallReadHook(*(s32 *)(bytes + 0x30), *(void **)(bytes + 4), *(u32 *)(bytes + 0x50), &nread, 0);

        if (ok != 0 && nread == 0) {
            wxci_call_errfn(0, "E02052101:The reading start position is over the end of the file.\n");
            bytes[1] = 3;
        }

        *(u32 *)(bytes + 0x50) = nread;
    }

    D_007A55DC = 0;

    if (ok == 0) {
        sub_0016AA60();
        err = GetLastError();

        switch (err) {
        case 0x26:
            wxci_call_errfn(0, "E02052001:The reading start position is over the end of the file.\n");
            bytes[1] = 3;
            break;
        case 6:
            wxci_call_errfn(0, "E02040401:The reading error occurred.");
            bytes[1] = 3;
            break;
        case 0x1E:
            wxci_call_errfn(0, "E02040901:The reading error occurred.");
            bytes[1] = 3;
            break;
        case 8:
        case 0x6F8:
            wxci_call_errfn(0, "E02050801:Too many I/O requests.");
            bytes[1] = 3;
            break;
        case 0x3E5:
            break;
        default:
            sprintf(wxfic_msg, "E02052002:The reading error occurred. (%d)\n", err);
            wxci_call_errfn(0, wxfic_msg);
            bytes[1] = 3;
            break;
        }

        if (bytes[1] == 3) {
            *(s32 *)(bytes + 0x58) = 0;
        }

        sub_0016AA70();
    }

    return ok;
}

/* xb_wxCiExecHndl 0x169F60.
 *
 * Steps a reading handle: starts its read, polls it, and when it is
 * done pads the last sector with zeros, records the bytes moved and
 * advances the position. */

void xb_wxCiExecHndl(void *hn) {
    u8 *bytes = hn;
    s32 n;
    s32 rem;
    long long moved;

    if (!xb_wxci_TestAndSet((s32 *)(bytes + 0x5C))) {
        return;
    }

    if (bytes[1] == 2) {
        if (*(s32 *)(bytes + 0x54) == 1) {
            xb_wxci_StartRead(hn);
        }

        if (*(s32 *)(bytes + 0x58) == 1) {
            xb_wxci_CheckOverlapped(hn);

            if (*(s32 *)(bytes + 0x58) == 0 && bytes[1] != 3) {
                sub_0016AA60();
                n = *(s32 *)(bytes + 0x50);

                if ((rem = n % *(s32 *)(bytes + 8)) != 0) {
                    memset(*(u8 **)(bytes + 4) + n, 0, *(s32 *)(bytes + 8) - rem);
                }

                moved = (long long)*(s32 *)(bytes + 0x28) * *(s32 *)(bytes + 8);
                *(s32 *)(bytes + 0x20) = (s32)moved;
                *(s32 *)(bytes + 0x24) = (s32)(moved >> 32);
                *(s32 *)(bytes + 0x1C) += *(s32 *)(bytes + 0x28);
                bytes[1] = 1;
                sub_0016AA70();
            }
        }
    }

    *(s32 *)(bytes + 0x5C) = 0;
}

extern s32 XB_STDCALL XOpenSoundtrackSong(u32 id, s32 async);
extern s32 XB_STDCALL CreateFileA(const char *name, u32 access, u32 share, void *sa, u32 disp, u32 flags, s32 tmpl);
extern s32 SJRBF_GetBufSize(void *sj);
extern s32 xb_aixp_ReturnZero(void *obj);

/* wxCiSetSctLen 0x169780.
 *
 * Changes the sector length, keeping the byte position: the sector
 * count, position and transfer count are rescaled. The old length must
 * be a multiple of 32. */

void wxCiSetSctLen(void *hn, s32 len) {
    u8 *bytes = hn;
    long long pos;

    if (hn == 0) {
        wxci_call_errfn(0, "E0040302:handl is null.");
        return;
    }

    if (*(s32 *)(bytes + 8) % 32 != 0) {
        wxci_call_errfn(0, "E0040303:invalidate size.");
        return;
    }

    pos = (long long)*(s32 *)(bytes + 0x1C) * *(s32 *)(bytes + 8);
    *(s32 *)(bytes + 8) = len;
    *(s32 *)(bytes + 0x18) =
        (s32)((((long long)*(s32 *)(bytes + 0x14) << 32 | *(u32 *)(bytes + 0x10)) + (len - 1)) / len);
    *(s32 *)(bytes + 0x1C) = (s32)(pos / len);
    pos = (long long)*(s32 *)(bytes + 0x28) * len;
    *(s32 *)(bytes + 0x20) = (s32)pos;
    *(s32 *)(bytes + 0x24) = (s32)(pos >> 32);
}

/* xb_wxci_ParseHex 0x169860.
 *
 * The value of eight lower-case hex digits (a soundtrack song id). */

u32 xb_wxci_ParseHex(const char *str) {
    char digits[17];
    u32 v = 0;
    u32 i;
    u32 d;

    memcpy(digits, "0123456789abcdef", 17);

    for (i = 0; i < 8; i++) {
        v <<= 4;

        for (d = 0; d < 16; d++) {
            if (str[i] == digits[d]) {
                break;
            }
        }

        v += d;
    }

    return v;
}

/* xb_wxci_OpenSoundtrackSong 0x1698F0.
 *
 * Opens a soundtrack song by the id after the first three characters of
 * its name ("s:" names); asynchronously unless reads are synchronous. */

s32 xb_wxci_OpenSoundtrackSong(const char *name) {
    s32 h = XOpenSoundtrackSong(xb_wxci_ParseHex(name + 3), dat_007A55D8 == 0);

    if (h == -1) {
        sprintf(wxfic_msg, "E02082603:can not open '%s'.(err:%d)", name, GetLastError());
        wxci_call_errfn(0, wxfic_msg);
        return 0;
    }

    return h;
}

/* xb_wxci_SetRootDir 0x169950.
 *
 * Sets the root directory that relative names are read from: a drive
 * path as given, anything else under D:, always ending in a backslash.
 * No name (or an empty one) is ".". */

void xb_wxci_SetRootDir(const char *dir) {
    char buf[0x104];
    s32 len;

    if (dir != 0) {
        sprintf(buf, "%s", dir);
    } else {
        buf[0] = '.';
        buf[1] = 0;
    }

    if ((len = strlen(buf)) == 0) {
        buf[0] = '.';
        buf[1] = 0;
    }

    memset(wxci_rootdir, 0, sizeof(wxci_rootdir));

    if (buf[1] == ':' && len > 1) {
        strcpy((char *)wxci_rootdir, buf);
    } else {
        sprintf((char *)wxci_rootdir, buf[0] == '\\' ? "D:" : "D:\\");
        strcat((char *)wxci_rootdir, buf);
    }

    if (wxci_rootdir[strlen((char *)wxci_rootdir) - 1] != '\\') {
        strcat((char *)wxci_rootdir, "\\");
    }
}

/* wxCiOptFn1 0x169CC0.
 *
 * The device's option call: 0xC8 track count, 0xC9 ring buffer size,
 * 0xCB and 0xCD file size, 0x12B 1, 0x12C the 64-bit handle size;
 * 0xCA and 0xCC return 0, anything else -1. */

s32 wxCiOptFn1(void *hn, s32 opt) {
    switch (opt) {
    case 0xC8:
        return xb_wxci_GetNumTrUpper(hn);
    case 0xC9:
        return SJRBF_GetBufSize(hn);
    case 0xCA:
        return xb_aixp_ReturnZero(hn);
    case 0xCB:
        return xb_wxci_GetFileSizeThunk(hn);
    case 0xCC:
        return xb_aixp_ReturnZero(hn);
    case 0xCD:
        return xb_wxci_GetFileSizeThunk(hn);
    case 0x12B:
        return 1;
    case 0x12C:
        return (s32)xb_wxci_GetHandleSize64(hn);
    }

    return -1;
}

/* xb_wxci_OpenFile 0x169E20.
 *
 * Opens a file for reading (overlapped and unbuffered, or plain for
 * synchronous reads) with the server lock released; "s" names are
 * soundtrack songs. Returns the handle, or 0. */

s32 xb_wxci_OpenFile(char *path) {
    s32 n = xb_wxci_ForceUnlock();
    s32 h;

    if (path[0] == 's' || path[0] == 'S') {
        h = xb_wxci_OpenSoundtrackSong(path);
        xb_wxci_Relock(n);
        return h;
    }

    if (dat_007A55D8 == 0) {
        h = CreateFileA(path, 0x80000000, 3, 0, 3, 0x70000000, 0);
    } else {
        xb_wxci_EnterCs();
        h = CreateFileA(path, 0x80000000, 3, 0, 3, 0x10000000, 0);
        xb_wxci_LeaveCs();
    }

    if (h == -1) {
        sprintf(wxfic_msg, "E0092911:can not open '%s'.(err:%d)", path, GetLastError());
        wxci_call_errfn(0, wxfic_msg);
        xb_wxci_Relock(n);
        return 0;
    }

    xb_wxci_Relock(n);
    return h;
}
