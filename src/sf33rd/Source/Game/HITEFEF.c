/* Effect attack against effect, retail sf33rd.xbe.
 * effect_at_vs_effect_dm is 0x60BB0 size 0x17B.
 *
 * Both dm_vital stores (128) come before the as->wu.att.dipsw test.
 * hf.hit.effect is chosen branchless: 2 when xyz[1] is above 0, else 1.
 * routine_no[2] is cleared before routine_no[1] is set. The C keeps the
 * PlayStation 2 order.
 * q_hit_push is 0xC7EB40. rl_flag is +0xA. hit_stop is +0x44. vital_new is
 * +0x9E. dm_vital is +0xA2. kind_of_waza is +0x20F. att.dipsw is +0x2C4.
 * dir_atthit is +0x2DE. att_hit_ok is +0x2E2. shell_vs_refrect is +0x2E9.
 * hf.hit.effect is +0x2F7. dm_dir is +0x30E. dm_rl is +0x310.
 * dm_kind_of_waza is +0x327. dm_refrect is +0x394 and refrected +0x395.
 * cal_hit_mark_pos is 0x5F8C0. cal_damage_vitality is folded into 0x96821.
 * effect_02_init is 0x320DC. hit_pattern_extdat_check is 0x5E894.
 */

#include "types.h"

typedef union {
    s32 cal;
    struct {
        s16 low;
        s16 pos;
    } disp;
} XY;

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[4];
    s16 work_id;
    s16 id;
    s8 rl_flag;
    u8 pad_rno[0x24 - 0xB];
    s16 routine_no[8];
    u8 pad_hs[0x44 - 0x34];
    s16 hit_stop;
    u8 pad_xyz[0x64 - 0x46];
    XY xyz[3];
    u8 pad_vit[0x9E - 0x70];
    s16 vital_new;
    u8 pad_dmv[0xA2 - 0xA0];
    s16 dm_vital;
    u8 pad_kw[0x20F - 0xA4];
    u8 kind_of_waza;
    u8 pad_att[0x2C4 - 0x210];
    struct {
        u8 dipsw;
    } att;
    u8 pad_dah[0x2DE - 0x2C5];
    s16 dir_atthit;
    u8 pad_ok[0x2E2 - 0x2E0];
    s8 att_hit_ok;
    u8 pad_svr[0x2E9 - 0x2E3];
    s8 shell_vs_refrect;
    u8 pad_hf[0x2F7 - 0x2EA];
    struct {
        struct {
            u8 effect;
        } hit;
    } hf;
    u8 pad_dd[0x30E - 0x2F8];
    s16 dm_dir;
    s8 dm_rl;
    u8 pad_dkw[0x327 - 0x311];
    u8 dm_kind_of_waza;
    u8 pad_end[0x388 - 0x328];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
    s16 master_player;
    s16 master_priority;
    s8 dm_refrect;
    s8 refrected;
} WORK_Other;

typedef struct {
    WORK wu;
} PLW;

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, vital_new) == 0x9E, "vital_new");
_Static_assert(__builtin_offsetof(WORK, dm_vital) == 0xA2, "dm_vital");
_Static_assert(__builtin_offsetof(WORK, kind_of_waza) == 0x20F, "kind_of_waza");
_Static_assert(__builtin_offsetof(WORK, att.dipsw) == 0x2C4, "dipsw");
_Static_assert(__builtin_offsetof(WORK, dir_atthit) == 0x2DE, "dir_atthit");
_Static_assert(__builtin_offsetof(WORK, att_hit_ok) == 0x2E2, "att_hit_ok");
_Static_assert(__builtin_offsetof(WORK, shell_vs_refrect) == 0x2E9, "svr");
_Static_assert(__builtin_offsetof(WORK, hf.hit.effect) == 0x2F7, "hf");
_Static_assert(__builtin_offsetof(WORK, dm_dir) == 0x30E, "dm_dir");
_Static_assert(__builtin_offsetof(WORK, dm_rl) == 0x310, "dm_rl");
_Static_assert(__builtin_offsetof(WORK, dm_kind_of_waza) == 0x327, "dkw");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, dm_refrect) == 0x394, "dm_refrect");
#endif

extern WORK *q_hit_push[];

void cal_hit_mark_pos(WORK *as, WORK *ds, s32 ix2, s32 ix);
void sub_00096821(PLW *as, PLW *ds);
s32 effect_02_init(WORK *wk, s32 dmgp, s32 mkst, s32 dmrl);
void hit_pattern_extdat_check(WORK *as);

void effect_at_vs_effect_dm(s16 ix2, s16 ix) {
    WORK_Other *as = (WORK_Other *)q_hit_push[ix2];
    WORK_Other *ds = (WORK_Other *)q_hit_push[ix];

    ds->wu.dm_rl = as->wu.rl_flag;
    as->wu.dm_rl = ds->wu.rl_flag;
    cal_hit_mark_pos(&as->wu, &ds->wu, ix2, ix);

    if (ds->wu.att.dipsw & 2) {
        if (as->wu.att.dipsw & 2) {
            ds->wu.dm_vital = 128;
            as->wu.dm_vital = 128;
        } else {
            ds->wu.dm_vital = 128;
            as->wu.dm_vital = 128;

            if (as->wu.shell_vs_refrect == 0) {
                as->dm_refrect = 1;
                as->refrected = 1;
                as->wu.att_hit_ok = 1;
            }
        }
    } else if (ds->wu.id == 13) {
        switch (as->wu.work_id) {
        case 4:
            ds->wu.dm_vital = as->wu.vital_new;
            as->wu.dm_vital = ds->wu.vital_new;

            if (ds->wu.dm_vital > ds->wu.vital_new) {
                ds->wu.dm_vital = ds->wu.vital_new;
            }

            if (as->wu.dm_vital > as->wu.vital_new) {
                as->wu.dm_vital = as->wu.vital_new;
            }

            break;

        default:
            break;
        }
    } else if (ds->wu.id == 122 || ds->wu.id == 123) {
        sub_00096821((PLW *)as, (PLW *)ds);
        as->wu.dm_vital = 256;
    } else {
        ds->wu.dm_vital = 256;
    }

    if (ds->wu.xyz[1].disp.pos > 0) {
        as->wu.hf.hit.effect = 2;
    } else {
        as->wu.hf.hit.effect = 1;
    }

    ds->wu.routine_no[1] = 1;
    ds->wu.routine_no[2] = 0;
    as->wu.hit_stop = ds->wu.hit_stop = 6;
    ds->wu.dm_dir = as->wu.dir_atthit;
    ds->wu.dm_kind_of_waza = as->wu.kind_of_waza;

    if (ds->wu.id == 122 || ds->wu.id == 123) {
        effect_02_init(&as->wu, 2, 1, ds->wu.dm_rl);
    }

    hit_pattern_extdat_check(&as->wu);
}
