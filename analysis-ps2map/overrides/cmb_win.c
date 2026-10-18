/* Located by their bytes (tools/locate_data.py): cmb_pos_tbl is 0x27F6A0. */

/* Rewritten to match retail (tools/permute.py): grade_add_reversal parameter 1: s16 -> s32. */
s32 reversal_check(s8 PL) {
    s8 PLS;

    if (rever_attack[PL]) {
        return 0;
    }

    if (plw[PL].wu.routine_no[1] == 4 && plw[PL].wu.old_rno[1] == 1 && pcon_dp_flag == 0 &&
        plw[PL].wu.routine_no[2] >= 0x10) {
        rever_attack[PL] = 1;

        if (PL == 0) {
            PLS = (1);
        } else {
            PLS = 0;
        }

        combo_window_push(PLS, 5);
        grade_add_reversal(PL);
        return 1;
    }

    return 0;
}

/* Xbox: the operands are the other way round */
void first_attack_pts_check(s8 PL) {
    if (plw[PL].wu.id == first_attack - 1) {
        first_attack = 3;
        bonus_pts[PL] += 2;
    }
}

/* <= 47, as retail compares. */
void super_arts_finish_check(s8 PL) {
    if (arts_finish_check2(PL) != 0) {
        if ((plw[PL].cb->new_dm & 0x3F) <= 47) {
            sa_kind = 2;
        } else {
            sa_kind = 3;
        }

        combo_window_push(PL, 3);
    }
}

/* <= 7, as retail compares. */
void hit_combo_check(s8 PL) {
    s32* sa_ptr = (s32*)plw[PL].cb->kind_of[4][0];
    s8 lpx;

    for (lpx = 0; lpx < 20; lpx++) {
        if (!(*sa_ptr++ == 0)) {
            if (arts_finish_check(PL)) {
                if (lpx <= 7) {
                    bonus_pts[PL] += 2;
                    sa_kind = 2;
                } else {
                    bonus_pts[PL] += 3;
                    sa_kind = 3;
                }

                combo_window_push(PL, 2);
                return;
            }

            combo_window_push(PL, 1);
            return;
        }
    }

    combo_window_push(PL, 0);
}

/* Rewritten to match retail (tools/permute.py): grade_get_first_attack parameter 1: s16 -> s32; grade_max_combo_check parameter 1: s16 -> s32; grade_max_combo_check parameter 2: s16 -> s32. */
void combo_window_push(s8 PL, s8 KIND) {
    u32 score;
    s8 PLS;
    u32 Pts_Buff;
    s32 xx;
    s16 i;

    s32 assign1;
    s32 assign2;

    if (KIND < 3) {
        score = SCORE_CALCULATION(PL);
        grade_max_combo_check(PL ^ 1, hit_num);
    }

    if (PL == 0) {
        PLS = 1;
    } else {
        PLS = 0;
    }

    if (cmb_stock[PL] == 5) {
        switch (KIND) {
        case 2:
            if (sa_kind == 2) {
                score += 20000;
            } else {
                score += 30000;
            }
            break;

        case 3:
            if (sa_kind == 2) {
                score = 20000;
            } else {
                score = 30000;
            }
            break;

        case 4:
            score = 1500;
            grade_get_first_attack(PLS);
            break;

        case 6:
            score = paring_counter[PLS] * 100;
            break;
        }

        if (score >= 1000000) {
            score = 999900;
        }

        SCORE_PLUS(PLS, score);

        if (Mode_Type == 1) {
            Score_Sub();
        } else if (plw[PLS].wu.operator) {
            Score_Sub();
        }

        return;
    } else {
        cmb_stock[PL]++;
        cmst_buff[PL][cst_write[PL]].routine_num = 0;
        cmst_buff[PL][cst_write[PL]].hit_hi = (u8)hit_num / 10;
        cmst_buff[PL][cst_write[PL]].hit_low = (u8)hit_num - (cmst_buff[PL][cst_write[PL]].hit_hi * 10);
        cmst_buff[PL][cst_write[PL]].kind = KIND;

        if (Mode_Type == 1) {
            cmst_buff[PL][cst_write[PL]].pts_flag = 1;
        } else if (Mode_Type == 5) {
            cmst_buff[PL][cst_write[PL]].pts_flag = 1;
        } else if (plw[PLS].wu.operator) {
            cmst_buff[PL][cst_write[PL]].pts_flag = 1;
        } else {
            cmst_buff[PL][cst_write[PL]].pts_flag = 0;
        }

        switch (KIND) {
        case 0:
        case 1:
            break;

        case 2:
            if (sa_kind == 2) {
                score += 20000;
            } else {
                score += 30000;
            }
            break;

        case 3:
            if (sa_kind == 2) {
                score = 20000;
            } else {
                score = 30000;
            }
            break;

        case 4:
            score = 1500;
            grade_get_first_attack(PLS);
            break;

        case 5:
            score = 0;
            cmst_buff[PL][cst_write[PL]].pts_flag = 0;
            break;

        case 6:
            score = paring_counter[PLS] * 100;
            break;
        }

        if (score >= 1000000) {
            score = 999900;
        }

        Pts_Buff = cmst_buff[PL][cst_write[PL]].pts = score;
        i = 3;
        xx = 100000;

        assign1 = cmst_buff[PL][cst_write[PL]].first_digit = -1;

        while (i >= 0) {
            cmst_buff[PL][cst_write[PL]].pts_digit[i] = Pts_Buff / xx & 0xFF;
            Pts_Buff -= (cmst_buff[PL][cst_write[PL]].pts_digit[i] * xx);

            if (cmst_buff[PL][cst_write[PL]].first_digit < 0 && cmst_buff[PL][cst_write[PL]].pts_digit[i]) {
                cmst_buff[PL][cst_write[PL]].first_digit = i;
            }

            i--;
            assign2 = xx /= 10;
        }

        cmst_buff[PL][cst_write[PL]].move[1] = cmst_buff[PL][cst_write[PL]].first_digit + 6;

        if (cst_write[PL] == 4) {
            cst_write[PL] = 0;
        } else {
            cst_write[PL]++;
        }
    }
}

