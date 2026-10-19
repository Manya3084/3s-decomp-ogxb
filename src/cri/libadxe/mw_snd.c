/* mwSndStop 0x16C380.
 *
 * A failed stop reports E1229 and returns. Otherwise this waits while
 * status bit 0 is set. The limit is QueryPerformanceFrequency
 * divided by 0x5DC. The scanner start at 0x16C3F0 is inside the wait.
 * 0x199ED8, 0x199F34, 0x123320, 0x123331, 0x1786E0, and 0x1725A0 are
 * IDirectSoundBuffer_Stop, IDirectSoundBuffer_GetStatus,
 * QueryPerformanceCounter, QueryPerformanceFrequency, _alldiv, and
 * xb_mwerr_CallErrFunc. The only caller is 0x16C783.
 */

#include "types.h"

#include <string.h>

typedef struct {
    u32 lo;
    u32 hi;
} MwU64;

extern s32 XB_STDCALL IDirectSoundBuffer_Stop(void *dsb);
extern s32 XB_STDCALL IDirectSoundBuffer_SetVolume(void *dsb, s32 vol);
extern s32 XB_STDCALL IDirectSoundBuffer_SetCurrentPosition(void *dsb, s32 pos);
extern void XB_STDCALL IDirectSoundBuffer_GetStatus(void *dsb, u32 *stat);
extern s32 XB_STDCALL IDirectSoundBuffer_SetFrequency(void *dsb, s32 freq);
void xb_mwsnd_PlayDsb(void *dsb);
extern void QueryPerformanceCounter(MwU64 *out);
extern void QueryPerformanceFrequency(MwU64 *out);
extern void xb_mwerr_CallErrFunc(const char *msg);
extern void *xb_mwsnd_Alloc(void);
extern void xb_mwsnd_Free(void *hn);
extern s32 xb_mwsnd_CreateBuffer(s32 nch, s32 bytes);
typedef struct {
    u16 wFormatTag;
    u16 nChannels;
    u32 nSamplesPerSec;
    u32 nAvgBytesPerSec;
    u16 nBlockAlign;
    u16 wBitsPerSample;
    u16 cbSize;
} MwWaveFmt;

typedef struct {
    u32 dwSize;
    u32 dwFlags;
    u32 dwBufferBytes;
    MwWaveFmt *lpwfxFormat;
    void *lpMixBins;
    u32 dwInputMixBin;
} MwBufDesc;

void xb_mwsnd_MakeWaveFormat(s32 nch, MwWaveFmt *fmt);
extern s32 XB_STDCALL IDirectSound_CreateSoundBuffer(void *ds, MwBufDesc *desc, void **dsb, void *outer);
extern s32 XB_STDCALL IDirectSoundBuffer_SetHeadroom(void *dsb, u32 headroom);
/* mwsnd_bufsz is 0x43CA48. */
s32 mwsnd_bufsz = 0x8000;
extern s32 mwsnd_mode; /* 0x7A603C */
extern s32 XB_STDCALL IDirectSoundBuffer_Lock(void *dsb, u32 ofs, u32 size, void **p1, u32 *n1, void **p2, u32 *n2, u32 flags);
extern s32 XB_STDCALL IDirectSoundBuffer_Unlock(void *dsb, void *p1, u32 n1, void *p2, u32 n2);
extern s32 XB_STDCALL IDirectSoundBuffer_GetCurrentPosition(void *dsb, u32 *play, u32 *write);
extern void *mwsnd_flag; /* mwsnd_flag is 0x7A6038 */
extern u8 mwsnd_obj[16][0x58]; /* mwsnd_obj is 0x7A5AB8 */
void xb_mwsnd_SetSfreq(void *hn, s32 sfreq);
extern s32 XB_STDCALL IDirectSoundBuffer_SetMixBins(void *dsb, void *bins);
extern s32 XB_STDCALL IDirectSoundBuffer_Release(void *dsb);
extern void *D_0043C9C8[32];
void xb_mwsnd_ApplyPan(void *hn, s32 ch, s32 pan);
void xb_mwsnd_SetSpeakerMix(void *hn, s32 a, s32 b);
void xb_mwsnd_StorePan(void *hn, s32 ch, s32 pan);
void xb_mwsnd_StopPort(void *hn);
void xb_mwsnd_ApplySfreq(void *hn, s32 sfreq);
void xb_mwsnd_UpdateNumChan(void *hn, s32 nch);
s32 xb_mwsnd_GetSfreq(void *hn);

void mwSndStop(void *dsb) {
    MwU64 start;
    MwU64 now;
    MwU64 scale;
    unsigned long long limit;
    long long elapsed;
    long long start_ticks;
    long long now_ticks;
    u32 stat;

    if (IDirectSoundBuffer_Stop(dsb) != 0) {
        xb_mwerr_CallErrFunc("E1229:IDirectSoundBuffer_Stop return error in mwSndStop");
        return;
    }

    QueryPerformanceCounter(&start);
    IDirectSoundBuffer_GetStatus(dsb, &stat);
    if ((stat & 1) == 0) {
        return;
    }

    do {
        QueryPerformanceFrequency(&scale);
        limit = (long long)(((unsigned long long)scale.hi << 32) | scale.lo) / 0x5DC;
        QueryPerformanceCounter(&now);
        now_ticks = (long long)(((unsigned long long)now.hi << 32) | now.lo);
        start_ticks = (long long)(((unsigned long long)start.hi << 32) | start.lo);
        elapsed = now_ticks - start_ticks;
        if (elapsed > (long long)limit) {
            break;
        }
        if (now_ticks <= start_ticks) {
            break;
        }
        IDirectSoundBuffer_GetStatus(dsb, &stat);
    } while ((stat & 1) != 0);
}

