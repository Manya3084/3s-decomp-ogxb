/* GD3rd.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * fsUpdateDiskDriveError 0x59A43 size 0xA. Read against the x86: on Xbox the
 * body is only DskDrvErrType = 0xFFFF (DskDrvErrType is 0xC805F0); the PS2
 * disc-type and error polling is gone. The C is the Xbox code
 * (analysis-ps2map/overrides/GD3rd.c).
 * fsOpen 0x59A4D size 0x5D. Read against the x86: 0x5FB is AFS_FILE_COUNT.
 * adxf is 0x795CD4. appFileSizes is 0x333100. The C is the PS2 C.
 * fsClose 0x59AAA size 0x14. Read against the x86: the unnamed dword is adxf.
 * The C is the PS2 C.
 * fsGetFileSize 0x59ABE size 0x19. Read against the x86: 0x5FB is
 * AFS_FILE_COUNT and 0x333100 appFileSizes. The C is the PS2 C.
 * fsCalSectorSize 0x59AD7 size 0xD.
 * fsCansel 0x59AE4 size 0x25. Read against the x86: the unnamed dword is adxf.
 * The C is the PS2 C.
 * fsCheckCommandExecuting 0x59B09 size 0x21. Read against the x86: the unnamed
 * dword is adxf; ADXF_GetStat is called once. The C is the PS2 C.
 * fsRequestFileRead 0x59B2A size 0x1A. Read against the x86: the unnamed dword
 * is adxf. The C is the PS2 C.
 * fsCheckFileReaded 0x59B44 size 0x2E. Read against the x86: the unnamed dword
 * is adxf. The C is the PS2 C.
 * waitVsyncDummy 0x59B72 size 0xA. Read against the x86: rewritten for Xbox:
 * it only runs ADXM_ExecMain and cseExecServer (folded into the return-0 stub
 * 0x4AFFA), with no vsync wait. The C is the Xbox code
 * (analysis-ps2map/overrides/GD3rd.c).
 * Init_Load_Request_Queue_1st 0x59B7C size 0x1C. Read against the x86: 0x28 is
 * the q_ldreq entry size and -1 a decrement. The C is the PS2 C.
 * Request_LDREQ_Break 0x59B98 size 0x8. Read against the x86: the unnamed byte
 * is ldreq_break. ldreq_break is 0xC7F4FC. The C is the PS2 C.
 * Check_LDREQ_Break 0x59BA0 size 0x11. Read against the x86: the unnamed byte
 * is ldreq_break. The C is the PS2 C.
 * Push_LDREQ_Queue 0x59BB1 size 0x79.
 * Check_LDREQ_Clear 0x59C92 size 0x14.
 * Check_LDREQ_Queue_Player 0x59CA6 size 0x4C. Read against the x86: the
 * unnamed array is ldreq_result. ldreq_result is 0xC7F7A0. The C is the PS2 C.
 * Check_LDREQ_Queue_Union 0x59CF2 size 0x3A. Read against the x86: 0x3C is a
 * ldreq index step; the unnamed array is ldreq_result. The C is the PS2 C.
 * Check_LDREQ_Queue_Direct 0x59D2C size 0x14. Read against the x86: 0x3C is a
 * ldreq index step; the unnamed array is ldreq_result. The C is the PS2 C.
 * q_ldreq_error 0x59D40 size 0x8.
 * fsFileReadSync 0x59D48 size 0x36.
 * load_it_use_this_key 0x59D7E size 0xA2. Read against the x86: 0x40 is a key
 * table step and 0x43CF74 the /GS stack cookie. The C is the PS2 C.
 * Push_LDREQ_Queue_Player 0x59E20 size 0xAF. Read against the x86: the offsets
 * are fields of ldreq_tbl records (0x25C740, 4 bytes each); 0x43CF74 is the
 * /GS stack cookie. The C is the PS2 C.
 * Push_LDREQ_Queue_Union 0x59ECF size 0x8A. Read against the x86: the offsets
 * are fields of ldreq_tbl records; 0x43CF74 is the /GS stack cookie. The C is
 * the PS2 C.
 * Push_LDREQ_Queue_Direct 0x59F59 size 0x69. Read against the x86: ldreq_tbl
 * is 0x25C740; 0x43CF74 is the /GS stack cookie. The C is the PS2 C.
 * Check_LDREQ_Queue_BG 0x59FC2 size 0x10.
 * load_it_use_any_key2 0x59FD2 size 0x83. Read against the x86: rewritten for
 * Xbox: there is no file-number check, and a file of size 0 sets DskDrvErrBe
 * and the load state word at 0xC7F4FA to 1 and enters the disc-error loop
 * sub_00059948. The C is the Xbox code (analysis-ps2map/overrides/GD3rd.c).
 * load_it_use_any_key 0x5A055 size 0x27.
 * Push_LDREQ_Queue_Metamor 0x5A07C size 0x44.
 * Push_LDREQ_Queue_BG 0x5A0C0 size 0x14.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * Setup_Directory_Record_Data, Check_LDREQ_Queue, disp_ldreq_status.
 * Push_ramcnt_key is folded into 0x97103.
 * cseExecServer is folded into 0x4AFFA.
 * sceCdGetDiskType has no XBE name and no aligned call.
 * sceCdGetError has no XBE name and no aligned call.
 * sceGsSyncV has no XBE name and no aligned call.
 * Data: ldreq_process_name: not located in the XBE, PS2 initializer kept.
 * Data: DskDrvErrBe 0xC7F4FE.
 * Data: DskDrvErrType 0xC805F0.
 * Data: DskDrvErrRetry: defined elsewhere on Xbox.
 * Data: ps2CdReadMode: defined elsewhere on Xbox.
 * Data: plt_req 0xC7F500.
 * Data: ldreq_break 0xC7F4FC.
 * Data: adxf 0x795CD4, in .bss, so it has no initial bytes to compare.
 * Data: sf3ptinfo: defined elsewhere on Xbox.
 * Data: q_ldreq 0xC7F520.
 * Data: ldreq_result 0xC7F7A0.
 * Data: lpr_wrdata is 0x25C718, 0x3 bytes compared.
 * Data: lpc_seldat: not located in the XBE, PS2 initializer kept.
 * Data: lpt_seldat is 0x25C720, 0x4 bytes compared.
 * Data: ldreq_process: not located in the XBE, PS2 initializer kept.
 * Data: ldreq_tbl 0x25C740, not compared.
 * Data: ldreq_ix is 0x25CBD8, 0xAC bytes compared.
 * Unnamed data used (not checked): load_it_use_this_key: 0x43cf74,0xc7f4fa;
 * Push_LDREQ_Queue_Player: 0x43cf74; Push_LDREQ_Queue_Union: 0x43cf74;
 * Push_LDREQ_Queue_Direct: 0x43cf74; load_it_use_any_key2: 0xc7f4fa.
 * Globals: lpr_wrdata 0x25C718, lpt_seldat 0x25C720, ldreq_tbl 0x25C740,
 * ldreq_ix 0x25CBD8, appFileSizes 0x333100, adxf 0x795CD4, My_char 0x7A8114,
 * ldreq_break 0xC7F4FC, DskDrvErrBe 0xC7F4FE, plt_req 0xC7F500, q_ldreq
 * 0xC7F520, ldreq_result 0xC7F7A0, DskDrvErrType 0xC805F0.
 */

