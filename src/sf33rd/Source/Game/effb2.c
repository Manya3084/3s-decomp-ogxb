/* Effect B2, retail sf33rd.xbe.
 * b3_Break_Into_check is 0xBB189 size 0x1A and is interior.
 * fight_col_chg_sub is 0xBB1A3 size 0x95 and is interior.
 * effect_B2_init is 0xBB238 size 0xD1 and is interior.
 * effect_B2_move is 0xBB309 size 0x1E7 and is interior.
 * The effect_B2_move size includes the jump table at
 * 0xBB4C4. The pull failure is an early ret.
 * 0xBB4F0 stays unnamed.
 *
 * effect_B2_move tests 99 and 100 before the jump table
 * for cases 0 through 10. Case 10 shares the increment
 * of case 5. Case 2 stores hit_stop before size.y. The
 * init stores the bgw[3] words in a different order and
 * compares Round_num with sete. The C keeps the
 * PlayStation 2 order. effb2_sound_tbl is 0x28488C and
 * fight_col_move_tbl is 0x284894. Both match the
 * PlayStation 2 values. rf_b2_flag is 0x7AAC30.
 * b2_curr_no is 0x7AAC32. Break_Into is 0x7A8802.
 * Next_Step is 0x7A86D2. save_w is 0x7BD3E0, stride
 * 0x208, and Battle_Number is +0x1A. Present_Mode is
 * 0x7A819C. Play_Type is 0x7A812D. Round_num is
 * 0x7A8818. bg_w is 0x7BC520. disp_pos_trans_entry5
 * stays disp_pos_trans_entry. random_16 is 0x9326B.
 * Bg_Family_Set_appoint is 0xB36C0.
 * push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. effect_L5_init,
 * effect_B3_init, and effect_I6_init are named. frw is 0xC806A0 and each
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
    s16 old_rno[8];
    s16 hit_stop;
    u8 pad_dir[0x96 - 0x46];
    s16 dir_old;
    u8 pad_vn[0x9E - 0x98];
    s16 vital_new;
    u8 pad_fam[0x242 - 0xA0];
    s16 my_family;
    u8 pad_mr[0x250 - 0x244];
    struct {
        struct {
            s16 x;
            s16 y;
        } size;
    } my_mr;
    u8 pad_ec[0x342 - 0x254];
    s16 extra_col;
    u8 pad_end[0x388 - 0x344];
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef struct {
    u8 raw0[0xA];
    s16 position_x;
    s16 position_y;
    u8 raw1[0x18 - 0xE];
    XY xy[2];
    XY wxy[2];
    u8 raw2[0x90 - 0x28];
} BGW;

typedef struct {
    u8 raw0[0x1C];
    s16 pos_offset;
    u8 raw1[0x38 - 0x1E];
    BGW bgw[7];
} BG;

typedef struct {
    u8 pad[0x1A];
    u8 Battle_Number[2];
    u8 tail[0x208 - 0x1C];
} SAVE_W;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, routine_no[1]) == 0x26, "rno1");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, dir_old) == 0x96, "dir_old");
_Static_assert(__builtin_offsetof(WORK, vital_new) == 0x9E, "vital_new");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.x) == 0x250, "mr.x");
_Static_assert(__builtin_offsetof(WORK, my_mr.size.y) == 0x252, "mr.y");
_Static_assert(__builtin_offsetof(WORK, extra_col) == 0x342, "extra_col");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, bgw[3].position_x) == 0x1F2, "bgw3 position_x");
_Static_assert(__builtin_offsetof(BG, bgw[3].xy[0].cal) == 0x200, "bgw3 xy0");
_Static_assert(__builtin_offsetof(BG, bgw[3].wxy[1].cal) == 0x20C, "bgw3 wxy1");
_Static_assert(sizeof(SAVE_W) == 0x208, "SAVE_W");
#endif

extern EffectRow frw[];
extern BG bg_w;
extern SAVE_W save_w[6];
extern u8 Present_Mode;
extern u8 Play_Type;
extern u8 Round_num;
extern s8 Break_Into;
extern s8 Next_Step;

const s16 effb2_sound_tbl[4] = { 0x80, 0x82, 0x84, 0x86 };
const s16 fight_col_move_tbl[18] = { 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0 };

s16 b2_curr_no = 0;
s16 rf_b2_flag = 0;

void disp_pos_trans_entry(WORK_Other *ewk);
s16 random_16(void);
void Bg_Family_Set_appoint(s32 num_of_bg);
s32 effect_I6_init(WORK_Other *oya);
s32 effect_B3_init(WORK_Other *oya);
s32 effect_L5_init(WORK_Other *oya);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

s32 b3_Break_Into_check(WORK_Other *ewk);
s32 fight_col_chg_sub(WORK_Other *ewk);

s32 b3_Break_Into_check(WORK_Other *ewk) {
    if (Break_Into) {
        ewk->wu.routine_no[0] = 99;
        return 1;
    } else {
        return 0;
    }
}

s32 fight_col_chg_sub(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.vital_new = 0;
        ewk->wu.hit_stop = 1;
        break;

    case 1:
        ewk->wu.hit_stop -= 1;

        if (ewk->wu.hit_stop <= 0) {
            ewk->wu.hit_stop = 1;
            ewk->wu.vital_new += 1;

            if (ewk->wu.vital_new > 17) {
                ewk->wu.routine_no[1] += 1;
                ewk->wu.hit_stop = 6;
            } else {
                ewk->wu.extra_col = fight_col_move_tbl[ewk->wu.vital_new];
                ewk->wu.extra_col += 0x52;
                ewk->wu.extra_col |= 0x2000;
            }
        }

        break;

    case 2:
        ewk->wu.hit_stop -= 1;

        if (ewk->wu.hit_stop <= 0) {
            ewk->wu.routine_no[1] += 1;
            return 1;
        }

        /* fallthrough */

    case 3:
        disp_pos_trans_entry(ewk);
        break;
    }

    return 0;
}