/* mwSndOpenPort 0x16C5C0.
 *
 * A channel count outside 1..2 reports E1221 and returns 0. A failed
 * alloc reports E1222 and returns 0. The handle is 0x58 bytes. Its
 * vtable is 0x43C9E0. 0x16C4A0, 0x16C4D0, 0x16C4F0, and 0x16C260 are
 * xb_mwsnd_Alloc, xb_mwsnd_Free, xb_mwsnd_CreateBuffer, and
 * xb_mwsnd_MakeWaveFormat. The only reference is the pointer at 0x43C9DC.
 */

void *mwSndOpenPort(s32 maxnch) {
    void *hn;
    u8 *bytes;
    u8 fmt[0x12];
    s32 created;

    if ((maxnch < 1) || (maxnch > 2)) {
        xb_mwerr_CallErrFunc("E1221:Illigal parameter(MAXNCH) in mwSndOpenPort");
        return 0;
    }

    hn = xb_mwsnd_Alloc();
    if (hn == 0) {
        xb_mwerr_CallErrFunc("E1222:Not enough instance(MWSND) in mwSndOpenPort");
        return 0;
    }

    memset(hn, 0, (size_t)0x58);
    bytes = hn;
    *(void **)bytes = (void *)0x43C9E0;
    created = xb_mwsnd_CreateBuffer(maxnch, mwsnd_bufsz * maxnch);
    if (created == 0) {
        xb_mwsnd_Free(hn);
        return 0;
    }

    *(s32 *)(bytes + 8) = created;
    *(s32 *)(bytes + 0xC) = mwsnd_mode;
    xb_mwsnd_MakeWaveFormat(maxnch, (MwWaveFmt *)fmt);
    memcpy(bytes + 0x14, fmt, (size_t)0x12);
    *(s32 *)(bytes + 0x30) = maxnch;
    *(s32 *)(bytes + 0x2C) = maxnch;
    *(s32 *)(bytes + 0x50) = 0;
    *(s32 *)(bytes + 0x54) = -127;
    if (maxnch == 1) {
        *(s32 *)(bytes + 4) = maxnch;
        *(s32 *)(bytes + 0x44) = 0;
        *(s32 *)(bytes + 0x48) = 0;
        return hn;
    }

    if (maxnch == 2) {
        *(s32 *)(bytes + 0x44) = -15;
        *(s32 *)(bytes + 0x48) = 15;
    }

    *(s32 *)(bytes + 4) = 1;
    return hn;
}

/* mwSndPlay 0x16C6E0.
 *
 * A zero dword at +4 returns. A null buffer at +8 tail-jumps to
 * 0x1725A0 with E1225. A failed 0x19A63B tail-jumps with E1228.
 * When the dword at +0x34 is 1, a failed 0x199F70 calls 0x1725A0
 * with E1227, and +0x34 is cleared either way. Success tail-jumps
 * to xb_mwsnd_PlayDsb (0x16C2B0) with the buffer. The only
 * reference is the pointer at 0x43C9F0.
 */

void mwSndPlay(void *hn) {
    u8 *bytes;
    void *dsb;

    bytes = hn;
    if (*(s32 *)(bytes + 4) == 0) {
        return;
    }

    dsb = *(void **)(bytes + 8);
    if (dsb == 0) {
        xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
        return;
    }

    if (IDirectSoundBuffer_SetFrequency(dsb, *(s32 *)(bytes + 0x18)) != 0) {
        xb_mwerr_CallErrFunc("E1228:IDirectSoundBuffer_SetFrequency return error in mwSndPlay");
        return;
    }

    if (*(s32 *)(bytes + 0x34) == 1) {
        if (IDirectSoundBuffer_SetCurrentPosition(*(void **)(bytes + 8), 0) != 0) {
            xb_mwerr_CallErrFunc("E1227:IDirectSoundBuffer_SetCurrentPosition return error");
        }
        *(s32 *)(bytes + 0x34) = 0;
    }

    xb_mwsnd_PlayDsb(*(void **)(bytes + 8));
}

/* mwSndSetVol 0x16C960.
 *
 * A zero dword at +4 returns. A null buffer at +8 reports E1225.
 * The argument times 10 is clamped to -10000..0 and stored at +0x3C.
 * That value plus the dword at +0x4C is clamped the same way and
 * passed to 0x199DF0. A failed call reports E1230. 0x199DF0 and 0x1725A0 are
 * IDirectSoundBuffer_SetVolume and xb_mwerr_CallErrFunc. The only reference is
 * the pointer at
 * 0x43CA14.
 */

