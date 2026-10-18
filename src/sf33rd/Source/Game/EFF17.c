/* EFF17.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * EFF17_Bowan 0x38036 size 0x4E.
 * effect_17_move 0x38084 size 0x4C.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/EFF17.h"
#include "bin2obj/char_table.h"
#include "common.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_17_move(WORK_Other* ewk) {
    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
    } else if (Menu_Cursor_Y[0] == ewk->wu.type) {
        EFF17_Bowan(ewk);
    } else {
        ewk->wu.my_clear_level = 128;
        ewk->wu.routine_no[1] = 0;
    }

    sort_push_request4(&ewk->wu);
}

void EFF17_Bowan(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.my_clear_level -= 4;

        if (ewk->wu.my_clear_level < 20) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_clear_level = 20;
        }

        break;

    case 1:
        ewk->wu.my_clear_level += 4;

        if (ewk->wu.my_clear_level > 127) {
            ewk->wu.routine_no[1]--;
            ewk->wu.my_clear_level = 127;
        }

        break;
    }
}
