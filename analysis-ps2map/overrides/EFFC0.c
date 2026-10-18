/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request8(WORK* wk);
extern const s16 plhos_data[20][3];
extern void (*const D_0024D368[17])();

void xb_effect_C0_draw(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 1:
        ewk->wu.position_x = mwk->wu.position_x;
        ewk->wu.position_y = mwk->wu.position_y + plhos_data[mwk->player_number][1];
        ewk->wu.position_z = mwk->wu.position_z - 4;
        sort_push_request8(&ewk->wu);
        break;
    }
}
