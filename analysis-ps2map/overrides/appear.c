/* Rewritten to match retail (tools/permute.py): < 1 -> <= 0. */
void Appear_28000(PLW* wk) {
    s16 id_w = wk->wu.id ^ 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        Appear_car_stop[id_w] = 0;
        set_char_move_init(&wk->wu, 9, 17);
        bg_app_stop = 1;
        break;

    case 1:
        if (Appear_car_stop[id_w]) {
            wk->wu.routine_no[3]++;
            set_char_move_init2(&wk->wu, 9, 17, 2, 0);
        }

        break;

    case 2:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 9) {
            wk->wu.routine_no[3]++;
        }

        break;

    case 3:
        if (plw[id_w].wu.routine_no[3] >= 3) {
            wk->wu.routine_no[3]++;
            appear_work[wk->wu.id] = 20;
        }

        break;

    case 4:
        appear_work[wk->wu.id]--;

        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init2(&wk->wu, 9, 17, 15, 0);
        }

        break;

    case 5:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
            Appear_end++;
        }

        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 1 -> <= 0. */
void Appear_37000(PLW* wk) {
    s16 id_w = wk->wu.id ^ 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x11);
        bg_app_stop = 1;
        wk->wu.cmwk[0] = 0;
        effect_M1_init(&wk->wu);
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
            wk->wu.cmwk[0] = 1;
        }
        break;

    case 2:
        char_move(&wk->wu);

        if (wk->wu.cmwk[0] == 2) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x12);
        }

        break;

    case 3:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x13);
        }

        break;

    case 4:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 9) {
            wk->wu.routine_no[3]++;
            wk->wu.cmwk[0] = 3;
            wk->wu.next_z = plw[id_w].wu.my_priority;
        }

        break;

    case 5:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 0, 3);
            app_counter[wk->wu.id] = 0x2a;

            if (wk->wu.id) {
                cal_all_speed_data(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0, 0, 0);
            } else {
                cal_all_speed_data(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0, 0, 0);
            }

            wk->wu.next_z = wk->wu.my_priority;
        } else {
            wk->wu.next_z = plw[id_w].wu.my_priority;
        }

        break;

    case 6:
        char_move(&wk->wu);
        app_counter[wk->wu.id]--;

        if (app_counter[wk->wu.id] <= 0) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
            Appear_end++;
        } else {
            sub_000EF072((WORK_Other*)&wk->wu);
        }

        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 1 -> <= 0; < 1 -> <= 0; < 1 -> <= 0; < 0x41 -> <= 0x40. */
