/* Effect L4, retail sf33rd.xbe.
 * effect_L4_move is 0xB94E5 size 0x87 and is interior.
 * effect_L4_init is 0xB956C size 0xBF and is interior.
 * The pull failure jumps to the shared epilogue.
 * 0xB94A4 stays unnamed. 0xB962B stays unnamed.
 *
 * 0xB94A4 repeats the case 1 display check of
 * effect_L4_move without the char_move call. The
 * PlayStation 2 source has no such function.
 * effl4_data_tbl is 0x2847B0 and matches the
 * PlayStation 2 values. The rows were not pasted. The
 * _frc_char_table immediate is 0x2FCFD0. Those bytes
 * were not compared. EXE_flag is 0xC7C834. Game_pause
 * is 0x7A89B0. char_move is 0x2008E.
 * set_char_move_init is 0x200A9.
 * sort_push_request4 is 0x9E092.
 * push_effect_work is 0x4AC6C. pull_effect_work
 * stays pull_effect_work. obr_no_disp_check,
 * range_x_check3, and get_my_trans_mode are named. frw
 * is 0xC806A0 and each object is 0x700 bytes.
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
    u8 pad_rno[0x24 - 0xA];
    s16 routine_no[8];
    u8 pad_cg[0x48 - 0x34];
    s8 cgromtype;
    u8 pad_pos[0xB];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_ct[0x1AC - 0x70];
    u32 *char_table[1];
    u8 pad_ci[0x208 - 0x1B0];
    s16 char_index;
    u8 pad_col[0x23C - 0x20A];
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
    u32 *my_master;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
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
extern s16 EXE_flag;
extern u8 Game_pause;
extern u32 _frc_char_table[];

const s16 effl4_data_tbl[24] = { 143, 96,  73, 9,  223, 120, 73, 10, 303, 104, 73, 11,
                                 367, 112, 73, 12, 399, 144, 73, 13, 487, 120, 73, 14 };

s32 obr_no_disp_check(void);
s32 range_x_check3(WORK_Other *ewk, s16 rad);
void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sort_push_request4(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void effect_L4_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
        }

        if (!obr_no_disp_check() && range_x_check3(ewk, 208)) {
            ewk->wu.position_x = (ewk->wu.xyz[0].disp.pos & 0xFFFF) + 1;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
            sort_push_request4(&ewk->wu);
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_L4_init(void) {
    WORK_Other *ewk;
    s16 ix;
    s16 i;
    const s16 *data_ptr = effl4_data_tbl;

    for (i = 0; i < 6; i++) {
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }

        ewk = (WORK_Other *)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 214;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 300;
        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.position_z = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.char_table[0] = _frc_char_table;
    }

    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_L4_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (obr_no_disp_check() == 0 && range_x_check3(ewk, 0xD0)) {
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos + 1;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
            sort_push_request4(&ewk->wu);
        }

        break;
    }
}
