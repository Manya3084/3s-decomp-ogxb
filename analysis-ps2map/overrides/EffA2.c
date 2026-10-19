/* Data read off the retail code: hnc_pointer is 0xC80630, hnc_timer is 0xC80634. */


/* Xbox-only: the drawing half of effect_A2_move, called through the effect
   draw table by xb_draw_effect_work. */
void xb_effect_A2_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        hnc_set(ewk->wu.direction, 20);
        break;

    case 2:
        hnc_set(ewk->wu.direction, hnc_col);
        break;

    case 3:
        hnc_set(ewk->wu.direction, hnc_col);
        break;
    }
}