void Appear_26000(PLW* wk) {
    // s32 effect_86_init(s16 type86);

    switch (wk->wu.routine_no[3]) {
    case 0:
        bg_app_stop = 1;
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x10);
        appear_work[wk->wu.id] = 0x14;
        Appear_free[wk->wu.id] = 0;
        break;

    case 1:
        appear_work[wk->wu.id]--;

        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            appear_work[wk->wu.id] = 0x14;

            if (wk->wu.id) {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 88, 0, 0, 1);
            } else {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 88, 0, 0, 1);
            }
        }

        break;

    case 2:
        char_move(&wk->wu);
        appear_work[wk->wu.id]--;
        sub_000EF072((WORK_Other*)wk);
        sub_000EF088((WORK_Other*)wk);

        if (wk->wu.xyz[1].disp.pos <= 0x40) {
            wk->wu.routine_no[3]++;
            wk->wu.hit_quake = 0x18;

            if (wk->wu.id == 0) {
                effect_86_init(0);
            }
            sub_00098407(0x109);
        }

        break;

    case 3:
        char_move(&wk->wu);

        if (wk->wu.hit_quake <= 0) {
            wk->wu.routine_no[3]++;
            Appear_free[wk->wu.id] = 1;
        }

        break;

    case 4:
        char_move(&wk->wu);
        appear_work[wk->wu.id]--;

        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init2(&wk->wu, 9, 0x10, 3, 0);
            wk->wu.xyz[1].cal = 0;
        } else {
            sub_000EF072((WORK_Other*)wk);
            sub_000EF088((WORK_Other*)wk);
        }

        break;

    case 5:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 9) {
            wk->wu.rl_flag ^= 1;
            wk->wu.routine_no[3]++;
        }

        break;

    case 6:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
            Appear_end++;
        }

        break;
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void Appear_03000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, wk->wu.char_index);
        bg_app_stop = 1;
        return;

    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
            Appear_end++;
        }
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void Appear_32000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        wk->wu.disp_flag = 1;
        work = random_16();
        work &= 7;
        set_char_move_init(&wk->wu, 9, work + 8);
        bg_app_stop = 1;
        break;

    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
            Appear_end += 1;
        }
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void Appear_34000(PLW* wk) {
    s16 work;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        wk->wu.disp_flag = 1;

        work = random_16();
        work &= 7;
        set_char_move_init(&wk->wu, 9, work);

        switch (work) {
        case 0:
        case 2:
        case 6:
        case 7:
            if (wk->wu.id) {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 0x71;
            } else {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - 0x71;
            }
        }
        bg_app_stop = 1;
        break;

    default:
        Appear_01000(wk);
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void Appear_21000(PLW* wk) {
    s16 work;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        wk->wu.disp_flag = 1;
        work = random_16();
        work &= 7;
        if (work == 6 || work == 7) {
            appear_data_set(wk, (APPEAR_DATA*)appear_data + 24);
            set_char_move_init(&wk->wu, 9, 0xE);
        } else {
            set_char_move_init(&wk->wu, 9, work + 8);
        }
        bg_app_stop = 1;
        break;

    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
            Appear_end += 1;
        }
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void Appear_23000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        wk->wu.disp_flag = 1;
        work = random_16();
        work &= 3;
        wk->wu.cmwk[1] = 0;
        set_char_move_init(&wk->wu, 9, work + 4);
        bg_app_stop = 1;
        break;

    case 1:
        char_move(&wk->wu);
        if ((wk->wu.cmwk[1]) && wk->wu.cg_type == 9) {
            wk->wu.routine_no[3] += 1;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 8);
            return;
        } else {
            break;
        }
    case 2:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
            Appear_end += 1;
        }
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init2 parameter 4: s16 -> s32. */
void Appear_14000(PLW* wk) {
    s16 work;
    s16 id_w = wk->wu.id ^ 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] += 1;
        wk->wu.disp_flag = 1;
        wk->gill_ccch_go = 1;

        if (sean_appear_check(wk, id_w)) {
            set_char_move_init(&wk->wu, 9, 0x3C);
            return;
        }

        wk->wu.routine_no[2] = 1;
        wk->wu.routine_no[3] = 0;
        Appear_end++;
        break;

    case 1:
        switch (Appear_free[id_w]) {
        case 0:
            char_move(&wk->wu);
            break;

        case 1:
            work = wk->wu.cg_ix / wk->wu.cgd_type;
            set_char_move_init2(&wk->wu, 0, 0, work + 1, 0);
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 1;
            Appear_end += 1;
            break;

        case 2:
            char_move(&wk->wu);
            if (wk->wu.cg_type == 0xFF) {
                wk->wu.routine_no[2] = 1;
                wk->wu.routine_no[3] = 0;
                Appear_end += 1;
            }
        }
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void Appear_01000(PLW* wk) {
    s16 work;
    s16 id_w;

    id_w = wk->wu.id ^ 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        bg_app_stop = 1;
        work = random_16();

        switch (wk->wu.routine_no[4]) {
        case 1:
            work &= 3;
            set_char_move_init(&wk->wu, 9, work);
            break;

        case 2:
            work &= 3;
            set_char_move_init(&wk->wu, 9, work + 4);
            break;

        case 35:
            work &= 7;
            set_char_move_init(&wk->wu, 9, work);
            break;
        }
        break;

    case 1:
        if (Appear_flag[wk->wu.id]) {
            wk->wu.routine_no[3]++;
            char_move(&wk->wu);
            return;
        }
        wk->wu.routine_no[3] = 3;
        set_char_move_init(&wk->wu, 9, wk->wu.char_index + 8);
        break;

    case 2:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9 && Appear_flag[wk->wu.id] == 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 8);
        }
        break;

    case 3:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
            Appear_end++;
        }
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32. */
void Appear_18000(PLW* wk) {
    s16 work;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;

        if (plw[0].player_number == 8 && plw[1].player_number == 8) {
            Appear_free[wk->wu.id] = 0;

            if (wk->wu.id) {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - 0x3B;
            } else {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 0x3B;
            }

            set_char_move_init(&wk->wu, 9, 0x10);
            goto one;
        }

        Appear_free[wk->wu.id] = 1;
        work = random_16();
        work &= 3;
        set_char_move_init(&wk->wu, 9, work + 8);

        wk->wu.mvxy.a[0].sp = 0;
        wk->wu.mvxy.a[1].sp = 0x80000;

        appear_work[wk->wu.id] = 0x1F;

        if (wk->wu.id) {
            cal_delta_speed(&wk->wu, appear_work[wk->wu.id], (bg_w.bgw[1].pos_x_work + 0x58), 0, 0, 1);
            goto one;
        }
        cal_delta_speed(&wk->wu, appear_work[wk->wu.id], (bg_w.bgw[1].pos_x_work - 0x58), 0, 0, 1);

    one:
        bg_app_stop = 1;
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 9) {
            if (!Appear_free[wk->wu.id]) {
                wk->wu.mvxy.a[0].sp = 0;
                wk->wu.mvxy.a[1].sp = 0x80000;

                appear_work[wk->wu.id] = 0x1F;

                if (wk->wu.id) {
                    cal_delta_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0, 0, 1);
                } else {
                    cal_delta_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0, 0, 1);
                }
            }

            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
        }
        break;

    case 2:
        char_move(&wk->wu);

        appear_work[wk->wu.id]--;

        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            wk->wu.xyz[1].cal = 0;
            return;
        }

        sub_000EF072((WORK_Other*)&wk->wu);
        sub_000EF088((WORK_Other*)&wk->wu);
        return;

    case 3:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = 1;
            wk->wu.routine_no[3] = 0;
            Appear_end++;
        }

        break;
    }
    return;
}
