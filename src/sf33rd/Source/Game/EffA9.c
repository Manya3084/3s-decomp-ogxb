/* EffA9.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_A9_move 0x565AA size 0x186.
 * Setup_A9 0x56730 size 0x6F.
 * effect_A9_init 0x5679F size 0xD4. Read against the x86: the unnamed words
 * are a four-short position record table at 0x267AE8. The C is the PS2 C.
 * Unnamed data used (not checked): effect_A9_init:
 * 0x267ae8,0x267aea,0x267aec,0x267aee.
 * Globals: _sel_pl_char_table 0x2FE100, Suicide 0x7A8268, LOSER 0x7A82FD,
 * Offset_BG_X 0x7A87B0, E_07_Flag 0x7A88EC, bg_w 0x7BC520, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
s32 Ck_Range_Out_S(WORK_Other* ewk, s16 BG_No, s16 R);
extern s8 Suicide[8];
extern s8 E_07_Flag[2];
extern s8 LOSER;
void SsRequest(u16 ReqNumber);
void char_move(WORK* wk);
void push_effect_work(WORK* wkhd);
s32 sort_push_request4(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);
extern s16 Offset_BG_X[6];
extern BG bg_w;
extern const s16 Position_Data_A9[][4];
void Setup_A9(WORK_Other* ewk, s16 Char_Index, s16 Option, s16 Option2);
s32 effect_59_init(WORK_Other* mwk, s16 Synchro_BG, s16 ID, s16 direction);



void effect_A9_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    case 1:
        if (!Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.vital_new)) {
            ewk->wu.disp_flag = 1;
            ewk->wu.routine_no[0]++;
        }

        break;

    case 2:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.vital_new) || Suicide[3] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 99;
            break;
        }

        if (ewk->wu.char_index == 55) {
            if (E_07_Flag[LOSER]) {
                ewk->wu.routine_no[0]++;
                ewk->wu.dir_timer = 20;
                SsRequest(0x62);
            }

            break;
        }

        if (ewk->wu.char_index == 57) {
            char_move(&ewk->wu);
        }

        break;

    case 3:
        char_move(&ewk->wu);

        if (--ewk->wu.dir_timer == 0) {
            if (ewk->wu.cg_type == 1) {
                ewk->wu.dir_timer = 1;
            } else {
                ewk->wu.routine_no[0] = 4;
            }
        }

        break;

    case 4:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.vital_new) || Suicide[3] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 99;
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
    sort_push_request4(&ewk->wu);
}

s32 effect_A9_init(s16 Char_Index, s16 Option, s16 Pos_Index, s16 Option2) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 109;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 144;
    ewk->wu.my_family = 4;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.char_index = Char_Index;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.xyz[0].disp.pos = Offset_BG_X[3] + bg_w.bgw[3].wxy[0].disp.pos + Position_Data_A9[Pos_Index][0];
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[3].wxy[1].disp.pos + Position_Data_A9[Pos_Index][1];
    ewk->wu.xyz[2].disp.pos = Position_Data_A9[Pos_Index][2];
    ewk->wu.vital_new = Position_Data_A9[Pos_Index][3];
    Setup_A9(ewk, Char_Index, Option, Option2);
    return 0;
}

void Setup_A9(WORK_Other* ewk, s16 Char_Index, s16 Option, s16 Option2) {
    switch (Char_Index) {
    case 32:
        if (Option2) {
            effect_59_init(ewk, ewk->wu.my_family, 4, 1);
        }

        /* fallthrough */

    case 33:
    case 34:
    case 81:
    case 12:
    case 16:
    case 79:
    case 6:
    case 80:
    case 58:
    case 60:
    case 59:
        ewk->wu.dir_step = Option;
        break;
    }
}
