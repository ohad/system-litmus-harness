#include <stdint.h>

#include "lib.h"

static void P0(litmus_test_run* data) {
  asm volatile (
    "mov x0, #0\n\t"
    "mov x1, %[xpte]\n\t"
    "mov x2, %[xpage]\n\t"
    "mov x3, %[zdesc]\n\t"
    "mov x4, %[xpte]\n\t"
    "mov x5, #1\n\t"
    "mov x6, %[y]\n\t"
    /* test payload */
    "str x0,[x1]\n\t"
    "dsb sy\n\t"
    "tlbi vae1is,x2\n\t"
    "dsb sy\n\t"
    "str x3,[x4]\n\t"
    "dsb sy\n\t"
    "isb\n\t"
    "str x5,[x6]\n\t"
  :
  : [zdesc] "r" (data->desc[2]), [xpte] "r" (data->pte[0]), [xpage] "r" (PAGE(data->var[0])), [y] "r" (data->var[1])
  : "memory", "x0", "x1", "x2", "x3", "x4"
  );
}

static void sync_handler(void) {
  asm volatile(
    "mov x2, #0\n\t"

    "mrs x10, elr_el1\n\t"
    "add x10, x10, #4\n\t"
    "msr elr_el1, x10\n\t"
    "eret\n\t"
  );
}

static void P1(litmus_test_run* data) {
  asm volatile (
      /* move from C vars into machine regs */
      "mov x1, %[y]\n\t"
      "mov x3, %[x]\n\t"
      /* test */
      "ldr x0,[x1]\n\t"
      "dsb sy\n\t"
      "isb\n\t"
      "ldr x2,[x3]\n\t"
      /* output */
      "str x0, [%[outp1r0]]\n\t"
      "str x2, [%[outp1r2]]\n\t"
      :
      : [y] "r" (data->var[1]), [x] "r" (data->var[0]), [outp1r0] "r" (data->out_reg[0]), [outp1r2] "r" (data->out_reg[1])
      :  "cc", "memory", "x0", "x1", "x2", "x3", "x4"
  );
}


litmus_test_t BBM1_dsbtlbiisdsbdsbisb_dsbisb = {
  "BBM1+dsb-tlbiis-dsb-dsb-isb+dsb-isb",
  2,(th_f*[]){
    (th_f*)P0,
    (th_f*)P1
  },
  3,(const char*[]){"x", "y", "z"},
  2,(const char*[]){"p1:x0", "p1:x2"},
  .interesting_result = (uint64_t[]){
      /* p1:x0 =*/1,
      /* p1:x2 =*/0,
  },
  .start_els=(int[]){1,0},
  .thread_sync_handlers =
    (uint32_t**[]){
     (uint32_t*[]){NULL, NULL},
     (uint32_t*[]){(uint32_t*)sync_handler, NULL},
    },
  .no_init_states=1,
  .init_states=(init_varstate_t*[]){
    &(init_varstate_t){"z", TYPE_HEAP, 1},
  },
  .requires_pgtable=1,
};