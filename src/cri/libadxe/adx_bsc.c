/* adxb_DefGetWr 0x172A60. adxb_DefAddWr 0x172AA0.
 * ADXB_Destroy 0x172AC0 clears 0xE4 bytes.
 * SKG_Init 0x172AF0 increments the counter at 0x7A60C4.
 * ADXB_EntryGetWrFunc 0x172C20 stores get_wr and object.
 * ADXB_Init 0x1733B0 calls 0x173C70, then SKG_Init, then clears
 * the 16 objects at 0xCCF540. ADXB_Create 0x1733D0 takes a free
 * one of those objects.
 * ADXB_GetPcmBuf 0x172C40 returns unk3C.
 * ADXB_GetFormat 0x172C50, ADXB_GetSfreq 0x172C60, ADXB_GetNumChan 0x172C70,
 * ADXB_GetOutBps 0x172C80,
 * ADXB_GetBlkSmpl 0x172CE0, ADXB_GetTotalNumSmpl 0x172CF0,
 * ADXB_GetNumLoop 0x172D00, ADXB_GetAinfLen 0x172D40,
 * ADXB_GetDefOutVol 0x172D50, ADXB_GetDefPan 0x172D60,
 * ADXB_GetStat 0x172EE0, ADXB_EntryData 0x172EF0,
 * ADXB_Start 0x172F60,
 * ADXB_Stop 0x172F80, ADXB_Reset 0x172FA0, ADXB_GetDecDtLen 0x172FD0,
 * ADXB_GetDecNumSmpl 0x172FE0, ADXB_EvokeExpandSte 0x173020,
 * ADXB_EvokeDecode 0x173060,
 * memcpy2 0x173130,
 * ADXB_CopyExtraBufSte 0x173160, ADXB_EndDecode 0x1731C0,
 * ADXB_ExecOneAdx 0x173290,
 * ADXB_ExecHndl 0x173330.
 * ADXB_SetAc3InSj 0x173840. When unkBC is set it tail-jumps
 * through ac3setsjifunc at 0x7A60E0.
 * ADXB_SetAc3DecSmpl 0x173860 stores the count at +0xC0 and
 * that count divided by 2048 at +0xC4.
 * ADXB_Ac3TermSupply 0x173890 tail-jumps through
 * ac3termsupplyfunc at 0x7A60E4 when unkBC is set.
 * ADXB_SetAhxInSj 0x173970 tail-jumps through ahxsetsjifunc
 * at 0x7A60EC when unkB0 is set.
 * ADXB_SetAhxDecSmpl 0x173990 calls ahxsetdecsmplfunc at
 * 0x7A60F0, stores the count at +0xB4, and stores the count
 * divided by 96 at +0xB8.
 * ADXB_AhxTermSupply 0x1739E0 tail-jumps through
 * ahxtermsupplyfunc at 0x7A60F4 when unkB0 is set.
 *
 * stat is the s32 at +4. adxpd is +8. sample_bitdepth is +0x0D,
 * channel_count is +0x0E, and block_size is +0x0F. samples_per_block
 * is +0x10, sample_rate is +0x14, and total_samples is +0x18.
 * unk24 is the word at +0x24. unk48 is +0x48. unk74 is +0x74.
 * unk8C is +0x8C. dec_num_sample is +0x90. dec_data_len is +0x94.
 * format is the word at +0x98. unk9A is the word at +0x9A.
 * ADXPD_Stop and ADXPD_Reset are named in adx_xpnd.c.
 * GetNumChan returns channel_count. It does not test unkE4.
 * Stop does not read unkE4.
 * ADXB_EvokeDecode is 0x173060. It does not test unkE4. The
 * other channel calls 0x172FF0. ADXB_EndDecode calls
 * ADXB_GetBlkSmpl on the adxpd pointer and does not test unkE4.
 * The mono extra copy is 0x1731A0.
 * ADXB_ExecOneAdx is 0x173290. It does not test unkE4.
 * ExecHndl sends format 0x14 to ADXB_ExecOneAc3 (0x1738B0), 0xA to
 * ADXB_ExecOneAhx (0x1739D0), 2 to 0x1751C0 (ADXB_ExecOneSpsd folded with
 * ADXB_ExecOneWav16), 3 to
 * ADXB_ExecOneAiff (0x174FF0), 4 to ADXB_ExecOneAu (0x174BA0), and 1 to
 * ADXB_ExecOneWav (0x174450).
 * ADXB_DecodeHeader is 0x173770. The 0x8000 branch calls
 * ADXB_DecodeHeaderAdx at 0x1734E0. encoding_type >= 5 stores format
 * 0xA. Otherwise format is 0. ahxsetextfunc is 0x7A60D0 (a pointer).
 * ADX_DecodeInfo, ADX_DecodeInfoExADPCM2, ADX_DecodeInfoExVer,
 * ADX_DecodeInfoExIdly, ADX_DecodeInfoExLoop, and ADX_DecodeInfoAinf
 * are named in adx_dcd.c.
 * adxb_get_key is 0x172E10 and always returns 0. The default key
 * words are 0x7A60D4, 0x7A60D8, and 0x7A60DC. SKG_GenerateKey is
 * 0x172B00 is SKG_GenerateKey.
 * ADXPD_SetCoef, ADXPD_SetDly, ADXPD_GetDly, ADXPD_SetExtPrm,
 * ADXPD_GetExtPrm, ADXPD_Destroy, ADXPD_GetStat, ADXPD_EntryMono,
 * ADXPD_EntrySte, ADXPD_Start, ADXPD_Stop, and ADXPD_Reset are named in adx_xpnd.c.
 * The SPSD check at 0x1752C0 calls 0x175100. The WAV check at
 * 0x174420 calls 0x174140. The AIFF check at 0x174E40 calls 0x174F30.
 * The AU check at 0x1746C0 calls 0x1747B0. Those checks compare
 * SPSD, RIFF/WAVE, FORM/AIFF, and .snd or .sd. There is no AC3
 * check. The leftover path calls 0x1738D0.

 * ADXB_GetSfreq is folded into 0x172C60 with 1 other bodies. Unnamed.
 * ADXB_GetBlkSmpl is folded into 0x172CE0 with 2 other bodies. Unnamed. */

#include "types.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    u8 pad[0x10];
} ADXB_UNKCC;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    void *unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
} ADXB_UNK48;

