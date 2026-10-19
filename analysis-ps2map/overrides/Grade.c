/* Rewritten to match retail (tools/permute.py): < 2 -> <= 1. */
void grade_add_guard_success(s16 ix) {
    if ((u16)ix <= 1) {
        judge_item[ix][Play_Type].guard_succ++;
    }
}

/* Rewritten to match retail (tools/permute.py): < 0x180 -> <= 0x17f. */
void grade_add_onaji_waza(s16 ix) {
    s16 num;

    num = plw[ix].wu.char_index + ((plw[ix].wu.now_koc == 5) * 0xF0);
    if (num <= 0x17f) {
        if (ji_sat[ix][num] != 0xFF) {
            ji_sat[ix][num]++;
        }

        if (judge_item[ix][Play_Type].onaji_waza < ji_sat[ix][num]) {
            judge_item[ix][Play_Type].onaji_waza = ji_sat[ix][num];
        }
    }
}

/* Rewritten to match retail (tools/permute.py): < 2 -> <= 1. */
void check_guard_miss(WORK* as, PLW* ds, s8 gddir) {
    if (ds->rp->total) {
        return;
    }

    judge_item[ds->wu.id][Play_Type].grd_mcnt++;

    if ((ds->guard_flag != 3) && (as->att.guard & 0x3F) && (ds->wu.xyz[1].disp.pos <= 1) &&
        (as->work_id != 1 || !as->jump_att_flag || !(ds->cp->sw_new & 0xF)) && (!(ds->cp->sw_new & 1)) &&
        (!(ds->saishin_lvdir & gddir)) && ((ds->cp->waza_flag[3] + ds->cp->waza_flag[4]) == 0)) {
        return;
    }

    judge_item[ds->wu.id][Play_Type].grd_miss++;
}

/* all_clear is VS_Index[WINNER] > 9. */
void grade_makeup_final_parameter(s16 ix, s16 pt) {
    renew_judge_final_work(ix, pt);
    judge_final[ix][pt].all_clear = VS_Index[WINNER] > 9;
    judge_final[ix][pt].keizoku = Continue_Coin[ix];
    makeup_spp_frdat(ix, pt);
    makeup_final_grade(ix, pt);
}

/* Play_Type is read once, and the loop keeps a separate down counter. */
void grade_makeup_round_para_dko() {
    s32 i;
    s32 n;
    s32 pt = Play_Type;

    for (i = 0, n = 2; n != 0; i++, n--) {
        judge_item[i][pt].offence_total += get_offence_total(i);
        judge_item[i][pt].defence_total += get_defence_total(i, 0);
        judge_item[i][pt].tech_pts_total += get_tech_pts_total(i);
        judge_item[i][pt].ex_point_total += get_ex_point_total(i, 0);
        judge_item[i][pt].round += 1;
    }

    backup_RO_PT();
}

/* Xbox: without the last_judge_dada stores (remake_2_10 is not in the image). */
s16 get_offence_total(s16 ix) {
    s32 num;
    s32 num2;
    s32 point;
    s32 point2;
    s16 i;
    s16 ix2;

    ix2 = (ix + 1) & 1;
    point = point2 = 0;
    num2 = judge_item[ix2][Play_Type].guard_succ + judge_item[ix2][Play_Type].nml_blocking +
           judge_item[ix2][Play_Type].rpd_blocking + judge_item[ix2][Play_Type].grd_blocking +
           judge_item[ix][Play_Type].clean_hits;

    if (num2 != 0) {
        num = (judge_item[ix][Play_Type].clean_hits * 100) / num2;
    } else {
        num = 0;
    }


    for (i = 0; i < 23; i++) {
        if (num < grade_t_meichuuritsu2[i + 1][0]) {
            break;
        }
    }

    point2 = grade_t_meichuuritsu2[i][1];

    if (judge_item[ix][Play_Type].att_renew) {
        num = (num2 * 100) / judge_item[ix][Play_Type].att_renew;
    } else {
        num = 0;
    }

    point2 = (point2 * num) / 100;

    if (judge_item[ix2][Play_Type].grd_mcnt) {
        num = (judge_item[ix2][Play_Type].grd_miss * 100) / judge_item[ix2][Play_Type].grd_mcnt;
    } else {
        num = 0;
    }


    for (i = 0; i < 20; i++) {
        if (num < grade_t_meichuuritsu3[i + 1][0]) {
            break;
        }
    }

    point2 *= grade_t_meichuuritsu3[i][1];
    point2 /= 32;

    point = point2;

    for (i = 0; i < 4; i++) {
        if (judge_item[ix][Play_Type].em_stun < grade_t_em_stun[i + 1][0]) {
            break;
        }
    }

    point += grade_t_em_stun[i][1];

    for (i = 0; i < 18; i++) {
        if (judge_item[ix][Play_Type].max_combo < grade_t_max_combo[i + 1][0]) {
            break;
        }
    }

    point += grade_t_max_combo[i][1];

    return point;
}

