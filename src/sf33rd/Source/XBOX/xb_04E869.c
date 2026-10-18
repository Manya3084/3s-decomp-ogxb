/* xb_04E869.c: Xbox-only code from the run of Xbox-only functions at 0x4E869, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

s32 obr_no_disp_check(void);
void sub_000EF0C0(WORK_Other* ewk);
s32 compel_dead_check(WORK_Other* ewk);

void xb_effect_12_draw(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (compel_dead_check(ewk) == 0) {
            sub_000EF0C0(ewk);
        }

        break;
    }
}
