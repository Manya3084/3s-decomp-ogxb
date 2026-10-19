/* Xbox-only: the drawing half of effect_15_move, called through the
 * effect draw table. It does not build to retail's registers yet. */
void xb_effect_15_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
    case 2:
        sort_push_request(&ewk->wu);
        break;
    }
}
