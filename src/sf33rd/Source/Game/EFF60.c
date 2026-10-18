/* EFF60.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_60_move 0x3E636 size 0xB9.
 * effect_60_init 0x3E6EF size 0xF9. Read against the x86: +2 is data_ptr[1].
 * The C is the PS2 C.
 * all_cgps_put_back is folded into 0x4384A.
 * Data: flash_obj_data61 is 0x32AE60, 3 pointers whose arrays were compared.
 * Data: flash_0000 is 0x24F024, 0x14 bytes compared.
 * Data: flash_0001 is 0x24F038, 0x14 bytes compared.
 * Data: flash_0002 is 0x24F04C, 0x14 bytes compared.
 * Globals: flash_obj_data61 0x32AE60, char_add 0x332CC8, EXE_obroll 0x7A8111,
 * Game_pause 0x7A89B0, bg_w 0x7BC520, EXE_flag 0xC7C834, frw 0xC806A0.
 */

#include "structs.h"

#define EFFECT_MAX 128

void sub_0004384A(WORK* wk);
void set_char_move_init(WORK* wk, s16 koc, s16 index);
s32 compel_dead_check(WORK_Other* ewk);
extern s16 EXE_flag;
extern u8 Game_pause;
extern s8 EXE_obroll;
void char_move(WORK* wk);
void disp_pos_trans_entry_rs(WORK_Other* ewk);
void push_effect_work(WORK* wkhd);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];
extern u32* char_add[];
extern BG bg_w;
void suzi_offset_set(WORK_Other* ewk);
s16 get_my_trans_mode(s16 curr);

const s16 flash_0000[10] = { 0, 2, 300, 431, 80, 82, 1, 0, 0, 3 };

const s16 flash_0001[10] = { 0, 2, 300, 511, 184, 82, 2, 0, 0, 3 };

const s16 flash_0002[10] = { 0, 2, 300, 431, 64, 83, 2, 0, 0, 2 };

const s16* flash_obj_data61[3] = { flash_0000, flash_0001, flash_0002 };

/* Rewritten to match retail (tools/permute.py): set_char_move_init parameter 3: s16 -> s32; < 3 -> <= 2. */
void effect_60_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.disp_flag = 1;
        break;

    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }

        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            if (ewk->wu.type <= 2) {
                ewk->wu.disp_flag = 1;
                char_move(&ewk->wu);
            } else {
                ewk->wu.old_rno[1]--;

                if (ewk->wu.old_rno[1] <= 0) {
                    ewk->wu.disp_flag ^= 1;
                    ewk->wu.old_rno[1] = ewk->wu.old_rno[0];

                    if (ewk->wu.hit_stop) {
                        char_move(&ewk->wu);
                    }
                }
            }
        }

        disp_pos_trans_entry_rs(ewk);
        break;

    case 2:
        ewk->wu.routine_no[0]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_60_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    data_ptr = flash_obj_data61[type];
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 60;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.type = type;
    ewk->wu.dead_f = *data_ptr++;
    ewk->wu.my_family = *data_ptr++;
    ewk->wu.my_col_code = *data_ptr++;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.hit_stop = *data_ptr++;
    ewk->wu.sync_suzi = *data_ptr++;
    ewk->wu.old_rno[0] = *data_ptr++;
    ewk->wu.old_rno[1] = ewk->wu.old_rno[0];
    ewk->wu.char_table[0] = char_add[bg_w.bg_index];
    suzi_offset_set(ewk);
    ewk->wu.my_mts = 7;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    return 0;
}
