const s16 EFF66_Half_OBJ_Data[15][7] = {
    { -192, 384, 16, 48, 0, 128, 1 },  { -144, 144, 12, 156, 1, 42, 1 },  { -64, 128, 0, 96, 0, 128, 1 },
    { -184, 368, -40, 208, 1, 77, 1 }, { 104, 176, 32, 96, 1, 175, 1 },   { 128, 144, -26, 180, 0, 128, 1 },
    { -168, 336, -16, 80, 0, 128, 1 }, { 0, 160, 0, 80, 0, 128, 1 },      { -200, 400, 0, 256, 0, 179, 1 },
    { -72, 144, 0, 96, 1, 93, 1 },     { -72, 144, 0, 96, 0, 128, 1 },    { 200, 368, -40, 156, 1, 77, 1 },
    { -184, 368, -40, 156, 1, 128, 1 }, { -184, 368, -54, 160, 1, 64, 1 }, { -176, 352, -32, 192, 1, 77, 1 }
};

/* Data: EFF66_Half_OBJ_Data is 0x24F4E0 (effect_66_setup reads it, 0xE bytes a row).
   Xbox values: row 4 is { 104, 176, 32, 96, 1, 175, 1 } (PS2 { 120, 144, 40,
   80, 1, 42, 2 }) and row 12 clears to 128 (PS2 77). */
/* Xbox: the body of the PS2 effect_66_init, after the work is pulled,
   is its own function. */
s32 effect_66_setup(WORK_Other* ewk, s16 order_index, s16 id, s16 master_player, s16 target_bg, s16 char_ix,
                    s16 char_ix2, s16 option) {
    s16 cg_type;

    ewk->wu.be_flag = 1;
    ewk->wu.id = 66;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x1AC;
    ewk->wu.my_family = target_bg + 1;
    ewk->wu.rl_waza = 1;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.dir_old = order_index;
    ewk->wu.dir_step = char_ix2;
    ewk->wu.type = id;
    ewk->master_player = master_player;
    ewk->wu.char_index = char_ix;
    ewk->master_priority = option;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);

    switch (option) {
    case 1:
        ewk->wu.my_clear_level = 0x80;
        return 0;
    }

    if (ewk->master_priority & 0x8000) {
        cg_type = ewk->master_priority & 0x3FFF;

        switch (cg_type) {
        case 9:
        case 10:
        case 13:
            ewk->wu.my_col_code = 3;
            break;

        default:
            ewk->wu.my_col_code = 1;
            break;
        }

        ewk->wu.shell_ix[0] = EFF66_Half_OBJ_Data[cg_type][0];
        ewk->wu.shell_ix[1] = EFF66_Half_OBJ_Data[cg_type][1];
        ewk->wu.shell_ix[2] = EFF66_Half_OBJ_Data[cg_type][2];
        ewk->wu.shell_ix[3] = EFF66_Half_OBJ_Data[cg_type][3];
        ewk->wu.charset_id = EFF66_Half_OBJ_Data[cg_type][4];
        ewk->wu.my_clear_level = EFF66_Half_OBJ_Data[cg_type][5];
        ewk->wu.rl_waza = EFF66_Half_OBJ_Data[cg_type][6];
    }

    return 0;
}

s32 effect_66_setup(WORK_Other* ewk, s16 order_index, s16 id, s16 master_player, s16 target_bg, s16 char_ix,
                    s16 char_ix2, s16 option);

/* Xbox: pulls the work and passes the rest to effect_66_setup. */
s32 effect_66_init(s16 order_index, s16 id, s16 master_player, s16 target_bg, s16 char_ix, s16 char_ix2, s16 option) {
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    return effect_66_setup((WORK_Other*)frw[ix], order_index, id, master_player, target_bg, char_ix, char_ix2, option);
}
