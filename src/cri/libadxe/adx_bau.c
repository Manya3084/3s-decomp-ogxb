/* adx_bau.c: the Sun AU path of the ADX decoder. ADXB_CheckAu 0x1746C0 and
 * ADXB_ExecOneAu 0x174BA0 (the 8- and 16-bit bodies are folded with the
 * AIFF ones at 0x174990 and 0x174870). */

#include "types.h"

#include <string.h>

extern void ADXB_ExecOneAuUlaw(void *adxb);
extern void ADXB_ExecOneAu8(void *adxb);
extern void ADXB_ExecOneAu16(void *adxb);

s32 ADXB_CheckAu(u8 *hdr) {
    if (memcmp(hdr, ".snd", 4) == 0 || memcmp(hdr, ".sd", 4) == 0) {
        return 1;
    }

    return 0;
}

void ADXB_ExecOneAu(void *adxb) {
    s16 fmt = *(s16 *)((u8 *)adxb + 0x9A);

    if (fmt == 2) {
        ADXB_ExecOneAuUlaw(adxb);
    } else if (fmt == 1) {
        ADXB_ExecOneAu8(adxb);
    } else {
        ADXB_ExecOneAu16(adxb);
    }
}