void mwSndSetVol(void *hn, s32 vol) {
    u8 *bytes;
    void *dsb;
    s32 scaled;
    s32 sum;

    bytes = hn;
    if (*(s32 *)(bytes + 4) == 0) {
        return;
    }

    dsb = *(void **)(bytes + 8);
    if (dsb == 0) {
        xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
        return;
    }

    scaled = (s32)((u32)vol * 10u);
    if (scaled > 0) {
        scaled = 0;
    } else if (scaled < -10000) {
        scaled = -10000;
    }
    *(s32 *)(bytes + 0x3C) = scaled;

    sum = (s32)((u32)*(s32 *)(bytes + 0x4C) + (u32)scaled);
    if (sum > 0) {
        sum = 0;
    } else if (sum < -10000) {
        sum = -10000;
    }

    if (IDirectSoundBuffer_SetVolume(dsb, sum) != 0) {
        xb_mwerr_CallErrFunc("E1230:IDirectSoundBuffer_SetVolume return error in mwSndSetVol");
    }
}

/* mwSndSetBalance 0x16CA40.
 *
 * A dword of 1 at +0xC returns. A zero dword at +4 returns. A null
 * buffer at +8 reports E1225 and returns. Otherwise the argument is
 * clamped to -15..15, stored at +0x38, and this reports E1232.
 * Every call in the body is xb_mwerr_CallErrFunc (0x1725A0). The only
 * reference is the pointer at 0x43CA24.
 */

void mwSndSetBalance(void *hn, s32 pan) {
    u8 *bytes;
    s32 clamped;

    bytes = hn;
    if (*(s32 *)(bytes + 0xC) == 1) {
        return;
    }
    if (*(s32 *)(bytes + 4) == 0) {
        return;
    }
    if (*(void **)(bytes + 8) == 0) {
        xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
        return;
    }

    if (pan < -15) {
        clamped = -15;
    } else if (pan > 15) {
        clamped = 15;
    } else {
        clamped = pan;
    }
    *(s32 *)(bytes + 0x38) = clamped;
    xb_mwerr_CallErrFunc("E1232:IDirectSoundBuffer_SetPan return error in mwSndSetBalance");
}

/* The port handles are 0x58 bytes, sixteen at 0x7A5AB8: +4 is the in-use
 * word, +8 the DirectSound buffer, +0x18 the frequency, +0x22 the bits per
 * sample, +0x38 the balance, and +0x44/+0x48 the channel pans.
 * xb_mwsnd_Init 0x16C450, xb_mwsnd_Finish 0x16C470, xb_mwsnd_Alloc
 * 0x16C4A0, xb_mwsnd_Free 0x16C4D0, xb_mwsnd_StopPort 0x16C760,
 * xb_mwsnd_GetBufSize 0x16C790, xb_mwsnd_GetPlayPos 0x16C810, the
 * frequency and sample-size accessors 0x16C880..0x16C930,
 * xb_mwsnd_StorePan 0x16C9E0, xb_mwsnd_GetVol 0x16CA10,
 * xb_mwsnd_GetBalance 0x16CAA0, xb_mwsnd_ApplySfreq 0x16CAD0 and
 * xb_mwsnd_CopyPcm 0x16CB30. */

void xb_mwsnd_Init(void *flag) {
    s32 i;

    mwsnd_flag = flag;

    for (i = 0; i < 16; i++) {
        *(s32 *)(mwsnd_obj[i] + 4) = 0;
        *(void **)(mwsnd_obj[i] + 8) = 0;
    }
}

void xb_mwsnd_Finish(void) {
    s32 i;

    mwsnd_flag = 0;

    for (i = 0; i < 16; i++) {
        *(s32 *)(mwsnd_obj[i] + 4) = 0;
        *(void **)(mwsnd_obj[i] + 8) = 0;
    }

    mwsnd_mode = 0;
    mwsnd_bufsz = 0x8000;
}

void *xb_mwsnd_Alloc(void) {
    s32 i;
    void *hn = 0;

    for (i = 0; i < 16; i++) {
        if (*(s32 *)(mwsnd_obj[i] + 4) == 0) {
            hn = mwsnd_obj[i];
            break;
        }
    }

    return hn;
}

void xb_mwsnd_Free(void *hn) {
    memset(hn, 0, 0x58);
    *(s32 *)((u8 *)hn + 4) = 0;
}

void xb_mwsnd_StopPort(void *hn) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 4) != 0) {
        if (*(void **)(bytes + 8) == 0) {
            xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
            return;
        }

        mwSndStop(*(void **)(bytes + 8));
    }
}

s32 xb_mwsnd_GetBufSize(void *hn) {
    u8 *bytes = hn;
    void *p1;
    u32 n1;
    void *p2;
    u32 n2;

    if (IDirectSoundBuffer_Lock(*(void **)(bytes + 8), 0, 8, &p1, &n1, &p2, &n2, 0) != 0) {
        xb_mwerr_CallErrFunc("E1234:IDirectSoundBuffer_Lock return error");
        return 0;
    }

    IDirectSoundBuffer_Unlock(*(void **)(bytes + 8), p1, n1, p2, n2);
    *(u32 *)(bytes + 0x28) = n1;
    return mwsnd_bufsz / *(u16 *)(bytes + 0x22) << 3;
}