/* Rewritten to match retail (tools/permute.py): check_combo_end parameter 1: s16 -> s32. */
void combo_control(s8 PL) {
    s16 cmb_flag;

    cmb_flag = check_combo_end(PL + 0);

    if (cmb_flag) {
        cmb_calc_now[PL] = 1;
    } else {
        cmb_calc_now[PL] = 0;
    }

    if (reversal_check(PL) == 0) {
        if (rever_attack[PL]) {
            reversal_continue_check(PL);
        }

        if (!paring_check(PL) && plw[PL].cb->total) {
            if (first_attack == 0) {
                first_attack = plw[PL].wu.id + 1;
                combo_window_push(PL, 4);
                return;
            }

            if (pcon_dp_flag == 1 && last_hit_time == 0) {
                super_arts_last_check(PL);
            }

            if (cmb_flag != 0) {
                return;
            } else if (plw[PL].cb->total == 1) {
                training_disp_data_set(PL, 1);
                super_arts_finish_check(PL);
                combo_hensuu_clear(PL);
                first_attack = 3;
                return;
            }

            check_and_set_combo(PL);
        }
    }
}


/* Xbox-only: the drawing half of combo_window_trans, called from the
 * draw pass. It draws the combo message and points for the current
 * window. It repeats the routine-0 setup and still sets end_flag bit 2
 * and the routine-2 timer, as retail does. */
