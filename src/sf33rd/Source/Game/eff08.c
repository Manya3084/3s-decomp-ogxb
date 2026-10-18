/* Bonus color rewrite, retail sf33rd.xbe.
 * effect_08_move is 0xB6BC1 size 0xD3 and is interior.
 * effect_08_init is 0xB6C94 size 0x6C and is a scanned start.
 * 0xB6D00 is effect_12_move.
 *
 * Suicide[5] is 0x7A826D. PB_Status is 0x7A8932.
 * Rewrite_Color_Data_08 is 0x2841C8 and matches the 52 bytes.
 * The rows were not pasted. The color store adds 0.
 * The sign-bit tail jump is written as a call.
 * sc_ram_to_vram_opc sign-extends type and zero-extends the
 * two position bytes and the color word.
 * pull_effect_work is 0x4A6A8. push_effect_work stays
 * push_effect_work. frw is 0xC806A0 and each object is 0x700 bytes.
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
    u8 pad_cg[0x14];
    s8 cgromtype;
    u8 pad_pos[0xB];
    s16 position_x;
    s16 position_y;
    s16 position_z;
    u8 pad_xyz[0xA];
    XY xyz[3];
    u8 pad_sync[6];
    s16 sync_suzi;
    u8 pad_dir[0x20];
    s16 dir_step;
    s16 dir_timer;
    u8 pad_ct[0x110];
    u32 *char_table[1];
    u8 pad_ci[0x58];
    s16 char_index;
    u8 pad_col[0x32];
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
    u8 pad_mp[0xA];
    s16 master_priority;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, be_flag) == 0, "be_flag");
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, routine_no) == 0x24, "routine_no");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, position_y) == 0x56, "position_y");
_Static_assert(__builtin_offsetof(WORK, dir_step) == 0x98, "dir_step");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, my_col_code) == 0x23E, "my_col_code");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_priority) == 0x392, "master_priority");
#endif

extern s8 Suicide[8];
extern u8 PB_Status;
extern const u8 Rewrite_Color_Data_08[2][13][2];
extern EffectRow frw[];

void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);
void sc_ram_to_vram_opc(s8 sc_num, s8 x, s8 y, u16 atr);
void effect_08_move(WORK_Other *ewk);

void effect_08_move(WORK_Other *ewk) {
    if ((Suicide[5] & 0x80) != 0) {
        push_effect_work(&ewk->wu);
        return;
    }

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if ((Suicide[5] & 1) != 0) {
            if ((PB_Status & 3) != 0) {
                ewk->wu.routine_no[0]++;
                ewk->wu.dir_timer = 1;
                ewk->wu.dir_step = 0;
            } else {
                ewk->wu.routine_no[0] = 99;
            }
        }

        break;

    case 1:
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.my_col_code = Rewrite_Color_Data_08[ewk->master_priority][ewk->wu.dir_step][0] + 0;
            ewk->wu.dir_timer = Rewrite_Color_Data_08[ewk->master_priority][ewk->wu.dir_step][1];

            if (ewk->wu.dir_timer == 0xFF) {
                ewk->wu.routine_no[0] = 99;
            } else {
                ewk->wu.dir_step++;
            }
        }

        break;
    }

    sc_ram_to_vram_opc(ewk->wu.type, ewk->wu.position_x, ewk->wu.position_y, ewk->wu.my_col_code);
}

s32 effect_08_init(s8 sc_num, s8 x, s8 y, u16 atr, s16 color_type) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 8;
    ewk->wu.work_id = 16;
    ewk->wu.type = sc_num + 0;
    ewk->wu.position_x = x;
    ewk->wu.position_y = y;
    ewk->wu.my_col_code = atr;
    ewk->master_priority = color_type;
    effect_08_move(ewk);
    return 0;
}
