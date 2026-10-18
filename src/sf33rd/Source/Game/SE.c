/* SE.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Stage_BGM 0x98370 size 0x97. FLAG: x86-only constants 0x28.
 * BGM_Request_Code_Check 0x9840C size 0xD.
 * BGM_Stop 0x98419 size 0x5.
 * SE_All_Off 0x9841E size 0x5.
 * Check_Finish_SE 0x98423 size 0x2D.
 * Get_Position 0x98450 size 0x4A. FLAG: x86-only constants -0x60.
 * Check_Bonus_SE 0x9849A size 0x36.
 * Se_Shock 0x984D0 size 0x99.
 * Se_Myself 0x98569 size 0x49.
 * Se_Myself_Die 0x985B2 size 0x45. FLAG: x86-only constants 0x300.
 * Se_Let 0x985F7 size 0x4D.
 * Se_Let_SP 0x98644 size 0x73.
 * Call_Se 0x986B7 size 0x1C.
 * Se_Term 0x986D3 size 0x4B. FLAG: x86-only constants 0x300.
 * Finish_SE 0x9871E size 0x49. FLAG: x86-only constants 0x300.
 * Sound_SE is folded into 0x98407 with 1 other bodies. Unnamed.
 * BGM_Request is folded into 0x98407 with 1 other bodies. Unnamed.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0: Se_Dummy,
 * Store_Sound_Code, Disp_Sound_Code.
 * Data: bgm_selector is 0x32FD20, 2 pointers whose arrays were compared.
 * Data: gSeqStatus 0xC7C836.
 * Data: sdeb: defined elsewhere on Xbox.
 * Data: bgm_selectorDC is 0x32FD00, 0x10 bytes compared.
 * Data: bgm_selectorAC is 0x32FD10, 0x10 bytes compared.
 * Data: BGM_Stage_Data is 0x2652C8, 0x2C bytes compared.
 * Data: SE_Shock_Data is 0x265304, 0xE bytes compared.
 * Data: Finish_SE_Data is 0x265314, 0x1C bytes compared.
 * Globals: BGM_Stage_Data 0x2652C8, SE_Shock_Data 0x265304, Finish_SE_Data
 * 0x265314, Bonus_Voice_Data 0x267008, bgm_selector 0x32FD20, My_char
 * 0x7A8114, Bonus_Type 0x7A8120, Play_Type 0x7A812D, COM_id 0x7A81C0,
 * Mode_Type 0x7A825A, Bonus_Game_Flag 0x7A8272, Winner_id 0x7A8472,
 * Last_Called_SE 0x7A8796, sys_w 0x7C5940, gSeqStatus 0xC7C836, plw 0xC7CEA0.
 */

#include "structs.h"

#define SDEB_SIZE 8

typedef struct { u8 raw[0x1A];

u8 bgm_type;
} _SYSTEM_W;
extern u8 Mode_Type;
extern u8 Play_Type;
extern u8 My_char[2];
extern s8 COM_id;
extern s16 Bonus_Game_Flag;
extern u8 Bonus_Type;
extern s16 Last_Called_SE;
extern s8 Winner_id;
extern PLW plw[2];
extern _SYSTEM_W sys_w;
extern const u16 Bonus_Voice_Data[768];
extern s16 gill_appear_check(void);
extern u16 get_center_position(void);
extern void SsRequestPan(u16 code, s16 pan, s16 unused, s32 unused2, s32 unused3);
extern void SsRequest_CC(u16 num);
extern void SsBgmOff(void);
extern void spu_all_off(void);
extern void Go_BGM(void);
u16 Check_Bonus_SE(u16 code);
u16 Get_Position(PLW *wk);
s32 Check_Finish_SE(void);
void SsRequest(u16 ReqNumber);

extern u8 gSeqStatus[1];

extern SoundPatch sdeb[SDEB_SIZE];

s16 bgm_selectorDC[8] = { 0, 1, 2, 1, 2, 1, 2, 1 };

s16 bgm_selectorAC[8] = { 0, 1, 0, 1, 0, 1, 0, 1 };

