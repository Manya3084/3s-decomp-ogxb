/* mlTsbSetBankAddr, retail sf33rd.xbe 0xF44FE size 0x12.
 * It is interior. gpTsb is the pointer table at 0x7970B0.
 * mlTsbGetDataAdrs is 0xF4315 size 0x13 and is interior.
 * A SoundEvent is 0x20 bytes.
 * mlTsbSetToReqp is 0xF4328 size 0x54 and is interior.
 * eax is the request and ecx is the event. The bank is the stack argument.
 * mlTsbRequest is 0xF437C size 0xE8 and is a scanned start.
 * The request block is 0x18 bytes. Commands 1 and 6 call 0xF42A6.
 * eax is the request, edx is the event, and the stack arguments are the
 * bank, the code, and aRtpc[6]. Command 2 calls 0xF42F7 with the request
 * in eax and the bank and code on the stack. Command 3 prints the string
 * at 0x2B4220. Command 5 prints the string at 0x2B4234. Command 7 does
 * not stop an echo. 0xF42A6 and 0xF42F7 are xb_TsbCommand1 and xb_TsbCommand2.
 */

#include "types.h"

#include <stddef.h>

typedef struct {
    u8 cmd;
    u8 flags;
    u8 prog;
    u8 note;
    u8 attr;
    u8 vol;
    u8 pan;
    u8 pad0;
    s16 pitch;
    u8 prio;
    u8 id1;
    u8 id2;
    u8 pad1[3];
    u32 kofftime;
    u8 limit;
    u8 pad2;
    u16 param0;
    u16 param1;
    u16 param2;
    u16 param3;
    u16 link;
} SoundEvent;

typedef struct {
    u16 flags;
    u8 attr;
    u8 prio;
    u8 bank;
    u8 note;
    u8 id1;
    u8 id2;
    s16 vol;
    s16 pan;
    s16 pitch;
    s16 bend;
    u8 limit;
    u8 pad11;
    u8 pad12;
    u8 pad13;
    u32 kofftime;
} CSE_REQP;

#if defined(__i386__)
_Static_assert(sizeof(SoundEvent) == 0x20, "SoundEvent");
_Static_assert(offsetof(SoundEvent, flags) == 1, "flags");
_Static_assert(offsetof(SoundEvent, note) == 3, "note");
_Static_assert(offsetof(SoundEvent, attr) == 4, "attr");
_Static_assert(offsetof(SoundEvent, vol) == 5, "vol");
_Static_assert(offsetof(SoundEvent, pan) == 6, "pan");
_Static_assert(offsetof(SoundEvent, pitch) == 8, "pitch");
_Static_assert(offsetof(SoundEvent, prio) == 0xA, "prio");
_Static_assert(offsetof(SoundEvent, id1) == 0xB, "id1");
_Static_assert(offsetof(SoundEvent, id2) == 0xC, "id2");
_Static_assert(offsetof(SoundEvent, kofftime) == 0x10, "kofftime");
_Static_assert(offsetof(SoundEvent, limit) == 0x14, "limit");
_Static_assert(offsetof(SoundEvent, link) == 0x1E, "link");
_Static_assert(sizeof(CSE_REQP) == 0x18, "CSE_REQP");
_Static_assert(offsetof(CSE_REQP, attr) == 2, "attr");
_Static_assert(offsetof(CSE_REQP, prio) == 3, "prio");
_Static_assert(offsetof(CSE_REQP, bank) == 4, "bank");
_Static_assert(offsetof(CSE_REQP, note) == 5, "note");
_Static_assert(offsetof(CSE_REQP, id1) == 6, "id1");
_Static_assert(offsetof(CSE_REQP, id2) == 7, "id2");
_Static_assert(offsetof(CSE_REQP, vol) == 8, "vol");
_Static_assert(offsetof(CSE_REQP, pan) == 0xA, "pan");
_Static_assert(offsetof(CSE_REQP, pitch) == 0xC, "pitch");
_Static_assert(offsetof(CSE_REQP, limit) == 0x10, "limit");
_Static_assert(offsetof(CSE_REQP, kofftime) == 0x14, "kofftime");
#endif

