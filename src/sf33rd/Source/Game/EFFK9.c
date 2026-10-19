/* Effect K9, retail sf33rd.xbe.
 * effect_K9_move is 0x50F45 size 0xE2.
 * effect_K9_init is 0x51027 size 0x90.
 *
 * effect_K9_init stores type before my_master and be_flag. The C keeps the
 * PlayStation 2 order. The character table immediate is 0x308B40
 * (_plef_char_table). Those bytes were not compared.
 * dead_f is +0x20. dir_old is +0x96. dir_step is +0x98. now_koc is +0x206.
 * char_index is +0x208. cg_type is +0x214. my_mr_flag is +0x24E and
 * my_mr.size +0x250. EXE_flag is 0xC7C834. Game_pause is 0x7A89B0.
 * base_y_pos is 0x7BC516. push_color_trans_req is 0xB61A0.
 * set_char_move_init is 0x200A9. char_move is 0x2008E.
 * sort_push_request is 0x9DF9A. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. frw is 0xC806A0, 0x700 bytes per object.
 */

#include "types.h"
#include "structs.h"



typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

#if defined(__i386__)
#endif

extern s16 EXE_flag;
extern u8 Game_pause;
extern s16 base_y_pos;
extern u32 _plef_char_table[];
extern EffectRow frw[];

void push_color_trans_req(s32 id, s32 code);
void set_char_move_init(WORK *wk, s16 koc, s32 index);
void char_move(WORK *wk);
void sort_push_request(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

void effect_K9_move(WORK_Other *ewk) {
    WORK *mwk = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        push_color_trans_req(0x36, 10);
        ewk->wu.my_col_code = 10;
        ewk->wu.my_priority = ewk->wu.position_z = 32;
        ewk->wu.my_clear_level = 0xA0;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 112;
        set_char_move_init(&ewk->wu, 0, 0x90);
        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 0) {
            if (EXE_flag != 0 || Game_pause != 0 ||
                (ewk->wu.dir_old == mwk->now_koc && ewk->wu.dir_step == mwk->char_index &&
                 (char_move(&ewk->wu), ewk->wu.cg_type != 0xFF))) {
                sort_push_request(&ewk->wu);
                return;
            }
        }

        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = 2;
        return;

    default:
    case 2:
        push_effect_work(&ewk->wu);
        return;
    }
}

s32 effect_K9_init(WORK *wk, u8 data) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(5)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->my_master = (u32 *)wk;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 209;
    ewk->wu.type = data;
    ewk->wu.work_id = 16;
    ewk->wu.my_mts = 6;
    ewk->wu.my_family = 8;
    ewk->wu.position_x = 192;
    ewk->wu.position_y = 112 - base_y_pos;
    ewk->wu.dir_old = wk->now_koc;
    ewk->wu.dir_step = wk->char_index;
    *ewk->wu.char_table = _plef_char_table;
    return 0;
}
