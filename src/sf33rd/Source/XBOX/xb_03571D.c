/* xb_03571D.c: Xbox-only code from the run of Xbox-only functions at 0x3571D, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

s32 sort_push_request(WORK* wk);
extern s8 Suicide[8];
extern s16 EXE_flag;
extern u8 Game_pause;
extern void (*const D_0024D368[17])();

void xb_effect_13_draw(WORK_Other* ewk) {
    TAMA* tama = (TAMA*)ewk->wu.my_effadrs;

    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.dead_f != 1 && Suicide[6] == 0) {
            if (EXE_flag == 0 && Game_pause == 0) {
                D_0024D368[tama->kind_of_tama](ewk, tama);
            }

            sort_push_request(&ewk->wu);
        }

        break;
    }
}
