/* Eff95.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * xb_effect_95_draw 0x55E65 size 0x36. FLAG: x86-only callees
 * Ck_Range_Out_S,sort_push_request4.
 * effect_95_move 0x55E9B size 0x1E5. Read against the x86: the unnamed word at
 * 0xC80636 is the file's static counter (+3, wrapped above 9). The C is the
 * PS2 C.
 * effect_95_init 0x56080 size 0x115.
 * Data: RND_95: defined elsewhere on Xbox.
 * Data: END_OF_95 0xC80638.
 * Data: eff95_data_tbl is 0x25C058, 0x50 bytes compared.
 * Unnamed data used (not checked): effect_95_move: 0xc80636.
 * Globals: eff95_data_tbl 0x25C058, _sel_pl_char_table 0x2FE100, LOSER
 * 0x7A82FD, Continue_Cut 0x7A8420, Loser_id 0x7A875C, Break_Into 0x7A8802,
 * Continue_Count_Down 0x7A891A, Continue_Count 0x7A89D2, bg_w 0x7BC520,
 * END_OF_95 0xC80638, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

s32 sort_push_request4(WORK* wk);
s32 Ck_Range_Out_S(WORK_Other* ewk, s16 BG_No, s16 R);
extern void (*const D_0025B2C0[])(WORK* wk);
extern u8 Continue_Count_Down[2];
extern s8 LOSER;
void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
extern s8 Continue_Count[2];
extern u8 Continue_Cut[2];
extern s8 Loser_id;
s32 random_16();
extern s8 Break_Into;
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);
extern u32 _sel_pl_char_table[];
extern BG bg_w;

extern s16 RND_95;

extern s16 END_OF_95;

const s16 eff95_data_tbl[10][4] = { { 0, 0, 0, 0 }, { 0, 0, 1, 1 }, { 2, 2, 3, 3 }, { 4, 4, 5, 5 }, { 6, 6, 6, 7 },
                                    { 7, 7, 8, 8 }, { 8, 9, 9, 9 }, { 9, 9, 9, 9 }, { 9, 9, 9, 9 }, { 9, 9, 9, 9 } };

/* Rewritten to match retail (tools/permute.py): set_char_move_init2 parameter 3: s16 -> s32; set_char_move_init2 parameter 4: s16 -> s32. */
void effect_95_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!Continue_Count_Down[LOSER]) {
            ewk->wu.routine_no[0]++;
        }

        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    case 1:
        if (ewk->wu.dmcal_m != (Continue_Count[LOSER])) {
            if (!(ewk->wu.dmcal_m = Continue_Count[LOSER])) {
                if (Continue_Cut[Loser_id]) {
                    ewk->wu.routine_no[0] = 3;
                    ewk->wu.dir_step = 0;
                    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                } else {
                    ewk->wu.old_rno[5] = 6;
                    ewk->wu.old_rno[6] = 6;
                    ewk->wu.dir_step = 9;
                    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                }
            } else if (Continue_Count[LOSER] < 0) {
                ewk->wu.routine_no[0] = 3;
                ewk->wu.dir_step = 0;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            } else {
                ewk->wu.old_rno[5] = 6;
                ewk->wu.old_rno[6] = 6;
                ewk->wu.dir_step = 9;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
            }
        } else {
            switch (ewk->wu.vital_new) {
            case 4:
                ewk->wu.old_rno[5] = ewk->wu.old_rno[5] - 1;

                if (ewk->wu.old_rno[5] <= 0) {
                    ewk->wu.old_rno[5] = 6;
                    ewk->wu.dir_step = ewk->wu.dir_step - 1;

                    if (ewk->wu.dir_step <= 0) {
                        ewk->wu.dir_step = 0;
                    }

                    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                }

                break;

            case 8:
                ewk->wu.old_rno[6] = ewk->wu.old_rno[6] - 1;

                if (ewk->wu.old_rno[6] <= 0) {
                    ewk->wu.old_rno[6] = 6;
                }

                RND_95 = (random_16() >> 1) & 3;
                ewk->wu.dir_step = eff95_data_tbl[ewk->wu.old_rno[6]][RND_95];
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                break;

            default:
                RND_95 = (random_16() >> 1) & 7;
                RND_95 = RND_95 + 3;

                if (RND_95 > 9) {
                    RND_95 = 0;
                }

                ewk->wu.dir_step = RND_95;
                set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
                break;
            }
        }

        if (Break_Into) {
            ewk->wu.routine_no[0] = 2;
        }

        break;

    case 2:
        break;

    case 3:
        if (!Ck_Range_Out_S(ewk, 1, 64)) {
            break;
        }

        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        return;

    default:
        push_effect_work(&ewk->wu);
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    ewk->wu.position_z;
    sort_push_request4(&ewk->wu);
}

s32 effect_95_init(s16 vital_new) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 95;
    ewk->wu.work_id = 16;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.my_col_code = 0x2090;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.direction = 3;
    ewk->wu.vital_new = vital_new;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 85;
    ewk->wu.dmcal_m = Continue_Count[LOSER];
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos + 152;
    ewk->wu.position_z = 15;

    switch (vital_new) {
    case 1:
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 594;
        break;

    case 2:
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 570;
        break;

    case 8:
        ewk->wu.old_rno[6] = 6;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 538;
        break;

    case 4:
        END_OF_95 = 10;
        ewk->wu.old_rno[5] = 6;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 514;
        break;
    }

    ewk->wu.dir_step = 9;
    return 0;
}

void xb_effect_95_draw(WORK_Other* ewk) {
    if (ewk->wu.routine_no[0] == 3 && Ck_Range_Out_S(ewk, 1, 0x40)) {
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
    sort_push_request4(&ewk->wu);
}
