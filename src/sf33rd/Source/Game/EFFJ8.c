/* EFFJ8.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * dragonfly_stop_timer 0x4E93A size 0x1F.
 * dragonfly_move_next 0x4E9AA size 0x1D.
 * effect_J8_init 0x4E9C7 size 0xF5.
 * dragonfly_move_0000 0x4ED56 size 0xC5. Read against the x86: 0x20 is the 32
 * added to pos_offset. The C is the PS2 C.
 * dragonfly_move_0004 0x4EED6 size 0x9F.
 * dragonfly_move 0x4F025 size 0x47.
 * effect_J8_move 0x4F06C size 0x88.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * dragonfly_l_move_0, dragonfly_l_move_1, dragonfly_l_move_2,
 * dragonfly_l_move_3, dragonfly_l_move_4, dragonfly_l_move,
 * dragonfly_r_move_0, dragonfly_r_move_1, dragonfly_r_move_2,
 * dragonfly_r_move_3, dragonfly_r_move_4, dragonfly_r_move,
 * dragonfly_move_0001, dragonfly_move_0005, dragonfly_line_set.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * all_cgps_put_back is folded into 0x4384A.
 * disp_pos_trans_entry is folded into 0xEF0C0.
 * Data: effj8_timer_tbl is 0x259840, 0x10 bytes compared.
 * Data: effj8_y_tbl is 0x259850, 0x10 bytes compared.
 * Data: effj8_sp_tbl is 0x259860, 0x80 bytes compared.
 * Globals: effj8_timer_tbl 0x259840, char_add 0x332CC8, EXE_obroll 0x7A8111,
 * Game_pause 0x7A89B0, bg_w 0x7BC520, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000EF072(WORK_Other* ewk);
void sub_000EF088(WORK_Other* ewk);
void sub_0004384A(WORK* wk);
void sub_000EF0C0(WORK_Other* ewk);
s32 obr_no_disp_check();
void set_char_move_init(WORK* wk, s16 koc, s16 index);
s32 compel_dead_check(WORK_Other* ewk);
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;
void dragonfly_move(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
void dragonfly_move_0000(WORK_Other* ewk);
void dragonfly_move_0001(WORK_Other* ewk);
void dragonfly_r_move(WORK_Other* ewk);
void dragonfly_l_move(WORK_Other* ewk);
void dragonfly_move_0004(WORK_Other* ewk);
void dragonfly_move_0005(WORK_Other* ewk);
void char_move(WORK* wk);
extern BG bg_w;
void dragonfly_stop_timer(WORK_Other* ewk);
void dragonfly_move_next(WORK_Other* ewk);
s32 random_16();
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);
extern u32* char_add[];
void suzi_offset_set(WORK_Other* ewk);

const s16 effj8_timer_tbl[8] = { 60, 120, 180, 90, 150, 30, 220, 160 };

const s16 effj8_y_tbl[8] = { 128, 80, 96, 160, 176, 112, 144, 168 };

const s32 effj8_sp_tbl[8][4] = { { 0x60000, -0x4000, 0x4000, 0 }, { 0x60000, -0x4800, -0x4000, 0 },
                                 { 0x60000, -0x1000, 0x4000, 0 }, { 0x60000, -0x2000, -0x4000, 0 },
                                 { 0x80000, -0xA000, 0x4000, 0 }, { 0x80000, -0x2000, -0x4000, 0 },
                                 { 0x80000, -0x6000, 0x4000, 0 }, { 0x80000, -0x4000, -0x4000, 0 } };

void effect_J8_move(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }

        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            dragonfly_move(ewk);
        }

        sub_000EF0C0(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

void dragonfly_move(WORK_Other* ewk) {
    void (*const dragonfly_move_jp1[8])(WORK_Other*) = { dragonfly_move_0000, dragonfly_move_0001, dragonfly_r_move,
                                                         dragonfly_l_move,    dragonfly_move_0004, dragonfly_move_0005,
                                                         dragonfly_l_move,    dragonfly_r_move };
    dragonfly_move_jp1[ewk->wu.routine_no[1]](ewk);
}

void dragonfly_move_0000(WORK_Other* ewk) {
    char_move(&ewk->wu);

    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.rl_flag = 1;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].r_limit2 + bg_w.pos_offset + 32;
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.xyz[1].disp.pos = 107;
        ewk->wu.xyz[1].disp.low = 0;
        dragonfly_stop_timer(ewk);
        break;

    case 1:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[2]++;
            ewk->wu.dir_timer = 150;
            ewk->wu.mvxy.a[0].sp = -0x32C5F;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = -0x1B4E;
            ewk->wu.mvxy.d[1].sp = 0;
        }

        break;

    case 2:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            dragonfly_move_next(ewk);
            ewk->wu.xyz[0].disp.pos = 512;
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = 91;
            ewk->wu.xyz[1].disp.low = 0;
            break;
        }

        sub_000EF072(ewk);
        sub_000EF088(ewk);
        break;
    }
}

void dragonfly_move_0004(WORK_Other* ewk) {
    char_move(&ewk->wu);

    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.rl_flag = 0;
        dragonfly_stop_timer(ewk);
        break;

    case 1:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[2]++;
            ewk->wu.dir_timer = 180;
            ewk->wu.mvxy.a[0].sp = 0x364FA;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = -0x27D2;
            ewk->wu.mvxy.d[1].sp = 0;
        }

        break;

    case 2:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            dragonfly_move_next(ewk);
            ewk->wu.xyz[0].disp.pos = 627;
            ewk->wu.xyz[0].disp.low = 0;
            ewk->wu.xyz[1].disp.pos = 92;
            ewk->wu.xyz[1].disp.low = 0;
            break;
        }

        sub_000EF072(ewk);
        sub_000EF088(ewk);
        break;
    }
}

void dragonfly_stop_timer(WORK_Other* ewk) {
    s16 work = random_16();

    work &= 7;
    ewk->wu.dir_timer = effj8_timer_tbl[work];
}

void dragonfly_move_next(WORK_Other* ewk) {
    ewk->wu.routine_no[1]++;
    ewk->wu.routine_no[1] &= 7;
    ewk->wu.routine_no[2] = 0;
    ewk->wu.routine_no[3] = 0;
}

s32 effect_J8_init() {
    WORK_Other* ewk;
    s16 ix;
    s16 i;

    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 198;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.type = i;
        ewk->wu.dead_f = 1;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 8492;
        ewk->wu.my_mts = 7;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);

        switch (ewk->wu.type) {
        case 0:
            ewk->wu.routine_no[1] = 4;
            ewk->wu.xyz[0].disp.pos = 16;
            ewk->wu.xyz[1].disp.pos = 120;
            break;
        case 1:
            ewk->wu.routine_no[1] = 0;
            ewk->wu.xyz[0].disp.pos = -1;
            ewk->wu.xyz[1].disp.pos = 104;
            break;
        }

        ewk->wu.my_priority = ewk->wu.position_z = 83;
        ewk->wu.char_index = 4;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = char_add[bg_w.bg_index];
        suzi_offset_set(ewk);
    }

    return 0;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void dragonfly_l_move_0(WORK_Other* ewk) {
    s16 work;

    ewk->wu.rl_flag = 1;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].r_limit2 + bg_w.pos_offset + 32;
    work = random_16();
    work &= 7;
    ewk->wu.xyz[1].disp.pos = effj8_y_tbl[work];
    ewk->wu.xyz[1].disp.low = 0;
}

void dragonfly_l_move_1(WORK_Other* ewk) {
    char_move(&ewk->wu);
    dragonfly_line_set(ewk, 0);
}

s16 dragonfly_l_move_2(WORK_Other* ewk) {
    char_move(&ewk->wu);
    add_x_sub(ewk);
    add_y_sub(ewk);

    if (ewk->wu.xyz[0].disp.pos <= bg_w.bgw[1].l_limit2 - bg_w.pos_offset - 24) {
        dragonfly_stop_timer(ewk);
        return 99;
    }

    if (ewk->wu.mvxy.a[0].sp < -0x2FFFF) {
        return 1;
    }

    return 0;
}

s16 dragonfly_l_move_3(WORK_Other* ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    add_x_sub(ewk);
    add_y_sub(ewk);

    if (ewk->wu.xyz[0].disp.pos <= bg_w.bgw[1].l_limit2 - bg_w.pos_offset - 24) {
        dragonfly_stop_timer(ewk);
        set_char_move_init(&ewk->wu, 0, 6);
        return 99;
    }

    if (ewk->wu.mvxy.a[0].sp >= 0) {
        dragonfly_stop_timer(ewk);
        set_char_move_init(&ewk->wu, 0, 6);
        return 1;
    }

    return 0;
}

s16 dragonfly_l_move_4(WORK_Other* ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    char_move(&ewk->wu);
    ewk->wu.dir_timer--;

    if (ewk->wu.dir_timer <= 0) {
        set_char_move_init(&ewk->wu, 0, 4);
        return 1;
    }

    return 0;
}

void dragonfly_l_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        dragonfly_l_move_0(ewk);
        /* fallthrough */

    case 1:
        ewk->wu.routine_no[2]++;
        dragonfly_l_move_1(ewk);
        break;

    case 2:
        ewk->wu.routine_no[2] += dragonfly_l_move_2(ewk);
        break;

    case 3:
        ewk->wu.routine_no[2] += dragonfly_l_move_3(ewk);
        break;

    case 4:
        char_move(&ewk->wu);

        if (dragonfly_l_move_4(ewk)) {
            ewk->wu.routine_no[2] = 1;
            break;
        }

        break;

    default:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            dragonfly_move_next(ewk);
            set_char_move_init(&ewk->wu, 0, 4);
        }

        break;
    }
}

