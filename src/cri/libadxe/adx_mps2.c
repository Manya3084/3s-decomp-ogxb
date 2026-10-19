/* ADXM, CRI's Xbox thread layer (the strings call it ADXWIN), 0x1652F0 to
 * 0x165AD0. Retail has no PS2 counterpart for most of it, so the globals keep
 * their addresses as names.
 *
 * ADXM_IsSetupThrd 0x165460 returns whether adxm_init_level at 0x7A5158 is
 * nonzero. ADXM_SetupThrd 0x1658E0 tests that counter and increments it.
 * ADXT_Init compares the IsSetupThrd result with 1. The other caller,
 * 0x167320, does the same compare.
 *
 * Three threads run the SVM servers: vsync (handle 0xCEC4BC, priority
 * 0x7A5164, stop and stopped flags 0x7A519C/0x7A51A0), file system (0xCEC4D0,
 * 0x7A5168, 0x7A51A4/0x7A51A8), and MW idle (0xCEC480, 0x7A5170,
 * 0x7A51AC/0x7A51B0). 0xCEC4CC is the main thread's pseudo handle. The
 * handles and flags are volatile: retail stores and reloads them. The lock
 * is the critical section at 0xCEC4A0, entered and left through the import
 * slots 0x218DC4/0x218DC0 and initialized through 0x218DC8.
 */

#include "types.h"

long _InterlockedExchange(long volatile *target, long value);
#pragma intrinsic(_InterlockedExchange)

typedef void *(*XbBeginThreadFn)(void *sec, u32 stack, u32 (XB_STDCALL *proc)(void *), void *arg, u32 flags,
                                 u32 *tid);

extern volatile s32 adxm_init_level; /* re-read each use, as retail does */
extern void (XB_STDCALL *D_00218DC0)(void *cs);
extern void (XB_STDCALL *D_00218DC4)(void *cs);
extern void (XB_STDCALL *D_00218DC8)(void *cs);
extern u8 D_00CEC4A0[];
extern volatile s32 D_007A5174;
extern volatile s32 D_007A5178;
extern volatile s32 D_007A5180;
extern volatile s32 D_007A5184;
extern void (*volatile D_007A518C)(void *obj);
extern void *D_007A5190;
extern volatile s32 D_007A5194;
extern volatile s32 D_007A5198;
extern volatile s32 D_007A519C;
extern volatile s32 D_007A51A0;
extern volatile s32 D_007A51A4;
extern volatile s32 D_007A51A8;
extern volatile s32 D_007A51AC;
extern volatile s32 D_007A51B0;
extern XbBeginThreadFn D_007A51B4;
extern s32 D_007A515C;
extern s32 D_007A5160;
extern s32 D_007A5164;
extern s32 D_007A5168;
extern volatile s32 D_007A516C;
extern volatile s32 D_007A5170;
extern void *volatile D_00CEC480;
extern void *volatile D_00CEC4BC;
extern void *volatile D_00CEC4CC;
extern void *volatile D_00CEC4D0;
extern u32 D_00CEC4C0;
extern u32 D_00CEC4C4;
extern u32 D_00CEC4C8;

