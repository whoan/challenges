// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// Medium

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> bits; bits.reserve(arr.size());
        std::transform(arr.begin(), arr.end(), std::back_inserter(bits), [this] (auto& s) { return get_bits(s); });
        return backtrack(arr, bits, 0, 0);
    }

private:
    int backtrack(vector<string>& arr, vector<int>& bits, int i, int ored) const {
        int max = 0;
        for (; i < bits.size(); ++i) {
            if (bits[i] && (ored & bits[i]) == 0) {
                max = std::max(max, int(arr[i].size()) + backtrack(arr, bits, i+1, ored | bits[i]));
            }
        }
        return max;
    }

    int get_bits(const string& s) const {
        std::bitset<26> bits{};
        for (char c : s) {
            if (bits[c-'a']) {
                return 0;
            }
            bits[c-'a'] = true;
        }
        return bits.to_ulong();
    }
};
