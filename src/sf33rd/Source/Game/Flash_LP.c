/* Win lamp flash, retail sf33rd.xbe.
 * Flash_Lamp is 0x597E9 size 0x15F.
 *
 * The loop tests ix at the bottom. ix 0 always passes the
 * Battle_Number test, so it is the PlayStation 2 for loop.
 * Mode_Type is the byte at 0x7A825A. omop_cockpit is 0x7C5C6C.
 * Game_pause is 0x7A89B0. Lamp_No is 0x7A88D8. Lamp_Index is 0x7A8229.
 * Lamp_Timer is 0x7A82DE. Lamp_Color is 0x7A87F2. Lamp_Flash_Data is
 * 0x25C710, two bytes per row. flash_win_type is 0x7A8458 and
 * sync_win_type is 0x7A85A0, each u8 [2][4]. vmark_tbl is 0x2AE720.
 * save_w is 0x7BD3E0, 0x208 bytes per mode, Battle_Number at +0x1A. Present_Mode is 0x7A819C. Play_Type is
 * 0x7A812D. scfont_sqput is 0xE61FE.
 */

#include "types.h"
#include "structs.h"


#if defined(__i386__)
_Static_assert(__builtin_offsetof(struct _SAVE_W, Battle_Number) == 0x1A, "Battle_Number");
_Static_assert(sizeof(struct _SAVE_W) == 0x208, "struct _SAVE_W");
#endif

extern u8 Mode_Type;
extern s16 omop_cockpit;
extern u8 Game_pause;
extern u8 Lamp_No;
extern u8 Lamp_Index;
extern s16 Lamp_Timer;
extern u8 Lamp_Color;
/* Tables pasted from the PS2 file; analysis-ps2map/portdata.py found
   each equal to retail. */
const u8 Lamp_Flash_Data[2][2] = { { 0x07, 0x6F }, { 0x1E, 0x03 } };

extern u8 flash_win_type[2][4];
extern u8 sync_win_type[2][4];
extern const u8 vmark_tbl[];
extern u8 Present_Mode;
extern u8 Play_Type;
extern struct _SAVE_W save_w[];

void scfont_sqput(u16 x, u16 y, u8 atr, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2, u16 priority);

void Flash_Lamp(void) {
    u8 ix;
    u8 ix2p;
    u8 mark;
    u8 color;

    if (Mode_Type == 3 || Mode_Type == 4) {
        return;
    }

    if (omop_cockpit == 0) {
        return;
    }

    if (!Game_pause) {
        switch (Lamp_No) {
        case 0:
            Lamp_No = 1;
            Lamp_Index = 1;
            Lamp_Timer = 1;
            /* fallthrough */

        case 1:
            if (--Lamp_Timer == 0) {
                if (++Lamp_Index > 1) {
                    Lamp_Index = 0;
                }
                Lamp_Color = Lamp_Flash_Data[Lamp_Index][0];
                Lamp_Timer = Lamp_Flash_Data[Lamp_Index][1];
            }

            break;
        }
    }

    for (ix = 0; ix <= save_w[Present_Mode].Battle_Number[Play_Type]; ix++) {
        mark = flash_win_type[0][ix];

        if (flash_win_type[0][ix] == 0) {
            color = 7;
        } else {
            color = Lamp_Color;
        }

        if (flash_win_type[0][ix] == sync_win_type[0][ix]) {
            scfont_sqput(vmark_tbl[ix], 4, color, 0, mark * 2, 26, 2, 1, 2);
        }

        mark = flash_win_type[1][ix];
        ix2p = ix + 4;

        if (flash_win_type[1][ix] == 0) {
            color = 7;
        } else {
            color = Lamp_Color;
        }

        if (flash_win_type[1][ix] == sync_win_type[1][ix]) {
            scfont_sqput(vmark_tbl[ix2p], 4, color, 0, mark * 2, 26, 2, 1, 2);
        }
    }
}
