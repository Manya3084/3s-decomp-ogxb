/* Effect 02, retail sf33rd.xbe.
 * urian_guard_se_check is 0x32086 size 0x56 and is interior.
 * effect_02_init is 0x320DC size 0x19C and is interior.
 * effect_02_move is 0x32278 size 0x382 and is a scanned start.
 * The pull failure is an early ret. The Combo_Demo_Flag
 * path jumps to the shared epilogue.
 * 0x3201A stays unnamed. 0x325FA is eff03_disp_pos.
 *
 * hit_mark_dir_table is 0x249C80. hmdt is 0x249CA0.
 * hcct is 0x24A378. gqdt is 0x24A388. explem is 0x24A3D4.
 * explem2 is 0x24A3F0. hit_mark_hosei_table is 0x24A4E0.
 * All of them match. The rows were not pasted. Four zero
 * bytes at 0x24A384 pad hcct. Four zero bytes at 0x24A3EC
 * pad explem.
 *
 * The init stores vital_new, vital_old, and dm_rl before
 * be_flag. It stores my_mr_flag before dm_vital. It stores
 * weight_level before old_pos[1]. The player path stores
 * weight_level before dir_timer. The C keeps the PlayStation
 * 2 order. Case 1 stores routine_no[0] before disp_flag on
 * the cg_type path. The character table immediate is
 * 0x3064A0. Those bytes were not compared.
 * Combo_Demo_Flag is 0x7A8198. Last_Called_SE is 0x7A8796.
 * Suicide is 0x7A8268. Pause_Hit_Marks is 0x7A88AC.
 * EXE_flag is 0xC7C834. Game_pause is 0x7A89B0.
 * bg_w.quake_y_index is 0x7BC540.
 * sound_effect_request is 0x266008.
 * char_move is 0x2008E.
 * set_char_move_init is 0x200A9.
 * random_16 is 0x9326B.
 * pp_screen_quake is 0x96BD3.
 * sort_push_request8 is 0x9E174.
 * push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. frw is 0xC806A0
 * and each object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"


typedef struct {
    u16 se;
    u8 hits;
    u8 deff;
    u8 kezu;
    u8 fsin;
    u8 status;
    u8 quake;
    u8 dir;
    u8 col;
    u8 myhix;
    u8 emhix;
} HMDT;

typedef struct {
    u16 chix;
    s16 hx;
    s16 hy;
} EXPLEM;

typedef struct {
    u8 pad[0xE];
    u8 hit_mark;
} Att;

typedef struct {
    struct {
        s16 x;
        s16 y;
    } size;
} Mr;





typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */
typedef void (*SERequest)(WORK_Other *ewk, u16 oto);

