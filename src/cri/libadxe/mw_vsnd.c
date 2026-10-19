/* mw_vsnd.c: the virtual sound port ("RNADMY"), 0x1725F0 to 0x172880. It
 * plays nothing and keeps time from the timer callback at 0x7A5AAC, in
 * microseconds, at 0.0441 samples per microsecond (44.1 kHz). Sixteen ports
 * of 0x20 bytes are at 0xCD0380: +0 the interface (0x43CCE8), +4 in use,
 * +8 the resume flag, +0xC the frequency, +0x10 the buffer size, +0x14 the
 * start time, +0x18 the stop time, +0x1C the last position. */

#include "types.h"

#include <string.h>

typedef struct {
    u32 lo;
    u32 hi;
} MwVsndU64;

char *volatile mwvsnd_build = "\nRNADMY Ver.3.04 Build:Feb 13 2004 21:07:57\n"; /* mwvsnd_build is 0x2E15D8 */
extern u8 mwvsnd_obj[16][0x20]; /* mwvsnd_obj is 0xCD0380 */
extern void *D_0043CCD0[32];
extern u32 (*D_007A5AAC)(void);
extern s32 XB_STDCALL QueryPerformanceFrequency(long long *freq);
extern s32 XB_STDCALL QueryPerformanceCounter(long long *count);
void *xb_mwvsnd_AllocHandle(void);
void xb_mwvsnd_FreeHandle(void *hn);

void xb_mwvsnd_Init(void) {
    s32 i;

    (void)mwvsnd_build;

    for (i = 0; i < 16; i++) {
        *(s32 *)(mwvsnd_obj[i] + 4) = 0;
    }
}

void xb_mwvsnd_Finish(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        *(s32 *)(mwvsnd_obj[i] + 4) = 0;
    }
}

void *xb_mwvsnd_AllocHandle(void) {
    s32 i;
    void *hn = 0;

    for (i = 0; i < 16; i++) {
        if (*(s32 *)(mwvsnd_obj[i] + 4) == 0) {
            hn = mwvsnd_obj[i];
            break;
        }
    }

    return hn;
}

void xb_mwvsnd_FreeHandle(void *hn) {
    memset(hn, 0, 0x20);
    *(s32 *)((u8 *)hn + 4) = 0;
}

void *xb_mwvsnd_OpenPort(void) {
    u8 *hn = xb_mwvsnd_AllocHandle();

    *(void **)hn = D_0043CCD0 + 6;
    *(s32 *)(hn + 0xC) = 44100;
    *(s32 *)(hn + 0x10) = 0x4000;
    *(s32 *)(hn + 0x14) = 0;
    *(s32 *)(hn + 0x18) = 0;
    *(s32 *)(hn + 0x1C) = 0;
    *(s32 *)(hn + 8) = 0;
    *(s32 *)(hn + 4) = 1;
    return hn;
}

void xb_mwvsnd_ClosePort(void *hn) {
    xb_mwvsnd_FreeHandle(hn);
}

void xb_mwvsnd_Play(void *hn) {
    u32 t = 0;

    if (D_007A5AAC != 0) {
        t = D_007A5AAC();
    }

    if (*(s32 *)((u8 *)hn + 8) == 1) {
        *(s32 *)((u8 *)hn + 0x14) = *(s32 *)((u8 *)hn + 0x18);
        return;
    }

    *(s32 *)((u8 *)hn + 0x14) = (s32)((double)t * 0.0441);
}

void xb_mwvsnd_Stop(void *hn) {
    u32 t = 0;

    if (D_007A5AAC != 0) {
        t = D_007A5AAC();
    }

    *(s32 *)((u8 *)hn + 0x18) = (s32)((double)t * 0.0441);
}

s32 xb_mwvsnd_GetBufSize(void *hn) {
    (void)hn;
    return 0x4000;
}

u32 xb_mwvsnd_GetPlayPos(void *hn) {
    u8 *bytes = hn;
    u32 t = 0;
    s32 pos;

    if (D_007A5AAC != 0) {
        t = D_007A5AAC();
    }

    pos = -*(s32 *)(bytes + 0x14) - (s32)((double)t * -0.0441);
    *(s32 *)(bytes + 0x1C) = pos;
    return (u32)pos % *(u32 *)(bytes + 0x10);
}

void xb_mwvsnd_SetSfreq(void *hn, s32 sfreq) {
    *(s32 *)((u8 *)hn + 0xC) = sfreq;
}

s32 xb_mwvsnd_GetBitPerSmpl(void *hn) {
    (void)hn;
    return 16;
}

void xb_mwsnd_GetCmdResult(void *hn, s32 cmd, s32 *a, s32 *b) {
    (void)hn;
    (void)cmd;
    *a = 0;
    *b = 0;
}

s32 xb_mwsnd_ReturnOne(void) {
    return 1;
}

s32 xb_mwvsnd_SetResume(void *hn) {
    *(s32 *)((u8 *)hn + 8) = 1;
    return 0;
}

s32 xb_mwvsnd_GetTime(void) {
    long long freq;
    long long count;

    if (!QueryPerformanceFrequency(&freq)) {
        return 0;
    }

    QueryPerformanceCounter(&count);
    return (s32)(count / (freq * 1e-06f));
}

extern void ADXF_Ocbi(void);
extern void ADXPD_GetStat(void);
extern void xb_aixp_ReturnZero(void);

/* D_0043CCD0 is 0x43CCD0: the mwVSnd (dummy voice) interface, in the
 * mwSnd layout. Init, Finish and OpenPort are its slots 3 to 5; a voice
 * handle points at slot 6 (0x43CCE8, as retail stores it), so its slots
 * 3 on are ClosePort on. Empty slots are 0; the empty bodies are folded. */
void *D_0043CCD0[32] = {
    0, 0, 0, (void *)xb_mwvsnd_Init, (void *)xb_mwvsnd_Finish,
    (void *)xb_mwvsnd_OpenPort, 0, 0, 0, (void *)xb_mwvsnd_ClosePort,
    (void *)xb_mwvsnd_Play, (void *)xb_mwvsnd_Stop, (void *)xb_mwvsnd_GetBufSize,
    (void *)ADXF_Ocbi, (void *)xb_mwvsnd_GetPlayPos, (void *)xb_mwvsnd_SetSfreq,
    (void *)ADXPD_GetStat, (void *)ADXF_Ocbi, (void *)xb_mwvsnd_GetBitPerSmpl,
    (void *)ADXF_Ocbi, (void *)xb_aixp_ReturnZero, (void *)ADXF_Ocbi,
    (void *)xb_aixp_ReturnZero, (void *)ADXF_Ocbi, (void *)xb_aixp_ReturnZero,
    (void *)ADXF_Ocbi, (void *)xb_mwsnd_GetCmdResult, (void *)ADXF_Ocbi,
    (void *)ADXF_Ocbi, (void *)xb_mwsnd_ReturnOne, (void *)xb_mwvsnd_SetResume,
    (void *)xb_aixp_ReturnZero,
};
