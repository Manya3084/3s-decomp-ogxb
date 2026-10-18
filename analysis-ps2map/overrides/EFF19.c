/* The Xbox returns where the PS2 breaks out of the switch. */
void eff19_quake_sub(WORK_Other* ewk) {
    s16 work;
    s8 fall_go;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (bg_w.quake_y_index <= 2) {
            break;
        }

        work = random_16();

        if (bg_w.quake_y_index < 8) {
            fall_go = effect_19_s_tbl[work];
        } else if (bg_w.quake_y_index > 14) {
            fall_go = effect_19_l_tbl[work];
        } else {
            fall_go = effect_19_m_tbl[work];
        }

        if (fall_go) {
            ewk->wu.routine_no[1]++;
            ewk->wu.routine_no[2] = 0;
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[1].sp = -0x6000;
            ewk->wu.old_rno[0] = eff19_wait_tbl[work];
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.routine_no[2] = 1;
        ewk->wu.old_rno[0] = 60;
        break;

    case 1:
        if (ewk->wu.routine_no[2]) {
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] >= 0) {
                break;
            }

            ewk->wu.routine_no[1] = 0;
            set_char_move_init(&ewk->wu, 0, 6);
            return;
        }

        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] < 0) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < 66) {
            ewk->wu.routine_no[1]++;
            break;
        }

        break;

    case 3:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            break;
        }

        break;

    case 4:
        if (!range_x_check(ewk)) {
            ewk->wu.routine_no[1] = 0;
            ewk->wu.disp_flag = 1;
            ewk->wu.xyz[1].disp.pos = eff19_data_tbl[(ewk->wu.type * 2) + 1];
            set_char_move_init(&ewk->wu, 0, 6);
        }

        break;
    }
}
