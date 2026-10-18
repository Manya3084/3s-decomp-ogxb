/* Effect E3, retail sf33rd.xbe.
 * effect_E3_move is 0xBC148 size 0x49D and is interior.
 * effect_E3_init is 0xBC5E5 size 0x8A and is interior.
 * The pull failure is an early ret.
 * 0xBC66F stays unnamed.
 *
 * effect_E3_move folds each run of spmv_ng_flag and
 * spmv_ng_flag2 updates into one and and one or, and
 * tests a single byte for the 0x200 and 0xD0000 bits.
 * Case 5 of the second training switch jumps to the
 * case 1 or case 3 stores. Case 6 divides the unsigned
 * Game_timer by 3. The init follows the PlayStation 2
 * order. Training is 0x7C5900.
 * Only Training[0] is read, and the TrainingData size
 * was not checked. Mode_Type is 0x7A825A.
 * New_Challenger is 0x7A86D6. Game_timer is 0x7A8830.
 * vib_sel is 0xC7D9D2. omop_vital_ix is 0x7C5C70.
 * omop_spmv_ng_table is 0xC7D8D8. omop_spmv_ng_table2
 * is 0xC7D9C8. demo_set_sa_full stays sub_00087CAD.
 * clear_super_arts_point stays sub_00085DF1.
 * push_effect_work stays sub_0004AC6C. pull_effect_work
 * stays sub_0004A6A8. tr_spgauge_cont_init and
 * tr_spgauge_cont_init2 are named. frw is 0xC806A0 and
 * each object is 0x700 bytes.
 */

#include "types.h"

typedef struct {
    s8 be_flag;
    u8 pad_work[5];
    s16 work_id;
    s16 id;
    u8 pad_myself[0x1A - 0xA];
    s16 myself;
    u8 pad_dead[0x20 - 0x1C];
    s16 dead_f;
    u8 pad_rno[2];
    s16 routine_no[8];
    u8 pad_dir[0x94 - 0x34];
    s16 direction;
    u8 pad_ds[2];
    s16 dir_step;
    s16 dir_timer;
    s16 vitality;
    u8 pad_dm[0xA2 - 0x9E];
    s16 dm_vital;
    u8 pad_e3[0x34E - 0xA4];
    s16 E3_work_index;
    u8 pad_end[0x388 - 0x350];
} WORK;

typedef struct {
    u8 pad_wf[0x16];
    s16 waza_flag[8];
} WAZA_WORK;

typedef struct {
    u8 pad_gk[2];
    s16 genkai;
    u8 pad_now[0xA - 4];
    struct {
        struct {
            s16 h;
        } quantity;
    } now;
} PLW_PY;

typedef struct {
    WORK wu;
    WAZA_WORK *cp;
    u32 spmv_ng_flag;
    u32 spmv_ng_flag2;
    s16 player_number;
    u8 pad_gc[0x3A7 - 0x396];
    s8 guard_chuu;
    u8 pad_sa[0x3C4 - 0x3A8];
    void *sa;
    u8 pad_py[4];
    PLW_PY *py;
    u8 pad_e3[0x450 - 0x3D0];
    u8 init_E3_flag;
    u8 tail[0x46C - 0x451];
} PLW;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
    s16 master_player;
    u8 pad_ng[6];
    u32 master_ng_flag;
    u32 master_ng_flag2;
} WORK_Other;

typedef struct {
    s8 contents[2][2][4];
} TrainingData;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, myself) == 0x1A, "myself");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, routine_no[2]) == 0x28, "rno2");
_Static_assert(__builtin_offsetof(WORK, direction) == 0x94, "direction");
_Static_assert(__builtin_offsetof(WORK, dir_step) == 0x98, "dir_step");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, vitality) == 0x9C, "vitality");
_Static_assert(__builtin_offsetof(WORK, dm_vital) == 0xA2, "dm_vital");
_Static_assert(__builtin_offsetof(WORK, E3_work_index) == 0x34E, "E3_work_index");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WAZA_WORK, waza_flag[7]) == 0x24, "waza_flag7");
_Static_assert(__builtin_offsetof(PLW_PY, genkai) == 2, "genkai");
_Static_assert(__builtin_offsetof(PLW_PY, now.quantity.h) == 0xA, "quantity.h");
_Static_assert(__builtin_offsetof(PLW, cp) == 0x388, "cp");
_Static_assert(__builtin_offsetof(PLW, spmv_ng_flag) == 0x38C, "spmv_ng_flag");
_Static_assert(__builtin_offsetof(PLW, spmv_ng_flag2) == 0x390, "spmv_ng_flag2");
_Static_assert(__builtin_offsetof(PLW, player_number) == 0x394, "player_number");
_Static_assert(__builtin_offsetof(PLW, guard_chuu) == 0x3A7, "guard_chuu");
_Static_assert(__builtin_offsetof(PLW, sa) == 0x3C4, "sa");
_Static_assert(__builtin_offsetof(PLW, py) == 0x3CC, "py");
_Static_assert(__builtin_offsetof(PLW, init_E3_flag) == 0x450, "init_E3_flag");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(__builtin_offsetof(WORK_Other, master_work_id) == 0x38C, "master_work_id");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
_Static_assert(__builtin_offsetof(WORK_Other, master_player) == 0x390, "master_player");
_Static_assert(__builtin_offsetof(WORK_Other, master_ng_flag) == 0x398, "master_ng_flag");
_Static_assert(__builtin_offsetof(WORK_Other, master_ng_flag2) == 0x39C, "master_ng_flag2");
_Static_assert(__builtin_offsetof(TrainingData, contents[0][1][3]) == 7, "contents");
#endif

