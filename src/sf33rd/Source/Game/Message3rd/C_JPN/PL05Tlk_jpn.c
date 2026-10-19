/* PL05Tlk_jpn.c, retail sf33rd.xbe.
 * The Japanese counterpart of C_USA/PL05Tlk_usa.c: the table at 0x322CC4, which
 * D_0032C150's talk table lists for character 5, walked with
 * the US file's 6 messages (analysis-ps2map/jpnmsg.py). */

#include "structs.h"

static s8* msgTlkPL05_00J[1] = {
    "",
};
static s8* msgTlkPL05_01J[2] = {
    "\201@\201@\202\242\202\242\202\251\202\260\202\361\202\311\202\265\202\342\202\252\202\352\201I",
    "\201@\201@\202\242\202\302\202\334\202\305\202\340\203R\203\\\203R\203\\\202\306\202\346\203H\201I",
};
static s8* msgTlkPL05_02J[2] = {
    "\201@\201@\221S\225\224\211\360\202\301\202\304\202\361\202\276\202\346",
    "\201@\201@\203M\203\213\202\361\202\306\202\261\202\353\202\314\216g\202\242\202\276\202\353\203H\202\252\201I",
};
static s8* msgTlkPL05_03J[1] = {
    "\201@\201@\201d\201d\201d\201d",
};
static s8* msgTlkPL05_04J[2] = {
    "\201@\201@\212\256\221S\221\314\202\276\202\251\203i\203\223\202\276\202\251\222m\202\347\202\313\202\246\202\252",
    "\201@\201@\227\312\216Y\225i\202\311\225\211\202\257\202\351\202\315\202\270\202\252\202\313\202\246\201I",
};
static s8* msgTlkPL05_05J[2] = {
    "\201@\201@\202\263\202\240\201A\227\210\202\310\201I",
    "\201@\201@\203X\203N\203\211\203b\203v\202\311\202\265\202\304\221\227\202\350\225\324\202\265\202\304\202\342\202\351\203b\201I",
};

static s8** msgTalkAdrPL05J[6] = {
    msgTlkPL05_00J, msgTlkPL05_01J, msgTlkPL05_02J, msgTlkPL05_03J, msgTlkPL05_04J, msgTlkPL05_05J,
};

static s8 msgTalkCtrPL05J[6] = {
    1, 2, 2, 1, 2, 2,
};

/* xb_pl05tlk_jpn_tbl is 0x322CC4. */
MessageTable xb_pl05tlk_jpn_tbl = { msgTalkAdrPL05J, msgTalkCtrPL05J };