s32 xb_mwsnd_GetPlayPos(void *hn) {
    u8 *bytes = hn;
    s32 pos = 0;
    u32 play;
    u32 write;

    if (*(s32 *)(bytes + 4) != 0) {
        if (*(void **)(bytes + 8) == 0) {
            xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
            return 0;
        }

        if (*(s32 *)(bytes + 0x34) == 1) {
            pos = 0;
            return pos;
        }

        if (IDirectSoundBuffer_GetCurrentPosition(*(void **)(bytes + 8), &play, &write) == 0) {
            pos = play / (*(u16 *)(bytes + 0x22) >> 3) / *(u32 *)(bytes + 0x2C);
        }
    }

    return pos;
}

void xb_mwsnd_SetSfreq(void *hn, s32 sfreq) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 4) != 0) {
        if (*(void **)(bytes + 8) == 0) {
            xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
            return;
        }

        if (sfreq > 0x2EDEF) {
            sfreq = 0x2EDEF;
        } else if (sfreq < 0xBC) {
            sfreq = 0xBC;
        }

        *(s32 *)(bytes + 0x18) = sfreq;
    }
}

s32 xb_mwsnd_GetSfreq(void *hn) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 4) != 0) {
        if (*(void **)(bytes + 8) == 0) {
            xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
            return 0;
        }

        return *(s32 *)(bytes + 0x18);
    }

    return 0;
}

void xb_mwsnd_SetBitPerSmpl(void *hn, s32 bps) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 4) != 0) {
        if (*(void **)(bytes + 8) == 0) {
            xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
            return;
        }

        *(u16 *)(bytes + 0x22) = (u16)bps;
    }
}

s32 xb_mwsnd_GetBitPerSmpl(void *hn) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 4) != 0) {
        if (*(void **)(bytes + 8) == 0) {
            xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
            return 0;
        }

        return *(u16 *)(bytes + 0x22);
    }

    return 0;
}

void xb_mwsnd_StorePan(void *hn, s32 ch, s32 pan) {
    u8 *bytes = hn;

    if (ch == 0) {
        *(s32 *)(bytes + 0x44) = pan;
    } else if (ch == 1) {
        *(s32 *)(bytes + 0x48) = pan;
    }

    *(s32 *)(bytes + 0x4C) = 0;
}

s32 xb_mwsnd_GetVol(void *hn) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 4) != 0 && *(void **)(bytes + 8) == 0) {
        xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
        return 0;
    }

    return 0;
}

s32 xb_mwsnd_GetBalance(void *hn) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 4) != 0) {
        if (*(void **)(bytes + 8) == 0) {
            xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
            return 0;
        }

        return *(s32 *)(bytes + 0x38);
    }

    return 0;
}

void xb_mwsnd_ApplySfreq(void *hn, s32 sfreq) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 4) != 0) {
        if (*(void **)(bytes + 8) == 0) {
            xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
            return;
        }

        xb_mwsnd_SetSfreq(hn, sfreq);

        if (IDirectSoundBuffer_SetFrequency(*(void **)(bytes + 8), xb_mwsnd_GetSfreq(hn)) != 0) {
            xb_mwerr_CallErrFunc("E1236:IDirectSoundBuffer_SetFrequency return error");
        }
    }
}

void xb_mwsnd_CopyPcm(void *dst, const void *src, u32 n) {
    memcpy(dst, src, n);
}

/* xb_mwsnd_ResetPlayPos 0x16CF50, xb_mwsnd_GetQueued 0x16CF60,
 * xb_mwsnd_GetInterface 0x16CF70 (the interface table at 0x43C9C8),
 * xb_mwsnd_SetMixBins 0x16CF80, xb_mwsnd_ClosePort 0x16CFA0,
 * xb_mwsnd_UpdateNumChan 0x16D240, xb_mwsnd_SetOutPan 0x16D280,
 * xb_mwsnd_ExecCmd 0x16D2D0 and xb_mwsnd_SetNumChan 0x16D310. */

void xb_mwsnd_ResetPlayPos(void *hn) {
    *(s32 *)((u8 *)hn + 0x34) = 1;
}

s32 xb_mwsnd_GetQueued(void *hn, s32 ch, s32 *queued) {
    (void)hn;
    (void)ch;
    *queued = 0;
    return 0;
}

void *xb_mwsnd_GetInterface(void) {
    return D_0043C9C8;
}

void xb_mwsnd_SetMixBins(void *hn, void *bins) {
    IDirectSoundBuffer_SetMixBins(*(void **)((u8 *)hn + 8), bins);
    *(s32 *)((u8 *)hn + 0x10) = 1;
}

void xb_mwsnd_ClosePort(void *hn) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 4) != 0) {
        xb_mwsnd_StopPort(hn);

        if (*(void **)(bytes + 8) != 0) {
            IDirectSoundBuffer_Release(*(void **)(bytes + 8));
            *(void **)(bytes + 8) = 0;
        }

        xb_mwsnd_Free(hn);
    }
}

