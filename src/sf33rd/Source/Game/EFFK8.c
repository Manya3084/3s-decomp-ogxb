/* Effect K8, retail sf33rd.xbe.
 * effect_K8_move is 0x50D7A size 0x125.
 * effect_K8_init is 0x50E9F size 0xA6.
 *
 * In effect_K8_move the dead_f path of case 1 falls into the case 2 code
 * for its disp_flag and routine_no stores. When now_koc or char_index
 * changes, routine_no[0] is set to 2 before the Bg_Y_Sitei call.
 * Case 0 stores position_z before my_priority.
 * effect_K8_init stores type and my_master first. The C keeps the PS2
 * order.
 * _plef_char_table is 0x308B40. seraph_flag is 0x7BC4F4.
 * base_y_pos is 0x7BC516. Game_pause is 0x7A89B0. EXE_flag is 0xC7C834.
 * frw is 0xC806A0, 0x700 bytes per object.
 * dir_old is +0x96. my_mr_flag is +0x24E. my_mr.size is +0x250.
 * set_char_move_init stays sub_000200A9. char_move stays sub_0002008E.
 * push_color_trans_req stays sub_000B61A0.
 * Bg_Y_Sitei is 0xB32A5. Bg_Disp_Switch is 0xAF601.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 * sort_push_request is 0x9DF9A.
 */

#include "types.h"

typedef struct {
    s16 x;
    s16 y;
} MRSize;

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
    u8 pad_rno[2];
    s16 routine_no[8];
    u8 pad_cgr[0x48 - 0x34];
    s8 cgromtype;
    u8 pad_pos[0x54 - 0x49];
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
    u8 pad_col[0x23C - 0x215];
    s16 my_col_mode;
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_mts[0x24C - 0x244];
    s16 my_mts;
    s16 my_mr_flag;
    MRSize my_mr_size;
    u8 pad_end[0x388 - 0x254];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, dir_old) == 0x96, "dir_old");
_Static_assert(__builtin_offsetof(WORK, dir_step) == 0x98, "dir_step");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, now_koc) == 0x206, "now_koc");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_mr_flag) == 0x24E, "my_mr_flag");
_Static_assert(__builtin_offsetof(WORK, my_mr_size.y) == 0x252, "my_mr_size");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

extern u32 _plef_char_table[];
extern u8 seraph_flag;
extern s16 base_y_pos;
extern u8 Game_pause;
extern u16 EXE_flag;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void sort_push_request(WORK *wk);
void Bg_Y_Sitei(u8 on_off, s16 pos);
void Bg_Disp_Switch(u8 on_off);
void sub_000200A9(WORK *wk, s16 koc, s32 index);
void sub_0002008E(WORK *wk);
void sub_000B61A0(s32 from_col, s32 to_col);

void effect_K8_move(WORK_Other *ewk) {
    WORK *mwk = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        seraph_flag = 1;
        Bg_Disp_Switch(1);
        ewk->wu.my_priority = ewk->wu.position_z = 67;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr_size.x = 127;
        ewk->wu.my_mr_size.y = 127;
        sub_000200A9(&ewk->wu, 0, 0x8F);
        break;

    case 1:
        if (ewk->wu.dead_f != 0) {
            Bg_Y_Sitei(0, 0);
            Bg_Disp_Switch(0);
            seraph_flag = 0;
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 3;
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);

            if (ewk->wu.dir_old != mwk->now_koc || ewk->wu.dir_step != mwk->char_index) {
                ewk->wu.routine_no[0] = 2;
                Bg_Y_Sitei(0, 0);
                seraph_flag = 0;
                Bg_Disp_Switch(0);
            }
        }

        sub_000B61A0(ewk->wu.cg_type + 0x62, ewk->wu.my_col_code);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_K8_init(WORK *wk, u8 data) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(5)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->my_master = (u32 *)wk;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 208;
    ewk->wu.type = data;
    ewk->wu.my_mts = 6;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 8;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 2;
    ewk->wu.position_x = -8;
    ewk->wu.position_y = 240 - base_y_pos;
    ewk->wu.dir_old = wk->now_koc;
    ewk->wu.dir_step = wk->char_index;
    *ewk->wu.char_table = _plef_char_table;
    return 0;
}
