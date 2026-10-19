/* PL02Tlk_jpn.c, retail sf33rd.xbe.
 * The Japanese counterpart of C_USA/PL02Tlk_usa.c: the table at 0x322540, which
 * D_0032C150's talk table lists for character 2, walked with
 * the US file's 5 messages (analysis-ps2map/jpnmsg.py). */

#include "structs.h"

static s8* msgTlkPL02_00J[1] = {
    "",
};
static s8* msgTlkPL02_01J[1] = {
    "\201@\201@\202\346\202\255\226O\202\253\202\310\202\242\202\346\202\310\201A\202\250\202\334\202\246",
};
static s8* msgTlkPL02_02J[1] = {
    "\201@\201@\203t\203b\201A\202\250\214\335\202\242\227l\202\276",
};
static s8* msgTlkPL02_03J[2] = {
    "\201@\201@\202\334\201A\202\242\202\302\202\340\202\314\202\346\202\244\202\311\214y\202\255",
    "\201@\201@\203q\203l\202\301\202\304\202\342\202\351\202\251\202\347\201A\212o\214\345\202\265\202\310",
};
static s8* msgTlkPL02_04J[2] = {
    "\201@\201@\202\346\202\255\214\276\202\244\201d\201d\220\257\202\315\202\334\202\276\211\264\202\252\217\343\202\276",
    "\201@\201@\202\250\221O\202\261\202\273\212\310\222P\202\311\223|\202\352\202\351\202\310\202\346\201I",
};

static s8** msgTalkAdrPL02J[5] = {
    msgTlkPL02_00J, msgTlkPL02_01J, msgTlkPL02_02J, msgTlkPL02_03J, msgTlkPL02_04J,
};

static s8 msgTalkCtrPL02J[5] = {
    1, 1, 1, 2, 2,
};

/* xb_pl02tlk_jpn_tbl is 0x322540. */
MessageTable xb_pl02tlk_jpn_tbl = { msgTalkAdrPL02J, msgTalkCtrPL02J };
