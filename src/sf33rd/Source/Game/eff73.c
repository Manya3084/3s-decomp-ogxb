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
 * named. char_move stays sub_0002008E. set_char_move_init
 * stays sub_000200A9. add_x_sub stays sub_000EF072.
 * add_y_sub stays sub_000EF088. all_cgps_put_back stays
 * sub_0004384A. push_effect_work stays sub_0004AC6C.
 * pull_effect_work stays sub_0004A6A8. random_16 stays
 * sub_0009326B. suzi_offset_set stays sub_000B4052.
 * frw is 0xC806A0 and each object is 0x700 bytes.
 * 0xB6890 stays unnamed. 0xB61A0 stays unnamed.
 */

#include "types.h"

typedef union {
    s32 cal;
    struct {
        s16 low;
        s16 pos;
    } disp;
} XY;

typedef union {
    s32 sp;
} Reg32SpReal;

typedef struct {
    Reg32SpReal a[2];
    Reg32SpReal d[2];
    s16 kop[2];
    u16 index;
} MVXY;

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[2];
    u8 type;
    u8 pad_work[1];
    s16 work_id;
    s16 id;
    s8 rl_flag;
    u8 pad_dead[0x15];
    s16 dead_f;
    u8 pad_rno[2];
    s16 routine_no[8];
    s16 old_rno[8];
    u8 pad_cg[4];
    s8 cgromtype;
    u8 pad_pos[0xB];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_sync[6];
    s16 sync_suzi;
    u8 pad_mv[4];
    MVXY mvxy;
    u8 pad_ct[0x1AC - 0x94];
    u32 *char_table[1];
    u8 pad_col[0x23C - 0x1B0];
    s16 my_col_mode;
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_end[0x388 - 0x244];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
} WORK_Other;

typedef u8 EffectRow[0x700];

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
extern const s32 eff73_sp_tbl[4][3];
extern const s16 eff73_vanish_tbl[8];
extern const s16 eff73_survive_tbl[8];
extern EffectRow frw[];

s32 obr_no_disp_check(void);
void disp_pos_trans_entry_r(WORK_Other *ewk);
void sub_0002008E(WORK *wk);
void sub_000200A9(WORK *wk, s16 koc, s16 index);
void sub_000EF072(WORK_Other *ewk);
void sub_000EF088(WORK_Other *ewk);
void sub_0004384A(WORK *wk);
void sub_0004AC6C(WORK *wk);
s16 sub_0004A6A8(s16 index);
s16 sub_0009326B(void);
void sub_000B4052(WORK_Other *ewk);

void effect_73_move(WORK_Other *ewk) {
    if (obr_no_disp_check() != 0) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 1;
        sub_000200A9(&ewk->wu, 0, 2);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);
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
            sub_0002008E(&ewk->wu);
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
            sub_0002008E(&ewk->wu);
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
        sub_0004AC6C(&ewk->wu);
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

    work = sub_0009326B();
    work &= 7;

    for (i = 0; i < 4; i++) {
        if ((ix = sub_0004A6A8(4)) == -1) {
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
        ewk->wu.char_table[0] = (u32 *)0x3041D0;
        ewk->wu.xyz[0].disp.pos = oya->wu.xyz[0].disp.pos;
        ewk->wu.xyz[1].disp.pos = (s16)(oya->wu.xyz[1].disp.pos + 64);
        ewk->wu.position_z = ewk->wu.my_priority = 80;
        ewk->wu.mvxy.a[0].sp = eff73_sp_tbl[i][0];
        ewk->wu.mvxy.a[1].sp = eff73_sp_tbl[i][2];
        ewk->wu.mvxy.d[1].sp = -0x4000;

        if (i == eff73_survive_tbl[work]) {
            ewk->wu.old_rno[1] = 1;
        } else {
            ewk->wu.old_rno[1] = 0;
        }

        work2 = sub_0009326B();
        work2 &= 7;
        ewk->wu.old_rno[0] = eff73_vanish_tbl[work2];
        sub_000B4052(ewk);
    }

    return 0;
}
