/* Winner poses, retail sf33rd.xbe.
 * jijii_nebukuro is 0xF015D size 0xA2. jijii_jump is 0xF01FF size 0x18F.
 * jijii_full is 0xF038E size 0x76. q_em_distance_chk is 0xF0404 size 0x63.
 * q_em_dir is 0xF0467 size 0x98. q_keeping_action is 0xF04FF size 0x10B.
 * q_leave_after_action is 0xF060A size 0x17A. twelve_win_away is 0xF0784
 * size 0xE0. twelve_win_backjump is 0xF0864 size 0x12C. urien_dash_chk is
 * 0xF0990 size 0x44. urien_dash is 0xF09D4 size 0x145. win_select is
 * 0xF0B19 size 0xA.
 * q_em_distance_tbl is 0x2B3EA0 and matches the 80 PlayStation 2 bytes.
 * bg_app_stop is 0x7BC4E8. win_sp_flag is 0xC7D8E0. plw is 0xC7CEA0,
 * stride 0x46C. win_rno is 0x7A8A44. win_free is 0x7A8A3C. scrr is
 * 0x7A88F8. scrl is 0x7A81D0.
 * char_move stays sub_0002008E. set_char_move_init stays sub_000200A9.
 * set_char_move_init2 stays sub_000201B9. char_move_z stays sub_000202CE.
 * char_move_cmja stays sub_0002036A. add_x_sub stays sub_000EF072.
 * add_y_sub stays sub_000EF088. effect_work_kill stays sub_0004A7F0.
 * add_mvxy_speed stays sub_00092EA2. cal_mvxy_speed stays sub_00092E50.
 * set_field_hosei_flag stays sub_00093124. random_16 stays sub_0009326B.
 * setup_mvxy_data stays sub_000938DE.
 * q_em_dir does not write the saved position on the miss path.
 * 0xF0B23 stays unnamed.
 * q_keeping_action, q_leave_after_action, twelve_win_away, and urien_dash
 * are scanned starts. jijii_nebukuro, jijii_jump, jijii_full,
 * q_em_distance_chk, q_em_dir, twelve_win_backjump, urien_dash_chk, and
 * win_select are interior.
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
    u8 raw0[8];
    s16 id;
    s8 rl_flag;
    s8 rl_waza;
    u8 raw1[0x56 - 0xC];
    s16 position_y;
    s16 position_z;
    u8 raw2[0x64 - 0x5A];
    XY xyz[3];
    u8 raw3[0x7C - 0x70];
    MVXY mvxy;
    s16 direction;
    u8 raw4[0x16A - 0x96];
    s16 cmwk[32];
    u8 raw5[0x214 - 0x1AA];
    u8 cg_type;
    u8 raw6[0x22E - 0x215];
    s16 cg_jphos;
    u8 raw7[0x240 - 0x230];
    s16 my_priority;
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef struct {
    WORK wu;
    u8 mid[0x394 - sizeof(WORK)];
    s16 player_number;
} PLW;

typedef struct {
    u8 raw0[0x18];
    XY xy[2];
    XY wxy[2];
    u8 raw1[0x90 - 0x28];
} BGW;

typedef struct {
    u8 raw0[0x1C];
    s16 pos_offset;
    u8 raw1[0x38 - 0x1E];
    BGW bgw[7];
} BG;

#if defined(__i386__)
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, rl_waza) == 0xB, "rl_waza");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz) == 0x64, "xyz");
_Static_assert(__builtin_offsetof(XY, disp.pos) == 2, "disp.pos");
_Static_assert(__builtin_offsetof(WORK, mvxy) == 0x7C, "mvxy");
_Static_assert(__builtin_offsetof(MVXY, d) == 8, "d");
_Static_assert(__builtin_offsetof(WORK, direction) == 0x94, "direction");
_Static_assert(__builtin_offsetof(WORK, cmwk) == 0x16A, "cmwk");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, cg_jphos) == 0x22E, "cg_jphos");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(PLW, player_number) == 0x394, "player_number");
_Static_assert(__builtin_offsetof(BGW, xy) == 0x18, "xy");
_Static_assert(__builtin_offsetof(BGW, wxy) == 0x20, "wxy");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, pos_offset) == 0x1C, "pos_offset");
_Static_assert(__builtin_offsetof(BG, bgw) == 0x38, "bgw");
#endif

extern s8 bg_app_stop;
extern u8 win_sp_flag;
extern s16 win_rno[2];
extern s16 win_free[2];
extern s16 scrr;
extern s16 scrl;
extern PLW plw[2];
extern BG bg_w;

void sub_0002008E(WORK *wk);
void sub_000200A9(WORK *wk, s16 koc, s16 index);
void sub_000201B9(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void sub_000202CE(WORK *wk);
void sub_0002036A(WORK *wk);
void sub_000EF072(WORK_Other *wk);
void sub_000EF088(WORK_Other *wk);
void sub_0004A7F0(s16 index, s16 kill_id);
void sub_00092EA2(WORK *wk);
void sub_00092E50(WORK *wk);
s32 sub_00093124(PLW *pl, s32 pos, s16 ix);
s16 sub_0009326B(void);
void sub_000938DE(WORK *wk, u16 ix);
s32 range_x_check3(WORK_Other *ewk, s16 optional_range);

void jijii_nebukuro(PLW *wk) {
    bg_app_stop = 1;

    switch (win_rno[1]) {
    case 0:
        sub_0002008E(&wk->wu);

        if (wk->wu.cg_type == 1) {
            win_rno[1]++;
            sub_000202CE(&wk->wu);
            wk->wu.mvxy.a[1].sp = 0xF0000;
            wk->wu.mvxy.d[1].sp = -0x600;
        }

        break;

    case 1:
        if (wk->wu.cg_type != 2) {
            sub_0002008E(&wk->wu);
        }

        sub_000EF088((WORK_Other *)wk);

        if (wk->wu.xyz[1].disp.pos > 256) {
            win_rno[1]++;
            win_sp_flag = 2;
            sub_000200A9(&wk->wu, 9, 40);
            wk->wu.xyz[1].disp.pos = 200;
        }

        break;

    case 2:
        sub_0002008E(&wk->wu);
        break;
    }
}

void jijii_jump(PLW *wk) {
    s16 id_w;

    bg_app_stop = 1;
    id_w = wk->wu.id ^ 1;
    wk->wu.position_z = plw[id_w].wu.position_z - 1;
    wk->wu.my_priority = wk->wu.position_z;

    switch (win_rno[1]) {
    case 0:
        sub_0002008E(&wk->wu);

        if (wk->wu.cg_type == 9) {
            win_rno[1]++;

            if (wk->wu.rl_flag) {
                wk->wu.mvxy.a[0].sp = 0x60000;
                wk->wu.mvxy.d[0].sp = 0x1000;
            } else {
                wk->wu.mvxy.a[0].sp = -0x60000;
                wk->wu.mvxy.d[0].sp = -0x1000;
            }

            wk->wu.mvxy.a[1].sp = 0xA0000;
            wk->wu.mvxy.d[1].sp = -0x600;
        }

        break;

    case 1:
        if (wk->wu.cg_type != 99) {
            sub_0002008E(&wk->wu);
        }

        sub_000EF072((WORK_Other *)wk);
        sub_000EF088((WORK_Other *)wk);

        if (wk->wu.rl_flag) {
            if (wk->wu.xyz[0].disp.pos > bg_w.bgw[1].xy[0].disp.pos + 320) {
                win_rno[1]++;
                sub_0004A7F0(3, 13);
            }

            break;
        }

        if (wk->wu.xyz[0].disp.pos < bg_w.bgw[1].xy[0].disp.pos - 320) {
            win_rno[1]++;
            sub_0004A7F0(3, 13);
        }

        break;

    case 2:
        win_rno[1]++;
        sub_000201B9(&wk->wu, 9, 36, 7, 0);
        win_free[wk->wu.id] = 48;
        break;

    case 3:
        win_free[wk->wu.id]--;

        if (win_free[wk->wu.id] > 0) {
            break;
        }

        win_rno[1]++;

        if (wk->wu.rl_flag) {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos - 328;
            wk->wu.mvxy.a[0].sp = 0x18000;
        } else {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].xy[0].disp.pos + 328;
            wk->wu.mvxy.a[0].sp = -0x18000;
        }

        wk->wu.mvxy.d[0].sp = 0;
        wk->wu.xyz[1].cal = 0;
        /* fallthrough */

    case 4:
        sub_000EF072((WORK_Other *)wk);
        sub_0002008E(&wk->wu);
        break;
    }
}

