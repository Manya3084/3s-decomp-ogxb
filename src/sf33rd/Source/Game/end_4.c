/* end_4.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_400_0000 0xC4F3C size 0x9E.
 * end_401_4000 0xC5437 size 0x102.
 * end_04000 0xC56BA size 0xD8.
 * end_400_1000 is folded into 0xC4FDA with 1 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: end_400_move,
 * end_401_move, end_401_0000, end_401_1000, end_401_2000, end_401_3000,
 * end_402_move, end_402_0000, end_402_1000.
 * BGM_Request is folded into 0x98407.
 * Bg_On_W is folded into 0xAF4AA.
 * end_400_move has no XBE name and no aligned call.
 * end_401_move has no XBE name and no aligned call.
 * end_402_move has no XBE name and no aligned call.
 * Data: timer_4_tbl is 0x2866C0, 0xA bytes compared, found by the bytes.
 * Data: end_4_pos is 0x2866CC, 0x14 bytes compared, found by the bytes.
 * Data: end_400_jp is 0x332DEC, 5 entries compared.
 * Data: end_401_jp: not located in the XBE.
 * Data: end_402_jp: not located in the XBE.
 * Globals: timer_4_tbl 0x2866C0, end_4_pos 0x2866CC, end_w 0x7AABF0,
 * end_no_cut 0x7AABFE, end_fade_flag 0x7AAC08, bgw_ptr 0x7BC510, bg_w
 * 0x7BC520.
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
extern s8 end_fade_flag;
extern s16 end_fade_timer;
void Zoomf_Init();
void Frame_Up(u16 x, u16 y, u16 add);
void Frame_Down(); /* called with 4 arguments here, as on Xbox */

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

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void end_400_move() {
    bgw_ptr = &bg_w.bgw[0];
    end_400_jp[end_w.r_no_2]();
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
#if defined(TARGET_PS2)
    void Frame_Up(u32 x, u32 y, u16 add);
    void Frame_Down(u32 x, u32 y, u16 add, u32 /* unused */);
#endif

    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(2);
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
#if defined(TARGET_PS2)
    void Frame_Up(u32 x, u32 y, u16 add);
    void Frame_Down(u32 x, u32 y, u16 add, u32 /* unused */);
#endif

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
#endif
