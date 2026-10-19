/* Effect 71, retail sf33rd.xbe.
 * effect_71_move is 0x40AAB size 0xB0.
 * effect_71_init is 0x40B5B size 0x4C.
 *
 * effect_71_init stores old_rno[0] before be_flag. The C keeps the
 * PlayStation 2 order. old_rno is +0x34. cgromtype is +0x48. rl_flag is +0xA.
 * EXE_flag is 0xC7C834. Game_pause is 0x7A89B0. EXE_obroll is 0x7A8111.
 * eff71_time_tbl is 0x24F64C. frw is 0xC806A0, 0x700 bytes per object.
 * obr_no_disp_check is 0xEF0A2. random_16 is 0x9326B.
 * effect_72_init is 0x40C23. all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 */

#include "types.h"
#include "structs.h"



typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

extern s16 EXE_flag;
extern u8 Game_pause;
extern u8 EXE_obroll;
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s16 eff71_time_tbl[8] = { 2, 8, 12, 9, 4, 6, 50, 3 };

extern EffectRow frw[];

s32 obr_no_disp_check(void);
s16 random_16(void);
s16 pull_effect_work(s16 index);
void push_effect_work(WORK *wk);
void sub_0004384A(WORK *wk);
s32 effect_72_init(WORK_Other *ewk, s16 type);

void effect_71_move(WORK_Other *ewk) {
    s16 work;

    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 1;
                ewk->wu.old_rno[1] = 0;
                effect_72_init(ewk, 0);
                effect_72_init(ewk, 1);
            }
        }

        break;

    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            ewk->wu.routine_no[0] = 0;
            ewk->wu.old_rno[1] = 0;
            work = random_16();
            work &= 7;
            ewk->wu.old_rno[0] = eff71_time_tbl[work];
        }

        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_71_init(void) {
    WORK_Other *ewk;
    s16 ix;

    if (EXE_obroll) {
        return 0;
    }

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 71;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.disp_flag = 0;
    ewk->wu.old_rno[0] = 0;
    return 0;
}
