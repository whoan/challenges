/*
 * https://www.hackerrank.com/challenges/ctci-ice-cream-parlor
 */

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class IceCream {
public:
    int cost;
    int index;
    IceCream(int cost, int index) : cost(cost), index(index) {}
};

int binarySearch(int first, int last, const std::vector<IceCream>& iCreams, int search) {
    int medium = first + (last-first)/2;
    if (search == iCreams[medium]) return medium;

}

int main() {
    int trips;
    std::cin >> trips;
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

        std::sort(iCreams.begin(), iCreams.end(), [](const IceCream& ic1, const IceCream& ic2) -> bool {
            return ic1.cost < ic2.cost;
        });

        for (int i(0); i < flavors-1; ++i) {
            int remainder = money - iCreams[i].cost;
            if (remainder >= iCreams[i].cost) {
                int index = binarySearch( i + 1, flavors - 1, iCreams, remainder);
                if (index != -1) {
                    std::cout << min(iCreams[i].index, index) << " " << max(iCreams[i].index, index) << std::endl;
                    break;
                }
            }
        }
    }
}
