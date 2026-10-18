/* Effect L7, retail sf33rd.xbe.
 * effl7_move is 0xB9874 size 0x17C and is interior.
 * effect_L7_init is 0xB99F0 size 0x1B9 and is interior.
 * effect_L7_move is 0xB9BA9 size 0x70 and is interior.
 * The early returns share the init epilogue. The pull
 * failure is an early ret.
 * 0xB9861 stays unnamed. 0xB9C19 stays unnamed.
 *
 * 0xB9861 calls pl_eff_trans_entry when routine_no[0]
 * is 0. The PlayStation 2 source has no such function.
 * effl7_move case 4 pushes four arguments to
 * set_char_move_init2, as the PlayStation 2 build does,
 * and pops 0x10 bytes. The fifth parameter reads the
 * caller's stack. effl7_move case 4 stores mvxy.a[1]
 * before mvxy.a[0]. The init stores char_index and
 * sync_suzi before xyz[1]. The C keeps the
 * PlayStation 2 order. effl7_data_tbl is 0x2847E0 and
 * matches the PlayStation 2 values. Suicide is
 * 0x7A8268. poison_flag is 0x7A8A48. My_char is
 * 0x7A8114. p1sw_0 is 0x7C557C. p2sw_0 is 0x7C5B90.
 * bg_w is 0x7BC520. EXE_flag is 0xC7C834. Game_pause is
 * 0x7A89B0. The _etc3_char_table immediate is 0x303250
 * and the _etc_char_table immediate is 0x2F9850. Those
 * bytes were not compared. char_move stays
 * char_move. set_char_move_init is 0x200A9.
 * set_char_move_init2 is 0x201B9. add_x_sub
 * stays add_x_sub. add_y_sub is folded into 0xEF088.
 * cal_initial_speed is 0x1D280. suzi_offset_set
 * stays suzi_offset_set. random_16 is 0x9326B.
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
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, sync_suzi) == 0x76, "sync_suzi");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[0].sp) == 0x7C, "a0sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[1].sp) == 0x80, "a1sp");
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
extern BG bg_w;
extern s8 Suicide[8];
extern s16 poison_flag[2];
extern u8 My_char[2];
extern u16 p1sw_0;
extern u16 p2sw_0;
extern s16 EXE_flag;
extern u8 Game_pause;
extern u32 _etc3_char_table[];
extern u32 _etc_char_table[];

const s16 effl7_data_tbl[16] = { 55, 56, 57, 55, 56, 57, 55, 57, 55, 56, 57, 55, 56, 57, 56, 57 };

void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sub_000EF072(WORK_Other *ewk);
void sub_000EF088(WORK_Other *ewk);
void cal_initial_speed(WORK *wk, s16 tm, s16 tx, s16 ty);
void suzi_offset_set(WORK_Other *ewk);
s16 random_16(void);
s32 range_x_check3(WORK_Other *ewk, s16 rad);
void pl_eff_trans_entry(WORK_Other *ewk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effl7_move(WORK_Other *ewk);

void effl7_move(WORK_Other *ewk) {
    void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip);

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = -10;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 80;
        cal_initial_speed(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos);
        break;

    case 1:
        char_move(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);
        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[1] += 1;
            set_char_move_init(&ewk->wu, 0, 1);
        }

        break;

    default:
        break;

    case 2:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] += 1;
            set_char_move_init(&ewk->wu, 1, ewk->wu.old_rno[2]);
        }

        break;

    case 3:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 9) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.rl_flag ^= 1;
        }

        break;

    case 4:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] += 1;
            set_char_move_init2(&ewk->wu, 0, 0, 3);

            if (ewk->wu.rl_flag) {
                ewk->wu.mvxy.a[0].sp = 0x20000;
            } else {
                ewk->wu.mvxy.a[0].sp = -0x20000;
            }

            ewk->wu.mvxy.a[1].sp = 0;
        }

        break;

    case 5:
        char_move(&ewk->wu);
        sub_000EF072(ewk);

        if (range_x_check3(ewk, 64) == 0) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.disp_flag = 0;
            ewk->wu.kage_flag = 0;
        }

        break;

    case 6:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.routine_no[0] += 1;
        break;
    }
}

s32 effect_L7_init(WORK *wk, s32 unused) {
    WORK_Other *ewk;
    s16 ix;
    s16 kind_w;

    (void)unused;

    if ((wk->work_id == 1) && (((PLW *)wk)->player_number != My_char[wk->id])) {
        return 0;
    }

    if (poison_flag[wk->id]) {
        return 0;
    }

    if (wk->id) {
        if (!(p2sw_0 & 1)) {
            return 0;
        }
    } else if (!(p1sw_0 & 1)) {
        return 0;
    }

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 217;
    ewk->wu.work_id = 16;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 1;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32 *)wk;
    ewk->wu.rl_flag = wk->rl_flag;

    if (wk->rl_flag) {
        if (wk->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos - 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - (bg_w.pos_offset + 32);
        }

        ewk->wu.old_rno[1] = wk->xyz[0].disp.pos - 32;
    } else {
        if (wk->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos + 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + (bg_w.pos_offset + 32);
        }

        ewk->wu.old_rno[1] = wk->xyz[0].disp.pos + 32;
    }

    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.my_priority = 28;
    ewk->wu.position_z = 28;
    ewk->wu.char_table[0] = _etc3_char_table;
    ewk->wu.char_table[1] = _etc_char_table;
    ewk->wu.char_index = 0;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(ewk);
    kind_w = random_16();
    ewk->wu.old_rno[2] = effl7_data_tbl[kind_w];
    poison_flag[wk->id] = 1;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}

void effect_L7_move(WORK_Other *ewk) {
    WORK *oya_ptr = (WORK *)ewk->my_master;

    if (Suicide[0] || (ewk->wu.dead_f)) {
        ewk->wu.routine_no[0] = 1;
        ewk->wu.disp_flag = 0;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if ((!EXE_flag) && (!Game_pause)) {
            effl7_move(ewk);
        }

        pl_eff_trans_entry(ewk);
        break;

    case 1:
        ewk->wu.routine_no[0] += 1;
        poison_flag[oya_ptr->id] = 0;
        /* fallthrough */

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
