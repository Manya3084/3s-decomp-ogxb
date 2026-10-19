/* color3rd.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * init_color_trans_req 0xB564D size 0x1F. FLAG: x86-only offsets 0x2.
 * palCopyGhostDC 0xB566C size 0x3D.
 * palConvSrcToRam 0xB56A9 size 0x9C.
 * palCreateGhost 0xB5745 size 0x15C. FLAG: x86-only constants 0x800.
 * palGetChunkGhostDC 0xB58A1 size 0x6.
 * palGetChunkGhostCP3 0xB58A7 size 0x6.
 * palConvRowTim2CI8Clut 0xB58AD size 0x56. FLAG: x86-only constants
 * 0x3e0,0x7c00,0x8000.
 * palUpdateGhostDC 0xB5903 size 0x78.
 * palUpdateGhostCP3 0xB597B size 0x66.
 * set_hitmark_color 0xB59E1 size 0x99.
 * init_trans_color_ram 0xB5A7A size 0x726. FLAG: x86-only callees
 * xb_SetColorRamEntry,xb_PurgeListEntry,xb_GetExtraLoadBuffer; PS2-only
 * callees cseSendBd2SpuWithId,cseMemMapSetPhdAddr; x86-only constants
 * 0x1c,0x52,0x61,0x1600; x86-only offsets
 * -0xe00,-0x800,-0x400,-0x80,-0x1,0x1,0x80,0x100.
 * push_color_trans_req 0xB61A0 size 0x26.
 * q_ldreq_color_data 0xB61C6 size 0x1B9. FLAG: x86-only callees
 * xb_GetColorRamEntry,xb_ShowDiskReadError; PS2-only callees cseGetIdStoredBd,
 * Get_size_data_ramcnt_key,cseSendBd2SpuWithId,cseMemMapSetPhdAddr,cseTsbSetBa
 * nkAddr; x86-only offsets 0x5; x86-only globals DskDrvErrBe.
 * load_any_color 0xB637F size 0x40.
 * cseTsbSetBankAddr 0xF4532 size 0x5. FLAG: not compared.
 * Not located in sf33rd.xbe; their PS2 C is kept under #if 0:
 * cseTsbSetBankAddr, cseMemMapSetPhdAddr.
 * cseGetIdStoredBd has no XBE name and no aligned call.
 * cseMemMapSetPhdAddr has no XBE name and no aligned call.
 * cseSendBd2SpuWithId has no XBE name and no aligned call.
 * flUnlockPalette is folded into 0x9B78F.
 * njSetPaletteMode is folded into 0x4384A.
 * sndCheckVTransStatus is folded into 0x9B78F.
 * Data: colPalBuffDC 0x796080.
 * Data: ColorRAM 0x7AAD60.
 * Data: col3rd_w 0x7AAC60.
 * Data: plcol 0x7AAD50.
 * Data: palFormRam 0x7BAD80.
 * Data: palFormSrc 0x7AAD20.
 * Data: palFormConv 0x7BAD60.
 * Data: hitmark_color is 0x283458, 0x100 bytes compared.
 * Data: color_file 0x283558: the Xbox AFS file numbers, taken from the XBE
 * (the PS2 values differ in 143 of the 161 rows).
 * cseTsbSetBankAddr is defined in
 * sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.c, the object retail puts it in.
 * Unnamed data used (not checked): init_trans_color_ram:
 * 0x7c5ce0,0x881400,0x9ca4c0,0xb84200; q_ldreq_color_data: 0xc7f4fa.
 * Globals: lpr_wrdata 0x25C718, hitmark_color 0x283458, color_file 0x283558,
 * cseTSBDataTable 0x32FD28, colPalBuffDC 0x796080, My_char 0x7A8114,
 * Player_Color 0x7A8906, hi_meta 0x7A9EA0, col3rd_w 0x7AAC60, palFormSrc
 * 0x7AAD20, plcol 0x7AAD50, ColorRAM 0x7AAD60, palFormConv 0x7BAD60,
 * palFormRam 0x7BAD80, DskDrvErrBe 0xC7F4FE.
 */

#include "structs.h"

