/* Staff roll, retail sf33rd.xbe.
 * check_shortcut is 0xEE649 size 0x2B. set_credit_string is 0xEE674
 * size 0x56. staff_credits is 0xEE6CA size 0x4D2.
 * staff_r_no is 0x7AAC02. end_no_cut is 0x7AABFE. WINNER is 0x7A89BD.
 * end_w is 0x7AABF0 and timer is +0xA. roll_rate_t2 is 0x7A99F4.
 * roll_rate2 is 0x7A99F6. roll_stop is 0x7A99F8. name_timer is 0x7A99FA.
 * name_ptr is 0x79689C. staffroll_end is 0x7968A0. sf3_staff is 0x2AF008,
 * 243 rows of 0xC. p1sw_0 is 0x7C557C. p2sw_0 is 0x7C5B90.
 * bg_w is 0x7BC520. bgw[5] is 0x7BC828. pos_offset is 0x7BC53C.
 * Row 199, YOSHIKI OKAMOTO, waits 120. Row 200 is "Xbox STAFF" and waits
 * 100. Row 236, AND CAPCOM ALL STAFF, waits 150. The other rows match.
 * BGM_Request is folded into 0x98407. effect_H6_init is 0x4C7BA.
 * Family_Set_R stays Family_Set_W. Family_Set_W has the same body.
 * check_shortcut, set_credit_string, and staff_credits are interior.
 */

#include "types.h"

#include <string.h>

typedef union {
    s32 cal;
    struct {
        s16 low;
        s16 pos;
    } disp;
} XY;

typedef struct {
    u8 raw0[2];
    s16 fam_no;
    u8 raw1[6];
    s16 position_x;
    s16 position_y;
    u8 raw2[0xA];
    XY xy[2];
    XY wxy[2];
    u8 raw3[0xC];
    s32 zuubun;
    u8 raw4[0x10];
    s16 pos_x_work;
    s16 pos_y_work;
    s8 rewrite_flag;
    u8 raw5[3];
    XY hos_xy[2];
    u8 raw6[8];
    s16 free;
    s16 frame_deff;
    s16 r_limit;
    u8 raw7[2];
    s16 l_limit;
    u8 raw8[0x26];
} BGW;

typedef struct {
    u8 raw0[0x10];
    u8 scno;
    u8 raw1[8];
    s8 chase_flag;
    u8 raw2[2];
    s16 pos_offset;
    s16 quake_x_index;
    u8 raw3[0x18];
    BGW bgw[7];
} BG;

typedef struct {
    s16 r_no_0;
    s16 r_no_1;
    s16 r_no_2;
    s16 type;
    s16 end_flag;
    s16 timer;
} END_W;

typedef struct {
    s16 next;
    u16 x;
    u16 y;
    u16 atr;
    s8 *name;
} StaffRow;

#if defined(__i386__)
_Static_assert(sizeof(XY) == 4, "XY");
_Static_assert(__builtin_offsetof(XY, disp.pos) == 2, "XY.disp.pos");
_Static_assert(sizeof(BGW) == 0x90, "BGW");
_Static_assert(__builtin_offsetof(BGW, position_x) == 0xA, "position_x");
_Static_assert(__builtin_offsetof(BGW, position_y) == 0xC, "position_y");
_Static_assert(__builtin_offsetof(BGW, xy) == 0x18, "xy");
_Static_assert(__builtin_offsetof(BGW, wxy) == 0x20, "wxy");
_Static_assert(__builtin_offsetof(BG, pos_offset) == 0x1C, "pos_offset");
_Static_assert(__builtin_offsetof(BG, bgw) == 0x38, "bgw");
_Static_assert(sizeof(END_W) == 0xC, "END_W");
_Static_assert(__builtin_offsetof(END_W, timer) == 0xA, "timer");
_Static_assert(sizeof(StaffRow) == 0xC, "StaffRow");
_Static_assert(__builtin_offsetof(StaffRow, name) == 8, "name");
#endif

