/* Rewritten to match retail (tools/permute.py): set_char_move_init2 parameter 4: s16 -> s32; set_char_move_init2 parameter 3: s16 -> s32. */
void effect_81_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer) {
            return;
        }

        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.mvxy.a[0].sp = 0xE0000;
        ewk->wu.mvxy.d[0].sp = 0x10000;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos - 416;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].xy[1].disp.pos - 24;
        ewk->wu.hit_quake = bg_w.bgw[1].xy[0].disp.pos - 16;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 39;
        }

        break;

    case 2:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
        }

        break;

    case 3:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 240)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            return;
        }

        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos + base_y_pos + 0xFFFF;
    sort_push_request4(&ewk->wu);
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_81_draw(WORK_Other* ewk) {
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos + base_y_pos - 1;
    sort_push_request4(&ewk->wu);
}
