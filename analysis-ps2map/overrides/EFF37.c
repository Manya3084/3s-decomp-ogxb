/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request(WORK* wk);
extern const s16 panel_pos_hosei[][4][2];

void xb_effect_37_draw(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;
    s16 ix;

    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.dead_f == 1) {
            break;
        }

        if (mwk->cg_type) {
            ewk->wu.disp_flag = 1;

            if (mwk->cg_type == 0xFF) {
                ix = 3;
            } else {
                ix = mwk->cg_type - 1;
            }

            if (ewk->wu.rl_waza) {
                ewk->wu.position_x = mwk->position_x - panel_pos_hosei[ewk->wu.charset_id][ix][0];
            } else {
                ewk->wu.position_x = mwk->position_x + panel_pos_hosei[ewk->wu.charset_id][ix][0];
            }

            ewk->wu.position_y = mwk->position_y + panel_pos_hosei[ewk->wu.charset_id][ix][1];
        } else {
            ewk->wu.disp_flag = 0;
        }

        sort_push_request(&ewk->wu);
        break;
    }
}
