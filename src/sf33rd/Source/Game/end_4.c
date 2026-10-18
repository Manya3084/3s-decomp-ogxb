/* end_4.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_400_move 0xC4F24 size 0x18.
 * end_400_0000 0xC4F3C size 0x9E.
 * end_401_move 0xC50C6 size 0x18.
 * end_401_1000 0xC5168 size 0xEC.
 * end_401_2000 0xC5254 size 0x106.
 * end_401_3000 0xC535A size 0xDD.
 * end_401_4000 0xC5437 size 0x102.
 * end_402_move 0xC5539 size 0x18.
 * end_402_0000 0xC5551 size 0x7D.
 * end_402_1000 0xC55CE size 0xEC.
 * end_04000 0xC56BA size 0xD8.
 * end_400_1000 is folded into 0xC4FDA with 1 other bodies. Unnamed.
 * end_401_0000 is folded into 0xC50DE with 1 other bodies. Unnamed.
 * BGM_Request is folded into 0x98407.
 * Bg_On_W is folded into 0xAF4AA.
 * Data: timer_4_tbl is 0x2866C0, 0xA bytes compared.
 * Data: end_4_pos is 0x2866CC, 0x14 bytes compared.
 * Data: end_400_jp is 0x332DEC, 5 entries compared.
 * Data: end_401_jp is 0x332E00, 5 entries compared.
 * Data: end_402_jp is 0x332E14, 5 entries compared.
 * TARGET_PS2 block in end_401_2000: kept the PS2 side of a TARGET_PS2 block.
 * TARGET_PS2 block in end_401_3000: kept the PS2 side of a TARGET_PS2 block.
 * TARGET_PS2 block in end_401_4000: kept the PS2 side of a TARGET_PS2 block.
 * Globals: timer_4_tbl 0x2866C0, end_4_pos 0x2866CC, end_400_jp 0x332DEC,
 * end_401_jp 0x332E00, end_402_jp 0x332E14, end_w 0x7AABF0, end_no_cut
 * 0x7AABFE, end_fade_flag 0x7AAC08, bgw_ptr 0x7BC510, bg_w 0x7BC520.
 */

#include "structs.h"

void sub_00098407(s16 Code);
void sub_000AF4AA(u16 s_prm);
void end_400_0000();
void end_400_1000();
void end_X_com01();
void end_401_0000();
void end_401_1000();
void end_401_2000();
void end_401_3000();
void end_401_4000();
void end_402_0000();
void end_402_1000();
extern END_W end_w;
void common_end_init00(s16 pl_num);
void common_end_init01();
void fadeout_to_staff_roll();
void end_scn_pos_set2();
void end_bg_pos_hosei2();
void end_fam_set2();
extern s8 end_no_cut;
extern BG bg_w;
void end_400_move();
void end_401_move();
void end_402_move();
extern BGW* bgw_ptr;
s32 Rewrite_End_Message(u16 mes_no);
s32 effect_E6_init(u8 char_num);
s32 effect_H1_init();
void Frame_Up(u16 x, u16 y, u16 add);
void Frame_Down();
void Zoomf_Init();
extern s8 end_fade_flag;
extern s16 end_fade_timer;

const s16 timer_4_tbl[5] = { 960, 1140, 1800, 600, 780 };

const s16 end_4_pos[5][2] = { { 576, 768 }, { 512, 256 }, { 512, 768 }, { 512, 512 }, { 512, 256 } };

void (*end_400_jp[5])() = { end_400_0000, end_400_1000, end_X_com01, end_X_com01, end_X_com01 };

void (*end_401_jp[5])() = { end_401_0000, end_401_1000, end_401_2000, end_401_3000, end_401_4000 };

void (*end_402_jp[5])() = { end_402_0000, end_402_1000, end_X_com01, end_X_com01, end_X_com01 };

void end_04000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_4_tbl[end_w.r_no_2];
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

            if (end_w.r_no_2 == 2) {
                end_no_cut = 1;
            }

            end_w.timer = timer_4_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_400_move();
        end_401_move();
        end_402_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_400_move() {
    bgw_ptr = &bg_w.bgw[0];
    end_400_jp[end_w.r_no_2]();
}

void end_400_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Rewrite_End_Message(1);
        sub_000AF4AA(1);
        bgw_ptr->xy[0].disp.pos = 720;
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->speed_x = 0x8000;
        break;

    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos < 416) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[0].cal = 0x1A00000;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;
    }
}