/* Retail addresses the code used as numbers: the sound bank buffers. */
extern u8 D_009CA4C0[];
extern u8 D_00B84200[];
extern u8 D_007C5CE0[];
extern u8 D_00881400[];

typedef struct {
    // total size: 0x1C00
    u16 col[2][28][64]; // offset 0x0, size 0x1C00
} COL;

typedef struct {
    // total size: 0x8
    u16 data; // offset 0x0, size 0x2
    u16 type; // offset 0x2, size 0x2
    u16 apfn; // offset 0x4, size 0x2
    u16 free; // offset 0x6, size 0x2
} col_file_data;

typedef struct {
    // total size: 0x1000
    u16 col[2][16][64]; // offset 0x0, size 0x1000
} COL_x1000;

typedef struct {
    u16 col[64]; // offset 0x0, size 0x80
} COL_x80;

typedef struct {
    u16 col[3][64]; // offset 0x0, size 0x180
} COL_x180;

typedef struct {
    u16 col[2][64]; // offset 0x0, size 0x100
} COL_x100;

typedef struct {
    u16 col[20][16][16]; // offset 0x0, size 0x2800
} COL_x2800;

extern s32 mlTsbSetBankAddr(u32 bank, SoundEvent *addr);
extern Col3rd_W col3rd_w;
extern u16 colPalBuffDC[1024];
extern u16 ColorRAM[512][64];
extern PixelFormat palFormSrc;
extern PixelFormat palFormRam;
extern s32 palFormConv;
extern s16 Pull_ramcnt_key(u32 memreq, u8 kokey, u8 group, u8 frre);
extern void *Get_ramcnt_address(s16 key);
extern s32 ppgSetupPalChunkDir(Palette *pch, PPLFileHeader *ppl, u8 *adrs, s32 ixNum1st, s32 unused);
extern void Push_ramcnt_key(s32 key);
extern void sub_0004384A(s32 mode);
extern void njSetPaletteData(s32 ofs, s32 cnt, void *data);
extern void flLockPalette(void *rect, u32 handle, plContext *bits, s32 flag);
extern s32 sub_0009B78F(u32 handle);
extern u32 Get_size_data_ramcnt_key(s16 key);
extern u8 My_char[2];
extern s8 Player_Color[2];
extern COL *plcol[2];
extern u16 hi_meta[2][2][64];
extern SoundEvent *cseTSBDataTable[];
extern void metamor_color_store(s32 wkid);
extern void xb_SetColorRamEntry(void *addr, u32 size, s32 id, s32 index);
extern void xb_PurgeListEntry(s32 bank);
extern void waitVsyncDummy(void);
extern u8 *xb_GetExtraLoadBuffer(void);
extern const col_file_data color_file[161];
extern const u8 lpr_wrdata[3];
extern u16 DskDrvErrBe;
extern u16 D_00C7F4FA;
extern s32 fsCheckCommandExecuting(void);
extern s32 fsOpen(REQ *curr);
extern void fsClose(REQ *curr);
extern u32 fsGetFileSize(u16 fnum);
extern u32 fsCalSectorSize(u32 size);
extern s32 fsRequestFileRead(REQ *curr, u32 sect, void *adrs);
extern s32 fsCheckFileReaded(REQ *curr);
extern s16 load_it_use_any_key(u16 fnum, u8 kokey, u8 group);
extern void xb_ShowDiskReadError(void);
extern s32 xb_GetColorRamEntry(s32 id);
extern void Set_size_data_ramcnt_key(s16 key, u32 size);
void init_trans_color_ram(s16 id, s16 key, u8 type, u16 data);
u16 palConvSrcToRam(u16 col);
void palUpdateGhostCP3(s32 pal, s32 nums);
void palConvRowTim2CI8Clut(u16* src, u32* dst, s32 size);
s32 cseTsbSetBankAddr(u32 bank, SoundEvent* addr);
void palCopyGhostDC(s32 ofs, s32 cnt, void *data);
void palUpdateGhostDC(void);

extern u16 colPalBuffDC[1024];

extern u16 ColorRAM[512][64];

extern Col3rd_W col3rd_w;

extern COL* plcol[2];

