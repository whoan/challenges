// https://leetcode.com/problems/can-place-flowers/
// Easy

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.reserve(flowerbed.size()-1);
        flowerbed.push_back(0);
        for (int i=0; i < flowerbed.size()-1; ++i) {
            // no spot, continue
            if (flowerbed[i]) {
                continue;
            }
            // we only check current spot when we also have a spot before
            if (i != 0 && flowerbed[i-1]) {
                continue;
            }
            // check next 2 spots "?" after "0": xxxx0??
            if (!flowerbed[i] && !flowerbed[i+1]) {
                flowerbed[i] = 1;
                --n;
                ++i;
            }
        }
        return n <= 0;
    }
};

class HorribleSolution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1 && !flowerbed[0]) {
            return n <= 1;
        }
        if (flowerbed.size() > 1 && !flowerbed[0] && !flowerbed[1]) {
            flowerbed[0] = 1;
            --n;
        }
        if (flowerbed.size() > 1 && !flowerbed[flowerbed.size()-2] && !flowerbed[flowerbed.size()-1]) {
            flowerbed[flowerbed.size()-1] = 1;
            --n;
        }
        for (int i=1; i < flowerbed.size()-1; ++i) {
            if (!flowerbed[i-1] && !flowerbed[i] && !flowerbed[i+1]) {
                flowerbed[i] = 1;
                --n;
                ++i;
            }
        }
        return n <= 0;
    }
};

/*
Test data:
[1,0,0,0,1]
1
[1,0,0,0,1]
2
[0]
1
[1]
1
[0,1,0]
1
[1,0]
1
*/
