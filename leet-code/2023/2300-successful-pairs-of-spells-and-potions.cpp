// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
// Medium

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end());
        std::vector<int> pairs; pairs.reserve(spells.size());
        for (int spell_strength : spells) {
            auto it = std::lower_bound(potions.begin(), potions.end(), success / spell_strength);
            pairs.push_back(std::distance(it, potions.end()));
            if (it != potions.end() && (long long) spell_strength*(*it) < success) {
                pairs.back() -= std::distance(
                    it,
                    std::find_if(it, potions.end(), [it] (int n) { return n != *it;})
                );
            }
        }
        return pairs;
    }
};

/*
Test data:
[5,1,3]
[1,2,3,4,5]
7
[3,1,2]
[8,5,8]
16
[15,8,19]
[38,36,23]
328
[13,22,21,13,11,9,13,35,7,38,10,10,38,19,3,16,13,24,16,27,20,24,32,5,16,35,24,2,25,32,20,22,22,3,35,39,27,26,25,21,27,40,15,17,24,40,35,27,20,40,9,35,27,19,15,34,35,37,17,40,8,3,33,39,29,22,30,1,37,2,16,30,32,31,24,6,34,26,36,4,21,2,29,31,3,27,6,24,40,18]
[33,16,35,14,26,23,23,2,37,23,15,20,25,34,23,29,4,18,26,24,16,37,15,11,33,24,12,13,7,24,3,26,1,3,38,33,19,3,34,22,30,39,18,7,21,4,33,18,39,5,34,14,32,5,20,22,5,25,15]
533
*/