#include "structs.h"

#define NULL 0
#define AFS_FILE_COUNT 1535
#define ADXF_STAT_READING (2)
#define ADXF_STAT_ERROR (4)

typedef struct {
	struct _sj_vtbl *vtbl;		
								
} SJ_OBJ;

typedef char					Char8;

typedef signed int				Sint32;

typedef SJ_OBJ *SJ;

typedef void *ADXSTM;

typedef  char				Sint8;

typedef struct _adx_fs {
    Sint8 used;       
    Sint8 stat;       
    Sint8 sjflag;     
    Sint8 stopnw_flg; 
    ADXSTM stm;       
    SJ sj;            
    Sint32 fnsct;     
    Sint32 fsize;     
    Sint32 skpos;     
    Sint32 rdstpos;   
    Sint32 rqsct;     
    Sint32 rdsct;     
    Sint8 *buf;       
    Sint32 bsize;     
    Sint32 rqrdsct;   
    
    Sint32 ofst; 
                 
    void *dir;
    const Char8 *unk38;
    Sint32 unk3C;
    Sint32 unk40;
} ADX_FS;

typedef ADX_FS *ADXF;

typedef struct {
    // total size: 0x4
    u8 trycount;    // offset 0x0, size 0x1
    u8 spindlctrl;  // offset 0x1, size 0x1
    u8 datapattern; // offset 0x2, size 0x1
    u8 pad;         // offset 0x3, size 0x1
} PS2CDReadMode;

typedef struct {
    // total size: 0x4
    u8 type;  // offset 0x0, size 0x1
    u8 ix;    // offset 0x1, size 0x1
    u8 frre;  // offset 0x2, size 0x1
    u8 kokey; // offset 0x3, size 0x1
} LDREQ_TBL;

typedef void (*LDREQ_Process_Func)(REQ*);

void sub_00097103(s16 key);
s32 sub_0004AFFA();
void sub_00059948(void);
extern s16 D_00C7F4FA;
void q_ldreq_error(REQ* curr);
void q_ldreq_texture_group(REQ* curr);
void q_ldreq_color_data(REQ* curr);
extern s32 appFileSizes[];
void ADXF_Close(ADXF adxf);
ADXF ADXF_OpenAfs(Sint32 ptid, Sint32 flid);
Sint32 ADXF_GetStat(ADXF adxf);
Sint32 ADXF_StopNw(ADXF adxf);
Sint32 ADXF_ReadNw(ADXF adxf, Sint32 nsct, void* buf);
void waitVsyncDummy();
Sint32 ADXM_ExecMain();
s16 Pull_ramcnt_key(size_t memreq, u8 kokey, u8 group, u8 frre);
uintptr_t Get_ramcnt_address(s16 key);
s32 load_it_use_this_key(u16 fnum, s16 key);
void Set_size_data_ramcnt_key(s16 key, u32 size);
s32 flLogOut(s8* format, ...);
s32 Push_LDREQ_Queue(REQ* ldreq);
void Push_LDREQ_Queue_Union(s16 ix);
void Push_LDREQ_Queue_Metamor();
extern u8 My_char[2];
void Push_LDREQ_Queue_Direct(s16 ix, s16 id);
s32 Check_LDREQ_Queue_Union(s16 ix);

