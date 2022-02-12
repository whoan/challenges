// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/
// Medium

class SparseVector {
    vector<pair<int, int>> value_index;
public:

    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                value_index.push_back(make_pair(nums[i], i));
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& other) {
        int result = 0;
        for (auto& pair : value_index) {
             auto other_it = lower_bound(
                other.value_index.begin(),
                other.value_index.end(),
                pair,
                [] (auto& pair_a, auto& pair_b) { return pair_a.second < pair_b.second; }
            );
            if (other_it == other.value_index.end()) {
                break;
            }
            if (other_it->second == pair.second) {
                result += other_it->first * pair.first;
            }
        }
        return result;
    }
};
