/* end_1.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_100_move 0xBFE6D size 0x3D.
 * end_01000 0xBFEAA size 0xB7.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: end_100_0000,
 * end_100_0001, end_100_0002, end_100_0004.
 * BGM_Request is folded into 0x98407.
 * Data: timer_1_tbl is 0x2862F8, 0xA bytes compared.
 * Data: end_1_pos is 0x286304, 0x14 bytes compared.
 * Globals: timer_1_tbl 0x2862F8, end_w 0x7AABF0, bgw_ptr 0x7BC510, bg_w
 * 0x7BC520.
 */

#include "structs.h"

void sub_00098407(s16 Code);
extern END_W end_w;
void common_end_init00(s16 pl_num);
void common_end_init01();
void fadeout_to_staff_roll();
void end_scn_pos_set2();
void end_bg_pos_hosei2();
void end_fam_set2();
extern BG bg_w;
void end_100_move();
void end_100_0000();
void end_100_0001();
void end_100_0002();
void end_100_0004();
extern BGW* bgw_ptr;

const s16 timer_1_tbl[5] = { 1200, 900, 1260, 240, 360 };

const s16 end_1_pos[5][2] = { { 256, 768 }, { 256, 512 }, { 768, 512 }, { 256, 256 }, { 768, 240 } };

void end_01000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        end_w.timer = timer_1_tbl[end_w.r_no_2];
        common_end_init01();
        sub_00098407(0x31);
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 >= 5) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                break;
            }

            end_w.timer = timer_1_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }

        end_100_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_100_move() {
    void (*end_100_jp[5])() = { end_100_0000, end_100_0001, end_100_0002, end_100_0002, end_100_0004 };
    bgw_ptr = &bg_w.bgw[0];
    end_100_jp[end_w.r_no_2]();
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void end_100_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_1_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_1_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = 0;
        Bg_On_W(1);
        effect_E6_init(0xA1);
        Rewrite_End_Message(1);
        bgw_ptr->free = 0x46;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free < 1) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        bgw_ptr->xy[0].cal += 0x8000;

        if (384 < bgw_ptr->xy[0].disp.pos) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1800000;
            bgw_ptr->free = 0x5A;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 3:
        bgw_ptr->free--;

        if (bgw_ptr->free < 1) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 4:
        if (Request_Fade(3)) {
            bgw_ptr->r_no_1++;
            end_no_cut = 1;
        }

        break;

    case 5:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            bgw_ptr->free = 0x28;
            overwrite_panel(0xFFFFFFFF, 0x17);
        }

        break;

    case 6:
        overwrite_panel(0xFFFFFFFF, 0x17);
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
            end_w.timer = 0;
        }
    }
}

void end_100_0001() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        overwrite_panel(0xFFFFFFFF, 0x17);
        if (Request_Fade(2)) {
            bgw_ptr->r_no_1 += 1;
            end_no_cut = 1;
            bgw_ptr->xy[0].disp.pos = end_1_pos[end_w.r_no_2][0];
            bgw_ptr->xy[1].disp.pos = end_1_pos[end_w.r_no_2][1];
            bgw_ptr->abs_x = 512;
            effect_E6_init(0xA3);
            Rewrite_End_Message(2);
        }

        break;

    case 1:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1 += 1;
            end_no_cut = 0;
        }

        break;

    case 2:
        break;
    }
}

void end_100_0002() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_1_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_1_pos[end_w.r_no_2][1];

        switch (end_w.r_no_2) {
        case 2:
            effect_E6_init(0xA4U);
            Rewrite_End_Message(3U);
            break;

        case 3:
            Rewrite_End_Message(4U);
            break;
        }

        break;

    case 1:
        break;
    }
}

void end_100_0004() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1 += 1;
        bgw_ptr->xy[0].disp.pos = end_1_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_1_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0xA6);
        Rewrite_End_Message(5);
        end_fade_flag = 1;
        end_fade_timer = timer_1_tbl[end_w.r_no_2] - 120;
        bgw_ptr->speed_y = 0x4000;
        break;

    case 1:
        bgw_ptr->xy[1].cal += bgw_ptr->speed_y;

        if ((bgw_ptr->xy[1].disp.pos) > 272) {
            bgw_ptr->r_no_1++;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        /* fallthrough */

    case 2:
        break;
    }
}
#endif
