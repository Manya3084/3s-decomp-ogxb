/* exchange.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * D_002ED3E8 0x2ed3e8 size 0x40: Xbox size (PS2 0x80); match (placed by _exchange_pow).
 * D_002ED428 0x2ed428 size 0x40: match (placed by _exchange_pow).
 * D_002ED468 0x2ed468 size 0x40: match (placed by _exchange_pow_pl03_sa3).
 * D_002ED52C 0x2ed52c size 0x48: match (placed by _exchange_koa).
 * D_002ED574 0x2ed574 size 0x48: match (placed by _exchange_koa).
 * D_002ED5BC 0x2ed5bc size 0x48: match (placed by _exchange_koa).
 * D_002ED604 0x2ed604 size 0x48: match (placed by _exchange_koa).
 * D_002ED64C 0x2ed64c size 0x48: match (placed by _exchange_koa).
 * D_002ED694 0x2ed694 size 0x48: match (placed by _exchange_koa).
 * D_002ED6DC 0x2ed6dc size 0x48: match (placed by _exchange_koa).
 * D_002ED724 0x2ed724 size 0x48: match (placed by _exchange_koa).
 * D_002ED76C 0x2ed76c size 0x48: match (placed by _exchange_koa).
 * D_002ED7B4 0x2ed7b4 size 0x48: match (placed by _exchange_koa).
 * D_002ED7FC 0x2ed7fc size 0x48: match (placed by _exchange_koa).
 * _exchange_koa 0x2ed4a8 size 0x84: match.
 * _exchange_pow 0x2ed364 size 0x84: match.
 * _exchange_pow_pl03_sa3 0x2ed2e0 size 0x84: match.
 */

#include "structs.h"
#include <stddef.h>

#ifndef DATA_SECTION
#define DATA_SECTION
#endif

extern u32 D_002ED3E8[];
extern u32 D_002ED428[];
extern u32 D_002ED468[];
extern u32 D_002ED52C[];
extern u32 D_002ED574[];
extern u32 D_002ED5BC[];
extern u32 D_002ED5BC[];
extern u32 D_002ED604[];
extern u32 D_002ED604[];
extern u32 D_002ED604[];
extern u32 D_002ED604[];
extern u32 D_002ED64C[];
extern u32 D_002ED64C[];
extern u32 D_002ED64C[];
extern u32 D_002ED64C[];
extern u32 D_002ED694[];
extern u32 D_002ED694[];
extern u32 D_002ED694[];
extern u32 D_002ED694[];
extern u32 D_002ED6DC[];
extern u32 D_002ED6DC[];
extern u32 D_002ED6DC[];
extern u32 D_002ED6DC[];
extern u32 D_002ED724[];
extern u32 D_002ED724[];
extern u32 D_002ED724[];
extern u32 D_002ED724[];
extern u32 D_002ED76C[];
extern u32 D_002ED76C[];
extern u32 D_002ED76C[];
extern u32 D_002ED76C[];
extern u32 D_002ED7B4[];
extern u32 D_002ED7B4[];
extern u32 D_002ED7B4[];
extern u32 D_002ED7B4[];
extern u32 D_002ED7FC[];

DATA_SECTION u32* _exchange_pow_pl03_sa3[] = { D_002ED468, D_002ED468, D_002ED468, D_002ED468, D_002ED468, D_002ED468,
                                               D_002ED468, D_002ED468, D_002ED468, D_002ED468, D_002ED468, D_002ED468,
                                               D_002ED468, D_002ED468, D_002ED468, D_002ED468, D_002ED468, D_002ED468,
                                               D_002ED468, D_002ED468, D_002ED468, D_002ED468, D_002ED468, D_002ED468,
                                               D_002ED468, D_002ED468, D_002ED468, D_002ED468, D_002ED468, D_002ED468,
                                               D_002ED468, D_002ED468, D_002ED468 };

DATA_SECTION u32* _exchange_pow[] = { D_002ED3E8, D_002ED3E8, D_002ED3E8, D_002ED3E8, D_002ED3E8, D_002ED3E8,
                                      D_002ED3E8, D_002ED3E8, D_002ED3E8, D_002ED3E8, D_002ED3E8, D_002ED3E8,
                                      D_002ED3E8, D_002ED3E8, D_002ED3E8, D_002ED3E8, D_002ED428, D_002ED428,
                                      D_002ED428, D_002ED428, D_002ED428, D_002ED428, D_002ED428, D_002ED428,
                                      D_002ED428, D_002ED428, D_002ED428, D_002ED428, D_002ED428, D_002ED428,
                                      D_002ED428, D_002ED428, D_002ED428 };

/* Xbox: 16 words. D_002ED428 follows at +0x40; the PS2 table's other 16
 * words are not in the XBE. */
DATA_SECTION u32 D_002ED3E8[] = { 0x1F0020, 0x1D001E, 0x1B001C, 0x19001A, 0x170018, 0x150016, 0x130014, 0x110012,
                                  0xF0010,  0xE000E,  0xD000D,  0xC000C,  0xB000B,  0xA000A,  0x90009,  0x80008 };

DATA_SECTION u32 D_002ED428[] = { 0x1E0020, 0x1A001C, 0x160018, 0x130014, 0x110012, 0xF0010, 0xD000E, 0xB000C,
                                  0xA000A,  0x90009,  0x80008,  0x70007,  0x60007,  0x60006, 0x50005, 0x50005 };