void end_400_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Rewrite_End_Message(2);
        bgw_ptr->free = 0x12C;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->speed_x = 0x5000;
            bgw_ptr->speed_y = 0x3000;
            bgw_ptr->free = 0xF0;
        }

        break;

    case 2:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        } else {
            bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
            bgw_ptr->xy[1].cal += bgw_ptr->speed_y;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 3:
        break;
    }
}

void end_401_move() {
    bgw_ptr = &bg_w.bgw[1];
    end_401_jp[end_w.r_no_2]();
}

void end_401_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        effect_E6_init(0x5D);
        effect_H1_init();
        bgw_ptr->speed_x = 0xC000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos < 161) {
            bgw_ptr->r_no_1++;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

void end_401_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        effect_E6_init(0x5F);
        bgw_ptr->free = 0x12C;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->speed_x = 0xA000;
            bgw_ptr->speed_y = 0x6000;
            bgw_ptr->free = 0xF0;
        }

        break;

    case 2:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        } else {
            bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
            bgw_ptr->xy[1].cal += bgw_ptr->speed_y;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 3:
        break;
    }
}

void end_401_2000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(2);
        Rewrite_End_Message(0);
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        bg_w.center_x = 0xC0;
        bg_w.center_y = 0x70;
        Frame_Up(bg_w.center_x, bg_w.center_y, 0x1E);
        bg_w.frame_deff = 0x33;
        bg_w.frame_vol = 1;
        break;

    case 1:
        bgw_ptr->r_no_1++;
        end_no_cut = 0;
        /* fallthrough */

    case 2:
        bg_w.frame_vol--;

        if (bg_w.frame_vol <= 0) {
            bg_w.frame_vol = 1;
            bg_w.frame_deff--;

            if (bg_w.frame_deff < 0) {
                bgw_ptr->r_no_1++;
                end_w.timer = 0;
                break;
            }

            Frame_Down(bg_w.center_x, bg_w.center_y, 1, 1);
        }

        break;

    case 3:
        break;
    }
}

void end_401_3000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        break;

    case 1:
        bgw_ptr->r_no_1++;
        Zoomf_Init();
        bg_w.center_x = 176;
        bg_w.center_y = 128;
        Frame_Up(bg_w.center_x, bg_w.center_y, 0x1E);
        bg_w.frame_deff = 48;
        bg_w.frame_vol = 1;
        /* fallthrough */

    case 2:
        bg_w.frame_vol--;

        if (bg_w.frame_vol <= 0) {
            bg_w.frame_vol = 1;
            bg_w.frame_deff--;

            if (bg_w.frame_deff < 0) {
                bgw_ptr->r_no_1++;
                end_w.timer = 0;
                break;
            }
            Frame_Down(bg_w.center_x, bg_w.center_y, 1, 1);
        }

        break;

    case 3:
        break;
    }
}

void end_401_4000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        end_fade_flag = 1;
        end_fade_timer = timer_4_tbl[end_w.r_no_2] - 120;
        break;

    case 1:
        bgw_ptr->r_no_1++;
        Zoomf_Init();
        bg_w.center_x = 160;
        bg_w.center_y = 128;
        Frame_Up(bg_w.center_x, bg_w.center_y, 0x1E);
        bg_w.frame_deff = 0x2E;
        bg_w.frame_vol = 1;
        /* fallthrough */

    case 2:
        bg_w.frame_vol--;
        if (bg_w.frame_vol <= 0) {
            bg_w.frame_vol = 2;
            bg_w.frame_deff--;

            if (bg_w.frame_deff < 0) {
                bgw_ptr->r_no_1++;
                end_w.timer = 60;
                break;
            }

            Frame_Down(bg_w.center_x, bg_w.center_y, 1, 1);
        }

        break;

    case 3:
        break;
    }
}

void end_402_move() {
    bgw_ptr = &bg_w.bgw[2];
    end_402_jp[end_w.r_no_2]();
}

void end_402_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        bgw_ptr->speed_x = 0x8000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos < 161) {
            bgw_ptr->r_no_1++;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

void end_402_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_4_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_4_pos[end_w.r_no_2][1];
        effect_E6_init(0x5E);
        bgw_ptr->free = 0x12C;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->speed_x = 0xA000;
            bgw_ptr->speed_y = 0x4000;
            bgw_ptr->free = 0xF0;
            break;
        }

        break;

    case 2:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        } else {
            bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;
            bgw_ptr->xy[1].cal += bgw_ptr->speed_y;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 3:
        break;
    }
}
