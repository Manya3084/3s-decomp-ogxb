
/* Xbox-only: the drawing half of spgauge_cont_main, called from the draw
 * pass. It puts the gauge bases, the SA timer text, the stock and frame
 * of a full gauge, and the gauge itself. */
void xb_sast_draw(void) {
    u8 i;

    for (i = 0; i < 2; i++) {
        spgauge_base_put(i, spg_dat[i].spg_len);
    }

    if ((Game_pause & 0x80) || EXE_flag || Stop_SG) {
        return;
    }

    if (Old_Stop_SG) {
        Old_Stop_SG = 0;
        Exec_Wipe_F = 0;
        time_clear[0] = 0;
        time_clear[1] = 0;
    }

    if (time_flag[0] == 0 && time_flag[1] == 0) {
        return;
    }

    if (time_timer == 0) {
        if (time_flag[0] == 1 && time_operate[0] == 1) {
            scfont_sqput2(1, 25, 11, 0, 2, sa_time_data_tbl[time_num][0], 0, 4, 2);
        }

        if (time_flag[1] == 1 && time_operate[1] == 1) {
            scfont_sqput2(43, 25, 11, 0, 2, sa_time_data_tbl[time_num][1], 0, 4, 2);
        }

        time_timer = 3;

        if (time_num == 5) {
            time_num = 0;
        } else {
            time_num++;
        }
    }

    for (i = 0; i < 2; i++) {
        if (spg_dat[i].max) {
            switch (spg_dat[i].max_rno) {
            case 0:
                sa_moji_trans(i, 0, 1);
                spg_dat[i].spg_level = plw[i].sa->store;
                sa_stock_trans(spg_dat[i].spg_level, 1, i);
                sa_waku_trans(i, 1);
                break;

            case 1:
                if (spg_dat[i].timer != 0) {
                    if (spg_dat[i].timer2 != 0) {
                        break;
                    }

                    sa_waku_trans(i, spg_dat[i].kind);
                    sa_stock_trans(spg_dat[i].spg_level, spg_dat[i].kind, i);
                } else {
                    sa_waku_trans(i, 1);
                    sa_stock_trans(spg_dat[i].spg_level, 1, i);
                }

                break;
            }
        } else if (spg_dat[i].flag) {
            sast_control(i);
        }
    }

    for (i = 0; i < 2; i++) {
        if (gauge_stop_flag[i] == 0) {
            if (spg_dat[i].current_spg == plw[i].sa->gauge.s.h && spg_dat[i].max == 0) {
                return;
            }

            if (spg_dat[i].max) {
                spg_dat[i].current_spg = spg_dat[i].spg_dotlen;
            } else {
                spg_dat[i].current_spg = plw[i].sa->gauge.s.h;
            }

            if (max2[i] == 1) {
                return;
            }

            if (spg_dat[i].max == 0 && spg_dat[i].flag == 0 && spg_dat[i].max_old == 0 &&
                spg_dat[i].time_no_clear == 0) {
                sa_gauge_trans(i);
            }
        }
    }
}