extern PixelFormat palFormRam;

extern PixelFormat palFormSrc;

extern s32 palFormConv;

const u16 hitmark_color[128];

const col_file_data color_file[161];

const u16 hitmark_color[128] = {
    0,     64478, 64408, 64338, 64268, 64200, 64068, 63942, 63808, 58332, 52186, 54104, 51988, 47888, 41740, 49424,
    64478, 58270, 54174, 49950, 45662, 43550, 43486, 41310, 64478, 64346, 64214, 64148, 64016, 63884, 63752, 61506,
    36944, 64478, 64470, 64402, 64332, 64200, 63940, 61568, 55296, 32768, 32768, 32768, 32768, 32768, 32768, 32768,
    64478, 62302, 60190, 60124, 58012, 57882, 55770, 53658, 64478, 62302, 60190, 60124, 58012, 57882, 55770, 53658,
    0,     64478, 64472, 60298, 54148, 50054, 45896, 39690, 37512, 58332, 52186, 54104, 51988, 47888, 41740, 49424,
    64478, 62302, 60190, 60124, 58012, 57882, 55770, 53658, 64478, 64346, 64214, 64148, 64016, 63884, 63752, 61506,
    36944, 64478, 64470, 64402, 64332, 64200, 63940, 61568, 55296, 32768, 32768, 32768, 32768, 32768, 32768, 32768,
    64478, 58270, 54174, 49950, 45662, 43550, 43486, 41310, 64478, 58206, 56094, 53982, 53918, 51806, 49694, 47582
};

const col_file_data color_file[161] = { { .data = 0x0, .type = 0x1, .apfn = 0x5B3, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5B6, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5BA, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5BD, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5C1, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5C4, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5C8, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5CD, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5D1, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5D5, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5D8, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5DC, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5E0, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5E4, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5E8, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5EC, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5EF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5F2, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5F5, .free = 0x0 },
                                        { .data = 0x0, .type = 0x1, .apfn = 0x5F9, .free = 0x0 },
                                        { .data = 0x20, .type = 0x2, .apfn = 0xB, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x563, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x568, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x56B, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x56E, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x571, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x574, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x577, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x57A, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x57D, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x580, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x583, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x586, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x58C, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x58F, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x592, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x595, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x598, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x59B, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x59E, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x5A3, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x567, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x56A, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x56D, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x570, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x573, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x576, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x578, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x57C, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x57F, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x582, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x585, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x588, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x58B, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x58E, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x591, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x594, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x597, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x597, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x59A, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x59D, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x5A1, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x5A6, .free = 0x0 },
                                        { .data = 0x0, .type = 0x7, .apfn = 0x5A7, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x54F, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x550, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x551, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x552, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x553, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x554, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x555, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x556, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x557, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x558, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x559, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x55A, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x55B, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x55C, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x55D, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x55E, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x55F, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x560, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x561, .free = 0x0 },
                                        { .data = 0x0, .type = 0x3, .apfn = 0x562, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x52, .free = 0x0 },
                                        { .data = 0x6, .type = 0x4, .apfn = 0x5BE, .free = 0x0 },
                                        { .data = 0x4, .type = 0x5, .apfn = 0x5C5, .free = 0x0 },
                                        { .data = 0x5, .type = 0x6, .apfn = 0x5CE, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x589, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x13, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x14, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x15, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x16, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x17, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x18, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x19, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x1A, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x1B, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x1C, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x1D, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x1E, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x1F, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x20, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x21, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x22, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x23, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x24, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x25, .free = 0x0 },
                                        { .data = 0x12C, .type = 0x2, .apfn = 0x26, .free = 0x0 },
                                        { .data = 0x0, .type = 0x50, .apfn = 0x7, .free = 0x0 },
                                        { .data = 0x0, .type = 0x51, .apfn = 0x8, .free = 0x0 },
                                        { .data = 0x0, .type = 0x52, .apfn = 0x9, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0xA, .apfn = 0x5B4, .free = 0x0 },
                                        { .data = 0x1, .type = 0xA, .apfn = 0x5B7, .free = 0x0 },
                                        { .data = 0x2, .type = 0xA, .apfn = 0x5BB, .free = 0x0 },
                                        { .data = 0x3, .type = 0xA, .apfn = 0x5BF, .free = 0x0 },
                                        { .data = 0x4, .type = 0xA, .apfn = 0x5C2, .free = 0x0 },
                                        { .data = 0x5, .type = 0xA, .apfn = 0x5C6, .free = 0x0 },
                                        { .data = 0x6, .type = 0xA, .apfn = 0x5CA, .free = 0x0 },
                                        { .data = 0x7, .type = 0xA, .apfn = 0x5CF, .free = 0x0 },
                                        { .data = 0x8, .type = 0xA, .apfn = 0x5D2, .free = 0x0 },
                                        { .data = 0x9, .type = 0xA, .apfn = 0x5D6, .free = 0x0 },
                                        { .data = 0xA, .type = 0xA, .apfn = 0x5D9, .free = 0x0 },
                                        { .data = 0xB, .type = 0xA, .apfn = 0x5DD, .free = 0x0 },
                                        { .data = 0xC, .type = 0xA, .apfn = 0x5E1, .free = 0x0 },
                                        { .data = 0xD, .type = 0xA, .apfn = 0x5E5, .free = 0x0 },
                                        { .data = 0xE, .type = 0xA, .apfn = 0x5E9, .free = 0x0 },
                                        { .data = 0xF, .type = 0xA, .apfn = 0x5ED, .free = 0x0 },
                                        { .data = 0x10, .type = 0xA, .apfn = 0x5F0, .free = 0x0 },
                                        { .data = 0x11, .type = 0xA, .apfn = 0x5F3, .free = 0x0 },
                                        { .data = 0x12, .type = 0xA, .apfn = 0x5F6, .free = 0x0 },
                                        { .data = 0x13, .type = 0xA, .apfn = 0x5FA, .free = 0x0 },
                                        { .data = 0x0, .type = 0xC, .apfn = 0x544, .free = 0x0 },
                                        { .data = 0x0, .type = 0x61, .apfn = 0xD, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0xB, .apfn = 0x53E, .free = 0x0 },
                                        { .data = 0x0, .type = 0x63, .apfn = 0x51, .free = 0x0 },
                                        { .data = 0x4, .type = 0x4, .apfn = 0x5C9, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0x10, .free = 0x0 },
                                        { .data = 0x0, .type = 0x0, .apfn = 0xA, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xFFFF, .free = 0x0 },
                                        { .data = 0x0, .type = 0x9, .apfn = 0xC, .free = 0x0 } };

