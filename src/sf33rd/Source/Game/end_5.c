/* end_5.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * end_500_comm 0xC5792 size 0xA3.
 * end_500_0001 0xC5835 size 0x12F.
 * end_500_0006 0xC5964 size 0x65.
 * end_500_quake_y_sub 0xC59C9 size 0x5F.
 * end_500_0011 0xC5A28 size 0x43.
 * end_5_bg0_move_sub 0xC5A6B size 0x30.
 * end_5_bg1_move_sub 0xC5A9B size 0x71.
 * end_5_bg1_move_sub2 0xC5B0C size 0x79.
 * end_501_0007 0xC5B85 size 0xBD.
 * end_501_0008 0xC5C42 size 0x1B.
 * end_501_0009 0xC5C5D size 0x3B.
 * end_501_0010 0xC5C98 size 0x67.
 * end_501_0011 0xC5CFF size 0xB3.
 * end_501_0012 0xC5DB2 size 0x5D.
 * end_500_0007 0xC5E0F size 0xF9.
 * end_500_0008 0xC5F08 size 0xF9.
 * end_501_move 0xC6001 size 0x61.
 * end_500_move 0xC6062 size 0x63.
 * end_05000 0xC60C5 size 0xC3.
 * BGM_Request is folded into 0x98407.
 * Bg_Off_W is folded into 0xAF4C2.
 * Bg_On_W is folded into 0xAF4AA.
 * Data: bdl_index 0x7AAC0A.
 * Data: wr5_index 0x7AAC09.
 * Data: end_5_flag 0x7AAC0C.
 * Data: timer_5_tbl is 0x2866E0, 0x1A bytes compared.
 * Data: end_5_pos is 0x2866FC, 0x2C bytes compared.
 * Data: necro_quake_tbl is 0x286728, 0x80 bytes compared.
 * Data: necro_quake_timer is 0x2867A8, 0x40 bytes compared.
 * Data: end_500_quake_tbl is 0x2867E8, 0x10 bytes compared.
 * Globals: timer_5_tbl 0x2866E0, end_5_pos 0x2866FC, necro_quake_tbl 0x286728,
 * necro_quake_timer 0x2867A8, end_500_quake_tbl 0x2867E8, end_w 0x7AABF0,
 * end_no_cut 0x7AABFE, end_fade_timer 0x7AAC00, end_etc_flag 0x7AAC03,
 * end_fade_flag 0x7AAC08, wr5_index 0x7AAC09, bdl_index 0x7AAC0A, end_5_flag
 * 0x7AAC0C, bgw_ptr 0x7BC510, bg_w 0x7BC520.
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
void end_500_move();
void end_501_move();
void end_500_comm();
void end_500_0001();
void end_500_0006();
void end_500_0007();
void end_500_0008();
void end_X_com01();
void end_500_0011();
extern BGW* bgw_ptr;
s32 Rewrite_End_Message(u16 mes_no);
s32 effect_E6_init(u8 char_num);
s32 Request_Fade(u16 fade_code);
extern s8 end_no_cut;
s16 end_fade_complete();
void overwrite_panel(u32 color, u8 priority);
void end_5_bg0_move_sub();
extern s8 end_etc_flag;
void end_501_0007();
void end_501_0008();
void end_501_0009();
void end_501_0010();
void end_501_0011();
void end_501_0012();
extern s8 end_fade_flag;
extern s16 end_fade_timer;

extern s8 bdl_index;

extern s8 wr5_index;

extern s16 end_5_flag;

const s16 timer_5_tbl[13] = { 120, 540, 660, 420, 180, 360, 360, 360, 360, 360, 300, 360, 360 };

const s16 end_5_pos[11][2] = { { 256, 768 }, { 768, 768 }, { 256, 512 }, { 768, 512 }, { 256, 256 }, { 768, 256 },
                               { 256, 768 }, { 256, 768 }, { 256, 768 }, { 256, 768 }, { 256, 768 } };

const s16 necro_quake_tbl[32][2] = { { 2, -2 },  { 4, -4 }, { 6, -8 }, { 8, -4 }, { 6, 0 },  { 8, -4 },  { 4, 0 },
                                     { 0, 0 },   { -2, 0 }, { -4, 4 }, { -4, 8 }, { -6, 2 }, { 0, 6 },   { 4, 0 },
                                     { -5, -4 }, { -5, 2 }, { 0, 0 },  { 2, -4 }, { 4, -8 }, { 6, -10 }, { 2, 2 },
                                     { -2, 6 },  { 0, 4 },  { 3, 1 },  { 6, 0 },  { 4, -2 }, { -6, 4 },  { -2, 8 },
                                     { 0, 0 },   { 6, 6 },  { 0, -8 }, { 4, 4 } };

const s16 necro_quake_timer[32] = { 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 8, 4, 4, 8,
                                    4, 4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 8, 4, 8 };

const s16 end_500_quake_tbl[8] = { 2, 4, -2, -4, -2, -4, 2, 4 };

/* The Xbox returns where the PS2 breaks out of the switch. */
void end_05000(s16 pl_num) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_w.r_no_2 = 0;
        common_end_init00(pl_num);
        end_w.timer = timer_5_tbl[end_w.r_no_2];
        common_end_init01();
        sub_00098407(0x32);
        break;

    case 1:
        end_w.timer--;

        if (end_w.timer < 0) {
            end_w.r_no_2++;

            if (end_w.r_no_2 == 13) {
                end_w.r_no_1++;
                end_w.end_flag = 1;
                fadeout_to_staff_roll();
                end_scn_pos_set2();
                end_bg_pos_hosei2();
                end_fam_set2();
                return;
            }

            end_w.timer = timer_5_tbl[end_w.r_no_2];
            bg_w.bgw[0].r_no_1 = 0;
            bg_w.bgw[1].r_no_1 = 0;
            bg_w.bgw[2].r_no_1 = 0;
        }

        end_500_move();
        end_501_move();
        /* fallthough */

    case 2:
        end_scn_pos_set2();
        end_bg_pos_hosei2();
        end_fam_set2();
        break;
    }
}