typedef struct ADXB_OBJ {
    s16 unk0;
    s16 unk2;
    s32 stat;
    void *adxpd;
    s8 encoding_type;
    s8 sample_bitdepth;
    s8 channel_count;
    s8 block_size;
    s32 samples_per_block;
    s32 sample_rate;
    s32 total_samples;
    s16 unk1C;
    u8 gap1E[2];
    s32 unk20;
    s16 unk24;
    s16 unk26;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    void *unk3C;
    s32 unk40;
    s32 unk44;
    ADXB_UNK48 unk48;
    s32 unk74;
    void *(*get_wr)(void *object, s32 *arg1, s32 *arg2, s32 *arg3);
    void *object;
    void (*add_wr)(s32 arg0, s32 len, s32 samples);
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 dec_num_sample;
    s32 dec_data_len;
    s16 format;
    s16 unk9A;
    s16 unk9C;
    s16 unk9E;
    s16 unkA0;
    s16 unkA2;
    s16 unkA4;
    s16 unkA6;
    s16 unkA8[2];
    s16 unkAC[2];
    s32 unkB0;
    s32 ahx_dec_samples;
    s32 ahx_dec_frames;
    s32 unkBC;
    s32 ac3_dec_samples;
    s32 ac3_dec_frames;
    s32 unkC8;
    ADXB_UNKCC unkCC;
    s16 unkDC;
    s16 unkDE[2];
} ADXB_OBJ;

typedef ADXB_OBJ *ADXB;

#if defined(__i386__)
_Static_assert(offsetof(ADXB_OBJ, stat) == 4, "stat");
_Static_assert(offsetof(ADXB_OBJ, adxpd) == 8, "adxpd");
_Static_assert(offsetof(ADXB_OBJ, encoding_type) == 0x0C, "encoding_type");
_Static_assert(offsetof(ADXB_OBJ, sample_bitdepth) == 0x0D, "sample_bitdepth");
_Static_assert(offsetof(ADXB_OBJ, channel_count) == 0x0E, "channel_count");
_Static_assert(offsetof(ADXB_OBJ, block_size) == 0x0F, "block_size");
_Static_assert(offsetof(ADXB_OBJ, samples_per_block) == 0x10, "samples_per_block");
_Static_assert(offsetof(ADXB_OBJ, sample_rate) == 0x14, "sample_rate");
_Static_assert(offsetof(ADXB_OBJ, total_samples) == 0x18, "total_samples");
_Static_assert(offsetof(ADXB_OBJ, unk1C) == 0x1C, "unk1C");
_Static_assert(offsetof(ADXB_OBJ, unk20) == 0x20, "unk20");
_Static_assert(offsetof(ADXB_OBJ, unk24) == 0x24, "unk24");
_Static_assert(offsetof(ADXB_OBJ, unk26) == 0x26, "unk26");
_Static_assert(offsetof(ADXB_OBJ, unk34) == 0x34, "unk34");
_Static_assert(offsetof(ADXB_OBJ, unk38) == 0x38, "unk38");
_Static_assert(offsetof(ADXB_OBJ, unk3C) == 0x3C, "unk3C");
_Static_assert(offsetof(ADXB_OBJ, unk40) == 0x40, "unk40");
_Static_assert(offsetof(ADXB_OBJ, unk44) == 0x44, "unk44");
_Static_assert(offsetof(ADXB_OBJ, unk48) == 0x48, "unk48");
_Static_assert(offsetof(ADXB_UNK48, unk4) == 4, "unk48.unk4");
_Static_assert(offsetof(ADXB_UNK48, unk8) == 8, "unk48.unk8");
_Static_assert(offsetof(ADXB_UNK48, unk10) == 0x10, "unk48.unk10");
_Static_assert(offsetof(ADXB_UNK48, unk14) == 0x14, "unk48.unk14");
_Static_assert(offsetof(ADXB_UNK48, unk1C) == 0x1C, "unk48.unk1C");
_Static_assert(offsetof(ADXB_UNK48, unk20) == 0x20, "unk48.unk20");
_Static_assert(offsetof(ADXB_UNK48, unk24) == 0x24, "unk48.unk24");
_Static_assert(offsetof(ADXB_UNK48, unk28) == 0x28, "unk48.unk28");
_Static_assert(offsetof(ADXB_OBJ, unk74) == 0x74, "unk74");
_Static_assert(offsetof(ADXB_OBJ, get_wr) == 0x78, "get_wr");
_Static_assert(offsetof(ADXB_OBJ, object) == 0x7C, "object");
_Static_assert(offsetof(ADXB_OBJ, add_wr) == 0x80, "add_wr");
_Static_assert(offsetof(ADXB_OBJ, unk84) == 0x84, "unk84");
_Static_assert(offsetof(ADXB_OBJ, unk88) == 0x88, "unk88");
_Static_assert(offsetof(ADXB_OBJ, unk8C) == 0x8C, "unk8C");
_Static_assert(offsetof(ADXB_OBJ, unkB0) == 0xB0, "unkB0");
_Static_assert(offsetof(ADXB_OBJ, ahx_dec_samples) == 0xB4, "ahx_dec_samples");
_Static_assert(offsetof(ADXB_OBJ, ahx_dec_frames) == 0xB8, "ahx_dec_frames");
_Static_assert(offsetof(ADXB_OBJ, unkBC) == 0xBC, "unkBC");
_Static_assert(offsetof(ADXB_OBJ, ac3_dec_samples) == 0xC0, "ac3_dec_samples");
_Static_assert(offsetof(ADXB_OBJ, ac3_dec_frames) == 0xC4, "ac3_dec_frames");
_Static_assert(offsetof(ADXB_OBJ, unkC8) == 0xC8, "unkC8");
_Static_assert(offsetof(ADXB_OBJ, unkCC) == 0xCC, "unkCC");
_Static_assert(offsetof(ADXB_OBJ, unkDC) == 0xDC, "unkDC");
_Static_assert(offsetof(ADXB_OBJ, unkDE) == 0xDE, "unkDE");
_Static_assert(sizeof(ADXB_UNKCC) == 0x10, "unkCC");
_Static_assert(offsetof(ADXB_OBJ, dec_num_sample) == 0x90, "dec_num_sample");
_Static_assert(offsetof(ADXB_OBJ, dec_data_len) == 0x94, "dec_data_len");
_Static_assert(offsetof(ADXB_OBJ, format) == 0x98, "format");
_Static_assert(offsetof(ADXB_OBJ, unk9A) == 0x9A, "unk9A");
_Static_assert(offsetof(ADXB_OBJ, unk9C) == 0x9C, "unk9C");
_Static_assert(offsetof(ADXB_OBJ, unk9E) == 0x9E, "unk9E");
_Static_assert(offsetof(ADXB_OBJ, unkA0) == 0xA0, "unkA0");
_Static_assert(sizeof(ADXB_OBJ) == 0xE4, "ADXB_OBJ");
#endif

