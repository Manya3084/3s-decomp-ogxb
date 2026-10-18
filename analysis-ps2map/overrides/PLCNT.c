/* Notes from the hand port this file replaced:
 * set_kizetsu_status is 0x85BF2 size 0x7B, interior after the ret.
 * clear_kizetsu_point is 0x85C6D size 0x43, interior after the ret.
 * check_damage_hosei_nage is 0x858FA size 0x9B.
 * check_damage_hosei_dageki is 0x85995 size 0x30.
 * set_scrrrl is 0x85EF2 size 0x1E.
 * check_damage_hosei is 0x8637C size 0xA0.
 * These four are the PS2 C. scrr is the word at 0x7A88F8 and scrl the word at
 * 0x7A81D0. hosei_amari is PLW + 0x3AA, dm_hos_flag + 0x3AC, and
 * muriyari_ugoku + 0x3AE.
 * piyori_type is 0xC7D9A0, stride 0x14. flag is +0, genkai is +2,
 * time is +4, now.timer is +8, recover is +0xC, and store is +0x10.
 * My_char is 0x7A8114. omop_stun_gauge_len is 0x7C5C48.
 * stun_gauge_len_omake is 0x268480 and matches the 5 PlayStation 2
 * words. pl_piyo_tbl is 0x262420 and matches the 20 words.
 * pl_nr_piyo_tbl is 0x262448 and matches the 20 dwords.
 * player_number is PLW + 0x394. py is PLW + 0x3CC.
 */

/* The hand port's bodies (they matched as written): set_kizetsu_status,
 * clear_kizetsu_point, set_scrrrl, check_damage_hosei_nage,
 * check_damage_hosei_dageki, check_damage_hosei. */
void set_kizetsu_status(s16 ix) {
    s16 plnum = My_char[ix];

    piyori_type[ix].flag = 0;
    piyori_type[ix].time = 0;
    piyori_type[ix].now.timer = 0;
    piyori_type[ix].store = 0;
    piyori_type[ix].recover = pl_nr_piyo_tbl[plnum];
    piyori_type[ix].genkai = pl_piyo_tbl[plnum] + stun_gauge_len_omake[omop_stun_gauge_len[ix]];

    if (piyori_type[ix].genkai < 56) {
        piyori_type[ix].genkai = 56;
    }

    if (piyori_type[ix].genkai > 72) {
        piyori_type[ix].genkai = 72;
    }
}

void clear_kizetsu_point(PLW *wk) {
    wk->py->flag = 0;
    wk->py->time = 0;
    wk->py->now.timer = 0;
    wk->py->store = 0;
    wk->py->recover = pl_nr_piyo_tbl[wk->player_number];
}

void set_scrrrl() {
    s16 scrc = get_center_position();

    scrr = scrc + 192;
    scrl = scrc - 192;
}

void check_damage_hosei_nage(PLW* as, PLW* ds) {
    if (as->kind_of_catch) {
        if (ds->hosei_amari != 0) {
            as->wu.xyz[0].disp.pos += ds->hosei_amari;
            as->muriyari_ugoku += ds->hosei_amari;
            return;
        }

        if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(as, scrr, 1) != 0) {
            set_field_hosei_flag(as, scrl, 0);
        }

        if (as->hosei_amari != 0) {
            ds->wu.xyz[0].disp.pos += as->hosei_amari;
            ds->muriyari_ugoku += as->hosei_amari;
        }
    } else if (ds->hosei_amari != 0) {
        as->wu.xyz[0].disp.pos += ds->hosei_amari;
        as->muriyari_ugoku += ds->hosei_amari;
    }
}

void check_damage_hosei_dageki(PLW* w1, PLW* w2) {
    if ((w1->dm_hos_flag != 0) && (w2->wu.hit_stop == 0)) {
        w2->wu.xyz[0].disp.pos += w1->hosei_amari;
        w2->muriyari_ugoku += w1->hosei_amari;
    }
}

void check_damage_hosei() {
    plw[0].muriyari_ugoku = plw[0].hosei_amari;
    plw[1].muriyari_ugoku = plw[1].hosei_amari;

    if (plw[0].tsukami_f && plw[1].tsukamare_f) {
        check_damage_hosei_nage(&plw[0], &plw[1]);
    } else if (plw[1].tsukami_f && plw[0].tsukamare_f) {
        check_damage_hosei_nage(&plw[1], &plw[0]);
    } else {
        switch ((plw[0].hosei_amari != 0) + ((plw[1].hosei_amari != 0) * 2)) {
        case 1:
            check_damage_hosei_dageki(&plw[0], &plw[1]);
            break;
        case 2:
            check_damage_hosei_dageki(&plw[1], &plw[0]);
            break;
        }
    }

    plw[0].hosei_amari = plw[1].hosei_amari = 0;
}

