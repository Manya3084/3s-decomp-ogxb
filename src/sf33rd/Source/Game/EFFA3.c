/* EFFA3.c, retail sf33rd.xbe.
 * Ported from the PS2 C (ps2.path). Each function was compared with its
 * x86 by analysis-ps2map/portcheck.py: callees, constants, field offsets,
 * and globals. Unless a note says otherwise the C is the PS2 C.
 * effect_A3_move 0x42D40 size 0x151. Read against the x86: two Xbox changes.
 * Letter_Data_A3 gets an outer index: the x86 reads
 * Letter_Data_A3[D_007AA5F1][type][ix], and the table at 0x32B720 holds two
 * 23x8 blocks, Western terms in block 0 and Japanese ones in block 1 (PARRYING
 * becomes BLOCKING in four strings). Letter_Data_A3 is 0x32B720, all 368
 * entries compared with the XBE. And zoom (1.4f or 1.2f) reaches
 * SSPutStr_Bigger truncated: the x86 converts it with _ftol, keeps the low 16
 * bits unsigned, and converts back to float, so the call gets 1.0f. The C
 * table, index, and cast are changed to match. The other constants are the
 * floats 1.4f (0x24FE24), 1.2f (0x24FE20), 1.0f (0x2190AC), and 2.0f
 * (0x2190A4).
 * effect_A3_init 0x42E91 size 0x84.
 * Data: Contents_Check_Data_A3 is 0x24FE08, 0x17 bytes compared, found by the
 * bytes.
 * Data: Letter_Data_A3: not located in the XBE, PS2 initializer kept.
 * Globals: Contents_Check_Data_A3 0x24FE08, Menu_Cursor_Y 0x7A827E,
 * Menu_Suicide 0x7A87A0, Record_Data_Tr 0x7A89BC, Training 0x7C5900, frw
 * 0xC806A0.
 */

#include "structs.h"

#define NULL 0
#define EFFECT_MAX 128

extern u8 Menu_Suicide[4];
void push_effect_work(WORK* wkhd);
extern s8 Menu_Cursor_Y[2];
extern TrainingData Training[3];
extern u8 Record_Data_Tr;
void SSPutStr_Bigger(u16 x, u16 y, u8 atr, s8* str, f32 sc, u8 gr, u16 priority);
s16 pull_effect_work(s16 index);
extern uintptr_t frw[EFFECT_MAX][448];

const u8 Contents_Check_Data_A3[23] = { 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0 };

extern s8 D_007AA5F1;

/* Xbox: [0] uses the Western terms (PARRYING), [1] the Japanese ones
 * (BLOCKING). D_007AA5F1 selects. */
