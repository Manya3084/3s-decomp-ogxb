/* Effect B4, retail sf33rd.xbe.
 * effect_B4_move is 0x44073 size 0xA9.
 * effect_B4_init is 0x4411C size 0xB8.
 *
 * In case 0 of effect_B4_move, random_16() & 0x1F is stored once into
 * old_rno[0]. The s_mark_tbl entry is added to char_index in place.
 * effect_B4_init keeps 0 in a register for master_id, my_col_mode,
 * sync_suzi and rl_flag.
 * s_mark_tbl is 0x251910. _etc_char_table is 0x2F9850.
 * Game_pause is 0x7A89B0. EXE_flag is 0xC7C834.
 * frw is 0xC806A0, 0x700 bytes per object. old_rno is +0x34.
 * set_char_move_init stays sub_000200A9. char_move stays sub_0002008E.
 * all_cgps_put_back stays sub_0004384A. suzi_offset_set stays sub_000B4052.
 * suzi_sync_pos_set is 0xB3627. random_16 is 0x9326B.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 * sort_push_request is 0x9DF9A. get_my_trans_mode is 0xEF70B.
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
    s8 rl_flag;
    u8 pad_rno[0x24 - 0xB];
    s16 routine_no[8];
    s16 old_rno[8];
    u8 pad_cgr[0x48 - 0x44];
    s8 cgromtype;
    u8 pad_pos[0x58 - 0x49];
    s16 position_z;
    u8 pad_xyz[0x64 - 0x5A];
    XY xyz[3];
    u8 pad_sync[0x76 - 0x70];
    s16 sync_suzi;
    u8 pad_ct[0x1AC - 0x78];
    u32 *char_table[1];
    u8 pad_ci[0x208 - 0x1B0];
    s16 char_index;
    u8 pad_cg[0x214 - 0x20A];
    u8 cg_type;
    u8 pad_col[0x23C - 0x215];
    s16 my_col_mode;
    s16 my_col_code;
    u8 pad_fam[2];
    s16 my_family;
    u8 pad_mts[0x24C - 0x244];
    s16 my_mts;
    u8 pad_tm[0x254 - 0x24E];
    s16 my_trans_mode;
    u8 pad_end[0x388 - 0x256];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, sync_suzi) == 0x76, "sync_suzi");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
#endif

extern const s16 s_mark_tbl[32];
extern u32 _etc_char_table[];
extern u8 Game_pause;
extern u16 EXE_flag;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void sort_push_request(WORK *wk);
s16 get_my_trans_mode(s32 curr);
s16 random_16(void);
void suzi_sync_pos_set(WORK_Other *wk);
void sub_000200A9(WORK *wk, s16 koc, s32 index);
void sub_0002008E(WORK *wk);
void sub_0004384A(WORK *wk);
void sub_000B4052(WORK_Other *wk);

void effect_B4_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[0] = random_16() & 0x1F;
        ewk->wu.char_index += s_mark_tbl[ewk->wu.old_rno[0]];
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            sub_0002008E(&ewk->wu);

            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[0]++;
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        break;

    case 3:
        ewk->wu.routine_no[0]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
}

s32 effect_B4_init(WORK_Other *oya) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 114;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->my_master = (u32 *)oya;
    ewk->master_id = 0;
    ewk->wu.my_col_mode = 0;
    ewk->wu.my_col_code = 0x20;
    ewk->wu.my_family = 2;
    ewk->wu.position_z = oya->wu.position_z - 1;
    ewk->wu.char_table[0] = _etc_char_table;
    ewk->wu.char_index = 34;
    ewk->wu.sync_suzi = 0;
    ewk->wu.rl_flag = 0;
    ewk->wu.xyz[0].disp.pos = oya->wu.xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = oya->wu.xyz[1].disp.pos;
    sub_000B4052(ewk);
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
