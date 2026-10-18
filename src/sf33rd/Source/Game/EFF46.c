/* EFF46.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * eff46_appear_check 0x3CDBA size 0x43.
 * effect_46_init 0x3CDFD size 0x131.
 * eff46_move 0x3CF2E size 0x9C.
 * effect_46_move 0x3CFCA size 0x72.
 * add_x_sub is folded into 0xEF072.
 * add_y_sub is folded into 0xEF088.
 * Data: _etc2_char_table is 0x2F77F0, the char table effect_46_init stores.
 * Globals: EXE_obroll 0x7A8111, Game_pause 0x7A89B0, bg_w 0x7BC520, EXE_flag
 * 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_000EF072(WORK_Other* ewk);
void sub_000EF088(WORK_Other* ewk);
void setup_shadow_of_the_Effy(WORK* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;
void eff46_move(WORK_Other* ewk);
void suzi_sync_pos_set(WORK_Other* ewk);
s32 sort_push_request(WORK* wk);
void push_effect_work(WORK* wkhd);
void char_move(WORK* wk);
s16 eff46_appear_check(WORK_Other* ewk);
s32 random_16();
s32 range_x_check3(WORK_Other* ewk, s16 optional_range);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern BG bg_w;
extern u32 _etc2_char_table[];
void suzi_offset_set(WORK_Other* ewk);
s16 get_my_trans_mode(s16 curr);



void effect_46_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        setup_shadow_of_the_Effy(&ewk->wu);
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;

    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            eff46_move(ewk);
        }

        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

void eff46_move(WORK_Other* ewk) {
    s16 work2;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        char_move(&ewk->wu);

        if (!eff46_appear_check(ewk)) {
            break;
        }

        ewk->wu.routine_no[1]++;
        work2 = random_16();

        if (work2 & 1) {
            set_char_move_init(&ewk->wu, 0, 44);
        } else {
            set_char_move_init(&ewk->wu, 0, 45);
        }

        break;

    case 1:
        char_move(&ewk->wu);

        if (ewk->wu.cg_type) {
            ewk->wu.routine_no[1]++;
        }

        break;

    case 2:
        char_move(&ewk->wu);
        sub_000EF072(ewk);

        if (ewk->wu.xyz[1].disp.pos >= ewk->wu.old_rno[0]) {
            sub_000EF088(ewk);
        }

        if (!range_x_check3(ewk, 64)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
        }

        break;

    default:
        ewk->wu.routine_no[0] = 2;
        break;
    }
}

s16 eff46_appear_check(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16 work = oya_ptr->xyz[0].disp.pos - ewk->wu.xyz[0].disp.pos;

    if (work < 0) {
        work = -work;
    }

    if (work > 48) {
        return 0;
    }

    work = oya_ptr->xyz[1].disp.pos - ewk->wu.xyz[1].disp.pos;

    if (work < 0) {
        work = -work;
    }

    if (work > 80) {
        return 0;
    }

    return 1;
}

s32 effect_46_init(WORK* wk, s32 /* unused */) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 46;
    ewk->master_id = wk->id;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 6;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;

    if (wk->id) {
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 112;
        ewk->wu.mvxy.a[0].sp = 0x50000;
        ewk->wu.mvxy.d[0].sp = 0x8000;
        ewk->wu.mvxy.a[1].sp = 0x30000;
        ewk->wu.mvxy.d[1].sp = -0x6000;
    } else {
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - 112;
        ewk->wu.mvxy.a[0].sp = -0x50000;
        ewk->wu.mvxy.d[0].sp = -0x8000;
        ewk->wu.mvxy.a[1].sp = 0x30000;
        ewk->wu.mvxy.d[1].sp = -0x6000;
    }

    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.old_rno[0] = ewk->wu.xyz[1].disp.pos;
    ewk->wu.my_priority = wk->my_priority - 12;
    ewk->wu.position_z = ewk->wu.my_priority - 12;
    *ewk->wu.char_table = _etc2_char_table;
    ewk->wu.char_index = 43;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(ewk);
    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
