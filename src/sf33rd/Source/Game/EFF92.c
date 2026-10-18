/* Effect 92, retail sf33rd.xbe.
 * effect_92_move is 0x4251E size 0xC5.
 * effect_92_init is 0x425E3 size 0x6A.
 *
 * The move tests the default case first. The init stores dmcal_m first.
 * The C keeps the PlayStation 2 order.
 * win_type is 0x7A86B0, flash_win_type is 0x7A8458, sync_win_type is
 * 0x7A85A0, each u8 [2][4]. Rewrite_Mark_Data is 0x24FB0C, two bytes per
 * row. vmark_tbl is 0x2AE720, one byte per entry.
 * dir_step is +0x98. dir_timer is +0x9A. dmcal_m is +0xA4. master_id is
 * +0x38E. scfont_sqput is 0xE61FE. push_effect_work is 0x4AC6C.
 * pull_effect_work is 0x4A6A8. frw is 0xC806A0, 0x700 bytes per object.
 */

#include "types.h"

typedef struct {
    s8 be_flag;
    s8 disp_flag;
    u8 pad_type[2];
    u8 type;
    u8 pad_work[3];
    s16 id;
    u8 pad_rno[0x24 - 0xA];
    s16 routine_no[8];
    u8 pad_dir[0x98 - 0x34];
    s16 dir_step;
    s16 dir_timer;
    u8 pad_dm[0xA4 - 0x9C];
    u16 dmcal_m;
    u8 pad_end[0x388 - 0xA6];
} WORK;

typedef struct {
    WORK wu;
    u32 *my_master;
    s16 master_work_id;
    s16 master_id;
} WORK_Other;

typedef u8 EffectRow[0x700];

#if defined(__i386__)
_Static_assert(__builtin_offsetof(WORK, type) == 4, "type");
_Static_assert(__builtin_offsetof(WORK, dir_step) == 0x98, "dir_step");
_Static_assert(__builtin_offsetof(WORK, dir_timer) == 0x9A, "dir_timer");
_Static_assert(__builtin_offsetof(WORK, dmcal_m) == 0xA4, "dmcal_m");
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
#endif

extern u8 win_type[2][4];
extern u8 flash_win_type[2][4];
extern u8 sync_win_type[2][4];
extern const u8 Rewrite_Mark_Data[][2];
extern const u8 vmark_tbl[];
extern EffectRow frw[];

void scfont_sqput(u16 x, u16 y, u8 atr, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2, u16 priority);
void push_effect_work(WORK *wk);
s16 pull_effect_work(s16 index);

void effect_92_move(WORK_Other *ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if ((ewk->wu.dir_timer -= 1) == 0) {
            ewk->wu.type = Rewrite_Mark_Data[ewk->wu.dmcal_m][0];
            ewk->wu.dir_timer = Rewrite_Mark_Data[ewk->wu.dmcal_m][1];
            ewk->wu.dmcal_m++;
        }

        if (ewk->wu.type == 0xFF) {
            ewk->wu.type = win_type[ewk->master_id][ewk->wu.dir_step];
            scfont_sqput(vmark_tbl[ewk->wu.dir_step + (ewk->master_id << 2)], 4, 7, 0, ewk->wu.type << 1, 26, 2, 1, 2);
        }

        if (ewk->wu.dir_timer == 99) {
            ewk->wu.routine_no[0]++;
        }

        break;

    default:
        flash_win_type[ewk->master_id][ewk->wu.dir_step] = win_type[ewk->master_id][ewk->wu.dir_step];
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_92_init(s16 PL_id, s16 win_number) {
    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 92;
    ewk->master_id = PL_id;
    ewk->wu.dir_step = win_number;
    ewk->wu.dir_timer = 1;
    ewk->wu.dmcal_m = 0;
    sync_win_type[ewk->master_id][ewk->wu.dir_step] = win_type[ewk->master_id][ewk->wu.dir_step];
    return 0;
}
