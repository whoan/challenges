// https://leetcode.com/problems/zero-array-transformation-iii/
// Medium

// moved code around to try to improve performance
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        std::ranges::sort(queries);
        std:priority_queue<int> candidates;
        int queries_idx = 0;
        int can_decrement = 0; // prefix_sum from valid/taken candidates
        std::vector<int> decrement(nums.size()+1, 0); // track when prefix sum should decrement
        enum { START, END };
        for (int i = 0; i < nums.size(); ++i) {
            // in case some ranges ended on previous iteration
            can_decrement -= decrement[i];
            // more ranges needed
            if (nums[i] > can_decrement) {
                // fill pq with candidates available
                for (; queries_idx < queries.size() && queries[queries_idx][START] <= i; ++queries_idx) {
                    candidates.push(queries[queries_idx][END]);
                }
                // check candidates
                while (nums[i] > can_decrement) {
                    if (candidates.empty() || candidates.top() < i) {
                        return -1;
                    }
                    // valid candidate found
                    ++can_decrement;
                    ++decrement[candidates.top()+1];
                    candidates.pop();
                }
            }
        }
        return candidates.size() + (queries.size()-queries_idx); // return unused candidates
    }
};

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        std::ranges::sort(queries);
        std:priority_queue<int> candidates;
        int queries_idx = 0;
        int can_decrement = 0; // prefix_sum from valid/taken candidates
        std::vector<int> decrement(nums.size()+1, 0); // track when prefix sum should decrement
        enum { START, END };
        for (int i = 0; i < nums.size(); ++i) {
            // in case some ranges ended on previous iteration
            can_decrement -= decrement[i];
            // fill pq with candidates available
            for (; queries_idx < queries.size() && queries[queries_idx][START] <= i; ++queries_idx) {
                candidates.push(queries[queries_idx][END]);
            }
            // more ranges needed. check candidates
            while (nums[i] > can_decrement) {
                if (candidates.empty() || candidates.top() < i) {
                    return -1;
                }
                // valid candidate found
                ++can_decrement;
                ++decrement[candidates.top()+1];
                candidates.pop();
            }
        }
        return candidates.size() + (queries.size()-queries_idx); // return unused candidates
    }
};
