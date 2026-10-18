/* EFF33.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_33_move 0x3ABE7 size 0x13B. Read against the x86: 0xFF is the
 * Event_Judge_Gals compare. The C is the PS2 C.
 * effect_33_init 0x3AD22 size 0xF9. Read against the x86: the +48/-48 choice
 * is branchless, 0x30 plus (-0x60 masked). The C is the PS2 C.
 * Data: WinLoseID is 0x24DDB4, 0x8 bytes compared.
 * Data: _etc3_char_table is 0x303250, the char table effect_33_init stores.
 * Globals: WinLoseID 0x24DDB4, Event_Judge_Gals 0x7A810E, Suicide 0x7A8268,
 * Winner_id 0x7A8472, Game_pause 0x7A89B0, Complete_Judgement 0x7A8A02,
 * EXE_flag 0xC7C834, pcon_rno 0xC7E020, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void set_char_move_init(WORK* wk, s16 koc, s16 index);
void suzi_sync_pos_set(WORK_Other* ewk);
s32 sort_push_request(WORK* wk);
extern s16 EXE_flag;
extern u8 Game_pause;
extern s16 pcon_rno[4];
extern s8 Event_Judge_Gals;
extern s8 Complete_Judgement;
extern s8 Winner_id;
extern s8 Suicide[8];
void char_move(WORK* wk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32 _etc3_char_table[];
void suzi_offset_set(WORK_Other* ewk);
s16 get_my_trans_mode(s16 curr);

const s16 WinLoseID[2][2];

const s16 WinLoseID[2][2] = { { 1, 0 }, { 0, 1 } };

void effect_33_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = -10;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);

        if (EXE_flag || Game_pause || pcon_rno[2] != 1 || Event_Judge_Gals != -1 || !Complete_Judgement) {
            break;
        }

        ewk->wu.routine_no[0]++;
        break;

    case 2:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[0]++;
            ewk->wu.char_index = WinLoseID[ewk->master_id][Winner_id] + 10;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 3:
        if (!EXE_flag && !Game_pause) {
            if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0]++;
                break;
            }

            char_move(&ewk->wu);
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    case 4:
        ewk->wu.routine_no[0]++;
        break;

    case 5:
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_33_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;
    s64 var_s1;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 33;
    ewk->wu.work_id = 16;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 1;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos;
    ewk->wu.xyz[0].disp.pos += wk->rl_flag ? -48 : 48;
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.my_priority = wk->my_priority - 12;
    ewk->wu.position_z = ewk->wu.my_priority - 12;
    ewk->wu.char_table[0] = _etc3_char_table;
    ewk->wu.char_index = 7;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(ewk);
    ewk->wu.my_mts = 0xE;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
