/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
extern u8 Game_pause;
void effE8_trans(WORK_Other* ewk, PLW* mwk);
void effe8_zanzou_process(WORK_Other* ewk, PLW* mwk);
extern void (*const D_0024D368[17])();

void xb_effect_E8_draw(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        effe8_zanzou_process(ewk, mwk);
        effE8_trans(ewk, mwk);
        break;

    case 1:
        if (ewk->wu.dead_f == 1) {
            break;
        }

        if (Game_pause == 0x81) {
            effE8_trans(ewk, mwk);
            break;
        }

        switch (ewk->wu.routine_no[1]) {
        case 0:
            effe8_zanzou_process(ewk, mwk);
            effE8_trans(ewk, mwk);
            break;

        default:
            if (ewk->wu.type > 0) {
                effe8_zanzou_process(ewk, mwk);
                effE8_trans(ewk, mwk);
            }

            break;
        }

        break;
    }
}
