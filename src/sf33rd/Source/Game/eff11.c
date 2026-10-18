/* Effect 11, retail sf33rd.xbe.
 * quake_level_middle is 0x35151 size 0x14A and is interior.
 * quake_level_large is 0x3529B size 0x2B1 and is interior.
 * Its jump table is 0x35520 and is inside the size.
 * effect_11_init is 0x3554C size 0xFF. It follows that
 * jump table. make progress reports it as not code.
 * eff11_quake_sub is 0x3564B size 0x5F and is interior.
 * effect_11_move is 0x356AA size 0x73 and is interior.
 * 0x3510D stays unnamed. 0x3571D stays unnamed.
 *
 * Case 0 of the move stores disp_flag between the pushes
 * and the call. The middle and large routines store the
 * routine, and sometimes the low word, between the pushes
 * and the call. Case 2 of quake_level_large stores
 * old_rno[5] and d[0] after set_char_move_init. The init
 * stores sync_suzi and old_rno[1] before the row. It
 * stores the flags, my_family, my_col_mode, the character
 * table, old_rno[3], and old_rno[2] between the push and
 * suzi_offset_set. It stores my_mts between the push and
 * get_my_trans_mode. The pull failure jumps to the shared
 * epilogue. The C keeps the PlayStation 2 order. Case 0
 * of each quake function falls through.
 *
 * eff11_data_tbl is 0x24B688 and matches the 24 words.
 * eff11_quake_index_tbl is 0x24B6B8 and matches the 111
 * words. Two zero bytes at 0x24B796 pad it.
 * eff11_quake_speed_y_tbl is 0x24B798.
 * eff11_quake_speed_y_tbl2 is 0x24B7D8.
 * eff11_quake_speed_x_tbl is 0x24B7F8. All three match.
 * The rows were not pasted. The character table immediate
 * is 0x3015C0. Those bytes were not compared.
 * bg_w.quake_y_index is 0x7BC540. EXE_flag is 0xC7C834.
 * Game_pause is 0x7A89B0. EXE_obroll is 0x7A8111.
 * obr_no_disp_check and disp_pos_trans_entry_r are named.
 * get_my_trans_mode is named. char_move stays sub_0002008E.
 * set_char_move_init stays sub_000200A9.
 * set_char_move_init2 stays sub_000201B9.
 * add_x_sub stays sub_000EF072. add_y_sub stays sub_000EF088.
 * all_cgps_put_back stays sub_0004384A.
 * push_effect_work stays sub_0004AC6C.
 * pull_effect_work stays sub_0004A6A8.
 * suzi_offset_set stays sub_000B4052.
 * random_16 stays sub_0009326B.
 * cal_initial_speed stays sub_0001D280.
 * frw is 0xC806A0 and each object is 0x700 bytes.
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
} Reg32;

typedef struct {
    Reg32 a[2];
    Reg32 d[2];
} MVXY;

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[2];
    u8 type;
    u8 pad_wid;
    s16 work_id;
    s16 id;
    s8 rl_flag;
    u8 pad_rno[0x19];
    s16 routine_no[8];
    s16 old_rno[8];
    u8 pad_cg[4];
    s8 cgromtype;
    u8 pad_pos[0xF];
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_sync[6];
    s16 sync_suzi;
    u8 pad_mv[4];
    MVXY mvxy;
    u8 pad_ct[0x120];
    u32 *char_table[2];
    u8 pad_ci[0x54];
    s16 char_index;
    u8 pad_col[0x32];
    s16 my_col_mode;
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_mts[8];
    s16 my_mts;
    u8 pad_tm[6];
    s16 my_trans_mode;
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef struct {
    u8 raw[0x20];
    s16 quake_y_index;
} BG;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.low) == 0x64, "xlow");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.low) == 0x68, "ylow");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, sync_suzi) == 0x76, "sync_suzi");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[0].sp) == 0x7C, "a0");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[1].sp) == 0x80, "a1");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[0].sp) == 0x84, "d0");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[1].sp) == 0x88, "d1");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(__builtin_offsetof(BG, quake_y_index) == 0x20, "quake_y_index");
#endif

extern EffectRow frw[];
extern BG bg_w;
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;
extern const s16 eff11_data_tbl[24];
extern const s16 eff11_quake_index_tbl[111];
extern const s32 eff11_quake_speed_y_tbl[2][8];
extern const s32 eff11_quake_speed_y_tbl2[2][4];
extern const s32 eff11_quake_speed_x_tbl[2][8];
extern u32 _usa_char_table[];

s32 obr_no_disp_check(void);
void disp_pos_trans_entry_r(WORK_Other *ewk);
s16 get_my_trans_mode(s16 curr);
void sub_0002008E(WORK *wk);
void sub_000200A9(WORK *wk, s16 koc, s16 index);
void sub_000201B9(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void sub_000EF072(WORK_Other *ewk);
void sub_000EF088(WORK_Other *ewk);
void sub_0004384A(WORK *wk);
void sub_0004AC6C(WORK *wk);
s16 sub_0004A6A8(s16 kind);
void sub_000B4052(WORK_Other *ewk);
s16 sub_0009326B(void);
void sub_0001D280(WORK *wk, s16 t, s16 x, s16 y);

void eff11_quake_sub(WORK_Other *ewk);
void quake_level_middle(WORK_Other *ewk);
void quake_level_large(WORK_Other *ewk);

void effect_11_move(WORK_Other *ewk) {
    if (obr_no_disp_check() != 0) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && EXE_obroll == 0) {
            eff11_quake_sub(ewk);
        }

        disp_pos_trans_entry_r(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        sub_0004AC6C(&ewk->wu);
        break;
    }
}

void eff11_quake_sub(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (bg_w.quake_y_index > 1) {
            ewk->wu.routine_no[1]++;
            ewk->wu.old_rno[1] = eff11_quake_index_tbl[bg_w.quake_y_index];
        }

        break;

    case 1:
        if (ewk->wu.old_rno[1] > 4) {
            quake_level_large(ewk);
            break;
        }

        quake_level_middle(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[2] = 0;
        ewk->wu.old_rno[1] = 0;
        break;
    }
}

void quake_level_middle(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        sub_000200A9(&ewk->wu, 0, ewk->wu.old_rno[6] + 1);
        ewk->wu.mvxy.a[1].sp = eff11_quake_speed_y_tbl[ewk->wu.old_rno[3]][ewk->wu.old_rno[1]];
        ewk->wu.mvxy.d[1].sp = -0x6000;
        /* fallthrough */

    case 1:
    case 3:
    case 5:
        sub_0002008E(&ewk->wu);
        sub_000EF088(ewk);

        if (ewk->wu.mvxy.a[1].sp < 0) {
            ewk->wu.routine_no[2]++;
            sub_000201B9(&ewk->wu, 0, ewk->wu.old_rno[6] + 1, 13, 0);
            ewk->wu.old_rno[0] = 0;
        }

        break;

    case 2:
    case 4:
        sub_0002008E(&ewk->wu);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[2]++;
            sub_000200A9(&ewk->wu, 0, ewk->wu.old_rno[6] + 1);
            ewk->wu.mvxy.a[1].sp = eff11_quake_speed_y_tbl[ewk->wu.old_rno[3]][ewk->wu.old_rno[1]];
            ewk->wu.mvxy.a[1].sp >>= ewk->wu.routine_no[2];
            ewk->wu.old_rno[0]++;
            ewk->wu.old_rno[0] &= 3;
            ewk->wu.mvxy.a[1].sp = eff11_quake_speed_y_tbl2[ewk->wu.old_rno[3]][ewk->wu.old_rno[0]];
        }

        break;

    case 6:
        sub_0002008E(&ewk->wu);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[1] = 2;
            sub_000200A9(&ewk->wu, 0, ewk->wu.old_rno[6]);
        }

        break;
    }
}

