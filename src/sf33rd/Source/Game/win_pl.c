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
 * char_move is 0x2008E. set_char_move_init is 0x200A9.
 * set_char_move_init2 is 0x201B9. char_move_z is 0x202CE.
 * char_move_cmja is 0x2036A. add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088. effect_work_kill is 0x4A7F0.
 * add_mvxy_speed is 0x92EA2. cal_mvxy_speed is 0x92E50.
 * set_field_hosei_flag is 0x93124. random_16 is 0x9326B.
 * setup_mvxy_data is 0x938DE.
 * bonus_game_win_pause is 0xF0B23 size 0x156. meta_win_pause is 0xF0C79
 * size 0xF3. Win_01000 is 0xF0D6C size 0x138. Win_03000 is 0xF0EA4 size
 * 0x13D. Win_04000 is 0xF0FE1 size 0x125. Normal_normal_Winner is 0xF1106
 * size 0x93. Judge_normal_winner is 0xF1199 size 0x9F. Win_05000 is
 * 0xF1238 size 0x170. Win_06000 is 0xF13A8 size 0xDF. Win_07000 is 0xF1487
 * size 0x19F. Win_08000 is 0xF1626 size 0xF7. Win_09000 is 0xF171D size
 * 0x19C. Win_10000 is 0xF18B9 size 0x17E. Win_11000 is 0xF1A37 size 0x15C.
 * Win_12000 is 0xF1B93 size 0xD9. Win_13000 is 0xF1C6C size 0x109.
 * Win_14000 is 0xF1D75 size 0x10F. Win_15000 is 0xF1E84 size 0xE4.
 * Win_00000 is 0xF1F68 size 0x5. Win_02000 is 0xF1F6D size 0xF2.
 * win_player is 0xF205F size 0xD5.
 * winner_type_tbl is 0x2B3DD8 and matches the 40 bytes. win_10000_tbl is
 * 0x2B3E00 and matches the 32 bytes. win_2000_tbl is 0x2B3E20 and matches
 * the 36 bytes. Win_3000_tbl is 0x2B3E44 and matches the 32 bytes.
 * Win_3001_tbl is 0x2B3E64 and matches the 16 bytes. Win_15000_tbl is
 * 0x2B3F00 and matches the 16 bytes. meta_win_tbl is 0x2B3F10 and matches
 * the 40 bytes.
 * Bonus_Game_Flag is 0x7A8272. Bonus_Game_result is 0x7A881A.
 * Bonus_Game_ex_result is 0x7A842A. bs_scrrrl is 0x7A8418. Time_Over is
 * 0x7A8150. Round_num is 0x7A8818. PL_Wins is 0x7A832E. Round_Result is
 * 0x7A81B4. Play_Type is 0x7A812D. Present_Mode is 0x7A819C. My_char is
 * 0x7A8114. Perfect_Flag is 0x7A812C. poison_flag is 0x7A8A48.
 * pcon_rno[0] is 0xC7E020. save_w is 0x7BD3E0, stride 0x208, and
 * Battle_Number is +0x1A. bg_w.stage is 0x7BC523. bg_w.bg_index is
 * 0x7BC550. p1sw_0 is 0x7C557C. p2sw_0 is 0x7C5B90.
 * effect_82_init stays sub_0004180D. effect_83_init stays sub_00041AA1.
 * effect_30_init stays sub_0003A58F. effect_31_init stays sub_0003A80A.
 * effect_32_init stays sub_0003AA8B. effect_L6_init is 0xBEC0D.
 * effect_L3_init is 0xB925A. effect_M2_init is 0x521B6.
 * q_em_dir does not write the saved position on the miss path.
 * Win_00000 tails into Normal_normal_Winner.
 * q_keeping_action, q_leave_after_action, twelve_win_away, and urien_dash
 * are scanned starts. jijii_nebukuro, jijii_jump, jijii_full,
 * q_em_distance_chk, q_em_dir, twelve_win_backjump, urien_dash_chk, and
 * win_select are interior. win_player is a scanned start.
 * bonus_game_win_pause, meta_win_pause, Win_01000, Win_03000, Win_04000,
 * Normal_normal_Winner, Judge_normal_winner, Win_05000, Win_06000,
 * Win_07000, Win_08000, Win_09000, Win_10000, Win_11000, Win_12000,
 * Win_13000, Win_14000, Win_15000, Win_00000, and Win_02000 are interior.
 * 0xF2679 stays unnamed.
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
    u8 raw0;
    s8 disp_flag;
    u8 raw0b;
    u8 operator;
    u8 raw0c[4];
    s16 id;
    s8 rl_flag;
    s8 rl_waza;
    u8 raw1[0x24 - 0xC];
    s16 routine_no[8];
    u8 raw1b[0x56 - 0x34];
    s16 position_y;
    s16 position_z;
    u8 raw2[0x5E - 0x5A];
    s16 next_z;
    u8 raw2b[0x64 - 0x60];
    XY xyz[3];
    u8 raw3[0x7C - 0x70];
    MVXY mvxy;
    s16 direction;
    u8 raw4[0x16A - 0x96];
    s16 cmwk[32];
    u8 raw5[0x204 - 0x1AA];
    s16 cg_ix;
    s16 now_koc;
    s16 char_index;
    s16 current_colcd;
    s16 cgd_type;
    u8 raw5b[0x214 - 0x20E];
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
    u8 raw0[3];
    s8 stage;
    u8 raw0b[0x1C - 4];
    s16 pos_offset;
    u8 raw1[0x30 - 0x1E];
    s16 bg_index;
    u8 raw1b[0x38 - 0x32];
    BGW bgw[7];
} BG;

