/* Effect I3, retail sf33rd.xbe.
 * effect_I3_move is 0x4D09D size 0xFB.
 * effect_I3_init is 0x4D198 size 0x73.
 *
 * Case 1 of the source switch loads hit_stop unsigned, then compares it
 * signed and negates it, which is the PS2 absolute value. The move tests
 * the default case first.
 * i3_data is 0x257AB8, six bytes per entry: flag (u8) at +0, sour (s16)
 * at +2, tm (s16) at +4. bg_stop is 0x7BC4A0. Suicide is 0x7A8268.
 * EXE_flag is 0xC7C834. Game_pause is 0x7A89B0.
 * dead_f is +0x20. hit_stop is +0x44. dir_timer is +0x9A. now_koc is
 * +0x206. char_index is +0x208. cg_type is +0x214.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
 * frw is 0xC806A0, 0x700 bytes per object.
 */

#include "types.h"

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[2];
    u8 type;
    u8 pad_work[1];
    s16 work_id;
    s16 id;
    u8 pad_dead[0x20 - 0xA];
    s16 dead_f;
    u8 pad_rno[0x24 - 0x22];
    s16 routine_no[8];
    u8 pad_hs[0x44 - 0x34];
    s16 hit_stop;
    u8 pad_dir[0x9A - 0x46];
    s16 dir_timer;
    u8 pad_koc[0x206 - 0x9C];
    s16 now_koc;
    s16 char_index;
    u8 pad_cg[0x214 - 0x20A];
    u8 cg_type;
    u8 pad_end[0x388 - 0x215];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
} WORK_Other;

typedef struct {
    u8 flag;
    u8 pad;
    s16 sour;
    s16 tm;
} I3Data;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, now_koc) == 0x206, "now_koc");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(sizeof(I3Data) == 6, "I3Data");
#endif

extern const I3Data i3_data[];
extern s16 bg_stop;
extern u8 Suicide[];
extern s16 EXE_flag;
extern u8 Game_pause;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

void effect_I3_move(WORK_Other *ewk) {
    WORK *mwk = (WORK *)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        bg_stop = 1;

        switch (i3_data[ewk->wu.type].sour) {
        case 1:
            if ((ewk->wu.dir_timer = ewk->wu.hit_stop) < 0) {
                ewk->wu.dir_timer = -ewk->wu.dir_timer;
            }

            break;

        case 2:
            ewk->wu.dir_timer = ewk->wu.cg_type;
            break;

        default:
            ewk->wu.dir_timer = i3_data[ewk->wu.type].tm;
            break;
        }

        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.routine_no[0]++;
            break;
        }

        if (EXE_flag != 0 || Game_pause != 0) {
            break;
        }

        if ((i3_data[ewk->wu.type].flag & 1 && --ewk->wu.dir_timer < 0) ||
            (i3_data[ewk->wu.type].flag & 2 &&
             (ewk->wu.now_koc != mwk->now_koc || ewk->wu.char_index != mwk->char_index))) {
            ewk->wu.routine_no[0] = 2;
        }

        break;

    case 2:
    default:
        bg_stop = 0;
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_I3_init(WORK *wk, u8 tix) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 183;
    ewk->wu.work_id = 16;
    ewk->my_master = (u32 *)wk;
    ewk->wu.type = tix;
    ewk->wu.cg_type = wk->cg_type;
    ewk->wu.hit_stop = wk->hit_stop;
    ewk->wu.now_koc = wk->now_koc;
    ewk->wu.char_index = wk->char_index;
    return 0;
}
