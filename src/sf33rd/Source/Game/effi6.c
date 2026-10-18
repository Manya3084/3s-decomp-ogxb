/* Effect I6, retail sf33rd.xbe.
 * effi6_line_move is 0xBE971 size 0x41 and is interior.
 * effect_I6_init is 0xBE9B2 size 0xAF and is interior.
 * effect_I6_move is 0xBEA61 size 0x5D and is interior.
 * The pull failure is an early ret.
 * 0xBE935 stays unnamed. 0xBEABE stays unnamed.
 *
 * 0xBE935 repeats the parent routine 3 and 4 display
 * paths of effect_I6_move. The PlayStation 2 source has
 * no such function. The init stores the char_table
 * entry after xyz[0] and position_x. The C keeps the
 * PlayStation 2 order. bg_w is 0x7BC520. The
 * _etc_char_table immediate is 0x2F9850. Those bytes
 * were not compared. set_char_move_init2 stays
 * set_char_move_init2. disp_pos_trans_entry5 stays
 * disp_pos_trans_entry. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8.
 * get_my_trans_mode is named. frw is 0xC806A0 and each
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
    s16 hit_stop;
    s16 hit_quake;
    s8 cgromtype;
    u8 pad_pos[0x54 - 0x49];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_dir[0x96 - 0x70];
    s16 dir_old;
    u8 pad_ct[0x1AC - 0x98];
    u32 *char_table[1];
    u8 pad_cg[0x23E - 0x1B0];
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
    u8 pad_ec[0x342 - 0x256];
    s16 extra_col;
    u8 pad_end[0x388 - 0x344];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
} WORK_Other;

typedef struct {
    u8 raw0[0xA];
    s16 position_x;
    u8 raw1[0x90 - 0xC];
} BGW;

typedef struct {
    u8 raw0[0x1C];
    s16 pos_offset;
    u8 raw1[0x38 - 0x1E];
    BGW bgw[7];
} BG;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, routine_no[1]) == 0x26, "rno1");
_Static_assert(__builtin_offsetof(WORK, routine_no[2]) == 0x28, "rno2");
_Static_assert(__builtin_offsetof(WORK, old_rno[1]) == 0x36, "old_rno1");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, hit_quake) == 0x46, "hit_quake");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.low) == 0x64, "xyz0low");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].cal) == 0x68, "xyz1cal");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, dir_old) == 0x96, "dir_old");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_mr_flag) == 0x24E, "my_mr_flag");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.x) == 0x250, "mr.x");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.y) == 0x252, "mr.y");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(__builtin_offsetof(WORK, extra_col) == 0x342, "extra_col");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw[1].position_x) == 0xD2, "bgw position_x");
#endif

extern EffectRow frw[];
extern BG bg_w;
extern u32 _etc_char_table[];

void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void sub_000EF0C0(WORK_Other *ewk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effi6_line_move(WORK_Other *ewk);

void effect_I6_move(WORK_Other *ewk) {
    WORK_Other *oya_ptr = (WORK_Other *)ewk->my_master;

    switch (oya_ptr->wu.routine_no[0]) {
    case 2:
        effi6_line_move(ewk);
        /* fallthrough */

    case 3:
        ewk->wu.my_mr.size.x = oya_ptr->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_ptr->wu.my_mr.size.y;
        sub_000EF0C0(ewk);
        break;

    case 4:
        ewk->wu.disp_flag = 0;
        sub_000EF0C0(ewk);
        break;

    case 5:
    case 99:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effi6_line_move(WORK_Other *ewk) {
    WORK_Other *oya_ptr = (WORK_Other *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 0;
        ewk->wu.my_mr.size.y = 0;
        set_char_move_init2(&ewk->wu, 0, 2, 3, 0);
        /* fallthrough */

    case 1:
        break;
    }
}

s32 effect_I6_init(WORK_Other *oya) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xBA;
    ewk->wu.work_id = 0x10;
    ewk->wu.cgromtype = 1;
    ewk->my_master = (u32 *)oya;
    ewk->wu.my_family = 4;
    ewk->wu.my_col_code = 0x52;
    ewk->wu.my_priority = ewk->wu.position_z = 10;
    ewk->wu.my_mts = 0xE;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    *ewk->wu.char_table = (u32 *)_etc_char_table;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = 0x90;
    return 0;
}
