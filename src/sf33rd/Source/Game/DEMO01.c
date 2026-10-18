/* DEMO01.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Title 0x314B6 size 0xF0. Read against the x86: the byte switched on is
 * D_No[1]. D_No is 0x7A8200. The C is the PS2 C.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: Title_At_a_Dash.
 * Globals: Cover_Timer 0x7A81F4, D_Timer 0x7A892E.
 */

#include "structs.h"

void njSetBackColor(u32 c0, u32 c1, u32 c2);
extern u8 D_No[4];
s32 Check_LDREQ_Clear();
void Standby_BGM(u16 num);
extern s16 D_Timer;
s16 opening_demo();
void Switch_Screen_Init(s32 );
s32 Switch_Screen(u8 Wipe_Type);
extern s8 Cover_Timer;
void TexRelease(u32 G_Num);



s16 Title() {
    s16 xx = 0;

    njSetBackColor(0, 0, 0);

    switch (D_No[1]) {
    case 0:
        if (Check_LDREQ_Clear() != 0) {
            Standby_BGM(0x34);
            D_No[1] += 1;
            D_Timer = 20;
        }

        break;

    case 1:
        if (D_Timer != 0) {
            D_Timer -= 1;
        } else if (opening_demo()) {
            D_No[1] += 1;
            D_Timer = 40;
        }

        break;

    case 2:
        opening_demo();

        if (--D_Timer == 0) {
            D_No[1] += 1;
            Switch_Screen_Init(1);
        }

        break;

    case 3:
        opening_demo();

        if (Switch_Screen(1) != 0) {
            D_No[1] += 1;
            Cover_Timer = 20;
        }

        break;

    case 4:
        Switch_Screen(1);
        D_No[1] += 1;
        D_Timer = 2;
        break;

    default:
        Switch_Screen(1);

        if (--D_Timer == 0) {
            TexRelease(0x259);
            xx = 1;
        }

        break;
    }

    return xx;
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

s16 Title_At_a_Dash() {
    s16 xx = 0;

    BGM_Stop();
    Disp_Copyright();

    switch (D_No[1]) {
    case 0:
        mpp_w.ctrDemo = 0;
        D_No[1] += 1;
        D_Timer = 30;

        if (!title_tex_flag) {
            TITLE_Init();
        }

        break;

    case 1:
        if (--D_Timer == 0) {
            D_No[1] += 1;
        }

        TITLE_Move(1);
        break;

    default:
        xx = 1;
        TITLE_Move(1);
        break;
    }

    return xx;
}
#endif
