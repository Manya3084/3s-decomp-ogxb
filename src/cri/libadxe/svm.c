/* SVM_Lock 0x168990, svm_unlock 0x168BF0, SVM_Unlock 0x168C50,
 * SVM_CallErr 0x1689A0, SVM_CallErr1 0x1689F0, SVM_SetCbSvr 0x168C60,
 * SVM_DelCbSvr 0x168CC0, SVM_SetCbSvrId 0x168D10.
 * svm_lock is 0x168950 and is not named yet.
 * svmerr_msg is 0xCE8EC0 (128 bytes). The error callback is 0x7A5518 and its
 * object is 0x7A551C. Server slots are 6 pairs of (func, object) at
 * 0x7A5398 + index * 48.
 * svm_lock_level is 0x7A5584. svm_locking_type is 0x7A5588.
 * The unlock callback is 0x7A538C and its object is 0x7A5390.
 * SVM_SetCbSvrId's second check compares id with 8.
 */

#include "types.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    s32 (*func)(void *object);
    void *object;
} SVMSVRCallback;

typedef struct {
    void (*func)(void *object);
    void *object;
} SVMLockCallback;

extern void svm_lock(s32 type);
extern char svmerr_msg[0x80];
extern void (*svm_error_func)(void *object, char *msg);
extern void *svm_error_object;
extern SVMSVRCallback svm_svr_rows[][6];
extern s32 svm_lock_level;
extern s32 svm_locking_type;
extern SVMLockCallback svm_unlock_callback;

void SVM_CallErr(const char *format, ...);

void svm_unlock(s32 type) {
    if (svm_unlock_callback.func == 0) {
        return;
    }

    svm_lock_level -= 1;

    if (svm_lock_level == 0) {
        if (svm_locking_type != type) {
            SVM_CallErr("2103102:SVM:svm_unlock:lock type miss match.(type org=%d, type now=%d)",
                svm_locking_type, type);
        }

        svm_locking_type = 0;
    }

    svm_unlock_callback.func(svm_unlock_callback.object);
}

void SVM_Lock(void) {
    svm_lock(1);
}

void SVM_Unlock(void) {
    svm_unlock(1);
}

void SVM_CallErr(const char *format, ...) {
    va_list args;

    memset(svmerr_msg, 0, sizeof(svmerr_msg));
    va_start(args, format);
    vsprintf(svmerr_msg, format, args);
    va_end(args);

    if (svm_error_func != 0) {
        svm_error_func(svm_error_object, svmerr_msg);
    }
}

void SVM_CallErr1(const char *msg) {
    strncpy(svmerr_msg, msg, sizeof(svmerr_msg) - 1);

    if (svm_error_func != 0) {
        svm_error_func(svm_error_object, svmerr_msg);
    }
}

s32 SVM_SetCbSvr(s32 index, s32 (*func)(void *object), void *object) {
    s32 i;

    SVM_Lock();

    for (i = 0; i < 6; i++) {
        SVMSVRCallback *callback = &svm_svr_rows[index][i];

        if (callback->func == 0) {
            callback->func = func;
            callback->object = object;
            break;
        }
    }

    if (i == 6) {
        SVM_CallErr1("1051001:SVM_SetCbSvr:too many server function");
    }

    SVM_Unlock();
    return (i != 6) ? i : -1;
}

void SVM_DelCbSvr(s32 group, s32 id) {
    if (id < 0 || id >= 6) {
        SVM_CallErr1("1051002:SVM_DelCbSvr:illegal id");
    }

    SVM_Lock();
    svm_svr_rows[group][id].func = 0;
    svm_svr_rows[group][id].object = 0;
    SVM_Unlock();
}

void SVM_SetCbSvrId(s32 svtype, s32 id, s32 (*func)(void *object), void *object) {
    SVMSVRCallback *callback;

    if (id < 0 || id >= 6) {
        SVM_CallErr1("1071201:SVM_SetCbSvrId:illegal id");
    }

    if (svtype < 0 || id >= 8) {
        SVM_CallErr1("1071202:SVM_SetCbSvrId:illegal svtype");
    }

    SVM_Lock();
    callback = &svm_svr_rows[svtype][id];

    if (callback->func != 0) {
        SVM_CallErr1("2100801:SVM_SetCbSvrId:over write callback function.");
    }

    callback->func = func;
    callback->object = object;
    SVM_Unlock();
}
