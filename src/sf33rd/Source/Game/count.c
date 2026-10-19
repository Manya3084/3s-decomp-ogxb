/* Round timer, retail sf33rd.xbe.
 * counter_write is 0xB63BF size 0xEF and is a scanned start.
 * bcounter_write is 0xB64AE size 0x70 and is interior.
 * counter_flash is 0xB651E size 0x41 and is interior.
 * bcount_cont_init is 0xB655F size 0x3E and is interior.
 * bcounter_control is 0xB659D size 0x72 and is interior.
 * bcounter_down is 0xB660F size 0x68 and is interior.
 * count_cont_init is 0xB6677 size 0xA0 and is interior.
 * counter_control is 0xB6717 size 0xD3 and is interior.
 * bcount_cont_main is 0xB67EA size 0x3D and is interior.
 * count_cont_main is 0xB6827 size 0x69 and is interior.
 *
 * Counter_hi is 0x7A8330. Counter_low is 0x7A8265.
 * math_counter_hi is 0x7AAC42. math_counter_low is 0x7AAC40.
 * mugen_flag is 0x7AAC43. counter_color is 0x7AAC41.
 * flash_timer is 0x7AAC46. flash_col is 0x7AAC44.
 * flash_r_num is 0x7AAC34. hoji_counter is 0x7AAC45.
 * round_timer is 0x7AAC38. half.l is +0 and half.h is +1.
 * These functions do not touch step.
 *
 * flash_timer_tbl is 0x2AE80C and matches 3, 1. Two zero bytes
 * at 0x2AE80E pad it. flash_color_tbl is 0x2AE810 and matches
 * 5, 6, 5, 4.
 *
 * save_w Time_Limit is +0x19. Present_Mode is 0x7A819C.
 * Allow_a_battle_f is 0x7A82B8. count_end is 0x7A842C, the byte
 * immediately before Demo_Flag. Time_Over is 0x7A8150.
 * No_Trans is 0x7BD3C9. Time_Stop is 0x7A8918. Break_Into is
 * 0x7A8802. Game_pause is 0x7A89B0. EXE_flag is 0xC7C834.
 * Bonus_Game_Flag is 0x7A8272. Demo_Time_Stop is 0x7A8A32.
 * omop_cockpit is 0x7C5C6C. omop_round_timer is 0x7C5C5C.
 *
 * count_cont_init stores half.l only on the else path.
 * bcount_cont_main and count_cont_main omit the Debug_w[24]
 * test. Their tail jumps are written as calls. sa_stop_check
 * stays sa_stop_check. 0xB6890 stays unnamed.
 */

#include "types.h"
#include "structs.h"

typedef struct {
    u8 pad[0x19];
    s8 Time_Limit;
    u8 tail[0x208 - 0x1A];
} SAVE_W;


#if defined(__i386__)
_Static_assert(sizeof(SAVE_W) == 0x208, "SAVE_W");
_Static_assert(__builtin_offsetof(SAVE_W, Time_Limit) == 0x19, "Time_Limit");
_Static_assert(sizeof(Round_Timer) == 8, "Round_Timer");
_Static_assert(__builtin_offsetof(Round_Timer, size.half.h) == 1, "half.h");
#endif

extern SAVE_W save_w[6];
extern u8 Present_Mode;
extern s8 Counter_hi;
extern s8 Counter_low;
extern s8 math_counter_hi;
extern s8 math_counter_low;
extern s8 mugen_flag;
extern u8 counter_color;
extern s8 flash_timer;
extern s8 flash_col;
extern s8 flash_r_num;
extern s8 hoji_counter;
extern Round_Timer round_timer;
extern const s8 flash_timer_tbl[2];
extern const u8 flash_color_tbl[4];
extern u8 Allow_a_battle_f;
extern u8 count_end;
extern s8 Time_Over;
extern u8 No_Trans;
extern s8 Time_Stop;
extern s8 Break_Into;
extern u8 Game_pause;
extern s16 EXE_flag;
extern s16 Bonus_Game_Flag;
extern s8 Demo_Time_Stop;
extern s16 omop_cockpit;
extern s16 omop_round_timer;

void scfont_put(u16 x, u16 y, u8 atr, u8 page, u8 cx, u8 cy, u16 priority);
void scfont_sqput(u16 x, u16 y, u8 atr, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2, u16 priority);
s32 sa_stop_check(void);
void counter_write(u8 atr);
void counter_control(void);
void counter_flash(s8 Flash_Num);
void bcounter_write(void);
void bcounter_control(void);

void count_cont_init(u8 type) {
    Counter_hi = save_w[Present_Mode].Time_Limit;

    if (Counter_hi == -1) {
        mugen_flag = 1;
        round_timer.size.half.h = 1;

        if (type == 0) {
            counter_write(4);
        }
    } else {
        mugen_flag = 0;
        hoji_counter = 60;
        Counter_low = hoji_counter;
        round_timer.size.half.h = Counter_hi;
        math_counter_hi = Counter_hi;
        math_counter_hi /= 10;
        math_counter_low = Counter_hi - (math_counter_hi * 10);

        if (type == 0) {
            counter_write(4);
        }

        round_timer.size.half.l = 0;
    }

    flash_r_num = 0;
    flash_col = 0;
    counter_color = 4;
}

