/* Opening pieces, retail sf33rd.xbe.
 * eff36_move00 is 0xB78DA size 0xAC and is interior.
 * eff36_move01 is 0xB7986 size 0x6A and is interior.
 * eff36_move02 is 0xB79F0 size 0x7A and is interior.
 * eff36_move03 is 0xB7A6A size 0x7D and is interior.
 * eff36_move04 is 0xB7AE7 size 0x105 and is interior.
 * eff36_move05 is 0xB7BEC size 0x81 and is interior.
 * eff36_move06 is 0xB7C6D size 0xE9 and is interior.
 * effect_36_move is 0xB7D56 size 0x81 and is interior.
 * effect_36_init is 0xB7DD7 size 0xEC and is interior.
 * The init's -1 path is an early ret. 0xB7EC3 stays unnamed.
 *
 * eff36_data_tbl is 0x284388 and matches the 29 rows.
 * The rows were not pasted. eff36_04_tbl is not a
 * separate object. Cases 1, 2, and 3 compare
 * gSeqStatus[0] with 5, 9, and 13. Case 1 also
 * rejects 0x74. The C keeps the table. Those cases
 * share the advance tail. The C keeps the three
 * copies. eff36_move06 stores old_rno[6] after the
 * size increments. The C keeps the PlayStation 2 order.
 * The init omits the Debug_w[48] test. The first
 * table read adds 0x12C in one store. The character
 * table immediate is 0x3059F0. Those bytes were not
 * compared. gSeqStatus[0] is the byte at 0xC7C836.
 * op_w is 0xC7E1C0 and index is the word at 0xC7E1C4.
 * disp_pos_trans_entry and disp_pos_trans_entry5 share
 * 0xEF0C0. push_color_trans_req is 0xB61A0.
 * char_move is 0x2008E. set_char_move_init2
 * stays set_char_move_init2. push_effect_work stays
 * push_effect_work. pull_effect_work is 0x4A6A8.
 * frw is 0xC806A0 and each object is 0x700 bytes.
 * 0xB6890 stays unnamed. 0xB61A0 is push_color_trans_req.
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
    s16 old_rno[8];
    u8 pad_cg[4];
    s8 cgromtype;
    u8 pad_pos[0xB];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_ct[0x1AC - 0x70];
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
} WORK_Other;

typedef struct {
    s8 r_no_0;
    s8 r_no_1;
    s8 r_no_2;
    s8 old_rno;
    s16 index;
} OP_W;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, old_rno[6]) == 0x40, "old_rno6");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].cal) == 0x64, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0.pos");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
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
_Static_assert(__builtin_offsetof(OP_W, index) == 4, "op_w.index");
#endif

extern OP_W op_w;
extern u8 gSeqStatus[1];
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s16 eff36_data_tbl[29][9] = { { 0, 1, 512, 128, 73, 5, 1, 41, 42 },   { 0, 1, 392, 128, 70, 5, 2, 41, 42 },
                                    { 25, 0, 496, 192, 80, 3, 12, 42, 45 }, { 0, 1, 512, 128, 73, 5, 1, 43, 44 },
                                    { 0, 1, 440, 128, 70, 5, 3, 43, 44 },   { 0, 1, 512, 128, 73, 5, 1, 45, 46 },
                                    { 0, 1, 488, 128, 70, 5, 4, 45, 46 },   { 27, 0, 480, 176, 80, 3, 13, 46, 49 },
                                    { 0, 1, 512, 128, 73, 5, 1, 47, 48 },   { 0, 1, 528, 128, 70, 5, 5, 47, 48 },
                                    { 0, 1, 512, 128, 73, 5, 1, 49, 50 },   { 0, 1, 576, 128, 70, 5, 6, 49, 50 },
                                    { 39, 0, 480, 160, 80, 3, 14, 50, 53 }, { 0, 1, 512, 128, 73, 5, 1, 51, 52 },
                                    { 0, 1, 624, 128, 70, 5, 7, 51, 52 },   { 0, 2, 512, 16, 70, 4, 1, 53, 54 },
                                    { 0, 3, 600, 128, 65, 10, 1, 89, 91 },  { 0, 4, 512, 128, 65, 3, 22, 91, 92 },
                                    { 0, 2, 320, 48, 70, 8, 1, 25, 26 },    { 0, 2, 320, 128, 70, 9, 1, 25, 26 },
                                    { 0, 2, 320, 32, 70, 8, 1, 26, 27 },    { 0, 2, 320, 160, 70, 9, 1, 26, 27 },
                                    { 0, 5, 512, 144, 70, 7, 1, 8, 9 },     { 0, 5, 512, 64, 70, 7, 1, 14, 15 },
                                    { 0, 5, 544, 136, 70, 6, 1, 54, 55 },   { 0, 5, 448, 136, 70, 6, 1, 57, 58 },
                                    { 0, 5, 544, 136, 70, 6, 1, 79, 80 },   { 0, 5, 464, 136, 70, 6, 1, 81, 82 },
                                    { 0, 6, 488, 120, 66, 11, 1, 91, 92 } };

extern EffectRow frw[];

void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void char_move(WORK *wk);
void sub_000EF0C0(WORK_Other *ewk);
void push_color_trans_req(s32 from_col, s32 to_col);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s16 curr);

void eff36_move00(WORK_Other *ewk);
void eff36_move01(WORK_Other *ewk);
void eff36_move02(WORK_Other *ewk);
void eff36_move03(WORK_Other *ewk);
void eff36_move04(WORK_Other *ewk);
void eff36_move05(WORK_Other *ewk);
void eff36_move06(WORK_Other *ewk);

const s16 eff36_04_tbl[4] = { 0, 5, 9, 13 };

void effect_36_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (ewk->wu.old_rno[1] <= op_w.index) {
            ewk->wu.routine_no[0] += 1;
        } else if (ewk->wu.old_rno[2] <= op_w.index) {
            switch (ewk->wu.routine_no[1]) {
            case 0:
                eff36_move00(ewk);
                break;

            case 1:
                eff36_move01(ewk);
                break;

            case 2:
                eff36_move02(ewk);
                break;

            case 3:
                eff36_move03(ewk);
                break;

            case 4:
                eff36_move04(ewk);
                break;

            case 5:
                eff36_move05(ewk);
                break;

            case 6:
                eff36_move06(ewk);
                break;

            default:
                break;
            }
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff36_move00(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        push_color_trans_req(ewk->wu.my_col_code & 0x1FF, 0);
        ewk->wu.my_col_code = 0;
        break;

    case 1:
        ewk->wu.my_mr.size.x += 1;
        ewk->wu.my_mr.size.y += 1;

        if (ewk->wu.my_mr.size.x >= 88) {
            ewk->wu.routine_no[2] += 1;
            ewk->wu.my_mr.size.x = 88;
            ewk->wu.my_mr.size.y = 88;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void eff36_move01(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);

        if (ewk->wu.type == 0) {
            push_color_trans_req((ewk->wu.my_col_code & 0x1FF) + 3, 1);
        }

        ewk->wu.my_col_code = 0;
        break;

    case 1:
        sub_000EF0C0(ewk);
        break;
    }
}

void eff36_move02(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);

        if (ewk->wu.type == 15) {
            push_color_trans_req((ewk->wu.my_col_code & 0x1FF) + 8, 0);
        } else if (ewk->wu.type <= 18) {
            push_color_trans_req((ewk->wu.my_col_code & 0x1FF) + 8, 1);
        }

        ewk->wu.my_col_code = 0;
        break;

    case 1:
        char_move(&ewk->wu);
        sub_000EF0C0(ewk);
        break;
    }
}

void eff36_move03(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        push_color_trans_req((ewk->wu.my_col_code & 0x1FF) + 8, 1);
        ewk->wu.my_col_code = 0;
        break;

    case 1:
        char_move(&ewk->wu);
        ewk->wu.xyz[0].cal -= 0x8000 + 0x8000;

        if (ewk->wu.xyz[0].disp.pos < 288) {
            ewk->wu.routine_no[0] = 99;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void eff36_move04(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[6] = 4;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        push_color_trans_req((ewk->wu.my_col_code & 0x1FF) + 2, 1);
        ewk->wu.my_col_code = 0;
        break;

    case 1:
        if (ewk->wu.old_rno[6] <= 0) {
            ewk->wu.disp_flag = 0;
        } else {
            ewk->wu.old_rno[6] -= 1;
        }

        if ((gSeqStatus[0] >= eff36_04_tbl[ewk->wu.routine_no[2]]) && (gSeqStatus[0] != 0x74)) {
            ewk->wu.routine_no[2] += 1;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_rno[6] = 4;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], 0x17, 0);
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        if (ewk->wu.old_rno[6] <= 0) {
            ewk->wu.disp_flag = 0;
        } else {
            ewk->wu.old_rno[6] -= 1;
        }

        if (gSeqStatus[0] >= eff36_04_tbl[ewk->wu.routine_no[2]]) {
            ewk->wu.routine_no[2] += 1;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_rno[6] = 4;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], 0x18, 0);
        }

        sub_000EF0C0(ewk);
        break;

    case 3:
        if (ewk->wu.old_rno[6] <= 0) {
            ewk->wu.disp_flag = 0;
        } else {
            ewk->wu.old_rno[6] -= 1;
        }

        if (gSeqStatus[0] >= eff36_04_tbl[ewk->wu.routine_no[2]]) {
            ewk->wu.routine_no[2] += 1;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_rno[6] = 4;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], 0x19, 0);
        }

        sub_000EF0C0(ewk);
        break;

    case 4:
        sub_000EF0C0(ewk);
        break;
    }
}

void eff36_move05(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);

        if (ewk->wu.type <= 24) {
            push_color_trans_req((ewk->wu.my_col_code & 0x1FF) + 8, 1);
        }

        ewk->wu.my_col_code = 0;
        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type == 255) {
            ewk->wu.routine_no[0] += 1;
            break;
        }

        sub_000EF0C0(ewk);
        break;
    }
}

void eff36_move06(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        push_color_trans_req((ewk->wu.my_col_code & 0x1FF) + 0x15, 8);
        push_color_trans_req((ewk->wu.my_col_code & 0x1FF) + 0x16, 9);
        ewk->wu.my_col_code = 8;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 66;
        ewk->wu.my_mr.size.y = 66;
        sub_000EF0C0(ewk);
        ewk->wu.old_rno[6] = 2;
        break;

    case 1:
        ewk->wu.old_rno[6] -= 1;

        if (ewk->wu.old_rno[6] <= 0) {
            ewk->wu.old_rno[6] = 2;
            ewk->wu.my_mr.size.x += 1;
            ewk->wu.my_mr.size.y += 1;

            if (ewk->wu.my_mr.size.x >= 127) {
                ewk->wu.routine_no[2] += 1;
                ewk->wu.my_mr.size.x = 127;
                ewk->wu.my_mr.size.y = 127;
            }
        }

        /* fallthrough */

    case 2:
        sub_000EF0C0(ewk);
        break;
    }
}

s32 effect_36_init(u8 typenum) {
    WORK_Other *ewk;
    s16 ix;
    const s16 *data_ptr;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    data_ptr = eff36_data_tbl[typenum];
    ewk->wu.id = 0x24;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 0x10;
    ewk->wu.type = typenum;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = (u32 *)0x3059F0;
    ewk->wu.my_family = 2;
    ewk->wu.my_mts = 9;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.my_col_code = 0x12C;
    ewk->wu.my_col_code += *data_ptr++;
    ewk->wu.routine_no[1] = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.old_rno[0] = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.old_rno[2] = *data_ptr++;
    ewk->wu.old_rno[1] = *data_ptr++;
    effect_36_move(ewk);
    return 0;
}
