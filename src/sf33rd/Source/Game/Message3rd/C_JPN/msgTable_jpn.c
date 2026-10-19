/* msgTable_jpn.c, retail sf33rd.xbe.
 * The Japanese message lists: D_0032C150 (EFFB6's get_message_conn_data)
 * points at the win, talk and end lists of the 20 characters and at the
 * system direction, extra and menu lists, which sit beside the US ones
 * (analysis-ps2map/jpnmsg.py). */

#include "structs.h"

extern MessageTable xb_msgExtra_jpn_tbl;
extern MessageTable xb_msgMenu_jpn_tbl;
extern MessageTable xb_msgSysDir_jpn_tbl;
extern MessageTable xb_pl00end_jpn_tbl;
extern MessageTable xb_pl00tlk_jpn_tbl;
extern MessageTable xb_pl00win_jpn_tbl;
extern MessageTable xb_pl01end_jpn_tbl;
extern MessageTable xb_pl01tlk_jpn_tbl;
extern MessageTable xb_pl01win_jpn_tbl;
extern MessageTable xb_pl02end_jpn_tbl;
extern MessageTable xb_pl02tlk_jpn_tbl;
extern MessageTable xb_pl02win_jpn_tbl;
extern MessageTable xb_pl03end_jpn_tbl;
extern MessageTable xb_pl03tlk_jpn_tbl;
extern MessageTable xb_pl03win_jpn_tbl;
extern MessageTable xb_pl04end_jpn_tbl;
extern MessageTable xb_pl04tlk_jpn_tbl;
extern MessageTable xb_pl04win_jpn_tbl;
extern MessageTable xb_pl05end_jpn_tbl;
extern MessageTable xb_pl05tlk_jpn_tbl;
extern MessageTable xb_pl05win_jpn_tbl;
extern MessageTable xb_pl06end_jpn_tbl;
extern MessageTable xb_pl06tlk_jpn_tbl;
extern MessageTable xb_pl06win_jpn_tbl;
extern MessageTable xb_pl07end_jpn_tbl;
extern MessageTable xb_pl07tlk_jpn_tbl;
extern MessageTable xb_pl07win_jpn_tbl;
extern MessageTable xb_pl08end_jpn_tbl;
extern MessageTable xb_pl08tlk_jpn_tbl;
extern MessageTable xb_pl08win_jpn_tbl;
extern MessageTable xb_pl09end_jpn_tbl;
extern MessageTable xb_pl09tlk_jpn_tbl;
extern MessageTable xb_pl09win_jpn_tbl;
extern MessageTable xb_pl10end_jpn_tbl;
extern MessageTable xb_pl10tlk_jpn_tbl;
extern MessageTable xb_pl10win_jpn_tbl;
extern MessageTable xb_pl11end_jpn_tbl;
extern MessageTable xb_pl11tlk_jpn_tbl;
extern MessageTable xb_pl11win_jpn_tbl;
extern MessageTable xb_pl12end_jpn_tbl;
extern MessageTable xb_pl12tlk_jpn_tbl;
extern MessageTable xb_pl12win_jpn_tbl;
extern MessageTable xb_pl13end_jpn_tbl;
extern MessageTable xb_pl13tlk_jpn_tbl;
extern MessageTable xb_pl13win_jpn_tbl;
extern MessageTable xb_pl14end_jpn_tbl;
extern MessageTable xb_pl14win_jpn_tbl;
extern MessageTable xb_pl15end_jpn_tbl;
extern MessageTable xb_pl15tlk_jpn_tbl;
extern MessageTable xb_pl15win_jpn_tbl;
extern MessageTable xb_pl16end_jpn_tbl;
extern MessageTable xb_pl16tlk_jpn_tbl;
extern MessageTable xb_pl16win_jpn_tbl;
extern MessageTable xb_pl17end_jpn_tbl;
extern MessageTable xb_pl17win_jpn_tbl;
extern MessageTable xb_pl18end_jpn_tbl;
extern MessageTable xb_pl18tlk_jpn_tbl;
extern MessageTable xb_pl18win_jpn_tbl;
extern MessageTable xb_pl19end_jpn_tbl;
extern MessageTable xb_pl19tlk_jpn_tbl;
extern MessageTable xb_pl19win_jpn_tbl;