void xb_mwsnd_UpdateNumChan(void *hn, s32 nch) {
    u8 *bytes = hn;

    *(s32 *)(bytes + 0x30) = nch;

    if (*(s32 *)(bytes + 0xC) != 1 && *(s32 *)(bytes + 0x40) == 1 && nch == 1 && *(s32 *)(bytes + 0x2C) == 1) {
        xb_mwsnd_ApplyPan(hn, 0, *(s32 *)(bytes + 0x44));
    }
}

void xb_mwsnd_SetOutPan(void *hn, s32 ch, s32 pan) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 4) != 0) {
        if (*(void **)(bytes + 8) == 0) {
            xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
            return;
        }

        if (*(s32 *)(bytes + 0xC) == 1) {
            return;
        }

        *(s32 *)(bytes + 0x40) = 1;

        if (*(s32 *)(bytes + 0x2C) == 1 && *(s32 *)(bytes + 0x30) == 1) {
            xb_mwsnd_ApplyPan(hn, ch, pan);
        } else {
            xb_mwsnd_StorePan(hn, ch, pan);
        }
    }
}

void xb_mwsnd_ExecCmd(void *hn, s32 cmd, s32 a, s32 b) {
    switch (cmd) {
    case 5:
        xb_mwsnd_ApplySfreq(hn, a);
        break;

    case 6:
        xb_mwsnd_SetSpeakerMix(hn, a, b);
        break;
    }
}

void xb_mwsnd_SetNumChan(void *hn, s32 nch) {
    u8 *bytes = hn;

    if (*(s32 *)(bytes + 4) != 0) {
        if (*(void **)(bytes + 8) == 0) {
            xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
            return;
        }

        *(s32 *)(bytes + 0x30) = nch;
        xb_mwsnd_UpdateNumChan(hn, nch);
    }
}

/* xb_mwsnd_MakeWaveFormat 0x16C260 fills a 16-bit 44.1 kHz PCM format;
 * xb_mwsnd_CreateBuffer 0x16C4F0 creates the DirectSound buffer on the
 * device object 0x7A6038 (mono buffers get flag 0x10 in mode 1). */

void xb_mwsnd_MakeWaveFormat(s32 nch, MwWaveFmt *fmt) {
    memset(fmt, 0, 0x12);
    fmt->nChannels = (u16)nch;
    fmt->nBlockAlign = (u16)(nch * 2);
    fmt->wFormatTag = 1;
    fmt->nSamplesPerSec = 44100;
    fmt->wBitsPerSample = 16;
    fmt->cbSize = 0;
    fmt->nAvgBytesPerSec = fmt->nBlockAlign * 44100;
}

s32 xb_mwsnd_CreateBuffer(s32 nch, s32 nbytes) {
    MwBufDesc desc;
    MwWaveFmt fmt;
    void *dsb = 0;
    void *ds = mwsnd_flag;

    if (ds == 0) {
        xb_mwerr_CallErrFunc("E2003100700:DirectSound Object is NULL. Probably ADX?\?_SetupSound was not called properly.");
        return 0;
    }

    memset(&desc, 0, sizeof(desc));
    xb_mwsnd_MakeWaveFormat(nch, &fmt);
    desc.dwBufferBytes = nbytes;
    desc.dwSize = sizeof(desc);
    desc.dwFlags = 0x400A0;
    desc.lpwfxFormat = &fmt;

    if (mwsnd_mode == 1 && nch == 1) {
        desc.dwFlags = 0x400B0;
    }

    if (IDirectSound_CreateSoundBuffer(ds, &desc, &dsb, 0) != 0) {
        xb_mwerr_CallErrFunc("E1223:Cannot create DirectSoundBuffer in mwSndOpenPort");
        dsb = 0;
    }

    IDirectSoundBuffer_SetHeadroom(dsb, 0);
    return (s32)dsb;
}

