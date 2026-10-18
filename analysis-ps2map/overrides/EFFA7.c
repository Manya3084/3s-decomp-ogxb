/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request8(WORK* wk);
extern s8 Suicide[8];
extern s8 Pause_Hit_Marks;
extern void (*const D_0025B2C0[])(WORK* wk);

void xb_effect_A7_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Pause_Hit_Marks == 0) {
            sort_push_request8(&ewk->wu);
        }

        break;

    case 1:
        if (Pause_Hit_Marks == 0 && ewk->wu.dead_f != 1 && Suicide[6] == 0) {
            sort_push_request8(&ewk->wu);
        }

        break;
    }
}
