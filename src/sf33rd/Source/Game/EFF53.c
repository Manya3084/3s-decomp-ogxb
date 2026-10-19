/* Effect 53, retail sf33rd.xbe.
 * effect_53_move is 0x3D72E size 0xB9.
 * effect_53_init is 0x3D7E7 size 0x46.
 *
 * effect_53_init stores old_rno[2] before be_flag. The C keeps the
 * PlayStation 2 order. old_rno is +0x34. cgromtype is +0x48.
 * EXE_flag is 0xC7C834. Game_pause is 0x7A89B0. EXE_obroll is 0x7A8111.
 * eff53_vanish_time is 0x24EFC8. frw is 0xC806A0, 0x700 bytes per object.
 * obr_no_disp_check is 0xEF0A2. random_16 is 0x9326B.
 * effect_54_init is 0x3D889. all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 */

#include "types.h"
#include "structs.h"



typedef uintptr_t EffectRow[448]; /* 0x700 bytes on the 32-bit retail build */

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

extern s16 EXE_flag;
extern u8 Game_pause;
extern u8 EXE_obroll;
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s16 eff53_vanish_time[8] = { 480, 600, 900, 1440, 480, 1080, 1500, 600 };

extern EffectRow frw[];

s32 obr_no_disp_check(void);
s16 random_16(void);
s16 pull_effect_work(s16 index);
void push_effect_work(WORK *wk);
void sub_0004384A(WORK *wk);
s32 effect_54_init(WORK_Other *oya);

void effect_53_move(WORK_Other *ewk) {
    s16 work;

    if (obr_no_disp_check()) {
        return;
    }

    if (EXE_flag || Game_pause || !EXE_obroll) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.old_rno[2]--;

        if (ewk->wu.old_rno[2] <= 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.old_rno[0] = 30;
            ewk->wu.old_rno[1] = 0;
            ewk->wu.disp_flag = 1;
        }

        break;

    case 1:
        ewk->wu.old_rno[0]--;

        if (ewk->wu.old_rno[0] > 0) {
            break;
        }

        ewk->wu.disp_flag ^= 1;
        ewk->wu.old_rno[0] = 30;

        if (ewk->wu.disp_flag) {
            break;
        }

        ewk->wu.old_rno[1]++;

        if (ewk->wu.old_rno[1] < 6) {
            break;
        }

        ewk->wu.routine_no[0] = 0;
        work = random_16();
        work &= 7;
        ewk->wu.old_rno[2] = eff53_vanish_time[work];
        ewk->wu.disp_flag = 0;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_53_init(void) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 53;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.disp_flag = 0;
    ewk->wu.old_rno[2] = 0;
    effect_54_init(ewk);
    return 0;
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_53_draw(WORK_Other* ewk) {
    obr_no_disp_check();
}
