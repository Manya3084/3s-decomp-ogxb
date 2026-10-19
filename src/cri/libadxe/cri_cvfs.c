/* cvFsCallUsrErrFn 0x16A270, cvFsError 0x16A290, getDevice 0x16A2B0,
 * toUpperStr 0x16A300, isExistDev 0x16A330, cvFsGetDefDev 0x16A360,
 * allocCvFsHn 0x16A370, releaseCvFsHn 0x16A3E0, getDevName 0x16A3F0,
 * getDefDev 0x16A4D0, cvFsClose 0x16A520,
 * cvFsTell 0x16A560, cvFsSeek 0x16A5B0, cvFsReqRd 0x16A600,
 * cvFsExecServer 0x16A650, cvFsGetStat 0x16A680, cvFsEntryErrFunc 0x16A6D0,
 * isNeedDevName 0x16A700, addDevName 0x16A730, addDevice 0x16A780,
 * cvFsSetDefDev 0x16A820, variousProc 0x16A8A0, cvFsOpen 0x16A8F0,
 * cvFsAddDev 0x16AA00.
 *
 * Named devices are 32 slots of 0x10 at 0x7A5880. The default-device
 * buffer is 16 bytes at 0x7A5600. Handles are 40 slots of 8 at 0x7A5610.
 * cvfs_errfn is 0x7A5A80 and cvfs_errobj is 0x7A5A84. addDevName's scratch
 * is 0x7A5750. cvfs_build is the pointer at 0x2E0200. Its value is
 * 0x2E0204, the string "\nCVFS/XBOX Ver.2.35 Build:Feb 13 2004 21:08:02\n".
 *
 * toUpperStr, isExistDev, isNeedDevName, addDevName, and addDevice take
 * some arguments in registers. The C below uses ordinary arguments.
 */

#include "types.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define CVFS_DEVICE_MAX 32
#define CVFS_HANDLE_MAX 40
#define CVFS_MAX_NAME_LENGTH 0x129

typedef void (*CVFSErrFn)(void *object, const char *msg, s32 arg2);

typedef struct CVFSDevice {
    void (*ExecServer)(void);
    void (*EntryErrFunc)(CVFSErrFn function, void *object);
    u8 gap08[8];
    void *(*Open)(char *name, void *arg1, s32 arg2);
    void (*Close)(void *fd);
    s32 (*Seek)(void *fd, s32 offset, s32 whence);
    s32 (*Tell)(void *fd);
    s32 (*ReqRd)(void *fd, s32 len, void *buf);
    u8 gap24[8];
    s32 (*GetStat)(void *fd);
    u8 gap30[0x30];
    s32 (*OptFn1)(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
} CVFSDevice;

typedef struct {
    CVFSDevice *device;
    void *fd;
} CVFSHandle;

typedef struct {
    CVFSDevice *device;
    char name[12];
} CVFSNamedDevice;

#if defined(__i386__)
_Static_assert(offsetof(CVFSDevice, EntryErrFunc) == 4, "EntryErrFunc");
_Static_assert(offsetof(CVFSDevice, Close) == 0x14, "Close");
_Static_assert(offsetof(CVFSDevice, Seek) == 0x18, "Seek");
_Static_assert(offsetof(CVFSDevice, Tell) == 0x1C, "Tell");
_Static_assert(offsetof(CVFSDevice, ReqRd) == 0x20, "ReqRd");
_Static_assert(offsetof(CVFSDevice, GetStat) == 0x2C, "GetStat");
_Static_assert(offsetof(CVFSDevice, OptFn1) == 0x60, "OptFn1");
_Static_assert(sizeof(CVFSNamedDevice) == 0x10, "named device");
_Static_assert(sizeof(CVFSHandle) == 8, "handle");
#endif

extern CVFSNamedDevice cvfs_named_devices[CVFS_DEVICE_MAX];
extern char cvfs_def_dev[16];
extern CVFSHandle cvfs_handles[CVFS_HANDLE_MAX];
extern void (*cvfs_errfn)(void *object, const char *msg, s32 arg2);
extern void *cvfs_errobj;
char *volatile cvfs_build = "\nCVFS/XBOX Ver.2.35 Build:Feb 13 2004 21:08:02\n";
extern char cvfs_path_buf[];

void cvFsCallUsrErrFn(void *object, const char *msg, s32 arg2) {
    (void)object;

    if (cvfs_errfn != 0) {
        cvfs_errfn(cvfs_errobj, msg, arg2);
    }
}

void cvFsError(const char *msg) {
    cvFsCallUsrErrFn(&cvfs_errobj, msg, 0);
}

CVFSDevice *getDevice(const char *name) {
    s32 len = (s32)strlen(name);
    s32 i;

    for (i = 0; i < CVFS_DEVICE_MAX; i++) {
        if (strncmp(name, cvfs_named_devices[i].name, (size_t)len) == 0) {
            return cvfs_named_devices[i].device;
        }
    }

    return 0;
}

void toUpperStr(char *str) {
    u32 len = strlen(str);
    u32 i;

    for (i = 0; i < len + 1; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (char)(str[i] - 0x20);
        }
    }
}

