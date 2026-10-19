/* Effect 09, retail sf33rd.xbe.
 * effect_09_move is 0x32EC3 size 0x29 and is interior.
 * eff09_0000 is 0x32EEC size 0x8F and is interior.
 * eff09_1000 is 0x32F7B size 0x133 and is interior.
 * sean_ball_move is 0x330AE size 0xF1 and is interior.
 * ball_bound_set is 0x3319F size 0x48 and is interior.
 * eff09_3000 is 0x331E7 size 0x103 and is interior.
 * eff09_4000 is 0x332EA size 0x129 and is interior.
 * eff09_5000 is 0x33413 size 0x6B and is interior.
 * eff09_6000 is 0x3347E size 0x8D and is interior.
 * eff09_7000 is 0x3350B size 0xBB and is interior.
 * eff09_8000 is 0x335C6 size 0x72 and is interior.
 * eff09_9000 is 0x33638 size 0x89 and is interior.
 * eff09_10000 is 0x336C1 size 0xA0 and is interior.
 * eff09_11000 is 0x33761 size 0x134 and is interior.
 * eff09_12000 is 0x33895 size 0xEA and is interior.
 * eff09_13000 is 0x3397F size 0x139 and is interior.
 * eff09_14000 is 0x33AB8 size 0xCA and is interior.
 * eff09_15000 is 0x33B82 size 0xA5 and is interior.
 * eff09_16000 is 0x33C27 size 0x9B and is interior.
 * eff09_17000 is 0x33CC2 size 0xCE and is interior.
 * eff09_18000 is 0x33D90 size 0x12D and is interior.
 * eff09_19000 is 0x33EBD size 0x13F and is interior.
 * eff09_20000 is 0x33FFC size 0xD1 and is interior.
 * eff09_21000 is 0x340CD size 0x184 and is interior.
 * eff09_22000 is 0x34251 size 0xFC and is interior.
 * eff09_23000 is 0x3434D size 0x127 and is interior.
 * eff09_24000 is 0x34474 size 0x138 and is interior.
 * eff09_25000 is 0x345AC size 0x108 and is interior.
 * jijii_win_tama_sub is 0x346B4 size 0x29 and is interior.
 * eff09_27000 is 0x346DD size 0x12F and is interior.
 * eff09_26000 is 0x34DF8 size 0x137 and is interior.
 * effect_09_init is 0x3480C size 0xF3 and is interior.
 * effect_09_init2 is 0x348FF size 0x26A and is interior.
 * eff09_2000 is 0x34B69 size 0x28F and is a scanned start.
 * 0x32C0D stays unnamed.
 * 0x34F2F is effect_10_move.
 *
 * Case 0 stores disp_flag, and sometimes dead_f, the
 * kage fields, or old_rno[0], between the pushes and
 * the call. eff09_1000 stores position_z before
 * my_priority. eff09_4000 and eff09_11000 store the
 * x position and old_rno[0] between the speed pushes
 * and the call. ball_bound_set stores the negated
 * constants when rl_flag is set. eff09_7000 stores
 * a[1] and d[1] before the master_id test.
 * eff09_12000 selects a[0] without a branch.
 * eff09_16000 adds 2 to x before the routine store
 * and stores rl_flag between the pushes and the
 * call. eff09_17000 adds or subtracts 32. The
 * PlayStation 2 source reads eff09_data2[21][2],
 * which is -32. The C keeps the PlayStation 2
 * order except for that add.
 * eff09_18000 stores old_rno[1] between the speed
 * pushes and the call. It reads wxy and pos_offset
 * as dwords and keeps the low word.
 * eff09_19000 omits the unused master load. It
 * stores d[1] and the routine between the push
 * and the call. eff09_20000 omits the test_flag
 * test. It stores kage_prio and kage_char between
 * the pushes and the call. It reads wxy and
 * pos_offset as dwords and keeps the low word.
 * eff09_21000 checks Suicide[0] before the switch.
 * eff09_22000, eff09_23000, eff09_24000, and
 * eff09_26000 omit the test_flag test.
 * eff09_22000 stores the routine between the
 * pushes and the call when the master cg_type
 * is 99. eff09_23000 selects a[0] without a
 * branch and stores d[0] before that select.
 * eff09_24000 stores case 0 before the pushes
 * and returns without the player entry.
 * eff09_25000 omits the unused master load.
 * eff09_26000 stores the routine, disp_flag,
 * and dead_f between the pushes and the call.
 * eff09_27000 stores the setup before the
 * pushes and writes the positive a[0] when
 * rl_flag is set. The C keeps the PlayStation 2
 * order.
 * effect_09_init omits the dead my_priority = 64.
 * It stores cgromtype, rl_flag, my_col_mode, the
 * character table, hit_stop, and sync_suzi between
 * the push and suzi_offset_set. It stores my_mts
 * between the push and get_my_trans_mode. The pull
 * failure is an early ret. eff09_data is 0x24B1D0
 * and matches the 2 rows. The rows were not pasted.
 * The character table immediate is 0x2F5250. Those
 * bytes were not compared. effect_09_init2 stores
 * sync_suzi between the push and suzi_offset_set.
 * Case 34 falls through. push_color_trans_req stays
 * push_color_trans_req. test_flag is the byte at 0x7A8902.
 * bg_w.stage is the byte at 0x7BC523. The character
 * table immediate is 0x2F9850. Those bytes were not
 * compared. The pull failure is an early ret. The C
 * keeps the PlayStation 2 order.
 * eff09_2000 stores disp_flag between the pushes and
 * the call. It stores old_rno from index 3 down to 0.
 * The player-switch select is branchless. The second
 * random_16 result is unused, so the mask of 7 is
 * omitted. Appear_free = 2 is stored between the push
 * and effect_B4_init. The C keeps the PlayStation 2
 * order. eff09_2000_data is 0x24B4A8 and matches the
 * 2 rows. sean_ball_hit is 0x24B4F8 and matches the
 * 4 words. The rows were not pasted. Appear_free is
 * 0x7BCC80. p1sw_0 is 0x7C557C. p2sw_0 is 0x7C5B90.
 * h_bod is +0x284. sa is +0x3C4. metamorphose is
 * +0x445. hit_check_subroutine is 0x5F40D.
 * effect_B4_init is 0x4411C.
 * add_super_arts_gauge is 0x936BF.
 *
 * eff09_data2 is 0x24B1F8 and matches the 43 rows.
 * eff09_add_tbl0 is 0x24B4C8. eff09_add_tbl1 is
 * 0x24B4D8. eff09_add_tbl2 is 0x24B4E8. All three
 * match. eff09_13_tbl is 0x24B500 and matches the
 * 3 rows. eff09_19000_tbl is 0x24B530 and matches
 * the 3 rows. The rows were not pasted. The move table
 * at 0x32AA38 is not named.
 *
 * base_y_pos is 0x7BC516. bg_w is 0x7BC520.
 * bgw[1].xy[0].disp.pos is 0x7BC602.
 * bgw[1].wxy[0].disp.pos is 0x7BC60A.
 * bgw[1].pos_x_work is 0x7BC630.
 * pos_offset is 0x7BC53C.
 * plw is 0xC7CEA0, stride 0x46C, operator at +3.
 * Exec_Wipe is 0x7A82F9. Winner_id is 0x7A8472.
 * EXE_flag is 0xC7C834. Game_pause is 0x7A89B0.
 * EXE_obroll is 0x7A8111.
 * compel_dead_check, obr_no_disp_check,
 * disp_pos_trans_entry_s, disp_pos_trans_entry_rs,
 * and eff_hit_check are named.
 * char_move is 0x2008E.
 * set_char_move_init is 0x200A9.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * add_x_sub2 shares add_x_sub.
 * add_y_sub2 shares add_y_sub.
 * disp_pos_trans_entry is folded into 0xEF0C0.
 * suzi_sync_pos_set is 0xB3627.
 * sort_push_request is 0x9DF9A.
 * sort_push_request4 is 0x9E092.
 * push_effect_work is 0x4AC6C.
 * random_16 is 0x9326B.
 * Sound_SE stays BGM_Request.
 * cal_all_speed_data is 0x1D4D7.
 * Suicide is 0x7A8268.
 * set_char_move_init2 is 0x201B9.
 * char_move_z is 0x202CE.
 * range_x_check3 and pl_eff_trans_entry are named.
 * suzi_offset_set is 0xB4052.
 * pull_effect_work is 0x4A6A8.
 * get_my_trans_mode is named.
 * frw is 0xC806A0 and each object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"


typedef union {
    s32 sp;
} Reg32;



typedef struct {
    s16 body_dm[4][4];
} HitBody;

typedef struct {
    struct {
        s16 x;
        s16 y;
    } size;
} Mr;






#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, blink_timing) == 2, "blink_timing");
_Static_assert(__builtin_offsetof(WORK, operator) == 3, "operator");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, kage_flag) == 0x49, "kage_flag");
_Static_assert(__builtin_offsetof(WORK, kage_hx) == 0x4A, "kage_hx");
_Static_assert(__builtin_offsetof(WORK, kage_hy) == 0x4C, "kage_hy");
_Static_assert(__builtin_offsetof(WORK, kage_prio) == 0x4E, "kage_prio");
_Static_assert(__builtin_offsetof(WORK, kage_char) == 0x52, "kage_char");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[0].sp) == 0x7C, "a0");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[1].sp) == 0x80, "a1");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[0].sp) == 0x84, "d0");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[1].sp) == 0x88, "d1");
_Static_assert(__builtin_offsetof(WORK, dir_step) == 0x98, "dir_step");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, cmwk) == 0x16A, "cmwk");
_Static_assert(__builtin_offsetof(WORK, cg_ix) == 0x204, "cg_ix");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cgd_type) == 0x20C, "cgd_type");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, target_adrs) == 0xC, "target_adrs");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, sync_suzi) == 0x76, "sync_suzi");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_mr_flag) == 0x24E, "my_mr_flag");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.x) == 0x250, "mr_x");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.y) == 0x252, "mr_y");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(__builtin_offsetof(WORK, h_bod) == 0x284, "h_bod");
_Static_assert(__builtin_offsetof(PLW, sa) == 0x3C4, "sa");
_Static_assert(__builtin_offsetof(PLW, metamorphose) == 0x445, "metamorphose");
_Static_assert(__builtin_offsetof(BG, stage) == 3, "bg_w.stage");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BGW, xy[0].disp.pos) == 0x1A, "bg xy");
_Static_assert(__builtin_offsetof(BGW, pos_x_work) == 0x48, "pos_x_work");
_Static_assert(__builtin_offsetof(BG, bgw[1].xy[0].disp.pos) == 0xE2, "bgw1");
_Static_assert(__builtin_offsetof(BG, bgw[1].pos_x_work) == 0x110, "bgw1x");
_Static_assert(__builtin_offsetof(BGW, wxy[0].disp.pos) == 0x22, "wxy");
_Static_assert(__builtin_offsetof(BG, pos_offset) == 0x1C, "pos_offset");
_Static_assert(__builtin_offsetof(BG, bgw[1].wxy[0].disp.pos) == 0xEA, "bgw1w");
#endif

extern PLW plw[2];
extern BG bg_w;
extern s16 base_y_pos;
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;
extern s8 Exec_Wipe;
extern s8 Winner_id;
extern s8 Suicide[8];
typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

extern EffectRow frw[];
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s16 eff09_data[2][9] = { { 0, 2, 8492, 832, 192, 10, 0, 1, 0 }, { 19, 2, 8492, 528, 108, 78, 1, 0, 0 } };

const s16 eff09_data2[43][8] = {
    { 1, 0, 0, 4, 1, 25, 1, 0 },       { 2, 0, -34, 153, -10, 26, 1, 0 }, { 3, 6, 48, 240, -1, 99, 1, 0 },
    { 4, 0, 48, -4, -10, 28, 1, 0 },   { 5, 0, 10, 96, -20, 46, 1, 0 },   { 6, 0, 0, 0, -20, 47, 1, 0 },
    { 7, 0, 0, 80, -10, 43, 1, 0 },    { 0, 0, -38, 84, -2, 41, 1, 0 },   { 8, 0, 0, 0, -2, 55, 1, 0 },
    { 8, 0, 0, 0, -2, 56, 1, 0 },      { 9, 0, 0, 0, -12, 71, 1, 0 },     { 9, 0, 0, 0, -12, 72, 1, 0 },
    { 10, 0, 0, 0, -12, 73, 1, 0 },    { 11, 0, 48, -10, -10, 28, 1, 0 }, { 12, 0, 0, 74, 2, 75, 1, 0 },
    { 13, 0, -4, 154, -2, 80, 1, 0 },  { 13, 0, -32, 112, -2, 81, 1, 0 }, { 13, 0, 16, 122, -2, 82, 1, 0 },
    { 14, 26, 45, 0, -16, 84, 1, 0 },  { 14, 26, 12, 0, -16, 84, 1, 0 },  { 15, 0, -18, 62, -2, 85, 1, 0 },
    { 17, 0, -32, 72, -2, 85, 1, 0 },  { 16, 0, 0, 0, -12, 87, 1, 0 },    { 18, 0, 0, 0, 1, 96, 1, 0 },
    { 20, 0, 160, 45, 10, 20, 1, 0 },  { 20, 0, 192, 45, 10, 21, 1, 0 },  { 20, 0, 208, 45, 10, 22, 1, 0 },
    { 20, 0, 176, 45, 10, 23, 1, 0 },  { 5, 0, 30, 3, 2, 48, 1, 0 },      { 21, 0, -24, 136, -2, 51, 1, 0 },
    { 21, 0, -24, 136, -2, 51, 1, 0 }, { 0, 26, 34, 42, -2, 60, 1, 0 },   { 22, 0, 0, 0, -2, 61, 1, 0 },
    { 23, 0, 72, -5, 2, 63, 1, 0 },    { 24, 0, -96, 8, 4, 97, 1, 0 },    { 24, 0, 80, 4, 3, 98, 1, 0 },
    { 25, 0, 68, 40, 1, 26, 1, 0 },    { 25, 0, 42, 51, 1, 26, 1, 0 },    { 24, 0, -432, 4, 3, 98, 1, 0 },
    { 24, 0, -192, 8, 4, 88, 1, 0 },   { 24, 0, -304, 8, 4, 97, 1, 0 },   { 26, 6, 0, 0, 1, 101, 1, 0 },
    { 27, 0, 0, 16, -10, 107, 1, 0 }
};

const s32 eff09_2000_data[2][4] = { { -0x10000, 0x50000, -0x1000, -0x6000 }, { -0x50000, 0x60000, -0xC00, -0x6000 } };

const s32 eff09_add_tbl0[2][2] = { { 0x800, -0x800 }, { 0x800, -0x1000 } };

const s32 eff09_add_tbl1[2][2] = { { -0x800, 0x800 }, { -0x1200, 0x1000 } };

const s32 eff09_add_tbl2[2][2] = { { -0x800, 0x800 }, { -0x1000, 0x1200 } };

const s16 sean_ball_hit[4] = { -16, 32, -11, 22 };

const s32 eff09_13_tbl[3][4] = { { 0x0, 0x1000, 0x30000, 0x0 },
                                 { 0x48000, 0x1000, 0x28000, 0x0 },
                                 { -0x48000, -0x1000, 0x28000, 0x0 } };

const s32 eff09_19000_tbl[3][4] = { { 0x30000, 0x0, 0x10000, -0x6000 },
                                    { 0x20000, 0x0, 0x48000, -0x6000 },
                                    { 0x18000, 0x0, 0x30000, -0x6000 } };

extern u32 _eff09_char_table[];
extern u32 _etc_char_table[];
extern u8 test_flag;
extern s8 Appear_free[2];
extern u16 p1sw_0;
extern u16 p2sw_0;
void eff09_0000(WORK_Other*);
void eff09_1000(WORK_Other*);
void eff09_2000(WORK_Other*);
void eff09_3000(WORK_Other*);
void eff09_4000(WORK_Other*);
void eff09_5000(WORK_Other*);
void eff09_6000(WORK_Other*);
void eff09_7000(WORK_Other*);
void eff09_8000(WORK_Other*);
void eff09_9000(WORK_Other*);
void eff09_10000(WORK_Other*);
void eff09_11000(WORK_Other*);
void eff09_12000(WORK_Other*);
void eff09_13000(WORK_Other*);
void eff09_14000(WORK_Other*);
void eff09_15000(WORK_Other*);
void eff09_16000(WORK_Other*);
void eff09_17000(WORK_Other*);
void eff09_18000(WORK_Other*);
void eff09_19000(WORK_Other*);
void eff09_20000(WORK_Other*);
void eff09_21000(WORK_Other*);
void eff09_22000(WORK_Other*);
void eff09_23000(WORK_Other*);
void eff09_24000(WORK_Other*);
void eff09_25000(WORK_Other*);
void eff09_26000(WORK_Other*);
void eff09_27000(WORK_Other*);
/* Pasted from the PS2 file. */
void (*eff09_tbl[28])(WORK_Other*) = { eff09_0000,  eff09_1000,  eff09_2000,  eff09_3000,  eff09_4000,  eff09_5000,
                                       eff09_6000,  eff09_7000,  eff09_8000,  eff09_9000,  eff09_10000, eff09_11000,
                                       eff09_12000, eff09_13000, eff09_14000, eff09_15000, eff09_16000, eff09_17000,
                                       eff09_18000, eff09_19000, eff09_20000, eff09_21000, eff09_22000, eff09_23000,
                                       eff09_24000, eff09_25000, eff09_26000, eff09_27000 };