s8* Letter_Data_A3[2][23][8] = {
    {
        { "NORMAL MODE", "RECORDING MODE", "REPLAY", "DUMMY SETTING", "TRAINING OPTION", "BUTTON CONFIG.", "CHARACTER CHANGE", "EXIT" },
        { "ACTION$............", "GUARD$.............", "QUICK STANDING$....", "STUN$..............", "DEFAULT SETTING", "EXIT" },
        { "STAND", "CROUCH", "JUMP", "CPU", "HUMAN" },
        { "AUTO GUARD", "NO GUARD", "ALL GUARD", "PARRYING", "RANDOM GUARD", "RANDOM PARRYING", "ALL RANDOM" },
        { "OFF", "ON", "RANDOM" },
        { "OFF", "ON" },
        { "S.A.GAUGE$.........", "ATTACK DATA$.......", "DAMAGE$............$L    $H", "DIFFICULTY$........$L        $H", "DEFAULT SETTING", "EXIT" },
        { "NORMAL", "MAX START", "INFINITY", "MAXIMUM" },
        { "OFF", "ON" },
        { "$ *", "$ **", "$ ***", "$ ****" },
        { "$ *", "$ **", "$ ***", "$ ****", "$ *****", "$ ******", "$ *******", "$ ********" },
        { "DUMMY RECORDING", "PARRYING TRAINING", "TRAINING OPTION", "BUTTON CONFIG.", "CHARACTER CHANGE", "EXIT" },
        { "STAND", "CROUCH", "JUMP" },
        { "NORMAL", "MAX START", "INFINITY" },
        { "NORMAL", "MAX START", "INFINITY" },
        { "OFF", "ON" },
        { "ACTION(PLAYER)$......", "S.A.GAUGE(DUMMY)$....", "AUTO PARRYING$.......", "S.A.GAUGE(PLAYER)$...", "DEFAULT SETTING", "EXIT" },
        { "STAND", "CROUCH", "JUMP" },
        { "NORMAL", "MAX START", "INFINITY", "MAXIMUM" },
        { "OFF", "ON" },
        { "NORMAL", "MAX START", "INFINITY", "MAXIMUM" },
        { "RECORDING", "TRAINING" },
        { "REPLAY DATA", "FINISHED$!" }
    },
    {
        { "NORMAL MODE", "RECORDING MODE", "REPLAY", "DUMMY SETTING", "TRAINING OPTION", "BUTTON CONFIG.", "CHARACTER CHANGE", "EXIT" },
        { "ACTION$............", "GUARD$.............", "QUICK STANDING$....", "STUN$..............", "DEFAULT SETTING", "EXIT" },
        { "STAND", "CROUCH", "JUMP", "CPU", "HUMAN" },
        { "AUTO GUARD", "NO GUARD", "ALL GUARD", "BLOCKING", "RANDOM GUARD", "RANDOM BLOCKING", "ALL RANDOM" },
        { "OFF", "ON", "RANDOM" },
        { "OFF", "ON" },
        { "S.A.GAUGE$.........", "ATTACK DATA$.......", "DAMAGE$............$L    $H", "DIFFICULTY$........$L        $H", "DEFAULT SETTING", "EXIT" },
        { "NORMAL", "MAX START", "INFINITY", "MAXIMUM" },
        { "OFF", "ON" },
        { "$ *", "$ **", "$ ***", "$ ****" },
        { "$ *", "$ **", "$ ***", "$ ****", "$ *****", "$ ******", "$ *******", "$ ********" },
        { "DUMMY RECORDING", "BLOCKING TRAINING", "TRAINING OPTION", "BUTTON CONFIG.", "CHARACTER CHANGE", "EXIT" },
        { "STAND", "CROUCH", "JUMP" },
        { "NORMAL", "MAX START", "INFINITY" },
        { "NORMAL", "MAX START", "INFINITY" },
        { "OFF", "ON" },
        { "ACTION(PLAYER)$......", "S.A.GAUGE(DUMMY)$....", "AUTO BLOCKING$.......", "S.A.GAUGE(PLAYER)$...", "DEFAULT SETTING", "EXIT" },
        { "STAND", "CROUCH", "JUMP" },
        { "NORMAL", "MAX START", "INFINITY", "MAXIMUM" },
        { "OFF", "ON" },
        { "NORMAL", "MAX START", "INFINITY", "MAXIMUM" },
        { "RECORDING", "TRAINING" },
        { "REPLAY DATA", "FINISHED$!" }
    }
};

void effect_A3_move(WORK_Other* ewk) {
    s16 color;
    s16 ix;
    s16 clear_level;
    f32 zoom;
    f32 prio;

    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (ewk->master_priority != Menu_Cursor_Y[0]) {
        color = 9;
    } else {
        color = 5;
    }

    if (Contents_Check_Data_A3[ewk->wu.type] == 1) {
        ix = Training[2].contents[ewk->master_id][ewk->wu.dir_step][ewk->master_priority];
    } else {
        ix = ewk->wu.cg_type;
    }

    clear_level = 0;

    if (Record_Data_Tr == 0 && ewk->wu.type == 0 && ewk->master_priority == 2) {
        clear_level = 1;
    }
    if (Record_Data_Tr == 0 && ewk->wu.type == 11 && ewk->master_priority == 1) {
        clear_level = 1;
    }

    if (Training[2].contents[0][0][0] == 3 && ewk->wu.type == 0 && ewk->master_priority == 1) {
        clear_level = 1;
    }

    if (ewk->master_priority == 99) {
        zoom = 1.4f;
        color = 10;
    } else {
        zoom = 1.2f;
    }

    if (ewk->wu.type < 22) {
        prio = 1.0f;
    } else {
        prio = 2.0f;
    }

    SSPutStr_Bigger(ewk->wu.xyz[0].disp.pos,
                    ewk->wu.xyz[1].disp.pos,
                    color,
                    Letter_Data_A3[D_007AA5F1][ewk->wu.type][ix],
                    (u16)zoom, /* Xbox: truncated, so 1.4f and 1.2f draw at 1 */
                    clear_level,
                    prio);
}

s32 effect_A3_init(s16 id, u8 Type, u8 Type_in_Type, u8 dir_step, u8 Death_Type, s16 pos_x, s16 pos_y, s16 Buff) {
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 103;
    ewk->wu.work_id = 16;
    ewk->master_id = id;
    ewk->wu.type = Type;
    ewk->master_priority = Type_in_Type;
    ewk->wu.cg_type = dir_step;
    ewk->master_player = Death_Type;
    ewk->wu.dir_step = Buff;
    ewk->wu.xyz[0].disp.pos = pos_x;
    ewk->wu.xyz[1].disp.pos = pos_y;
    return 0;
}