#if defined(__i386__)
_Static_assert(sizeof(HMDT) == 0xC, "HMDT");
_Static_assert(sizeof(EXPLEM) == 6, "EXPLEM");
_Static_assert(__builtin_offsetof(HMDT, hits) == 2, "hits");
_Static_assert(__builtin_offsetof(HMDT, deff) == 3, "deff");
_Static_assert(__builtin_offsetof(HMDT, kezu) == 4, "kezu");
_Static_assert(__builtin_offsetof(HMDT, status) == 6, "status");
_Static_assert(__builtin_offsetof(HMDT, quake) == 7, "quake");
_Static_assert(__builtin_offsetof(HMDT, dir) == 8, "dir");
_Static_assert(__builtin_offsetof(HMDT, col) == 9, "col");
_Static_assert(__builtin_offsetof(HMDT, myhix) == 0xA, "myhix");
_Static_assert(__builtin_offsetof(HMDT, emhix) == 0xB, "emhix");
_Static_assert(__builtin_offsetof(EXPLEM, hx) == 2, "hx");
_Static_assert(__builtin_offsetof(EXPLEM, hy) == 4, "hy");
_Static_assert(__builtin_offsetof(WORK, be_flag) == 0, "be_flag");
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, blink_timing) == 2, "blink");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, target_adrs) == 0xC, "target");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, scr_mv_x) == 0x60, "scr_mv_x");
_Static_assert(__builtin_offsetof(WORK, scr_mv_y) == 0x62, "scr_mv_y");
_Static_assert(__builtin_offsetof(WORK, xyz) == 0x64, "xyz");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, xyz[2].disp.pos) == 0x6E, "xyz2");
_Static_assert(__builtin_offsetof(WORK, old_pos) == 0x70, "old_pos");
_Static_assert(__builtin_offsetof(WORK, direction) == 0x94, "direction");
_Static_assert(__builtin_offsetof(WORK, dir_old) == 0x96, "dir_old");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, vital_new) == 0x9E, "vital_new");
_Static_assert(__builtin_offsetof(WORK, vital_old) == 0xA0, "vital_old");
_Static_assert(__builtin_offsetof(WORK, dm_vital) == 0xA2, "dm_vital");
_Static_assert(__builtin_offsetof(WORK, weight_level) == 0xA8, "weight");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mr_flag) == 0x24E, "my_mr_flag");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.x) == 0x250, "mr_x");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.y) == 0x252, "mr_y");
_Static_assert(__builtin_offsetof(WORK, att.hit_mark) == 0x2CE, "hit_mark");
_Static_assert(__builtin_offsetof(WORK, kezuri_pow) == 0x2D4, "kezuri");
_Static_assert(__builtin_offsetof(WORK, dir_atthit) == 0x2DE, "dir_atthit");
_Static_assert(__builtin_offsetof(WORK, hit_mark_x) == 0x2F8, "hmx");
_Static_assert(__builtin_offsetof(WORK, hit_mark_y) == 0x2FA, "hmy");
_Static_assert(__builtin_offsetof(WORK, kohm) == 0x2FE, "kohm");
_Static_assert(__builtin_offsetof(WORK, dm_rl) == 0x310, "dm_rl");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
_Static_assert(__builtin_offsetof(WORK_Other, master_work_id) == 0x38C, "mwid");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "mid");
_Static_assert(__builtin_offsetof(WORK_Other, master_player) == 0x390, "mplayer");
_Static_assert(__builtin_offsetof(PLW, player_number) == 0x394, "player");
_Static_assert(__builtin_offsetof(PLW, muriyari_ugoku) == 0x3AE, "muriyari");
_Static_assert(__builtin_offsetof(BG, quake_y_index) == 0x20, "quake_y");
#endif

extern EffectRow frw[];
extern u32 _ef01_char_table[];
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s16 hit_mark_dir_table[16] = { 0, -1, -2, -3, -4, -5, -6, -7, 8, 7, 6, 5, 4, 3, 2, 1 };

