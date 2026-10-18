/* xb_049F1C.c: Xbox-only code from the run of Xbox-only functions at 0x49F1C, which no
 * PS2 file covers.
 * Capcom's source is lost. Its C++ methods are written as C,
 * XB_FASTCALL (__fastcall) with this first. Each body was checked
 * against retail by analysis-ps2map/xbgen.py. The xb_ names are
 * made up. */

#include "types.h"
#include "structs.h"

s32 sort_push_request(WORK* wk);
void get_attdata_of_illusion(WORK_Other* ewk);
extern s16 EXE_flag;
extern u8 Game_pause;
extern const s16 after_image_color[][2];

void xb_effect_E7_draw(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;
    s16 pricol;

    switch (ewk->wu.routine_no[0]) {
    case 0:
    case 1:
        if (ewk->wu.dead_f == 1) {
            break;
        }

        if (Game_pause != 0x81) {
            if (ewk->wu.old_rno[5]) {
                ewk->wu.position_x = mwk->wu.position_x;
                ewk->wu.position_y = mwk->wu.position_y;
            }

            ewk->wu.position_z = mwk->wu.position_z;

            if (ewk->wu.old_rno[3] == 0) {
                ewk->wu.cg_number = mwk->wu.cg_number;
                ewk->wu.rl_flag = mwk->wu.rl_flag;
                ewk->wu.cg_flip = mwk->wu.cg_flip;
            }

            if (EXE_flag == 0 && Game_pause == 0) {
                break;
            }

            pricol = ewk->wu.dmcal_d - (ewk->wu.dir_timer + ewk->wu.dmcal_m - 1) / ewk->wu.dmcal_m;
            ewk->wu.old_rno[6] = pricol;

            if (ewk->wu.old_rno[0]) {
                ewk->wu.position_z -= pricol;
            } else {
                ewk->wu.position_z += pricol;
            }

            if (ewk->wu.old_rno[4]) {
                if (ewk->wu.olc_work_ix[2] && mwk->metamorphose) {
                    ewk->wu.extra_col = after_image_color[ewk->wu.old_rno[4] + pricol][(ewk->master_id + 1) & 1];
                } else {
                    ewk->wu.extra_col = after_image_color[ewk->wu.old_rno[4] + pricol][ewk->master_id];
                }
            } else {
                ewk->wu.extra_col = mwk->wu.current_colcd;
            }

            if (ewk->wu.old_rno[1]) {
                get_attdata_of_illusion(ewk);
            }

            ewk->wu.my_bright_level = (ewk->wu.old_rno[6] * 3) + 1;
        }

        if (mwk->wu.disp_flag != 0 && mwk->sa_stop_flag == 0) {
            sort_push_request(&ewk->wu);
        }

        break;
    }
}