typedef struct {
    u8 raw[0x1A];
    u8 Battle_Number[2];
    u8 raw_tail[0x208 - 0x1C];
} SAVE_W;

#if defined(__i386__)
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, operator) == 3, "operator");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, rl_waza) == 0xB, "rl_waza");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, next_z) == 0x5E, "next_z");
_Static_assert(__builtin_offsetof(WORK, xyz) == 0x64, "xyz");
_Static_assert(__builtin_offsetof(XY, disp.pos) == 2, "disp.pos");
_Static_assert(__builtin_offsetof(WORK, mvxy) == 0x7C, "mvxy");
_Static_assert(__builtin_offsetof(MVXY, d) == 8, "d");
_Static_assert(__builtin_offsetof(WORK, direction) == 0x94, "direction");
_Static_assert(__builtin_offsetof(WORK, cmwk) == 0x16A, "cmwk");
_Static_assert(__builtin_offsetof(WORK, cg_ix) == 0x204, "cg_ix");
_Static_assert(__builtin_offsetof(WORK, now_koc) == 0x206, "now_koc");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cgd_type) == 0x20C, "cgd_type");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, cg_jphos) == 0x22E, "cg_jphos");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(PLW, player_number) == 0x394, "player_number");
_Static_assert(__builtin_offsetof(BGW, xy) == 0x18, "xy");
_Static_assert(__builtin_offsetof(BGW, wxy) == 0x20, "wxy");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BG, stage) == 3, "stage");
_Static_assert(__builtin_offsetof(BG, pos_offset) == 0x1C, "pos_offset");
_Static_assert(__builtin_offsetof(BG, bg_index) == 0x30, "bg_index");
_Static_assert(__builtin_offsetof(BG, bgw) == 0x38, "bgw");
_Static_assert(sizeof(SAVE_W) == 0x208, "SAVE_W");
_Static_assert(__builtin_offsetof(SAVE_W, Battle_Number) == 0x1A, "Battle_Number");
#endif

extern s8 bg_app_stop;
extern u8 win_sp_flag;
extern s16 win_rno[2];
extern s16 win_free[2];
extern s16 scrr;
extern s16 scrl;
extern PLW plw[2];
extern BG bg_w;
extern SAVE_W save_w[];
extern s16 Bonus_Game_Flag;
extern s16 Bonus_Game_result;
extern s16 Bonus_Game_ex_result;
extern s16 bs_scrrrl[2][2];
extern s8 Time_Over;
extern u8 Round_num;
extern u8 PL_Wins[2];
extern u16 Round_Result;
extern u8 Play_Type;
extern u8 Present_Mode;
extern u8 My_char[2];
extern s8 Perfect_Flag;
extern s16 poison_flag[2];
extern s16 pcon_rno[2];
extern u16 p1sw_0;
extern u16 p2sw_0;

