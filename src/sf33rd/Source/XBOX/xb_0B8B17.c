/* xb_0B8B17.c: Xbox-only code from the run of Xbox-only functions at 0xB8B17, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

s32 obr_no_disp_check(void);
void disp_pos_trans_entry_r(WORK_Other* ewk);

void xb_effect_J6_draw(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 1:
    case 2:
    case 4:
        disp_pos_trans_entry_r(ewk);
        break;
    }
}
