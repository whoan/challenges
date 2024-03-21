// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
// Medium

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> monsters; monsters.reserve(dist.size());
        for (int i = 0; i < dist.size(); ++i) {
            monsters.push_back(double(dist[i])/speed[i]);
        }
        std::sort(monsters.begin(), monsters.end());
        int i = 0;
        for (i = 1; i < monsters.size(); ++i) {
            if (monsters[i] <= i) {
                break;
            }
        }
        return i;
    }
};

// "inspired" by https://leetcode.com/problems/eliminate-maximum-number-of-monsters/solutions/1314550/sort-by-arrival/?envType=daily-question&envId=2023-11-07
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        auto& arrival = dist;
        for (int i = 0; i < dist.size(); ++i) {
            arrival[i] = (dist[i]-1) / speed[i];
        }
        std::sort(arrival.begin(), arrival.end());
        int i = 1;
        for (; i < arrival.size(); ++i) {
            if (arrival[i] < i) {
                return i;
            }
        }
        return arrival.size();
    }
};

/*
Test data:
[1,3,4]
[1,1,1]
[1,1,2,3]
[1,1,1,1]
[3,2,4]
[5,3,2]
[3,5,7,4,5]
[2,3,6,3,2]
[4,2,8]
[2,1,4]
*/
