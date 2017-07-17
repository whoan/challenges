/*
 * https://www.hackerrank.com/challenges/ctci-merge-sort
 */

#include <iostream>
#include <vector>

class MergeSort {
    long long inversions;

    void sort(std::vector<int>& original, long long begin, long long end) {
        if (end - begin <= 1) return;
        int middle = begin + (end-begin)/2;
        sort(original, begin, middle);
        sort(original, middle, end);
        merge(original, begin, middle, end);
    }

    void merge(std::vector<int>& original, long long left, long long middle, const long long end) {
        const std::vector<int> leftSide({original.begin()+left, original.begin()+middle});
        const std::vector<int>& rightSide=original; // just to make the code cleaner
        auto posForward=left;
        auto right=middle;
        // reset left offsets because we are using a new collection
        middle -= left, left = 0;
        for ( ; left < middle && right < end; ++posForward) {
            if (leftSide[left] <= rightSide[right]) {
                original[posForward] = leftSide[left++];
            } else {
                original[posForward] = rightSide[right++];
                inversions += (middle-left);
            }
        }
        while (left < middle) {
            original[posForward++] = leftSide[left++];
        }
        while (right < end) {
            original[posForward++] = rightSide[right++];
        }
    }
public:
    MergeSort(std::vector<int>& original) : inversions(0) {
        sort(original, 0, original.size());
    }
    ~MergeSort() {
        std::cout << inversions << std::endl;
    }
};

int main() {
    int t;
    std::cin >> t;
    for (int a0 = 0; a0 < t; ++a0) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        MergeSort ms(arr);
    }
    return 0;
}