s16* bgm_selector[2] = { bgm_selectorDC, bgm_selectorAC };

const u16 BGM_Stage_Data[22] = { 46, 1, 13, 34, 31, 4, 7, 16, 25, 28, 34, 1, 28, 43, 22, 10, 19, 40, 4, 37, 61, 62 };

const s16 SE_Shock_Data[7] = { 285, 286, 287, 288, 289, 305, 306 };

const s16 Finish_SE_Data[2][7] = { { 305, 306, 285, 286, 287, 288, 272 }, { 292, 293, 290, 291, 287, 288, 272 } };

void Stage_BGM(u16 stage_number, u16 round_number) {
    u16 code;

    if (Mode_Type == 0 && Play_Type == 0 && My_char[COM_id] == 17 && Bonus_Game_Flag == 0) {
        code = (u16)(BGM_Stage_Data[17] + bgm_selector[sys_w.bgm_type][round_number & 7]);
    } else {
        code = (u16)(BGM_Stage_Data[stage_number] + bgm_selector[sys_w.bgm_type][round_number & 7]);
    }

    *gSeqStatus = 0;

    if (code == 0x2E && gill_appear_check() == 0) {
        Go_BGM();
        return;
    }

    SsRequest(code);
}

void Sound_SE(s16 Code) {
    SsRequest(Code);
}

void BGM_Request(s16 Code) {
    SsRequest(Code);
}

void BGM_Request_Code_Check(u16 code) {
    SsRequest_CC(code);
}

void BGM_Stop(void) {
    SsBgmOff();
}

void SE_All_Off(void) {
    spu_all_off();
}

void Se_Shock(WORK_Other *ewk, u16 code) {
    PLW *em;
    s16 xx;
    s16 zz;
    s16 uid;

    code = Check_Bonus_SE(code);

    if (ewk->wu.work_id == 1) {
        em = (PLW *)ewk->wu.target_adrs;
        uid = ewk->wu.id;
    } else {
        em = (PLW *)((PLW *)ewk->my_master)->wu.target_adrs;
        uid = ewk->master_id;
    }

    if (em->wu.work_id == 1 && em->wu.vital_new < 0) {
        for (xx = 0, zz = 0x27; xx < 7; xx++) {
            if (code == SE_Shock_Data[xx]) {
                zz = 0;
                break;
            }
        }

        code = (u16)(code + zz);
    }

    if (code) {
        code = (u16)(code + uid * 0x300);
    }

    xx = (s16)Get_Position((PLW *)ewk);
    SsRequestPan(code, xx, xx, 0, 2);
}

void Se_Myself(WORK_Other *ewk, u16 code) {
    s16 xx;
    s16 uid = ewk->wu.id;

    if ((ewk->wu.work_id == 1) || (uid = ewk->master_id, uid <= 1)) {
        if (code) {
            code = (u16)(code + uid * 0x300);
        }

        xx = (s16)Get_Position((PLW *)ewk);
        SsRequestPan(code, xx, xx, 0, 2);
    }
}

void Se_Myself_Die(WORK_Other *ewk, u16 code) {
    s16 xx;

    if ((ewk->wu.work_id == 1) && (ewk->wu.vital_new >= 0)) {
        if (code) {
            code = (u16)(code + ewk->wu.id * 0x300);
        }

        xx = (s16)Get_Position((PLW *)ewk);
        SsRequestPan(code, xx, xx, 0, 2);
    }
}

void Se_Let(WORK_Other *ewk, u16 code) {
    s16 xx;
    s16 uid;

    code = Check_Bonus_SE(code);

    if (ewk->wu.work_id == 1) {
        uid = ewk->wu.id;
    } else {
        uid = ewk->master_id;
    }

    if (code) {
        code = (u16)(code + uid * 0x300);
    }

    xx = (s16)Get_Position((PLW *)ewk);
    SsRequestPan(code, xx, xx, 0, 2);
}