s32 compel_dead_check(WORK_Other *ewk);
s32 obr_no_disp_check(void);
void disp_pos_trans_entry_s(WORK_Other *ewk);
void disp_pos_trans_entry_rs(WORK_Other *ewk);
void sub_000EF0C0(WORK_Other *ewk);
s16 eff_hit_check(WORK_Other *ewk, s16 type);
void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sub_000EF072(WORK_Other *ewk);
void sub_000EF088(WORK_Other *ewk);
void suzi_sync_pos_set(WORK_Other *ewk);
void sort_push_request(WORK *wk);
void sort_push_request4(WORK *wk);
void push_effect_work(WORK *wk);
s16 random_16(void);
void sub_00098407(s16 code);
void cal_all_speed_data(WORK *wk, s16 tm, s16 tx, s16 ty, s16 ax, s16 ay);
void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void char_move_z(WORK *wk);
s32 range_x_check3(WORK_Other *ewk, s16 rad);
void pl_eff_trans_entry(WORK_Other *ewk);
s16 pull_effect_work(s16 index);
void suzi_offset_set(WORK_Other *ewk);
s16 get_my_trans_mode(s16 curr);
void push_color_trans_req(s32 from_col, s32 to_col);
s16 hit_check_subroutine(WORK *wk1, WORK *wk2, const s16 *hd1, const s16 *hd2);
void effect_B4_init(WORK_Other *ewk);
void add_super_arts_gauge(SA_WORK *wk, s16 ix, s16 asag, u8 mf);

