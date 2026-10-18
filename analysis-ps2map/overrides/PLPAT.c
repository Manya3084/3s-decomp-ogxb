/* Rewritten to match retail (tools/permute.py): <= 0 -> < 1. */
void check_ja_nmj_dummy_RTNM(PLW* wk) {
    s32 temp_a0;
    u8 temp_v1;

    if (wk->wu.xyz[1].disp.pos < 1) {
        wk->ja_nmj_rno = 0;
        return;
    }

    switch (wk->ja_nmj_rno) {
    case 0:
        if ((wk->wu.cg_ja.atix != 0) || (wk->wu.cg_ja.caix != 0)) {
            wk->ja_nmj_rno = 1;
        }

        break;

    case 1:
        if (((wk->wu.cg_ja.atix == 0) && (wk->wu.cg_ja.caix == 0)) || !wk->wu.att_hit_ok) {
            wk->ja_nmj_cnt = get_cjdR(wk);
            wk->ja_nmj_rno = 2;
        }

        break;

    case 2:
        if (((wk->wu.cg_ja.atix != 0) || (wk->wu.cg_ja.caix != 0)) && wk->wu.att_hit_ok) {
            wk->ja_nmj_rno = 1;
            break;
        }

        if (!--wk->ja_nmj_cnt) {
            wk->ja_nmj_rno = 3;
        }

        break;

    default:
        if ((wk->wu.cg_ja.atix != 0) || (wk->wu.cg_ja.caix != 0)) {
            if (wk->wu.att_hit_ok) {
                wk->ja_nmj_rno = 1;
                break;
            }
        } else if (wk->wu.cg_type == 0) {
            wk->wu.cg_type = 64;
        }

        break;
    }
}
