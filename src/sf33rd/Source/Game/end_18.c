/* end_18.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_1800_0001 0xC32AA size 0xFC.
 * end_1800_0005 0xC33A6 size 0xB4.
 * end_1800_0006 0xC345A size 0x79.
 * end_1800_0008 0xC34D3 size 0x79.
 * end_1800_move 0xC369B size 0x58.
 * end_18000 0xC36F3 size 0xBE.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: end_1800_0009,
 * end_1800_0010.
 * BGM_Request is folded into 0x98407.
 * Bg_On_W is folded into 0xAF4AA.
 * Data: timer_18_tbl is 0x2865D0, 0x16 bytes compared.
 * Data: end_18_pos is 0x2865E8, 0x2C bytes compared.
 * Globals: timer_18_tbl 0x2865D0, end_18_pos 0x2865E8, end_w 0x7AABF0, bgw_ptr
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
void end_1800_move();
void end_1800_0005();
void end_1800_0001();
void end_1800_0006();
void end_1800_0008();
void end_1800_0009();
void end_1800_0010();
extern BGW* bgw_ptr;
s32 effect_E6_init(u8 char_num);
s32 Rewrite_End_Message(u16 mes_no);

const s16 timer_18_tbl[11] = { 900, 240, 240, 240, 240, 420, 720, 360, 480, 240, 300 };

const s16 end_18_pos[11][2] = { { 768, 768 }, { 256, 768 }, { 256, 768 }, { 256, 768 }, { 256, 768 }, { 768, 768 },
                                { 256, 512 }, { 256, 768 }, { 256, 512 }, { 256, 256 }, { 768, 512 } };

void end_18000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        sub_00098407(0x32);
        end_w.timer = timer_18_tbl[end_w.r_no_2];
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 >= 11) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                break;
            }

            end_w.timer = timer_18_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_1800_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_1800_move() {
    void (*end_1800_move_jp[11])() = { end_1800_0005, end_1800_0001, end_1800_0001, end_1800_0001,
                                       end_1800_0001, end_1800_0005, end_1800_0006, end_1800_0001,
                                       end_1800_0008, end_1800_0009, end_1800_0010 };
    bgw_ptr = &bg_w.bgw[0];
    end_1800_move_jp[end_w.r_no_2]();
}

void end_1800_0001() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];

        switch (end_w.r_no_2) {
        case 1:
            sub_000AF4AA(1);
            effect_E6_init(0x6F);
            effect_E6_init(0x74);
            bgw_ptr->l_limit = 0;
            bgw_ptr->free = 3;
            Rewrite_End_Message(2);
            break;

        case 2:
            effect_E6_init(0x70);
            break;

        case 3:
            effect_E6_init(0x71);
            break;

        case 4:
            effect_E6_init(0x72);
            break;

        case 7:
            effect_E6_init(0x77);
            effect_E6_init(0x7A);
            Rewrite_End_Message(4);
            bgw_ptr->l_limit = 0;
            bgw_ptr->free = 3;
            break;
        }

        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 1;
            bgw_ptr->l_limit ^= 1;
        }

        break;
    }
}

void end_1800_0005() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1);
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];
        effect_E6_init(0x73);
        effect_E6_init(0x75);

        if (end_w.r_no_2) {
            Rewrite_End_Message(3);
        } else {
            Rewrite_End_Message(1);
        }

        bgw_ptr->l_limit = 0;
        bgw_ptr->free = 3;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 2;
            bgw_ptr->l_limit ^= 1;
        }

        break;
    }
}

void end_1800_0006() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];
        effect_E6_init(0x76);
        Rewrite_End_Message(6);
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 1;
            bgw_ptr->l_limit ^= 1;
        }

        break;
    }
}

void end_1800_0008() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];
        effect_E6_init(0x78);
        Rewrite_End_Message(5);
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 1;
            bgw_ptr->l_limit ^= 1;
        }

        break;
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void end_1800_0009() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];
        bgw_ptr->free = 0;
        Rewrite_End_Message(0);
        break;

    case 1:
        bgw_ptr->free++;
        bgw_ptr->free &= 1;

        if (bgw_ptr->free) {
            bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
            break;
        }

        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0] + 512;
        break;
    }
}

void end_1800_0010() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_18_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_18_pos[end_w.r_no_2][1];
        effect_E6_init(0x79);
        effect_E6_init(0xA2);
        bgw_ptr->free = 1;
        bgw_ptr->l_limit = 0;
        end_fade_flag = 1;
        end_fade_timer = timer_18_tbl[end_w.r_no_2] - 120;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->free = 1;
            bgw_ptr->l_limit++;
            bgw_ptr->l_limit &= 1;
        }

        break;
    }
}
#endif
