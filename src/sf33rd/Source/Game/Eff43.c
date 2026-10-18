/* Effect 43, retail sf33rd.xbe.
 * effect_43_move is 0x528A9 size 0x68.
 * effect_43_init is 0x52911 size 0xAE.
 *
 * The move's & 0xFFFF on the positions is a plain word move. The init
 * stores xyz[1].disp.pos and dir_timer before xyz[0].disp.pos, position_z,
 * char_index, and the character table. The C keeps the PlayStation 2 order.
 * The character table immediate is 0x2FE100 (_sel_pl_char_table). Those
 * bytes were not compared. bg_w is 0x7BC520, bgw at +0x38, stride 0x90;
 * bgw[f - 1].wxy[0] and wxy[1] are read as 0x7BC4EA and 0x7BC4EE + f * 0x90.
 * dir_timer is +0x9A. char_index is +0x208.
 * set_char_move_init stays sub_000200A9. char_move stays sub_0002008E.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 * sort_push_request4 is 0x9E092. get_my_trans_mode is 0xEF70B.
 * frw is 0xC806A0, 0x700 bytes per object.
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
    u8 pad_pos[0x54 - 0x34];
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
    u8 pad_col[0x23E - 0x20A];
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_mts[0x24C - 0x244];
    s16 my_mts;
    u8 pad_trans[6];
    s16 my_trans_mode;
    u8 pad_end[0x388 - 0x256];
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef struct {
    u8 raw0[0x18];
    XY xy[2];
    XY wxy[2];
    u8 raw1[0x90 - 0x28];
} BGW;

typedef struct {
    u8 raw0[0x38];
    BGW bgw[7];
} BG;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "trans");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(BG, bgw[0].wxy[0].disp.pos) == 0x5A, "wxy0");
#endif

extern u32 _sel_pl_char_table[];
extern BG bg_w;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
void sort_push_request4(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);
void sub_000200A9(WORK *wk, s16 koc, s32 index);
void sub_0002008E(WORK *wk);

void effect_43_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer) {
            return;
        }

        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        sub_0002008E(&ewk->wu);
        break;

    default:
        push_effect_work(&ewk->wu);
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}

s32 effect_43_init(s16 Time, s16 Target_BG) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 43;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x2090;
    ewk->wu.my_family = Target_BG + 1;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 128;
    ewk->wu.position_z = 15;
    ewk->wu.char_index = 77;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.dir_timer = Time;
    return 0;
}
