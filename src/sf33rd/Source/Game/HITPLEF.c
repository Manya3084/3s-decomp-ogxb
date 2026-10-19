/* Player attack against effect, retail sf33rd.xbe.
 * player_at_vs_effect_dm is 0x60F63 size 0x130.
 *
 * The hf.hit.player choice is branchless: 2 or 1 for an id 122/123 effect
 * on work_id 2, else 32 or 16, by whether xyz[1] is above 0. routine_no[2]
 * is cleared before routine_no[1] is set. The C keeps the PlayStation 2
 * order. The halving of hit_stop and dm_stop is a signed divide.
 * q_hit_push is 0xC7EB40. dm_rl is +0x310. dm_stop is +0x312. dm_vital is
 * +0xA2. hit_stop is +0x44. hf.hit.player is +0x2F6. att.dipsw is +0x2C4.
 * att_hit_ok is +0x2E2. charset_id is +5.
 * pp_pulpara_hit is 0x96C5B. cal_hit_mark_pos is 0x5F8C0.
 * cal_damage_vitality is folded into 0x96821. effect_02_init is 0x320DC.
 * dm_status_copy is 0x5F01F. hit_pattern_extdat_check is 0x5E894.
 */

#include "types.h"
#include "structs.h"





#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, charset_id) == 5, "charset_id");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, dm_vital) == 0xA2, "dm_vital");
_Static_assert(__builtin_offsetof(WORK, att.dipsw) == 0x2C4, "dipsw");
_Static_assert(__builtin_offsetof(WORK, att_hit_ok) == 0x2E2, "att_hit_ok");
_Static_assert(__builtin_offsetof(WORK, hf.hit.player) == 0x2F6, "hf");
_Static_assert(__builtin_offsetof(WORK, dm_rl) == 0x310, "dm_rl");
_Static_assert(__builtin_offsetof(WORK, dm_stop) == 0x312, "dm_stop");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

extern WORK *q_hit_push[];

void pp_pulpara_hit(WORK *wk);
void cal_hit_mark_pos(WORK *as, WORK *ds, s32 ix2, s32 ix);
void sub_00096821(PLW *as, PLW *ds);
s32 effect_02_init(WORK *wk, s32 dmgp, s32 mkst, s32 dmrl);
void dm_status_copy(WORK *as, WORK *ds);
void hit_pattern_extdat_check(WORK *as);

void player_at_vs_effect_dm(s16 ix2, s16 ix) {
    PLW *as = (PLW *)q_hit_push[ix2];
    WORK_Other *ds = (WORK_Other *)q_hit_push[ix];

    pp_pulpara_hit(&as->wu);
    ds->wu.dm_rl = as->wu.rl_flag;
    cal_hit_mark_pos(&as->wu, &ds->wu, ix2, ix);

    if (ds->wu.id == 122 || ds->wu.id == 123) {
        sub_00096821(as, (PLW *)ds);
    } else {
        ds->wu.dm_vital = 256;
    }

    if (ds->wu.work_id == 2 && (ds->wu.id == 122 || ds->wu.id == 123)) {
        if (ds->wu.xyz[1].disp.pos <= 0) {
            as->wu.hf.hit.player = 2;
        } else {
            as->wu.hf.hit.player = 1;
        }
    } else if (ds->wu.xyz[1].disp.pos <= 0) {
        as->wu.hf.hit.player = 32;
    } else {
        as->wu.hf.hit.player = 16;
    }

    ds->wu.routine_no[1] = 1;
    ds->wu.routine_no[2] = 0;

    if (ds->wu.work_id != 2 || ds->wu.id != 0x87) {
        if (ds->wu.att.dipsw & 2) {
            effect_02_init(&as->wu, 2, 2, ds->wu.dm_rl);
        } else if (ds->wu.id != 13) {
            effect_02_init(&as->wu, 2, 1, ds->wu.dm_rl);
        } else if (ds->wu.charset_id == 2) {
            effect_02_init(&as->wu, 2, 2, ds->wu.dm_rl);
        }
    }

    dm_status_copy(&as->wu, &ds->wu);

    if (ds->wu.work_id == 2 && ds->wu.id != 122 && ds->wu.id != 123) {
        as->wu.att_hit_ok = 1;
        as->wu.hit_stop /= 2;
        ds->wu.dm_stop /= 2;
    }

    hit_pattern_extdat_check(&as->wu);
}
