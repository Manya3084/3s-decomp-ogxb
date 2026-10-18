/* xb_0BE935.c: Xbox-only code from the run of Xbox-only functions at 0xBE935, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

void sub_000EF0C0(WORK_Other* ewk);
extern void (*const D_0025B2C0[])(WORK* wk);

void xb_effect_I6_draw(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;

    switch (mwk->routine_no[0]) {
    case 3:
        ewk->wu.my_mr.size.x = mwk->my_mr.size.x;
        ewk->wu.my_mr.size.y = mwk->my_mr.size.y;
        sub_000EF0C0(ewk);
        break;

    case 4:
        sub_000EF0C0(ewk);
        break;
    }
}
