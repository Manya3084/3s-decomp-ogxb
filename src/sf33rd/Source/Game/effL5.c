/* Effect L5, retail sf33rd.xbe.
 * hukuromoji_move is 0xB9665 size 0xF4 and is interior.
 * effect_L5_init is 0xB9759 size 0xA7 and is interior.
 * effect_L5_move is 0xB9800 size 0x61 and is interior.
 * The pull failure is an early ret.
 * 0xB962B stays unnamed. 0xB9861 stays unnamed.
 *
 * 0xB962B repeats the display cases of effect_L5_move.
 * It does not clear disp_flag in case 8 and does not
 * call hukuromoji_move. The PlayStation 2 source has no
 * such function. hukuromoji_move case 2 tests size.x
 * against 63. The init stores my_col_code after
 * xyz[0]. The C keeps the PlayStation 2 order. bg_w is
 * 0x7BC520. rf_b2_flag is 0x7AAC30. The _etc_char_table
 * immediate is 0x2F9850. Those bytes were not compared.
 * disp_pos_trans_entry5 stays disp_pos_trans_entry.
 * set_char_move_init2 is 0x201B9. Sound_SE stays
 * BGM_Request. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8.
 * get_my_trans_mode is named. frw is 0xC806A0 and each
 * object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"






typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, routine_no[1]) == 0x26, "rno1");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, dir_old) == 0x96, "dir_old");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_mr_flag) == 0x24E, "my_mr_flag");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.x) == 0x250, "mr.x");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.y) == 0x252, "mr.y");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(__builtin_offsetof(WORK, extra_col) == 0x342, "extra_col");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw[1].position_x) == 0xD2, "bgw position_x");
#endif

extern EffectRow frw[];
extern BG bg_w;
extern s16 rf_b2_flag;
extern u32 _etc_char_table[];

void sub_000EF0C0(WORK_Other *ewk);
void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void sub_00098407(s16 code);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void hukuromoji_move(WORK_Other *ewk);

void hukuromoji_move(WORK_Other *ewk) {
    WORK_Other *oya_ptr = (WORK_Other *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        set_char_move_init2(&ewk->wu, 0, 2, 6, 0);
        ewk->wu.hit_stop = 2;
        break;

    case 1:
        ewk->wu.hit_stop -= 1;

        if (ewk->wu.hit_stop < 0) {
            ewk->wu.routine_no[1] += 1;
            sub_00098407(oya_ptr->wu.dir_old + 1);
            return;
        }

        break;

    case 2:
        ewk->wu.my_mr.size.x -= 6;
        ewk->wu.my_mr.size.y -= 6;

        if (ewk->wu.my_mr.size.x <= 63) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.my_mr.size.x = 63;
            ewk->wu.my_mr.size.y = 63;
            ewk->wu.hit_stop = 4;
            set_char_move_init2(&ewk->wu, 0, 2, 7, 0);
            return;
        }

        break;

    case 3:
        ewk->wu.hit_stop -= 1;

        if (ewk->wu.hit_stop <= 0) {
            ewk->wu.routine_no[1] += 1;
            rf_b2_flag = 1;
        }

        break;

    case 4:
        break;
    }
}

s32 effect_L5_init(WORK_Other *oya) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xD7;
    ewk->wu.work_id = 0x10;
    ewk->my_master = (u32 *)oya;
    ewk->wu.my_family = 4;
    ewk->wu.my_mts = 0xE;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.my_col_code = 0x52;
    ewk->wu.my_priority = ewk->wu.position_z = 9;
    *ewk->wu.char_table = _etc_char_table;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
    ewk->wu.xyz[1].disp.pos = 0x90;
    return 0;
}

void effect_L5_move(WORK_Other *ewk) {
    WORK_Other *oya_ptr = (WORK_Other *)ewk->my_master;

    switch (oya_ptr->wu.routine_no[0]) {
    case 5:
    case 6:
        hukuromoji_move(ewk);
        sub_000EF0C0(ewk);
        break;

    case 7:
        ewk->wu.extra_col = oya_ptr->wu.extra_col;
        sub_000EF0C0(ewk);
        break;

    case 8:
        ewk->wu.disp_flag = 0;
        sub_000EF0C0(ewk);
        break;

    case 9:
    case 99:
        push_effect_work(&ewk->wu);
        break;
    }
}
