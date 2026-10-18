/* Xbox-only: the drawing half of effect_C9_move, called through the effect
   draw table by xb_draw_effect_work. Case 0 repeats the set-up of the move
   function without advancing it. */
void xb_effect_C9_draw(WORK_Other* ewk) {
    s16 scrc;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        scrc = get_center_position();
        ewk->wu.xyz[0].disp.pos = app_pos_hosei[ewk->wu.type][0] + scrc;
        ewk->wu.xyz[1].disp.pos = app_pos_hosei[ewk->wu.type][1];
        ewk->wu.xyz[2].disp.pos = app_pos_hosei[ewk->wu.type][2] + 32;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = judge_gals_kage_tbl[ewk->wu.charset_id][0];
        ewk->wu.kage_hy = judge_gals_kage_tbl[ewk->wu.charset_id][1];
        ewk->wu.kage_prio = judge_gals_kage_tbl[ewk->wu.charset_id][2];
        ewk->wu.kage_char = judge_gals_kage_tbl[ewk->wu.charset_id][3];

        if (ewk->wu.type == 1) {
            ewk->wu.kage_hy -= 2;
        }

        set_char_move_init(&ewk->wu, 0, 0);

        if (ewk->wu.charset_id == 7) {
            ewk->wu.next_x = efy_data[0];
            ewk->wu.xyz[0].disp.pos += efy_data[1];
            ewk->wu.next_y = ewk->wu.xyz[1].disp.pos;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
        sort_push_request(&ewk->wu);
        break;

    case 1:
        if ((ewk->wu.dead_f == 1) || (Suicide[0] != 0)) {
            break;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;
    }
}
