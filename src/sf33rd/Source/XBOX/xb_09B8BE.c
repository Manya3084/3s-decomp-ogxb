/* xb_09B8BE.c: Xbox-only code from the run of Xbox-only functions at 0x9B8BE, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"

extern u32 adxt;
void ADXT_ClearErrCode(u32 adxt);

void xb_ClearAdxtError(s32 which) {
    if (which == 0) {
        ADXT_ClearErrCode(adxt);
    }
}
