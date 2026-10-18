/* Effect B3, retail sf33rd.xbe.
 * round_move_init is 0xBB5F6 size 0x67 and is interior.
 * round_move is 0xBB65D size 0xD0 and is interior.
 * fight_move is 0xBB72D size 0x9B and is interior.
 * fight_col_move is 0xBB7C8 size 0x1F and is interior.
 * fight_vanish is 0xBB7E7 size 0x6E and is interior.
 * effect_B3_init is 0xBB855 size 0xCD and is interior.
 * effect_B3_move is 0xBB922 size 0xC7 and is interior.
 * The pull failure is an early ret.
 * 0xBB4F0 stays unnamed. 0xBB9E9 stays unnamed.
 *
 * 0xBB4F0 repeats the oya_adrs and routine sync of
 * effect_B3_move and then only the display paths of the
 * callees. The PlayStation 2 source has no such
 * function. round_move shares the set_char_move_init2
 * call of its two branches. fight_vanish case 0 stores
 * extra_col before my_col_code. The init stores
 * xyz[0].disp.pos before xyz[1].cal and tests type with
 * setne. The C keeps the PlayStation 2 order.
 * oya_adrs is 0x7AAC2C. rf_b2_flag is 0x7AAC30. bg_w is
 * 0x7BC520. The _etc_char_table immediate is 0x2F9850.
 * Those bytes were not compared. disp_pos_trans_entry5
 * stays sub_000EF0C0. char_move stays sub_0002008E.
 * set_char_move_init2 stays sub_000201B9. Sound_SE
 * stays sub_00098407. effect_B9_init stays
 * sub_000BBAD3. push_effect_work stays sub_0004AC6C.
 * pull_effect_work stays sub_0004A6A8.
 * get_my_trans_mode is named. frw is 0xC806A0 and each
 * object is 0x700 bytes.
 */

#include "types.h"

#include <stddef.h>

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
    s16 hit_stop;
    s16 hit_quake;
    u8 pad_pos[0x58 - 0x48];
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_dir[0x96 - 0x70];
    s16 dir_old;
    u8 pad_ct[0x1AC - 0x98];
    u32 *char_table[1];
    u8 pad_cg_type[0x214 - 0x1B0];
    u8 cg_type;
    u8 pad_col[0x23E - 0x215];
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
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, routine_no[1]) == 0x26, "rno1");
_Static_assert(__builtin_offsetof(WORK, routine_no[2]) == 0x28, "rno2");
_Static_assert(__builtin_offsetof(WORK, old_rno[1]) == 0x36, "old_rno1");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, hit_quake) == 0x46, "hit_quake");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.low) == 0x64, "xyz0low");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].cal) == 0x68, "xyz1cal");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, dir_old) == 0x96, "dir_old");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
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
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw[1].position_x) == 0xD2, "bgw position_x");
#endif

extern EffectRow frw[];
extern BG bg_w;
extern s16 rf_b2_flag;
extern u32 _etc_char_table[];

WORK_Other *oya_adrs = NULL;

void sub_000EF0C0(WORK_Other *ewk);
void sub_0002008E(WORK *wk);
void sub_000201B9(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void sub_00098407(s16 code);
s32 sub_000BBAD3(WORK_Other *oya);
void sub_0004AC6C(WORK *wk);
s16 sub_0004A6A8(s16 index);
s16 get_my_trans_mode(s16 curr);

void round_move_init(WORK_Other *ewk);
void round_move(WORK_Other *ewk);
void fight_move(WORK_Other *ewk);
void fight_col_move(WORK_Other *ewk);
void fight_vanish(WORK_Other *ewk);

void round_move_init(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        sub_000201B9(&ewk->wu, 0, 2, 1, 0);
        /* fallthrough */

    case 1:
        ewk->wu.my_mr.size.x = oya_adrs->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_adrs->wu.my_mr.size.y;
        sub_000EF0C0(ewk);
        break;
    }
}

void round_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;

        if (ewk->wu.hit_quake) {
            sub_00098407(138);
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
            ewk->wu.xyz[0].disp.pos -= 96;
            ewk->wu.xyz[1].disp.pos = 144;
            sub_000201B9(&ewk->wu, 0, 2, 4, 0);
        } else {
            sub_00098407(oya_adrs->wu.dir_old);
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
            ewk->wu.xyz[0].disp.pos -= 32;
            sub_000201B9(&ewk->wu, 0, 2, 2, 0);
        }

        /* fallthrough */

    case 1:
        ewk->wu.my_mr.size.x = oya_adrs->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_adrs->wu.my_mr.size.y;
        sub_000EF0C0(ewk);
        break;
    }
}

void fight_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        sub_000201B9(&ewk->wu, 0, 2, 5, 0);
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 0;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
        ewk->wu.xyz[1].disp.pos = 144;
        sub_000EF0C0(ewk);
        break;

    case 1:
        ewk->wu.my_mr.size.x = oya_adrs->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_adrs->wu.my_mr.size.y;
        sub_000EF0C0(ewk);
        break;
    }
}

void fight_col_move(WORK_Other *ewk) {
    ewk->wu.extra_col = oya_adrs->wu.extra_col;
    sub_000EF0C0(ewk);
}

void fight_vanish(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        sub_000201B9(&ewk->wu, 0, 4, 1, 0);
        sub_000EF0C0(ewk);
        ewk->wu.my_col_code = 0x52;
        ewk->wu.extra_col = 0;
        break;

    case 1:
        sub_0002008E(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1] += 1;
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        rf_b2_flag = 1;
        sub_000EF0C0(ewk);
        break;
    }
}

s32 effect_B3_init(WORK_Other *oya) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = sub_0004A6A8(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x71;
    ewk->wu.work_id = 0x10;
    ewk->my_master = (u32 *)oya;
    ewk->wu.my_family = 4;
    ewk->wu.my_col_code = 0x52;
    ewk->wu.my_priority = ewk->wu.position_z = 10;
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.xyz[1].cal = 0x780000;
    ewk->wu.xyz[0].disp.low = 0;
    *ewk->wu.char_table = _etc_char_table;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].position_x + bg_w.pos_offset;
    ewk->wu.xyz[1].disp.pos = 0x90;
    ewk->wu.old_rno[1] = 0;

    if (oya->wu.type) {
        ewk->wu.hit_quake = 1;
    } else {
        ewk->wu.hit_quake = 0;
    }

    sub_000BBAD3(oya);
    return 0;
}

void effect_B3_move(WORK_Other *ewk) {
    oya_adrs = (WORK_Other *)ewk->my_master;

    if (ewk->wu.old_rno[1] != oya_adrs->wu.routine_no[0]) {
        ewk->wu.routine_no[1] = 0;
        ewk->wu.routine_no[2] = 0;
    }

    ewk->wu.old_rno[1] = oya_adrs->wu.routine_no[0];

    switch (oya_adrs->wu.routine_no[0]) {
    case 1:
        round_move_init(ewk);
        break;

    case 2:
        round_move(ewk);
        break;

    case 3:
    case 5:
    case 6:
        ewk->wu.my_mr.size.x = oya_adrs->wu.my_mr.size.x;
        ewk->wu.my_mr.size.y = oya_adrs->wu.my_mr.size.y;
        sub_000EF0C0(ewk);
        break;

    case 4:
        fight_move(ewk);
        break;

    case 7:
        fight_col_move(ewk);
        break;

    case 8:
        fight_vanish(ewk);
        break;

    case 9:
    case 10:
    case 99:
        ewk->wu.disp_flag = 0;
        break;

    default:
        sub_0004AC6C(&ewk->wu);
        break;
    }
}