extern s16 roll_rate2;
extern s16 roll_rate_t2;
extern s16 roll_stop;
extern s16 name_timer;
extern s32 staffroll_end;
extern s16 name_ptr;
extern const StaffRow sf3_staff[243];
extern s8 end_no_cut;
extern s8 WINNER;
extern s8 staff_r_no;
extern END_W end_w;
extern BG bg_w;
extern u16 p1sw_0;
extern u16 p2sw_0;

void Scrn_Move_Set(s8 bgnm, s16 x, s16 y);
void SsBgmFadeOut(u16 time);
void sub_00098407(s16 code);
void sub_000AF47B(s8 fmnm, s16 x, s16 y);
s32 effect_H6_init(s16 timer, s8 *str, s16 X, s16 Y, s16 Original_Color, s32 color);

static s32 check_shortcut(void) {
    u16 sw_w;

    if (!end_no_cut) {
        if (WINNER) {
            sw_w = p2sw_0;
        } else {
            sw_w = p1sw_0;
        }

        if (sw_w & 0xFF0) {
            return 1;
        }
    }

    return 0;
}

void set_credit_string(s32 t, s32 x, s32 y, s32 a, s8 *s) {
    s8 *su;
    s16 xu;
    s16 yu;
    s16 mojisuu;

    su = s;
    xu = (s16)x;
    yu = (s16)y;

    if (*su == 0x3F || *su == 0x60) {
        su++;
    }

    mojisuu = (s16)strlen((const char *)su);
    xu = (s16)(192 - ((mojisuu * 9) / 2));

    xu = (s16)(xu + (bg_w.bgw[5].xy[0].disp.pos) - 192);
    yu = (s16)(yu + bg_w.bgw[5].position_y);

    effect_H6_init((s16)t, su, xu, yu, (s16)a, -1);
}

