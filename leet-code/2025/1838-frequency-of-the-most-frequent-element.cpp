// https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Medium

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        std::ranges::sort(nums, std::greater{});
        int max = 1;
        for (int i=0, j=0; j < nums.size(); ++j) {
            k -= nums[i]-nums[j];
            while (k < 0) {
                k += (nums[i]-nums[i+1])*(j-i);
                ++i;
            }
            max = std::max(max, j-i+1);
        }
        return max;
    }
};

// brute force
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        std::map<int, int, std::greater<int>> map;
        for (int n : nums) {
            ++map[n];
        }
        int max = 0;
        for (auto it = map.begin(); it != map.end(); ++it) {
            int rem = k;
            int extra = 0;
            for (auto inner = std::next(it); rem > 0 && inner != map.end(); ++inner) {
                for (int q = inner->second; q && rem-(it->first-inner->first) >= 0; --q) {
                    rem -= it->first-inner->first;
                    ++extra;
                }
            }
            max = std::max(max, it->second+extra);
        }
        return max;
    }
};

// still slow
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        std::ranges::sort(nums, std::greater{});``
        int result = 0, current = 0;
        std::deque<int> changes{0};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[changes.back()] != nums[i]) {
                changes.push_back(i);
            }
            k -= nums[changes.front()]-nums[i];
            while (k < 0) {
                int removed = changes.front(); changes.pop_front();
                current -= changes.front()-removed;
                k += (nums[removed]-nums[changes.front()])*(i-changes.front()+1);
            }
            ++current;
            result = std::max(result, current);
        }
        return result;
    }
};

// The slowest and most horrible solution ever
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        std::ranges::sort(nums, std::greater{});
        int start_idx = 0;
        int target = nums[start_idx];
        int rem = k;
        bool start_set = false;
        int result = 0, current = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!start_set && nums[start_idx] != nums[i]) {
                start_idx = i;
                start_set = true;
            }
            rem -= target-nums[i];
            if (rem < 0) {
                rem = k;
                target = nums[start_idx];
                current = 0;
                i = start_idx;
                start_set = false;
            }
            ++current;
            result = std::max(result, current);
        }
        return result;
    }
};

/*
Test cases:
[1,4,8,13]
5
*/
