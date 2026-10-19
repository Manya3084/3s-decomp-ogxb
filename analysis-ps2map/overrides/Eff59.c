/* Xbox-only: the drawing half of effect_59_move. It does not build to
 * retail's registers yet. */
void xb_effect_59_draw(WORK_Other* ewk) {
    WORK_Other* mwk = (WORK_Other*)ewk->my_master;

    if (mwk->wu.be_flag != 0) {
        ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos;
        ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos - 16;
        EFF59_Trans(ewk);
    }
}
