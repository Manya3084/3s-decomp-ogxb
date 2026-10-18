/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void sub_000EF0C0(WORK_Other* ewk);

void xb_effect_68_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        sub_000EF0C0(ewk);
        break;
    }
}
