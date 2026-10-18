/* EFF70.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_70_move 0x40834 size 0x18D. Read against the x86: Sel_PL_Complete[n]
 * & 0x8000 is tested as the high byte & 0x80. The C is the PS2 C.
 * Setup_Eff70 0x409C1 size 0x53.
 * effect_70_init 0x40A14 size 0x97.
 * Globals: Face_Pos_Data 0x26765A, _sel_pl_char_table 0x2FE100, Play_Type
 * 0x7A812D, Present_Mode 0x7A819C, Sel_PL_Complete 0x7A81BC, Suicide 0x7A8268,
 * Complete_Face 0x7A847C, permission_player 0x7C5860, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

extern s8 Suicide[8];
void set_char_move_init(WORK* wk, s16 koc, s16 index);
s32 sort_push_request4(WORK* wk);
void char_move(WORK* wk);
extern s8 Complete_Face;
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
extern u8 Play_Type;
extern s16 Sel_PL_Complete[2];
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
void Setup_Eff70(WORK_Other* ewk);
extern const s16 Face_Pos_Data[20][2];
extern Permission permission_player[6];
extern u8 Present_Mode;
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);



void effect_70_move(WORK_Other* ewk) {
    if (Suicide[0] == 1) {
        ewk->wu.routine_no[0] = 99;
        ewk->wu.disp_flag = 0;
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            sort_push_request4(&ewk->wu);
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            Complete_Face--;
            ewk->wu.routine_no[0]++;
            ewk->wu.char_index = 0;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }

        sort_push_request4(&ewk->wu);
        /* fallthrough */

    case 2:
        if (Play_Type == 1 && Sel_PL_Complete[0] & 0x8000 && Sel_PL_Complete[1] & 0x8000) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 30;
        }

        sort_push_request4(&ewk->wu);
        break;

    case 3:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.my_mr_flag = 1;
            ewk->wu.my_mr.size.x = 63;
            ewk->wu.my_mr.size.y = 63;
            ewk->wu.mvxy.a[0].sp = 0x80000;
        }

        sort_push_request4(&ewk->wu);
        break;

    case 4:
        if ((ewk->wu.my_mr.size.x -= ewk->wu.mvxy.a[0].real.h) <= 0) {
            ewk->wu.my_mr.size.x = 0;
        }

        if ((ewk->wu.my_mr.size.y -= ewk->wu.mvxy.a[0].real.h) <= 0) {
            ewk->wu.my_mr.size.y = 0;
        }

        if (ewk->wu.my_mr.size.x <= 0 && ewk->wu.my_mr.size.y <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr_flag = 0;
            ewk->wu.disp_flag = 0;
            break;
        }

        sort_push_request4(&ewk->wu);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_70_init(s16 id) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    Setup_Eff70(ewk);
    ewk->wu.xyz[0].disp.pos = Face_Pos_Data[id][0] + 512;
    ewk->wu.xyz[1].disp.pos = Face_Pos_Data[id][1] + 0;
    ewk->wu.position_z = 62;
    ewk->wu.dir_step = id;
    ewk->wu.dir_timer = 10;

    if (permission_player[Present_Mode].ok[id] == 0) {
        ewk->wu.my_bright_type = 1;
        ewk->wu.my_bright_level = 7;
        ewk->wu.my_clear_level = 80;
    }

    return 0;
}

void Setup_Eff70(WORK_Other* ewk) {
    ewk->wu.be_flag = 1;
    ewk->wu.id = 70;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x2090;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 13;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
}
