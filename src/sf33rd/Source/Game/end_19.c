/* end_19.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_1900_0 0xC37B1 size 0x109.
 * end_1900_move 0xC39D1 size 0x38.
 * end_19000 0xC3A09 size 0xBE.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: end_1900_common.
 * BGM_Request is folded into 0x98407.
 * Bg_On_W is folded into 0xAF4AA.
 * Data: timer_19_tbl is 0x286614, 0xC bytes compared.
 * Data: end_19_pos is 0x286620, 0x18 bytes compared.
 * Globals: timer_19_tbl 0x286614, end_19_pos 0x286620, end_w 0x7AABF0, bgw_ptr
 * 0x7BC510, bg_w 0x7BC520.
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
void end_1900_move();
void end_1900_0();
void end_1900_common();
extern BGW* bgw_ptr;
s32 effect_E6_init(u8 char_num);
s32 Rewrite_End_Message(u16 mes_no);

const s16 timer_19_tbl[6] = { 360, 720, 660, 780, 600, 300 };

const s16 end_19_pos[6][2] = { { 512, 768 }, { 256, 512 }, { 256, 512 }, { 768, 512 }, { 256, 256 }, { 256, 256 } };

void end_19000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        sub_00098407(0x32);
        end_w.timer = timer_19_tbl[end_w.r_no_2];
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 >= 6) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                break;
            }

            end_w.timer = timer_19_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_1900_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_1900_move() {
    void (*end_1900_move_jp[6])() = { end_1900_0,      end_1900_common, end_1900_common,
                                      end_1900_common, end_1900_common, end_1900_common };
    bgw_ptr = &bg_w.bgw[0];
    end_1900_move_jp[end_w.r_no_2]();
}

void end_1900_0() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1);
        bgw_ptr->xy[0].disp.pos = end_19_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_19_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = 0;
        bgw_ptr->speed_x = 0x10000;
        effect_E6_init(0x84);
        effect_E6_init(0x85);
        effect_E6_init(0x86);
        effect_E6_init(0x87);
        Rewrite_End_Message(1);
        bgw_ptr->free = 0x28;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos < 320) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1400000;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 3:
        break;
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void end_1900_common() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_19_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_19_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;

        switch (end_w.r_no_2) {
        case 1:
            effect_E6_init(0x88);
            effect_E6_init(0x89);
            effect_E6_init(0x8A);
            effect_E6_init(0x8B);
            effect_E6_init(0x8C);
            effect_E6_init(0x8D);
            Rewrite_End_Message(2);
            break;

        case 2:
            Rewrite_End_Message(3);
            break;

        case 3:
            Rewrite_End_Message(4);
            break;

        case 4:
            effect_E6_init(0x8F);
            Rewrite_End_Message(5);
            break;

        case 5:
            effect_E6_init(0x90);
            Rewrite_End_Message(0);
            end_fade_flag = 1;
            end_fade_timer = timer_19_tbl[end_w.r_no_2] - 120;
            break;
        }

    case 1:
        break;
    }
}
#endif