s32 isExistDev(const char *name, s32 length) {
    s32 i;

    for (i = 0; i < CVFS_DEVICE_MAX; i++) {
        if (strncmp(name, cvfs_named_devices[i].name, (size_t)length) == 0) {
            return 1;
        }
    }

    return 0;
}

char *cvFsGetDefDev(void) {
    return cvfs_def_dev;
}

CVFSHandle *allocCvFsHn(void) {
    s32 i;

    for (i = 0; i < CVFS_HANDLE_MAX; i++) {
        if (cvfs_handles[i].fd == 0) {
            break;
        }
    }

    if (i == CVFS_HANDLE_MAX) {
        return 0;
    }

    return &cvfs_handles[i];
}

void releaseCvFsHn(CVFSHandle *handle) {
    handle->fd = 0;
    handle->device = 0;
}

/* getDevName 0x16A3F0.
 *
 * Matches the PS2 body. A null path returns. The scan stops at ':' or
 * a null, and it is unrolled by 3. The limit is 0x129. The scanner
 * start at 0x16A450 is the inc eax inside that scan. A missing colon
 * copies the name onto the device buffer and clears the filename.
 * strlen and memcpy are inlined. A colon is skipped. When that index
 * is 2, the filename is cleared and the device copy starts at 0.
 * This then tail-jumps to toUpperStr. The filename stays in edx, which
 * is what toUpperStr reads. The only caller is cvFsOpen. The jmp is at
 * 0x16A4C5 and the int3s run through 0x16A4CF.
 */

void getDevName(char *filename, char *device_name, const char *full_path) {
    s32 i;
    s32 j;

    if (full_path == 0) {
        return;
    }

    i = 0;
    while (i < CVFS_MAX_NAME_LENGTH && full_path[i] != ':' && full_path[i] != '\0') {
        filename[i] = full_path[i];
        i += 1;
    }

    if (full_path[i] == '\0') {
        filename[i] = '\0';
        memcpy(device_name, filename, strlen(filename) + 1);
        filename[0] = '\0';
        return;
    }

    filename[i] = '\0';
    i += 1;
    if (i == 2) {
        filename[0] = '\0';
        i = 0;
    }

    j = i;
    while (j < CVFS_MAX_NAME_LENGTH && full_path[j] != '\0') {
        device_name[j - i] = full_path[j];
        j += 1;
    }

    device_name[j - i] = '\0';
    toUpperStr(filename);
}

/* getDefDev 0x16A4D0.
 *
 * Matches the PS2 body. The bytes take the destination in eax.
 * strlen of the 16-byte buffer at 0x7A5600 runs first. An empty
 * buffer stores 0 and returns. Otherwise memcpy copies that length
 * plus the null. Both are inlined. The only callers are 0x16A8AA
 * and 0x16A8CA. The previous byte is an int3, and the ret at
 * 0x16A511 is followed by int3s through 0x16A51F.
 */

void getDefDev(char *out) {
    s32 len = (s32)strlen(cvfs_def_dev);

    if (cvfs_def_dev[0] == 0) {
        out[0] = 0;
        return;
    }

    memcpy(out, cvfs_def_dev, (size_t)len + 1);
}