void quake_level_large(WORK_Other *ewk) {
    s16 work;

    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        sub_000200A9(&ewk->wu, 0, ewk->wu.old_rno[6] + 1);
        ewk->wu.mvxy.a[1].sp = eff11_quake_speed_y_tbl[ewk->wu.old_rno[3]][ewk->wu.old_rno[1]];
        ewk->wu.mvxy.d[1].sp = -0x6000;
        ewk->wu.mvxy.a[0].sp = eff11_quake_speed_x_tbl[ewk->wu.old_rno[3]][ewk->wu.old_rno[1]];
        work = sub_0009326B();

        if ((work & 1) != 0) {
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        }
        /* fallthrough */

    case 1:
        sub_0002008E(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.mvxy.a[1].sp < 0) {
            ewk->wu.routine_no[2]++;
            sub_000201B9(&ewk->wu, 0, ewk->wu.old_rno[6] + 1, 13, 0);
            break;
        }

        break;

    case 2:
        sub_0002008E(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (!(ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2])) {
            break;
        }

        ewk->wu.routine_no[2]++;
        ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
        ewk->wu.xyz[1].disp.low = 0;
        sub_000200A9(&ewk->wu, 0, ewk->wu.old_rno[6] + 3);
        ewk->wu.old_rno[5] = 28;
        ewk->wu.mvxy.d[0].sp = 0;

        if (ewk->wu.old_rno[3] != 0) {
            ewk->wu.mvxy.d[1].sp = -0x6000;
        } else {
            ewk->wu.mvxy.d[1].sp = -0x8000;
        }

        sub_0001D280(&ewk->wu, ewk->wu.old_rno[5], ewk->wu.old_rno[4], ewk->wu.old_rno[2]);
        break;

    case 3:
        sub_0002008E(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);
        ewk->wu.old_rno[5]--;

        if (ewk->wu.mvxy.a[1].sp < 0) {
            ewk->wu.routine_no[2]++;
            sub_000201B9(&ewk->wu, 0, ewk->wu.old_rno[6] + 3, 7, 0);
        }

        break;

    case 4:
        sub_0002008E(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);
        ewk->wu.old_rno[5]--;

        if (ewk->wu.old_rno[5] <= 0) {
            ewk->wu.routine_no[2]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[4];
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            ewk->wu.xyz[1].disp.low = 0;
            sub_000200A9(&ewk->wu, 0, ewk->wu.old_rno[6] + 3);
            ewk->wu.old_rno[0] = 0;
            ewk->wu.mvxy.a[1].sp = eff11_quake_speed_y_tbl2[ewk->wu.old_rno[3]][ewk->wu.old_rno[0]];
            ewk->wu.mvxy.d[1].sp = -0x6000;
        }

        break;

    case 5:
    case 7:
    case 9:
        sub_0002008E(&ewk->wu);
        sub_000EF088(ewk);

        if (ewk->wu.mvxy.a[1].sp < 0) {
            ewk->wu.routine_no[2]++;
            sub_000201B9(&ewk->wu, 0, ewk->wu.old_rno[6] + 3, 7, 0);
        }

        break;

    case 6:
    case 8:
        sub_0002008E(&ewk->wu);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[2]++;
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            ewk->wu.xyz[1].disp.low = 0;
            sub_000200A9(&ewk->wu, 0, ewk->wu.old_rno[6] + 3);
            ewk->wu.old_rno[0]++;
            ewk->wu.old_rno[0] &= 3;
            ewk->wu.mvxy.a[1].sp = eff11_quake_speed_y_tbl2[ewk->wu.old_rno[3]][ewk->wu.old_rno[0]];
            ewk->wu.mvxy.d[1].sp = -0x6000;
        }

        break;

    case 10:
        sub_0002008E(&ewk->wu);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2]) {
            ewk->wu.routine_no[1] = 2;
            sub_000200A9(&ewk->wu, 0, ewk->wu.old_rno[6]);
        }

        break;
    }
}

s32 effect_11_init(void) {
    WORK_Other *ewk;
    s16 ix;
    s16 i;
    const s16 *data_ptr = eff11_data_tbl;

    for (i = 0; i < 4; i++) {
        if ((ix = sub_0004A6A8(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other *)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 11;
        ewk->wu.type = (u8)i;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.char_table[0] = _usa_char_table;
        ewk->wu.sync_suzi = 0;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.old_rno[3] = *data_ptr++;
        ewk->wu.old_rno[1] = 0;
        ewk->wu.old_rno[6] = ewk->wu.char_index;
        ewk->wu.old_rno[4] = ewk->wu.xyz[0].disp.pos;
        ewk->wu.old_rno[2] = ewk->wu.xyz[1].disp.pos;
        sub_000B4052(ewk);
        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    }

    return 0;
}