void q_ldreq_color_data(REQ *curr) {
    col_file_data *cfn;
    s32 err;

    cfn = (col_file_data *)&color_file[curr->ix];

    switch (curr->rno) {
    case 0:
        if (fsCheckCommandExecuting() != 0) {
            break;
        }

        if (cfn->type == 10) {
            if (sub_0009B78F(0) == 0) {
                break;
            }

            if (xb_GetColorRamEntry(curr->id + 1) == cfn->data + 1) {
                *curr->result |= lpr_wrdata[curr->id];
                curr->be = 0;
                break;
            }
        }

        curr->rno = 1;
        curr->fnum = cfn->apfn;
        curr->retry -= 1;

        if (cfn->apfn == 0xFFFF) {
            *curr->result |= lpr_wrdata[curr->id];
            curr->be = 0;
        }

        if (curr->retry == 0) {
            DskDrvErrBe = 1;
            D_00C7F4FA = 1;
            xb_ShowDiskReadError();
            return;
        }

        /* fallthrough */

    case 1:
        err = fsOpen(curr);

        if (err == 0) {
            curr->rno = 0;
            break;
        }

        curr->rno = 2;
        /* fallthrough */

    case 2:
        curr->size = (s32)fsGetFileSize(curr->fnum);
        curr->sect = (s32)fsCalSectorSize((u32)curr->size);
        curr->key = Pull_ramcnt_key((u32)curr->sect << 11, curr->kokey, curr->group, curr->frre);
        Set_size_data_ramcnt_key(curr->key, (u32)curr->size);
        curr->rno = 3;
        /* fallthrough */

    case 3:
        err = fsRequestFileRead(curr, (u32)curr->sect, Get_ramcnt_address(curr->key));

        if (err == 0) {
            Push_ramcnt_key(curr->key);
            fsClose(curr);
            curr->rno = 0;
        } else {
            curr->rno = 4;
            curr->be = 1;
        }

        break;

    case 4:
        switch (fsCheckFileReaded(curr)) {
        case 1:
            init_trans_color_ram(curr->id, curr->key, cfn->type, cfn->data);
            fsClose(curr);
            *curr->result |= lpr_wrdata[curr->id];
            curr->be = 0;
            break;

        case 0:
            break;

        default:
            Push_ramcnt_key(curr->key);
            fsClose(curr);
            curr->be = 2;
            curr->rno = 0;
            break;
        }

        break;
    }
}

