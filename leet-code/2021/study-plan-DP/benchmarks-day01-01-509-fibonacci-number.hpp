#include <benchmark/benchmark.h>

static void BM_Solution(benchmark::State& state) {
  for (auto _ : state) {
    Solution().fib(state.range(0));
  }
}
BENCHMARK(BM_Solution)->Range(1, 2048);


static void BM_SolutionWithPair(benchmark::State& state) {
  for (auto _ : state) {
    SolutionWithPair().fib(state.range(0));
  }
}
BENCHMARK(BM_SolutionWithPair)->Range(1, 2048);


static void BM_SolutionWithAtomic(benchmark::State& state) {
  for (auto _ : state) {
    SolutionWithAtomic().fib(state.range(0));
  }
}
BENCHMARK(BM_SolutionWithAtomic)->Range(1, 2048);


static void BM_SolutionWithSwap(benchmark::State& state) {
  for (auto _ : state) {
    SolutionWithSwap().fib(state.range(0));
  }
}
BENCHMARK(BM_SolutionWithSwap)->Range(1, 2048);


static void BM_SolutionWithTailRecursion(benchmark::State& state) {
  for (auto _ : state) {
    SolutionWithTailRecursion().fib(state.range(0));
  }
}
BENCHMARK(BM_SolutionWithTailRecursion)->Range(1, 2048);


BENCHMARK_MAIN();