extern EffectRow frw[];
extern TrainingData Training[];
extern u8 Mode_Type;
extern s8 New_Challenger;
extern u16 Game_timer;
extern u8 vib_sel[2];
extern s16 omop_vital_ix[2];
extern u32 omop_spmv_ng_table[2];
extern u32 omop_spmv_ng_table2[2];

void sub_00087CAD(void *sa);
void sub_00085DF1(PLW *wk);
void tr_spgauge_cont_init(s8 pl);
void tr_spgauge_cont_init2(s8 pl);
void sub_0004AC6C(WORK *wk);
s16 sub_0004A6A8(s16 index);

void effect_E3_move(WORK_Other *ewk) {
    PLW *mwk = (PLW *)ewk->my_master;
    s16 num;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if ((mwk->wu.E3_work_index != ewk->wu.myself || ewk->wu.dead_f != 0) || (Mode_Type != 3 && Mode_Type != 4)) {
            ewk->wu.routine_no[0] = 2;
            break;
        }

        if (mwk->init_E3_flag == 0) {
            break;
        }

        mwk->init_E3_flag = 0;

        if (Mode_Type != 3) {
            break;
        }

        if (mwk->wu.id == New_Challenger && Training[0].contents[0][0][0] != 4) {
            vib_sel[mwk->wu.id] = 0;
        }

        if (Training[0].contents[0][1][3] == 2) {
            vib_sel[mwk->wu.id] = 0;
        }

        ewk->wu.direction = 0;

        if (Training[0].contents[0][0][0] == 3 || Training[0].contents[0][0][0] == 4) {
            ewk->wu.direction = 1;
        }

        omop_vital_ix[mwk->wu.id] = 1;

        if (Training[0].contents[0][1][3] == 0) {
            omop_vital_ix[mwk->wu.id] = 3;
        }

        ewk->wu.dm_vital = 0;
        ewk->wu.vitality = 0;
        ewk->wu.dir_timer = 0;

        if (mwk->wu.id == New_Challenger) {
            mwk->py->now.quantity.h = 0;

            if (ewk->wu.direction == 0) {
                switch (Training[0].contents[0][0][1]) {
                case 0:
                case 1:
                case 6:
                    mwk->spmv_ng_flag &= 0xFFFFFFEF;
                    mwk->spmv_ng_flag |= 0xC0;
                    break;

                case 2:
                case 4:
                    mwk->spmv_ng_flag |= 0x80;
                    mwk->spmv_ng_flag &= 0xFFFFFFBF;
                    mwk->spmv_ng_flag &= 0xFFFFFFEF;
                    break;

                case 3:
                case 5:
                    mwk->spmv_ng_flag |= 0x40;
                    mwk->spmv_ng_flag &= 0xFFFFFF7F;
                    mwk->spmv_ng_flag &= 0xFFFFF0FF;
                    break;
                }
            } else {
                mwk->spmv_ng_flag |= 0xC0;
                mwk->spmv_ng_flag &= 0xFFFFFFEF;
                mwk->spmv_ng_flag &= 0xFFFFF0FF;
            }
        }

        switch (Training[0].contents[0][1][0]) {
        case 1:
            mwk->spmv_ng_flag2 &= 0xFFFBFFFF;
            mwk->spmv_ng_flag2 |= 0x90000;
            sub_00087CAD(mwk->sa);
            tr_spgauge_cont_init2(mwk->wu.id);
            break;

        case 3:
            mwk->spmv_ng_flag2 &= 0xFFF7FFFF;
            mwk->spmv_ng_flag2 |= 0x50000;
            sub_00087CAD(mwk->sa);
            tr_spgauge_cont_init2(mwk->wu.id);
            break;

        case 2:
            mwk->spmv_ng_flag2 &= 0xFFFEFFFF;
            mwk->spmv_ng_flag2 |= 0xC0000;
            sub_00085DF1(mwk);
            tr_spgauge_cont_init(mwk->wu.id);
            break;

        case 0:
            mwk->spmv_ng_flag2 |= 0xD0000;
            sub_00085DF1(mwk);
            tr_spgauge_cont_init(mwk->wu.id);
            break;
        }

        ewk->wu.routine_no[0]++;
        omop_spmv_ng_table[mwk->wu.id] = mwk->spmv_ng_flag;
        omop_spmv_ng_table2[mwk->wu.id] = mwk->spmv_ng_flag2;
        /* fallthrough */

    case 1:
        if ((mwk->wu.E3_work_index != ewk->wu.myself || ewk->wu.dead_f != 0) || (Mode_Type != 3 && Mode_Type != 4)) {
            ewk->wu.routine_no[0] = 2;
            break;
        }

        if (mwk->init_E3_flag == 1) {
            ewk->wu.routine_no[0] = 0;
            mwk->spmv_ng_flag = ewk->master_ng_flag;
            mwk->spmv_ng_flag2 = ewk->master_ng_flag2;
            break;
        }

        if (New_Challenger != mwk->wu.id) {
            break;
        }

        if (ewk->wu.direction == 0) {
            mwk->cp->waza_flag[7] = 2;

            switch (Training[0].contents[0][0][2]) {
            case 0:
            sw1_case_0:
                mwk->spmv_ng_flag2 |= 0x200;
                break;

            case 1:
            sw1_case_1:
                mwk->spmv_ng_flag2 &= 0xFFFFFDFF;
                break;

            default:
                if (Game_timer & 0xF) {
                    break;
                }

                switch (mwk->spmv_ng_flag2 & 0x200) {
                case 0:
                    goto sw1_case_0;

                default:
                    goto sw1_case_1;
                }

                break;
            }

            switch (Training[0].contents[0][0][1]) {
            case 0:
                if (mwk->wu.routine_no[1] == 1 || mwk->wu.routine_no[1] == 3) {
                    ewk->wu.dm_vital = 1;
                    ewk->wu.dir_timer = 12;
                } else {
                    ewk->wu.dm_vital = 0;
                }

                if (ewk->wu.dm_vital) {
                    mwk->spmv_ng_flag &= 0xFFFFFFBF;
                } else {
                    if (ewk->wu.dir_timer == 0) {
                        mwk->spmv_ng_flag |= 0x40;
                    } else {
                        ewk->wu.dir_timer--;
                    }
                }

                break;

            case 5:
                if ((Game_timer & 2) != 0) {
                    goto sw2_case_3;
                }

            case 1:
            sw2_case_1:
                mwk->spmv_ng_flag |= 0x80;
                mwk->spmv_ng_flag |= 0x40;
                mwk->spmv_ng_flag |= 0x10;
                break;

            case 2:
            sw2_case_2:
                mwk->spmv_ng_flag |= 0x80;
                mwk->spmv_ng_flag &= 0xFFFFFFBF;
                mwk->spmv_ng_flag &= 0xFFFFFFEF;
                break;

            case 6:
                num = Game_timer % 3;

                if (num == 1) {
                    goto sw2_case_1;
                }

                if (num == 2) {
                    goto sw2_case_2;
                }

            case 3:
            sw2_case_3:
                mwk->spmv_ng_flag |= 0x40;
                mwk->spmv_ng_flag &= 0xFFFFFF7F;
                mwk->spmv_ng_flag &= 0xFFFFF0FF;
                break;

            case 4:
                if ((mwk->wu.routine_no[1] == 1 && mwk->wu.routine_no[2] >= 4) && mwk->wu.routine_no[2] < 14) {
                    ewk->wu.dm_vital = 1;
                    ewk->wu.dir_timer = 12;
                } else {
                    ewk->wu.dm_vital = 0;
                }

                if (ewk->wu.dm_vital) {
                    mwk->spmv_ng_flag &= 0xFFFFFFBF;
                } else {
                    if (ewk->wu.dir_timer == 0) {
                        if ((Game_timer & 4) != 0) {
                            mwk->spmv_ng_flag &= 0xFFFFFFBF;
                        } else {
                            mwk->spmv_ng_flag |= 0x40;
                        }
                    } else {
                        ewk->wu.dir_timer--;
                    }
                }

                break;
            }
        }

        if (Training[0].contents[0][0][3] == 1) {
            if ((mwk->wu.routine_no[1] == 1 && mwk->guard_chuu == 0) || mwk->wu.routine_no[1] == 3) {
                ewk->wu.vitality = 1;
                ewk->wu.dir_step = 20;
            } else {
                ewk->wu.vitality = 0;
            }

            if (ewk->wu.vitality == 0) {
                if (ewk->wu.dir_step == 0) {
                    mwk->py->now.quantity.h = mwk->py->genkai - 1;
                } else {
                    ewk->wu.dir_step--;
                }
            }
        }

        break;

    case 2:
    default:
        sub_0004AC6C(&ewk->wu);
        break;
    }
}

s32 effect_E3_init(PLW *wk) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = sub_0004A6A8(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 143;
    ewk->wu.work_id = 16;
    ewk->my_master = (u32 *)wk;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_id = wk->wu.id;
    ewk->master_player = wk->player_number;
    ewk->master_ng_flag = wk->spmv_ng_flag;
    ewk->master_ng_flag2 = wk->spmv_ng_flag2;
    wk->init_E3_flag = 1;
    wk->wu.E3_work_index = ewk->wu.myself;
    return 0;
}
