/* EFFA1.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * effect_A1_move 0x42CDE size 0x62.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/EFFA1.h"
#include "bin2obj/char_table.h"
#include "common.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_A1_move(WORK_Other* ewk) {
    s16 x;

    ewk->wu.disp_flag = 0;

    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (ewk->wu.be_flag == 0) {
        return;
    }

    ewk->wu.my_clear_level = Flash_Synchro;

    if (ewk->wu.type) {
        x = Cursor_Limit[1] - Cursor_Limit[0];

        if (x > 4) {
            ewk->wu.disp_flag = 1;
        }
    } else if (Cursor_Limit[0] > 0) {
        ewk->wu.disp_flag = 1;
    }

    sort_push_request4(&ewk->wu);
}
