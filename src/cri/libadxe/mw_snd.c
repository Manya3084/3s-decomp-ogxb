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
extern void xb_mwsnd_PlayDsb(void *dsb);
extern void QueryPerformanceCounter(MwU64 *out);
extern void QueryPerformanceFrequency(MwU64 *out);
extern void xb_mwerr_CallErrFunc(const char *msg);
extern void *xb_mwsnd_Alloc(void);
extern void xb_mwsnd_Free(void *hn);
extern s32 xb_mwsnd_CreateBuffer(s32 nch, s32 bytes);
extern void xb_mwsnd_MakeWaveFormat(s32 nch, u8 *fmt);
extern s32 mwsnd_bufsz; /* 0x43CA48 */
extern s32 mwsnd_mode; /* 0x7A603C */
extern s32 XB_STDCALL IDirectSoundBuffer_Lock(void *dsb, u32 ofs, u32 size, void **p1, u32 *n1, void **p2, u32 *n2, u32 flags);
extern s32 XB_STDCALL IDirectSoundBuffer_Unlock(void *dsb, void *p1, u32 n1, void *p2, u32 n2);
extern s32 XB_STDCALL IDirectSoundBuffer_GetCurrentPosition(void *dsb, u32 *play, u32 *write);
extern s32 mwsnd_flag; /* mwsnd_flag is 0x7A6038 */
extern u8 mwsnd_obj[16][0x58]; /* mwsnd_obj is 0x7A5AB8 */
void xb_mwsnd_SetSfreq(void *hn, s32 sfreq);
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
    xb_mwsnd_MakeWaveFormat(maxnch, fmt);
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

void xb_mwsnd_Init(s32 flag) {
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