void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void set_char_move_init2(WORK *wk, s16 koc, s16 index, s16 ip, s16 scf);
void char_move_z(WORK *wk);
void char_move_cmja(WORK *wk);
void sub_000EF072(WORK_Other *wk);
void sub_000EF088(WORK_Other *wk);
void effect_work_kill(s16 index, s16 kill_id);
void add_mvxy_speed(WORK *wk);
void cal_mvxy_speed(WORK *wk);
s32 set_field_hosei_flag(PLW *pl, s32 pos, s16 ix);
s16 random_16(void);
void setup_mvxy_data(WORK *wk, u16 ix);
s32 range_x_check3(WORK_Other *ewk, s16 optional_range);
s32 sub_0004180D(WORK *wk);
s32 sub_00041AA1(WORK *wk);
s32 sub_0003A58F(WORK *wk);
s32 sub_0003A80A(WORK *wk);
s32 sub_0003AA8B(WORK *wk);
s32 effect_L6_init(WORK *wk, u8 typel6);
s32 effect_L3_init(PLW *wk);
s32 effect_M2_init(WORK *wk, u8 data);

void jijii_nebukuro(PLW *wk) {
    bg_app_stop = 1;

    switch (win_rno[1]) {
    case 0:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 1) {
            win_rno[1]++;
            char_move_z(&wk->wu);
            wk->wu.mvxy.a[1].sp = 0xF0000;
            wk->wu.mvxy.d[1].sp = -0x600;
        }

        break;

    case 1:
        if (wk->wu.cg_type != 2) {
            char_move(&wk->wu);
        }

        sub_000EF088((WORK_Other *)wk);

        if (wk->wu.xyz[1].disp.pos > 256) {
            win_rno[1]++;
            win_sp_flag = 2;
            set_char_move_init(&wk->wu, 9, 40);
            wk->wu.xyz[1].disp.pos = 200;
        }

        break;

    case 2:
        char_move(&wk->wu);
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
        char_move(&wk->wu);

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
            char_move(&wk->wu);
        }

        sub_000EF072((WORK_Other *)wk);
        sub_000EF088((WORK_Other *)wk);

        if (wk->wu.rl_flag) {
            if (wk->wu.xyz[0].disp.pos > bg_w.bgw[1].xy[0].disp.pos + 320) {
                win_rno[1]++;
                effect_work_kill(3, 13);
            }

            break;
        }

        if (wk->wu.xyz[0].disp.pos < bg_w.bgw[1].xy[0].disp.pos - 320) {
            win_rno[1]++;
            effect_work_kill(3, 13);
        }

        break;

    case 2:
        win_rno[1]++;
        set_char_move_init2(&wk->wu, 9, 36, 7, 0);
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
        char_move(&wk->wu);
        break;
    }
}

