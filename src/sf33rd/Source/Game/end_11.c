/* end_11.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_b00_0000 0xC0753 size 0x138.
 * end_b00_1000 0xC088B size 0x9D.
 * end_b00_3000 0xC0928 size 0x125.
 * end_b01_0000 0xC0A4D size 0xA6.
 * end_b01_3000 0xC0AF3 size 0xE0.
 * end_b00_move 0xC0BD3 size 0x3F.
 * end_b01_move 0xC0C12 size 0x40.
 * end_11000 0xC0C52 size 0xD0.
 * BGM_Request is folded into 0x98407.
 * Bg_Off_W is folded into 0xAF4C2.
 * Bg_On_W is folded into 0xAF4AA.
 * Data: timer_b_tbl is 0x28633C, 0xE bytes compared.
 * Data: end_b_pos is 0x28634C, 0x1C bytes compared.
 * Globals: quake_y_tbl 0x2762F8, timer_b_tbl 0x28633C, end_b_pos 0x28634C,
 * end_w 0x7AABF0, end_fade_timer 0x7AAC00, end_etc_flag 0x7AAC03,
 * end_fade_flag 0x7AAC08, bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

void sub_00098407(s16 Code);
void sub_000AF4C2(u16 s_prm);
void sub_000AF4AA(u16 s_prm);
extern END_W end_w;
void common_end_init00(s16 pl_num);
void common_end_init01();
void fadeout_to_staff_roll();
void end_scn_pos_set2();
void end_bg_pos_hosei2();
void end_fam_set2();
extern BG bg_w;
void end_b00_move();
void end_b01_move();
void end_b00_0000();
void end_b00_1000();
void end_b00_3000();
extern BGW* bgw_ptr;
s32 effect_E6_init(u8 char_num);
s32 Rewrite_End_Message(u16 mes_no);
extern s8 end_fade_flag;
extern s16 end_fade_timer;
extern s8 end_etc_flag;
extern const s8 quake_y_tbl[130];
void end_b01_0000();
void end_X_com01();
void end_b01_3000();

const s16 timer_b_tbl[7] = { 240, 480, 180, 420, 600, 1080, 720 };

const s16 end_b_pos[7][2] = { { 256, 288 }, { 256, 768 }, { 768, 288 }, { 768, 768 },
                              { 256, 512 }, { 768, 512 }, { 768, 512 } };

void end_11000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        sub_00098407(0x31);
        end_w.timer = timer_b_tbl[end_w.r_no_2];
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 >= 7) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                break;
            }

            end_w.timer = timer_b_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
        }

        if (bg_w.quake_y_index > 0) {
            bg_w.quake_y_index--;
        }

        end_b00_move();
        end_b01_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_b00_move() {
    void (*end_b00_jp[7])() = { end_b00_0000, end_b00_1000, end_b00_0000, end_b00_3000,
                                end_b00_0000, end_b00_0000, end_b00_0000 };
    bgw_ptr = &bg_w.bgw[0];
    end_b00_jp[end_w.r_no_2]();
}

void end_b00_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_b_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;

        switch (end_w.r_no_2) {
        case 0:
            sub_000AF4C2(1);
            effect_E6_init(0x60);
            Rewrite_End_Message(1);
            break;

        case 2:
            sub_000AF4C2(1);
            effect_E6_init(0x62);
            Rewrite_End_Message(0);
            break;

        case 4:
            effect_E6_init(0x65);
            effect_E6_init(0x66);
            effect_E6_init(0x67);
            effect_E6_init(0x68);
            Rewrite_End_Message(3);
            break;

        case 5:
            effect_E6_init(0x69);
            effect_E6_init(0x6A);
            effect_E6_init(0x6D);
            effect_E6_init(0x6E);
            effect_E6_init(0x6B);
            Rewrite_End_Message(4);
            break;

        case 6:
            effect_E6_init(0x6C);
            Rewrite_End_Message(5);
            end_fade_flag = 1;
            end_fade_timer = timer_b_tbl[end_w.r_no_2] - 120;
            break;
        }

        break;

    case 1:
        break;
    }
}

void end_b00_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1);
        bgw_ptr->xy[0].disp.pos = end_b_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        end_etc_flag = 0;
        effect_E6_init(0x61);
        Rewrite_End_Message(0);
        break;

    case 1:
        if (end_etc_flag) {
            bgw_ptr->r_no_1++;
            end_w.timer = 10;
        }

        /* fallthrough */

    case 2:
        break;
    }
}

void end_b00_3000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_b_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = 0;
        sub_000AF4AA(1);
        bg_w.quake_y_index = 24;
        bgw_ptr->free = 2;
        effect_E6_init(0x63);
        Rewrite_End_Message(2);
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->free = 2;

            if (bg_w.quake_y_index <= 0) {
                bgw_ptr->r_no_1++;
                bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
                bgw_ptr->abs_y = 0;
                effect_E6_init(0x64);
                break;
            }
            bgw_ptr->xy[1].disp.pos = (s16)quake_y_tbl[bg_w.quake_y_index] + end_b_pos[end_w.r_no_2][0];
            bgw_ptr->abs_y = quake_y_tbl[bg_w.quake_y_index];
        }

        break;

    case 2:
        break;
    }
}

void end_b01_move() {
    void (*end_b01_jp[7])() = { end_b01_0000, end_X_com01, end_b01_0000, end_b01_3000,
                                end_X_com01,  end_X_com01, end_X_com01 };
    bgw_ptr = &bg_w.bgw[1];
    end_b01_jp[end_w.r_no_2]();
}

/* Rewritten to match retail (tools/permute.py): < 33 -> <= 32. */
void end_b01_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_b_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];

        if (end_w.r_no_2 == 1) {
            bgw_ptr->speed_y = 0x100000;
            break;
        }

        bgw_ptr->speed_y = -0x40000;
        break;

    case 1:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(2U);
        /* fallthrough */

    case 2:
        bgw_ptr->xy[1].cal += bgw_ptr->speed_y;
        bgw_ptr->abs_y += bgw_ptr->speed_y;

        if (bgw_ptr->xy[1].disp.pos <= 32) {
            bgw_ptr->xy[1].disp.pos = 288;
        }

        break;
    }
}

void end_b01_3000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_b_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        sub_000AF4AA(2U);
        break;

    case 1:
        if (bg_w.quake_y_index) {
            bgw_ptr->xy[1].disp.pos = (s16)quake_y_tbl[bg_w.quake_y_index] + end_b_pos[end_w.r_no_2][0];
            bgw_ptr->abs_y = quake_y_tbl[bg_w.quake_y_index];
            break;
        }

        bgw_ptr->r_no_1++;
        bgw_ptr->xy[1].disp.pos = end_b_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = 0;
        break;

    case 2:
        break;
    }
}
