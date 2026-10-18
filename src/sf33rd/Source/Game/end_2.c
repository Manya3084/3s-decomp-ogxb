/* end_2.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_200_2000 0xC3C1F size 0x55.
 * end_200_move 0xC3F72 size 0x3D.
 * end_201_move 0xC3FAF size 0x3A.
 * end_202_move 0xC3FE9 size 0x3D.
 * end_02000 0xC4026 size 0xCC.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: end_200_0000,
 * end_200_1000, end_200_3000, end_201_1000, end_201_3000, end_202_1000,
 * end_202_3000, end_202_4000.
 * BGM_Request is folded into 0x98407.
 * Bg_On_W is folded into 0xAF4AA.
 * Data: timer_2_tbl is 0x286638, 0xA bytes compared.
 * Data: end_2_pos is 0x286644, 0x14 bytes compared.
 * Globals: timer_2_tbl 0x286638, end_w 0x7AABF0, bgw_ptr 0x7BC510, bg_w
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
void end_200_move();
void end_201_move();
void end_202_move();
void end_200_0000();
void end_200_1000();
void end_200_2000();
void end_200_3000();
extern BGW* bgw_ptr;
s32 Rewrite_End_Message(u16 mes_no);
s32 effect_E6_init(u8 char_num);
void end_X_com01();
void end_201_1000();
void end_201_3000();
void end_202_1000();
void end_202_3000();
void end_202_4000();

const s16 timer_2_tbl[5] = { 480, 660, 120, 240, 780 };

const s16 end_2_pos[5][2] = { { 256, 768 }, { 320, 256 }, { 512, 0 }, { 320, 256 }, { 320, 256 } };

void end_02000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_2_tbl[end_w.r_no_2];
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

            end_w.timer = timer_2_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_200_move();
        end_201_move();
        end_202_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_200_move() {
    void (*end_200_jp[5])() = { end_200_0000, end_200_1000, end_200_2000, end_200_3000, end_200_3000 };
    bgw_ptr = &bg_w.bgw[0];
    end_200_jp[end_w.r_no_2]();
}

void end_200_2000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1);
        Rewrite_End_Message(3);
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x7D);
        effect_E6_init(0x7E);
        break;

    case 1:
        end_X_com01();
        break;
    }
}

void end_201_move() {
    void (*end_201_jp[5])() = { end_X_com01, end_201_1000, end_X_com01, end_201_3000, end_201_3000 };
    bgw_ptr = &bg_w.bgw[1];
    end_201_jp[end_w.r_no_2]();
}

void end_202_move() {
    void (*end_202_jp[5])() = { end_X_com01, end_202_1000, end_X_com01, end_202_3000, end_202_4000 };
    bgw_ptr = &bg_w.bgw[2];
    end_202_jp[end_w.r_no_2]();
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void end_200_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Rewrite_End_Message(1);
        Bg_On_W(1);
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        bgw_ptr->free = 0x1E;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->speed_y = 0xC000;
        }

        break;

    case 2:
        bgw_ptr->xy[1].cal -= bgw_ptr->speed_y;

        if (bgw_ptr->xy[1].disp.pos < 513) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2000000;
        }

        break;
    }
}

void end_200_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Rewrite_End_Message(2);
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        bgw_ptr->speed_x = 0x4000;
        bgw_ptr->free = 3;
        bgw_ptr->l_limit = 0;
        break;

    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos < 193) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x7C);
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

void end_200_3000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];

        switch (end_w.r_no_2) {
        case 3:
            Rewrite_End_Message(4);
            bgw_ptr->free = 3;
            bgw_ptr->l_limit = 0;
            break;

        case 4:
            Rewrite_End_Message(5);
            end_fade_flag = 1;
            end_fade_timer = timer_2_tbl[end_w.r_no_2] - 120;
            break;
        }

    case 1:
        break;
    }
}

void end_201_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(2);
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->speed_x = 0x4000;
        bgw_ptr->free = 4;
        bgw_ptr->l_limit = 0;
        break;

    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos < 193) {
            bgw_ptr->r_no_1++;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

void end_201_3000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        Bg_On_W(2);
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];

        if (end_w.r_no_2 == 3) {
            bgw_ptr->free = 4;
            bgw_ptr->l_limit = 0;
        }

        break;

    case 1:
    case 2:
        break;
    }
}

void end_202_1000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->speed_x = 0xC000;
        effect_E6_init(0x7B);
        break;

    case 1:
        bgw_ptr->xy[0].cal -= bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos < 129) {
            bgw_ptr->r_no_1++;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

void end_202_3000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        effect_E6_init(0x7F);
        bgw_ptr->speed_x = 0x8000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 1:
        bgw_ptr->xy[0].cal += bgw_ptr->speed_x;

        if (bgw_ptr->xy[0].disp.pos >= 560) {
            bgw_ptr->r_no_1++;
        }

        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        break;

    case 2:
        break;
    }
}

void end_202_4000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_2_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_2_pos[end_w.r_no_2][1];
        effect_E6_init(0x80);
        break;

    case 1:
        break;
    }
}
#endif
