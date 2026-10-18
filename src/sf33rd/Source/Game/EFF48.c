/* EFF48.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * eff48_0000 0x3D23E size 0x6B.
 * eff48_1000 0x3D2A9 size 0xDF.
 * effect_48_init 0x3D388 size 0x167. Read against the x86: 0x20 and 0xE0 are
 * the y offsets added to index * 4 in the two branches; the unnamed address is
 * the scr_obj table pointer array at 0x32AE08. The C is the PS2 C.
 * effect_48_move 0x3D4EF size 0x27.
 * add_y_sub is folded into 0xEF088.
 * disp_pos_trans_entry is folded into 0xEF0C0.
 * Data: eff48_num_tbl is 0x24E3C8, 0x2C bytes compared.
 * Data: eff48_data_tbl00 is 0x24E3F8, 0x150 bytes compared.
 * Data: eff48_data_tbl01 is 0x24E548, 0xD0 bytes compared.
 * Data: eff48_data_tbl02 is 0x24E618, 0x40 bytes compared.
 * Data: eff48_data_tbl03 is 0x24E658, 0x70 bytes compared.
 * Data: eff48_data_tbl04 is 0x24E6C8, 0x90 bytes compared.
 * Data: eff48_data_tbl05 is 0x24E758, 0x40 bytes compared.
 * Data: eff48_data_tbl06 is 0x24E798, 0x70 bytes compared.
 * Data: eff48_data_tbl07 is 0x24E808, 0xA0 bytes compared.
 * Data: eff48_data_tbl08 is 0x24E8A8, 0x60 bytes compared.
 * Data: eff48_data_tbl09 is 0x24E908, 0x40 bytes compared.
 * Data: eff48_data_tbl10 is 0x24E948, 0x60 bytes compared.
 * Data: eff48_data_tbl11 is 0x24E9A8, 0x50 bytes compared.
 * Data: eff48_data_tbl12 is 0x24E9F8, 0x130 bytes compared.
 * Data: eff48_data_tbl13 is 0x24EB28, 0x40 bytes compared.
 * Data: eff48_data_tbl14 is 0x24EB68, 0x50 bytes compared.
 * Data: eff48_data_tbl15 is 0x24EBB8, 0xE0 bytes compared.
 * Data: eff48_data_tbl16 is 0x24EC98, 0xB0 bytes compared.
 * Data: eff48_data_tbl17 is 0x24ED48, 0xA0 bytes compared.
 * Data: eff48_data_tbl18 is 0x24EDE8, 0x30 bytes compared.
 * Data: eff48_data_tbl19 is 0x24EE18, 0x40 bytes compared.
 * Data: eff48_data_tbl20 is 0x24EE58, 0xA0 bytes compared.
 * Data: eff48_data_tbl21 is 0x24EEF8, 0xD0 bytes compared.
 * Data: eff48_adrs_tbl: not located in the XBE, PS2 initializer kept.
 * Unnamed data used (not checked): effect_48_init: 0x32ae08.
 * Globals: eff48_num_tbl 0x24E3C8, _op_char_table 0x3059F0, op_obj_disp
 * 0xC7E19A, op_scrn_end 0xC7E1A0, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

typedef const s16* ConstShortArray;

void sub_000EF088(WORK_Other* ewk);
void sub_000EF0C0(WORK_Other* ewk);
void eff48_0000(WORK_Other* ewk);
void eff48_1000(WORK_Other* ewk);
extern s16 op_obj_disp;
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
void push_effect_work(WORK* wkhd);
extern s8 op_scrn_end;
void cal_all_speed_data(WORK* wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw);
s32 effect_36_init(u8 typenum);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);
extern u32 _op_char_table[];
void COLOR_COPYn(s16 dst, s16 colcd, s16 n);

const s16 eff48_num_tbl[22] = { 21, 13, 4, 7, 9, 4, 7, 10, 6, 4, 6, 5, 19, 4, 5, 14, 11, 10, 3, 4, 10, 13 };

const s16 eff48_data_tbl00[168] = {
    0,  0, 336, 112, 60, 0, 20,  1,  0,  0, 368, 112, 60, 0, 8,   1,  0,  0, 400, 112, 60, 0, 5,   1,  0,  0, 336, 80,
    60, 0, 5,   1,   0,  0, 368, 80, 60, 0, 16,  1,   0,  0, 392, 80, 60, 0, 9,   1,   0,  0, 416, 80, 60, 0, 3,   1,
    0,  0, 464, 80,  60, 0, 20,  1,  0,  0, 496, 80,  60, 0, 18,  1,  0,  0, 520, 80,  60, 0, 9,   1,  0,  0, 544, 80,
    60, 0, 12,  1,   0,  0, 576, 80, 60, 0, 15,  1,   0,  0, 608, 80, 60, 0, 7,   1,   0,  0, 640, 80, 60, 0, 25,  1,
    0,  0, 336, 48,  60, 0, 21,  1,  0,  0, 368, 48,  60, 0, 14,  1,  0,  0, 400, 48,  60, 0, 6,   1,  0,  0, 432, 48,
    60, 0, 15,  1,   0,  0, 464, 48, 60, 0, 12,  1,   0,  0, 496, 48, 60, 0, 4,   1,   0,  0, 528, 48, 60, 0, 19,  1
};

const s16 eff48_data_tbl01[104] = { 0,  0, 352, 224, 60, 0, 12,  1,   0,  0, 376, 224, 60, 0, 9,   1,   0,  0, 400, 224,
                                    60, 0, 22,  1,   0,  0, 432, 224, 60, 0, 5,   1,   0,  0, 352, 200, 60, 0, 20,  1,
                                    0,  0, 384, 200, 60, 0, 8,   1,   0,  0, 416, 200, 60, 0, 5,   1,   0,  0, 464, 200,
                                    60, 0, 12,  1,   0,  0, 496, 200, 60, 0, 5,   1,   0,  0, 528, 200, 60, 0, 7,   1,
                                    0,  0, 560, 200, 60, 0, 5,   1,   0,  0, 592, 200, 60, 0, 14,  1,   0,  0, 624, 200,
                                    60, 0, 4,   1 };

const s16 eff48_data_tbl02[32] = { 0, 0, 448, 128, 60, 0, 20, 1, 0, 0, 480, 128, 60, 0, 15, 1,
                                   0, 0, 544, 128, 60, 0, 2,  1, 0, 0, 576, 128, 60, 0, 5,  1 };

const s16 eff48_data_tbl03[56] = { 0,  0, 416, 128, 60, 0, 20,  1,   0,  0, 448, 128, 60, 0, 8,   1,   0,  0, 480, 128,
                                   60, 0, 5,   1,   0,  0, 544, 128, 60, 0, 2,   1,   0,  0, 576, 128, 60, 0, 5,   1,
                                   0,  0, 608, 128, 60, 0, 19,  1,   0,  0, 640, 128, 60, 0, 20,  1 };

const s16 eff48_data_tbl04[72] = { 0,  0, 376, 128, 60, 0, 15,  1,   0,  0, 408, 128, 60, 0, 6,   1,   0,  0, 456, 128,
                                   60, 0, 20,  1,   0,  0, 488, 128, 60, 0, 8,   1,   0,  0, 520, 128, 60, 0, 5,   1,
                                   0,  0, 568, 128, 60, 0, 2,   1,   0,  0, 600, 128, 60, 0, 5,   1,   0,  0, 632, 128,
                                   60, 0, 19,  1,   0,  0, 664, 128, 60, 0, 20,  1 };

const s16 eff48_data_tbl05[32] = { 0, 0, 448, 128, 60, 0, 25, 1, 0, 0, 480, 128, 60, 0, 15, 1,
                                   0, 0, 512, 128, 60, 0, 21, 1, 0, 0, 544, 128, 60, 0, 18, 1 };

const s16 eff48_data_tbl06[56] = { 0,  0, 416, 128, 60, 0, 4,   1,   0,  0, 448, 128, 60, 0, 5,   1,   0,  0, 480, 128,
                                   60, 0, 19,  1,   0,  0, 512, 128, 60, 0, 20,  1,   0,  0, 544, 128, 60, 0, 9,   1,
                                   0,  0, 576, 128, 60, 0, 14,  1,   0,  0, 608, 128, 60, 0, 25,  1 };

const s16 eff48_data_tbl07[80] = { 0,  0, 360, 128, 60, 0, 9,   1,   0,  0, 384, 128, 60, 0, 19,  1,   0,  0, 432, 128,
                                   60, 0, 15,  1,   0,  0, 464, 128, 60, 0, 21,  1,   0,  0, 496, 128, 60, 0, 20,  1,
                                   0,  0, 544, 128, 60, 0, 20,  1,   0,  0, 576, 128, 60, 0, 8,   1,   0,  0, 608, 128,
                                   60, 0, 5,   1,   0,  0, 640, 128, 60, 0, 18,  1,   0,  0, 672, 128, 60, 0, 5,   1 };

const s16 eff48_data_tbl08[48] = { 2, 1, 432, 64, 60, 2, 13, 1, 2, 1, 464, 64, 60, 2, 1,  1,
                                   2, 1, 496, 64, 60, 2, 11, 1, 2, 1, 528, 64, 60, 2, 15, 1,
                                   2, 1, 560, 64, 60, 2, 20, 1, 2, 1, 592, 64, 60, 2, 15, 1 };

const s16 eff48_data_tbl09[32] = { 2, 1, 368, 208, 60, 2, 18, 1, 2, 1, 400, 208, 60, 2, 5,  1,
                                   2, 1, 432, 208, 60, 2, 13, 1, 2, 1, 464, 208, 60, 2, 25, 1 };

const s16 eff48_data_tbl10[48] = { 0, 0, 368, 48, 60, 2, 4, 1, 0, 0, 400, 48, 60, 2, 21, 1,
                                   0, 0, 432, 48, 60, 2, 4, 1, 0, 0, 464, 48, 60, 2, 12, 1,
                                   0, 0, 496, 48, 60, 2, 5, 1, 0, 0, 528, 48, 60, 2, 25, 1 };

const s16 eff48_data_tbl11[40] = { 0,  0, 352, 208, 60, 2, 5,   1,   0,  0, 384, 208, 60, 2, 12,  1,   0,  0, 416, 208,
                                   60, 2, 5,   1,   0,  0, 448, 208, 60, 2, 14,  1,   0,  0, 480, 208, 60, 2, 1,   1 };

const s16 eff48_data_tbl12[152] = { 0,  0, 336, 112, 60, 0, 9,   1,   0,  0, 360, 112, 60, 0, 20,  1,  0,  0, 384, 112,
                                    60, 0, 33,  1,   0,  0, 416, 112, 60, 0, 19,  1,   0,  0, 336, 80, 60, 0, 1,   1,
                                    0,  0, 368, 80,  60, 0, 12,  1,   0,  0, 400, 80,  60, 0, 12,  1,  0,  0, 448, 80,
                                    60, 0, 1,   1,   0,  0, 480, 80,  60, 0, 2,   1,   0,  0, 512, 80, 60, 0, 15,  1,
                                    0,  0, 544, 80,  60, 0, 21,  1,   0,  0, 576, 80,  60, 0, 20,  1,  0,  0, 336, 48,
                                    60, 0, 22,  1,   0,  0, 360, 48,  60, 0, 9,   1,   0,  0, 384, 48, 60, 0, 3,   1,
                                    0,  0, 416, 48,  60, 0, 20,  1,   0,  0, 448, 48,  60, 0, 15,  1,  0,  0, 480, 48,
                                    60, 0, 18,  1,   0,  0, 512, 48,  60, 0, 25,  1 };

const s16 eff48_data_tbl13[32] = { 0, 0, 400, 200, 60, 2, 19, 1, 0, 0, 400, 152, 60, 2, 5,  1,
                                   0, 0, 400, 104, 60, 2, 1,  1, 0, 0, 400, 56,  60, 2, 14, 1 };

const s16 eff48_data_tbl14[40] = { 2,  2, 384, 208, 60, 2, 9,   1,  2,  2, 384, 168, 60, 2, 2,   1,  2,  2, 384, 128,
                                   60, 2, 21,  1,   2,  2, 384, 88, 60, 2, 11,  1,   2,  2, 384, 48, 60, 2, 9,   1 };

const s16 eff48_data_tbl15[112] = { 0,  0, 512, 80, 60, 0, 20,  1,  0,  0, 544, 80, 60, 0, 8,   1,  0,  0, 576, 80,
                                    60, 0, 5,   1,  0,  0, 608, 80, 60, 0, 18,  1,  0,  0, 640, 80, 60, 0, 5,   1,
                                    0,  0, 680, 80, 60, 0, 9,   1,  0,  0, 704, 80, 60, 0, 19,  1,  0,  0, 528, 48,
                                    60, 0, 14,  1,  0,  0, 560, 48, 60, 0, 15,  1,  0,  0, 608, 48, 60, 0, 12,  1,
                                    0,  0, 632, 48, 60, 0, 9,   1,  0,  0, 656, 48, 60, 0, 13,  1,  0,  0, 680, 48,
                                    60, 0, 9,   1,  0,  0, 704, 48, 60, 0, 20,  1 };

const s16 eff48_data_tbl16[88] = { 1,  144, 464, 224, 60,  0,   20,  1,   1,  144, 496, 224, 60,  0,   15,
                                   1,  1,   144, 544, 224, 60,  1,   20,  1,  1,   144, 576, 224, 60,  0,
                                   8,  1,   1,   144, 608, 224, 60,  0,   5,  1,   1,   112, 416, 48,  60,
                                   0,  19,  1,   1,   112, 448, 48,  60,  0,  16,  1,   1,   112, 472, 48,
                                   60, 0,   9,   1,   1,   112, 496, 48,  60, 0,   18,  1,   1,   112, 520,
                                   48, 60,  0,   9,   1,   1,   112, 544, 48, 60,  1,   20,  1 };

const s16 eff48_data_tbl17[80] = { 1, 144, 416, 224, 60, 0, 15, 1, 1, 144, 448, 224, 60, 1, 6,  1,
                                   1, 144, 496, 224, 60, 0, 1,  1, 1, 112, 448, 48,  60, 1, 6,  1,
                                   1, 112, 472, 48,  60, 0, 9,  1, 1, 112, 496, 48,  60, 0, 7,  1,
                                   1, 112, 528, 48,  60, 0, 8,  1, 1, 112, 560, 48,  60, 0, 20, 1,
                                   1, 112, 592, 48,  60, 0, 5,  1, 1, 112, 624, 48,  60, 0, 18, 1 };

const s16 eff48_data_tbl18[24] = { 0,  0, 528, 208, 60, 2, 25,  1,   0,  0, 576, 208,
                                   60, 2, 21,  1,   0,  0, 624, 208, 60, 2, 14,  1 };

const s16 eff48_data_tbl19[32] = { 0, 0, 640, 208, 60, 2, 25, 1, 0, 0, 640, 160, 60, 2, 1, 1,
                                   0, 0, 640, 112, 60, 2, 14, 1, 0, 0, 640, 64,  60, 2, 7, 1 };

const s16 eff48_data_tbl20[80] = { 1, 144, 480, 224, 60, 0, 20, 1, 1, 144, 512, 224, 60, 0, 8,  1,
                                   1, 144, 544, 224, 60, 1, 5,  1, 1, 144, 576, 224, 60, 0, 18, 1,
                                   1, 144, 608, 224, 60, 0, 5,  1, 1, 112, 400, 48,  60, 0, 3,  1,
                                   1, 112, 432, 48,  60, 0, 1,  1, 1, 112, 464, 48,  60, 0, 14, 1,
                                   1, 112, 512, 48,  60, 0, 2,  1, 1, 112, 544, 48,  60, 1, 5,  1 };

const s16 eff48_data_tbl21[104] = { 1,   160, 432, 224, 60,  0,   15,  1,   1,   160, 464, 224, 60,  1,   14,
                                    1,   1,   160, 496, 224, 60,  0,   12,  1,   1,   160, 528, 224, 60,  0,
                                    25,  1,   1,   128, 432, 224, 60,  0,   15,  1,   1,   128, 464, 224, 60,
                                    1,   14,  1,   1,   128, 496, 224, 60,  0,   5,   1,   1,   96,  416, 48,
                                    60,  0,   23,  1,   1,   96,  440, 48,  60,  0,   9,   1,   1,   96,  464,
                                    48,  60,  1,   14,  1,   1,   96,  496, 48,  60,  0,   14,  1,   1,   96,
                                    528, 48,  60,  0,   5,   1,   1,   96,  560, 48,  60,  0,   18,  1 };

ConstShortArray eff48_adrs_tbl[22] = { eff48_data_tbl00, eff48_data_tbl01, eff48_data_tbl02, eff48_data_tbl03,
                                       eff48_data_tbl04, eff48_data_tbl05, eff48_data_tbl06, eff48_data_tbl07,
                                       eff48_data_tbl08, eff48_data_tbl09, eff48_data_tbl10, eff48_data_tbl11,
                                       eff48_data_tbl12, eff48_data_tbl13, eff48_data_tbl14, eff48_data_tbl15,
                                       eff48_data_tbl16, eff48_data_tbl17, eff48_data_tbl18, eff48_data_tbl19,
                                       eff48_data_tbl20, eff48_data_tbl21 };

void effect_48_move(WORK_Other* ewk) {
    void (*eff48_jp[3])(WORK_Other*) = { eff48_0000, eff48_1000, eff48_0000 };
    eff48_jp[ewk->wu.routine_no[0]](ewk);
}

void eff48_0000(WORK_Other* ewk) {
    if (ewk->wu.old_rno[1] <= op_obj_disp) {
        ewk->wu.routine_no[1] = 0x63;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        /* fallthrough */

    case 1:
        if (op_obj_disp) {
            ewk->wu.routine_no[1] += 1;
            return;
        }

        sub_000EF0C0(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff48_1000(WORK_Other* ewk) {
    if (ewk->wu.old_rno[1] <= op_obj_disp) {
        ewk->wu.routine_no[1] = 0x63;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        op_scrn_end = 0;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.old_rno[0], ewk->wu.char_index, 0);
        ewk->wu.old_rno[3] = 10;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[3], ewk->wu.xyz[0].disp.pos, ewk->wu.old_rno[2], 2, 2);
        /* fallthrough */

    case 1:
        ewk->wu.old_rno[3] -= 1;

        if (ewk->wu.old_rno[3] < 0) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[2];
            op_scrn_end = 1;

            if (!ewk->wu.old_rno[4]) {
                switch (ewk->wu.type) {
                case 16:
                    effect_36_init(0x18);
                    break;

                case 17:
                    effect_36_init(0x19);
                    break;

                case 20:
                    effect_36_init(0x1A);
                    break;

                case 21:
                    effect_36_init(0x1B);
                    break;
                }
            }
        } else {
            sub_000EF088(ewk);
        }

        /* fallthrough */

    case 2:
        sub_000EF0C0(ewk);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

