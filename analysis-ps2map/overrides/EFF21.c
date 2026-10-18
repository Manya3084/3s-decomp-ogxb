/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request4(WORK* wk);
s32 obr_no_disp_check(void);
s32 range_x_check(WORK_Other* ewk);
extern void (*const D_0025B2C0[])(WORK* wk);

void xb_effect_21_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.old_rno[3]) {
            if (obr_no_disp_check() == 0 && range_x_check(ewk)) {
                sort_push_request4(&ewk->wu);
            }
        } else if (obr_no_disp_check() == 0) {
            sort_push_request4(&ewk->wu);
        }

        break;
    }
}
