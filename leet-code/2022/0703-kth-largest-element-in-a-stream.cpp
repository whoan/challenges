// https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Easy

// heap solution
class KthLargest {
    int k;
    int kth_element;
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        kth_element = std::numeric_limits<int>::min();
        for (int i = 0; i < k && i < nums.size(); ++i) {
            heap.push(nums[i]);
        }
        for (int i = k; i < nums.size(); ++i) {
            conditionally_push(nums[i]);
        }
    }

    int add(int val) {
        conditionally_push(val);
        return kth_element;
    }

private:
    void conditionally_push(int val) {
        if (val > kth_element) {
            heap.push(val);
            if (heap.size() > k) {
                heap.pop();
            }
            kth_element = heap.top();
        }
    }
};

// heap. cleaner but slower
class CleanerButSlowerKthLargest {
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int i = 0; i < nums.size(); ++i) {
            heap.push(nums[i]);
        }
        while (heap.size() > k) {
            heap.pop();
        }
    }

    int add(int val) {
        if (heap.size() < k || val > heap.top()) {
            heap.push(val);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        return heap.top();
    }
};

class FurtherImprovedKthLargest {
    int k;
    int kth_element;
    std::multiset<int> sorted;

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        kth_element = std::numeric_limits<int>::min();
        for (int i = 0; i < k && i < nums.size(); ++i) {
            sorted.insert(nums[i]);
        }
        for (int i = k; i < nums.size(); ++i) {
            conditionally_insert(nums[i]);
        }
    }

    int add(int val) {
        conditionally_insert(val);
        return kth_element;
    }

private:
    void conditionally_insert(int val) {
        if (val > kth_element) {
            sorted.insert(val);
            if (sorted.size() > k) {
                sorted.erase(sorted.begin());
            }
            kth_element = *sorted.begin();
        }
    }
};

class ImprovedKthLargest {
    int k;
    int last;
    std::multiset<int> sorted;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        std::copy(nums.begin(), nums.end(), std::inserter(sorted, sorted.end()));
        while (sorted.size() > k) {
            sorted.erase(sorted.begin());
        }
        if (sorted.size() < k) {
            last = std::numeric_limits<int>::min();
        } else {
            last = *sorted.begin();
        }
    }

    int add(int val) {
        if (val > last) {
            sorted.insert(val);
            if (sorted.size() > k) {
                sorted.erase(sorted.begin());
            }
            last = *sorted.begin();
        }
        return last;
    }
};

class NaiveKthLargest {
    int k;
    std::multiset<int> sorted;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        std::copy(nums.begin(), nums.end(), std::inserter(sorted, sorted.end()));
    }

    int add(int val) {
        sorted.insert(val);
        return *std::prev(sorted.end(), k);
    }
};

/*
Test data:
["KthLargest","add","add","add","add","add"]
[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]
["KthLargest","add","add","add","add","add"]
[[1,[]],[-3],[-2],[-4],[0],[4]]
*/
