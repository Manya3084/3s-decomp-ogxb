/* The Xbox has no Debug_w test. */
void effect_A5_move(WORK_Other* ewk) {
    if (Present_Mode == 4 || Present_Mode == 5) {
        return;
    }

    if (Break_Into) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Time_Stop == 0) {
            ewk->wu.routine_no[0]++;
        }

        break;

    case 1:
        if (!Check_Sleep_A5(ewk)) {
            break;
        }

        if (--Unit_Of_Timer) {
            break;
        }

        Unit_Of_Timer = 50;
        bcdext = 0;

        if ((Select_Timer = sbcd(1, Select_Timer)) == 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 30;
        }

        break;

    case 2:
        if (!Check_Sleep_A5(ewk)) {
            break;
        }

        if (Select_Timer) {
            ewk->wu.routine_no[0] = 1;
            Unit_Of_Timer = 50;
        } else if (--ewk->wu.dir_timer == 0) {
            Time_Over = 1;
            ewk->wu.routine_no[0]++;
        }

        break;

    case 3:
        if (!Check_Sleep_A5(ewk)) {
            break;
        }

        Time_Over = 1;

        if (Select_Timer) {
            ewk->wu.routine_no[0] = 1;
            Unit_Of_Timer = 50;
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
