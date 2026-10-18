/* EFFA6.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * check2_A6_shortcut 0x43068 size 0x1F.
 * effect_A6_move 0x43087 size 0x270. Read against the x86: the unnamed words
 * at 0xCB87CE to 0xCB87D8 are the file's static position and timer words. The
 * C is the PS2 C.
 * wwwk_set 0x432F7 size 0x5A.
 * effect_A6_init 0x43351 size 0xBD.
 * Data: effa6_pos_x_1p: defined elsewhere on Xbox.
 * Data: effa6_pos_y_1p: defined elsewhere on Xbox.
 * Data: effa6_pos_z_1p: defined elsewhere on Xbox.
 * Data: effa6_pos_x_2p: defined elsewhere on Xbox.
 * Data: effa6_pos_y_2p: defined elsewhere on Xbox.
 * Data: mmes_already: defined elsewhere on Xbox.
 * Data: effA6_pl2_data_tbl is 0x24FE28, 0xA00 bytes compared.
 * Unnamed data used (not checked): effect_A6_move:
 * 0xcb87ce,0xcb87d0,0xcb87d2,0xcb87d4,0xcb87d6,0xcb87d8.
 * Globals: effA6_pl2_data_tbl 0x24FE28, Player_id 0x7A810F, My_char 0x7A8114,
 * Suicide 0x7A8268, Next_Step 0x7A86D2, bg_w 0x7BC520, p1sw_0 0x7C557C, p2sw_0
 * 0x7C5B90, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

extern s8 Player_id;
extern u16 p2sw_0;
extern u16 p1sw_0;
extern s8 Next_Step;
s32 Auto_Cut_Sub();
void get_message_conn_data(WORK_Other_CONN* ewk, s16 kind, s16 pl, s16 msg);
extern s8 Suicide[8];
extern BG bg_w;
s32 sort_push_request3(WORK* wk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
void wwwk_set(WORK_Other_CONN* ewk);
extern u8 My_char[2];

extern s16 effa6_pos_x_1p;

extern s16 effa6_pos_y_1p;

extern s16 effa6_pos_z_1p;

extern s16 effa6_pos_x_2p;

extern s16 effa6_pos_y_2p;

extern s16 mmes_already;

const s16 effA6_pl2_data_tbl[20][64] = {
    { 1, 210, 2, 210, 3, 210, 0, 630, 7, 210, 8, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 630, 4, 210, 5, 210, 6, 210, 0, 420, 0, -1,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 210, 2, 630, 0, -1,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 420, 3, 210, 4, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 210, 2, 420, 4, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 420, 3, 420, 0, -1,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 210, 2, 840, 6, 210, 0, -1,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 420, 3, 210, 4, 210, 5, 420, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 630, 4, 210, 5, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 210, 2, 210, 3, 630, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 210, 2, 420, 4, 210, 5, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 420, 3, 630, 0, -1,  0, 0,   0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 210, 2, 210, 3, 630, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 630, 4, 210, 5, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 420, 3, 210,  4, 210, 5, 210, 6, 420, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 210, 2, 1050, 7, 210, 0, -1,  0, 0,   0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 420, 3, 210, 4, 420, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 210, 2, 630, 5, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 210, 2, 630, 5, 210, 6, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 420, 3, 210, 4, 630, 0, -1,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 420, 3, 210, 4, 630, 0, -1,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 210, 2, 630, 5, 210, 6, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 210, 2, 630, 5, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 420, 3, 210, 4, 420, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 840, 5, 210, 6, 210, 0, -1,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 210, 2, 210, 3, 210, 4, 630, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 630, 4, 210, 5, 210, 6, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 210, 2, 210, 3, 840, 0, -1,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 210, 2, 210, 3, 1050, 0, -1,  0, 0,   0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 630, 4, 210, 5, 210,  6, 210, 7, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 210, 2, 210, 3, 630, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 630, 4, 210, 5, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 420, 3, 210, 4, 420, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 210, 2, 630, 5, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 420, 3, 210, 4, 210, 5, 630, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 210, 2, 840, 6, 210, 7, 210, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

s32 check2_A6_shortcut() {
    u16 sw_w;

    if (Player_id) {
        sw_w = p2sw_0;
    } else {
        sw_w = p1sw_0;
    }

    if (sw_w & 0x4000) {
        return 1;
    }

    return 0;
}

void effect_A6_move(WORK_Other_CONN* ewk) {
    WORK_Other* mwk;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (check2_A6_shortcut() != 0) {
            Next_Step |= ~0x7F;
        }

        if (Auto_Cut_Sub() != 0) {
            if (ewk->wu.routine_no[6] < 211) {
                ewk->wu.routine_no[6] = 1;
            } else if (ewk->wu.routine_no[6] < 421) {
                ewk->wu.routine_no[6] = 210;
            } else if (ewk->wu.routine_no[6] < 631) {
                ewk->wu.routine_no[6] = 420;
            } else if (ewk->wu.routine_no[6] < 841) {
                ewk->wu.routine_no[6] = 630;
            } else {
                ewk->wu.routine_no[6] = 840;
            }
        }

        ewk->wu.routine_no[6] = ewk->wu.routine_no[6] - 1;

        if (ewk->wu.routine_no[6] <= 0) {
            ewk->wu.routine_no[6] = effA6_pl2_data_tbl[ewk->master_player][ewk->wu.routine_no[5] + 1];

            if (ewk->wu.routine_no[6] < 0) {
                ewk->wu.routine_no[6] = -1;
                Next_Step |= ~0x7F;
            } else {
                if (!(mmes_already = effA6_pl2_data_tbl[ewk->master_player][ewk->wu.routine_no[5]])) {
                    ewk->wu.disp_flag = 0;
                    ewk->wu.routine_no[5] = ewk->wu.routine_no[5] + 2;
                } else {
                    ewk->wu.routine_no[5] = ewk->wu.routine_no[5] + 2;
                    get_message_conn_data(ewk, 1, ewk->master_player, mmes_already);
                    ewk->wu.disp_flag = 1;
                    ewk->wu.vitality = 0xF0;
                    ewk->wu.routine_no[1] = 0;
                }
            }
        }

        if (Suicide[3]) {
            ewk->wu.routine_no[0] = 1;
            break;
        }

        if (!ewk->wu.disp_flag) {
            break;
        }

        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;

            switch (ewk->wu.dir_old) {
            case 0x43:
                ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 384;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].xy[1].disp.pos + 186;
                break;

            default:
                ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 72;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].xy[1].disp.pos + 26;
                break;
            }

            /* fallthrough */

        case 1:
            switch (ewk->wu.dir_old) {
            case 0x43:
                ewk->wu.position_x += 10;

                if (ewk->wu.position_x >= bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 192) {
                    ewk->wu.routine_no[1]++;
                    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos =
                        bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 192;
                }

                break;

            default:
                ewk->wu.position_x -= 10;

                if (ewk->wu.position_x <= bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 120) {
                    ewk->wu.routine_no[1]++;
                    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos =
                        bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 120;
                }

                break;
            }

            break;

        case 2:
            break;
        }

        mwk = (WORK_Other*)ewk->my_master;

        switch (ewk->wu.dir_old) {
        case 0x43:
            ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = mwk->wu.position_z - 1;
            effa6_pos_x_1p = mwk->wu.position_x;
            effa6_pos_y_1p = mwk->wu.position_y;
            effa6_pos_z_1p = mwk->wu.position_z;
            break;

        default:
            ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = mwk->wu.position_z - 1;
            effa6_pos_x_2p = mwk->wu.position_x;
            effa6_pos_y_2p = mwk->wu.position_y;
            effa6_pos_y_2p = mwk->wu.position_y;
            break;
        }

        sort_push_request3(&ewk->wu);
        break;

    case 1:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        break;

    case 2:
        ewk->wu.routine_no[0]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_A6_init(WORK_Other* mwk) {
    WORK_Other_CONN* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN*)frw[ix];
    wwwk_set(ewk);
    ewk->wu.dir_old = mwk->wu.dir_old;
    ewk->wu.routine_no[6] = 60;
    ewk->master_player = My_char[Player_id];
    ewk->my_master = (u32*)mwk;

    switch (ewk->wu.dir_old) {
    case 0x43:
        if (!Player_id) {
            ewk->wu.routine_no[5] = 0;
        } else {
            ewk->wu.routine_no[5] = 32;
        }

        ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 64;
        break;

    default:

        if (Player_id) {
            ewk->wu.routine_no[5] = 0;
        } else {
            ewk->wu.routine_no[5] = 32;
        }

        ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 64;
        break;
    }

    return 0;
}

void wwwk_set(WORK_Other_CONN* ewk) {
    ewk->wu.be_flag = 1;
    ewk->wu.id = 106;
    ewk->wu.work_id = 16;
    ewk->wu.rl_flag = 0;
    ewk->wu.cgromtype = 1;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_mts = 12;
    ewk->wu.my_col_code = 55;
    ewk->wu.my_family = 1;
    ewk->wu.my_priority = 35;
    ewk->wu.position_y = 24;
    ewk->wu.position_z = 35;
}
