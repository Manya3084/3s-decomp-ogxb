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

/* Rewritten to match retail (tools/permute.py): remake_score_index parameter 1: s16 -> s32. */
void set_damage_and_piyo(PLW* as, PLW* ds) {
    sub_00096821(as, ds);
    ds->wu.dm_piyo = _add_piyo_gauge[as->player_number][as->wu.att.piyo];
    ds->wu.dm_piyo = ds->wu.dm_piyo * stun_gauge_omake[omop_stun_gauge_add[(ds->wu.id + 1) & 1]] / 32;

    if ((ds->wu.pat_status == 32 || ds->wu.pat_status == 3) || ds->wu.pat_status == 25) {
        ds->wu.dm_vital = (ds->wu.dm_vital * 125) / 100;
    } else if (ds->wu.pat_status == 7 || ds->wu.pat_status == 23 || ds->wu.pat_status == 35) {
        ds->wu.dm_vital = (ds->wu.dm_vital * 150) / 100;
    } else if (ds->wu.pat_status == 1 || ds->wu.pat_status == 21 || ds->wu.pat_status == 37) {
        ds->wu.dm_vital *= 2;
    }

    if (ds->wu.dm_vital) {
        if (as->wu.routine_no[1] == 2) {
            ds->wu.dm_vital = (ds->wu.dm_vital) * (as->tk_nage + 32) / 32;

            if ((as->tk_nage -= 2) < 0) {
                as->tk_nage = 0;
            }
        }

        if (as->wu.routine_no[1] == 4) {
            ds->wu.dm_vital = (ds->wu.dm_vital) * (as->tk_dageki + 32) / 32;

            if ((as->tk_dageki -= 2) < 0) {
                as->tk_dageki = 0;
            }
        }

        ds->utk_nage = as->tk_nage;
        ds->utk_dageki = as->tk_dageki;
    }

    if (ds->wu.dm_piyo) {
        ds->wu.dm_piyo = ds->wu.dm_piyo * (as->tk_kizetsu + 32) / 32;

        if ((as->tk_kizetsu -= 2) < 0) {
            as->tk_kizetsu = 0;
        }

        ds->utk_kizetsu = as->tk_kizetsu;
    }

    as->wu.at_ten_ix = remake_score_index(ds->wu.dm_vital);
    cal_combo_waribiki(as, ds);
    cal_dm_vital_gauge_hosei(ds);
    cal_combo_waribiki2(ds);

    if (as->wu.work_id != 1) {
        return;
    }

    switch (as->dm_vital_use) {
    case 1:
        ds->wu.dm_vital += as->dm_vital_backup;
        as->dm_vital_backup = 0;
        break;

    case 2:
        as->dm_vital_backup /= 2;
        ds->wu.dm_vital += as->dm_vital_backup;
        break;
    }
}

/* Rewritten to match retail (tools/permute.py): >= 8 -> > 7. */
void attack_hit_check() {
    WORK* mad;
    WORK* sad;
    s16* mh;
    s16* sh;
    s16 mi;
    s16 si;
    s16 lp;
    s16 lp2;
    s16 mw;

    s16* assign1;
    s16* assign2;

    for (si = 0; si < hpq_in; si++) {
        if (hs[si].flag.results & 0x1101) {
            continue;
        }

        sad = q_hit_push[si];
        sh = sad->h_bod->body_dm[0];
        mh = sad->h_han->hand_dm[0];

        for (lp = 0; lp < 4; lp++, sh += 4, assign1 = mh += 4) {
            dmdat_adrs[lp] = sh;
            dmdat_adrs[lp + 4] = mh;
        }

        dmdat_adrs[8] = &sad->h_att->att_box[2][0];
        dmdat_adrs[9] = &sad->h_att->att_box[3][0];
        dmdat_adrs[10] = &sad->h_hos->hos_box[0];

        for (mi = 0; mi < hpq_in; mi++) {
            if (mi == si) {
                continue;
            }
            if (hs[mi].flag.results & 0x1110) {
                continue;
            }

            mad = q_hit_push[mi];
            if (mad->cg_ja.atix == 0) {
                continue;
            }
            if (mad->att_hit_ok == 0) {
                continue;
            }

            if (!(mad->att.dipsw & 2) ||
                (!(sad->att.dipsw & 2) && (sad->work_id == 1 || !(((WORK_Other*)sad)->refrected)))) {
                if ((mad->work_id != 1 && mad->work_id != 8) || !(sad->att.dipsw & 2)) {
                    if (!(mad->vs_id & sad->work_id)) {
                        continue;
                    }
                }
            }

            if (mad->work_id != 1) {
                if (sad->work_id == 1) {
                    if (((WORK_Other*)mad)->master_id == sad->id) {
                        continue;
                    }
                } else if (((WORK_Other*)mad)->master_id == ((WORK_Other*)sad)->master_id) {
                    continue;
                }
            } else if ((sad->work_id != 1 && ((WORK_Other*)sad)->refrected == 0) &&
                       (mad->id == ((WORK_Other*)sad)->master_id)) {
                continue;
            }

            mh = &mad->h_att->att_box[0][0];

            for (lp = 0; lp < 4; lp++, assign2 = mh += 4) {
                if (mh[1] == 0) {
                    continue;
                }

                for (lp2 = 0; lp2 < 11; lp2++) {
                    if (lp2 > 3 && mad->att_hit_ok == 0) {
                        goto end;
                    }

                    if (dmdat_adrs[lp2][1] == 0) {
                        continue;
                    }

                    if ((lp == 2 || lp == 3) && (lp2 == 8 || lp2 == 9)) {
                        continue;
                    }

                    if ((lp2 > 3) && (lp2 < 0xA)) {
                        if (!(((mad->rl_flag) + (sad->rl_flag)) & 1)) {
                            if (mad->rl_flag) {
                                if (!(mad->xyz[0].disp.pos <= sad->xyz[0].disp.pos)) {
                                    continue;
                                }
                            } else if (!(mad->xyz[0].disp.pos >= sad->xyz[0].disp.pos)) {
                                continue;
                            }
                        }
                        if (mad->att.dipsw & 4 && (lp2 > 7 || sad->cg_ja.bhix == 0)) {
                            continue;
                        }
                    }

                    if (lp2 == 10) {
                        if (!(mad->att.dipsw & 64) || sad->kind_of_waza & 0x60 || pcon_dp_flag ||
                            sad->pat_status == 0x26) {
                            continue;
                        }
                    }

                    mw = hit_check_subroutine(mad, sad, mh, dmdat_adrs[lp2]);

                    if (mw > mkm_wk[si]) {
                        hs[mi].flag.results |= 0x10;
                        hs[mi].my_hit = si;
                        hs[mi].my_att = lp;
                        hs[si].flag.results |= 1;
                        hs[si].dm_me = mi;
                        hs[si].dm_body = lp2;
                        mad->att_hit_ok = 0;
                        mkm_wk[si] = mw;
                        hs[mi].ah = mh;
                        hs[si].dh = dmdat_adrs[lp2];
                    }
                }
            }
        }

    end:
        continue;
    }
}
