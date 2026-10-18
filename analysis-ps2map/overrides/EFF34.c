/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void effect_34_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = -10;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 60;
        cal_initial_speed(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos);
        break;

    case 1:
        if (EXE_flag || Game_pause || bg_w.bgw[1].xy[1].disp.pos >= 104) {
            suzi_sync_pos_set(ewk);
            sort_push_request(&ewk->wu);
            break;
        }

        char_move(&ewk->wu);
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[0]++;
            ewk->wu.cg_type = 0;
            oya_ptr->cmwk[1] = 9;
        }

        break;

    case 2:
        if (EXE_flag || Game_pause) {
            suzi_sync_pos_set(ewk);
            sort_push_request(&ewk->wu);
            break;
        }

        char_move(&ewk->wu);
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0]++;
            ewk->wu.rl_flag = ewk->wu.rl_flag ? 0 : 1;
            set_char_move_init(&ewk->wu, 0, 0);
        }

        break;

    case 3:
        if (EXE_flag || Game_pause) {
            suzi_sync_pos_set(ewk);
            sort_push_request(&ewk->wu);
            break;
        }

        if (ewk->wu.old_rno[0]--) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            suzi_sync_pos_set(ewk);
            sort_push_request(&ewk->wu);
            break;
        }

        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        break;

    case 4:
        ewk->wu.routine_no[0]++;
        break;

    case 5:
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
