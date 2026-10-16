/* ADXSJD_SetLnkSw 0x170160.
 * ADXSJD_ExecHndl 0x170700, ADXSJD_ExecServer 0x170730.
 *
 * lnkflg is a dword at +0x9C. adxb is the pointer at +4.
 * used is +0 and state is +1. The object is 0xA0 bytes.
 * ExecServer walks 10 objects from 0xCD5AA0 through 0xCD64A0.
 * ExecHndl sends state 2 to adxsjd_decode_exec and state 1 to 0x16FD00.
 * adxsjd_decode_exec is 0x170690. The format word is adxb+0x98.
 * Formats 0xA, 0x14, 0xB, 0xC, and 0xF call 0x1700F0.
 */

#include "types.h"

#include <stddef.h>

#define ADXSJD_MAX_OBJ 10

typedef struct ADXB_OBJ {
    u8 gap00[0x98];
    s16 format;
} ADXB_OBJ;

typedef struct ADXSJD_OBJ {
    s8 used;
    s8 state;
    s8 maxnch;
    s8 unk3;
    ADXB_OBJ *adxb;
    u8 gap08[0x94];
    s32 lnkflg;
} ADXSJD_OBJ;

typedef ADXSJD_OBJ *ADXSJD;

#if defined(__i386__)
_Static_assert(offsetof(ADXB_OBJ, format) == 0x98, "format");
_Static_assert(offsetof(ADXSJD_OBJ, used) == 0, "used");
_Static_assert(offsetof(ADXSJD_OBJ, state) == 1, "state");
_Static_assert(offsetof(ADXSJD_OBJ, adxb) == 4, "adxb");
_Static_assert(offsetof(ADXSJD_OBJ, lnkflg) == 0x9C, "lnkflg");
_Static_assert(sizeof(ADXSJD_OBJ) == 0xA0, "ADXSJD_OBJ");
#endif

void ADXSJD_SetLnkSw(ADXSJD sjd, s32 sw) {
    sjd->lnkflg = sw;
}

/* GetSfreq 0x1701D0, GetNumChan 0x1701E0, GetOutBps 0x1701F0, and
 * GetTotalNumSmpl 0x170210. Each replaces its argument with adxb and tail-jumps.
 * ADXT_GetNumChan jumps to GetNumChan. ADXT_GetTimeSfreq2's PLAYEND path
 * stores GetTotalNumSmpl in *ncount, stores GetSfreq in *tscale, and
 * divides 16 by GetOutBps. The same-shaped thunks at 0x1701C0
 * and 0x170200 stay unnamed. The ADXB callees (0x172C60, 0x172C70,
 * 0x172C80, 0x172CF0) are not named yet.
 */

extern s32 ADXB_GetSfreq(void *adxb);
extern s32 ADXB_GetNumChan(void *adxb);
extern s32 ADXB_GetOutBps(void *adxb);
extern s32 ADXB_GetTotalNumSmpl(void *adxb);

s32 ADXSJD_GetSfreq(ADXSJD sjd) {
    return ADXB_GetSfreq(sjd->adxb);
}

s32 ADXSJD_GetNumChan(ADXSJD sjd) {
    return ADXB_GetNumChan(sjd->adxb);
}

s32 ADXSJD_GetOutBps(ADXSJD sjd) {
    return ADXB_GetOutBps(sjd->adxb);
}

s32 ADXSJD_GetTotalNumSmpl(ADXSJD sjd) {
    return ADXB_GetTotalNumSmpl(sjd->adxb);
}

extern ADXSJD_OBJ adxsjd_obj[ADXSJD_MAX_OBJ];
extern s32 ADXB_GetStat(void *adxb);
extern void ADXB_ExecHndl(void *adxb);
extern void adxsjd_decexec_start(ADXSJD sjd);
extern void adxsjd_decexec_end(ADXSJD sjd);
extern void adxsjd_decexec_extra(ADXSJD sjd);
extern void adxsjd_decode_prep(ADXSJD sjd);

void adxsjd_decode_exec(ADXSJD sjd) {
    ADXB_OBJ *adxb;
    s16 format;

    adxb = sjd->adxb;

    if (ADXB_GetStat(adxb) == 0) {
        adxsjd_decexec_start(sjd);
    }

    ADXB_ExecHndl(adxb);

    if (ADXB_GetStat(adxb) == 3) {
        adxsjd_decexec_end(sjd);
    }

    format = adxb->format;

    if (format == 0xA || format == 0x14 || format == 0xB || format == 0xC || format == 0xF) {
        adxsjd_decexec_extra(sjd);
    }
}

void ADXSJD_ExecHndl(ADXSJD sjd) {
    s8 state;

    state = sjd->state;

    if (state == 2) {
        adxsjd_decode_exec(sjd);
    } else if (state == 1) {
        adxsjd_decode_prep(sjd);
    }
}

void ADXSJD_ExecServer(void) {
    s32 i;

    for (i = 0; i < ADXSJD_MAX_OBJ; i++) {
        if (adxsjd_obj[i].used == 1) {
            ADXSJD_ExecHndl(&adxsjd_obj[i]);
        }
    }
}
