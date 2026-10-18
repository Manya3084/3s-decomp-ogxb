/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request3(WORK* wk);
s32 sort_push_request4(WORK* wk);
extern void (*const D_0025B2C0[])(WORK* wk);

void xb_effect_67_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        sort_push_request4(&ewk->wu);
        break;

    case 1:
        sort_push_request4(&ewk->wu);
        break;

    case 2:
        sort_push_request3(&ewk->wu);
        break;

    case 3:
        sort_push_request4(&ewk->wu);
        break;

    case 4:
        sort_push_request3(&ewk->wu);
        break;

    case 5:
        sort_push_request4(&ewk->wu);
        break;

    case 6:
        sort_push_request3(&ewk->wu);
        break;
    }
}
