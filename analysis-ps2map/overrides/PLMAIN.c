/* Rewritten to match retail (tools/permute.py): <= 0 -> < 1. */
void sag_union(PLW* wk) {
    switch (wk->sa->sa_rno) {
    case 0:
        if (wk->sa->store) {
            wk->sa->sa_rno = 1;
            wk->sa->ok = 1;
            wk->sa->id_arts++;
        }

        wk->sa->saeff_ok = 0;
        break;

    case 1:
        if (wk->sa->store == 0) {
            wk->sa->sa_rno = 0;
            wk->sa->ok = 0;
            break;
        }

        if (wk->sa->ok == -1) {
            wk->sa->sa_rno = 2;
            wk->sa->sa_rno2 = 0;
            wk->sa->saeff_ok = 1;

            if (wk->sa->gt2 == 0) {
                wk->sa->bacckup_g_h = 0;
                break;
            }
        }

        break;

    case 2:
        switch (wk->sa->gt2) {
        case 0:
            switch (wk->sa->saeff_ok) {
            case -1:
                if (pcon_dp_flag == 0) {
                    if (wk->sa->ex4th_exec) {
                        wk->sa->store = 0;
                    } else {
                        wk->sa->store--;
                    }
                }

                sag_bug_fix(wk->wu.id);
                wk->sa->saeff_ok = 0;
                wk->sa->sa_rno = 0;
                wk->sa->ok = 0;
                sag_inc_timer[wk->wu.id] = 20;
                break;

            case 1:
                if (wk->wu.routine_no[1] != 4) {
                default:
                    wk->sa->saeff_ok = 0;
                    wk->sa->sa_rno = 0;
                    wk->sa->ok = 0;
                }
            }

            break;

        case 1:
            switch (wk->sa->sa_rno2) {
            case 0:
                switch (wk->sa->saeff_ok) {
                case -1:
                    if (pcon_dp_flag == 0) {
                        if (wk->sa->ex4th_exec) {
                            wk->sa->store = 0;
                        } else {
                            wk->sa->store--;
                        }
                    }

                    sag_bug_fix(wk->wu.id);

                    if (wk->sa->mp == 1) {
                        wk->sa->bacckup_g_h = 0;
                    } else {
                        wk->sa->bacckup_g_h = wk->sa->gauge.s.h;
                    }

                    wk->sa->gauge.s.h = wk->sa->gauge_len;
                    wk->sa->gauge.s.l = -1;
                    wk->sa->sa_rno2 = 1;
                    wk->sa->saeff_ok = 0;
                    break;

                case 1:
                    if (wk->wu.routine_no[1] != 4) {
                    default:
                        wk->sa->saeff_ok = 0;
                        wk->sa->sa_rno = 0;
                        wk->sa->ok = 0;
                        wk->sa->dtm_mul = 1;
                    }
                }

                break;

            case 1:
                if (Timer_Freeze != 0) {
                    break;
                }

                wk->sa->sa_rno2 = 2;
                /* fallthrough */

            case 2:
                if ((wk->sa_stop_flag != 1) && (((PLW*)wk->wu.target_adrs)->sa_stop_flag != 1)) {
                    wk->sa->gauge.i -= wk->sa->dtm * wk->sa->dtm_mul;
                }

                if (wk->sa->gauge.s.h < 1 || Suicide[6] != 0) {
                    wk->sa->gauge.i = 0;
                    wk->sa->ok = 0;
                    wk->sa->sa_rno = 0;
                    wk->sa->dtm_mul = 1;
                    wk->sa->gauge.s.h = wk->sa->bacckup_g_h;
                    sag_inc_timer[wk->wu.id] = 20;
                    break;
                }

                if (My_char[wk->wu.id] == 3) {
                    addSAAttribute(&wk->wu.kind_of_waza, &wk->wu.at_koa);
                }

                if (My_char[wk->wu.id] == 10) {
                    wk->wu.kind_of_waza |= 32;
                    wk->wu.at_koa = 128;
                }

                if (My_char[wk->wu.id] == 16) {
                    wk->wu.kind_of_waza |= 32;
                    wk->wu.at_koa = 128;
                }

                if (My_char[wk->wu.id] == 18) {
                    wk->wu.kind_of_waza |= 32;
                    wk->wu.at_koa = 128;
                }

                if ((My_char[wk->wu.id] == 9) && (wk->sa->kind_of_arts == 2)) {
                    wk->wu.att.dipsw |= 0x10;
                }

                break;
            }

            break;

        case 3:
            switch (wk->sa->sa_rno2) {
            case 0:
                switch (wk->sa->saeff_ok) {
                case -1:
                    sag_bug_fix(wk->wu.id);
                    wk->sa->store--;
                    wk->sa->saeff_ok = 0;
                    wk->sa->sa_rno2 = 1;
                    break;

                case 1:
                    break;

                default:
                    wk->sa->saeff_ok = 0;
                    wk->sa->sa_rno = 0;
                    wk->sa->ok = 0;
                }

                break;

            default:
                break;
            }

            break;

        default:
            wk->sa->sa_rno = 0;
            wk->sa->ok = 0;
            wk->sa->store = 0;
            wk->sa->saeff_ok = 0;
            break;
        }

        break;
    }
}

