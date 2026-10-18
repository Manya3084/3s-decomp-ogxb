/* Rewritten to match retail (tools/permute.py): set_field_hosei_flag parameter 2: s16 -> s32; Player_move_bonus parameter 2: u16 -> s32. */
void move_P1_move_P2_bonus(s16* field_work) {
    Player_move_bonus(&plw[0], processed_lvbt(Convert_User_Setting(0)));

    if (set_field_hosei_flag(&plw[0], field_work[0], 1) != 0) {
        set_field_hosei_flag(&plw[0], field_work[1], 0);
    }

    Player_move_bonus(&plw[1], processed_lvbt(Convert_User_Setting(1)));

    if (set_field_hosei_flag(&plw[1], field_work[2], 1) != 0) {
        set_field_hosei_flag(&plw[1], field_work[3], 0);
    }

    if (Bonus_Game_Flag == 20) {
        plw[1].wu.disp_flag = 0;
    }
}

/* Rewritten to match retail (tools/permute.py): set_field_hosei_flag parameter 2: s16 -> s32; Player_move_bonus parameter 2: u16 -> s32. */
void move_P2_move_P1_bonus(s16* field_work) {
    Player_move_bonus(&plw[1], processed_lvbt(Convert_User_Setting(1)));

    if (set_field_hosei_flag(&plw[1], field_work[2], 1) != 0) {
        set_field_hosei_flag(&plw[1], field_work[3], 0);
    }

    Player_move_bonus(&plw[0], processed_lvbt(Convert_User_Setting(0)));

    if (set_field_hosei_flag(&plw[0], field_work[0], 1) != 0) {
        set_field_hosei_flag(&plw[0], field_work[1], 0);
    }

    if (Bonus_Game_Flag == 20) {
        plw[0].wu.disp_flag = 0;
    }
}
