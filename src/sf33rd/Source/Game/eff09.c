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
 * 0x32C0D stays unnamed.
 * 0x3480C stays unnamed.
 * 0x34F2F stays unnamed.
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
 * char_move stays sub_0002008E.
 * set_char_move_init stays sub_000200A9.
 * add_x_sub stays sub_000EF072.
 * add_y_sub stays sub_000EF088.
 * add_x_sub2 shares sub_000EF072.
 * add_y_sub2 shares sub_000EF088.
 * disp_pos_trans_entry stays sub_000EF0C0.
 * suzi_sync_pos_set stays sub_000B3627.
 * sort_push_request stays sub_0009DF9A.
 * sort_push_request4 stays sub_0009E092.
 * push_effect_work stays sub_0004AC6C.
 * random_16 stays sub_0009326B.
 * Sound_SE stays sub_00098407.
 * cal_all_speed_data stays sub_0001D4D7.
 * Suicide is 0x7A8268.
 * set_char_move_init2 stays sub_000201B9.
 * char_move_z stays sub_000202CE.
 * range_x_check3 and pl_eff_trans_entry are named.
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
} Reg32;

typedef struct {
    Reg32 a[2];
    Reg32 d[2];
    s16 kop[2];
    u16 index;
} MVXY;

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 blink_timing;
    u8 operator;
    u8 type;
    u8 pad_wid;
    s16 work_id;
    s16 id;
    s8 rl_flag;
    u8 pad_dead[0x15];
    s16 dead_f;
    u8 pad_rno[2];
    s16 routine_no[8];
    s16 old_rno[8];
    s16 hit_stop;
    u8 pad_kage[3];
    u8 kage_flag;
    s16 kage_hx;
    s16 kage_hy;
    s16 kage_prio;
    u8 pad_kchar[2];
    s16 kage_char;
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_mv[0xC];
    MVXY mvxy;
    u8 pad_step[4];
    s16 dir_step;
    s16 dir_timer;
    u8 pad_cm[0xCE];
    s16 cmwk[32];
    u8 pad_ci[0x5A];
    s16 cg_ix;
    u8 pad_cgix[2];
    s16 char_index;
    u8 pad_cd[2];
    s16 cgd_type;
    u8 pad_cg[6];
    u8 cg_type;
    u8 pad_col[0x29];
    s16 my_col_code;
    s16 my_priority;
    u8 pad_end[0x146];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
    u8 pad_id[2];
    s16 master_id;
} WORK_Other;

typedef struct {
    WORK wu;
    u8 pad_pl[0xE4];
} PLW;

typedef struct {
    u8 raw[0x18];
    XY xy[2];
    XY wxy[2];
    u8 mid[0x20];
    s16 pos_x_work;
    u8 tail[0x46];
} BGW;

typedef struct {
    u8 raw[0x1C];
    s16 pos_offset;
    u8 pad_bg[0x1A];
    BGW bgw[2];
} BG;

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
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
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
extern const s16 eff09_data2[43][8];
extern const s32 eff09_add_tbl0[2][2];
extern const s32 eff09_add_tbl1[2][2];
extern const s32 eff09_add_tbl2[2][2];
extern const s32 eff09_13_tbl[3][4];
extern const s32 eff09_19000_tbl[3][4];
extern void (*eff09_tbl[28])(WORK_Other *ewk);

