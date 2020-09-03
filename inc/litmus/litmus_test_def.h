#ifndef LITMUS_TEST_DEF_H
#define LITMUS_TEST_DEF_H

#include "lib.h"


/* litmus_macros to help the user define a litmus test */
#include "litmus_macros.h"

/* test configuration */
typedef enum {
  TYPE_HEAP,
  TYPE_PTE,
  TYPE_UNMAPPED,
  TYPE_ALIAS,
  TYPE_AP,
  TYPE_REGION,
  TYPE_REGION_OWN,
} init_type_t;

typedef enum {
  REGION_SAME_VAR,  /* unused, but for completeness of type */
  REGION_SAME_CACHE_LINE, /* both in the same cache line */
  REGION_SAME_PAGE, /* both in the same 4k page but not the same cache-line */
  REGION_SAME_PMD,  /* both in the same 2M region but not the same 4k page */
  REGION_SAME_PUD,  /* both in the same 1G region but not the same 4k page */
  REGION_SAME_PGD,  /* unused, too large */
} pin_level_t;

char* pin_level_to_str(pin_level_t lvl);

#define NUM_PIN_LEVELS 6

typedef enum {
  REGION_OWN_VAR, /* unused, but for completeness of type */
  REGION_OWN_CACHE_LINE,  /* no other vars should be allocated in this cache line */
  REGION_OWN_PAGE,  /* no other vars should be allocated in this 4k region */
  REGION_OWN_PMD,  /* no other vars should be allocated in this 2M region */
  REGION_OWN_PUD,  /* no other vars should be allocated in this 1G region */
  REGION_OWN_PGD,  /* unused, too large */
} own_level_t;

char* own_level_to_str(own_level_t lvl);

typedef struct {
  const char* varname;
  init_type_t type;
  union {
    uint64_t value;
    const char* aliasname;
    struct {
      const char* pinned_var_name;
      pin_level_t pinned_level;
    };
    own_level_t ownership_level;
  };
} init_varstate_t;

/* Each thread is a functon that takes pointers to a slice of heap variables and output registers */
typedef struct test_ctx test_ctx_t;

typedef struct {
  test_ctx_t* ctx;
  uint64_t i;
  uint64_t** va;
  uint64_t** out_reg;
  uint64_t* pa;
  uint64_t*** pte_descs;
  uint64_t* desc;
} litmus_test_run;

typedef void th_f(litmus_test_run* data);

uint64_t* var_va(litmus_test_run* data, const char* name);
uint64_t var_pa(litmus_test_run* data, const char* name);
uint64_t* var_pte(litmus_test_run* data, const char* name);
uint64_t* var_pte_level(litmus_test_run* data, const char* name, int level);
uint64_t* var_pte_level0(litmus_test_run* data, const char* name);
uint64_t* var_pte_level1(litmus_test_run* data, const char* name);
uint64_t* var_pte_level2(litmus_test_run* data, const char* name);
uint64_t* var_pte_level3(litmus_test_run* data, const char* name);

uint64_t var_desc(litmus_test_run* data, const char* name);
uint64_t var_page(litmus_test_run* data, const char* name);
uint64_t* out_reg(litmus_test_run* data, const char* name);

/**
 * definition of a litmus test
 *
 * aka the static configuration that defines a litmus test
 */
typedef struct {
  const char* name;

  int no_threads;
  th_f** threads;
  int no_heap_vars;
  const char** heap_var_names;
  int no_regs;
  const char** reg_names;

  uint64_t* interesting_result;    /* interesting (relaxed) result to highlight */
  uint64_t no_interesting_results;
  uint64_t** interesting_results;  /* same as above, but plural */

  uint64_t no_sc_results;  /* a count of SC results, used in sanity-checking output */
  th_f** setup_fns;
  th_f** teardown_fns;

  int no_init_states;
  init_varstate_t** init_states;   /* initial state array */

  int* start_els;
  uint32_t*** thread_sync_handlers;

  /** whether the test requires any special options to be enabled */
  uint8_t requires_pgtable;  /* requires --pgtable */
  uint8_t requires_perf;     /* requires --perf */
  uint8_t requires_debug;    /* requires -d */
} litmus_test_t;


#endif /* LITMUS_TEST_DEF_H */