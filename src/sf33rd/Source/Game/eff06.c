/* Screen objects, retail sf33rd.xbe.
 * effect_06_move is 0xB6A3F size 0x63 and is interior.
 * effect_06_init is 0xB6AA2 size 0x11F and is interior.
 * The init size runs through the or eax, -1 tail after its ret.
 *
 * scr_obj_num6 is 0x283D80 and matches the 22 counts.
 * scr_obj_data6 is 0x332D78. Its 22 pointers and the s16 rows
 * they address match. Index 1 shares its row with index 13.
 * Index 5 shares its row with index 17. The dummy rows share
 * 0x283A8C. char_add is the effect 5 table at 0x332CC8.
 * Those pointers are Xbox addresses. The rows were not pasted.
 *
 * frw is 0xC806A0 and each object is 0x700 bytes.
 * bg_w.bg_index is 0x7BC550.
 * set_char_move_init is 0x200A9. all_cgps_put_back
 * stays sub_0004384A. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. suzi_offset_set stays
 * suzi_offset_set.
 */

#include "types.h"
#include "structs.h"





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
/* The tables the pointer tables reach, at the addresses their pointers  *
 * hold (analysis-ps2map/portdata.py): st0000_data_tbl is 0x283DAC,
 * st0100_data_tbl is 0x283DC0, st0200_data_tbl is 0x283E60, st0400_data_tbl
 * is 0x283F00, st0500_data_tbl is 0x283F30, st0700_data_tbl is 0x284010,
 * st0800_data_tbl is 0x284030, st0900_data_tbl is 0x2840E0, st0A00_data_tbl
 * is 0x283EA0, st0B00_data_tbl is 0x283E20, st0c00_data_tbl is 0x284110,
 * st0e00_data_tbl is 0x284140, st1000_data_tbl is 0x284158, st1100_data_tbl
 * is 0x284178, st1300_data_tbl is 0x283FA0, st1400_data_tbl is 0x2841B8. */
/* Pasted from the PS2 file. */
const s16 scr_obj_num6[22] = { 1, 6, 4, 0, 3, 1, 0, 2, 8, 3, 0, 4, 3, 0, 1, 1, 4, 0, 1, 1, 0, 0 };
/* Pasted from the PS2 file. */
/* Pasted from the PS2 file. */
extern const s16 stg_dum_data_tbl[1];

const s16 st0000_data_tbl[8] = { 0, 2, 8492, 640, 48, 82, 0, 0 };

const s16 st0100_data_tbl[48] = { 0, 1, 300,  648, 48, 86, 1,  0, 0, 1, 300,  728, 48, 86, 2,  0,
                                  0, 1, 300,  792, 48, 86, 3,  0, 0, 2, 8492, 648, 16, 10, 18, 0,
                                  0, 2, 8492, 416, 48, 70, 20, 0, 0, 2, 8492, 264, 48, 72, 21, 0 };

const s16 st0B00_data_tbl[32] = { 0, 1, 300, 648, 48, 86, 1, 0, 0, 1, 300, 728, 48,  86, 2,  0,
                                  0, 1, 300, 792, 48, 86, 3, 0, 0, 2, 300, 463, 193, 83, 22, 0 };

const s16 st0200_data_tbl[32] = { 0, 6, 8492, 160, 64, 86, 0, 0, 0, 6, 8492, 224, 64, 86, 1, 0,
                                  0, 6, 8492, 336, 64, 86, 2, 0, 0, 6, 8492, 432, 64, 86, 3, 0 };

const s16 st0A00_data_tbl[48] = { 0, 3, 300, 448, 16, 88, 9,  0, 0, 3, 300, 528, 16, 88, 11, 0,
                                  0, 3, 300, 608, 16, 88, 12, 0, 0, 3, 300, 688, 16, 88, 13, 0,
                                  0, 3, 300, 768, 16, 88, 14, 0, 0, 3, 300, 848, 16, 88, 15, 0 };

const s16 st0400_data_tbl[24] = { 0,  2,  8492, 672, 24, 10, 0,   0,   0, 2,  300, 416,
                                  72, 82, 1,    0,   0,  2,  300, 192, 0, 10, 12,  0 };

const s16 st0500_data_tbl[56] = { 0,   3, 8492, 432, 0,   82,  8, 0,   0,   2, 300, 160, 0,   84,  0, 0,   0,   2, 300,
                                  256, 0, 84,   1,   0,   0,   2, 300, 352, 0, 84,  2,   0,   0,   2, 300, 672, 0, 84,
                                  5,   0, 0,    2,   300, 768, 0, 84,  6,   0, 0,   2,   300, 864, 0, 84,  7,   0 };