extern u16 DskDrvErrBe;

extern u16 DskDrvErrType;

extern u16 DskDrvErrRetry;

extern PS2CDReadMode ps2CdReadMode;

extern s16 plt_req[2];

extern u8 ldreq_break;

struct _adx_fs* adxf = NULL;

extern u8 sf3ptinfo[3352];

extern REQ q_ldreq[16];

extern u8 ldreq_result[294];

const u8 lpr_wrdata[3] = { 0x03, 0xC0, 0x3C };

const u8 lpc_seldat[2] = { 10, 11 };

const u8 lpt_seldat[4] = { 3, 4, 5, 0 };

const LDREQ_Process_Func ldreq_process[6];

s8* ldreq_process_name[];

const LDREQ_TBL ldreq_tbl[294];

const s16 ldreq_ix[43][2];

const LDREQ_Process_Func ldreq_process[6] = {
    // size: 0x18, address: 0x51FE30
    q_ldreq_error, q_ldreq_texture_group, q_ldreq_color_data, q_ldreq_color_data, q_ldreq_color_data, q_ldreq_color_data
};

s8* ldreq_process_name[] = {
    // size: 0x18, address: 0x573AB0
    "EMP", "TEX", "COL", "SCR", "SND", "KNJ",
};

const LDREQ_TBL ldreq_tbl[294] = {
    // size: 0x0, address: 0x51FE80
    {
        0x1,
        0x1,
        0x2,
        0x3,
    },
    {
        0x1,
        0x1B,
        0x2,
        0x3,
    },
    {
        0x1,
        0x23,
        0x2,
        0x3,
    },
    {
        0x2,
        0x0,
        0x1,
        0xA,
    },
    {
        0x4,
        0x82,
        0x1,
        0x16,
    },
    {
        0x1,
        0x2,
        0x2,
        0x3,
    },
    {
        0x2,
        0x1,
        0x1,
        0xA,
    },
    {
        0x4,
        0x83,
        0x1,
        0x16,
    },
    {
        0x4,
        0x99,
        0x1,
        0x15,
    },
    {
        0x1,
        0x26,
        0x1,
        0xC,
    },
    {
        0x1,
        0x3,
        0x2,
        0x3,
    },
    {
        0x1,
        0x59,
        0x2,
        0x3,
    },
    {
        0x2,
        0x2,
        0x1,
        0xA,
    },
    {
        0x4,
        0x84,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0x4,
        0x2,
        0x3,
    },
    {
        0x2,
        0x3,
        0x1,
        0xA,
    },
    {
        0x2,
        0x55,
        0x1,
        0xA,
    },
    {
        0x4,
        0x85,
        0x1,
        0x16,
    },
    {
        0x1,
        0x5,
        0x2,
        0x3,
    },
    {
        0x2,
        0x4,
        0x1,
        0xA,
    },
    {
        0x4,
        0x86,
        0x1,
        0x16,
    },
    {
        0x2,
        0x54,
        0x1,
        0x2,
    },
    {
        0x1,
        0x3D,
        0x1,
        0x2,
    },
    {
        0x3,
        0x9A,
        0x1,
        0x1D,
    },
    {
        0x1,
        0x6,
        0x2,
        0x3,
    },
    {
        0x1,
        0x1B,
        0x2,
        0x3,
    },
    {
        0x2,
        0x5,
        0x1,
        0xA,
    },
    {
        0x2,
        0x56,
        0x1,
        0xA,
    },
    {
        0x4,
        0x87,
        0x1,
        0x16,
    },
    {
        0x1,
        0x7,
        0x2,
        0x3,
    },
    {
        0x2,
        0x6,
        0x1,
        0xA,
    },
    {
        0x2,
        0x9B,
        0x1,
        0xA,
    },
    {
        0x4,
        0x88,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0x8,
        0x2,
        0x3,
    },
    {
        0x1,
        0x5A,
        0x2,
        0x3,
    },
    {
        0x2,
        0x7,
        0x1,
        0xA,
    },
    {
        0x2,
        0x57,
        0x1,
        0xA,
    },
    {
        0x4,
        0x89,
        0x1,
        0x16,
    },
    {
        0x1,
        0x9,
        0x2,
        0x3,
    },
    {
        0x2,
        0x8,
        0x1,
        0xA,
    },
    {
        0x4,
        0x8A,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0xA,
        0x2,
        0x3,
    },
    {
        0x1,
        0x5B,
        0x2,
        0x3,
    },
    {
        0x2,
        0x9,
        0x1,
        0xA,
    },
    {
        0x4,
        0x8B,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0xB,
        0x2,
        0x3,
    },
    {
        0x2,
        0xA,
        0x1,
        0xA,
    },
    {
        0x4,
        0x8C,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0xC,
        0x2,
        0x3,
    },
    {
        0x1,
        0x5C,
        0x2,
        0x3,
    },
    {
        0x2,
        0xB,
        0x1,
        0xA,
    },
    {
        0x4,
        0x8D,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0xD,
        0x2,
        0x3,
    },
    {
        0x1,
        0x5D,
        0x2,
        0x3,
    },
    {
        0x2,
        0xC,
        0x1,
        0xA,
    },
    {
        0x4,
        0x8E,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0xE,
        0x2,
        0x3,
    },
    {
        0x1,
        0x5E,
        0x2,
        0x3,
    },
    {
        0x2,
        0xD,
        0x1,
        0xA,
    },
    {
        0x4,
        0x8F,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0xF,
        0x2,
        0x3,
    },
    {
        0x1,
        0x5F,
        0x2,
        0x3,
    },
    {
        0x2,
        0xE,
        0x1,
        0xA,
    },
    {
        0x4,
        0x90,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0x10,
        0x2,
        0x3,
    },
    {
        0x1,
        0x60,
        0x2,
        0x3,
    },
    {
        0x2,
        0xF,
        0x1,
        0xA,
    },
    {
        0x4,
        0x91,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0x11,
        0x2,
        0x3,
    },
    {
        0x2,
        0x10,
        0x1,
        0xA,
    },
    {
        0x4,
        0x92,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0x12,
        0x2,
        0x3,
    },
    {
        0x2,
        0x11,
        0x1,
        0xA,
    },
    {
        0x4,
        0x93,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0x13,
        0x2,
        0x3,
    },
    {
        0x2,
        0x12,
        0x1,
        0xA,
    },
    {
        0x4,
        0x94,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x1,
        0x14,
        0x2,
        0x3,
    },
    {
        0x1,
        0x61,
        0x2,
        0x3,
    },
    {
        0x2,
        0x13,
        0x1,
        0xA,
    },
    {
        0x4,
        0x95,
        0x1,
        0x16,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x15,
        0x1,
        0x2,
    },
    {
        0x1,
        0x53,
        0x1,
        0x13,
    },
    {
        0x1,
        0x54,
        0x1,
        0x13,
    },
    {
        0x1,
        0x34,
        0x1,
        0x13,
    },
    {
        0x3,
        0x29,
        0x1,
        0x12,
    },
    {
        0x2,
        0x16,
        0x1,
        0x2,
    },
    {
        0x1,
        0x2C,
        0x1,
        0x13,
    },
    {
        0x3,
        0x2A,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x17,
        0x1,
        0x2,
    },
    {
        0x1,
        0x3A,
        0x1,
        0x13,
    },
    {
        0x3,
        0x2B,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x18,
        0x1,
        0x2,
    },
    {
        0x1,
        0x2D,
        0x1,
        0x13,
    },
    {
        0x3,
        0x2C,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x19,
        0x1,
        0x2,
    },
    {
        0x1,
        0x32,
        0x1,
        0x13,
    },
    {
        0x3,
        0x2D,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x1A,
        0x1,
        0x2,
    },
    {
        0x1,
        0x2A,
        0x1,
        0x13,
    },
    {
        0x3,
        0x2E,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x1B,
        0x1,
        0x2,
    },
    {
        0x1,
        0x2F,
        0x1,
        0x13,
    },
    {
        0x3,
        0x2F,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x1C,
        0x1,
        0x2,
    },
    {
        0x1,
        0x35,
        0x1,
        0x13,
    },
    {
        0x3,
        0x30,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x1D,
        0x1,
        0x2,
    },
    {
        0x1,
        0x2B,
        0x1,
        0x13,
    },
    {
        0x3,
        0x31,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x1E,
        0x1,
        0x2,
    },
    {
        0x1,
        0x30,
        0x1,
        0x13,
    },
    {
        0x3,
        0x32,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x1F,
        0x1,
        0x2,
    },
    {
        0x1,
        0x55,
        0x1,
        0x13,
    },
    {
        0x3,
        0x33,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x20,
        0x1,
        0x2,
    },
    {
        0x1,
        0x56,
        0x1,
        0x13,
    },
    {
        0x3,
        0x34,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x58,
        0x1,
        0x2,
    },
    {
        0x1,
        0x57,
        0x1,
        0x13,
    },
    {
        0x3,
        0x35,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x21,
        0x1,
        0x2,
    },
    {
        0x1,
        0x31,
        0x1,
        0x13,
    },
    {
        0x3,
        0x36,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x22,
        0x1,
        0x2,
    },
    {
        0x1,
        0x2E,
        0x1,
        0x13,
    },
    {
        0x3,
        0x37,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x23,
        0x1,
        0x2,
    },
    {
        0x1,
        0x38,
        0x1,
        0x13,
    },
    {
        0x3,
        0x38,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x24,
        0x1,
        0x2,
    },
    {
        0x1,
        0x33,
        0x1,
        0x13,
    },
    {
        0x3,
        0x39,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x20,
        0x1,
        0x2,
    },
    {
        0x1,
        0x56,
        0x1,
        0x13,
    },
    {
        0x3,
        0x34,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x25,
        0x1,
        0x2,
    },
    {
        0x1,
        0x58,
        0x1,
        0x13,
    },
    {
        0x3,
        0x3B,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x26,
        0x1,
        0x2,
    },
    {
        0x1,
        0x37,
        0x1,
        0x13,
    },
    {
        0x3,
        0x3C,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x27,
        0x1,
        0x2,
    },
    {
        0x1,
        0x36,
        0x1,
        0x13,
    },
    {
        0x1,
        0x22,
        0x2,
        0x13,
    },
    {
        0x3,
        0x3D,
        0x1,
        0x12,
    },
    {
        0x1,
        0x21,
        0x2,
        0x13,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x28,
        0x1,
        0x2,
    },
    {
        0x1,
        0x3B,
        0x1,
        0x13,
    },
    {
        0x1,
        0x22,
        0x2,
        0x13,
    },
    {
        0x3,
        0x3E,
        0x1,
        0x12,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x0,
        0x0,
        0x0,
        0x0,
    },
    {
        0x2,
        0x40,
        0x1,
        0x2,
    },
    {
        0x2,
        0x41,
        0x1,
        0x2,
    },
    {
        0x2,
        0x42,
        0x1,
        0x2,
    },
    {
        0x2,
        0x43,
        0x1,
        0x2,
    },
    {
        0x2,
        0x44,
        0x1,
        0x2,
    },
    {
        0x2,
        0x45,
        0x1,
        0x2,
    },
    {
        0x2,
        0x46,
        0x1,
        0x2,
    },
    {
        0x2,
        0x47,
        0x1,
        0x2,
    },
    {
        0x2,
        0x48,
        0x1,
        0x2,
    },
    {
        0x2,
        0x49,
        0x1,
        0x2,
    },
    {
        0x2,
        0x4A,
        0x1,
        0x2,
    },
    {
        0x2,
        0x4B,
        0x1,
        0x2,
    },
    {
        0x2,
        0x4C,
        0x1,
        0x2,
    },
    {
        0x2,
        0x4D,
        0x1,
        0x2,
    },
    {
        0x2,
        0x4E,
        0x1,
        0x2,
    },
    {
        0x2,
        0x4F,
        0x1,
        0x2,
    },
    {
        0x2,
        0x50,
        0x1,
        0x2,
    },
    {
        0x2,
        0x51,
        0x1,
        0x2,
    },
    {
        0x2,
        0x52,
        0x1,
        0x2,
    },
    {
        0x2,
        0x53,
        0x1,
        0x2,
    },
    {
        0x4,
        0x6E,
        0x1,
        0x16,
    },
    {
        0x4,
        0x6F,
        0x1,
        0x16,
    },
    {
        0x4,
        0x70,
        0x1,
        0x16,
    },
    {
        0x4,
        0x71,
        0x1,
        0x16,
    },
    {
        0x4,
        0x72,
        0x1,
        0x16,
    },
    {
        0x4,
        0x73,
        0x1,
        0x16,
    },
    {
        0x4,
        0x74,
        0x1,
        0x16,
    },
    {
        0x4,
        0x75,
        0x1,
        0x16,
    },
    {
        0x4,
        0x76,
        0x1,
        0x16,
    },
    {
        0x4,
        0x77,
        0x1,
        0x16,
    },
    {
        0x4,
        0x78,
        0x1,
        0x16,
    },
    {
        0x4,
        0x79,
        0x1,
        0x16,
    },
    {
        0x4,
        0x7A,
        0x1,
        0x16,
    },
    {
        0x4,
        0x7B,
        0x1,
        0x16,
    },
    {
        0x4,
        0x7C,
        0x1,
        0x16,
    },
    {
        0x4,
        0x7D,
        0x1,
        0x16,
    },
    {
        0x4,
        0x7E,
        0x1,
        0x16,
    },
    {
        0x4,
        0x7F,
        0x1,
        0x16,
    },
    {
        0x4,
        0x80,
        0x1,
        0x16,
    },
    {
        0x4,
        0x81,
        0x1,
        0x16,
    },
    {
        0x4,
        0x82,
        0x1,
        0x16,
    },
    {
        0x4,
        0x83,
        0x1,
        0x16,
    },
    {
        0x4,
        0x84,
        0x1,
        0x16,
    },
    {
        0x4,
        0x85,
        0x1,
        0x16,
    },
    {
        0x4,
        0x86,
        0x1,
        0x16,
    },
    {
        0x4,
        0x87,
        0x1,
        0x16,
    },
    {
        0x4,
        0x88,
        0x1,
        0x16,
    },
    {
        0x4,
        0x89,
        0x1,
        0x16,
    },
    {
        0x4,
        0x8A,
        0x1,
        0x16,
    },
    {
        0x4,
        0x8B,
        0x1,
        0x16,
    },
    {
        0x4,
        0x82,
        0x1,
        0x16,
    },
    {
        0x4,
        0x83,
        0x1,
        0x16,
    },
    {
        0x4,
        0x84,
        0x1,
        0x16,
    },
    {
        0x4,
        0x85,
        0x1,
        0x16,
    },
    {
        0x4,
        0x86,
        0x1,
        0x16,
    },
    {
        0x4,
        0x87,
        0x1,
        0x16,
    },
    {
        0x4,
        0x88,
        0x1,
        0x16,
    },
    {
        0x4,
        0x89,
        0x1,
        0x16,
    },
    {
        0x4,
        0x8A,
        0x1,
        0x16,
    },
    {
        0x4,
        0x8B,
        0x1,
        0x16,
    },
    {
        0x2,
        0x0,
        0x1,
        0xA,
    },
    {
        0x2,
        0x1,
        0x1,
        0xA,
    },
    {
        0x2,
        0x2,
        0x1,
        0xA,
    },
    {
        0x2,
        0x3,
        0x1,
        0xA,
    },
    {
        0x2,
        0x4,
        0x1,
        0xA,
    },
    {
        0x2,
        0x5,
        0x1,
        0xA,
    },
    {
        0x2,
        0x6,
        0x1,
        0xA,
    },
    {
        0x2,
        0x7,
        0x1,
        0xA,
    },
    {
        0x2,
        0x8,
        0x1,
        0xA,
    },
    {
        0x2,
        0x9,
        0x1,
        0xA,
    },
    {
        0x2,
        0xA,
        0x1,
        0xA,
    },
    {
        0x2,
        0xB,
        0x1,
        0xA,
    },
    {
        0x2,
        0xC,
        0x1,
        0xA,
    },
    {
        0x2,
        0xD,
        0x1,
        0xA,
    },
    {
        0x2,
        0xE,
        0x1,
        0xA,
    },
    {
        0x2,
        0xF,
        0x1,
        0xA,
    },
    {
        0x2,
        0x10,
        0x1,
        0xA,
    },
    {
        0x2,
        0x11,
        0x1,
        0xA,
    },
    {
        0x2,
        0x12,
        0x1,
        0xA,
    },
    {
        0x2,
        0x13,
        0x1,
        0xA,
    },
    {
        0x5,
        0x97,
        0x2,
        0x19,
    },
    {
        0x5,
        0x98,
        0x2,
        0x1A,
    },
};

