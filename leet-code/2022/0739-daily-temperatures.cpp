// https://leetcode.com/problems/daily-temperatures/
// Medium

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        for (int i = n-2; i >= 0; --i) {
            int wait_days = 1;
            while (temperatures[i+wait_days] <= temperatures[i] && answer[i+wait_days]) {
                wait_days += answer[i+wait_days];
            }
            answer[i] = wait_days * (temperatures[i+wait_days] > temperatures[i]);
        }
        return answer;
    }
};

/*
Test data:
[100,65,67,52,63,40,92,44,66,39]
[89,62,70,58,47,47,46,76,100,70]
*/
