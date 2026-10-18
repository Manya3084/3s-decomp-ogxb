/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request4(WORK* wk);
extern s16 Plate_X[2][3];
extern s16 Plate_Y[2][3];
extern void (*const D_0024D368[17])();

void xb_effect_50_draw(WORK_Other* ewk) {
    ewk->wu.xyz[0].disp.pos = ewk->wu.dmcal_m + Plate_X[ewk->master_id][0];
    ewk->wu.xyz[1].disp.pos = ewk->wu.dmcal_d + Plate_Y[ewk->master_id][0];
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}
