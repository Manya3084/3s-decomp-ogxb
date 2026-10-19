/* Effect 94, retail sf33rd.xbe.
 * eff94_0000 is 0xB830A size 0x5A and is interior.
 * eff94_1000 is 0xB8364 size 0xF2 and is interior.
 * eff94_2000_0 is 0xB8456 size 0x28 and is interior.
 * eff94_2000_2 is 0xB847E size 0x2C and is interior.
 * eff94_2000_3 is 0xB84AA size 0x44 and is interior.
 * eff94_2000_4 is 0xB84EE size 0x1B and is interior.
 * eff94_3000_0 is 0xB8509 size 0x62 and is interior.
 * eff94_3000_4 is 0xB856B size 0xB and is interior.
 * eff94_4000 is 0xB8576 size 0x71 and is interior.
 * effect_94_init is 0xB85E7 size 0x109 and is interior.
 * eff94_2000_1 is 0xB86F0 size 0x92 and is interior.
 * eff94_3000 is 0xB8782 size 0x31 and is a scanned start.
 * eff94_2000 is 0xB87B3 size 0x38 and is a scanned start.
 * effect_94_move is 0xB87EB size 0xA2 and is a scanned start.
 * The pull failure jumps to the shared epilogue.
 * 0xB82C0 stays unnamed. 0xB888D stays unnamed.
 *
 * eff94_data_tbl is 0x284600 and matches the 5 rows.
 * eff94_2000_tbl is 0x284664. eff94_2000_1_tbl is
 * 0x284674. eff94_3000_tbl is 0x284684. All match.
 * The rows were not pasted. Four zero bytes at
 * 0x2845FC pad EFF91_Pos_Data. char_add is 0x332CC8.
 * Those 22 pointers are Xbox addresses and were not
 * compared. eff94_2000_0 stores old_rno[3] with setge.
 * The C keeps the PlayStation 2 if. eff94_1000 stores
 * routine_no[0] before disp_flag. The C keeps the
 * PlayStation 2 order. eff94_2000_2 stores the y
 * position between the pushes and the call. The init
 * stores char_table before the row and the flag block
 * after it. dead_f is stored during the row. The C
 * keeps the PlayStation 2 order. Case 0 of
 * effect_94_move stores disp_flag between the pushes
 * and the call. EXE_obroll is 0x7A8111. EXE_flag is
 * 0xC7C834. Game_pause is 0x7A89B0. bg_w is 0x7BC520.
 * disp_pos_trans_entry and disp_pos_trans_entry5 share
 * 0xEF0C0. disp_pos_trans_entry_r is named.
 * get_my_trans_mode is named. char_move stays
 * char_move. set_char_move_init is 0x200A9.
 * add_x_sub is folded into 0xEF072. add_y_sub stays
 * add_y_sub. all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C. pull_effect_work
 * stays pull_effect_work. random_16 is 0x9326B.
 * frw is 0xC806A0 and each object is 0x700 bytes.
 * 0xB6890 stays unnamed. 0xB61A0 is push_color_trans_req.
 * 0xB7EC3 stays unnamed.
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
    s16 hit_stop;
    u8 pad_cg[2];
    s8 cgromtype;
    u8 pad_pos[0xB];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_mv[0xC];
    MVXY mvxy;
    u8 pad_dir[6];
    s16 dir_timer;
    u8 pad_ct[0x110];
    u32 *char_table[1];
    u8 pad_ci[0x58];
    s16 char_index;
    u8 pad_cgtype[0xA];
    u8 cg_type;
    u8 pad_col[0x27];
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
} WORK_Other;

typedef struct {
    u8 raw0[0x66];
    s16 r_limit2;
    s16 l_limit;
    s16 l_limit2;
    u8 raw1[0x24];
} BGW;

typedef struct {
    u8 raw0[0x1C];
    s16 pos_offset;
    s16 quake_x_index;
    s16 quake_y_index;
    u8 raw1[0xE];
    s16 bg_index;
    u8 raw2[6];
    BGW bgw[2];
} BG;

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
_Static_assert(__builtin_offsetof(WORK, routine_no[2]) == 0x28, "rno2");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, old_rno[3]) == 0x3A, "old3");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].cal) == 0x68, "xyz1cal");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, mvxy) == 0x7C, "mvxy");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[1].sp) == 0x80, "a1");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[0].sp) == 0x84, "d0");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[1].sp) == 0x88, "d1");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, pos_offset) == 0x1C, "pos_offset");
_Static_assert(__builtin_offsetof(BG, quake_y_index) == 0x20, "quake_y");
_Static_assert(__builtin_offsetof(BG, bg_index) == 0x30, "bg_index");
_Static_assert(__builtin_offsetof(BG, bgw[1].r_limit2) == 0x12E, "r_limit2");
_Static_assert(__builtin_offsetof(BG, bgw[1].l_limit2) == 0x132, "l_limit2");
#endif

extern s8 EXE_obroll;
extern s16 EXE_flag;
extern u8 Game_pause;
extern BG bg_w;
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s16 eff94_data_tbl[5][10] = { { 2, 8492, 392, 64, 12, 22, 52, 0, 0, 1 },
                                    { 2, 8492, 408, 75, 11, 23, 53, 0, 1, 1 },
                                    { 2, 8492, 640, 16, 10, 9, 10, 0, 4, 1 },
                                    { 2, 8492, 352, 272, 10, 2, 2, 0, 2, 1 },
                                    { 2, 8492, 352, 272, 10, 2, 2, 0, 3, 0 } };

const s16 eff94_2000_tbl[8] = { 288, 336, 320, 288, 328, 296, 344, 304 };

const s8 eff94_2000_1_tbl[16] = { 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1 };

const s16 eff94_3000_tbl[4][3] = { { 328, 304, 0 }, { 288, 240, 1 }, { 280, 320, 0 }, { 352, 264, 1 } };

extern u32 *char_add[22];
extern EffectRow frw[];

void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sub_000EF072(WORK_Other *ewk);
void sub_000EF088(WORK_Other *ewk);
void sub_000EF0C0(WORK_Other *ewk);
void disp_pos_trans_entry_r(WORK_Other *ewk);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 random_16(void);
s16 get_my_trans_mode(s16 curr);

void eff94_0000(WORK_Other *ewk);
void eff94_1000(WORK_Other *ewk);
void eff94_2000(WORK_Other *ewk);
void eff94_3000(WORK_Other *ewk);
void eff94_4000(WORK_Other *ewk);
void eff94_2000_0(WORK_Other *ewk);
void eff94_2000_1(WORK_Other *ewk);
void eff94_2000_2(WORK_Other *ewk);
void eff94_2000_3(WORK_Other *ewk);
void eff94_2000_4(WORK_Other *ewk);
void eff94_3000_0(WORK_Other *ewk);
void eff94_3000_4(WORK_Other *ewk);
s32 effect_94_init(u8 type94);

/* The Xbox returns where the PS2 breaks out of the switch. */
void effect_94_move(WORK_Other *ewk) {
    void (*const eff94_move_jp[5])(WORK_Other *) = {
        eff94_0000, eff94_1000, eff94_2000, eff94_3000, eff94_4000,
    };

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && EXE_obroll == 0) {
            eff94_move_jp[ewk->wu.routine_no[1]](ewk);
        }

        if (ewk->wu.old_rno[1] != 0) {
            disp_pos_trans_entry_r(ewk);
            return;
        }

        sub_000EF0C0(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff94_0000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        if (bg_w.quake_y_index > 3) {
            ewk->wu.routine_no[2]++;
        }

        break;

    case 1:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[2]);
        break;

    case 2:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[2] = 0;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
        }

        break;
    }
}