extern s32 XB_STDCALL IDirectSoundBuffer_Play(void *dsb, u32 r1, u32 r2, u32 flags);
extern s32 XB_STDCALL IDirectSoundBuffer_SetMixBinVolumes_8(void *dsb, void *bins);
/* D_002E0968 is 0x2E0968. */
f32 D_002E0968[32] = {
    1.0f, 0.9986295104026794f, 0.9945219159126282f, 0.9876883625984192f, 0.9781476259231567f,
    0.9659258127212524f, 0.9510565400123596f, 0.9335803985595703f, 0.9135454297065735f,
    0.8910065293312073f, 0.8660253882408142f, 0.838670551776886f, 0.80901700258255f,
    0.7771459817886353f, 0.7431448101997375f, 0.7071067690849304f, 0.6691306233406067f,
    0.6293203830718994f, 0.5877852439880371f, 0.5446390509605408f, 0.5f, 0.45399048924446106f,
    0.4067366421222687f, 0.3583679497241974f, 0.30901700258255005f, 0.258819043636322f,
    0.2079116851091385f, 0.15643446147441864f, 0.10452846437692642f, 0.0523359552025795f, 0.0f,
    -1.0f,
};
/* D_002E09E8 is 0x2E09E8. */
s32 D_002E09E8[32] = {
    0, -5, -19, -44, -79, -125, -184, -258, -349, -462, -602, -781, -1020, -1364, -1962, -10000,
    -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000,
    -10000, -10000, -10000, -10000,
};
/* D_002E0A68 is 0x2E0A68. */
s32 D_002E0A68[256] = {
    0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -2, -2, -2, -3, -3, -4, -4, -5, -5, -6, -7, -7, -8, -9, -10,
    -10, -11, -12, -13, -14, -15, -16, -17, -18, -19, -21, -22, -23, -24, -26, -27, -28, -30, -31,
    -33, -34, -36, -37, -39, -41, -42, -44, -46, -48, -49, -51, -53, -55, -57, -59, -61, -63, -65,
    -68, -70, -72, -74, -77, -79, -82, -84, -87, -89, -92, -94, -97, -100, -102, -105, -108, -111,
    -114, -117, -120, -123, -126, -129, -132, -136, -139, -142, -145, -149, -152, -156, -159, -163,
    -167, -170, -174, -178, -182, -186, -190, -194, -198, -202, -206, -210, -214, -219, -223, -228,
    -232, -237, -241, -246, -251, -255, -260, -265, -270, -275, -280, -285, -290, -296, -301, -306,
    -312, -317, -323, -329, -334, -340, -346, -352, -358, -364, -371, -377, -383, -390, -396, -403,
    -409, -416, -423, -430, -437, -444, -451, -459, -466, -474, -481, -489, -497, -505, -513, -521,
    -529, -537, -546, -554, -563, -572, -581, -590, -599, -608, -618, -627, -637, -647, -657, -667,
    -678, -688, -699, -709, -720, -732, -743, -755, -766, -778, -790, -803, -815, -828, -841, -854,
    -867, -881, -895, -909, -924, -938, -954, -969, -984, -1000, -1017, -1033, -1050, -1068, -1085,
    -1104, -1122, -1141, -1161, -1181, -1201, -1222, -1244, -1266, -1289, -1312, -1336, -1361,
    -1386, -1413, -1440, -1468, -1497, -1527, -1559, -1591, -1625, -1660, -1697, -1735, -1775,
    -1818, -1862, -1909, -1958, -2011, -2066, -2126, -2190, -2260, -2335, -2418, -2509, -2612,
    -2728, -2861, -3020, -3213, -3463, -3815, -4417, -10000, -10000,
};

/* xb_mwsnd_PlayDsb 0x16C2B0.
 *
 * Starts the buffer looping and waits (up to 1/1500 s) until it reports
 * playing; the counterpart of mwSndStop. */

void xb_mwsnd_PlayDsb(void *dsb) {
    MwU64 start;
    MwU64 now;
    MwU64 scale;
    long long limit;
    long long start_ticks;
    long long now_ticks;
    u32 stat;

    if (IDirectSoundBuffer_Play(dsb, 0, 0, 1) != 0) {
        xb_mwerr_CallErrFunc("E1226:IDirectSoundBuffer_Play return error in mwSndPlay");
    }

    QueryPerformanceCounter(&start);
    IDirectSoundBuffer_GetStatus(dsb, &stat);

    if (stat & 1) {
        return;
    }

    do {
        QueryPerformanceFrequency(&scale);
        limit = (long long)(((unsigned long long)scale.hi << 32) | scale.lo) / 0x5DC;
        QueryPerformanceCounter(&now);
        now_ticks = (long long)(((unsigned long long)now.hi << 32) | now.lo);
        start_ticks = (long long)(((unsigned long long)start.hi << 32) | start.lo);

        if (now_ticks - start_ticks > limit || now_ticks <= start_ticks) {
            break;
        }

        IDirectSoundBuffer_GetStatus(dsb, &stat);
    } while ((stat & 1) == 0);
}

/* xb_mwsnd_MonoToStereoScaled 0x16CB50.
 *
 * A centred mono stream into a stereo buffer, each side at -3 dB. */

void xb_mwsnd_MonoToStereoScaled(s16 *dst, s16 *src, s32 nbytes) {
    u32 n = (u32)(nbytes / 2) >> 1;

    for (; n != 0; n--) {
        dst[0] = (s16)(*src * 0.70710677f);
        dst[1] = (s16)(*src * 0.70710677f);
        dst += 2;
        src++;
    }
}

/* xb_mwsnd_InterleaveMono 0x16CBC0.
 *
 * One channel into every other sample of a stereo buffer. */

void xb_mwsnd_InterleaveMono(s16 *dst, s16 *src, s32 nbytes) {
    u32 n = (u32)(nbytes / 2) >> 1;

    for (; n != 0; n--) {
        *dst = *src++;
        dst += 2;
    }
}

#define MWSND_PAN_GAIN(pan) D_002E0968[(pan) < 0 ? -(pan) : (pan)]

/* xb_mwsnd_MixPanCh0 0x16CC00.
 *
 * Channel 0 panned (+0x44, -15..15) into a stereo buffer, overwriting
 * it. */

