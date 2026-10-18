/* The Xbox does not call Check_Pos_OBJ2. */
void effect_40_move(WORK_Other* ewk) {
    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (ewk->master_id) {
        ewk->wu.rl_waza = save_w[1].extra_option.contents[Menu_Page_Buff][Menu_Max];
    } else {
        ewk->wu.rl_waza = system_dir[1].contents[Menu_Page_Buff][Menu_Max];
    }

    EFF40_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    sort_push_request4(&ewk->wu);
}
