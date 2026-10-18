/* EFFB8.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_B8_move 0x4487B size 0x161. Read against the x86: Xbox code the PS2 C
 * lacks: before get_message_conn_data, if sub_001100AC() is nonzero and
 * Country is not 1, mes_already is held to 20..27. sub_001100AC returns the
 * dword at 0x79A170. The clamp is added to the C.
 * effb8_normal_or_senyou 0x449DC size 0x1F. Read against the x86: the random
 * choice also runs while sub_001100AC (the dword at 0x79A170) is set, not only
 * when Country is 1. The C is the Xbox code
 * (analysis-ps2map/overrides/EFFB8.c).
 * effb8_sel_1_by_8 0x449FB size 0x5C.
 * wk_set 0x44A57 size 0x78.
 * effect_B8_init 0x44ACF size 0xD0. Read against the x86: the unnamed words at
 * 0xCB87C8 and 0xCB87CA are the file's message counters. The C is the PS2 C.
 * Data: test_pl_no: defined elsewhere on Xbox.
 * Data: test_mes_no: defined elsewhere on Xbox.
 * Data: test_in: defined elsewhere on Xbox.
 * Data: old_mes_no2 0xCB87C6.
 * Data: old_mes_no3 0xCB87CC.
 * Data: old_mes_no_pl 0xCB87C4.
 * Data: mes_timer 0xCB87C2.
 * Unnamed data used (not checked): effect_B8_init: 0xcb87c8,0xcb87ca.
 * Globals: My_char 0x7A8114, Suicide 0x7A8268, mes_already 0x7A8290, Country
 * 0x7A8748, bg_w 0x7BC520, plw 0xC7CEA0, frw 0xC806A0, mes_timer 0xCB87C2,
 * old_mes_no_pl 0xCB87C4, old_mes_no2 0xCB87C6, old_mes_no3 0xCB87CC.
 */

#include "structs.h"

#define EFFECT_MAX 128

s32 sub_001100AC(void);
void get_message_conn_data(WORK_Other_CONN* ewk, s16 kind, s16 pl, s16 msg);
extern s16 mes_already;
extern BG bg_w;
extern s8 Suicide[8];
s32 sort_push_request3(WORK* wk);
void push_effect_work(WORK* wkhd);
extern PLW plw[2];
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
void wk_set(WORK_Other_CONN* ewk);
extern u8 My_char[2];
u16 effb8_normal_or_senyou();
u16 effb8_sel_1_by_8();
extern u8 Country;
s32 random_16();

extern s16 test_pl_no;

extern s16 test_mes_no;

extern s16 test_in;

extern s16 old_mes_no2;

extern s16 old_mes_no3;

extern s16 old_mes_no_pl;

extern s16 mes_timer;

void effect_B8_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.my_mts = 12;
        mes_timer = mes_timer - 1;

        if (--mes_timer > 0) {
            break;
        }

        ewk->wu.routine_no[0]++;
        get_message_conn_data(ewk, 0, ewk->master_player, mes_already);
        ewk->wu.disp_flag = 1;
        ewk->wu.vitality = 240;
        mes_timer = 55;
        ewk->wu.mvxy.a[0].sp = -0x100000;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 152;
        ewk->wu.mvxy.a[0].sp = -0x100000;
        ewk->wu.mvxy.d[0].sp = 0;
        break;

    case 1:
        if (Suicide[2] == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 3;
            break;
        }

        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;

    case 2:
        if (Suicide[2] == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        sort_push_request3(&ewk->wu);
        break;

    case 3:
        ewk->wu.routine_no[0]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_B8_init(s8 WIN_PL_NO, s16 timer) {
    PLW* wk;
    WORK_Other_CONN* ewk;
    s16 ix;
    u16 mes_no;

    test_in = 0;
    wk = &plw[WIN_PL_NO];

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    wk_set(ewk);
    mes_timer = timer;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_id = wk->wu.id;
    ewk->master_player = My_char[wk->wu.id];
    test_pl_no = My_char[wk->wu.id];

    if (effb8_normal_or_senyou()) {
        mes_no = My_char[wk->wu.id ^ 1] + 0;

        if (old_mes_no_pl == mes_no) {
            mes_no = effb8_sel_1_by_8();
        }

        old_mes_no_pl = mes_no;
    } else {
        mes_no = effb8_sel_1_by_8();
    }

    mes_already = mes_no;
    test_mes_no = mes_no;
    return 0;
}

/* Xbox: the random choice also runs while sub_001100AC is set. */
u16 effb8_normal_or_senyou() {
    if (sub_001100AC() == 0 && Country != 1) {
        return 0;
    }

    return random_16() & 1;
}

u16 effb8_sel_1_by_8() {
    u16 mes_no;

    mes_no = random_16() & 7;
    old_mes_no2 = old_mes_no2 & 7;
    old_mes_no3 = old_mes_no3 & 7;

    if (old_mes_no2 == mes_no) {
        mes_no = (mes_no + 1) & 7;
    }

    if (old_mes_no3 == mes_no) {
        mes_no = (mes_no + 1) & 7;

        if (old_mes_no2 == mes_no) {
            mes_no = (mes_no + 1) & 7;
        }
    }

    old_mes_no3 = old_mes_no2;
    old_mes_no2 = mes_no;
    mes_no = mes_no + 20;
    return mes_no;
}

void wk_set(WORK_Other_CONN* ewk) {
    ewk->wu.be_flag = 1;
    ewk->wu.id = 118;
    ewk->wu.work_id = 16;
    ewk->wu.rl_flag = 0;
    ewk->wu.cgromtype = 1;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x37;
    ewk->wu.my_family = 1;
    ewk->wu.my_priority = 35;
    ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 168;
    ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 15;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 168;
    ewk->wu.position_z = 35;
}