s32 compel_dead_check(WORK_Other *ewk);
s32 obr_no_disp_check(void);
void disp_pos_trans_entry_s(WORK_Other *ewk);
void disp_pos_trans_entry_rs(WORK_Other *ewk);
void sub_000EF0C0(WORK_Other *ewk);
s16 eff_hit_check(WORK_Other *ewk, s16 type);
void sub_0002008E(WORK *wk);
void sub_000200A9(WORK *wk, s16 koc, s16 index);
void sub_000EF072(WORK_Other *ewk);
void sub_000EF088(WORK_Other *ewk);
void sub_000B3627(WORK_Other *ewk);
void sub_0009DF9A(WORK *wk);
void sub_0009E092(WORK *wk);
void sub_0004AC6C(WORK *wk);
s16 sub_0009326B(void);
void sub_00098407(s16 code);
void sub_0001D4D7(WORK *wk, s16 tm, s16 tx, s16 ty, s16 ax, s16 ay);
void sub_000201B9(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void sub_000202CE(WORK *wk);
s32 range_x_check3(WORK_Other *ewk, s16 rad);
void pl_eff_trans_entry(WORK_Other *ewk);

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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.hit_stop != 0) {
            sub_0002008E(&ewk->wu);

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
        sub_0004AC6C(&ewk->wu);
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
        ewk->wu.old_rno[0] = sub_0009326B();
        ewk->wu.old_rno[0] &= 1;

        if (ewk->master_id != 0) {
            ewk->wu.type = 10;
        } else {
            ewk->wu.type = 9;
        }

        if (EXE_obroll != 0) {
            sub_000200A9(&ewk->wu, 0, 25);
            ewk->wu.old_rno[0] = 1;
        } else if (ewk->wu.old_rno[0] != 0) {
            sub_000200A9(&ewk->wu, 0, 25);
        } else {
            sub_000200A9(&ewk->wu, 0, 65);
        }

        sub_0009DF9A(&ewk->wu);
        break;

    case 1:
    case 3:
        if (EXE_flag == 0 && Game_pause == 0 && EXE_obroll == 0) {
            sub_0002008E(&ewk->wu);

            if (ewk->wu.cg_type != 0) {
                ewk->wu.routine_no[1]++;
            }
        }

        if (obr_no_disp_check() == 0) {
            sub_0009DF9A(&ewk->wu);
        }

        break;

    case 2:
        if (obr_no_disp_check() != 0) {
            break;
        }

        if (ewk->wu.old_rno[0] != 0 && EXE_flag == 0 && Game_pause == 0 && EXE_obroll == 0 &&
            eff_hit_check(ewk, 0) != 0) {
            ewk->wu.routine_no[1]++;
            sub_000200A9(&ewk->wu, 0, 65);
        }

        sub_0009DF9A(&ewk->wu);
        break;

    case 4:
        if (obr_no_disp_check() == 0) {
            sub_0009DF9A(&ewk->wu);
        }

        break;

    default:
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        sub_0001D4D7(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.xyz[0].disp.pos, 40, 1, 2);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
            } else {
                sub_000EF088(ewk);
            }

            sub_0002008E(&ewk->wu);
        }

        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    case 2:
        if (Exec_Wipe != 0) {
            sub_00098407((Winner_id * 0x300) + 0x130);
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);
        }

        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    default:
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
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
        sub_0001D4D7(&ewk->wu, ewk->wu.old_rno[0], work2, 0, 0, 2);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);
            sub_000EF072(ewk);
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
                sub_000200A9(&ewk->wu, 0, 29);
            }
        }

        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);
        }

        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    default:
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);
        }

        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    default:
        sub_0004AC6C(&ewk->wu);
        break;
    }
}

void eff09_6000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        sub_0002008E(&ewk->wu);

        if (ewk->wu.cg_type == 9) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 2;
            ewk->wu.blink_timing = 1;
        }

        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    case 2:
        sub_0002008E(&ewk->wu);

        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            break;
        }

        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    case 3:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004AC6C(&ewk->wu);
        break;
    }
}

void eff09_7000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
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
            break;
        }

        sub_0002008E(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);
        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004AC6C(&ewk->wu);
        break;
    }
}

void eff09_8000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (ewk->wu.hit_stop != 0) {
            sub_0002008E(&ewk->wu);

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
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.hit_stop != 0) {
            sub_0002008E(&ewk->wu);
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.hit_stop != 0) {
            sub_0002008E(&ewk->wu);

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
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
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
        sub_0001D4D7(&ewk->wu, ewk->wu.old_rno[0], work2, 0, 0, 2);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);
            sub_000EF072(ewk);
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
                oya_ptr->cmwk[0] = 9;
            }
        }

        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
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
        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    default:
        sub_0004AC6C(&ewk->wu);
        break;
    }
}

