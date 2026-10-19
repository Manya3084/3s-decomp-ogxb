/* Winner piece, retail sf33rd.xbe.
 * effect_20_move is 0xB7006 size 0xC0 and is interior.
 * effect_20_init is 0xB70C6 size 0xD1 and is interior.
 * 0xB7197 is eff35_0000.
 *
 * The init does not store my_priority = 0x40. The later store
 * of 16 is the only priority write. The character table
 * immediate is 0x2F77F0. Those bytes were not compared.
 * Winner_id is 0x7A8472. plw is 0xC7CEA0, stride 0x46C, and
 * rl_flag is +0xA. my_master is +0x388. master_id is +0x38E.
 * cg_type is +0x214. old_rno is +0x34.
 * char_move is 0x2008E. set_char_move_init stays
 * set_char_move_init. sort_push_request4 is 0x9E092.
 * all_cgps_put_back stays sub_0004384A. push_effect_work
 * stays push_effect_work. pull_effect_work is 0x4A6A8.
 * frw is 0xC806A0 and each object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"

/* Retail addresses the code used as numbers. */
extern u32 _etc2_char_table[];


typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

#if defined(__i386__)
#endif

extern EffectRow frw[];
extern s8 Winner_id;
extern PLW plw[2];

void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sort_push_request4(WORK *wk);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effect_20_move(WORK_Other *ewk) {
    WORK_Other *oya = (WORK_Other *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        oya->wu.old_rno[0] = 0;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            oya->wu.old_rno[0] = 1;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request4(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_20_init(WORK_Other *oya) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->my_master = (u32 *)oya;
    ewk->master_id = oya->wu.id;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 20;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = plw[Winner_id].wu.rl_flag;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = _etc2_char_table;
    ewk->wu.my_family = 8;
    ewk->wu.my_col_code = 0x38;
    ewk->wu.xyz[0].disp.pos = 192;
    ewk->wu.xyz[1].disp.pos = 24;
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    ewk->wu.my_priority = ewk->wu.position_z = 16;
    ewk->wu.char_index = 49;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