void end_500_move() {
    void (*end_500_jp[13])() = { end_500_comm, end_500_0001, end_500_0001, end_500_comm, end_500_comm,
                                 end_500_comm, end_500_0006, end_500_0007, end_500_0008, end_X_com01,
                                 end_X_com01,  end_500_0011, end_X_com01 };
    bgw_ptr = &bg_w.bgw[0];
    end_500_jp[end_w.r_no_2]();
}

void end_500_comm() {
    bgw_ptr = &bg_w.bgw[0];

    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = end_5_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_5_pos[end_w.r_no_2][1];

        switch (end_w.r_no_2) {
        case 0:
            sub_000AF4AA(1);
            Rewrite_End_Message(0);
            break;

        case 3:
            bgw_ptr->abs_x = 512;
            bgw_ptr->abs_y = 0;
            Rewrite_End_Message(3);
            break;

        case 4:
            effect_E6_init(0xB);
            Rewrite_End_Message(4);
            break;

        case 5:
            effect_E6_init(0xC);
            effect_E6_init(0xD);
            Rewrite_End_Message(5);
            break;
        }

    case 1:
        break;
    }
}

void end_500_0001() {
    bgw_ptr = bg_w.bgw;

    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        bgw_ptr->xy[0].disp.pos = end_5_pos[end_w.r_no_2][0];
        bgw_ptr->xy[1].disp.pos = end_5_pos[end_w.r_no_2][1];
        bgw_ptr->frame_deff = 0;
        bgw_ptr->free = necro_quake_timer[bgw_ptr->frame_deff];

        switch (end_w.r_no_2) {
        case 1:
            effect_E6_init(9);
            Rewrite_End_Message(1);
            break;

        case 2:
            effect_E6_init(0xA);
            Rewrite_End_Message(2);
            break;
        }

        break;

    case 1:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->frame_deff++;
            bgw_ptr->frame_deff &= 0x1F;
            bgw_ptr->free = necro_quake_timer[bgw_ptr->frame_deff];
            bgw_ptr->xy[0].disp.pos = end_5_pos[end_w.r_no_2][0];
            bgw_ptr->xy[0].disp.pos += necro_quake_tbl[bgw_ptr->frame_deff][0];
            bgw_ptr->xy[1].disp.pos = end_5_pos[end_w.r_no_2][1];
            bgw_ptr->xy[1].disp.pos += necro_quake_tbl[bgw_ptr->frame_deff][1];
            bgw_ptr->abs_x = 512;
            bgw_ptr->abs_x += necro_quake_tbl[bgw_ptr->frame_deff][0];
            bgw_ptr->abs_y = 0;
            bgw_ptr->abs_y += necro_quake_tbl[bgw_ptr->frame_deff][1];
        }

        break;
    }
}

