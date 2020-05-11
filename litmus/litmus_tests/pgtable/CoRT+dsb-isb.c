#include <stdint.h>

#include "lib.h"

static void P0(litmus_test_run* data) {
  asm volatile (
    /* move from C vars into machine regs */
    "mov x0, %[ydesc]\n\t"
    "mov x1, %[xpte]\n\t"
    /* test */
    "str x0, [x1]\n\t"
    :
    : [ydesc] "r" (data->desc[1]), [xpte] "r" (data->pte[0])
    :  "cc", "memory", "x0", "x1"
  );
}


static void P1(litmus_test_run* data) {
  asm volatile (
    /* move from C vars into machine regs */
    "mov x1, %[xpte]\n\t"
    "mov x3, %[x]\n\t"

    /* test payload */
    "ldr x0, [x1]\n\t"
    "dsb sy\n\t"
    "isb\n\t"
    "ldr x2, [x3]\n\t"

    /* save results */
    "str x0, [%[outp1r0]]\n\t"  /* save desc,  later re-write to be 0, 1 */
    "str x2, [%[outp1r2]]\n\t"
    :
    : [x] "r" (data->var[0]), [xpte] "r" (data->pte[0]), [ydesc] "r" (data->desc[1]), [outp1r0] "r" (data->out_reg[0]), [outp1r2] "r" (data->out_reg[1])
    :  "cc", "memory", "x0", "x1", "x2", "x3", "x4"
  );

  *data->out_reg[0] = (*data->out_reg[0] == data->desc[1]) ? 1 : 0;
}


litmus_test_t CoRT_dsbisb = {
  "CoRT+dsb-isb",
  2,(th_f*[]){
    (th_f*)P0,
    (th_f*)P1
  },
  2,(const char*[]){"x", "y"},
  2,(const char*[]){"p1:x0","p1:x2"},
  .interesting_result = (uint64_t[]){
      /* p0:x0 =*/1,
      /* p0:x2 =*/0,
  },
  .no_init_states=1,
  .init_states=(init_varstate_t*[]){
    &(init_varstate_t){"y", TYPE_HEAP, 1},
  },
  .requires_pgtable = 1,
  .no_sc_results = 3,
};