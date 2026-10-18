/* Rewritten to match retail (tools/permute.py): < 4 -> <= 3; < 3 -> <= 2. */
s32 effect_M2_init(WORK* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;

    if (data) {
        if (Win_Record[wk->id] <= 3) {
            return 0;
        }
    } else if (Win_Record[wk->id] <= 2) {
        return 0;
    }

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 222;
    ewk->wu.cgromtype = 1;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.type = data;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = _etc2_char_table;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 59;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