void jijii_full(PLW *wk) {
    bg_app_stop = 1;

    switch (win_rno[1]) {
    case 0:
        sub_0002008E(&wk->wu);

        if (wk->wu.cmwk[0] == 1) {
            win_rno[1]++;
            break;
        }

        break;

    case 1:
        sub_0002008E(&wk->wu);
        wk->wu.xyz[1].cal += 0x10000;

        if (wk->wu.xyz[1].disp.pos >= 42) {
            win_rno[1]++;
            wk->wu.cmwk[0] = 2;
            sub_000200A9(&wk->wu, 9, 43);
            break;
        }

        break;

    case 2:
        sub_0002008E(&wk->wu);
        break;
    }
}

const s16 q_em_distance_tbl[20][2] = { { -96, -16 }, { -104, 0 },  { -90, -16 }, { -100, -8 }, { -100, 0 },
                                       { -106, 0 },  { 12, -117 }, { -84, -21 }, { -112, 0 },  { -106, 4 },
                                       { -100, 0 },  { -90, -16 }, { -90, -16 }, { -96, -16 }, { -90, -16 },
                                       { -90, -16 }, { 0, -96 },   { -2, -112 }, { -112, 4 },  { -96, -6 } };

s16 q_em_distance_chk(PLW *wk) {
    s16 work;
    s16 id_w = wk->wu.id ^ 1;
    s16 rl_w = wk->wu.rl_flag ^ plw[id_w].wu.rl_flag;

    if (wk->wu.rl_flag) {
        work = wk->wu.xyz[0].disp.pos - plw[id_w].wu.xyz[0].disp.pos;

        if (work >= q_em_distance_tbl[plw[id_w].player_number][rl_w]) {
            return 1;
        }
    } else {
        work = plw[id_w].wu.xyz[0].disp.pos - wk->wu.xyz[0].disp.pos;

        if (work >= q_em_distance_tbl[plw[id_w].player_number][rl_w]) {
            return 1;
        }
    }

    return 0;
}