void dragonfly_r_move_0(WORK_Other* ewk) {
    s16 work;

    ewk->wu.rl_flag = 0;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].l_limit2 - bg_w.pos_offset - 32;
    work = random_16();
    work &= 7;
    ewk->wu.xyz[1].disp.pos = effj8_y_tbl[work];
    ewk->wu.xyz[1].disp.low = 0;
}

void dragonfly_r_move_1(WORK_Other* ewk) {
    char_move(&ewk->wu);
    dragonfly_line_set(ewk, 1);
}

s16 dragonfly_r_move_2(WORK_Other* ewk) {
    char_move(&ewk->wu);
    add_x_sub(ewk);
    add_y_sub(ewk);

    if (ewk->wu.xyz[0].disp.pos > bg_w.bgw[1].r_limit2 + bg_w.pos_offset + 24) {
        dragonfly_stop_timer(ewk);
        return 99;
    }

    if (ewk->wu.mvxy.a[0].sp < 0x30001) {
        return 1;
    }

    return 0;
}

s16 dragonfly_r_move_3(WORK_Other* ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    add_x_sub(ewk);
    add_y_sub(ewk);

    if (ewk->wu.xyz[0].disp.pos >= bg_w.bgw[1].r_limit2 + bg_w.pos_offset + 24) {
        dragonfly_stop_timer(ewk);
        set_char_move_init(&ewk->wu, 0, 6);
        return 99;
    }

    if (ewk->wu.mvxy.a[0].sp <= 0) {
        dragonfly_stop_timer(ewk);
        set_char_move_init(&ewk->wu, 0, 6);
        return 1;
    }

    return 0;
}

