/* EFFD4.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * distance2speed 0x47A15 size 0x7F.
 * effect_D4_init 0x47A94 size 0x125.
 * effect_D4_move 0x47BB9 size 0x1C3. Read against the x86: 0x330 is
 * &wk->wu.shell_ix[0], the base of the 8-entry shell loop. The C is the PS2 C.
 * Data: sel_suikomi_tbl is 0x254590, 0xA bytes compared.
 * Data: swallow_areas_x is 0x2545A0, 0x180 bytes compared.
 * Data: swallow_areas_y is 0x254720, 0x180 bytes compared.
 * Data: swallow_speeds is 0x2548A0, 0x40 bytes compared.
 * Globals: sel_suikomi_tbl 0x254590, swallow_areas_x 0x2545A0, swallow_areas_y
 * 0x254720, swallow_speeds 0x2548A0, Bonus_Game_Flag 0x7A8272, Game_pause
 * 0x7A89B0, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

extern s16 EXE_flag;
extern u8 Game_pause;
s32 distance2speed(WORK_Other* ewk, WORK* wk, s32 dir);
extern uintptr_t frw[EFFECT_MAX][448];
void push_effect_work(WORK* wkhd);
extern s16 Bonus_Game_Flag;
s16 pull_effect_work(s16 index);
s32 effect_G3_init(WORK* wk, u8 data);

const s8 sel_suikomi_tbl[2][5] = { { 0, 0, 0, 1, 90 }, { 0, 0, 0, 255, 60 } };

const s8 swallow_areas_x[12][32] = {
    { 0, 13, 7, 4, 3, 3, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 13, 13, 7, 6, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 13, 13, 7, 6, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 13, 13, 7, 6, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 13, 13, 7, 6, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 13, 13, 7, 6, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 14, 14, 13, 12, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 14, 14, 13, 12, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 14, 14, 13, 12, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 7, 7, 7, 6, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 7, 7, 7, 6, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 7, 7, 7, 6, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0 }
};

const s8 swallow_areas_y[12][32] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

const s32 swallow_speeds[16] = { 0,       0x8000,  0x10000, 0x18000, 0x20000, 0x28000, 0x30000, 0x38000,
                                 0x40000, 0x48000, 0x50000, 0x58000, 0x60000, 0x68000, 0x70000, 0x78000 };

void effect_D4_move(WORK_Other* ewk) {
    PLW* wk = (PLW*)ewk->wu.target_adrs;
    PLW* mwk = (PLW*)ewk->my_master;
    WORK* swk;
    s32 rl;
    s32 add_x;
    s32 add_y;
    s32 i;
    s32 j;

    ewk->wu.position_x = mwk->wu.position_x;
    ewk->wu.position_y = mwk->wu.position_y;
    ewk->wu.position_z = mwk->wu.position_z;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.routine_no[0]++;
            break;
        }

        if (mwk->wu.routine_no[1] != 4) {
            ewk->wu.dir_timer = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        if (EXE_flag != 0 || Game_pause != 0) {
            break;
        }

        ewk->wu.dir_timer -= 1;

        if (ewk->wu.dir_timer <= 0) {
            ewk->wu.routine_no[0]++;
            break;
        }

        if (ewk->wu.xyz[0].cal < wk->wu.xyz[0].cal) {
            rl = 1;
        } else {
            rl = 0;
        }

        if ((ewk->wu.dmcal_d || mwk->sa_stop_flag) &&
            (!ewk->wu.dmcal_d || rl != ewk->wu.rl_flag || mwk->sa_stop_flag)) {
            break;
        }

        i = distance2speed(ewk, &wk->wu, 0);
        ewk->wu.mvxy.a[0].sp = swallow_speeds[i];
        ewk->wu.mvxy.d[0].sp = 0;
        i = distance2speed(ewk, &wk->wu, 1);
        ewk->wu.mvxy.a[1].sp = swallow_speeds[i];
        ewk->wu.mvxy.d[1].sp = 0;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;
        add_x = ewk->wu.mvxy.a[0].sp;
        add_y = -ewk->wu.mvxy.a[1].sp;

        if (ewk->wu.dmcal_m == -1) {
            add_x = -add_x;
            add_y = -add_y;
        }

        if (wk->wu.swallow_no_effect == 0) {
            if (rl) {
                wk->wu.xyz[0].cal -= add_x;
            } else {
                wk->wu.xyz[0].cal += add_x;
            }

            wk->wu.xyz[1].cal += add_y;
        }

        if (ewk->wu.dmcal_m != -1) {
            break;
        }

        for (j = 0; j < 8; j++) {
            if (wk->wu.shell_ix[j] == -1) {
                continue;
            }

            swk = (WORK*)frw[wk->wu.shell_ix[j]];

            if (!swk->be_flag) {
                continue;
            }

            if (ewk->wu.xyz[0].cal < swk->xyz[0].cal) {
                rl = 1;
            } else {
                rl = 0;
            }

            i = distance2speed(ewk, swk, 0);
            ewk->wu.mvxy.a[0].sp = swallow_speeds[i];
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
            add_x = -ewk->wu.mvxy.a[0].sp;

            if (rl) {
                swk->xyz[0].cal -= add_x;
            } else {
                swk->xyz[0].cal += add_x;
            }
        }

        break;

    case 2:
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 distance2speed(WORK_Other* ewk, WORK* wk, s32 dir) {
    s32 y = 0;
    s32 x = 0;

    if (ewk->wu.xyz[0].disp.pos < wk->xyz[0].disp.pos) {
        x = wk->xyz[0].disp.pos - ewk->wu.xyz[0].disp.pos;
    } else if (ewk->wu.xyz[0].disp.pos > wk->xyz[0].disp.pos) {
        x = ewk->wu.xyz[0].disp.pos - wk->xyz[0].disp.pos;
    }

    if (x >= 512) {
        x = 511;
    }

    x >>= 4;

    if (ewk->wu.xyz[1].disp.pos < wk->xyz[1].disp.pos) {
        y = wk->xyz[1].disp.pos - ewk->wu.xyz[1].disp.pos;
    }

    if (y >= 192) {
        y = 191;
    }

    y >>= 4;

    if (dir == 0) {
        return swallow_areas_x[y][x];
    }

    return swallow_areas_y[y][x];
}

s32 effect_D4_init(WORK* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;

    if (Bonus_Game_Flag != 0) {
        return 0;
    }

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 134;
    ewk->wu.work_id = 16;
    ewk->wu.type = data;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.cgromtype = wk->cgromtype;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->work_id;
    ewk->master_id = wk->id;
    ewk->wu.target_adrs = (u32*)wk->target_adrs;
    ewk->wu.xyz[0].disp.pos = wk->position_x;
    ewk->wu.xyz[1].disp.pos = wk->position_y;
    ewk->wu.xyz[2].disp.pos = wk->position_z;
    ewk->wu.position_x = wk->position_x;
    ewk->wu.position_y = wk->position_y;
    ewk->wu.position_z = wk->position_z;
    ewk->wu.rl_flag = wk->rl_flag + sel_suikomi_tbl[data][1] & 1;
    ewk->wu.dmcal_d = sel_suikomi_tbl[data][2];
    ewk->wu.dmcal_m = sel_suikomi_tbl[data][3];
    ewk->wu.dir_timer = sel_suikomi_tbl[data][4];
    effect_G3_init(&ewk->wu, 0);
    effect_G3_init(&ewk->wu, 1);
    return 0;
}
