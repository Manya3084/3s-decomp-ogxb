/* Eff81.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_81_move 0x55863 size 0x146.
 * effect_81_init 0x559A9 size 0xAF.
 * all_cgps_put_back is folded into 0x4384A.
 * Globals: _sel_pl_char_table 0x2FE100, Appear_Q 0x7A85C6, base_y_pos
 * 0x7BC516, bg_w 0x7BC520, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_0004384A(WORK* wk);
extern BG bg_w;
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
s32 Ck_Range_Out_S(WORK_Other* ewk, s16 BG_No, s16 R);
void push_effect_work(WORK* wkhd);
extern s16 base_y_pos;
s32 sort_push_request4(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
extern u8 Appear_Q;
s16 get_my_trans_mode(s16 curr);



/* Rewritten to match retail (tools/permute.py): set_char_move_init2 parameter 4: s16 -> s32; set_char_move_init2 parameter 3: s16 -> s32. */
void effect_81_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer) {
            return;
        }

        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.mvxy.a[0].sp = 0xE0000;
        ewk->wu.mvxy.d[0].sp = 0x10000;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos - 416;
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].xy[1].disp.pos - 24;
        ewk->wu.hit_quake = bg_w.bgw[1].xy[0].disp.pos - 16;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 39;
        }

        break;

    case 2:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
        }

        break;

    case 3:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, 240)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            return;
        }

        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos + base_y_pos + 0xFFFF;
    sort_push_request4(&ewk->wu);
}

s32 effect_81_init(s16 Time) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 81;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 8336;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 16;
    ewk->wu.dir_step = 7;
    ewk->wu.char_table[0] = (u32*)_sel_pl_char_table;
    ewk->wu.dir_timer = Time;
    ewk->wu.position_z = 8;
    Appear_Q = 1;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.my_mr_flag = 1;
    ewk->wu.my_mr.size.x = 127;
    ewk->wu.my_mr.size.y = 127;
    return 0;
}
