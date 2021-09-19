#include <benchmark/benchmark.h>

std::vector<int> input{
    -2,1,-3,4,-1,2,1,-5,4,10,9,90,54,-100,-5,84,-56,-4,-9,0,0,0,0,66,
    1,-2,1,-3,4,-1,2,1,-5,4,-2,1,-3,4,-1,2,1,-5,4,-2,1,-3,4,-1,2,1,-5,4,
    -2,1,-3,4,-1,2,1,-5,4,10,9,90,54,-100,-5,84,-56,-4,-9,0,0,0,0,66,
    1,-2,1,-3,4,-1,2,1,-5,4,-2,1,-3,4,-1,2,1,-5,4,-2,1,-3,4,-1,2,1,-5,4,
    -2,1,-3,4,-1,2,1,-5,4,10,9,90,54,-100,-5,84,-56,-4,-9,0,0,0,0,66,
    1,-2,1,-3,4,-1,2,1,-5,4,-2,1,-3,4,-1,2,1,-5,4,-2,1,-3,4,-1,2,1,-5,4
};

static void BM_Solution(benchmark::State& state) {
  for (auto _ : state) {
    Solution().maxSubArray(input);
  }
}
BENCHMARK(BM_Solution);


static void BM_SolutionWithMax(benchmark::State& state) {
  for (auto _ : state) {
    SolutionWithMax().maxSubArray(input);
  }
}
BENCHMARK(BM_SolutionWithMax);


BENCHMARK_MAIN();