void xb_mwsnd_MixPanCh0(u8 *hn, s16 *dst, s16 *src, s32 nbytes) {
    s32 pan = *(s32 *)(hn + 0x44);
    f32 gl = MWSND_PAN_GAIN(pan + 15);
    f32 gr = MWSND_PAN_GAIN(pan - 15);
    u32 n = (u32)(nbytes / 2) >> 1;

    for (; n != 0; n--) {
        dst[0] = (s16)(*src * gl);
        dst[1] = (s16)(*src * gr);
        dst += 2;
        src++;
    }
}

/* xb_mwsnd_MixPanCh1 0x16CCA0.
 *
 * Channel 1 panned (+0x48) and added to the stereo buffer, clipped. */

void xb_mwsnd_MixPanCh1(u8 *hn, s16 *dst, s16 *src, s32 nbytes) {
    s32 pan = *(s32 *)(hn + 0x48);
    f32 gl = MWSND_PAN_GAIN(pan + 15);
    f32 gr = MWSND_PAN_GAIN(pan - 15);
    u32 n = (u32)(nbytes / 2) >> 1;
    f32 l;
    f32 r;

    for (; n != 0; n--) {
        l = *src * gl + dst[0];
        r = *src * gr + dst[1];
        src++;

        if ((s32)l > 0x7FFF) {
            dst[0] = 0x7FFF;
        } else if ((s32)l < -0x8000) {
            dst[0] = -0x8000;
        } else {
            dst[0] = (s32)l;
        }

        if ((s32)r > 0x7FFF) {
            dst[1] = 0x7FFF;
        } else if ((s32)r < -0x8000) {
            dst[1] = -0x8000;
        } else {
            dst[1] = (s32)r;
        }

        dst += 2;
    }
}

/* xb_mwsnd_Write 0x16CDC0.
 *
 * Writes channel ch's samples at sample position pos into the buffer:
 * copied as they are for a mono buffer; for a stereo one, a mono source
 * is centred or panned, and a stereo source hard-panned left/right is
 * interleaved, otherwise each channel is panned and mixed. Fewer than
 * 0x20 bytes are not written. */

void xb_mwsnd_Write(u8 *hn, s32 ch, s32 pos, s16 *data, s32 nsmpl) {
    void *dsb;
    s32 bps;
    s32 nbytes;
    void *p1;
    u32 n1;
    void *p2;
    u32 n2;

    if (*(s32 *)(hn + 4) == 0) {
        return;
    }

    if ((dsb = *(void **)(hn + 8)) == 0) {
        xb_mwerr_CallErrFunc("E1225:dsb(member in handle) is NULL");
        return;
    }

    bps = *(u16 *)(hn + 0x22);
    nbytes = bps * nsmpl / 8;

    if (nbytes < 0x20) {
        return;
    }

    if (IDirectSoundBuffer_Lock(dsb, bps * pos / 8 * *(s32 *)(hn + 0x2C), *(s32 *)(hn + 0x2C) * nbytes, &p1, &n1, &p2,
                                &n2, 0) != 0) {
        xb_mwerr_CallErrFunc("E1234:IDirectSoundBuffer_Lock return error");
    }

    if (*(s32 *)(hn + 0x2C) == 1) {
        xb_mwsnd_CopyPcm(p1, data, n1);
    } else if (*(s32 *)(hn + 0x2C) == 2) {
        if (*(s32 *)(hn + 0x30) == 1) {
            if (*(s32 *)(hn + 0x44) == 0) {
                xb_mwsnd_MonoToStereoScaled(p1, data, n1);
            } else {
                xb_mwsnd_MixPanCh0(hn, p1, data, n1);
            }
        } else if (*(s32 *)(hn + 0x44) == -15 && *(s32 *)(hn + 0x48) == 15) {
            if (ch == 0) {
                xb_mwsnd_InterleaveMono(p1, data, n1);
            } else {
                xb_mwsnd_InterleaveMono((s16 *)p1 + 1, data, n1);
            }
        } else if (ch == 0) {
            xb_mwsnd_MixPanCh0(hn, p1, data, n1);
        } else {
            xb_mwsnd_MixPanCh1(hn, p1, data, n1);
        }
    }

    if (IDirectSoundBuffer_Unlock(dsb, p1, n1, p2, n2) != 0) {
        xb_mwerr_CallErrFunc("E1235:IDirectSoundBuffer_Unlock return error");
    }
}

typedef struct {
    s32 bin;
    s32 vol;
} MwMixBinVol;

typedef struct {
    s32 count;
    MwMixBinVol *pairs;
} MwMixBins;

#define MWSND_DB(tbl, i) (tbl)[(i) < 0 ? -(i) : (i)]

/* xb_mwsnd_ApplyPan 0x16CFE0.
 *
 * Pans a mono voice across the left, right and centre speaker bins
 * (dB table at 0x2E09E8), unless it already has that pan. */

