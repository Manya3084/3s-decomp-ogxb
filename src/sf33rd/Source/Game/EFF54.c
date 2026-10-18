/* Effect 54, retail sf33rd.xbe.
 * effect_54_move is 0x3D849 size 0x40.
 * effect_54_init is 0x3D889 size 0xED.
 *
 * effect_54_init clears dead_f and stores my_master before be_flag, and
 * clears sync_suzi right after get_my_trans_mode. It keeps the constant 2
 * in a register for both the loop bound and my_family. The C keeps the
 * PlayStation 2 order.
 * eff29_data_tbl is 0x24EFD8, four s16 per object. The character table
 * immediate is 0x2F6DC0 (_eng_char_table). Those bytes were not compared.
 * dead_f is +0x20. sync_suzi is +0x76. char_index is +0x208.
 * set_char_move_init stays sub_000200A9. disp_pos_trans_entry_rs is
 * 0xEF16D. suzi_offset_set stays sub_000B4052. pull_effect_work is 0x4A6A8.
 * get_my_trans_mode is 0xEF70B. frw is 0xC806A0, 0x700 bytes per object.
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
    u8 pad_dead[0x20 - 0xB];
    s16 dead_f;
    u8 pad_rno[0x24 - 0x22];
    s16 routine_no[8];
    u8 pad_cg[0x48 - 0x34];
    s8 cgromtype;
    u8 pad_pos[0x58 - 0x49];
    s16 position_z;
    u8 pad_xyz[0x64 - 0x5A];
    XY xyz[3];
    u8 pad_suzi[0x76 - 0x70];
    s16 sync_suzi;
    u8 pad_ct[0x1AC - 0x78];
    u32 *char_table[1];
    u8 pad_ix[0x208 - 0x1B0];
    s16 char_index;
    u8 pad_col[0x23C - 0x20A];
    s16 my_col_mode;
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
    u32 *my_master;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, sync_suzi) == 0x76, "sync_suzi");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "trans");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
#endif

extern const s16 eff29_data_tbl[];
extern u32 _eng_char_table[];
extern EffectRow frw[];

s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);
void disp_pos_trans_entry_rs(WORK_Other *ewk);
void sub_000200A9(WORK *wk, s16 koc, s32 index);
void sub_000B4052(WORK_Other *ewk);

void effect_54_move(WORK_Other *ewk) {
    WORK_Other *oya = (WORK_Other *)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        ewk->wu.disp_flag = oya->wu.disp_flag;
        disp_pos_trans_entry_rs(ewk);
        break;
    }
}

s32 effect_54_init(WORK_Other *oya) {
    WORK_Other *ewk;
    s16 ix;
    s16 i;
    const s16 *data_ptr = eff29_data_tbl;

    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other *)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 54;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->my_master = (u32 *)oya;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.type = i;
        ewk->wu.dead_f = 0;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 8492;
        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = _eng_char_table;
        sub_000B4052(ewk);
    }

    return 0;
}
