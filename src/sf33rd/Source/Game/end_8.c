/* end_8.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_8000_0000 0xC6D48 size 0xA9.
 * end_8000_0001 0xC6DF1 size 0xA6.
 * end_8000_0002 0xC6E97 size 0xB1.
 * end_800_move 0xC6F48 size 0x36.
 * end_08000 0xC6F7E size 0xB0.
 * BGM_Request is folded into 0x98407.
 * Bg_On_W is folded into 0xAF4AA.
 * Data: timer_8_tbl is 0x28688C, 0x8 bytes compared.
 * Data: end_8_pos is 0x286894, 0x10 bytes compared.
 * Globals: timer_8_tbl 0x28688C, end_8_pos 0x286894, end_w 0x7AABF0,
 * end_fade_timer 0x7AAC00, end_fade_flag 0x7AAC08, bgw_ptr 0x7BC510, bg_w
 * 0x7BC520.
 */

#include "structs.h"

void sub_00098407(s16 Code);
void sub_000AF4AA(u16 s_prm);
extern END_W end_w;
void common_end_init00(s16 pl_num);
void common_end_init01();
void fadeout_to_staff_roll();
void end_scn_pos_set2();
void end_bg_pos_hosei2();
void end_fam_set2();
extern BG bg_w;
void end_800_move();
void end_8000_0000();
void end_8000_0001();
void end_8000_0002();
extern BGW* bgw_ptr;
s32 effect_E6_init(u8 char_num);
s32 Rewrite_End_Message(u16 mes_no);
extern s8 end_fade_flag;
extern s16 end_fade_timer;

const s16 timer_8_tbl[4] = { 840, 480, 900, 360 };

const s16 end_8_pos[4][2] = { { 256, 768 }, { 256, 512 }, { 256, 0 }, { 768, 512 } };

/* The Xbox returns where the PS2 breaks out of the switch. */
void end_08000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        sub_00098407(0x31);
        end_w.timer = timer_8_tbl[end_w.r_no_2];
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if ((end_w.r_no_2) == 4) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }

            end_w.timer = timer_8_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
        }

        end_800_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_800_move() {
    void (*end_800_jp[4])() = { end_8000_0000, end_8000_0001, end_8000_0002, end_8000_0002 };
    bgw_ptr = &bg_w.bgw[0];
    end_800_jp[end_w.r_no_2]();
}

void end_8000_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1);
        effect_E6_init(0x46);
        bgw_ptr->xy[0].disp.pos = end_8_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_8_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        Rewrite_End_Message(1);
        break;

    case 1:
        bgw_ptr->xy[0].cal += 0x8000;

        if (bgw_ptr->xy[0].disp.pos > 448) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1C00000;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

void end_8000_0001() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_8_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_8_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Rewrite_End_Message(2);
        break;

    case 1:
        bgw_ptr->xy[1].cal -= 0x8000;

        if (bgw_ptr->xy[1].disp.pos < 416) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].disp.pos = 416;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 2:
        break;
    }
}

void end_8000_0002() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_8_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_8_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;

        switch (end_w.r_no_2) {
        case 2:
            Rewrite_End_Message(3);
            break;

        case 3:
            effect_E6_init(0x47);
            effect_E6_init(0x48);
            end_fade_flag = 1;
            end_fade_timer = timer_8_tbl[end_w.r_no_2] - 120;
            Rewrite_End_Message(4);
            break;
        }

    case 1:
        break;
    }
}
