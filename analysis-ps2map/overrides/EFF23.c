/* Xbox-only: sets the 2D scale and origin for a button image
   (njScale(NULL, 1.6667, -2.0, 1.0) and a reset translation). */
void sub_000305CA(void);

/* Xbox: the button image is set up by sub_000305CA and drawn smaller, at
   (-42, 11) size 20x16 (PS2 (-44, 12) size 23x19). */
void effect_23_move(WORK_Other_CONN* ewk) {
    if (Check_Die_61((WORK_Other*)ewk)) {
        push_effect_work(&ewk->wu);
        return;
    }

    EFF23_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;

    if (ewk->wu.dir_old == 91 || ewk->wu.dir_old == 103) {
        ewk->wu.my_clear_level = 0;
        sort_push_request3(&ewk->wu);
        return;
    }

    if (Menu_Cursor_Y[ewk->master_id] == ewk->wu.type) {
        ewk->wu.my_clear_level = 0;
    } else {
        ewk->wu.my_clear_level = 128;
    }

    sort_push_request3(&ewk->wu);

    if (ewk->wu.char_index != 2 && ewk->wu.char_index != 3) {
        return;
    }

    if (ewk->wu.type < 8 && ewk->wu.disp_flag) {
        sub_000305CA();
        dispButtonImage(-42, 11, ewk->wu.position_z, 20, 16, ewk->wu.my_clear_level, ewk->wu.type);
    }
}
