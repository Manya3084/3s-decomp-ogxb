/* Notes from the hand port this file replaced:
 * set_kizetsu_status is 0x85BF2 size 0x7B, interior after the ret.
 * clear_kizetsu_point is 0x85C6D size 0x43, interior after the ret.
 * check_damage_hosei_nage is 0x858FA size 0x9B.
 * check_damage_hosei_dageki is 0x85995 size 0x30.
 * set_scrrrl is 0x85EF2 size 0x1E.
 * check_damage_hosei is 0x8637C size 0xA0.
 * These four are the PS2 C. scrr is the word at 0x7A88F8 and scrl the word at
 * 0x7A81D0. hosei_amari is PLW + 0x3AA, dm_hos_flag + 0x3AC, and
 * muriyari_ugoku + 0x3AE.
 * piyori_type is 0xC7D9A0, stride 0x14. flag is +0, genkai is +2,
 * time is +4, now.timer is +8, recover is +0xC, and store is +0x10.
 * My_char is 0x7A8114. omop_stun_gauge_len is 0x7C5C48.
 * stun_gauge_len_omake is 0x268480 and matches the 5 PlayStation 2
 * words. pl_piyo_tbl is 0x262420 and matches the 20 words.
 * pl_nr_piyo_tbl is 0x262448 and matches the 20 dwords.
 * player_number is PLW + 0x394. py is PLW + 0x3CC.
 */

/* The hand port's bodies (they matched as written): set_kizetsu_status,
 * clear_kizetsu_point, set_scrrrl, check_damage_hosei_nage,
 * check_damage_hosei_dageki, check_damage_hosei. */
void set_kizetsu_status(s16 ix) {
    s16 plnum = My_char[ix];

    piyori_type[ix].flag = 0;
    piyori_type[ix].time = 0;
    piyori_type[ix].now.timer = 0;
    piyori_type[ix].store = 0;
    piyori_type[ix].recover = pl_nr_piyo_tbl[plnum];
    piyori_type[ix].genkai = pl_piyo_tbl[plnum] + stun_gauge_len_omake[omop_stun_gauge_len[ix]];

    if (piyori_type[ix].genkai < 56) {
        piyori_type[ix].genkai = 56;
    }

    if (piyori_type[ix].genkai > 72) {
        piyori_type[ix].genkai = 72;
    }
}

void clear_kizetsu_point(PLW *wk) {
    wk->py->flag = 0;
    wk->py->time = 0;
    wk->py->now.timer = 0;
    wk->py->store = 0;
    wk->py->recover = pl_nr_piyo_tbl[wk->player_number];
}

void set_scrrrl() {
    s16 scrc = get_center_position();

    scrr = scrc + 192;
    scrl = scrc - 192;
}

void check_damage_hosei_nage(PLW* as, PLW* ds) {
    if (as->kind_of_catch) {
        if (ds->hosei_amari != 0) {
            as->wu.xyz[0].disp.pos += ds->hosei_amari;
            as->muriyari_ugoku += ds->hosei_amari;
            return;
        }

        if (bg_app_stop == 0 && bg_app == 0 && set_field_hosei_flag(as, scrr, 1) != 0) {
            set_field_hosei_flag(as, scrl, 0);
        }

        if (as->hosei_amari != 0) {
            ds->wu.xyz[0].disp.pos += as->hosei_amari;
            ds->muriyari_ugoku += as->hosei_amari;
        }
    } else if (ds->hosei_amari != 0) {
        as->wu.xyz[0].disp.pos += ds->hosei_amari;
        as->muriyari_ugoku += ds->hosei_amari;
    }
}

void check_damage_hosei_dageki(PLW* w1, PLW* w2) {
    if ((w1->dm_hos_flag != 0) && (w2->wu.hit_stop == 0)) {
        w2->wu.xyz[0].disp.pos += w1->hosei_amari;
        w2->muriyari_ugoku += w1->hosei_amari;
    }
}

void check_damage_hosei() {
    plw[0].muriyari_ugoku = plw[0].hosei_amari;
    plw[1].muriyari_ugoku = plw[1].hosei_amari;

    if (plw[0].tsukami_f && plw[1].tsukamare_f) {
        check_damage_hosei_nage(&plw[0], &plw[1]);
    } else if (plw[1].tsukami_f && plw[0].tsukamare_f) {
        check_damage_hosei_nage(&plw[1], &plw[0]);
    } else {
        switch ((plw[0].hosei_amari != 0) + ((plw[1].hosei_amari != 0) * 2)) {
        case 1:
            check_damage_hosei_dageki(&plw[0], &plw[1]);
            break;
        case 2:
            check_damage_hosei_dageki(&plw[1], &plw[0]);
            break;
        }
    }

    plw[0].hosei_amari = plw[1].hosei_amari = 0;
}