/* xb_pl_mes_tbl_jpn is 0x328968. */
MessageTable* xb_pl_mes_tbl_jpn[20] = {
    &xb_pl00win_jpn_tbl, &xb_pl01win_jpn_tbl, &xb_pl02win_jpn_tbl, &xb_pl03win_jpn_tbl,
    &xb_pl04win_jpn_tbl, &xb_pl05win_jpn_tbl, &xb_pl06win_jpn_tbl, &xb_pl07win_jpn_tbl,
    &xb_pl08win_jpn_tbl, &xb_pl09win_jpn_tbl, &xb_pl10win_jpn_tbl, &xb_pl11win_jpn_tbl,
    &xb_pl12win_jpn_tbl, &xb_pl13win_jpn_tbl, &xb_pl14win_jpn_tbl, &xb_pl15win_jpn_tbl,
    &xb_pl16win_jpn_tbl, &xb_pl17win_jpn_tbl, &xb_pl18win_jpn_tbl, &xb_pl19win_jpn_tbl,
};

/* xb_pl_tlk_tbl_jpn is 0x328A08. */
MessageTable* xb_pl_tlk_tbl_jpn[20] = {
    &xb_pl00tlk_jpn_tbl, &xb_pl01tlk_jpn_tbl, &xb_pl02tlk_jpn_tbl, &xb_pl03tlk_jpn_tbl,
    &xb_pl04tlk_jpn_tbl, &xb_pl05tlk_jpn_tbl, &xb_pl06tlk_jpn_tbl, &xb_pl07tlk_jpn_tbl,
    &xb_pl08tlk_jpn_tbl, &xb_pl09tlk_jpn_tbl, &xb_pl10tlk_jpn_tbl, &xb_pl11tlk_jpn_tbl,
    &xb_pl12tlk_jpn_tbl, &xb_pl13tlk_jpn_tbl, &xb_pl13tlk_jpn_tbl, &xb_pl15tlk_jpn_tbl,
    &xb_pl16tlk_jpn_tbl, &xb_pl16tlk_jpn_tbl, &xb_pl18tlk_jpn_tbl, &xb_pl19tlk_jpn_tbl,
};

/* xb_pl_end_tbl_jpn is 0x328AA8. */
MessageTable* xb_pl_end_tbl_jpn[20] = {
    &xb_pl00end_jpn_tbl, &xb_pl01end_jpn_tbl, &xb_pl02end_jpn_tbl, &xb_pl03end_jpn_tbl,
    &xb_pl04end_jpn_tbl, &xb_pl05end_jpn_tbl, &xb_pl06end_jpn_tbl, &xb_pl07end_jpn_tbl,
    &xb_pl08end_jpn_tbl, &xb_pl09end_jpn_tbl, &xb_pl10end_jpn_tbl, &xb_pl11end_jpn_tbl,
    &xb_pl12end_jpn_tbl, &xb_pl13end_jpn_tbl, &xb_pl14end_jpn_tbl, &xb_pl15end_jpn_tbl,
    &xb_pl16end_jpn_tbl, &xb_pl17end_jpn_tbl, &xb_pl18end_jpn_tbl, &xb_pl19end_jpn_tbl,
};

/* xb_msgSysDirTbl_jpn is 0x328AFC. */
MessageTable* xb_msgSysDirTbl_jpn[1] = {
    &xb_msgSysDir_jpn_tbl,
};

/* xb_msgExtraTbl_jpn is 0x328B04. */
MessageTable* xb_msgExtraTbl_jpn[1] = {
    &xb_msgExtra_jpn_tbl,
};

/* xb_msgMenuTbl_jpn is 0x328B0C. */
MessageTable* xb_msgMenuTbl_jpn[1] = {
    &xb_msgMenu_jpn_tbl,
};

/* D_0032C150 is 0x32C150. */
MessageTable** D_0032C150[6] = { xb_pl_mes_tbl_jpn, xb_pl_tlk_tbl_jpn, xb_pl_end_tbl_jpn, xb_msgSysDirTbl_jpn, xb_msgExtraTbl_jpn, xb_msgMenuTbl_jpn };
