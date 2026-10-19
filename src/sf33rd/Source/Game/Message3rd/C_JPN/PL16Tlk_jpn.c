/* PL16Tlk_jpn.c, retail sf33rd.xbe.
 * The Japanese counterpart of C_USA/PL16Tlk_usa.c: the table at 0x3247A4, which
 * D_0032C150's talk table lists for character 16, walked with
 * the US file's 6 messages (analysis-ps2map/jpnmsg.py). */

#include "structs.h"

static s8* msgTlkPL16_00J[1] = {
    "",
};
static s8* msgTlkPL16_01J[2] = {
    "\201@\201@\211\\\202\315\225\267\202\242\202\277\202\343\202\244",
    "\201@\201@\202\240\202\361\202\275\202\252\203\212\203\205\203E\202\342\202\313\201H",
};
static s8* msgTlkPL16_02J[2] = {
    "\201@\201@\202\273\202\314\224\253\212\252\202\253\202\306\222\205\202\275\202\253\202\350\223\267\222\205\201I",
    "\201@\201@\202\334\202\277\202\252\202\242\202\310\202\242\202\277\202\342\201I",
};
static s8* msgTlkPL16_03J[1] = {
    "\201@\201@\202\244\202\277\202\306\201A\202\242\202\301\202\263\202\361\217\237\225\211\202\266\202\341\201[\202\301\201I",
};
static s8* msgTlkPL16_04J[2] = {
    "\201@\201@\213\363\216\350\202\251\201d\201d",
    "\201@\201@\202\273\202\352\202\340\221\212\223\226\202\314\216g\202\242\216\350\202\276\202\310",
};
static s8* msgTlkPL16_05J[2] = {
    "\201@\201@\202\250\202\340\202\265\202\353\202\242\201I",
    "\201@\201@\214N\202\314\221S\227\315\201A\214\251\202\271\202\304\202\340\202\347\202\250\202\244\201I",
};

static s8** msgTalkAdrPL16J[6] = {
    msgTlkPL16_00J, msgTlkPL16_01J, msgTlkPL16_02J, msgTlkPL16_03J, msgTlkPL16_04J, msgTlkPL16_05J,
};

static s8 msgTalkCtrPL16J[6] = {
    1, 2, 2, 1, 2, 2,
};

/* xb_pl16tlk_jpn_tbl is 0x3247A4. */
MessageTable xb_pl16tlk_jpn_tbl = { msgTalkAdrPL16J, msgTalkCtrPL16J };
