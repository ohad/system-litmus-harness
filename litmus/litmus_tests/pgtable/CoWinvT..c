#include <stdint.h>

#include "lib.h"

static void* fault_handler(uint64_t esr, regvals_t* regs) {
  *(uint64_t*)regs->x4 = 1;

  /* return to next instruction in test */
  write_sysreg(read_sysreg(elr_el1)+4, elr_el1);
  return NULL;
}


static void P0(test_ctx_t* ctx, int i, uint64_t** heap_vars, uint64_t** ptes,
               uint64_t* pas, uint64_t** out_regs) {

  uint64_t* x = heap_vars[0];
  uint64_t* y = heap_vars[1];

  uint64_t* x4 = out_regs[0];

  uint64_t* xpte = ptes[0];
  uint64_t* ypte = ptes[1];

  set_pgfault_handler((uint64_t)x, &fault_handler);

  asm volatile (
      /* move from C vars into machine regs */
      "mov x0, #0\n\t"
      "mov x1, %[xpte]\n\t"
      "mov x3, %[x]\n\t"
      "mov x4, %[x4]\n\t"

      /* test */
      "str x0, [x1]\n\t"
      "ldr x2, [x3]\n\t"
      :
      : [ydesc] "r" (*ypte), [xpte] "r" (xpte), [x] "r" (x), [x4] "r" (x4)
      : "cc", "memory", "x0", "x1", "x2", "x3", "x4");

  reset_pgfault_handler((uint64_t)x);
}

litmus_test_t CoWinvT = {
  "CoWinvT",
  1, (th_f** []){
    (th_f* []) {NULL, P0, NULL},
  },
  1, (const char* []){"x"},
  1, (const char* []){"p0:x4",},
  .interesting_result = (uint64_t[]){
      /* p0:x4 =*/0,
  },
  .requires_pgtable = 1,
};