const s16 ldreq_ix[43][2] = {
    // size: 0xAC, address: 0x520320
    { 0x0000, 0x0005 }, { 0x0005, 0x0003 }, { 0x000A, 0x0004 }, { 0x000F, 0x0004 }, { 0x0013, 0x0003 },
    { 0x0019, 0x0005 }, { 0x001E, 0x0004 }, { 0x0023, 0x0005 }, { 0x0028, 0x0003 }, { 0x002D, 0x0004 },
    { 0x0032, 0x0003 }, { 0x0037, 0x0004 }, { 0x003C, 0x0004 }, { 0x0041, 0x0004 }, { 0x0046, 0x0004 },
    { 0x004B, 0x0004 }, { 0x0050, 0x0003 }, { 0x0055, 0x0003 }, { 0x005A, 0x0003 }, { 0x005F, 0x0004 },
    { 0x0064, 0x0005 }, { 0x0069, 0x0003 }, { 0x006E, 0x0003 }, { 0x0073, 0x0003 }, { 0x0078, 0x0003 },
    { 0x007D, 0x0003 }, { 0x0082, 0x0003 }, { 0x0087, 0x0003 }, { 0x008C, 0x0003 }, { 0x0091, 0x0003 },
    { 0x0096, 0x0003 }, { 0x009B, 0x0003 }, { 0x00A0, 0x0003 }, { 0x00A5, 0x0003 }, { 0x00AA, 0x0003 },
    { 0x00AF, 0x0003 }, { 0x00B4, 0x0003 }, { 0x00B9, 0x0003 }, { 0x00BE, 0x0003 }, { 0x00C3, 0x0003 },
    { 0x00C8, 0x0005 }, { 0x00CE, 0x0004 }, { 0x0016, 0x0003 },
};