s32 q_em_dir(PLW *wk) {
    s16 work;
    s16 pos_w;
    s16 id_w = wk->wu.id ^ 1;

    work = wk->wu.xyz[0].disp.pos - plw[id_w].wu.xyz[0].disp.pos;

    if (work < 0) {
        wk->wu.direction = 1;
    } else {
        wk->wu.direction = 0;
    }

    pos_w = wk->wu.xyz[0].disp.pos;

    if (q_em_distance_chk(wk)) {
        if (win_rno[0] == 3) {
            win_rno[0] = 1;
            sub_000200A9(&wk->wu, 9, 36);
        } else if (win_rno[0] == 4) {
            win_rno[0] = 2;
            sub_000200A9(&wk->wu, 9, 36);
        }

        wk->wu.direction = wk->wu.rl_flag;
        win_rno[1] = 4;
        wk->wu.xyz[0].disp.pos = pos_w;
        return 0;
    }

    wk->wu.xyz[0].disp.pos = pos_w;
    return 1;
}

void q_keeping_action(PLW *wk) {
    switch (win_rno[1]) {
    case 0:
        if (!q_em_dir(wk)) {
            break;
        }

        if (wk->wu.direction == wk->wu.rl_flag) {
            win_rno[1] = 2;
            break;
        }

        win_rno[1] = 1;
        sub_000200A9(&wk->wu, 9, 40);
        wk->wu.rl_flag ^= 1;
        break;

    case 1:
        sub_0002008E(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            win_rno[1]++;
            break;
        }

        break;

    case 2:
        win_rno[1]++;
        sub_000200A9(&wk->wu, 9, 41);
        wk->wu.mvxy.d[0].sp = 0;

        if (wk->wu.rl_flag) {
            wk->wu.mvxy.a[0].sp = 0x1C000;
            break;
        }

        wk->wu.mvxy.a[0].sp = -0x1C000;
        break;

    case 3:
        sub_0002008E(&wk->wu);
        sub_000EF072((WORK_Other *)wk);

        if (!q_em_distance_chk(wk)) {
            break;
        }

        win_rno[1]++;

        if (win_rno[0] == 1) {
            sub_000200A9(&wk->wu, 9, 36);
            break;
        }

        sub_000200A9(&wk->wu, 9, 37);
        break;

    case 4:
        sub_0002008E(&wk->wu);
        break;
    }
}