/* Xbox-only: the drawing half of effect 09. xb_effect_09_draw (0x32C0D)
 * calls the draw routine for routine_no[0] from the table at 0x32AAA8,
 * laid out like eff09_tbl; each routine pushes the sprite for the move
 * routine of the same number. Written from the x86; not all build to its
 * bytes. */
s32 range_x_check(WORK_Other* ewk);
void disp_pos_trans_entry(WORK_Other* ewk);
s32 compel_dead_check(WORK_Other* ewk);
void xb_eff09_00000_draw(WORK_Other* ewk);
void xb_eff09_01000_draw(WORK_Other* ewk);
void xb_eff09_02000_draw(WORK_Other* ewk);
void xb_eff09_03000_draw(WORK_Other* ewk);
void xb_eff09_05000_draw(WORK_Other* ewk);
void xb_eff09_06000_draw(WORK_Other* ewk);
void xb_eff09_07000_draw(WORK_Other* ewk);
void xb_eff09_08000_draw(WORK_Other* ewk);
void xb_eff09_09000_draw(WORK_Other* ewk);
void xb_eff09_11000_draw(WORK_Other* ewk);
void xb_eff09_12000_draw(WORK_Other* ewk);
void xb_eff09_14000_draw(WORK_Other* ewk);
void xb_eff09_16000_draw(WORK_Other* ewk);
void xb_eff09_19000_draw(WORK_Other* ewk);
void xb_eff09_20000_draw(WORK_Other* ewk);
void xb_eff09_21000_draw(WORK_Other* ewk);
void xb_eff09_22000_draw(WORK_Other* ewk);
void xb_eff09_23000_draw(WORK_Other* ewk);
void xb_eff09_25000_draw(WORK_Other* ewk);
void xb_eff09_26000_draw(WORK_Other* ewk);

