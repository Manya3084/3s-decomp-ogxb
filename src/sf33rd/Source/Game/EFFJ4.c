/* SA shadow, retail sf33rd.xbe.
 * effect_J4_move is 0x4E3EB size 0x11A.
 * effect_J4_init is 0x4E505 size 0x65.
 * setup_sa_shadow is 0x4E56A size 0x1A.
 *
 * The move tests case 2, then case 1, then case 0. Case 1 decrements
 * dir_timer through a copy and stores it before the <= 0 test. The C keeps
 * the PlayStation 2 order.
 * SA_shadow_on is 0x7A82EE. Suicide is 0x7A8268. Game_pause is 0x7A89B0.
 * pcon_dp_flag is 0xC7D8D0. EXE_flag is 0xC7C834. base_y_pos is 0x7BC516.
 * test_flag is 0x7A8902. blink_timing is +2. dead_f is +0x20.
 * dir_timer is +0x9A. shell_ix is +0x330.
 * sort_push_requestA is 0x9D87F. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. frw is 0xC806A0, 0x700 bytes per object.
 */

#include "types.h"
#include "structs.h"



typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, blink_timing) == 2, "blink_timing");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_clear_level) == 0x24A, "clear");
_Static_assert(__builtin_offsetof(WORK, shell_ix) == 0x330, "shell_ix");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

extern u8 SA_shadow_on;
extern u8 Suicide[];
extern u8 Game_pause;
extern u8 pcon_dp_flag;
extern s16 EXE_flag;
extern s16 base_y_pos;
extern u8 test_flag;
extern EffectRow frw[];

void sort_push_requestA(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

void effect_J4_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.blink_timing = 0;
        ewk->wu.rl_flag = 0;

        if (ewk->wu.type) {
            SA_shadow_on = 1;
        }

        if (ewk->wu.dir_timer == 0xFF) {
            ewk->wu.dir_timer = 0x7FFF;
            ewk->wu.my_clear_level = 160;
        }

        ewk->wu.my_priority = ewk->wu.position_z = 71;
        ewk->wu.shell_ix[0] = 0;
        ewk->wu.shell_ix[1] = 384;
        ewk->wu.shell_ix[2] = -base_y_pos;
        ewk->wu.shell_ix[3] = 224;
        ewk->wu.position_x = 0;
        ewk->wu.position_y = 0;
        break;

    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            goto jump;
        }

        if (Game_pause == 129 && pcon_dp_flag == 0) {
            break;
        }

        if (ewk->wu.dir_timer != 0x7FFF && !Game_pause && !EXE_flag && --ewk->wu.dir_timer <= 0) {
        jump:
            ewk->wu.routine_no[0]++;

            if (ewk->wu.type) {
                SA_shadow_on = 0;
            }
        }

        sort_push_requestA(&ewk->wu);
        break;

    case 2:
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0]++;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_J4_init(u8 data2) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(5)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 194;
    ewk->wu.dir_timer = data2;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 8;

    if (data2 != 0xFF) {
        ewk->wu.type = 1;
    }

    ewk->wu.my_col_code = 1;
    ewk->wu.my_clear_level = 144;
    return 0;
}

s32 setup_sa_shadow(u8 unused, u8 data) {
    (void)unused;

    if (test_flag) {
        return -1;
    }

    return effect_J4_init(data);
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_J4_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.dead_f != 1 && Suicide[0] == 0 && (Game_pause != 0x81 || pcon_dp_flag)) {
            sort_push_requestA(&ewk->wu);
        }

        break;
    }
}
