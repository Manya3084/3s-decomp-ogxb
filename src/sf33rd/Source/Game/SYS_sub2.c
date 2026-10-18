/* SYS_sub2.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * dspwhPack 0x9B535 size 0x12.
 * dspwhUnpack 0x9B547 size 0x20.
 * Setup_Disp_Size 0x9B567 size 0x3F. Read against the x86:
 * setup_pos_remake_key is empty and is inlined away, and Adjust_XY_Data[3] is
 * {0, 0}, so the Correct_X and Correct_Y stores are constant zeros. Correct_X
 * is 0x7BE110. Correct_Y is 0x7C59C8. Screen_Zoom_Y is 0x7BE11C. The C is the
 * PS2 C.
 * setup_pos_remake_key is folded into 0x4384A with 47 other bodies. Unnamed.
 * setup_pos_remake_key is folded into 0x4384A.
 * Data: Adjust_XY_Data: not located in the XBE, PS2 initializer kept.
 * Unnamed data used (not checked): Setup_Disp_Size: 0x2190ac.
 * Globals: Correct_X 0x7BE110, Screen_Zoom_Y 0x7BE11C, Correct_Y 0x7C59C8,
 * Screen_Zoom_X 0x7C5C20.
 */

#include "structs.h"

void sub_0004384A(s16 );
extern s16 Correct_X[4];
extern s16 Correct_Y[4];
extern f32 Screen_Zoom_X;
extern f32 Screen_Zoom_Y;

const s16 Adjust_XY_Data[4][2] = { { 18, 12 }, { 12, 8 }, { 6, 4 }, { 0, 0 } };

u8 dspwhPack(u8 xdsp, u8 ydsp) {
    u8 rnum = 100 - ydsp;
    rnum |= (100 - xdsp) * 16;
    return rnum;
}

void dspwhUnpack(u8 src, u8* xdsp, u8* ydsp) {
    *xdsp = 100 - ((src >> 4) & 0xF);
    *ydsp = 100 - (src & 0xF);
}

void Setup_Disp_Size(s16 /* unused */) {
    s16 dixH = 3;
    s16 dixV = 3;

    sub_0004384A(0);
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