/* Xbox: no disc polling; the drive error is always cleared. */
void fsUpdateDiskDriveError() {
    DskDrvErrType = 0xFFFF;
}

s32 fsOpen(REQ* req) {
    if (req->fnum >= AFS_FILE_COUNT) {
        return 0;
    }

    if (appFileSizes[req->fnum] == 0) {
        return 0;
    }

    if (adxf != NULL) {
        ADXF_Close(adxf);
    }

    adxf = ADXF_OpenAfs(0, req->fnum);

    if (adxf == NULL) {
        return 0;
    }

    req->info.number = 1;
    req->info.size = appFileSizes[req->fnum];
    return 1;
}

void fsClose(REQ* /* unused */) {
    ADXF_Close(adxf);
    adxf = NULL;
}

u32 fsGetFileSize(u16 fnum) {
    if (fnum >= AFS_FILE_COUNT) {
        return 0;
    }

    return appFileSizes[fnum];
}

u32 fsCalSectorSize(u32 size) {
    return (size + 2048 - 1) / 2048;
}

s32 fsCansel(REQ* /* unused */) {
    if (adxf != NULL && ADXF_GetStat(adxf) == ADXF_STAT_READING) {
        ADXF_StopNw(adxf);
    }

    return 1;
}

s32 fsCheckCommandExecuting() {
    if (adxf == NULL) {
        return 0;
    }

    if (ADXF_GetStat(adxf) == ADXF_STAT_READING || ADXF_GetStat(adxf) == ADXF_STAT_ERROR) {
        return 1;
    }

    return 0;
}

