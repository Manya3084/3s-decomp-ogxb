/* DIR_DATA.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * Dir_Default_Data 0x2499d0 size 0x48: match.
 * Dir_Menu_Max_Data 0x249988 size 0x46: match.
 * Letter_Data_51 0x32a668 size 0x3c0: match.
 * Page_Data 0x249a18 size 0xa: match.
 */

#include "structs.h"
#include <stddef.h>

const u8 Dir_Menu_Max_Data[10][7] = { { 1, 1, 1, 3, 1, 3, 2 }, { 1, 1, 3, 1, 1, 2, 0 }, { 1, 1, 1, 1, 1, 1, 2 },
                                      { 1, 1, 1, 2, 0, 0, 0 }, { 1, 1, 1, 1, 2, 0, 0 }, { 1, 1, 1, 3, 2, 0, 0 },
                                      { 1, 1, 1, 1, 1, 2, 0 }, { 1, 1, 1, 1, 1, 1, 2 }, { 1, 1, 1, 1, 1, 1, 2 },
                                      { 1, 1, 3, 1, 2, 0, 0 } };

const DirData Dir_Default_Data = { { { 1, 1, 1, 1, 1, 1, 1 },
                                                 { 1, 0, 1, 1, 1, 1, 1 },
                                                 { 1, 1, 1, 1, 1, 1, 1 },
                                                 { 1, 1, 0, 0, 1, 1, 1 },
                                                 { 1, 0, 1, 1, 1, 1, 1 },
                                                 { 1, 1, 1, 2, 0, 0, 1 },
                                                 { 1, 1, 1, 1, 0, 1, 1 },
                                                 { 0, 0, 0, 0, 0, 0, 0 },
                                                 { 0, 0, 0, 0, 0, 0, 0 },
                                                 { 0, 0, 1, 1, 0, 0, 0 } },
                                   0 };

const u8 Page_Data[10] = { 6, 5, 5, 3, 4, 4, 5, 6, 6, 4 };

s8* Letter_Data_51[10][6][4] = { { { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "S/#;;;/L", "S/##;;/L", "S/###;/L", "S/####/L" },
                                   { "OFF", "ON", NULL, NULL },
                                   { "S/#;;;/L", "S/##;;/L", "S/###;/L", "S/####/L" } },
                                 { { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "S/#;;;/L", "S/##;;/L", "S/###;/L", "S/####/L" },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL } },
                                 { { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL } },
                                 { { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "3rd", "2nd", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL } },
                                 { { "OFF", "ON", NULL, NULL },
                                   { "3rd", "2nd", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL } },
                                 { { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "S/#;;;/L", "S/##;;/L", "S/###;/L", "S/####/L" },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL } },
                                 { { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "3rd", "2nd", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL } },
                                 { { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL } },
                                 { { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL } },
                                 { { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "S/#;;;/L", "S/##;;/L", "S/###;/L", "S/####/L" },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL },
                                   { "OFF", "ON", NULL, NULL } } };
