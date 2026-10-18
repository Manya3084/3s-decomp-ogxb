const s8* Letter_Data_63[3][21] = { { "-10", "-9", "-8", "-7", "-6", "-5", "-4", "-3", "-2", "-1", "0",
                                      "1",   "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9",  "10" },
                                    /* Xbox: eight sizes from 86%; the PS2 build lists 94% to 100%. */
                                    { "86%", "88%", "90%", "92%", "94%", "96%", "98%", "100%", NULL, NULL, NULL,
                                      NULL,  NULL,  NULL,  NULL,   NULL, NULL, NULL, NULL, NULL, NULL },
                                    { "OFF", "ON", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                                      NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL } };

void Disp_63_Sub(WORK_Other_CONN* ewk) {
    s16 disp_index;

    switch (ewk->wu.type) {
    /* Xbox: the adjusts are kept times 4, and the sizes start at 86. */
    case 0:
        disp_index = X_Adjust / 4 + 10;
        break;

    case 1:
        disp_index = Y_Adjust / 4 + 10;
        break;

    case 2:
        disp_index = (s16)Disp_Size_H - 86;
        disp_index >>= 1;
        break;

    case 3:
        disp_index = (s16)Disp_Size_V - 86;
        disp_index >>= 1;
        break;

    default:
        disp_index = sys_w.screen_mode;
        break;
    }

    Setup_Letter_63(ewk, disp_index);
}