void eff94_1000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        if (bg_w.quake_y_index > 3) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[2]);
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            if (ewk->wu.xyz[0].disp.pos >= 452) {
                ewk->wu.routine_no[2]++;
                set_char_move_init(&ewk->wu, 0, 47);
                ewk->wu.mvxy.a[0].sp = 0x8000;
                ewk->wu.mvxy.a[1].sp = 0;
                ewk->wu.mvxy.d[0].sp = 0;
                ewk->wu.mvxy.d[1].sp = -0x6000;
                break;
            }

            ewk->wu.routine_no[2] = 0;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
            break;
        }

        break;

    case 2:
        char_move(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos <= 10) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 0, 48);
            ewk->wu.xyz[0].disp.pos += 2;
            ewk->wu.old_rno[1] = 0;
            break;
        }

        break;

    case 3:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[2]++;
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
        }

        break;
    }
}

void eff94_2000(WORK_Other *ewk) {
    void (*const eff94_2000_jp[5])(WORK_Other *) = {
        eff94_2000_0, eff94_2000_1, eff94_2000_2, eff94_2000_3, eff94_2000_4,
    };

    eff94_2000_jp[ewk->wu.routine_no[2]](ewk);
}

void eff94_2000_0(WORK_Other *ewk) {
    ewk->wu.disp_flag = 0;

    if (bg_w.quake_y_index > 3) {
        ewk->wu.routine_no[2]++;

        if (bg_w.quake_y_index >= 24) {
            ewk->wu.old_rno[3] = 1;
            return;
        }

        ewk->wu.old_rno[3] = 0;
    }
}

