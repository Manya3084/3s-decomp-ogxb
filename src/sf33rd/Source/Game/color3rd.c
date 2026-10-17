/* cseTsbSetBankAddr, retail sf33rd.xbe 0xF4532 size 0x5.
 * It is interior. The body is a tail jump to mlTsbSetBankAddr.
 * 0xF4510, 0xF451D, and 0xF452A stay unnamed.
 *
 * set_hitmark_color is 0xB59E1 size 0x99 and is interior.
 * hitmark_color is 0x283458 and matches the 256 PlayStation 2 bytes.
 * ColorRAM is 0x7AAD60. The mode call stays sub_0004384A.
 * The data calls stay sub_000309CF. That body passes its three
 * arguments to palCopyGhostDC and tails into palUpdateGhostDC.
 * The PlayStation 2 source calls njSetPaletteData(64, 64, ColorRAM[15])
 * and njSetPaletteData(576, 64, ColorRAM[31]).
 *
 * init_color_trans_req is 0xB564D size 0x1F and is interior.
 * col3rd_w.req starts at 0x7AAC88. reqNum is 0x7AAD08.
 * palCopyGhostDC is 0xB566C size 0x3D and is interior.
 * colPalBuffDC is 0x796080. upBits is 0x7AAD0C.
 * palConvSrcToRam is 0xB56A9 size 0x9C and is interior.
 * palFormConv is 0x7BAD60. palFormSrc is 0x7AAD20. palFormRam is 0x7BAD80.
 * The masks run in B, G, R, A order. The OR is the PlayStation 2 word.
 *
 * palCreateGhost is 0xB5745 size 0x15C and is a scanned start.
 * It stores palFormConv as 0. palFormRam.rs stays 10 and palFormRam.bs
 * stays 0. The PlayStation 2 source sets palFormConv to 1, palFormRam.rs
 * to 0, palFormRam.bs to 10, palFormRam.gl to 5, and palFormRam.gm to 31.
 * Each buffer is 0x2000 bytes and is cleared as 0x800 dwords.
 * The key push stays sub_00097103.
 *
 * palGetChunkGhostDC is 0xB58A1 size 0x6 and is interior.
 * palGetChunkGhostCP3 is 0xB58A7 size 0x6 and is interior.
 * palDC is 0x7AAC60. palCP3 is 0x7AAC74.
 *
 * palUpdateGhostDC is 0xB5903 size 0x78 and is a scanned start.
 * palUpdateGhostCP3 is 0xB597B size 0x66 and is a scanned start.
 * Both lock through sub_00016F71(0, handle, &bits, 2). The row expand
 * is sub_000B58AD. The PlayStation 2 source calls palConvRowTim2CI8Clut.
 * The unlock is sub_0009B78F, which returns 1.
 * 0xB58AD, 0x16F71, 0x9B78F, 0x4384A, 0x309CF, and 0x97103 stay unnamed.
 *
 * init_trans_color_ram is 0xB5A7A size 0x726 and is a scanned start.
 * The jump table is 0xB6178 and is inside the size. plcol is 0x7AAD50.
 * hi_meta is 0x7A9EA0. My_char is 0x7A8114. Player_Color is 0x7A8906.
 * Case 3 calls sub_000D01D3. Case 8 calls sub_000F44CA and waits on
 * sub_0009B78F with sub_00059B72. Case 10 calls sub_000F50C9(id + 1),
 * copies the loaded bytes to 0x9CA4C0 + id * 0x8E590, and passes
 * cseTSBDataTable[data] to cseTsbSetBankAddr. cseTSBDataTable is 0x32FD2C.
 * It holds 20 pointers and a trailing zero. The PlayStation 2 source
 * indexes cseTSBDataTable[data + 1], maps a phd bank, stores sdbd, and
 * waits. Cases 0x50, 0x51, and 0x52 copy the loaded bytes to 0xB84200,
 * 0x7C5CE0, and 0x881400. Case 0x61 copies them to the pointer from
 * sub_00017792. That helper reads the dword at 0x795C14 and returns the
 * dword at +0xC. The PlayStation 2 case 0x61 is empty.
 * 0xD01D3, 0xF44CA, 0xF50C9, 0x59B72, and 0x17792 stay unnamed.
 * 0xB61A0 stays unnamed.
 *
 * q_ldreq_color_data is 0xB61C6 size 0x1B9 and is interior.
 * load_any_color is 0xB637F size 0x40 and is interior.
 * color_file is 0x283558. data and free match in all 161 rows.
 * 110 rows differ only in apfn, by -4. 23 differ only in apfn, by 5.
 * 2 differ only in apfn, by 2. 18 rows match. Eight rows also change
 * type. Index 109 changes type 8 to 0x50. Indices 110 and 111 change
 * type 9 to 0x51 and 0x52. Index 151 changes type 9 to 0x61. Index 152
 * changes type 0x62 to 9. Indices 158, 159, and 160 change type 0x63
 * to 9. Case 0 decrements retry before the 0xFFFF test, and that
 * success still tests retry. When retry reaches 0 the body stores 1
 * at DskDrvErrBe and 1 at 0xC7F4FA, then tails into sub_00059948.
 * Type 10 in case 0 calls sub_0009B78F(0) and sub_000F44F2(id + 1).
 * A match with data + 1 takes the success store. Case 4 always calls
 * init_trans_color_ram. It does not set rno to 5. There is no case 5,
 * no cseSendBd2SpuWithId, and no cseMemMapSetPhdAddr.
 * fsCheckFileReaded stays sub_00059B44. fsClose stays sub_00059AAA.
 * fsCheckCommandExecuting stays sub_00059B09. fsOpen stays
 * sub_00059A4D. fsGetFileSize stays sub_00059ABE. fsCalSectorSize
 * stays sub_00059AD7. fsRequestFileRead stays sub_00059B2A.
 * load_it_use_any_key stays sub_0005A055. The key push stays
 * sub_00097103. sub_00059948, sub_0009B78F, and sub_000F44F2 stay
 * unnamed. 0xB63BF stays unnamed.
 */

