/* Effect 07, retail sf33rd.xbe.
 * effect_07_move is 0x32ACF size 0x73 and is interior.
 * effect_07_init is 0x32B42 size 0xCB and is interior.
 * The pull failure jumps to the shared epilogue.
 * 0x32AC0 stays unnamed. 0x32C0D stays unnamed.
 *
 * Case 0 stores disp_flag between the pushes and the
 * call. The init stores char_index and xyz[0] before
 * type. It stores position_z and my_priority after
 * type and before the character tables. It stores
 * xyz[1] after the character tables. The C keeps the
 * PlayStation 2 order.
 *
 * eff07_data_tbl is 0x24B1C0 and matches the 6 words.
 * The rows were not pasted. The character table
 * immediate is 0x3015C0. Those bytes were not compared.
 * EXE_flag is 0xC7C834. Game_pause is 0x7A89B0.
 * EXE_obroll is 0x7A8111.
 * obr_no_disp_check and disp_pos_trans_entry_r are
 * named. get_my_trans_mode is named.
 * char_move is 0x2008E.
 * set_char_move_init is 0x200A9.
 * all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8.
 * frw is 0xC806A0 and each object is 0x700 bytes.
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
    u8 pad_wid[1];
    s16 work_id;
    s16 id;
    s8 rl_flag;
    u8 pad_rno[0x19];
    s16 routine_no[8];
    u8 pad_cg[0x14];
    s8 cgromtype;
    u8 pad_pos[0xF];
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_ct[0x13C];
    u32 *char_table[2];
    u8 pad_ci[0x54];
    s16 char_index;
    u8 pad_col[0x32];
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
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
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
#endif

extern EffectRow frw[];
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s16 eff07_data_tbl[2][3] = { { 4, 742, 28 }, { 5, 806, 28 } };

extern u32 _usa_char_table[];
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;

s32 obr_no_disp_check(void);
void disp_pos_trans_entry_r(WORK_Other *ewk);
s16 get_my_trans_mode(s16 curr);
void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

void effect_07_move(WORK_Other *ewk) {
    if (obr_no_disp_check() != 0) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && EXE_obroll == 0) {
            char_move(&ewk->wu);
        }

        disp_pos_trans_entry_r(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_07_init(void) {
    WORK_Other *ewk;
    s16 ix;
    s16 i;
    const s16 *data_ptr = &eff07_data_tbl[0][0];

    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other *)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 7;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_family = 3;
        ewk->wu.my_col_code = 8492;
        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
        ewk->wu.my_priority = ewk->wu.position_z = 98;
        ewk->wu.char_table[1] = (u32 *)ewk;
        ewk->wu.char_table[0] = _usa_char_table;
        ewk->wu.type = i;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
    }

    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
s32 sort_push_request4(WORK* wk);

void xb_effect_07_draw(WORK_Other* ewk) {
    if (obr_no_disp_check() == 0) {
        sort_push_request4(&ewk->wu);
    }
}
