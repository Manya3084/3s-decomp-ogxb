/* end_14.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_e00_0000_col_sub 0xC17FC size 0x4A.
 * end_e00_0000_col_sub2 0xC1846 size 0x39.
 * end_e00_1000_col_sub 0xC187F size 0x47.
 * end_e00_1000 0xC18C6 size 0xAE. Read against the x86: 0x240000 is the cal
 * value stored, which happens to fall inside dir_sel_table's range; it is not
 * a reference. The C is the PS2 C.
 * end_e00_2000 0xC1974 size 0xEC.
 * end_e00_3000 0xC1A60 size 0x11D.
 * end_e00_4000 0xC1B7D size 0xF3.
 * end_e00_5000 0xC1C70 size 0x7E.
 * end_e00_6000 0xC1CEE size 0x11C.
 * end_e00_7000 0xC1E0A size 0x146.
 * end_e01_0000 0xC1F50 size 0x153.
 * end_e01_7000 0xC20A3 size 0x9A.
 * end_e02_0000 0xC213D size 0xED.
 * end_e02_1000 0xC222A size 0x49.
 * end_e02_2000 0xC2273 size 0x73. FLAG: x86-only constants 0xf000.
 * end_e02_3000 0xC22E6 size 0x70.
 * end_e02_4000 0xC2356 size 0x52.
 * end_e02_7000 0xC23A8 size 0xAA.
 * end_e00_0000 0xC2452 size 0x1E1.
 * end_e01_move 0xC2633 size 0x42.
 * end_e02_move 0xC2675 size 0x52.
 * end_e00_move 0xC26C7 size 0x55.
 * end_14000 0xC271C size 0xF1.
 * BGM_Request is folded into 0x98407.
 * Bg_Off_W is folded into 0xAF4C2.
 * Bg_On_W is folded into 0xAF4AA.
 * Data: gxy 0x7AAC10.
 * Data: timer_e_tbl is 0x286408, 0x12 bytes compared.
 * Data: end_e_pos is 0x28641C, 0x28 bytes compared.
 * Data: end_e00_0000_col_tbl is 0x286444, 0xC bytes compared.
 * Data: end_e00_1000_col_tbl is 0x286450, 0x8 bytes compared.
 * Data: end_e00_2000_col_tbl is 0x286458, 0x8 bytes compared.
 * Unnamed data used (not checked): end_e00_2000: 0x500000; end_e00_4000:
 * 0x400000; end_e00_7000: 0x332f24; end_e00_0000: 0x332f20.
 * Globals: dir_sel_table 0x23CBD8, timer_e_tbl 0x286408, end_e_pos 0x28641C,
 * end_e00_0000_col_tbl 0x286444, end_e00_1000_col_tbl 0x286450,
 * end_e00_2000_col_tbl 0x286458, end_w 0x7AABF0, end_no_cut 0x7AABFE,
 * end_fade_timer 0x7AAC00, end_etc_flag 0x7AAC03, end_fade_flag 0x7AAC08, gxy
 * 0x7AAC10, g_kakikae 0x7BC4A2, g_number 0x7BC4EE, scr_bcm 0x7BC500, bgw_ptr
 * 0x7BC510, nosekae 0x7BC51C, bg_w 0x7BC520.
 */

#include "structs.h"

void sub_00098407(s16 Code);
void sub_000AF4C2(u16 s_prm);
void sub_000AF4AA(u16 s_prm);
extern END_W end_w;
extern u8 nosekae;
extern u8 g_kakikae[2];
extern u8 g_number[2];
void common_end_init00(s16 pl_num);
void common_end_init01();
void fadeout_to_staff_roll();
void end_scn_pos_set2();
void end_bg_pos_hosei2();
void end_fam_set2();
extern BG bg_w;
void end_e00_move();
void end_e01_move();
void end_e02_move();
void end_e00_0000();
void end_e00_1000();
void end_e00_2000();
void end_e00_3000();
void end_e00_4000();
void end_e00_5000();
void end_e00_6000();
void end_e00_7000();
extern BGW* bgw_ptr;
s32 Rewrite_End_Message(u16 mes_no);
s32 effect_E6_init(u8 char_num);
extern const u16* scr_bcm[4];
extern const u16* ending_map_tbl[][3];
s16 end_e00_0000_col_sub();
void Frame_Up(u16 x, u16 y, u16 add);
s32 Request_Fade(u16 fade_code);
extern s8 end_no_cut;
s16 end_fade_complete();
void overwrite_panel(u32 color, u8 priority);
void Frame_Down(u16 x, u16 y, u16 add);
void Zoomf_Init();
extern s8 end_etc_flag;
extern s8 end_fade_flag;
extern s16 end_fade_timer;
void end_e01_0000();
void end_X_com01();
void end_e01_7000();
void end_e02_0000();
void end_e02_1000();
void end_e02_2000();
void end_e02_3000();
void end_e02_4000();
void end_e02_7000();

