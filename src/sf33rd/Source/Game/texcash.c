/* Texture cache, retail sf33rd.xbe.
 * init_texcash_1st is 0xEF544 size 0x60. init_texcash_2nd is 0xEF5A4
 * size 0xE0. update_with_tpu_free is 0xEF684 size 0x87.
 * get_my_trans_mode is 0xEF70B size 0x23. make_texcash_work is 0xEF72E
 * size 0x276. clear_texcash_work is 0xEF9A4 size 0xF5.
 * purge_texcash_work is 0xEFA99 size 0x8D. init_texcash_before_process
 * is 0xEFB26 size 0x35. texture_cash_update is 0xEFB5B size 0xE2.
 * Clear_texcash_work is 0xEFC3D size 0x16.
 * mts is 0x7A8F20, stride 0x64. mts_ok is 0x7A98A0, stride 0xC.
 * texcash_melt_buffer is 0x7A9880. tpu_free is 0x7A8F10.
 * mts_ob_curr_stage is 0x7A9884. mts_base is 0x2B09A8 and matches the
 * 24 PlayStation 2 rows. mts_OB_page is 0x2B0BE8 and matches the 22
 * rows. bg_w.stage is 0x7BC523.
 * init_texcash_1st pulls 0x1D08 bytes with kokey 1. The base is
 * texcash_melt_buffer and tpu_free is that base plus 0x1000. The
 * PlayStation 2 build points those at scratchpad SPR+0x1000 and
 * SPR+0x2000. make_texcash_work returns when be is already set. It
 * does not test the keys. purge_texcash_work still releases the
 * texture when a key test fails. update_with_tpu_free does not stop
 * when time goes negative. texture_cash_update does not call
 * search_texcash_free_area or disp_texcash_free_area, and it does not
 * stop on a mapping mismatch.
 * work_init_zero is 0x4A84E. makeup_tpu_free stays
 * makeup_tpu_free. mlt_obj_trans_init is 0x627F6.
 * mlt_obj_trans_update is 0x628A8. The key push stays
 * Push_ramcnt_key. 0xEFC53 stays unnamed.
 * init_texcash_2nd, make_texcash_work, and texture_cash_update are
 * scanned starts. init_texcash_1st, update_with_tpu_free,
 * get_my_trans_mode, clear_texcash_work, purge_texcash_work,
 * init_texcash_before_process, and Clear_texcash_work are interior.
 */

#include "types.h"

typedef struct {
    u8 raw[3];
    s8 stage;
} BG;

typedef struct {
    s16 be;
    s16 mincg;
    s16 min16;
    s16 min32;
    s16 key0;
    s16 key1;
} MTS_OK;

typedef struct {
    s32 p16;
    s32 p32;
    s32 gix;
    s16 life16;
    s16 life32;
    s16 type;
    u16 mode;
    u32 attribute;
} MTSBase;

typedef struct {
    s32 x16;
    s32 x32;
    u16 x16_free[1024];
    u16 x32_free[640];
} TexturePoolFree;

typedef struct {
    s32 x16;
    s32 x32;
    u16 x16_used[1024];
    u16 x32_used[640];
} TexturePoolUsed;

typedef struct {
    u16 x16_map[4][16];
    u8 x32_map[10][8];
} PatternMap;

typedef union {
    u32 code;
} PatternCode;

typedef struct {
    s16 time;
    s16 state;
    PatternCode cs;
} PatternState;

typedef struct {
    s16 curr_disp;
    s16 time;
    u32 cg;
    s16 x16;
    s16 x32;
    PatternMap map;
} PatternInstance;

typedef struct {
    s16 kazu;
    u16 pad;
    PatternInstance *adr[64];
    PatternInstance patt[64];
} PatternCollection;

typedef struct {
    u8 raw[0x20];
} Texture;

typedef struct {
    s32 mltnum16;
    s32 mltnum32;
    s32 mltnum;
    s32 mltgidx16;
    s32 mltgidx32;
    s32 mltcshtime16;
    s32 mltcshtime32;
    PatternState *mltcsh16;
    PatternState *mltcsh32;
    u8 *mltbuf;
    Texture tex;
    u8 tex_list[8];
    u32 attribute;
    PatternCollection *cpat;
    TexturePoolFree *tpf;
    TexturePoolUsed *tpu;
    u8 id;
    u8 ext;
    s16 mode;
} MultiTexture;

