/************************
 *  AUTOGENERATED FILE  *
 *     DO NOT EDIT      *
 ************************/

 /* this file was generated with the following command:
  * `make LITMUS_TESTS='@all -@amo'`
  *
  * please re-run that command to re-generate this file
  */
#include "lib.h"

extern litmus_test_t
  BBM1_dmblddsbtlbiisdsbisbdsbisb_dsbisb,
  BBM1_dmbldtlbiisdsbisbdsbisb_dsbisb,
  BBM1_dsbisbtlbiisdsbisbdsbisb_dsbisb,
  BBM1_dsbtlbiisdsbdsb_dsb,
  BBM1_dsbtlbiisdsbdsb_dsbisb,
  BBM1_dsbtlbiisdsbdsbisb_dsb,
  BBM1_dsbtlbiisdsbdsbisb_dsbisb,
  BBM1_podetourdsbtlbiisdsbisbdsbisb_dsbisb,
  BBM1_podsbtlbiisdsbisbdsbisb_dsbisb,
  BBM1id_dsbtlbiisdsbdsb_dsbisb,
  CoRT,
  CoRT_dsbisb,
  CoTR,
  CoTR1_dsbdcdsbtlbidsbisb,
  CoTR1_dsbtlbidsbisb,
  CoTR1tlbi_dsbdsbisb,
  CoTR_addr,
  CoTR_dmb,
  CoTR_dsb,
  CoTR_dsbisb,
  CoTRinv,
  CoTRinv_dsbisb,
  CoTT,
  CoWRalias,
  CoWT,
  CoWT1_dsbtlbidsb,
  CoWT1_dsbtlbidsbisb,
  CoWT_dsb,
  CoWT_dsbisb,
  CoWT_dsbsvctlbidsb,
  CoWTinv,
  CoWTinv_dmb,
  CoWTinv_dsb,
  CoWTinv_dsbisb,
  CoWinvT,
  CoWinvT1_dsbtlbidsb,
  CoWinvT_dsbisb,
  CoWinvWT1_dsbtlbidsbdsbisb,
  ISA2trr_dmb_po_dmb,
  LB_RsvcW_RsvcW,
  LB_pos,
  MPRT1_dcdsbtlbialldsb_dsbisb,
  MPRT1_dcdsbtlbialldsbisb_dsbisb,
  MPRT1_dsbdmblddmb_dsbisb,
  MPRT1_dsbdmblddsbisbtlbiisdsbisb_dmb,
  MPRT1_dsbdmblddsbisbtlbiisdsbisb_dsbisb,
  MPRT1_dsbdmblddsbtlbiisdsbisb_dmb,
  MPRT1_dsbisbtlbiisdsbisb_dsbisb,
  MPRT1_dsbtlbialldsb_dsbisb,
  MPRT1_dsbtlbiallisdsb_dsbisb,
  MPRT1_dsbtlbidsb_dsbisb,
  MPRT1_dsbtlbiisdsb_dsbisb,
  MPRT1_dsbtlbiisdsbisb_dmb,
  MPRT1_dsbtlbiisdsbisb_dsbisb,
  MPRT1_dsbtlbiisdsbtlbiisdsb_dsbisb,
  MPRT_svcdsbtlbidsb_dsbisb,
  MPRT_svcdsbtlbiisdsb_dsbisb,
  MPRTinv_dmb_addr,
  MPRTinv_dmb_po,
  MPTT_WinvdmbWinv_tpo,
  MPTT_dmb_dsbisb,
  MPTT_dmb_tpo,
  MPTTinv_dmb_dsbisb,
  MPTTinv_dmb_tpo,
  MP_WsvcW_addr,
  MP_dmb_RsvceretR,
  MP_dmb_eret,
  MP_dmb_po,
  MP_dmb_svc,
  MP_dmb_svc2ReretR,
  MP_dmb_svcReretsvcR,
  MP_dmb_svcRsvcR,
  MP_dmb_svcRsvceretR,
  MP_dmbdata_dmb,
  MP_dmbs,
  MP_po_dmb,
  MP_podata_dmb,
  MP_pos,
  MP_rfidata_dmb,
  MP_svcWeretW_addr,
  MPalias2_dmbdata_dmb,
  MPalias2_dmbs,
  MPalias2_podata_dmb,
  MPalias3_rfidata_dmb,
  MPalias_dmbs,
  MPinvRT1_dsbisbtlbiisdsbisb_dsbisb,
  MPinvRT1_dsbtlbiisdsb_dsb,
  MPinvRT1_dsbtlbiisdsb_dsbisb,
  MPinvRT_dsb_dsbisb,
  MPtimes_pos,
  SB_WsvcR_WsvcR,
  SB_dmbs,
  SB_pos,
  SB_svcerets,
  SBalias_dmbs,
  WRC_addrs,
  WRC_pos,
  WRCalias2_addrs,
  WRCalias2_dmbs,
  WRCat_ctrl_dsb,
  WRCtrr_addr_dmb,
  WRCtrrinv_addrs,
  WRCtrt1_dsbtlbiisdsb_dmb,
  WRCtrt1_dsbtlbiisdsb_dsbisb,
  WRCtrt_addr_dmb,
  WRCtrt_dmbs,
  WRCtrt_dsbisbs,
  WRCtrtinv_addrs,
  WRCtrtinv_dsbisbs,
  WRCtrtinv_po_addr,
  WRCtrtinv_po_dmb,
  check1,
  check2,
  check3,
  check4,
  check5,
  check6;