extern struct {
    XY xy[2];
} gxy;

const s16 timer_e_tbl[9] = { 1320, 240, 900, 1200, 360, 360, 300, 420, 600 };

const s16 end_e_pos[10][2] = { { 256, 768 }, { 768, 0 }, { 768, 768 }, { 256, 0 },   { 768, 768 },
                               { 768, 768 }, { 256, 0 }, { 256, 768 }, { 256, 256 }, { 768, 256 } };

const u8 end_e00_0000_col_tbl[12] = { 0, 1, 2, 3, 4, 5, 6, 5, 6, 5, 6, 6 };

const u8 end_e00_1000_col_tbl[8] = { 0, 0, 1, 2, 3, 4, 5, 6 };

const u8 end_e00_2000_col_tbl[8] = { 6, 5, 4, 3, 2, 1, 0, 0 };

void end_14000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        nosekae = 0;
        g_kakikae[0] = 0;
        g_kakikae[1] = 0;
        g_number[0] = 0;
        g_number[1] = 0;
        gxy.xy[1].disp.pos = 0;
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        end_w.timer = timer_e_tbl[end_w.r_no_2];
        common_end_init01();
        sub_00098407(0x32);
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 == 8) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                break;
            }

            end_w.timer = timer_e_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_e00_move();
        end_e01_move();
        end_e02_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_e00_move() {
    void (*end_e00_jp[8])() = { end_e00_0000, end_e00_1000, end_e00_2000, end_e00_3000,
                                end_e00_4000, end_e00_5000, end_e00_6000, end_e00_7000 };
    bgw_ptr = &bg_w.bgw[0];
    end_e00_jp[end_w.r_no_2]();
}

/* Rewritten to match retail (tools/permute.py): < 273 -> <= 272; < 713 -> <= 712; < -223 -> <= -224. */
void end_e00_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1);
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[0].disp.pos += 64;
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->free = 0x3C;
        Rewrite_End_Message(1);
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        bgw_ptr->xy[1].cal -= 0x18000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;

        if (bgw_ptr->xy[1].disp.pos <= 272) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x19);
            gxy.xy[1].disp.pos = bgw_ptr->xy[1].disp.pos;
            nosekae = 1;
            *scr_bcm = ending_map_tbl[20][0];
        }

        break;

    case 3:
        bgw_ptr->xy[1].cal -= 0x18000;
        gxy.xy[1].cal = gxy.xy[1].cal - 0x18000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;

        if (bgw_ptr->xy[1].disp.pos < 0) {
            bgw_ptr->xy[1].disp.pos = 0;
        }

        if (gxy.xy[1].disp.pos <= -224) {
            bgw_ptr->xy[1].disp.pos = 752;
        }

        break;

    case 4:
        bgw_ptr->r_no_1++;
        bgw_ptr->free = 7;
        bgw_ptr->l_limit = 0;
        g_kakikae[0] = 1;
        /* fallthrough */

    case 5:
        if (end_e00_0000_col_sub()) {
            bgw_ptr->r_no_1++;
        }

        /* fallthrough */

    case 6:
        bgw_ptr->xy[1].cal -= 0x4000;

        if (bgw_ptr->xy[1].disp.pos <= 712) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2C80000;
            end_w.timer = 20;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 7:
        break;
    }
}

s16 end_e00_0000_col_sub() {
    bgw_ptr->free--;

    if (bgw_ptr->free <= 0) {
        bgw_ptr->free = 7;
        bgw_ptr->l_limit++;

        if (bgw_ptr->l_limit >= 12) {
            return 1;
        }

        *g_number = end_e00_0000_col_tbl[bgw_ptr->l_limit];
    }

    return 0;
}

s16 end_e00_0000_col_sub2() {
    bgw_ptr->free--;

    if (bgw_ptr->free <= 0) {
        bgw_ptr->free = 7;
        bgw_ptr->l_limit++;

        if (bgw_ptr->l_limit >= 12) {
            return 1;
        }
    }

    return 0;
}

