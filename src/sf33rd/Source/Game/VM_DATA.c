/* VM_DATA.c, retail sf33rd.xbe.
 * The PS2 file's data (ps2.path), checked by analysis-ps2map/portdata.py
 * against the XBE: each table at its data.txt address, or at the
 * address a checked table's pointer to it holds ("placed by").
 * Replay_File_Name 0x330558 size 0x28: match.
 * SysDir_File_Name 0x330580 size 0x28: match.
 */

#include "structs.h"
#include <stddef.h>

s8* Replay_File_Name[10] = { "SF33rd.RD0", "SF33rd.RD1", "SF33rd.RD2", "SF33rd.RD3", "SF33rd.RD4",
                             "SF33rd.RD5", "SF33rd.RD6", "SF33rd.RD7", "SF33rd.RD8", "SF33rd.RD9" };

s8* SysDir_File_Name[10] = { "SF33rd.SD0", "SF33rd.SD1", "SF33rd.SD2", "SF33rd.SD3", "SF33rd.SD4",
                             "SF33rd.SD5", "SF33rd.SD6", "SF33rd.SD7", "SF33rd.SD8", "SF33rd.SD9" };
