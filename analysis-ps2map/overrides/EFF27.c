/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request4(WORK* wk);
s32 obr_no_disp_check(void);

void xb_effect_27_draw(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 1:
        sort_push_request4(&ewk->wu);
        break;
    }
}