const HMDT hmdt[146] = { { 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0 },         { 266, 1, 1, 5, 9, 6, 0, 0, 0, 0, 0 },
                         { 266, 1, 2, 6, 10, 6, 0, 0, 0, 0, 0 },      { 266, 1, 3, 7, 11, 6, 0, 0, 0, 0, 0 },
                         { 266, 1, 4, 8, 12, 6, 0, 0, 0, 0, 0 },      { 267, 2, 1, 5, 9, 6, 0, 0, 3, 0, 0 },
                         { 267, 2, 2, 6, 10, 6, 0, 0, 3, 0, 0 },      { 267, 2, 3, 7, 11, 6, 0, 0, 3, 0, 0 },
                         { 267, 2, 4, 8, 12, 6, 0, 0, 3, 0, 0 },      { 266, 3, 1, 5, 9, 6, 0, 0, 0, 0, 0 },
                         { 266, 3, 2, 6, 10, 6, 0, 0, 0, 0, 0 },      { 266, 3, 3, 7, 11, 6, 0, 0, 0, 0, 0 },
                         { 266, 3, 4, 8, 12, 6, 0, 0, 0, 0, 0 },      { 256, 38, 1, 5, 9, 2, 0, 1, 0, 0, 0 },
                         { 257, 38, 2, 6, 10, 2, 0, 1, 0, 0, 0 },     { 258, 38, 3, 7, 11, 2, 0, 1, 0, 0, 0 },
                         { 259, 38, 4, 8, 12, 2, 0, 1, 0, 0, 0 },     { 256, 47, 1, 5, 9, 2, 0, 1, 0, 0, 0 },
                         { 257, 47, 2, 6, 10, 2, 0, 1, 0, 0, 0 },     { 258, 47, 3, 7, 11, 2, 0, 1, 0, 0, 0 },
                         { 259, 47, 4, 8, 12, 2, 0, 1, 0, 0, 0 },     { 256, 56, 1, 5, 9, 2, 0, 1, 0, 0, 0 },
                         { 257, 56, 2, 6, 10, 2, 0, 1, 0, 0, 0 },     { 258, 56, 3, 7, 11, 2, 0, 1, 0, 0, 0 },
                         { 259, 56, 4, 8, 12, 2, 0, 1, 0, 0, 0 },     { 256, 65, 1, 5, 9, 2, 0, 1, 0, 0, 0 },
                         { 257, 65, 2, 6, 10, 2, 0, 1, 0, 0, 0 },     { 258, 65, 3, 7, 11, 2, 0, 1, 0, 0, 0 },
                         { 259, 65, 4, 8, 12, 2, 0, 1, 0, 0, 0 },     { 260, 38, 1, 5, 9, 2, 0, 1, 0, 0, 0 },
                         { 261, 38, 2, 6, 10, 2, 0, 1, 0, 0, 0 },     { 262, 38, 3, 7, 11, 2, 0, 1, 0, 0, 0 },
                         { 263, 38, 4, 8, 12, 2, 0, 1, 0, 0, 0 },     { 260, 47, 1, 5, 9, 2, 0, 1, 0, 0, 0 },
                         { 261, 47, 2, 6, 10, 2, 0, 1, 0, 0, 0 },     { 262, 47, 3, 7, 11, 2, 0, 1, 0, 0, 0 },
                         { 263, 47, 4, 8, 12, 2, 0, 1, 0, 0, 0 },     { 260, 56, 1, 5, 9, 2, 0, 1, 0, 0, 0 },
                         { 261, 56, 2, 6, 10, 2, 0, 1, 0, 0, 0 },     { 262, 56, 3, 7, 11, 2, 0, 1, 0, 0, 0 },
                         { 263, 56, 4, 8, 12, 2, 0, 1, 0, 0, 0 },     { 260, 65, 1, 5, 9, 2, 0, 1, 0, 0, 0 },
                         { 261, 65, 2, 6, 10, 2, 0, 1, 0, 0, 0 },     { 262, 65, 3, 7, 11, 2, 0, 1, 0, 0, 0 },
                         { 263, 65, 4, 8, 12, 2, 0, 1, 0, 0, 0 },     { 275, 8, 1, 5, 9, 6, 1, 0, 1, 0, 0 },
                         { 276, 8, 2, 6, 10, 6, 2, 0, 1, 0, 0 },      { 305, 8, 3, 7, 11, 6, 3, 0, 1, 0, 0 },
                         { 306, 8, 4, 8, 12, 6, 4, 0, 1, 0, 0 },      { 275, 9, 1, 5, 9, 6, 1, 0, 1, 0, 0 },
                         { 276, 9, 2, 6, 10, 6, 2, 0, 1, 0, 0 },      { 305, 9, 3, 7, 11, 6, 3, 0, 1, 0, 0 },
                         { 306, 9, 4, 8, 12, 6, 4, 0, 1, 0, 0 },      { 275, 10, 1, 5, 9, 6, 1, 0, 1, 0, 0 },
                         { 276, 10, 2, 6, 10, 6, 2, 0, 1, 0, 0 },     { 305, 10, 3, 7, 11, 6, 3, 0, 1, 0, 0 },
                         { 306, 10, 4, 8, 12, 6, 4, 0, 1, 0, 0 },     { 275, 11, 1, 5, 9, 6, 1, 0, 1, 0, 0 },
                         { 276, 11, 2, 6, 10, 6, 2, 0, 1, 0, 0 },     { 305, 11, 3, 7, 11, 6, 3, 0, 1, 0, 0 },
                         { 306, 11, 4, 8, 12, 6, 4, 0, 1, 0, 0 },     { 305, 10, 3, 7, 11, 6, 2, 0, 1, 0, 0 },
                         { 305, 10, 3, 7, 11, 20, 5, 0, 1, 0, 0 },    { 305, 10, 3, 7, 11, 20, 5, 0, 1, 1, 0 },
                         { 263, 12, 4, 8, 12, 6, 0, 0, 1, 0, 0 },     { 259, 13, 4, 8, 12, 4, 6, 0, 1, 0, 0 },
                         { 264, 0, 3, 7, 11, 6, 7, 0, 1, 0, 0 },      { 259, 36, 0, 0, 0, 6, 0, 0, 0, 0, 0 },
                         { 259, 37, 0, 0, 0, 6, 0, 0, 0, 0, 0 },      { 263, 37, 0, 0, 0, 6, 0, 0, 0, 0, 0 },
                         { 264, 0, 3, 7, 11, 6, 8, 0, 0, 0, 0 },      { 272, 47, 2, 6, 10, 6, 0, 0, 0, 0, 0 },
                         { 275, 14, 1, 5, 9, 6, 9, 0, 1, 0, 0 },      { 276, 15, 2, 6, 10, 6, 10, 0, 1, 0, 0 },
                         { 305, 16, 3, 7, 11, 6, 9, 0, 1, 0, 0 },     { 306, 17, 4, 8, 12, 6, 10, 0, 1, 0, 0 },
                         { 275, 18, 1, 5, 9, 6, 1, 0, 1, 0, 0 },      { 276, 18, 2, 6, 10, 6, 2, 0, 1, 0, 0 },
                         { 305, 18, 3, 7, 11, 6, 3, 0, 1, 0, 0 },     { 306, 18, 4, 8, 12, 6, 4, 0, 1, 0, 0 },
                         { 275, 0, 1, 5, 9, 6, 1, 0, 1, 0, 0 },       { 276, 0, 2, 6, 10, 6, 2, 0, 1, 0, 0 },
                         { 305, 0, 3, 7, 11, 6, 3, 0, 1, 0, 0 },      { 306, 0, 4, 8, 12, 6, 4, 0, 1, 0, 0 },
                         { 264, 38, 3, 7, 11, 6, 8, 0, 0, 0, 0 },     { 305, 18, 3, 7, 11, 20, 2, 0, 1, 3, 0 },
                         { 331, 38, 2, 6, 10, 6, 0, 0, 0, 0, 0 },     { 259, 19, 3, 7, 11, 6, 0, 0, 0, 0, 0 },
                         { 256, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0 },       { 257, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0 },
                         { 258, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0 },       { 259, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0 },
                         { 260, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0 },       { 261, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0 },
                         { 262, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0 },       { 263, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0 },
                         { 259, 20, 4, 8, 12, 6, 0, 0, 0, 0, 0 },     { 259, 21, 4, 8, 12, 4, 11, 0, 1, 0, 0 },
                         { 263, 22, 4, 8, 12, 4, 12, 0, 1, 0, 0 },    { 263, 13, 4, 8, 12, 4, 6, 0, 1, 0, 0 },
                         { 305, 23, 1, 5, 9, 6, 13, 0, 1, 0, 0 },     { 305, 24, 2, 6, 10, 6, 14, 0, 1, 0, 0 },
                         { 305, 25, 3, 7, 11, 6, 15, 0, 1, 0, 0 },    { 305, 26, 4, 8, 12, 6, 16, 0, 1, 0, 0 },
                         { 306, 23, 1, 5, 9, 6, 13, 0, 1, 0, 0 },     { 306, 24, 2, 6, 10, 6, 14, 0, 1, 0, 0 },
                         { 306, 25, 3, 7, 11, 6, 15, 0, 1, 0, 0 },    { 306, 26, 4, 8, 12, 6, 16, 0, 1, 0, 0 },
                         { 256, 27, 1, 5, 9, 6, 0, 0, 0, 0, 0 },      { 257, 28, 2, 6, 10, 6, 0, 0, 0, 0, 0 },
                         { 258, 29, 3, 7, 11, 6, 0, 0, 0, 0, 0 },     { 259, 30, 4, 8, 12, 6, 0, 0, 0, 0, 0 },
                         { 256, 0, 113, 114, 113, 6, 0, 0, 0, 0, 0 }, { 266, 0, 113, 114, 113, 6, 0, 0, 0, 0, 0 },
                         { 267, 0, 113, 114, 113, 6, 0, 0, 0, 0, 0 }, { 258, 31, 3, 7, 11, 6, 3, 0, 0, 0, 0 },
                         { 259, 31, 4, 8, 12, 6, 4, 0, 0, 0, 0 },     { 258, 32, 3, 7, 11, 6, 0, 0, 0, 0, 0 },
                         { 259, 32, 4, 8, 12, 6, 0, 0, 0, 0, 0 },     { 262, 31, 3, 7, 11, 6, 3, 0, 0, 0, 0 },
                         { 263, 31, 4, 8, 12, 6, 4, 0, 0, 0, 0 },     { 262, 32, 3, 7, 11, 6, 0, 0, 0, 0, 0 },
                         { 263, 32, 4, 8, 12, 6, 0, 0, 0, 0, 0 },     { 275, 33, 1, 5, 9, 6, 1, 0, 1, 0, 0 },
                         { 276, 33, 2, 6, 10, 6, 2, 0, 1, 0, 0 },     { 305, 33, 3, 7, 11, 6, 3, 0, 1, 0, 0 },
                         { 306, 33, 4, 8, 12, 6, 4, 0, 1, 0, 0 },     { 271, 23, 1, 5, 9, 6, 13, 0, 1, 0, 0 },
                         { 271, 24, 2, 6, 10, 6, 14, 0, 1, 0, 0 },    { 271, 25, 3, 7, 11, 6, 15, 0, 1, 0, 0 },
                         { 271, 26, 4, 8, 12, 6, 16, 0, 1, 0, 0 },    { 306, 11, 4, 8, 12, 6, 17, 0, 1, 0, 0 },
                         { 306, 11, 4, 8, 12, 20, 15, 0, 1, 1, 0 },   { 256, 34, 1, 5, 9, 6, 0, 0, 0, 0, 0 },
                         { 257, 35, 2, 6, 10, 6, 0, 0, 0, 0, 0 },     { 258, 36, 3, 7, 11, 6, 0, 0, 0, 0, 0 },
                         { 259, 37, 4, 8, 12, 6, 0, 0, 0, 0, 0 },     { 260, 34, 1, 5, 9, 6, 0, 0, 0, 0, 0 },
                         { 261, 35, 2, 6, 10, 6, 0, 0, 0, 0, 0 },     { 262, 36, 3, 7, 11, 6, 0, 0, 0, 0, 0 },
                         { 263, 37, 4, 8, 12, 6, 0, 0, 0, 0, 0 },     { 259, 37, 4, 8, 12, 6, 0, 0, 0, 0, 0 },
                         { 263, 37, 4, 8, 12, 6, 0, 0, 0, 0, 0 },     { 383, 74, 4, 8, 12, 118, 0, 0, 5, 0, 1 },
                         { 331, 32, 4, 8, 12, 6, 0, 0, 0, 0, 0 },     { 0, 75, 4, 8, 12, 6, 0, 0, 4, 0, 0 } };

