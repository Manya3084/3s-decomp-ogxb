/* The check_work_position result is on the left of the comparison. */
void Normal_54000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 12);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[2] = 18;
            wk->wu.routine_no[3] = 0;

            if (check_work_position(&wk->wu, (WORK*)wk->wu.target_adrs) != wk->wu.rl_flag) {
                wk->wu.routine_no[2] = 20;
            }
        }

        break;
    }
}
