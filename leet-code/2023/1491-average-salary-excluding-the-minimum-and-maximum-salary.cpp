// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
// Easy

class Solution {
public:
    double average(vector<int>& salaries) {
        int min = 1e6, max = 0;
        int total = 0;
        for (int salary : salaries) {
            min = std::min(min, salary);
            max = std::max(max, salary);
            total += salary/1000;
        }
        total *= 1000;
        return double(total - min - max) / (salaries.size()-2);
    }
};