const s16 hcct[6] = { 8192, 8224, 8224, 8224, 4, 484 };

const s16 gqdt[19][2] = {
    { 0, 0 }, { 6, 6 }, { 6, 8 }, { 6, 10 }, { 6, 12 }, { 6, 18 }, { 6, 6 },  { 6, 0 },  { 6, 0 },  { 6, 4 },
    { 6, 6 }, { 6, 4 }, { 6, 8 }, { 6, 6 },  { 6, 8 },  { 6, 10 }, { 6, 12 }, { 6, 16 }, { 6, 60 },
};

const EXPLEM explem[4] = { { 10, -92, 0 }, { 10, 96, 0 }, { 13, -44, 60 }, { 18, -18, 0 } };

const EXPLEM explem2[2][20] = {
    { { 10, -84, 0 }, { 10, -84, 0 }, { 10, -84, 0 }, { 10, -84, 0 }, { 10, -84, 0 }, { 10, -84, 0 }, { 10, -84, 0 },
      { 10, -84, 0 }, { 10, -84, 0 }, { 10, -84, 0 }, { 10, -84, 0 }, { 10, -84, 0 }, { 10, -84, 0 }, { 8, 0, 0 },
      { 8, 0, 0 },    { 8, 0, 0 },    { 8, 0, 0 },    { 8, 0, 0 },    { 8, 0, 0 },    { 8, 0, 0 } },
    { { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 },
      { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 },
      { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 }, { 74, 0, 29 } }
};