void jijii_full(PLW *wk) {
    bg_app_stop = 1;

    switch (win_rno[1]) {
    case 0:
        char_move(&wk->wu);

        if (wk->wu.cmwk[0] == 1) {
            win_rno[1]++;
            break;
        }

        break;

    case 1:
        char_move(&wk->wu);
        wk->wu.xyz[1].cal += 0x10000;

        if (wk->wu.xyz[1].disp.pos >= 42) {
            win_rno[1]++;
            wk->wu.cmwk[0] = 2;
            set_char_move_init(&wk->wu, 9, 43);
            break;
        }

        break;

    case 2:
        char_move(&wk->wu);
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
            set_char_move_init(&wk->wu, 9, 36);
        } else if (win_rno[0] == 4) {
            win_rno[0] = 2;
            set_char_move_init(&wk->wu, 9, 36);
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
        set_char_move_init(&wk->wu, 9, 40);
        wk->wu.rl_flag ^= 1;
        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            win_rno[1]++;
            break;
        }

        break;

    case 2:
        win_rno[1]++;
        set_char_move_init(&wk->wu, 9, 41);
        wk->wu.mvxy.d[0].sp = 0;

        if (wk->wu.rl_flag) {
            wk->wu.mvxy.a[0].sp = 0x1C000;
            break;
        }

        wk->wu.mvxy.a[0].sp = -0x1C000;
        break;

    case 3:
        char_move(&wk->wu);
        sub_000EF072((WORK_Other *)wk);

        if (!q_em_distance_chk(wk)) {
            break;
        }

        win_rno[1]++;

        if (win_rno[0] == 1) {
            set_char_move_init(&wk->wu, 9, 36);
            break;
        }

        set_char_move_init(&wk->wu, 9, 37);
        break;

    case 4:
        char_move(&wk->wu);
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
            set_char_move_init(&wk->wu, 9, 40);
            wk->wu.rl_flag ^= 1;
        }

        break;

    case 1:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            win_rno[1]++;
        }

        break;

    case 2:
        win_rno[1]++;
        set_char_move_init(&wk->wu, 9, 41);
        wk->wu.mvxy.d[0].sp = 0;

        if (wk->wu.rl_flag) {
            wk->wu.mvxy.a[0].sp = 0x1C000;
        } else {
            wk->wu.mvxy.a[0].sp = -0x1C000;
        }

        break;

    case 3:
        char_move(&wk->wu);
        sub_000EF072((WORK_Other *)wk);

        if (q_em_distance_chk(wk)) {
            win_rno[1]++;

            if (win_rno[0] == 2) {
                set_char_move_init(&wk->wu, 9, 36);
            } else {
                set_char_move_init(&wk->wu, 9, 39);
            }
        }

        break;

    case 4:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 0xFF) {
            win_rno[1]++;
            set_char_move_init(&wk->wu, 9, 41);
            wk->wu.mvxy.d[0].sp = 0;

            if (wk->wu.rl_flag) {
                wk->wu.mvxy.a[0].sp = 0x1C000;
            } else {
                wk->wu.mvxy.a[0].sp = -0x1C000;
            }
        }

        break;

    case 5:
        char_move(&wk->wu);
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
        char_move(&wk->wu);

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
        char_move(&wk->wu);

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
        char_move(&wk->wu);

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

        if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
        }

        break;

    case 1:
        sub_000EF088((WORK_Other *)wk);
        sub_000EF072((WORK_Other *)wk);
        char_move(&wk->wu);

        if (wk->wu.cg_type == 2) {
            win_rno[1]++;
            char_move_z(&wk->wu);
            wk->wu.xyz[1].cal = 0;
        }

        if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
        }

        break;

    case 2:
        char_move(&wk->wu);

        if (wk->wu.cg_type == 9) {
            win_rno[1]++;
        }

        break;

    case 3:
        char_move(&wk->wu);
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
            set_char_move_init(&wk->wu, 0, 4);
            setup_mvxy_data(&wk->wu, 2);
        }

        /* fallthrough */

    case 1:
        if (wk->wu.cg_type == 1) {
            win_rno[1]++;
            add_mvxy_speed(&wk->wu);
        } else {
            char_move(&wk->wu);
        }

        break;

    case 2:
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        char_move(&wk->wu);

        if (wk->wu.xyz[1].disp.pos + wk->wu.cg_jphos >= 1) {
            break;
        }

        win_rno[1]++;
        wk->wu.position_y = 0;
        wk->wu.xyz[1].cal = 0;
        wk->wu.mvxy.a[1].sp = 0;
        char_move_cmja(&wk->wu);
        break;

    case 3:
        char_move(&wk->wu);

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
        char_move(&wk->wu);

        if (wk->wu.cg_type != 0xFF) {
            break;
        }

        win_rno[1]++;
        /* fallthrough */

    case 5:
        win_rno[1]++;
        set_char_move_init(&wk->wu, 9, 36);
        break;

    case 6:
        char_move(&wk->wu);
        break;
    }
}

s16 win_select(PLW *wk, s16 num) {
    s16 work;

    (void)wk;
    work = random_16();
    work &= num;
    return work;
}

