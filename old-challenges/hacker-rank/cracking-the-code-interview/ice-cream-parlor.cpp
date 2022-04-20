/*
 * https://www.hackerrank.com/challenges/ctci-ice-cream-parlor
 */

#include <vector>
#include <iostream>
#include <algorithm>

class IceCream {
public:
    int cost;
    int index;
    IceCream(int cost, int index) : cost(cost), index(index) {}
};

int main() {
    int trips;
    std::cin >> trips;
    auto comparator = [](const IceCream& ic1, const IceCream& ic2) -> bool {
        return ic1.cost < ic2.cost;
    };
    for (int trip(0); trip < trips; ++trip) {
        int money;
        int flavors;
        std::cin >> money >> flavors;
        std::vector<IceCream> iCreams;
        iCreams.reserve(flavors);

        for (int i(0); i < flavors; ++i) {
            int cost;
            std::cin >> cost;
            iCreams.push_back(IceCream(cost, i+1));
        }

        std::sort(iCreams.begin(), iCreams.end(), comparator);

        // solution
        for (auto first = iCreams.begin(), end = iCreams.end(); first < end; ++first) {
            int remainder = money - first->cost;
            auto second = std::lower_bound(first+1, end, IceCream(remainder, -1), comparator);
            if (second != iCreams.end() && remainder == second->cost) {
                std::cout << std::min(first->index, second->index) << " " << std::max(first->index, second->index) << std::endl;
                break;
            }
            end = second;
        }
    }
}