void xb_mwsnd_ApplyPan(void *p, s32 ch, s32 pan) {
    u8 *hn = p;
    MwMixBins mb;
    MwMixBinVol pairs[3];

    (void)ch;
    mb.count = 0;
    mb.pairs = 0;
    pairs[0].bin = 0;
    pairs[0].vol = 0;
    pairs[1].bin = 1;
    pairs[1].vol = 0;
    pairs[2].bin = 2;
    pairs[2].vol = 0;

    if (*(s32 *)(hn + 0xC) == 1 || *(s32 *)(hn + 0x44) == pan) {
        return;
    }

    *(s32 *)(hn + 0x44) = pan;
    pairs[0].vol = MWSND_DB(D_002E09E8, pan + 15);
    pairs[2].vol = MWSND_DB(D_002E09E8, pan);
    pairs[1].vol = MWSND_DB(D_002E09E8, pan - 15);
    mb.pairs = pairs;
    *(s32 *)(hn + 0x4C) = 0;
    mb.count = 3;

    if (*(s32 *)(hn + 0x10) == 0) {
        xb_mwsnd_SetMixBins(hn, &mb);
    } else {
        IDirectSoundBuffer_SetMixBinVolumes_8(*(void **)(hn + 8), &mb);
    }
}

/* xb_mwsnd_SetSpeakerMix 0x16D0C0.
 *
 * Positions a mono 3D voice: a (left/right) and b (front/back),
 * -127..127, give the four speaker bins' volumes (dB table at
 * 0x2E0A68), each clamped to -10000..0. */

void xb_mwsnd_SetSpeakerMix(void *p, s32 a, s32 b) {
    u8 *hn = p;
    MwMixBins mb;
    MwMixBinVol pairs[4];
    s32 la;
    s32 ra;
    s32 fb;
    s32 bb;
    s32 v0;
    s32 v1;
    s32 v2;
    s32 v3;

    mb.count = 0;
    mb.pairs = 0;
    pairs[0].bin = 0;
    pairs[0].vol = 0;
    pairs[1].bin = 1;
    pairs[1].vol = 0;
    pairs[2].bin = 4;
    pairs[2].vol = 0;
    pairs[3].bin = 5;
    pairs[3].vol = 0;

    if (*(s32 *)(hn + 0xC) == 1) {
        return;
    }

    if (*(s32 *)(hn + 0x2C) != 1) {
        xb_mwerr_CallErrFunc("E1240:Handle must be created for 3D sound.");
        return;
    }

    la = MWSND_DB(D_002E0A68, a + 0x7F);
    ra = MWSND_DB(D_002E0A68, a - 0x7F);
    fb = MWSND_DB(D_002E0A68, b + 0x7F);
    bb = MWSND_DB(D_002E0A68, b - 0x7F);
    v0 = fb + la;
    v1 = fb + ra;
    v2 = bb + la;
    v3 = bb + ra;
    v0 = v0 > 0 ? 0 : v0 < -10000 ? -10000 : v0;
    v1 = v1 > 0 ? 0 : v1 < -10000 ? -10000 : v1;
    v2 = v2 > 0 ? 0 : v2 < -10000 ? -10000 : v2;
    v3 = v3 > 0 ? 0 : v3 < -10000 ? -10000 : v3;
    pairs[3].vol = v3;
    pairs[2].vol = v2;
    pairs[0].vol = v0;
    pairs[1].vol = v1;
    mb.count = 4;
    mb.pairs = pairs;

    if (*(s32 *)(hn + 0x10) == 0) {
        xb_mwsnd_SetMixBins(hn, &mb);
    } else {
        IDirectSoundBuffer_SetMixBinVolumes_8(*(void **)(hn + 8), &mb);
    }
}

extern void xb_aixp_ReturnZero(void);
extern void xb_mwsnd_GetCmdResult(void);
extern void xb_mwsnd_ReturnOne(void);
/* D_0043C9C8 is 0x43C9C8: the mwSnd voice interface. */
void *D_0043C9C8[32] = {
    0, 0, 0, (void *)xb_mwsnd_Init, (void *)xb_mwsnd_Finish, (void *)mwSndOpenPort, 0,
    0, 0, (void *)xb_mwsnd_ClosePort, (void *)mwSndPlay, (void *)xb_mwsnd_StopPort,
    (void *)xb_mwsnd_GetBufSize, (void *)xb_mwsnd_SetNumChan,
    (void *)xb_mwsnd_GetPlayPos, (void *)xb_mwsnd_SetSfreq, (void *)xb_mwsnd_GetSfreq,
    (void *)xb_mwsnd_SetBitPerSmpl, (void *)xb_mwsnd_GetBitPerSmpl,
    (void *)mwSndSetVol, (void *)xb_mwsnd_GetVol, (void *)xb_mwsnd_SetOutPan,
    (void *)xb_mwsnd_GetVol, (void *)mwSndSetBalance, (void *)xb_mwsnd_GetBalance,
    (void *)xb_mwsnd_ExecCmd, (void *)xb_mwsnd_GetCmdResult, (void *)xb_mwsnd_Write,
    (void *)xb_mwsnd_ResetPlayPos, (void *)xb_mwsnd_ReturnOne,
    (void *)xb_mwsnd_GetQueued, (void *)xb_aixp_ReturnZero,
};
