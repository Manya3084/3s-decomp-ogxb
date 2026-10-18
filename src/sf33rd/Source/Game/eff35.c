/* Bonus stage pieces, retail sf33rd.xbe.
 * eff35_0000 is 0xB7197 size 0x59 and is interior.
 * eff35_0001 is 0xB71F0 size 0xFD and is interior.
 * eff35_0002 is 0xB72ED size 0x9C and is interior.
 * eff35_0003 is 0xB7389 size 0x157 and is interior.
 * eff35_0004 is 0xB74E0 size 0xEE and is interior.
 * eff35_0005 is 0xB75CE size 0xC2 and is interior.
 * eff35_0006 is 0xB7690 size 0xC9 and is interior.
 * effect_35_init is 0xB7759 size 0x13B and is interior.
 * effect_35_move is 0xB7894 size 0x46 and is a scanned start.
 * The init's -1 path is an early ret. 0xB78DA stays unnamed.
 *
 * eff35_data_tbl is 0x2842C8 and matches the 12 rows.
 * eff35_03_b is 0x284370 and eff35_03_s is 0x284378.
 * Both match. The rows were not pasted.
 * Break_Into is 0x7A8802. Next_Step is 0x7A86D2.
 * pcon_rno[0] is 0xC7E020 and pcon_rno[2] is 0xC7E024.
 * Bonus_Game_result is 0x7A881A. Bonus_Game_ex_result is
 * 0x7A842A. Country is 0x7A8748. EXE_flag is 0xC7C834.
 * Game_pause is 0x7A89B0. bg_w is 0x7BC520.
 * The character table immediate is 0x3027D0. Those bytes
 * were not compared. The init stores my_family after the
 * table reads. The C keeps the PlayStation 2 order.
 * disp_pos_trans_entry and disp_pos_trans_entry5 share
 * 0xEF0C0. add_x_sub is 0xEF072. char_move stays
 * char_move. set_char_move_init is 0x200A9.
 * set_char_move_init2 is 0x201B9. effect_58_init
 * stays effect_58_init. all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C. pull_effect_work
 * stays pull_effect_work. frw is 0xC806A0 and each object is
 * 0x700 bytes.
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
    u8 pad_rno[0x24 - 0xA];
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
    u8 pad_mv[0xC];
    MVXY mvxy;
    u8 pad_ct[0x1AC - 0x94];
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
    s16 my_mr_flag;
    struct {
        struct {
            s16 x;
            s16 y;
        } size;
    } my_mr;
    s16 my_trans_mode;
    u8 pad_end[0x132];
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef struct {
    u8 raw0[0xA];
    s16 position_x;
    s16 position_y;
    u8 raw1[0x18 - 0xE];
    XY xy[2];
    XY wxy[2];
    u8 raw2[0x30 - 0x28];
    s16 old_pos_x;
    u8 raw3[0x90 - 0x32];
} BGW;

typedef struct {
    u8 raw0[3];
    s8 stage;
    u8 raw1[0x38 - 4];
    BGW bgw[7];
} BG;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(MVXY, a[0].sp) == 0, "a0");
_Static_assert(__builtin_offsetof(MVXY, d[0].sp) == 8, "d0");
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, mvxy) == 0x7C, "mvxy");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[0].sp) == 0x84, "mvxy.d");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_mr_flag) == 0x24E, "my_mr_flag");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.x) == 0x250, "mr.x");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.y) == 0x252, "mr.y");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw[1].wxy[0].disp.pos) == 0xEA, "wxy");
_Static_assert(__builtin_offsetof(BG, bgw[1].xy[1].disp.pos) == 0xE6, "xy");
#endif

extern s8 Break_Into;
extern s8 Next_Step;
extern s16 EXE_flag;
extern u8 Game_pause;
extern s16 pcon_rno[4];
extern s16 Bonus_Game_result;
extern s16 Bonus_Game_ex_result;
extern u8 Country;
extern BG bg_w;
extern const s16 eff35_data_tbl[12][7];
extern const s16 eff35_03_b[4];
extern const s16 eff35_03_s[4];
extern EffectRow frw[];

void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void char_move(WORK *wk);
void disp_pos_trans_entry(WORK_Other *ewk);
void add_x_sub(WORK_Other *ewk);
s32 effect_58_init(s16 id, s16 time0, s16 option);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void eff35_0000(WORK_Other *ewk);
void eff35_0001(WORK_Other *ewk);
void eff35_0002(WORK_Other *ewk);
void eff35_0003(WORK_Other *ewk);
void eff35_0004(WORK_Other *ewk);
void eff35_0005(WORK_Other *ewk);
void eff35_0006(WORK_Other *ewk);

void effect_35_move(WORK_Other *ewk) {
    void (*eff35_jp[7])(WORK_Other *) = { eff35_0000, eff35_0001, eff35_0002, eff35_0003,
                                          eff35_0004, eff35_0005, eff35_0006 };

    eff35_jp[ewk->wu.routine_no[0]](ewk);
}

void eff35_0000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        }

        break;

    case 1:
        disp_pos_trans_entry(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff35_0001(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.my_mr_flag = 1;
            ewk->wu.my_mr.size.x = 127;
            ewk->wu.my_mr.size.y = 63;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        }

        break;

    case 1:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.my_mr.size.x -= 12;

        if (ewk->wu.my_mr.size.x <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr.size.x = 0;
        }

        disp_pos_trans_entry(ewk);
        break;

    case 2:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.my_mr.size.x += 12;

        if (ewk->wu.my_mr.size.x >= 63) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr.size.x = 63;
        }

        disp_pos_trans_entry(ewk);
        break;

    case 3:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[4]--;

        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            Next_Step = 1;
        }

        disp_pos_trans_entry(ewk);
        break;

    case 4:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff35_0002(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
            effect_58_init(6, 4, 0xA8);
        }

        break;

    case 1:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[4]--;

        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }

        disp_pos_trans_entry(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff35_0003(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.old_rno[4] = 0;
        /* fallthrough */

    case 1:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 99;
            break;
        }

        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] > 0) {
            break;
        }

        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);

        if (ewk->wu.type == 2) {
            ewk->wu.xyz[0].disp.pos = eff35_data_tbl[2][0];
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = eff35_data_tbl[2][1];
            ewk->wu.xyz[1].disp.low = 0;
            ewk->wu.mvxy.a[0].sp = -0x78000;
            ewk->wu.mvxy.d[0].sp = 0;
        } else {
            ewk->wu.xyz[0].disp.pos = eff35_data_tbl[3][0];
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = eff35_data_tbl[3][1];
            ewk->wu.xyz[1].disp.low = 0;
            ewk->wu.mvxy.a[0].sp = 0x5C000;
            ewk->wu.mvxy.d[0].sp = 0;
        }

        break;

    case 2:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 99;
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            add_x_sub(ewk);
        }

        if (ewk->wu.type == 2) {
            if (ewk->wu.xyz[0].disp.pos < 416) {
                ewk->wu.routine_no[1] = 1;
                ewk->wu.disp_flag = 0;
                ewk->wu.old_rno[4]++;
                ewk->wu.old_rno[4] &= 3;
                ewk->wu.old_rno[1] = eff35_03_b[ewk->wu.old_rno[4]];
            }
        } else if (ewk->wu.xyz[0].disp.pos > 768) {
            ewk->wu.routine_no[1] = 1;
            ewk->wu.disp_flag = 0;
            ewk->wu.old_rno[4]++;
            ewk->wu.old_rno[4] &= 3;
            ewk->wu.old_rno[1] = eff35_03_s[ewk->wu.old_rno[4]];
        }

        disp_pos_trans_entry(ewk);
        break;

    case 99:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff35_0004(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        }

        break;

    case 1:
        if (pcon_rno[0] == 2 && pcon_rno[2] >= 3) {
            if (Bonus_Game_result >= 10 || Bonus_Game_ex_result >= 10) {
                ewk->wu.routine_no[1]++;
            } else {
                ewk->wu.routine_no[1] = 3;
            }
        } else if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
        }

        disp_pos_trans_entry(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
        }

        if (ewk->wu.cg_type == 9) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 8);
        }

        disp_pos_trans_entry(ewk);
        break;

    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
        }

        disp_pos_trans_entry(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff35_0005(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.my_col_code = 0x49;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        }

        break;

    case 1:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[4]--;

        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }

        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + eff35_data_tbl[ewk->wu.type][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].xy[1].disp.pos + eff35_data_tbl[ewk->wu.type][1];
        disp_pos_trans_entry(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff35_0006(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.my_col_code = 0x49;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        }

        break;

    case 1:
        if (Break_Into != 0) {
            ewk->wu.routine_no[1] = 4;
            break;
        }

        ewk->wu.old_rno[4]--;

        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            Next_Step = 1;
        }

        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + eff35_data_tbl[ewk->wu.type][0];
        ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].xy[1].disp.pos + eff35_data_tbl[ewk->wu.type][1];
        disp_pos_trans_entry(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_35_init(s16 wait_timer, s16 c_type) {
    WORK_Other *ewk;
    s16 ix;
    const s16 *data_ptr;
    u8 char_num;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.id = 35;

    switch (c_type) {
    case 5:
        if (Country == 1 || Country == 8) {
            char_num = 5;
        } else {
            char_num = 9;
        }

        break;

    case 7:
        if (Country == 1 || Country == 8) {
            char_num = 7;
        } else {
            char_num = 8;
        }

        break;

    case 10:
        switch (Bonus_Game_result) {
        case 2:
            char_num = 11;
            break;

        case 3:
            char_num = 10;
            break;

        default:
            char_num = 10;
            ewk->wu.routine_no[1] = 99;
            Next_Step = 1;
            break;
        }

        break;

    default:
        char_num = c_type;
        break;
    }

    data_ptr = eff35_data_tbl[char_num];
    ewk->wu.be_flag = 1;
    ewk->wu.old_rno[1] = wait_timer;
    ewk->wu.type = char_num;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = (u32 *)0x3027D0;
    ewk->wu.my_col_code = 0x12C;
    ewk->wu.my_mts = 7;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.my_family = 2;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.old_rno[3] = *data_ptr++;
    ewk->wu.routine_no[0] = *data_ptr++;
    ewk->wu.old_rno[4] = *data_ptr++;
    return 0;
}