extern SoundEvent *gpTsb[16];

extern s32 xb_TsbCommand1(CSE_REQP *reqp, SoundEvent *event, u32 bank, u32 code, s32 rtpc6);
extern s32 xb_TsbCommand2(CSE_REQP *reqp, u32 bank, u32 code);
extern s32 flLogOut(const char *text);
extern s32 xb_TsbQueueRequest(u32 bank, u32 code, s32 id1, u8 prio, u8 a, s32 b, s16 c);
extern s32 xb_StopSeByGroup(u32 bank, u32 code, s32 id1, u8 prio);

void mlTsbSetToReqp(CSE_REQP *pReqp, SoundEvent *pTSB, u16 bank);

s32 mlTsbSetBankAddr(u32 bank, SoundEvent *addr) {
    gpTsb[bank] = addr;
    return 0;
}

SoundEvent *mlTsbGetDataAdrs(u32 bank, u32 code) {
    return &gpTsb[bank][code];
}

s32 mlTsbRequest(u16 bank, u16 code, s32 *aRtpc) {
    CSE_REQP reqp = {0};
    SoundEvent *pTSB;

    while (1) {
        pTSB = mlTsbGetDataAdrs(bank, code);
        mlTsbSetToReqp(&reqp, pTSB, bank);
        reqp.note += aRtpc[1];
        reqp.id1 += aRtpc[2];
        reqp.id2 += aRtpc[3];
        reqp.prio += aRtpc[4];
        reqp.vol += aRtpc[5];
        reqp.pan += aRtpc[6];
        reqp.pitch += aRtpc[7];
        reqp.kofftime += aRtpc[8];
        reqp.limit += aRtpc[9];

        switch (pTSB->cmd) {
        case 1:
        case 6:
            xb_TsbCommand1(&reqp, pTSB, bank, code, aRtpc[6]);
            break;

        case 2:
            xb_TsbCommand2(&reqp, bank, code);
            break;

        case 3:
            flLogOut("mlTsbRequest: STOP\n");
            break;

        case 5:
            flLogOut("mlTsbRequest: LFO\n");
            break;

        default:
            break;
        }

        if (pTSB->link != 0xFFFF && pTSB->link != code) {
            code = pTSB->link;
        } else {
            break;
        }
    }

    return 0;
}

void mlTsbSetToReqp(CSE_REQP *pReqp, SoundEvent *pTSB, u16 bank) {
    pReqp->flags = pTSB->flags;
    pReqp->bank = bank;
    pReqp->note = pTSB->note;
    pReqp->vol = pTSB->vol;
    pReqp->pan = pTSB->pan;
    pReqp->pitch = pTSB->pitch;
    pReqp->prio = pTSB->prio;
    pReqp->id1 = pTSB->id1;
    pReqp->id2 = pTSB->id2;
    pReqp->kofftime = pTSB->kofftime;
    pReqp->attr = pTSB->attr;
    pReqp->limit = pTSB->limit;
}

/* xb_TsbCommand1 0xF42A6 and xb_TsbCommand2 0xF42F7: static
 * (config/sf33rd/static.txt), so mlTsbRequest passes the request in eax
 * and the event in edx. Command1's two queue calls share their pushes
 * (VC7.1 merges them around the one differing argument). */

s32 xb_TsbCommand1(CSE_REQP *reqp, SoundEvent *event, u32 bank, u32 code, s32 rtpc6) {
    if (event->flags & 2) {
        reqp->flags = (u16)event->flags & ~8;
    } else {
        reqp->flags = (u16)(event->flags | 8);
    }

    if (event->param0 != 0) {
        xb_TsbQueueRequest(bank, code, reqp->id1, reqp->prio, 0, 0x100, 0);
    } else {
        xb_TsbQueueRequest(bank, code, reqp->id1, reqp->prio, 0, rtpc6, 0);
    }

    return 0;
}

s32 xb_TsbCommand2(CSE_REQP *reqp, u32 bank, u32 code) {
    xb_StopSeByGroup(bank, code, reqp->id1, reqp->prio);
    return 0;
}
