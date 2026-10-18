/* Xbox-only: sets the 2D scale and origin for a button image
   (njScale(NULL, 1.6667, -2.0, 1.0) and a reset translation). */
void xb_SetButtonImageScale(void);

/* Xbox: the button images are set up by xb_SetButtonImageScale and drawn at 18x14,
   two pixels further right and one or two higher (PS2 22x17). */
void effect_A8_move(WORK_Other_CONN* ewk) {
    s16 ix;

    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (Menu_Cursor_Y[0] == ewk->wu.type) {
        ewk->wu.disp_flag = 1;
    } else {
        ewk->wu.disp_flag = 0;
    }

    switch (ewk->master_id) {
    case 2:
        ewk->wu.my_clear_level = Flash_Synchro;
        Setup_A8_Sub(ewk);
        ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Pos_Data_A8[ewk->wu.dir_step][0];
        ix = ewk->num_of_conn - 1;
        ix = ewk->conn[ix].nx;
        ewk->wu.position_x -= ix / 2;
        sort_push_request3(&ewk->wu);
        break;

    case 0:
        Setup_A8_Sub(ewk);
        sort_push_request3(&ewk->wu);

        if (ewk->wu.disp_flag) {
            xb_SetButtonImageScale();

            if (Order_Dir[ewk->wu.dir_old]) {
                dispButtonImage(-85, 24, 68, 18, 14, 0, 4);
            } else {
                dispButtonImage(-21, -2, 68, 18, 14, 0, 5);
            }
        }

        break;

    case 3:
        sort_push_requestA(&ewk->wu);
        break;
    }
}