void cvFsClose(CVFSHandle *handle) {
    if (handle == 0) {
        cvFsError("cvFsClose #1:handle error");
        return;
    }

    if (handle->device->Close != 0) {
        handle->device->Close(handle->fd);
        releaseCvFsHn(handle);
        return;
    }

    cvFsError("cvFsClose #2:vtbl error");
}

s32 cvFsTell(CVFSHandle *handle) {
    s32 offset;

    if (handle == 0) {
        cvFsError("cvFsTell #1:handle error");
        return 0;
    }

    if (handle->device->Tell != 0) {
        offset = handle->device->Tell(handle->fd);
    } else {
        offset = 0;
        cvFsError("cvFsTell #2:vtbl error");
    }

    return offset;
}

s32 cvFsSeek(CVFSHandle *handle, s32 offset, s32 whence) {
    s32 result;

    if (handle == 0) {
        cvFsError("cvFsSeek #1:handle error");
        return 0;
    }

    if (handle->device->Seek != 0) {
        result = handle->device->Seek(handle->fd, offset, whence);
    } else {
        result = 0;
        cvFsError("cvFsSeek #2:vtbl error");
    }

    return result;
}

s32 cvFsReqRd(CVFSHandle *handle, s32 len, void *buf) {
    s32 result;

    if (handle == 0) {
        cvFsError("cvFsReqRd #1:handle error");
        return 0;
    }

    if (handle->device->ReqRd != 0) {
        result = handle->device->ReqRd(handle->fd, len, buf);
    } else {
        result = 0;
        cvFsError("cvFsReqRd #2:vtbl error");
    }

    return result;
}

void cvFsExecServer(void) {
    s32 i;

    for (i = 0; i < CVFS_DEVICE_MAX; i++) {
        CVFSDevice *device = cvfs_named_devices[i].device;

        if (device != 0 && device->ExecServer != 0) {
            device->ExecServer();
        }
    }
}

s32 cvFsGetStat(CVFSHandle *handle) {
    s32 stat = 3;

    if (handle == 0) {
        cvFsError("cvFsGetStat #1:handle error");
        return 3;
    }

    if (handle->device->GetStat != 0) {
        stat = handle->device->GetStat(handle->fd);
    } else {
        cvFsError("cvFsGetStat #2:vtbl error");
    }

    return stat;
}

void cvFsEntryErrFunc(void (*function)(void *object, const char *msg, s32 arg2), void *object) {
    if (function == 0) {
        cvfs_errfn = 0;
        cvfs_errobj = 0;
        return;
    }

    cvfs_errfn = function;
    cvfs_errobj = object;
}

s32 isNeedDevName(const char *device_name) {
    CVFSDevice *device = getDevice(device_name);

    if (device == 0 || device->OptFn1 == 0) {
        return 0;
    }

    return device->OptFn1(0, 0x64, 0, 0);
}

void addDevName(const char *device_name, char *out) {
    if (device_name == 0) {
        device_name = cvFsGetDefDev();
    }

    if (isNeedDevName(device_name) == 1) {
        strcpy(cvfs_path_buf, out);
        sprintf(out, "%s:%s", device_name, cvfs_path_buf);
    }
}

CVFSDevice *addDevice(char *device_name, CVFSDevice *(*device_provider)(void)) {
    CVFSDevice *device;
    s32 i;

    toUpperStr(device_name);
    device = device_provider();

    if (getDevice(device_name) != 0) {
        return device;
    }

    for (i = 0; i < CVFS_DEVICE_MAX; i++) {
        if (cvfs_named_devices[i].name[0] == 0) {
            break;
        }
    }

    if (i == CVFS_DEVICE_MAX) {
        return 0;
    }

    cvfs_named_devices[i].device = device;
    memcpy(cvfs_named_devices[i].name, device_name, strlen(device_name) + 1);
    return device;
}

