/* Effect G8, retail sf33rd.xbe.
 * effg8_range_check is 0xBE735 size 0x31 and is interior.
 * effect_G8_init is 0xBE766 size 0xA0 and is interior.
 * effect_G8_move is 0xBE806 size 0x12F and is interior.
 * The pull failure jumps to the shared epilogue.
 * 0xBE719 stays unnamed. 0xBE935 stays unnamed.
 *
 * 0xBE719 copies the position words and calls
 * sort_push_request4. The PlayStation 2 source has no
 * such function. effect_G8_move case 0 stores the
 * constants 192 and 128 into xyz without reading
 * old_rno back, and case 2 adds to size.y before
 * size.x. effg8_range_check ends with setg. The C keeps
 * the PlayStation 2 order. effg8_sp_tbl is 0x285FF8 and
 * matches the PlayStation 2 values. akebono_flag is
 * 0x7BC4A9. The _etc2_char_table immediate is 0x2F77F0.
 * Those bytes were not compared. set_char_move_init
 * stays sub_000200A9. random_16 stays sub_0009326B.
 * sort_push_request4 stays sub_0009E092. add_x_sub
 * stays sub_000EF072. add_y_sub stays sub_000EF088.
 * all_cgps_put_back stays sub_0004384A.
 * push_effect_work stays sub_0004AC6C. pull_effect_work
 * stays sub_0004A6A8. get_my_trans_mode is named. frw
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

typedef union {
    s32 sp;
} Reg32SpReal;

typedef struct {
    Reg32SpReal a[2];
    Reg32SpReal d[2];
    s16 kop[2];
    u16 index;
} MVXY;

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
    u8 pad_pos[0x54 - 0x49];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_mv[0xC];
    MVXY mvxy;
    u8 pad_ct[0x1AC - 0x94];
    u32 *char_table[1];
    u8 pad_col[0x23C - 0x1B0];
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
    u8 pad_end[0x388 - 0x256];
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, old_rno[2]) == 0x38, "old_rno2");
_Static_assert(__builtin_offsetof(WORK, old_rno[3]) == 0x3A, "old_rno3");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[0].sp) == 0x7C, "a0sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[1].sp) == 0x80, "a1sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[0].sp) == 0x84, "d0sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[1].sp) == 0x88, "d1sp");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
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
#endif

extern EffectRow frw[];
extern s8 akebono_flag;
extern u32 _etc2_char_table[];

extern const s32 effg8_sp_tbl[28][4];

void sub_000200A9(WORK *wk, s16 koc, s16 index);
s16 sub_0009326B(void);
void sub_0009E092(WORK *wk);
void sub_000EF072(WORK_Other *ewk);
void sub_000EF088(WORK_Other *ewk);
void sub_0004384A(WORK *wk);
void sub_0004AC6C(WORK *wk);
s16 sub_0004A6A8(s16 index);
s16 get_my_trans_mode(s16 curr);

s16 effg8_range_check(WORK_Other *ewk);

void effect_G8_move(WORK_Other *ewk) {
    if (!akebono_flag) {
        ewk->wu.routine_no[0] = 99;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 0;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 0;
        ewk->wu.my_mr.size.y = 0;
        sub_000200A9(&ewk->wu, 0, 17);
        ewk->wu.old_rno[3] = sub_0009326B();
        ewk->wu.old_rno[0] = 192;
        ewk->wu.old_rno[1] = 128;
        ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[0];
        ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[1];
        ewk->wu.mvxy.a[0].sp = effg8_sp_tbl[ewk->wu.old_rno[2]][0];
        ewk->wu.mvxy.d[0].sp = effg8_sp_tbl[ewk->wu.old_rno[2]][1];
        ewk->wu.mvxy.a[1].sp = effg8_sp_tbl[ewk->wu.old_rno[2]][2];
        ewk->wu.mvxy.d[1].sp = effg8_sp_tbl[ewk->wu.old_rno[2]][3];
        break;

    case 1:
        ewk->wu.old_rno[3] -= 1;

        if (ewk->wu.old_rno[3] > 0) {
            break;
        }

        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 1;
        /* fallthrough */

    case 2:
        ewk->wu.my_mr.size.x += 2;
        ewk->wu.my_mr.size.y += 2;

        if (ewk->wu.my_mr.size.x >= 63) {
            ewk->wu.routine_no[0] += 1;
        }

        /* fallthrough */

    case 3:
        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (effg8_range_check(ewk)) {
            ewk->wu.routine_no[0] = 99;
            break;
        }

        ewk->wu.position_x = (ewk->wu.xyz[0].disp.pos & 0xFFFF);
        ewk->wu.position_y = (ewk->wu.xyz[1].disp.pos & 0xFFFF);
        sub_0009E092(&ewk->wu);
        break;

    default:
        sub_0004384A(&ewk->wu);
        sub_0004AC6C(&ewk->wu);
        break;
    }
}

s16 effg8_range_check(WORK_Other *ewk) {
    if (ewk->wu.xyz[0].disp.pos < 88) {
        return 1;
    }

    if (ewk->wu.xyz[0].disp.pos > 296) {
        return 1;
    }

    if (ewk->wu.xyz[1].disp.pos < 64) {
        return 1;
    }

    if (ewk->wu.xyz[1].disp.pos > 208) {
        return 1;
    }

    return 0;
}

s32 effect_G8_init(void) {
    WORK_Other *ewk;
    s16 ix;
    s16 i;

    for (i = 0; i < 16; i++) {
        if ((ix = sub_0004A6A8(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other *)frw[ix];
        ewk->wu.id = 168;
        ewk->wu.be_flag = 1;
        ewk->wu.type = i;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 30;
        ewk->wu.char_table[0] = _etc2_char_table;
        ewk->wu.my_family = 4;
        ewk->wu.my_priority = ewk->wu.position_z = 10;
        ewk->wu.old_rno[2] = i;
        ewk->wu.my_mts = 14;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    }

    return 0;
}

const s32 effg8_sp_tbl[28][4] = { { 0, 0, 8192, 16384 },
                                  { -65536, -32768, 4096, 32768 },
                                  { -32768, 32768, 0, 16384 },
                                  { -131072, -32768, 0, 0 },
                                  { -65536, -32768, 0, -8192 },
                                  { 0, 0, -8192, -16384 },
                                  { -32768, -32768, -4096, -32768 },
                                  { -65536, -32768, 0, -16384 },
                                  { 0, 0, 8192, 16384 },
                                  { 65536, 32768, 4096, 32768 },
                                  { 32768, 32768, 0, 16384 },
                                  { 131072, 32768, 0, 0 },
                                  { 65536, 32768, 0, -8192 },
                                  { 0, 0, -8192, -16384 },
                                  { 65536, 32768, -4096, -32768 },
                                  { 32768, 32768, 0, -16384 },
                                  { 16384, 131072, 8192, 0 },
                                  { -16384, -131072, -8192, 0 },
                                  { 16384, 131072, -8192, -32768 },
                                  { -12288, -131072, 8192, 32768 },
                                  { -4096, -65536, -8192, -32768 },
                                  { 0, 0, 4096, 65536 },
                                  { 0, 32768, -8192, -32768 },
                                  { 16384, 131072, 0, 8192 },
                                  { 0, 0, 0, 16384 },
                                  { 0, -16384, -8192, -32768 },
                                  { 0, -131072, -8192, -32768 },
                                  { 4096, 131072, -4096, -16384 } };