s32 staff_credits(u32 unused) {
    s16 t;
    s16 x;
    s16 y;
    s16 a;

    (void)unused;

    switch (staff_r_no) {
    case 0:
        staff_r_no++;
        staffroll_end = 0;
        sub_00098407(0x3F);
        bg_w.bgw[5].wxy[0].cal = bg_w.bgw[5].xy[0].cal = 0x01000000;
        bg_w.bgw[5].xy[1].cal = 0;
        bg_w.bgw[5].position_x = (s16)(0x100 - bg_w.pos_offset);
        bg_w.bgw[5].position_y = 0;
        x = bg_w.bgw[5].position_x;
        y = bg_w.bgw[5].position_y;
        Scrn_Move_Set(5, x, y);
        x = (s16)(-x & 0xFFFF);
        y = (s16)((0x300 - (y & 0xFFFF)) & 0xFFFF);
        sub_000AF47B(6, x, y);
        roll_rate2 = 1;
        roll_stop = 0;
        name_ptr = 0;
        end_w.timer = 0;
        name_timer = 0;
        break;

    case 1:
        if (check_shortcut() != 0) {
            staff_r_no = 4;
            end_w.timer = 0;
        } else {
            roll_rate_t2 = 1;
        }

        if (end_w.timer >= 0) {
            end_w.timer = (s16)(end_w.timer - roll_rate_t2);
        } else {
            if (sf3_staff[name_ptr].name == 0) {
                staff_r_no = 3;
                end_w.timer = sf3_staff[name_ptr].next;
                SsBgmFadeOut(0x88);
                break;
            }

            if (*sf3_staff[name_ptr].name == 0x3F) {
                SsBgmFadeOut(0x4E);
            }

            if (*sf3_staff[name_ptr].name == 0x60) {
                sub_00098407(0x40);
            }

            name_timer = 0x7FFF;
            t = 240;
            x = (s16)sf3_staff[name_ptr].x;
            y = (s16)sf3_staff[name_ptr].y;
            a = (s16)sf3_staff[name_ptr].atr;
            set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
            end_w.timer = sf3_staff[name_ptr].next;
            name_ptr++;

            if (0 >= end_w.timer) {
                t = 240;
                x = (s16)sf3_staff[name_ptr].x;
                y = (s16)sf3_staff[name_ptr].y;
                a = (s16)sf3_staff[name_ptr].atr;
                set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
                end_w.timer = sf3_staff[name_ptr].next;
                name_ptr++;

                if (0 >= end_w.timer) {
                    t = 240;
                    x = (s16)sf3_staff[name_ptr].x;
                    y = (s16)sf3_staff[name_ptr].y;
                    a = (s16)sf3_staff[name_ptr].atr;
                    set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
                    end_w.timer = 0xF0;
                    name_ptr++;
                }
            }
        }

        if (name_timer >= 0) {
            name_timer = (s16)(name_timer - roll_rate_t2);
            break;
        }

        name_timer = sf3_staff[name_ptr].next;
        t = 20;
        x = (s16)sf3_staff[name_ptr].x;
        y = (s16)sf3_staff[name_ptr].y;
        a = (s16)sf3_staff[name_ptr].atr;
        set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
        name_ptr++;
        t = 20;
        x = (s16)sf3_staff[name_ptr].x;
        y = (s16)sf3_staff[name_ptr].y;
        a = (s16)sf3_staff[name_ptr].atr;
        set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
        name_ptr++;

        if (sf3_staff[name_ptr].next == 0) {
            t = 20;
            x = (s16)sf3_staff[name_ptr].x;
            y = (s16)sf3_staff[name_ptr].y;
            a = (s16)sf3_staff[name_ptr].atr;
            set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
            name_ptr++;
            t = 20;
            x = (s16)sf3_staff[name_ptr].x;
            y = (s16)sf3_staff[name_ptr].y;
            a = (s16)sf3_staff[name_ptr].atr;
            set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
            name_ptr++;

            if (sf3_staff[name_ptr].next == 0) {
                t = 20;
                x = (s16)sf3_staff[name_ptr].x;
                y = (s16)sf3_staff[name_ptr].y;
                a = (s16)sf3_staff[name_ptr].atr;
                set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
                name_ptr++;
                t = 20;
                x = (s16)sf3_staff[name_ptr].x;
                y = (s16)sf3_staff[name_ptr].y;
                a = (s16)sf3_staff[name_ptr].atr;
                set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
                name_ptr++;

                if (sf3_staff[name_ptr].next == 0) {
                    t = 20;
                    x = (s16)sf3_staff[name_ptr].x;
                    y = (s16)sf3_staff[name_ptr].y;
                    a = (s16)sf3_staff[name_ptr].atr;
                    set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
                    name_ptr++;
                    t = 20;
                    x = (s16)sf3_staff[name_ptr].x;
                    y = (s16)sf3_staff[name_ptr].y;
                    a = (s16)sf3_staff[name_ptr].atr;
                    set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
                    name_ptr++;

                    if (sf3_staff[name_ptr].next == 0) {
                        t = 20;
                        x = (s16)sf3_staff[name_ptr].x;
                        y = (s16)sf3_staff[name_ptr].y;
                        a = (s16)sf3_staff[name_ptr].atr;
                        set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
                        name_ptr++;
                        t = 20;
                        x = (s16)sf3_staff[name_ptr].x;
                        y = (s16)sf3_staff[name_ptr].y;
                        a = (s16)sf3_staff[name_ptr].atr;
                        set_credit_string(t, x, y, a, sf3_staff[name_ptr].name);
                        name_ptr++;
                    }
                }
            }
        }

        break;

    case 2:
    case 3:
        if (end_w.timer >= 0) {
            end_w.timer = (s16)(end_w.timer - roll_rate_t2);
        } else {
            staff_r_no++;
        }

        if (check_shortcut() != 0) {
            staff_r_no = 4;
            end_w.timer = 0;
        }

        break;

    default:
        staffroll_end = 1;
        break;
    }

    return staffroll_end;
}
