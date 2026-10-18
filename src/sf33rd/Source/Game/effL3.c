/* Effect L3, retail sf33rd.xbe.
 * effl3_0000 is 0xB8F83 size 0xAB and is interior.
 * effl3_0001 is 0xB902E size 0xEB and is interior.
 * effl3_tobi is 0xB9119 size 0xF6 and is interior.
 * effl3_kie is 0xB920F size 0x4B and is interior.
 * effect_L3_init is 0xB925A size 0x18B.
 * effl3_0002 is 0xB93E5 size 0x57 and is interior.
 * effect_L3_move is 0xB943C size 0x68.
 * 0xB8F70 stays unnamed. 0xB94A4 stays unnamed.
 *
 * effl3_wait_timer is 0x2846C0 and effl3_data_tbl is
 * 0x2846D0. Both match the PlayStation 2 values. The rows
 * were not pasted. effl3_0000 case 1 shares one
 * routine_no[2] store and call for both directions.
 * effl3_0001 case 0 passes old_rno[2] as the immediate 60
 * and stores it between the pushes and the call. The
 * effl3_tobi case 2 store of mvxy.a[0] comes last. The
 * init stores my_priority with the routine_no[1] store
 * and kage_hy before kage_flag. The C keeps the
 * PlayStation 2 order. Perfect_Flag is 0x7A812C.
 * Appear_Q is 0x7A85C6. bg_w is 0x7BC520. plw is
 * 0xC7CEA0, stride 0x46C. EXE_flag is 0xC7C834.
 * Game_pause is 0x7A89B0. The _etc_char_table immediate
 * is 0x2F9850. Those bytes were not compared.
 * char_move is 0x2008E. set_char_move_init stays
 * set_char_move_init. add_x_sub is 0xEF072. add_y_sub
 * stays add_y_sub. cal_all_speed_data stays
 * cal_all_speed_data. random_16 is 0x9326B.
 * all_cgps_put_back stays sub_0004384A. push_effect_work
 * stays push_effect_work. pull_effect_work stays
 * pull_effect_work. range_x_check3, pl_eff_trans_entry, and
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
    u8 pad_mv[0xC];
    MVXY mvxy;
    u8 pad_ct[0x1AC - 0x94];
    u32 *char_table[10];
    u8 pad_cg_type[0x214 - 0x1D4];
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
    u8 tail[0x46C - 0x388];
} PLW;

typedef struct {
    u8 raw0[0xA];
    s16 position_x;
    s16 position_y;
    u8 raw1[0x18 - 0xE];
    XY xy[2];
    XY wxy[2];
    u8 raw2[0x90 - 0x28];
} BGW;

typedef struct {
    u8 raw0[0x38];
    BGW bgw[7];
} BG;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, routine_no[1]) == 0x26, "rno1");
_Static_assert(__builtin_offsetof(WORK, routine_no[2]) == 0x28, "rno2");
_Static_assert(__builtin_offsetof(WORK, routine_no[3]) == 0x2A, "rno3");
_Static_assert(__builtin_offsetof(WORK, routine_no[4]) == 0x2C, "rno4");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, old_rno[1]) == 0x36, "old_rno1");
_Static_assert(__builtin_offsetof(WORK, old_rno[2]) == 0x38, "old_rno2");
_Static_assert(__builtin_offsetof(WORK, old_rno[3]) == 0x3A, "old_rno3");
_Static_assert(__builtin_offsetof(WORK, old_rno[4]) == 0x3C, "old_rno4");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, kage_flag) == 0x49, "kage_flag");
_Static_assert(__builtin_offsetof(WORK, kage_hx) == 0x4A, "kage_hx");
_Static_assert(__builtin_offsetof(WORK, kage_hy) == 0x4C, "kage_hy");
_Static_assert(__builtin_offsetof(WORK, kage_prio) == 0x4E, "kage_prio");
_Static_assert(__builtin_offsetof(WORK, kage_char) == 0x52, "kage_char");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[0].sp) == 0x7C, "a0sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[1].sp) == 0x80, "a1sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[0].sp) == 0x84, "d0sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[1].sp) == 0x88, "d1sp");
_Static_assert(__builtin_offsetof(WORK, char_table[0]) == 0x1AC, "char_table0");
_Static_assert(__builtin_offsetof(WORK, char_table[1]) == 0x1B0, "char_table1");
_Static_assert(__builtin_offsetof(WORK, char_table[9]) == 0x1D0, "char_table9");
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
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw[1].wxy[0].disp.pos) == 0xEA, "wxy");
#endif

extern EffectRow frw[];
extern PLW plw[2];
extern BG bg_w;
extern u8 Perfect_Flag;
extern u8 Appear_Q;
extern s16 EXE_flag;
extern u8 Game_pause;
extern u32 _etc_char_table[];

const s16 effl3_wait_timer[8] = { 3, 0, 30, 50, 40, 8, 20, 1 };

const s16 effl3_data_tbl[112] = { -272, -8,  -1, 1, 18, -32, -8, 0, 272,  -8,  -1, 0, 18, 48,   -8, 0,
                                  272,  2,   1,  0, 17, 96,  2,  0, -272, -8,  -1, 1, 18, -128, -8, 0,
                                  112,  128, 1,  0, 17, 0,   2,  1, -272, 2,   1,  1, 17, -80,  2,  0,
                                  -272, -8,  -1, 1, 18, -64, -8, 0, -272, 2,   1,  1, 17, -112, 2,  0,
                                  272,  -8,  -1, 0, 18, 16,  -8, 0, 272,  -8,  -1, 0, 18, 80,   -8, 0,
                                  272,  2,   1,  0, 17, 192, 2,  0, 272,  128, 1,  0, 17, 160,  2,  1,
                                  -272, 2,   1,  0, 17, 16,  2,  0, 272,  128, 1,  0, 17, 32,   2,  1 };

void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void add_x_sub(WORK_Other *ewk);
void add_y_sub(WORK_Other *ewk);
void cal_all_speed_data(WORK *wk, s16 tm, s16 tx, s16 ty, s16 ax, s16 ay);
s16 random_16(void);
s32 range_x_check3(WORK_Other *ewk, s16 rad);
void pl_eff_trans_entry(WORK_Other *ewk);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effl3_0000(WORK_Other *ewk);
void effl3_0001(WORK_Other *ewk);
void effl3_0002(WORK_Other *ewk);
void effl3_tobi(WORK_Other *ewk);
void effl3_kie(WORK_Other *ewk);

void effl3_0000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 2);

        if (ewk->wu.rl_flag) {
            ewk->wu.mvxy.a[0].sp = 0x28000;
        } else {
            ewk->wu.mvxy.a[0].sp = -0x28000;
        }

        /* fallthrough */

    case 1:
        char_move(&ewk->wu);
        add_x_sub(ewk);

        if (ewk->wu.rl_flag) {
            if (ewk->wu.xyz[0].disp.pos > ewk->wu.old_rno[0]) {
                ewk->wu.routine_no[2]++;
                set_char_move_init(&ewk->wu, 0, 11);
                break;
            }
        } else {
            if (ewk->wu.xyz[0].disp.pos < ewk->wu.old_rno[0]) {
                ewk->wu.routine_no[2]++;
                set_char_move_init(&ewk->wu, 0, 11);
            }
        }

        break;

    case 2:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 0, 0);
        }

        break;

    case 3:
        if (Appear_Q) {
            ewk->wu.routine_no[1] = 2;
        }

        char_move(&ewk->wu);
        break;
    }
}

