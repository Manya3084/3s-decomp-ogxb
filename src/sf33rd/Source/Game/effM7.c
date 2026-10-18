/* Effect M7, retail sf33rd.xbe.
 * effm7_move is 0xBA9DA size 0x172 and is interior.
 * effect_M7_init is 0xBAB4C size 0x15A.
 * effect_M7_move is 0xBACA6 size 0x3D and is interior.
 * The pull failure jumps to the shared epilogue.
 * 0xBA8FD stays unnamed. 0xBACE3 stays unnamed.
 *
 * 0xBA8FD runs when routine_no[0] is 0 and the game is
 * not paused. It repeats the effm7_move position and
 * speed stores of cases 0, 3, and 4 without the routine
 * increments or char_move, then calls
 * pl_eff_trans_entry. The PlayStation 2 source has no
 * such function. effm7_move case 4 stores mvxy.a[0]
 * last. Case 5 stores routine_no[1] before
 * routine_no[0]. The init stores my_priority, the
 * char_table entries, and kage_flag after the table
 * reads. The C keeps the PlayStation 2 order.
 * effm7_data_tbl is 0x284820 and matches the
 * PlayStation 2 values. plw is 0xC7CEA0, stride 0x46C.
 * EXE_flag is 0xC7C834. Game_pause is 0x7A89B0. The
 * _etc_char_table immediate is 0x2F9850. Those bytes
 * were not compared. char_move is 0x2008E.
 * set_char_move_init is 0x200A9. add_x_sub
 * stays add_x_sub. add_y_sub is folded into 0xEF088.
 * all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C. pull_effect_work
 * stays pull_effect_work. range_x_check3,
 * pl_eff_trans_entry, and get_my_trans_mode are named.
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
    u8 kage_flag;
    s16 kage_hx;
    s16 kage_hy;
    s16 kage_prio;
    s16 kage_width;
    s16 kage_char;
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
    u32 *char_table[2];
    u8 pad_ci[0x208 - 0x1B4];
    s16 char_index;
    u8 pad_cg_type[0x214 - 0x20A];
    u8 cg_type;
    u8 pad_col[0x23C - 0x215];
    s16 my_col_mode;
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_mts[8];
    s16 my_mts;
    u8 pad_tm[6];
    s16 my_trans_mode;
    u8 pad_end[0x132];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
} WORK_Other;

typedef struct {
    WORK wu;
    u8 pad_pn[0x394 - 0x388];
    s16 player_number;
    u8 tail[0x46C - 0x396];
} PLW;

typedef struct {
    u8 raw0[0x18];
    XY xy[2];
    XY wxy[2];
    u8 raw2[0x90 - 0x28];
} BGW;

typedef struct {
    u8 raw0[0x1C];
    s16 pos_offset;
    u8 raw1[0x38 - 0x1E];
    BGW bgw[7];
} BG;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, routine_no[1]) == 0x26, "rno1");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, old_rno[1]) == 0x36, "old_rno1");
_Static_assert(__builtin_offsetof(WORK, old_rno[2]) == 0x38, "old_rno2");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, kage_flag) == 0x49, "kage_flag");
_Static_assert(__builtin_offsetof(WORK, kage_hx) == 0x4A, "kage_hx");
_Static_assert(__builtin_offsetof(WORK, kage_hy) == 0x4C, "kage_hy");
_Static_assert(__builtin_offsetof(WORK, kage_prio) == 0x4E, "kage_prio");
_Static_assert(__builtin_offsetof(WORK, kage_char) == 0x52, "kage_char");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].cal) == 0x68, "xyz1cal");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, sync_suzi) == 0x76, "sync_suzi");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[0].sp) == 0x7C, "a0sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[1].sp) == 0x80, "a1sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[0].sp) == 0x84, "d0sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[1].sp) == 0x88, "d1sp");
_Static_assert(__builtin_offsetof(WORK, char_table[0]) == 0x1AC, "char_table0");
_Static_assert(__builtin_offsetof(WORK, char_table[1]) == 0x1B0, "char_table1");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
_Static_assert(__builtin_offsetof(PLW, player_number) == 0x394, "player_number");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw[1].wxy[0].disp.pos) == 0xEA, "wxy");
#endif

extern EffectRow frw[];
extern PLW plw[2];
extern s16 EXE_flag;
extern u8 Game_pause;
extern u32 _etc_char_table[];

const s16 effm7_data_tbl[42] = {
    48,  -8, -1, 0, 18, 30, 90, 64,   2,  1,  0, 17, 16, 98,  -32,  -8, -1, 1, 18, 4,  92,
    -64, 2,  1,  1, 17, 24, 96, -112, -8, -1, 1, 18, 8,  102, -224, 2,  1,  1, 17, 10, 106
};

void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sub_000EF072(WORK_Other *ewk);
void sub_000EF088(WORK_Other *ewk);
s32 range_x_check3(WORK_Other *ewk, s16 rad);
void pl_eff_trans_entry(WORK_Other *ewk);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effm7_move(WORK_Other *ewk);

void effm7_move(WORK_Other *ewk) {
    s16 id_w;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        id_w = ewk->master_id ^ 1;
        ewk->wu.rl_flag ^= plw[id_w].wu.rl_flag;

        if (plw[id_w].wu.rl_flag) {
            ewk->wu.xyz[0].disp.pos = plw[id_w].wu.xyz[0].disp.pos - ewk->wu.xyz[0].disp.pos;
        } else {
            ewk->wu.xyz[0].disp.pos = plw[id_w].wu.xyz[0].disp.pos + ewk->wu.xyz[0].disp.pos;
        }

        set_char_move_init(&ewk->wu, 0, 0);
        break;

    case 1:
        ewk->wu.old_rno[1]--;
        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] < 0) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        char_move(&ewk->wu);

        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] < 0) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 1, 0x6C);
        }

        break;

    case 3:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type != 1) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.mvxy.a[0].sp = 0;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.a[1].sp = 0x78000;
        ewk->wu.mvxy.d[1].sp = -0x6000;
        break;

    case 4:
        sub_000EF088(ewk);
        char_move(&ewk->wu);

        if (ewk->wu.cg_type != 2) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.mvxy.d[0].sp = 0;

        if (ewk->wu.rl_flag) {
            ewk->wu.mvxy.a[0].sp = 0x80000;
        } else {
            ewk->wu.mvxy.a[0].sp = -0x80000;
        }

        ewk->wu.mvxy.a[1].sp = -0x8000;
        ewk->wu.mvxy.d[1].sp = 0x4000;
        break;

    case 5:
        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (!range_x_check3(ewk, 208)) {
            ewk->wu.routine_no[0] = 99;
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[1]++;
        }

        break;
    }
}

s32 effect_M7_init(PLW *oya) {
    WORK_Other *ewk;
    s16 ix;
    s16 i;
    const s16 *data_ptr = effm7_data_tbl;
    s16 em_id = oya->wu.id ^ 1;

    for (i = 0; i < 6; i++) {
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }

        ewk = (WORK_Other *)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 227;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.disp_flag = 0;
        ewk->my_master = (u32 *)oya;
        ewk->master_id = oya->wu.id;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = oya->wu.id ? 8 : 0;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].cal = plw[em_id].wu.xyz[1].cal;
        ewk->wu.xyz[1].disp.pos += *data_ptr++;
        ewk->wu.position_z = plw[em_id].wu.my_priority;
        ewk->wu.position_z += *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z;
        ewk->wu.rl_flag = *data_ptr++;
        ewk->wu.kage_char = *data_ptr++;
        ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.old_rno[1] = *data_ptr++;
        ewk->wu.char_table[0] = *oya->wu.char_table;
        ewk->wu.char_table[1] = _etc_char_table;
        ewk->wu.char_index = 0;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 6;
        ewk->wu.kage_hy = 0;
        ewk->wu.kage_prio = ewk->wu.position_z + 5;
        ewk->wu.my_mts = oya->wu.my_mts;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    }

    return 0;
}

void effect_M7_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause) {
            effm7_move(ewk);
        }

        pl_eff_trans_entry(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}
