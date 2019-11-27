#include <bits/stdc++.h>

template <typename Collection>
class MergeSort {
    Collection& collection;

    void sort(std::size_t left, std::size_t right) {
        // base case to end recursion
        if (right - left < 2) {
            return;
        }

        // call recursively basically to track indices in the stack (frames).
        // the indices will be useful for the merge call to start mergign the smallest possibe ranges
        std::size_t middle = left + (right-left)/2;
        sort(left, middle);
        sort(middle, right);

        // do the actual work.
        // at this point, left-middle and middle-right are always sorted (starting from 1 element each)
        merge(left, middle, right);
    }

    void merge(std::size_t left, std::size_t middle, std::size_t right) {
        Collection buffer;
        std::size_t i=left, j=middle;
        while (i < middle && j < right) {
            if (collection[i] < collection[j]) {
                buffer.insert(std::end(buffer), collection[i++]);
            } else {
                buffer.insert(std::end(buffer), collection[j++]);
            }
        }

        while (i < middle) {
            buffer.insert(std::end(buffer), collection[i++]);
        }
        while (j < right) {
            buffer.insert(std::end(buffer), collection[j++]);
        }

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

int main() {
    for (auto item : mergeSort({4, 8, 1, 3, 2, 56, 3, 4, 7, 12, 4, 543, 7, 96, 73, 2, 3, 6, 8, 99, 2})) {
        std::cerr << item << " ";
    }
    std::cerr << std::endl;
    return 0;
}
