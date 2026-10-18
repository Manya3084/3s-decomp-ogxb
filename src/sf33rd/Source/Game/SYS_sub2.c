/* SYS_sub2.c, retail sf33rd.xbe.
 * PlayStation 2 C, not hand-adjusted for Xbox. Each named body was located
 * from the PS2 retail map: call graph, source order, and agreement of
 * constants, field offsets, callees, and size. See docs/decompiling.md.
 * The #include lines name headers in the PS2 tree (ps2.path).
 * Setup_Disp_Size 0x9B567 size 0x3F.
 * The other functions in this file are not located in sf33rd.xbe yet.
 */

#include "sf33rd/Source/Game/SYS_sub2.h"
#include "common.h"
#include "sf33rd/Source/Game/WORK_SYS.h"

u8 dspwhPack(u8 xdsp, u8 ydsp) {
    u8 rnum = 100 - ydsp;
    rnum |= (100 - xdsp) * 16;
    return rnum;
}

void dspwhUnpack(u8 src, u8* xdsp, u8* ydsp) {
    *xdsp = 100 - ((src >> 4) & 0xF);
    *ydsp = 100 - (src & 0xF);
}

const s16 Adjust_XY_Data[4][2] = { { 18, 12 }, { 12, 8 }, { 6, 4 }, { 0, 0 } };

void Setup_Disp_Size(s16 /* unused */) {
    s16 dixH = 3;
    s16 dixV = 3;

    setup_pos_remake_key(0);
    Correct_X[3] = Adjust_XY_Data[dixH][0];
    Correct_Y[3] = Adjust_XY_Data[dixV][1];
    Screen_Zoom_X = 1.0f;
    Screen_Zoom_Y = 1.0f;
    Correct_X[1] = Correct_X[2] = Correct_X[3];
    Correct_Y[1] = Correct_Y[2] = Correct_Y[3];
}

void setup_pos_remake_key(s16 /* unused */) {
    // Do nothing
}
