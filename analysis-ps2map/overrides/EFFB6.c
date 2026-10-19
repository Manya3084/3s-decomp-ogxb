/* Xbox: the upper bounds are written inclusive (<= 0x9F, <= 0xFF). */
s32 msgCheckCodeSize(u8 data) {
    if (data >= 0x80 && data <= 0x9F) {
        return 2;
    }

    if (data >= 0xE0 && data <= 0xFF) {
        return 2;
    }

    return 1;
}

/* Xbox: effect B6's move-table slot is the shared empty body (0x4384A),
 * so it does nothing. */
void effect_B6_move(WORK_Other* ewk) {
    (void)ewk;
}

/* mess_tables is 0x32C168, pl_mes_tbl is 0x328918, pl_tlk_tbl is 0x3289B8,
   pl_end_tbl is 0x328A58, msgSysDirTbl is 0x328AF8, msgExtraTbl is 0x328B00,
   msgMenuTbl is 0x328B08. Xbox: the Japanese message tables (pl_mes_tbl and the others, each just
   after its Western one at 0x328968, 0x328A08, 0x328AA8, 0x328AFC,
   0x328B04 and 0x328B0C), indexed as mess_tables is. */
extern MessageTable** D_0032C150[6];

/* Xbox: Japanese text (mpp_w.language 1) comes from D_0032C150, and any
   language but English sets lines 18 pixels apart with hzsel 1. */
void get_message_conn_data(WORK_Other_CONN* ewk, s16 kind, s16 pl, s16 msg) {
    u8** msghead;
    u8* msgtbl;
    s32 msgline;
    s32 slideX;
    s32 slideY;
    s32 currX;
    s32 currY;
    s32 i;
    s32 hzsel;
    s32 space;
    s32 hzflag;
    s32 bytes;
    s32 mjcnt;
    u16 objnum;

    currX = 0;
    currY = 0;
    mjcnt = 0;
    slideX = 8;

    if (mpp_w.language) {
        slideY = -18;
        hzsel = 1;
    } else {
        slideY = -16;
        hzsel = 0;
    }

    if (msg >= 0xFF) {
        return;
    }

    if (mpp_w.language == 1) {
        msghead = (u8**)D_0032C150[kind][pl]->msgAdr[msg];
        msgline = D_0032C150[kind][pl]->msgNum[msg];
    } else {
        msghead = (u8**)mess_tables[kind][pl]->msgAdr[msg];
        msgline = mess_tables[kind][pl]->msgNum[msg];
    }

    for (i = 0; i < msgline; i++) {
        for (msgtbl = msghead[i]; *msgtbl; msgtbl += bytes) {
            bytes = msgConvertObjNum(msgtbl, &space, &hzflag, &objnum, hzsel);

            if (!space) {
                ewk->conn[mjcnt].nx = currX;
                ewk->conn[mjcnt].ny = currY;
                ewk->conn[mjcnt].col = 0;
                ewk->conn[mjcnt].chr = objnum;
                mjcnt++;

                if (mjcnt > 108) {
                    while (1) {
                        // do nothing
                    }
                }
            }

            if (hzflag) {
                currX += slideX * 2;
            } else {
                currX += slideX;
            }
        }

        currX = 0;
        currY += slideY;
    }

    ewk->num_of_conn = mjcnt;
}
