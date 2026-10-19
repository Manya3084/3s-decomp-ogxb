/* PL04Tlk_jpn.c, retail sf33rd.xbe.
 * The Japanese counterpart of C_USA/PL04Tlk_usa.c: the table at 0x322A50, which
 * D_0032C150's talk table lists for character 4, walked with
 * the US file's 6 messages (analysis-ps2map/jpnmsg.py). */

#include "structs.h"

static s8* msgTlkPL04_00J[1] = {
    "",
};
static s8* msgTlkPL04_01J[2] = {
    "\201@\201@\214N\202\252\202\240\202\314\227L\226\274\202\310",
    "\201@\201@\203T\203\200\203\211\203C\203t\203@\203C\203^\201[\202\251\202\313\201H",
};
static s8* msgTlkPL04_02J[2] = {
    "\201@\201@\212\357\213\366\202\276\202\310",
    "\201@\201@\202\250\202\352\202\340\202\240\202\361\202\275\202\360\222T\202\265\202\304\202\242\202\275\202\361\202\276",
};
static s8* msgTlkPL04_03J[2] = {
    "\201@\201@\211p\215\221\210\352\202\314\203p\201[\203t\203F\203N\203g\203{\203N\203T\201[",
    "\201@\201@\202\272\202\320\210\352\223x\216\350\215\207\202\355\202\271\202\265\202\275\202\242\201I",
};
static s8* msgTlkPL04_04J[2] = {
    "\201@\201@\201d\201d\202\323\202\323\202\323\201A\213C\202\311\223\374\202\301\202\275\202\346\201I",
    "\201@\201@\220a\216m\221R\202\306\202\265\202\275\225\250\215\230\202\306\202\273\202\314\211s\202\242\212\341",
};
static s8* msgTlkPL04_05J[1] = {
    "\201@\201@\212y\202\265\202\242\214\337\214\343\202\311\202\310\202\350\202\273\202\244\202\276\201I",
};

static s8** msgTalkAdrPL04J[6] = {
    msgTlkPL04_00J, msgTlkPL04_01J, msgTlkPL04_02J, msgTlkPL04_03J, msgTlkPL04_04J, msgTlkPL04_05J,
};

static s8 msgTalkCtrPL04J[6] = {
    1, 2, 2, 2, 2, 1,
};

/* xb_pl04tlk_jpn_tbl is 0x322A50. */
MessageTable xb_pl04tlk_jpn_tbl = { msgTalkAdrPL04J, msgTalkCtrPL04J };