/* Xbox: no Debug_w[15] test */
void reqPlayerDraw() {
    move_effect_work(6);
    sort_push_request(&plw[0].wu);
    sort_push_request(&plw[1].wu);
}

/* Xbox: written num < 1 */
s16 remake_sa_store_max(s16 ix, s16 store_max) {
    s16 num = store_max + sag_stock_omake[omop_sag_max_ix[ix]];

    if (num < 1) {
        num = 1;
    }

    if (num > 9) {
        num = 9;
    }

    return num;
}

/* The Xbox does not call effect_00_init. */
void setup_other_data(PLW* wk) {
    s16 i;

    if (wk->player_number == 0) {
        (Introduce_Boss[wk->wu.id][1] & 0x80) == 0;
        setup_GILL_exsa_obj();
    }

    for (i = 0; i < 4; i++) {
        effect_01_init(&wk->wu, i);
    }

    effect_K5_init(wk);
}

/* The Xbox does not call sub_0004384A. */
void init_app_10000() {
    switch (pcon_rno[1]) {
    case 0:
        pli_0000();
        pcon_rno[1] = 2;
        pcon_dp_flag = 0;
        round_slow_flag = 0;
        dead_voice_flag = 0;
        another_bg[0] = another_bg[1] = 0;
        plw[0].scr_pos_set_flag = plw[1].scr_pos_set_flag = 1;

        if (Play_Type == 0) {
            if (plw[0].wu.operator) {
                mpp_w.useChar[My_char[0]]++;
            }

            if (plw[1].wu.operator) {
                mpp_w.useChar[My_char[1]]++;
                return;
            }
        }

        break;

    case 1:
        pli_1000();
        break;

    case 2:
        pcon_rno[1] = 3;

        if (plw[0].wu.operator) {
            paring_ctr_vs[0][0] = paring_ctr_ori[0];
        } else {
            paring_ctr_vs[0][0] = 0;
        }

        if (plw[1].wu.operator) {
            paring_ctr_vs[0][1] = paring_ctr_ori[1];
            return;
        }

        paring_ctr_vs[0][1] = 0;
        break;

    case 3:
        pcon_rno[1] = 1;
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): grade_set_round_result parameter 1: s16 -> s32. */
void settle_type_30000() {
    switch (pcon_rno[2]) {
    case 0:
        break;

    case 1:
        if ((Event_Judge_Gals == -1) && Complete_Judgement) {
            plw[Winner_id].wu.routine_no[2] = 40;
            plw[Loser_id].wu.routine_no[2] = 41;
            plw[0].wu.routine_no[3] = plw[1].wu.routine_no[3] = 0;
            plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
            grade_set_round_result(Winner_id + 0);
            complete_victory_pause();
            pcon_rno[2]++;
        }

        break;

    case 2:
        if ((plw[0].wu.routine_no[3] == 9) && (plw[1].wu.routine_no[3] == 9)) {
            pcon_rno[2]++;
        }

        break;
    }
}

/* Rewritten to match retail (tools/permute.py): sub_00087F1C parameter 2: u16 -> s32. */
void move_P1_move_P2() {
    if (plw[0].do_not_move == 0) {
        sub_00087F1C(&plw[0], processed_lvbt(Convert_User_Setting(0)));
    }

    if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(&plw[0], scrr, 1) != 0) {
        set_field_hosei_flag(&plw[0], scrl, 0);
    }

    if (plw[1].do_not_move == 0) {
        sub_00087F1C(&plw[1], processed_lvbt(Convert_User_Setting(1)));
    }

    if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(&plw[1], scrr, 1) != 0) {
        set_field_hosei_flag(&plw[1], scrl, 0);
    }
}

