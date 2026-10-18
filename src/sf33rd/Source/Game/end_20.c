/* end_20.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_2000_0000 0xC40F2 size 0xA0.
 * end_2000_0001 0xC4192 size 0xBE.
 * end_2000_0002 0xC4250 size 0x9B.
 * end_2000_0003 0xC42EB size 0xE3.
 * end_2000_0005 0xC43CE size 0x105.
 * end_2001_0000 0xC44D3 size 0x53.
 * end_2001_0002 0xC4526 size 0x5B.
 * end_2001_0004 0xC4581 size 0x18.
 * end_2001_0005 0xC4599 size 0x5E.
 * sea_trans 0xC45F7 size 0x102. Read against the x86: the PS2 build converts
 * the double with dptofp; MSVC uses fld/fstp. The C is the PS2 C.
 * end_2000_move 0xC46F9 size 0x44.
 * sea_write 0xC473D size 0x85. Read against the x86: written from the x86; the
 * PS2 decompilation has no C for it. It loops 512 times (j to 0x800 by 4),
 * scales rate_256_table[(u8)(j + ls_cnt1)][0] by e_line_step = 64, shifts
 * right 4, and passes the high half to sea_trans unless No_Trans is set; then
 * ls_cnt1 advances by 2, wrapped at 0x200. rate_256_table is 0x23C3D8. ls_cnt1
 * is 0x7BC4F2. e_line_step is 0x7AAC06. The PS2 build calls litodp for the
 * int-to-double step. The C is in analysis-ps2map/overrides/end_20.c.
 * end_2001_0003 0xC47C2 size 0x9A.
 * end_2001_move 0xC485C size 0x47.
 * end_20000 0xC48A3 size 0xC3.
 * BGM_Request is folded into 0x98407.
 * Bg_Off_W is folded into 0xAF4C2.
 * Bg_On_W is folded into 0xAF4AA.
 * dptofp has no XBE name and no aligned call.
 * litodp has no XBE name and no aligned call.
 * Data: timer_20_tbl is 0x286658, 0xC bytes compared.
 * Data: end_20_pos is 0x286664, 0x18 bytes compared.
 * Unnamed data used (not checked): sea_trans:
 * 0x2190ac,0x28667c,0x286680,0x286688,0x286690.
 * Globals: rate_256_table 0x23C3D8, timer_20_tbl 0x286658, end_20_pos
 * 0x286664, ppgAkeList 0x7A8060, end_w 0x7AABF0, end_fade_timer 0x7AAC00,
 * e_line_step 0x7AAC06, end_fade_flag 0x7AAC08, ls_cnt1 0x7BC4F2, bgw_ptr
 * 0x7BC510, bg_w 0x7BC520, No_Trans 0x7BD3C9, Frame_Zoom_Y 0x7C5854,
 * Frame_Zoom_X 0x7C5B94, PrioBase 0xC7E560.
 */

#include "structs.h"

#define NULL 0

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
void end_2000_move();
void end_2001_move();
void end_2000_0000();
void end_2000_0001();
void end_2000_0002();
void end_2000_0003();
void end_2000_0005();
extern BGW* bgw_ptr;
s32 effect_E6_init(u8 char_num);
s32 Rewrite_End_Message(u16 mes_no);
extern s8 end_fade_flag;
extern s16 end_fade_timer;
void end_2001_0000();
void end_X_com01();
void end_2001_0002();
void end_2001_0003();
void end_2001_0004();
void end_2001_0005();
void ppgSetupCurrentDataList(PPGDataList* dlist);
extern PPGDataList ppgAkeList;
void ppgSetupCurrentPaletteNumber(Palette* pal, s32 num);
extern s16 ls_cnt1;
void sea_write();
extern s16 e_line_step;
extern const s32 rate_256_table[256][2];
extern u8 No_Trans;
void sea_trans(u16 num, f64 arg2);
extern f32 Frame_Zoom_X;
extern f32 Frame_Zoom_Y;
extern f32 PrioBase[128];
void njDrawTexture(Polygon* polygon, s32 , s32 tex, s32 );

const s16 timer_20_tbl[6] = { 360, 420, 780, 720, 240, 780 };

const s16 end_20_pos[6][2] = { { 256, 704 }, { 256, 304 }, { 256, 448 }, { 256, 816 }, { 768, 768 }, { 256, 224 } };