const s16 hit_mark_hosei_table[108][2] = {
    { 0, 0 },     { -16, 84 },  { -82, 70 },  { -89, 65 },  { -52, 72 },  { 1, 32 },    { -48, 46 },  { -64, 63 },
    { -68, 84 },  { -62, 106 }, { -48, 46 },  { -62, 106 }, { -48, 46 },  { -60, 106 }, { -48, 46 },  { -64, 63 },
    { -68, 84 },  { -60, 106 }, { 1, 64 },    { -64, 21 },  { -68, 72 },  { -80, 21 },  { -68, 72 },  { -40, 48 },
    { -40, 48 },  { -56, 72 },  { -72, 0 },   { 72, 0 },    { -32, 56 },  { -8, 0 },    { 64, 0 },    { -90, 58 },
    { -81, 66 },  { -100, 79 }, { -46, 67 },  { -90, 57 },  { -90, 57 },  { -78, 62 },  { -56, 136 }, { -44, 62 },
    { -36, 82 },  { -38, 72 },  { -38, 62 },  { -76, 35 },  { -63, 37 },  { -143, 67 }, { -99, 45 },  { -138, 86 },
    { -113, 74 }, { -108, 27 }, { -117, 54 }, { -146, 30 }, { -130, 72 }, { -17, 96 },  { -48, 0 },   { -64, 0 },
    { -29, 144 }, { -44, 60 },  { -76, 57 },  { -91, 62 },  { -66, 46 },  { -88, 48 },  { -68, 68 },  { -85, 71 },
    { -95, 54 },  { -47, 66 },  { -34, 85 },  { -35, 85 },  { -30, 112 }, { -30, 112 }, { 0, 80 },    { -40, 40 },
    { 0, -4 },    { 0, -4 },    { -49, 64 },  { 1, 38 },    { -141, 0 },  { 0, 68 },    { 7, 104 },   { 6, 85 },
    { 21, 79 },   { 3, -5 },    { -30, 70 },  { -46, 100 }, { -44, 82 },  { -36, 112 }, { -72, 64 },  { -72, 96 },
    { -62, 44 },  { -92, 81 },  { -96, 43 },  { -94, 66 },  { -35, 101 }, { -50, 78 },  { -37, 38 },  { -50, 61 },
    { -72, 29 },  { -91, 78 },  { -52, 97 },  { -26, 114 }, { -51, 74 },  { -49, 63 },  { -53, 3 },   { -56, 80 },
    { -72, 0 },   { -48, 104 }, { 0, 2 },     { -48, 50 }
};

