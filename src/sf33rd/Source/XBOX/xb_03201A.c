/* xb_03201A.c: Xbox-only code from the run of Xbox-only functions at 0x3201A, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

s32 sort_push_request8(WORK* wk);
extern s8 Suicide[8];
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 Pause_Hit_Marks;

void xb_effect_02_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Pause_Hit_Marks == 0) {
            sort_push_request8(&ewk->wu);
        }

        break;

    case 1:
        if (ewk->wu.dead_f != 1 && Suicide[6] == 0 && Pause_Hit_Marks == 0 &&
            (EXE_flag != 0 || Game_pause != 0 || ewk->wu.cg_type != 0xFF)) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
            ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
            sort_push_request8(&ewk->wu);
        }

        break;
    }
}
