/* Xbox: no effect_00_init after the first tama_display (EFF00 is not in
   the Xbox build). */
void effect_13_move(WORK_Other* ewk) {
    TAMA* tama = (TAMA*)ewk->wu.my_effadrs;
    PLW* mwk;
    PLW* emwk;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.my_mts = 14;
        ewk->wu.charset_id = 11;
        set_char_base_data(&ewk->wu);
        ewk->wu.hf.hit_flag = 0;
        ewk->wu.work_id = tama->my_wkid;
        ewk->wu.dir_timer = tama->life_time;
        ewk->wu.disp_flag = tama->disp_type;
        ewk->wu.blink_timing = ewk->master_id;
        ewk->wu.at_koa = tama->koa;
        ewk->wu.vital_new = tama->def_power;
        ewk->wu.dm_vital = 0;
        ewk->wu.original_vitality = tama->waza_num;
        ewk->wu.shell_vs_refrect = tama->vs_refrect;
        ewk->wu.charset_id = tama->kind_of_tama;

        if (ewk->master_id) {
            if (tama->col_2p == 0) {
                ewk->wu.my_col_code = ewk->wu.old_rno[7];
            } else {
                ewk->wu.my_col_code = tcct[tama->col_2p];
            }
        } else if (tama->col_1p == 0) {
            ewk->wu.my_col_code = ewk->wu.old_rno[7];
        } else {
            ewk->wu.my_col_code = tcct[tama->col_1p];
        }

        if (tama->kage_index) {
            ewk->wu.kage_flag = 1;
            ewk->wu.kage_hx = kage_tbl[tama->kage_index][0];
            ewk->wu.kage_hy = kage_tbl[tama->kage_index][1];
            ewk->wu.kage_prio = kage_tbl[tama->kage_index][2];
            ewk->wu.kage_char = kage_tbl[tama->kage_index][3];
        } else {
            ewk->wu.kage_flag = 0;
        }

        if (tama->kind_of_tama == 2) {
            set_tengu_init_pos(&ewk->wu, (WORK*)ewk->my_master);
            ewk->wu.disp_flag = 0;
            ewk->wu.dir_old = ((PLW*)ewk->my_master)->sa->id_arts;
            set_char_move_init2(&ewk->wu, 0, tama->chix, random_16() & 7, 0);
        } else if (tama->kind_of_tama == 0xF) {
            mwk = (PLW*)ewk->my_master;

            if (tama->data01) {
                ewk->wu.mvxy.a[0].sp = mwk->wu.mvxy.a[0].sp;
                ewk->wu.mvxy.a[1].sp = mwk->wu.mvxy.a[1].sp ? mwk->wu.mvxy.a[1].sp : -0x80000;
                ewk->wu.mvxy.d[0].sp = mwk->wu.mvxy.d[0].sp;
                ewk->wu.mvxy.d[1].sp = mwk->wu.mvxy.d[1].sp;
                ewk->wu.mvxy.kop[1] = 0;
            } else {
                emwk = (PLW*)mwk->wu.target_adrs;
                ewk->wu.xyz[0].disp.pos = tama->hos_x;
                ewk->wu.xyz[0].disp.pos += emwk->wu.xyz[0].disp.pos;
                ewk->wu.xyz[0].disp.pos += X_F_L_A_T_pos_hos[0][emwk->player_number][0];
                ewk->wu.xyz[1].disp.pos = tama->hos_y;
                ewk->wu.xyz[1].disp.pos += emwk->wu.xyz[1].disp.pos;
                ewk->wu.xyz[1].disp.pos += X_F_L_A_T_pos_hos[0][emwk->player_number][1];
                ewk->wu.rl_flag = ewk->wu.xyz[0].disp.pos > emwk->wu.xyz[0].disp.pos ? 0 : 1;
                setup_mvxy_data(&ewk->wu, tama->data00);
            }

            set_char_move_init(&ewk->wu, 0, tama->chix);
        } else {
            if (ewk->wu.rl_flag) {
                ewk->wu.xyz[0].disp.pos -= tama->hos_x;
            } else {
                ewk->wu.xyz[0].disp.pos += tama->hos_x;
            }

            ewk->wu.xyz[1].disp.pos += tama->hos_y;
            ewk->wu.position_z = ewk->wu.my_priority;

            if (tama->kind_of_tama == 7) {
                ewk->wu.position_z += 2;
            }

            setup_mvxy_data(&ewk->wu, tama->data00);
            set_char_move_init(&ewk->wu, 0, tama->chix);
        }

        if (tama->kind_of_tama == 11) {
            ewk->wu.next_z = 71;
            ewk->wu.my_mr_flag = 1;
            ewk->wu.my_mr.size.x = 127;
            ewk->wu.my_mr.size.y = 127;
        }

        if (tama->kind_of_tama == 10) {
            ewk->wu.rl_flag = ((WORK*)ewk->my_master)->rl_waza;
        }

        tama_display(&ewk->wu);
        break;

    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[6] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        if (ewk->wu.hit_stop < 0) {
            ewk->wu.hit_stop = -ewk->wu.hit_stop;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            kind_of_tama_process[tama->kind_of_tama](ewk, tama);
        }

        tama_display(&ewk->wu);

        if (ewk->wu.floor) {
            ewk->wu.kind_of_waza |= 0x20;
            ewk->wu.at_koa = 0x80;
        }

        hit_push_request(&ewk->wu);
        break;

    case 2:
        erase_my_shell_ix((WORK*)ewk->my_master, ewk->wu.myself);
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}
