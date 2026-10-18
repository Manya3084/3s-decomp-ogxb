/* end_13.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_d00_1000 0xC128D size 0x9F.
 * end_d00_3000 0xC132C size 0xB0.
 * end_d00_4000 0xC13DC size 0xC8.
 * end_d00_6000 0xC14A4 size 0x12C.
 * end_d00_7000 0xC15D0 size 0x86.
 * end_d01_4000 0xC1656 size 0x40.
 * end_d00_move 0xC1696 size 0x4E.
 * end_d01_move 0xC16E4 size 0x3E.
 * end_13000 0xC1722 size 0xDA.
 * end_d00_2000 is folded into 0xC0E5C with 1 other bodies. Unnamed.
 * BGM_Request is folded into 0x98407.
 * Bg_Off_W is folded into 0xAF4C2.
 * Bg_On_W is folded into 0xAF4AA.
 * Data: timer_d_tbl is 0x2863D8, 0x10 bytes compared.
 * Data: end_d_pos is 0x2863E8, 0x20 bytes compared.
 * Globals: timer_d_tbl 0x2863D8, end_d_pos 0x2863E8, end_w 0x7AABF0,
 * end_no_cut 0x7AABFE, end_fade_timer 0x7AAC00, end_etc_flag 0x7AAC03,
 * end_fade_flag 0x7AAC08, bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

void sub_00098407(s16 Code);
void sub_000AF4C2(u16 s_prm);
void sub_000AF4AA(u16 s_prm);
extern END_W end_w;
void common_end_init00(s16 pl_num);
void common_end_init01();
s32 effect_E6_init(u8 char_num);
void fadeout_to_staff_roll();
void end_scn_pos_set2();
void end_bg_pos_hosei2();
void end_fam_set2();
extern BG bg_w;
void end_d00_move();
void end_d01_move();
void end_d00_1000();
void end_d00_2000();
void end_d00_3000();
void end_d00_4000();
void end_d00_6000();
void end_d00_7000();
extern BGW* bgw_ptr;
s32 Rewrite_End_Message(u16 mes_no);
s32 Request_Fade(u16 fade_code);
extern s8 end_no_cut;
s16 end_fade_complete();
void overwrite_panel(u32 color, u8 priority);
extern s8 end_etc_flag;
extern s8 end_fade_flag;
extern s16 end_fade_timer;
void end_X_com01();
void end_d01_4000();

const s16 timer_d_tbl[8] = { 120, 240, 600, 780, 600, 420, 360, 660 };

const s16 end_d_pos[8][2] = { { 256, 0 },   { 256, 768 }, { 256, 768 }, { 256, 512 },
                              { 192, 256 }, { 256, 512 }, { 256, 0 },   { 256, 0 } };

void end_13000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        end_w.timer = timer_d_tbl[end_w.r_no_2];
        common_end_init01();
        sub_00098407(0x32);
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 == 1) {
                effect_E6_init(0x32);
                effect_E6_init(0x33);
            }

            if (end_w.r_no_2 >= 8) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                break;
            }

            end_w.timer = timer_d_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }

        end_d00_move();
        end_d01_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_d00_move() {
    void (*end_d00_jp[8])() = { end_d00_1000, end_d00_1000, end_d00_2000, end_d00_3000,
                                end_d00_4000, end_d00_1000, end_d00_6000, end_d00_7000 };
    bgw_ptr = &bg_w.bgw[0];
    end_d00_jp[end_w.r_no_2]();
}

void end_d00_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1 << bgw_ptr->fam_no);
        bgw_ptr->xy[0].disp.pos = end_d_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_d_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;

        switch (end_w.r_no_2) {
        case 0:
            break;

        case 1:
            effect_E6_init(0x34);
            break;

        case 5:
            sub_000AF4C2(1);
            Rewrite_End_Message(3);
            break;
        }

        break;

    case 1:
        break;
    }
}

void end_d00_2000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        if (Request_Fade(3)) {
            end_no_cut = 1;
            bgw_ptr->r_no_1++;
        }

        break;

    case 1:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
            end_w.timer = 20;
            overwrite_panel(0xFFFFFFFF, 0x17);
            break;
        }

        break;

    default:
        overwrite_panel(0xFFFFFFFF, 0x17);
        break;
    }
}

void end_d00_3000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        overwrite_panel(0xFFFFFFFF, 0x17);
        bgw_ptr->xy[0].disp.pos = end_d_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_d_pos[end_w.r_no_2][1];
        effect_E6_init(0x35);
        /* fallthrough */

    case 1:
        overwrite_panel(0xFFFFFFFF, 0x17);

        if (Request_Fade(2)) {
            end_no_cut = 1;
            bgw_ptr->r_no_1++;
            Rewrite_End_Message(1);
        }

        break;

    case 2:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
        }

        break;
    }
}

void end_d00_4000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1 << bgw_ptr->fam_no);
        bgw_ptr->xy[0].disp.pos = end_d_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_d_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        Rewrite_End_Message(2);
        effect_E6_init(0x36);
        effect_E6_init(0x37);
        break;

    case 1:
        bgw_ptr->xy[0].cal += 0x8000;

        if (bgw_ptr->xy[0].disp.pos > 304) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1300000;
            bgw_ptr->free = 10;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

void end_d00_6000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1 << bgw_ptr->fam_no);
        bgw_ptr->xy[0].disp.pos = end_d_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_d_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x4A);
        bgw_ptr->free = 0x3C;
        Rewrite_End_Message(0);
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            end_etc_flag = 0;
            effect_E6_init(0x4B);
            bgw_ptr->free = 0;
        }

        break;

    case 2:
        if (!end_etc_flag) {
            bgw_ptr->free++;
            bgw_ptr->free &= 1;

            if (bgw_ptr->free) {
                bgw_ptr->xy[1].disp.pos += 8;
                bgw_ptr->abs_y += 8;
                break;
            }

            bgw_ptr->xy[1].disp.pos -= 8;
            bgw_ptr->abs_y -= 8;
            break;
        }

        bgw_ptr->r_no_1++;
        end_w.timer = 30;
        break;

    case 3:
        bgw_ptr->free++;
        bgw_ptr->free &= 1;

        if (bgw_ptr->free) {
            bgw_ptr->xy[1].disp.pos += 8;
            bgw_ptr->abs_y += 8;
            break;
        }

        bgw_ptr->xy[1].disp.pos -= 8;
        bgw_ptr->abs_y -= 8;
        break;
    }
}

void end_d00_7000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_d_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_d_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        Rewrite_End_Message(4);
        end_fade_flag = 1;
        end_fade_timer = timer_d_tbl[end_w.r_no_2] - 120;
        break;

    case 1:
        break;
    }
}

void end_d01_move() {
    void (*end_d01_jp[8])() = { end_X_com01,  end_X_com01, end_X_com01, end_X_com01,
                                end_d01_4000, end_X_com01, end_X_com01, end_X_com01 };
    bgw_ptr = &bg_w.bgw[1];
    end_d01_jp[end_w.r_no_2]();
}

void end_d01_4000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos = 0;
        break;

    case 1:
        break;
    }
}
