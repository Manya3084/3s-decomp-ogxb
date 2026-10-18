/* Effect 97, retail sf33rd.xbe.
 * effect_97_move is 0xB88A6 size 0x17F and is interior.
 * effect_97_init is 0xB8A25 size 0xF2 and is interior.
 * The pull failure is an early ret.
 * 0xB888D stays unnamed. 0xB8B17 stays unnamed.
 *
 * Case 0 stores routine_no[0] and disp_flag between the
 * pushes and the call. Case 2 flips rl_flag before the
 * routine store, and that store sits between the pushes
 * and the call. The init stores the x position between
 * the push and my_mts, and my_trans_mode between the
 * push and suzi_offset_set. The C keeps the PlayStation 2
 * order. Cases 1, 2, and 3 share the suzi tail. The C
 * keeps the three copies. plw is 0xC7CEA0, stride 0x46C.
 * The character table immediate is 0x2F9850. Those bytes
 * were not compared. EXE_flag is 0xC7C834. Game_pause is
 * 0x7A89B0. char_move is 0x2008E.
 * set_char_move_init is 0x200A9. add_x_sub stays
 * add_x_sub. add_y_sub is folded into 0xEF088.
 * suzi_sync_pos_set is 0xB3627. suzi_offset_set
 * stays suzi_offset_set. sort_push_request4 stays
 * sort_push_request4. all_cgps_put_back stays sub_0004384A.
 * push_effect_work is 0x4AC6C. pull_effect_work
 * stays pull_effect_work. get_my_trans_mode is named.
 * frw is 0xC806A0 and each object is 0x700 bytes.
 * 0xB6890 stays unnamed. 0xB61A0 stays unnamed.
 * 0xB7EC3 stays unnamed. 0xB82C0 stays unnamed.
 */

#include "types.h"

typedef union {
    s32 cal;
    struct {
        s16 low;
        s16 pos;
    } disp;
} XY;

typedef union {
    s32 sp;
} Reg32SpReal;

typedef struct {
    Reg32SpReal a[2];
    Reg32SpReal d[2];
    s16 kop[2];
    u16 index;
} MVXY;

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[2];
    u8 type;
    u8 pad_work[1];
    s16 work_id;
    s16 id;
    s8 rl_flag;
    u8 pad_dead[0x15];
    s16 dead_f;
    u8 pad_rno[2];
    s16 routine_no[8];
    s16 old_rno[8];
    u8 pad_cg[4];
    s8 cgromtype;
    u8 kage_flag;
    s16 kage_hx;
    s16 kage_hy;
    s16 kage_prio;
    s16 kage_width;
    s16 kage_char;
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_sync[6];
    s16 sync_suzi;
    u8 pad_mv[4];
    MVXY mvxy;
    u8 pad_ct[0x1AC - 0x94];
    u32 *char_table[1];
    u8 pad_col[0x23C - 0x1B0];
    s16 my_col_mode;
    s16 my_col_code;
    s16 my_priority;
    s16 my_family;
    u8 pad_mts[8];
    s16 my_mts;
    u8 pad_tm[6];
    s16 my_trans_mode;
    u8 pad_end[0x132];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
} WORK_Other;