void load_any_color(u16 ix, u8 kokey) {
    col_file_data *cfn;
    s16 key;

    cfn = (col_file_data *)&color_file[ix];
    key = load_it_use_any_key(cfn->apfn, kokey, 0);

    if (key != 0) {
        init_trans_color_ram(0, key, cfn->type, cfn->data);
    }
}

void set_hitmark_color(void) {
    s16 i;

    for (i = 0; i < 64; i++) {
        ColorRAM[7][i] = ColorRAM[15][i] = palConvSrcToRam(hitmark_color[i]);
        ColorRAM[23][i] = ColorRAM[31][i] = palConvSrcToRam(hitmark_color[i + 64]);
    }

    sub_0004384A(0);
    njSetPaletteData(64, 64, ColorRAM[15]);
    njSetPaletteData(576, 64, ColorRAM[31]);
    palUpdateGhostCP3(7, 1);
    palUpdateGhostCP3(15, 1);
    palUpdateGhostCP3(23, 1);
    palUpdateGhostCP3(31, 1);
}

void init_trans_color_ram(s16 id, s16 key, u8 type, u16 data) {
    u16 *ldadrs;
    u16 *tradrs;
    s16 i;
    s16 j;
    s32 n;
    s32 size;
    u8 *loaded;
    u8 *image;
    u32 nbytes;

    switch (type) {
    case 1:
        plcol[id] = (COL *)Get_ramcnt_address(key);

        if (My_char[id] == 0) {
            for (i = 0; i < 64; i++) {
                ColorRAM[id * 16][i] = palConvSrcToRam(plcol[id]->col[0][Player_Color[id]][i]);
                ColorRAM[(id * 16) + 8][i] = palConvSrcToRam(plcol[id]->col[1][Player_Color[id]][i]);
            }

            for (i = 0; i < 6; i++) {
                for (j = 0; j < 64; j++) {
                    ColorRAM[i + ((id * 16) + 1)][j] = palConvSrcToRam(plcol[id]->col[0][i + 16][j]);
                    ColorRAM[i + ((id * 16) + 9)][j] = palConvSrcToRam(plcol[id]->col[1][i + 16][j]);
                }
            }
        } else {
            tradrs = plcol[id]->col[0][Player_Color[id]];
            ldadrs = ColorRAM[id * 16];

            for (i = 0; i < 64; i++) {
                ldadrs[i] = ldadrs[i + 512] = palConvSrcToRam(tradrs[i]);
            }

            ldadrs += 64;
            tradrs = plcol[id]->col[0][16];

            for (i = 0; i < 384; i++) {
                ldadrs[i] = ldadrs[i + 512] = palConvSrcToRam(tradrs[i]);
            }
        }

        tradrs = plcol[id]->col[0][22];

        if (id != 0) {
            ldadrs = ColorRAM[506];
        } else {
            ldadrs = ColorRAM[502];
        }

        for (i = 0; i < 256; i++) {
            ldadrs[i] = palConvSrcToRam(tradrs[i]);
        }

        Push_ramcnt_key(key);
        palUpdateGhostCP3(id * 16, 16);

        if (id != 0) {
            palUpdateGhostCP3(506, 4);
        } else {
            palUpdateGhostCP3(502, 4);
        }

        break;

    case 2:
        size = (s32)Get_size_data_ramcnt_key(key) / 2;
        tradrs = (u16 *)Get_ramcnt_address(key);
        ldadrs = (u16 *)ColorRAM[data];

        for (n = 0; n < size; n++) {
            ldadrs[n] = palConvSrcToRam(tradrs[n]);
        }

        Push_ramcnt_key(key);

        if (data == 32) {
            ColorRAM[511][0] = 0;

            for (i = 1; i < 64; i++) {
                ColorRAM[511][i] = 0x8000;
            }
        }

        palUpdateGhostCP3(data, size / 64);
        break;

    case 3: {
        COL_x1000 *dadr = (COL_x1000 *)Get_ramcnt_address(key);

        if (id == 2) {
            for (i = 0; i < 64; i++) {
                hi_meta[0][0][i] = dadr->col[0][Player_Color[0]][i];
                hi_meta[0][1][i] = dadr->col[0][Player_Color[0]][i];
                hi_meta[1][0][i] = dadr->col[0][Player_Color[1]][i];
                hi_meta[1][1][i] = dadr->col[0][Player_Color[1]][i];
            }

            metamor_color_store(0);
            metamor_color_store(1);
        } else {
            if (My_char[(id + 1) & 1] == 0) {
                for (i = 0; i < 64; i++) {
                    hi_meta[id][0][i] = dadr->col[0][Player_Color[id]][i];
                    hi_meta[id][1][i] = dadr->col[1][Player_Color[id]][i];
                }
            } else {
                for (i = 0; i < 64; i++) {
                    hi_meta[id][0][i] = dadr->col[0][Player_Color[id]][i];
                    hi_meta[id][1][i] = dadr->col[0][Player_Color[id]][i];
                }
            }

            metamor_color_store(id);
        }

        Push_ramcnt_key(key);
        break;
    }

    case 4: {
        COL_x80 *adr = (COL_x80 *)Get_ramcnt_address(key);
        u16 *src = adr[Player_Color[id]].col;
        u16 *dst = ColorRAM[data + (id * 16)];

        for (i = 0; i < 64; i++) {
            dst[i] = palConvSrcToRam(src[i]);
        }

        dst = ColorRAM[data + (id * 16) + 8];

        for (i = 0; i < 64; i++) {
            dst[i] = palConvSrcToRam(src[i]);
        }

        Push_ramcnt_key(key);
        palUpdateGhostCP3(data + (id * 16), 1);
        palUpdateGhostCP3(data + (id * 16) + 8, 1);
        break;
    }

    case 5: {
        COL_x180 *adr = (COL_x180 *)Get_ramcnt_address(key);
        u16 *src = adr[Player_Color[id]].col[0];
        u16 *dst = ColorRAM[data + (id * 16)];

        for (i = 0; i < 192; i++) {
            dst[i] = palConvSrcToRam(src[i]);
        }

        dst = ColorRAM[data + (id * 16) + 8];

        for (i = 0; i < 192; i++) {
            dst[i] = palConvSrcToRam(src[i]);
        }

        Push_ramcnt_key(key);
        palUpdateGhostCP3(data + (id * 16), 3);
        palUpdateGhostCP3(data + (id * 16) + 8, 3);
        break;
    }

    case 6: {
        COL_x100 *adr = (COL_x100 *)Get_ramcnt_address(key);
        u16 *src = adr[Player_Color[id]].col[0];
        u16 *dst = ColorRAM[data + (id * 16)];

        for (i = 0; i < 128; i++) {
            dst[i] = palConvSrcToRam(src[i]);
        }

        dst = ColorRAM[data + (id * 16) + 8];

        for (i = 0; i < 128; i++) {
            dst[i] = palConvSrcToRam(src[i]);
        }

        Push_ramcnt_key(key);
        palUpdateGhostCP3(data + (id * 16), 2);
        palUpdateGhostCP3(data + (id * 16) + 8, 2);
        break;
    }

    case 7: {
        COL_x2800 *adrs = (COL_x2800 *)Get_ramcnt_address(key);

        ldadrs = ColorRAM[40];
        tradrs = ColorRAM[41];

        for (i = 0; i < 16; i++) {
            ldadrs[i] = palConvSrcToRam(adrs->col[My_char[0]][Player_Color[0]][i]);
            tradrs[i] = palConvSrcToRam(adrs->col[My_char[1]][Player_Color[1]][i]);
        }

        Push_ramcnt_key(key);
        palUpdateGhostCP3(40, 2);
        break;
    }

    case 8:
        xb_SetColorRamEntry(Get_ramcnt_address(key), Get_size_data_ramcnt_key(key), 0, 0);

        while (sub_0009B78F(1) == 0) {
            waitVsyncDummy();
        }

        Push_ramcnt_key(key);
        break;

    case 10:
        xb_PurgeListEntry((u8)id + 1);
        loaded = Get_ramcnt_address(key);
        nbytes = Get_size_data_ramcnt_key(key);
        image = D_009CA4C0 + (s32)id * 0x8E590;

        if ((s32)nbytes > 0) {
            for (n = 0; n < (s32)nbytes; n++) {
                image[n] = loaded[n];
            }
        }

        cseTsbSetBankAddr((u32)(id + 1), cseTSBDataTable[data + 1]);
        xb_SetColorRamEntry(image, nbytes, id + 1, data + 1);
        Push_ramcnt_key(key);
        break;

    case 0xB:
    case 0xC:
        break;

    case 0x50:
    case 0x51:
    case 0x52:
        loaded = Get_ramcnt_address(key);
        nbytes = Get_size_data_ramcnt_key(key);

        if (type == 0x50) {
            image = D_00B84200;
        } else if (type == 0x51) {
            image = D_007C5CE0;
        } else {
            image = D_00881400;
        }

        if ((s32)nbytes > 0) {
            for (n = 0; n < (s32)nbytes; n++) {
                image[n] = loaded[n];
            }
        }

        Push_ramcnt_key(key);
        break;

    case 0x61:
        image = xb_GetExtraLoadBuffer();
        loaded = Get_ramcnt_address(key);
        nbytes = Get_size_data_ramcnt_key(key);

        if ((s32)nbytes > 0) {
            for (n = 0; n < (s32)nbytes; n++) {
                image[n] = loaded[n];
            }
        }

        Push_ramcnt_key(key);
        break;
    }
}

