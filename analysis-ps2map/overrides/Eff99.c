extern s8 D_007AA5F1;

const s8* Letter_Data_99[2][5][21] = {
    {
        { ";;;;;;;#", ";;;;;;##", ";;;;;###", ";;;;####", ";;;#####", ";;######", ";#######", "########" },
        { "#;;;;;;;", "##;;;;;;", "###;;;;;", "####;;;;", "#####;;;", "######;;", "#######;", "########" },
        { "UNKNOWN", "AMERICA", "JAPAN",  "HONG KONG", "ENGLAND", "RUSSIA", "GERMANY",
          "JAPAN",   "KENYA",   "BRAZIL", "HONG KONG", "AMERICA", "BRAZIL", "MEXICO",
          "JAPAN",   "CHINA",   "JAPAN",  "",          "RUSSIA",  "FRANCE", "RANDOM" },
        { "GILL STAGE",
          "SUBWAY STATION",
          "SUZAKU CASTLE ROOFTOP",
          "SHOPPING DISTRICT",
          "MAIN STREET",
          "MOSQUE",
          "HOME SWEET HOME",
          "A ROAD IN KYOTO",
          "SAVANNA",
          "SANTOS HARBOR",
          "SHOPPING DISTRICT",
          "SUBWAY STATION",
          "SANTOS HARBOR",
          "ORMECA RUINS",
          "KOUSYU STREET",
          "CHINESE RESTAURANT",
          "THE DOJO OF RINDO-KAN",
          "",
          "MOSQUE",
          "CLUB METRO",
          "" },
        { "",
          "ALEX STAGE",
          "RYU STAGE",
          "YUN STAGE",
          "DUDLEY STAGE",
          "NECRO STAGE",
          "HUGO STAGE",
          "IBUKI STAGE",
          "ELENA STAGE",
          "ORO STAGE",
          "YANG STAGE",
          "KEN STAGE",
          "SEAN STAGE",
          "URIEN STAGE",
          "AKUMA STAGE",
          "CHUN-LI STAGE",
          "MAKOTO STAGE",
          "",
          "TWELVE STAGE",
          "REMY STAGE",
          "" }
    },
    {
        { ";;;;;;;#", ";;;;;;##", ";;;;;###", ";;;;####", ";;;#####", ";;######", ";#######", "########" },
        { "#;;;;;;;", "##;;;;;;", "###;;;;;", "####;;;;", "#####;;;", "######;;", "#######;", "########" },
        { "UNKNOWN", "AMERICA", "JAPAN",  "HONG KONG", "ENGLAND", "RUSSIA", "GERMANY",
          "JAPAN",   "KENYA",   "BRAZIL", "HONG KONG", "AMERICA", "BRAZIL", "MEXICO",
          "JAPAN",   "CHINA",   "JAPAN",  "",          "RUSSIA",  "FRANCE", "RANDOM" },
        { "GILL STAGE",
          "SUBWAY STATION",
          "SUZAKU CASTLE ROOFTOP",
          "SHOPPING DISTRICT",
          "MAIN STREET",
          "MOSQUE",
          "HOME SWEET HOME",
          "A ROAD IN KYOTO",
          "SAVANNA",
          "SANTOS HARBOR",
          "SHOPPING DISTRICT",
          "SUBWAY STATION",
          "SANTOS HARBOR",
          "ORMECA RUINS",
          "KOUSYU STREET",
          "CHINESE RESTAURANT",
          "THE DOJO OF RINDO-KAN",
          "",
          "MOSQUE",
          "CLUB METRO",
          "" },
        { "",
          "ALEX STAGE",
          "RYU STAGE",
          "YUN STAGE",
          "DUDLEY STAGE",
          "NECRO STAGE",
          "HUGO STAGE",
          "IBUKI STAGE",
          "ELENA STAGE",
          "ORO STAGE",
          "YANG STAGE",
          "KEN STAGE",
          "SEAN STAGE",
          "URIEN STAGE",
          "GOUKI STAGE",
          "CHUN-LI STAGE",
          "MAKOTO STAGE",
          "",
          "TWELVE STAGE",
          "REMY STAGE",
          "" }
    }
};

void Setup_Letter_99(WORK_Other_CONN* ewk, s16 letter_index, s16 disp_index) {
    s16 x;
    s16 ix;
    s16 offset_x;
    u8* ptr;
    u8 space;

    if (ewk->wu.old_cgnum == 0x70A7) {
        offset_x = 8;
    } else {
        offset_x = 14;
    }

    ptr = (u8*)Letter_Data_99[D_007AA5F1][letter_index][disp_index];
    ix = 0;
    x = 0;
    space = 0;

    while (*ptr != '\0') {
        if (*ptr == ' ') {
            x += offset_x;
            ptr++;
            space++;
            continue;
        }

        ewk->conn[ix].nx = x;
        ewk->conn[ix].ny = 0;
        ewk->conn[ix].col = 0;
        ewk->conn[ix].chr = ewk->wu.old_cgnum + *ptr;
        x += offset_x;
        ptr++;
        ix++;
    }

    ewk->num_of_conn = ix;

    if (ewk->wu.type != 1) {
        return;
    }

    if (ewk->wu.old_cgnum == 0x7047) {
        x = 16;
    } else {
        x = 8;
    }

    x = x * (ix + space) / 2;

    ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + Pos_Data_99[ewk->master_priority][0] - x;
}