/* Xbox: without the last_judge_dada stores (remake_2_10 is not in the image). */
s16 get_defence_total(s16 ix, s16 wf) {
    s32 num = 0;
    s16 i;
    s16 ix2;
    s32 point;
    s32 point2;

    ix2 = (ix + 1) & 1;

    if (judge_item[ix2][Play_Type].att_renew) {
        point2 = ((judge_item[ix2][Play_Type].att_renew - judge_item[ix2][Play_Type].clean_hits) * 100) /
                 judge_item[ix2][Play_Type].att_renew;
    } else {
        point2 = 0;
    }


    for (i = 0; i < 13; i++) {
        if (point2 < grade_t_bougyoritsu2[i + 1][0]) {
            break;
        }
    }

    num += grade_t_bougyoritsu2[i][1];
    point2 = judge_item[ix][Play_Type].clean_hits + judge_item[ix2][Play_Type].guard_succ;

    if (judge_item[ix][Play_Type].att_renew) {
        point2 = (point2 * 100) / judge_item[ix][Play_Type].att_renew;
    } else {
        point2 = 0;
    }


    for (i = 0; i < 12; i++) {
        if (point2 < grade_t_bougyoritsu3[i + 1][0]) {
            break;
        }
    }

    point = grade_t_bougyoritsu3[i][1];

    if (judge_item[ix2][Play_Type].att_renew == 0) {
        point = (point * 200) / 100;
    }

    num += point;

    if (wf) {
        for (i = 0; i < 12; i++) {
            if (judge_item[ix][Play_Type].vitality < grade_t_nokori_vital[i + 1][0]) {
                break;
            }
        }

        num += grade_t_nokori_vital[i][1];
    }

    for (i = 0; i < 10; i++) {
        if (judge_item[ix][Play_Type].nml_blocking < grade_t_def_nmlblock[i + 1][0]) {
            break;
        }
    }

    num += grade_t_def_nmlblock[i][1];

    for (i = 0; i < 10; i++) {
        if (judge_item[ix][Play_Type].rpd_blocking < grade_t_def_rpdblock[i + 1][0]) {
            break;
        }
    }

    num += grade_t_def_rpdblock[i][1];

    for (i = 0; i < 8; i++) {
        if (judge_item[ix][Play_Type].grd_blocking < grade_t_def_grdblock[i + 1][0]) {
            break;
        }
    }

    num += grade_t_def_grdblock[i][1];

    return num;
}

/* Xbox: without the last_judge_dada stores (remake_2_10 is not in the image). */
void grade_check_work_round_init(s16 ix) {
    s16 i;

    judge_item[ix][Play_Type].em_stun = 0;
    judge_item[ix][Play_Type].max_combo = 0;
    judge_item[ix][Play_Type].clean_hits = 0;
    judge_item[ix][Play_Type].att_renew = 0;
    judge_item[ix][Play_Type].guard_succ = 0;
    judge_item[ix][Play_Type].vitality = 0;
    judge_item[ix][Play_Type].nml_blocking = 0;
    judge_item[ix][Play_Type].rpd_blocking = 0;
    judge_item[ix][Play_Type].grd_blocking = 0;
    judge_item[ix][Play_Type].first_attack = 0;
    judge_item[ix][Play_Type].leap_attack = 0;
    judge_item[ix][Play_Type].target_combo = 0;
    judge_item[ix][Play_Type].nml_nage = 0;
    judge_item[ix][Play_Type].grap_def = 0;
    judge_item[ix][Play_Type].quick_stand = 0;
    judge_item[ix][Play_Type].personal_act = 0;
    judge_item[ix][Play_Type].reversal = 0;
    judge_item[ix][Play_Type].comwaza = 0;
    judge_item[ix][Play_Type].sa_exec = 0;
    judge_item[ix][Play_Type].tairyokusa = 0;
    judge_item[ix][Play_Type].kimarite = 0;
    judge_item[ix][Play_Type].app_nml_block = -1;
    judge_item[ix][Play_Type].app_rpd_block = -1;
    judge_item[ix][Play_Type].app_grd_block = -1;
    judge_item[ix][Play_Type].onaji_waza = 0;

    if (Round_Operator[ix] == 0) {
        judge_item[ix][Play_Type].grd_miss = ji_grd_init_data[Setup_Lv10(0)];
        judge_item[ix][Play_Type].grd_mcnt = ji_grd_init_data[Setup_Lv10(0)];
    } else {
        judge_item[ix][Play_Type].grd_miss = 0;
        judge_item[ix][Play_Type].grd_mcnt = 0;
    }

    for (i = 0; i < 384; i++) {
        ji_sat[ix][i] = 0;
    }

    judge_gals[ix].grade = 0;
    judge_gals[ix].offence_total = 0;
    judge_gals[ix].defence_total = 0;
    judge_gals[ix].tech_pts_total = 0;
    judge_gals[ix].ex_point_total = 0;
}
