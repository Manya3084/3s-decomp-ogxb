/* Effect 96, retail sf33rd.xbe.
 * effect_96_move is 0x42691 size 0x9F.
 * effect_96_init is 0x42730 size 0xE1.
 *
 * effect_96_move shares one exit for the two "disp_flag = 0, routine_no[0]++"
 * paths and increments routine_no[0] before it clears disp_flag.
 * effect_96_init clears hit_stop with "and word, 0" right after work_id.
 * PLW player_number is +0x394. The C keeps the PS2 order.
 * Suicide[6] is 0x7A826E. Game_pause is 0x7A89B0. EXE_flag is 0xC7C834.
 * _ef13_char_table is 0x318500. frw is 0xC806A0, 0x700 bytes per object.
 * hit_stop is +0x44. cgromtype is +0x48. cg_type is +0x214.
 * set_char_move_init is 0x200A9. char_move is 0x2008E.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 * sort_push_request is 0x9DF9A.
 */

#include "types.h"
#include "structs.h"




typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, blink_timing) == 2, "blink_timing");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
_Static_assert(__builtin_offsetof(WORK_Other, master_player) == 0x390, "player");
_Static_assert(__builtin_offsetof(PLW, player_number) == 0x394, "player_number");
#endif

extern s8 Suicide[8];
extern u8 Game_pause;
extern u16 EXE_flag;
extern u32 _ef13_char_table[];
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void sort_push_request(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s32 index);
void char_move(WORK *wk);

void effect_96_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.char_table[0] = _ef13_char_table;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[6] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }

        if (ewk->wu.hit_stop) {
            ewk->wu.hit_stop--;
        } else if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0]++;
                break;
            }
        }

        sort_push_request(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_96_init(WORK *wk, u8 chix, s8 dspf, s32 /* unused */) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 96;
    ewk->wu.work_id = 16;
    ewk->wu.blink_timing = wk->blink_timing;
    ewk->wu.char_index = chix;
    ewk->wu.disp_flag = dspf;
    ewk->wu.hit_stop = 0;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.cgromtype = wk->cgromtype;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code;
    ewk->wu.my_mts = 14;
    ewk->wu.position_x = wk->position_x;
    ewk->wu.position_y = wk->position_y;
    ewk->wu.position_z = 26;

    if (wk->work_id == 1) {
        ewk->master_player = ((PLW *)wk)->player_number;
        ewk->master_id = wk->id;
    } else {
        ewk->master_player = ((WORK_Other *)wk)->master_player;
        ewk->master_id = ((WORK_Other *)wk)->master_id;
    }

    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_96_draw(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 1:
        if (ewk->wu.dead_f != 1 && Suicide[6] == 0 && ewk->wu.hit_stop != 0 &&
            (EXE_flag != 0 || Game_pause != 0 || ewk->wu.cg_type != 0xFF)) {
            sort_push_request(&ewk->wu);
        }

        break;
    }
}