void end_500_0006() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        if (Request_Fade(1) != 0) {
            bgw_ptr->r_no_1++;
            end_no_cut = 1;
        }

        break;

    case 1:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
            end_w.timer = 30;
            overwrite_panel(0xFF000000, 0x17);
        }

        break;

    case 2:
        overwrite_panel(0xFF000000, 0x17);
        break;
    }
}

void end_500_quake_y_sub() {
    bgw_ptr->frame_deff--;

    if (bgw_ptr->frame_deff <= 0) {
        bgw_ptr->frame_deff = 4;
        bg_w.quake_y_index++;
        bg_w.quake_y_index &= 7;
        bgw_ptr->xy[1].disp.pos += end_500_quake_tbl[bg_w.quake_y_index];
        bgw_ptr->abs_y += end_500_quake_tbl[bg_w.quake_y_index];
    }
}

/* Rewritten to match retail (tools/permute.py): < 1 -> <= 0; < 193 -> <= 192; < -127 -> <= -128. */
void end_500_0007() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        overwrite_panel(0xFF000000, 0x17);
        bgw_ptr->r_no_1++;
        sub_000AF4C2(1);
        bgw_ptr->xy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = 768;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        effect_E6_init(0xF);
        effect_E6_init(0x49);
        break;

    case 1:
        break;

    case 2:
        bgw_ptr->r_no_1++;
        bgw_ptr->free = 0x28;
        break;

    case 3:
        bgw_ptr->free--;

        if (bgw_ptr->free <= 0) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 4:
        end_5_bg0_move_sub();

        if (bgw_ptr->xy[0].disp.pos <= 192) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x11);
            bg_w.quake_y_index = 0;
            bgw_ptr->frame_deff = 4;
        }

        break;

    case 5:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();

        if (bgw_ptr->xy[0].disp.pos <= -128) {
            bgw_ptr->r_no_1++;
            end_w.timer = 0;
        }

        break;
    }
}

/* Rewritten to match retail (tools/permute.py): < -1855 -> <= -1856. */
void end_500_0008() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        /* fallthrough */

    case 1:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();

        if (bgw_ptr->xy[0].disp.pos < -240) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x12);
        }

        break;

    case 2:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();

        if (bgw_ptr->xy[0].disp.pos < -624) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x14);
        }

        break;

    case 3:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();

        if (bgw_ptr->xy[0].disp.pos < -1008) {
            bgw_ptr->r_no_1++;
            effect_E6_init(0x15);
        }

        break;

    case 4:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();

        if (bgw_ptr->xy[0].disp.pos < -1376) {
            bgw_ptr->r_no_1++;
            end_etc_flag = 0;
            effect_E6_init(0x13);
        }

        break;

    case 5:
        end_5_bg0_move_sub();
        end_500_quake_y_sub();

        if (bgw_ptr->xy[0].disp.pos < -1472) {
            bgw_ptr->r_no_1++;
        }

        break;

    case 6:
        end_5_bg0_move_sub();

        if (bgw_ptr->xy[0].disp.pos <= -1856) {
            bgw_ptr->r_no_1++;
            end_w.timer = 18;
        }

        break;
    }
}

void end_500_0011() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        Rewrite_End_Message(6);
        bgw_ptr->r_no_1++;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        break;

    case 1:
        end_X_com01();
        break;
    }
}

void end_5_bg0_move_sub() {
    if (end_w.r_no_2 == 7) {
        bgw_ptr->xy[0].cal += 0xFFF60000;
    } else {
        bgw_ptr->xy[0].cal += 0xFFFA0000;
    }

    bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
}