void effl3_0001(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 1, 49);
        ewk->wu.old_rno[2] = 60;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[2], ewk->wu.old_rno[0], ewk->wu.xyz[1].disp.pos - 32, 2, 2);
        break;

    case 1:
        char_move(&ewk->wu);
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] < 0) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 1, 50);
            ewk->wu.mvxy.a[1].sp = 0;
            ewk->wu.mvxy.d[1].sp = -0x6000;
            break;
        }

        add_x_sub(ewk);
        add_y_sub(ewk);
        break;

    case 2:
        char_move(&ewk->wu);
        add_y_sub(ewk);

        if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[1]) {
            ewk->wu.routine_no[2]++;
            set_char_move_init(&ewk->wu, 0, 0);
        }

        break;

    case 3:
        if (Appear_Q) {
            ewk->wu.routine_no[1] = 2;
        }

        char_move(&ewk->wu);
        break;
    }
}

void effl3_tobi(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[4]) {
    case 0:
        ewk->wu.old_rno[4]--;

        if (ewk->wu.old_rno[4] < 0) {
            ewk->wu.routine_no[4]++;
            set_char_move_init(&ewk->wu, 9, 39);
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 1) {
            ewk->wu.routine_no[4]++;
            ewk->wu.mvxy.a[0].sp = 0;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = 0x78000;
            ewk->wu.mvxy.d[1].sp = -0x6000;
        }

        break;

    case 2:
        add_y_sub(ewk);
        char_move(&ewk->wu);

        if (ewk->wu.cg_type != 2) {
            break;
        }

        ewk->wu.routine_no[4]++;
        ewk->wu.mvxy.d[0].sp = 0;

        if (ewk->wu.rl_flag) {
            ewk->wu.mvxy.a[0].sp = 0x80000;
        } else {
            ewk->wu.mvxy.a[0].sp = -0x80000;
        }

        ewk->wu.mvxy.a[1].sp = -0x8000;
        ewk->wu.mvxy.d[1].sp = 0x4000;
        break;

    case 3:
        add_x_sub(ewk);
        add_y_sub(ewk);

        if (!range_x_check3(ewk, 208)) {
            ewk->wu.routine_no[0] = 99;
        }

        break;

    case 4:
        break;
    }
}

