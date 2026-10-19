/* Effect L8, retail sf33rd.xbe.
 * get_new_color_data_L8 is 0xBEE28 size 0x28 and is interior.
 * save_old_color_data is 0xBEE50 size 0x1B and is interior.
 * load_old_color_data is 0xBEE6B size 0x1B and is interior.
 * effect_L8_init is 0xBEE86 size 0x6D and is interior.
 * check_new_color_data_L8 is 0xBEEF3 size 0x28 and is
 * interior.
 * effect_L8_move is 0xBEF1B size 0xF6 and is interior.
 * The player test and the pull failure return through
 * their own epilogues. 0xBF011 stays unnamed.
 *
 * effect_L8_move case 0 picks the ColorRAM row with sete
 * and a shift. Case 1 shares the push_effect_work call
 * of case 2 and the default. The C keeps the
 * PlayStation 2 order. pl17_0_00 is 0x2861B8 and matches
 * the PlayStation 2 values. ColorRAM is 0x7AAD60.
 * spmv_ng_save is 0x7AAC20. push_effect_work stays
 * push_effect_work. pull_effect_work is 0x4A6A8.
 * palConvSrcToRam is named. frw is 0xC806A0 and each
 * object is 0x700 bytes.
 */

#include "types.h"
#include "structs.h"





typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, hit_adrs) == 0x10, "hit_adrs");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, step_xy_table) == 0x1E0, "step_xy_table");
_Static_assert(__builtin_offsetof(WORK, move_xy_table) == 0x1E4, "move_xy_table");
_Static_assert(__builtin_offsetof(WORK, zu_flag) == 0x2D0, "zu_flag");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(SA_WORK, ok) == 0xA, "sa ok");
_Static_assert(__builtin_offsetof(PLW, spmv_ng_flag) == 0x38C, "spmv_ng_flag");
_Static_assert(__builtin_offsetof(PLW, player_number) == 0x394, "player_number");
_Static_assert(__builtin_offsetof(PLW, sa) == 0x3C4, "sa");
_Static_assert(__builtin_offsetof(PLW, att_plus) == 0x432, "att_plus");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(__builtin_offsetof(WORK_Other, master_work_id) == 0x38C, "master_work_id");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
_Static_assert(__builtin_offsetof(WORK_Other, master_player) == 0x390, "master_player");
#endif

extern EffectRow frw[];
extern u16 ColorRAM[512][64];
extern u32 spmv_ng_save[2];

extern const s16 pl17_0_00[12];

u16 palConvSrcToRam(u16 col);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

void check_new_color_data_L8(WORK *wk);
void get_new_color_data_L8(WORK *wk, s16 *trom, s16 *tram);
void save_old_color_data(s16 *wram, s16 *tram);
void load_old_color_data(s16 *wram, s16 *tram);

void get_new_color_data_L8(WORK *wk, s16 *trom, s16 *tram) {
    s16 i;
    u16 col;

    for (i = 0; i < 12; i++) {
        col = *trom++;
        *tram++ = palConvSrcToRam(col);
    }
}

void save_old_color_data(s16 *wram, s16 *tram) {
    s16 i;

    for (i = 0; i < 12; i++) {
        *wram++ = *tram++;
    }
}

void load_old_color_data(s16 *wram, s16 *tram) {
    s16 i;

    for (i = 0; i < 12; i++) {
        *tram++ = *wram++;
    }
}

s32 effect_L8_init(PLW *wk) {
    WORK_Other *ewk;
    s16 ix;

    if (wk->player_number != 16) {
        return 0;
    }

    if ((ix = pull_effect_work(6)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 218;
    ewk->wu.work_id = 16;
    ewk->my_master = (u32 *)wk;
    ewk->master_id = wk->wu.id;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_player = wk->player_number;
    return 0;
}

void check_new_color_data_L8(WORK *wk) {
    get_new_color_data_L8(wk, (s16 *)wk->hit_adrs, wk->step_xy_table);
    get_new_color_data_L8(wk, (s16 *)wk->hit_adrs, wk->move_xy_table);
}

void effect_L8_move(WORK_Other *ewk) {
    PLW *mwk = (PLW *)ewk->my_master;
    s16 *save_old_col_ptr = (s16 *)&ewk->wu.zu_flag;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.hit_adrs = (u32 *)pl17_0_00;
        ewk->wu.step_xy_table = (s16 *)ColorRAM[(ewk->master_id == 1) * 16];
        ewk->wu.move_xy_table = ewk->wu.step_xy_table + 512;
        save_old_color_data(save_old_col_ptr, ewk->wu.step_xy_table);
        check_new_color_data_L8(&ewk->wu);
        mwk->att_plus = 14;
        spmv_ng_save[ewk->master_id] = mwk->spmv_ng_flag;
        mwk->spmv_ng_flag = (mwk->spmv_ng_flag | 48);
        break;

    case 1:
        if ((mwk->sa->ok == -1) && (ewk->wu.dead_f == 0)) {
            break;
        }

        ewk->wu.routine_no[0] += 1;
        load_old_color_data(save_old_col_ptr, ewk->wu.step_xy_table);
        load_old_color_data(save_old_col_ptr, ewk->wu.move_xy_table);
        mwk->att_plus = 8;
        mwk->spmv_ng_flag = spmv_ng_save[ewk->master_id];
        break;

    case 2:
        ewk->wu.routine_no[0] += 1;
        /* fallthrough */

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

const s16 pl17_0_00[12] = { 0, -278, -439, -569, -668, -1790, -2944, -732, -796, -893, -5054, -9216 };