void bonus_game_win_pause(PLW *wk) {
    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        win_rno[0] = win_rno[1] = 0;

        if (Bonus_Game_Flag == 20) {
            if (wk->wu.operator) {
                if (Time_Over) {
                    set_char_move_init(&wk->wu, 9, 67);
                } else {
                    set_char_move_init(&wk->wu, 9, 65);
                }

                break;
            }

            wk->wu.routine_no[3] = 99;
            break;
        }

        if (wk->wu.operator) {
            if (Bonus_Game_result == 20 || Bonus_Game_ex_result == 20) {
                set_char_move_init(&wk->wu, 9, 65);
                break;
            }

            if (Bonus_Game_result > 10) {
                set_char_move_init(&wk->wu, 9, 66);
                break;
            }

            set_char_move_init(&wk->wu, 9, 67);
            break;
        }

        if (Bonus_Game_result == 20 || Bonus_Game_ex_result == 20) {
            win_rno[0] = 1;

            if (wk->wu.rl_flag) {
                wk->wu.mvxy.a[0].sp = 0x20000;
            } else {
                wk->wu.mvxy.a[0].sp = -0x20000;
            }

            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[1].sp = 0x80000;
            wk->wu.mvxy.d[1].sp = -0x6000;
            win_rno[0] = 0;
            set_char_move_init(&wk->wu, 9, 66);
            break;
        }

        set_char_move_init(&wk->wu, 9, 52);
        break;

    case 1:
    case 9:
        char_move(&wk->wu);
        break;
    }

    if (set_field_hosei_flag(&plw[1], bs_scrrrl[1][0], 1)) {
        set_field_hosei_flag(&plw[1], bs_scrrrl[1][1], 0);
    }

    if (set_field_hosei_flag(&plw[0], bs_scrrrl[0][0], 1)) {
        set_field_hosei_flag(&plw[0], bs_scrrrl[0][1], 0);
    }
}

const s16 meta_win_tbl[20] = { 33, 32, 32, 32, 32, 32, 33, 32, 32, 37, 32, 32, 32, 32, 34, 32, 32, 32, 32, 32 };

void meta_win_pause(PLW *wk) {
    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 9, meta_win_tbl[wk->player_number]);
        break;

    case 1:
    case 9:
        char_move(&wk->wu);
        break;
    }

    if (Bonus_Game_Flag) {
        if (set_field_hosei_flag(&plw[1], bs_scrrrl[1][0], 1)) {
            set_field_hosei_flag(&plw[1], bs_scrrrl[1][1], 0);
        }

        if (set_field_hosei_flag(&plw[0], bs_scrrrl[0][0], 1)) {
            set_field_hosei_flag(&plw[0], bs_scrrrl[0][1], 0);
        }
    } else {
        if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
        }
    }
}

const s16 win_10000_tbl[2][8] = { { 32, 33, 34, 32, 36, 37, 38, 33 }, { 35, 39, 34, 35, 36, 37, 38, 39 } };

void Win_01000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 7);

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            if (Round_Result & 0x800) {
                wk->wu.cmwk[0] = 0;
                set_char_move_init(&wk->wu, 9, 42);
                win_rno[0] = 3;
                break;
            }

            if (bg_w.stage == 9) {
                set_char_move_init(&wk->wu, 9, 41);
                win_rno[0] = 1;
                break;
            }

            set_char_move_init(&wk->wu, 9, win_10000_tbl[1][work]);

            if (work == 4) {
                win_rno[0] = 2;
            }

            break;
        }

        set_char_move_init(&wk->wu, 9, win_10000_tbl[0][work]);

        if (work == 4) {
            win_rno[0] = 2;
        }

        break;

    case 1:
    case 9:
        switch (win_rno[0]) {
        case 0:
            char_move(&wk->wu);
            break;

        case 1:
            jijii_nebukuro(wk);
            break;

        case 2:
            jijii_jump(wk);
            break;

        case 3:
            jijii_full(wk);
            break;
        }

        break;
    }
}

const s16 Win_3000_tbl[16] = { 42, 34, 33, 42, 32, 42, 32, 35, 42, 34, 33, 42, 32, 42, 32, 35 };

const s8 Win_3001_tbl[16] = { 36, 40, 41, 40, 41, 38, 40, 39, 36, 40, 41, 39, 41, 37, 39, 40 };

