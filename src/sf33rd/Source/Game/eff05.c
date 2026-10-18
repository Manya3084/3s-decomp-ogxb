/* Screen objects, retail sf33rd.xbe.
 * effect_05_move is 0xB68BD size 0x63 and is interior.
 * effect_05_init is 0xB6920 size 0x11F and is interior.
 * The init size runs through the or eax, -1 tail after its ret.
 * 0xB6890 stays unnamed.
 *
 * scr_obj_num is 0x283A60 and matches the 22 counts.
 * scr_obj_data is 0x332D20. Its 22 pointers and the s16 rows
 * they address match, including the shared dummy at 0x283A8C.
 * char_add is 0x332CC8. Those 22 pointers are Xbox addresses.
 * The bytes they point at were not compared. The rows were
 * not pasted.
 *
 * frw is 0xC806A0 and each object is 0x700 bytes.
 * bg_w.bg_index is 0x7BC550.
 * set_char_move_init is 0x200A9. all_cgps_put_back
 * stays sub_0004384A. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. suzi_offset_set stays
 * suzi_offset_set.
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
    u8 pad_cg[0x14];
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
    u8 pad_mp[0xA];
    s16 master_priority;
} WORK_Other;

typedef struct {
    u8 raw[0x30];
    s16 bg_index;
} BG;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, be_flag) == 0, "be_flag");
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz) == 0x64, "xyz");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, sync_suzi) == 0x76, "sync_suzi");
_Static_assert(__builtin_offsetof(WORK, dir_step) == 0x98, "dir_step");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_priority) == 0x392, "master_priority");
_Static_assert(__builtin_offsetof(BG, bg_index) == 0x30, "bg_index");
#endif

extern BG bg_w;
extern const s16 scr_obj_num[22];
extern const s16 *scr_obj_data[22];
extern u32 *char_add[22];
extern EffectRow frw[];

s32 obr_no_disp_check(void);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
s32 compel_dead_check(WORK_Other *ewk);
void disp_pos_trans_entry_s(WORK_Other *ewk);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void suzi_offset_set(WORK_Other *ewk);
s16 get_my_trans_mode(s16 curr);

void effect_05_move(WORK_Other *ewk) {
    if (obr_no_disp_check() == 0) {
        switch (ewk->wu.routine_no[0]) {
        case 0:
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
            break;

        case 1:
            if (compel_dead_check(ewk) != 0) {
                ewk->wu.routine_no[0]++;
                break;
            }

            disp_pos_trans_entry_s(ewk);
            break;

        default:
            sub_0004384A(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    }
}

s32 effect_05_init(void) {
    WORK_Other *ewk;
    s16 ix;
    s16 lp_cnt;
    s16 i;
    const s16 *data_ptr;

    lp_cnt = scr_obj_num[bg_w.bg_index];

    if (lp_cnt == 0) {
        return 0;
    }

    data_ptr = scr_obj_data[bg_w.bg_index];

    for (i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other *)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 5;
        ewk->wu.work_id = 0x10;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.char_table[0] = char_add[bg_w.bg_index];
        ewk->wu.type = i;
        ewk->wu.dead_f = *data_ptr++;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.sync_suzi = *data_ptr++;
        suzi_offset_set(ewk);
        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    }

    return 0;
}
