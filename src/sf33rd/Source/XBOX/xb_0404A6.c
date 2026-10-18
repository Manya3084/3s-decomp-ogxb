/* xb_0404A6.c: Xbox-only code from the run of Xbox-only functions at 0x404A6, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

s32 sort_push_request4(WORK* wk);

void xb_effect_38_draw(WORK_Other* ewk) {
    if (ewk->wu.be_flag) {
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request4(&ewk->wu);
    }
}
