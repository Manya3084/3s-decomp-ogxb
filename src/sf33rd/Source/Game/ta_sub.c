/* Target helpers, retail sf33rd.xbe.
 * sync_fam_set3 is 0xEEEB9 size 0xBD. range_x_check is 0xEEF76 size 0x5A.
 * range_x_check3 is 0xEEFD0 size 0x58. range_y_check is 0xEF028 size 0x4A.
 * obr_no_disp_check is 0xEF0A2 size 0x1E. disp_pos_trans_entry_r is 0xEF0E5
 * size 0x34. disp_pos_trans_entry_r4 is 0xEF119 size 0x32.
 * disp_pos_trans_entry_s is 0xEF14B size 0x22. disp_pos_trans_entry_rs is
 * 0xEF16D size 0x2D. pl_eff_trans_entry is 0xEF19A size 0x25.
 * eff_hit_check_sub is 0xEF1BF size 0x50. hit_check_subroutine_yu is 0xEF20F
 * size 0xC1. eff_hit_flag_clear is 0xEF2D0 size 0x11. compel_dead_check is
 * 0xEF2E1 size 0x16. win_lose_work_clear is 0xEF2F7 size 0x3F.
 * cal_bg_speed_data_x is 0xEF336 size 0x74. cal_bg_speed_data_y is 0xEF3AA
 * size 0x74. eff_hit_check is 0xEF41E size 0x75. eff_hit_check_sub2 is
 * 0xEF493 size 0x34. eff_hit_check2 is 0xEF4C7 size 0x7D.
 * add_x_sub and add_x_sub2 share 0xEF072. add_y_sub and add_y_sub2 share
 * 0xEF088. disp_pos_trans_entry and disp_pos_trans_entry5 share 0xEF0C0.
 * Those three bodies stay unnamed.
 * bg_w is 0x7BC520. quake_x_tbl is 0x276270 and quake_y_tbl is 0x2762F8.
 * Both tables match the 130 PlayStation 2 bytes. akebono_flag is 0x7BC4A9.
 * sa_pa_flag is 0x7BC4AA. aku_flag is 0x7BC4F0. seraph_flag is 0x7BC4F4.
 * chase_x is 0x7BC4EC. chase_y is 0x7BC51A. bg_mvxy is 0x7BC4C0.
 * eff_hit_flag is 0x7A99C0. eff_hit_data is 0x333084 and matches the 16
 * PlayStation 2 words. pl_hit_eff is 0x2B08D0 and matches the 100 words.
 * plw is 0xC7CEA0. EXE_obroll is 0x7A8111. pcon_dp_flag is 0xC7D8D0.
 * a_rno is 0x7A8A40. win_rno is 0x7A8A44. win_free is 0x7A8A3C.
 * lose_rno is 0xC7E988. lose_free is 0xC7E980.
 * Family_Set_W stays sub_000AF47B. sort_push_request4 stays sub_0009E092.
 * sort_push_request stays sub_0009DF9A. suzi_sync_pos_set stays
 * sub_000B3627. hit_check_subroutine stays sub_0005F40D.
 * sync_fam_set3 subtracts the pos_offset dword and stores the low word.
 * hit_check_subroutine_yu, cal_bg_speed_data_x, cal_bg_speed_data_y, and
 * eff_hit_check2 are scanned starts. sync_fam_set3, range_x_check,
 * range_x_check3, range_y_check, obr_no_disp_check,
 * disp_pos_trans_entry_r, disp_pos_trans_entry_r4, disp_pos_trans_entry_s,
 * disp_pos_trans_entry_rs, pl_eff_trans_entry, eff_hit_check_sub,
 * eff_hit_flag_clear, compel_dead_check, win_lose_work_clear,
 * eff_hit_check, and eff_hit_check_sub2 are interior.
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
    s16 l;
    s16 h;
} LoHi16;

typedef union {
    s32 pl;
    LoHi16 ps;
} S32Split;

typedef struct {
    s32 timer;
    s32 timer2;
    S32Split x;
    S32Split y;
    s32 spx;
    s32 dlx;
    s32 spy;
    s32 dly;
    s32 amx;
    s32 amy;
} MotionState;

typedef struct {
    s16 body_dm[4][4];
} HitBody;

typedef struct {
    u8 raw0[4];
    u8 type;
    u8 raw1[5];
    s8 rl_flag;
    u8 raw2[0x15];
    s16 dead_f;
    u8 raw3[2];
    s16 routine_no[8];
    u8 raw4[0x10];
    s16 hit_stop;
    u8 raw5[0xE];
    s16 position_x;
    s16 position_y;
    u8 raw6[0xC];
    XY xyz[3];
    u8 raw7[0xC];
    MVXY mvxy;
    u8 raw8[0x242 - 0x94];
    s16 my_family;
    u8 raw9[0x284 - 0x244];
    HitBody *h_bod;
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef struct {
    WORK wu;
    u8 mid[0x394 - 0x288];
    s16 player_number;
} PLW;

typedef struct {
    u8 raw0[0xA];
    s16 position_x;
    s16 position_y;
    u8 raw1[0x18 - 0xE];
    XY xy[2];
    XY wxy[2];
    u8 raw2[0x58 - 0x28];
    XY chase_xy[2];
    u8 raw3[0x8C - 0x60];
    s16 abs_x;
    s16 abs_y;
} BGW;

typedef struct {
    u8 raw0[5];
    s8 compel_flag;
    u8 raw1[0x13];
    s8 chase_flag;
    u8 raw2[2];
    s16 pos_offset;
    s16 quake_x_index;
    s16 quake_y_index;
    u8 raw3[0x16];
    BGW bgw[7];
} BG;

#if defined(__i386__)
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(MVXY, d) == 8, "d");
_Static_assert(__builtin_offsetof(MVXY, kop) == 0x10, "kop");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, xyz) == 0x64, "xyz");
_Static_assert(__builtin_offsetof(WORK, mvxy) == 0x7C, "mvxy");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, h_bod) == 0x284, "h_bod");
_Static_assert(__builtin_offsetof(PLW, player_number) == 0x394, "player_number");
_Static_assert(__builtin_offsetof(BGW, position_x) == 0xA, "bg position_x");
_Static_assert(__builtin_offsetof(BGW, xy) == 0x18, "xy");
_Static_assert(__builtin_offsetof(BGW, wxy) == 0x20, "wxy");
_Static_assert(__builtin_offsetof(BGW, chase_xy) == 0x58, "chase_xy");
_Static_assert(__builtin_offsetof(BGW, abs_x) == 0x8C, "abs_x");
_Static_assert(__builtin_offsetof(BGW, abs_y) == 0x8E, "abs_y");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, compel_flag) == 5, "compel_flag");
_Static_assert(__builtin_offsetof(BG, chase_flag) == 0x19, "chase_flag");
_Static_assert(__builtin_offsetof(BG, pos_offset) == 0x1C, "pos_offset");
_Static_assert(__builtin_offsetof(BG, quake_x_index) == 0x1E, "quake_x_index");
_Static_assert(__builtin_offsetof(BG, quake_y_index) == 0x20, "quake_y_index");
_Static_assert(__builtin_offsetof(BG, bgw) == 0x38, "bgw");
#endif

extern BG bg_w;
extern const s8 quake_x_tbl[130];
extern const s8 quake_y_tbl[130];
extern s8 akebono_flag;
extern s8 sa_pa_flag;
extern s8 aku_flag;
extern s8 seraph_flag;
extern s16 chase_x;
extern s16 chase_y;
extern MVXY bg_mvxy;
extern s16 eff_hit_flag[11];
extern s16 eff_hit_data[4][4];
extern const s16 pl_hit_eff[25][4];
extern PLW plw[2];
extern s8 EXE_obroll;
extern u8 pcon_dp_flag;
extern s16 a_rno;
extern s16 win_rno[2];
extern s16 win_free[2];
extern s16 lose_rno[3];
extern s16 lose_free[2];

void Scrn_Move_Set(s8 bgnm, s16 x, s16 y);
void sub_000AF47B(s8 fmnm, s16 x, s16 y);
s32 sub_0009E092(WORK *wk);
s32 sub_0009DF9A(WORK *wk);
void sub_000B3627(WORK_Other *ewk);
s16 sub_0005F40D(WORK *wk1, WORK *wk2, const s16 *hd1, const s16 *hd2);

s32 eff_hit_check_sub(WORK_Other *ewk, PLW *pl);
s32 eff_hit_check_sub2(WORK_Other *ewk, PLW *pl, s16 where_type);
static s16 hit_check_subroutine_yu(WORK *tpl, WORK *tef, s16 *hd1, s16 *hd2);

void sync_fam_set3(s16 my_fam) {
    s16 pos_work_x;
    s16 pos_work_y;
    s16 pos_x_w;
    s16 pos_y_w;

    if (bg_w.chase_flag & 0xF) {
        pos_x_w = bg_w.bgw[my_fam].chase_xy[0].disp.pos;
    } else {
        pos_x_w = bg_w.bgw[my_fam].wxy[0].disp.pos;
    }

    if (bg_w.chase_flag & 0xF0) {
        pos_y_w = bg_w.bgw[my_fam].chase_xy[1].disp.pos;
    } else {
        pos_y_w = bg_w.bgw[my_fam].xy[1].disp.pos;
    }

    pos_work_x = (s16)(pos_x_w & 0xFFFF);
    pos_work_x = (s16)(pos_work_x - bg_w.pos_offset);
    pos_x_w = (s16)(pos_x_w - bg_w.pos_offset);

    if ((bg_w.quake_x_index) > 0) {
        pos_work_x = (s16)(pos_work_x + quake_x_tbl[bg_w.quake_x_index]);
        pos_x_w = (s16)(pos_x_w + quake_x_tbl[bg_w.quake_x_index]);
    }

    bg_w.bgw[my_fam].position_x = (s16)(pos_work_x & 0xFFFF);
    bg_w.bgw[my_fam].abs_x = pos_x_w;
    pos_work_y = (s16)(pos_y_w & 0xFFFF);
    pos_work_y = (s16)(pos_work_y + quake_y_tbl[bg_w.quake_y_index]);
    pos_y_w = (s16)(pos_y_w + quake_y_tbl[bg_w.quake_y_index]);
    bg_w.bgw[my_fam].position_y = (s16)(pos_work_y & 0xFFFF);
    bg_w.bgw[my_fam].abs_y = pos_y_w;
    Scrn_Move_Set((s8)my_fam, bg_w.bgw[my_fam].position_x, bg_w.bgw[my_fam].position_y);
    pos_work_x = (s16)(-pos_work_x & 0xFFFF);
    pos_work_x = (s16)(pos_work_x & 0xFFFF);
    pos_work_y = (s16)((768 - (pos_work_y & 0xFFFF)) & 0xFFFF);
    sub_000AF47B((s8)(my_fam + 1), pos_work_x, pos_work_y);
}

s32 range_x_check(WORK_Other *ewk) {
    s16 pos_x_work;
    s16 work2;
    s16 work3;

    if (bg_w.chase_flag & 0xF) {
        pos_x_work = bg_w.bgw[ewk->wu.my_family - 1].chase_xy[0].disp.pos;
    } else {
        pos_x_work = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos;
    }

    if (ewk->wu.hit_stop == -77) {
        work2 = (s16)(pos_x_work - 193);
        work3 = (s16)(pos_x_work + 225);
    } else {
        work2 = (s16)(pos_x_work - 193);
        work3 = (s16)(pos_x_work + 193);
    }

    if (work2 > ewk->wu.xyz[0].disp.pos) {
        return 0;
    } else if (ewk->wu.xyz[0].disp.pos > work3) {
        return 0;
    }

    return 1;
}

s32 range_x_check3(WORK_Other *ewk, s16 optional_range) {
    s16 pos_x_work;
    s16 work2;
    s16 work3;

    if (bg_w.chase_flag & 0xF) {
        pos_x_work = bg_w.bgw[ewk->wu.my_family - 1].chase_xy[0].disp.pos;
    } else {
        pos_x_work = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos;
    }

    work2 = (s16)(pos_x_work - 192 - optional_range);
    work3 = (s16)(192 + pos_x_work + optional_range);

    if (work2 > ewk->wu.xyz[0].disp.pos) {
        return 0;
    } else if (ewk->wu.xyz[0].disp.pos > work3) {
        return 0;
    }

    return 1;
}

s32 range_y_check(WORK_Other *ewk) {
    s16 pos_y_work;
    s16 work2;
    s16 work3;

    if (bg_w.chase_flag & 0xF) {
        pos_y_work = bg_w.bgw[ewk->wu.my_family - 1].chase_xy[1].disp.pos;
    } else {
        pos_y_work = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos;
    }

    work2 = (s16)(pos_y_work + 256);
    work3 = (s16)(pos_y_work - 32);

    if (work2 < ewk->wu.xyz[1].disp.pos) {
        return 0;
    } else if (work3 > ewk->wu.xyz[1].disp.pos) {
        return 0;
    }

    return 1;
}

s32 obr_no_disp_check(void) {
    if (aku_flag | akebono_flag | sa_pa_flag | seraph_flag) {
        return 1;
    }

    return 0;
}

void disp_pos_trans_entry_r(WORK_Other *ewk) {
    if ((obr_no_disp_check() == 0) && (range_x_check(ewk) != 0)) {
        ewk->wu.position_x = (s16)((ewk->wu.xyz[0].disp.pos & 0xFFFF) + 1);
        ewk->wu.position_y = (s16)(ewk->wu.xyz[1].disp.pos & 0xFFFF);
        sub_0009E092(&ewk->wu);
    }
}

void disp_pos_trans_entry_r4(WORK_Other *ewk) {
    if ((obr_no_disp_check() == 0) && (range_y_check(ewk) != 0)) {
        ewk->wu.position_x = (s16)(ewk->wu.xyz[0].disp.pos & 0xFFFF);
        ewk->wu.position_y = (s16)(ewk->wu.xyz[1].disp.pos & 0xFFFF);
        sub_0009E092(&ewk->wu);
    }
}

void disp_pos_trans_entry_s(WORK_Other *ewk) {
    if (obr_no_disp_check() == 0) {
        sub_000B3627(ewk);
        ewk->wu.position_x++;
        sub_0009E092(&ewk->wu);
    }
}

void disp_pos_trans_entry_rs(WORK_Other *ewk) {
    if ((obr_no_disp_check() == 0) && (range_x_check(ewk) != 0)) {
        sub_000B3627(ewk);
        ewk->wu.position_x++;
        sub_0009E092(&ewk->wu);
    }
}

void pl_eff_trans_entry(WORK_Other *ewk) {
    if (obr_no_disp_check() == 0) {
        ewk->wu.position_x = (s16)(ewk->wu.xyz[0].disp.pos & 0xFFFF);
        ewk->wu.position_y = (s16)(ewk->wu.xyz[1].disp.pos & 0xFFFF);
        sub_0009DF9A(&ewk->wu);
    }
}

s16 eff_hit_check(WORK_Other *ewk, s16 type) {
    if (!EXE_obroll) {
        if (type) {
            if (pcon_dp_flag) {
                eff_hit_flag[ewk->wu.type] = (s16)(eff_hit_flag[ewk->wu.type] + eff_hit_check_sub(ewk, &plw[0]));
                eff_hit_flag[ewk->wu.type] = (s16)(eff_hit_flag[ewk->wu.type] + eff_hit_check_sub(ewk, &plw[1]));
            }
        } else {
            eff_hit_flag[ewk->wu.type] = (s16)(eff_hit_flag[ewk->wu.type] + eff_hit_check_sub(ewk, &plw[0]));
            eff_hit_flag[ewk->wu.type] = (s16)(eff_hit_flag[ewk->wu.type] + eff_hit_check_sub(ewk, &plw[1]));
        }
    }

    return eff_hit_flag[ewk->wu.type];
}

s32 eff_hit_check_sub(WORK_Other *ewk, PLW *pl) {
    if (pl->wu.routine_no[1] == 1) {
        if (pl->wu.routine_no[2] < 14 || pl->wu.routine_no[2] >= 24) {
            return 0;
        }

        if (sub_0005F40D(&pl->wu, &ewk->wu, &pl_hit_eff[pl->player_number][0], &eff_hit_data[ewk->wu.type][0])) {
            return 1;
        }
    }

    return 0;
}

s16 eff_hit_check2(WORK_Other *ewk, s16 type, s16 where_type) {
    if (!EXE_obroll) {
        if (type) {
            if (pcon_dp_flag) {
                eff_hit_flag[ewk->wu.type] =
                    (s16)(eff_hit_flag[ewk->wu.type] + eff_hit_check_sub2(ewk, &plw[0], where_type));
                eff_hit_flag[ewk->wu.type] =
                    (s16)(eff_hit_flag[ewk->wu.type] + eff_hit_check_sub2(ewk, &plw[1], where_type));
            }
        } else {
            eff_hit_flag[ewk->wu.type] =
                (s16)(eff_hit_flag[ewk->wu.type] + eff_hit_check_sub2(ewk, &plw[0], where_type));
            eff_hit_flag[ewk->wu.type] =
                (s16)(eff_hit_flag[ewk->wu.type] + eff_hit_check_sub2(ewk, &plw[1], where_type));
        }
    }

    return eff_hit_flag[ewk->wu.type];
}

s32 eff_hit_check_sub2(WORK_Other *ewk, PLW *pl, s16 where_type) {
    s16 *hd1 = pl->wu.h_bod->body_dm[where_type];

    if (hit_check_subroutine_yu(&pl->wu, &ewk->wu, hd1, eff_hit_data[ewk->wu.type])) {
        return 1;
    }

    return 0;
}

static s16 hit_check_subroutine_yu(WORK *tpl, WORK *tef, s16 *hd1, s16 *hd2) {
    s16 d0 = *hd1++;
    s16 d1 = *hd1++;
    s16 d2;
    s16 d3;
    s16 flag;

    if (tpl->rl_flag) {
        d0 = (s16)-d0;
        d0 = (s16)(d0 - d1);
    }

    d0 = (s16)(d0 + tpl->xyz[0].disp.pos);
    d2 = *hd2++;
    d3 = *hd2++;

    if (tef->rl_flag) {
        d2 = (s16)-d2;
        d2 = (s16)(d2 - d3);
    }

    d2 = (s16)(d2 + tef->xyz[0].disp.pos);
    flag = (s16)(d0 < d2);
    d2 = (s16)(d2 + (d3 - d0));
    d3 = (s16)(d3 + d1);

    if ((u32)d2 >= (u32)d3) {
        return 0;
    }

    d0 = (s16)((tpl->xyz[1].disp.pos + *hd1++) - (tef->xyz[1].disp.pos + *hd2++ - 40));
    d1 = *hd1;
    d0 = (s16)(d0 + d1);
    d1 = (s16)(d1 + *hd2);

    if ((u32)d0 >= (u32)d1) {
        return 0;
    } else if (flag) {
        d2 = (s16)(d3 - d2);
    }

    return d2;
}

void eff_hit_flag_clear(void) {
    s16 i;
    s16 *ptr;

    ptr = &eff_hit_flag[0];

    for (i = 0; i < 0xB; i++) {
        *ptr++ = 0;
    }
}

s32 compel_dead_check(WORK_Other *ewk) {
    s32 var_s0 = 0;

    if (bg_w.compel_flag) {
        if (ewk->wu.dead_f) {
            var_s0 = 1;
        }
    }

    return var_s0;
}

void win_lose_work_clear(void) {
    a_rno = 0;
    lose_rno[2] = 0;
    win_rno[0] = 0;
    win_free[0] = 0;
    lose_rno[0] = 0;
    lose_free[0] = 0;
    win_rno[1] = 0;
    win_free[1] = 0;
    lose_rno[1] = 0;
    lose_free[1] = 0;
}

void cal_bg_speed_data_x(s16 bg_num, s16 tm, s16 unk) {
    MotionState ms;

    (void)unk;

    bg_w.bgw[bg_num].chase_xy[0].disp.low = 0;
    ms.timer = tm;
    ms.timer2 = ((ms.timer * (ms.timer - 1)) / 2) + ms.timer;
    ms.x.ps.h = (s16)(chase_x - bg_w.bgw[bg_num].chase_xy[0].disp.pos);
    ms.x.ps.l = 0;

    if (!ms.timer) {
        ms.amx = 0;
        ms.dlx = 0;
        ms.spx = 0;
    } else {
        ms.amx = ms.x.pl % ms.timer2;
        ms.spx = ms.dlx = ms.x.pl / ms.timer2;
    }

    bg_mvxy.a[0].sp = ms.spx;
    bg_mvxy.d[0].sp = ms.dlx;
    bg_w.bgw[bg_num].chase_xy[0].cal += ms.amx;
    bg_mvxy.kop[0] = 0;
}

void cal_bg_speed_data_y(s16 bg_num, s16 tm, s16 unk) {
    MotionState ms;

    (void)unk;

    bg_w.bgw[bg_num].chase_xy[1].disp.low = 0;
    ms.timer = tm;
    ms.timer2 = ((ms.timer * (ms.timer - 1)) / 2) + ms.timer;
    ms.y.ps.h = (s16)(chase_y - bg_w.bgw[bg_num].chase_xy[1].disp.pos);
    ms.y.ps.l = 0;

    if (!ms.timer) {
        ms.amy = 0;
        ms.dly = 0;
        ms.spy = 0;
    } else {
        ms.amy = ms.y.pl % ms.timer2;
        ms.spy = ms.dly = ms.y.pl / ms.timer2;
    }

    bg_mvxy.a[1].sp = ms.spy;
    bg_mvxy.d[1].sp = ms.dly;
    bg_w.bgw[bg_num].chase_xy[1].cal += ms.amy;
    bg_mvxy.kop[1] = 0;
}
