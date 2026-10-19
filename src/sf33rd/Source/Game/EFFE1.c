/* Effect E1, retail sf33rd.xbe.
 * effect_E1_move is 0x48EB1 size 0x5D.
 * effect_E1_init is 0x48F0E size 0xBB.
 *
 * The move's & 0xFFFF on the positions is a plain word move. The init
 * stores dir_timer first and shares the xyz stores after the switch. Case 1
 * stores position_z and my_priority before char_index. The C keeps the
 * PlayStation 2 order. The character table immediate is 0x2F9850
 * (_etc_char_table). Those bytes were not compared.
 * dir_timer is +0x9A. cgromtype is +0x48. char_index is +0x208.
 * my_mr.size is +0x250. frw is 0xC806A0 and each object is 0x700 bytes.
 * set_char_move_init is 0x200A9. pull_effect_work is 0x4A6A8.
 * sort_push_request4 is 0x9E092.
 */

#include "types.h"
#include "structs.h"




typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

#if defined(__i386__)
#endif

extern u32 _etc_char_table[];
extern EffectRow frw[];

s16 pull_effect_work(s16 index);
void sort_push_request4(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s32 index);

void effect_E1_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        /* fallthrough */

    case 1:
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        break;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}

s32 effect_E1_init(s16 id, s16 Time, s16 unused) {
    WORK_Other *ewk;
    s16 ix;

    (void)unused;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x8D;
    ewk->wu.work_id = 0x10;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 1;
    ewk->wu.dir_timer = Time;
    ewk->wu.char_table[0] = _etc_char_table;
    ewk->wu.my_mr.size.x = 0x3F;
    ewk->wu.my_mr.size.y = 0x3F;

    switch (id) {
    case 0:
        ewk->wu.char_index = 0x59;
        ewk->wu.xyz[0].disp.pos = 0x200;
        ewk->wu.xyz[1].disp.pos = 0x90;
        ewk->wu.my_priority = ewk->wu.position_z = 0x45;
        break;

    case 1:
        ewk->wu.my_priority = ewk->wu.position_z = 0x44;
        ewk->wu.xyz[0].disp.pos = 0x200;
        ewk->wu.xyz[1].disp.pos = 0x90;
        ewk->wu.char_index = 0x5A;
        break;
    }

    return 0;
}
