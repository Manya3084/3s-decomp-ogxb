/* xb_061F5E.c: Xbox-only code from the run of Xbox-only functions at 0x61F76, which no PS2 file covers.
 * Capcom's source is lost. The C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first (analysis-ps2map/xbgen.py wrote
 * these from their shapes). The names are made up (xb_). */

#include "types.h"

s32 xb_GetTexRenewBufferSize(void) {
    return 0xD000;
}