#include "types.h"

#include <stddef.h>

typedef struct {
    s8 be;
    u8 c_mode;
    u16 total;
    u16 *handle;
    s32 ixNum1st;
    u8 *srcAdrs;
    u32 srcSize;
} Palette;

typedef struct {
    Palette palDC;
    Palette palCP3;
    s16 req[32][2];
    s16 reqNum;
    u32 upBits;
} Col3rd_W;

typedef struct {
    s32 rl;
    s32 rs;
    s32 rm;
    s32 gl;
    s32 gs;
    s32 gm;
    s32 bl;
    s32 bs;
    s32 bm;
    s32 al;
    s32 as;
    s32 am;
} PixelFormat;

typedef struct {
    u32 desc;
    s32 width;
    s32 height;
    s32 pitch;
    void *ptr;
} plContext;

typedef struct {
    u32 magic;
    u32 fileSize;
    u16 free;
    u8 compress;
    u8 c_mode;
    u16 formARGB;
    u16 palettes;
} PPLFileHeader;

typedef struct {
    u16 col[2][28][64];
} COL;

typedef struct {
    u16 col[2][16][64];
} COL_x1000;

typedef struct {
    u16 col[64];
} COL_x80;

typedef struct {
    u16 col[3][64];
} COL_x180;

typedef struct {
    u16 col[2][64];
} COL_x100;

typedef struct {
    u16 col[20][16][16];
} COL_x2800;

typedef struct {
    u16 data;
    u16 type;
    u16 apfn;
    u16 free;
} col_file_data;

typedef struct {
    u8 be;
    u8 type;
    s16 id;
    u8 rno;
    u8 retry;
    u8 ix;
    u8 frre;
    s16 key;
    u8 kokey;
    u8 group;
    u8 *result;
    s32 size;
    s32 sect;
    u16 fnum;
    u8 free[2];
    void *lds;
    u32 info_number;
    u32 info_size;
} REQ;

