/* end_9.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_900_0000 0xC702E size 0xD7.
 * end_900_5000 0xC7105 size 0xF6.
 * end_900_move 0xC71FB size 0x38.
 * end_09000 0xC7233 size 0xB7.
 * BGM_Request is folded into 0x98407.
 * Bg_On_W is folded into 0xAF4AA.
 * Data: timer_9_tbl is 0x2868A4, 0xC bytes compared.
 * Data: end_9_pos is 0x2868B0, 0x18 bytes compared.
 * Globals: timer_9_tbl 0x2868A4, end_9_pos 0x2868B0, end_w 0x7AABF0,
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
void end_900_move();
void end_900_0000();
void end_900_5000();
extern BGW* bgw_ptr;
s32 effect_E6_init(u8 char_num);
s32 Rewrite_End_Message(u16 mes_no);
extern s8 end_fade_flag;
extern s16 end_fade_timer;

const s16 timer_9_tbl[6] = { 300, 480, 120, 540, 780, 600 };

const s16 end_9_pos[6][2] = { { 256, 512 }, { 256, 768 }, { 256, 336 }, { 256, 0 }, { 256, 768 }, { 256, 512 } };

void end_09000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_9_tbl[end_w.r_no_2];
        sub_00098407(0x32);
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 == 6) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                break;
            }

            end_w.timer = timer_9_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }

        end_900_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_900_move() {
    void (*end_900_jp[6])() = { end_900_0000, end_900_0000, end_900_0000, end_900_0000, end_900_0000, end_900_5000 };
    bgw_ptr = &bg_w.bgw[0];
    end_900_jp[end_w.r_no_2]();
}

void end_900_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_9_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_9_pos[end_w.r_no_2][1];

        switch (end_w.r_no_2) {
        case 0:
            sub_000AF4AA(1);
            bgw_ptr->abs_x = 512;
            bgw_ptr->abs_y = 0;
            effect_E6_init(0x24);
            Rewrite_End_Message(1);
            break;

        case 1:
            Rewrite_End_Message(2);
            effect_E6_init(0x25);
            break;

        case 2:
            Rewrite_End_Message(3);
            break;

        case 3:
            effect_E6_init(0x26);
            effect_E6_init(0x27);
            effect_E6_init(0x28);
            effect_E6_init(0x29);
            Rewrite_End_Message(4);
            break;

        case 4:
            Rewrite_End_Message(5);
            effect_E6_init(0x25);
            break;
        }

        break;

    case 1:
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 337 -> <= 336. */
void end_900_5000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        effect_E6_init(0x2A);
        bgw_ptr->free = 0x1E;
        bgw_ptr->xy[0].disp.pos = end_9_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_9_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Rewrite_End_Message(6);
        end_fade_flag = 1;
        end_fade_timer = timer_9_tbl[end_w.r_no_2] - 120;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        bgw_ptr->xy[1].cal -= 0x8000;

        if (bgw_ptr->xy[1].disp.pos <= 336) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1500000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 3:
        break;
    }
}
