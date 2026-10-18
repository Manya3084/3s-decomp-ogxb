/* EFF72.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_72_move 0x40BA7 size 0x7C.
 * effect_72_init 0x40C23 size 0xE7. Read against the x86: _hkg_char_table is
 * the char table store (0x3041D0); the debug ELF does not list it. The C is
 * the PS2 C.
 * all_cgps_put_back is folded into 0x4384A.
 * Data: _hkg_char_table is 0x3041D0, the char table effect_72_init stores.
 * Globals: EXE_obroll 0x7A8111, Game_pause 0x7A89B0, EXE_flag 0xC7C834, frw
 * 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_0004384A(WORK* wk);
s32 obr_no_disp_check();
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s16 EXE_flag;
extern u8 Game_pause;
void char_move(WORK* wk);
void disp_pos_trans_entry_r(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
extern s8 EXE_obroll;
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
s16 get_my_trans_mode(s16 curr);
extern u32 _hkg_char_table[];
void suzi_offset_set(WORK_Other* ewk);



void effect_72_move(WORK_Other* ewk) {
    WORK_Other* oya;

    if (obr_no_disp_check()) {
        return;
    }

    oya = (WORK_Other*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 0;
            }
        }

        disp_pos_trans_entry_r(ewk);
        break;

    default:
    case 2:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_72_init(WORK_Other* oya, u8 type_id) {
    WORK_Other* ewk;
    s16 ix;

    if (EXE_obroll) {
        return 0;
    }

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 72;
    ewk->wu.type = type_id;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->my_master = (u32*)oya;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 8492;
    ewk->wu.my_mts = 7;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.char_table[0] = _hkg_char_table;
    ewk->wu.xyz[0].disp.pos = 511;
    ewk->wu.xyz[1].disp.pos = 0;

    if (type_id) {
        ewk->wu.position_z = ewk->wu.my_priority = 10;
        ewk->wu.char_index = 8;
    } else {
        ewk->wu.position_z = ewk->wu.my_priority = 72;
        ewk->wu.char_index = 9;
    }

    ewk->wu.sync_suzi = 0;
    suzi_offset_set(ewk);
    return 0;
}
