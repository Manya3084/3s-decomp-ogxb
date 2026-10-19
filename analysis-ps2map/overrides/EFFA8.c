/* Xbox-only: sets the 2D scale and origin for a button image
   (njScale(NULL, 1.6667, -2.0, 1.0) and a reset translation). */
void xb_SetButtonImageScale(void);

/* Xbox: the button images are set up by xb_SetButtonImageScale and drawn at 18x14,
   two pixels further right and one or two higher (PS2 22x17). */
void effect_A8_move(WORK_Other_CONN* ewk) {
    s16 ix;

    if (Menu_Suicide[ewk->master_player]) {
        push_effect_work(&ewk->wu);
        return;
    }

    if (Menu_Cursor_Y[0] == ewk->wu.type) {
        ewk->wu.disp_flag = 1;
    } else {
        ewk->wu.disp_flag = 0;
    }

    switch (ewk->master_id) {
    case 2:
        ewk->wu.my_clear_level = Flash_Synchro;
        Setup_A8_Sub(ewk);
        ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Pos_Data_A8[ewk->wu.dir_step][0];
        ix = ewk->num_of_conn - 1;
        ix = ewk->conn[ix].nx;
        ewk->wu.position_x -= ix / 2;
        sort_push_request3(&ewk->wu);
        break;

    case 0:
        Setup_A8_Sub(ewk);
        sort_push_request3(&ewk->wu);

        if (ewk->wu.disp_flag) {
            xb_SetButtonImageScale();

            if (Order_Dir[ewk->wu.dir_old]) {
                dispButtonImage(-85, 24, 68, 18, 14, 0, 4);
            } else {
                dispButtonImage(-21, -2, 68, 18, 14, 0, 5);
            }
        }

        break;

    case 3:
        sort_push_requestA(&ewk->wu);
        break;
    }
}

/* Xbox: Japanese copies of the track lists, which name Akuma's stage
   "Gouki Stage". */
const s8* Letter_Data_A8DC_jp[69] = { "-PLAY(  )",
                                   " STOP(  ) BUTTON-",
                                   "1. Alex & Ken Stage -JAZZY NYC '99 mix1-",
                                   "2. Alex & Ken Stage -JAZZY NYC '99 mix2-",
                                   "3. Alex & Ken Stage -JAZZY NYC '99 mix3-",
                                   "4. Necro & Twelve Stage -SNOWLAND mix1-",
                                   "5. Necro & Twelve Stage -SNOWLAND mix2-",
                                   "6. Necro & Twelve Stage -SNOWLAND mix3-",
                                   "7. Hugo Stage -THE CIRCUIT mix1-",
                                   "8. Hugo Stage -THE CIRCUIT mix2-",
                                   "9. Hugo Stage -THE CIRCUIT mix3-",
                                   "10. Chun-Li Stage -CHINA VOX mix1-",
                                   "11. Chun-Li Stage -CHINA VOX mix2-",
                                   "12. Chun-Li Stage -CHINA VOX mix3-",
                                   "13. Ryu Stage -KOBU mix1-",
                                   "14. Ryu Stage -KOBU mix2-",
                                   "15. Ryu Stage -KOBU mix3-",
                                   "16. Ibuki Stage -TWILIGHT mix1-",
                                   "17. Ibuki Stage -TWILIGHT mix2-",
                                   "18. Ibuki Stage -TWILIGHT mix3-",
                                   "19. Makoto Stage -SPUNKY mix1-",
                                   "20. Makoto Stage -SPUNKY mix2-",
                                   "21. Makoto Stage -SPUNKY mix3-",
                                   "22. Gouki Stage -KILLING MOON mix1-",
                                   "23. Gouki Stage -KILLING MOON mix2-",
                                   "24. Gouki Stage -KILLING MOON mix3-",
                                   "25. Elena Stage -BEATS IN MY HEAD mix1-",
                                   "26. Elena Stage -BEATS IN MY HEAD mix2-",
                                   "27. Elena Stage -BEATS IN MY HEAD mix3-",
                                   "28. Sean & Oro Stage -THE LONGSHOREMAN mix1-",
                                   "29. Sean & Oro Stage -THE LONGSHOREMAN mix2-",
                                   "30. Sean & Oro Stage -THE LONGSHOREMAN mix3-",
                                   "31. Dudley Stage -YOU BLOW MY MIND mix1-",
                                   "32. Dudley Stage -YOU BLOW MY MIND mix2-",
                                   "33. Dudley Stage -YOU BLOW MY MIND mix3-",
                                   "34. Yun & Yang Stage -CROWDED STREET mix1-",
                                   "35. Yun & Yang Stage -CROWDED STREET mix2-",
                                   "36. Yun & Yang Stage -CROWDED STREET mix3-",
                                   "37. Remy Stage -THE BEEP mix1-",
                                   "38. Remy Stage -THE BEEP mix2-",
                                   "39. Remy Stage -THE BEEP mix3-",
                                   "40. The Theme Of Q -Q mix1-",
                                   "41. The Theme Of Q -Q mix2-",
                                   "42. The Theme Of Q -Q mix3-",
                                   "43. Urien Stage -CRAZY CHILI DOG mix1-",
                                   "44. Urien Stage -CRAZY CHILI DOG mix2-",
                                   "45. Urien Stage -CRAZY CHILI DOG mix3-",
                                   "46. Gill Stage -PSYCH OUT mix1-",
                                   "47. Gill Stage -PSYCH OUT mix2-",
                                   "48. Gill Stage -PSYCH OUT mix3-",
                                   "49. Ending1",
                                   "50. Ending2",
                                   "51. Just Before The Battle",
                                   "52. Opening Demo -THIRD STRIKE OPENING MIX-",
                                   "53. Player Select -LET'S GET IT ON(ARCADE)-",
                                   "54. Final Results",
                                   "55. Stage Results",
                                   "56. Judgement",
                                   "57. Stage Select & Score Ranking",
                                   "58. Continue",
                                   "59. We Await Your Return,Warrior!",
                                   "60. Gill Appears!",
                                   "61. Bonus Game 1",
                                   "62. Bonus Game 2",
                                   "63. Staff Roll -Moving On-",
                                   "64. Staff Roll -THIRD STRIKE REMIX-",
                                   "65. Menu -THIRD STRIKE-",
                                   "66. Player Select -LET'S GET IT ON(VERSUS)-",
                                   "67. Capcom Logo" };