/* Rewritten to match retail (tools/permute.py): < 193 -> <= 192. */
void end_5_bg1_move_sub() {
    bgw_ptr->xy[0].cal += 0xFFF00000;
    bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;

    if (bgw_ptr->xy[0].disp.pos <= 192) {
        if (bgw_ptr->xy[1].disp.pos == 768) {
            bgw_ptr->xy[0].disp.pos = bgw_ptr->abs_x = 448;
            bgw_ptr->xy[1].disp.pos = 512;
            return;
        }

        bgw_ptr->xy[0].disp.pos = bgw_ptr->abs_x = 704;
        bgw_ptr->xy[1].disp.pos = 768;
    }
}

void end_5_bg1_move_sub2() {
    bgw_ptr->xy[0].cal += 0x180000;
    bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;

    if (bgw_ptr->xy[1].disp.pos == 768) {
        if (bgw_ptr->xy[0].disp.pos >= 704) {
            bgw_ptr->xy[0].disp.pos = bgw_ptr->abs_x = 192;
            bgw_ptr->xy[1].disp.pos = 512;
        }
    } else if (bgw_ptr->xy[0].disp.pos >= 448) {
        bgw_ptr->xy[0].disp.pos = bgw_ptr->abs_x = 192;
        bgw_ptr->xy[1].disp.pos = 768;
    }
}

void end_501_move() {
    void (*end_501_jp[13])() = { end_X_com01,  end_X_com01,  end_X_com01,  end_X_com01,  end_X_com01,
                                 end_X_com01,  end_X_com01,  end_501_0007, end_501_0008, end_501_0009,
                                 end_501_0010, end_501_0011, end_501_0012 };
    bgw_ptr = &bg_w.bgw[1];
    end_501_jp[end_w.r_no_2]();
}

void end_501_0007() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        overwrite_panel(0xFF000000, 0x17);
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 512;
        bgw_ptr->xy[1].disp.pos = 768;
        bgw_ptr->abs_x = bgw_ptr->xy[0].disp.pos;
        bdl_index = 0;
        wr5_index = 0;
        end_5_flag = 512;
        /* fallthrough */

    case 1:
        if (Request_Fade(0)) {
            bgw_ptr->r_no_1++;
            end_no_cut = 1;
        }

        break;

    case 2:
        bgw_ptr->r_no_1++;
        sub_000AF4AA(2);
        /* fallthrough */

    case 3:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            bg_w.bgw[0].r_no_1 = 2;
        }

        /* fallthrough */

    case 4:
        end_5_bg1_move_sub();
        break;
    }
}

void end_501_0008() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        /* fallthrough */

    case 1:
        end_5_bg1_move_sub();
        break;
    }
}

void end_501_0009() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        wr5_index--;
        break;

    case 1:
        end_5_bg1_move_sub2();

        if (end_etc_flag) {
            bgw_ptr->r_no_1++;
            end_w.timer = 0;
        }

        break;
    }
}

void end_501_0010() {
    end_5_bg1_move_sub2();

    switch (bgw_ptr->r_no_1) {
    case 0:
        if (Request_Fade(3)) {
            bgw_ptr->r_no_1++;
            end_no_cut = 1;
        }

        break;

    case 1:
        if (end_fade_complete()) {
            bgw_ptr->r_no_1++;
            end_no_cut = 0;
            end_w.timer = 30;
            overwrite_panel(0xFFFFFFFF, 0x17);
        }

        break;

    case 2:
        overwrite_panel(0xFFFFFFFF, 0x17);
        break;
    }
}

void end_501_0011() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bgw_ptr->xy[0].disp.pos = 256;
        bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->abs_x = 512;
        bgw_ptr->abs_y = 0;
        effect_E6_init(0x10);
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

        /* fallthrough */

    case 3:
        bgw_ptr->xy[1].cal += 0x40000;

        if (bgw_ptr->xy[1].disp.pos >= 256) {
            bgw_ptr->xy[1].disp.pos = 0;
        }

        break;
    }
}

void end_501_0012() {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        effect_E6_init(0xE);
        end_fade_flag = 1;
        end_fade_timer = timer_5_tbl[end_w.r_no_2] - 120;
        /* fallthrough */

    case 1:
        bgw_ptr->xy[1].cal += 0x40000;

        if (bgw_ptr->xy[1].disp.pos >= 256) {
            bgw_ptr->xy[1].disp.pos = 0;
        }

        break;
    }
}
