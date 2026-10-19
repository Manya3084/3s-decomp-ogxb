/* Effect B3, retail sf33rd.xbe.
 * round_move_init is 0xBB5F6 size 0x67 and is interior.
 * round_move is 0xBB65D size 0xD0 and is interior.
 * fight_move is 0xBB72D size 0x9B and is interior.
 * fight_col_move is 0xBB7C8 size 0x1F and is interior.
 * fight_vanish is 0xBB7E7 size 0x6E and is interior.
 * effect_B3_init is 0xBB855 size 0xCD and is interior.
 * effect_B3_move is 0xBB922 size 0xC7 and is interior.
 * The pull failure is an early ret.
 * xb_effect_B3_draw is 0xBB4F0 size 0x106.
 *
 * xb_effect_B3_draw repeats the oya_adrs and routine sync of
 * effect_B3_move and then only the display paths of the
 * callees. The PlayStation 2 source has no such
 * function. round_move shares the set_char_move_init2
 * call of its two branches. fight_vanish case 0 stores
 * extra_col before my_col_code. The init stores
 * xyz[0].disp.pos before xyz[1].cal and tests type with
 * setne. The C keeps the PlayStation 2 order.
 * oya_adrs is 0x7AAC2C. rf_b2_flag is 0x7AAC30. bg_w is
 * 0x7BC520. The _etc_char_table immediate is 0x2F9850.
 * Those bytes were not compared. disp_pos_trans_entry5
 * stays disp_pos_trans_entry. char_move is 0x2008E.
 * set_char_move_init2 is 0x201B9. Sound_SE
 * stays BGM_Request. push_effect_work stays
 * push_effect_work. pull_effect_work is 0x4A6A8.
 * effect_B9_init and get_my_trans_mode are named. frw is 0xC806A0 and each
 * object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"

#include <stddef.h>






typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

#if defined(__i386__)
#endif

extern EffectRow frw[];
extern BG bg_w;
extern s16 rf_b2_flag;
extern u32 _etc_char_table[];

WORK_Other *oya_adrs = NULL;

void sub_000EF0C0(WORK_Other *ewk);
void char_move(WORK *wk);
void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void sub_00098407(s16 code);
s32 effect_B9_init(WORK_Other *oya);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

/* Xbox-only: the drawing half of effect_B3_move, called through the effect
 * draw table by xb_draw_effect_work. */
void xb_effect_B3_draw(WORK_Other *ewk) {
    oya_adrs = (WORK_Other *)ewk->my_master;

    if (ewk->wu.old_rno[1] != oya_adrs->wu.routine_no[0]) {
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[2] = 0;
    }

    ewk->wu.old_rno[1] = oya_adrs->wu.routine_no[0];

    switch (oya_adrs->wu.routine_no[0]) {
    case 2:
        switch (ewk->wu.routine_no[1]) {
        case 1:
            sub_000EF0C0(ewk);
            break;
        }

        break;

    case 3:
    case 5:
    case 6:
        ewk->wu.my_mr.size.x = oya_adrs->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_adrs->wu.my_mr.size.y;
        sub_000EF0C0(ewk);
        break;

    case 4:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.my_mr.size.x = 63;
            ewk->wu.my_mr.size.y = 0;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
            ewk->wu.xyz[1].disp.pos = 144;
            sub_000EF0C0(ewk);
            break;

        case 1:
            ewk->wu.my_mr.size.x = oya_adrs->wu.my_mr.size.x;
            ewk->wu.my_mr.size.y = oya_adrs->wu.my_mr.size.y;
            sub_000EF0C0(ewk);
            break;
        }

        break;

    case 7:
        ewk->wu.extra_col = oya_adrs->wu.extra_col;
        sub_000EF0C0(ewk);
        break;

    case 8:
        switch (ewk->wu.routine_no[1]) {
        case 1:
        case 2:
            sub_000EF0C0(ewk);
            break;
        }

        break;
    }
}

