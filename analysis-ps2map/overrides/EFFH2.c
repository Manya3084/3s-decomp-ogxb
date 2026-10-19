/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request(WORK* wk);
extern const s16 panel_guide[8][2];
void Att_DUMMY();
/* D_0024D368 is 0x24D368. */
void (*const D_0024D368[17])() = {
    Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY,
    Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY, Att_DUMMY,
    Att_DUMMY,
};

void xb_effect_H2_draw(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.dead_f != 1) {
            ewk->wu.position_x = mwk->position_x + panel_guide[ewk->wu.dir_step][0];
            ewk->wu.position_y = mwk->position_y + panel_guide[ewk->wu.dir_step][1] + 17;
            sort_push_request(&ewk->wu);
        }

        break;
    }
}
