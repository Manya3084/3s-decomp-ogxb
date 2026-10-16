/* ADXSJD_SetLnkSw 0x170160.
 *
 * lnkflg is a dword at +0x9C. adxb is the pointer at +4.
 */

#include "types.h"

#include <stddef.h>

typedef struct ADXSJD_OBJ {
    u8 gap00[4];
    void *adxb;
    u8 gap08[0x94];
    s32 lnkflg;
} ADXSJD_OBJ;

typedef ADXSJD_OBJ *ADXSJD;

#if defined(__i386__)
_Static_assert(offsetof(ADXSJD_OBJ, adxb) == 4, "adxb");
_Static_assert(offsetof(ADXSJD_OBJ, lnkflg) == 0x9C, "lnkflg");
#endif

void ADXSJD_SetLnkSw(ADXSJD sjd, s32 sw) {
    sjd->lnkflg = sw;
}

/* GetSfreq 0x1701D0, GetNumChan 0x1701E0, GetOutBps 0x1701F0, and
 * GetTotalNumSmpl 0x170210. Each replaces its argument with adxb and tail-jumps.
 * ADXT_GetNumChan jumps to GetNumChan. The PLAYEND path at 0x167B60, which
 * is not named yet, stores GetTotalNumSmpl in *ncount, stores GetSfreq in
 * *tscale, and divides 16 by GetOutBps. The same-shaped thunks at 0x1701C0
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
