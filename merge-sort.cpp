#include <bits/stdc++.h>

template <typename Collection>
class MergeSort {
    Collection& collection;

    void sort(std::size_t left, std::size_t right) {
        // base case to end recursion
        if (right - left < 2) {
            return;
        }

        // DIVIDE
        // call recursively basically to track indices in the stack (frames).
        // the indices will be useful for the merge call to start mergign the smallest possibe ranges
        std::size_t middle = left + (right-left)/2;
        sort(left, middle);
        sort(middle, right);

        // CONQUER
        // at this point, [left, middle) and [middle, right) are already sorted
        merge(left, middle, right);
    }

    void merge(std::size_t left, std::size_t middle, std::size_t right) {
        Collection buffer;
        // merge two sorted ranges: https://en.cppreference.com/w/cpp/algorithm/merge
        std::merge(
            // first sorted half
            std::next(std::begin(collection), left),
            std::next(std::begin(collection), middle),
            // second sorted half
            std::next(std::begin(collection), middle),
            std::next(std::begin(collection), right),
            // full sorted buffer
            std::inserter(buffer, std::end(buffer))
        );
        std::copy(std::begin(buffer), std::end(buffer), std::next(std::begin(collection), left));
    }

public:
    MergeSort(Collection& collection) : collection(collection) {
        sort(0, collection.size());
    }
};

// tremplate-template only to support custom containerss (and to show off)
template <template<typename> typename Collection=std::vector, typename T=int>
inline Collection<T> mergeSort(Collection<T> collection) {
    MergeSort<Collection<T>> a(collection);
    return collection;
}

// see https://github.com/whoan/snip
// snip("print.hpp")

int main() {
    snip::printLoopSpaces(mergeSort({5}));
    snip::printLoopSpaces(mergeSort({-2}));
    snip::printLoopSpaces(mergeSort({5, 2}));
    snip::printLoopSpaces(mergeSort({5, 2, 3}));
    snip::printLoopSpaces(mergeSort({5, 2, 1}));
    snip::printLoopSpaces(mergeSort({5, 2, 1, 9}));
    snip::printLoopSpaces(mergeSort({4, 8, 1, 3, 2, 56, 3, 4, 7, 12, 4, 543, 7, 96, 73, 2, 3, 6, 8, 99, 2}));
    return 0;
}
