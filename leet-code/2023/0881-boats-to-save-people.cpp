// https://leetcode.com/problems/boats-to-save-people/
// Medium

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int boats = 0;
        for (int i = 0; i < people.size(); people.pop_back(), ++boats) {
            i += (people.size() > 1 && people[i]+people.back() <= limit);
        }
        return boats;
    }
};

/*
Test data:
[1,2]
3
[3,2,2,1]
3
[3,5,3,4]
5
[1,5,3,5]
7
*/