#if defined(__i386__)
_Static_assert(sizeof(MTS_OK) == 0xC, "MTS_OK");
_Static_assert(sizeof(MTSBase) == 0x18, "MTSBase");
_Static_assert(sizeof(TexturePoolFree) == 0xD08, "TexturePoolFree");
_Static_assert(sizeof(TexturePoolUsed) == 0xD08, "TexturePoolUsed");
_Static_assert(sizeof(PatternMap) == 0xD0, "PatternMap");
_Static_assert(sizeof(PatternState) == 8, "PatternState");
_Static_assert(sizeof(PatternInstance) == 0xDC, "PatternInstance");
_Static_assert(__builtin_offsetof(PatternInstance, map) == 0xC, "map");
_Static_assert(sizeof(PatternCollection) == 0x3804, "PatternCollection");
_Static_assert(__builtin_offsetof(PatternCollection, adr) == 4, "adr");
_Static_assert(__builtin_offsetof(PatternCollection, patt) == 0x104, "patt");
_Static_assert(sizeof(MultiTexture) == 0x64, "MultiTexture");
_Static_assert(__builtin_offsetof(MultiTexture, mltcsh16) == 0x1C, "mltcsh16");
_Static_assert(__builtin_offsetof(MultiTexture, mltbuf) == 0x24, "mltbuf");
_Static_assert(__builtin_offsetof(MultiTexture, tex) == 0x28, "tex");
_Static_assert(__builtin_offsetof(MultiTexture, attribute) == 0x50, "attribute");
_Static_assert(__builtin_offsetof(MultiTexture, cpat) == 0x54, "cpat");
_Static_assert(__builtin_offsetof(MultiTexture, tpf) == 0x58, "tpf");
_Static_assert(__builtin_offsetof(MultiTexture, tpu) == 0x5C, "tpu");
_Static_assert(__builtin_offsetof(MultiTexture, id) == 0x60, "id");
_Static_assert(__builtin_offsetof(BG, stage) == 3, "stage");
#endif

extern BG bg_w;
extern MultiTexture mts[24];
extern MTS_OK mts_ok[24];
extern u8 *texcash_melt_buffer;
extern TexturePoolUsed *tpu_free;
extern s16 mts_ob_curr_stage;
extern const MTSBase mts_base[24];
extern const s16 mts_OB_page[22][2];

extern s16 Pull_ramcnt_key(u32 memreq, u8 kokey, u8 group, u8 frre);
extern void *Get_ramcnt_address(s16 key);
extern s32 Test_ramcnt_key(s16 key);
extern void sub_00097103(s16 key);
extern s32 ppgReleaseTextureHandle(Texture *tch, s32 ixNum);
extern void work_init_zero(s32 *adrs, s32 size);
extern void makeup_tpu_free(s32 x16, s32 x32, PatternMap *map);
extern void mlt_obj_trans_init(MultiTexture *mt, s32 mode, u8 *adrs);
extern void mlt_obj_trans_update(MultiTexture *mt);

void init_texcash_1st(void) {
    s16 i;

    texcash_melt_buffer = Get_ramcnt_address(Pull_ramcnt_key(0x1D08, 1, 0, 0));
    tpu_free = (TexturePoolUsed *)(texcash_melt_buffer + 0x1000);

    for (i = 0; i < 24; i++) {
        mts_ok[i].be = 0;
        mts_ok[i].mincg = 0;
        mts_ok[i].min16 = 0x7FFF;
        mts_ok[i].min32 = 0x7FFF;
        mts_ok[i].key0 = 0;
        mts_ok[i].key1 = 0;
        mts[i].mode = -1;
    }
}

