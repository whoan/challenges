#include <bits/stdc++.h>

#snip "print.hpp"

template <typename Collection>
class QuickSort {
    Collection& collection;

    template <typename It>
    void sort(It begin, It end) {
        if (begin == end) {
            return;
        }
        // DIVIDE
        auto middle = partition(begin, end);
        // CONQUER
        sort(begin, middle);
        sort(std::next(middle), end);
    }

    template <typename It>
    It partition(It begin, It end) {
        auto pivot = *std::prev(end);
        auto middle = std::partition(begin, end, [&pivot] (const auto& value) {
            return value <  pivot;
        });
        std::partition(middle, end, [&pivot] (const auto& value) {
            return value <= pivot;
        });
        return middle;
    }

public:
    QuickSort(Collection& collection) : collection(collection) {
        sort(std::begin(collection), std::end(collection));
    }
};

// tremplate-template only to support custom containerss (and to show off)
template <template<typename> typename Collection=std::vector, typename T=int>
inline Collection<T> quickSort(Collection<T> collection) {
    QuickSort<Collection<T>> a(collection);
    return collection;
}

// see https://github.com/whoan/snip
// snip("print.hpp")

int main() {
    snip::printLoopSpaces(quickSort({5}));
    snip::printLoopSpaces(quickSort({-2}));
    snip::printLoopSpaces(quickSort({5, 2}));
    snip::printLoopSpaces(quickSort(std::list<int>({3, 1, 2})));
    snip::printLoopSpaces(quickSort({3, 1, 2}));
    snip::printLoopSpaces(quickSort({5, 2, 1}));
    snip::printLoopSpaces(quickSort({5, 2, 1, 9}));
    snip::printLoopSpaces(quickSort({4, 8, 1, 3, 2, 56, 3, 4, 7, 12, 4, 543, 7, 96, 73, 2, 3, 6, 8, 99, 2}));
    return 0;
}
