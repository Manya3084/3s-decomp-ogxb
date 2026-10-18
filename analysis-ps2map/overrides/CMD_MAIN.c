/* Rewritten to match retail (tools/permute.py): make_red_blocking_time parameter 1: s16 -> s32; make_red_blocking_time parameter 2: s16 -> s32. */
void cmd_data_set(PLW* /* unused */, s16 i) {
    u8* ptr3;
    u16* ptr4;

    wcp[cmd_id].reset[i] = *cmd_tbl_ptr++;
    waza_work[cmd_id][i].w_dead = *cmd_tbl_ptr++;
    waza_work[cmd_id][i].w_dead2 = *cmd_tbl_ptr++;

    ptr3 = &wcp[cmd_id].waza_r[i][0];
    *ptr3++ = (s8)*cmd_tbl_ptr++;
    *ptr3++ = (s8)*cmd_tbl_ptr++;
    *ptr3++ = (s8)*cmd_tbl_ptr++;
    *ptr3++ = (s8)*cmd_tbl_ptr++;

    wcp[cmd_id].btix[i] = *cmd_tbl_ptr++;

    ptr4 = &wcp[cmd_id].exdt[i][0];
    *ptr4++ = *cmd_tbl_ptr++;
    *ptr4++ = *cmd_tbl_ptr++;
    *ptr4++ = *cmd_tbl_ptr++;
    *ptr4++ = *cmd_tbl_ptr++;

    switch (i) {
    case 3:
    case 4:
    case 5:
        wcp[cmd_id].reset[i] += blok_b_omake[omop_b_block_ix[cmd_id]];
        make_red_blocking_time(cmd_id, i, wcp[cmd_id].reset[i]);
        break;

    case 6:
    case 12:
        wcp[cmd_id].reset[i] += blok_b_omake[omop_b_block_ix[cmd_id]];
        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void check_10() {
    switch (waza_ptr->shot_ok) {
    case 0:
        if (chk_pl->sw_lever == 0) {
            waza_ptr->shot_ok++;
        }
        break;

    case 1:
        if ((cmd_pl->wu.xyz[1].disp.pos > 0 || (waza_type[cmd_id] != 5 && waza_type[cmd_id] != 6)) &&
            chk_pl->now_lvbt & 0xF) {
            if (chk_pl->sw_lever == waza_ptr->w_lvr) {
                waza_ptr->shot_ok++;
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = wcp[cmd_id].reset[waza_type[cmd_id]];
                waza_ptr->free3 = wcp[cmd_id].reset[waza_type[cmd_id]] + 10;
                waza_ptr->w_int = 6;

                switch (waza_type[cmd_id]) {
                case 3:
                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }

                    break;

                case 4:
                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }

                    break;

                case 5:
                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }

                    if (waza_work[cmd_id][6].free3 > 0) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }

                    break;

                case 6:
                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }

                    if (waza_work[cmd_id][5].free3 > 0) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }

                    break;

                case 12:
                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }

                    break;
                }
            } else {
                waza_ptr->shot_ok = 0;
                break;
            }
        }

        break;

    case 2:
        waza_ptr->w_int--;
        waza_ptr->free3--;

        if (waza_ptr->w_int > 0) {
            if (chk_pl->sw_lever == 0) {
                waza_ptr->shot_ok++;
                break;
            }

            if (chk_pl->sw_lever & 8) {
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
                waza_ptr->shot_ok++;
                break;
            }

            if (chk_pl->sw_lever != waza_ptr->w_lvr) {
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
                waza_ptr->shot_ok++;
                break;
            }
        } else {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
            waza_ptr->shot_ok++;
        }

        break;

    case 3:
        waza_ptr->free3--;

        if (waza_ptr->free3 < 0) {
            waza_ptr->w_type = 0;
            return;
        }

        if ((chk_pl->sw_now & 8) || !(chk_pl->sw_now != waza_ptr->w_lvr)) {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
            break;
        }

        if (chk_pl->sw_now & 0xF) {
            waza_ptr->shot_ok++;
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
        }

        break;

    case 4:
        waza_ptr->free3--;

        if (waza_ptr->free3 < 0) {
            waza_ptr->w_type = 0;
        }

        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void check_12() {
    switch (waza_ptr->shot_ok) {
    case 0:
        if (chk_pl->sw_lever == 0) {
            waza_ptr->shot_ok++;
        }
        break;

    case 1:
        if (cmd_pl->wu.xyz[1].disp.pos > 0 && (chk_pl->now_lvbt & 0xF) != 0) {
            if (chk_pl->sw_lever == waza_ptr->w_lvr) {
                waza_ptr->shot_ok++;
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = wcp[cmd_id].reset[waza_type[cmd_id]];
                waza_ptr->free3 = wcp[cmd_id].reset[waza_type[cmd_id]] + 10;
                waza_ptr->w_int = 6;

                switch (waza_type[cmd_id]) {
                case 3:
                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[3] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }

                    break;

                case 4:
                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[4] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }

                    break;

                case 5:
                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[5] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }

                    break;

                case 6:
                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[6] > wcp[cmd_id].waza_flag[12]) {
                        wcp[cmd_id].waza_flag[12] = 0;
                    }

                    break;

                case 12:
                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[3]) {
                        wcp[cmd_id].waza_flag[3] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[4]) {
                        wcp[cmd_id].waza_flag[4] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[5]) {
                        wcp[cmd_id].waza_flag[5] = 0;
                    }

                    if (wcp[cmd_id].waza_flag[12] > wcp[cmd_id].waza_flag[6]) {
                        wcp[cmd_id].waza_flag[6] = 0;
                    }

                    break;
                }
            } else {
                waza_ptr->shot_ok = 0;
                break;
            }
        }

        break;

    case 2:
        waza_ptr->w_int--;
        waza_ptr->free3--;

        if (waza_ptr->w_int > 0) {
            if (chk_pl->sw_lever == 0) {
                waza_ptr->shot_ok++;
                break;
            }

            if (chk_pl->sw_lever & 8) {
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
                waza_ptr->shot_ok++;
                break;
            }

            if (chk_pl->sw_lever != waza_ptr->w_lvr) {
                wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
                waza_ptr->shot_ok++;
                break;
            }
        } else {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
            waza_ptr->shot_ok++;
        }

        break;

    case 3:
        waza_ptr->free3--;

        if (waza_ptr->free3 < 0) {
            waza_ptr->w_type = 0;
            return;
        }

        if ((chk_pl->sw_now & 8) || !(chk_pl->sw_now != waza_ptr->w_lvr)) {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
            break;
        }

        if (chk_pl->sw_now & 0xF) {
            waza_ptr->shot_ok++;
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
        }

        break;

    case 4:
        waza_ptr->free3--;

        if (waza_ptr->free3 < 0) {
            waza_ptr->w_type = 0;
        }

        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void check_23() {
    switch (waza_ptr->shot_ok) {
    case 0:
        if (chk_pl->sw_lever == 0) {
            waza_ptr->shot_ok++;
            break;
        }

        break;

    case 1:
        if ((chk_pl->old_lvbt & 0xF) != (chk_pl->new_lvbt & 0xF) && chk_pl->sw_lever == waza_ptr->w_lvr) {
            waza_ptr->shot_ok++;
            wcp[cmd_id].waza_flag[(waza_type[cmd_id])] = wcp[cmd_id].reset[(waza_type[cmd_id])];
            waza_ptr->free3 = (s16)(((((wcp[cmd_id].reset[(waza_type[cmd_id])])) + 3)));
            waza_ptr->w_int = 6;
        }

        break;

    case 2:
        waza_ptr->w_int -= 1;
        waza_ptr->free3 -= 1;

        if (((waza_ptr->w_int)) > 0) {
            if (chk_pl->sw_lever == 0) {
                waza_ptr->shot_ok++;
                break;
            }

            if (chk_pl->sw_lever & 8) {
                wcp[cmd_id].waza_flag[(waza_type[cmd_id])] = 0;
                waza_ptr->shot_ok++;
                break;
            }

            if (chk_pl->sw_lever != ((waza_ptr->w_lvr))) {
                wcp[cmd_id].waza_flag[(waza_type[cmd_id])] = 0;
                waza_ptr->w_type = 0;
                return;
            }
        } else {
            wcp[cmd_id].waza_flag[(waza_type[cmd_id])] = 0;
            waza_ptr->shot_ok++;
        }

        break;

    case 3:
        waza_ptr->free3--;

        if (waza_ptr->free3 < 0) {
            waza_ptr->w_type = 0;
            break;
        }

        if ((chk_pl->sw_now & 8) || !(chk_pl->sw_now != waza_ptr->w_lvr)) {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
            break;
        }

        if (chk_pl->sw_now & 0xF) {
            wcp[cmd_id].waza_flag[waza_type[cmd_id]] = 0;
            waza_ptr->w_type = 0;
        }

        break;
    }
}