s16 dragonfly_r_move_4(WORK_Other* ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init(WORK * wk, s16 koc, s32 index);
#endif

    char_move(&ewk->wu);
    ewk->wu.dir_timer--;

    if (ewk->wu.dir_timer <= 0) {
        set_char_move_init(&ewk->wu, 0, 4);
        return 1;
    }

    return 0;
}

void dragonfly_r_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        dragonfly_r_move_0(ewk);
        /* fallthrough */

    case 1:
        ewk->wu.routine_no[2]++;
        dragonfly_r_move_1(ewk);
        break;

    case 2:
        ewk->wu.routine_no[2] += dragonfly_r_move_2(ewk);
        break;

    case 3:
        ewk->wu.routine_no[2] += dragonfly_r_move_3(ewk);
        break;

    case 4:
        char_move(&ewk->wu);

        if (dragonfly_r_move_4(ewk)) {
            ewk->wu.routine_no[2] = 1;
        }

        break;

    default:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            dragonfly_move_next(ewk);
            set_char_move_init(&ewk->wu, 0, 4);
        }

        break;
    }
}

void dragonfly_move_0001(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        char_move(&ewk->wu);
        ewk->wu.routine_no[2]++;
        ewk->wu.rl_flag = 1;
        dragonfly_stop_timer(ewk);
        break;

    case 1:
        char_move(&ewk->wu);
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[2]++;
            break;
        }

        break;

    case 2:
        ewk->wu.routine_no[2]++;
        dragonfly_l_move_1(ewk);
        /* fallthrough */

    case 3:
        ewk->wu.routine_no[2] += dragonfly_l_move_2(ewk);
        break;

    case 4:
        ewk->wu.routine_no[2] += dragonfly_l_move_3(ewk);
        break;

    case 5:
        char_move(&ewk->wu);

        if (dragonfly_l_move_4(ewk)) {
            ewk->wu.routine_no[2] = 2;
            break;
        }

        break;

    default:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            dragonfly_move_next(ewk);
            set_char_move_init(&ewk->wu, 0, 4);
        }

        break;
    }
}

void dragonfly_move_0005(WORK_Other* ewk) {
    char_move(&ewk->wu);

    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.rl_flag = 0;
        dragonfly_stop_timer(ewk);
        break;

    case 1:
        ewk->wu.dir_timer--;
        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[2]++;
            break;
        }
        break;

    case 2:
        ewk->wu.routine_no[2]++;
        dragonfly_r_move_1(ewk);
        break;

    case 3:
        ewk->wu.routine_no[2] += dragonfly_r_move_2(ewk);
        break;

    case 4:
        ewk->wu.routine_no[2] += dragonfly_r_move_3(ewk);
        break;

    case 5:
        char_move(&ewk->wu);

        if (dragonfly_r_move_4(ewk)) {
            ewk->wu.routine_no[2] = 2;
            break;
        }

        break;

    default:
        ewk->wu.dir_timer--;

        if (ewk->wu.dir_timer <= 0) {
            dragonfly_move_next(ewk);
            set_char_move_init(&ewk->wu, 0, 4);
        }

        break;
    }
}

void dragonfly_line_set(WORK_Other* ewk, s16 dir_type) {
    s16 work = random_16();
    const s32* sp_ptr;

    work &= 7;
    sp_ptr = &effj8_sp_tbl[work][0];

    if (dir_type) {
        ewk->wu.mvxy.a[0].sp = *sp_ptr++;
        ewk->wu.mvxy.d[0].sp = *sp_ptr++;
    } else {
        ewk->wu.mvxy.a[0].sp = -*sp_ptr++;
        ewk->wu.mvxy.d[0].sp = -*sp_ptr++;
    }

    ewk->wu.xyz[0].disp.low = 0;
    ewk->wu.mvxy.a[1].sp = *sp_ptr++;
    ewk->wu.mvxy.d[1].sp = *sp_ptr++;
}
#endif
