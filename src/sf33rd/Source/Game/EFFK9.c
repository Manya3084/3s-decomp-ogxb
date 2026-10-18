/* Effect K9, retail sf33rd.xbe.
 * effect_K9_move is 0x50F45 size 0xE2.
 * effect_K9_init is 0x51027 size 0x90.
 *
 * effect_K9_init stores type before my_master and be_flag. The C keeps the
 * PlayStation 2 order. The character table immediate is 0x308B40
 * (_plef_char_table). Those bytes were not compared.
 * dead_f is +0x20. dir_old is +0x96. dir_step is +0x98. now_koc is +0x206.
 * char_index is +0x208. cg_type is +0x214. my_mr_flag is +0x24E and
 * my_mr.size +0x250. EXE_flag is 0xC7C834. Game_pause is 0x7A89B0.
 * base_y_pos is 0x7BC516. push_color_trans_req stays sub_000B61A0.
 * set_char_move_init stays sub_000200A9. char_move stays sub_0002008E.
 * sort_push_request is 0x9DF9A. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. frw is 0xC806A0, 0x700 bytes per object.
 */

#include "types.h"

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[2];
    u8 type;
    u8 pad_work[1];
    s16 work_id;
    s16 id;
    u8 pad_dead[0x20 - 0xA];
    s16 dead_f;
    u8 pad_rno[0x24 - 0x22];
    s16 routine_no[8];
    u8 pad_pos[0x54 - 0x34];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_dir[0x96 - 0x5A];
    s16 dir_old;
    s16 dir_step;
    u8 pad_ct[0x1AC - 0x9A];
    u32 *char_table[1];
    u8 pad_koc[0x206 - 0x1B0];
    s16 now_koc;
    s16 char_index;
    u8 pad_cg[0x214 - 0x20A];
    u8 cg_type;
    u8 pad_col[0x23E - 0x215];
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_clear[0x24A - 0x244];
    s16 my_clear_level;
    s16 my_mts;
    s16 my_mr_flag;
    struct {
        s16 x;
        s16 y;
    } my_mr_size;
    u8 pad_end[0x388 - 0x254];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, dir_old) == 0x96, "dir_old");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, now_koc) == 0x206, "now_koc");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_clear_level) == 0x24A, "clear");
_Static_assert(__builtin_offsetof(WORK, my_mr_flag) == 0x24E, "my_mr_flag");
_Static_assert(__builtin_offsetof(WORK, my_mr_size) == 0x250, "my_mr");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

extern s16 EXE_flag;
extern u8 Game_pause;
extern s16 base_y_pos;
extern u32 _plef_char_table[];
extern EffectRow frw[];

void sub_000B61A0(s32 id, s32 code);
void sub_000200A9(WORK *wk, s16 koc, s32 index);
void sub_0002008E(WORK *wk);
void sort_push_request(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

void effect_K9_move(WORK_Other *ewk) {
    WORK *mwk = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        sub_000B61A0(0x36, 10);
        ewk->wu.my_col_code = 10;
        ewk->wu.my_priority = ewk->wu.position_z = 32;
        ewk->wu.my_clear_level = 0xA0;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr_size.x = 127;
        ewk->wu.my_mr_size.y = 112;
        sub_000200A9(&ewk->wu, 0, 0x90);
        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 0) {
            if (EXE_flag != 0 || Game_pause != 0 ||
                (ewk->wu.dir_old == mwk->now_koc && ewk->wu.dir_step == mwk->char_index &&
                 (sub_0002008E(&ewk->wu), ewk->wu.cg_type != 0xFF))) {
                sort_push_request(&ewk->wu);
                return;
            }
        }

        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = 2;
        return;

    default:
    case 2:
        push_effect_work(&ewk->wu);
        return;
    }
}

s32 effect_K9_init(WORK *wk, u8 data) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(5)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->my_master = (u32 *)wk;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 209;
    ewk->wu.type = data;
    ewk->wu.work_id = 16;
    ewk->wu.my_mts = 6;
    ewk->wu.my_family = 8;
    ewk->wu.position_x = 192;
    ewk->wu.position_y = 112 - base_y_pos;
    ewk->wu.dir_old = wk->now_koc;
    ewk->wu.dir_step = wk->char_index;
    *ewk->wu.char_table = _plef_char_table;
    return 0;
}