#if defined(__i386__)
_Static_assert(sizeof(Palette) == 0x14, "Palette");
_Static_assert(offsetof(Palette, total) == 2, "total");
_Static_assert(offsetof(Palette, handle) == 4, "handle");
_Static_assert(offsetof(Col3rd_W, palCP3) == 0x14, "palCP3");
_Static_assert(offsetof(Col3rd_W, req) == 0x28, "req");
_Static_assert(offsetof(Col3rd_W, reqNum) == 0xA8, "reqNum");
_Static_assert(offsetof(Col3rd_W, upBits) == 0xAC, "upBits");
_Static_assert(sizeof(PixelFormat) == 0x30, "PixelFormat");
_Static_assert(offsetof(PixelFormat, bs) == 0x1C, "bs");
_Static_assert(offsetof(PixelFormat, as) == 0x28, "as");
_Static_assert(sizeof(PPLFileHeader) == 0x10, "PPL");
_Static_assert(offsetof(PPLFileHeader, c_mode) == 0xB, "c_mode");
_Static_assert(offsetof(PPLFileHeader, formARGB) == 0xC, "form");
_Static_assert(offsetof(PPLFileHeader, palettes) == 0xE, "palettes");
_Static_assert(offsetof(plContext, ptr) == 0x10, "ptr");
_Static_assert(sizeof(COL) == 0x1C00, "COL");
_Static_assert(sizeof(COL_x1000) == 0x1000, "COL_x1000");
_Static_assert(sizeof(COL_x80) == 0x80, "COL_x80");
_Static_assert(sizeof(COL_x180) == 0x180, "COL_x180");
_Static_assert(sizeof(COL_x100) == 0x100, "COL_x100");
_Static_assert(sizeof(COL_x2800) == 0x2800, "COL_x2800");
_Static_assert(sizeof(col_file_data) == 8, "col_file_data");
_Static_assert(offsetof(col_file_data, type) == 2, "type");
_Static_assert(offsetof(col_file_data, apfn) == 4, "apfn");
_Static_assert(sizeof(REQ) == 0x28, "REQ");
_Static_assert(offsetof(REQ, rno) == 4, "rno");
_Static_assert(offsetof(REQ, retry) == 5, "retry");
_Static_assert(offsetof(REQ, ix) == 6, "ix");
_Static_assert(offsetof(REQ, frre) == 7, "frre");
_Static_assert(offsetof(REQ, key) == 8, "key");
_Static_assert(offsetof(REQ, kokey) == 0xA, "kokey");
_Static_assert(offsetof(REQ, group) == 0xB, "group");
_Static_assert(offsetof(REQ, result) == 0xC, "result");
_Static_assert(offsetof(REQ, size) == 0x10, "size");
_Static_assert(offsetof(REQ, sect) == 0x14, "sect");
_Static_assert(offsetof(REQ, fnum) == 0x18, "fnum");
#endif

typedef struct SoundEvent SoundEvent;

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
extern void sub_00097103(s32 key);
extern void sub_0004384A(s32 mode);
extern void sub_000309CF(s32 ofs, s32 cnt, void *data);
extern void sub_00016F71(void *rect, u32 handle, plContext *bits, s32 flag);
extern void sub_000B58AD(u16 *src, void *dst, s32 count);
extern s32 sub_0009B78F(u32 handle);
extern u32 Get_size_data_ramcnt_key(s16 key);
extern u8 My_char[2];
extern s8 Player_Color[2];
extern COL *plcol[2];
extern u16 hi_meta[2][2][64];
extern SoundEvent *cseTSBDataTable[];
extern void sub_000D01D3(s32 wkid);
extern void sub_000F44CA(void *addr, u32 size, s32 id, s32 index);
extern void sub_000F50C9(s32 bank);
extern void sub_00059B72(void);
extern u8 *sub_00017792(void);
extern const col_file_data color_file[161];
extern const u8 lpr_wrdata[3];
extern u16 DskDrvErrBe;
extern u16 word_C7F4FA;
extern s32 sub_00059B09(void);
extern s32 sub_00059A4D(REQ *curr);
extern void sub_00059AAA(REQ *curr);
extern u32 sub_00059ABE(u16 fnum);
extern u32 sub_00059AD7(u32 size);
extern s32 sub_00059B2A(REQ *curr, u32 sect, void *adrs);
extern s32 sub_00059B44(REQ *curr);
extern s16 sub_0005A055(u16 fnum, u8 kokey, u8 group);
extern void sub_00059948(void);
extern s32 sub_000F44F2(s32 id);
extern void Set_size_data_ramcnt_key(s16 key, u32 size);

void init_trans_color_ram(s16 id, s16 key, u8 type, u16 data);

