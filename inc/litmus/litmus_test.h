#ifndef LITMUS_TEST_H
#define LITMUS_TEST_H
#include <stdint.h>

#include "litmus_test_def.h"
#include "litmus_test_results.h"
#include "litmus_test_ctx.h"


/* entry point for tests */
void run_test(const litmus_test_t* cfg);

typedef struct {
    void (*init_runner)(test_ctx_t* ctx, const litmus_test_t* cfg);

    /* call at the start and end of each run  */
    void (*start_of_run)(test_ctx_t* ctx, int cpu, int vcpu, int i, int r);
    void (*end_of_run)(test_ctx_t* ctx, int cpu, int vcpu, int i, int r);

    /* call at the start and end of each thread */
    void (*start_of_thread)(test_ctx_t* ctx, int cpu);
    void (*end_of_thread)(test_ctx_t* ctx, int cpu);

    /* call at the beginning and end of each test */
    void (*start_of_test)(test_ctx_t* ctx);
    void (*end_of_test)(test_ctx_t* ctx);
} test_runner_t;

extern test_runner_t SEMI_ARRAY_TEST_RUNNER;
extern test_runner_t ARRAY_TEST_RUNNER;
extern test_runner_t EPHEMERAL_TEST_RUNNER;

#endif /* LITMUS_TEST_H */
