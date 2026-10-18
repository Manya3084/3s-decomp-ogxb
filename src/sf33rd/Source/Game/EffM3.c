/* EffM3.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effM3_trans 0x57BD6 size 0x3F.
 * effect_M3_init 0x57C15 size 0x73.
 * xb_effect_M3_draw 0x57C88 size 0x7C. FLAG: x86-only callees effM3_trans.
 * effect_M3_move 0x57D04 size 0x17E. Read against the x86: M3_bahn_data is
 * folded into immediates (16, 10, 78, and -512 * 16 = 0xE000), and 0x3A is 60
 * - (type + 2) with the 2 folded. The C is the PS2 C.
 * Data: M3_bahn_data is 0x25C438, 0xA bytes compared.
 * Globals: Suicide 0x7A8268, Next_Step 0x7A86D2, bg_w 0x7BC520, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void effM3_trans(WORK* ewk);
extern s8 Suicide[8];
extern s8 Next_Step;
void cal_mvxy_speed(WORK* wk);
void push_effect_work(WORK* wkhd);
extern BG bg_w;
s32 sort_push_request4(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];

const s16 M3_bahn_data[5] = { 16, 10, 78, 0, -512 };

void effect_M3_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] = 1;
        ewk->wu.disp_flag = 0;
        ewk->wu.my_mts = 13;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x90;
        ewk->wu.my_family = 3;
        ewk->wu.position_z = 60 - (ewk->wu.type + 2);
        ewk->wu.dmcal_m = M3_bahn_data[0];
        ewk->wu.dmcal_d = M3_bahn_data[1];
        ewk->wu.dir_timer = M3_bahn_data[2];
        ewk->wu.old_cgnum = 0;
        break;

    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[2] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }

        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (!(Next_Step & 1)) {
                break;
            }

            ewk->wu.routine_no[1]++;
            ewk->wu.mvxy.a[0].real.h = 64;
            ewk->wu.mvxy.a[0].real.l = -1;
            ewk->wu.mvxy.d[0].real.h = -1;
            ewk->wu.mvxy.d[0].real.l = M3_bahn_data[4] * 16;
            ewk->wu.mvxy.kop[0] = 1;
            ewk->wu.my_mr_flag = 1;
            /* fallthrough */

        case 1:
            if (--ewk->wu.dir_timer >= 0) {
                break;
            }

            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            /* fallthrough */

        case 2:
            cal_mvxy_speed(&ewk->wu);
            ewk->wu.mvxy.d[0].sp = (ewk->wu.mvxy.d[0].sp * ewk->wu.dmcal_m) / ewk->wu.dmcal_d;

            if (!ewk->wu.mvxy.a[0].real.h) {
                ewk->wu.routine_no[1]++;

                if (ewk->wu.type == 0) {
                    Next_Step = 0;
                }
            }

            break;

        default:
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }

        ewk->wu.my_mr.size.x = ewk->wu.my_mr.size.y = ewk->wu.mvxy.a[0].real.h + 63;
        effM3_trans(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void effM3_trans(WORK* ewk) {
    ewk->position_x = bg_w.bgw[ewk->my_family - 1].wxy[0].disp.pos;
    ewk->position_y = bg_w.bgw[ewk->my_family - 1].wxy[1].disp.pos;
    ewk->position_x += ewk->xyz[0].disp.pos;
    ewk->position_y += ewk->xyz[1].disp.pos;
    sort_push_request4(ewk);
}

s32 effect_M3_init(WORK_Other_CONN* wk, s16 num) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 223;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.type = num;
    ewk->wu.xyz[0].disp.pos = wk->conn[num].nx;
    ewk->wu.xyz[1].disp.pos = wk->conn[num].ny + 40;
    ewk->wu.cg_number = wk->conn[num].chr;
    return 0;
}

void xb_effect_M3_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[2] != 0) {
            break;
        }

        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (!(Next_Step & 1)) {
                break;
            }

            /* fallthrough */

        case 1:
            if (ewk->wu.dir_timer >= 0) {
                break;
            }

            /* fallthrough */

        case 2:
            ewk->wu.mvxy.d[0].sp = (ewk->wu.mvxy.d[0].sp * ewk->wu.dmcal_m) / ewk->wu.dmcal_d;
            break;
        }

        ewk->wu.my_mr.size.x = ewk->wu.my_mr.size.y = ewk->wu.mvxy.a[0].real.h + 63;
        effM3_trans(&ewk->wu);
        break;
    }
}
