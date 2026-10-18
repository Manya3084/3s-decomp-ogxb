/* Rewritten to match retail (tools/permute.py): < 31 -> <= 30. */
s32 check_pat_status(WORK* wk) {
    if (wk->pat_status >= 14 && wk->pat_status <= 30) {
        return 1;
    }

    return 0;
}

/* Rewritten to match retail (tools/permute.py): < -2 -> <= -3. */
void same_dm_stop(WORK* as, WORK* ds) {
    if (as->work_id == 1 && as->att.dipsw & 1 && (ds->xyz[1].disp.pos > 0 || (ds->vital_new - ds->dm_vital) <= -3)) {
        switch ((ds->dm_stop < 0) + ((as->att.hs_me < 0) * 2)) {
        case 1:
            ds->dm_stop = -as->att.hs_me;
            /* fallthrough */

        case 2:
            ds->dm_stop = -as->att.hs_me;
            break;

        default:
            ds->dm_stop = as->att.hs_me;
            break;
        }
    }
}

/* Rewritten to match retail (tools/permute.py): < 31 -> <= 30. */
void set_paring_status(PLW* as, PLW* ds) {
    s16 hsadix;

    if ((as->wu.att.hs_you == 0) && (as->wu.att.hs_me == 0)) {
        ds->wu.routine_no[2] = ds->wu.old_rno[2];
    } else {
        hsadix = 4;
        if ((as->wu.kind_of_waza & 0xF8) == 0) {
            hsadix = (as->wu.kind_of_waza / 2) & 3;
        }
        ds->wu.routine_no[1] = 0;
        ds->wu.routine_no[3] = 0;
        waza_compel_all_init2(ds);
        dm_status_copy(&as->wu, &ds->wu);
        ds->wu.dm_piyo = 0;
        ds->wu.cg_type = 0;

        switch ((as->wu.xyz[1].disp.pos > 0) + (ds->wu.routine_no[2] - 31) * 2) {
        case 0:
        case 2:
        case 4:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = sel_hs_add_tbl[hsadix] + 16;
            as->wu.hit_quake = sel_hs_add_tbl[hsadix] + 16;
            break;

        case 1:
        case 3:
        case 5:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;

        case 6:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;

        case 7:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;

        case 8:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;

        case 9:
            ds->wu.dm_stop = -15;
            as->wu.hit_stop = 16;
            as->wu.hit_quake = 16;
            break;

        default:
            ds->wu.dm_stop = 0;
            as->wu.hit_stop = 0;
            as->wu.hit_quake = 0;
            break;
        }

        ds->wu.dm_quake = 0;

        if (ds->wu.xyz[1].disp.pos < 0) {
            ds->wu.xyz[1].cal = 0;
        }

        ds->wu.dm_arts_point = 0;

        if (as->wu.pat_status >= 0xE && as->wu.pat_status <= 30 && as->wu.work_id == 1 &&
            sel_sp_ch_tbl[as->wu.kind_of_waza >> 3] == 0) {
            remake_mvxy_PoGR(&as->wu);
        }

        if (Bonus_Game_Flag == 0 && ds->spmv_ng_flag & 0x80) {
            paring_bonus_r[ds->wu.id] = 1;
            paring_ctr_vs[Play_Type][ds->wu.id]++;

            if (paring_ctr_vs[Play_Type][ds->wu.id] > 39) {
                paring_ctr_vs[Play_Type][ds->wu.id] = 39;
            }

            paring_counter[ds->wu.id] = parisucc_pts[Play_Type][paring_ctr_vs[Play_Type][ds->wu.id] - 1];
        }

        as->wu.cmwk[8]++;
    }

    hit_pattern_extdat_check(&as->wu);
}
