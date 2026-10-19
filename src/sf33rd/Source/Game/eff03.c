/* Effect 03, retail sf33rd.xbe.
 * eff03_disp_pos is 0x325FA size 0x4E and is interior.
 * effect_03_init is 0x32648 size 0xCD and is interior.
 * effect_03_move is 0x32762 size 0x1CD and is interior.
 * The pull failure is an early ret.
 * 0x32715 stays unnamed. 0x3292F stays unnamed.
 *
 * plef_data is 0x24A690 and matches the 165 rows.
 * The rows were not pasted. The init stores type before
 * be_flag. The player path stores 1 for master_work_id.
 * Case 1 stores routine_no[0] before disp_flag. The C
 * keeps the PlayStation 2 order. The character table
 * immediate is 0x308B40. Those bytes were not compared.
 * Suicide is 0x7A8268. Pause_Hit_Marks is 0x7A88AC.
 * EXE_flag is 0xC7C834. Game_pause is 0x7A89B0.
 * char_move is 0x2008E.
 * set_char_move_init is 0x200A9.
 * sort_push_request is 0x9DF9A.
 * all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. frw is 0xC806A0
 * and each object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"



typedef struct {
    struct {
        s16 x;
        s16 y;
    } size;
} Mr;



typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(sizeof(PLEF) == 0x10, "PLEF");
_Static_assert(__builtin_offsetof(PLEF, sel_pri) == 6, "sel_pri");
_Static_assert(__builtin_offsetof(PLEF, sel_rl) == 7, "sel_rl");
_Static_assert(__builtin_offsetof(PLEF, color) == 8, "color");
_Static_assert(__builtin_offsetof(PLEF, sel_col) == 0xA, "sel_col");
_Static_assert(__builtin_offsetof(PLEF, dspf) == 0xB, "dspf");
_Static_assert(__builtin_offsetof(PLEF, ichi) == 0xC, "ichi");
_Static_assert(__builtin_offsetof(PLEF, mts) == 0xD, "mts");
_Static_assert(__builtin_offsetof(PLEF, chix) == 0xE, "chix");
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, blink_timing) == 2, "blink");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, rl_waza) == 0xB, "rl_waza");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, xyz[2].disp.pos) == 0x6E, "xyz2");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_mr_flag) == 0x24E, "my_mr_flag");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.x) == 0x250, "mr_x");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.y) == 0x252, "mr_y");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
_Static_assert(__builtin_offsetof(WORK_Other, master_work_id) == 0x38C, "mwid");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "mid");
#endif

extern EffectRow frw[];
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const PLEF plef_data[165] = { { 0, 0, -1, 0, 1, 0, 0, 1, 0, 0, 0 },       { 13, 0, -2, 0, 1, 0, 0, 1, 0, 0, 1 },
                              { 14, 2, 67, 1, 1, 32, 1, 1, 0, 0, 28 },    { -14, 2, 67, 1, 1, 32, 1, 1, 0, 0, 29 },
                              { 20, 2, 67, 1, 1, 32, 1, 1, 0, 0, 28 },    { -20, 2, 67, 1, 1, 32, 1, 1, 0, 0, 29 },
                              { 26, 2, 67, 1, 1, 32, 1, 1, 0, 0, 28 },    { -26, 2, 67, 1, 1, 32, 1, 1, 0, 0, 29 },
                              { 32, 2, 67, 1, 1, 32, 1, 1, 0, 0, 28 },    { -32, 2, 67, 1, 1, 32, 1, 1, 0, 0, 29 },
                              { 2, 44, -2, 0, 1, 32, 1, 1, 1, 0, 23 },    { 4, 78, -4, 0, 1, 0, 0, 1, 0, 0, 25 },
                              { 48, 54, -4, 0, 1, 0, 0, 1, 1, 0, 33 },    { 36, 54, -4, 0, 1, 0, 0, 1, 1, 0, 34 },
                              { 48, 54, -4, 0, 1, 0, 0, 1, 1, 0, 122 },   { 0, -16, -1, 0, 1, 0, 1, 1, 0, 0, 35 },
                              { 26, 0, 2, 0, 1, 32, 1, 1, 0, 0, 6 },      { 0, 4, -1, 0, 1, 32, 1, 1, 0, 0, 28 },
                              { 16, 0, -1, 0, 1, 32, 1, 1, 0, 0, 32 },    { 24, 6, -1, 0, 1, 32, 1, 1, 0, 0, 32 },
                              { -32, 2, -1, 0, 1, 32, 1, 1, 0, 0, 52 },   { -24, 8, -4, 0, 1, 32, 1, 1, 0, 0, 52 },
                              { 24, 8, -1, 0, 1, 32, 1, 1, 0, 0, 32 },    { 24, 2, -1, 0, 1, 32, 1, 1, 0, 0, 32 },
                              { -24, 4, -1, 0, 1, 32, 1, 1, 0, 0, 61 },   { -36, 0, -2, 0, 1, 32, 1, 1, 0, 0, 61 },
                              { -20, 0, -4, 0, 1, 32, 1, 1, 0, 0, 29 },   { 72, 2, -1, 0, 1, 32, 1, 1, 0, 0, 63 },
                              { 52, -4, -1, 0, 1, 32, 1, 1, 0, 0, 68 },   { 0, 0, -2, 0, 1, 32, 1, 1, 1, 0, 23 },
                              { 0, 0, -2, 0, 1, 32, 1, 1, 1, 0, 23 },     { 0, 0, -2, 0, 1, 32, 1, 1, 1, 0, 23 },
                              { 0, 0, -2, 0, 1, 32, 1, 1, 1, 0, 23 },     { 56, 0, -2, 0, 1, 0, 0, 1, 0, 0, 44 },
                              { 56, 0, -2, 0, 1, 0, 0, 1, 0, 0, 45 },     { 16, 0, 24, 1, 1, 32, 1, 1, 0, 0, 155 },
                              { 38, 0, -1, 0, 1, 0, 1, 1, 0, 0, 48 },     { 16, 0, -1, 0, 1, 32, 1, 1, 0, 0, 47 },
                              { 14, 0, -1, 0, 1, 32, 1, 1, 0, 0, 28 },    { -38, -23, -4, 0, 1, 0, 0, 1, 0, 0, 59 },
                              { -114, 128, -2, 0, 1, 0, 0, 1, 0, 0, 60 }, { -46, 2, -2, 0, 1, 32, 1, 1, 0, 0, 61 },
                              { -34, 2, -1, 0, 1, 32, 1, 1, 0, 0, 52 },   { 32, 2, 67, 1, 1, 32, 1, 1, 0, 0, 28 },
                              { 0, 2, 67, 1, 1, 32, 1, 1, 0, 0, 29 },     { 108, 88, -2, 0, 1, 0, 0, 1, 0, 0, 64 },
                              { 108, 168, -2, 0, 1, 0, 0, 1, 0, 0, 73 },  { 0, 0, 24, 1, 1, 0, 0, 2, 0, 0, 65 },
                              { 25, 0, 24, 1, 1, 32, 1, 1, 0, 0, 66 },    { 25, 0, 24, 1, 1, 32, 1, 1, 0, 0, 67 },
                              { 25, 0, 24, 1, 1, 32, 1, 1, 0, 0, 68 },    { -14, 0, -1, 0, 1, 32, 1, 1, 0, 0, 47 },
                              { 124, 96, -2, 0, 1, 0, 0, 1, 0, 0, 64 },   { 124, 176, -2, 0, 1, 0, 0, 1, 0, 0, 73 },
                              { 140, 104, -2, 0, 1, 0, 0, 1, 0, 0, 64 },  { 140, 184, -2, 0, 1, 0, 0, 1, 0, 0, 73 },
                              { 40, -2, -2, 0, 1, 32, 1, 1, 0, 0, 69 },   { 64, -2, 66, 1, 1, 32, 1, 1, 0, 0, 70 },
                              { -16, 0, 68, 1, 1, 32, 1, 1, 0, 0, 52 },   { -84, 0, 2, 0, 1, 0, 0, 2, 0, 0, 71 },
                              { 84, 0, 2, 0, 1, 0, 0, 2, 0, 0, 72 },      { -84, 0, 2, 0, 1, 0, 0, 2, 0, 0, 90 },
                              { 84, 0, 2, 0, 1, 0, 0, 2, 0, 0, 91 },      { 0, 0, 1, 0, 1, 32, 1, 2, 0, 0, 21 },
                              { 0, 0, 1, 0, 1, 32, 1, 2, 0, 0, 22 },      { 0, 0, 1, 0, 1, 32, 1, 2, 0, 0, 30 },
                              { 0, 0, 1, 0, 1, 32, 1, 2, 0, 0, 31 },      { 0, 0, 2, 1, 1, 0, 1, 1, 0, 0, 163 },
                              { -14, 0, -1, 0, 1, 32, 1, 1, 0, 0, 47 },   { 0, 16, -2, 0, 0, 32, 1, 2, 0, 0, 30 },
                              { 0, 12, -2, 0, 0, 32, 1, 2, 0, 0, 30 },    { 0, 0, -2, 0, 1, 0, 1, 1, 0, 0, 78 },
                              { 0, 0, -2, 0, 1, 0, 1, 1, 0, 0, 79 },      { 32, 0, -2, 0, 1, 0, 1, 1, 0, 0, 80 },
                              { 32, -2, 67, 1, 1, 32, 1, 1, 0, 0, 28 },   { -32, -2, 67, 1, 1, 32, 1, 1, 0, 0, 29 },
                              { 8, 0, 67, 1, 1, 32, 1, 1, 0, 0, 82 },     { -8, 0, 67, 1, 1, 32, 1, 1, 0, 0, 83 },
                              { 0, 0, 67, 1, 1, 0, 0, 1, 0, 0, 81 },      { 0, 0, -2, 0, 1, 0, 0, 1, 0, 0, 84 },
                              { 32, -2, 67, 1, 1, 32, 1, 1, 0, 0, 28 },   { -32, -2, 67, 1, 1, 32, 1, 1, 0, 0, 29 },
                              { 12, 4, -2, 0, 1, 0, 1, 1, 0, 0, 80 },     { 32, 6, -2, 0, 1, 0, 1, 1, 0, 0, 88 },
                              { 44, 8, -2, 0, 1, 0, 1, 1, 0, 0, 89 },     { 32, -2, 67, 1, 1, 32, 1, 1, 0, 0, 28 },
                              { -32, -2, 67, 1, 1, 32, 1, 1, 0, 0, 29 },  { -44, -4, -1, 0, 1, 32, 1, 1, 0, 0, 61 },
                              { 40, 48, 24, 1, 1, 7, 0, 1, 0, 0, 115 },   { 2, 96, 24, 1, 1, 7, 0, 1, 0, 0, 114 },
                              { 60, 24, 24, 1, 1, 7, 0, 1, 0, 0, 115 },   { 78, 80, 24, 1, 1, 7, 0, 1, 0, 0, 114 },
                              { 32, 44, 24, 1, 1, 7, 0, 1, 0, 0, 115 },   { 24, 4, 24, 1, 1, 7, 0, 1, 0, 0, 114 },
                              { 48, 92, 24, 1, 1, 7, 0, 1, 0, 0, 115 },   { 2, 64, 24, 1, 1, 7, 0, 1, 0, 0, 114 },
                              { 80, 32, 24, 1, 1, 7, 0, 1, 0, 0, 115 },   { 44, 8, 24, 1, 1, 7, 0, 1, 0, 0, 114 },
                              { 28, 76, 24, 1, 1, 7, 0, 1, 0, 0, 115 },   { 68, 64, 24, 1, 1, 7, 0, 1, 0, 0, 114 },
                              { 16, 32, 24, 1, 1, 7, 0, 1, 0, 0, 115 },   { 52, 30, 24, 1, 1, 7, 0, 1, 0, 0, 114 },
                              { 30, 64, 24, 1, 1, 7, 0, 1, 0, 0, 115 },   { 8, 0, 2, 0, 1, 32, 1, 1, 0, 0, 166 },
                              { 50, 0, 2, 0, 1, 32, 1, 1, 0, 0, 6 },      { 32, -23, -4, 0, 1, 0, 0, 1, 0, 0, 59 },
                              { -16, -14, 24, 1, 1, 7, 1, 1, 0, 0, 116 }, { 96, 56, -4, 0, 1, 0, 0, 1, 0, 0, 167 },
                              { -36, 0, -2, 0, 1, 32, 1, 1, 0, 0, 61 },   { 72, -2, 2, 0, 1, 32, 1, 1, 0, 0, 6 },
                              { -24, 0, -2, 0, 1, 32, 1, 2, 1, 0, 120 },  { 0, 0, -2, 0, 1, 0, 0, 1, 0, 0, 169 },
                              { 0, 0, -2, 0, 1, 6, 0, 1, 0, 0, 134 },     { 0, 0, 2, 0, 1, 6, 0, 1, 0, 0, 135 },
                              { -8, 0, 2, 0, 1, 6, 0, 1, 0, 0, 136 },     { 40, 48, 24, 1, 1, 7, 1, 1, 0, 0, 115 },
                              { 2, 96, 24, 1, 1, 7, 1, 1, 0, 0, 114 },    { 60, 24, 24, 1, 1, 7, 1, 1, 0, 0, 115 },
                              { 78, 80, 24, 1, 1, 7, 1, 1, 0, 0, 114 },   { 32, 44, 24, 1, 1, 7, 1, 1, 0, 0, 115 },
                              { 24, 4, 24, 1, 1, 7, 1, 1, 0, 0, 114 },    { 48, 92, 24, 1, 1, 7, 1, 1, 0, 0, 115 },
                              { 2, 64, 24, 1, 1, 7, 1, 1, 0, 0, 114 },    { 80, 32, 24, 1, 1, 7, 1, 1, 0, 0, 115 },
                              { 44, 8, 24, 1, 1, 7, 1, 1, 0, 0, 114 },    { 28, 76, 24, 1, 1, 7, 1, 1, 0, 0, 115 },
                              { 68, 64, 24, 1, 1, 7, 1, 1, 0, 0, 114 },   { 16, 32, 24, 1, 1, 7, 1, 1, 0, 0, 115 },
                              { 52, 30, 24, 1, 1, 7, 1, 1, 0, 0, 114 },   { 30, 64, 24, 1, 1, 7, 1, 1, 0, 0, 115 },
                              { 8, -7, 67, 1, 1, 32, 1, 1, 0, 0, 28 },    { -32, -7, 67, 1, 1, 32, 1, 1, 0, 0, 29 },
                              { 0, -5, -2, 0, 0, 300, 1, 1, 0, 0, 140 },  { 0, -7, -2, 0, 0, 300, 1, 1, 0, 0, 141 },
                              { 0, 0, -1, 0, 1, 0, 0, 1, 0, 0, 142 },     { -12, -4, -1, 0, 1, 32, 1, 1, 0, 0, 61 },
                              { -32, -4, -4, 0, 1, 32, 1, 1, 0, 0, 61 },  { 0, -4, -4, 0, 1, 32, 1, 1, 0, 0, 61 },
                              { -7, 109, 24, 1, 1, 7, 0, 1, 0, 0, 147 },  { 8, 96, 33, 1, 0, 1, 0, 1, 0, 0, 144 },
                              { 56, 29, 24, 1, 1, 7, 0, 1, 0, 0, 145 },   { 20, 0, 1, 0, 1, 32, 1, 2, 0, 0, 146 },
                              { 72, 56, -4, 0, 1, 0, 0, 1, 0, 0, 170 },   { 42, -2, 67, 1, 1, 32, 1, 1, 0, 0, 28 },
                              { -22, -2, 67, 1, 1, 32, 1, 1, 0, 0, 29 },  { 16, 78, -10, 1, 1, 4, 0, 1, 1, 0, 148 },
                              { 31, 60, 24, 1, 1, 4, 0, 1, 0, 0, 171 },   { 0, 0, 67, 1, 1, 4, 0, 1, 0, 0, 149 },
                              { 41, -3, -1, 0, 1, 32, 1, 1, 0, 0, 172 },  { 54, 0, -1, 0, 1, 4, 0, 1, 0, 0, 150 },
                              { 50, 92, -10, 0, 1, 7, 0, 1, 1, 0, 151 },  { 7, 4, 67, 0, 0, 32, 1, 1, 0, 0, 28 },
                              { -7, 4, 67, 0, 0, 32, 1, 1, 0, 0, 29 },    { -32, 0, -1, 0, 1, 32, 1, 1, 0, 0, 52 },
                              { 36, 20, -10, 1, 1, 4, 0, 1, 1, 0, 148 },  { 0, 0, 24, 1, 1, 4, 0, 2, 0, 0, 173 },
                              { 0, 0, 67, 1, 1, 4, 0, 1, 0, 0, 174 },     { 7, 4, 67, 0, 0, 32, 1, 1, 0, 0, 28 },
                              { -7, 4, 67, 0, 0, 32, 1, 1, 0, 0, 29 },    { 0, 0, 1, 0, 1, 32, 1, 2, 0, 0, 152 },
                              { -10, 32, -1, 0, 0, 32, 1, 1, 1, 0, 57 },  { -20, -8, -1, 0, 0, 32, 1, 1, 1, 0, 57 },
                              { 16, -4, -1, 0, 0, 32, 1, 1, 1, 0, 57 },   { -37, 4, -1, 0, 0, 32, 1, 1, 1, 0, 58 },
                              { 44, 1, -1, 0, 0, 32, 1, 1, 1, 0, 58 } };

extern u32 _plef_char_table[];
extern s8 Suicide[8];
extern u8 Pause_Hit_Marks;
extern s16 EXE_flag;
extern u8 Game_pause;

void eff03_disp_pos(WORK *ewk, WORK *mwk);
void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sort_push_request(WORK *wk);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

void effect_03_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = plef_data[ewk->wu.type].dspf;
        ewk->wu.blink_timing = ewk->master_id;

        if (plef_data[ewk->wu.type].sel_rl) {
            ewk->wu.rl_flag = ewk->wu.rl_waza;
        }

        if (ewk->wu.rl_flag) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos + plef_data[ewk->wu.type].hx;
        } else {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos - plef_data[ewk->wu.type].hx;
        }

        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos + plef_data[ewk->wu.type].hy;
        ewk->wu.position_z = ewk->wu.xyz[2].disp.pos + plef_data[ewk->wu.type].hz;

        if (plef_data[ewk->wu.type].sel_pri) {
            ewk->wu.position_z = plef_data[ewk->wu.type].hz;
        }

        if (plef_data[ewk->wu.type].sel_col) {
            ewk->wu.my_col_code = plef_data[ewk->wu.type].color | 0x2000;
        } else {
            ewk->wu.my_col_code += plef_data[ewk->wu.type].color;
        }

        ewk->wu.my_mts = 14;
        set_char_move_init(&ewk->wu, 0, plef_data[ewk->wu.type].chix);

        if (plef_data[ewk->wu.type].ichi) {
            ewk->wu.xyz[0].disp.pos = plef_data[ewk->wu.type].hx;
            ewk->wu.xyz[1].disp.pos = plef_data[ewk->wu.type].hy;
            ewk->wu.xyz[2].disp.pos = plef_data[ewk->wu.type].hz;

            if (ewk->wu.rl_flag == 0) {
                ewk->wu.xyz[0].disp.pos = -ewk->wu.xyz[0].disp.pos;
            }
        } else {
            ewk->wu.xyz[0].disp.pos = ewk->wu.position_x;
            ewk->wu.xyz[1].disp.pos = ewk->wu.position_y;
            ewk->wu.xyz[2].disp.pos = ewk->wu.position_z;
        }

        if (ewk->wu.type == 146) {
            ewk->wu.my_mr_flag = 1;
            ewk->wu.my_mr.size.x = 127;
            ewk->wu.my_mr.size.y = 63;
        }

        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        if (Pause_Hit_Marks) {
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type) {
                if (ewk->wu.cg_type == 0xFF) {
                    ewk->wu.disp_flag = 0;
                    ewk->wu.routine_no[0]++;
                    break;
                }

                ewk->wu.disp_flag = 2;
            }
        }

        eff03_disp_pos(&ewk->wu, (WORK *)ewk->my_master);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff03_disp_pos(WORK *ewk, WORK *mwk) {
    if (plef_data[ewk->type].ichi) {
        ewk->position_x = mwk->position_x + ewk->xyz[0].disp.pos;
        ewk->position_y = mwk->position_y + ewk->xyz[1].disp.pos;
        ewk->position_z = mwk->position_z + ewk->xyz[2].disp.pos;
        return;
    }

    ewk->position_x = ewk->xyz[0].disp.pos;
    ewk->position_y = ewk->xyz[1].disp.pos;
}

s32 effect_03_init(WORK *wk, u8 data) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 3;
    ewk->wu.work_id = 16;
    ewk->wu.type = data;
    ewk->wu.rl_waza = wk->rl_flag;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.cgromtype = wk->cgromtype;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code;
    ewk->my_master = (u32 *)wk;

    if (wk->work_id == 1) {
        ewk->master_work_id = wk->work_id;
        ewk->master_id = wk->id;
    } else {
        ewk->master_work_id = ((WORK_Other *)wk)->master_work_id;
        ewk->master_id = ((WORK_Other *)wk)->master_id;
    }

    ewk->wu.xyz[0].disp.pos = wk->position_x;
    ewk->wu.xyz[1].disp.pos = wk->position_y;
    ewk->wu.xyz[2].disp.pos = wk->position_z;
    ewk->wu.char_table[0] = _plef_char_table;
    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_03_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.dead_f != 1 && Suicide[0] == 0 && Pause_Hit_Marks == 0 && (EXE_flag != 0 || Game_pause != 0)) {
            eff03_disp_pos(&ewk->wu, (WORK*)ewk->my_master);
            sort_push_request(&ewk->wu);
        }

        break;
    }
}
