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
