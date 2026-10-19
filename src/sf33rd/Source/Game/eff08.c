/* Bonus color rewrite, retail sf33rd.xbe.
 * effect_08_move is 0xB6BC1 size 0xD3 and is interior.
 * effect_08_init is 0xB6C94 size 0x6C and is a scanned start.
 * 0xB6D00 is effect_12_move.
 *
 * Suicide[5] is 0x7A826D. PB_Status is 0x7A8932.
 * Rewrite_Color_Data_08 is 0x2841C8 and matches the 52 bytes.
 * The rows were not pasted. The color store adds 0.
 * The sign-bit tail jump is written as a call.
 * sc_ram_to_vram_opc sign-extends type and zero-extends the
 * two position bytes and the color word.
 * pull_effect_work is 0x4A6A8. push_effect_work stays
 * push_effect_work. frw is 0xC806A0 and each object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"




typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, be_flag) == 0, "be_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, dir_step) == 0x98, "dir_step");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_priority) == 0x392, "master_priority");
#endif

extern s8 Suicide[8];
extern u8 PB_Status;
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const u8 Rewrite_Color_Data_08[2][13][2] = { { { 30, 2 },
                                               { 15, 2 },
                                               { 30, 2 },
                                               { 15, 2 },
                                               { 30, 2 },
                                               { 15, 2 },
                                               { 30, 2 },
                                               { 15, 2 },
                                               { 30, 2 },
                                               { 15, 2 },
                                               { 15, 255 },
                                               { 0, 0 },
                                               { 0, 0 } },
                                             { { 26, 2 },
                                               { 30, 2 },
                                               { 26, 2 },
                                               { 30, 2 },
                                               { 26, 2 },
                                               { 30, 2 },
                                               { 26, 2 },
                                               { 30, 2 },
                                               { 26, 2 },
                                               { 30, 2 },
                                               { 26, 255 },
                                               { 0, 0 },
                                               { 0, 0 } } };

extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void sc_ram_to_vram_opc(s8 sc_num, s8 x, s8 y, u16 atr);
void effect_08_move(WORK_Other *ewk);

void effect_08_move(WORK_Other *ewk) {
    if ((Suicide[5] & 0x80) != 0) {
        push_effect_work(&ewk->wu);
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if ((Suicide[5] & 1) != 0) {
            if ((PB_Status & 3) != 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.dir_timer = 1;
                ewk->wu.dir_step = 0;
            } else {
                ewk->wu.routine_no[0] = 99;
            }
        }

        break;

    case 1:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.my_col_code = Rewrite_Color_Data_08[ewk->master_priority][ewk->wu.dir_step][0] + 0;
            ewk->wu.dir_timer = Rewrite_Color_Data_08[ewk->master_priority][ewk->wu.dir_step][1];

            if (ewk->wu.dir_timer == 0xFF) {
                ewk->wu.routine_no[0] = 99;
            } else {
                ewk->wu.dir_step++;
            }
        }

        break;
    }

    sc_ram_to_vram_opc(ewk->wu.type, ewk->wu.position_x, ewk->wu.position_y, ewk->wu.my_col_code);
}

s32 effect_08_init(s8 sc_num, s8 x, s8 y, u16 atr, s16 color_type) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 8;
    ewk->wu.work_id = 16;
    ewk->wu.type = sc_num + 0;
    ewk->wu.position_x = x;
    ewk->wu.position_y = y;
    ewk->wu.my_col_code = atr;
    ewk->master_priority = color_type;
    effect_08_move(ewk);
    return 0;
}
