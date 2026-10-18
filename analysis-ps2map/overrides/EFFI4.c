/* The Xbox returns where the PS2 breaks out of the switch. */
void effect_i4_hit_sub(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (eff_hit_check2(ewk, 0, 2)) {
            set_char_move_init(&ewk->wu, 0, 25);
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 1;
            ewk->wu.routine_no[3] = 0;
            break;
        }

        if (eff_hit_check2(ewk, 0, 0)) {
            set_char_move_init(&ewk->wu, 0, 24);
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
            ewk->wu.routine_no[3] = 0;
        }

        break;

    case 1:
        if (ewk->wu.routine_no[2]) {
            effi4_up_to_down(ewk);
            return;
        }

        effi4_down_to_up(ewk);
        break;
    }
}
