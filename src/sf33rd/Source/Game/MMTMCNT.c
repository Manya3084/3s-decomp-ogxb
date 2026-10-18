/* MMTMCNT.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Purge_com_player_from_mm 0x61BFF size 0x23.
 * Purge_memory_of_list 0x61C22 size 0x5D. Read against the x86: after the
 * purge loop, Xbox releases sound bank 1 when pmo_list[ix][3] is set and bank
 * 2 when [4] is (xb_PurgeListEntry, the routine init_trans_color_ram also
 * uses). The C is the Xbox code (analysis-ps2map/overrides/MMTMCNT.c).
 * Purge_texcash_of_list 0x61C7F size 0x2C.
 * Make_texcash_of_list 0x61CAB size 0x32.
 * Purge_mmtm_area 0x61CDD size 0x16.
 * Data: MM_num is 0x25EF60, 0x20 bytes compared.
 * Data: TM_num is 0x25EF80, 0x18 bytes compared.
 * Data: pmo_list is 0x25EF98, 0x120 bytes compared.
 * Data: pto_list is 0x25F0B8, 0xD8 bytes compared.
 * Data: mto_list is 0x25F190, 0xD8 bytes compared.
 * Globals: MM_num 0x25EF60, TM_num 0x25EF80, pmo_list 0x25EF98, pto_list
 * 0x25F0B8, mto_list 0x25F190, plw 0xC7CEA0.
 */

#include "structs.h"

void xb_PurgeListEntry(s32 bank);
extern PLW plw[2];
void purge_player_texture(s16 id);
void Purge_texcash_of_list(s16 ix);
void Purge_memory_of_list(s16 ix);
void Purge_memory_of_kind_of_key(u8 kokey);
void purge_texcash_work(s16 ix);
void make_texcash_work(s16 ix);

const u8 MM_num[32] = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15,
                        16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };

const u8 TM_num[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };

const u8 pmo_list[9][32] = {
    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0 }
};

const u8 pto_list[9][24] = { { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                             { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                             { 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 } };

const u8 mto_list[9][24] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

void Purge_com_player_from_mm() {
    if (plw[0].wu.operator == 0) {
        purge_player_texture(0);
    }

    if (plw[1].wu.operator == 0) {
        purge_player_texture(1);
    }
}

void Purge_mmtm_area(s16 ix) {
    Purge_texcash_of_list(ix);
    Purge_memory_of_list(ix);
}

/* Xbox: after the purge, list entries 3 and 4 also release sound banks 1
   and 2. */
void Purge_memory_of_list(s16 ix) {
    s16 i;

    for (i = 0; i < 32; i++) {
        if (pmo_list[ix][i]) {
            Purge_memory_of_kind_of_key(MM_num[i]);
        }
    }

    if (pmo_list[ix][3]) {
        xb_PurgeListEntry(1);
    }

    if (pmo_list[ix][4]) {
        xb_PurgeListEntry(2);
    }
}

void Purge_texcash_of_list(s16 ix) {
    s16 i;

    for (i = 0; i < 0x18; i++) {
        if (pto_list[ix][i]) {
            purge_texcash_work(i);
        }
    }
}

void Make_texcash_of_list(s16 ix) {
    s16 i;

    for (i = 0; i < 0x18; i++) {
        if (mto_list[ix][i]) {
            make_texcash_work(TM_num[i]);
        }
    }
}
