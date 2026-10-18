/* mwSndStop 0x16C380.
 *
 * A failed stop reports E1229 and returns. Otherwise this waits while
 * status bit 0 is set. The limit is QueryPerformanceFrequency
 * divided by 0x5DC. The scanner start at 0x16C3F0 is inside the wait.
 * 0x199ED8, 0x199F34, 0x123320, 0x123331, 0x1786E0, and 0x1725A0 stay
 * unnamed. The only caller is 0x16C783.
 */

#include "types.h"

#include <string.h>

typedef struct {
    u32 lo;
    u32 hi;
} MwU64;

extern s32 IDirectSoundBuffer_Stop(void *dsb);
extern s32 IDirectSoundBuffer_SetVolume(void *dsb, s32 vol);
extern s32 IDirectSoundBuffer_SetCurrentPosition(void *dsb, s32 pos);
extern void IDirectSoundBuffer_GetStatus(void *dsb, u32 *stat);
extern s32 IDirectSoundBuffer_SetFrequency(void *dsb, s32 freq);
extern void sub_0016C2B0(void *dsb);
extern void QueryPerformanceCounter(MwU64 *out);
extern void QueryPerformanceFrequency(MwU64 *out);
extern void sub_001725A0(const char *msg);
extern void *sub_0016C4A0(void);
extern void sub_0016C4D0(void *hn);
extern s32 sub_0016C4F0(s32 nch, s32 bytes);
extern void sub_0016C260(s32 nch, u8 *fmt);
extern s32 mwsnd_bufsz; /* 0x43CA48 */
extern s32 mwsnd_mode; /* 0x7A603C */

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
        sub_001725A0("E1229:IDirectSoundBuffer_Stop return error in mwSndStop");
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
 * vtable is 0x43C9E0. 0x16C4A0, 0x16C4D0, 0x16C4F0, and 0x16C260 stay
 * unnamed. The only reference is the pointer at 0x43C9DC.
 */

void *mwSndOpenPort(s32 maxnch) {
    void *hn;
    u8 *bytes;
    u8 fmt[0x12];
    s32 created;

    if ((maxnch < 1) || (maxnch > 2)) {
        sub_001725A0("E1221:Illigal parameter(MAXNCH) in mwSndOpenPort");
        return 0;
    }

    hn = sub_0016C4A0();
    if (hn == 0) {
        sub_001725A0("E1222:Not enough instance(MWSND) in mwSndOpenPort");
        return 0;
    }

    memset(hn, 0, (size_t)0x58);
    bytes = hn;
    *(void **)bytes = (void *)0x43C9E0;
    created = sub_0016C4F0(maxnch, mwsnd_bufsz * maxnch);
    if (created == 0) {
        sub_0016C4D0(hn);
        return 0;
    }

    *(s32 *)(bytes + 8) = created;
    *(s32 *)(bytes + 0xC) = mwsnd_mode;
    sub_0016C260(maxnch, fmt);
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
 * to 0x16C2B0 with the buffer. Those callees stay unnamed. The only
 * reference is the pointer at 0x43C9F0.
 */

void mwSndPlay(void *hn) {
    u8 *bytes;
    void *dsb;
    s32 freq;

    bytes = hn;
    if (*(s32 *)(bytes + 4) == 0) {
        return;
    }

    dsb = *(void **)(bytes + 8);
    if (dsb == 0) {
        sub_001725A0("E1225:dsb(member in handle) is NULL");
        return;
    }

    freq = *(s32 *)(bytes + 0x18);
    if (IDirectSoundBuffer_SetFrequency(dsb, freq) != 0) {
        sub_001725A0("E1228:IDirectSoundBuffer_SetFrequency return error in mwSndPlay");
        return;
    }

    if (*(s32 *)(bytes + 0x34) == 1) {
        if (IDirectSoundBuffer_SetCurrentPosition(dsb, 0) != 0) {
            sub_001725A0("E1227:IDirectSoundBuffer_SetCurrentPosition return error");
        }
        *(s32 *)(bytes + 0x34) = 0;
    }

    sub_0016C2B0(dsb);
}

/* mwSndSetVol 0x16C960.
 *
 * A zero dword at +4 returns. A null buffer at +8 reports E1225.
 * The argument times 10 is clamped to -10000..0 and stored at +0x3C.
 * That value plus the dword at +0x4C is clamped the same way and
 * passed to 0x199DF0. A failed call reports E1230. 0x199DF0 and
 * 0x1725A0 stay unnamed. The only reference is the pointer at
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
        sub_001725A0("E1225:dsb(member in handle) is NULL");
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
        sub_001725A0("E1230:IDirectSoundBuffer_SetVolume return error in mwSndSetVol");
    }
}

/* mwSndSetBalance 0x16CA40.
 *
 * A dword of 1 at +0xC returns. A zero dword at +4 returns. A null
 * buffer at +8 reports E1225 and returns. Otherwise the argument is
 * clamped to -15..15, stored at +0x38, and this reports E1232.
 * Every call in the body is 0x1725A0. It stays unnamed. The only
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
        sub_001725A0("E1225:dsb(member in handle) is NULL");
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
    sub_001725A0("E1232:IDirectSoundBuffer_SetPan return error in mwSndSetBalance");
}
