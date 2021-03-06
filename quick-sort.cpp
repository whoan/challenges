#include <bits/stdc++.h>

// https://en.wikipedia.org/wiki/Quicksort

template <typename Collection>
class QuickSort {
public:
    enum PartitionScheme {
        Lomuto, Hoare, Default
    };

private:
    PartitionScheme partitionScheme;
    Collection& collection;

    template <typename It>
    void sort(It begin, It end) {
        // expensive and requires random access iterators:
        // it will remain like this to allow differet partition schemes (educational purposes)
        if (std::distance(begin, end) <= 1) {
            return;
        }
        // DIVIDE
        auto middle = partition(begin, end);
        // CONQUER
        sort(begin, middle);
        sort(partitionScheme == PartitionScheme::Hoare ? middle : std::next(middle), end);
    }

    template <typename It>
    auto partition(It begin, It end) {
        switch (partitionScheme) {
            case Lomuto:
                return partitionLomuto(begin, end);
            case Hoare:
                return partitionHoare(begin, end);
            default:
                return partitionDefault(begin, end);
        }
    }

    template <typename It>
    It partitionLomuto(It begin, It end) {
        auto pivot = getPivot(begin, end);
        auto middle = begin;
        for (auto it = begin; it != end; std::advance(it, 1)) {
            if (*it < pivot) {
                std::swap(*middle, *it);
                std::advance(middle, 1);
            }
        }
        std::swap(*middle, *std::prev(end));
        return middle;
    }

    template <typename It>
    It partitionHoare(It begin, It end) {
        // LegacyBidirectionalIterator is needed here
        auto pivot = getPivot(begin, end);
        std::advance(begin, -1);
        while (true) {
            for (std::advance(begin, 1); *begin < pivot; std::advance(begin, 1)) {}
            for (std::advance(end, -1); *end > pivot; std::advance(end, -1)) {}
            if (std::distance(begin, end) <= 0) {
                break;
            }
            std::swap(*begin, *end);
        }
        // this iterator does not guarantee to "point" to the pivot, we process it again (see conquer step)
        return begin;
    }

    template <typename It>
    It partitionDefault(It begin, It end) {
        auto pivot = getPivot(begin, end);
        auto middle = std::partition(begin, end, std::bind(std::less<>(), std::placeholders::_1, pivot));
        std::partition(middle, end, std::bind(std::less_equal<>(), std::placeholders::_1, pivot));
        return middle;
    }

    template <typename It>
    auto getPivot(It begin, It end) const {
        switch (partitionScheme) {
            case Lomuto:
                return getPivotLomuto(begin, end);
            case Hoare:
                return getPivotHoare(begin, end);
            default:
                return getPivotDefault(begin, end);
        }
    }

    template <typename It>
    auto getPivotLomuto(It, It end) const {
        // Lomuto's algorithm does not require to choose pivot in this way, but I think this is the most common approach
        return *std::prev(end);
    }

    template <typename It>
    auto getPivotHoare(It begin, It end) const {
        // Hoare's algorithm does not require to choose pivot in this way, but I think this is the most common approach
        return *std::next(begin, std::distance(begin, end) / 2);
    }

    template <typename It>
    auto getPivotDefault(It begin, It end) const {
        // after Sedgewick recommendation
        auto middle = std::next(begin, std::distance(begin, end) / 2);
        std::array<typename Collection::value_type, 3> candidates = {*begin, *middle, *std::prev(end)};
        std::sort(std::begin(candidates), std::end(candidates));
        return *std::next(std::begin(candidates));
    }

public:
    QuickSort(Collection& collection, PartitionScheme partitionScheme=Lomuto)
    : partitionScheme(partitionScheme), collection(collection) {
        sort(std::begin(collection), std::end(collection));
    }
};

// tremplate-template only to support custom containerss (and to show off)
template <template<typename> typename Collection=std::vector, typename T=int>
inline Collection<T> quickSort(
    Collection<T> collection,
    typename QuickSort<Collection<T>>::PartitionScheme partitionScheme=QuickSort<Collection<T>>::PartitionScheme::Lomuto
) {
    QuickSort<Collection<T>> a(collection, partitionScheme);
    return collection;
}

// see https://github.com/whoan/snip
// snip("cpp/print.hpp")

int main() {
    snip::printLoopSpaces(quickSort({5}));
    snip::printLoopSpaces(quickSort({5}, QuickSort<std::vector<int>>::PartitionScheme::Hoare));
    snip::printLoopSpaces(quickSort(std::list<int>({5})));

    snip::printLoopSpaces(quickSort({-2}));
    snip::printLoopSpaces(quickSort({-2}, QuickSort<std::vector<int>>::PartitionScheme::Hoare));
    snip::printLoopSpaces(quickSort(std::list<int>({-2})));

    snip::printLoopSpaces(quickSort({5, 2}));
    snip::printLoopSpaces(quickSort({5, 2}, QuickSort<std::vector<int>>::PartitionScheme::Hoare));
    snip::printLoopSpaces(quickSort(std::list<int>({5, 2})));

    snip::printLoopSpaces(quickSort({2, 2}));
    snip::printLoopSpaces(quickSort({2, 2}, QuickSort<std::vector<int>>::PartitionScheme::Hoare));
    snip::printLoopSpaces(quickSort(std::list<int>({2, 2})));

    snip::printLoopSpaces(quickSort({3, 3, 3}));
    snip::printLoopSpaces(quickSort({3, 3, 3}, QuickSort<std::vector<int>>::PartitionScheme::Hoare));
    snip::printLoopSpaces(quickSort(std::list<int>({3, 3, 3})));

    snip::printLoopSpaces(quickSort({3, 1, 2}));
    snip::printLoopSpaces(quickSort({3, 1, 2}, QuickSort<std::vector<int>>::PartitionScheme::Hoare));
    snip::printLoopSpaces(quickSort(std::list<int>({3, 1, 2})));

    snip::printLoopSpaces(quickSort({5, 2, 1}));
    snip::printLoopSpaces(quickSort({5, 2, 1}, QuickSort<std::vector<int>>::PartitionScheme::Hoare));
    snip::printLoopSpaces(quickSort(std::list<int>({5, 2, 1})));

    snip::printLoopSpaces(quickSort({5, 2, 1, 9}));
    snip::printLoopSpaces(quickSort({5, 2, 1, 9}, QuickSort<std::vector<int>>::PartitionScheme::Hoare));
    snip::printLoopSpaces(quickSort(std::list<int>({5, 2, 1, 9})));

    snip::printLoopSpaces(quickSort({4, 8, 1, 3, 2, 56, 3, 4, 7, 12, 4, 543, 7, 96, 73, 2, 3, 6, 8, 99, 2}));
    snip::printLoopSpaces(quickSort({4, 8, 1, 3, 2, 56, 3, 4, 7, 12, 4, 543, 7, 96, 73, 2, 3, 6, 8, 99, 2}, QuickSort<std::vector<int>>::PartitionScheme::Hoare));
    snip::printLoopSpaces(quickSort(std::list<int>({4, 8, 1, 3, 2, 56, 3, 4, 7, 12, 4, 543, 7, 96, 73, 2, 3, 6, 8, 99, 2})));

    return 0;
}
