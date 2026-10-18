/* Stage sound, retail sf33rd.xbe.
 * Stage_BGM is 0x98370 size 0x97, interior after the ret.
 * BGM_Request_Code_Check is 0x9840C size 0xD, interior after the ret.
 * BGM_Stop is 0x98419 size 0x5, interior after the jmp.
 * SE_All_Off is 0x9841E size 0x5, interior after the jmp.
 * Check_Finish_SE is 0x98423 size 0x2D, interior after the ret.
 * Get_Position is 0x98450 size 0x4A, interior after the ret.
 * Check_Bonus_SE is 0x9849A size 0x36, interior after the ret.
 * Se_Shock is 0x984D0 size 0x99 and is a scanned start.
 * Se_Myself is 0x98569 size 0x49, interior after the ret.
 * Se_Myself_Die is 0x985B2 size 0x45, interior after the ret.
 * Se_Let is 0x985F7 size 0x4D, interior after the ret.
 * Se_Let_SP is 0x98644 size 0x73, interior after the ret.
 * Call_Se is 0x986B7 size 0x1C, interior after the ret.
 * Se_Term is 0x986D3 size 0x4B, interior after the ret.
 * Finish_SE is 0x9871E size 0x49, interior after the ret.
 * BGM_Stage_Data is 0x2652C8 and matches the 22 PlayStation 2 words.
 * The Gill path adds BGM_Stage_Data[17], which is 0x28.
 * bgm_selector is 0x32FD20. Its rows are 0, 1, 2, 1, 2, 1, 2, 1 and
 * 0, 1, 0, 1, 0, 1, 0, 1. sys_w.bgm_type is the byte at 0x7C595A.
 * gSeqStatus is the byte at 0xC7C836. Bonus_Game_Flag is the word at
 * 0x7A8272. Bonus_Type is the byte at 0x7A8120. Bonus_Voice_Data is
 * 0x267008 and its first eight words match. SE_Shock_Data is 0x265304.
 * Finish_SE_Data is 0x265314. Last_Called_SE is the word at 0x7A8796.
 * plw is 0xC7CEA0, stride 0x46C. Winner_id is the byte at 0x7A8472.
 * 0x98407 stays unnamed because Sound_SE and BGM_Request share that
 * body. 0x9C57A stays unnamed.
 */

#include "types.h"

typedef union {
    s32 cal;
    struct {
        s16 low;
        s16 pos;
    } disp;
} XY;

typedef struct {
    s32 sp;
} Reg32Sp;

typedef struct {
    Reg32Sp a[2];
    u8 rest[0x10];
} MVXY;

typedef struct {
    u8 raw0[6];
    s16 work_id;
    s16 id;
    u8 raw1[2];
    void *target_adrs;
    u8 raw2[0x44];
    s16 position_x;
    u8 raw3[0xE];
    XY xyz[3];
    u8 raw4[0xC];
    MVXY mvxy;
    u8 raw5[0xA];
    s16 vital_new;
    u8 raw6[0x2E8];
} WORK;

typedef struct {
    WORK wu;
    void *my_master;
    s16 master_work_id;
    s16 master_id;
} WORK_Other;

typedef struct {
    WORK wu;
    u8 raw[0x46C - 0x388];
} PLW;

typedef struct {
    u8 raw[0x1A];
    u8 bgm_type;
} _SYSTEM_W;

#if defined(__i386__)
_Static_assert(sizeof(WORK) == 0x388, "WORK");
_Static_assert(__builtin_offsetof(WORK, work_id) == 6, "work_id");
_Static_assert(__builtin_offsetof(WORK, id) == 8, "id");
_Static_assert(__builtin_offsetof(WORK, target_adrs) == 0xC, "target_adrs");
_Static_assert(__builtin_offsetof(WORK, position_x) == 0x54, "position_x");
_Static_assert(__builtin_offsetof(WORK, xyz) == 0x64, "xyz");
_Static_assert(__builtin_offsetof(WORK, mvxy) == 0x7C, "mvxy");
_Static_assert(__builtin_offsetof(WORK, vital_new) == 0x9E, "vital_new");
_Static_assert(__builtin_offsetof(WORK_Other, my_master) == 0x388, "my_master");
_Static_assert(__builtin_offsetof(WORK_Other, master_id) == 0x38E, "master_id");
_Static_assert(__builtin_offsetof(MVXY, a[1].sp) == 4, "a[1].sp");
_Static_assert(sizeof(PLW) == 0x46C, "PLW");
_Static_assert(__builtin_offsetof(_SYSTEM_W, bgm_type) == 0x1A, "bgm_type");
#endif

extern u8 Mode_Type;
extern u8 Play_Type;
extern u8 My_char[2];
extern s8 COM_id;
extern s16 Bonus_Game_Flag;
extern u8 Bonus_Type;
extern u8 gSeqStatus[1];
extern s16 Last_Called_SE;
extern s8 Winner_id;
extern PLW plw[2];
extern _SYSTEM_W sys_w;
extern s16 *bgm_selector[2];
extern const u16 BGM_Stage_Data[22];
extern const s16 SE_Shock_Data[7];
extern const s16 Finish_SE_Data[2][7];
extern const u16 Bonus_Voice_Data[768];

extern s16 gill_appear_check(void);
extern u16 get_center_position(void);
extern void SsRequestPan(u16 code, s16 pan, s16 unused, s32 unused2, s32 unused3);
extern void SsRequest(u16 num);
extern void SsRequest_CC(u16 num);
extern void SsBgmOff(void);
extern void spu_all_off(void);
extern void Go_BGM(void);

u16 Check_Bonus_SE(u16 code);
u16 Get_Position(PLW *wk);
s32 Check_Finish_SE(void);

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

void BGM_Request_Code_Check(u16 code) {
    SsRequest_CC(code);
}

void BGM_Stop(void) {
    SsBgmOff();
}

void SE_All_Off(void) {
    spu_all_off();
}

s32 Check_Finish_SE(void) {
    s16 xx;

    for (xx = 0; xx < 7; xx++) {
        if (Last_Called_SE == Finish_SE_Data[0][xx]) {
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

    if ((ewk->wu.work_id == 1) || (uid = ewk->master_id, uid < 2)) {
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