/* Rewritten to match retail (tools/permute.py): remake_sa_gauge_len parameter 1: s16 -> s32; remake_sa_gauge_len parameter 2: s16 -> s32; remake_sa_store_max parameter 2: s16 -> s32; remake_sa_store_max parameter 1: s16 -> s32. */
void set_super_arts_status(s16 ix) {
    const SA_DATA* saptr;

    if (cmd_sel[ix] || no_sa[ix]) {
        saptr = &super_arts_DATA[My_char[ix]][Super_Arts[ix]];
    } else {
        saptr = &super_arts_data[My_char[ix]][Super_Arts[ix]];
    }

    super_arts[ix].kind_of_arts = Super_Arts[ix];
    super_arts[ix].nmsa_g_ix = saptr->nmsa_g_ix;
    super_arts[ix].exsa_g_ix = saptr->exsa_g_ix;
    super_arts[ix].exs2_g_ix = saptr->exs2_g_ix;
    super_arts[ix].nmsa_a_ix = saptr->nmsa_a_ix;
    super_arts[ix].exsa_a_ix = saptr->exsa_a_ix;
    super_arts[ix].exs2_a_ix = saptr->exs2_a_ix;
    super_arts[ix].ex4th_full = saptr->ex4th_full;
    super_arts[ix].gauge_type = saptr->gauge_type;
    super_arts[ix].gt2 = saptr->gauge_type;
    super_arts[ix].gauge_len = remake_sa_gauge_len(ix, saptr->gauge_len);
    super_arts[ix].store_max = remake_sa_store_max(ix, saptr->store_max);
    super_arts[ix].dtm = saptr->dtm;
    super_arts[ix].dtm_mul = 1;
    super_arts[ix].store = 0;
    super_arts[ix].gauge.s.h = 0;
    super_arts[ix].gauge.s.l = -1;
    super_arts[ix].sa_rno = 0;
    super_arts[ix].ok = 0;
}

/* Rewritten to match retail (tools/permute.py): Convert_User_Setting parameter 1: s16 -> u16. */
void move_P2_move_P1() {
    if (plw[1].do_not_move == 0) {
        sub_00087F1C(&plw[1], processed_lvbt(Convert_User_Setting(1)));
    }

    if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(&plw[1], scrr, 1) != 0) {
        set_field_hosei_flag(&plw[1], scrl, 0);
    }

    if (plw[0].do_not_move == 0) {
        sub_00087F1C(&plw[0], processed_lvbt(Convert_User_Setting(0)));
    }

    if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(&plw[0], scrr, 1) != 0) {
        set_field_hosei_flag(&plw[0], scrl, 0);
    }
}

/* The Xbox has no Debug_w tests. */
void plcnt_move() {
    if (time_over_check() != 0) {
        return;
    }

    if (No_Death) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }

    if (Break_Into) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }

    if (Mode_Type == 3 && Training->contents[0][1][3] == 0) {
        plw[0].wu.dm_nodeathattack = 1;
        plw[1].wu.dm_nodeathattack = 1;
    }

    move_player_work();

    if (aiuchi_flag) {
        subtract_dm_vital_aiuchi(&plw[0]);
        subtract_dm_vital_aiuchi(&plw[1]);

        if ((plw[0].dead_flag != 0) && (plw[1].dead_flag != 0)) {
            plw[0].wu.hit_stop = plw[1].wu.hit_stop = 2;
            plw[0].wu.dm_stop = plw[1].wu.dm_stop = 0;
            plw[0].wu.hit_quake = plw[1].wu.hit_quake = 4;
            plw[0].wu.dm_quake = plw[1].wu.dm_quake = 0;
        } else if ((plw[0].dead_flag != 0) || (plw[1].dead_flag != 0)) {
            plw[0].wu.hit_stop = plw[1].wu.hit_stop = 4;
            plw[0].wu.dm_stop = plw[1].wu.dm_stop = 0;
            plw[0].wu.hit_quake = plw[1].wu.hit_quake = 8;
            plw[0].wu.dm_quake = plw[1].wu.dm_quake = 0;
        }
    }

    settle_check();

    if (pcon_rno[0] == 2) {
        if (Round_Result & 0x980) {
            if ((Round_Result & 0x800) && gouki_wins) {
                effect_D3_init(1);
            } else {
                effect_D3_init(0);
            }
        }

        if ((plw[0].kezurijini_flag == 1) || (plw[1].kezurijini_flag == 1)) {
            Round_Result |= 0x200;
        }

        if (Winner_id != Loser_id) {
            grade_store_vitality(Winner_id + 0);
        }
    }

    grade_check_tairyokusa();
}