DATA_SECTION u32 D_002ED468[] = { 0x1F0020, 0x1C001E, 0x18001A, 0x120015, 0xD000F, 0xA000B, 0x80009, 0x60007,
                                  0x40005,  0x20003,  0x10001,  0x10001,  0x10001, 0x10001, 0x10001, 0x10001 };

DATA_SECTION u32* _exchange_koa[] = { D_002ED52C, D_002ED574, D_002ED5BC, D_002ED5BC, D_002ED604, D_002ED604,
                                      D_002ED604, D_002ED604, D_002ED64C, D_002ED64C, D_002ED64C, D_002ED64C,
                                      D_002ED694, D_002ED694, D_002ED694, D_002ED694, D_002ED6DC, D_002ED6DC,
                                      D_002ED6DC, D_002ED6DC, D_002ED724, D_002ED724, D_002ED724, D_002ED724,
                                      D_002ED76C, D_002ED76C, D_002ED76C, D_002ED76C, D_002ED7B4, D_002ED7B4,
                                      D_002ED7B4, D_002ED7B4, D_002ED7FC };

DATA_SECTION u32 D_002ED52C[] = { 0x1000600, 0x1000100, 0x4000400, 0x4000400, 0x1000100, 0x1000100,
                                  0x3000300, 0x3000300, 0x2000200, 0x2000200, 0x3000300, 0x3000300,
                                  0x4000400, 0x4000400, 0x5000500, 0x5000500, 0x100,     0 };

DATA_SECTION u32 D_002ED574[] = { 0x5000100, 0x1000100, 0x4000400, 0x4000400, 0x1000100, 0x1000100,
                                  0x3000300, 0x3000300, 0x2000200, 0x2000200, 0x3000300, 0x3000300,
                                  0x4000400, 0x4000400, 0x5000500, 0x5000500, 0x100,     0 };

DATA_SECTION u32 D_002ED5BC[] = { 0x1000100, 0x6000400, 0x4000400, 0x4000400, 0x1000100, 0x1000100,
                                  0x3000300, 0x3000300, 0x2000200, 0x2000200, 0x3000300, 0x3000300,
                                  0x4000400, 0x4000400, 0x5000500, 0x5000500, 0x100,     0 };

DATA_SECTION u32 D_002ED604[] = { 0x2000100, 0x3000300, 0x1000100, 0x1000100, 0x2000200, 0x2000200,
                                  0x3000300, 0x3000300, 0x2000200, 0x2000200, 0x3000300, 0x3000300,
                                  0x4000400, 0x4000400, 0x5000500, 0x5000500, 0x100,     0 };

DATA_SECTION u32 D_002ED64C[] = { 0x2000100, 0x3000300, 0x4000400, 0x4000400, 0x4000400, 0x4000400,
                                  0x5000500, 0x5000500, 0x2000200, 0x2000200, 0x3000300, 0x3000300,
                                  0x4000400, 0x4000400, 0x5000500, 0x5000500, 0x100,     0 };

DATA_SECTION u32 D_002ED694[] = { 0x2000100, 0x3000300, 0x4000400, 0x4000400, 0x2000200, 0x2000200,
                                  0x1000100, 0x1000100, 0x2000200, 0x2000200, 0x3000300, 0x3000300,
                                  0x4000400, 0x4000400, 0x5000500, 0x5000500, 0x100,     0 };

DATA_SECTION u32 D_002ED6DC[] = { 0x1000000, 0x2000200, 0x4000400, 0x4000400, 0x3000300, 0x3000300,
                                  0x5000500, 0x5000500, 0x1000100, 0x1000100, 0x2000200, 0x2000200,
                                  0x4000400, 0x4000400, 0x5000500, 0x5000500, 0x100,     0 };

DATA_SECTION u32 D_002ED724[] = { 0x1000000, 0x2000200, 0x4000400, 0x4000400, 0x3000300, 0x3000300,
                                  0x5000500, 0x5000500, 0x2000200, 0x2000200, 0x1000100, 0x1000100,
                                  0x4000400, 0x4000400, 0x5000500, 0x5000500, 0x100,     0 };

DATA_SECTION u32 D_002ED76C[] = { 0x1000000, 0x2000200, 0x4000400, 0x4000400, 0x3000300, 0x3000300,
                                  0x5000500, 0x5000500, 0x2000200, 0x2000200, 0x3000300, 0x3000300,
                                  0x1000100, 0x1000100, 0x5000500, 0x5000500, 0x100,     0 };

DATA_SECTION u32 D_002ED7B4[] = { 0x1000000, 0x2000200, 0x4000400, 0x4000400, 0x3000300, 0x3000300,
                                  0x5000500, 0x5000500, 0x2000200, 0x2000200, 0x3000300, 0x3000300,
                                  0x4000400, 0x4000400, 0x1000100, 0x1000100, 0x100,     0 };

DATA_SECTION u32 D_002ED7FC[] = { 0x1000000, 0x2000200, 0x4000400, 0x4000400, 0x3000300, 0x3000300,
                                  0x5000500, 0x5000500, 0x1000100, 0x1000100, 0x2000200, 0x2000200,
                                  0x4000400, 0x4000400, 0x5000500, 0x5000500, 0x100,     0 };