/* Rewritten to match retail (tools/permute.py): >= 8 -> > 7. */
void end_e00_1000_col_sub() {
    if (bgw_ptr->l_limit > 7) {
        return;
    }

    bgw_ptr->free--;

    if (bgw_ptr->free > 0) {
        return;
    }

    bgw_ptr->l_limit++;

    if (bgw_ptr->l_limit < 7) {
        bgw_ptr->free = 8;
        g_number[1] = end_e00_1000_col_tbl[bgw_ptr->l_limit];
    }
}

void end_e00_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 768;
        bgw_ptr->xy[1].disp.pos = 128;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 128;
        bgw_ptr->free = 8;
        bgw_ptr->l_limit = 0;
        g_kakikae[1] = 1;
        g_number[1] = 0;
        Rewrite_End_Message(2);
        break;

    case 1:
        bgw_ptr->xy[1].cal -= 0x8000;

        if (bgw_ptr->xy[1].disp.pos < 36) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x240000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        /* fallthrough */

    case 2:
        end_e00_1000_col_sub();
        break;
    }
}

void end_e00_2000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        break;

    case 1:
        bgw_ptr->xy[1].cal += 0x10000;

        if (bgw_ptr->xy[1].disp.pos > 80) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x500000;
            bgw_ptr->free = 0x4E;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 2:
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->free = 8;
            bgw_ptr->l_limit = 0;
        }

        break;

    case 3:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->l_limit++;

            if (bgw_ptr->l_limit >= 8) {
                bgw_ptr->r_no_1++;
                end_w.timer = 120;
                break;
            }

            bgw_ptr->free = 8;
            g_number[1] = end_e00_2000_col_tbl[bgw_ptr->l_limit];
        }

        break;

    case 4:
        g_kakikae[1] = 0;
        g_number[1] = 0;
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 1 -> <= 0. */
void end_e00_3000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4C2(1);
        bgw_ptr->xy[0].disp.pos = 256;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x1A);
        bgw_ptr->free = 0x30;
        Rewrite_End_Message(0);
        break;

    case 1:
        break;

    case 2:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        } else {
            Frame_Up(0xC0, 0x30, 1);
        }

        break;

    case 3:
        if (Request_Fade(3)) {
            end_no_cut = 1;
            bgw_ptr->r_no_1++;
        }

        break;

    case 4:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
            end_w.timer = 10;
            overwrite_panel(0xFFFFFFFF, 0x17);
            Frame_Down(0xC0, 0x30, 0x10);
        }

        break;

    case 5:
        Frame_Down(0xC0, 0x30, 3);
        overwrite_panel(0xFFFFFFFF, 0x17);
        break;
    }
}

void end_e00_4000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        overwrite_panel(0xFFFFFFFF, 0x17);
        bgw_ptr->r_no_1++;
        Zoomf_Init();
        bgw_ptr->xy[0].disp.pos = 256;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x1D);
        effect_E6_init(0x1E);
        break;

    case 1:
        overwrite_panel(0xFFFFFFFF, 0x17);

        if (Request_Fade(2)) {
            bgw_ptr->r_no_1++;
            end_no_cut = 1;
        }

        break;

    case 2:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
        }

        break;

    case 3:
        bgw_ptr->xy[1].cal += 0x4000;

        if (bgw_ptr->xy[1].disp.pos >= 64) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x400000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 4:
        break;
    }
}

void end_e00_5000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        sub_000AF4AA(1);
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        Rewrite_End_Message(3);
        break;

    case 1:
        break;
    }
}

