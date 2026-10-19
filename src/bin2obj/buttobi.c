/* buttobi.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * _buttobi_add_y_table 0x2f2678 size 0x118: Xbox size (PS2 0x128); match.
 * _buttobi_time_table 0x2f2560 size 0x118: match.
 */

#include "structs.h"
#include <stddef.h>

#ifndef DATA_SECTION
#define DATA_SECTION
#endif

DATA_SECTION s16 _buttobi_time_table[][4] = {
    { 22, 26, 30, 34 }, { 8, 10, 12, 14 },  { 10, 12, 14, 16 }, { 24, 28, 32, 36 }, { 12, 16, 20, 24 },
    { 18, 22, 26, 30 }, { 28, 32, 36, 40 }, { 28, 32, 36, 40 }, { 24, 28, 32, 36 }, { 12, 16, 20, 24 },
    { 8, 12, 16, 20 },  { 12, 14, 16, 18 }, { 24, 28, 32, 36 }, { 10, 12, 14, 16 }, { 14, 16, 18, 20 },
    { 24, 28, 32, 36 }, { 24, 28, 32, 36 }, { 48, 56, 64, 72 }, { 16, 18, 20, 22 }, { 24, 28, 32, 36 },
    { 2, 4, 6, 8 },     { 2, 4, 6, 8 },     { 18, 20, 22, 24 }, { 18, 20, 22, 24 }, { 20, 22, 24, 26 },
    { 30, 32, 34, 36 }, { 6, 8, 10, 12 },   { 12, 14, 16, 18 }, { 14, 16, 18, 20 }, { 2, 4, 6, 8 },
    { 8, 10, 12, 14 },  { 8, 10, 12, 14 },  { 32, 34, 36, 38 }, { 12, 14, 16, 18 }, { 28, 30, 32, 34 }
};

/* Xbox: 35 rows. _guard_pause_table follows at +0x118; the PS2 table has
 * two more zero rows. */
DATA_SECTION s16 _buttobi_add_y_table[][4] = {
    { 0, 0, 0, 0 }, { 4, 4, 4, 4 }, { 4, 4, 4, 4 }, { 4, 4, 4, 4 }, { 2, 2, 2, 2 }, { 2, 2, 2, 2 }, { 4, 4, 4, 4 },
    { 2, 2, 2, 2 }, { 4, 4, 4, 4 }, { 2, 2, 2, 2 }, { 2, 2, 2, 2 }, { 4, 4, 4, 4 }, { 4, 4, 4, 4 }, { 4, 4, 4, 4 },
    { 4, 4, 4, 4 }, { 2, 2, 2, 2 }, { 2, 2, 2, 2 }, { 6, 6, 6, 6 }, { 0, 0, 0, 0 }, { 4, 6, 8, 8 }, { 0, 0, 0, 0 },
    { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 },
    { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }
};
