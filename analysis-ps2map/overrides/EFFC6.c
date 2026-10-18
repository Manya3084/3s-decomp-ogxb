/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request(WORK* wk);

void xb_effect_C6_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
    case 2:
        sort_push_request(&ewk->wu);
        break;
    }
}