void xb_cmb_win_draw(s8 PL) {
    if (cmb_stock[PL] == 0) {
        return;
    }

    if (cmst_buff[PL][cst_read[PL]].pts_flag) {
        switch (cmst_buff[PL][cst_read[PL]].routine_num) {
        case 0:
            cmst_buff[PL][cst_read[PL]].move[0] = cmb_window_move_tbl[cmst_buff[PL][cst_read[PL]].kind];
            cmst_buff[PL][cst_read[PL]].x_posnum[0] = 0;
            cmst_buff[PL][cst_read[PL]].timer[0] = 8;
            end_flag[PL] = 0;
            cmst_buff[PL][cst_read[PL]].x_posnum[1] = 0;
            break;

        case 1:
            if (cmst_buff[PL][cst_read[PL]].x_posnum[0] != 0) {
                combo_message_set(PL, cmst_buff[PL][cst_read[PL]].kind, cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[0] - 1], cmst_buff[PL][cst_read[PL]].x_posnum[0], cmst_buff[PL][cst_read[PL]].hit_hi,
                                  cmst_buff[PL][cst_read[PL]].hit_low);
            }

            if (!(end_flag[PL] & 2)) {
                if (cmst_buff[PL][cst_read[PL]].timer[0] < 0) {
                    if (cmst_buff[PL][cst_read[PL]].x_posnum[1] < cmst_buff[PL][cst_read[PL]].move[1] + 2) {
                        if (cmst_buff[PL][cst_read[PL]].x_posnum[1] < cmst_buff[PL][cst_read[PL]].move[1]) {
                            if (cmst_buff[PL][cst_read[PL]].x_posnum[1] != 0) {
                                combo_pts_set(PL, cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[1] - 1], cmst_buff[PL][cst_read[PL]].x_posnum[1],
                                              &cmst_buff[PL][cst_read[PL]].pts_digit[0], cmst_buff[PL][cst_read[PL]].first_digit);
                            }
                        } else if (cmst_buff[PL][cst_read[PL]].x_posnum[1] != 0) {
                            combo_pts_set(PL, cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[1] - 1], cmst_buff[PL][cst_read[PL]].move[1] - 1,
                                          &cmst_buff[PL][cst_read[PL]].pts_digit[0], cmst_buff[PL][cst_read[PL]].first_digit);
                        }
                    } else {
                        end_flag[PL] |= 2;
                        combo_pts_set(PL, cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[1] - 1], cmst_buff[PL][cst_read[PL]].move[1] - 1,
                                      &cmst_buff[PL][cst_read[PL]].pts_digit[0], cmst_buff[PL][cst_read[PL]].first_digit);
                    }
                }
            } else {
                combo_pts_set(PL, cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[1] - 1], cmst_buff[PL][cst_read[PL]].move[1] - 1, &cmst_buff[PL][cst_read[PL]].pts_digit[0],
                              cmst_buff[PL][cst_read[PL]].first_digit);
            }

            if (!(Game_pause & 0x80) && (end_flag[PL] & 3) == 3) {
                cmst_buff[PL][cst_read[PL]].timer[1] = cmb_window_time_tbl[cmst_buff[PL][cst_read[PL]].kind];
            }

            break;

        case 2:
            if ((Game_pause & 0x80) || cmst_buff[PL][cst_read[PL]].timer[1] != 0) {
                combo_message_set(PL, cmst_buff[PL][cst_read[PL]].kind, cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[0] - 1], cmst_buff[PL][cst_read[PL]].x_posnum[0], cmst_buff[PL][cst_read[PL]].hit_hi,
                                  cmst_buff[PL][cst_read[PL]].hit_low);
                combo_pts_set(PL, cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[1] - 1], cmst_buff[PL][cst_read[PL]].move[1] - 1, &cmst_buff[PL][cst_read[PL]].pts_digit[0],
                              cmst_buff[PL][cst_read[PL]].first_digit);
            }

            break;
        }
    } else {
        switch (cmst_buff[PL][cst_read[PL]].routine_num) {
        case 0:
            cmst_buff[PL][cst_read[PL]].move[0] = cmb_window_move_tbl[cmst_buff[PL][cst_read[PL]].kind];
            cmst_buff[PL][cst_read[PL]].x_posnum[0] = 1;
            cmst_buff[PL][cst_read[PL]].routine_num++;
            break;

        case 1:
            combo_message_set(PL, cmst_buff[PL][cst_read[PL]].kind, cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[0] - 1], cmst_buff[PL][cst_read[PL]].x_posnum[0], cmst_buff[PL][cst_read[PL]].hit_hi,
                              cmst_buff[PL][cst_read[PL]].hit_low);
            break;

        case 2:
            if ((Game_pause & 0x80) || cmst_buff[PL][cst_read[PL]].timer[1] != 0) {
                combo_message_set(PL, cmst_buff[PL][cst_read[PL]].kind, cmb_pos_tbl[PL][cmst_buff[PL][cst_read[PL]].x_posnum[0] - 1], cmst_buff[PL][cst_read[PL]].x_posnum[0], cmst_buff[PL][cst_read[PL]].hit_hi,
                                  cmst_buff[PL][cst_read[PL]].hit_low);
            }

            break;
        }
    }
}

