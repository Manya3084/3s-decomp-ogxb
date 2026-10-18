/* adx_bsps.c: the SPSD path of the ADX decoder. ADXB_CheckSpsd 0x1752C0. */

#include "types.h"

#include <string.h>

s32 ADXB_CheckSpsd(u8 *hdr) {
    return memcmp(hdr, "SPSD", 4) == 0;
}