void Se_Let_SP(WORK_Other *ewk, u16 code) {
    PLW *em;
    s16 xx;
    s16 uid;

    if (ewk->wu.work_id == 1) {
        uid = ewk->wu.id;
    } else {
        uid = ewk->master_id;
    }

    em = (PLW *)ewk->wu.target_adrs;

    if ((em->wu.work_id == 1) && (em->wu.vital_new < 0)) {
        if (code == 0x14B) {
            code = 0x158;
        }

        if (code == 0x13A) {
            code = 0x15A;
        }
    }

    if (code) {
        code = (u16)(code + uid * 0x300);
    }

    xx = (s16)Get_Position((PLW *)ewk);
    SsRequestPan(code, xx, xx, 0, 2);
}

void Call_Se(WORK_Other *ewk, u16 code) {
    s16 xx = (s16)Get_Position((PLW *)ewk);

    SsRequestPan(code, xx, xx, 0, 2);
}

void Se_Term(WORK_Other *ewk, u16 code) {
    s16 xx;

    if (ewk->wu.work_id != 1) {
        return;
    }

    if ((ewk->wu.mvxy.a[1].sp < 0) && (ewk->wu.xyz[1].disp.pos <= 64)) {
        return;
    }

    if (code) {
        code = (u16)(code + ewk->wu.id * 0x300);
    }

    xx = (s16)Get_Position((PLW *)ewk);
    SsRequestPan(code, xx, xx, 0, 2);
}

void Finish_SE(void) {
    PLW *wk;
    s16 xx;
    s32 code = Check_Finish_SE();

    if (code == -1) {
        return;
    }

    wk = &plw[Winner_id];

    if (code) {
        code += wk->wu.id * 0x300;
    }

    xx = (s16)Get_Position(wk);
    SsRequestPan((u16)code, xx, xx, 0, 2);
}

s32 Check_Finish_SE(void) {
    s16 xx;

    for (xx = 0; xx < 7; xx++) {
        if (Finish_SE_Data[0][xx] == Last_Called_SE) {
            return Finish_SE_Data[1][xx];
        }
    }

    return -1;
}

u16 Get_Position(PLW *wk) {
    u16 xx;
    u16 yy;

    xx = get_center_position();
    xx -= 0xC0;
    xx = (u16)(wk->wu.position_x - xx);
    xx /= 4;
    xx += 16;

    if (xx < 0x70) {
        return xx;
    }

    yy = get_center_position();

    if (yy > wk->wu.position_x) {
        return 0x10;
    }

    return 0x70;
}

u16 Check_Bonus_SE(u16 code) {
    if (Bonus_Game_Flag == 0 || Bonus_Type != 20) {
        return code;
    }

    if (code < 0x100 || code >= 0x760) {
        return code;
    }

    return Bonus_Voice_Data[code - 0x100];
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

void Se_Dummy(WORK_Other* ewk, u16 Code) {
    SoundPatchConfig rmc;

    rmc.ptix = 0;
    rmc.bank = 0;
    rmc.port = 0;
    rmc.code = 0;

    Store_Sound_Code(Code, &rmc);
}

void Store_Sound_Code(u16 code, SoundPatchConfig* rmc) {
    s16 i;

    for (i = 7; i > 0; i--) {
        sdeb[i] = sdeb[i - 1];
    }

    sdeb->cp3code = code;
    sdeb->rmc = *rmc;
}

void Disp_Sound_Code() {
    s16 i;

    if (Debug_w[4] == 0) {
        return;
    }

    flPrintColor(0xFFFFFFFF);

    for (i = 0; i < SDEB_SIZE; i++) {
        flPrintL(2, i * 2 + 11, "%3X", sdeb[i].cp3code);
        flPrintL(50, i * 2 + 11, "%2X", sdeb[i].rmc.ptix);
        flPrintL(53, i * 2 + 11, "%2X", sdeb[i].rmc.bank);
        flPrintL(56, i * 2 + 11, "%2X", sdeb[i].rmc.port);
        flPrintL(59, i * 2 + 11, "%3X", sdeb[i].rmc.code);
    }

    flPrintColor(0xFFFFFF8F);
    flPrintL(2, 9, "CODE  KDCM PORT BKCD PRIO VOL  POS  PICH NEXT   PX BK PO CODE");
}
#endif
