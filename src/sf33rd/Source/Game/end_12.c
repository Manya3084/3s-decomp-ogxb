/* end_12.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_C00_0000 0xC0D22 size 0xB7.
 * end_C00_1000 0xC0DD9 size 0x83.
 * end_C00_2000 0xC0E5C size 0x5F.
 * end_C00_3000 0xC0EBB size 0xA8.
 * end_C00_4000 0xC0F63 size 0x68.
 * end_C00_5000 0xC0FCB size 0x5E.
 * end_C00_6000 0xC1029 size 0x9C.
 * end_12000 0xC11CA size 0xC3.
 * end_C01_0000 is folded into 0xC4FDA with 1 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: end_C00_move,
 * end_C01_move.
 * BGM_Request is folded into 0x98407.
 * Bg_On_W is folded into 0xAF4AA.
 * end_C00_move has no XBE name and no aligned call.
 * end_C01_move has no XBE name and no aligned call.
 * Data: timer_c_tbl is 0x286368, 0xE bytes compared.
 * Data: end_c_pos is 0x286378, 0x1C bytes compared.
 * Globals: timer_c_tbl 0x286368, end_c_pos 0x286378, end_w 0x7AABF0,
 * end_no_cut 0x7AABFE, end_fade_flag 0x7AAC08, bgw_ptr 0x7BC510, bg_w
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
void end_C00_move();
void end_C01_move();
extern BGW* bgw_ptr;
s32 Rewrite_End_Message(u16 mes_no);
s32 effect_F2_init();
s32 effect_E6_init(u8 char_num);
s32 Request_Fade(u16 fade_code);
extern s8 end_no_cut;
s16 end_fade_complete();
void overwrite_panel(u32 color, u8 priority);
extern s8 end_fade_flag;
extern s16 end_fade_timer;

const s16 timer_c_tbl[7] = { 600, 600, 360, 420, 360, 540, 420 };

const s16 end_c_pos[7][2] = { { 256, 32 },  { 768, 768 }, { 768, 768 }, { 768, 512 },
                              { 768, 768 }, { 768, 256 }, { 768, 256 } };

void end_12000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_c_tbl[end_w.r_no_2];
        sub_00098407(0x31);
        break;

    case 1:
        end_w.timer--;
        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 == 7) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                break;
            }

            end_w.timer = timer_c_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_C00_move();
        end_C01_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_C00_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1);
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Rewrite_End_Message(1);
        break;

    case 1:
        if (bgw_ptr->xy[1].disp.pos > 304) {
            bgw_ptr->r_no_1++;
            effect_F2_init();
        }

        /* fallthrough */

    case 2:
        bgw_ptr->xy[1].cal += 0x10000;

        if (bgw_ptr->xy[1].disp.pos > 384) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1800000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 3:
        break;
    }
}

void end_C00_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x39);
        Rewrite_End_Message(2);
        bgw_ptr->free = 0;
        bgw_ptr->l_limit = 3;
        break;

    case 1:
        break;
    }
}

void end_C00_2000() {
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
            end_w.timer = 0x14;
            overwrite_panel(0xFFFFFFFF, 0x17);
        }

        break;

    default:
        overwrite_panel(0xFFFFFFFF, 0x17);
        break;
    }
}

void end_C00_3000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        overwrite_panel(0xFFFFFFFF, 0x17);
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        Rewrite_End_Message(3);
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

        break;
    }
}

void end_C00_4000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        effect_E6_init(0x3B);
        Rewrite_End_Message(4);
        bgw_ptr->free = 0;
        bgw_ptr->l_limit = 3;
        break;

    case 1:
        break;
    }
}

void end_C00_5000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        effect_E6_init(0x3C);
        effect_E6_init(0x99);
        Rewrite_End_Message(5);
        break;

    case 1:
        break;
    }
}

void end_C00_6000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        bgw_ptr->free = 0x3C;
        end_fade_flag = 1;
        end_fade_timer = timer_c_tbl[end_w.r_no_2] - 120;
        Rewrite_End_Message(6);
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x3D);
        }

        break;

    case 2:
        break;
    }
}

void end_C01_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(2);
        bgw_ptr->xy[0].disp.pos = end_c_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_c_pos[end_w.r_no_2][1];
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 1:
        bgw_ptr->xy[1].cal += 0x10000;

        if (bg_w.bgw[0].r_no_1 >= 3) {
            bgw_ptr->r_no_1++;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 2:
        break;
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void end_C00_move() {
    void (*end_C00_jp[7])() = { end_C00_0000, end_C00_1000, end_C00_2000, end_C00_3000,
                                end_C00_4000, end_C00_5000, end_C00_6000 };
    bgw_ptr = &bg_w.bgw[0];
    end_C00_jp[end_w.r_no_2]();
}

void end_C01_move() {
    void (*end_c01_jp[7])() = { end_C01_0000, end_X_com01, end_X_com01, end_X_com01,
                                end_X_com01,  end_X_com01, end_X_com01 };
    bgw_ptr = &bg_w.bgw[1];
    end_c01_jp[end_w.r_no_2]();
}
#endif