void cvFsSetDefDev(char *device_name) {
    s32 length;

    if (device_name == 0) {
        cvFsError("cvFsSetDefDev #1:illegal device name");
        return;
    }

    length = (s32)strlen(device_name);

    if (length == 0) {
        cvfs_def_dev[0] = 0;
        return;
    }

    toUpperStr(device_name);

    if (isExistDev(device_name, length) == 1) {
        memcpy(cvfs_def_dev, device_name, (size_t)length + 1);
        return;
    }

    cvFsError("cvFsSetDefDev #2:unknown device name");
}

/* variousProc 0x16A8A0.
 *
 * Matches the PS2 body. The filename arrives in edi, the device buffer
 * in eax, and the path in ebx. The device buffer stays in esi.
 * getDefDev and addDevName are register calls. getDevice is a stack
 * call. strcpy is a byte loop. There are no dword immediates. The only
 * caller is cvFsOpen at 0x16A967. The previous byte is an int3. The
 * ret at 0x16A8EF has no padding, and cvFsOpen begins on the next byte.
 */

CVFSDevice *variousProc(char *filename, char *device_name, const char *full_path) {
    CVFSDevice *device;

    if (filename[0] == 0) {
        getDefDev(filename);

        if (filename[0] == 0) {
            return 0;
        }
    }

    addDevName(filename, device_name);
    device = getDevice(filename);

    if (device == 0) {
        getDefDev(filename);
        device = getDevice(filename);

        if (device == 0) {
            return 0;
        }

        strcpy(device_name, full_path);
    }

    return device;
}

/* cvFsOpen 0x16A8F0.
 *
 * Matches the PS2 body. A null name, or an empty device name, reports
 * #1 and returns 0. Both paths use the same string. A failed alloc
 * reports #3 and returns 0. getDevName fills the two 0x12A buffers. The
 * frame is 0x258 bytes. variousProc takes the filename in edi, the
 * device buffer in eax, and the path in ebx. A null device is stored,
 * the handle is released, and this reports #4.
 * A null Open at +0x10 releases the handle and reports #5. A null
 * result releases the handle and reports #6. Otherwise the result is
 * stored at +4 and this returns the handle. The only caller is
 * 0x16E31E. The ret at 0x16A8EF is the previous byte.
 */

CVFSHandle *cvFsOpen(const char *fname, void *arg1, s32 arg2) {
    char filename[CVFS_MAX_NAME_LENGTH + 1];
    char device_name[CVFS_MAX_NAME_LENGTH + 1];
    CVFSHandle *handle;
    CVFSDevice *device;

    if (fname == 0) {
        cvFsError("cvFsOpen #1:illegal file name");
        return 0;
    }

    getDevName(filename, device_name, fname);
    if (device_name[0] == 0) {
        cvFsError("cvFsOpen #1:illegal file name");
        return 0;
    }

    handle = allocCvFsHn();
    if (handle == 0) {
        cvFsError("cvFsOpen #3:failed handle alloced");
        return 0;
    }

    device = variousProc(filename, device_name, fname);
    handle->device = device;
    if (device == 0) {
        releaseCvFsHn(handle);
        cvFsError("cvFsOpen #4:device not found");
        return 0;
    }

    if (device->Open != 0) {
        handle->fd = device->Open(device_name, arg1, arg2);
    } else {
        releaseCvFsHn(handle);
        cvFsError("cvFsOpen #5:vtbl error");
        return 0;
    }

    if (handle->fd == 0) {
        releaseCvFsHn(handle);
        cvFsError("cvFsOpen #6:open failed");
        return 0;
    }

    return handle;
}

void cvFsAddDev(char *device_name, CVFSDevice *(*device_provider)(void), s32 arg2) {
    CVFSDevice *device;

    (void)arg2;
    cvfs_build;

    if (device_name == 0) {
        cvFsError("cvFsAddDev #1:illegal device name");
        return;
    }

    if (device_provider == 0) {
        cvFsError("cvFsAddDev #2:illegal I/F func name");
        return;
    }

    device = addDevice(device_name, device_provider);

    if (device == 0) {
        cvFsError("cvFsAddDev #3:failed added a device");
        return;
    }

    if (device->EntryErrFunc != 0) {
        device->EntryErrFunc(cvFsCallUsrErrFn, 0);
    }
}