s32 effect_B2_init(void) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x70;
    ewk->wu.work_id = 0x10;
    ewk->wu.my_family = 4;
    bg_w.bgw[3].xy[0].cal = bg_w.bgw[3].wxy[0].cal = 0x100000;
    bg_w.bgw[3].wxy[1].cal = 0;
    bg_w.bgw[3].xy[1].cal = 0;
    bg_w.bgw[3].position_x = 256 - bg_w.pos_offset;
    bg_w.bgw[3].position_y = 0;
    Bg_Family_Set_appoint(3);

    switch (save_w[Present_Mode].Battle_Number[Play_Type]) {
    case 0:
        ewk->wu.type = 0;
        break;

    case 1:
        if (Round_num == 2) {
            ewk->wu.type = 1;
        } else {
            ewk->wu.type = 0;
        }

        break;

    case 2:
        if (Round_num == 4) {
            ewk->wu.type = 1;
        } else {
            ewk->wu.type = 0;
        }

        break;

    case 3:
        if (Round_num == 6) {
            ewk->wu.type = 1;
        } else {
            ewk->wu.type = 0;
        }

        break;
    }

    effect_B3_init(ewk);
    return 0;
}

void effect_B2_move(WORK_Other *ewk) {
    s16 work;

    b3_Break_Into_check(ewk);

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.old_rno[0] = ewk->wu.old_rno[1] = ewk->wu.old_rno[2] = 0;
        rf_b2_flag = 0;
        b2_curr_no = 0;
        ewk->wu.hit_stop = 2;
        work = random_16();
        work &= 3;
        ewk->wu.dir_old = effb2_sound_tbl[work];
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        break;

    case 1:
        ewk->wu.hit_stop -= 1;

        if (ewk->wu.hit_stop < 0) {
            ewk->wu.routine_no[0] += 1;
            ewk->wu.my_mr.size.y = 0;
            effect_I6_init(ewk);
            return;
        }

        break;

    case 2:
        ewk->wu.my_mr.size.y += 10;

        if (ewk->wu.my_mr.size.y >= 63) {
            ewk->wu.routine_no[0] += 1;
            ewk->wu.my_mr.size.y = 63;
            ewk->wu.hit_stop = 64;
            rf_b2_flag = 0;
            return;
        }

        break;

    case 3:
        ewk->wu.hit_stop -= 1;

        if (ewk->wu.hit_stop < 0) {
            ewk->wu.routine_no[0] += 1;
            b2_curr_no = 0;
            rf_b2_flag = 0;
            ewk->wu.hit_stop = 10;
            return;
        }

        break;

    case 4:
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 0;
        ewk->wu.hit_stop -= 1;

        if (ewk->wu.hit_stop < 0) {
            ewk->wu.routine_no[0] += 1;
            rf_b2_flag = 0;
            effect_L5_init(ewk);
            return;
        }

        break;

    case 5:
        ewk->wu.my_mr.size.y += 6;

        if (ewk->wu.my_mr.size.y >= 63) {
            ewk->wu.routine_no[0] += 1;
            ewk->wu.my_mr.size.y = 63;
            return;
        }

        break;

    case 6:
        if (rf_b2_flag) {
            ewk->wu.routine_no[0] += 1;
            rf_b2_flag = 0;
            return;
        }

        break;

    case 7:
        if (fight_col_chg_sub(ewk) != 0) {
            ewk->wu.routine_no[0] += 1;
            rf_b2_flag = 0;
            ewk->wu.routine_no[1] = 0;
            return;
        }

        break;

    case 8:
        if (rf_b2_flag) {
            ewk->wu.routine_no[0] += 1;
            return;
        }

        break;

    case 9:
        Next_Step = 1;
        ewk->wu.routine_no[0] += 1;
        break;

    case 10:
        ewk->wu.routine_no[0] += 1;
        break;

    case 99:
        ewk->wu.routine_no[0] += 1;
        break;

    case 100:
        ewk->wu.routine_no[0] += 1;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}
