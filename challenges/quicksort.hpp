/*
 * To be used for different sources
 */

#include <vector>
#include <algorithm>
#include <utility>

template <class T>
class Quicksort {
    void quicksort(std::vector<T>& elements, int left, int right) {
        if (right <= left) return;
        auto index = partition(elements, left, right);
        quicksort(elements, left, index-1);
        quicksort(elements, index+1, right);
    }

    int partition(std::vector<T>& elements, int left, int right) {
        const auto indexPivot(left);
        const auto pivot(elements[indexPivot]);
        int index(indexPivot);
        ++left; // skip the pivot
        do {
            while (left <= right && elements[left] <= pivot) {
                index=left;
                ++left;
            }
            while (left < right && elements[right] >= pivot) {
                --right;
            }
            if (left < right) {
                std::swap(elements[left], elements[right]);
            }
        } while (left < right);
        // put the pivot in its right place
        std::swap(elements[index], elements[indexPivot]);
        return index;
    }
public:
    std::vector<T>& sort(std::vector<T>& elements) {
        quicksort(elements, 0, elements.size()-1);
        return elements;
    }
};
