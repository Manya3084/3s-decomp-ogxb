/* Effect L5, retail sf33rd.xbe.
 * hukuromoji_move is 0xB9665 size 0xF4 and is interior.
 * effect_L5_init is 0xB9759 size 0xA7 and is interior.
 * effect_L5_move is 0xB9800 size 0x61 and is interior.
 * The pull failure is an early ret.
 * 0xB962B stays unnamed. 0xB9861 stays unnamed.
 *
 * 0xB962B repeats the display cases of effect_L5_move.
 * It does not clear disp_flag in case 8 and does not
 * call hukuromoji_move. The PlayStation 2 source has no
 * such function. hukuromoji_move case 2 tests size.x
 * against 63. The init stores my_col_code after
 * xyz[0]. The C keeps the PlayStation 2 order. bg_w is
 * 0x7BC520. rf_b2_flag is 0x7AAC30. The _etc_char_table
 * immediate is 0x2F9850. Those bytes were not compared.
 * disp_pos_trans_entry5 stays sub_000EF0C0.
 * set_char_move_init2 stays sub_000201B9. Sound_SE stays
 * sub_00098407. push_effect_work stays sub_0004AC6C.
 * pull_effect_work stays sub_0004A6A8.
 * get_my_trans_mode is named. frw is 0xC806A0 and each
 * object is 0x700 bytes.
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
    u8 pad_hs[0x44 - 0x34];
    s16 hit_stop;
    u8 pad_pos[0x58 - 0x46];
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_dir[0x96 - 0x70];
    s16 dir_old;
    u8 pad_ct[0x1AC - 0x98];
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
    u8 pad_ec[0x342 - 0x256];
    s16 extra_col;
    u8 pad_end[0x388 - 0x344];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
} WORK_Other;

typedef struct {
    u8 raw0[0xA];
    s16 position_x;
    u8 raw1[0x90 - 0xC];
} BGW;

typedef struct {
    u8 raw0[0x1C];
    s16 pos_offset;
    u8 raw1[0x38 - 0x1E];
    BGW bgw[7];
} BG;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, routine_no[1]) == 0x26, "rno1");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, dir_old) == 0x96, "dir_old");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_mr_flag) == 0x24E, "my_mr_flag");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.x) == 0x250, "mr.x");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.y) == 0x252, "mr.y");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(__builtin_offsetof(WORK, extra_col) == 0x342, "extra_col");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw[1].position_x) == 0xD2, "bgw position_x");
#endif

extern EffectRow frw[];
extern BG bg_w;
extern s16 rf_b2_flag;
extern u32 _etc_char_table[];

void sub_000EF0C0(WORK_Other *ewk);
void sub_000201B9(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void sub_00098407(s16 code);
void sub_0004AC6C(WORK *wk);
s16 sub_0004A6A8(s16 index);
s16 get_my_trans_mode(s16 curr);

void hukuromoji_move(WORK_Other *ewk);

void hukuromoji_move(WORK_Other *ewk) {
    WORK_Other *oya_ptr = (WORK_Other *)ewk->my_master;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        sub_000201B9(&ewk->wu, 0, 2, 6, 0);
        ewk->wu.hit_stop = 2;
        break;

    case 1:
        ewk->wu.hit_stop -= 1;

        if (ewk->wu.hit_stop < 0) {
            ewk->wu.routine_no[1] += 1;
            sub_00098407(oya_ptr->wu.dir_old + 1);
            return;
        }

        break;

    case 2:
        ewk->wu.my_mr.size.x -= 6;
        ewk->wu.my_mr.size.y -= 6;

        if (ewk->wu.my_mr.size.x < 64) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.my_mr.size.x = 63;
            ewk->wu.my_mr.size.y = 63;
            ewk->wu.hit_stop = 4;
            sub_000201B9(&ewk->wu, 0, 2, 7, 0);
            return;
        }

        break;

    case 3:
        ewk->wu.hit_stop -= 1;

        if (ewk->wu.hit_stop <= 0) {
            ewk->wu.routine_no[1] += 1;
            rf_b2_flag = 1;
        }

        break;

    case 4:
        break;
    }
}

s32 effect_L5_init(WORK_Other *oya) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = sub_0004A6A8(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xD7;
    ewk->wu.work_id = 0x10;
    ewk->my_master = (u32 *)oya;
    ewk->wu.my_family = 4;
    ewk->wu.my_mts = 0xE;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.my_col_code = 0x52;
    ewk->wu.my_priority = ewk->wu.position_z = 9;
    *ewk->wu.char_table = _etc_char_table;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
    ewk->wu.xyz[1].disp.pos = 0x90;
    return 0;
}

void effect_L5_move(WORK_Other *ewk) {
    WORK_Other *oya_ptr = (WORK_Other *)ewk->my_master;

    switch (oya_ptr->wu.routine_no[0]) {
    case 5:
    case 6:
        hukuromoji_move(ewk);
        sub_000EF0C0(ewk);
        break;

    case 7:
        ewk->wu.extra_col = oya_ptr->wu.extra_col;
        sub_000EF0C0(ewk);
        break;

    case 8:
        ewk->wu.disp_flag = 0;
        sub_000EF0C0(ewk);
        break;

    case 9:
    case 99:
        sub_0004AC6C(&ewk->wu);
        break;
    }
}
