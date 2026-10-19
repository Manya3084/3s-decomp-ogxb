/* Burst pieces, retail sf33rd.xbe.
 * effect_73_move is 0xB7EE5 size 0x13F and is interior.
 * effect_73_init is 0xB8024 size 0x121 and is a scanned start.
 * The EXE_obroll path is an early ret. The pull failure
 * jumps to the shared epilogue. 0xB7EC3 stays unnamed.
 *
 * eff73_sp_tbl is 0x284594 and matches the 4 rows.
 * eff73_vanish_tbl is 0x2845C4. eff73_survive_tbl is
 * 0x2845D4. Both match. The rows were not pasted.
 * The init stores sync_suzi before be_flag. The C keeps
 * the PlayStation 2 order. a[1].sp receives column 2 only.
 * The PlayStation 2 source stores column 1 and then
 * overwrites it. my_priority and position_z are split
 * around the survive test. The C keeps them together.
 * The character table immediate is 0x3041D0. Those bytes
 * were not compared. EXE_obroll is 0x7A8111. EXE_flag is
 * 0xC7C834. Game_pause is 0x7A89B0. Cases 1, 2, and 3
 * share the disp tail. The C keeps the three copies.
 * disp_pos_trans_entry_r is named. obr_no_disp_check is
 * named. char_move is 0x2008E. set_char_move_init
 * stays set_char_move_init. add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088. all_cgps_put_back stays
 * sub_0004384A. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. random_16 stays
 * random_16. suzi_offset_set is 0xB4052.
 * frw is 0xC806A0 and each object is 0x700 bytes.
 * 0xB6890 stays unnamed. 0xB61A0 is push_color_trans_req.
 */

#include "types.h"
#include "structs.h"

/* Retail addresses the code used as numbers. */
extern u32 _hkg_char_table[];






typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

#if defined(__i386__)
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(MVXY, a[1].sp) == 4, "a1");
_Static_assert(__builtin_offsetof(MVXY, d[0].sp) == 8, "d0");
_Static_assert(__builtin_offsetof(MVXY, d[1].sp) == 0xC, "d1");
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, sync_suzi) == 0x76, "sync_suzi");
_Static_assert(__builtin_offsetof(WORK, mvxy) == 0x7C, "mvxy");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
#endif

extern s8 EXE_obroll;
extern s16 EXE_flag;
extern u8 Game_pause;
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s32 eff73_sp_tbl[4][3] = {
    { 0x28000, -0x18000, -0x800 }, { 0x10000, 0x8000, 0x20000 }, { -0x4000, 0x0, 0x0 }, { -0x10000, 0x8000, 0x28000 }
};

const s16 eff73_vanish_tbl[8] = { 0x003C, 0x0018, 0x0026, 0x000E, 0x0016, 0x001C, 0x0012, 0x0028 };

const s16 eff73_survive_tbl[8] = { 0x0000, 0x0001, 0x0002, 0x0003, 0x0003, 0x0002, 0x0001, 0x0000 };

extern EffectRow frw[];

s32 obr_no_disp_check(void);
void disp_pos_trans_entry_r(WORK_Other *ewk);
void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sub_000EF072(WORK_Other *ewk);
void sub_000EF088(WORK_Other *ewk);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 random_16(void);
void suzi_offset_set(WORK_Other *ewk);

void effect_73_move(WORK_Other *ewk) {
    if (obr_no_disp_check() != 0) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 2);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            sub_000EF088(ewk);
            ewk->wu.old_rno[0] -= 1;

            if (ewk->wu.old_rno[0] < 0) {
                if (ewk->wu.old_rno[1] != 0) {
                    ewk->wu.routine_no[0] += 1;
                } else {
                    ewk->wu.routine_no[0] = 99;
                    ewk->wu.disp_flag = 0;
                }
            }
        }

        disp_pos_trans_entry_r(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            sub_000EF088(ewk);

            if (ewk->wu.xyz[1].disp.pos < 64) {
                ewk->wu.routine_no[0] += 1;
                ewk->wu.mvxy.a[0].sp = eff73_sp_tbl[ewk->wu.type][0];
                ewk->wu.mvxy.d[0].sp = 0;
                ewk->wu.mvxy.a[1].sp = 0x30000;
                ewk->wu.mvxy.d[1].sp = -0x4000;
            }
        }

        disp_pos_trans_entry_r(ewk);
        break;

    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            sub_000EF088(ewk);

            if (ewk->wu.xyz[1].disp.pos < 56) {
                ewk->wu.routine_no[0] = 99;
                ewk->wu.disp_flag = 0;
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

s32 effect_73_init(WORK_Other *oya) {
    WORK_Other *ewk;
    s16 ix;
    s16 i;
    s16 work;
    s16 work2;

    if (EXE_obroll != 0) {
        return 0;
    }

    work = random_16();
    work &= 7;

    for (i = 0; i < 4; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other *)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 73;
        ewk->wu.work_id = 16;
        ewk->my_master = (u32 *)oya;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.type = (u8)i;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.dead_f = 1;
        ewk->wu.my_family = 2;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = _hkg_char_table;
        ewk->wu.xyz[0].disp.pos = oya->wu.xyz[0].disp.pos;
        ewk->wu.xyz[1].disp.pos = (s16)(oya->wu.xyz[1].disp.pos + 64);
        ewk->wu.position_z = ewk->wu.my_priority = 80;
        ewk->wu.mvxy.a[0].sp = eff73_sp_tbl[i][0];
        ewk->wu.mvxy.a[1].sp = eff73_sp_tbl[i][2];
        ewk->wu.mvxy.d[1].sp = -0x4000;

        if (eff73_survive_tbl[work] == i) {
            ewk->wu.old_rno[1] = 1;
        } else {
            ewk->wu.old_rno[1] = 0;
        }

        work2 = random_16();
        work2 &= 7;
        ewk->wu.old_rno[0] = eff73_vanish_tbl[work2];
        suzi_offset_set(ewk);
    }

    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_73_draw(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 1:
    case 2:
    case 3:
        disp_pos_trans_entry_r(ewk);
        break;
    }
}
