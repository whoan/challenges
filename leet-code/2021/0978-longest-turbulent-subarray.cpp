// https://leetcode.com/problems/longest-turbulent-subarray/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int longest = 1;
        int candidate = 1;
        bool sign = true;

        for (unsigned i = 1; i < arr.size(); ++i) {
            if (arr[i-sign] < arr[i-!sign]) {
                ++candidate;
                sign = !sign;
            } else {
                longest = max(longest, candidate);
                candidate = 1 + (arr[i-1] != arr[i-0]);
            }
        }
        return max(longest, candidate);
    }
};

// faster despite the extra branch! (check perf stat below)
class SolutionWithExtraBranch {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int longest = 1;
        int candidate = 1;
        bool sign = true;

        for (unsigned i = 1; i < arr.size(); ++i) {
            if (arr[i-sign] < arr[i-!sign]) {
                ++candidate;
                sign = !sign;
            } else {
                longest = max(longest, candidate);
                candidate = arr[i-1] == arr[i-0] ? 1 : 2;
            }
        }
        return max(longest, candidate);
    }
};

/*
Dataset:
[9,4,2,10,7,8,8,1,9]
[4,8,12,16]
[0,1,1,0,1,0,1,1,0,0]
*/

// https://github.com/whoan/snip
// snip("./benchmarks-0978-longest-turbulent-subarray.hpp")

// compile with:
// snip g++ --std=c++17 -Wall -Wextra -pthread -g -O2 -lbenchmark file...

/*
$ perf stat ./a.out --benchmark_filter=BM_Solution$
2021-09-15T11:28:53+02:00
Running ./a.out
Run on (8 X 1800 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 8192 KiB (x1)
Load Average: 0.33, 0.40, 0.48
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
------------------------------------------------------
Benchmark            Time             CPU   Iterations
------------------------------------------------------
BM_Solution      27905 ns        27745 ns        24857

 Performance counter stats for './a.out --benchmark_filter=BM_Solution$':

          1,032.62 msec task-clock:u              #    0.983 CPUs utilized          
                 0      context-switches:u        #    0.000 /sec                   
                 0      cpu-migrations:u          #    0.000 /sec                   
               152      page-faults:u             #  147.198 /sec                   
     1,802,833,399      cycles:u                  #    1.746 GHz                    
     3,950,989,574      instructions:u            #    2.19  insn per cycle         
       506,081,499      branches:u                #  490.095 M/sec                  
        11,335,204      branch-misses:u           #    2.24% of all branches        

       1.050386427 seconds time elapsed

       1.021383000 seconds user
       0.006424000 seconds sys


$ perf stat ./a.out --benchmark_filter=BM_SolutionWithExtraBranch
2021-09-15T11:28:47+02:00
Running ./a.out
Run on (8 X 1800 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 8192 KiB (x1)
Load Average: 0.36, 0.40, 0.48
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
---------------------------------------------------------------------
Benchmark                           Time             CPU   Iterations
---------------------------------------------------------------------
BM_SolutionWithExtraBranch      26983 ns        26961 ns        25944

 Performance counter stats for './a.out --benchmark_filter=BM_SolutionWithExtraBranch':

          1,007.35 msec task-clock:u              #    0.985 CPUs utilized          
                 0      context-switches:u        #    0.000 /sec                   
                 0      cpu-migrations:u          #    0.000 /sec                   
               153      page-faults:u             #  151.883 /sec                   
     1,797,804,126      cycles:u                  #    1.785 GHz                    
     4,062,161,290      instructions:u            #    2.26  insn per cycle         
       513,242,831      branches:u                #  509.497 M/sec                  
        11,096,426      branch-misses:u           #    2.16% of all branches        

       1.022411959 seconds time elapsed

       1.007051000 seconds user
       0.000000000 seconds sys
