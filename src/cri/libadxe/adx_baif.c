/* adx_baif.c: the AIFF path of the ADX decoder. ADXB_CheckAiff 0x174E40 and
 * ADXB_ExecOneAiff 0x174FF0. */

#include "types.h"

#include <string.h>

extern void ADXB_ExecOneAiff8(void *adxb);
extern void ADXB_ExecOneAiff16(void *adxb);

s32 ADXB_CheckAiff(u8 *hdr) {
    if (memcmp(hdr, "FORM", 4) == 0 && memcmp(hdr + 8, "AIFF", 4) == 0) {
        return 1;
    }

    return 0;
}

void ADXB_ExecOneAiff(void *adxb) {
    if (*(s16 *)((u8 *)adxb + 0x9A) == 1) {
        ADXB_ExecOneAiff8(adxb);
    } else {
        ADXB_ExecOneAiff16(adxb);
    }
}
