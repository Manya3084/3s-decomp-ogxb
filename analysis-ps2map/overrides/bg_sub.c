/* Rewritten to match retail (tools/permute.py): < 0x180 -> <= 0x17f; < 0x40 -> <= 0x3f. */
void bg_base_x_move_sub() {
    s16 work[2];
    s8 st[2];
    s8 i;
    s16 bg_pos;

    bg_pos = ideal_w.iw[0].disp.pos - bg_w.pos_offset;

    if (plw[0].wu.scr_mv_x < ideal_w.iw[0].disp.pos) {
        work[0] = plw[0].wu.scr_mv_x - *&satse[plw[0].player_number];
    } else {
        work[0] = plw[0].wu.scr_mv_x + *&satse[plw[0].player_number];
    }

    work[0] -= bg_pos;

    if (plw[1].wu.scr_mv_x < ideal_w.iw[0].disp.pos) {
        work[1] = plw[1].wu.scr_mv_x - *&satse[plw[1].player_number];
    } else {
        work[1] = plw[1].wu.scr_mv_x + *&satse[plw[1].player_number];
    }

    work[1] -= bg_pos;

    if (work[0] < 0) {
        work[0] = 0;
    } else if (work[0] > 0x17F) {
        work[0] = 0x17F;
    }

    if (work[1] < 0) {
        work[1] = 0;
    } else if (work[1] > 0x17F) {
        work[1] = 0x17F;
    }

    for (i = 0; i < 2; i++) {
        if (0 <= work[i] && work[i] <= 0x3f) {
            st[i] = 1;
        } else if (work[i] >= 0x140 && work[i] <= 0x17f) {
            st[i] = 2;
        } else {
            st[i] = 0;
        }
    }

    scr_x_mv_jp[(st[0] << 4) + st[1]]();
}

/* Rewritten to match retail (tools/permute.py): Bg_Texture_Load2 parameter 1: u8 -> s32. */
void bg_etc_write(s16 type) {
    u8 i;

    Family_Init();
    Scrn_Pos_Init();
    Zoomf_Init();
    bg_w.bg_opaque = 224;
    Screen_Switch = 0;
    Screen_Switch_Buffer = 0;
    bg_disp_off = 0;
    bg_w.scno = bg_w.scrno = use_scr2[type];
    bg_w.pos_offset = 192;

    Bg_Texture_Load2((u8)type);

    for (i = 0; i < 7; i++) {
        bg_w.bgw[i].pos_x_work = 0;
        bg_w.bgw[i].pos_y_work = 0;
        bg_w.bgw[i].hos_xy[1].cal = bg_w.bgw[i].hos_xy[0].cal = bg_w.bgw[i].wxy[1].cal = bg_w.bgw[i].wxy[0].cal =
            bg_w.bgw[i].xy[1].cal = bg_w.bgw[i].xy[0].cal = bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].rewrite_flag = 0;
        bg_w.bgw[i].fam_no = i;
        bg_w.bgw[i].speed_y = bg_w.bgw[i].speed_x = 0;
        bg_w.bgw[i].r_no_1 = bg_w.bgw[i].r_no_2 = 0;
    }

    bg_w.scr_stop = 0;
    bg_w.frame_flag = 0;
    bg_w.old_chase_flag = bg_w.chase_flag = 0;
    bg_w.bg_f_x = 64;
    bg_w.bg_f_y = 64;
    bg_w.bg2_sp_x2 = bg_w.bg2_sp_x = 0;
    bg_w.max_x = 8;
    bg_w.quake_x_index = 0;
    bg_w.quake_y_index = 0;

    for (i = 0; i < bg_w.scno; i++) {
        bg_w.bgw[i].hos_xy[0].cal = bg_w.bgw[i].wxy[0].cal = bg_w.bgw[i].xy[0].cal = bg_pos_tbl2[type][i][0];
        bg_w.bgw[i].hos_xy[1].cal = bg_w.bgw[i].wxy[1].cal = bg_w.bgw[i].xy[1].cal = bg_pos_tbl2[type][i][1];
        bg_w.bgw[i].pos_y_work = bg_w.bgw[i].xy[1].disp.pos;
        bg_w.bgw[i].old_pos_x = bg_w.bgw[i].pos_x_work = bg_w.bgw[i].xy[0].disp.pos;
        bg_w.bgw[i].speed_x = msp2[type][i][0];
        bg_w.bgw[i].speed_y = msp2[type][i][1];
        bg_w.bgw[i].rewrite_flag = 0;
        bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].frame_deff = 64;
        bg_w.bgw[i].max_x_limit = bg_w.bgw[i].speed_x * bg_w.max_x;
    }

    base_y_pos = 40;
}