extern s32 XB_STDCALL SetThreadPriority(void *thread, s32 priority);
extern s32 XB_STDCALL SetThreadPriorityBoost(void *thread, s32 disable);
extern u32 XB_STDCALL ResumeThread(void *thread);
extern u32 XB_STDCALL SuspendThread(void *thread);
extern u32 XB_STDCALL WaitForSingleObject(void *handle, u32 ms);
extern s32 XB_STDCALL CloseHandle(void *handle);
extern s32 XB_STDCALL SwitchToThread(void);
extern void XB_STDCALL D3DDevice_BlockUntilVerticalBlank(void);
extern void *_beginthreadex(void *sec, u32 stack, u32 (XB_STDCALL *proc)(void *), void *arg, u32 flags, u32 *tid);
extern void SVM_CallErr1(const char *msg);
extern void SVM_Init(void);
extern void SVM_Finish(void);
extern void SVM_Lock(void);
extern void SVM_Unlock(void);
extern void SVM_ExecSvrVsync(void);
extern void SVM_ExecSvrFs(void);
extern void SVM_ExecSvrMain(void);
extern s32 SVM_ExecSvrMwIdle(void);
extern void SVM_SetCbLock(void (*func)(void *object), void *object);
extern void SVM_SetCbUnlock(void (*func)(void *object), void *object);
extern s32 SVM_SetCbTestAndSet(s32 (*callback)(void));
extern void SVM_SetCbBdr(s32 index, void (*func)(void), s32 arg);
extern void xb_mwrna_SetSndIf(s32 a, void *sndif);
extern s32 xb_wxfic_Create(void *a, s32 b, s32 c, s32 d);
extern void xb_adxxb_GetVersionStr(void);
extern void cvFsEntryErrFunc(void (*function)(void *object, const char *msg, s32 arg2), void *object);
extern void cvFsAddDev(const char *name, void *(*getif)(void), s32 arg);
extern void cvFsSetDefDev(const char *name);
extern void xb_wxci_Init(void);
extern void *wxCiGetInterface(void);
extern void xb_wxci_SetRootDir(const char *dir);
extern void adxini_lscerr_cbfn(void *object, const char *msg, s32 arg2);
extern void *mfCiGetInterface(void);

void _adxm_lock(void *obj) {
    (void)obj;
    D_00218DC4(D_00CEC4A0);
    D_007A5174++;
}

void _adxm_unlock(void *obj) {
    (void)obj;
    D_007A5174--;
    D_00218DC0(D_00CEC4A0);
}

s32 xb_adxm_TestAndSet(s32 *flag) {
    s32 old = _InterlockedExchange((long volatile *)flag, 1);

    return old == 0;
}

void adxm_goto_mwidle_border(void) {
    s32 i;

    D_007A5178 = 1;

    for (i = 0; i < 3000000; i++) {
        SetThreadPriority(D_00CEC480, D_007A515C);
        ResumeThread(D_00CEC480);

        if (D_007A5178 == 0) {
            break;
        }
    }

    if (i == 3000000) {
        SVM_CallErr1("1060102: Internal Error: adxm_goto_mwidle_border");
    }

    SetThreadPriority(D_00CEC480, D_007A5170);
}

u32 XB_STDCALL xb_adxm_MwIdleThrdProc(void *arg) {
    (void)arg;

    while (D_007A51AC == 0) {
        D_007A5184++;

        if (SVM_ExecSvrMwIdle() != 0 && D_007A5178 != 1) {
            continue;
        }

        if (D_007A5178 == 1) {
            D_007A5178 = 0;
            SetThreadPriority(D_00CEC480, D_007A5170);
        }

        if (D_007A518C != 0) {
            D_007A518C(D_007A5190);
        }

        SuspendThread(D_00CEC480);
    }

    D_007A51B0 = 1;
    return 0;
}

s32 ADXM_IsSetupThrd(void) {
    return adxm_init_level != 0;
}

void ADXM_ExecMain(void) {
    SVM_ExecSvrMain();
}

void ADXM_WaitVsync(void) {
    D3DDevice_BlockUntilVerticalBlank();
}

