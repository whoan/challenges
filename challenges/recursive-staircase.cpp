#include <iostream>
#include <unordered_map>

unsigned getCombinations(int height) {
    static std::unordered_map<int, unsigned> cache {
        {1, 1},
        {2, 2},
        {3, 4}
    };
    if (cache.count(height)) return cache[height];
    return cache[height] =
        getCombinations(height-1) + // combinations ending in 1
        getCombinations(height-2) + // combinations ending in 2
        getCombinations(height-3);  // combinations ending in 3
}

int main(int argc, char* argv[]) {
    int staircases;
    std::cin >> staircases;
    for (int i=0; i < staircases; ++i) {
        int height;
        std::cin >> height;
        std::cout << getCombinations(height) << std::endl;
    }
    return 0;
}