void Win_03000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        win_rno[0] = win_rno[1] = 0;
        work = win_select(wk, 15);

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            if (bg_w.stage == 7) {
                set_char_move_init(&wk->wu, 9, 43);
                break;
            }

            set_char_move_init(&wk->wu, 9, Win_3001_tbl[work]);

            if (Win_3001_tbl[work] == 41) {
                win_rno[0] = 1;
            }

            break;
        }

        set_char_move_init(&wk->wu, 9, Win_3000_tbl[work]);
        break;

    default:
        if (win_rno[0]) {
            char_move(&wk->wu);

            if (wk->wu.cg_type == 0xFF) {
                wk->wu.disp_flag = 0;
                win_rno[0] = 0;
            }

            break;
        }

        char_move(&wk->wu);
        break;
    }

    if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
    }
}

void Win_04000(PLW *wk) {
    s16 work;
    s16 work2;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        win_rno[0] = win_rno[1] = 0;
        work = win_select(wk, 3);

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            set_char_move_init(&wk->wu, 9, work + 36);
            break;
        }

        switch (work) {
        case 1:
        case 3:
            if (wk->wu.now_koc == 0 && wk->wu.char_index == 0) {
                work2 = wk->wu.cg_ix / wk->wu.cgd_type;
                work2 += 2;
                set_char_move_init2(&wk->wu, 9, work + 32, work2, 0);
            } else {
                set_char_move_init(&wk->wu, 9, work + 32);
            }

            break;

        default:
            set_char_move_init(&wk->wu, 9, work + 32);
            break;
        }

        break;

    case 1:
    default:
        char_move(&wk->wu);
        break;
    }

    if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
    }
}

void Normal_normal_Winner(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        work = win_select(wk, 7);
        set_char_move_init(&wk->wu, 9, work + 32);
        break;

    case 1:
    case 9:
        char_move(&wk->wu);
        break;
    }

    if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
    }
}

void Judge_normal_winner(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 3);
        set_char_move_init(&wk->wu, 9, work + 52);
        break;

    case 1:
    case 9:
        char_move(&wk->wu);
        break;
    }

    if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
    }
}

void Win_05000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type]) {
            set_char_move_init(&wk->wu, 9, 36);

            if (wk->wu.rl_flag) {
                wk->wu.mvxy.a[0].sp = 0x20000;
            } else {
                wk->wu.mvxy.a[0].sp = -0x20000;
            }

            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[1].sp = 0x80000;
            wk->wu.mvxy.d[1].sp = -0x6000;
            win_rno[0] = 0;
            break;
        }

        work = win_select(wk, 3);
        set_char_move_init(&wk->wu, 9, work + 32);
        win_rno[0] = 1;
        break;

    default:
        if (win_rno[0]) {
            Normal_normal_Winner(wk);
            break;
        }

        switch (win_rno[1]) {
        case 0:
            char_move(&wk->wu);
            sub_000EF072((WORK_Other *)wk);
            sub_000EF088((WORK_Other *)wk);

            if (wk->wu.xyz[1].disp.pos < 0) {
                win_rno[1]++;
                wk->wu.xyz[1].cal = 0;
                char_move_z(&wk->wu);
            }

            break;

        case 1:
            char_move(&wk->wu);
            break;
        }
    }

    if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
    }
}

void Win_06000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 36);
        } else {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 32);
        }

        if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
        }

        break;

    default:
        Normal_normal_Winner(wk);
        break;
    }
}

void Win_07000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            work = win_select(wk, 7);

            if (work < 4) {
                if (plw[0].player_number == 5 && plw[1].player_number == 5) {
                    win_rno[0] = 0;
                    set_char_move_init(&wk->wu, 9, work + 32);
                    break;
                }

                sub_0004180D(&wk->wu);
                win_rno[0] = 1;
                set_char_move_init(&wk->wu, 9, 60);
                wk->wu.cmwk[1] = 0;
                break;
            }

            if (plw[0].player_number == 5 && plw[1].player_number == 5) {
                win_rno[0] = 0;
                set_char_move_init(&wk->wu, 9, work + 32);
                break;
            }

            sub_00041AA1(&wk->wu);
            win_rno[0] = 2;
            set_char_move_init(&wk->wu, 9, 60);
            wk->wu.cmwk[1] = 0;
            break;
        }

        win_rno[0] = 0;
        work = win_select(wk, 7);
        set_char_move_init(&wk->wu, 9, work + 32);
        break;

    default:
        switch (win_rno[0]) {
        case 0:
            char_move(&wk->wu);
            break;

        default:
            if (win_rno[1] == 0) {
                if (wk->wu.cmwk[1]) {
                    win_rno[1]++;

                    if (win_rno[0] == 1) {
                        set_char_move_init(&wk->wu, 9, 32);
                    } else {
                        set_char_move_init(&wk->wu, 9, 37);
                    }

                    break;
                }

                char_move(&wk->wu);
                break;
            }

            char_move(&wk->wu);
        }
    }

    if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
    }
}