s32 fsRequestFileRead(REQ* /* unused */, u32 sec, void* buff) {
    ADXF_ReadNw(adxf, sec, buff);
    return 1;
}

s32 fsCheckFileReaded(REQ* /* unused */) {
    s32 rnum = ADXF_GetStat(adxf);
    fsUpdateDiskDriveError();

    if (rnum == ADXF_STAT_ERROR) {
        DskDrvErrBe = 1;
        return 2;
    }

    if (rnum == ADXF_STAT_READING) {
        return 0;
    }

    return 1;
}

s32 fsFileReadSync(REQ* req, u32 sec, void* buff) {
    s32 rnum = fsRequestFileRead(req, sec, buff);

    if (rnum == 0) {
        return 0;
    }

    while (1) {
        rnum = fsCheckFileReaded(req);

        if (rnum == 1) {
            return 1;
        }

        if (rnum == 2) {
            return 0;
        }

        waitVsyncDummy();
    }
}

/* Xbox: no vsync wait; it only runs the ADX and sound servers. */
void waitVsyncDummy() {
    ADXM_ExecMain();
    sub_0004AFFA();
}

/* Xbox: no file-number check; a file of size 0 raises the disc error. */
s32 load_it_use_any_key2(u16 fnum, void** adrs, s16* key, u8 kokey, u8 group) {
    u32 size;
    u32 err;

    size = fsGetFileSize(fnum);

    if (size == 0) {
        DskDrvErrBe = 1;
        D_00C7F4FA = 1;
        sub_00059948();
    }

    *key = Pull_ramcnt_key(fsCalSectorSize(size) << 11, kokey, group, 0);
    *adrs = (void*)Get_ramcnt_address(*key);

    err = load_it_use_this_key(fnum, *key);

    if (err != 0) {
        return size;
    }

    sub_00097103(*key);
    return 0;
}

