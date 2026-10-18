/* svm_lock 0x168950, SVM_Lock 0x168990, SVM_SetCbLock 0x168A20,
 * SVM_SetCbUnlock 0x168A40, SVM_ExecSvrFunc 0x168A60,
 * SVM_ExecSvrVsync 0x168AD0, SVM_ExecSvrFs 0x168AE0, SVM_ExecSvrMain 0x168AF0,
 * svm_reset_variable 0x168B10, SVM_Init 0x168B80, SVM_Finish 0x168BA0,
 * SVM_SetCbTestAndSet 0x168BD0, svm_unlock 0x168BF0, SVM_Unlock 0x168C50,
 * SVM_CallErr 0x1689A0, SVM_CallErr1 0x1689F0, SVM_SetCbSvr 0x168C60,
 * SVM_DelCbSvr 0x168CC0, SVM_SetCbSvrId 0x168D10, SVM_SetCbBdr 0x168D90,
 * SVM_TestAndSet 0x168DC0.
 *
 * svmerr_msg is 0xCE8EC0 (128 bytes). The error callback is 0x7A5518 and its
 * object is 0x7A551C. Server slots are 6 pairs of (func, object) at
 * 0x7A5398. Exec flags are 0xCE8EA0. Exec counts are 0xCE8F40.
 * svm_init_level is 0x7A5580. svm_lock_level is 0x7A5584.
 * svm_svr_exec_flag is 0xCE8EA0. svm_exec_cnt is 0xCE8F40. svm_error is
 * 0x7A5518, a func/object pair cleared with one memset.
 * svm_lock_level, svm_locking_type, svm_svr_exec_flag and svm_exec_cnt
 * are volatile: retail reloads them and increments through a register.
 * svm_locking_type is 0x7A5588. The test-and-set callback is 0x7A5380.
 * The lock callback is 0x7A5384 / 0x7A5388. The unlock callback is
 * 0x7A538C / 0x7A5390. Border slots are pairs at 0x7A5520.
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

typedef struct {
    void (*func)(void);
    s32 arg;
} SVMBorder;

extern char svmerr_msg[0x80];
typedef struct {
    void (*func)(void *object, char *msg);
    void *object;
} SVMErrCallback;

extern SVMErrCallback svm_error;
extern SVMSVRCallback svm_svr_rows[][6];
extern volatile s32 svm_svr_exec_flag[8];
extern volatile s32 svm_exec_cnt[8];
extern volatile s32 svm_init_level; /* re-read and stored each use, as retail does */
extern volatile s32 svm_lock_level;
extern volatile s32 svm_locking_type;
extern s32 (*svm_test_and_set_callback)(void);
extern SVMLockCallback svm_lock_callback;
extern SVMLockCallback svm_unlock_callback;
extern SVMBorder svm_border[];

void svm_lock(s32 type) {
    if (svm_lock_callback.func == 0) {
        return;
    }

    svm_lock_callback.func(svm_lock_callback.object);

    if (svm_lock_level == 0) {
        svm_locking_type = type;
    }

    svm_lock_level += 1;
}

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

    if (svm_error.func != 0) {
        svm_error.func(svm_error.object, svmerr_msg);
    }
}

void SVM_CallErr1(const char *msg) {
    strncpy(svmerr_msg, msg, sizeof(svmerr_msg) - 1);

    if (svm_error.func != 0) {
        svm_error.func(svm_error.object, svmerr_msg);
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
    return (i == 6) ? -1 : i;
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

void SVM_SetCbLock(void (*func)(void *object), void *object) {
    svm_lock_callback.func = func;
    svm_lock_callback.object = object;
}

void SVM_SetCbUnlock(void (*func)(void *object), void *object) {
    svm_unlock_callback.func = func;
    svm_unlock_callback.object = object;
}

s32 SVM_ExecSvrFunc(s32 svtype) {
    s32 i;
    s32 result = 0;

    for (i = 0; i < 6; i++) {
        SVMSVRCallback *callback = &svm_svr_rows[svtype][i];

        if (callback->func != 0) {
            svm_svr_exec_flag[svtype] = 1;
            result |= callback->func(callback->object);
            svm_svr_exec_flag[svtype] = 0;
        }
    }

    svm_exec_cnt[svtype] += 1;
    return result;
}

s32 SVM_ExecSvrVsync(void) {
    return SVM_ExecSvrFunc(2);
}

s32 SVM_ExecSvrFs(void) {
    return SVM_ExecSvrFunc(4);
}

s32 SVM_ExecSvrMain(void) {
    return SVM_ExecSvrFunc(5);
}

void svm_reset_variable(void) {
    s32 i;

    memset((void *)svm_svr_exec_flag, 0, sizeof(svm_svr_exec_flag));
    memset(&svm_lock_callback, 0, sizeof(svm_lock_callback));
    memset(&svm_unlock_callback, 0, sizeof(svm_unlock_callback));

    for (i = 0; i < 6; i++) {
        svm_exec_cnt[i] = 0;
    }

    svm_test_and_set_callback = 0;
}

void SVM_Init(void) {
    if (svm_init_level == 0) {
        svm_reset_variable();
    }

    svm_init_level += 1;
}

void SVM_Finish(void) {
    svm_init_level -= 1;

    if (svm_init_level == 0) {
        svm_reset_variable();
        memset(&svm_error, 0, sizeof(svm_error));
    }
}

s32 SVM_SetCbTestAndSet(s32 (*callback)(void)) {
    if (svm_test_and_set_callback != 0) {
        return 0;
    }

    svm_test_and_set_callback = callback;
    return 1;
}

void SVM_SetCbBdr(s32 index, void (*func)(void), s32 arg) {
    SVM_Lock();
    svm_border[index].func = func;
    svm_border[index].arg = arg;
    SVM_Unlock();
}

s32 SVM_TestAndSet(s32 *mem) {
    s32 ret;

    if (svm_test_and_set_callback != 0) {
        return svm_test_and_set_callback();
    }

    SVM_Lock();
    ret = *mem != 1;
    *mem = 1;
    SVM_Unlock();
    return ret;
}

/* SVM_ExecSvrMwIdle 0x168B00 runs the MW-idle server group (6). */

s32 SVM_ExecSvrMwIdle(void) {
    return SVM_ExecSvrFunc(6);
}
