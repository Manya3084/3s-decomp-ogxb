/* cvFsCallUsrErrFn 0x16A270, cvFsError 0x16A290, getDevice 0x16A2B0,
 * toUpperStr 0x16A300, isExistDev 0x16A330, cvFsGetDefDev 0x16A360,
 * allocCvFsHn 0x16A370, releaseCvFsHn 0x16A3E0, cvFsClose 0x16A520,
 * cvFsTell 0x16A560, cvFsSeek 0x16A5B0, cvFsReqRd 0x16A600,
 * cvFsExecServer 0x16A650, cvFsGetStat 0x16A680, cvFsEntryErrFunc 0x16A6D0,
 * isNeedDevName 0x16A700, addDevName 0x16A730, addDevice 0x16A780,
 * cvFsSetDefDev 0x16A820, cvFsAddDev 0x16AA00.
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
extern void (*cvfs_errfn)(void *object, const char *msg);
extern void *cvfs_errobj;
extern char *volatile cvfs_build;
extern char cvfs_path_buf[];

void cvFsCallUsrErrFn(void *object, const char *msg, s32 arg2) {
    (void)object;
    (void)arg2;

    if (cvfs_errfn != 0) {
        cvfs_errfn(cvfs_errobj, msg);
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
    s32 len = (s32)strlen(str);
    s32 i;

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

void cvFsEntryErrFunc(void (*function)(void *object, const char *msg), void *object) {
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
    const char *name_to_add = device_name;

    if (name_to_add == 0) {
        name_to_add = cvFsGetDefDev();
    }

    if (isNeedDevName(name_to_add) == 1) {
        strcpy(cvfs_path_buf, out);
        sprintf(out, "%s:%s", name_to_add, cvfs_path_buf);
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
