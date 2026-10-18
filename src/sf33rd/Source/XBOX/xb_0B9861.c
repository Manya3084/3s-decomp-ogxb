/* xb_0B9861.c: Xbox-only code from the run of Xbox-only functions at 0xB9861, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

void pl_eff_trans_entry(WORK_Other* ewk);

void xb_effect_L7_draw(WORK_Other* ewk) {
    if (ewk->wu.routine_no[0] == 0) {
        pl_eff_trans_entry(ewk);
    }
}