void (*const D_0032AAA8[28])(WORK_Other* ewk) = { xb_eff09_00000_draw, xb_eff09_01000_draw, xb_eff09_02000_draw, xb_eff09_03000_draw, xb_eff09_03000_draw, xb_eff09_05000_draw, xb_eff09_06000_draw, xb_eff09_07000_draw, xb_eff09_08000_draw, xb_eff09_09000_draw, xb_eff09_09000_draw, xb_eff09_11000_draw, xb_eff09_12000_draw, xb_eff09_03000_draw, xb_eff09_14000_draw, xb_eff09_09000_draw, xb_eff09_16000_draw, xb_eff09_09000_draw, xb_eff09_09000_draw, xb_eff09_19000_draw, xb_eff09_20000_draw, xb_eff09_21000_draw, xb_eff09_22000_draw, xb_eff09_23000_draw, xb_eff09_23000_draw, xb_eff09_25000_draw, xb_eff09_26000_draw, xb_eff09_22000_draw };

void xb_effect_09_draw(WORK_Other* ewk) {
    if (compel_dead_check(ewk)) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[1] = 99;
    }

    D_0032AAA8[ewk->wu.routine_no[0]](ewk);
}

void xb_eff09_00000_draw(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 1:
        if (!obr_no_disp_check() && range_x_check(ewk)) {
            sort_push_request4(&ewk->wu);
        }

        break;
    }
}

void xb_eff09_01000_draw(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        sort_push_request(&ewk->wu);
        break;

    case 1:
    case 2:
    case 3:
    case 4:
        if (!obr_no_disp_check()) {
            sort_push_request(&ewk->wu);
        }

        break;
    }
}

void xb_eff09_02000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
    case 1:
    case 2:
        sort_push_request(&ewk->wu);
        break;
    }
}

void xb_eff09_03000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 1:
    case 2:
        sort_push_request(&ewk->wu);
        break;
    }
}

void xb_eff09_05000_draw(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 1:
        sort_push_request(&ewk->wu);
        break;
    }
}

void xb_eff09_06000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 1:
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (ewk->wu.cg_type != 0xFF) {
            sort_push_request(&ewk->wu);
        }

        break;
    }
}

void xb_eff09_07000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 1:
        sort_push_request(&ewk->wu);
        break;
    }
}

void xb_eff09_08000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 1:
        if (!obr_no_disp_check()) {
            sort_push_request4(&ewk->wu);
        }

        break;
    }
}

void xb_eff09_09000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 1:
        if (!obr_no_disp_check() && range_x_check(ewk)) {
            sort_push_request4(&ewk->wu);
        }

        break;
    }
}

void xb_eff09_11000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 1:
    case 3:
        sort_push_request(&ewk->wu);
        break;
    }
}

void xb_eff09_12000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
    case 1:
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (ewk->wu.old_rno[1] >= 0) {
            sort_push_request(&ewk->wu);
        }

        break;
    }
}

void xb_eff09_14000_draw(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;

    if (ewk->wu.rl_flag) {
        ewk->wu.xyz[0].disp.pos = mwk->xyz[0].disp.pos - eff09_data2[ewk->wu.type][2];
    } else {
        ewk->wu.xyz[0].disp.pos = eff09_data2[ewk->wu.type][2] + mwk->xyz[0].disp.pos;
    }

    ewk->wu.xyz[1].disp.pos = eff09_data2[ewk->wu.type][3] + mwk->xyz[1].disp.pos;

    switch (ewk->wu.routine_no[1]) {
    case 1:
        if (!obr_no_disp_check() && range_x_check(ewk)) {
            sort_push_request4(&ewk->wu);
        }

        break;
    }
}

void xb_eff09_16000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 1:
        sort_push_request4(&ewk->wu);
        break;
    }
}

void xb_eff09_19000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
    case 1:
    case 2:
    case 3:
        disp_pos_trans_entry(ewk);
        break;
    }
}

void xb_eff09_20000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
    case 1:
        disp_pos_trans_entry(ewk);
        break;
    }
}

void xb_eff09_21000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 1:
    case 2:
        disp_pos_trans_entry(ewk);
        break;
    }
}

void xb_eff09_22000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 1:
    case 2:
        pl_eff_trans_entry(ewk);
        break;
    }
}

void xb_eff09_23000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 1:
    case 2:
    case 3:
        pl_eff_trans_entry(ewk);
        break;
    }
}

void xb_eff09_25000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
    case 1:
        pl_eff_trans_entry(ewk);
        break;
    }
}

void xb_eff09_26000_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 1:
    case 2:
    case 3:
    case 4:
        disp_pos_trans_entry(ewk);
        break;
    }
}

void effect_09_move(WORK_Other *ewk) {
    if (compel_dead_check(ewk) != 0) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[1] = 99;
    }

    eff09_tbl[ewk->wu.routine_no[0]](ewk);
}

