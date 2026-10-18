/* EFF58.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_58_init 0x3E138 size 0x5A.
 * SF33rd_Logo 0x3E192 size 0xAE.
 * EFF58_Type_01 0x3E240 size 0x43.
 * Fade_In_58_Sub 0x3E283 size 0xAA.
 * effect_58_move 0x3E32D size 0x2E0. FLAG: x86-only constants -0x7bfffc1b;
 * x86-only offsets -0x1c.
 * BGM_Request is folded into 0x98407.
 * Globals: Cover_Timer 0x7A81F4, Suicide 0x7A8268, Disappear_LOGO 0x7A8429,
 * Demo_Flag 0x7A842D, Next_Step 0x7A86D2, Offset_BG_X 0x7A87B0, Cut_Scroll
 * 0x7A88FE, bg_mvxy 0x7BC4C0, bg_w 0x7BC520, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_00098407(s16 Code);
extern BG bg_w;
extern s16 Target_BG_X[6];
extern s16 Offset_BG_X[6];
extern s8 Next_Step;
void EFF58_Type_01(WORK_Other* ewk);
void Fade_In_58_Sub(WORK_Other* ewk);
extern s8 Demo_Flag;
void SsRequest(u16 ReqNumber);
extern s8 PB_Music_Off;
void SsBgmFadeIn(u16 ReqNumber, u16 FadeSpeed);
void SF3_logo(u8 step);
s32 SF33rd_Logo(WORK_Other* ewk);
extern s8 Cut_Scroll;
s32 Cut_Cut_Sub(s16 xx);
extern MVXY bg_mvxy;
extern s8 Suicide[8];
void Setup_BG(s16 BG_INDEX, s16 X, s16 Y);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u8 Disappear_LOGO;
s32 sort_push_request4(WORK* wk);
s32 Switch_Screen(u8 Wipe_Type);
extern s8 Cover_Timer;
void Switch_Screen_Init(s32 );
s32 Switch_Screen_Revival(u8 Wipe_Type);
void ToneDown(u8 tone, u8 priority);



void effect_58_move(WORK_Other* ewk) {
    s16 xx;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[0]++;
        }

        break;

    case 1:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            bg_w.bgw[ewk->wu.direction].wxy[0].cal += bg_w.bgw[ewk->wu.direction].speed_x;

            if (0 < bg_w.bgw[ewk->wu.direction].speed_x) {
                if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] <=
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                    Next_Step |= 1;
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                        Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                    ewk->wu.routine_no[0]++;
                }
            } else if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] >=
                       bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                Next_Step |= 1;
                bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                    Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                ewk->wu.routine_no[0]++;
            }
            break;

        case 1:
            EFF58_Type_01(ewk);
            break;

        case 4:
            Fade_In_58_Sub(ewk);
            break;

        case 6:
            if (Demo_Flag != 0) {
                SsRequest(ewk->wu.direction);
            }

            ewk->wu.routine_no[0]++;
            break;

        case 7:
            Next_Step = 1;
            ewk->wu.routine_no[0]++;
            break;

        case 8:
            if (Demo_Flag != 0 && PB_Music_Off == 0) {
                sub_00098407(ewk->wu.direction);
            }

            ewk->wu.routine_no[0]++;
            break;

        case 9:
            if (Demo_Flag != 0 && PB_Music_Off == 0) {
                SsBgmFadeIn(ewk->wu.direction, 0x222);
            }

            ewk->wu.routine_no[0]++;
            break;

        case 10:
            SF3_logo(SF33rd_Logo(ewk));
            break;

        case 12:
            if (Cut_Scroll == 0) {
                xx = 3;
            } else {
                xx = Cut_Cut_Sub(3);
            }

            bg_w.bgw[ewk->wu.direction].wxy[0].cal += bg_mvxy.a[0].sp * xx;
            bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;

            if (0 < bg_mvxy.a[0].sp) {
                if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] <=
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                    Next_Step |= 1;
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                        Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                    ewk->wu.routine_no[0]++;
                }
            } else if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] >=
                       bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                Next_Step |= 1;
                bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                    Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                ewk->wu.routine_no[0]++;
            }

            break;

        case 13:
            if (Cut_Scroll == 0) {
                xx = 5;
            } else {
                xx = Cut_Cut_Sub(5);
            }

            bg_w.bgw[ewk->wu.direction].wxy[0].cal += bg_mvxy.a[0].sp * xx;
            bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;

            if (0 < bg_mvxy.a[0].sp) {
                if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] <=
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                    Next_Step |= 1;
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                        Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                    ewk->wu.routine_no[0]++;
                }
            } else if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] >=
                       bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                Next_Step |= 1;
                bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                    Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                ewk->wu.routine_no[0]++;
            }

            break;

        case 14:
            bg_w.bgw[ewk->wu.direction].wxy[0].cal += bg_mvxy.a[0].sp;
            bg_mvxy.a[0].sp += bg_mvxy.d[0].sp;

            if (0 < bg_mvxy.a[0].sp) {
                if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] <=
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                    Next_Step |= 1;
                    bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                        Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                    ewk->wu.routine_no[0]++;
                }
            } else if (Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction] >=
                       bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos) {
                Next_Step |= 1;
                bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos =
                    Target_BG_X[ewk->wu.direction] + Offset_BG_X[ewk->wu.direction];
                ewk->wu.routine_no[0]++;
            }

            break;

        case 15:
            Suicide[ewk->wu.direction] = 1;
            ewk->wu.routine_no[0]++;
            break;

        case 16:
            bg_w.bgw[ewk->wu.direction].wxy[1].disp.pos += 256;
            Setup_BG(ewk->wu.direction,
                     bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos,
                     bg_w.bgw[ewk->wu.direction].wxy[1].disp.pos);
            ewk->wu.routine_no[0]++;
            break;

        case 17:
            bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos += 512;
            Setup_BG(ewk->wu.direction,
                     bg_w.bgw[ewk->wu.direction].wxy[0].disp.pos,
                     bg_w.bgw[ewk->wu.direction].wxy[1].disp.pos);
            ewk->wu.routine_no[0]++;
            break;

        case 18:
            Setup_BG(2, 0x480, 0);
            ewk->wu.routine_no[0]++;
            break;
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_58_init(s16 id, s16 time0, s16 option) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 58;
    ewk->wu.work_id = 16;
    ewk->wu.dir_timer = time0;
    ewk->wu.dir_old = time0;
    ewk->wu.direction = option;
    ewk->wu.routine_no[1] = id;
    return 0;
}

s32 SF33rd_Logo(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.dir_timer = 1;
        Disappear_LOGO = 0;
        /* fallthrough */

    case 1:
        if (--ewk->wu.dir_timer != 0) {
            break;
        }

        ewk->wu.dir_timer = 2;
        ewk->wu.direction++;

        if (ewk->wu.direction >= 8) {
            ewk->wu.direction = 8;
            ewk->wu.routine_no[2]++;
        }

        break;

    case 2:
        if (Disappear_LOGO) {
            ewk->wu.routine_no[2]++;
            ewk->wu.dir_timer = 1;
        }

        break;

    default:
        if (--ewk->wu.dir_timer != 0) {
            break;
        }

        ewk->wu.dir_timer = 2;
        ewk->wu.direction++;

        if (ewk->wu.direction > 16) {
            ewk->wu.direction = 16;
            sort_push_request4(&ewk->wu);
        }

        break;
    }

    return ewk->wu.direction;
}

void EFF58_Type_01(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        Switch_Screen(1);

        if (!--Cover_Timer) {
            ewk->wu.routine_no[2]++;
            Switch_Screen_Init(1);
        }

        break;

    case 1:
        if (Switch_Screen_Revival(1)) {
            ewk->wu.routine_no[0] = 99;
        }

        break;
    }
}

void Fade_In_58_Sub(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        ewk->wu.routine_no[2]++;
        ewk->wu.dir_timer = 10;
        ewk->wu.dir_old = 0xFF;
        /* fallthrough */

    case 1:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.routine_no[2]++;
            ewk->wu.dir_timer = 4;
        }

        ToneDown(ewk->wu.dir_old, ewk->wu.direction);
        break;

    default:
        if (ewk->wu.dir_old < 0) {
            ewk->wu.dir_old = 0;
            ewk->wu.routine_no[0]++;
        }

        ToneDown(ewk->wu.dir_old, ewk->wu.direction);

        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.dir_old -= 16;
            ewk->wu.dir_timer = 4;
        }

        break;
    }
}
