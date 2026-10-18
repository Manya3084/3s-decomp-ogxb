/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request4(WORK* wk);
s32 Ck_Range_Out_S(WORK_Other* ewk, s16 BG_No, s16 R);
extern void (*const D_0025B2C0[])(WORK* wk);

void xb_effect_95_draw(WORK_Other* ewk) {
    if (ewk->wu.routine_no[0] == 3 && Ck_Range_Out_S(ewk, 1, 0x40)) {
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
    sort_push_request4(&ewk->wu);
}
