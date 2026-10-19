/* Effect 29, retail sf33rd.xbe.
 * effect_29_move is 0x3A2D8 size 0xBB.
 * effect_29_init is 0x3A393 size 0xB7.
 *
 * effect_29_move calls obr_no_disp_check before it saves any registers.
 * effect_29_init stores position_z before my_priority, and disp_flag
 * before old_rno[0]. The C keeps the PS2 order.
 * eff29_vanish_time is 0x24DDA4. _hkg_char_table is 0x3041D0.
 * EXE_obroll is 0x7A8111. Game_pause is 0x7A89B0. EXE_flag is 0xC7C834.
 * frw is 0xC806A0, 0x700 bytes per object. old_rno is +0x34.
 * my_priority is +0x240.
 * set_char_move_init is 0x200A9. char_move is 0x2008E.
 * all_cgps_put_back stays sub_0004384A. suzi_offset_set is 0xB4052.
 * obr_no_disp_check is 0xEF0A2. disp_pos_trans_entry_r is 0xEF0E5.
 * random_16 is 0x9326B. get_my_trans_mode is 0xEF70B.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 */

#include "types.h"
#include "structs.h"




typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, sync_suzi) == 0x76, "sync_suzi");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s16 eff29_vanish_time[8] = { 480, 600, 300, 240, 200, 340, 500, 360 };

extern u32 _hkg_char_table[];
extern u8 EXE_obroll;
extern u8 Game_pause;
extern u16 EXE_flag;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s32 curr);
s16 random_16(void);
s32 obr_no_disp_check(void);
void disp_pos_trans_entry_r(WORK_Other *ewk);
void set_char_move_init(WORK *wk, s16 koc, s32 index);
void char_move(WORK *wk);
void sub_0004384A(WORK *wk);
void suzi_offset_set(WORK_Other *wk);

void effect_29_move(WORK_Other *ewk) {
    s16 work;

    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 1;
                set_char_move_init(&ewk->wu, 0, 0);
                break;
            }
        }

        break;

    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[0] = 0;
                ewk->wu.disp_flag = 0;
                work = random_16();
                work &= 7;
                ewk->wu.old_rno[0] = eff29_vanish_time[work];
            }
        }

        disp_pos_trans_entry_r(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_29_init(void) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 29;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.dead_f = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 300;
    ewk->wu.my_mts = 7;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.xyz[0].disp.pos = 512;
    ewk->wu.xyz[1].disp.pos = 0;
    ewk->wu.my_priority = ewk->wu.position_z = 82;
    ewk->wu.char_index = 0;
    ewk->wu.sync_suzi = 0;
    ewk->wu.char_table[0] = _hkg_char_table;
    suzi_offset_set(ewk);
    ewk->wu.old_rno[0] = 120;
    ewk->wu.disp_flag = 0;
    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 range_x_check(WORK_Other* ewk);

void xb_effect_29_draw(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (obr_no_disp_check() == 0 && range_x_check(ewk)) {
            disp_pos_trans_entry_r(ewk);
        }

        break;
    }
}
