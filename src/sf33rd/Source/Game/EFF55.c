/* Effect 55, retail sf33rd.xbe.
 * effect_55_move is 0x3D9A8 size 0xFF.
 * effect_55_init is 0x3DAA7 size 0xA6.
 *
 * effect_55_move calls obr_no_disp_check before it saves any registers.
 * Cases 1 and 3 share one routine_no[0] increment, and cases 1 to 4 share
 * one disp_pos_trans_entry call. Case 3 tests xyz[1].disp.pos <= 96.
 * effect_55_init clears hit_stop and sync_suzi with "and word, 0" right
 * after get_my_trans_mode, and stores my_priority before position_z.
 * The C keeps the PS2 order.
 * _brz_char_table is 0x302E30. Game_pause is 0x7A89B0.
 * EXE_flag is 0xC7C834. frw is 0xC806A0, 0x700 bytes per object.
 * set_char_move_init is 0x200A9.
 * all_cgps_put_back stays sub_0004384A. suzi_offset_set is 0xB4052.
 * disp_pos_trans_entry is 0xEF0C0.
 * obr_no_disp_check is 0xEF0A2. get_my_trans_mode is 0xEF70B.
 * push_effect_work is 0x4AC6C. pull_effect_work is 0x4A6A8.
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
    s16 old_rno[8];
    s16 hit_stop;
    u8 pad_cgr[2];
    s8 cgromtype;
    u8 pad_pos[0x58 - 0x49];
    s16 position_z;
    u8 pad_xyz[0x64 - 0x5A];
    XY xyz[3];
    u8 pad_sync[0x76 - 0x70];
    s16 sync_suzi;
    u8 pad_ct[0x1AC - 0x78];
    u32 *char_table[1];
    u8 pad_col[0x23C - 0x1B0];
    s16 my_col_mode;
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_mts[0x24C - 0x244];
    s16 my_mts;
    u8 pad_tm[0x254 - 0x24E];
    s16 my_trans_mode;
    u8 pad_end[0x388 - 0x256];
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, hit_stop) == 0x44, "hit_stop");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[1].cal) == 0x68, "xyz1");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1pos");
_Static_assert(__builtin_offsetof(WORK, sync_suzi) == 0x76, "sync_suzi");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

extern u32 _brz_char_table[];
extern u8 Game_pause;
extern u16 EXE_flag;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
s16 get_my_trans_mode(s32 curr);
s32 obr_no_disp_check(void);
void set_char_move_init(WORK *wk, s16 koc, s32 index);
void sub_0004384A(WORK *wk);
void suzi_offset_set(WORK_Other *wk);
void disp_pos_trans_entry(WORK_Other *ewk);

void effect_55_move(WORK_Other *ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 3);
        break;

    case 1:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.xyz[1].cal += 0x3000;

            if (ewk->wu.xyz[1].disp.pos >= 128) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 300;
            }
        }

        disp_pos_trans_entry(ewk);
        break;

    case 2:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.routine_no[0]++;
            }
        }

        disp_pos_trans_entry(ewk);
        break;

    case 3:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.xyz[1].cal -= 0x4000;

            if (ewk->wu.xyz[1].disp.pos < 97) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 480;
            }
        }

        disp_pos_trans_entry(ewk);
        break;

    case 4:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] < 0) {
                ewk->wu.routine_no[0] = 1;
            }
        }

        disp_pos_trans_entry(ewk);
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_55_init(void) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 55;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 8492;
    ewk->wu.my_mts = 7;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.xyz[0].disp.pos = 511;
    ewk->wu.xyz[1].disp.pos = 96;
    ewk->wu.my_priority = 86;
    ewk->wu.position_z = 86;
    ewk->wu.hit_stop = 0;
    ewk->wu.sync_suzi = 0;
    ewk->wu.char_table[0] = _brz_char_table;
    suzi_offset_set(ewk);
    return 0;
}
