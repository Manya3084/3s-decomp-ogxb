/* Rewritten to match retail (tools/permute.py): set_char_move_init2 parameter 4: s16 -> s32; set_char_move_init2 parameter 3: s16 -> s32. */
s32 effect_K6_init(s16 PL_id, s16 dir_old, s16 dm_vital, s16 Target_BG) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 206;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x2090;
    ewk->wu.my_family = Target_BG + 1;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->wu.direction = dm_vital;
    ewk->wu.dir_old = dir_old;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    Setup_CharK6(ewk, dm_vital);
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
    return 0;
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init2 parameter 4: s16 -> s32; set_char_move_init2 parameter 3: s16 -> s32. */
void EFFK6_SUDDENLY(WORK_Other* ewk) {
    s16 xx;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        xx = Setup_K6_Index(ewk);
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Get_PosK6(ewk, xx, 0, 1);
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Get_PosK6(ewk, xx, 1, 1);
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    default:
        if (ewk->wu.dir_old == 27 || ewk->wu.dir_old == 28) {
            Order[ewk->wu.dir_old] = 4;
            ewk->wu.routine_no[0] = 4;
            ewk->wu.routine_no[6] = 0;
            break;
        }

        ewk->wu.routine_no[0] = 0;
        Order[ewk->wu.dir_old] = 0;
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init2 parameter 4: s16 -> s32; set_char_move_init2 parameter 3: s16 -> s32. */
void EFFK6_MOVE(WORK_Other* ewk) {
    if (Order[ewk->wu.dir_old] != 4) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[6] = 0;
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Sel_PL_Complete[ewk->master_id] || plw[ewk->master_id].wu.operator == 0) {
            ewk->wu.routine_no[1] = 2;
        } else {
            ewk->wu.routine_no[1]++;
        }

        /* fallthrough */

    case 1:
        if (ewk->wu.dir_step != ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]]) {
            ewk->wu.dir_step = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
            ewk->wu.xyz[0].disp.pos =
                bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Get_PosK6(ewk, ewk->wu.dir_step, 0, Play_Type);
            ewk->wu.xyz[1].disp.pos =
                bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Get_PosK6(ewk, ewk->wu.dir_step, 1, Play_Type);

            if (ewk->wu.direction == 19) {
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, (ewk->wu.dir_step) + 1, 0);
            }
        }

        if (Sel_PL_Complete[ewk->master_id]) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init2 parameter 4: s16 -> s32; set_char_move_init2 parameter 3: s16 -> s32. */
void EFFK6_SLIDE_IN(WORK_Other* ewk) {
    s16 xx;

    if ((Order[ewk->wu.dir_old]) == 5) {
        ewk->wu.routine_no[0] = 5;
        ewk->wu.routine_no[1] = 0;
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old]) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;

        if (ewk->wu.dir_old == 27 || ewk->wu.dir_old == 28) {
            xx = ID_of_Face[Cursor_Y[ewk->master_id]][Cursor_X[ewk->master_id]];
            Setup_1st_PosK6(ewk, xx, Play_Type);
        } else {
            xx = ewk->wu.dir_step;
            Setup_1st_PosK6(ewk, xx, Play_Type);

            if (ewk->wu.direction == 25 && xx != 0) {
                ewk->wu.xyz[0].disp.pos += 8;
                ewk->wu.hit_quake += 8;

                if (ewk->wu.mvxy.a[0].sp > 0) {
                    ewk->wu.xyz[0].disp.pos += 8;
                    ewk->wu.hit_quake += 8;
                }
            }
        }

        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                    Order[ewk->wu.dir_old] = 0;
                }

                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;

                if (ewk->wu.dir_old < 31) {
                    Order[ewk->wu.dir_old] = 4;
                    ewk->wu.routine_no[0] = 4;
                    ewk->wu.routine_no[6] = 0;
                    break;
                }

                ewk->wu.routine_no[0] = 0;
            }

            break;
        }

        if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                Order[ewk->wu.dir_old] = 0;
            }

            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;

            if (ewk->wu.dir_old < 31) {
                Order[ewk->wu.dir_old] = 4;
                ewk->wu.routine_no[0] = 4;
                ewk->wu.routine_no[6] = 0;
                break;
            }

            ewk->wu.routine_no[0] = 0;
        }

        break;
    }
}

/* The Xbox does not call Check_Pos_OBJ. */
void effect_K6_move(WORK_Other* ewk) {
    EFFK6_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}