void eff94_2000_1(WORK_Other *ewk) {
    s16 work;

    ewk->wu.routine_no[2]++;
    set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
    ewk->wu.disp_flag = 1;
    work = random_16();

    if (eff94_2000_1_tbl[work] != 0) {
        ewk->wu.routine_no[2] = 4;
        ewk->wu.dir_timer = 8;
        return;
    }

    if (work == 7 && ewk->wu.old_rno[3] != 0) {
        effect_94_init(4);
        effect_94_init(4);
        effect_94_init(4);
    }

    work &= 7;
    ewk->wu.xyz[0].disp.pos = eff94_2000_tbl[work];
    ewk->wu.xyz[1].cal = 0x1100000;
    ewk->wu.mvxy.a[1].sp = -0x68000;
    ewk->wu.mvxy.d[1].sp = -0x6000;
}

void eff94_2000_2(WORK_Other *ewk) {
    sub_000EF088(ewk);

    if (ewk->wu.xyz[1].disp.pos <= 16) {
        ewk->wu.routine_no[2]++;
        ewk->wu.xyz[1].disp.pos = 16;
        set_char_move_init(&ewk->wu, 0, 3);
    }
}

void eff94_2000_3(WORK_Other *ewk) {
    char_move(&ewk->wu);

    if ((ewk->wu.xyz[0].disp.pos <= bg_w.bgw[1].l_limit2 - bg_w.pos_offset) ||
        ewk->wu.xyz[0].disp.pos >= bg_w.bgw[1].r_limit2 + bg_w.pos_offset) {
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 0;
        ewk->wu.dir_timer = 4;
    }
}

void eff94_2000_4(WORK_Other *ewk) {
    ewk->wu.dir_timer--;

    if (ewk->wu.dir_timer <= 0) {
        ewk->wu.routine_no[2] = 0;
    }
}

void eff94_3000(WORK_Other *ewk) {
    void (*const eff94_2000_jp[4])(WORK_Other *) = {
        eff94_3000_0, eff94_2000_2, eff94_2000_3, eff94_3000_4,
    };

    eff94_2000_jp[ewk->wu.routine_no[2]](ewk);
}

void eff94_3000_0(WORK_Other *ewk) {
    s16 work;

    ewk->wu.routine_no[2]++;
    set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
    ewk->wu.disp_flag = 1;
    work = random_16();
    work &= 3;
    ewk->wu.xyz[0].disp.pos = eff94_3000_tbl[work][0];
    ewk->wu.xyz[1].disp.pos = eff94_3000_tbl[work][1];
    ewk->wu.rl_flag = eff94_3000_tbl[work][2];
    ewk->wu.mvxy.a[1].sp = -0x68000;
    ewk->wu.mvxy.d[1].sp = -0x6000;
}

void eff94_3000_4(WORK_Other *ewk) {
    ewk->wu.routine_no[0] = 99;
}

void eff94_4000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        if (bg_w.quake_y_index > 3) {
            ewk->wu.routine_no[2]++;
        }

        break;

    case 1:
        ewk->wu.routine_no[2]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[2]);
        break;

    case 2:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 9) {
            if (bg_w.quake_y_index > 3) {
                ewk->wu.routine_no[2] = 1;
                break;
            }
        } else if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[2] = 0;
            set_char_move_init(&ewk->wu, 0, ewk->wu.old_rno[0]);
        }

        break;
    }
}

s32 effect_94_init(u8 type94) {
    WORK_Other *ewk;
    s16 ix;
    const s16 *data_ptr = eff94_data_tbl[type94];

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 94;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.type = type94;
    ewk->wu.dead_f = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = char_add[bg_w.bg_index];
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.my_col_code = *data_ptr++;
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.position_z = ewk->wu.my_priority = *data_ptr++;
    ewk->wu.old_rno[0] = ewk->wu.char_index = *data_ptr++;
    ewk->wu.old_rno[2] = *data_ptr++;
    ewk->wu.hit_stop = *data_ptr++;
    ewk->wu.routine_no[1] = *data_ptr++;
    ewk->wu.old_rno[1] = *data_ptr++;
    ewk->wu.my_mts = 7;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
