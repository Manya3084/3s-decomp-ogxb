/* Rewritten to match retail (tools/permute.py): <= 0 -> < 1. */
void get_attdata_of_illusion(WORK_Other* ewk) {
    ewk->wu.cg_hit_ix = zanzou_table[ewk->master_id][ewk->wu.type].hit_ix;
    ewk->wu.cg_att_ix = zanzou_table[ewk->master_id][ewk->wu.type].renew;
    ewk->wu.xyz[0].disp.pos = ewk->wu.position_x;
    ewk->wu.xyz[1].disp.pos = ewk->wu.position_y;
    ewk->wu.xyz[2].disp.pos = ewk->wu.position_z;
    get_char_data_zanzou(&ewk->wu);
    ewk->wu.att.guard = 0x3F;
    ewk->wu.att.dipsw = 1;
    ewk->wu.kezuri_pow = 0;
    ewk->wu.at_attribute = 0;
    ewk->wu.att.pow /= 4;

    if (ewk->wu.att.pow < 1) {
        ewk->wu.att.pow = 1;
    }

    ewk->wu.att.piyo = 0;
    ewk->wu.att.hs_you = 0;
    ewk->wu.add_arts_point = 0;
    ewk->wu.kind_of_waza = zanzou_table[ewk->master_id][ewk->wu.type].kowaza;
    ewk->wu.at_koa = acatkoa_table[ewk->wu.kind_of_waza];

    if (ewk->wu.cg_hit_ix) {
        hit_push_request(&ewk->wu);
    }
}