void end_e00_6000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        sub_000AF4C2(1);
        effect_E6_init(0x1E);
        end_etc_flag = 0;
        effect_E6_init(0x1F);
        Rewrite_End_Message(4);
        break;

    case 1:
        if (end_etc_flag) {
            bgw_ptr->r_no_1++;
            bgw_ptr->free = 10;
        }

        break;

    case 2:
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 3:
        if (Request_Fade(3)) {
            end_no_cut = 1;
            bgw_ptr->r_no_1++;
        }

        break;

    case 4:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
            end_w.timer = 10;
            overwrite_panel(0xFFFFFFFF, 0x17);
        }

        /* fallthrough */

    case 5:
        overwrite_panel(0xFFFFFFFF, 0x17);
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 697 -> <= 696. */
void end_e00_7000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        overwrite_panel(0xFFFFFFFF, 0x17);
        bgw_ptr->r_no_1++;
        nosekae = 2;
        *scr_bcm = ending_map_tbl[20][1];
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->xy[1].disp.pos += 48;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        sub_000AF4AA(1);
        end_fade_flag = 1;
        end_fade_timer = timer_e_tbl[end_w.r_no_2] - 120;
        Rewrite_End_Message(5);
        /* fallthrough */

    case 1:
        overwrite_panel(0xFFFFFFFF, 0x17);

        if (Request_Fade(2)) {
            end_no_cut = 1;
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
        }

        /* fallthrough */

    case 3:
        bgw_ptr->xy[1].cal -= 0x3000;

        if (bgw_ptr->xy[1].disp.pos <= 696) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2B80000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 4:
        break;
    }
}

void end_e01_move() {
    void (*end_101_jp[8])() = { end_e01_0000, end_X_com01, end_X_com01, end_X_com01,
                                end_X_com01,  end_X_com01, end_X_com01, end_e01_7000 };
    bgw_ptr = &bg_w.bgw[1];
    end_101_jp[end_w.r_no_2]();
}

/* Rewritten to match retail (tools/permute.py): < 273 -> <= 272; < -311 -> <= -312. */
void end_e01_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(2);
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        bgw_ptr->free = 0x3C;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        bgw_ptr->xy[1].cal -= 0x18000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;

        if (bgw_ptr->xy[1].disp.pos <= 272) {
            bgw_ptr->r_no_1++;
            sub_000AF4C2(2);
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 3:
        bgw_ptr->xy[1].cal -= 0x18000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 4:
        bgw_ptr->r_no_1++;
        bgw_ptr->free = 7;
        bgw_ptr->l_limit = 0;
        /* fallthrough */

    case 5:
        if (end_e00_0000_col_sub2()) {
            bgw_ptr->r_no_1++;
        }

        /* fallthrough */

    case 6:
        bgw_ptr->xy[1].cal -= 0x4000;

        if (bgw_ptr->xy[1].disp.pos <= -312) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0xFEC80000;
            end_w.timer = 20;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 7:
        break;
    }
}

void end_e01_7000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0x23);
        break;

    case 1:
        if (bg_w.bgw[0].r_no_1 >= 4) {
            bgw_ptr->r_no_1++;
        } else {
            bgw_ptr->xy[1].cal -= 0x7000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 2:
        break;
    }
}

void end_e02_move() {
    void (*end_102_jp[8])() = { end_e02_0000, end_e02_1000, end_e02_2000, end_e02_3000,
                                end_e02_4000, end_X_com01,  end_X_com01,  end_e02_7000 };
    bgw_ptr = &bg_w.bgw[2];
    end_102_jp[end_w.r_no_2]();
}

void end_e02_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0x16);
        effect_E6_init(0x17);
        effect_E6_init(0x18);
        effect_E6_init(0x1B);
        effect_E6_init(0x1C);
        bgw_ptr->free = 0x3C;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        bgw_ptr->xy[0].cal -= 0x8000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->xy[1].cal += 0xFFFDE000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}

void end_e02_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(4);
        bgw_ptr->xy[0].disp.pos = 768;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        break;

    case 1:
        break;
    }
}

void end_e02_2000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 768;
        bgw_ptr->xy[1].disp.pos = 256;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 1:
        bgw_ptr->xy[1].cal += 0xF000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;

        if (bgw_ptr->xy[1].disp.pos >= 432) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < 353 -> <= 352. */
void end_e02_3000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 768;
        bgw_ptr->xy[1].disp.pos = 408;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 1:
        bgw_ptr->xy[1].cal += -0x18000;

        if (bgw_ptr->xy[1].disp.pos <= 352) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1600000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 2:
        break;
    }
}

void end_e02_4000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 768;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        break;

    case 1:
        bgw_ptr->r_no_1++;
        sub_000AF4C2(4);
        break;

    case 2:
        break;
    }
}

void end_e02_7000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_e_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_e_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0x20);
        effect_E6_init(0x21);
        effect_E6_init(0x22);
        break;

    case 1:
        if (bg_w.bgw[0].r_no_1 >= 4) {
            bgw_ptr->r_no_1++;
        } else {
            bgw_ptr->xy[1].cal -= 0x6000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 2:
        break;
    }
}
