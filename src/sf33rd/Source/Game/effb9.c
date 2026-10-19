/* Effect B9, retail sf33rd.xbe.
 * effect_B9_move is 0xBBA33 size 0xA0 and is interior.
 * effect_B9_init is 0xBBAD3 size 0xF7 and is interior.
 * The pull failure is an early ret.
 * 0xBB9E9 stays unnamed. 0xBBBCA stays unnamed.
 *
 * 0xBB9E9 sets oya_p and repeats the display paths of
 * effect_B9_move for parent routines 3 and 4. The
 * PlayStation 2 source has no such function. The init
 * stores xyz[1] before the type test and shares the
 * xyz[0] store of both branches. The C keeps
 * the PlayStation 2 order. oya_p is 0x7AAC28. Round_num
 * is 0x7A8818. bg_w is 0x7BC520. The _etc_char_table
 * immediate is 0x2F9850. Those bytes were not compared.
 * disp_pos_trans_entry5 stays disp_pos_trans_entry.
 * set_char_move_init2 is 0x201B9.
 * push_effect_work is 0x4AC6C. pull_effect_work
 * stays pull_effect_work. get_my_trans_mode is named. frw
 * is 0xC806A0 and each object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"

#include <stddef.h>






typedef u8 EffectRow[0x700];

#if defined(__i386__)
#endif

extern EffectRow frw[];
extern BG bg_w;
extern u8 Round_num;
extern u32 _etc_char_table[];

WORK_Other *oya_p = NULL;

void sub_000EF0C0(WORK_Other *ewk);
void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effect_B9_move(WORK_Other *ewk) {
    oya_p = (WORK_Other *)ewk->my_master;

    switch (oya_p->wu.routine_no[0]) {
    case 2:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1] += 1;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
            ewk->wu.my_mr_flag = 1;
            /* fallthrough */

        case 1:
            ewk->wu.my_mr.size.x = oya_p->wu.my_mr.size.x;
            ewk->wu.my_mr.size.y = oya_p->wu.my_mr.size.y;
            sub_000EF0C0(ewk);
            break;
        }

        break;

    case 3:
        ewk->wu.my_mr.size.x = oya_p->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_p->wu.my_mr.size.y;
        sub_000EF0C0(ewk);
        break;

    case 4:
        ewk->wu.disp_flag = 0;
        sub_000EF0C0(ewk);
        break;

    case 5:
    case 99:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_B9_init(WORK_Other *oya) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x77;
    ewk->wu.work_id = 0x10;
    ewk->my_master = (u32 *)oya;
    ewk->wu.my_family = 4;
    ewk->wu.my_col_code = 0x52;
    ewk->wu.my_priority = ewk->wu.position_z = 10;
    *ewk->wu.char_table = _etc_char_table;
    ewk->wu.my_mts = 0xE;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);

    if (oya->wu.type) {
        ewk->wu.old_rno[0] = 2;
        ewk->wu.char_index = 2;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
        ewk->wu.xyz[0].disp.pos += 0x50;
        ewk->wu.xyz[1].disp.pos = 0x90;
    } else {
        ewk->wu.old_rno[0] = 3;
        ewk->wu.char_index = Round_num + 1;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
        ewk->wu.xyz[0].disp.pos += 0x70;
        ewk->wu.xyz[1].disp.pos = 0x90;
    }

    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_B9_draw(WORK_Other* ewk) {
    oya_p = (WORK_Other*)ewk->my_master;

    switch (oya_p->wu.routine_no[0]) {
    case 3:
        ewk->wu.my_mr.size.x = oya_p->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_p->wu.my_mr.size.y;
        sub_000EF0C0(ewk);
        break;

    case 4:
        ewk->wu.disp_flag = 0;
        sub_000EF0C0(ewk);
        break;
    }
}
