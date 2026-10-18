/* EFFA5.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Check_Sleep_A5 0x42F15 size 0x16.
 * effect_A5_init 0x42F2B size 0x2C.
 * effect_A5_move 0x42F57 size 0x111. Read against the x86: the word cleared
 * before the sbcd call is bcdext. bcdext is 0xCBA91C. sbcd is 0x1CF59. The C
 * is the PS2 C.
 * Globals: Time_Over 0x7A8150, Present_Mode 0x7A819C, Unit_Of_Timer 0x7A82A8,
 * Break_Into 0x7A8802, Time_Stop 0x7A8918, Select_Timer 0x7A89D1, frw
 * 0xC806A0, bcdext 0xCBA91C.
 */

#include "structs.h"

#define EFFECT_MAX 128

extern u8 Present_Mode;
extern s8 Break_Into;
extern s8 Time_Stop;
s32 Check_Sleep_A5(WORK_Other* ewk);
extern s16 Unit_Of_Timer;
extern s16 bcdext;
extern s8 Select_Timer;
u8 sbcd(u8 a, u8 b);
extern s8 Time_Over;
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];



/* The Xbox has no Debug_w test. */
void effect_A5_move(WORK_Other* ewk) {
    if (Present_Mode == 4 || Present_Mode == 5) {
        return;
    }

    if (Break_Into) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Time_Stop == 0) {
            ewk->wu.routine_no[0]++;
        }

        break;

    case 1:
        if (!Check_Sleep_A5(ewk)) {
            break;
        }

        if (--Unit_Of_Timer) {
            break;
        }

        Unit_Of_Timer = 50;
        bcdext = 0;

        if ((Select_Timer = sbcd(1, Select_Timer)) == 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 30;
        }

        break;

    case 2:
        if (!Check_Sleep_A5(ewk)) {
            break;
        }

        if (Select_Timer) {
            ewk->wu.routine_no[0] = 1;
            Unit_Of_Timer = 50;
        } else if (--ewk->wu.dir_timer == 0) {
            Time_Over = 1;
            ewk->wu.routine_no[0]++;
        }

        break;

    case 3:
        if (!Check_Sleep_A5(ewk)) {
            break;
        }

        Time_Over = 1;

        if (Select_Timer) {
            ewk->wu.routine_no[0] = 1;
            Unit_Of_Timer = 50;
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 Check_Sleep_A5(WORK_Other* ewk) {
    if (Time_Stop == 2) {
        ewk->wu.routine_no[0] = 0;
    }

    return 1;
}

s32 effect_A5_init() {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 105;
    return 0;
}
