/* EFFJ9.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effJ9_trans 0x4F0F4 size 0x18.
 * effect_J9_move 0x4F1B3 size 0xF4.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: get_c2_quake,
 * effect_J9_init.
 * get_c2_quake has no XBE name and no aligned call.
 * Data: c2quake_table: not located in the XBE, PS2 initializer kept.
 */

#include "structs.h"

void set_char_base_data(WORK* wk);
s32 effect_00_init(WORK* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
s16 get_c2_quake(WORK* c2wk);
void player_hosei_data(); /* called with 2 arguments here, as on Xbox */
void effJ9_trans(WORK* wk);
void push_effect_work(WORK* wkhd);
s32 sort_push_request(WORK* wk);

const s16 c2quake_table[19] = { 0, 3, 3, 2, 2, 1, 1, 1, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, 0 };

void effect_J9_move(WORK_Other* ewk) {
    WORK* c2wk = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.charset_id = 17;
        set_char_base_data(&ewk->wu);
        ewk->wu.my_col_mode = 0x4400;
        ewk->wu.my_col_code = 0x21FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.position_z = ewk->wu.my_priority = 68;
        effect_00_init(&ewk->wu);
        ewk->wu.next_x = 0;
        break;

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, 0x44);
            break;

        case 1:
            ewk->wu.next_x = get_c2_quake(c2wk);

            if (c2wk->char_index == 0x47) {
                ewk->wu.next_x = 0;
                ewk->wu.routine_no[1]++;
                set_char_move_init(&ewk->wu, 0, 0x45);
            }

            break;

        default:
            ewk->wu.xyz[0].disp.pos = c2wk->xyz[0].disp.pos;
            break;
        }

        player_hosei_data(ewk, c2wk->dir_timer);
        effJ9_trans(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effJ9_trans(WORK* wk) {
    wk->position_x = wk->xyz[0].disp.pos + wk->next_x;
    sort_push_request(wk);
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

s16 get_c2_quake(WORK* c2wk) {
    u16 c2cg;

    if ((c2cg = c2wk->cg_number) > 18) {
        return 0;
    }

    return c2quake_table[c2cg];
}

s32 effect_J9_init(WORK_Other* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 199;
    ewk->wu.work_id = 16;
    ewk->wu.type = data;
    ewk->wu.my_mts = 14;
    ewk->my_master = (u32*)wk;
    ewk->master_player = wk->master_player;
    ewk->master_id = wk->master_id;
    ewk->master_work_id = wk->master_work_id;
    ewk->wu.xyz[0].disp.pos = wk->wu.xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = wk->wu.xyz[1].disp.pos;
    return 0;
}
#endif
