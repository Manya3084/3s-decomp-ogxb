/* Ex_Letter_Data is 0x32E498 and Ex_Title_Data is 0x32F378. */

extern s8 D_007AA5F1;
extern s8* Ex_Letter_Data[2][4][7][17];

void Setup_Letter_C4(WORK_Other_CONN* ewk) {
    s16 x;
    s16 ix;
    u8* ptr;

    if (ewk->master_id) {
        ptr = (u8*)Ex_Letter_Data[D_007AA5F1][Menu_Page_Buff][ewk->wu.char_index]
                                 [save_w[1].extra_option.contents[Menu_Page_Buff][ewk->wu.type]];
    } else {
        ptr = (u8*)Ex_Title_Data[Menu_Page_Buff][ewk->wu.char_index];
    }

    ix = 0;
    x = 0;

    while (*ptr != '\0') {
        if (*ptr == ' ') {
            x += 8;
            ptr++;
            continue;
        }

        if (*ptr == '/') {
            x += 4;
            ptr++;
            continue;
        }

        if (ewk->master_id) {
            if (save_w[1].extra_option.contents[Menu_Page_Buff][ewk->wu.type] !=
                save_w[0].extra_option.contents[Menu_Page_Buff][ewk->wu.type]) {
                ewk->conn[ix].col = 0x18;
            } else {
                ewk->conn[ix].col = 0;
            }
        }

        ewk->conn[ix].nx = x;
        ewk->conn[ix].ny = 0;
        ewk->conn[ix].chr = *ptr + 0x70A7;
        x += 8;
        ptr++;
        ix++;
    }

    ewk->num_of_conn = ix;
}