void init_color_trans_req(void) {
    s16 i;

    for (i = 0; i < 32; i++) {
        col3rd_w.req[i][0] = col3rd_w.req[i][1] = 0;
    }

    col3rd_w.reqNum = 0;
}

void push_color_trans_req(s16 from_col, s16 to_col) {
    palCopyGhostDC(to_col << 6, 64, ColorRAM[from_col]);
    palUpdateGhostDC();
}

void palCopyGhostDC(s32 ofs, s32 cnt, void *data) {
    s32 i;
    u16 *srcAdrs = data;
    u16 *dstAdrs = &colPalBuffDC[ofs];

    for (i = 0; i < cnt; i++) {
        *dstAdrs++ = *srcAdrs++;
    }

    col3rd_w.upBits = col3rd_w.upBits | (1 << (ofs / 64));
}

u16 palConvSrcToRam(u16 col) {
    u8 cA;
    u8 cR;
    u8 cG;
    u8 cB;

    if (palFormConv == 0) {
        return col;
    }

    cA = palFormSrc.am & (col >> palFormSrc.as);
    cR = palFormSrc.rm & (col >> palFormSrc.rs);
    cG = palFormSrc.gm & (col >> palFormSrc.gs);
    cB = palFormSrc.bm & (col >> palFormSrc.bs);
    return (cA << palFormRam.as) | (cR << palFormRam.rs) | (cG << palFormRam.gs) | (cB << palFormRam.bs);
}

