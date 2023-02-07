// https://leetcode.com/problems/fruit-into-baskets/
// Medium

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        enum TypesOfFruits {First, Second, Max};
        const int UNSET = -1;
        std::array<int, TypesOfFruits::Max> types_of_fruits = {fruits[0], UNSET};
        std::array<int, TypesOfFruits::Max> amount_of_fruits = {1, 0};
        int max = 1;
        for (int i=0, j=1; j < fruits.size(); ++j) {
            while (types_of_fruits[Second] != UNSET && fruits[j] != types_of_fruits[First] && fruits[j] != types_of_fruits[Second]) {
                if (fruits[i] == types_of_fruits[First]) {
                    if (--amount_of_fruits[First] == 0) {
                        types_of_fruits[First] = fruits[j];
                    }
                } else {
                    if (--amount_of_fruits[Second] == 0) {
                        types_of_fruits[Second] = fruits[j];
                    }
                }
                ++i;
            }
            if (fruits[j] == types_of_fruits[First]) {
                ++amount_of_fruits[First];
            } else {
                ++amount_of_fruits[Second];
                if (types_of_fruits[Second] == UNSET) {
                    types_of_fruits[Second] = fruits[j];
                }
            }
            max = std::max(max, amount_of_fruits[First] + amount_of_fruits[Second]);
        }
        return max;
    }
};