void eff09_12000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.mvxy.a[1].sp = -0x10000;
        ewk->wu.mvxy.d[1].sp = 0;
        ewk->wu.mvxy.d[0].sp = 0;

        if (ewk->wu.rl_flag != 0) {
            ewk->wu.mvxy.a[0].sp = -0x20000;
        } else {
            ewk->wu.mvxy.a[0].sp = 0x20000;
        }

        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    case 1:
        sub_0002008E(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);

        if (ewk->wu.xyz[1].disp.pos < 56) {
            ewk->wu.routine_no[1]++;
            ewk->wu.blink_timing = 1;
            ewk->wu.disp_flag = 2;
            ewk->wu.old_rno[1] = 20;
        }

        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    case 2:
        ewk->wu.old_rno[1]--;

        if (ewk->wu.old_rno[1] < 0) {
            ewk->wu.routine_no[1]++;
            break;
        }

        sub_0002008E(&ewk->wu);
        sub_000EF072(ewk);
        sub_000EF088(ewk);
        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    case 3:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);

            if (oya_ptr->cg_type == 99) {
                ewk->wu.routine_no[1]++;
                sub_000200A9(&ewk->wu, 0, 83);
                ewk->wu.mvxy.a[0].sp = eff09_13_tbl[ewk->wu.type - 0xF][0];
                ewk->wu.mvxy.d[0].sp = eff09_13_tbl[ewk->wu.type - 0xF][1];
                ewk->wu.mvxy.a[1].sp = eff09_13_tbl[ewk->wu.type - 0xF][2];
                ewk->wu.mvxy.d[1].sp = eff09_13_tbl[ewk->wu.type - 0xF][3];
            }
        }

        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);
            sub_000EF072(ewk);
            sub_000EF088(ewk);

            if (ewk->wu.xyz[0].disp.pos < bg_w.bgw[1].pos_x_work - 240 ||
                ewk->wu.xyz[0].disp.pos > bg_w.bgw[1].pos_x_work + 240 || ewk->wu.xyz[1].disp.pos > 512) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        sub_000B3627(ewk);
        sub_0009DF9A(&ewk->wu);
        break;

    case 3:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.hit_stop != 0) {
            sub_0002008E(&ewk->wu);

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
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.hit_stop != 0) {
            sub_0002008E(&ewk->wu);

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
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && ewk->wu.hit_stop != 0) {
            sub_0002008E(&ewk->wu);

            if (ewk->wu.cg_type != 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        sub_000B3627(ewk);
        sub_0009E092(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[1]++;
        break;

    default:
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);

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
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);

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
        sub_0001D4D7(&ewk->wu, ewk->wu.old_rno[0], oya_ptr->xyz[0].disp.pos, ewk->wu.old_rno[1], 0, 0);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);
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
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
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

            if (ewk->wu.xyz[1].disp.pos < 64) {
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

            if (ewk->wu.xyz[1].disp.pos < 64) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        sub_000EF0C0(ewk);
        return;

    default:
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        sub_000EF0C0(ewk);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);

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
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
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

        sub_0001D4D7(&ewk->wu, ewk->wu.old_rno[0], arrive_x, arrive_y, 2, 2);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[1]++;
                sub_000200A9(&ewk->wu, 0, 58);
            } else {
                sub_000EF072(ewk);
                sub_000EF088(ewk);
            }
        }

        sub_000EF0C0(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);

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
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            if (oya_ptr->cg_type == 99) {
                ewk->wu.routine_no[1]++;
                sub_000200A9(&ewk->wu, 0, 62);
            } else if (oya_ptr->cg_ix != ewk->wu.cg_ix) {
                work = oya_ptr->cg_ix / oya_ptr->cgd_type;
                sub_000201B9(&ewk->wu, 0, 61, work + 1, 0);
                ewk->wu.cg_ix = oya_ptr->cg_ix;
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    default:
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0 && oya_ptr->cg_type == 1) {
            ewk->wu.routine_no[1]++;
        }

        pl_eff_trans_entry(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;

                if (ewk->wu.rl_flag != 0) {
                    ewk->wu.mvxy.a[0].sp = -0x20000;
                } else {
                    ewk->wu.mvxy.a[0].sp = 0x20000;
                }

                ewk->wu.mvxy.d[0].sp = 0;
                sub_000200A9(&ewk->wu, 0, 64);
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);
            sub_000EF072(ewk);

            if (range_x_check3(ewk, 64) == 0) {
                ewk->wu.routine_no[1]++;
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    default:
        sub_0004AC6C(&ewk->wu);
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

        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
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
            sub_0002008E(&ewk->wu);

            if (ewk->wu.cg_type == 9) {
                ewk->wu.routine_no[1]++;
                sub_000202CE(&ewk->wu);

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
            sub_0002008E(&ewk->wu);
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
        sub_0004AC6C(&ewk->wu);
        return;
    }
}

void eff09_25000(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.dead_f = 1;
        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
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
            sub_0002008E(&ewk->wu);
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
        sub_0004AC6C(&ewk->wu);
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
        sub_000200A9(&ewk->wu, 0, 101);
        ewk->wu.old_rno[0] = 0;
        ewk->wu.xyz[1].disp.pos += base_y_pos;
        break;

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);

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
            sub_0002008E(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[1]++;
                sub_000200A9(&ewk->wu, 0, 102);
            }
        }

        jijii_win_tama_sub(ewk);
        sub_000EF0C0(ewk);
        break;

    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);

            if (oya_ptr->cmwk[0] == 2) {
                ewk->wu.routine_no[1]++;
            }
        }

        jijii_win_tama_sub(ewk);
        sub_000EF0C0(ewk);
        break;

    case 4:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);
        }

        ewk->wu.xyz[1].disp.pos = oya_ptr->position_y + base_y_pos;
        ewk->wu.xyz[1].disp.pos -= 42;
        jijii_win_tama_sub(ewk);
        sub_000EF0C0(ewk);
        break;

    default:
        sub_0004AC6C(&ewk->wu);
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

        sub_000200A9(&ewk->wu, 0, ewk->wu.char_index);
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

                sub_000201B9(&ewk->wu, 0, 107, 2, 0);
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            sub_0002008E(&ewk->wu);
            sub_000EF072(ewk);

            if (range_x_check3(ewk, 36) == 0) {
                ewk->wu.routine_no[1]++;
                ewk->wu.disp_flag = 0;
            }
        }

        pl_eff_trans_entry(ewk);
        break;

    default:
        sub_0004AC6C(&ewk->wu);
        break;
    }
}
