/*
 * https://www.hackerrank.com/challenges/ctci-bubble-sort
 */

#include <vector>
#include <iostream>

int bubbleSort(int a[], int n) {
    int totalSwaps(0);
    for (int i = 0; i < n; ++i) {
        // Track number of elements swapped during a single array traversal
        int numberOfSwaps = 0;

        for (int j = 0; j < n-1-i; ++j) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                ++numberOfSwaps;
            }
        }

        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0) {
            break;
        }
        totalSwaps += numberOfSwaps;
    }
    return totalSwaps;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
       std::cin >> a[i];
    }
    std::cout << "Array is sorted in " << bubbleSort(a.data(), n) << " swaps." << std::endl;
    std::cout << "First Element: " << a.front() << std::endl;
    std::cout << "Last Element: " << a.back() << std::endl;
    return 0;
}
