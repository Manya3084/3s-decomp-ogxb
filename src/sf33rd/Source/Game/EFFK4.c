/* EFFK4.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * get_init_position_effK4 0x4FEAB size 0x4E.
 * get_init_speed_and_timer_effK4 0x4FEF9 size 0xD7.
 * effect_K4_move 0x4FFD0 size 0xFD.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: setup_effK4.
 * Data: effK4_isp_table is 0x25A808, 0x40 bytes compared, found by the bytes.
 * Data: effK4_isp_x_hosei is 0x25A848, 0x40 bytes compared, found by the
 * bytes.
 * Data: effK4_isp_y_hosei is 0x25A888, 0x40 bytes compared, found by the
 * bytes.
 * Data: effK4_life_time is 0x25A8C8, 0x8 bytes compared, found by the bytes.
 * Data: effK4_char_sel_table is 0x25A8D0, 0x80 bytes compared.
 * Unnamed data used (not a difference): get_init_speed_and_timer_effK4:
 * 0x43cf74.
 * Globals: effK4_isp_table 0x25A808, effK4_isp_x_hosei 0x25A848,
 * effK4_isp_y_hosei 0x25A888, effK4_life_time 0x25A8C8, effK4_char_sel_table
 * 0x25A8D0, Suicide 0x7A8268, Game_pause 0x7A89B0, EXE_flag 0xC7C834.
 */

#include "structs.h"

void get_init_position_effK4(WORK* wk);
void get_init_speed_and_timer_effK4(WORK* wk);
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

const s16 effK4_isp_table[4][4][2] = { { { -512, 768 }, { -768, 768 }, { 512, 768 }, { 768, 768 } },
                                       { { -1024, 1024 }, { -1280, 1024 }, { 1024, 1024 }, { 1280, 1024 } },
                                       { { -1280, 1280 }, { -1792, 1280 }, { 1280, 1280 }, { 1792, 1280 } },
                                       { { -1536, 1536 }, { -2048, 1536 }, { 1536, 1536 }, { 2048, 1536 } } };

const s16 effK4_isp_x_hosei[4][8] = { { 0, 128, 256, 384, -128, -256, -384, -512 },
                                      { 0, 128, 256, 384, -128, -256, -512, -768 },
                                      { 0, 256, 384, 512, -256, -512, -768, -1024 },
                                      { 0, 256, 512, -256, -512, -768, -1024, -1280 } };

const s16 effK4_isp_y_hosei[4][8] = { { 0, 0, 128, 128, 256, 256, 384, -128 },
                                      { 0, 128, 128, 256, 256, 384, 384, -256 },
                                      { 0, 128, 256, 384, 512, -128, -256, -512 },
                                      { 0, 256, 384, 512, 640, -256, -512, -768 } };

const s16 effK4_life_time[4] = { 24, 24, 24, 24 };

const s16 effK4_char_sel_table[4][16] = {
    { 132, 132, 132, 132, 133, 133, 133, 133, 134, 134, 134, 134, 135, 135, 135, 135 },
    { 136, 136, 136, 137, 137, 137, 138, 138, 138, 139, 139, 139, 132, 132, 133, 134 },
    { 140, 140, 132, 132, 136, 136, 141, 141, 141, 142, 142, 142, 143, 143, 143, 137 },
    { 140, 140, 140, 136, 136, 136, 132, 132, 132, 140, 136, 132, 134, 142, 143, 140 }
};

void effect_K4_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.blink_timing = ewk->master_id;
        get_init_position_effK4(&ewk->wu);
        get_init_speed_and_timer_effK4(&ewk->wu);
        ewk->wu.position_z = 24;
        set_char_move_init(&ewk->wu, 0, effK4_char_sel_table[ewk->wu.dm_attlv][random_16()]);
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

void get_init_position_effK4(WORK* wk) {
    s16 xhs;

    wk->xyz[0].disp.pos = wk->hit_mark_x;
    wk->xyz[1].disp.pos = wk->hit_mark_y;
    xhs = 32 - (random_32() * 2);
    wk->xyz[0].disp.pos += xhs;
    wk->xyz[1].disp.pos += 8 - random_16();
    wk->position_z = 24;
    wk->type = (xhs < 0) * 2;
}

void get_init_speed_and_timer_effK4(WORK* wk) {
    s16 data[4];
    s16 ix;

    ix = wk->type + (random_16() & 1);
    data[0] = effK4_isp_table[wk->dm_attlv][ix][0];
    data[2] = effK4_isp_table[wk->dm_attlv][ix][1];
    data[1] = 0;
    data[3] = -96;
    ix = random_16() & 7;
    data[0] += effK4_isp_x_hosei[wk->dm_attlv][ix];
    ix = random_16() & 7;
    data[2] += effK4_isp_y_hosei[wk->dm_attlv][ix];
    setup_move_data_easy(wk, &data[0], 1, 0);
    wk->kage_prio = (random_16() & 7) + effK4_life_time[wk->dm_attlv];
    wk->kage_hy = wk->kage_prio / 2;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void setup_effK4(WORK* wk) {
    WORK* twk;
    s16 i;
    s16 j;

    (void)wk;
    (void)twk;
    (void)i;
    (void)j;
}
#endif
