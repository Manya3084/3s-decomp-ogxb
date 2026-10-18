/* EFF15.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * eff15_koishi 0x37BA8 size 0x12D.
 * effect_15_init 0x37CD5 size 0xCD.
 * effect_15_move 0x37DA2 size 0x19.
 * eff15_kemuri is folded into 0x4384A with 48 other bodies. Unnamed.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * all_cgps_put_back is folded into 0x4384A.
 * eff15_kemuri is folded into 0x4384A.
 * Globals: _etc2_char_table 0x2F77F0, Game_pause 0x7A89B0, EXE_flag 0xC7C834,
 * frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000EF072(WORK_Other* ewk);
void sub_000EF088(WORK_Other* ewk);
void sub_0004384A();
void eff15_koishi(WORK_Other* ewk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s16 EXE_flag;
extern u8 Game_pause;
void char_move(WORK* wk);
void suzi_sync_pos_set(WORK_Other* ewk);
s32 sort_push_request(WORK* wk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _etc2_char_table[];
void suzi_offset_set(WORK_Other* ewk);
s16 get_my_trans_mode(s16 curr);



void effect_15_move(WORK_Other* ewk) {
    if (ewk->wu.type) {
        eff15_koishi(ewk);
    } else {
        sub_0004384A(ewk);
    }
}

void eff15_kemuri(WORK_Other* ewk) {
    WORK* oya_ptr;

    (void)ewk;
    (void)oya_ptr;
}

void eff15_koishi(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);

        if (ewk->wu.type == 1) {
            ewk->wu.mvxy.a[0].sp = 0x8000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = -0x28000;
            ewk->wu.mvxy.d[1].sp = -0x6000;
            ewk->wu.xyz[0].disp.pos = 640;
            ewk->wu.old_rno[2] = 64;
            break;
        }

        ewk->wu.mvxy.a[0].sp = -0x8000;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.a[1].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x4000;
        ewk->wu.xyz[0].disp.pos = 576;
        ewk->wu.old_rno[2] = 72;
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            sub_000EF088(ewk);

            if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2]) {
                ewk->wu.routine_no[0]++;
                set_char_move_init(&ewk->wu, 0, 41);
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 0;
            }
        }

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

s32 effect_15_init(WORK* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xF;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.type = data;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2020;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = 0;
    ewk->wu.xyz[0].disp.pos = 629;
    ewk->wu.xyz[1].disp.pos = 340;
    ewk->wu.my_priority = 76;
    ewk->wu.position_z = 76;
    ewk->wu.char_table[0] = _etc2_char_table;

    if (data) {
        ewk->wu.char_index = 40;
    } else {
        ewk->wu.char_index = 39;
    }

    ewk->wu.sync_suzi = 0;
    suzi_offset_set(ewk);
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
