#include <bits/stdc++.h>

#snip "print.hpp"

template <typename Collection>
class QuickSort {
public:
    enum PartitionScheme {
        Lomuto, Hoare
    };

private:
    PartitionScheme partitionScheme;
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
        // TODO: paritin according to partition scheme, instead of just selecting pivot differently
        auto pivot = getPivot(begin, end);
        auto middle = std::partition(begin, end, std::bind(std::less<>(), std::placeholders::_1, pivot));
        std::partition(middle, end, std::bind(std::less_equal<>(), std::placeholders::_1, pivot));
        return middle;
    }

    template <typename It>
    auto getPivot(It begin, It end) const {
        switch (partitionScheme) {
            case Lomuto:
                return getLomutoPivot(begin, end);
            case Hoare:
                return getHoarePivot(begin, end);
        }
        throw std::runtime_error("Partition Scheme not supported " + std::to_string(partitionScheme));
    }

    template <typename It>
    auto getLomutoPivot(It, It end) const {
        return *std::prev(end);
    }

    template <typename It>
    auto getHoarePivot(It begin, It end) const {
        return *std::next(begin, std::distance(begin, end) / 2);
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
// snip("print.hpp")

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
