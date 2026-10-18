/* Effect M0, retail sf33rd.xbe.
 * animal_init is 0xB9DE0 size 0xE6 and is interior.
 * mouse_run_set is 0xB9EC6 size 0x2F and is interior.
 * mouse_stand_set is 0xB9EF5 size 0x1F and is interior.
 * cat_run_set is 0xB9F14 size 0x2F and is interior.
 * cat_run_set2 is 0xB9F43 size 0x2F and is interior.
 * cat_walk_set is 0xB9F72 size 0x2F and is interior.
 * don_run_set is 0xB9FA1 size 0x2F and is interior.
 * effect_M0_init is 0xB9FD0 size 0x84 and is interior.
 * animal_0000 is 0xBA054 size 0xAD and is interior.
 * animal_0001 is 0xBA101 size 0x7D and is interior.
 * animal_0002 is 0xBA17E size 0x96 and is interior.
 * animal_0004 is 0xBA214 size 0xB8 and is interior.
 * animal_0005 is 0xBA2CC size 0xED and is interior.
 * animal_control is 0xBA3B9 size 0x40.
 * effect_M0_move is 0xBA3F9 size 0x5E and is interior.
 * The pull failure is an early ret.
 * 0xBA457 is effect_M5_move.
 *
 * animal_init reads bg_w.bgw[1].wxy[0] and pos_offset as
 * dwords and shares the kage tail of cases 0 and 6. Case
 * 2 flips rl_flag first. The init stores type before
 * be_flag. animal_0002 case 2 and the range failures of
 * animal_0001, animal_0004, and animal_0005 store
 * routine_no[1] before routine_no[0]. The C keeps the
 * PlayStation 2 order. animal_0005_tbl is 0x284800 and
 * matches the PlayStation 2 values. plw is 0xC7CEA0,
 * stride 0x46C. bg_w is 0x7BC520. EXE_flag is 0xC7C834.
 * Game_pause is 0x7A89B0. The _etc2_char_table
 * immediate is 0x2F77F0. Those bytes were not compared.
 * disp_pos_trans_entry and disp_pos_trans_entry5 share
 * 0xEF0C0, which stays disp_pos_trans_entry. char_move stays
 * char_move. set_char_move_init is 0x200A9.
 * add_x_sub is folded into 0xEF072. random_16 stays
 * random_16. all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C. pull_effect_work
 * stays pull_effect_work. range_x_check3 and
 * get_my_trans_mode are named. frw is 0xC806A0 and each
 * object is 0x700 bytes.
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
extern PLW plw[2];
extern BG bg_w;
extern s16 EXE_flag;
extern u8 Game_pause;
extern u32 _etc2_char_table[];

const s16 animal_0005_tbl[16] = { 40, 50, 160, 70, 80, 100, 30, 200, 340, 10, 110, 18, 40, 60, 30, 150 };

void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sub_000EF072(WORK_Other *ewk);
void sub_000EF0C0(WORK_Other *ewk);
s16 random_16(void);
s32 range_x_check3(WORK_Other *ewk, s16 rad);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void animal_init(WORK_Other *ewk);
void animal_control(WORK_Other *ewk);
void animal_0000(WORK_Other *ewk);
void animal_0001(WORK_Other *ewk);
void animal_0002(WORK_Other *ewk);
void animal_0004(WORK_Other *ewk);
void animal_0005(WORK_Other *ewk);
void mouse_run_set(WORK_Other *ewk);
void mouse_stand_set(WORK_Other *ewk);
void cat_run_set(WORK_Other *ewk);
void don_run_set(WORK_Other *ewk);

void animal_init(WORK_Other *ewk) {
    s16 work_l = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset;
    s16 work_r = bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset;

    switch (ewk->wu.type) {
    case 0:
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = -4;
        ewk->wu.kage_hy = 33;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 3;

        if (ewk->wu.rl_flag) {
            ewk->wu.xyz[0].disp.pos = work_l;
            break;
        }

        ewk->wu.xyz[0].disp.pos = work_r;
        break;

    case 2:
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = -4;
        ewk->wu.kage_hy = 33;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 3;
        ewk->wu.rl_flag ^= 1;
        break;

    case 6:
        if (plw->player_number == 7) {
            ewk->wu.my_col_code = plw->wu.my_col_code;
        } else {
            ewk->wu.my_col_code = plw[1].wu.my_col_code;
        }

        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = -2;
        ewk->wu.kage_hy = 24;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 8;

        if (ewk->wu.rl_flag) {
            ewk->wu.xyz[0].disp.pos = work_l;
            break;
        }

        ewk->wu.xyz[0].disp.pos = work_r;
        break;

    default:
        if (ewk->wu.rl_flag) {
            ewk->wu.xyz[0].disp.pos = work_r;
        } else {
            ewk->wu.xyz[0].disp.pos = work_l;
        }

        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = 33;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 0;
        ewk->wu.rl_flag ^= 1;
        break;
    }
}

void mouse_run_set(WORK_Other *ewk) {
    set_char_move_init(&ewk->wu, 0, 25);

    if (ewk->wu.rl_flag) {
        ewk->wu.mvxy.a[0].sp = -0x30000;
    } else {
        ewk->wu.mvxy.a[0].sp = 0x30000;
    }

    ewk->wu.mvxy.d[0].sp = 0;
}

void mouse_stand_set(WORK_Other *ewk) {
    set_char_move_init(&ewk->wu, 0, 18);
    ewk->wu.mvxy.a[0].sp = 0;
    ewk->wu.mvxy.d[0].sp = 0;
}

void cat_run_set(WORK_Other *ewk) {
    set_char_move_init(&ewk->wu, 0, 26);

    if (ewk->wu.rl_flag) {
        ewk->wu.mvxy.a[0].sp = 0x38000;
    } else {
        ewk->wu.mvxy.a[0].sp = -0x38000;
    }

    ewk->wu.mvxy.d[0].sp = 0;
}

void cat_run_set2(WORK_Other *ewk) {
    set_char_move_init(&ewk->wu, 0, 26);

    if (ewk->wu.rl_flag) {
        ewk->wu.mvxy.a[0].sp = 0x2C000;
    } else {
        ewk->wu.mvxy.a[0].sp = -0x2C000;
    }

    ewk->wu.mvxy.d[0].sp = 0;
}

void cat_walk_set(WORK_Other *ewk) {
    set_char_move_init(&ewk->wu, 0, 27);

    if (ewk->wu.rl_flag) {
        ewk->wu.mvxy.a[0].sp = 0x18000;
    } else {
        ewk->wu.mvxy.a[0].sp = -0x18000;
    }

    ewk->wu.mvxy.d[0].sp = 0;
}

void don_run_set(WORK_Other *ewk) {
    set_char_move_init(&ewk->wu, 0, 52);

    if (ewk->wu.rl_flag) {
        ewk->wu.mvxy.a[0].sp = 0x48000;
    } else {
        ewk->wu.mvxy.a[0].sp = -0x48000;
    }

    ewk->wu.mvxy.d[0].sp = 0;
}

s32 effect_M0_init(u8 pl_rl, u8 animal_type) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 220;
    ewk->wu.work_id = 16;
    ewk->wu.type = animal_type;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = _etc2_char_table;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 58;
    ewk->wu.rl_flag = pl_rl;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}

void animal_0000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;

        if (ewk->wu.type == 6) {
            ewk->wu.old_rno[0] = 10;
            don_run_set(ewk);
            ewk->wu.xyz[1].disp.pos = 24;
        } else {
            ewk->wu.old_rno[0] = 60;
            cat_run_set(ewk);
            ewk->wu.xyz[1].disp.pos = 32;
        }

        ewk->wu.my_priority = ewk->wu.position_z = 27;
        break;

    case 1:
        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        sub_000EF072(ewk);
        char_move(&ewk->wu);

        if (!range_x_check3(ewk, 48)) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 3:
        sub_000EF072(ewk);
        char_move(&ewk->wu);
        ewk->wu.routine_no[0] = 99;
        ewk->wu.routine_no[1]++;
        break;
    }
}

void animal_0001(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[0] = 30;
        ewk->wu.disp_flag = 1;
        mouse_run_set(ewk);
        ewk->wu.xyz[1].disp.pos = 32;
        ewk->wu.my_priority = ewk->wu.position_z = 27;
        break;

    case 1:
        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        sub_000EF072(ewk);
        char_move(&ewk->wu);

        if (!range_x_check3(ewk, 32)) {
            ewk->wu.routine_no[0] = 99;
            ewk->wu.routine_no[1]++;
        }

        break;
    }
}

void animal_0002(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 47);
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos;
        ewk->wu.xyz[1].disp.pos = 32;
        ewk->wu.my_priority = ewk->wu.position_z = 27;
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.rl_flag ^= 1;
            cat_run_set(ewk);
        }

        break;

    case 2:
        sub_000EF072(ewk);
        char_move(&ewk->wu);

        if (!range_x_check3(ewk, 32)) {
            ewk->wu.routine_no[0] = 99;
            ewk->wu.routine_no[1]++;
        }

        break;
    }
}

void animal_0004(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[0] = 30;
        ewk->wu.disp_flag = 1;
        mouse_stand_set(ewk);
        ewk->wu.xyz[1].disp.pos = 32;
        ewk->wu.my_priority = ewk->wu.position_z = 27;

        if (ewk->wu.rl_flag) {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 48;
            break;
        }

        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - 48;
        break;

    case 1:
        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            mouse_run_set(ewk);
        }

        break;

    case 3:
        char_move(&ewk->wu);
        sub_000EF072(ewk);

        if (!range_x_check3(ewk, 32)) {
            ewk->wu.routine_no[0] = 99;
            ewk->wu.routine_no[1]++;
        }

        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void animal_0005(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[0] = 30;
        ewk->wu.disp_flag = 1;
        mouse_run_set(ewk);
        ewk->wu.xyz[1].disp.pos = 32;
        ewk->wu.my_priority = ewk->wu.position_z = 27;
        ewk->wu.old_rno[2] = random_16();
        ewk->wu.old_rno[3] = animal_0005_tbl[ewk->wu.old_rno[2]];
        break;

    case 1:
        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        char_move(&ewk->wu);
        ewk->wu.old_rno[3]--;

        if (ewk->wu.old_rno[3] <= 0) {
            ewk->wu.routine_no[1]++;
            mouse_stand_set(ewk);
            return;
        }

        sub_000EF072(ewk);
        break;

    case 3:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            mouse_run_set(ewk);
        }

        break;

    case 4:
        sub_000EF072(ewk);
        char_move(&ewk->wu);

        if (!range_x_check3(ewk, 32)) {
            ewk->wu.routine_no[0] = 99;
            ewk->wu.routine_no[1]++;
        }

        break;
    }
}

void animal_control(WORK_Other *ewk) {
    void (*animal_jp[7])(WORK_Other *ewk) = { animal_0000, animal_0001, animal_0002, animal_0001,
                                              animal_0004, animal_0005, animal_0000 };
    animal_jp[ewk->wu.type](ewk);
}

void effect_M0_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        animal_init(ewk);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            animal_control(ewk);
        }

        sub_000EF0C0(ewk);
        break;

    case 99:
        ewk->wu.routine_no[0]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}