void count_cont_main(void) {
    if (Bonus_Game_Flag != 0) {
        return;
    }

    if (count_end != 0) {
        counter_write(4);
        return;
    }

    if (Allow_a_battle_f == 0 || Demo_Time_Stop != 0) {
        counter_write(counter_color);
        return;
    }

    if (Break_Into != 0) {
        counter_write(counter_color);
        return;
    }

    if (sa_stop_check() != 0) {
        counter_write(counter_color);
        return;
    }

    if (mugen_flag == 1) {
        counter_write(4);
        return;
    }

    if (EXE_flag == 0 && Game_pause == 0) {
        counter_control();
        return;
    }

    counter_write(counter_color);
}

void counter_control(void) {
    if (Counter_hi == 0) {
        if (No_Trans == 0) {
            counter_write(counter_color);
        }

        return;
    }

    if (flash_r_num != 0) {
        if (Counter_hi == 10 && Counter_low == hoji_counter) {
            flash_timer = 0;
            counter_flash(1);
        } else if (Counter_hi <= 10) {
            counter_flash(1);
        } else {
            counter_flash(0);
        }
    } else if (Counter_hi == 30 && Counter_low == hoji_counter) {
        flash_r_num = 1;
        flash_timer = 0;
        counter_flash(0);
    }

    if (Counter_low != 0) {
        Counter_low -= 1;

        if (No_Trans == 0) {
            counter_write(counter_color);
        }

        return;
    }

    Counter_low = hoji_counter;
    Counter_hi -= 1;

    if (Counter_hi == 0) {
        counter_color = 4;
    }

    round_timer.size.half.h = Counter_hi;
    math_counter_hi = Counter_hi;
    math_counter_hi /= 10;
    math_counter_low = Counter_hi - (math_counter_hi * 10);

    if (No_Trans == 0) {
        counter_write(counter_color);
    }
}

void counter_write(u8 atr) {
    u8 i;

    if (omop_cockpit != 0) {
        if (omop_round_timer == 0) {
            for (i = 0; i < 4; i++) {
                scfont_sqput(i + 22, 1, 9, 2, 31, 2, 1, 3, 2);
            }
        } else if (mugen_flag == 0) {
            scfont_sqput(22, 0, atr, 2, math_counter_hi << 1, 2, 2, 4, 2);
            scfont_sqput(24, 0, atr, 2, math_counter_low << 1, 2, 2, 4, 2);
        } else {
            scfont_sqput(22, 0, 4, 2, 28, 28, 4, 4, 2);
        }

        scfont_sqput(21, 1, 9, 0, 12, 6, 1, 4, 2);
        scfont_sqput(26, 1, 137, 0, 12, 6, 1, 4, 2);
        scfont_sqput(22, 4, 9, 0, 3, 18, 4, 1, 2);
    }
}

void bcounter_write(void) {
    if (No_Trans == 0) {
        scfont_put(21, 4, 0x8F, 2, 20, 6, 2);
        scfont_sqput(22, 2, 15, 2, math_counter_hi << 1, 6, 2, 3, 2);
        scfont_sqput(24, 2, 15, 2, math_counter_low << 1, 6, 2, 3, 2);
        scfont_put(26, 4, 15, 2, 20, 6, 2);
    }
}

void counter_flash(s8 Flash_Num) {
    flash_timer--;

    if (flash_timer < 0) {
        flash_timer = flash_timer_tbl[Flash_Num];
        counter_color = flash_color_tbl[flash_col];
        flash_col++;

        if (flash_col == 4) {
            flash_col = 0;
        }
    }
}

void bcount_cont_init(void) {
    Counter_hi = 50;
    hoji_counter = 60;
    Counter_low = hoji_counter;
    round_timer.size.half.h = Counter_hi;
    math_counter_hi = 5;
    math_counter_low = 0;
    bcounter_write();
    round_timer.size.half.l = 0;
    Time_Stop = 0;
}

void bcount_cont_main(void) {
    if (Break_Into != 0 || sa_stop_check() != 0 || Time_Stop != 0 || Allow_a_battle_f == 0) {
        return;
    }

    if (EXE_flag == 0 && Game_pause == 0) {
        bcounter_control();
    }
}

void bcounter_control(void) {
    if (Counter_hi != 0) {
        if (Counter_low != 0) {
            Counter_low -= 1;
            return;
        }

        hoji_counter = 60;
        Counter_low = hoji_counter;
        Counter_hi -= 1;
        round_timer.size.half.h = Counter_hi;
        math_counter_hi = Counter_hi;
        math_counter_hi /= 10;
        math_counter_low = Counter_hi - (math_counter_hi * 10);

        if (Counter_hi == 0) {
            math_counter_hi = math_counter_low = 0;
            Allow_a_battle_f = 0;
            Time_Over = 1;
        }
    }
}

s16 bcounter_down(u8 kind) {
    if (Counter_hi == 0) {
        math_counter_hi = math_counter_low = 0;
        return 0;
    }

    Counter_hi -= 1;

    if (kind != 0) {
        Counter_hi = 0;
    }

    math_counter_hi = Counter_hi;
    math_counter_hi /= 10;
    math_counter_low = Counter_hi - (math_counter_hi * 10);

    if (Counter_hi == 0) {
        math_counter_hi = math_counter_low = 0;
    }

    return Counter_hi;
}
