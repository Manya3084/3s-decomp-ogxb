/* EFF92.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * effect_92_move 0x4251E size 0xC5.
 * effect_92_init 0x425E3 size 0x6A.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/EFF92.h"
#include "common.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/sc_data.h"
#include "sf33rd/Source/Game/sc_sub.h"
#include "sf33rd/Source/Game/workuser.h"

const u8 Rewrite_Mark_Data[13][2] = { { -1, 2 }, { 0, 2 },  { -1, 2 }, { 0, 2 },  { -1, 2 }, { 0, 2 },  { -1, 2 },
                                      { 0, 2 },  { -1, 2 }, { 0, 2 },  { -1, 2 }, { 0, 3 },  { -1, 99 } };

void effect_92_move(WORK_Other* ewk) {
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
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 92;
    ewk->master_id = PL_id;
    ewk->wu.dir_step = win_number;
    ewk->wu.dir_timer = 1;
    ewk->wu.dmcal_m = 0;
    sync_win_type[ewk->master_id][ewk->wu.dir_step] = win_type[ewk->master_id][ewk->wu.dir_step];
    return 0;
}
