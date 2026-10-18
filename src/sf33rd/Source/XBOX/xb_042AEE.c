/* xb_042AEE.c: Xbox-only code from the run of Xbox-only functions at 0x42AEE, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

s32 sort_push_request3(WORK* wk);

void xb_effect_51_draw(WORK_Other* ewk) {
    sort_push_request3(&ewk->wu);
}
