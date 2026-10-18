/* Effect E1, retail sf33rd.xbe.
 * effect_E1_move is 0x48EB1 size 0x5D.
 * effect_E1_init is 0x48F0E size 0xBB.
 *
 * The move's & 0xFFFF on the positions is a plain word move. The init
 * stores dir_timer first and shares the xyz stores after the switch. Case 1
 * stores position_z and my_priority before char_index. The C keeps the
 * PlayStation 2 order. The character table immediate is 0x2F9850
 * (_etc_char_table). Those bytes were not compared.
 * dir_timer is +0x9A. cgromtype is +0x48. char_index is +0x208.
 * my_mr.size is +0x250. frw is 0xC806A0 and each object is 0x700 bytes.
 * set_char_move_init stays sub_000200A9. pull_effect_work is 0x4A6A8.
 * sort_push_request4 is 0x9E092.
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
    u8 pad_type[4];
    s16 work_id;
    s16 id;
    u8 pad_rno[0x24 - 0xA];
    s16 routine_no[8];
    u8 pad_cg[0x48 - 0x34];
    s8 cgromtype;
    u8 pad_pos[0x54 - 0x49];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0x64 - 0x5A];
    XY xyz[3];
    u8 pad_dir[0x9A - 0x70];
    s16 dir_timer;
    u8 pad_ct[0x1AC - 0x9C];
    u32 *char_table[1];
    u8 pad_ix[0x208 - 0x1B0];
    s16 char_index;
    u8 pad_col[0x23C - 0x20A];
    s16 my_col_mode;
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_mr[0x250 - 0x244];
    struct {
        s16 x;
        s16 y;
    } my_mr_size;
    u8 pad_end[0x388 - 0x254];
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_mr_size) == 0x250, "my_mr");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

extern u32 _etc_char_table[];
extern EffectRow frw[];

s16 pull_effect_work(s16 index);
void sort_push_request4(WORK *wk);
void sub_000200A9(WORK *wk, s16 koc, s32 index);

void effect_E1_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 1;
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        /* fallthrough */

    case 1:
        ewk->wu.my_mr_size.x = 63;
        ewk->wu.my_mr_size.y = 63;
        break;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}

s32 effect_E1_init(s16 id, s16 Time, s16 unused) {
    WORK_Other *ewk;
    s16 ix;

    (void)unused;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x8D;
    ewk->wu.work_id = 0x10;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 1;
    ewk->wu.dir_timer = Time;
    ewk->wu.char_table[0] = _etc_char_table;
    ewk->wu.my_mr_size.x = 0x3F;
    ewk->wu.my_mr_size.y = 0x3F;

    switch (id) {
    case 0:
        ewk->wu.char_index = 0x59;
        ewk->wu.xyz[0].disp.pos = 0x200;
        ewk->wu.xyz[1].disp.pos = 0x90;
        ewk->wu.my_priority = ewk->wu.position_z = 0x45;
        break;

    case 1:
        ewk->wu.my_priority = ewk->wu.position_z = 0x44;
        ewk->wu.xyz[0].disp.pos = 0x200;
        ewk->wu.xyz[1].disp.pos = 0x90;
        ewk->wu.char_index = 0x5A;
        break;
    }

    return 0;
}
