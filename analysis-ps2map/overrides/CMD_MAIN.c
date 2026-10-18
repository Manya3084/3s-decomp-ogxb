/* Rewritten to match retail (tools/permute.py): make_red_blocking_time parameter 1: s16 -> s32; make_red_blocking_time parameter 2: s16 -> s32. */
void cmd_data_set(PLW* /* unused */, s16 i) {
    u8* ptr3;
    u16* ptr4;

    wcp[cmd_id].reset[i] = *cmd_tbl_ptr++;
    waza_work[cmd_id][i].w_dead = *cmd_tbl_ptr++;
    waza_work[cmd_id][i].w_dead2 = *cmd_tbl_ptr++;

    ptr3 = &wcp[cmd_id].waza_r[i][0];
    *ptr3++ = (s8)*cmd_tbl_ptr++;
    *ptr3++ = (s8)*cmd_tbl_ptr++;
    *ptr3++ = (s8)*cmd_tbl_ptr++;
    *ptr3++ = (s8)*cmd_tbl_ptr++;

    wcp[cmd_id].btix[i] = *cmd_tbl_ptr++;

    ptr4 = &wcp[cmd_id].exdt[i][0];
    *ptr4++ = *cmd_tbl_ptr++;
    *ptr4++ = *cmd_tbl_ptr++;
    *ptr4++ = *cmd_tbl_ptr++;
    *ptr4++ = *cmd_tbl_ptr++;

    switch (i) {
    case 3:
    case 4:
    case 5:
        wcp[cmd_id].reset[i] += blok_b_omake[omop_b_block_ix[cmd_id]];
        make_red_blocking_time(cmd_id, i, wcp[cmd_id].reset[i]);
        break;

    case 6:
    case 12:
        wcp[cmd_id].reset[i] += blok_b_omake[omop_b_block_ix[cmd_id]];
        break;
    }
}
