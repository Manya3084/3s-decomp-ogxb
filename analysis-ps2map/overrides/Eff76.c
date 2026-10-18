/* Notes from the hand port this file replaced:
 * Country is the byte at 0x7A8748. The character test is the dword 14.
 * A character of 20 with the same country test is a different function.
 */

s32 chkNameAkuma(s32 plnum, s32 rnum) {
    if (plnum == 14 && (Country == 4 || Country == 2 || Country == 3)) {
        return rnum;
    }

    return 0;
}

/* The Xbox has no case 0x30 (its Check_Pos_OBJ call). */
void effect_76_move(WORK_Other* ewk) {
    EFF76_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag == 0) {
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;

    switch (ewk->wu.dir_old) {
    case 0x38:
    case 0x42:
        sort_push_requestA(&ewk->wu);
        break;

    default:
        sort_push_request4(&ewk->wu);
        break;
    }
}

/* Xbox-only functions of this object (analysis-ps2map/xbgen.py checked each). */
void xb_effect_76_draw(WORK_Other* ewk) {
    if (ewk->wu.be_flag == 0) {
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;

    switch (ewk->wu.dir_old) {
    case 0x38:
    case 0x42:
        sort_push_requestA(&ewk->wu);
        break;

    default:
        sort_push_request4(&ewk->wu);
        break;
    }
}