extern BG bg_w;
extern u8 Combo_Demo_Flag;
extern u8 Pause_Hit_Marks;
extern s16 Last_Called_SE;
extern s8 Suicide[8];
extern s16 EXE_flag;
extern u8 Game_pause;
extern SERequest sound_effect_request[];

void urian_guard_se_check(WORK_Other *ewk, PLW *twk, u16 oto);
void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
s16 random_16(void);
void pp_screen_quake(s32 ix);
void sort_push_request8(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

void effect_02_move(WORK_Other *ewk) {
    const HMDT *tad;
    const EXPLEM *edt;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.char_table[0] = _ef01_char_table;
        tad = &hmdt[ewk->wu.kohm];

        if (ewk->wu.vital_old == 2) {
            ewk->wu.kohm = tad->deff;

            if (ewk->wu.dm_vital != 0) {
                ewk->wu.kohm = tad->kezu;
            }
        }

        tad = &hmdt[ewk->wu.kohm];

        if (tad->hits == 0) {
            if (tad->se) {
                urian_guard_se_check(ewk, (PLW *)ewk->wu.target_adrs, tad->se);
            } else {
                Last_Called_SE = 0;
            }

            if (tad->quake != 0) {
                bg_w.quake_y_index = gqdt[tad->quake][1];
                pp_screen_quake(bg_w.quake_y_index);
            }

            push_effect_work(&ewk->wu);
            break;
        }

        if (tad->status & 8) {
            ewk->wu.disp_flag = 2;
        } else {
            ewk->wu.disp_flag = 1;
        }

        if (tad->status & 0x40) {
            if (((PLW *)ewk->wu.target_adrs)->wu.work_id == 1) {
                ewk->wu.dir_timer = ((PLW *)ewk->wu.target_adrs)->player_number;
            } else {
                ewk->wu.dir_timer = ((WORK_Other *)ewk->wu.target_adrs)->master_player;
            }
        }

        if (tad->col) {
            ewk->wu.my_col_code = hcct[tad->col];
        } else if (tad->status & 0x80) {
            ewk->wu.my_col_code = ((PLW *)ewk->wu.target_adrs)->wu.my_col_code;
        }

        if (tad->se) {
            urian_guard_se_check(ewk, (PLW *)ewk->wu.target_adrs, tad->se);
        } else {
            Last_Called_SE = 0;
        }

        if (tad->status & 4) {
            ewk->wu.rl_flag = ewk->wu.dm_rl;
        }

        if (tad->status & 0x10) {
            if (tad->status & 0x20) {
                edt = &explem2[tad->emhix][ewk->wu.dir_timer];
            } else {
                edt = &explem[tad->myhix];
            }

            if (ewk->wu.rl_flag) {
                ewk->wu.xyz[0].disp.pos -= *(s16 *)&edt->hx;
            } else {
                ewk->wu.xyz[0].disp.pos += *(s16 *)&edt->hx;
            }

            ewk->wu.xyz[1].disp.pos += *(s16 *)&edt->hy;
        } else {
            ewk->wu.xyz[0].disp.pos += ewk->wu.old_pos[0];
            ewk->wu.xyz[1].disp.pos += ewk->wu.old_pos[1];
        }

        if (ewk->wu.weight_level) {
            ewk->wu.xyz[0].disp.pos += ((PLW *)ewk->my_master)->muriyari_ugoku;
        }

        if (tad->status & 2) {
            ewk->wu.xyz[0].disp.pos += random_16() - 7;
            ewk->wu.xyz[1].disp.pos += (random_16() & 7) - 3;
        }

        ewk->wu.scr_mv_x = gqdt[tad->quake][0];
        ewk->wu.scr_mv_y = gqdt[tad->quake][1];
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;

        if (tad->status & 0x10) {
            set_char_move_init(&ewk->wu, 0, edt->chix);
        } else {
            ewk->wu.dir_old = 0;

            if (tad->dir) {
                ewk->wu.dir_old = hit_mark_dir_table[ewk->wu.direction];

                if (ewk->wu.dir_old < 0) {
                    ewk->wu.rl_flag = 1;
                    ewk->wu.dir_old = -ewk->wu.dir_old;
                }
            }

            set_char_move_init(&ewk->wu, 0, tad->hits + ewk->wu.dir_old);
        }

        if (ewk->wu.char_index == 0x4B) {
            ewk->wu.my_mr_flag = 1;
            ewk->wu.my_mr.size.x = 127;
            ewk->wu.my_mr.size.y = 63;
            ewk->wu.my_col_code |= (ewk->master_id == 1) * 16;
        }

        if (!Pause_Hit_Marks) {
            sort_push_request8(&ewk->wu);
        }

        break;

    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[6] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        if (Pause_Hit_Marks) {
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0]++;
                break;
            }

            if (ewk->wu.scr_mv_x && --ewk->wu.scr_mv_x == 0) {
                bg_w.quake_y_index = ewk->wu.scr_mv_y;
                pp_screen_quake(bg_w.quake_y_index);
            }
        }

        sort_push_request8(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void urian_guard_se_check(WORK_Other *ewk, PLW *twk, u16 oto) {
    if (twk->player_number == 13 && (oto == 266 || oto == 267)) {
        sound_effect_request[280](ewk, 280);
        Last_Called_SE = 280;
        return;
    }

    sound_effect_request[oto](ewk, oto);
    Last_Called_SE = oto;
}

s32 effect_02_init(WORK *wk, s8 dmgp, s8 mkst, s8 dmrl) {
    WORK_Other *ewk;
    WORK_Other *dwk;
    s16 ix;

    if (Combo_Demo_Flag & 0x80) {
        return 0;
    }

    if ((ix = pull_effect_work(2)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 2;
    ewk->wu.work_id = 64;
    ewk->wu.vital_new = dmgp;
    ewk->wu.vital_old = mkst;
    ewk->wu.dm_rl = dmrl;
    ewk->wu.kohm = wk->att.hit_mark;
    ewk->wu.direction = wk->dir_atthit;
    ewk->wu.dm_vital = wk->kezuri_pow;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_mr_flag = 0;
    ewk->wu.xyz[0].disp.pos = ewk->wu.position_x = wk->xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = ewk->wu.position_y = wk->xyz[1].disp.pos;
    ewk->wu.xyz[2].disp.pos = 26;
    ewk->wu.old_pos[0] = wk->hit_mark_x - wk->xyz[0].disp.pos;
    ewk->wu.old_pos[1] = wk->hit_mark_y - wk->xyz[1].disp.pos;
    ewk->wu.weight_level = 0;

    if (wk->work_id == 1) {
        ewk->my_master = (u32 *)wk;
        ewk->master_id = wk->id;
        ewk->master_work_id = wk->work_id;
        ewk->wu.target_adrs = wk->target_adrs;
        ewk->wu.my_col_code = wk->my_col_code;
        ewk->master_player = ewk->wu.dir_timer = ((PLW *)wk)->player_number;
        ewk->wu.weight_level = 1;
    } else {
        dwk = (WORK_Other *)wk;
        ewk->my_master = (u32 *)dwk->my_master;
        ewk->master_id = dwk->master_id;
        ewk->master_work_id = dwk->master_work_id;
        ewk->wu.target_adrs = ((WORK *)dwk->my_master)->target_adrs;
        ewk->wu.my_col_code = ((WORK *)dwk->my_master)->my_col_code;
        ewk->master_player = ewk->wu.dir_timer = dwk->master_player;
    }

    ewk->wu.blink_timing = ewk->master_id;
    return 0;
}
