/* Rewritten to match retail (tools/permute.py): Bg_Texture_Load_Ending parameter 1: s16 -> s32. */
void common_end_init00(s16 pl_num) {
    s16 i;

    Family_Init();
    Scrn_Pos_Init();
    Zoomf_Init();
    bg_w.bg_opaque = ending_opaque[pl_num];
    Screen_Switch = 0;
    Screen_Switch_Buffer = 0;
    bg_disp_off = 0;
    end_w.type = pl_num;
    bg_w.scno = end_use_scr[end_w.type];
    bg_w.scrno = end_use_real_scr[end_w.type];
    Bg_Texture_Load_Ending(end_w.type);
    ending_obj_load();
    bg_w.pos_offset = 192;
    base_y_pos = 40;

    for (i = 0; i < 7; i++) {
        bg_w.bgw[i].r_no_0 = 0;
        bg_w.bgw[i].r_no_1 = 0;
        bg_w.bgw[i].r_no_2 = 0;
        bg_w.bgw[i].pos_x_work = bg_w.bgw[i].pos_y_work = 0;
        bg_w.bgw[i].zuubun = 0;
        bg_w.bgw[i].xy[0].cal = 0;
        bg_w.bgw[i].xy[1].cal = 0;
        bg_w.bgw[i].wxy[0].cal = 0;
        bg_w.bgw[i].wxy[1].cal = 0;
        bg_w.bgw[i].hos_xy[0].cal = 0;
        bg_w.bgw[i].hos_xy[1].cal = 0;
        bg_w.bgw[i].rewrite_flag = 0;
    }

    for (i = 0; i < bg_w.scno; i++) {
        bg_w.bgw[i].r_no_1 = bg_w.bgw[i].r_no_2 = 0;
        bg_w.bgw[i].fam_no = i;
    }
}
