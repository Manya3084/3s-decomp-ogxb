/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request4(WORK* wk);

void xb_effect_42_draw(WORK_Other* ewk) {
    if (ewk->wu.be_flag) {
        sort_push_request4(&ewk->wu);
    }
}