void init_texcash_2nd(s16 ix) {
    PatternState *mc;
    PatternCollection *cp;
    TexturePoolFree *tf;
    TexturePoolUsed *tu;
    s16 i;

    tf = mts[ix].tpf;
    tu = mts[ix].tpu;
    cp = mts[ix].cpat;
    tf->x32 = 0;
    tf->x16 = 0;
    tu->x32 = 0;
    tu->x16 = 0;
    mc = mts[ix].mltcsh16;

    for (i = (s16)(mts[ix].mltnum16 - 1); i >= 0; i--) {
        if (mc[i].cs.code == (u32)-1) {
            tf->x16_free[tf->x16] = (u16)i;
            tf->x16 += 1;
        } else {
            tu->x16_used[tu->x16] = (u16)i;
            tu->x16 += 1;
        }
    }

    mc = mts[ix].mltcsh32;

    for (i = (s16)(mts[ix].mltnum32 - 1); i >= 0; i--) {
        if (mc[i].cs.code == (u32)-1) {
            tf->x32_free[tf->x32] = (u16)i;
            tf->x32 += 1;
        } else {
            tu->x32_used[tu->x32] = (u16)i;
            tu->x32 += 1;
        }
    }

    cp->kazu = 0;

    for (i = 0; i < 0x40; i++) {
        if (cp->patt[i].time) {
            cp->adr[cp->kazu] = &cp->patt[i];
            cp->kazu += 1;
        }
    }
}

void update_with_tpu_free(PatternState *mc16, PatternState *mc32) {
    s16 i;

    for (i = 0; i < tpu_free->x16; i++) {
        mc16[tpu_free->x16_used[i]].time -= 1;

        if (mc16[tpu_free->x16_used[i]].time <= 0) {
            mc16[tpu_free->x16_used[i]].cs.code = (u32)-1;
        }
    }

    for (i = 0; i < tpu_free->x32; i++) {
        mc32[tpu_free->x32_used[i]].time -= 1;

        if (mc32[tpu_free->x32_used[i]].time <= 0) {
            mc32[tpu_free->x32_used[i]].cs.code = (u32)-1;
        }
    }
}

s16 get_my_trans_mode(s16 curr) {
    if (mts_ok[curr].be == 0) {
        return -1;
    }

    return mts[curr].mode;
}

void make_texcash_work(s16 ix) {
    u32 memreq;
    u8 *adrs;
    s32 page16;
    s32 page32;

    if (mts_ok[ix].be != 0) {
        return;
    }

    if (ix == 7) {
        page16 = mts_OB_page[bg_w.stage][0];
        page32 = mts_OB_page[bg_w.stage][1];
        mts_ob_curr_stage = bg_w.stage;
    } else {
        page16 = mts_base[ix].p16;
        page32 = mts_base[ix].p32;
    }

    mts[ix].mltnum16 = (s32)((u32)page16 << 8);
    mts[ix].mltnum32 = (s32)((u32)page32 << 6);
    mts[ix].mltnum = page16 + page32;
    mts[ix].mltgidx16 = mts_base[ix].gix;
    mts[ix].mltgidx32 = page16 + mts_base[ix].gix;
    mts[ix].mltcshtime16 = mts_base[ix].life16;
    mts[ix].mltcshtime32 = mts_base[ix].life32;
    mts[ix].ext = (u8)((mts_base[ix].mode & 0x2000) != 0);

    if (mts[ix].ext) {
        memreq = (u32)((mts[ix].mltnum16 * 8) + (mts[ix].mltnum32 * 8) + (s32)sizeof(PatternCollection) +
                       (s32)sizeof(TexturePoolFree) + (s32)sizeof(TexturePoolUsed));
        mts_ok[ix].key0 = Pull_ramcnt_key(memreq, (u8)mts_base[ix].type, 0, 0);
        adrs = Get_ramcnt_address(mts_ok[ix].key0);
        mts[ix].mltcsh16 = (PatternState *)adrs;
        adrs += mts[ix].mltnum16 * 8;
        mts[ix].mltcsh32 = (PatternState *)adrs;
        adrs += mts[ix].mltnum32 * 8;
        mts[ix].cpat = (PatternCollection *)adrs;
        adrs += sizeof(PatternCollection);
        mts[ix].tpf = (TexturePoolFree *)adrs;
        adrs += sizeof(TexturePoolFree);
        mts[ix].tpu = (TexturePoolUsed *)adrs;
        work_init_zero((s32 *)mts[ix].cpat, (s32)sizeof(PatternCollection));
        work_init_zero((s32 *)mts[ix].tpf, (s32)sizeof(TexturePoolFree));
        work_init_zero((s32 *)mts[ix].tpu, (s32)sizeof(TexturePoolUsed));
        init_texcash_2nd(ix);
    } else {
        memreq = (u32)((mts[ix].mltnum16 * 8) + (mts[ix].mltnum32 * 8));
        mts_ok[ix].key0 = Pull_ramcnt_key(memreq, (u8)mts_base[ix].type, 0, 0);
        adrs = Get_ramcnt_address(mts_ok[ix].key0);
        mts[ix].mltcsh16 = (PatternState *)adrs;
        adrs += mts[ix].mltnum16 * 8;
        mts[ix].mltcsh32 = (PatternState *)adrs;
    }

    mts[ix].mltbuf = texcash_melt_buffer;
    memreq = (u32)(((mts_base[ix].mode & 4) != 0) + 1);
    memreq *= ((u32)mts[ix].mltnum << 16);
    mts_ok[ix].key1 = Pull_ramcnt_key(memreq, (u8)mts_base[ix].type, 0, 0);
    mts[ix].attribute = mts_base[ix].attribute;
    mlt_obj_trans_init(&mts[ix], mts_base[ix].mode, Get_ramcnt_address(mts_ok[ix].key1));

    if (mts[ix].ext) {
        init_texcash_2nd(ix);
    }

    mts[ix].id = (u8)ix;
    mts[ix].mode = (s16)(mts_base[ix].mode & 0xFF);
    mts_ok[ix].be = 1;
    mts_ok[ix].mincg = 0;
    mts_ok[ix].min16 = 0x7FFF;
    mts_ok[ix].min32 = 0x7FFF;
}

