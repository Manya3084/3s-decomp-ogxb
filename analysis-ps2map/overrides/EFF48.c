/* Located by their bytes (tools/locate_data.py): eff48_data_tbl01 is
 * 0x24E548. eff48_data_tbl02 is 0x24E618. eff48_data_tbl03 is 0x24E658.
 * eff48_data_tbl04 is 0x24E6C8. eff48_data_tbl05 is 0x24E758.
 * eff48_data_tbl06 is 0x24E798. eff48_data_tbl07 is 0x24E808.
 * eff48_data_tbl08 is 0x24E8A8. eff48_data_tbl09 is 0x24E908.
 * eff48_data_tbl10 is 0x24E948. eff48_data_tbl11 is 0x24E9A8.
 * eff48_data_tbl12 is 0x24E9F8. eff48_data_tbl13 is 0x24EB28.
 * eff48_data_tbl14 is 0x24EB68. eff48_data_tbl15 is 0x24EBB8.
 * eff48_data_tbl16 is 0x24EC98. eff48_data_tbl17 is 0x24ED48.
 * eff48_data_tbl18 is 0x24EDE8. eff48_data_tbl19 is 0x24EE18.
 * eff48_data_tbl20 is 0x24EE58. eff48_data_tbl21 is 0x24EEF8. */

/* The Xbox has no Debug_w test. */
s32 effect_48_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr;

    data_ptr = eff48_adrs_tbl[type];

    for (i = 0; i < eff48_num_tbl[type]; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 0x30;
        ewk->wu.work_id = 0x10;
        ewk->wu.type = type;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x12C;
        ewk->wu.my_family = 3;
        ewk->wu.my_mts = 9;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
        ewk->wu.old_rno[4] = i;
        ewk->wu.char_table[0] = _op_char_table;
        ewk->wu.routine_no[0] = *data_ptr++;
        ewk->wu.old_rno[2] = *data_ptr++;

        if (ewk->wu.routine_no[0] == 2) {
            ewk->wu.my_col_code += ewk->wu.old_rno[2];
        }

        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.old_rno[1] = *data_ptr++;

        if (ewk->wu.old_rno[0] == 2) {
            COLOR_COPYn(0x10, ((ewk->wu.my_col_code & 0x1FF) + 0x38) * 4, 4);
            ewk->wu.my_col_code = 4;
        } else {
            COLOR_COPYn(0x30, ((ewk->wu.my_col_code & 0x1FF) + 8) * 4, 4);
            ewk->wu.my_col_code = 12;
        }
    }

    return 0;
}
