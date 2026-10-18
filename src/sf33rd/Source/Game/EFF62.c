/* Effect 62, retail sf33rd.xbe.
 * effect_62_move is 0x3EC41 size 0x46.
 * effect_62_init is 0x3EC87 size 0xE0.
 *
 * The init stores my_master and dm_vital before be_flag. Both
 * my_col_code stores (0x2000, then 1) are kept. The C keeps the PlayStation
 * 2 order. EFF62_Correct_Data is 0x24F2F0, two s16 per row. The character
 * table immediate is 0x2FE100 (_sel_pl_char_table). Those bytes were not
 * compared. vital_new is +0x9E, vital_old +0xA0, dm_vital +0xA2.
 * shell_ix is +0x330. frw is 0xC806A0 and each object is 0x700 bytes.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 * sort_push_requestA is 0x9D87F. get_my_trans_mode is 0xEF70B.
 */

#include "types.h"

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[4];
    s16 work_id;
    s16 id;
    u8 pad_pos[0x54 - 0xA];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_vit[0x9E - 0x5A];
    s16 vital_new;
    s16 vital_old;
    s16 dm_vital;
    u8 pad_ct[0x1AC - 0xA4];
    u32 *char_table[1];
    u8 pad_col[0x23E - 0x1B0];
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_clear[6];
    s16 my_clear_level;
    s16 my_mts;
    u8 pad_trans[6];
    s16 my_trans_mode;
    u8 pad_shell[0x330 - 0x256];
    s16 shell_ix[4];
    u8 pad_end[0x388 - 0x338];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, vital_new) == 0x9E, "vital_new");
_Static_assert(__builtin_offsetof(WORK, dm_vital) == 0xA2, "dm_vital");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_clear_level) == 0x24A, "clear");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "trans");
_Static_assert(__builtin_offsetof(WORK, shell_ix) == 0x330, "shell_ix");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

extern u32 _sel_pl_char_table[];
extern const s16 EFF62_Correct_Data[][2];
extern EffectRow frw[];

void push_effect_work(WORK *wk);
void sort_push_requestA(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effect_62_move(WORK_Other *ewk) {
    WORK_Other *mwk = (WORK_Other *)ewk->my_master;

    if (mwk->wu.be_flag == 0) {
        push_effect_work(&ewk->wu);
        return;
    }

    ewk->wu.position_x = mwk->wu.position_x + ewk->wu.vital_new;
    ewk->wu.position_y = mwk->wu.position_y + ewk->wu.vital_old;
    ewk->wu.position_z = mwk->wu.position_z + 1;
    sort_push_requestA(&ewk->wu);
}

s32 effect_62_init(WORK_Other *mwk, s16 ID) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = 1;
    ewk->wu.id = 62;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x2000;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->my_master = (u32 *)mwk;
    ewk->wu.dm_vital = ID;
    ewk->wu.my_family = mwk->wu.my_family;
    ewk->wu.vital_new = EFF62_Correct_Data[ID][0];
    ewk->wu.vital_old = EFF62_Correct_Data[ID][1];
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.my_col_code = 1;
    ewk->wu.my_clear_level = 179;
    ewk->wu.shell_ix[0] = -190;
    ewk->wu.shell_ix[1] = 380;
    ewk->wu.shell_ix[2] = -46;
    ewk->wu.shell_ix[3] = 30;
    return 0;
}