void Win_08000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;

        if (Round_Result & 0x800) {
            set_char_move_init(&wk->wu, 9, 40);
        } else if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
                   PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 36);
        } else {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 32);
        }

        if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
        }

        break;

    default:
        Normal_normal_Winner(wk);
        break;
    }
}

void Win_09000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 7);

        if (work == 7) {
            set_char_move_init(&wk->wu, 9, 32);
        } else {
            set_char_move_init(&wk->wu, 9, work + 32);
        }

        if (Round_num < (save_w[Present_Mode].Battle_Number[Play_Type] * 2) &&
            PL_Wins[wk->wu.id] < save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            break;
        }

        if (poison_flag[wk->wu.id]) {
            break;
        }

        switch (work) {
        case 0:
            effect_L6_init(&wk->wu, 0);
            break;

        case 3:
            sub_0003A58F(&wk->wu);
            break;

        case 4:
            sub_0003A80A(&wk->wu);
            break;

        case 5:
            sub_0003AA8B(&wk->wu);
            break;

        case 7:
            wk->wu.cmwk[0] = 0;
            effect_L6_init(&wk->wu, 1);
            set_char_move_init(&wk->wu, 0, 0);
            win_rno[0] = 1;
            break;
        }

        break;

    default:
        if (win_rno[0]) {
            switch (win_rno[1]) {
            case 0:
                char_move(&wk->wu);

                if (wk->wu.cmwk[0]) {
                    win_rno[1]++;
                    set_char_move_init(&wk->wu, 9, 39);
                }

                break;

            case 1:
                char_move(&wk->wu);
                break;
            }

            break;
        }

        Normal_normal_Winner(wk);
        break;
    }

    if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
    }
}

void Win_10000(PLW *wk) {
    s16 work;
    s16 work2;
    s16 id_w;

    bg_app_stop = 1;
    id_w = wk->wu.id ^ 1;
    wk->wu.position_z = wk->wu.next_z = plw[id_w].wu.position_z + 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 3);

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            work2 = wk->wu.xyz[0].disp.pos - plw[id_w].wu.xyz[0].disp.pos;

            if (work2 < 0) {
                work2 = -work2;
            }

            if (work2 > 224) {
                if (work & 1) {
                    win_rno[0] = 1;
                } else {
                    win_rno[0] = 2;
                }
            } else if (work > 1) {
                if (work & 1) {
                    if (plw[id_w].wu.char_index != 67) {
                        win_rno[0] = 1;
                    } else {
                        win_rno[0] = 3;
                    }
                } else if (plw[id_w].wu.char_index != 67) {
                    win_rno[0] = 2;
                } else {
                    win_rno[0] = 4;
                }
            } else if (work & 1) {
                win_rno[0] = 1;
            } else {
                win_rno[0] = 2;
            }
        } else {
            set_char_move_init(&wk->wu, 9, work + 32);
        }

        if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
        }

        break;

    default:
        switch (win_rno[0]) {
        case 0:
            Normal_normal_Winner(wk);
            break;

        case 1:
        case 3:
            q_keeping_action(wk);
            break;

        case 2:
        case 4:
            q_leave_after_action(wk);
            break;
        }
    }
}

void Win_11000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 3);

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            if (Perfect_Flag) {
                win_rno[0] = 1;
                set_char_move_init(&wk->wu, 9, 38);
                effect_L3_init(wk);
            } else {
                set_char_move_init(&wk->wu, 9, work + 36);

                switch (work) {
                case 0:
                    win_rno[0] = 2;
                    break;

                case 1:
                    break;

                default:
                    effect_L3_init(wk);
                    win_rno[0] = 1;
                    break;
                }
            }
        } else {
            win_rno[0] = 0;
            set_char_move_init(&wk->wu, 9, work + 32);
        }

        if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
        }

        break;

    default:
        switch (win_rno[0]) {
        case 0:
            Normal_normal_Winner(wk);
            break;

        case 1:
            twelve_win_away(wk);
            break;

        case 2:
            twelve_win_backjump(wk);
            break;
        }
    }
}

