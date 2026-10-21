/* Texture groups, retail sf33rd.xbe.
 * q_ldreq_texture_group is 0xEFC53 size 0x2FE. Init_texgrplds_work is
 * 0xEFF51 size 0x27. reservMemKeySelObj is 0xEFF78 size 0x3B.
 * checkSelObjFileLoaded is 0xEFFB3 size 0x7A. purge_texture_group is
 * 0xF002D size 0x28. purge_player_texture is 0xF0055 size 0x7C.
 * load_any_texture_grpnum is 0xF00D1 size 0x5D.
 * purge_texture_group_of_this is 0xF012E size 0x14.
 * load_any_texture_patnum is 0xF0142 size 0x1B.
 * texgrplds is 0x7A8A60, stride 0xC. texgrpdat is 0x2B0C68, stride 0x14.
 * num_of_1st, conv, ix1st, use, to_tex, and to_chd match the PlayStation 2
 * rows. 85 apfn fields differ by -4 or by 5. obj_group_table is 0x276380
 * and matches the 37664 PlayStation 2 bytes. lpr_wrdata is 0x25C718 and
 * matches. lpt_seldat is 0x25C720 and matches. plid_data is 0x261928 and
 * matches the 20 bytes. plt_req is 0xC7F500. char_init_data is 0xCBA020,
 * stride 0x64. parabora_own_table is 0xCB9FC0.
 * omSelObjNowOnMemoryType is 0x3330A4. mpp_w.language is 0x7AA5F1.
 * DskDrvErrBe is 0xC7F4FE. rckey_work is 0xC7CA60.
 * Case 0 decrements retry. When retry reaches 0 the body stores 1 at
 * DskDrvErrBe and 1 at 0xC7F4FA, then tails into xb_ShowDiskReadError. The
 * partition opener stores 0x2D0 at 0xC7F4FA. That word is not
 * DskDrvErrRetry. The PlayStation 2 case 0 does not decrement retry.
 * When a group is already loaded, the type 3 and type 4 updates still
 * run, and the body always takes the success exit. It does not log a
 * duplicate transfer and it does not hang. The character block relocates
 * 25 offsets in place and copies them into char_init_data. Q copies
 * patch word 3 onto word 37. Akuma merges the next selector entry.
 * reservMemKeySelObj hangs when the key is negative.
 * fsCheckFileReaded is 0x59B44. fsClose is 0x59AAA.
 * fsOpen is 0x59A4D and fsCheckCommandExecuting is 0x59B09.
 * fsGetFileSize is 0x59ABE. fsCalSectorSize is 0x59AD7.
 * fsRequestFileRead is 0x59B2A. load_it_use_this_key stays
 * load_it_use_this_key. load_it_use_any_key is 0x5A055. The key push
 * stays Push_ramcnt_key. xb_ShowDiskReadError stays unnamed. 0xF015D is
 * jijii_nebukuro.
 * All nine are interior.
 */

#include "types.h"
#include "structs.h"

typedef struct {
    s8 ok;
    s8 type;
    s16 key;
    u8 *texture_table;
    u8 *trans_table;
} TexGrpLd;


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
    TexGrpLd *lds;
    u32 info_number;
    u32 info_size;
} TexGrpReq;


typedef struct {
    s16 x;
    s16 y;
    u16 attr;
    u16 code;
} TexGroup_UNK_0;



#if defined(__i386__)
_Static_assert(sizeof(TexGrpLd) == 0xC, "TexGrpLd");
_Static_assert(__builtin_offsetof(TexGrpLd, key) == 2, "key");
_Static_assert(__builtin_offsetof(TexGrpLd, texture_table) == 4, "texture_table");
_Static_assert(__builtin_offsetof(TexGrpLd, trans_table) == 8, "trans_table");
_Static_assert(sizeof(TexGrpReq) == 0x28, "TexGrpReq");
_Static_assert(__builtin_offsetof(TexGrpReq, retry) == 5, "retry");
_Static_assert(__builtin_offsetof(TexGrpReq, ix) == 6, "ix");
_Static_assert(__builtin_offsetof(TexGrpReq, key) == 8, "req key");
_Static_assert(__builtin_offsetof(TexGrpReq, kokey) == 0xA, "kokey");
_Static_assert(__builtin_offsetof(TexGrpReq, group) == 0xB, "group");
_Static_assert(__builtin_offsetof(TexGrpReq, result) == 0xC, "result");
_Static_assert(__builtin_offsetof(TexGrpReq, size) == 0x10, "size");
_Static_assert(__builtin_offsetof(TexGrpReq, sect) == 0x14, "sect");
_Static_assert(__builtin_offsetof(TexGrpReq, fnum) == 0x18, "fnum");
_Static_assert(__builtin_offsetof(TexGrpReq, lds) == 0x1C, "lds");
_Static_assert(sizeof(TexGroup_UNK_0) == 8, "TexGroup_UNK_0");
#endif

