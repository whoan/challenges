/*
 * https://www.hackerrank.com/challenges/ctci-array-left-rotation
 */

#include <vector>
#include <iostream>

std::vector<int> array_left_rotation(std::vector<int>& a, int n, int k) {
    std::vector<int> rotated(a.begin()+k, a.end());
    a.resize(k);
    for (auto b: a) {
      rotated.push_back(b);
    }

    return rotated;
}

int main() {
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> output = array_left_rotation(a, n, k);
    for (int i = 0; i < n; ++i) {
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
