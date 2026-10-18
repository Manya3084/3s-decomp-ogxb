/* EFFA0.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_A0_move 0x42AF3 size 0x23.
 * effect_A0_init 0x42C07 size 0xD7.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: Setup_A0_Sub.
 * Setup_A0_Sub has no XBE name and no aligned call.
 * Data: Pos_Data_A0 is 0x24FB3C, 0x18 bytes compared, found by the bytes.
 * Globals: Pos_Data_A0 0x24FB3C, Menu_Suicide 0x7A87A0, bg_w 0x7BC520, frw
 * 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

extern u8 Menu_Suicide[4];
void push_effect_work(WORK* wkhd);
s32 sort_push_request3(WORK* wk);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);
extern BG bg_w;
void Convert_16_10_3(WORK_Other_CONN* ewk, u16 target);
void Setup_A0_Sub(WORK_Other_CONN* ewk, s16 old_rno, s16 zero);

const s16 Pos_Data_A0[4][3] = { { -52, 148, 69 }, { 140, 148, 69 }, { -52, 131, 69 }, { 140, 131, 69 } };

void effect_A0_move(WORK_Other_CONN* ewk) {
    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    sort_push_request3(&ewk->wu);
}

s32 effect_A0_init(s16 type, u16 disp_target, s16 pos_index, s16 old_rno, s16 zero, s16 target_bg, s16 master_player) {
    WORK_Other_CONN* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = 1;
    ewk->wu.id = 100;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 428;
    ewk->wu.type = type;
    ewk->wu.my_family = target_bg + 1;
    ewk->master_player = master_player;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Pos_Data_A0[pos_index][0];
    ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + Pos_Data_A0[pos_index][1];
    ewk->wu.position_z = Pos_Data_A0[pos_index][2];
    Convert_16_10_3(ewk, disp_target);
    Setup_A0_Sub(ewk, old_rno, zero);
    return 0;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void Setup_A0_Sub(WORK_Other_CONN* ewk, s16 old_rno, s16 zero) {
    ewk->num_of_conn = old_rno;
    ewk->conn[0].nx = 0;
    ewk->conn[0].ny = 0;
    ewk->conn[1].nx = 8;
    ewk->conn[1].ny = 0;

    switch (old_rno) {
    case 3:
        ewk->conn[0].chr = ewk->wu.old_rno[2] + 0x70D7;

        if (zero == 0 && ewk->wu.old_rno[2] == 0) {
            ewk->conn[0].ny -= 256;
        }

        ewk->conn[1].chr = ewk->wu.old_rno[1] + 0x70D7;

        if (zero == 0 && ewk->wu.old_rno[1] == 0 && ewk->wu.old_rno[2] == 0) {
            ewk->conn[1].ny -= 256;
        }

        ewk->conn[2].nx = 16;
        ewk->conn[2].ny = 0;
        ewk->conn[2].chr = ewk->wu.old_rno[0] + 0x70D7;
        break;

    case 2:
        ewk->conn[0].chr = ewk->wu.old_rno[1] + 0x70D7;

        if (zero == 0 && ewk->wu.old_rno[1] == 0) {
            ewk->conn[1].ny -= 256;
        }

        ewk->conn[1].chr = ewk->wu.old_rno[0] + 0x70D7;
        break;
    }
}
#endif