const litmus_test_group grp_checks = {
  .name="@checks",
  .tests = (const litmus_test_t*[]){
    &check1,
    &check2,
    &check3,
    &check4,
    &check5,
    &check6,
    NULL
  },
  .groups = (const litmus_test_group*[]){
    NULL
  },
};

const litmus_test_group grp_aliasing = {
  .name="@aliasing",
  .tests = (const litmus_test_t*[]){
    &CoWRalias,
    &MP_dmbdata_dmb,
    &MPalias_dmbs,
    &MPalias2_dmbdata_dmb,
    &MPalias2_dmbs,
    &MPalias2_podata_dmb,
    &MPalias3_rfidata_dmb,
    &SBalias_dmbs,
    &WRCalias2_addrs,
    &WRCalias2_dmbs,
    NULL
  },
  .groups = (const litmus_test_group*[]){
    NULL
  },
};

const litmus_test_group grp_pgtable = {
  .name="@pgtable",
  .tests = (const litmus_test_t*[]){
    &CoRT,
    &CoRT_dsbisb,
    &CoTR,
    &CoTR_addr,
    &CoTR_dmb,
    &CoTR_dsb,
    &CoTR_dsbisb,
    &CoTRinv,
    &CoTRinv_dsbisb,
    &CoTR1_dsbdcdsbtlbidsbisb,
    &CoTR1_dsbtlbidsbisb,
    &CoTR1tlbi_dsbdsbisb,
    &CoTT,
    &CoWT,
    &CoWT_dsb,
    &CoWT_dsbisb,
    &CoWT_dsbsvctlbidsb,
    &CoWTinv,
    &CoWTinv_dmb,
    &CoWTinv_dsb,
    &CoWTinv_dsbisb,
    &CoWT1_dsbtlbidsb,
    &CoWT1_dsbtlbidsbisb,
    &CoWinvT,
    &CoWinvT_dsbisb,
    &CoWinvT1_dsbtlbidsb,
    &CoWinvWT1_dsbtlbidsbdsbisb,
    &ISA2trr_dmb_po_dmb,
    &BBM1_dmblddsbtlbiisdsbisbdsbisb_dsbisb,
    &BBM1_dmbldtlbiisdsbisbdsbisb_dsbisb,
    &BBM1_podetourdsbtlbiisdsbisbdsbisb_dsbisb,
    &BBM1_dsbisbtlbiisdsbisbdsbisb_dsbisb,
    &BBM1_dsbtlbiisdsbdsb_dsb,
    &BBM1_dsbtlbiisdsbdsb_dsbisb,
    &BBM1_dsbtlbiisdsbdsbisb_dsb,
    &BBM1_dsbtlbiisdsbdsbisb_dsbisb,
    &BBM1_podsbtlbiisdsbisbdsbisb_dsbisb,
    &BBM1id_dsbtlbiisdsbdsb_dsbisb,
    &MPRT_svcdsbtlbidsb_dsbisb,
    &MPRT_svcdsbtlbiisdsb_dsbisb,
    &MPRTinv_dmb_addr,
    &MPRTinv_dmb_po,
    &MPRT1_dsbdmblddmb_dsbisb,
    &MPRT1_dsbdmblddsbisbtlbiisdsbisb_dmb,
    &MPRT1_dsbdmblddsbisbtlbiisdsbisb_dsbisb,
    &MPRT1_dsbdmblddsbtlbiisdsbisb_dmb,
    &MPRT1_dcdsbtlbialldsb_dsbisb,
    &MPRT1_dcdsbtlbialldsbisb_dsbisb,
    &MPRT1_dsbisbtlbiisdsbisb_dsbisb,
    &MPRT1_dsbtlbidsb_dsbisb,
    &MPRT1_dsbtlbialldsb_dsbisb,
    &MPRT1_dsbtlbiallisdsb_dsbisb,
    &MPRT1_dsbtlbiisdsb_dsbisb,
    &MPRT1_dsbtlbiisdsbisb_dmb,
    &MPRT1_dsbtlbiisdsbisb_dsbisb,
    &MPRT1_dsbtlbiisdsbtlbiisdsb_dsbisb,
    &MPTT_WinvdmbWinv_tpo,
    &MPTT_dmb_dsbisb,
    &MPTT_dmb_tpo,
    &MPTTinv_dmb_dsbisb,
    &MPTTinv_dmb_tpo,
    &MPinvRT_dsb_dsbisb,
    &MPinvRT1_dsbisbtlbiisdsbisb_dsbisb,
    &MPinvRT1_dsbtlbiisdsb_dsb,
    &MPinvRT1_dsbtlbiisdsb_dsbisb,
    &WRCat_ctrl_dsb,
    &WRCtrr_addr_dmb,
    &WRCtrrinv_addrs,
    &WRCtrt_addr_dmb,
    &WRCtrt_dmbs,
    &WRCtrt_dsbisbs,
    &WRCtrtinv_addrs,
    &WRCtrtinv_dsbisbs,
    &WRCtrtinv_po_addr,
    &WRCtrtinv_po_dmb,
    &WRCtrt1_dsbtlbiisdsb_dmb,
    &WRCtrt1_dsbtlbiisdsb_dsbisb,
    NULL
  },
  .groups = (const litmus_test_group*[]){
    &grp_aliasing,
    NULL
  },
};