void eff09_0000(WORK_Other *ewk) {
    if (obr_no_disp_check() != 0) {
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.hit_stop != 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type != 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_1000(WORK_Other *ewk) {
    if (obr_no_disp_check() != 0) {
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_priority = ewk->wu.position_z = 67;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = 4;
        ewk->wu.old_rno[0] = random_16();
        ewk->wu.old_rno[0] &= 1;

        if (ewk->master_id != 0) {
            ewk->wu.type = 10;
        } else {
            ewk->wu.type = 9;
        }

        if (EXE_obroll != 0) {
            set_char_move_init(&ewk->wu, 0, 25);
            ewk->wu.old_rno[0] = 1;
        } else if (ewk->wu.old_rno[0] != 0) {
            set_char_move_init(&ewk->wu, 0, 25);
        } else {
            set_char_move_init(&ewk->wu, 0, 65);
        }

        sort_push_request(&ewk->wu);
        break;

    case 1:
    case 3:
        if (EXE_flag == 0 && Game_pause == 0 && EXE_obroll == 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type != 0) {
                ewk->wu.routine_no[1]++;
            }
        }

        if (obr_no_disp_check() == 0) {
            sort_push_request(&ewk->wu);
        }

        break;

    case 2:
        if (obr_no_disp_check() != 0) {
            break;
        }

        if (ewk->wu.old_rno[0] != 0 && EXE_flag == 0 && Game_pause == 0 && EXE_obroll == 0 &&
            eff_hit_check(ewk, 0) != 0) {
            ewk->wu.routine_no[1]++;
            set_char_move_init(&ewk->wu, 0, 65);
        }

        sort_push_request(&ewk->wu);
        break;

    case 4:
        if (obr_no_disp_check() == 0) {
            sort_push_request(&ewk->wu);
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void sean_ball_move(WORK_Other *ewk, u16 sw_work) {
    if (plw[ewk->master_id].wu.operator == 0) {
        return;
    }

    if ((sw_work & 1) != 0) {
        ewk->wu.old_rno[0]++;

        if (ewk->wu.old_rno[0] < 8) {
            ewk->wu.mvxy.d[1].sp += eff09_add_tbl0[ewk->wu.dir_step][0];
        }
    }

    if ((sw_work & 2) != 0) {
        ewk->wu.old_rno[1]++;

        if (ewk->wu.old_rno[1] < 8) {
            ewk->wu.mvxy.d[1].sp += eff09_add_tbl0[ewk->wu.dir_step][1];
        }
    }

    if ((sw_work & 4) != 0) {
        ewk->wu.old_rno[2]++;

        if (ewk->wu.rl_flag != 0) {
            if (ewk->wu.old_rno[2] < 4) {
                ewk->wu.mvxy.d[0].sp += eff09_add_tbl1[ewk->wu.dir_step][0];
            }
        } else if (ewk->wu.old_rno[2] < 8) {
            ewk->wu.mvxy.d[0].sp += eff09_add_tbl2[ewk->wu.dir_step][0];
        }
    }

    if ((sw_work & 8) != 0) {
        ewk->wu.old_rno[3]++;

        if (ewk->wu.rl_flag != 0) {
            if (ewk->wu.old_rno[3] < 8) {
                ewk->wu.mvxy.d[0].sp += eff09_add_tbl1[ewk->wu.dir_step][1];
            }
        } else if (ewk->wu.old_rno[3] < 4) {
            ewk->wu.mvxy.d[0].sp += eff09_add_tbl2[ewk->wu.dir_step][1];
        }
    }
}

void ball_bound_set(WORK_Other *ewk) {
    ewk->wu.mvxy.a[0].sp = -0x40000;
    ewk->wu.mvxy.a[1].sp = 0x60000;
    ewk->wu.mvxy.d[0].sp = -0x1000;
    ewk->wu.mvxy.d[1].sp = -0x8000;
    ewk->wu.dir_timer = 12;

    if (ewk->wu.rl_flag != 0) {
        ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.d[0].sp = -ewk->wu.mvxy.d[0].sp;
    }
}

void eff09_3000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Exec_Wipe != 0) {
            ewk->wu.routine_no[1] = 99;
            break;
        }

        sub_00098407((Winner_id * 0x300) + 0x136);
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[0] = 96;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.xyz[0].disp.pos, 40, 1, 2);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
            } else {
                sub_000EF088(ewk);
            }

            char_move(&ewk->wu);
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (Exec_Wipe != 0) {
            sub_00098407((Winner_id * 0x300) + 0x130);
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_4000(WORK_Other *ewk) {
    s16 work;
    s16 work2;
    WORK *oya_ptr;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 2;
        ewk->wu.kage_hy = -3;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 0;
        ewk->wu.my_col_code = 0x2000;
        ewk->wu.position_z = ewk->wu.my_priority = 20;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        oya_ptr = (WORK *)ewk->my_master;
        ewk->wu.rl_flag = oya_ptr->rl_flag;

        if (oya_ptr->rl_flag != 0) {
            work = bg_w.bgw[1].xy[0].disp.pos - 272;
            work2 = oya_ptr->xyz[0].disp.pos - 88;
        } else {
            work = bg_w.bgw[1].xy[0].disp.pos + 272;
            work2 = oya_ptr->xyz[0].disp.pos + 88;
        }

        ewk->wu.xyz[0].disp.pos = work;
        ewk->wu.old_rno[0] = 202;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work2, 0, 0, 2);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
                set_char_move_init(&ewk->wu, 0, 29);
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_5000(WORK_Other *ewk) {
    if (obr_no_disp_check() != 0) {
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_6000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 9) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 2;
            ewk->wu.blink_timing = 1;
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            break;
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 3:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void eff09_7000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 32;

        if (ewk->master_id != 0) {
            ewk->wu.mvxy.a[0].sp = 0x30000;
            ewk->wu.mvxy.a[1].sp = 0x90000;
            ewk->wu.mvxy.d[0].sp = 0x1000;
            ewk->wu.mvxy.d[1].sp = -0x6000;
            break;
        }

        ewk->wu.mvxy.a[0].sp = -0x30000;
        ewk->wu.mvxy.a[1].sp = 0x90000;
        ewk->wu.mvxy.d[0].sp = -0x1000;
        ewk->wu.mvxy.d[1].sp = -0x6000;
        break;

    case 1:
        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] < 0) {
            ewk->wu.routine_no[1]++;
            return;
        }

        char_move(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_8000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (ewk->wu.hit_stop != 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        disp_pos_trans_entry_s(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_9000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;

        if (ewk->wu.rl_flag != 0) {
            ewk->wu.xyz[0].disp.pos -= 6;
        } else {
            ewk->wu.xyz[0].disp.pos -= 2;
        }

        ewk->wu.rl_flag = 0;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.hit_stop != 0) {
            char_move(&ewk->wu);
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_10000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;

        if (ewk->wu.rl_flag != 0) {
            ewk->wu.xyz[0].disp.pos -= 6;
        } else {
            ewk->wu.xyz[0].disp.pos -= 2;
        }

        ewk->wu.rl_flag = 0;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.hit_stop != 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type != 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_11000(WORK_Other *ewk) {
    s16 work;
    s16 work2;
    WORK *oya_ptr = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 2;
        ewk->wu.kage_hy = -10;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 0;
        ewk->wu.my_col_code = 0x2000;
        ewk->wu.position_z = ewk->wu.my_priority = 20;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.rl_flag = oya_ptr->rl_flag ^ 1;

        if (oya_ptr->rl_flag != 0) {
            work = bg_w.bgw[1].xy[0].disp.pos + 272;
            work2 = oya_ptr->xyz[0].disp.pos + 56;
        } else {
            work = bg_w.bgw[1].xy[0].disp.pos - 272;
            work2 = oya_ptr->xyz[0].disp.pos - 56;
        }

        ewk->wu.xyz[0].disp.pos = work;
        ewk->wu.old_rno[0] = 220;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work2, 0, 0, 2);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
                oya_ptr->cmwk[0] = 9;
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        sub_000EF072(ewk);

        if (oya_ptr->rl_flag != 0) {
            if (oya_ptr->xyz[0].disp.pos > ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[1]++;
            }
        } else if (oya_ptr->xyz[0].disp.pos < ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[1]++;
        }

        /* fallthrough */
    case 3:
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

/* The Xbox returns where the PS2 breaks out of the switch. */
void eff09_12000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.mvxy.a[1].sp = -0x10000;
        ewk->wu.mvxy.d[1].sp = 0;
        ewk->wu.mvxy.d[0].sp = 0;

        if (ewk->wu.rl_flag != 0) {
            ewk->wu.mvxy.a[0].sp = -0x20000;
        } else {
            ewk->wu.mvxy.a[0].sp = 0x20000;
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 1:
        char_move(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < 56) {
            ewk->wu.routine_no[1]++;
            ewk->wu.blink_timing = 1;
            ewk->wu.disp_flag = 2;
            ewk->wu.old_rno[1] = 20;
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] < 0) {
            ewk->wu.routine_no[1]++;
            return;
        }

        char_move(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 3:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_13000(WORK_Other *ewk) {
    WORK *oya_ptr = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (oya_ptr->cg_type == 99) {
                ewk->wu.routine_no[1]++;
                set_char_move_init(&ewk->wu, 0, 83);
                ewk->wu.mvxy.a[0].sp = eff09_13_tbl[ewk->wu.type - 0xF][0];
                ewk->wu.mvxy.d[0].sp = eff09_13_tbl[ewk->wu.type - 0xF][1];
                ewk->wu.mvxy.a[1].sp = eff09_13_tbl[ewk->wu.type - 0xF][2];
                ewk->wu.mvxy.d[1].sp = eff09_13_tbl[ewk->wu.type - 0xF][3];
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            sub_000EF088(ewk);

            if (ewk->wu.xyz[0].disp.pos < bg_w.bgw[1].pos_x_work - 240 ||
                ewk->wu.xyz[0].disp.pos > bg_w.bgw[1].pos_x_work + 240 || ewk->wu.xyz[1].disp.pos > 512) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 3:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_14000(WORK_Other *ewk) {
    WORK *oya_ptr = (WORK *)ewk->my_master;

    if (ewk->wu.rl_flag != 0) {
        ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos - eff09_data2[ewk->wu.type][2];
    } else {
        ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos + eff09_data2[ewk->wu.type][2];
    }

    ewk->wu.xyz[1].disp.pos = oya_ptr->xyz[1].disp.pos + eff09_data2[ewk->wu.type][3];
    ewk->wu.xyz[1].disp.pos += base_y_pos;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.hit_stop != 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type != 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_15000(WORK_Other *ewk) {
    WORK *oya_ptr;

    if (obr_no_disp_check() != 0) {
        return;
    }

    oya_ptr = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.hit_stop != 0) {
            char_move(&ewk->wu);

            if (oya_ptr->cg_type == 9) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_16000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.xyz[0].disp.pos += 2;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        ewk->wu.rl_flag = 0;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.hit_stop != 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type != 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request4(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_17000(WORK_Other *ewk) {
    WORK *oya_ptr;

    if (obr_no_disp_check() != 0) {
        return;
    }

    oya_ptr = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (oya_ptr->cg_type == 9 || oya_ptr->routine_no[1] != 4 || oya_ptr->routine_no[2] != 30) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos;

        if (oya_ptr->rl_flag != 0) {
            ewk->wu.xyz[0].disp.pos += 32;
        } else {
            ewk->wu.xyz[0].disp.pos -= 32;
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_18000(WORK_Other *ewk) {
    WORK *oya_ptr;

    if (obr_no_disp_check() != 0) {
        return;
    }

    oya_ptr = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);

        if (oya_ptr->rl_flag != 0) {
            if (oya_ptr->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
                ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos - 256;
            } else {
                ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - (bg_w.pos_offset + 32);
            }
        } else if (oya_ptr->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = oya_ptr->xyz[0].disp.pos + 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + (bg_w.pos_offset + 32);
        }

        ewk->wu.xyz[1].disp.pos = base_y_pos + 160;
        ewk->wu.old_rno[0] = 35;
        ewk->wu.old_rno[1] = oya_ptr->xyz[1].disp.pos + 106 + base_y_pos;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], oya_ptr->xyz[0].disp.pos, ewk->wu.old_rno[1], 0, 0);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
            } else {
                sub_000EF072(ewk);
                sub_000EF088(ewk);
            }
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 0;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_19000(WORK_Other *ewk) {
    if (obr_no_disp_check() != 0) {
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.mvxy.a[0].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][0];
        ewk->wu.mvxy.d[0].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][1];
        ewk->wu.mvxy.a[1].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][2];
        ewk->wu.mvxy.d[1].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][3];
        ewk->wu.routine_no[1]++;
        sub_000EF0C0(ewk);
        return;

    case 1:
    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_000EF072(ewk);
            sub_000EF088(ewk);

            if (ewk->wu.xyz[1].disp.pos <= 63) {
                ewk->wu.xyz[1].cal = 0x3F0000;
                ewk->wu.mvxy.a[0].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][0];
                ewk->wu.mvxy.d[0].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][1];
                ewk->wu.mvxy.a[1].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][2];
                ewk->wu.mvxy.d[1].sp = eff09_19000_tbl[ewk->wu.routine_no[1]][3];
                ewk->wu.routine_no[1]++;
            }
        }

        sub_000EF0C0(ewk);
        return;

    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_000EF072(ewk);
            sub_000EF088(ewk);

            if (ewk->wu.xyz[1].disp.pos <= 63) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        sub_000EF0C0(ewk);
        return;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_20000(WORK_Other *ewk) {
    WORK *oya_ptr;
    s16 pos_work;

    oya_ptr = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 5;
        ewk->wu.kage_hy = base_y_pos + 2;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 11;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        sub_000EF0C0(ewk);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (oya_ptr->id != 0) {
                pos_work = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset;
                pos_work -= 64;

                if (ewk->wu.xyz[0].disp.pos < pos_work) {
                    oya_ptr->cmwk[1] = 1;
                    ewk->wu.routine_no[1]++;
                }
            } else {
                pos_work = bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset;
                pos_work += 64;

                if (ewk->wu.xyz[0].disp.pos > pos_work) {
                    oya_ptr->cmwk[1] = 1;
                    ewk->wu.routine_no[1]++;
                }
            }
        }

        sub_000EF0C0(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_21000(WORK_Other *ewk) {
    s16 arrive_x;
    s16 arrive_y;

    if (Suicide[0] != 0) {
        ewk->wu.routine_no[1] = 99;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x8000;

        if (ewk->wu.type == 29) {
            ewk->wu.old_rno[0] = 70;

            if (ewk->wu.rl_flag != 0) {
                arrive_x = ewk->wu.xyz[0].disp.pos + 42;
            } else {
                arrive_x = ewk->wu.xyz[0].disp.pos - 42;
            }

            arrive_y = ewk->wu.xyz[1].disp.pos + 6;
        } else {
            ewk->wu.old_rno[0] = 64;

            if (plw[Winner_id].wu.rl_flag != 0) {
                arrive_x = plw[Winner_id].wu.xyz[0].disp.pos + 28;
            } else {
                arrive_x = plw[Winner_id].wu.xyz[0].disp.pos - 28;
            }

            arrive_y = plw[Winner_id].wu.xyz[1].disp.pos + 162;
        }

        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], arrive_x, arrive_y, 2, 2);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
                set_char_move_init(&ewk->wu, 0, 58);
            } else {
                sub_000EF072(ewk);
                sub_000EF088(ewk);
            }
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type != 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
                plw[Winner_id].wu.cmwk[0] = 1;
            }
        }

        sub_000EF0C0(ewk);
        break;

    case 3:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_22000(WORK_Other *ewk) {
    WORK *oya_ptr;
    s16 work;

    oya_ptr = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            if (oya_ptr->cg_type == 99) {
                ewk->wu.routine_no[1]++;
                set_char_move_init(&ewk->wu, 0, 62);
            } else if (oya_ptr->cg_ix != ewk->wu.cg_ix) {
                work = oya_ptr->cg_ix / oya_ptr->cgd_type;
                set_char_move_init2(&ewk->wu, 0, 61, work + 1, 0);
                ewk->wu.cg_ix = oya_ptr->cg_ix;
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_23000(WORK_Other *ewk) {
    WORK *oya_ptr;

    oya_ptr = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 1;
        ewk->wu.kage_hy = -2;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 11;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && oya_ptr->cg_type == 1) {
            ewk->wu.routine_no[1]++;
        }

        pl_eff_trans_entry(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;

                if (ewk->wu.rl_flag != 0) {
                    ewk->wu.mvxy.a[0].sp = -0x20000;
                } else {
                    ewk->wu.mvxy.a[0].sp = 0x20000;
                }

                ewk->wu.mvxy.d[0].sp = 0;
                set_char_move_init(&ewk->wu, 0, 64);
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);

            if (range_x_check3(ewk, 64) == 0) {
                ewk->wu.routine_no[1]++;
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff09_24000(WORK_Other *ewk) {
    WORK *oya_ptr;

    oya_ptr = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;

        if (ewk->wu.type == 38) {
            ewk->wu.rl_flag ^= 1;
        }

        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        return;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && oya_ptr->cg_type == 1) {
            ewk->wu.routine_no[1]++;

            if (ewk->wu.type == 38) {
                ewk->wu.routine_no[1] = 99;
            }
        }

        pl_eff_trans_entry(ewk);
        return;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 9) {
                ewk->wu.routine_no[1]++;
                char_move_z(&ewk->wu);

                if (ewk->wu.type == 35) {
                    ewk->wu.mvxy.a[0].sp = 0x18000;
                } else {
                    ewk->wu.mvxy.a[0].sp = -0x18000;
                }

                if (ewk->wu.rl_flag != 0) {
                    ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
                }

                ewk->wu.mvxy.d[0].sp = 0;
            }
        }

        pl_eff_trans_entry(ewk);
        return;

    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);

            if (ewk->wu.type == 34) {
                if (range_x_check3(ewk, 176) == 0) {
                    ewk->wu.routine_no[1]++;
                }
            } else if (range_x_check3(ewk, 88) == 0) {
                ewk->wu.routine_no[1]++;
            }
        }

        pl_eff_trans_entry(ewk);
        return;

    default:
        push_effect_work(&ewk->wu);
        return;
    }
}