extern void ADXPD_Stop(void *adxpd);
extern void ADXPD_Destroy(void *adxpd);
extern void *ADXPD_Create(void);
extern s32 skg_init_count; /* 0x7A60C4 */

#define ADXB_MAX_OBJ 16

extern ADXB_OBJ adxb_obj[ADXB_MAX_OBJ]; /* 0xCCF540 */
extern void ADXPD_Init(void);
extern void ADXPD_Reset(void *adxpd);
extern s32 ADXPD_GetStat(void *adxpd);
extern void ADXPD_ExecHndl(void *adxpd);
extern s32 ADXPD_EntrySte(void *adxpd, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void ADXPD_Start(void *adxpd);
extern void ADXB_EvokeExpandMono(ADXB adxb, s32 nblk);
extern void ADXB_CopyExtraBufMono(void *buf, s32 arg1, s32 arg2, s32 arg3);
extern void ADXB_ExecOneAhx(ADXB adxb);
extern void sub_001751C0(ADXB adxb);
extern void ADXB_ExecOneAiff(ADXB adxb);
extern void ADXB_ExecOneAu(ADXB adxb);
extern void ADXB_ExecOneWav(ADXB adxb);
extern void ADXB_ExecOneAc3(ADXB adxb);
extern s32 ADX_DecodeInfo(void *header, s32 len, s16 *audio_offset, s8 *encoding_type, s8 *sample_bitdepth,
                          s8 *block_size, s8 *channel_count, s32 *sample_rate, s32 *total_samples,
                          s32 *samples_per_block);
extern s32 ADX_DecodeInfoExVer(void *header, s32 len, s8 *version, s8 *flags);
extern s32 ADX_DecodeInfoExADPCM2(void *header, s32 len, s16 *high_pass);
extern s32 ADX_DecodeInfoExIdly(void *header, s32 len, s16 *dly0, s16 *dly1);
extern s32 ADX_DecodeInfoExLoop(void *header, s32 len, s32 *loop_unk20, s16 *loop_unk24, s16 *loop_unk26,
                                s32 *loop_unk28, s32 *loop_unk2C, s32 *loop_unk30, s32 *loop_unk34);
extern s32 ADX_DecodeInfoAinf(void *header, s32 len, s32 *unk_c8, ADXB_UNKCC *unk_cc, s16 *unk_dc, s16 *unk_de);
extern s16 adxb_def_k0;
extern s16 adxb_def_km;
extern s16 adxb_def_ka;
extern void ADXPD_SetExtPrm(void *adxpd, s16 arg1, s16 arg2, s16 arg3);
extern void ADXPD_SetCoef(void *adxpd, s32 sample_rate, s16 high_pass);
extern void ADXPD_SetDly(void *adxpd, s16 *dly0, s16 *dly1);
extern void ADXPD_GetDly(void *adxpd, s16 *dly0, s16 *dly1);
extern void ADXPD_GetExtPrm(void *adxpd, s16 *arg1, s16 *arg2, s16 *arg3);
extern s32 ADXPD_EntryMono(void *adxpd, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void ADXERR_CallErrFunc2(const char *msg, const char *detail);
extern void (*ahxsetextfunc)(s32 arg0, s16 *arg1);
extern void (*ac3setsjifunc)(s32 arg0, void *sj); /* 0x7A60E0 */
extern void (*ac3termsupplyfunc)(s32 arg0); /* 0x7A60E4 */
extern void (*ahxsetsjifunc)(s32 arg0, void *sj); /* 0x7A60EC */
extern void (*ahxsetdecsmplfunc)(s32 arg0, s32 samples); /* 0x7A60F0 */
extern void (*ahxtermsupplyfunc)(s32 arg0); /* 0x7A60F4 */
extern void (*ac3execfunc)(ADXB adxb); /* 0x7A60E8 */
extern void (*ahxexecfunc)(void); /* 0x7A60F8 */
extern s32 ADXB_CheckSpsd(void *header);
extern s32 ADXB_DecodeHeaderSpsd(ADXB adxb, void *header, s32 len);
extern s32 ADXB_CheckWav(void *header);
extern s32 ADXB_DecodeHeaderWav(ADXB adxb, void *header, s32 len);
extern s32 ADXB_CheckAiff(void *header);
extern s32 ADXB_DecodeHeaderAiff(ADXB adxb, void *header, s32 len);
extern s32 ADXB_CheckAu(void *header);
extern s32 ADXB_DecodeHeaderAu(ADXB adxb, void *header, s32 len);
extern s32 ADXB_DecodeHeaderAc3(ADXB adxb, void *header, s32 len);

void *adxb_DefGetWr(void *object, s32 *arg1, s32 *arg2, s32 *arg3) {
    ADXB adxb = object;

    *arg1 = adxb->unk8C;
    *arg2 = adxb->unk40 - adxb->unk8C;
    *arg3 = adxb->total_samples - adxb->unk88;
    return adxb->unk3C;
}

void adxb_DefAddWr(s32 object, s32 arg1, s32 arg2) {
    ADXB adxb = (ADXB)object;

    (void)arg1;
    adxb->unk8C += arg2;
    adxb->unk88 += arg2;
}

void ADXB_Destroy(ADXB adxb) {
    void *adxpd;

    if (adxb != NULL) {
        adxpd = adxb->adxpd;
        adxb->adxpd = NULL;
        ADXPD_Destroy(adxpd);
        memset(adxb, 0, sizeof(*adxb));
        adxb->unk0 = 0;
    }
}

s32 SKG_Init(void) {
    skg_init_count += 1;
    return 0;
}

/* SKG_GenerateKey 0x172B00.
 *
 * Derives the three ADX key words from a key string: each runs from its
 * seed (0x4A1D, 0x53FF, 0x5DC1) through the string, multiplying by the
 * character's table value (skg_prim_tbl from its middle, indexed by the signed char) and
 * mapping the product mod 1024 through skg_prim_tbl. All are 0 for an empty
 * key. */

/* skg_prim_tbl is 0x2E1628: 1024 primes from 16411. The character
 * multipliers are its entries 0 to 255, read through its middle (0x2E1728)
 * with the signed character as index. */
const u16 skg_prim_tbl[1024] = {
    16411, 16417, 16421, 16427, 16433, 16447, 16451, 16453, 16477, 16481, 16487, 16493,
    16519, 16529, 16547, 16553, 16561, 16567, 16573, 16603, 16607, 16619, 16631, 16633,
    16649, 16651, 16657, 16661, 16673, 16691, 16693, 16699, 16703, 16729, 16741, 16747,
    16759, 16763, 16787, 16811, 16823, 16829, 16831, 16843, 16871, 16879, 16883, 16889,
    16901, 16903, 16921, 16927, 16931, 16937, 16943, 16963, 16979, 16981, 16987, 16993,
    17011, 17021, 17027, 17029, 17033, 17041, 17047, 17053, 17077, 17093, 17099, 17107,
    17117, 17123, 17137, 17159, 17167, 17183, 17189, 17191, 17203, 17207, 17209, 17231,
    17239, 17257, 17291, 17293, 17299, 17317, 17321, 17327, 17333, 17341, 17351, 17359,
    17377, 17383, 17387, 17389, 17393, 17401, 17417, 17419, 17431, 17443, 17449, 17467,
    17471, 17477, 17483, 17489, 17491, 17497, 17509, 17519, 17539, 17551, 17569, 17573,
    17579, 17581, 17597, 17599, 17609, 17623, 17627, 17657, 17659, 17669, 17681, 17683,
    17707, 17713, 17729, 17737, 17747, 17749, 17761, 17783, 17789, 17791, 17807, 17827,
    17837, 17839, 17851, 17863, 17881, 17891, 17903, 17909, 17911, 17921, 17923, 17929,
    17939, 17957, 17959, 17971, 17977, 17981, 17987, 17989, 18013, 18041, 18043, 18047,
    18049, 18059, 18061, 18077, 18089, 18097, 18119, 18121, 18127, 18131, 18133, 18143,
    18149, 18169, 18181, 18191, 18199, 18211, 18217, 18223, 18229, 18233, 18251, 18253,
    18257, 18269, 18287, 18289, 18301, 18307, 18311, 18313, 18329, 18341, 18353, 18367,
    18371, 18379, 18397, 18401, 18413, 18427, 18433, 18439, 18443, 18451, 18457, 18461,
    18481, 18493, 18503, 18517, 18521, 18523, 18539, 18541, 18553, 18583, 18587, 18593,
    18617, 18637, 18661, 18671, 18679, 18691, 18701, 18713, 18719, 18731, 18743, 18749,
    18757, 18773, 18787, 18793, 18797, 18803, 18839, 18859, 18869, 18899, 18911, 18913,
    18917, 18919, 18947, 18959, 18973, 18979, 19001, 19009, 19013, 19031, 19037, 19051,
    19069, 19073, 19079, 19081, 19087, 19121, 19139, 19141, 19157, 19163, 19181, 19183,
    19207, 19211, 19213, 19219, 19231, 19237, 19249, 19259, 19267, 19273, 19289, 19301,
    19309, 19319, 19333, 19373, 19379, 19381, 19387, 19391, 19403, 19417, 19421, 19423,
    19427, 19429, 19433, 19441, 19447, 19457, 19463, 19469, 19471, 19477, 19483, 19489,
    19501, 19507, 19531, 19541, 19543, 19553, 19559, 19571, 19577, 19583, 19597, 19603,
    19609, 19661, 19681, 19687, 19697, 19699, 19709, 19717, 19727, 19739, 19751, 19753,
    19759, 19763, 19777, 19793, 19801, 19813, 19819, 19841, 19843, 19853, 19861, 19867,
    19889, 19891, 19913, 19919, 19927, 19937, 19949, 19961, 19963, 19973, 19979, 19991,
    19993, 19997, 20011, 20021, 20023, 20029, 20047, 20051, 20063, 20071, 20089, 20101,
    20107, 20113, 20117, 20123, 20129, 20143, 20147, 20149, 20161, 20173, 20177, 20183,
    20201, 20219, 20231, 20233, 20249, 20261, 20269, 20287, 20297, 20323, 20327, 20333,
    20341, 20347, 20353, 20357, 20359, 20369, 20389, 20393, 20399, 20407, 20411, 20431,
    20441, 20443, 20477, 20479, 20483, 20507, 20509, 20521, 20533, 20543, 20549, 20551,
    20563, 20593, 20599, 20611, 20627, 20639, 20641, 20663, 20681, 20693, 20707, 20717,
    20719, 20731, 20743, 20747, 20749, 20753, 20759, 20771, 20773, 20789, 20807, 20809,
    20849, 20857, 20873, 20879, 20887, 20897, 20899, 20903, 20921, 20929, 20939, 20947,
    20959, 20963, 20981, 20983, 21001, 21011, 21013, 21017, 21019, 21023, 21031, 21059,
    21061, 21067, 21089, 21101, 21107, 21121, 21139, 21143, 21149, 21157, 21163, 21169,
    21179, 21187, 21191, 21193, 21211, 21221, 21227, 21247, 21269, 21277, 21283, 21313,
    21317, 21319, 21323, 21341, 21347, 21377, 21379, 21383, 21391, 21397, 21401, 21407,
    21419, 21433, 21467, 21481, 21487, 21491, 21493, 21499, 21503, 21517, 21521, 21523,
    21529, 21557, 21559, 21563, 21569, 21577, 21587, 21589, 21599, 21601, 21611, 21613,
    21617, 21647, 21649, 21661, 21673, 21683, 21701, 21713, 21727, 21737, 21739, 21751,
    21757, 21767, 21773, 21787, 21799, 21803, 21817, 21821, 21839, 21841, 21851, 21859,
    21863, 21871, 21881, 21893, 21911, 21929, 21937, 21943, 21961, 21977, 21991, 21997,
    22003, 22013, 22027, 22031, 22037, 22039, 22051, 22063, 22067, 22073, 22079, 22091,
    22093, 22109, 22111, 22123, 22129, 22133, 22147, 22153, 22157, 22159, 22171, 22189,
    22193, 22229, 22247, 22259, 22271, 22273, 22277, 22279, 22283, 22291, 22303, 22307,
    22343, 22349, 22367, 22369, 22381, 22391, 22397, 22409, 22433, 22441, 22447, 22453,
    22469, 22481, 22483, 22501, 22511, 22531, 22541, 22543, 22549, 22567, 22571, 22573,
    22613, 22619, 22621, 22637, 22639, 22643, 22651, 22669, 22679, 22691, 22697, 22699,
    22709, 22717, 22721, 22727, 22739, 22741, 22751, 22769, 22777, 22783, 22787, 22807,
    22811, 22817, 22853, 22859, 22861, 22871, 22877, 22901, 22907, 22921, 22937, 22943,
    22961, 22963, 22973, 22993, 23003, 23011, 23017, 23021, 23027, 23029, 23039, 23041,
    23053, 23057, 23059, 23063, 23071, 23081, 23087, 23099, 23117, 23131, 23143, 23159,
    23167, 23173, 23189, 23197, 23201, 23203, 23209, 23227, 23251, 23269, 23279, 23291,
    23293, 23297, 23311, 23321, 23327, 23333, 23339, 23357, 23369, 23371, 23399, 23417,
    23431, 23447, 23459, 23473, 23497, 23509, 23531, 23537, 23539, 23549, 23557, 23561,
    23563, 23567, 23581, 23593, 23599, 23603, 23609, 23623, 23627, 23629, 23633, 23663,
    23669, 23671, 23677, 23687, 23689, 23719, 23741, 23743, 23747, 23753, 23761, 23767,
    23773, 23789, 23801, 23813, 23819, 23827, 23831, 23833, 23857, 23869, 23873, 23879,
    23887, 23893, 23899, 23909, 23911, 23917, 23929, 23957, 23971, 23977, 23981, 23993,
    24001, 24007, 24019, 24023, 24029, 24043, 24049, 24061, 24071, 24077, 24083, 24091,
    24097, 24103, 24107, 24109, 24113, 24121, 24133, 24137, 24151, 24169, 24179, 24181,
    24197, 24203, 24223, 24229, 24239, 24247, 24251, 24281, 24317, 24329, 24337, 24359,
    24371, 24373, 24379, 24391, 24407, 24413, 24419, 24421, 24439, 24443, 24469, 24473,
    24481, 24499, 24509, 24517, 24527, 24533, 24547, 24551, 24571, 24593, 24611, 24623,
    24631, 24659, 24671, 24677, 24683, 24691, 24697, 24709, 24733, 24749, 24763, 24767,
    24781, 24793, 24799, 24809, 24821, 24841, 24847, 24851, 24859, 24877, 24889, 24907,
    24917, 24919, 24923, 24943, 24953, 24967, 24971, 24977, 24979, 24989, 25013, 25031,
    25033, 25037, 25057, 25073, 25087, 25097, 25111, 25117, 25121, 25127, 25147, 25153,
    25163, 25169, 25171, 25183, 25189, 25219, 25229, 25237, 25243, 25247, 25253, 25261,
    25301, 25303, 25307, 25309, 25321, 25339, 25343, 25349, 25357, 25367, 25373, 25391,
    25409, 25411, 25423, 25439, 25447, 25453, 25457, 25463, 25469, 25471, 25523, 25537,
    25541, 25561, 25577, 25579, 25583, 25589, 25601, 25603, 25609, 25621, 25633, 25639,
    25643, 25657, 25667, 25673, 25679, 25693, 25703, 25717, 25733, 25741, 25747, 25759,
    25763, 25771, 25793, 25799, 25801, 25819, 25841, 25847, 25849, 25867, 25873, 25889,
    25903, 25913, 25919, 25931, 25933, 25939, 25943, 25951, 25969, 25981, 25997, 25999,
    26003, 26017, 26021, 26029, 26041, 26053, 26083, 26099, 26107, 26111, 26113, 26119,
    26141, 26153, 26161, 26171, 26177, 26183, 26189, 26203, 26209, 26227, 26237, 26249,
    26251, 26261, 26263, 26267, 26293, 26297, 26309, 26317, 26321, 26339, 26347, 26357,
    26371, 26387, 26393, 26399, 26407, 26417, 26423, 26431, 26437, 26449, 26459, 26479,
    26489, 26497, 26501, 26513, 26539, 26557, 26561, 26573, 26591, 26597, 26627, 26633,
    26641, 26647, 26669, 26681,
};

s32 SKG_GenerateKey(s8 *buf, s32 len, s16 *k0, s16 *km, s16 *ka) {
    s16 a;
    s16 b;
    s16 c;
    s32 i;

    if (skg_init_count == 0) {
        SKG_Init();
    }

    *k0 = 0;
    *km = 0;
    *ka = 0;

    if (buf == 0 && len <= 0) {
        return 0;
    }

    for (a = 0x4A1D, i = 0; i < len; i++) {
        a = skg_prim_tbl[((const s16 *)skg_prim_tbl + 128)[buf[i]] * a % 1024];
    }

    for (b = 0x53FF, i = 0; i < len; i++) {
        b = skg_prim_tbl[((const s16 *)skg_prim_tbl + 128)[buf[i]] * b % 1024];
    }

    for (c = 0x5DC1, i = 0; i < len; i++) {
        c = skg_prim_tbl[((const s16 *)skg_prim_tbl + 128)[buf[i]] * c % 1024];
    }

    *k0 = a;
    *km = b;
    *ka = c;
    return 0;
}

void ADXB_EntryGetWrFunc(ADXB adxb, void *(*get_wr)(void *object, s32 *arg1, s32 *arg2, s32 *arg3), void *object) {
    adxb->get_wr = get_wr;
    adxb->object = object;
}

void *ADXB_GetPcmBuf(ADXB adxb) {
    return adxb->unk3C;
}

s32 ADXB_GetFormat(ADXB adxb) {
    return adxb->format;
}

s32 ADXB_GetSfreq(ADXB adxb) {
    return adxb->sample_rate;
}

s32 ADXB_GetNumChan(ADXB adxb) {
    return adxb->channel_count;
}

s32 ADXB_GetOutBps(ADXB adxb) {
    s16 format;
    s16 kind;

    format = adxb->format;

    if (format == 0) {
        return 16;
    }

    if (format == 2) {
        kind = adxb->unk9A;

        if (kind == 2) {
            return 4;
        }

        return (kind == 1) ? 8 : 16;
    }

    if (format == 1) {
        kind = adxb->unk9A;
        return (kind == 2) ? 4 : 16;
    }

    return 16;
}

s32 ADXB_GetBlkSmpl(ADXB adxb) {
    return adxb->samples_per_block;
}

s32 ADXB_GetTotalNumSmpl(ADXB adxb) {
    return adxb->total_samples;
}

s32 ADXB_GetNumLoop(ADXB adxb) {
    return adxb->unk24;
}

s32 ADXB_GetAinfLen(ADXB adxb) {
    return adxb->unkC8;
}

s16 ADXB_GetDefOutVol(ADXB adxb) {
    return adxb->unkDC;
}

s16 ADXB_GetDefPan(ADXB adxb, s32 arg1) {
    return adxb->unkDE[arg1];
}

static s32 adxb_get_key(ADXB adxb, u8 version, u8 flags, s32 total_samples, s16 *k0, s16 *km, s16 *ka) {
    char text[16];

    if (version >= 4) {
        if (flags >= 0x10) {
            sprintf(text, "%08X", total_samples);
            SKG_GenerateKey(text, 8, k0, km, ka);
        } else if (flags >= 8) {
            if ((adxb->unk9C == 0) && (adxb->unk9E == 0) && (adxb->unkA0 == 0)) {
                adxb->unk9C = adxb_def_k0;
                adxb->unk9E = adxb_def_km;
                adxb->unkA0 = adxb_def_ka;
            }

            *k0 = adxb->unk9C;
            *km = adxb->unk9E;
            *ka = adxb->unkA0;
        } else {
            *k0 = 0;
            *km = 0;
            *ka = 0;
        }
    } else {
        *k0 = 0;
        *km = 0;
        *ka = 0;
    }

    return 0;
}

s32 ADXB_GetStat(ADXB adxb) {
    return adxb->stat;
}

void ADXB_EntryData(ADXB adxb, s32 arg1, s32 arg2) {
    adxb->dec_data_len = 0;
    adxb->dec_num_sample = 0;
    adxb->unk74 = 0;

    if (adxb->format == 0) {
        adxb->unk48.unk0 = arg1;
        adxb->unk48.unk4 = arg2 / adxb->block_size;
    } else {
        adxb->unk48.unk0 = arg1;
        adxb->unk48.unk4 = arg2 / ((adxb->sample_bitdepth / 8) * adxb->channel_count);
    }
}

void ADXB_Start(ADXB adxb) {
    if (adxb->stat == 0) {
        adxb->stat = 1;
    }
}

void ADXB_Stop(ADXB adxb) {
    ADXPD_Stop(adxb->adxpd);
    adxb->stat = 0;
}

void ADXB_Reset(ADXB adxb) {
    if (adxb->stat == 3) {
        ADXPD_Reset(adxb->adxpd);
        adxb->unk8C = 0;
        adxb->stat = 0;
    }
}

s32 ADXB_GetDecDtLen(ADXB adxb) {
    return adxb->dec_data_len;
}

s32 ADXB_GetDecNumSmpl(ADXB adxb) {
    return adxb->dec_num_sample;
}

void ADXB_EvokeExpandSte(ADXB adxb, s32 arg1) {
    void *adxpd = adxb->adxpd;
    s32 a3;
    s32 t0;

    a3 = (s32)((u8 *)adxb->unk48.unk14 + (adxb->unk48.unk20 * 2));
    t0 = a3 + (adxb->unk48.unk1C * 2);
    ADXPD_EntrySte(adxpd, adxb->unk48.unk0, arg1 * 2, a3, t0);
    ADXPD_Start(adxpd);
}

void ADXB_EvokeDecode(ADXB adxb) {
    s32 temp_a1_2;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_t0;
    s32 temp_t2;
    s32 temp_t7;
    s32 var_t3;
    s32 var_t1;
    s32 var_t4;
    s32 var_a3;

    temp_lo = adxb->unk48.unk4 / adxb->unk48.unk8;
    temp_t7 = adxb->unk48.unk18;
    var_t1 = adxb->unk48.unk10;
    temp_t0 = adxb->unk48.unk20;
    var_a3 = adxb->unk48.unk28;
    temp_lo_2 = (var_a3 + var_t1 - 1) / var_t1;
    var_t3 = (temp_t7 - temp_t0 + var_t1 - 1) / var_t1;
    temp_a1_2 = var_t1 - ((var_a3 + var_t1 - 1) % var_t1) - 1;
    var_t4 = adxb->unk48.unk24;
    temp_lo_3 = var_t3 * var_t1;

    if (temp_lo_2 < var_t3) {
        if ((temp_t0 + temp_lo_3 - temp_a1_2) < temp_t7) {
            var_t3 += 1;
        }
    }

    if (var_a3 < var_t4) {
        var_t4 += temp_a1_2;
    }

    temp_t2 = var_t4 / var_t1;
    if (temp_lo < temp_t2) {
        temp_t2 = temp_lo;
    }
    if (temp_lo_2 < temp_t2) {
        temp_t2 = temp_lo_2;
    }
    if (var_t3 < temp_t2) {
        temp_t2 = var_t3;
    }

    if (adxb->unk48.unk8 == 2) {
        ADXB_EvokeExpandSte(adxb, temp_t2);
    } else {
        ADXB_EvokeExpandMono(adxb, temp_t2);
    }
}

void memcpy2(void *dest, const void *src, s32 count) {
    u16 *out;
    const u16 *in;

    out = dest;
    in = src;
    while (count > 0) {
        *out++ = *in++;
        count -= 1;
    }
}

void ADXB_CopyExtraBufSte(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    memcpy2(arg0, (u8 *)arg0 + (arg1 * 2), arg3);
    memcpy2((u8 *)arg0 + (arg2 * 2), (u8 *)arg0 + ((arg2 + arg1) * 2), arg3);
}

void ADXB_EndDecode(ADXB adxb) {
    s32 s1;
    s32 s2;
    s32 sp0;
    s32 s3;
    s32 s0;
    s32 remainder;
    s32 s7;
    s32 s4;
    s32 v0;
    s32 temp_div;

    s3 = adxb->unk48.unkC;
    s1 = adxb->unk48.unk10;
    s4 = adxb->unk48.unk20;
    sp0 = adxb->unk44;
    s7 = adxb->unk40;
    temp_div = adxb->unk48.unk28 + s1 - 1;
    s0 = temp_div % s1;
    remainder = s1 - s0 - 1;
    s2 = temp_div / s1;
    v0 = ADXB_GetBlkSmpl(adxb->adxpd);
    s1 = (v0 * s1) / adxb->unk48.unk8;
    s2 = s2 * adxb->unk48.unk8;
    s3 = v0 * s3;
    adxb->dec_num_sample = (v0 < s2) ? s1 : s1 - remainder;
    s4 += adxb->dec_num_sample;
    adxb->dec_data_len = s3;

    if (s4 >= s7) {
        s4 -= s7;
        if (adxb->unk48.unk8 == 2) {
            ADXB_CopyExtraBufSte(adxb->unk48.unk14, s7, sp0, s4);
        } else {
            ADXB_CopyExtraBufMono(adxb->unk48.unk14, s7, sp0, s4);
        }
    }
}

void ADXB_ExecOneAdx(ADXB adxb) {
    if (adxb->stat == 1) {
        if (ADXPD_GetStat(adxb->adxpd) == 0) {
            adxb->get_wr(adxb->object, &adxb->unk48.unk20, &adxb->unk48.unk24, &adxb->unk48.unk28);
            ADXB_EvokeDecode(adxb);
            adxb->stat = 2;
        }
    }

    if (adxb->stat == 2) {
        ADXPD_ExecHndl(adxb->adxpd);
        if (ADXPD_GetStat(adxb->adxpd) == 3) {
            ADXB_EndDecode(adxb);
            ADXPD_Reset(adxb->adxpd);
            adxb->add_wr(adxb->unk84, adxb->dec_data_len, adxb->dec_num_sample);
            adxb->stat = 3;
        }
    }
}

void ADXB_ExecHndl(ADXB adxb) {
    if (adxb->format == 0) {
        ADXB_ExecOneAdx(adxb);
    } else if (adxb->format == 0xA) {
        ADXB_ExecOneAhx(adxb);
    } else if (adxb->format == 2) {
        sub_001751C0(adxb);
    } else if (adxb->format == 3) {
        ADXB_ExecOneAiff(adxb);
    } else if (adxb->format == 4) {
        ADXB_ExecOneAu(adxb);
    } else if (adxb->format == 1) {
        ADXB_ExecOneWav(adxb);
    } else if (adxb->format == 0x14) {
        ADXB_ExecOneAc3(adxb);
    }
}

void ADXB_Init(void) {
    ADXPD_Init();
    SKG_Init();
    memset(&adxb_obj, 0, sizeof(adxb_obj));
}

ADXB ADXB_Create(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    ADXB adxb;
    s32 i;

    for (i = 0; i < ADXB_MAX_OBJ; i++) {
        if (adxb_obj[i].unk0 == 0) {
            break;
        }
    }

    if (i == ADXB_MAX_OBJ) {
        return NULL;
    }

    adxb = &adxb_obj[i];
    memset(adxb, 0, sizeof(*adxb));
    adxb->unk0 = 1;
    adxb->adxpd = ADXPD_Create();

    if (adxb->adxpd == NULL) {
        ADXB_Destroy(adxb);
        return NULL;
    }

    adxb->unk38 = arg0;
    adxb->unk3C = arg1;
    adxb->unk40 = arg2;
    adxb->unk44 = arg3;
    adxb->unkDE[0] = -0x80;
    adxb->unkDE[1] = -0x80;
    adxb->get_wr = adxb_DefGetWr;
    adxb->object = adxb;
    adxb->add_wr = adxb_DefAddWr;
    adxb->unk84 = (s32)adxb;
    adxb->unkC8 = 0;
    adxb->unkDC = 0;
    memset(&adxb->unkCC, 0, sizeof(adxb->unkCC));
    return adxb;
}

s32 ADXB_DecodeHeaderAdx(ADXB adxb, void *header, s32 len) {
    s16 sp10[2];
    s16 sp20[2];
    s16 sp30;
    s16 sp32;
    s16 sp34;
    s16 sp36;
    s16 audio_offset;
    s8 version;
    s8 flags;
    s16 sp44;
    s16 sp46;
    s16 sp48;

    adxb->unk2 = 1;

    if (ADX_DecodeInfo(header, len, &audio_offset, &adxb->encoding_type, &adxb->sample_bitdepth, &adxb->block_size,
                       &adxb->channel_count, &adxb->sample_rate, &adxb->total_samples, &adxb->samples_per_block) < 0) {
        return 0;
    }

    if (adxb->encoding_type >= 5) {
        if (adxb->unkB0 == 0) {
            ADXERR_CallErrFunc2("E1060101 ADXB_DecodeHeaderAdx: ", "can't play AHX data by this handle");
            return -1;
        }

        adxb->sample_bitdepth = 8;
        adxb->block_size = (s8)(adxb->channel_count * 0xC0);
        adxb->samples_per_block = 0x60;
        adxb->format = 0xA;
        adxb->unk1C = 0;
        adxb->unk24 = 0;
        adxb->unk26 = 0;
        adxb->unk20 = 0;
        adxb->unk28 = 0;
        adxb->unk2C = 0;
        adxb->unk30 = 0;
        adxb->unk34 = 0;
        adxb->unk88 = 0;

        if (ADX_DecodeInfoExVer(header, len, &version, &flags) < 0) {
            return 0;
        }

        sp30 = 0;

        if (adxb_get_key(adxb, (u8)version, (u8)flags, adxb->total_samples, &sp32, &sp34, &sp36) < 0) {
            return -1;
        }

        if (ahxsetextfunc != 0) {
            ahxsetextfunc(adxb->unkB0, &sp30);
        }
    } else {
        if (ADX_DecodeInfoExVer(header, len, &version, &flags) < 0) {
            return 0;
        }

        if (adxb_get_key(adxb, (u8)version, (u8)flags, adxb->total_samples, &sp44, &sp46, &sp48) < 0) {
            return -1;
        }

        ADXPD_SetExtPrm(adxb->adxpd, sp44, sp46, sp48);

        if (ADX_DecodeInfoExADPCM2(header, len, &adxb->unk1C) < 0) {
            return 0;
        }

        if (ADX_DecodeInfoExIdly(header, len, sp10, sp20) < 0) {
            return 0;
        }

        ADXPD_SetCoef(adxb->adxpd, adxb->sample_rate, adxb->unk1C);
        ADXPD_SetDly(adxb->adxpd, sp10, sp20);
        ADX_DecodeInfoExLoop(header, len, &adxb->unk20, &adxb->unk24, &adxb->unk26, &adxb->unk28, &adxb->unk2C,
                             &adxb->unk30, &adxb->unk34);
        ADX_DecodeInfoAinf(header, len, &adxb->unkC8, &adxb->unkCC, &adxb->unkDC, adxb->unkDE);
        adxb->format = 0;
    }

    adxb->unk48.unk8 = adxb->channel_count;
    adxb->unk48.unkC = adxb->block_size;
    adxb->unk48.unk10 = adxb->samples_per_block;
    adxb->unk48.unk14 = adxb->unk3C;
    adxb->unk48.unk18 = adxb->unk40;
    adxb->unk48.unk1C = adxb->unk44;
    adxb->unk8C = 0;

    return audio_offset;
}

s32 ADXB_DecodeHeader(ADXB adxb, void *header, s32 len) {
    u8 *bytes = header;
    u16 magic;

    magic = (u16)((bytes[0] << 8) | bytes[1]);

    if (magic == 0x8000) {
        return ADXB_DecodeHeaderAdx(adxb, header, len);
    }

    if (ADXB_CheckSpsd(header) != 0) {
        return ADXB_DecodeHeaderSpsd(adxb, header, len);
    }

    if (ADXB_CheckWav(header) != 0) {
        return ADXB_DecodeHeaderWav(adxb, header, len);
    }

    if (ADXB_CheckAiff(header) != 0) {
        return ADXB_DecodeHeaderAiff(adxb, header, len);
    }

    if (ADXB_CheckAu(header) != 0) {
        return ADXB_DecodeHeaderAu(adxb, header, len);
    }

    return ADXB_DecodeHeaderAc3(adxb, header, len);
}

void ADXB_SetAc3InSj(ADXB adxb, void *sj) {
    s32 unkBC = adxb->unkBC;

    if (unkBC != 0) {
        ac3setsjifunc(unkBC, sj);
    }
}

void ADXB_SetAc3DecSmpl(ADXB adxb, s32 samples) {
    adxb->ac3_dec_samples = samples;
    adxb->ac3_dec_frames = samples / 2048;
}

void ADXB_Ac3TermSupply(ADXB adxb) {
    if (adxb->unkBC != 0) {
        ac3termsupplyfunc(adxb->unkBC);
    }
}

void ADXB_SetAhxInSj(ADXB adxb, void *sj) {
    if (adxb->unkB0 != 0) {
        ahxsetsjifunc(adxb->unkB0, sj);
    }
}

void ADXB_SetAhxDecSmpl(ADXB adxb, s32 samples) {
    if (adxb->unkB0 != 0) {
        ahxsetdecsmplfunc(adxb->unkB0, samples);
    }

    adxb->ahx_dec_samples = samples;
    adxb->ahx_dec_frames = samples / 96;
}

void ADXB_AhxTermSupply(ADXB adxb) {
    if (adxb->unkB0 != 0) {
        ahxtermsupplyfunc(adxb->unkB0);
    }
}


/* ADXB_GetLpStartPos 0x172D10, ADXB_GetLpStartOfst 0x172D20,
 * ADXB_GetLpEndOfst 0x172D30 (ADXB_GetLpEndPos is folded at 0x16D550),
 * ADXB_TakeSnapshot 0x172D80 and ADXB_RestoreSnapshot 0x172DC0 (the
 * ADXPD delays and extra parameters at +0xA2..+0xAF),
 * ADXB_EvokeExpandMono 0x172FF0, ADXB_CopyExtraBufMono 0x1731A0,
 * ADXB_ExecOneAc3 0x1738B0 and ADXB_ExecOneAhx 0x1739D0 (through
 * ac3execfunc at 0x7A60E8 and ahxexecfunc at 0x7A60F8), and
 * ADXB_DecodeHeaderAc3 0x1738D0. */

s32 ADXB_GetLpStartPos(ADXB adxb) {
    return adxb->unk28;
}

s32 ADXB_GetLpStartOfst(ADXB adxb) {
    if (adxb == 0) {
        return 0;
    }

    return adxb->unk2C;
}

s32 ADXB_GetLpEndOfst(ADXB adxb) {
    return adxb->unk34;
}

void ADXB_TakeSnapshot(ADXB adxb) {
    ADXPD_GetDly(adxb->adxpd, adxb->unkA8, adxb->unkAC);
    ADXPD_GetExtPrm(adxb->adxpd, &adxb->unkA2, &adxb->unkA4, &adxb->unkA6);
}

void ADXB_RestoreSnapshot(ADXB adxb) {
    ADXPD_SetDly(adxb->adxpd, adxb->unkA8, adxb->unkAC);
    ADXPD_SetExtPrm(adxb->adxpd, adxb->unkA2, adxb->unkA4, adxb->unkA6);
}

void ADXB_EvokeExpandMono(ADXB adxb, s32 nblk) {
    void *adxpd = adxb->adxpd;

    ADXPD_EntryMono(adxpd, adxb->unk48.unk0, nblk, (s32)((u8 *)adxb->unk48.unk14 + adxb->unk48.unk20 * 2), 0);
    ADXPD_Start(adxpd);
}

void ADXB_CopyExtraBufMono(void *buf, s32 arg1, s32 arg2, s32 arg3) {
    (void)arg2;
    memcpy2(buf, (u8 *)buf + arg1 * 2, arg3);
}

void ADXB_ExecOneAc3(ADXB adxb) {
    if (adxb->unkBC != 0) {
        ac3execfunc(adxb);
    }
}

s32 ADXB_DecodeHeaderAc3(ADXB adxb, void *header, s32 len) {
    (void)header;
    (void)len;

    if (adxb->unkBC == 0) {
        return 0;
    }

    adxb->samples_per_block = 0x1000;
    adxb->unk48.unk10 = 0x1000;
    adxb->unk48.unk14 = adxb->unk3C;
    adxb->unk48.unk18 = adxb->unk40;
    adxb->unk2 = 1;
    adxb->sample_rate = 0xAC44;
    adxb->channel_count = 2;
    adxb->sample_bitdepth = 0x10;
    adxb->total_samples = 0x7FFFFFFF;
    adxb->block_size = 0x7F;
    adxb->format = 0x14;
    adxb->unk48.unk8 = adxb->channel_count;
    adxb->unk48.unkC = adxb->block_size;
    adxb->unk48.unk1C = adxb->unk44;
    adxb->unk8C = 0;
    adxb->unk1C = 0;
    adxb->unk24 = 0;
    adxb->unk26 = 0;
    adxb->unk20 = 0;
    adxb->unk28 = 0;
    adxb->unk2C = 0;
    adxb->unk30 = 0;
    adxb->unk34 = 0;
    adxb->unk88 = 0;
    return 1;
}

void ADXB_ExecOneAhx(ADXB adxb) {
    (void)adxb;
    ahxexecfunc();
}

/* ADXB_GetLpEndPos 0x16D550, a shared getter body (+0x30). */
s32 ADXB_GetLpEndPos(ADXB adxb) {
    return adxb->unk30;
}