void round_move_init(WORK_Other *ewk);
void round_move(WORK_Other *ewk);
void fight_move(WORK_Other *ewk);
void fight_col_move(WORK_Other *ewk);
void fight_vanish(WORK_Other *ewk);

void round_move_init(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        set_char_move_init2(&ewk->wu, 0, 2, 1, 0);
        /* fallthrough */

    case 1:
        ewk->wu.my_mr.size.x = oya_adrs->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_adrs->wu.my_mr.size.y;
        sub_000EF0C0(ewk);
        break;
    }
}

void round_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;

        if (ewk->wu.hit_quake) {
            sub_00098407(138);
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
            ewk->wu.xyz[0].disp.pos -= 96;
            ewk->wu.xyz[1].disp.pos = 144;
            set_char_move_init2(&ewk->wu, 0, 2, 4, 0);
        } else {
            sub_00098407(oya_adrs->wu.dir_old);
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
            ewk->wu.xyz[0].disp.pos -= 32;
            set_char_move_init2(&ewk->wu, 0, 2, 2, 0);
        }

        /* fallthrough */

    case 1:
        ewk->wu.my_mr.size.x = oya_adrs->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_adrs->wu.my_mr.size.y;
        sub_000EF0C0(ewk);
        break;
    }
}

void fight_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        set_char_move_init2(&ewk->wu, 0, 2, 5, 0);
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 0;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
        ewk->wu.xyz[1].disp.pos = 144;
        sub_000EF0C0(ewk);
        break;

    case 1:
        ewk->wu.my_mr.size.x = oya_adrs->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_adrs->wu.my_mr.size.y;
        sub_000EF0C0(ewk);
        break;
    }
}

void fight_col_move(WORK_Other *ewk) {
    ewk->wu.extra_col = oya_adrs->wu.extra_col;
    sub_000EF0C0(ewk);
}

void fight_vanish(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        set_char_move_init2(&ewk->wu, 0, 4, 1, 0);
        sub_000EF0C0(ewk);
        ewk->wu.my_col_code = 0x52;
        ewk->wu.extra_col = 0;
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] += 1;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        rf_b2_flag = 1;
        sub_000EF0C0(ewk);
        break;
    }
}

s32 effect_B3_init(WORK_Other *oya) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x71;
    ewk->wu.work_id = 0x10;
    ewk->my_master = (u32 *)oya;
    ewk->wu.my_family = 4;
    ewk->wu.my_col_code = 0x52;
    ewk->wu.my_priority = ewk->wu.position_z = 10;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.xyz[1].cal = 0x780000;
    ewk->wu.xyz[0].disp.low = 0;
    *ewk->wu.char_table = _etc_char_table;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
    ewk->wu.xyz[1].disp.pos = 0x90;
    ewk->wu.old_rno[1] = 0;

    if (oya->wu.type) {
        ewk->wu.hit_quake = 1;
    } else {
        ewk->wu.hit_quake = 0;
    }

    effect_B9_init(oya);
    return 0;
}

void effect_B3_move(WORK_Other *ewk) {
    oya_adrs = (WORK_Other *)ewk->my_master;

    if (ewk->wu.old_rno[1] != oya_adrs->wu.routine_no[0]) {
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[2] = 0;
    }

    ewk->wu.old_rno[1] = oya_adrs->wu.routine_no[0];

    switch (oya_adrs->wu.routine_no[0]) {
    case 1:
        round_move_init(ewk);
        break;

    case 2:
        round_move(ewk);
        break;

    case 3:
    case 5:
    case 6:
        ewk->wu.my_mr.size.x = oya_adrs->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_adrs->wu.my_mr.size.y;
        sub_000EF0C0(ewk);
        break;

    case 4:
        fight_move(ewk);
        break;

    case 7:
        fight_col_move(ewk);
        break;

    case 8:
        fight_vanish(ewk);
        break;

    case 9:
    case 10:
    case 99:
        ewk->wu.disp_flag = 0;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
