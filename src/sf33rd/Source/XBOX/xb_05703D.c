/* xb_05703D.c: Xbox-only code from the run of Xbox-only functions at 0x5703D, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

s32 sort_push_request3(WORK* wk);
extern BG bg_w;
extern void (*const D_0025B2C0[])(WORK* wk);

void xb_effect_G0_draw(WORK_Other* ewk) {
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].xy[1].disp.pos + ewk->wu.xyz[1].disp.pos;
    sort_push_request3(&ewk->wu);
}