void effl3_kie(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[4]) {
    case 0:
        ewk->wu.old_rno[4]--;

        if (ewk->wu.old_rno[4] < 0) {
            ewk->wu.routine_no[4]++;
            set_char_move_init(&ewk->wu, 1, 94);
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0] = 99;
        }

        break;
    }
}

s32 effect_L3_init(PLW *oya) {
    WORK_Other *ewk;
    s16 ix;
    s16 i;
    s16 id_w;
    const s16 *data_ptr;

    if (!Perfect_Flag) {
        return 0;
    }

    data_ptr = effl3_data_tbl;
    id_w = oya->wu.id ^ 1;

    for (i = 0; i < 6; i++) {
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }

        ewk = (WORK_Other *)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 213;
        ewk->wu.work_id = 16;
        ewk->my_master = (u32 *)oya;
        ewk->master_id = oya->wu.id;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = oya->wu.id ? 8 : 0;
        ewk->wu.type = i;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos;
        ewk->wu.xyz[0].disp.pos += *data_ptr++;
        ewk->wu.xyz[1].disp.pos = plw[id_w].wu.xyz[1].disp.pos;
        ewk->wu.xyz[1].disp.pos += *data_ptr++;
        ewk->wu.position_z = plw[id_w].wu.position_z;
        ewk->wu.position_z += *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z;
        ewk->wu.rl_flag = *data_ptr++;
        ewk->wu.kage_char = *data_ptr++;
        ewk->wu.old_rno[0] = plw[id_w].wu.xyz[0].disp.pos;
        ewk->wu.old_rno[0] += *data_ptr++;
        ewk->wu.old_rno[1] = *data_ptr++;
        ewk->wu.routine_no[1] = *data_ptr++;
        ewk->wu.char_table[0] = oya->wu.char_table[0];
        ewk->wu.char_table[1] = _etc_char_table;
        ewk->wu.char_table[9] = oya->wu.char_table[9];
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 6;
        ewk->wu.kage_hy = 0;
        ewk->wu.kage_prio = ewk->wu.position_z + 5;
        ewk->wu.my_mts = oya->wu.my_mts;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    }

    return 0;
}

void effl3_0002(WORK_Other *ewk) {
    s16 work;

    switch (ewk->wu.routine_no[3]) {
    case 0:
        ewk->wu.routine_no[3]++;
        ewk->wu.disp_flag = 1;
        work = random_16();
        ewk->wu.old_rno[4] = effl3_wait_timer[work];
        ewk->wu.old_rno[3] = ewk->wu.type & 1;
        break;

    case 1:
        if (ewk->wu.old_rno[3]) {
            effl3_tobi(ewk);
            break;
        }

        effl3_kie(ewk);
        break;
    }
}

void effect_L3_move(WORK_Other *ewk) {
    void (*effl3_jp[3])(WORK_Other *) = { effl3_0000, effl3_0001, effl3_0002 };

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        /* fallthrough */

    case 1:
        if (!EXE_flag && !Game_pause) {
            effl3_jp[ewk->wu.routine_no[1]](ewk);
        }

        pl_eff_trans_entry(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}