void q_ldreq_color_data(REQ *curr) {
    col_file_data *cfn;
    s32 err;

    cfn = (col_file_data *)&color_file[curr->ix];

    switch (curr->rno) {
    case 0:
        if (sub_00059B09() != 0) {
            break;
        }

        if (cfn->type == 10) {
            if (sub_0009B78F(0) == 0) {
                break;
            }

            if (sub_000F44F2(curr->id + 1) == cfn->data + 1) {
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
            word_C7F4FA = 1;
            sub_00059948();
            return;
        }

        /* fallthrough */

    case 1:
        err = sub_00059A4D(curr);

        if (err == 0) {
            curr->rno = 0;
            break;
        }

        curr->rno = 2;
        /* fallthrough */

    case 2:
        curr->size = (s32)sub_00059ABE(curr->fnum);
        curr->sect = (s32)sub_00059AD7((u32)curr->size);
        curr->key = Pull_ramcnt_key((u32)curr->sect << 11, curr->kokey, curr->group, curr->frre);
        Set_size_data_ramcnt_key(curr->key, (u32)curr->size);
        curr->rno = 3;
        /* fallthrough */

    case 3:
        err = sub_00059B2A(curr, (u32)curr->sect, Get_ramcnt_address(curr->key));

        if (err == 0) {
            sub_00097103(curr->key);
            sub_00059AAA(curr);
            curr->rno = 0;
        } else {
            curr->rno = 4;
            curr->be = 1;
        }

        break;

    case 4:
        switch (sub_00059B44(curr)) {
        case 1:
            init_trans_color_ram(curr->id, curr->key, cfn->type, cfn->data);
            sub_00059AAA(curr);
            *curr->result |= lpr_wrdata[curr->id];
            curr->be = 0;
            break;

        case 0:
            break;

        default:
            sub_00097103(curr->key);
            sub_00059AAA(curr);
            curr->be = 2;
            curr->rno = 0;
            break;
        }

        break;
    }
}

s32 cseTsbSetBankAddr(u32 bank, SoundEvent *addr) {
    return mlTsbSetBankAddr(bank, addr);
}

u16 palConvSrcToRam(u16 col);
void palUpdateGhostCP3(s32 pal, s32 nums);

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

void load_any_color(u16 ix, u8 kokey) {
    col_file_data *cfn;
    s16 key;

    cfn = (col_file_data *)&color_file[ix];
    key = sub_0005A055(cfn->apfn, kokey, 0);

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
    sub_000309CF(64, 64, ColorRAM[15]);
    sub_000309CF(576, 64, ColorRAM[31]);
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

        sub_00097103(key);
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

        sub_00097103(key);

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

            sub_000D01D3(0);
            sub_000D01D3(1);
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

            sub_000D01D3(id);
        }

        sub_00097103(key);
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

        sub_00097103(key);
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

        sub_00097103(key);
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

        sub_00097103(key);
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

        sub_00097103(key);
        palUpdateGhostCP3(40, 2);
        break;
    }

    case 8:
        sub_000F44CA(Get_ramcnt_address(key), Get_size_data_ramcnt_key(key), 0, 0);

        while (sub_0009B78F(1) == 0) {
            sub_00059B72();
        }

        sub_00097103(key);
        break;

    case 10:
        sub_000F50C9((u8)id + 1);
        loaded = Get_ramcnt_address(key);
        nbytes = Get_size_data_ramcnt_key(key);
        image = (u8 *)0x9CA4C0 + (s32)id * 0x8E590;

        if ((s32)nbytes > 0) {
            for (n = 0; n < (s32)nbytes; n++) {
                image[n] = loaded[n];
            }
        }

        cseTsbSetBankAddr((u32)(id + 1), cseTSBDataTable[data]);
        sub_000F44CA(image, nbytes, id + 1, data + 1);
        sub_00097103(key);
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
            image = (u8 *)0xB84200;
        } else if (type == 0x51) {
            image = (u8 *)0x7C5CE0;
        } else {
            image = (u8 *)0x881400;
        }

        if ((s32)nbytes > 0) {
            for (n = 0; n < (s32)nbytes; n++) {
                image[n] = loaded[n];
            }
        }

        sub_00097103(key);
        break;

    case 0x61:
        image = sub_00017792();
        loaded = Get_ramcnt_address(key);
        nbytes = Get_size_data_ramcnt_key(key);

        if ((s32)nbytes > 0) {
            for (n = 0; n < (s32)nbytes; n++) {
                image[n] = loaded[n];
            }
        }

        sub_00097103(key);
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
    sub_00097103(key);

    ppl.palettes = 2;
    size = 0x2000;
    key = Pull_ramcnt_key(size, 2, 0, 1);
    adrs = (u8 *)Get_ramcnt_address((s16)key);

    for (i = 0; i < size; i++) {
        adrs[i] = 0;
    }

    ppgSetupPalChunkDir(&col3rd_w.palCP3, &ppl, adrs, 0, 1);
    sub_00097103(key);
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
            sub_00016F71(0, col3rd_w.palDC.handle[i], &bits, 2);
            dstAdrs = bits.ptr;
            srcAdrs = &colPalBuffDC[(i << 6)];
            sub_000B58AD(srcAdrs, dstAdrs, 0x40);
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
        sub_00016F71(0, col3rd_w.palCP3.handle[i], &bits, 2);
        dstAdrs = bits.ptr;
        srcAdrs = ColorRAM[i];
        sub_000B58AD(srcAdrs, dstAdrs, 0x40);
        sub_0009B78F(col3rd_w.palCP3.handle[i]);
    }
}
