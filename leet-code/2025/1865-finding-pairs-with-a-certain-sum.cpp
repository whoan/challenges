// https://leetcode.com/problems/finding-pairs-with-a-certain-sum
// Medium

class FindSumPairs {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::unordered_map<int, int> nums2_map;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        std::ranges::sort(nums1); // should help to reduce cache misses
        this->nums1 = std::move(nums1);
        for (int n : nums2) {
            ++nums2_map[n];
        }
        this->nums2 = std::move(nums2);
    }

    void add(int index, int val) {
        auto it = nums2_map.find(nums2[index]);
        if (--it->second == 0) {
            nums2_map.erase(it);
        }
        ++nums2_map[nums2[index] += val];
    }

    int count(int tot) {
        int result = 0;
        for (int n : nums1) {
            auto it = nums2_map.find(tot-n);
            if (it != nums2_map.end()) {
                result += it->second;
            }
        }
        return result;
    }
};

class FindSumPairs {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::unordered_map<int, int> nums2_map;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = std::move(nums1);
        for (int n : nums2) {
            ++nums2_map[n];
        }
        this->nums2 = std::move(nums2);
    }

    void add(int index, int val) {
        --nums2_map[nums2[index]]; // I could remove this if second is 0
        nums2[index] += val;
        ++nums2_map[nums2[index]];
    }

    int count(int tot) {
        int result = 0;
        for (int n : nums1) {
            auto it = nums2_map.find(tot-n);
            if (it != nums2_map.end()) {
                result += it->second;
            }
        }
        return result;
    }
};

// lab: some optimizations to try to make it faster at the expense of uglier code
class FindSumPairs {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::unordered_map<int, int> nums2_map;
    int max_nums2 = 0;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        // should help to reduce cache misses when equal elements are tested and helps to break loop below
        std::ranges::sort(nums1);
        max_nums2 = *std::ranges::max_element(nums2);
        this->nums1 = std::move(nums1);
        for (int n : nums2) {
            ++nums2_map[n];
        }
        this->nums2 = std::move(nums2);
    }

    void add(int index, int val) {
        auto it = nums2_map.find(nums2[index]);
        if (--it->second == 0) {
            nums2_map.erase(it);
        }
        int new_val = nums2[index] += val;
        max_nums2 = std::max(new_val, max_nums2);
        ++nums2_map[new_val];
    }

    int count(int tot) {
        int result = 0;
        for (int n : nums1) {
            if (tot-n < 0) {
                break;
            }
            if (tot-n > max_nums2) {
                continue;
            }
            auto it = nums2_map.find(tot-n);
            if (it != nums2_map.end()) {
                result += it->second;
            }
        }
        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
