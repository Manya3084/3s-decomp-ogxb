/* EFFK3.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * set_init_posspeed_effK3 0x4FBA3 size 0x105. Read against the x86: -0x20 is
 * random_32() * 2 - 32 with lea, and 0x43CF74 is the /GS stack cookie. The C
 * is the PS2 C.
 * effect_K3_init 0x4FCA8 size 0xC5.
 * setup_effK3 0x4FD6D size 0x55.
 * effect_K3_move 0x4FDC2 size 0xE9.
 * Data: numof_effK3 is 0x25A728, 0x8 bytes compared.
 * Data: effK3_isp_table is 0x25A730, 0x40 bytes compared.
 * Data: effK3_isp_x_hosei is 0x25A770, 0x40 bytes compared.
 * Data: effK3_isp_y_hosei is 0x25A7B0, 0x40 bytes compared.
 * Data: effK3_life_time is 0x25A7F0, 0x8 bytes compared.
 * Globals: numof_effK3 0x25A728, effK3_isp_table 0x25A730, effK3_isp_x_hosei
 * 0x25A770, effK3_isp_y_hosei 0x25A7B0, effK3_life_time 0x25A7F0,
 * _bonus_char_table 0x30DFC0, __security_cookie 0x43CF74, Suicide 0x7A8268,
 * Game_pause 0x7A89B0, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void set_init_posspeed_effK3(WORK* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
s32 random_16();
extern s8 Suicide[8];
extern s16 EXE_flag;
extern u8 Game_pause;
void char_move(WORK* wk);
void add_mvxy_speed(WORK* wk);
void cal_mvxy_speed(WORK* wk);
s32 sort_push_request(WORK* wk);
void push_effect_work(WORK* wkhd);
s32 random_32();
void setup_move_data_easy(WORK* wk, const s16* adrs, s16 prx, s16 pry);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _bonus_char_table[];

const s16 numof_effK3[4] = { 2, 4, 6, 6 };

const s16 effK3_isp_table[4][4][2] = { { { -512, 768 }, { -1024, 512 }, { 512, 768 }, { 1024, 512 } },
                                       { { -1024, 1280 }, { -1536, 896 }, { 1024, 1280 }, { 1536, 896 } },
                                       { { -1536, 1792 }, { -2048, 1280 }, { 1536, 1792 }, { 2048, 1280 } },
                                       { { -2048, 2304 }, { -2560, 1664 }, { 2048, 2304 }, { 2560, 1664 } } };

const s16 effK3_isp_x_hosei[4][8] = { { 0, 128, 256, 384, 0, -128, -256, -384 },
                                      { 0, 128, 256, 384, -128, -384, -512, -640 },
                                      { 0, 256, 384, 512, -256, -512, -768, -1024 },
                                      { 0, 256, 512, 768, -256, -512, -768, -1024 } };

const s16 effK3_isp_y_hosei[4][8] = { { 0, 128, 256, 384, 512, 0, -128, -256 },
                                      { 0, 128, 256, 384, 512, 0, -128, -256 },
                                      { 0, 128, 128, 256, 256, 384, 384, -256 },
                                      { 0, 256, 512, 0, -256, -512, 384, -384 } };

const s16 effK3_life_time[4] = { 24, 20, 16, 12 };

void effect_K3_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.blink_timing = ewk->master_id;
        set_init_posspeed_effK3(&ewk->wu);
        ewk->wu.position_z = 24;
        set_char_move_init(&ewk->wu, 0, (random_16() & 1) + 0x71);
        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            add_mvxy_speed(&ewk->wu);
            cal_mvxy_speed(&ewk->wu);

            if (ewk->wu.kage_hy) {
                ewk->wu.kage_hy--;
            } else {
                ewk->wu.disp_flag = 2;
            }

            if (--ewk->wu.kage_prio < 0) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0] = 2;
            }
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void set_init_posspeed_effK3(WORK* wk) {
    s16 data[4];
    s16 ix;
    s16 flag;

    wk->xyz[0].disp.pos = 520;
    wk->xyz[1].disp.pos = 96;
    flag = (random_32() * 2) - 32;
    wk->xyz[0].disp.pos += flag;
    wk->xyz[1].disp.pos += random_16();

    if (flag < 0) {
        flag = 2;
    } else {
        flag = 0;
    }

    ix = random_16() & 1;
    data[0] = effK3_isp_table[wk->dm_attlv][flag + ix][0];
    data[2] = effK3_isp_table[wk->dm_attlv][flag + ix][1];
    data[1] = 0;
    data[3] = -96;
    ix = random_16() & 7;
    data[0] += effK3_isp_x_hosei[wk->dm_attlv][ix];
    ix = random_16() & 7;
    data[2] += effK3_isp_y_hosei[wk->dm_attlv][ix];
    setup_move_data_easy(wk, &data[0], 1, 0);
    wk->kage_prio = effK3_life_time[wk->dm_attlv] + (random_16() & 3);
    wk->kage_hy = wk->kage_prio / 2;
}

s32 effect_K3_init(WORK_Other* wk) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(1)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 203;
    ewk->wu.work_id = 16;
    ewk->wu.my_mts = 5;
    ewk->wu.my_family = wk->wu.my_family;
    ewk->wu.cgromtype = wk->wu.cgromtype;
    ewk->wu.my_col_mode = wk->wu.my_col_mode;
    ewk->wu.my_col_code = wk->wu.my_col_code;
    ewk->my_master = (u32*)wk;
    ewk->wu.dm_dir = wk->wu.dm_dir;
    ewk->wu.dm_attlv = wk->wu.dm_attlv;
    ewk->master_player = wk->master_player;
    ewk->master_id = wk->master_id;
    ewk->master_work_id = wk->master_work_id;
    *ewk->wu.char_table = _bonus_char_table;
    return 0;
}

s32 setup_effK3(WORK* wk) {
    s16 i;

    if (wk->type != 3) {
        return 0;
    }

    if (wk->vital_old < 3 || wk->vital_old > 4) {
        return 0;
    }

    for (i = 0; i < numof_effK3[wk->dm_attlv]; i++) {
        effect_K3_init((WORK_Other*)wk);
    }

    return 1;
}
