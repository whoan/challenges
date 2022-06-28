// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// Medium

class Solution {
public:
    int minPartitions(string n) {
        return *std::max_element(n.begin(), n.end()) - '0';
    }
};

// get out of the loop once a 9 is found
class AlternativeSolution {
public:
    int minPartitions(string n) {
        int max = 0;
        for (int i = 0; i < n.size() && max != 9; ++i) {
            max = std::max(max, n[i]-'0');
        }
        return max;
    }
};