/* Xbox: no Debug_w[9] block; the stun recovery is added as a quotient by -32 (PS2: subtracted, by 32); the success flag is stored first. */
void look_after_timers(PLW* wk) {
    if (wk->tsukamarenai_flag) {
        wk->tsukamarenai_flag--;
    }

    if (wk->cat_break_ok_timer) {
        wk->cat_break_ok_timer--;
    }

    if (wk->uot_cd_ok_flag) {
        wk->ukemi_ok_timer--;

        if (wk->ukemi_ok_timer <= 0) {
            wk->ukemi_success = 0;
            wk->ukemi_ok_timer = 0;
            wk->uot_cd_ok_flag = 0;
        } else if (check_ukemi_flag(wk)) {
            wk->ukemi_success = 1;
            wk->ukemi_ok_timer = 0;
            wk->uot_cd_ok_flag = 0;
        }
    }

    if (wk->bullet_hcnt) {
        if (--wk->bhcnt_timer <= 0) {
            wk->bullet_hcnt = 0;
        }
    }

    if (wk->py->now.quantity.h && (wk->wu.hit_stop == 0)) {
        wk->py->now.timer += (wk->py->recover * stun_gauge_r_omake[omop_stun_gauge_rcv[wk->wu.id]]) / -32;

        if (wk->py->now.quantity.h <= 0) {
            wk->py->now.timer = 0;
        }
    }
}

/* Rewritten to match retail (tools/permute.py): check_illegal_lever_data parameter 1: u16 -> s32. */
void Player_move(PLW* wk, u16 lv_data) {
    s16 i;

    if (wk->wu.operator) {
        wk->cp->sw_lvbt = lv_data;
    } else {
        wk->cp->sw_lvbt = processed_lvbt(cpu_algorithm(wk));
    }

    wk->cp->sw_lvbt = check_illegal_lever_data(wk->cp->sw_lvbt);

    if (wk->metamor_over) {
        wk->cp->sw_lvbt = 0;
    }

    if (wk->resurrection_resv) {
        wk->cp->sw_lvbt = 0;
    }

    if (wk->dead_flag) {
        wk->cp->sw_lvbt = 0;
    }

    if (wk->wkey_flag) {
        wk->cp->sw_lvbt = 0;
    }

    if ((wk->dead_flag + wk->wkey_flag) == 0) {
        wk->hurimukenai_flag = 0;
    }

    for (i = 0; i < 8; i++) {
        wk->wu.old_rno[i] = wk->wu.routine_no[i];
    }

    for (i = 0; i < 3; i++) {
        wk->wu.old_pos[i] = wk->wu.xyz[i].disp.pos;
    }

    get_saikinnno_idouryou(wk);
    wk->old_gdflag = wk->guard_flag;
    wk->wu.renew_attack = 0;
    wk->wu.vital_old = wk->wu.vital_new;

    if (wk->sa_stop_flag != 1) {
        waza_check(wk);
    } else {
        key_thru(wk);
    }

    wk->wu.cmwk[10] = wk->cp->lgp;
    wk->wu.cmwk[11] += wk->cp->lgp;
    wk->wu.cmwk[11] &= 0x7FFF;
    wk->wu.cmwk[12] = wk->cp->sw_new;
    wk->wu.cmwk[13] = wk->cp->sw_now;
    plmain_lv_00[wk->wu.routine_no[0]](wk);
}
