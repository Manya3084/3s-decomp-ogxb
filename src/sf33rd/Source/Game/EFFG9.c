/* Effect G9, hit spark fragments, retail sf33rd.xbe.
 * effect_G9_move is 0x4BE1C size 0xE1.
 * effect_G9_init is 0x4BEFD size 0xB2.
 *
 * random_16 returns its table word sign-extended in eax. effect_G9_move
 * indexes g9_pos_hos with the first result directly and sign-extends the
 * second, which is held in the s16 rnd_ix. The position_z choice is
 * branchless: 67 when g9_pos_hos[rnd_ix] > 1, else 33. The dead_f path
 * and the cg_type 0xFF path share one exit.
 * g9_pos_hos is 0x257748. _plef_char_table is 0x308B40.
 * Pause_Hit_Marks is 0x7A88AC. Game_pause is 0x7A89B0.
 * EXE_flag is 0xC7C834. frw is 0xC806A0, 0x700 bytes per object.
 * direction is +0x94. mvxy.a[0].sp is +0x7C, mvxy.a[1].sp is +0x80.
 * set_char_move_init is 0x200A9. char_move is 0x2008E.
 * random_16 is 0x9326B. add_mvxy_speed is 0x92EA2.
 * sort_push_request8 is 0x9E174.
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

typedef union {
    s32 sp;
    struct {
        s16 l;
        s16 h;
    } real;
} Reg32SpReal;

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    s8 blink_timing;
    u8 pad_bt[1];
    u8 type;
    u8 pad_work[1];
    s16 work_id;
    s16 id;
    s8 rl_flag;
    u8 pad_dead[0x20 - 0xB];
    s16 dead_f;
    u8 pad_rno[2];
    s16 routine_no[8];
    u8 pad_cgr[0x48 - 0x34];
    s8 cgromtype;
    u8 pad_pos[0x54 - 0x49];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0x64 - 0x5A];
    XY xyz[3];
    u8 pad_mv[0x7C - 0x70];
    Reg32SpReal mvxy_a[2];
    u8 pad_dirn[0x94 - 0x84];
    s16 direction;
    u8 pad_ct[0x1AC - 0x96];
    u32 *char_table[1];
    u8 pad_ci[0x208 - 0x1B0];
    s16 char_index;
    u8 pad_cg[0x214 - 0x20A];
    u8 cg_type;
    u8 pad_col[0x23C - 0x215];
    s16 my_col_mode;
    s16 my_col_code;
    u8 pad_fam[2];
    s16 my_family;
    u8 pad_end[0x388 - 0x244];
} WORK;

typedef struct {
    WORK wu;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, blink_timing) == 2, "blink_timing");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, rl_flag) == 0xA, "rl_flag");
_Static_assert(__builtin_offsetof(WORK, dead_f) == 0x20, "dead_f");
_Static_assert(__builtin_offsetof(WORK, cgromtype) == 0x48, "cgromtype");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, xyz[0].disp.pos) == 0x66, "xyz0");
_Static_assert(__builtin_offsetof(WORK, xyz[1].disp.pos) == 0x6A, "xyz1");
_Static_assert(__builtin_offsetof(WORK, mvxy_a[0].sp) == 0x7C, "mvxy0");
_Static_assert(__builtin_offsetof(WORK, mvxy_a[1].sp) == 0x80, "mvxy1");
_Static_assert(__builtin_offsetof(WORK, direction) == 0x94, "direction");
_Static_assert(__builtin_offsetof(WORK, char_table) == 0x1AC, "char_table");
_Static_assert(__builtin_offsetof(WORK, char_index) == 0x208, "char_index");
_Static_assert(__builtin_offsetof(WORK, cg_type) == 0x214, "cg_type");
_Static_assert(__builtin_offsetof(WORK, my_family) == 0x242, "my_family");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
#endif

/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const s16 g9_pos_hos[16] = { 0, 1, -1, 2, -2, 0, 3, -3, 1, -1, 2, -2, 4, 3, 0, 3 };

extern u32 _plef_char_table[];
extern u8 Pause_Hit_Marks;
extern u8 Game_pause;
extern u16 EXE_flag;
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void sort_push_request8(WORK *wk);
s16 random_16(void);
void add_mvxy_speed(WORK *wk);
void set_char_move_init(WORK *wk, s16 koc, s32 index);
void char_move(WORK *wk);

void effect_G9_move(WORK_Other *ewk) {
    s16 rnd_ix;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = ewk->wu.type;
        ewk->wu.xyz[0].disp.pos += g9_pos_hos[random_16()];
        rnd_ix = random_16();
        ewk->wu.xyz[1].disp.pos += g9_pos_hos[rnd_ix];

        if (g9_pos_hos[rnd_ix] > 1) {
            ewk->wu.position_z = 67;
        } else {
            ewk->wu.position_z = 33;
        }

        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        /* fallthrough */

    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] += 1;
            break;
        }

        if (Pause_Hit_Marks) {
            break;
        }

        if ((EXE_flag == 0) && (Game_pause == 0)) {
            char_move(&ewk->wu);

            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0] += 1;
                break;
            }

            add_mvxy_speed(&ewk->wu);
        }

        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request8(&ewk->wu);
        break;

    case 2:
        ewk->wu.routine_no[0] = 3;
        break;

    default:
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_G9_init(WORK *wk) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.type = wk->disp_flag;
    ewk->wu.id = 0xA9;
    ewk->wu.work_id = 0x10;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.char_index = wk->direction;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.cgromtype = wk->cgromtype;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code;
    ewk->wu.mvxy_a[0].sp = wk->mvxy_a[0].sp;
    ewk->wu.mvxy_a[1].sp = wk->mvxy_a[1].sp;
    ewk->wu.blink_timing = wk->blink_timing;
    ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos;
    *ewk->wu.char_table = _plef_char_table;
    return 0;
}
