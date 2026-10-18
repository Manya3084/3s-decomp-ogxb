/* meta_col.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * metamor_color_copy 0xD0119 size 0xBA. Read against the x86: the copy loop
 * keeps a pointer to ColorRAM row 8 (0x7AB160) and reads row 0 at -0x400. The
 * C is the PS2 C.
 * metamor_color_restore 0xD0216 size 0x8A. Read against the x86: the same
 * pointer trick; the last loop reads metamor_original[wkid][4], 0x200 past the
 * base. metamor_original is 0x7AA0A0. The C is the PS2 C.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * metamor_color_trans, metamor_color_store.
 * Data: hi_meta 0x7A9EA0.
 * Data: metamor_original: defined elsewhere on Xbox.
 * Data: mcs_sel_tbl is 0x289A50, 0x4 bytes compared, found by the bytes.
 * Globals: mcs_sel_tbl 0x289A50, ColorRAM 0x7AAD60.
 */

#include "structs.h"

extern u16 ColorRAM[512][64];
void palUpdateGhostCP3(s32 pal, s32 nums);

extern u16 hi_meta[2][2][64];

extern u16 metamor_original[2][5][64];

// size: 0x500, address: 0x5E3650

// rodata
const s16 mcs_sel_tbl[2] = { 0x1F8, 0x1FC };

void metamor_color_copy(s16 wkid) {
    s16 from_id;
    s16 to_id;
    s16 i;
    s16 j;

    from_id = (((wkid == 0) * 0x10) + 1);
    to_id = (((wkid == 1) * 0x10) + 1);

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 64; j++) {
            ColorRAM[to_id + i][j] = ColorRAM[from_id + i][j];
            ColorRAM[to_id + i + 8][j] = ColorRAM[from_id + i + 8][j];
        }
    }

    for (j = 0; j < 64; j++) {
        ColorRAM[mcs_sel_tbl[wkid]][j] = ColorRAM[mcs_sel_tbl[(wkid + 1) & 1]][j];
    }

    palUpdateGhostCP3(to_id, 6);
    palUpdateGhostCP3(to_id + 8, 6);
    palUpdateGhostCP3(mcs_sel_tbl[wkid], 1);
}

void metamor_color_restore(s16 wkid) {
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 64; j++) {
            ColorRAM[i + (wkid * 16)][j] = metamor_original[wkid][i][j];
            ColorRAM[i + ((wkid * 16) + 8)][j] = metamor_original[wkid][i][j];
        }
    }

    for (j = 0; j < 64; j++) {
        ColorRAM[mcs_sel_tbl[wkid]][j] = metamor_original[wkid][i][j];
    }

    palUpdateGhostCP3(wkid * 16, 4);
    palUpdateGhostCP3((wkid * 16) + 8, 4);
    palUpdateGhostCP3(mcs_sel_tbl[wkid], 1);
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void metamor_color_trans(s16 wkid) {
    s16 i;

    for (i = 0; i < 64; i++) {
        ColorRAM[wkid * 16][i] = palConvSrcToRam(hi_meta[wkid][0][i]);
        ColorRAM[(wkid * 16) + 8][i] = palConvSrcToRam(hi_meta[wkid][1][i]);
    }

    palUpdateGhostCP3(wkid * 16, 1);
    palUpdateGhostCP3((wkid * 16) + 8, 1);
}

void metamor_color_store(s16 wkid) {
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 64; j++) {
            metamor_original[wkid][i][j] = ColorRAM[i + (wkid * 16)][j];
        }
    }

    for (j = 0; j < 64; j++) {
        metamor_original[wkid][i][j] = ColorRAM[mcs_sel_tbl[wkid]][j];
    }
}
#endif
