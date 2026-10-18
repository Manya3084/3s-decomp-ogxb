/* Xbox sound-bank release (also called from init_trans_color_ram). */
void xb_PurgeListEntry(s32 bank);

/* Xbox: after the purge, list entries 3 and 4 also release sound banks 1
   and 2. */
void Purge_memory_of_list(s16 ix) {
    s16 i;

    for (i = 0; i < 32; i++) {
        if (pmo_list[ix][i]) {
            Purge_memory_of_kind_of_key(MM_num[i]);
        }
    }

    if (pmo_list[ix][3]) {
        xb_PurgeListEntry(1);
    }

    if (pmo_list[ix][4]) {
        xb_PurgeListEntry(2);
    }
}
