// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs-ii/
// Medium

class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        std::sort(jobs.begin(), jobs.end());
        std::sort(workers.begin(), workers.end());
        int max = 0;
        for (int i = 0; i < jobs.size(); ++i) {
            max = std::max(max, int(std::ceil(float(jobs[i]) / workers[i])));
        }
        return max;
    }
};

/*
Test data:
[5,2,4]
[1,7,5]
[3,18,15,9]
[6,5,1,3]
[1]
[2]
*/
