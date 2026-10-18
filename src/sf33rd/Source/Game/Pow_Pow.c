/* Pow_Pow.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * Additinal_Score_DM 0x968BB size 0x8E. Read against the x86: the unnamed
 * table is Score_Data. Score_Data is 0x264DC8. The C is the PS2 C.
 * cal_damage_vitality is folded into 0x96821 with 1 other bodies. Unnamed.
 * cal_damage_vitality_eff is folded into 0x96821 with 1 other bodies. Unnamed.
 * Globals: Play_Type 0x7A812D, Mode_Type 0x7A825A, Score 0x7A8720, plw
 * 0xC7CEA0.
 */

#include "structs.h"

extern const u16 Power_Data[256];
extern u8 Play_Type;
extern const s8 Pow_Control_Data_1[2][8];
extern s16 Round_Level;
extern u32 Score[2][3];
extern const s32 Score_Data[];
extern u8 Mode_Type;
extern PLW plw[2];



void cal_damage_vitality(PLW* as, PLW* ds) {
    u16 xx = as->wu.att.pow;
    s16 yy;
    s16 power = Power_Data[xx];

    if (Play_Type == 1) {
        yy = Pow_Control_Data_1[0][3];
    } else {
        yy = Pow_Control_Data_1[0][Round_Level];
    }

    ds->wu.dm_vital = (power * yy) / 100;

    if (as->wu.work_id == 1) {
        ds->wu.dm_vital = (ds->wu.dm_vital * as->att_plus) / 8;
    }

    if (ds->wu.work_id == 1) {
        ds->wu.dm_vital = (ds->wu.dm_vital * ds->def_plus) / 8;
    }
}

void cal_damage_vitality_eff(WORK_Other* as, PLW* ds) {
    u16 xx = as->wu.att.pow;
    s16 yy;
    s16 power = Power_Data[xx];

    if (Play_Type == 1) {
        yy = Pow_Control_Data_1[0][3];
    } else {
        yy = Pow_Control_Data_1[0][Round_Level];
    }

    ds->wu.dm_vital = (power * yy) / 100;

    if (as->wu.work_id == 1) {
        ds->wu.dm_vital = (ds->wu.dm_vital * ((PLW*)as)->att_plus) / 8;
    }

    if (ds->wu.work_id == 1) {
        ds->wu.dm_vital = (ds->wu.dm_vital * ds->def_plus) / 8;
    }
}

void Additinal_Score_DM(WORK_Other* wk, u16 ix) {
    s16 id;

    if (wk->wu.work_id == 1) {
        id = wk->wu.id;
    } else {
        if (((WORK*)wk->my_master)->work_id != 1) {
            return;
        }

        id = wk->master_id;
    }

    Score[id][2] += Score_Data[ix];

    if (Score[id][2] >= 99999900) {
        Score[id][2] = 99999900;
    }

    if ((Mode_Type != 1) && (Mode_Type != 5)) {
        if (!plw[id].wu.operator) {
            return;
        }

        Score[id][Play_Type] += Score_Data[ix];

        if (Score[id][Play_Type] >= 99999900) {
            Score[id][Play_Type] = 99999900;
        }
    } else {
        Score[id][Play_Type] += Score_Data[ix];

        if (Score[id][Play_Type] >= 99999900) {
            Score[id][Play_Type] = 99999900;
        }
    }
}