/* Located by their bytes (tools/locate_data.py): eff48_data_tbl01 is
 * 0x24E548. eff48_data_tbl02 is 0x24E618. eff48_data_tbl03 is 0x24E658.
 * eff48_data_tbl04 is 0x24E6C8. eff48_data_tbl05 is 0x24E758.
 * eff48_data_tbl06 is 0x24E798. eff48_data_tbl07 is 0x24E808.
 * eff48_data_tbl08 is 0x24E8A8. eff48_data_tbl09 is 0x24E908.
 * eff48_data_tbl10 is 0x24E948. eff48_data_tbl11 is 0x24E9A8.
 * eff48_data_tbl12 is 0x24E9F8. eff48_data_tbl13 is 0x24EB28.
 * eff48_data_tbl14 is 0x24EB68. eff48_data_tbl15 is 0x24EBB8.
 * eff48_data_tbl16 is 0x24EC98. eff48_data_tbl17 is 0x24ED48.
 * eff48_data_tbl18 is 0x24EDE8. eff48_data_tbl19 is 0x24EE18.
 * eff48_data_tbl20 is 0x24EE58. eff48_data_tbl21 is 0x24EEF8. */

/* The Xbox has no Debug_w test. */
s32 effect_48_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr;

    data_ptr = eff48_adrs_tbl[type];

    for (i = 0; i < eff48_num_tbl[type]; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }

        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 0x30;
        ewk->wu.work_id = 0x10;
        ewk->wu.type = type;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x12C;
        ewk->wu.my_family = 3;
        ewk->wu.my_mts = 9;
        ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
        ewk->wu.old_rno[4] = i;
        ewk->wu.char_table[0] = _op_char_table;
        ewk->wu.routine_no[0] = *data_ptr++;
        ewk->wu.old_rno[2] = *data_ptr++;

        if (ewk->wu.routine_no[0] == 2) {
            ewk->wu.my_col_code += ewk->wu.old_rno[2];
        }

        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.old_rno[1] = *data_ptr++;

        if (ewk->wu.old_rno[0] == 2) {
            COLOR_COPYn(0x10, ((ewk->wu.my_col_code & 0x1FF) + 0x38) * 4, 4);
            ewk->wu.my_col_code = 4;
        } else {
            COLOR_COPYn(0x30, ((ewk->wu.my_col_code & 0x1FF) + 8) * 4, 4);
            ewk->wu.my_col_code = 12;
        }
    }

    return 0;
}
