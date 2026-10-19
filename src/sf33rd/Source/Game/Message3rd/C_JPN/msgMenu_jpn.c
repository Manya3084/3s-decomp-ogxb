/* msgMenu_jpn.c, retail sf33rd.xbe.
 * The Japanese counterpart of C_USA/msgMenu_usa.c: the table at 0x325204, walked
 * with the US file's 1 messages (analysis-ps2map/jpnmsg.py). */

#include "structs.h"

static s8* msgMenu_00J[7] = {
    "\203Z\203\214\203N\203g\203Q\201[\203\200\203\201\203j\203\205\201[\202\311\226\337\202\350\202\334\202\267\201B",
    "\202\346\202\353\202\265\202\242\202\305\202\267\202\251\201H",
    "",
    "\226\337\202\351\202\306\225\333\221\266\202\263\202\352\202\304\202\242\202\310\202\242\203Q\201[\203\200\203f\201[\203^\202\315",
    "\216\270\202\355\202\352\202\334\202\267\201B",
    "",
    "\201@\201@\201@\201@\202\315\202\242\201F\201@\201@\202\242\202\242\202\246\201F",
};

static s8** msgMenuAdrJ[1] = {
    msgMenu_00J,
};

static s8 msgMenuCtrJ[1] = {
    7,
};

/* xb_msgMenu_jpn_tbl is 0x325204. */
MessageTable xb_msgMenu_jpn_tbl = { msgMenuAdrJ, msgMenuCtrJ };
