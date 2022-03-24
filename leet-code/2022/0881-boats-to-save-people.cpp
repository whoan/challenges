// https://leetcode.com/problems/boats-to-save-people/
// Medium

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int number_of_boats = 0;
        for (int light = 0, heavy = people.size()-1; light <= heavy; --heavy) {
            if (people[heavy] + people[light] <= limit) {
                ++light;
            }
            ++number_of_boats;
        }
        return number_of_boats;
    }
};

/*
Test data:
[1,2,2,3]
3
[1,2]
3
[3,5,3,4]
5
*/