void eff09_25000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x6000;

        if (ewk->wu.type == 36) {
            ewk->wu.mvxy.a[0].sp = 0x48000;
            ewk->wu.mvxy.a[1].sp = 0x10000;
        } else {
            ewk->wu.mvxy.a[0].sp = 0x28000;
            ewk->wu.mvxy.a[1].sp = 0x30000;
        }

        if (ewk->wu.rl_flag != 0) {
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        }

        pl_eff_trans_entry(ewk);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            sub_000EF088(ewk);

            if (range_x_check3(ewk, 16) == 0) {
                ewk->wu.routine_no[1]++;
            } else if (ewk->wu.xyz[1].disp.pos < 0) {
                ewk->wu.xyz[1].cal = 0;
                ewk->wu.mvxy.a[1].sp = 0x40000;
                sub_00098407((ewk->master_id * 0x300) + 0x157);
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void jijii_win_tama_sub(WORK_Other *ewk);

void eff09_26000(WORK_Other *ewk) {
    WORK *oya_ptr;

    oya_ptr = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, 101);
        ewk->wu.old_rno[0] = 0;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 9) {
                ewk->wu.routine_no[1]++;
                oya_ptr->cmwk[0] = 1;
            }
        }

        jijii_win_tama_sub(ewk);
        sub_000EF0C0(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;
                set_char_move_init(&ewk->wu, 0, 102);
            }
        }

        jijii_win_tama_sub(ewk);
        sub_000EF0C0(ewk);
        break;

    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (oya_ptr->cmwk[0] == 2) {
                ewk->wu.routine_no[1]++;
            }
        }

        jijii_win_tama_sub(ewk);
        sub_000EF0C0(ewk);
        break;

    case 4:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
        }

        ewk->wu.xyz[1].disp.pos = oya_ptr->position_y + base_y_pos;
        ewk->wu.xyz[1].disp.pos -= 42;
        jijii_win_tama_sub(ewk);
        sub_000EF0C0(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void jijii_win_tama_sub(WORK_Other *ewk) {
    WORK *oya_ptr;

    oya_ptr = (WORK *)ewk->my_master;
    ewk->wu.old_rno[0] ^= 1;

    if (ewk->wu.old_rno[0] != 0) {
        ewk->wu.position_z = oya_ptr->position_z - 2;
        return;
    }

    ewk->wu.position_z = oya_ptr->position_z + 2;
}

void eff09_27000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = -8;
        ewk->wu.kage_hy = -11;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 8;
        ewk->wu.mvxy.a[0].sp = -0x80000;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.a[1].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x6000;

        if (ewk->wu.rl_flag != 0) {
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
        }

        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_000EF072(ewk);
            sub_000EF088(ewk);

            if (ewk->wu.xyz[1].disp.pos < -8) {
                ewk->wu.routine_no[1]++;
                ewk->wu.xyz[1].cal = -0x80000;
                ewk->wu.mvxy.a[0].sp = -0x38000;
                ewk->wu.mvxy.d[0].sp = 0;

                if (ewk->wu.rl_flag != 0) {
                    ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
                }

                set_char_move_init2(&ewk->wu, 0, 107, 2, 0);
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);

            if (range_x_check3(ewk, 36) == 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_09_init(WORK *wk, u8 data) {
    WORK_Other *ewk;
    s16 ix;
    const s16 *data_ptr;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.type = data;
    data_ptr = eff09_data[ewk->wu.type];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 9;
    ewk->wu.work_id = 16;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = _eff09_char_table;
    ewk->wu.routine_no[0] = *data_ptr++;
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.my_col_code = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.hit_stop = *data_ptr++;
    ewk->wu.sync_suzi = *data_ptr++;
    suzi_offset_set(ewk);
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}

s32 effect_09_init2(WORK *wk, u8 data) {
    WORK_Other *ewk;
    s16 ix;
    const s16 *data_ptr;

    if (data == 0x1F && bg_w.stage == 0xA) {
        return 0;
    }

    if (test_flag != 0 && data >= 32 && data <= 40) {
        return 0;
    }

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.type = data;
    ewk->my_master = (u32 *)wk;
    ewk->wu.target_adrs = wk->target_adrs;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 9;
    ewk->wu.work_id = 16;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.char_table[0] = _etc_char_table;
    ewk->wu.my_col_mode = wk->my_col_mode;
    data_ptr = eff09_data2[ewk->wu.type];
    ewk->wu.routine_no[0] = *data_ptr++;
    ewk->wu.my_mts = 14;

    switch (data) {
    case 18:
    case 19:
    case 31:
        ewk->wu.my_col_code = 0x2020;
        data_ptr++;
        break;

    case 24:
    case 25:
    case 26:
    case 27:
        ewk->wu.my_col_code = 0x3E;
        data_ptr++;
        break;

    case 32:
        ewk->wu.my_col_code = 0x4F;
        data_ptr++;
        break;

    case 33:
        ewk->wu.my_col_code = 0x50;
        data_ptr++;
        ewk->wu.my_mts = 7;
        break;

    case 34:
        push_color_trans_req(0x51, 0xA);
        /* fallthrough */

    case 35:
    case 38:
    case 39:
    case 40:
        ewk->wu.my_col_code = 0xA;
        data_ptr++;
        ewk->wu.my_mts = 0x10;
        break;

    case 41:
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.my_col_code += wk->my_col_code;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        break;

    default:
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.my_col_code += wk->my_col_code;
        break;
    }

    ewk->wu.my_family = wk->my_family;

    if (data == 4) {
        ewk->wu.rl_flag = 0;
    } else {
        ewk->wu.rl_flag = wk->rl_flag;
    }

    ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos;

    if (wk->rl_flag != 0) {
        ewk->wu.xyz[0].disp.pos -= *data_ptr++;
    } else {
        ewk->wu.xyz[0].disp.pos += *data_ptr++;
    }

    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos += wk->xyz[1].disp.pos;
    ewk->wu.my_priority = wk->my_priority;
    ewk->wu.my_priority += *data_ptr++;
    ewk->wu.position_z = ewk->wu.my_priority;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.hit_stop = *data_ptr++;
    ewk->wu.sync_suzi = *data_ptr++;
    suzi_offset_set(ewk);
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}

void eff09_2000(WORK_Other *ewk) {
    s16 work;
    const s32 *ptr;
    u16 sw_work;
    const s16 *pl_hit_ptr;
    PLW *hit_pl;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        Appear_free[ewk->master_id] = 0;

        if (ewk->master_id != 0) {
            sw_work = p2sw_0;
        } else {
            sw_work = p1sw_0;
        }

        if ((sw_work & 0x4000) != 0) {
            work = 0;
        } else {
            work = random_16();
            work &= 1;
        }

        ewk->wu.dir_step = work;
        ptr = eff09_2000_data[ewk->wu.dir_step];
        ewk->wu.mvxy.a[0].sp = *ptr++;
        ewk->wu.mvxy.a[1].sp = *ptr++;
        ewk->wu.mvxy.d[0].sp = *ptr++;
        ewk->wu.mvxy.d[1].sp = *ptr++;

        if (ewk->wu.rl_flag != 0) {
            ewk->wu.mvxy.a[0].sp = -ewk->wu.mvxy.a[0].sp;
            ewk->wu.mvxy.d[0].sp = -ewk->wu.mvxy.d[0].sp;
        }

        ewk->wu.old_rno[0] = ewk->wu.old_rno[1] = ewk->wu.old_rno[2] = ewk->wu.old_rno[3] = 0;
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        return;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            sub_000EF072(ewk);
            sub_000EF088(ewk);

            if (ewk->wu.xyz[0].disp.pos > 784 || ewk->wu.xyz[0].disp.pos < 240) {
                ewk->wu.routine_no[1] = 99;
                Appear_free[ewk->master_id] = 1;
                ewk->wu.disp_flag = 0;
            }

            if (ewk->master_id != 0) {
                sw_work = p2sw_0;
                hit_pl = &plw[0];
                pl_hit_ptr = &plw[0].wu.h_bod->body_dm[0][0];
            } else {
                sw_work = p1sw_0;
                hit_pl = &plw[1];
                pl_hit_ptr = &plw[1].wu.h_bod->body_dm[0][0];
            }

            sean_ball_move(ewk, sw_work);

            if (hit_check_subroutine(&hit_pl->wu, &ewk->wu, pl_hit_ptr, sean_ball_hit) != 0) {
                ewk->wu.routine_no[1]++;
                ball_bound_set(ewk);
                set_char_move_init2(&hit_pl->wu, 9, 63, 1, 0);
                Appear_free[ewk->master_id] = 2;
                effect_B4_init(ewk);
                (void)random_16();
                add_super_arts_gauge(plw[ewk->master_id].sa, plw[ewk->master_id].wu.id, 1, plw[ewk->master_id].metamorphose);
                break;
            }

            if (ewk->wu.xyz[1].disp.pos < 0) {
                sub_00098407((ewk->master_id * 0x300) + 0x157);
                ewk->wu.routine_no[1]++;
                ball_bound_set(ewk);
                Appear_free[ewk->master_id] = 1;
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            if (ewk->wu.xyz[0].disp.pos > 784 || ewk->wu.xyz[0].disp.pos < 240 || ewk->wu.xyz[1].disp.pos < -56) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            } else {
                sub_000EF072(ewk);
                sub_000EF088(ewk);
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 3:
        ewk->wu.routine_no[1]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