s16 load_it_use_any_key(u16 fnum, u8 kokey, u8 group) {
    u32 err;
    void* adrs;
    s16 key;

    err = load_it_use_any_key2(fnum, &adrs, &key, kokey, group);

    if (err != 0) {
        return key;
    }

    return 0;
}

s32 load_it_use_this_key(u16 fnum, s16 key) {
    REQ req;
    u32 err;

    req.fnum = fnum;

    while (1) {
        err = fsOpen(&req);

        if (err == 0) {
            continue;
        }

        req.size = fsGetFileSize(req.fnum);
        req.sect = fsCalSectorSize(req.size);
        err = fsFileReadSync(&req, req.sect, (void*)Get_ramcnt_address(key));
        fsClose(&req);
        Set_size_data_ramcnt_key(key, req.size);

        if (err != 0) {
            return 1;
        }

        flLogOut("ファイルの読み込みに失敗しました。ファイル番号：%d\n", fnum);
    }
}

void Init_Load_Request_Queue_1st() {
    s16 i;

    for (i = 0; i < (s16)(sizeof(q_ldreq) / sizeof(REQ)); i++) {
        q_ldreq[i].be = 0;
        q_ldreq[i].type = 0;
    }

    ldreq_break = 0;
}

void Request_LDREQ_Break() {
    ldreq_break = 1;
}

u8 Check_LDREQ_Break() {
    if (ldreq_break) {
        return 1;
    }

    return fsCheckCommandExecuting();
}

void Push_LDREQ_Queue_Player(s16 id, s16 ix) {
    REQ ldreq;
    s16 i;
    s16 kara;
    s16 made;

    kara = ldreq_ix[ix][0];
    made = kara + ldreq_ix[ix][1];
    plt_req[id] = ix;

    for (i = kara; i < made; i++) {
        ldreq.type = ldreq_tbl[i].type;
        ldreq.id = id;
        ldreq.ix = ldreq_tbl[i].ix;
        ldreq.frre = ldreq_tbl[i].frre;
        ldreq.key = 0;
        ldreq.group = 0;
        ldreq.result = &ldreq_result[i];

        if (ldreq.type == 2) {
            ldreq.kokey = lpc_seldat[id];
        } else {
            ldreq.kokey = lpt_seldat[id];
        }

        Push_LDREQ_Queue(&ldreq);
    }
}

void Push_LDREQ_Queue_BG(s16 ix) {
    Push_LDREQ_Queue_Union(ix + 20);
    Push_LDREQ_Queue_Metamor();
}

void Push_LDREQ_Queue_Union(s16 ix) {
    REQ ldreq;
    s16 i;
    s16 kara;
    s16 made;

    kara = ldreq_ix[ix][0];
    made = kara + ldreq_ix[ix][1];

    for (i = kara; i < made; i++) {
        ldreq.type = ldreq_tbl[i].type;
        ldreq.id = 2;
        ldreq.ix = ldreq_tbl[i].ix;
        ldreq.frre = ldreq_tbl[i].frre;
        ldreq.kokey = ldreq_tbl[i].kokey;
        ldreq.key = 0;
        ldreq.group = 0;
        ldreq.result = &ldreq_result[i];
        Push_LDREQ_Queue(&ldreq);
    }
}

void Push_LDREQ_Queue_Metamor() {
    switch ((My_char[0] == 0x12) + (My_char[1] == 0x12) * 2) {
    case 1:
        Push_LDREQ_Queue_Direct(My_char[1] + 0xD4, 0);
        break;

    case 2:
        Push_LDREQ_Queue_Direct(My_char[0] + 0xD4, 1);
        break;

    case 3:
        Push_LDREQ_Queue_Direct(0xE6, 2);
        break;
    }
}

