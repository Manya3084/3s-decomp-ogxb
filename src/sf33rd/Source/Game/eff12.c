/* Stage objects, retail sf33rd.xbe.
 * effect_12_move is 0xB6D00 size 0x80 and is interior.
 * effect_12_init is 0xB6D80 size 0x149 and is a scanned start.
 * The init size runs through the or eax, -1 tail after its ret.
 *
 * scr_obj_num12 is 0x2841FC and matches the 6 counts.
 * scr_obj_data12 is 0x332DD0. Its 6 pointers and the s16 rows
 * they address match. char_add is the effect 5 table at
 * 0x332CC8. Those pointers are Xbox addresses. The rows were
 * not pasted.
 *
 * frw is 0xC806A0 and each object is 0x700 bytes.
 * bg_w.bg_index is 0x7BC550. EXE_flag is 0xC7C834.
 * Game_pause is 0x7A89B0.
 * set_char_move_init is 0x200A9. char_move stays
 * char_move. disp_pos_trans_entry is folded into 0xEF0C0.
 * all_cgps_put_back stays sub_0004384A. push_effect_work
 * stays push_effect_work. pull_effect_work is 0x4A6A8.
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
    u8 pad_dead[0x15];
    s16 dead_f;
    u8 pad_rno[2];
    s16 routine_no[8];
    s16 old_rno[8];
    u8 pad_cg[4];
    s8 cgromtype;
    u8 pad_pos[0xB];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_sync[6];
    s16 sync_suzi;
    u8 pad_dir[0x20];
    s16 dir_step;
    s16 dir_timer;
    u8 pad_ct[0x110];
    u32 *char_table[1];
    u8 pad_ci[0x58];
    s16 char_index;
    u8 pad_cgtype[0xA];
    u8 cg_type;
    u8 pad_col[0x27];
    s16 my_col_mode;
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
    u8 pad_end[0x132];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
    s16 master_player;
    s16 master_priority;
} WORK_Other;

typedef struct {
    u8 raw[0x30];
    s16 bg_index;
} BG;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, sync_suzi) == 0x76, "sync_suzi");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_mr_flag) == 0x24E, "my_mr_flag");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.x) == 0x250, "mr.x");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.y) == 0x252, "mr.y");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(BG, bg_index) == 0x30, "bg_index");
#endif

extern BG bg_w;
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s16 scr_obj_num12[6] = { 1, 1, 2, 3, 3, 2 };

const s16 eff12_data_tbl0[8] = { 0, 1, 300, 512, 128, 86, 8, 0 };

const s16 eff12_data_tbl1[8] = { 0, 2, 8492, 511, 56, 80, 2, 0 };

const s16 eff12_data_tbl2[16] = { 0, 2, 8492, 559, 64, 72, 2, 0, 0, 2, 8492, 463, 112, 72, 4, 0 };

const s16 eff12_data_tbl3[24] = { 0,  1,  300, 496, 64, 86, 2,    0,   0,  2,  8492, 607,
                                  96, 83, 8,   0,   0,  2,  8492, 607, 96, 83, 26,   0 };

const s16 eff12_data_tbl4[24] = { 0,   2,  300, 511, 0, 11, 5,   0,   0, 2,  8492, 560,
                                  168, 79, 9,   0,   0, 2,  300, 512, 0, 76, 10,   0 };

const s16 eff12_data_tbl5[16] = { 0, 2, 8492, 575, 80, 74, 20, 0, 0, 2, 8492, 464, 64, 72, 19, 0 };

const s16* scr_obj_data12[6] = { eff12_data_tbl0, eff12_data_tbl1, eff12_data_tbl2,
                                 eff12_data_tbl3, eff12_data_tbl4, eff12_data_tbl5 };

extern u32 *char_add[22];
extern EffectRow frw[];
extern s16 EXE_flag;
extern u8 Game_pause;

s32 obr_no_disp_check(void);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void char_move(WORK *wk);
s32 compel_dead_check(WORK_Other *ewk);
void sub_000EF0C0(WORK_Other *ewk);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effect_12_move(WORK_Other *ewk) {
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
        if (compel_dead_check(ewk) != 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
        }

        sub_000EF0C0(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_12_init(s16 type) {
    WORK_Other *ewk;
    s16 ix;
    s16 lp_cnt;
    s16 i;
    const s16 *data_ptr;

    lp_cnt = scr_obj_num12[type];

    if (lp_cnt == 0) {
        return 0;
    }

    data_ptr = scr_obj_data12[type];

    for (i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other *)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 12;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.type = i;
        ewk->wu.dead_f = *data_ptr++;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.sync_suzi = *data_ptr++;
        ewk->wu.char_table[0] = char_add[bg_w.bg_index];
        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);

        if (type == 3 && i == 2) {
            ewk->wu.my_mr_flag = 1;
            ewk->wu.my_mr.size.x = 127;
            ewk->wu.my_mr.size.y = 127;
        }
    }

    return 0;
}