extern TexGrpLd texgrplds[100];
/* The Xbox rows, read from the XBE: the AFS file numbers (apfn) are the
   Xbox ones. */
const TexGroupData texgrpdat[100] = {
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 0, 1456, 0, 1, 3040072, 210820, 2945368 },
    { 1568, 1461, 0, 1, 2552860, 116432, 2420192 },
    { 2592, 1464, 0, 1, 1630652, 72828, 1543992 },
    { 3552, 1468, 0, 1, 2231332, 114816, 2075148 },
    { 4992, 1472, 0, 1, 2093456, 110728, 1973588 },
    { 6144, 1475, 0, 1, 2987268, 116636, 2870824 },
    { 7392, 1479, 0, 1, 3342276, 158400, 3225900 },
    { 8384, 1483, 0, 1, 2700876, 151744, 2480392 },
    { 10208, 1488, 0, 1, 1849896, 142292, 1707212 },
    { 11776, 1491, 0, 1, 2241340, 137680, 2119316 },
    { 13280, 1495, 0, 1, 2337716, 116892, 2190948 },
    { 14656, 1498, 0, 1, 1649368, 71900, 1556728 },
    { 15712, 1502, 0, 1, 1715944, 80596, 1618808 },
    { 16800, 1506, 0, 1, 2286852, 135428, 2186344 },
    { 18272, 1510, 0, 1, 2649420, 116116, 2547656 },
    { 19456, 1514, 0, 1, 2672552, 144584, 2541372 },
    { 21120, 1518, 0, 1, 2770372, 177724, 2635716 },
    { 23008, 1521, 0, 1, 3792908, 222124, 3666100 },
    { 24704, 1524, 0, 1, 2345792, 131348, 2208892 },
    { 25856, 1527, 0, 1, 1830216, 125420, 1724240 },
    { 27040, 1448, 0, 0, 1483, 436, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 27104, 1450, 0, 0, 1128236, 134308, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 29152, 1451, 0, 0, 176650, 14180, 0 },
    { 29344, 1452, 0, 0, 595797, 92368, 0 },
    { 30640, 1457, 0, 2, 88153, 5788, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 30896, 1453, 0, 0, 35820, 3448, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 31152, 1442, 0, 0, 2148437, 120700, 0 },
    { 32432, 1440, 0, 0, 36241, 2580, 0 },
    { 36896, 1458, 0, 2, 147800, 4212, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 32560, 1454, 0, 0, 170685, 25088, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 34352, 1397, 0, 0, 47835, 1704, 0 },
    { 34384, 1406, 0, 0, 57961, 2180, 0 },
    { 34448, 1385, 0, 0, 81332, 19772, 0 },
    { 34576, 1391, 0, 0, 47809, 3256, 0 },
    { 34672, 1424, 0, 0, 15596, 1672, 0 },
    { 34704, 1401, 0, 0, 41072, 1832, 0 },
    { 34736, 1409, 0, 0, 16744, 2220, 0 },
    { 34832, 1421, 0, 0, 5845, 296, 0 },
    { 34864, 1394, 0, 0, 157729, 12208, 0 },
    { 34960, 1430, 0, 0, 96435, 4016, 0 },
    { 35024, 1382, 0, 0, 62413, 4568, 0 },
    { 35120, 1403, 0, 0, 32337, 1100, 0 },
    { 35152, 1439, 0, 0, 2302, 64, 0 },
    { 35184, 1436, 0, 0, 111032, 7372, 0 },
    { 35328, 1427, 0, 0, 214221, 17548, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 35648, 1388, 0, 0, 40123, 2100, 0 },
    { 35744, 1444, 0, 0, 102144, 8496, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
    { 35904, 79, 0, 0, 1024977, 54492, 0 },
    { 36096, 39, 0, 0, 335656, 6552, 0 },
    { 36160, 40, 0, 0, 67041, 1540, 0 },
    { 36192, 41, 0, 0, 171245, 11480, 0 },
    { 36288, 42, 0, 0, 84254, 2300, 0 },
    { 36320, 43, 0, 0, 57154, 1712, 0 },
    { 36352, 44, 0, 0, 120474, 6460, 0 },
    { 36384, 45, 0, 0, 62031, 2332, 0 },
    { 36416, 46, 0, 0, 20849, 3412, 0 },
    { 36448, 47, 0, 0, 10724, 444, 0 },
    { 36480, 48, 0, 0, 32145, 1072, 0 },
    { 36512, 49, 0, 0, 83717, 2832, 0 },
    { 36544, 50, 0, 0, 152553, 4676, 0 },
    { 36576, 51, 0, 0, 69000, 5992, 0 },
    { 36608, 52, 0, 0, 233695, 8904, 0 },
    { 36640, 53, 0, 0, 320671, 14508, 0 },
    { 36704, 54, 0, 0, 65229, 1536, 0 },
    { 36736, 55, 0, 0, 122647, 2968, 0 },
    { 36768, 56, 0, 0, 166764, 6628, 0 },
    { 36800, 57, 0, 0, 61918, 2868, 0 },
    { 36864, 58, 0, 0, 182919, 4776, 0 },
    { 37024, 1455, 0, 0, 621536, 42292, 0 },
    { 37408, 1380, 0, 0, 35825, 2488, 0 },
    { 37536, 1381, 0, 0, 135261, 12984, 0 },
    { 34576, 1412, 0, 0, 47809, 3256, 0 },
    { 34448, 1415, 0, 0, 81332, 19772, 0 },
    { 34736, 1418, 0, 0, 16744, 2220, 0 },
    { 34352, 1433, 0, 0, 47835, 1704, 0 },
    { 30640, 1465, 0, 2, 88153, 5788, 0 },
    { 30640, 1484, 0, 2, 88153, 5788, 0 },
    { 30640, 1492, 0, 2, 88153, 5788, 0 },
    { 30640, 1499, 0, 2, 88153, 5788, 0 },
    { 30640, 1503, 0, 2, 88153, 5788, 0 },
    { 30640, 1507, 0, 2, 88153, 5788, 0 },
    { 30640, 1511, 0, 2, 88153, 5788, 0 },
    { 30640, 1515, 0, 2, 88153, 5788, 0 },
    { 30640, 1528, 0, 2, 88153, 5788, 0 },
    { 27104, 1449, 0, 0, 1126129, 134044, 0 },
    { 0, 65535, 0, 0, 0, 0, 0 },
};
extern const u8 obj_group_table[37664];
extern const u8 lpr_wrdata[3];
extern const u8 lpt_seldat[4];
extern const s8 plid_data[20];
extern s16 plt_req[2];
extern CharInitData char_init_data[23];
extern u32 *parabora_own_table[20];
/* Pasted from the PS2 file. */
u8 omSelObjNowOnMemoryType = 0xFF;
extern MPP mpp_w;
extern u16 DskDrvErrBe;
extern u16 D_00C7F4FA;
extern RCKeyWork rckey_work[64];

