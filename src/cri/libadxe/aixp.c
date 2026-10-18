/* AIXP_SetOutVolDolbyDigital 0x1669B0, AIXP_GetStat 0x166B00,
 * AIXP_GetAdxt 0x166B20, AIXP_SetLpSw 0x166B60, AIXP_Pause 0x167280.
 *
 * stat is the byte at +1. The ADXT table is the pointer array at +0xC.
 * Speaker volumes are the six dwords at +0x204. The loop switch is the
 * byte at +0x1B0. The per-track apply flag is the dword array at +0x1E0.
 * Error calls go through the tail
 * jmp at 0x16EB40, which jumps to ADXERR_CallErrFunc1.
 */

#include "types.h"

#include <stddef.h>

typedef struct {
    s8 used;
    s8 stat;
    s8 maxnch;
    s8 maxntr;
    void *sjd;
    void *stm;
    void *adxt[32];
    u8 gap[0x124];
    s8 lpsw;
    u8 after_lpsw[0x2F];
    s32 unk1E0[9];
    s32 spk_vol[6];
} AIX_PLY;

typedef struct {
    s32 ch;
    s32 vol;
} AIXP_CHVOL;

typedef struct {
    s32 nch;
    AIXP_CHVOL *pair;
} AIXP_OUTVOL;

#if defined(__i386__)
_Static_assert(offsetof(AIX_PLY, stat) == 1, "stat");
_Static_assert(offsetof(AIX_PLY, adxt) == 0xC, "adxt");
_Static_assert(offsetof(AIX_PLY, lpsw) == 0x1B0, "lpsw");
_Static_assert(offsetof(AIX_PLY, unk1E0) == 0x1E0, "unk1E0");
_Static_assert(offsetof(AIX_PLY, spk_vol) == 0x204, "spk_vol");
#endif

extern void ADXERR_CallErrFunc1(const char *msg);
extern void sub_0016AA60(void);
extern void sub_0016AA70(void);
extern void xb_aixp_Pause(AIX_PLY *aixp, s32 sw);
extern void xb_aixp_SetTrackSpeakerVol(void *adxt, AIXP_OUTVOL *arg);
extern void xb_aixp_SetTrackMixBinVolumes(void *adxt, AIXP_OUTVOL *arg);

/* AIXP_GetStat 0x166B00.
 *
 * Returns the status byte at +1. A null handle reports E2003050209
 * and returns -1. The error call is the tail jmp at 0x16EB40.
 * The previous byte is int3, so it is interior.
 */

s32 AIXP_GetStat(AIX_PLY *aixp) {
    if (aixp == 0) {
        ADXERR_CallErrFunc1("E2003050209 : NULL pointer is specified.");
        return -1;
    }

    return aixp->stat;
}

void *AIXP_GetAdxt(AIX_PLY *aixp, s32 trno) {
    if (aixp == 0) {
        ADXERR_CallErrFunc1("E2003050210 : NULL pointer is specified.");
        return 0;
    }

    if (trno > 0x20) {
        ADXERR_CallErrFunc1("E2003052112 : The parameter 'trno' is out of range.");
        return 0;
    }

    return aixp->adxt[trno];
}

/* AIXP_SetOutVolDolbyDigital 0x1669B0.
 *
 * Scales vol by 10 and clamps it to -10000..0, then stores it at
 * spk_vol[spkid] before the range check. spkid above 5 reports
 * E2003110703. Speakers 0 and 1 use channels 0 and 1, speakers 2 and 3
 * use channels 4 and 5, and speakers 4 and 5 use channels 2 and 3.
 * The pair is applied to adxt[spkid / 2]. The first apply calls
 * 0x16AFB0 and sets unk1E0. Later applies call 0x16AFD0. The jump
 * table is at 0x166ADC. It is a scanned start.
 */

void AIXP_SetOutVolDolbyDigital(AIX_PLY *aixp, s32 spkid, s32 vol) {
    s32 scaled;
    s32 track;
    AIXP_CHVOL pair[2];
    AIXP_OUTVOL arg;

    if (aixp == 0) {
        ADXERR_CallErrFunc1("E2003110701 : NULL pointer is specified.");
        return;
    }

    scaled = vol * 10;

    if (scaled > 0) {
        scaled = 0;
    } else if (scaled < -10000) {
        scaled = -10000;
    }

    aixp->spk_vol[spkid] = scaled;

    if ((u32)spkid > 5) {
        ADXERR_CallErrFunc1("E2003110703 : Illegal speaker ID is specified.");
        return;
    }

    if (spkid <= 1) {
        pair[0].ch = 0;
        pair[0].vol = aixp->spk_vol[0];
        pair[1].ch = 1;
        pair[1].vol = aixp->spk_vol[1];
    } else if (spkid <= 3) {
        pair[0].ch = 4;
        pair[0].vol = aixp->spk_vol[2];
        pair[1].ch = 5;
        pair[1].vol = aixp->spk_vol[3];
    } else {
        pair[0].ch = 2;
        pair[0].vol = aixp->spk_vol[4];
        pair[1].ch = 3;
        pair[1].vol = aixp->spk_vol[5];
    }

    track = spkid / 2;
    arg.nch = 2;
    arg.pair = pair;

    if (aixp->unk1E0[track] == 0) {
        xb_aixp_SetTrackSpeakerVol(aixp->adxt[track], &arg);
        aixp->unk1E0[track] = 1;
    } else {
        xb_aixp_SetTrackMixBinVolumes(aixp->adxt[track], &arg);
    }
}

/* AIXP_SetLpSw 0x166B60.
 *
 * Stores the low byte of sw at +0x1B0. The unnamed body at 0x166BF0
 * wraps the phrase at +0x1BC back to +0x1C4 when this byte is 1 and
 * the phrase reaches +0x1C8. The next byte, +0x1B1, gates the link
 * path in that same body. A null handle reports E2003050211.
 * It is a scanned start.
 */

void AIXP_SetLpSw(AIX_PLY *aixp, s32 sw) {
    if (aixp == 0) {
        ADXERR_CallErrFunc1("E2003050211 : NULL pointer is specified.");
        return;
    }

    aixp->lpsw = (s8)sw;
}

/* AIXP_Pause 0x167280.
 *
 * Locks, then calls 0x166B90. Xbox passes the handle in esi and pushes
 * only sw. That body stores sw at +0x1A8. Unless stat is 1, it calls
 * ADXT_Pause on each adxt[i]. A null handle there tail-jumps through
 * 0x16EB40 with E2003050222. This wrapper tail-jumps to ADXCRS_Unlock.
 * The previous byte is int3, so it is interior.
 */

void AIXP_Pause(AIX_PLY *aixp, s32 sw) {
    sub_0016AA60();
    xb_aixp_Pause(aixp, sw);
    sub_0016AA70();
}
