/************************
 *  AUTOGENERATED FILE  *
 *     DO NOT EDIT      *
 ************************/

 /* this file was generated with the following command:
  * `make LITMUS_TESTS='@all'`
  *
  * please re-run that command to re-generate this file
  */
#include "lib.h"

extern litmus_test_t
  BBM1_dsbisbtlbiisdsbisbdsbisb_dsbisb,
  BBM1_dsbtlbiisdsbdsb_dsb,
  BBM1_dsbtlbiisdsbdsb_dsbisb,
  BBM1_dsbtlbiisdsbdsbisb_dsb,
  BBM1_dsbtlbiisdsbdsbisb_dsbisb,
  CoRT,
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
  CoWT,
  CoWT1_dsbtlbidsb,
  CoWT1_dsbtlbidsbisb,
  CoWT_dsb,
  CoWT_dsbisb,
  CoWT_dsbsvctlbidsb,
  CoWTinv,
  CoWTinv_dsb,
  CoWTinv_dsbisb,
  CoWinvT,
  CoWinvT1_dsbtlbidsb,
  ISA2trr_dmb_po_dmb,
  LB_pos,
  MPRT1_dcdsbtlbialldsb_dsbisb,
  MPRT1_dsbtlbialldsb_dsbisb,
  MPRT1_dsbtlbiallisdsb_dsbisb,
  MPRT1_dsbtlbidsb_dsbisb,
  MPRT1_dsbtlbiisdsb_dsbisb,
  MPRT1_dsbtlbiisdsbisb_dsbisb,
  MPRT1_dsbtlbiisdsbtlbiisdsb_dsbisb,
  MPRT_svcdsbtlbidsb_dsbisb,
  MPRT_svcdsbtlbiisdsb_dsbisb,
  MPRTinv_dmb_addr,
  MP_dmb_eret,
  MP_dmb_svc,
  MP_dmbs,
  MP_pos,
  MPinvRT1_dsbtlbiisdsb_dsb,
  MPinvRT1_dsbtlbiisdsb_dsbisb,
  MPtimes_pos,
  SB_dmbs,
  SB_pos,
  WRC_addrs,
  WRC_pos,
  WRCat_ctrl_dsb,
  WRCtrr_addr_dmb,
  WRCtrrinv_addrs,
  WRCtrt1_dsbtlbiisdsb_dmb,
  WRCtrt_addr_dmb,
  WRCtrt_dmbs,
  WRCtrt_dsbisbs,
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

const litmus_test_group grp_pgtable = {
  .name="@pgtable",
  .tests = (const litmus_test_t*[]){
    &BBM1_dsbisbtlbiisdsbisbdsbisb_dsbisb,
    &BBM1_dsbtlbiisdsbdsb_dsb,
    &BBM1_dsbtlbiisdsbdsb_dsbisb,
    &BBM1_dsbtlbiisdsbdsbisb_dsb,
    &BBM1_dsbtlbiisdsbdsbisb_dsbisb,
    &CoRT,
    &CoTR,
    &CoTR1_dsbdcdsbtlbidsbisb,
    &CoTR1_dsbtlbidsbisb,
    &CoTR1tlbi_dsbdsbisb,
    &CoTR_addr,
    &CoTR_dmb,
    &CoTR_dsb,
    &CoTR_dsbisb,
    &CoTRinv,
    &CoTRinv_dsbisb,
    &CoWT,
    &CoWT1_dsbtlbidsb,
    &CoWT1_dsbtlbidsbisb,
    &CoWT_dsb,
    &CoWT_dsbisb,
    &CoWT_dsbsvctlbidsb,
    &CoWTinv,
    &CoWTinv_dsb,
    &CoWTinv_dsbisb,
    &CoWinvT,
    &CoWinvT1_dsbtlbidsb,
    &ISA2trr_dmb_po_dmb,
    &MPRT1_dcdsbtlbialldsb_dsbisb,
    &MPRT1_dsbtlbialldsb_dsbisb,
    &MPRT1_dsbtlbiallisdsb_dsbisb,
    &MPRT1_dsbtlbidsb_dsbisb,
    &MPRT1_dsbtlbiisdsb_dsbisb,
    &MPRT1_dsbtlbiisdsbisb_dsbisb,
    &MPRT1_dsbtlbiisdsbtlbiisdsb_dsbisb,
    &MPRT_svcdsbtlbidsb_dsbisb,
    &MPRT_svcdsbtlbiisdsb_dsbisb,
    &MPRTinv_dmb_addr,
    &MPinvRT1_dsbtlbiisdsb_dsb,
    &MPinvRT1_dsbtlbiisdsb_dsbisb,
    &WRCat_ctrl_dsb,
    &WRCtrr_addr_dmb,
    &WRCtrrinv_addrs,
    &WRCtrt1_dsbtlbiisdsb_dmb,
    &WRCtrt_addr_dmb,
    &WRCtrt_dmbs,
    &WRCtrt_dsbisbs,
    &WRCtrtinv_dsbisbs,
    &WRCtrtinv_po_addr,
    &WRCtrtinv_po_dmb,
    NULL
  },
  .groups = (const litmus_test_group*[]){
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
    &MP_dmb_eret,
    &MP_dmb_svc,
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
    &MP_dmbs,
    &MP_pos,
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
