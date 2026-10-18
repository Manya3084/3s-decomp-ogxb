void dispControllerWasRemovedMessage(s32 x, s32 y, s32 step, s32 pl_id);
s32 xb_GetOnlineFlag(void);

int sprintf(char* buf, const char* fmt, ...);
void xb_PrintSetAttr(s32 attr);
void xb_PrintSetScale(f32 scale);
void xb_PrintSetColor(s32 a, s32 b);
void xb_PrintSetPos(s32 x, s32 y);
void xb_PrintString(const s8* str);
extern s8 D_007AA5F6[2];
extern f32 PrioBase[128];

/* Xbox: drawn with the debug font at fixed positions; x, y, and step are not
 * used. The message names the controller port of player pl_id and ends with
 * "and press START to continue.". Country 1 prints the Japanese text. */
void dispControllerWasRemovedMessage(s32 x, s32 y, s32 step, s32 pl_id) {
    const s8* port_jp[4];
    char buf[32];

    xb_PrintSetAttr(0);
    xb_PrintSetScale(PrioBase[2]);

    if (Country == 1) {
        port_jp[0] = "\x82P";
        port_jp[1] = "\x82Q";
        port_jp[2] = "\x82R";
        port_jp[3] = "\x82S";
        xb_PrintSetColor(0x16, 0x16);
        sprintf(buf, "\x83\x8D\x81[\x83\x89\x92[\x8Eq%s\x82\xC9\x90\xDA\x91\xB1\x82\xB5\x81" "A", port_jp[D_007AA5F6[pl_id]]);
        xb_PrintSetPos(0xD0, 0x98);
        xb_PrintString("\x83R\x83\x93\x83g\x83\x8D\x81[\x83\x89\x82\xF0\x83R\x83\x93\x83g");
        xb_PrintSetPos(0xD0, 0xB8);
        xb_PrintString(buf);
        xb_PrintSetPos(0xD0, 0xD8);
        xb_PrintString("START\x83{\x83^\x83\x93\x82\xF0\x89\x9F\x82\xB5\x82\xC4");
        xb_PrintSetPos(0xD0, 0xF8);
        xb_PrintString("\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B");
        return;
    }

    xb_PrintSetColor(0x16, 0x16);
    sprintf(buf, "controller port %d", D_007AA5F6[pl_id] + 1);
    xb_PrintSetPos(0xE0, 0x88);
    xb_PrintString("Please reconnect");
    xb_PrintSetPos(0xE0, 0xA8);
    xb_PrintString("the controller to");
    xb_PrintSetPos(0xE0, 0xC8);
    xb_PrintString(buf);
    xb_PrintSetPos(0xE0, 0xE8);
    xb_PrintString("and press START");
    xb_PrintSetPos(0xE0, 0x108);
    xb_PrintString("to continue.");
}

/* The Xbox does not pause during an online match (xb_GetOnlineFlag). */
void Pause_Task(struct _TASK* task_ptr) {
    void (*Main_Jmp_Tbl[4])(struct _TASK*) = { Pause_Check, Pause_Move, Pause_Sleep, Pause_Die };

    if (!nowSoftReset() && Mode_Type != 2 && Mode_Type != 3 && Mode_Type != 4 && !xb_GetOnlineFlag()) {
        Main_Jmp_Tbl[task_ptr->r_no[0]](task_ptr);
        Flash_Pause(task_ptr);
    }
}

/* The Xbox message is 12 pixels higher (y 0x46) and names the controller (Pause_ID). */
void Flash_Pause_4th(struct _TASK* task_ptr) {
    if (Interface_Type[Pause_ID] == 0) {
        dispControllerWasRemovedMessage(0x84, 0x46, 0x10, Pause_ID);
        return;
    }

    Pause_Type = 1;
    Setup_Pause(task_ptr);
}

/* Xbox-only functions in this object (moved from src/sf33rd/Source/XBOX/xb_0965A6.c; analysis-ps2map/xbgen.py checked each). */
void xb_DrawTexturedRect(s32 a, s32 b, s32 c, s32 d, s32 e, u32 color, s32 f, s32 g);
void xb_DrawPadRemovedText(s32 x, s32 y, s32 step, s32 pl);

void xb_DrawPadRemovedBox(s32 pl) {
    xb_DrawTexturedRect(0xAC, 0x70, 3, 0x124, 0xC0, 0xF8402020, 2, 8);
    xb_DrawPadRemovedText(0x84, 0x54, 0x10, pl);
}
