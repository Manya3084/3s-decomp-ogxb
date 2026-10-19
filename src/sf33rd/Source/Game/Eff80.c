/* Effect 80, retail sf33rd.xbe.
 * effect_80_move is 0x556B2 size 0xD3.
 * effect_80_init is 0x55785 size 0xB8.
 *
 * In case 1 of effect_80_move, routine_no[0] is incremented before
 * disp_flag is cleared. In case 0, disp_flag is set to 1 before the call.
 * The position copies store xyz[n].disp.pos first and position_* second.
 * effect_80_init stores my_family first. It computes dir_step as
 * (PL_id * 20 + My_char[PL_id]) * 3 + Plate_id, which is the PS2 sum
 * regrouped. The C keeps the PS2 order.
 * Disp_Command_Name is 0x7A8528, 3 bytes per player. My_char is 0x7A8114.
 * _sel_pl_char_table is 0x2FE100. frw is 0xC806A0, 0x700 bytes per object.
 * Ck_Range_Out_S is 0xB3EA7. set_char_move_init2 is 0x201B9.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 * sort_push_request4 is 0x9E092. get_my_trans_mode is 0xEF70B.
 */

#include "types.h"
#include "structs.h"




typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[2].disp.pos) == 0x6E, "xyz2");
_Static_assert(__builtin_offsetof(WORK, dir_step) == 0x98, "dir_step");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
_Static_assert(__builtin_offsetof(WORK_Other, master_player) == 0x390, "player");
#endif

extern s8 Disp_Command_Name[2][3];
extern u8 My_char[2];
extern u32 _sel_pl_char_table[];
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void sort_push_request4(WORK *wk);
s16 get_my_trans_mode(s32 curr);
s32 Ck_Range_Out_S(WORK_Other *ewk, s16 type, s16 range);
void set_char_move_init2(WORK *wk, s32 koc, s32 index, s32 ip, s32 scf);

void effect_80_move(WORK_Other *ewk) {
    WORK_Other *mwk = (WORK_Other *)ewk->my_master;

    if (mwk->wu.be_flag == 0) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = 3;
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    case 1:
        if (Ck_Range_Out_S(ewk, 2, 96)) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            return;
        }

        break;

    case 2:
        ewk->wu.routine_no[0] = 99;
        return;

    default:
        push_effect_work(&ewk->wu);
        return;
    }

    ewk->wu.disp_flag = Disp_Command_Name[ewk->master_id][ewk->master_player];
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = mwk->wu.position_x;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = mwk->wu.position_y;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = mwk->wu.position_z - 1;
    sort_push_request4(&ewk->wu);
}

s32 effect_80_init(WORK_Other *mwk, s16 PL_id, s16 Plate_id, s16 Target_BG) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 80;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x90;
    ewk->wu.my_family = Target_BG + 1;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->master_player = Plate_id;
    ewk->my_master = (u32 *)mwk;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.char_index = 7;
    ewk->wu.dir_step = Plate_id + (My_char[PL_id] * 3) + (PL_id * 60);
    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_80_draw(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = mwk->position_x;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = mwk->position_y;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = mwk->position_z - 1;
    sort_push_request4(&ewk->wu);
}
