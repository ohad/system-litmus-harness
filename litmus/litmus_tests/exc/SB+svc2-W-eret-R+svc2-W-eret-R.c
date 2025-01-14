
#include "lib.h"

#define VARS x, y
#define REGS p0x2, p1x2

static void svc_handler00(void) {
  asm volatile(
                             // Save registers
      "mrs x10,spsr_el1\n\t" // saved program status
      "mrs x11,elr_el1\n\t"  // return location
               
      "svc #0\n\t"
      /* Take exception
         and return */
      /* x3 = Y */
      "ldr x2, [x3]\n\t"
      
      "msr elr_el1,x11\n\t"  // restore
      "msr spsr_el1,x10\n\t"      
      "eret\n\t");
}

static void svc_handler01(void) {
  asm volatile(
      /* x1 = X */
      "str x0, [x1]\n\t"
      "eret\n\t");
}


static void P0(litmus_test_run* data) {
  asm volatile (
    /* initial registers */
      "mov x0, #1\n\t"
      "mov x1, %[x]\n\t"
      "mov x3, %[y]\n\t"

      "svc #0\n\t"
      /* Take exception
         and return */
      
      /* extract values */
      "str x2, [%[outp0r2]]\n\t"
      "dmb st\n\t"
  :
  : ASM_VARS(data, VARS),
    ASM_REGS(data, REGS)
  : "cc", "memory", "x0", "x1", "x2", "x3",
    "x7", "x10", "x11"  
  );
}

static void svc_handler10(void) {
  asm volatile(
                             // Save registers
      "mrs x10,spsr_el1\n\t" // saved program status
      "mrs x11,elr_el1\n\t"  // return location
               
      "svc #0\n\t"
      /* Take exception
         and return */
      /* x3 = Y */
      "ldr x2, [x3]\n\t"
      "msr elr_el1,x11\n\t"  // restore
      "msr spsr_el1,x10\n\t"      
      "eret\n\t");
}

static void svc_handler11(void) {
  asm volatile(
      /* x1 = Y */
      "str x0, [x1]\n\t"
      "eret\n\t");
}

static void P1(litmus_test_run* data) {
  asm volatile (
    /* initial registers */
      "mov x0, #1\n\t"
      "mov x1, %[y]\n\t"
      "mov x3, %[x]\n\t"

      "svc #0\n\t"
      /* Take exception
         and return */

      "str x2, [%[outp1r2]]\n\t"
      "dmb st\n\t"
  :
  : ASM_VARS(data, VARS),
    ASM_REGS(data, REGS)
  : "cc", "memory", "x0", "x1", "x2", "x3", "x4", "x5", "x6",
    "x7", "x10", "x11" /* dont touch parameter registers */
  );
}



litmus_test_t SB_svc2WeretR_svc2WeretR = {
  "SB+svc2-W-eret-R+svc2-W-eret-R",
  MAKE_THREADS(2),
  MAKE_VARS(VARS),
  MAKE_REGS(REGS),
  INIT_STATE(
    2,
    INIT_VAR(x, 0),
    INIT_VAR(y, 0)
  ),
  .thread_sync_handlers =
    (u32**[]){
     (u32*[]){(u32*)svc_handler00, (u32*)svc_handler01},
     (u32*[]){(u32*)svc_handler10, (u32*)svc_handler11},
    },
  .interesting_result = (u64[]){
      /* p0:x2 =*/0,
      /* p1:x2 =*/0,
  },
};