s32 adxm_destroy_thrd(void) {
    s32 ret = 0;
    s32 i;

    if (D_00CEC4BC != 0) {
        for (i = 0; i < 30; i++) {
            D_007A519C = 1;
            SetThreadPriority(D_00CEC4BC, 2);
            ResumeThread(D_00CEC4BC);

            if (WaitForSingleObject(D_00CEC4BC, 1000) != 0x102) {
                break;
            }
        }

        if (i == 30) {
            SVM_CallErr1("02100901: Timeout Error: adxm_destroy_thrd (vsync)");
            ret--;
        }

        D_007A51A0 = 0;
        D_007A519C = 0;
        CloseHandle(D_00CEC4BC);
    }

    if (D_00CEC4D0 != 0) {
        for (i = 0; i < 30; i++) {
            D_007A51A4 = 1;
            SetThreadPriority(D_00CEC4D0, 2);
            ResumeThread(D_00CEC4D0);

            if (WaitForSingleObject(D_00CEC4D0, 1000) != 0x102) {
                break;
            }
        }

        if (i == 30) {
            SVM_CallErr1("02100902: Timeout Error: ADXWIN_DisableFsThrd");
            ret--;
        }

        D_007A51A8 = 0;
        D_007A51A4 = 0;
        CloseHandle(D_00CEC4D0);
    }

    if (D_00CEC480 != 0) {
        for (i = 0; i < 30; i++) {
            D_007A51AC = 1;
            SetThreadPriority(D_00CEC480, 2);
            ResumeThread(D_00CEC480);

            if (WaitForSingleObject(D_00CEC480, 1000) != 0x102) {
                break;
            }
        }

        if (i == 30) {
            SVM_CallErr1("02100903: Timeout Error: adxm_destroy_thrd (mwidle)");
            ret--;
        }

        D_007A51B0 = 0;
        D_007A51AC = 0;
        CloseHandle(D_00CEC480);
    }

    return ret;
}

s32 xb_adxm_SetThrdPriority(void) {
    s32 ret = 0;

    if (!SetThreadPriority(D_00CEC4BC, D_007A5164)) {
        SVM_CallErr1("E02100921 : The error occurred within the SetThreadPriority function.");
        ret--;
    }

    if (!SetThreadPriority(D_00CEC4D0, D_007A5168)) {
        SVM_CallErr1("E02100922 : The error occurred within the SetThreadPriority function.");
        ret--;
    }

    if (!SetThreadPriority(D_00CEC480, D_007A5170)) {
        SVM_CallErr1("E02100923 : The error occurred within the SetThreadPriority function.");
        ret--;
    }

    if (!SetThreadPriorityBoost(D_00CEC4BC, 1)) {
        SVM_CallErr1("E02100931 : The error occurred within the SetThreadPriorityBoost function.");
        ret--;
    }

    if (!SetThreadPriorityBoost(D_00CEC4D0, 1)) {
        SVM_CallErr1("E02100932 : The error occurred within the SetThreadPriorityBoost function.");
        ret--;
    }

    if (!SetThreadPriorityBoost(D_00CEC480, 1)) {
        SVM_CallErr1("E02100933 : The error occurred within the SetThreadPriorityBoost function.");
        ret--;
    }

    if (!SetThreadPriorityBoost(D_00CEC4CC, 1)) {
        SVM_CallErr1("E02100934 : The error occurred within the SetThreadPriorityBoost function.");
        ret--;
    }

    return ret;
}

void xb_adxm_WaitVsyncThunk(void) {
    ADXM_WaitVsync();
}

u32 XB_STDCALL xb_adxm_VsyncThrdProc(void *arg) {
    (void)arg;

    while (D_007A519C == 0) {
        xb_adxm_WaitVsyncThunk();
        SwitchToThread();
        D_007A5180++;
        SVM_Lock();
        SVM_ExecSvrVsync();
        SVM_Unlock();
        ResumeThread(D_00CEC480);

        if (D_007A518C != 0) {
            D_007A518C(D_007A5190);
        }
    }

    D_007A51A0 = 1;
    return 0;
}

u32 XB_STDCALL xb_adxm_FsThrdProc(void *arg) {
    (void)arg;

    while (D_007A51A4 == 0) {
        xb_adxm_WaitVsyncThunk();
        SwitchToThread();
        SVM_ExecSvrFs();
    }

    D_007A51A8 = 1;
    return 0;
}