void Push_LDREQ_Queue_Direct(s16 ix, s16 id) {
    REQ ldreq;
    ldreq.type = ldreq_tbl[ix].type;
    ldreq.id = id;
    ldreq.ix = ldreq_tbl[ix].ix;
    ldreq.frre = ldreq_tbl[ix].frre;
    ldreq.kokey = ldreq_tbl[ix].kokey;
    ldreq.key = 0;
    ldreq.group = 0;
    ldreq.result = &ldreq_result[ix];
    Push_LDREQ_Queue(&ldreq);
}

s32 Push_LDREQ_Queue(REQ* ldreq) {
    s16 i;
    u8 masknum;

    for (i = 0; i < 16; i++) {
        if (q_ldreq[i].be == 0) {
            break;
        }
    }

    if (i != 0x10) {
        q_ldreq[i] = ldreq[0];
        q_ldreq[i].be = 2;
        q_ldreq[i].rno = 0;
        q_ldreq[i].retry = 0x40;

        switch (ldreq->id) {
        case 0:
            masknum = 3;
            break;

        case 1:
            masknum = 0xC0;
            break;

        default:
            masknum = 0x3C;
            break;
        }

        *(u8*)(&q_ldreq[i].result)[0] &= ~masknum;
        return 1;
    }

    flLogOut("ファイル読み込み要求バッファがオーバーしました。\n");
    return 0;
}

s32 Check_LDREQ_Clear() {
    return q_ldreq->be == 0 && q_ldreq[1].be == 0;
}

s32 Check_LDREQ_Queue_Player(s16 id) {
    s16 i;
    s16 kara;
    s16 made;

    kara = ldreq_ix[plt_req[id]][0];
    made = kara + ldreq_ix[plt_req[id]][1];

    for (i = kara; i < made; i++) {
        if (!(ldreq_result[i] & lpr_wrdata[id])) {
            break;
        }
    }

    if (i != made) {
        return 0;
    }

    return 1;
}

s32 Check_LDREQ_Queue_BG(s16 ix) {
    return Check_LDREQ_Queue_Union(ix + 20);
}

s32 Check_LDREQ_Queue_Union(s16 ix) {
    s16 i;
    s16 kara;
    s16 made;

    kara = ldreq_ix[ix][0];
    made = kara + ldreq_ix[ix][1];

    for (i = kara; i < made; i++) {
        if (!(ldreq_result[i] & lpr_wrdata[2])) {
            break;
        }
    }

    if (i != made) {
        return 0;
    }

    return 1;
}

s32 Check_LDREQ_Queue_Direct(s16 ix) {
    if (!(ldreq_result[ix] & lpr_wrdata[2])) {
        return 0;
    }

    return 1;
}

void q_ldreq_error(REQ* curr) {
    curr->be = 0;
    flLogOut("Q_LDREQ_ERROR : ロード処理の指定に誤りがあります。\n");
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

s32 Setup_Directory_Record_Data() {
    DskDrvErrBe = 0;
    DskDrvErrType = 0xFFFF;
    DskDrvErrRetry = 0;

    ADXF_LoadPartitionNw(0, "SF33RD.AFS", NULL, sf3ptinfo);

    while (1) {
        if (ADXF_GetPtStat(0) == ADXF_STAT_READEND) {
            break;
        }

#if defined(TARGET_PS2)
        sceGsSyncV(0);
#else
        // CRI relies on VSync interrupts to execute its file system server.
        // On modern platforms we don't call the VSync interrupt handler until
        // we get to the main loop. That's why we have to emulate the interrupt
        // manually like this.
        begin_interrupt();
        ADXPS2_ExecVint(0);
        end_interrupt();
#endif

        ADXM_ExecMain();
    }

    ps2CdReadMode.trycount = 64;
    ps2CdReadMode.spindlctrl = 1;
    ps2CdReadMode.datapattern = 0;
    ps2CdReadMode.pad = 0;
    return 1;
}

void Check_LDREQ_Queue() {
    s16 i;

    disp_ldreq_status();

    if (!ldreq_break) {
        if (q_ldreq->be != 0) {
            ldreq_process[q_ldreq->type](q_ldreq);

            if (q_ldreq->be == 0) {
                for (i = 0; i < 15; i++) {
                    q_ldreq[i] = q_ldreq[i + 1];
                }

                q_ldreq[i].be = 0;
                q_ldreq[i].type = 0;
            }

            return;
        }
    } else {
        if (q_ldreq->be == 1) {
            fsCansel(q_ldreq);
        }

        Init_Load_Request_Queue_1st();
    }
}

void disp_ldreq_status() {
    s16 i;

    flPrintColor(0xFFFFFF8F);

    if (Debug_w[0xE]) {
        for (i = 0; i < 16; i++) {
            flPrintL(2, i + 18, "%1d", q_ldreq[i].be);
            flPrintL(3, i + 18, ldreq_process_name[q_ldreq[i].type]);
        }

        flPrintL(2, i + 18, "%4d", system_timer);
    }
}
#endif
