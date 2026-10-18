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
