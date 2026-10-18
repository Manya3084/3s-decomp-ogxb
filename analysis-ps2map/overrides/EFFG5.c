/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request8(WORK* wk);
extern s8 Pause_Hit_Marks;

void xb_effect_G5_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (Pause_Hit_Marks == 0) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
            sort_push_request8(&ewk->wu);
        }

        break;
    }
}
