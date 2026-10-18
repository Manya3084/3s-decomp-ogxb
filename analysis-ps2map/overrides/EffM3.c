/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void effM3_trans(WORK* ewk);
extern s8 Suicide[8];
extern s8 Next_Step;

void xb_effect_M3_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[2] != 0) {
            break;
        }

        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (!(Next_Step & 1)) {
                break;
            }

            /* fallthrough */

        case 1:
            if (ewk->wu.dir_timer >= 0) {
                break;
            }

            /* fallthrough */

        case 2:
            ewk->wu.mvxy.d[0].sp = (ewk->wu.mvxy.d[0].sp * ewk->wu.dmcal_m) / ewk->wu.dmcal_d;
            break;
        }

        ewk->wu.my_mr.size.x = ewk->wu.my_mr.size.y = ewk->wu.mvxy.a[0].real.h + 63;
        effM3_trans(&ewk->wu);
        break;
    }
}
