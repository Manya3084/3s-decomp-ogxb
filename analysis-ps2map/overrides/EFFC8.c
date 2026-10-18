/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void pl_eff_trans_entry(WORK_Other* ewk);

void xb_effect_C8_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
    case 2:
    case 3:
        pl_eff_trans_entry(ewk);
        break;
    }
}
