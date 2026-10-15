/* SVM_Lock 0x168990, SVM_Unlock 0x168C50, SVM_CallErr 0x1689A0,
 * SVM_CallErr1 0x1689F0, SVM_SetCbSvr 0x168C60.
 * svm_lock is 0x168950 and svm_unlock is 0x168BF0. Neither is named yet.
 * svmerr_msg is 0xCE8EC0 (128 bytes). The error callback is 0x7A5518 and its
 * object is 0x7A551C. Server slots are 6 pairs of (func, object) at
 * 0x7A5398 + index * 48.
 */

#include "types.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    s32 (*func)(void *object);
    void *object;
} SVMSVRCallback;

extern void svm_lock(s32 type);
extern void svm_unlock(s32 type);
extern char svmerr_msg[0x80];
extern void (*svm_error_func)(void *object, char *msg);
extern void *svm_error_object;
extern SVMSVRCallback svm_svr_rows[][6];

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
