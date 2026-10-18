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