typedef struct {
    WORK wu;
    u8 tail[0x46C - 0x388];
} PLW;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(sizeof(MVXY) == 0x18, "MVXY");
_Static_assert(__builtin_offsetof(MVXY, a[0].sp) == 0, "a0");
_Static_assert(__builtin_offsetof(MVXY, a[1].sp) == 4, "a1");
_Static_assert(__builtin_offsetof(MVXY, d[0].sp) == 8, "d0");
_Static_assert(__builtin_offsetof(MVXY, d[1].sp) == 0xC, "d1");
_Static_assert(__builtin_offsetof(WORK, disp_flag) == 1, "disp_flag");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, routine_no[2]) == 0x28, "rno2");
_Static_assert(__builtin_offsetof(WORK, routine_no[3]) == 0x2A, "rno3");
_Static_assert(__builtin_offsetof(WORK, old_rno) == 0x34, "old_rno");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, kage_flag) == 0x49, "kage_flag");
_Static_assert(__builtin_offsetof(WORK, kage_hx) == 0x4A, "kage_hx");
_Static_assert(__builtin_offsetof(WORK, kage_hy) == 0x4C, "kage_hy");
_Static_assert(__builtin_offsetof(WORK, kage_prio) == 0x4E, "kage_prio");
_Static_assert(__builtin_offsetof(WORK, kage_char) == 0x52, "kage_char");
_Static_assert(__builtin_offsetof(WORK, position_z) == 0x58, "position_z");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, sync_suzi) == 0x76, "sync_suzi");
_Static_assert(__builtin_offsetof(WORK, mvxy) == 0x7C, "mvxy");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[0].sp) == 0x7C, "a0sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.a[1].sp) == 0x80, "a1sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[0].sp) == 0x84, "d0sp");
_Static_assert(__builtin_offsetof(WORK, mvxy.d[1].sp) == 0x88, "d1sp");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, my_col_mode) == 0x23C, "my_col_mode");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(__builtin_offsetof(WORK, my_priority) == 0x240, "my_priority");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(__builtin_offsetof(WORK, my_mts) == 0x24C, "my_mts");
_Static_assert(__builtin_offsetof(WORK, my_trans_mode) == 0x254, "my_trans_mode");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(__builtin_offsetof(PLW, wu.id) == 8, "plw id");
_Static_assert(__builtin_offsetof(PLW, wu.routine_no[2]) == 0x28, "plw rno2");
_Static_assert(__builtin_offsetof(PLW, wu.routine_no[3]) == 0x2A, "plw rno3");
#endif

extern EffectRow frw[];
extern s16 EXE_flag;
extern u8 Game_pause;
extern PLW plw[2];

void char_move(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s16 index);
void sub_000EF072(WORK_Other *ewk);
void sub_000EF088(WORK_Other *ewk);
void suzi_sync_pos_set(WORK_Other *ewk);
void sort_push_request4(WORK *wk);
void sub_0004384A(WORK *wk);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void suzi_offset_set(WORK_Other *ewk);
s16 get_my_trans_mode(s16 curr);

void effect_97_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 44);
        /* fallthrough */

    case 1:
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);

            if (plw[ewk->master_id].wu.routine_no[2] == 1 &&
                plw[ewk->master_id].wu.routine_no[3] == 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.old_rno[0] = 16;
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request4(&ewk->wu);
        break;

    case 2:
        if (EXE_flag == 0 && Game_pause == 0) {
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] > 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.rl_flag ^= 1;
                set_char_move_init(&ewk->wu, 0, 45);
                ewk->wu.old_rno[0] = 16;
                ewk->wu.mvxy.a[1].sp = 0xE8000;
                ewk->wu.mvxy.d[1].sp = -0x6000;

                if (plw[ewk->master_id].wu.id != 0) {
                    ewk->wu.mvxy.a[0].sp = -0xA8000;
                    ewk->wu.mvxy.d[0].sp = -0x1000;
                } else {
                    ewk->wu.mvxy.a[0].sp = 0xA8000;
                    ewk->wu.mvxy.d[0].sp = 0x1000;
                }
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request4(&ewk->wu);
        break;

    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            ewk->wu.old_rno[0]--;

            if (ewk->wu.old_rno[0] > 0) {
                sub_000EF072(ewk);
                sub_000EF088(ewk);
            } else {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 0;
            }
        }

        suzi_sync_pos_set(ewk);
        sort_push_request4(&ewk->wu);
        break;

    case 4:
        ewk->wu.routine_no[0]++;
        break;

    default:
        sub_0004384A(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_97_init(PLW *oya) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 97;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->my_master = (u32 *)oya;
    ewk->master_id = oya->wu.id;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = oya->wu.my_col_code;
    ewk->wu.my_family = 2;
    ewk->wu.my_priority = ewk->wu.position_z = oya->wu.my_priority;
    ewk->wu.sync_suzi = 0;
    ewk->wu.xyz[1].disp.pos = 40;
    ewk->wu.kage_flag = 1;
    ewk->wu.kage_hx = 0;
    ewk->wu.kage_hy = 40;
    ewk->wu.kage_prio = 71;
    ewk->wu.kage_char = 20;
    ewk->wu.char_table[0] = (u32 *)0x2F9850;

    if (oya->wu.id != 0) {
        ewk->wu.rl_flag = 0;
        ewk->wu.xyz[0].disp.pos = oya->wu.xyz[0].disp.pos - 108;
    } else {
        ewk->wu.rl_flag = 1;
        ewk->wu.xyz[0].disp.pos = oya->wu.xyz[0].disp.pos + 108;
    }

    ewk->wu.my_mts = 14;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    suzi_offset_set(ewk);
    return 0;
}
