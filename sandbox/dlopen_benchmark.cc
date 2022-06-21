#include <dlfcn.h>

#include "benchmark/benchmark.h"

static void BM_DlopenDlClose(benchmark::State& state) {
  for (auto _ : state) {
    void* h = dlopen(nullptr, RTLD_NOW);
    benchmark::DoNotOptimize(h);
    int n = dlclose(h);
    benchmark::DoNotOptimize(n);
  }
}

BENCHMARK(BM_DlopenDlClose);

BENCHMARK_MAIN();