const s16 st1300_data_tbl[56] = { 0, 3,  8492, 432, 0, 82, 20,  0,   0, 2,  300, 160, 0, 84, 12,  0,   0, 2,  300, 256,
                                  0, 84, 13,   0,   0, 2,  300, 352, 0, 84, 14,  0,   0, 2,  300, 672, 0, 84, 17,  0,
                                  0, 2,  300,  768, 0, 84, 18,  0,   0, 2,  300, 864, 0, 84, 19,  0 };

const s16 st0700_data_tbl[16] = { 0, 6, 8492, 288, 80, 93, 0, 0, 0, 6, 8492, 416, 48, 93, 1, 0 };

const s16 st0800_data_tbl[88] = { 0,   7,   8492, 256,  43,   88,   10,   0,    0,   7,  8492, 384,  43,   88,   11,
                                  0,   0,   7,    8492, 752,  43,   88,   16,   0,   0,  2,    8492, 192,  48,   86,
                                  0,   0,   0,    2,    8492, 576,  48,   86,   2,   0,  0,    2,    8492, 800,  48,
                                  86,  3,   0,    0,    6,    8492, 640,  128,  85,  6,  0,    0,    6,    8492, 368,
                                  160, 85,  7,    0,    0,    2,    8492, 336,  88,  86, 6,    0,    0,    6,    8492,
                                  514, 136, 86,   8,    0,    0,    6,    8492, 722, 56, 86,   9,    0 };

const s16 st0900_data_tbl[24] = { 0,  3,  8492, 464, 64, 86, 6,    0,   0,  7,  8492, 512,
                                  96, 88, 7,    0,   0,  6,  8492, 832, 16, 10, 5,    0 };

const s16 st0c00_data_tbl[24] = { 0,  3,  8492, 464, 64, 86, 0,    0,   0,  7,  8492, 512,
                                  96, 88, 1,    0,   0,  6,  8492, 832, 16, 10, 5,    0 };

const s16 st0e00_data_tbl[8] = { 0, 2, 8492, 592, 16, 10, 0, 0 };

const s16 st1000_data_tbl[16] = { 0, 2, 8492, 448, 16, 14, 1, 0, 0, 2, 8492, 928, 32, 72, 3, 0 };

const s16 st1100_data_tbl[32] = { 0, 1, 8492, 256, 64,  90, 0, 0, 0, 1, 8492, 384, 128, 90, 1, 0,
                                  0, 1, 8492, 624, 128, 90, 4, 0, 0, 3, 8492, 784, 128, 10, 7, 0 };

const s16 st1400_data_tbl[8] = { 0, 3, 300, 496, 64, 88, 4, 0 };

const s16* scr_obj_data6[22] = { st0000_data_tbl,  st0100_data_tbl,  st0200_data_tbl, stg_dum_data_tbl, st0400_data_tbl,
                                 st0500_data_tbl,  stg_dum_data_tbl, st0700_data_tbl, st0800_data_tbl,  st0900_data_tbl,
                                 st0A00_data_tbl,  st0B00_data_tbl,  st0c00_data_tbl, st0100_data_tbl,  st0e00_data_tbl,
                                 st1000_data_tbl,  st1100_data_tbl,  st0500_data_tbl, st1300_data_tbl,  st1400_data_tbl,
                                 stg_dum_data_tbl, stg_dum_data_tbl };
extern u32 *char_add[22];
extern EffectRow frw[];

s32 obr_no_disp_check(void);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
s32 compel_dead_check(WORK_Other *ewk);
void disp_pos_trans_entry_rs(WORK_Other *ewk);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void suzi_offset_set(WORK_Other *ewk);
s16 get_my_trans_mode(s16 curr);

void effect_06_move(WORK_Other *ewk) {
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
            break;
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_06_init(void) {
    WORK_Other *ewk;
    s16 ix;
    s16 lp_cnt;
    s16 i;
    const s16 *data_ptr;

    lp_cnt = scr_obj_num6[bg_w.bg_index];

    if (lp_cnt == 0) {
        return 0;
    }

    data_ptr = scr_obj_data6[bg_w.bg_index];

    for (i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other *)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 6;
        ewk->wu.work_id = 16;
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
