/* EFFI0.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * xb_effect_I0_draw 0x4CDD0 size 0x23. FLAG: x86-only callees
 * sort_push_request8.
 * effect_I0_move 0x4CDF3 size 0x10C.
 * effect_I0_init 0x4CEFF size 0xBA.
 * setup_koishi_extra 0x4CFB9 size 0xE4.
 * Data: char_of_koishi is 0x2578E8, 0x10 bytes compared.
 * Data: num_of_koishi is 0x2578F8, 0x10 bytes compared.
 * Data: koishi_area_hosei is 0x257908, 0xA bytes compared.
 * Data: koishi_app_area is 0x257918, 0x100 bytes compared.
 * Data: koishi_speed_x is 0x257A18, 0x50 bytes compared.
 * Data: koishi_speed_y is 0x257A68, 0x50 bytes compared.
 * Globals: char_of_koishi 0x2578E8, num_of_koishi 0x2578F8, koishi_area_hosei
 * 0x257908, koishi_app_area 0x257918, koishi_speed_x 0x257A18, koishi_speed_y
 * 0x257A68, _plef_char_table 0x308B40, Game_pause 0x7A89B0, EXE_flag 0xC7C834,
 * frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

s32 sort_push_request8(WORK* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
s32 random_16();
extern s16 EXE_flag;
extern u8 Game_pause;
void add_mvxy_speed(WORK* wk);
void cal_mvxy_speed(WORK* wk);
void char_move(WORK* wk);
void char_move_wca(WORK* wk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _plef_char_table[];

const s16 char_of_koishi[8];

const s16 num_of_koishi[8];

const s16 koishi_area_hosei[5];

const s16 koishi_app_area[8][16];

const s16 koishi_speed_x[5][8];

const s16 koishi_speed_y[5][8];

const s16 char_of_koishi[8] = { 85, 86, 87, 85, 86, 87, 85, 86 };

const s16 num_of_koishi[8] = { 6, 7, 8, 10, 12, 14, 15, 16 };

const s16 koishi_area_hosei[5] = { 0, 20, -20, 40, -40 };

const s16 koishi_app_area[8][16] = {
    { 0, 1, 2, 3, 4, 3, 2, 1, 0, 1, 2, 3, 4, 3, 2, 1 }, { 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0 },
    { 3, 4, 3, 4, 1, 2, 1, 2, 0, 0, 1, 2, 3, 4, 3, 4 }, { 3, 4, 3, 0, 1, 2, 4, 3, 4, 3, 0, 1, 2, 4, 3, 4 },
    { 1, 2, 1, 2, 3, 4, 3, 4, 0, 0, 1, 2, 1, 2, 3, 4 }, { 0, 2, 4, 1, 3, 1, 3, 2, 4, 0, 1, 2, 3, 4, 1, 2 },
    { 2, 3, 1, 2, 0, 0, 4, 4, 0, 2, 3, 1, 4, 2, 4, 3 }, { 2, 4, 2, 4, 0, 1, 3, 0, 1, 3, 2, 2, 4, 0, 1, 3 }
};

const s16 koishi_speed_x[5][8] = { { 64, -64, 128, -128, 256, -256, 384, -384 },
                                   { -256, -384, -512, -640, -768, -896, -1024, -1280 },
                                   { 384, 512, 640, 768, 896, 1024, 1152, 1408 },
                                   { -768, -896, -1024, -1152, -1280, -1408, -1536, -1664 },
                                   { 896, 1024, 1152, 1280, 1408, 1536, 1664, 2048 } };

const s16 koishi_speed_y[5][8] = { { 768, 1024, 1152, 1280, 1408, 1536, 1792, 2048 },
                                   { 640, 704, 768, 832, 896, 1024, 1280, 1536 },
                                   { 576, 640, 704, 768, 832, 896, 1152, 1408 },
                                   { 512, 576, 640, 704, 768, 896, 1024, 1152 },
                                   { 512, 448, 512, 576, 640, 704, 896, 1024 } };

void effect_I0_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2020;
        set_char_move_init(&ewk->wu, 0, char_of_koishi[random_16() & 7]);
        /* fallthrough */
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] += 1;
            return;
        }

        if ((EXE_flag == 0) && (Game_pause == 0)) {
            switch (ewk->wu.routine_no[1]) {
            case 0:
                add_mvxy_speed(&ewk->wu);
                cal_mvxy_speed(&ewk->wu);
                if (ewk->wu.mvxy.a[1].sp <= 0) {
                    ewk->wu.routine_no[1] += 1;
                }
                char_move(&ewk->wu);
                break;

            case 1:
                add_mvxy_speed(&ewk->wu);
                cal_mvxy_speed(&ewk->wu);
                if (ewk->wu.xyz[1].disp.pos <= ewk->wu.next_y) {
                    ewk->wu.routine_no[1] += 1;
                    char_move_wca(&ewk->wu);
                } else {
                default:
                    char_move(&ewk->wu);
                    if (ewk->wu.cg_type == 0xFF) {
                        ewk->wu.disp_flag = 0;
                        ewk->wu.routine_no[0] += 1;
                    }
                }
                break;
            }
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request8(&ewk->wu);
        return;

    case 2:
        ewk->wu.routine_no[0] = 3;
        return;

    default:
        push_effect_work(&ewk->wu);
        return;
    }
}

s32 effect_I0_init(WORK* wk, s16 hsx, s16 hsy, s16 spx, s16 spy, s16 nxy) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xB4;
    ewk->wu.work_id = 0x10;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.cgromtype = 1;
    ewk->wu.next_y = nxy;
    ewk->wu.mvxy.a[0].sp = spx << 8;
    ewk->wu.mvxy.d[0].sp = 0;
    ewk->wu.mvxy.a[1].sp = spy << 8;
    ewk->wu.mvxy.d[1].sp = -0x8000U;

    if (ewk->wu.rl_flag) {
        ewk->wu.xyz[0].disp.pos = wk->position_x - hsx;
    } else {
        ewk->wu.xyz[0].disp.pos = wk->position_x + hsx;
    }

    ewk->wu.xyz[1].disp.pos = wk->position_y + hsy;
    ewk->wu.position_z = wk->position_z + 1;
    ewk->wu.char_table[0] = _plef_char_table;
    return 0;
}

s32 setup_koishi_extra(WORK* wk, u8 num) {
    s16* dix;
    s16 i;
    s16 hsx;
    s16 hsy;
    s16 spx;
    s16 spy;
    s16 nxy;
    dix = (s16*)koishi_app_area[random_16() & 7];

    for (i = 0; i < num_of_koishi[num]; i++) {
        hsx = (koishi_area_hosei[dix[i]] + (random_16() - 7));
        hsy = -(random_16() & 3);
        nxy = (hsy - (random_16() & 3));
        spx = koishi_speed_x[dix[i]][random_16() & 7];
        spy = koishi_speed_y[dix[i]][random_16() & 7];
        effect_I0_init(wk, hsx, hsy, spx, spy, nxy);
    }

    return 0;
}

void xb_effect_I0_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request8(&ewk->wu);
        break;
    }
}
