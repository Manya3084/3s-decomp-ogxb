extern s8 D_007AA5F1;

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
