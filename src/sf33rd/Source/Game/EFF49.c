/* EFF49.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_49_init 0x3D516 size 0xF9.
 * Setup_Char_49 0x3D60F size 0x2A.
 * effect_49_move 0x3D639 size 0xF0.
 * Globals: _sel_pl_char_table 0x2FE100, LOSER 0x7A82FD, Continue_Count
 * 0x7A89D2, bg_w 0x7BC520, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void set_char_move_init2(WORK* wk, s16 koc, s16 index, s16 ip, s16 scf);
extern s8 Continue_Count[2];
extern s8 LOSER;
void SsRequest(u16 ReqNumber);
u8 Setup_Char_49(WORK_Other* ewk);
s32 Ck_Range_Out_S(WORK_Other* ewk, s16 BG_No, s16 R);
void push_effect_work(WORK* wkhd);
s32 sort_push_request4(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _sel_pl_char_table[];
s16 get_my_trans_mode(s16 curr);
extern BG bg_w;



void effect_49_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    case 1:
        if (ewk->wu.dmcal_m == Continue_Count[LOSER]) {
            break;
        }

        ewk->wu.dmcal_m = Continue_Count[LOSER];

        if (Continue_Count[LOSER] < 0) {
            ewk->wu.routine_no[0]++;
        } else {
            SsRequest(0xA7);
            ewk->wu.dir_step = Setup_Char_49(ewk);
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }

        break;

    case 2:
        if (Ck_Range_Out_S(ewk, 1, 64)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            return;
        }

        break;

    default:
        push_effect_work(&ewk->wu);
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    ewk->wu.position_z;
    sort_push_request4(&ewk->wu);
}

s32 effect_49_init(s16 vital_new) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 49;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x2090;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.direction = 1;
    ewk->wu.vital_new = vital_new;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 84;
    ewk->wu.dmcal_m = Continue_Count[LOSER];
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[1].wxy[1].disp.pos + 8;
    ewk->wu.position_z = 15;

    if (vital_new == 4) {
        ix = Continue_Count[LOSER] & 0xF0;
        ix >>= 4;
        ewk->wu.dir_step = ix;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 450;
    } else {
        ix = Continue_Count[LOSER] & 0xF;
        ewk->wu.dir_step = ix;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 594;
    }

    return 0;
}

u8 Setup_Char_49(WORK_Other* ewk) {
    s16 xx;

    if (ewk->wu.vital_new == 4) {
        xx = Continue_Count[LOSER] & 0xF0;
        return (xx >>= 4);
    }

    return Continue_Count[LOSER] & 0xF;
}