void q_leave_after_action(PLW *wk) {
    s16 work;

    switch (win_rno[1]) {
    case 0:
        if (q_em_dir(wk) == 0) {
            break;
        }

        if (wk->wu.direction == wk->wu.rl_flag) {
            win_rno[1] = 2;
        } else {
            win_rno[1] = 1;
            sub_000200A9(&wk->wu, 9, 40);
            wk->wu.rl_flag ^= 1;
        }

        break;

    case 1:
        sub_0002008E(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            win_rno[1]++;
        }

        break;

    case 2:
        win_rno[1]++;
        sub_000200A9(&wk->wu, 9, 41);
        wk->wu.mvxy.d[0].sp = 0;

        if (wk->wu.rl_flag) {
            wk->wu.mvxy.a[0].sp = 0x1C000;
        } else {
            wk->wu.mvxy.a[0].sp = -0x1C000;
        }

        break;

    case 3:
        sub_0002008E(&wk->wu);
        sub_000EF072((WORK_Other *)wk);

        if (q_em_distance_chk(wk)) {
            win_rno[1]++;

            if (win_rno[0] == 2) {
                sub_000200A9(&wk->wu, 9, 36);
            } else {
                sub_000200A9(&wk->wu, 9, 39);
            }
        }

        break;

    case 4:
        sub_0002008E(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            win_rno[1]++;
            sub_000200A9(&wk->wu, 9, 41);
            wk->wu.mvxy.d[0].sp = 0;

            if (wk->wu.rl_flag) {
                wk->wu.mvxy.a[0].sp = 0x1C000;
            } else {
                wk->wu.mvxy.a[0].sp = -0x1C000;
            }
        }

        break;

    case 5:
        sub_0002008E(&wk->wu);
        sub_000EF072((WORK_Other *)wk);

        if (wk->wu.rl_flag) {
            work = bg_w.bgw[1].wxy[0].disp.pos + bg_w.pos_offset;
            work += 64;

            if (work < wk->wu.xyz[0].disp.pos) {
                win_rno[1]++;
            }

            break;
        }

        work = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset;
        work -= 64;

        if (work > wk->wu.xyz[0].disp.pos) {
            win_rno[1]++;
        }

        break;
    }
}

void twelve_win_away(PLW *wk) {
    switch (win_rno[1]) {
    case 0:
        sub_0002008E(&wk->wu);

        if (wk->wu.cg_type == 1) {
            win_rno[1]++;
            wk->wu.mvxy.a[0].sp = 0;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[1].sp = 0x78000;
            wk->wu.mvxy.d[1].sp = -0x6000;
        }

        break;

    case 1:
        sub_000EF088((WORK_Other *)wk);
        sub_0002008E(&wk->wu);

        if (wk->wu.cg_type != 2) {
            break;
        }

        win_rno[1]++;
        wk->wu.mvxy.d[0].sp = 0;

        if (wk->wu.rl_flag) {
            wk->wu.mvxy.a[0].sp = 0x80000;
        } else {
            wk->wu.mvxy.a[0].sp = -0x80000;
        }

        wk->wu.mvxy.a[1].sp = -0x8000;
        wk->wu.mvxy.d[1].sp = 0x4000;
        break;

    case 2:
        sub_000EF072((WORK_Other *)wk);
        sub_000EF088((WORK_Other *)wk);

        if (!range_x_check3((WORK_Other *)wk, 208)) {
            win_rno[1]++;
        }

        break;

    case 3:
        break;
    }
}