void clear_texcash_work(s16 ix) {
    s16 i;

    if ((mts_ok[ix].be != 0) && ((mts_base[ix].mode & 0x20) == 0)) {
        for (i = 0; i < mts[ix].mltnum16; i++) {
            mts[ix].mltcsh16[i].time = 0;
            mts[ix].mltcsh16[i].cs.code = (u32)-1;
        }

        for (i = 0; i < mts[ix].mltnum32; i++) {
            mts[ix].mltcsh32[i].time = 0;
            mts[ix].mltcsh32[i].cs.code = (u32)-1;
        }

        if (mts[ix].ext) {
            work_init_zero((s32 *)mts[ix].cpat, (s32)sizeof(PatternCollection));
            work_init_zero((s32 *)mts[ix].tpf, (s32)sizeof(TexturePoolFree));
            work_init_zero((s32 *)mts[ix].tpu, (s32)sizeof(TexturePoolUsed));
            init_texcash_2nd(ix);
        }

        mts_ok[ix].mincg = 0;
        mts_ok[ix].min16 = 0x7FFF;
        mts_ok[ix].min32 = 0x7FFF;
    }
}

void purge_texcash_work(s16 ix) {
    if (mts_ok[ix].be == 0) {
        return;
    }

    if ((Test_ramcnt_key(mts_ok[ix].key0) != 0) && (Test_ramcnt_key(mts_ok[ix].key1) != 0)) {
        sub_00097103(mts_ok[ix].key0);
        sub_00097103(mts_ok[ix].key1);
    }

    ppgReleaseTextureHandle(&mts[ix].tex, -1);
    mts_ok[ix].be = 0;
    mts_ok[ix].key0 = 0;
    mts_ok[ix].key1 = 0;
}

void init_texcash_before_process(void) {
    s16 i;

    for (i = 1; i < 24; i++) {
        if ((mts_ok[i].be != 0) && (mts[i].ext != 0)) {
            init_texcash_2nd(i);
        }
    }
}

void texture_cash_update(void) {
    s16 i;
    s16 num;

    for (num = 0; num < 24; num++) {
        if (mts_ok[num].be != 0) {
            if (mts[num].ext) {
                for (i = 0; i < mts[num].cpat->kazu; i++) {
                    if ((--mts[num].cpat->adr[i]->time) == 0) {
                        makeup_tpu_free(mts[num].mltnum16 / 256, mts[num].mltnum32 / 64,
                                     &mts[num].cpat->adr[i]->map);
                        update_with_tpu_free(mts[num].mltcsh16, mts[num].mltcsh32);
                    }
                }
            } else if ((mts[num].mltcshtime16 + mts[num].mltcshtime32) != 0) {
                mlt_obj_trans_update(&mts[num]);
            }
        }
    }
}

void Clear_texcash_work(void) {
    s16 i;

    for (i = 1; i < 24; i++) {
        clear_texcash_work(i);
    }
}