const s8* Letter_Data_A8AC_jp[69] = { "-PLAY(  )",
                                   " STOP(  ) BUTTON-",
                                   "1. Alex & Ken Stage -JAZZY NYC '99 1-",
                                   "2. Alex & Ken Stage -JAZZY NYC '99 2-",
                                   "-. ",
                                   "3. Necro & Twelve Stage -SNOWLAND 1-",
                                   "4. Necro & Twelve Stage -SNOWLAND 2-",
                                   "-. ",
                                   "5. Hugo Stage -THE CIRCUIT 1-",
                                   "6. Hugo Stage -THE CIRCUIT 2-",
                                   "-. ",
                                   "7. Chun-Li Stage -CHINA VOX 1-",
                                   "8. Chun-Li Stage -CHINA VOX 2-",
                                   "-. ",
                                   "9. Ryu Stage -KOBU 1-",
                                   "10. Ryu Stage -KOBU 2-",
                                   "-. ",
                                   "11. Ibuki Stage -TWILIGHT 1-",
                                   "12. Ibuki Stage -TWILIGHT 2-",
                                   "-. ",
                                   "13. Makoto Stage -SPUNKY 1-",
                                   "14. Makoto Stage -SPUNKY 2-",
                                   "-. ",
                                   "15. Gouki Stage -KILLING MOON 1-",
                                   "16. Gouki Stage -KILLING MOON 2-",
                                   "-. ",
                                   "17. Elena Stage -BEATS IN MY HEAD 1-",
                                   "18. Elena Stage -BEATS IN MY HEAD 2-",
                                   "-. ",
                                   "19. Sean & Oro Stage -THE LONGSHOREMAN 1-",
                                   "20. Sean & Oro Stage -THE LONGSHOREMAN 2-",
                                   "-. ",
                                   "21. Dudley Stage -YOU BLOW MY MIND 1-",
                                   "22. Dudley Stage -YOU BLOW MY MIND 2-",
                                   "-. ",
                                   "23. Yun & Yang Stage -CROWDED STREET 1-",
                                   "24. Yun & Yang Stage -CROWDED STREET 2-",
                                   "-. ",
                                   "25. Remy Stage -THE BEEP 1-",
                                   "26. Remy Stage -THE BEEP 2-",
                                   "-. ",
                                   "27. The Theme Of Q -Q 1-",
                                   "28. The Theme Of Q -Q 2-",
                                   "-. ",
                                   "29. Urien Stage -CRAZY CHILI DOG 1-",
                                   "30. Urien Stage -CRAZY CHILI DOG 2-",
                                   "-. ",
                                   "31. Gill Stage -PSYCH OUT 1-",
                                   "32. Gill Stage -PSYCH OUT 2-",
                                   "-. ",
                                   "33. Ending1",
                                   "34. Ending2",
                                   "35. Just Before The Battle",
                                   "36. Opening Demo -THIRD STRIKE OPENING MIX-",
                                   "37. Player Select -LET'S GET IT ON(ARCADE)-",
                                   "38. Final Results",
                                   "39. Stage Results",
                                   "40. Judgement",
                                   "41. Stage Select & Score Ranking",
                                   "42. Continue",
                                   "43. We Await Your Return,Warrior!",
                                   "44. Gill Appears!",
                                   "45. Bonus Game 1",
                                   "46. Bonus Game 2",
                                   "47. Staff Roll -Moving On-",
                                   "48. Staff Roll -THIRD STRIKE REMIX-",
                                   "49. Menu -THIRD STRIKE-",
                                   "50. Player Select -LET'S GET IT ON(VERSUS)-",
                                   "51. Capcom Logo" };

/* Xbox: the track lists by language (mpp_w.language), then BGM type. */
const s8** Letter_Data_A8[2][2] = { { Letter_Data_A8DC, Letter_Data_A8AC }, { Letter_Data_A8DC_jp, Letter_Data_A8AC_jp } };

/* Xbox: the list also depends on the language. */
void Setup_A8_Sub(WORK_Other_CONN* ewk) {
    s16 x;
    s16 ix;
    s16 offset_x;
    u8* ptr;

    if (ewk->wu.old_cgnum == 0x70A7) {
        offset_x = 8;
    } else {
        offset_x = 14;
    }

    ptr = (u8*)Letter_Data_A8[mpp_w.language][sys_w.bgm_type][Order_Dir[ewk->wu.dir_old] + ewk->master_id];
    ix = 0;
    x = 0;

    while (*ptr != '\0') {
        if (*ptr == ' ') {
            x += offset_x;
            ptr++;
            continue;
        }

        ewk->conn[ix].nx = x;
        ewk->conn[ix].ny = 0;
        ewk->conn[ix].col = 0;
        ewk->conn[ix].chr = ewk->wu.old_cgnum + *ptr;
        x += offset_x;
        ptr += 1;
        ix++;
    }

    ewk->num_of_conn = ix;
}
