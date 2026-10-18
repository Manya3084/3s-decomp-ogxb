/* EFFC0.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * xb_effect_C0_draw 0x44B9F size 0x47. FLAG: x86-only callees
 * sort_push_request8.
 * effect_C0_move 0x44BE6 size 0x15F.
 * effect_C0_init 0x44D45 size 0x8A.
 * Data: hok_table_ef is 0x252E78, 0x10 bytes compared.
 * Data: plhos_data is 0x252E88, 0x78 bytes compared.
 * Globals: hok_table_ef 0x252E78, plhos_data 0x252E88, _plef_char_table
 * 0x308B40, Suicide 0x7A8268, Game_pause 0x7A89B0, EXE_flag 0xC7C834, frw
 * 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

s32 sort_push_request8(WORK* wk);
extern const s16 plhos_data[20][3];
extern void (*const D_0024D368[17])();
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s8 Suicide[8];
extern s16 EXE_flag;
extern u8 Game_pause;
void char_move(WORK* wk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _plef_char_table[];

const s16 hok_table_ef[8] = { 1, 1, 2, 2, 3, 3, 3, 3 };

const s16 plhos_data[20][3] = { { 2, 136, 4 }, { 40, 92, 3 },  { -4, 104, 2 },  { 2, 92, 5 },   { 40, 88, 5 },
                                { 8, 94, 2 },  { 8, 106, 2 },  { 20, 78, 2 },   { 30, 96, 2 },  { 10, 88, 3 },
                                { 2, 92, 5 },  { -4, 104, 2 }, { -4, 104, 5 },  { 2, 136, 4 },  { -4, 104, 2 },
                                { 6, 90, 2 },  { -4, 104, 2 }, { -41, 127, 5 }, { -4, 104, 4 }, { -4, 104, 4 } };

void effect_C0_move(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;
    s16 i;
    s16 hok;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2020;
        set_char_move_init(&ewk->wu, 0, plhos_data[mwk->player_number][2]);
        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        if (mwk->wu.routine_no[1] != 1 || mwk->wu.routine_no[2] != 25) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        if (EXE_flag == 0 && Game_pause == 0 && mwk->sa_stop_flag != 1) {
            if (mwk->cp->lgp > 13) {
                hok = 3;
            } else {
                hok = hok_table_ef[mwk->cp->lgp / 2];
            }

            for (i = 0; i < hok; i++) {
                char_move(&ewk->wu);
            }
        }

        ewk->wu.position_x = mwk->wu.position_x;

        if (mwk->wu.rl_flag) {
            ewk->wu.position_x += plhos_data[mwk->player_number][0];
        } else {
            ewk->wu.position_x -= plhos_data[mwk->player_number][0];
        }

        ewk->wu.position_y = mwk->wu.position_y + plhos_data[mwk->player_number][1];
        ewk->wu.position_z = mwk->wu.position_z - 4;
        sort_push_request8(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_C0_init(PLW* wk, s32 /* unused */) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 120;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = wk->wu.my_family;
    ewk->wu.cgromtype = 1;
    ewk->wu.position_x = wk->wu.position_x;
    ewk->wu.position_y = wk->wu.position_y;
    ewk->wu.position_z = wk->wu.position_z - 4;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_id = wk->wu.id;
    *ewk->wu.char_table = _plef_char_table;
    return 0;
}

void xb_effect_C0_draw(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 1:
        ewk->wu.position_x = mwk->wu.position_x;
        ewk->wu.position_y = mwk->wu.position_y + plhos_data[mwk->player_number][1];
        ewk->wu.position_z = mwk->wu.position_z - 4;
        sort_push_request8(&ewk->wu);
        break;
    }
}
