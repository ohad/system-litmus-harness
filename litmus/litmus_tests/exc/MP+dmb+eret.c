#include <stdint.h>

#include "lib.h"

static void P0(litmus_test_run* data) {
  asm volatile(
      "mov x0, #1\n\t"
      "str x0, [x\n\t"
      "dmb sy\n\t"
      "mov x2, #1\n\t"
      "str x2, [y]\n\t"
      :
      : [x] "r" (var_va(data, "x")), [y] "r" (var_va(data, "y"))
      :  "cc", "memory", "x0", "x2"
  );
}

static void svc_handler(void) {
  asm volatile(
      /* x1 = Y */
      "ldr x0, [x1]\n\t"
      "eret\n\t");
}

static void P1(litmus_test_run* data) {
  asm volatile(
      /* initial registers */
      "mov x1, %[y]\n\t"
      "mov x3, %[x]\n\t"

      /* test */
      "svc #0\n\t"
      "ldr x2, [x3]\n\t"

      /* extract values */
      "str x0, [%[outp1r0]]\n\t"
      "str x2, [%[outp1r2]]\n\t"
      :
      : [y] "r" (var_va(data, "y")), [x] "r" (var_va(data, "x")), [outp1r0] "r" (out_reg(data, "p1:x0")), [outp1r2] "r" (out_reg(data, "p1:x2"))
      : "cc", "memory", "x0", "x1", "x2", "x3", "x4", "x5", "x6",
        "x7" /* dont touch parameter registers */
  );
}


litmus_test_t MP_dmb_eret = {
  "MP+dmb+eret",
  2,(th_f*[]){
    (th_f*)P0,
    (th_f*)P1
  },
  2,(const char*[]){"x", "y"},
  2,(const char*[]){"p1:x0", "p1:x2"},
  .thread_sync_handlers =
    (uint32_t**[]){
     (uint32_t*[]){NULL, NULL},
     (uint32_t*[]){(uint32_t*)svc_handler, NULL},
    },
  .interesting_result = (uint64_t[]){
      /* p1:x0 =*/1,
      /* p1:x2 =*/0,
  },
};