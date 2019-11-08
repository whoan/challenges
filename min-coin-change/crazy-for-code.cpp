// https://www.crazyforcode.com/coin-problem/

#include <bits/stdc++.h>

//int minCoins( int a[], int N, int S ){
template <typename Coins>
int minCoins(const Coins& a, int N, int S) {
    /* N: Length of the array */

    int *min = (int *)malloc(sizeof(int)*(S+1));  // whoan says: ignore this leak please
    int i,j;
    for(i=0;i<=S;i++)
        min[i]= INT_MAX; // start with extremly large value

    min[0]=0;
    for(i=1;i<=S;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i>=a[j])
            {
                if(min[i-a[j]]+1<min[i])
                min[i] = min[i-a[j]]+1;
            }
        }
    }

    if(min[S]== INT_MAX)
        return -1;

    return min[S];
}


// FROM HERE, STUFF NOT RELATED TO THE ALGORITHM

// forward call to match function signature
template <typename Coins>
int minCoinsChange(const Coins& coins, int target) {
  return minCoins(coins, coins.size(), target);
}

// see https://github.com/whoan/snip
// snip("https://raw.githubusercontent.com/whoan/challenges/master/min-coin-change/base.cpp")
