/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request4(WORK* wk);
s32 obr_no_disp_check(void);
s32 compel_dead_check(WORK_Other* ewk);
s32 range_x_check(WORK_Other* ewk);
extern void (*const D_0025B2C0[])(WORK* wk);

void xb_effect_25_draw(WORK_Other* ewk) {
    if (compel_dead_check(ewk)) {
        return;
    }

    if (ewk->wu.routine_no[0] == 0 && obr_no_disp_check() == 0 && range_x_check(ewk)) {
        sort_push_request4(&ewk->wu);
    }
}
