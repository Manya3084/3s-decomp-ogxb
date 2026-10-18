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

typedef struct {
    s8 ok;
    s8 type;
    s16 key;
    u8 *texture_table;
    u8 *trans_table;
} TEX_GRP_LD;

typedef struct {
    u16 num_of_1st;
    u16 apfn;
    s16 conv;
    s16 ix1st;
    u32 use;
    u32 to_tex;
    u32 to_chd;
} TexGroupData;

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
    TEX_GRP_LD *lds;
    u32 info_number;
    u32 info_size;
} REQ;

typedef struct {
    u32 *raw[24];
    u32 *prot;
} CharInitData;

typedef struct {
    s16 x;
    s16 y;
    u16 attr;
    u16 code;
} TexGroup_UNK_0;

typedef struct {
    u8 raw[0xA];
    u8 type;
    u8 use;
} RCKeyWork;

typedef struct {
    u8 raw[0x31]; /* Xbox layout: language is mpp_w + 0x31 (0x7AA5F1) */
    s8 language;
} MPP;

#if defined(__i386__)
_Static_assert(sizeof(TEX_GRP_LD) == 0xC, "TEX_GRP_LD");
_Static_assert(__builtin_offsetof(TEX_GRP_LD, key) == 2, "key");
_Static_assert(__builtin_offsetof(TEX_GRP_LD, texture_table) == 4, "texture_table");
_Static_assert(__builtin_offsetof(TEX_GRP_LD, trans_table) == 8, "trans_table");
_Static_assert(sizeof(TexGroupData) == 0x14, "TexGroupData");
_Static_assert(__builtin_offsetof(TexGroupData, ix1st) == 6, "ix1st");
_Static_assert(__builtin_offsetof(TexGroupData, to_tex) == 0xC, "to_tex");
_Static_assert(__builtin_offsetof(TexGroupData, to_chd) == 0x10, "to_chd");
_Static_assert(sizeof(REQ) == 0x28, "REQ");
_Static_assert(__builtin_offsetof(REQ, retry) == 5, "retry");
_Static_assert(__builtin_offsetof(REQ, ix) == 6, "ix");
_Static_assert(__builtin_offsetof(REQ, key) == 8, "req key");
_Static_assert(__builtin_offsetof(REQ, kokey) == 0xA, "kokey");
_Static_assert(__builtin_offsetof(REQ, group) == 0xB, "group");
_Static_assert(__builtin_offsetof(REQ, result) == 0xC, "result");
_Static_assert(__builtin_offsetof(REQ, size) == 0x10, "size");
_Static_assert(__builtin_offsetof(REQ, sect) == 0x14, "sect");
_Static_assert(__builtin_offsetof(REQ, fnum) == 0x18, "fnum");
_Static_assert(__builtin_offsetof(REQ, lds) == 0x1C, "lds");
_Static_assert(sizeof(CharInitData) == 0x64, "CharInitData");
_Static_assert(__builtin_offsetof(CharInitData, prot) == 0x60, "prot");
_Static_assert(sizeof(TexGroup_UNK_0) == 8, "TexGroup_UNK_0");
_Static_assert(sizeof(RCKeyWork) == 0xC, "RCKeyWork");
_Static_assert(__builtin_offsetof(RCKeyWork, type) == 0xA, "type");
_Static_assert(__builtin_offsetof(MPP, language) == 0x31, "language");
#endif

extern TEX_GRP_LD texgrplds[100];
extern const TexGroupData texgrpdat[100];
extern const u8 obj_group_table[37664];
extern const u8 lpr_wrdata[3];
extern const u8 lpt_seldat[4];
extern const s8 plid_data[20];
extern s16 plt_req[2];
extern CharInitData char_init_data[23];
extern u32 *parabora_own_table[20];
extern u8 omSelObjNowOnMemoryType;
extern MPP mpp_w;
extern u16 DskDrvErrBe;
extern u16 word_C7F4FA;
extern RCKeyWork rckey_work[64];

extern s32 fsCheckCommandExecuting(void);
extern s32 fsOpen(REQ *curr);
extern void fsClose(REQ *curr);
extern u32 fsGetFileSize(u16 fnum);
extern u32 fsCalSectorSize(u32 size);
extern s32 fsRequestFileRead(REQ *curr, u32 sect, void *adrs);
extern s32 fsCheckFileReaded(REQ *curr);
extern s32 load_it_use_this_key(u16 fnum, s16 key);
extern s16 load_it_use_any_key(u16 fnum, u8 kokey, u8 group);
extern void xb_ShowDiskReadError(void);
extern s16 Pull_ramcnt_key(u32 memreq, u8 kokey, u8 group, u8 frre);
extern void *Get_ramcnt_address(s16 key);
extern void Set_size_data_ramcnt_key(s16 key, u32 size);
extern void sub_00097103(s16 key);
extern s16 Search_ramcnt_type(u8 kokey);
extern void Clear_texcash_work(void);

s32 load_any_texture_grpnum(u8 grp, u8 kokey);
void purge_texture_group(u8 grp);

void q_ldreq_texture_group(REQ *curr) {
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
            word_C7F4FA = 1;
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
            sub_00097103(curr->key);
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

                for (i = 0; i < 25; i++) {
                    ((u32 *)ldchd)[i] += (u32)ldchd;
                }

                cit = (CharInitData *)ldchd;
                cit2 = &char_init_data[plid_data[plt_req[curr->id]]];
                *cit2 = *cit;
                parabora_own_table[plt_req[curr->id]] = cit2->prot;

                if (curr->ix == 18) {
                    patchAdrs = ((u32 **)ldchd)[8];
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
            sub_00097103(curr->key);
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

    for (i = 0; i < (s16)(sizeof(TEX_GRP_LD) / sizeof(u32)); i++) {
        ((u32 *)texgrplds)[i] = 0;
    }

    for (i = 1; i < 100; i++) {
        texgrplds[i] = texgrplds[0];
    }
}

void reservMemKeySelObj(void) {
    TEX_GRP_LD *lds;
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
    TEX_GRP_LD *lds;
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
        sub_00097103(texgrplds[grp].key);
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

        sub_00097103(pkey);
    }
}

s32 load_any_texture_patnum(u16 patnum, u8 kokey, u8 _unused) {
    (void)_unused;
    return load_any_texture_grpnum(obj_group_table[patnum], kokey);
}

s32 load_any_texture_grpnum(u8 grp, u8 kokey) {
    const TexGroupData *bsd;
    TEX_GRP_LD *lds;
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
