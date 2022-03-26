// https://leetcode.com/problems/two-city-scheduling/
// Medium

// after looking at other's solution
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        enum {CITY_A, CITY_B};
        std::sort(costs.begin(), costs.end(), [] (auto& person1, auto& person2) {
            return person1[CITY_A]-person2[CITY_A] < person1[CITY_B]-person2[CITY_B];
        });
        int result = 0;
        int half = costs.size()/2;
        for (int i = 0; i < half; ++i) {
            result += costs[i][CITY_A] + costs[i+half][CITY_B];
        }
        return result;
    }
};

class MySolution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        enum {CITY_A, CITY_B};
        std::sort(costs.begin(), costs.end(), [] (auto& person1, auto& person2) {
            return std::abs(person1[CITY_A]-person1[CITY_B]) > std::abs(person2[CITY_A]-person2[CITY_B]);
        });

        int result = 0;
        int city_a = 0, city_b = 0;
        int half = costs.size()/2;
        for (auto& cost : costs) {
            if (city_b == half || (city_a != half && cost[CITY_A] < cost[CITY_B])) {
                result += cost[CITY_A];
                ++city_a;
            } else {
                result += cost[CITY_B];
                ++city_b;
            }
        }
        return result;
    }
};

/*
Test data:
[[518,518],[71,971],[121,862],[967,607],[138,754],[513,337],[499,873],[337,387],[647,917],[76,417]]
[[10,20],[30,200],[400,50],[30,20]]
[[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
[[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
*/