s32 xb_adxm_CreateThrd(void) {
    if (D_007A51B4 != 0) {
        D_00CEC4BC = D_007A51B4(0, 0x3000, xb_adxm_VsyncThrdProc, 0, 4, &D_00CEC4C4);

        if (D_00CEC4BC == 0) {
            SVM_CallErr1("E02100911 : The error occurred within the CreateThread function.");
            return -1;
        }

        D_00CEC4D0 = D_007A51B4(0, 0x3000, xb_adxm_FsThrdProc, 0, 4, &D_00CEC4C0);

        if (D_00CEC4D0 == 0) {
            SVM_CallErr1("E02100912 : The error occurred within the CreateThread function.");
            return -1;
        }

        D_00CEC480 = D_007A51B4(0, 0x3000, xb_adxm_MwIdleThrdProc, 0, 4, &D_00CEC4C8);

        if (D_00CEC480 == 0) {
            SVM_CallErr1("E02100913 : The error occurred within the CreateThread function.");
            return -1;
        }

        D_00CEC4CC = (void *)-2;

        if (D_00CEC4CC == 0) {
            SVM_CallErr1("E02100914 : The error occurred within the GetCurrentThread function.");
            return -1;
        }
    }

    return 0;
}

void ADXM_SetupThrd(s32 *prm) {
    if (adxm_init_level == 0) {
        D_007A5194 = 0;
        D_007A5198 = 0;
        D_007A519C = 0;
        D_007A51A0 = 0;
        D_007A51AC = 0;
        D_007A51B0 = 0;
        D_007A5180 = 0;
        D_00218DC8(D_00CEC4A0);
        SVM_Init();
        SVM_SetCbLock(_adxm_lock, 0);
        SVM_SetCbUnlock(_adxm_unlock, 0);
        SVM_SetCbTestAndSet((s32 (*)(void))xb_adxm_TestAndSet);

        if (prm == 0) {
            D_007A516C = 0;
            D_007A515C = 0xF;
            D_007A5160 = 2;
            D_007A5164 = 1;
            D_007A5168 = 1;
            D_007A5170 = -2;
        } else {
            D_007A515C = prm[0];
            D_007A5160 = prm[1];
            D_007A5164 = prm[2];
            D_007A5168 = prm[3];
            D_007A516C = prm[4];
            D_007A5170 = prm[5];
        }

        if (xb_adxm_CreateThrd() < 0 || xb_adxm_SetThrdPriority() < 0) {
            adxm_destroy_thrd();
            SVM_Finish();
        } else {
            ResumeThread(D_00CEC4BC);
            ResumeThread(D_00CEC4D0);
            ResumeThread(D_00CEC480);
            SVM_SetCbBdr(6, adxm_goto_mwidle_border, 0);
            adxm_init_level++;
        }
    } else {
        adxm_init_level++;
    }
}

void *xb_adxm_BeginThread(void *sec, u32 stack, u32 (XB_STDCALL *proc)(void *), void *arg, u32 flags, u32 *tid) {
    return _beginthreadex(sec, stack, proc, arg, flags, tid);
}

void xb_adxm_SetSoundCallback(s32 *prm) {
    D_007A51B4 = xb_adxm_BeginThread;
    ADXM_SetupThrd(prm);
}

void xb_adxm_SetupFileSystems(char **root) {
    xb_adxxb_GetVersionStr();
    cvFsEntryErrFunc(adxini_lscerr_cbfn, 0);
    cvFsAddDev("MFS", mfCiGetInterface, 0);
    xb_wxci_Init();
    cvFsAddDev("WX", wxCiGetInterface, 0);
    cvFsSetDefDev("WX");

    if (root != 0) {
        xb_wxci_SetRootDir(*root);
    } else {
        xb_wxci_SetRootDir(0);
    }
}

void xb_adxm_SetRnaInterface(void *sndif) {
    xb_mwrna_SetSndIf(0, sndif);
}

s32 xb_adxm_CallIfSet(void *a, s32 b, s32 c, s32 d) {
    if (a == 0) {
        return 0;
    }

    return xb_wxfic_Create(a, b, c, d);
}
