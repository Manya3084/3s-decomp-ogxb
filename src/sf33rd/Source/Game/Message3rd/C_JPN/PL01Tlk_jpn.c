/* PL01Tlk_jpn.c, retail sf33rd.xbe.
 * The Japanese counterpart of C_USA/PL01Tlk_usa.c: the table at 0x322310, which
 * D_0032C150's talk table lists for character 1, walked with
 * the US file's 5 messages (analysis-ps2map/jpnmsg.py). */

#include "structs.h"

static s8* msgTlkPL01_00J[1] = {
    "",
};
static s8* msgTlkPL01_01J[1] = {
    "\201@\201@\223\271\222\205\202\311\203n\203`\203}\203L\201d\201d\202\240\202\361\202\275\202\252\203\212\203\205\203E\202\251",
};
static s8* msgTlkPL01_02J[2] = {
    "\201@\201@\211\\\202\331\202\307\202\314\222j\202\251\202\307\202\244\202\251",
    "\201@\201@\211\264\202\252\212m\202\251\202\337\202\304\202\342\202\351",
};
static s8* msgTlkPL01_03J[1] = {
    "\201@\201@\202\244\202\336\201d\201d\202\310\202\251\202\310\202\251\202\242\202\242\212\341\202\360\202\265\202\304\202\242\202\351",
};
static s8* msgTlkPL01_04J[2] = {
    "\201@\201@\211\223\227\266\202\315\202\242\202\347\202\361",
    "\201@\201@\202\315\202\266\202\337\202\251\202\347\221S\212J\202\305\201A\202\261\202\242\201I",
};

static s8** msgTalkAdrPL01J[5] = {
    msgTlkPL01_00J, msgTlkPL01_01J, msgTlkPL01_02J, msgTlkPL01_03J, msgTlkPL01_04J,
};

static s8 msgTalkCtrPL01J[5] = {
    1, 1, 2, 1, 2,
};

/* xb_pl01tlk_jpn_tbl is 0x322310. */
MessageTable xb_pl01tlk_jpn_tbl = { msgTalkAdrPL01J, msgTalkCtrPL01J };