extern s32 fsCheckCommandExecuting(void);
extern s32 fsOpen(TexGrpReq *curr);
extern void fsClose(TexGrpReq *curr);
extern u32 fsGetFileSize(u16 fnum);
extern u32 fsCalSectorSize(u32 size);
extern s32 fsRequestFileRead(TexGrpReq *curr, u32 sect, void *adrs);
extern s32 fsCheckFileReaded(TexGrpReq *curr);
extern s32 load_it_use_this_key(u16 fnum, s16 key);
extern s16 load_it_use_any_key(u16 fnum, u8 kokey, u8 group);
extern void xb_ShowDiskReadError(void);
extern s16 Pull_ramcnt_key(u32 memreq, u8 kokey, u8 group, u8 frre);
extern void *Get_ramcnt_address(s16 key);
extern void Set_size_data_ramcnt_key(s16 key, u32 size);
extern void Push_ramcnt_key(s16 key);
extern s16 Search_ramcnt_type(u8 kokey);
extern void Clear_texcash_work(void);

s32 load_any_texture_grpnum(u8 grp, u8 kokey);
void purge_texture_group(u8 grp);

void q_ldreq_texture_group(TexGrpReq *curr) {
    const TexGroupData *bsd;
    CharInitData *cit;
    CharInitData *cit2;
    u8 *ldadr;
    u8 *ldchd;
    s32 err;
    s16 i;
    u32 *patchAdrs;
    u16 *trsbas;
    TexGroup_UNK_0 *trsptr;
    s16 count;
    s16 loop;

    bsd = &texgrpdat[curr->ix];

    switch (curr->rno) {
    case 0:
        if (fsCheckCommandExecuting() != 0) {
            break;
        }

        curr->rno = 1;
        curr->fnum = bsd->apfn;

        if (bsd->apfn == 0xFFFF) {
            *curr->result |= lpr_wrdata[curr->id];
            curr->be = 0;
        }

        curr->retry -= 1;

        if (curr->retry == 0) {
            DskDrvErrBe = 1;
            D_00C7F4FA = 1;
            xb_ShowDiskReadError();
            return;
        }

        if (bsd->num_of_1st == 0) {
            curr->group = obj_group_table[bsd->num_of_1st + 1];
        } else {
            curr->group = obj_group_table[bsd->num_of_1st];
        }

        curr->lds = &texgrplds[curr->group];

        if (curr->lds->ok) {
            if (bsd->ix1st == 1 || bsd->ix1st == 2) {
                switch (rckey_work[curr->lds->key].type) {
                case 3:
                    if (curr->id != 0) {
                        rckey_work[curr->lds->key].type = 5;
                    }

                    break;

                case 4:
                    if (curr->id == 0) {
                        rckey_work[curr->lds->key].type = 5;
                    }

                    break;

                case 5:
                    break;
                }
            } else {
                rckey_work[curr->lds->key].type = curr->kokey;
            }

            *curr->result |= lpr_wrdata[curr->id];
            curr->be = 0;
            return;
        }

        /* fallthrough */

    case 1:
        err = fsOpen(curr);

        if (err == 0) {
            curr->rno = 0;
            return;
        }

        curr->rno = 2;
        /* fallthrough */

    case 2:
        curr->size = (s32)fsGetFileSize(curr->fnum);
        curr->sect = (s32)fsCalSectorSize((u32)curr->size);
        curr->key = Pull_ramcnt_key((u32)curr->sect << 11, curr->kokey, curr->group, curr->frre);
        curr->lds->key = curr->key;
        Set_size_data_ramcnt_key(curr->key, (u32)curr->size);
        curr->rno = 3;
        /* fallthrough */

    case 3:
        err = fsRequestFileRead(curr, (u32)curr->sect, Get_ramcnt_address(curr->key));

        if (err == 0) {
            Push_ramcnt_key(curr->key);
            fsClose(curr);
            curr->rno = 0;
            return;
        }

        curr->rno = 4;
        curr->be = 1;
        break;

    case 4:
        switch (fsCheckFileReaded(curr)) {
        case 1:
            fsClose(curr);
            ldadr = Get_ramcnt_address(curr->key);
            curr->lds->texture_table = ldadr + bsd->to_tex;
            curr->lds->trans_table = ldadr;
            curr->lds->ok = 1;

            if (bsd->ix1st == 1) {
                ldchd = ldadr + bsd->to_chd;

#if !defined(__LP64__) && !defined(_WIN64)
                for (i = 0; i < 25; i++) {
                    ((u32 *)ldchd)[i] += (u32)ldchd;
                }
#endif

                cit = (CharInitData *)ldchd;
                cit2 = &char_init_data[plid_data[plt_req[curr->id]]];
#if !defined(__LP64__) && !defined(_WIN64)
                *cit2 = *cit;
#else
                /* The file holds the 25 tables as 32-bit offsets from
                 * itself, which the 32-bit build turns into addresses in
                 * place. A 64-bit address does not fit a word: the file
                 * keeps the offsets, and CharInitData takes the addresses. */
                (void)cit;
                for (i = 0; i < 25; i++) {
                    ((void **)cit2)[i] = ldchd + ((u32 *)ldchd)[i];
                }
#endif
                parabora_own_table[plt_req[curr->id]] = cit2->prot;

                if (curr->ix == 18) {
#if !defined(__LP64__) && !defined(_WIN64)
                    patchAdrs = ((u32 **)ldchd)[8];
#else
                    patchAdrs = (u32 *)(ldchd + ((u32 *)ldchd)[8]);
#endif
                    patchAdrs[37] = patchAdrs[3];
                }

                if (curr->ix == 15) {
                    trsbas = (u16 *)(texgrplds[15].trans_table + ((u32 *)texgrplds[15].trans_table)[166]);
                    count = (s16)*trsbas;
                    count -= 1;
                    trsbas[0] = (u16)count;
                    trsbas += 1;
                    trsptr = (TexGroup_UNK_0 *)trsbas;
                    trsptr[0].x = (s16)(trsptr[0].x + trsptr[1].x);
                    trsptr[0].y = (s16)(trsptr[0].y + trsptr[1].y);
                    trsptr[0].attr = trsptr[1].attr;
                    trsptr[0].code = trsptr[1].code;

                    for (loop = 1; loop < count; loop++) {
                        trsptr[loop] = trsptr[loop + 1];
                    }
                }
            }

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

void Init_texgrplds_work(void) {
    s16 i;

    for (i = 0; i < (s16)(sizeof(TexGrpLd) / sizeof(u32)); i++) {
        ((u32 *)texgrplds)[i] = 0;
    }

    for (i = 1; i < 100; i++) {
        texgrplds[i] = texgrplds[0];
    }
}

void reservMemKeySelObj(void) {
    TexGrpLd *lds;
    u32 size;

    size = fsCalSectorSize(0x11372CU) << 11;
    lds = &texgrplds[obj_group_table[0x69E0]];
    lds->key = Pull_ramcnt_key(size, 0xD, 0, 1);

    if (lds->key < 0) {
        while (1) {}
    }
}

void checkSelObjFileLoaded(void) {
    const TexGroupData *bsd;
    TexGrpLd *lds;
    u8 *ldadr;
    s32 rnum;

    if (omSelObjNowOnMemoryType == mpp_w.language) {
        return;
    }

    if (mpp_w.language) {
        bsd = &texgrpdat[0x62];
    } else {
        bsd = &texgrpdat[0x17];
    }

    lds = &texgrplds[obj_group_table[0x69E0]];

    while (1) {
        rnum = load_it_use_this_key(bsd->apfn, lds->key);

        if (rnum != 0) {
            break;
        }
    }

    ldadr = Get_ramcnt_address(lds->key);
    lds->texture_table = ldadr + bsd->to_tex;
    lds->trans_table = ldadr;
    lds->ok = 1;
    omSelObjNowOnMemoryType = (u8)mpp_w.language;
    Clear_texcash_work();
}

void purge_texture_group_of_this(u16 patnum) {
    purge_texture_group(obj_group_table[patnum]);
}

void purge_texture_group(u8 grp) {
    if (texgrplds[grp].ok != 0) {
        texgrplds[grp].ok = 0;
        Push_ramcnt_key(texgrplds[grp].key);
    }
}

void purge_player_texture(s16 id) {
    s16 emid;
    s16 pkey;

    emid = (s16)((id + 1) & 1);

    if ((pkey = Search_ramcnt_type(lpt_seldat[2])) != 0) {
        while (1) {
            rckey_work[pkey].type = lpt_seldat[emid];

            if (!(pkey = Search_ramcnt_type(lpt_seldat[2]))) {
                break;
            }
        }
    }

    while (1) {
        pkey = Search_ramcnt_type(lpt_seldat[id]);

        if (pkey == 0) {
            break;
        }

        Push_ramcnt_key(pkey);
    }
}

s32 load_any_texture_patnum(u16 patnum, u8 kokey, u8 _unused) {
    (void)_unused;
    return load_any_texture_grpnum(obj_group_table[patnum], kokey);
}

s32 load_any_texture_grpnum(u8 grp, u8 kokey) {
    const TexGroupData *bsd;
    TexGrpLd *lds;
    u8 *ldadr;

    if (grp == 0) {
        return 0;
    }

    lds = &texgrplds[grp];
    bsd = &texgrpdat[grp];

    if (lds->ok) {
        return 0;
    }

    lds->key = load_it_use_any_key(bsd->apfn, kokey, grp);
    ldadr = Get_ramcnt_address(lds->key);
    lds->texture_table = ldadr + bsd->to_tex;
    lds->trans_table = ldadr;
    lds->ok = 1;
    return 1;
}