void palCreateGhost(void) {
    PPLFileHeader ppl;
    s32 key;
    s32 size;
    s32 i;
    u8 *adrs;

    palFormConv = 0;
    palFormSrc.rl = 5;
    palFormSrc.rs = 10;
    palFormSrc.rm = 31;
    palFormSrc.gl = 5;
    palFormSrc.gs = 5;
    palFormSrc.gm = 31;
    palFormSrc.bl = 5;
    palFormSrc.bs = 0;
    palFormSrc.bm = 31;
    palFormSrc.al = 1;
    palFormSrc.as = 15;
    palFormSrc.am = 1;
    palFormRam.rl = 5;
    palFormRam.rs = 10;
    palFormRam.rm = 31;
    palFormRam.gl = 5;
    palFormRam.gs = 5;
    palFormRam.gm = 31;
    palFormRam.bl = 5;
    palFormRam.bs = 0;
    palFormRam.bm = 31;
    palFormRam.al = 1;
    palFormRam.as = 15;
    palFormRam.am = 1;
    col3rd_w.upBits = 0;
    ppl.magic = 0;
    ppl.fileSize = 0;
    ppl.free = 0;
    ppl.compress = 0;
    ppl.c_mode = 2;
    ppl.formARGB = 0x5515;

    ppl.palettes = 0x1000;
    size = 0x2000;
    key = Pull_ramcnt_key(size, 2, 0, 1);
    adrs = (u8 *)Get_ramcnt_address((s16)key);

    for (i = 0; i < size; i++) {
        adrs[i] = 0;
    }

    ppgSetupPalChunkDir(&col3rd_w.palDC, &ppl, adrs, 0, 1);
    Push_ramcnt_key(key);

    ppl.palettes = 2;
    size = 0x2000;
    key = Pull_ramcnt_key(size, 2, 0, 1);
    adrs = (u8 *)Get_ramcnt_address((s16)key);

    for (i = 0; i < size; i++) {
        adrs[i] = 0;
    }

    ppgSetupPalChunkDir(&col3rd_w.palCP3, &ppl, adrs, 0, 1);
    Push_ramcnt_key(key);
}