const litmus_test_group grp_timing = {
  .name="@timing",
  .tests = (const litmus_test_t*[]){
    &MPtimes_pos,
    NULL
  },
  .groups = (const litmus_test_group*[]){
    NULL
  },
};

const litmus_test_group grp_exc = {
  .name="@exc",
  .tests = (const litmus_test_t*[]){
    &LB_RsvcW_RsvcW,
    &MP_WsvcW_addr,
    &MP_dmb_RsvceretR,
    &MP_dmb_eret,
    &MP_dmb_svc,
    &MP_dmb_svcReretsvcR,
    &MP_dmb_svcRsvcR,
    &MP_dmb_svcRsvceretR,
    &MP_dmb_svc2ReretR,
    &MP_svcWeretW_addr,
    &SB_WsvcR_WsvcR,
    &SB_svcerets,
    NULL
  },
  .groups = (const litmus_test_group*[]){
    NULL
  },
};

const litmus_test_group grp_data = {
  .name="@data",
  .tests = (const litmus_test_t*[]){
    &LB_pos,
    &MP_dmb_po,
    &MP_dmbs,
    &MP_po_dmb,
    &MP_podata_dmb,
    &MP_pos,
    &MP_rfidata_dmb,
    &SB_dmbs,
    &SB_pos,
    &WRC_addrs,
    &WRC_pos,
    NULL
  },
  .groups = (const litmus_test_group*[]){
    NULL
  },
};

const litmus_test_group grp_all = {
  .name="@all",
  .tests = (const litmus_test_t*[]){
    NULL
  },
  .groups = (const litmus_test_group*[]){
    &grp_checks,
    &grp_data,
    &grp_exc,
    &grp_pgtable,
    &grp_timing,
    NULL
  },
};
