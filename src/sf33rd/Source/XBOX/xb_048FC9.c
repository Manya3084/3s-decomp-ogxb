/* xb_048FC9.c: Xbox-only code from the run of Xbox-only functions at 0x48FC9, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

s32 sort_push_request8(WORK* wk);
extern s16 EXE_flag;
extern u8 Game_pause;
extern void (*const D_0024D368[17])();

void xb_effect_E2_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        sort_push_request8(&ewk->wu);
        break;

    case 1:
        if (ewk->wu.routine_no[1] == 0) {
            if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.cg_type && ewk->wu.cg_type == 1) {
                sort_push_request8(&ewk->wu);
            }

            sort_push_request8(&ewk->wu);
        }

        break;
    }
}