Palette *palGetChunkGhostDC(void) {
    return &col3rd_w.palDC;
}

Palette *palGetChunkGhostCP3(void) {
    return &col3rd_w.palCP3;
}

void palUpdateGhostDC(void) {
    plContext bits;
    s32 i;
    u16 *srcAdrs;
    void *dstAdrs;

    for (i = 0; i < col3rd_w.palDC.total; i++) {
        if (col3rd_w.upBits & (1 << i)) {
            flLockPalette(0, col3rd_w.palDC.handle[i], &bits, 2);
            dstAdrs = bits.ptr;
            srcAdrs = &colPalBuffDC[(i << 6)];
            palConvRowTim2CI8Clut(srcAdrs, dstAdrs, 0x40);
            sub_0009B78F(col3rd_w.palDC.handle[i]);
        }
    }

    col3rd_w.upBits = 0;
}

void palUpdateGhostCP3(s32 pal, s32 nums) {
    plContext bits;
    s32 i;
    u16 *srcAdrs;
    void *dstAdrs;

    for (i = pal; i < (pal + nums); i++) {
        flLockPalette(0, col3rd_w.palCP3.handle[i], &bits, 2);
        dstAdrs = bits.ptr;
        srcAdrs = ColorRAM[i];
        palConvRowTim2CI8Clut(srcAdrs, dstAdrs, 0x40);
        sub_0009B78F(col3rd_w.palCP3.handle[i]);
    }
}

/* The Xbox converts each 16-bit TIM2 colour into a 32-bit ARGB entry (alpha 0xFF when bit 15 is set) in row order; it has no PS2 CLUT swizzle. */
void palConvRowTim2CI8Clut(u16* src, u32* dst, s32 size) {
    s32 i;
    u32 col;

    for (i = 0; i < size; i++) {
        col = *src++;
        *dst++ = ((((((col & 0x7C00) << 3) | (col & 0x3E0)) << 3) | (col & 0x1F)) << 3) | ((col & 0x8000) ? 0xFF000000 : 0);
    }
}

#if 0
/* PS2 C for functions not located in sf33rd.xbe yet. */

s32 cseTsbSetBankAddr(u32 bank, SoundEvent* addr) {
    return mlTsbSetBankAddr(bank, addr);
}

s32 cseMemMapSetPhdAddr(u32 bank, void* addr) {
    return mlMemMapSetPhdAddr(bank, addr);
}
#endif
