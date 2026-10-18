/* xb_041D43.c: Xbox-only code from the run of Xbox-only functions at 0x41D43, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

void sub_000EF0C0(WORK_Other* ewk);

void xb_effect_85_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        sub_000EF0C0(ewk);
        break;
    }
}
