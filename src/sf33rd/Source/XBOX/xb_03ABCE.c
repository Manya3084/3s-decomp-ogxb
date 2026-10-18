/* xb_03ABCE.c: Xbox-only code from the run of Xbox-only functions at 0x3ABCE, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

s32 sort_push_request(WORK* wk);

void xb_effect_32_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
    case 2:
    case 3:
        sort_push_request(&ewk->wu);
        break;
    }
}
