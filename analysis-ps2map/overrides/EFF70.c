/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request4(WORK* wk);

void xb_effect_70_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        sort_push_request4(&ewk->wu);
        break;
    }
}
