/* Effect L9, retail sf33rd.xbe.
 * effect_L9_move is 0xB9C3C size 0x82 and is interior.
 * effect_L9_init is 0xB9CBE size 0x122 and is interior.
 * The pull failure is an early ret.
 * 0xB9C19 stays unnamed. 0xB9DE0 is animal_init.
 *
 * 0xB9C19 repeats the case 1 display of effect_L9_move
 * without char_move or the parent test. The PlayStation 2
 * source has no such function. The init stores
 * my_master, position_x, master_id, position_y, and type
 * before be_flag. The C keeps the PlayStation 2 order.
 * Winner_id is 0x7A8472. plw is 0xC7CEA0, stride 0x46C.
 * bg_w is 0x7BC520. The _etc2_char_table immediate is
 * 0x2F77F0. Those bytes were not compared. char_move
 * stays char_move. set_char_move_init stays
 * set_char_move_init. sort_push_request4 is 0x9E092.
 * all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C. pull_effect_work
 * stays pull_effect_work. get_my_trans_mode is named. frw
 * is 0xC806A0 and each object is 0x700 bytes.
 */

#include "types.h"

typedef union {
    s32 cal;
    struct {
        s16 low;
        s16 pos;
    } disp;
} XY;

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[2];
    u8 type;
    u8 pad_work[1];
    s16 work_id;
    s16 id;
    s8 rl_flag;
    u8 pad_rno[0x24 - 0xB];
    s16 routine_no[8];
    u8 pad_cg[0x48 - 0x34];
    s8 cgromtype;
    u8 pad_pos[0xB];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_ct[0x1AC - 0x70];
    u32 *char_table[1];
    u8 pad_ci[0x208 - 0x1B0];
    s16 char_index;
    u8 pad_col[0x23C - 0x20A];
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
    u8 raw0[0x18];
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
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, routine_no[1]) == 0x26, "rno1");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
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
extern s8 Winner_id;
extern u32 _etc2_char_table[];

void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sort_push_request4(WORK *wk);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effect_L9_move(WORK_Other *ewk) {
    WORK_Other *oya = (WORK_Other *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        char_move(&ewk->wu);

        if (oya->wu.routine_no[0] >= 3) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.disp_flag = 0;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
        sort_push_request4(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[1] += 1;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_L9_init(WORK_Other *oya, u8 ten_type) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->my_master = (u32 *)oya;
    ewk->master_id = oya->wu.id;
    ewk->wu.type = ten_type;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 219;
    ewk->wu.work_id = 16;
    ewk->wu.my_priority = 64;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = _etc2_char_table;
    ewk->wu.my_family = 8;
    ewk->wu.my_col_code = 56;
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos;

    if (ewk->wu.type) {
        ewk->wu.char_index = 53;

        if (plw[Winner_id].wu.rl_flag) {
            ewk->wu.xyz[0].disp.pos = 191;
        } else {
            ewk->wu.xyz[0].disp.pos = 192;
        }

        ewk->wu.my_priority = ewk->wu.position_z = 9;
        ewk->wu.xyz[1].disp.pos = 24;
    } else {
        ewk->wu.char_index = 48;
        ewk->wu.my_priority = ewk->wu.position_z = 17;
        ewk->wu.xyz[0].disp.pos = 192;
        ewk->wu.xyz[1].disp.pos = 8;
    }

    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
