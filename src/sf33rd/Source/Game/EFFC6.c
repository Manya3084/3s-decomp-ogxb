/* EFFC6.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * xb_effect_C6_draw 0x46A0B size 0x19. FLAG: x86-only callees
 * sort_push_request.
 * effect_C6_move 0x46A24 size 0xEE.
 * effect_C6_init 0x46B12 size 0xBF.
 * all_cgps_put_back is folded into 0x4384A.
 * Globals: _etc_char_table 0x2F9850, Game_pause 0x7A89B0, EXE_flag 0xC7C834,
 * plw 0xC7CEA0, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_0004384A(WORK* wk);
s32 sort_push_request(WORK* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s16 EXE_flag;
extern u8 Game_pause;
extern PLW plw[2];
void char_move(WORK* wk);
void suzi_sync_pos_set(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _etc_char_table[];
s16 get_my_trans_mode(s16 curr);
void suzi_offset_set(WORK_Other* ewk);



void effect_C6_move(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 10);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            if (oya->wu.routine_no[0] >= 2) {
                ewk->wu.routine_no[0]++;

                if (plw[oya->master_id ^ 1].player_number == 16) {
                    set_char_move_init(&ewk->wu, 0, 19);
                } else {
                    set_char_move_init(&ewk->wu, 0, 11);
                }
            } else {
                char_move(&ewk->wu);
            }
        }

        ewk->wu.xyz[0].cal = oya->wu.xyz[0].cal;
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 1) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 0;
            }
        }

        ewk->wu.xyz[0].cal = oya->wu.xyz[0].cal;
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 3:
        ewk->wu.routine_no[0]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_C6_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 126;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.disp_flag = 0;
    ewk->my_master = (u32*)oya;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 10;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_priority = ewk->wu.position_z = oya->wu.my_priority - 1;
    ewk->wu.xyz[0].cal = oya->wu.xyz[0].cal;
    ewk->wu.xyz[1].cal = oya->wu.xyz[1].cal;
    ewk->wu.rl_flag = oya->wu.rl_flag;
    *ewk->wu.char_table = _etc_char_table;
    ewk->wu.my_col_code = oya->wu.my_col_code;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    suzi_offset_set(ewk);
    return 0;
}

void xb_effect_C6_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
    case 2:
        sort_push_request(&ewk->wu);
        break;
    }
}