void twelve_win_backjump(PLW *wk) {
    switch (win_rno[1]) {
    case 0:
        sub_0002008E(&wk->wu);

        if (wk->wu.cg_type == 1) {
            win_rno[1]++;
            wk->wu.mvxy.a[0].sp = 0x30000;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[1].sp = 0x78000;
            wk->wu.mvxy.d[1].sp = -0x5000;

            if (wk->wu.rl_flag) {
                wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            }
        }

        if (sub_00093124(&plw[wk->wu.id], scrr, 1)) {
            sub_00093124(&plw[wk->wu.id], scrl, 0);
        }

        break;

    case 1:
        sub_000EF088((WORK_Other *)wk);
        sub_000EF072((WORK_Other *)wk);
        sub_0002008E(&wk->wu);

        if (wk->wu.cg_type == 2) {
            win_rno[1]++;
            sub_000202CE(&wk->wu);
            wk->wu.xyz[1].cal = 0;
        }

        if (sub_00093124(&plw[wk->wu.id], scrr, 1)) {
            sub_00093124(&plw[wk->wu.id], scrl, 0);
        }

        break;

    case 2:
        sub_0002008E(&wk->wu);

        if (wk->wu.cg_type == 9) {
            win_rno[1]++;
        }

        break;

    case 3:
        sub_0002008E(&wk->wu);
        wk->wu.xyz[1].cal += 0x20000;

        if (wk->wu.xyz[1].disp.pos > 256) {
            win_rno[1]++;
        }

        break;

    case 4:
        break;
    }
}

s32 urien_dash_chk(PLW *wk) {
    s16 id_w = wk->wu.id ^ 1;
    s16 pos_w = wk->wu.xyz[0].disp.pos - plw[id_w].wu.xyz[0].disp.pos;

    if (pos_w < 0) {
        pos_w = -pos_w;

        if (!wk->wu.rl_waza) {
            wk->wu.rl_waza = 1;
        }
    } else if (wk->wu.rl_waza) {
        wk->wu.rl_waza = 0;
    }

    if (pos_w < 88) {
        return 1;
    }

    return 0;
}

void urien_dash(PLW *wk) {
    switch (win_rno[1]) {
    case 0:
        win_rno[1]++;

        if (urien_dash_chk(wk)) {
            win_rno[1] = 5;
        } else {
            wk->wu.rl_flag = wk->wu.rl_waza;
            sub_000200A9(&wk->wu, 0, 4);
            sub_000938DE(&wk->wu, 2);
        }

        /* fallthrough */

    case 1:
        if (wk->wu.cg_type == 1) {
            win_rno[1]++;
            sub_00092EA2(&wk->wu);
        } else {
            sub_0002008E(&wk->wu);
        }

        break;

    case 2:
        sub_00092EA2(&wk->wu);
        sub_00092E50(&wk->wu);
        sub_0002008E(&wk->wu);

        if (wk->wu.xyz[1].disp.pos + wk->wu.cg_jphos >= 1) {
            break;
        }

        win_rno[1]++;
        wk->wu.position_y = 0;
        wk->wu.xyz[1].cal = 0;
        wk->wu.mvxy.a[1].sp = 0;
        sub_0002036A(&wk->wu);
        break;

    case 3:
        sub_0002008E(&wk->wu);

        if (wk->wu.cg_type != 64) {
            break;
        }

        if (urien_dash_chk(wk)) {
            win_rno[1]++;
        } else {
            win_rno[1] = 0;
        }

        break;

    case 4:
        sub_0002008E(&wk->wu);

        if (wk->wu.cg_type != 0xFF) {
            break;
        }

        win_rno[1]++;
        /* fallthrough */

    case 5:
        win_rno[1]++;
        sub_000200A9(&wk->wu, 9, 36);
        break;

    case 6:
        sub_0002008E(&wk->wu);
        break;
    }
}

s16 win_select(PLW *wk, s16 num) {
    s16 work;

    (void)wk;
    work = sub_0009326B();
    work &= num;
    return work;
}