void Win_12000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;
        work = win_select(wk, 7);
        set_char_move_init(&wk->wu, 9, work + 32);

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            effect_M2_init(&wk->wu, 1);
        }

        if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
        }

        break;

    default:
        Normal_normal_Winner(wk);
        break;
    }
}

void Win_13000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            if (wk->wu.id) {
                if (p2sw_0 & 1) {
                    set_char_move_init(&wk->wu, 9, 40);
                    return;
                }
            } else if (p1sw_0 & 1) {
                set_char_move_init(&wk->wu, 9, 40);
                return;
            }

            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 36);
        } else {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 32);
        }

        if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
        }

        break;

    default:
        Normal_normal_Winner(wk);
        break;
    }
}

void Win_14000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            work = win_select(wk, 3);

            if (!(work & 1)) {
                win_rno[0] = 1;
            } else {
                set_char_move_init(&wk->wu, 9, work + 36);
            }
        } else {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 32);
        }

        break;

    default:
        if (win_rno[0]) {
            urien_dash(wk);
        } else {
            Normal_normal_Winner(wk);
        }

        break;
    }

    if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
        set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
    }
}

const s16 Win_15000_tbl[8] = { 38, 37, 40, 39, 38, 40, 39, 36 };

void Win_15000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        win_rno[0] = win_rno[1] = 0;
        wk->wu.routine_no[3]++;

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            work = win_select(wk, 7);
            set_char_move_init(&wk->wu, 9, Win_15000_tbl[work]);
        } else {
            work = win_select(wk, 3);
            set_char_move_init(&wk->wu, 9, work + 32);
        }

        if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
        }

        break;

    default:
        Normal_normal_Winner(wk);
        break;
    }
}

void Win_00000(PLW *wk) {
    Normal_normal_Winner(wk);
}

const s16 win_2000_tbl[18] = { 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 };

void Win_02000(PLW *wk) {
    s16 work;

    bg_app_stop = 1;

    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        win_rno[0] = win_rno[1] = 0;
        work = win_select(wk, 3);

        if (Round_num >= (save_w[Present_Mode].Battle_Number[Play_Type] * 2) ||
            PL_Wins[wk->wu.id] >= save_w[Present_Mode].Battle_Number[Play_Type] + 1) {
            if (win_2000_tbl[bg_w.bg_index]) {
                set_char_move_init(&wk->wu, 9, work + 36);
            } else if (work & 1) {
                set_char_move_init(&wk->wu, 9, 32);
            } else {
                set_char_move_init(&wk->wu, 9, 38);
            }
        } else {
            set_char_move_init(&wk->wu, 9, 32);
        }

        if (set_field_hosei_flag(&plw[wk->wu.id], scrr, 1)) {
            set_field_hosei_flag(&plw[wk->wu.id], scrl, 0);
        }

        break;

    default:
        Normal_normal_Winner(wk);
        break;
    }
}

const s16 winner_type_tbl[20] = { 6, 0, 0, 6, 2, 7, 9, 3, 4, 1, 12, 0, 5, 14, 8, 13, 6, 10, 11, 15 };

void win_player(PLW *wk) {
    void (*win_jp_tbl[16])(PLW *) = { Win_00000, Win_01000, Win_02000, Win_03000, Win_04000, Win_05000,
                                      Win_06000, Win_07000, Win_08000, Win_09000, Win_10000, Win_11000,
                                      Win_12000, Win_13000, Win_14000, Win_15000 };

    if (My_char[wk->wu.id] != wk->player_number) {
        meta_win_pause(wk);
        return;
    }

    if (Bonus_Game_Flag) {
        bonus_game_win_pause(wk);
        return;
    }

    if (pcon_rno[0] == 2 && pcon_rno[1] == 3) {
        Judge_normal_winner(wk);
        return;
    }

    win_jp_tbl[winner_type_tbl[wk->player_number]](wk);
}
