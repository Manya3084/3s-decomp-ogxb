/* xb_061267.c: the Xbox keyConvert (0x61267), between xb_ResetInputState
 * and xb_GetJoiningPlayer. It replaces the PS2 IOConv.c keyConvert, which
 * read two pads; this one reads four ports and assigns them to players.
 * The C was written from the x86 and does not build to its bytes yet;
 * tools/behave.py runs it against the retail code. */

#include "types.h"
#include "structs.h"

extern MPP mpp_w;
extern FLPAD* flpad_adr[2];
extern IO io_w;
extern u8 Interface_Type[4];
extern struct _SAVE_W save_w[6];
extern u8 Present_Mode;
extern u8 Game_pause;
extern struct _TASK task[12];
extern u16 p1sw_buff;
extern u16 p2sw_buff;
extern u16 p3sw_buff;
extern u16 p4sw_buff;
/* The Xbox table: entries 7 and 11 differ from the PS2's (0x400 and 0x40
 * where the PS2 has 0x800 and 0x80). */
const u32 ioconv_table[24][2] = { { 0x1, 0x1 },      { 0x2, 0x2 },      { 0x4, 0x4 },       { 0x8, 0x8 },
                                  { 0x100, 0x10 },   { 0x200, 0x20 },   { 0x400, 0x40 },    { 0x400, 0x80 },
                                  { 0x10, 0x100 },   { 0x20, 0x200 },   { 0x40, 0x400 },    { 0x40, 0x800 },
                                  { 0x0, 0x1000 },   { 0x0, 0x2000 },   { 0x8000, 0x4000 }, { 0x4000, 0x8000 },
                                  { 0x0, 0x10000 },  { 0x0, 0x20000 },  { 0x0, 0x40000 },   { 0x0, 0x80000 },
                                  { 0x0, 0x100000 }, { 0x0, 0x200000 }, { 0x0, 0x400000 },  { 0x0, 0x800000 } };
s32 xb_GetOnlineModeArg(void);
void flPADSetRepeatSw(FLPAD* pad, u32 IOdata, u8 ctr, u8 times);

/* The Xbox keyConvert. Each of the four ports joins as the next player
 * on its first press; a joined port's pad goes to io_w.data[player].
 * xb_clear_pads clears the online player's pad for that many frames.
 * io_w is 0xC7E9A0 and ioconv_table is 0x32F790. */
void keyConvert(void) {
    IOPad* pad;
    FLPAD* fp;
    u32 currSw;
    s32 i;
    s32 j;
    s32 port;
    s32 repeat_on = 0;

    if (mpp_w.xb_pad_count < 4) {
        for (port = 0; port < 4; port++) {
            if ((u8)mpp_w.xb_port_player[port] == 0xFF && flpad_adr[0][port].sw != 0) {
                mpp_w.xb_port_player[port] = mpp_w.xb_pad_count;
                mpp_w.xb_player_port[mpp_w.xb_pad_count] = port;
                mpp_w.xb_pad_count++;
            }
        }
    }

    if (io_w.xb_clear_pads > 0) {
        io_w.xb_clear_pads--;
        flpad_adr[0][xb_GetOnlineModeArg()].sw = 0;
        flpad_adr[0][xb_GetOnlineModeArg()].sw_new = 0;
        flpad_adr[0][xb_GetOnlineModeArg()].sw_off = 0;
        flpad_adr[0][xb_GetOnlineModeArg()].sw_old = 0;
        flpad_adr[0][xb_GetOnlineModeArg()].sw_repeat = 0;
    }

    if ((save_w[Present_Mode].extra_option.contents[0][4]) && mpp_w.inGame && (Game_pause == 0)) {
        repeat_on = 1;

        if ((task[3].condition == 1) && (task[3].r_no[0] != 10)) {
            repeat_on = 0;
        }
    }

    io_w.sw[0] = io_w.sw[1] = io_w.sw[2] = io_w.sw[3] = 0;

    for (port = 0; port < 4; port++) {
        i = mpp_w.xb_port_player[port];

        if (i == -1) {
            continue;
        }

        flPADSetRepeatSw(&flpad_adr[0][port], 0xFF000F, 15, 3);

        if (repeat_on) {
            flPADSetRepeatSw(&flpad_adr[0][port], 0x3FF0, 2, 1);
        } else {
            flPADSetRepeatSw(&flpad_adr[0][port], 0x3FF0, 10, 2);
        }

        fp = &flpad_adr[0][port];
        pad = &io_w.data[i];
        pad->state = fp->state;
        pad->anstate = fp->anstate;
        pad->kind = fp->kind;
        pad->sw = fp->sw;
        pad->sw_old = fp->sw_old;
        pad->sw_new = fp->sw_new;
        pad->sw_off = fp->sw_off;
        pad->sw_chg = fp->sw_chg;
        pad->sw_repeat = fp->sw_repeat;
        pad->stick[0] = fp->stick[0];
        pad->stick[1] = fp->stick[1];

        if (mpp_w.useAnalogStickData) {
            if (!(fp->sw & 0xF)) {
                pad->sw |= (pad->sw >> 16) & 0xF;
                pad->sw_old |= (pad->sw_old >> 16) & 0xF;
                pad->sw_new |= (pad->sw_new >> 16) & 0xF;
                pad->sw_off |= (pad->sw_off >> 16) & 0xF;
                pad->sw_chg |= (pad->sw_chg >> 16) & 0xF;
                pad->sw_repeat |= (pad->sw_repeat >> 16) & 0xF;
            }

            if (!(fp->sw & 0xF)) {
                pad->sw |= (pad->sw >> 20) & 0xF;
                pad->sw_old |= (pad->sw_old >> 20) & 0xF;
                pad->sw_new |= (pad->sw_new >> 20) & 0xF;
                pad->sw_off |= (pad->sw_off >> 20) & 0xF;
                pad->sw_chg |= (pad->sw_chg >> 20) & 0xF;
                pad->sw_repeat |= (pad->sw_repeat >> 20) & 0xF;
            }
        }

        if (pad->kind == 0 || pad->kind == 0x8000) {
            Interface_Type[i] = 0;
        } else {
            Interface_Type[i] = 2;
        }

        currSw = pad->sw;

        for (j = 0; j < 4; j++) {
            if (currSw & ioconv_table[j][1]) {
                io_w.sw[i] |= ioconv_table[j][0];
            }
        }

        for (j = 12; j < 16; j++) {
            if (currSw & ioconv_table[j][1]) {
                io_w.sw[i] |= ioconv_table[j][0];
            }
        }

        if (repeat_on) {
            currSw = pad->sw_repeat;
        }

        for (j = 4; j < 12; j++) {
            if (currSw & ioconv_table[j][1]) {
                io_w.sw[i] |= ioconv_table[j][0];
            }
        }
    }

    p1sw_buff = io_w.sw[0];
    p2sw_buff = io_w.sw[1];
    p3sw_buff = io_w.sw[2];
    p4sw_buff = io_w.sw[3];
}