void end_20000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        common_end_init01();
        end_w.timer = timer_20_tbl[end_w.r_no_2];
        sub_00098407(0x31);
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

            end_w.timer = timer_20_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_2000_move();
        end_2001_move();
        /* fallthrough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_2000_move() {
    void (*end_2000_jp[6])() = { end_2000_0000, end_2000_0001, end_2000_0002,
                                 end_2000_0003, end_2000_0002, end_2000_0005 };
    bgw_ptr = &bg_w.bgw[0];
    end_2000_jp[end_w.r_no_2]();
}

void end_2000_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        effect_E6_init(0x3E);
        Rewrite_End_Message(1);
        break;

    case 1:
        bgw_ptr->xy[0].cal += 0x8000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->xy[1].cal += 0x4000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}

void end_2000_0001() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1);
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Rewrite_End_Message(2);
        effect_E6_init(0x3F);
        effect_E6_init(0x40);
        break;

    case 1:
        bgw_ptr->xy[1].cal -= 0x4000;

        if (bgw_ptr->xy[1].disp.pos < 272) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x1100000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 2:
        break;
    }
}

void end_2000_0002() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1);

        switch (end_w.r_no_2) {
        case 2:
            Rewrite_End_Message(3);
            break;

        case 4:
            Rewrite_End_Message(5);
            effect_E6_init(0x42);
            effect_E6_init(0x43);
            break;
        }

        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        break;

    case 1:
        break;
    }
}

void end_2000_0003() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4C2(1);
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        Rewrite_End_Message(4);
        effect_E6_init(0x91);
        effect_E6_init(0x92);
        effect_E6_init(0x93);
        effect_E6_init(0x94);
        effect_E6_init(0x95);
        break;

    case 1:
        bgw_ptr->xy[0].cal -= 0x4000;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bgw_ptr->xy[1].cal += 0x6000;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;
    }
}

void end_2000_0005() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(1);
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        effect_E6_init(0x44);
        effect_E6_init(0x45);
        Rewrite_End_Message(6);
        end_fade_flag = 1;
        end_fade_timer = timer_20_tbl[end_w.r_no_2] - 120;
        bgw_ptr->free = 0x5A;
        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 2:
        bgw_ptr->xy[1].cal += 0x10000;

        if (bgw_ptr->xy[1].disp.pos > 544) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0x2200000;
        }

        bgw_ptr->abs_y = bgw_ptr->xy[1].disp.pos;
        break;

    case 3:
        break;
    }
}

void end_2001_move() {
    void (
        *end_2001_jp[6])() = { end_2001_0000, end_X_com01, end_2001_0002, end_2001_0003, end_2001_0004, end_2001_0005 };
    bgw_ptr = &bg_w.bgw[1];
    end_2001_jp[end_w.r_no_2]();
}

void end_2001_0000() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(2);
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        effect_E6_init(0x38);
        break;

    case 1:
        break;
    }
}

void end_2001_0002() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        effect_E6_init(0x41);
        break;

    case 1:
        break;
    }
}

void end_2001_0003() {
    ppgSetupCurrentDataList(&ppgAkeList);
    ppgSetupCurrentPaletteNumber(NULL, 0);

    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        ls_cnt1 = 0;
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        /* fallthrough */

    case 1:
        sea_write();
        break;
    }
}

void end_2001_0004() {
    switch (bgw_ptr->r_no_1) {
    case 0:
    case 1:
        end_X_com01();
        break;
    }
}

void end_2001_0005() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_20_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_20_pos[end_w.r_no_2][1];
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        /* fallthrough */

    case 1:
    case 2:
        break;
    }
}

/* Written from the x86; the PS2 decompilation has no C for this function. */
void sea_write() {
    s16 i;
    u16 j;
    s32 work;

    e_line_step = 64;

    for (i = 0, j = 0; j < 0x800; j += 4, i++) {
        work = (e_line_step * rate_256_table[(u8)(j + ls_cnt1)][0]) >> 4;

        if (No_Trans == 0) {
            sea_trans(i, (s16)(work >> 16));
        }
    }

    ls_cnt1 = (ls_cnt1 + 2) & 0x1FF;
}

void sea_trans(u16 num, f64 arg2) {
    f32 suzi = arg2;
    Polygon poly[4];

    poly[0].col = poly[1].col = poly[2].col = poly[3].col = -1;
    poly[0].u = poly[1].u = 0.0f;
    poly[2].u = poly[3].u = 1.0f;
    poly[0].v = poly[2].v = num / 512.0f;
    poly[1].v = poly[3].v = (num + 1) / 512.0f;
    poly[0].x = poly[1].x = (-64.0f + suzi) * Frame_Zoom_X;
    poly[2].x = poly[3].x = (448.0f + suzi) * Frame_Zoom_X;
    poly[0].y = poly[2].y = (32.0f + num) * Frame_Zoom_Y;
    poly[1].y = poly[3].y = (32.0f + (num + 1)) * Frame_Zoom_Y;
    poly[0].z = poly[1].z = poly[2].z = poly[3].z = PrioBase[84];
    njDrawTexture(poly, 4, 228, 0);
}
