/* xb_03510D.c: Xbox-only code from the run of Xbox-only functions at 0x3510D, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

s32 sort_push_request4(WORK* wk);
s32 obr_no_disp_check(void);
s32 range_x_check(WORK_Other* ewk);
extern void (*const D_0024D368[17])();

void xb_effect_11_draw(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (obr_no_disp_check() == 0 && range_x_check(ewk)) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos + 1;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
            sort_push_request4(&ewk->wu);
        }

        break;
    }
}
